/*
 * Dave Plonka <plonka@doit.wisc.edu>
 *
 * This file had been called "radix.c" in the MRT sources.
 *
 * I renamed it to "patricia.c" since it's not an implementation of a general
 * radix trie.  Also I pulled in various requirements from "prefix.c" and
 * "demo.c" so that it could be used as a standalone API.
 *
 * Copyright (c) 1999-2013
 *
 * The Regents of the University of Michigan ("The Regents") and Merit
 * Network, Inc.
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

#include "address.h"
#include "io_parse.h"
#include "memory.h"
#include "patricia.h"

static unsigned int
_patricia_family_maxbits(int family)
{
  switch (family)
  {
    case AF_INET:
      return PATRICIA_MAXBITS_IPV4;
    case AF_INET6:
      return PATRICIA_MAXBITS_IPV6;
    default:
      return 0;
  }
}

static bool
_patricia_tree_accepts_prefix(const patricia_tree_t *tree, const patricia_prefix_t *prefix)
{
  const unsigned int maxbits = _patricia_family_maxbits(tree->family);
  if (maxbits == 0)
    return false;

  return prefix->family == tree->family && prefix->bitlen <= maxbits;
}

static const unsigned char *
_patricia_prefix_bytes(const patricia_prefix_t *prefix)
{
  return (const unsigned char *)&prefix->addr;
}

static bool
_patricia_prefix_bit_is_set(const unsigned char *bytes, unsigned int bit)
{
  return (bytes[bit / 8] & (0x80U >> (bit % 8))) != 0;
}

static unsigned int
_patricia_prefix_first_differing_bit(const unsigned char *lhs, const unsigned char *rhs, unsigned int bitlen)
{
  for (unsigned int bit = 0; bit < bitlen; ++bit)
  {
    if (_patricia_prefix_bit_is_set(lhs, bit) !=
        _patricia_prefix_bit_is_set(rhs, bit))
      return bit;
  }

  return bitlen;
}

static bool
_patricia_prefix_bits_equal(const unsigned char *lhs, const unsigned char *rhs, unsigned int bitlen)
{
  if (bitlen == 0)
    return true;

  const size_t bytes = bitlen / 8;
  if (memcmp(lhs, rhs, bytes))
    return false;

  const unsigned int remaining_bits = bitlen % 8;
  if (remaining_bits == 0)
    return true;

  const unsigned char mask =
    (unsigned char)(0xFFU << (8 - remaining_bits));

  return (lhs[bytes] & mask) == (rhs[bytes] & mask);
}

static bool
_patricia_prefix_init(patricia_prefix_t *prefix, const struct io_addr *addr, unsigned int bitlen)
{
  assert(prefix);
  assert(addr);

  const int family = address_get_family(addr);
  const unsigned int maxbits = _patricia_family_maxbits(family);
  if (maxbits == 0 || bitlen > maxbits)
    return false;

  patricia_prefix_t new_prefix =
  {
    .family = family,
    .bitlen = bitlen
  };

  switch (family)
  {
    case AF_INET:
      if (!address_to_bytes(addr, &new_prefix.addr.ipv4, sizeof(new_prefix.addr.ipv4)))
        return false;
      break;
    case AF_INET6:
      if (!address_to_bytes(addr, &new_prefix.addr.ipv6, sizeof(new_prefix.addr.ipv6)))
        return false;
      break;
    default:
      return false;
  }

  *prefix = new_prefix;
  return true;
}

static bool
_patricia_prefix_init_from_addr(patricia_prefix_t *prefix, const struct io_addr *addr, unsigned int bitlen)
{
  assert(prefix);
  assert(addr);

  const unsigned int maxbits = _patricia_family_maxbits(address_get_family(addr));
  if (maxbits == 0)
    return false;

  if (bitlen == 0 || bitlen > maxbits)
    bitlen = maxbits;

  return _patricia_prefix_init(prefix, addr, bitlen);
}

static bool
_patricia_prefix_init_from_string(patricia_prefix_t *prefix, const char *string)
{
  assert(prefix);
  assert(string);

  char address_buf[INET6_ADDRSTRLEN];
  const char *address_string = string;
  const char *const slash = strchr(string, '/');

  if (slash)
  {
    const size_t address_len = slash - string;
    if (address_len >= sizeof(address_buf))
      return false;

    memcpy(address_buf, string, address_len);
    address_buf[address_len] = '\0';
    address_string = address_buf;
  }

  struct io_addr addr;
  if (!address_from_string(address_string, &addr))
    return false;

  const unsigned int maxbits = _patricia_family_maxbits(address_get_family(&addr));
  if (maxbits == 0)
    return false;

  unsigned int bitlen = maxbits;

  if (slash)
  {
    unsigned int parsed_bitlen;
    switch (io_parse_uint(slash + 1, &parsed_bitlen))
    {
      case IO_PARSE_OK:
        if (parsed_bitlen <= maxbits)
          bitlen = parsed_bitlen;
        break;
      case IO_PARSE_RANGE:
        break;
      default:
        return false;
    }
  }

  return _patricia_prefix_init(prefix, &addr, bitlen);
}

static bool
_patricia_prefix_to_addr(const patricia_prefix_t *prefix, struct io_addr *addr)
{
  assert(prefix);
  assert(addr);

  switch (prefix->family)
  {
    case AF_INET:
      return address_from_bytes(addr, AF_INET, &prefix->addr.ipv4, sizeof(prefix->addr.ipv4));
    case AF_INET6:
      return address_from_bytes(addr, AF_INET6, &prefix->addr.ipv6, sizeof(prefix->addr.ipv6));
    default:
      return false;
  }
}

bool
patricia_prefix_to_string(const patricia_prefix_t *prefix, char *buf, size_t buflen, bool include_bitlen)
{
  assert(prefix);
  assert(buf);

  struct io_addr addr;
  if (!_patricia_prefix_to_addr(prefix, &addr))
    return false;

  if (!address_to_string(&addr, buf, buflen))
    return false;

  if (!include_bitlen)
    return true;

  const size_t address_len = strlen(buf);
  const int written = snprintf(buf + address_len, buflen - address_len, "/%u", prefix->bitlen);

  return written >= 0 && (size_t)written < buflen - address_len;
}

static patricia_prefix_t *
_patricia_prefix_dup(const patricia_prefix_t *prefix)
{
  assert(prefix);

  patricia_prefix_t *const copy = io_calloc(sizeof(*copy));
  *copy = *prefix;

  return copy;
}

/* these routines support continuous mask only */

patricia_tree_t *
patricia_create(int family)
{
  if (_patricia_family_maxbits(family) == 0)
    return NULL;

  patricia_tree_t *const tree = io_calloc(sizeof(*tree));
  tree->family = family;

  return tree;
}

/*
 * if func is supplied, it will be called as func(node->data)
 * before deleting the node
 */
void
patricia_clear(patricia_tree_t *tree, void (*func)(void *))
{
  assert(tree);

  if (tree->root == NULL)
    return;

  patricia_node_t *Xstack[PATRICIA_MAXBITS + 1];
  patricia_node_t **Xsp = Xstack;

  patricia_node_t *Xrn = tree->root;
  while (Xrn)
  {
    patricia_node_t *l = Xrn->left;
    patricia_node_t *r = Xrn->right;

    if (Xrn->prefix)
    {
      io_free(Xrn->prefix);

      if (Xrn->data && func)
        func(Xrn->data);
    }
    else
      assert(Xrn->data == NULL);

    io_free(Xrn);

    if (l)
    {
      if (r)
        *Xsp++ = r;

      Xrn = l;
    }
    else if (r)
      Xrn = r;
    else if (Xsp != Xstack)
      Xrn = *(--Xsp);
    else
      Xrn = NULL;
  }

  tree->root = NULL;
}

void
patricia_destroy(patricia_tree_t *tree, void (*func)(void *))
{
  patricia_clear(tree, func);
  io_free(tree);
}

/*
 * if func is supplied, it will be called as func(node->prefix, node->data)
 */
void
patricia_foreach(patricia_tree_t *tree, void (*func)(patricia_prefix_t *, void *))
{
  assert(tree);
  assert(func);

  patricia_node_t *node;
  PATRICIA_WALK(tree->root, node) {
    func(node->prefix, node->data);
  } PATRICIA_WALK_END;
}

patricia_node_t *
patricia_search_exact(const patricia_tree_t *tree, patricia_prefix_t *prefix)
{
  assert(tree);
  assert(prefix);

  if (!_patricia_tree_accepts_prefix(tree, prefix))
    return NULL;

  if (tree->root == NULL)
    return NULL;

  patricia_node_t *node = tree->root;
  const unsigned char *const addr = _patricia_prefix_bytes(prefix);
  const unsigned int bitlen = prefix->bitlen;

  while (node->bit_index < bitlen)
  {
    if (_patricia_prefix_bit_is_set(addr, node->bit_index))
      node = node->right;
    else
      node = node->left;

    if (node == NULL)
      return NULL;
  }

  if (node->bit_index > bitlen || node->prefix == NULL)
    return NULL;

  assert(node->bit_index == bitlen);
  assert(node->bit_index == node->prefix->bitlen);

  if (_patricia_prefix_bits_equal(
        _patricia_prefix_bytes(node->prefix),
        _patricia_prefix_bytes(prefix), bitlen))
    return node;

  return NULL;
}

/* if inclusive != 0, "best" may be the given prefix itself */
patricia_node_t *
patricia_search_best2(const patricia_tree_t *tree, patricia_prefix_t *prefix, bool inclusive)
{
  assert(tree);
  assert(prefix);

  if (!_patricia_tree_accepts_prefix(tree, prefix))
    return NULL;

  if (tree->root == NULL)
    return NULL;

  patricia_node_t *node = tree->root;
  patricia_node_t *candidates[PATRICIA_MAXBITS + 1];
  size_t candidate_count = 0;
  const unsigned char *const addr = _patricia_prefix_bytes(prefix);

  const unsigned int bitlen = prefix->bitlen;
  while (node->bit_index < bitlen)
  {
    if (node->prefix)
      candidates[candidate_count++] = node;

    if (_patricia_prefix_bit_is_set(addr, node->bit_index))
      node = node->right;
    else
      node = node->left;

    if (node == NULL)
      break;
  }

  if (inclusive && node && node->prefix)
    candidates[candidate_count++] = node;

  while (candidate_count)
  {
    node = candidates[--candidate_count];

    if (node->prefix->bitlen <= bitlen &&
        _patricia_prefix_bits_equal(_patricia_prefix_bytes(node->prefix),
        _patricia_prefix_bytes(prefix), node->prefix->bitlen))
      return node;
  }

  return NULL;
}

patricia_node_t *
patricia_search_best(const patricia_tree_t *tree, patricia_prefix_t *prefix)
{
  return patricia_search_best2(tree, prefix, true);
}

patricia_node_t *
patricia_lookup(patricia_tree_t *tree, patricia_prefix_t *prefix)
{
  assert(tree);
  assert(prefix);

  if (!_patricia_tree_accepts_prefix(tree, prefix))
    return NULL;

  if (tree->root == NULL)
  {
    patricia_node_t *const node = io_calloc(sizeof(*node));
    node->bit_index = prefix->bitlen;
    node->prefix = _patricia_prefix_dup(prefix);
    tree->root = node;

    return node;
  }

  const unsigned int maxbits = _patricia_family_maxbits(tree->family);
  const unsigned char *const addr = _patricia_prefix_bytes(prefix);
  const unsigned int bitlen = prefix->bitlen;
  patricia_node_t *node = tree->root;

  while (node->bit_index < bitlen || node->prefix == NULL)
  {
    if (node->bit_index < maxbits && _patricia_prefix_bit_is_set(addr, node->bit_index))
    {
      if (node->right == NULL)
        break;

      node = node->right;
    }
    else
    {
      if (node->left == NULL)
        break;

      node = node->left;
    }

    assert(node);
  }

  assert(node->prefix);

  const unsigned char *const test_addr = _patricia_prefix_bytes(node->prefix);

  const unsigned int check_bit = node->bit_index < bitlen ? node->bit_index : bitlen;
  const unsigned int differ_bit = _patricia_prefix_first_differing_bit(addr, test_addr, check_bit);

  patricia_node_t *parent = node->parent;
  while (parent && parent->bit_index >= differ_bit)
  {
    node = parent;
    parent = node->parent;
  }

  if (differ_bit == bitlen && node->bit_index == bitlen)
  {
    if (node->prefix)
      return node;

    node->prefix = _patricia_prefix_dup(prefix);
    assert(node->data == NULL);

    return node;
  }

  patricia_node_t *const new_node = io_calloc(sizeof(*new_node));
  new_node->bit_index = prefix->bitlen;
  new_node->prefix = _patricia_prefix_dup(prefix);

  if (node->bit_index == differ_bit)
  {
    new_node->parent = node;

    if (node->bit_index < maxbits && _patricia_prefix_bit_is_set(addr, node->bit_index))
    {
      assert(node->right == NULL);
      node->right = new_node;
    }
    else
    {
      assert(node->left == NULL);
      node->left = new_node;
    }

    return new_node;
  }

  if (bitlen == differ_bit)
  {
    if (bitlen < maxbits && _patricia_prefix_bit_is_set(test_addr, bitlen))
      new_node->right = node;
    else
      new_node->left = node;

    new_node->parent = node->parent;

    if (node->parent == NULL)
    {
      assert(tree->root == node);
      tree->root = new_node;
    }
    else if (node->parent->right == node)
      node->parent->right = new_node;
    else
      node->parent->left = new_node;

    node->parent = new_node;
  }
  else
  {
    patricia_node_t *const branch_node = io_calloc(sizeof(*branch_node));
    branch_node->bit_index = differ_bit;
    branch_node->parent = node->parent;

    if (differ_bit < maxbits && _patricia_prefix_bit_is_set(addr, differ_bit))
    {
      branch_node->right = new_node;
      branch_node->left = node;
    }
    else
    {
      branch_node->right = node;
      branch_node->left = new_node;
    }

    new_node->parent = branch_node;

    if (node->parent == NULL)
    {
      assert(tree->root == node);
      tree->root = branch_node;
    }
    else if (node->parent->right == node)
      node->parent->right = branch_node;
    else
      node->parent->left = branch_node;

    node->parent = branch_node;
  }

  return new_node;
}

void
patricia_remove(patricia_tree_t *tree, patricia_node_t *node)
{
  assert(tree);
  assert(node);

  if (node->right && node->left)
  {
    /*
     * This might be a placeholder node -- have to check and make sure
     * there is a prefix associated with it !
     */
    io_free(node->prefix);

    node->prefix = NULL;
    /* Also I needed to clear data pointer -- masaki */
    node->data = NULL;
    return;
  }

  patricia_node_t *parent, *child;
  if (node->right == NULL && node->left == NULL)
  {
    parent = node->parent;

    io_free(node->prefix);
    io_free(node);

    if (parent == NULL)
    {
      assert(tree->root == node);
      tree->root = NULL;
      return;
    }

    if (parent->right == node)
    {
      parent->right = NULL;
      child = parent->left;
    }
    else
    {
      assert(parent->left == node);

      parent->left = NULL;
      child = parent->right;
    }

    if (parent->prefix)
      return;

    /* We need to remove parent too */
    if (parent->parent == NULL)
    {
      assert(tree->root == parent);
      tree->root = child;
    }
    else if (parent->parent->right == parent)
      parent->parent->right = child;
    else
    {
      assert(parent->parent->left == parent);
      parent->parent->left = child;
    }

    child->parent = parent->parent;
    io_free(parent);
    return;
  }

  if (node->right)
    child = node->right;
  else
  {
    assert(node->left);
    child = node->left;
  }

  parent = node->parent;
  child->parent = parent;

  io_free(node->prefix);
  io_free(node);

  if (parent == NULL)
  {
    assert(tree->root == node);
    tree->root = child;
    return;
  }

  if (parent->right == node)
    parent->right = child;
  else
  {
    assert(parent->left == node);
    parent->left = child;
  }
}

patricia_node_t *
patricia_make_and_lookup(patricia_tree_t *tree, const char *string)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_string(&prefix, string))
    return NULL;

  return patricia_lookup(tree, &prefix);
}

patricia_node_t *
patricia_make_and_lookup_addr(patricia_tree_t *tree, const struct io_addr *addr, unsigned int bitlen)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_addr(&prefix, addr, bitlen))
    return NULL;

  return patricia_lookup(tree, &prefix);
}

bool
patricia_lookup_then_remove(patricia_tree_t *tree, const char *string)
{
  patricia_node_t *const node = patricia_try_search_exact(tree, string);
  if (node == NULL)
    return false;

  patricia_remove(tree, node);
  return true;
}

patricia_node_t *
patricia_try_search_exact(const patricia_tree_t *tree, const char *string)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_string(&prefix, string))
    return NULL;

  return patricia_search_exact(tree, &prefix);
}

patricia_node_t *
patricia_try_search_best(const patricia_tree_t *tree, const char *string)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_string(&prefix, string))
    return NULL;

  return patricia_search_best(tree, &prefix);
}

patricia_node_t *
patricia_try_search_exact_addr(const patricia_tree_t *tree, const struct io_addr *addr, unsigned int bitlen)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_addr(&prefix, addr, bitlen))
    return NULL;

  return patricia_search_exact(tree, &prefix);
}

patricia_node_t *
patricia_try_search_best_addr(const patricia_tree_t *tree, const struct io_addr *addr, unsigned int bitlen)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_addr(&prefix, addr, bitlen))
    return NULL;

  return patricia_search_best(tree, &prefix);
}

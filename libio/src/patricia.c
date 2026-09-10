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
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

#include "address.h"
#include "io_parse.h"
#include "memory.h"
#include "patricia.h"

enum
{
  PATRICIA_MAX_BITLEN_IPV4 = sizeof(struct in_addr) * CHAR_BIT,
  PATRICIA_MAX_BITLEN_IPV6 = sizeof(struct in6_addr) * CHAR_BIT,
  PATRICIA_MAX_BITLEN = PATRICIA_MAX_BITLEN_IPV6
};

static unsigned int
_patricia_family_max_bitlen(int family)
{
  switch (family)
  {
    case AF_INET:
      return PATRICIA_MAX_BITLEN_IPV4;
    case AF_INET6:
      return PATRICIA_MAX_BITLEN_IPV6;
    default:
      return 0;
  }
}

static bool
_patricia_tree_accepts_prefix(const patricia_tree_t *tree, const patricia_prefix_t *prefix)
{
  const unsigned int max_bitlen = _patricia_family_max_bitlen(tree->family);
  if (max_bitlen == 0)
    return false;

  return prefix->family == tree->family && prefix->bitlen <= max_bitlen;
}

static void
_patricia_tree_replace_node(patricia_tree_t *tree,
                            const patricia_node_t *node,
                            patricia_node_t *replacement)
{
  assert(tree);
  assert(node);
  assert(replacement != node);

  patricia_node_t *const parent = node->parent;
  if (parent == NULL)
  {
    assert(tree->root == node);
    tree->root = replacement;
  }
  else if (parent->left == node)
    parent->left = replacement;
  else
  {
    assert(parent->right == node);
    parent->right = replacement;
  }

  if (replacement)
    replacement->parent = parent;
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
  const unsigned int max_bitlen = _patricia_family_max_bitlen(family);
  if (max_bitlen == 0 || bitlen > max_bitlen)
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

  const unsigned int max_bitlen = _patricia_family_max_bitlen(address_get_family(addr));
  if (max_bitlen == 0)
    return false;

  if (bitlen == 0 || bitlen > max_bitlen)
    bitlen = max_bitlen;

  return _patricia_prefix_init(prefix, addr, bitlen);
}

static bool
_patricia_prefix_init_from_string(patricia_prefix_t *prefix, const char *prefix_string)
{
  assert(prefix);
  assert(prefix_string);

  char address_buffer[INET6_ADDRSTRLEN];
  const char *address_string = prefix_string;
  const char *const slash = strchr(prefix_string, '/');

  if (slash)
  {
    const size_t address_len = slash - prefix_string;
    if (address_len >= sizeof(address_buffer))
      return false;

    memcpy(address_buffer, prefix_string, address_len);
    address_buffer[address_len] = '\0';
    address_string = address_buffer;
  }

  struct io_addr addr;
  if (!address_from_string(address_string, &addr))
    return false;

  const unsigned int max_bitlen = _patricia_family_max_bitlen(address_get_family(&addr));
  if (max_bitlen == 0)
    return false;

  unsigned int bitlen = max_bitlen;

  if (slash)
  {
    unsigned int parsed_bitlen;
    switch (io_parse_uint(slash + 1, &parsed_bitlen))
    {
      case IO_PARSE_OK:
        if (parsed_bitlen <= max_bitlen)
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

void *
patricia_node_get_data(const patricia_node_t *node)
{
  assert(node);
  assert(node->prefix);

  return node->data;
}

void
patricia_node_set_data(patricia_node_t *node, void *data)
{
  assert(node);
  assert(node->prefix);

  node->data = data;
}

/* these routines support continuous mask only */

patricia_tree_t *
patricia_create(int family)
{
  if (_patricia_family_max_bitlen(family) == 0)
    return NULL;

  patricia_tree_t *const tree = io_calloc(sizeof(*tree));
  tree->family = family;

  return tree;
}

void
patricia_clear(patricia_tree_t *tree, void (*data_cleanup)(void *))
{
  assert(tree);

  patricia_node_t *const root = tree->root;
  if (root == NULL)
    return;

  assert(root->parent == NULL);

  tree->root = NULL;

  patricia_node_t *stack[PATRICIA_MAX_BITLEN + 1];
  size_t stack_count = 0;

  stack[stack_count++] = root;

  const unsigned int max_bitlen = _patricia_family_max_bitlen(tree->family);
  assert(max_bitlen != 0);

  while (stack_count)
  {
    patricia_node_t *const node = stack[--stack_count];
    assert(node->bit_index <= max_bitlen);

    if (node->prefix)
    {
      assert(node->bit_index == node->prefix->bitlen);
      assert(_patricia_tree_accepts_prefix(tree, node->prefix));
    }
    else
    {
      assert(node->left);
      assert(node->right);
      assert(node->data == NULL);
    }

    if (node->left && node->right)
      assert(node->left != node->right);

    /*
     * Push right before left so the existing left-first preorder is
     * preserved.
     */
    if (node->right)
    {
      assert(node->right->parent == node);
      assert(node->right->bit_index > node->bit_index);
      assert(stack_count < sizeof(stack) / sizeof(*stack));

      stack[stack_count++] = node->right;
    }

    if (node->left)
    {
      assert(node->left->parent == node);
      assert(node->left->bit_index > node->bit_index);
      assert(stack_count < sizeof(stack) / sizeof(*stack));

      stack[stack_count++] = node->left;
    }

    if (node->prefix)
    {
      if (node->data && data_cleanup)
        data_cleanup(node->data);

      io_free(node->prefix);
    }

    io_free(node);
  }
}

void
patricia_destroy(patricia_tree_t *tree, void (*data_cleanup)(void *))
{
  patricia_clear(tree, data_cleanup);
  io_free(tree);
}

static const patricia_node_t *
_patricia_node_next_preorder(const patricia_node_t *node)
{
  assert(node);

  if (node->left)
  {
    assert(node->left->parent == node);
    assert(node->left->bit_index > node->bit_index);
    return node->left;
  }

  if (node->right)
  {
    assert(node->right->parent == node);
    assert(node->right->bit_index > node->bit_index);
    return node->right;
  }

  while (node->parent)
  {
    const patricia_node_t *const parent = node->parent;
    const bool is_left = parent->left == node;
    const bool is_right = parent->right == node;

    assert(is_left != is_right);
    assert(parent->bit_index < node->bit_index);

    if (is_left && parent->right)
    {
      assert(parent->right->parent == parent);
      assert(parent->right->bit_index > parent->bit_index);
      return parent->right;
    }

    node = parent;
  }

  return NULL;
}

void
patricia_foreach(const patricia_tree_t *tree, patricia_foreach_fn callback)
{
  assert(tree);
  assert(callback);

  if (tree->root)
    assert(tree->root->parent == NULL);

  for (const patricia_node_t *node = tree->root; node; )
  {
    const patricia_node_t *const next = _patricia_node_next_preorder(node);
    if (node->prefix)
      callback(node->prefix, node->data);

    node = next;
  }
}

patricia_node_t *
patricia_search_exact(const patricia_tree_t *tree, const patricia_prefix_t *prefix)
{
  assert(tree);
  assert(prefix);

  if (!_patricia_tree_accepts_prefix(tree, prefix))
    return NULL;

  patricia_node_t *node = tree->root;
  if (node == NULL)
    return NULL;

  assert(node->parent == NULL);

  const unsigned char *const prefix_bytes = _patricia_prefix_bytes(prefix);

  const unsigned int bitlen = prefix->bitlen;
  while (node->bit_index < bitlen)
  {
    patricia_node_t *const next =
      _patricia_prefix_bit_is_set(prefix_bytes, node->bit_index) ? node->right : node->left;
    if (next == NULL)
      return NULL;

    assert(next->parent == node);
    assert(next->bit_index > node->bit_index);

    node = next;
  }

  if (node->bit_index != bitlen)
    return NULL;

  if (node->prefix == NULL)
  {
    assert(node->left);
    assert(node->right);
    assert(node->data == NULL);
    return NULL;
  }

  assert(node->bit_index == node->prefix->bitlen);
  assert(_patricia_tree_accepts_prefix(tree, node->prefix));

  if (!_patricia_prefix_bits_equal(_patricia_prefix_bytes(node->prefix), prefix_bytes, bitlen))
    return NULL;

  return node;
}

patricia_node_t *
patricia_search_best2(const patricia_tree_t *tree, const patricia_prefix_t *prefix, bool include_exact)
{
  assert(tree);
  assert(prefix);

  if (!_patricia_tree_accepts_prefix(tree, prefix))
    return NULL;

  if (tree->root == NULL)
    return NULL;

  assert(tree->root->parent == NULL);

  const unsigned char *const prefix_bytes = _patricia_prefix_bytes(prefix);
  const unsigned int bitlen = prefix->bitlen;

  patricia_node_t *node = tree->root;
  while (node->bit_index < bitlen)
  {
    patricia_node_t *const next =
      _patricia_prefix_bit_is_set(prefix_bytes, node->bit_index) ? node->right : node->left;
    if (next == NULL)
      break;

    assert(next->parent == node);
    assert(next->bit_index > node->bit_index);

    node = next;
  }

  while (node)
  {
    if (node->prefix)
    {
      assert(node->bit_index == node->prefix->bitlen);

      const unsigned int candidate_bitlen = node->prefix->bitlen;
      if (candidate_bitlen <= bitlen &&
          (include_exact || candidate_bitlen < bitlen) &&
          _patricia_prefix_bits_equal(_patricia_prefix_bytes(node->prefix), prefix_bytes, candidate_bitlen))
        return node;
    }

    patricia_node_t *const parent = node->parent;
    if (parent)
    {
      assert(parent->bit_index < node->bit_index);
      assert((parent->left == node) != (parent->right == node));
    }

    node = parent;
  }

  return NULL;
}

patricia_node_t *
patricia_search_best(const patricia_tree_t *tree, const patricia_prefix_t *prefix)
{
  return patricia_search_best2(tree, prefix, true);
}

patricia_node_t *
patricia_lookup(patricia_tree_t *tree, const patricia_prefix_t *prefix)
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

  assert(tree->root->parent == NULL);

  const unsigned int max_bitlen = _patricia_family_max_bitlen(tree->family);
  const unsigned char *const prefix_bytes = _patricia_prefix_bytes(prefix);
  const unsigned int bitlen = prefix->bitlen;
  patricia_node_t *node = tree->root;

  while (node->bit_index < bitlen || node->prefix == NULL)
  {
    assert(node->bit_index <= max_bitlen);

    if (node->prefix == NULL)
    {
      assert(node->left);
      assert(node->right);
      assert(node->bit_index < max_bitlen);
    }

    patricia_node_t *next;

    if (node->bit_index < max_bitlen &&
        _patricia_prefix_bit_is_set(prefix_bytes, node->bit_index))
      next = node->right;
    else
      next = node->left;

    if (next == NULL)
      break;

    assert(next->parent == node);
    assert(next->bit_index > node->bit_index);

    node = next;
  }

  assert(node->prefix);
  assert(node->bit_index == node->prefix->bitlen);
  assert(_patricia_tree_accepts_prefix(tree, node->prefix));

  const unsigned char *const node_bytes = _patricia_prefix_bytes(node->prefix);
  const unsigned int compare_bitlen = node->bit_index < bitlen ? node->bit_index : bitlen;
  const unsigned int differing_bit =
    _patricia_prefix_first_differing_bit(prefix_bytes, node_bytes, compare_bitlen);

  assert(differing_bit <= compare_bitlen);

  while (node->parent && node->parent->bit_index >= differing_bit)
  {
    assert(node->parent->bit_index < node->bit_index);
    node = node->parent;
  }

  if (differing_bit == bitlen && node->bit_index == bitlen)
  {
    if (node->prefix)
      return node;

    assert(node->left);
    assert(node->right);
    assert(node->data == NULL);

    node->prefix = _patricia_prefix_dup(prefix);
    return node;
  }

  patricia_node_t *const new_node = io_calloc(sizeof(*new_node));
  new_node->bit_index = bitlen;
  new_node->prefix = _patricia_prefix_dup(prefix);

  if (node->bit_index == differing_bit)
  {
    /*
     * If the differing bit is already represented by this node, the
     * new prefix belongs in its currently empty branch.
     */
    assert(node->prefix);

    new_node->parent = node;

    if (node->bit_index < max_bitlen &&
        _patricia_prefix_bit_is_set(prefix_bytes, node->bit_index))
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

  if (bitlen == differing_bit)
  {
    /* The new prefix is an ancestor of the existing node. */
    if (bitlen < max_bitlen && _patricia_prefix_bit_is_set(node_bytes, bitlen))
      new_node->right = node;
    else
      new_node->left = node;

    _patricia_tree_replace_node(tree, node, new_node);
    node->parent = new_node;
  }
  else
  {
    /*
     * Neither prefix is an ancestor of the other. Insert a structural
     * branch node at their first differing bit.
     */
    assert(differing_bit < bitlen);
    assert(differing_bit < node->bit_index);

    patricia_node_t *const branch_node = io_calloc(sizeof(*branch_node));
    branch_node->bit_index = differing_bit;

    if (_patricia_prefix_bit_is_set(prefix_bytes, differing_bit))
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

    _patricia_tree_replace_node(tree, node, branch_node);
    node->parent = branch_node;
  }

  return new_node;
}

void
patricia_remove(patricia_tree_t *tree, patricia_node_t *node)
{
  assert(tree);
  assert(node);
  assert(node->prefix);

  if (node->left && node->right)
  {
    io_free(node->prefix);
    node->prefix = NULL;
    node->data = NULL;
    return;
  }

  if (node->left || node->right)
  {
    patricia_node_t *const child = node->left ? node->left : node->right;
    _patricia_tree_replace_node(tree, node, child);

    io_free(node->prefix);
    io_free(node);
    return;
  }

  patricia_node_t *const parent = node->parent;
  if (parent == NULL || parent->prefix)
    _patricia_tree_replace_node(tree, node, NULL);
  else
  {
    patricia_node_t *sibling;

    if (parent->left == node)
      sibling = parent->right;
    else
    {
      assert(parent->right == node);
      sibling = parent->left;
    }

    assert(sibling);

    _patricia_tree_replace_node(tree, parent, sibling);
    io_free(parent);
  }

  io_free(node->prefix);
  io_free(node);
}

patricia_node_t *
patricia_make_and_lookup(patricia_tree_t *tree, const char *prefix_string)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_string(&prefix, prefix_string))
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
patricia_lookup_then_remove(patricia_tree_t *tree, const char *prefix_string)
{
  patricia_node_t *const node = patricia_try_search_exact(tree, prefix_string);
  if (node == NULL)
    return false;

  patricia_remove(tree, node);
  return true;
}

patricia_node_t *
patricia_try_search_exact(const patricia_tree_t *tree, const char *prefix_string)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_string(&prefix, prefix_string))
    return NULL;

  return patricia_search_exact(tree, &prefix);
}

patricia_node_t *
patricia_try_search_best(const patricia_tree_t *tree, const char *prefix_string)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_string(&prefix, prefix_string))
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

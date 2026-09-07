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
  return (const unsigned char *)&prefix->add;
}

static bool
_patricia_prefix_bits_equal(const unsigned char *lhs, const unsigned char *rhs, unsigned int bitlen)
{
  if (bitlen == 0)
    return true;

  const size_t bytes = bitlen / 8;
  if (memcmp(lhs, rhs, bytes))
    return false;

  const unsigned int remaining = bitlen % 8;
  if (remaining == 0)
    return true;

  const unsigned char mask =
    (unsigned char)(0xFFU << (8 - remaining));

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

  patricia_prefix_t tmp =
  {
    .family = family,
    .bitlen = bitlen
  };

  switch (family)
  {
    case AF_INET:
      if (!address_to_bytes(addr, &tmp.add.sin, sizeof(tmp.add.sin)))
        return false;
      break;
    case AF_INET6:
      if (!address_to_bytes(addr, &tmp.add.sin6, sizeof(tmp.add.sin6)))
        return false;
      break;
    default:
      return false;
  }

  *prefix = tmp;
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
    const size_t length = slash - string;
    if (length >= sizeof(address_buf))
      return false;

    memcpy(address_buf, string, length);
    address_buf[length] = '\0';
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
      return address_from_bytes(addr, AF_INET, &prefix->add.sin, sizeof(prefix->add.sin));
    case AF_INET6:
      return address_from_bytes(addr, AF_INET6, &prefix->add.sin6, sizeof(prefix->add.sin6));
    default:
      return false;
  }
}

const char *
patricia_prefix_to_string(const patricia_prefix_t *prefix, bool with_len)
{
  static char buf[INET6_ADDRSTRLEN + sizeof("/128")];

  assert(prefix);
  assert((prefix->family == AF_INET  && prefix->bitlen <= PATRICIA_MAXBITS_IPV4) ||
         (prefix->family == AF_INET6 && prefix->bitlen <= PATRICIA_MAXBITS_IPV6));

  struct io_addr addr;
  if (!_patricia_prefix_to_addr(prefix, &addr))
    return NULL;

  if (!address_to_string(&addr, buf, sizeof(buf)))
    return NULL;

  if (with_len)
  {
    const size_t len = strlen(buf);
    snprintf(buf + len, sizeof(buf) - len, "/%u", prefix->bitlen);
  }

  return buf;
}

static patricia_prefix_t *
_patricia_prefix_ref(patricia_prefix_t *prefix)
{
  if (prefix == NULL)
    return NULL;

  if (prefix->ref_count == 0)
  {
    patricia_prefix_t *const copy = io_calloc(sizeof(*copy));
    *copy = *prefix;
    copy->ref_count = 1;

    return copy;
  }

  ++prefix->ref_count;
  return prefix;
}

static void
_patricia_prefix_unref(patricia_prefix_t *prefix)
{
  if (prefix == NULL)
    return;

  assert(prefix->ref_count > 0);

  if (--prefix->ref_count == 0)
    io_free(prefix);
}

/* these routines support continuous mask only */

patricia_tree_t *
patricia_new(int family)
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

  if (tree->head == NULL)
    return;

  patricia_node_t *Xstack[PATRICIA_MAXBITS + 1];
  patricia_node_t **Xsp = Xstack;

  patricia_node_t *Xrn = tree->head;
  while (Xrn)
  {
    patricia_node_t *l = Xrn->l;
    patricia_node_t *r = Xrn->r;

    if (Xrn->prefix)
    {
      _patricia_prefix_unref(Xrn->prefix);

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

  tree->head = NULL;
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
patricia_process(patricia_tree_t *tree, void (*func)(patricia_prefix_t *, void *))
{
  assert(func);

  patricia_node_t *node;
  PATRICIA_WALK(tree->head, node) {
    func(node->prefix, node->data);
  } PATRICIA_WALK_END;
}

patricia_node_t *
patricia_search_exact(patricia_tree_t *tree, patricia_prefix_t *prefix)
{
  assert(tree);
  assert(prefix);

  if (!_patricia_tree_accepts_prefix(tree, prefix))
    return NULL;

  if (tree->head == NULL)
    return NULL;

  patricia_node_t *node = tree->head;
  const unsigned char *const addr = _patricia_prefix_bytes(prefix);
  const unsigned int bitlen = prefix->bitlen;

  while (node->bit < bitlen)
  {
    if (BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
      node = node->r;
    else
      node = node->l;

    if (node == NULL)
      return NULL;
  }

  if (node->bit > bitlen || node->prefix == NULL)
    return NULL;

  assert(node->bit == bitlen);
  assert(node->bit == node->prefix->bitlen);

  if (_patricia_prefix_bits_equal(
        _patricia_prefix_bytes(node->prefix),
        _patricia_prefix_bytes(prefix), bitlen))
    return node;

  return NULL;
}

/* if inclusive != 0, "best" may be the given prefix itself */
patricia_node_t *
patricia_search_best2(patricia_tree_t *tree, patricia_prefix_t *prefix, bool inclusive)
{
  assert(tree);
  assert(prefix);

  if (!_patricia_tree_accepts_prefix(tree, prefix))
    return NULL;

  if (tree->head == NULL)
    return NULL;

  patricia_node_t *node = tree->head;
  patricia_node_t *stack[PATRICIA_MAXBITS + 1];
  const unsigned char *const addr = _patricia_prefix_bytes(prefix);
  const unsigned int bitlen = prefix->bitlen;
  int cnt = 0;

  while (node->bit < bitlen)
  {
    if (node->prefix)
      stack[cnt++] = node;

    if (BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
      node = node->r;
    else
      node = node->l;

    if (node == NULL)
      break;
  }

  if (inclusive && node && node->prefix)
    stack[cnt++] = node;

  if (cnt <= 0)
    return NULL;

  while (--cnt >= 0)
  {
    node = stack[cnt];

    if (node->prefix->bitlen <= bitlen &&
        _patricia_prefix_bits_equal(_patricia_prefix_bytes(node->prefix),
        _patricia_prefix_bytes(prefix), node->prefix->bitlen))
      return node;
  }

  return NULL;
}

patricia_node_t *
patricia_search_best(patricia_tree_t *tree, patricia_prefix_t *prefix)
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

  if (tree->head == NULL)
  {
    patricia_node_t *node = io_calloc(sizeof(*node));
    node->bit = prefix->bitlen;
    node->prefix = _patricia_prefix_ref(prefix);
    tree->head = node;

    return node;
  }

  const unsigned int maxbits = _patricia_family_maxbits(tree->family);
  const unsigned char *const addr = _patricia_prefix_bytes(prefix);
  const unsigned int bitlen = prefix->bitlen;
  patricia_node_t *node = tree->head;

  while (node->bit < bitlen || node->prefix == NULL)
  {
    if (node->bit < maxbits && BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
    {
      if (node->r == NULL)
        break;

      node = node->r;
    }
    else
    {
      if (node->l == NULL)
        break;

      node = node->l;
    }

    assert(node);
  }

  assert(node->prefix);

  const unsigned char *const test_addr = _patricia_prefix_bytes(node->prefix);

  /* Find the first bit different */
  unsigned int check_bit = node->bit < bitlen ? node->bit : bitlen;
  unsigned int differ_bit = 0;
  int j, r;

  for (unsigned int i = 0; i * 8 < check_bit; i++)
  {
    if ((r = (addr[i] ^ test_addr[i])) == 0)
    {
      differ_bit = (i + 1) * 8;
      continue;
    }

    /* I know the better way, but for now */
    for (j = 0; j < 8; j++)
      if (BIT_TEST(r, (0x80 >> j)))
        break;

    /* Must be found */
    assert(j < 8);
    differ_bit = i * 8 + j;
    break;
  }

  if (differ_bit > check_bit)
    differ_bit = check_bit;

  patricia_node_t *parent = node->parent;
  while (parent && parent->bit >= differ_bit)
  {
    node = parent;
    parent = node->parent;
  }

  if (differ_bit == bitlen && node->bit == bitlen)
  {
    if (node->prefix)
      return node;

    node->prefix = _patricia_prefix_ref(prefix);
    assert(node->data == NULL);

    return node;
  }

  patricia_node_t *new_node = io_calloc(sizeof(*new_node));
  new_node->bit = prefix->bitlen;
  new_node->prefix = _patricia_prefix_ref(prefix);

  if (node->bit == differ_bit)
  {
    new_node->parent = node;

    if (node->bit < maxbits && BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
    {
      assert(node->r == NULL);
      node->r = new_node;
    }
    else
    {
      assert(node->l == NULL);
      node->l = new_node;
    }

    return new_node;
  }

  if (bitlen == differ_bit)
  {
    if (bitlen < maxbits && BIT_TEST(test_addr[bitlen >> 3], 0x80 >> (bitlen & 0x07)))
      new_node->r = node;
    else
      new_node->l = node;

    new_node->parent = node->parent;

    if (node->parent == NULL)
    {
      assert(tree->head == node);
      tree->head = new_node;
    }
    else if (node->parent->r == node)
      node->parent->r = new_node;
    else
      node->parent->l = new_node;

    node->parent = new_node;
  }
  else
  {
    patricia_node_t *glue = io_calloc(sizeof(*glue));
    glue->bit = differ_bit;
    glue->parent = node->parent;

    if (differ_bit < maxbits && BIT_TEST(addr[differ_bit >> 3], 0x80 >> (differ_bit & 0x07)))
    {
      glue->r = new_node;
      glue->l = node;
    }
    else
    {
      glue->r = node;
      glue->l = new_node;
    }

    new_node->parent = glue;

    if (node->parent == NULL)
    {
      assert(tree->head == node);
      tree->head = glue;
    }
    else if (node->parent->r == node)
      node->parent->r = glue;
    else
      node->parent->l = glue;

    node->parent = glue;
  }

  return new_node;
}

void
patricia_remove(patricia_tree_t *tree, patricia_node_t *node)
{
  assert(tree);
  assert(node);

  if (node->r && node->l)
  {
    /*
     * This might be a placeholder node -- have to check and make sure
     * there is a prefix associated with it !
     */
    if (node->prefix)
      _patricia_prefix_unref(node->prefix);

    node->prefix = NULL;
    /* Also I needed to clear data pointer -- masaki */
    node->data = NULL;
    return;
  }

  patricia_node_t *parent, *child;
  if (node->r == NULL && node->l == NULL)
  {
    parent = node->parent;
    _patricia_prefix_unref(node->prefix);
    io_free(node);

    if (parent == NULL)
    {
      assert(tree->head == node);
      tree->head = NULL;
      return;
    }

    if (parent->r == node)
    {
      parent->r = NULL;
      child = parent->l;
    }
    else
    {
      assert(parent->l == node);

      parent->l = NULL;
      child = parent->r;
    }

    if (parent->prefix)
      return;

    /* We need to remove parent too */
    if (parent->parent == NULL)
    {
      assert(tree->head == parent);
      tree->head = child;
    }
    else if (parent->parent->r == parent)
      parent->parent->r = child;
    else
    {
      assert(parent->parent->l == parent);
      parent->parent->l = child;
    }

    child->parent = parent->parent;
    io_free(parent);
    return;
  }

  if (node->r)
    child = node->r;
  else
  {
    assert(node->l);
    child = node->l;
  }

  parent = node->parent;
  child->parent = parent;

  _patricia_prefix_unref(node->prefix);
  io_free(node);

  if (parent == NULL)
  {
    assert(tree->head == node);
    tree->head = child;
    return;
  }

  if (parent->r == node)
    parent->r = child;
  else
  {
    assert(parent->l == node);
    parent->l = child;
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

void
patricia_lookup_then_remove(patricia_tree_t *tree, const char *string)
{
  patricia_node_t *node = patricia_try_search_exact(tree, string);
  if (node)
    patricia_remove(tree, node);
}

patricia_node_t *
patricia_try_search_exact(patricia_tree_t *tree, const char *string)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_string(&prefix, string))
    return NULL;

  return patricia_search_exact(tree, &prefix);
}

patricia_node_t *
patricia_try_search_best(patricia_tree_t *tree, const char *string)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_string(&prefix, string))
    return NULL;

  return patricia_search_best(tree, &prefix);
}

patricia_node_t *
patricia_try_search_exact_addr(patricia_tree_t *tree, const struct io_addr *addr, unsigned int bitlen)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_addr(&prefix, addr, bitlen))
    return NULL;

  return patricia_search_exact(tree, &prefix);
}

patricia_node_t *
patricia_try_search_best_addr(patricia_tree_t *tree, const struct io_addr *addr, unsigned int bitlen)
{
  patricia_prefix_t prefix;
  if (!_patricia_prefix_init_from_addr(&prefix, addr, bitlen))
    return NULL;

  return patricia_search_best(tree, &prefix);
}

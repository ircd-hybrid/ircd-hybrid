/*
 * $Id: patricia.c 8630 2018-11-03 19:27:05Z michael $
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

#include <assert.h> /* assert */
#include <stddef.h> /* NULL */
#include <stdio.h> /* sprintf, fprintf, stderr */
#include <stdlib.h> /* free, atol, calloc */
#include <string.h> /* memcpy, strchr, strlen */
#include <sys/types.h> /* BSD: for inet_addr */
#include <sys/socket.h> /* BSD, Linux: for inet_addr */
#include <netinet/in.h> /* BSD, Linux: for inet_addr */
#include <arpa/inet.h> /* BSD, Linux, Solaris: for inet_addr */

#include "patricia.h"
#include "memory.h"

/* { from prefix.c */

/* prefix_tochar
 * convert prefix information to bytes
 */
static unsigned char *
prefix_tochar(prefix_t *prefix)
{
  if (prefix == NULL)
    return NULL;
  return (unsigned char *)&prefix->add.sin;
}

static int
comp_with_mask(void *addr, void *dest, unsigned int mask)
{
  if ( /* mask/8 == 0 || */ memcmp(addr, dest, mask / 8) == 0)
  {
    int n = mask / 8;
    int m = ~((1 << (8 - (mask % 8))) - 1);

    if (mask % 8 == 0 || (((unsigned char *)addr)[n] & m) == (((unsigned char *)dest)[n] & m))
      return 1;
  }

  return 0;
}

/*
 * convert prefix information to ascii string with length
 */
const char *
patricia_prefix_toa(const prefix_t *prefix, int with_len)
{
  static char buf[INET6_ADDRSTRLEN + sizeof("/128")];

  assert(prefix);
  assert(prefix->ref_count >= 0);
  assert((prefix->family == AF_INET  && prefix->bitlen <=  32) ||
         (prefix->family == AF_INET6 && prefix->bitlen <= 128));

  inet_ntop(prefix->family, &prefix->add.sin6, buf, INET6_ADDRSTRLEN);

  if (with_len)
    sprintf(buf + strlen(buf), "/%d", prefix->bitlen);
  return buf;
}

static prefix_t *
New_Prefix2(int family, void *dest, int bitlen, prefix_t *prefix)
{
  int dynamic_allocated = 0;
  int addr_size = 0;

  switch (family)
  {
    case AF_INET:
      addr_size = sizeof(struct in_addr);
      break;
    case AF_INET6:
      addr_size = sizeof(struct in6_addr);
      break;
    default: return NULL;
  }

  if (prefix == NULL)
  {
    prefix = xcalloc(sizeof(*prefix));
    dynamic_allocated = 1;
  }

  memcpy(&prefix->add.sin6, dest, addr_size);
  prefix->bitlen = (bitlen >= 0) ? bitlen : addr_size * 8;
  prefix->family = family;
  prefix->ref_count = dynamic_allocated == 1;

/* fprintf(stderr, "[C %s, %d]\n", patricia_prefix_toa(prefix), prefix->ref_count); */
  return prefix;
}

static prefix_t *
New_Prefix(int family, void *dest, int bitlen)
{
  return New_Prefix2(family, dest, bitlen, NULL);
}

/* ascii2prefix
 */
static prefix_t *
ascii2prefix(int family, const char *string)
{
  char save[INET6_ADDRSTRLEN];
  int bitlen, maxbitlen = 0;
  union
  {
    struct in_addr sin;
    struct in6_addr sin6;
  } sin;

  assert(string);

  /* Easy way to handle both families */
  if (family == 0)
  {
    family = AF_INET;

    if (strchr(string, ':'))
      family = AF_INET6;
  }

  if (family == AF_INET)
    maxbitlen = sizeof(struct in_addr)  * 8;
  else if (family == AF_INET6)
    maxbitlen = sizeof(struct in6_addr) * 8;

  const char *const cp = strchr(string, '/');
  if (cp)
  {
    size_t length = cp - string;

    if (length >= sizeof(save))
      return NULL;

    bitlen = atoi(cp + 1);

    /* Copy the string to save. Avoid destroying the string */
    memcpy(save, string, length);
    save[length] = '\0';

    string = save;

    if (bitlen < 0 || bitlen > maxbitlen)
      bitlen = maxbitlen;
  }
  else
    bitlen = maxbitlen;

  if (inet_pton(family, string, &sin) <= 0)
    return NULL;
  return New_Prefix(family, &sin, bitlen);
}

static prefix_t *
Ref_Prefix(prefix_t *prefix)
{
  if (prefix == NULL)
    return NULL;

  if (prefix->ref_count == 0)
    /* Make a copy in case of a static prefix */
    return New_Prefix2(prefix->family, &prefix->add, prefix->bitlen, NULL);

  prefix->ref_count++;

/* fprintf(stderr, "[A %s, %d]\n", patricia_prefix_toa(prefix), prefix->ref_count); */
  return prefix;
}

static void
Deref_Prefix(prefix_t *prefix)
{
  if (prefix == NULL)
    return;

  /* For secure programming, raise an assert. No static prefix can call this */
  assert(prefix->ref_count > 0);
  if (--prefix->ref_count <= 0)
    xfree(prefix);
}
/* } */

/* #define PATRICIA_DEBUG 1 */

/* these routines support continuous mask only */

patricia_tree_t *
patricia_new(unsigned int maxbits)
{
  patricia_tree_t *patricia = xcalloc(sizeof(*patricia));
  patricia->maxbits = maxbits;

  assert(maxbits <= PATRICIA_MAXBITS);  /* XXX */
  return patricia;
}

/*
 * if func is supplied, it will be called as func(node->data)
 * before deleting the node
 */
void
patricia_clear(patricia_tree_t *patricia, void (*func)(void *))
{
  assert(patricia);

  if (patricia->head)
  {
    patricia_node_t *Xstack[PATRICIA_MAXBITS + 1];
    patricia_node_t **Xsp = Xstack;
    patricia_node_t *Xrn = patricia->head;

    while (Xrn)
    {
      patricia_node_t *l = Xrn->l;
      patricia_node_t *r = Xrn->r;

      if (Xrn->prefix)
      {
        Deref_Prefix(Xrn->prefix);

        if (Xrn->data && func)
          func(Xrn->data);
      }
      else
      {
        assert(Xrn->data == NULL);
      }

      xfree(Xrn);
      patricia->num_active_node--;

      if (l)
      {
        if (r)
        {
          *Xsp++ = r;
        }

        Xrn = l;
      }
      else if (r)
      {
        Xrn = r;
      }
      else if (Xsp != Xstack)
      {
        Xrn = *(--Xsp);
      }
      else
      {
        Xrn = NULL;
      }
    }
  }

  patricia->head = NULL;

  assert(patricia->num_active_node == 0);
}

void
patricia_destroy(patricia_tree_t *patricia, void (*func)(void *))
{
  patricia_clear(patricia, func);
  xfree(patricia);
}

/*
 * if func is supplied, it will be called as func(node->prefix, node->data)
 */
void
patricia_process(patricia_tree_t *patricia, void (*func)(prefix_t *, void *))
{
  patricia_node_t *node;

  assert(func);

  PATRICIA_WALK(patricia->head, node) {
    func(node->prefix, node->data);
  } PATRICIA_WALK_END;
}

patricia_node_t *
patricia_search_exact(patricia_tree_t *patricia, prefix_t *prefix)
{
  patricia_node_t *node;
  unsigned char *addr;
  unsigned int bitlen;

  assert(patricia);
  assert(prefix);
  assert(prefix->bitlen <= patricia->maxbits);

  if (patricia->head == NULL)
    return NULL;

  node = patricia->head;
  addr = prefix_touchar(prefix);
  bitlen = prefix->bitlen;

  while (node->bit < bitlen)
  {
    if (BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
    {
#ifdef PATRICIA_DEBUG
      if (node->prefix)
        fprintf(stderr, "patricia_search_exact: take right %s/%d\n",
                patricia_prefix_toa(node->prefix), node->prefix->bitlen);
      else
        fprintf(stderr, "patricia_search_exact: take right at %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */
      node = node->r;
    }
    else
    {
#ifdef PATRICIA_DEBUG
      if (node->prefix)
        fprintf(stderr, "patricia_search_exact: take left %s/%d\n",
                patricia_prefix_toa(node->prefix), node->prefix->bitlen);
      else
        fprintf(stderr, "patricia_search_exact: take left at %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */
      node = node->l;
    }

    if (node == NULL)
      return NULL;
  }

#ifdef PATRICIA_DEBUG
  if (node->prefix)
    fprintf(stderr, "patricia_search_exact: stop at %s/%d\n",
            patricia_prefix_toa(node->prefix), node->prefix->bitlen);
  else
    fprintf(stderr, "patricia_search_exact: stop at %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */

  if (node->bit > bitlen || node->prefix == NULL)
    return NULL;

  assert(node->bit == bitlen);
  assert(node->bit == node->prefix->bitlen);

  if (comp_with_mask(prefix_tochar(node->prefix), prefix_tochar(prefix), bitlen))
  {
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_search_exact: found %s/%d\n",
            patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif  /* PATRICIA_DEBUG */
    return node;
  }

  return NULL;
}

/* if inclusive != 0, "best" may be the given prefix itself */
patricia_node_t *
patricia_search_best2(patricia_tree_t *patricia, prefix_t *prefix, int inclusive)
{
  patricia_node_t *node;
  patricia_node_t *stack[PATRICIA_MAXBITS + 1];
  unsigned char *addr;
  unsigned int bitlen;
  int cnt = 0;

  assert(patricia);
  assert(prefix);
  assert(prefix->bitlen <= patricia->maxbits);

  if (patricia->head == NULL)
    return NULL;

  node = patricia->head;
  addr = prefix_touchar(prefix);
  bitlen = prefix->bitlen;

  while (node->bit < bitlen)
  {
    if (node->prefix)
    {
#ifdef PATRICIA_DEBUG
      fprintf(stderr, "patricia_search_best: push %s/%d\n",
              patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif  /* PATRICIA_DEBUG */
      stack[cnt++] = node;
    }

    if (BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
    {
#ifdef PATRICIA_DEBUG
      if (node->prefix)
        fprintf(stderr, "patricia_search_best: take right %s/%d\n",
                patricia_prefix_toa(node->prefix), node->prefix->bitlen);
      else
        fprintf(stderr, "patricia_search_best: take right at %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */
      node = node->r;
    }
    else
    {
#ifdef PATRICIA_DEBUG
      if (node->prefix)
        fprintf(stderr, "patricia_search_best: take left %s/%d\n",
                patricia_prefix_toa(node->prefix), node->prefix->bitlen);
      else
        fprintf(stderr, "patricia_search_best: take left at %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */
      node = node->l;
    }

    if (node == NULL)
      break;
  }

  if (inclusive && node && node->prefix)
    stack[cnt++] = node;

#ifdef PATRICIA_DEBUG
  if (node == NULL)
    fprintf(stderr, "patricia_search_best: stop at null\n");
  else if (node->prefix)
    fprintf(stderr, "patricia_search_best: stop at %s/%d\n",
            patricia_prefix_toa(node->prefix), node->prefix->bitlen);
  else
    fprintf(stderr, "patricia_search_best: stop at %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */

  if (cnt <= 0)
    return NULL;

  while (--cnt >= 0)
  {
    node = stack[cnt];
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_search_best: pop %s/%d\n",
           patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif  /* PATRICIA_DEBUG */

    if (comp_with_mask(prefix_tochar(node->prefix),
                       prefix_tochar(prefix), node->prefix->bitlen) && node->prefix->bitlen <= bitlen)
    {
#ifdef PATRICIA_DEBUG
      fprintf(stderr, "patricia_search_best: found %s/%d\n",
              patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif  /* PATRICIA_DEBUG */
      return node;
    }
  }

  return NULL;
}

patricia_node_t *
patricia_search_best(patricia_tree_t *patricia, prefix_t *prefix)
{
  return patricia_search_best2(patricia, prefix, 1);
}

patricia_node_t *
patricia_lookup(patricia_tree_t *patricia, prefix_t *prefix)
{
  patricia_node_t *node, *new_node, *parent, *glue;
  unsigned char *addr, *test_addr;
  unsigned int bitlen, check_bit, differ_bit;
  int j, r;

  assert(patricia);
  assert(prefix);
  assert(prefix->bitlen <= patricia->maxbits);

  if (patricia->head == NULL)
  {
    node = xcalloc(sizeof(*node));
    node->bit = prefix->bitlen;
    node->prefix = Ref_Prefix(prefix);
    patricia->head = node;
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_lookup: new_node #0 %s/%d (head)\n",
            patricia_prefix_toa(prefix), prefix->bitlen);
#endif  /* PATRICIA_DEBUG */
    patricia->num_active_node++;
    return node;
  }

  addr = prefix_touchar(prefix);
  bitlen = prefix->bitlen;
  node = patricia->head;

  while (node->bit < bitlen || node->prefix == NULL)
  {
    if (node->bit < patricia->maxbits && BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
    {
      if (node->r == NULL)
        break;
#ifdef PATRICIA_DEBUG
      if (node->prefix)
        fprintf(stderr, "patricia_lookup: take right %s/%d\n",
                patricia_prefix_toa(node->prefix), node->prefix->bitlen);
      else
        fprintf(stderr, "patricia_lookup: take right at %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */

      node = node->r;
    }
    else
    {
      if (node->l == NULL)
        break;
#ifdef PATRICIA_DEBUG
      if (node->prefix)
        fprintf(stderr, "patricia_lookup: take left %s/%d\n",
                patricia_prefix_toa(node->prefix), node->prefix->bitlen);
      else
        fprintf(stderr, "patricia_lookup: take left at %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */

      node = node->l;
    }

    assert(node);
  }

  assert(node->prefix);
#ifdef PATRICIA_DEBUG
  fprintf(stderr, "patricia_lookup: stop at %s/%d\n",
          patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif /* PATRICIA_DEBUG */

  test_addr = prefix_touchar(node->prefix);

  /* Find the first bit different */
  check_bit = (node->bit < bitlen) ? node->bit : bitlen;
  differ_bit = 0;

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
#ifdef PATRICIA_DEBUG
  fprintf(stderr, "patricia_lookup: differ_bit %d\n", differ_bit);
#endif  /* PATRICIA_DEBUG */

  parent = node->parent;

  while (parent && parent->bit >= differ_bit)
  {
    node = parent;
    parent = node->parent;

#ifdef PATRICIA_DEBUG
    if (node->prefix)
      fprintf(stderr, "patricia_lookup: up to %s/%d\n",
              patricia_prefix_toa(node->prefix), node->prefix->bitlen);
    else
      fprintf(stderr, "patricia_lookup: up to %u\n", node->bit);
#endif  /* PATRICIA_DEBUG */
  }

  if (differ_bit == bitlen && node->bit == bitlen)
  {
    if (node->prefix)
    {
#ifdef PATRICIA_DEBUG
      fprintf(stderr, "patricia_lookup: found %s/%d\n",
              patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif  /* PATRICIA_DEBUG */

      return node;
    }

    node->prefix = Ref_Prefix(prefix);
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_lookup: new node #1 %s/%d (glue mod)\n",
            patricia_prefix_toa(prefix), prefix->bitlen);
#endif  /* PATRICIA_DEBUG */

    assert(node->data == NULL);
    return node;
  }

  new_node = xcalloc(sizeof(*new_node));
  new_node->bit = prefix->bitlen;
  new_node->prefix = Ref_Prefix(prefix);
  patricia->num_active_node++;

  if (node->bit == differ_bit)
  {
    new_node->parent = node;

    if (node->bit < patricia->maxbits && BIT_TEST(addr[node->bit >> 3], 0x80 >> (node->bit & 0x07)))
    {
      assert(node->r == NULL);
      node->r = new_node;
    }
    else
    {
      assert(node->l == NULL);
      node->l = new_node;
    }
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_lookup: new_node #2 %s/%d (child)\n",
            patricia_prefix_toa(prefix), prefix->bitlen);
#endif  /* PATRICIA_DEBUG */
    return new_node;
  }

  if (bitlen == differ_bit)
  {
    if (bitlen < patricia->maxbits && BIT_TEST(test_addr[bitlen >> 3], 0x80 >> (bitlen & 0x07)))
    {
      new_node->r = node;
    }
    else
    {
      new_node->l = node;
    }

    new_node->parent = node->parent;

    if (node->parent == NULL)
    {
      assert(patricia->head == node);
      patricia->head = new_node;
    }
    else if (node->parent->r == node)
    {
      node->parent->r = new_node;
    }
    else
    {
      node->parent->l = new_node;
    }

    node->parent = new_node;
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_lookup: new_node #3 %s/%d (parent)\n",
            patricia_prefix_toa(prefix), prefix->bitlen);
#endif  /* PATRICIA_DEBUG */
  }
  else
  {
    glue = xcalloc(sizeof(*glue));
    glue->bit = differ_bit;
    glue->parent = node->parent;
    patricia->num_active_node++;

    if (differ_bit < patricia->maxbits && BIT_TEST(addr[differ_bit >> 3], 0x80 >> (differ_bit & 0x07)))
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
      assert(patricia->head == node);
      patricia->head = glue;
    }
    else if (node->parent->r == node)
    {
      node->parent->r = glue;
    }
    else
    {
      node->parent->l = glue;
    }

    node->parent = glue;
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_lookup: new_node #4 %s/%d (glue+node)\n",
            patricia_prefix_toa(prefix), prefix->bitlen);
#endif  /* PATRICIA_DEBUG */
  }

  return new_node;
}

void
patricia_remove(patricia_tree_t *patricia, patricia_node_t *node)
{
  patricia_node_t *parent, *child;

  assert(patricia);
  assert(node);

  if (node->r && node->l)
  {
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_remove: #0 %s/%d (r & l)\n",
            patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif  /* PATRICIA_DEBUG */

    /*
     * This might be a placeholder node -- have to check and make sure
     * there is a prefix associated with it !
     */
    if (node->prefix)
      Deref_Prefix(node->prefix);

    node->prefix = NULL;
    /* Also I needed to clear data pointer -- masaki */
    node->data = NULL;
    return;
  }

  if (node->r == NULL && node->l == NULL)
  {
#ifdef PATRICIA_DEBUG
    fprintf(stderr, "patricia_remove: #1 %s/%d (!r & !l)\n",
            patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif  /* PATRICIA_DEBUG */

    parent = node->parent;
    Deref_Prefix(node->prefix);
    xfree(node);
    patricia->num_active_node--;

    if (parent == NULL)
    {
      assert(patricia->head == node);
      patricia->head = NULL;
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
      assert(patricia->head == parent);
      patricia->head = child;
    }
    else if (parent->parent->r == parent)
    {
      parent->parent->r = child;
    }
    else
    {
      assert(parent->parent->l == parent);
      parent->parent->l = child;
    }

    child->parent = parent->parent;
    xfree(parent);
    patricia->num_active_node--;
    return;
  }

#ifdef PATRICIA_DEBUG
  fprintf(stderr, "patricia_remove: #2 %s/%d (r ^ l)\n",
          patricia_prefix_toa(node->prefix), node->prefix->bitlen);
#endif  /* PATRICIA_DEBUG */

  if (node->r)
  {
    child = node->r;
  }
  else
  {
    assert(node->l);
    child = node->l;
  }

  parent = node->parent;
  child->parent = parent;

  Deref_Prefix(node->prefix);
  xfree(node);
  patricia->num_active_node--;

  if (parent == NULL)
  {
    assert(patricia->head == node);
    patricia->head = child;
    return;
  }

  if (parent->r == node)
  {
    parent->r = child;
  }
  else
  {
    assert(parent->l == node);
    parent->l = child;
  }
}

/* { from demo.c */
patricia_node_t *
patricia_make_and_lookup(patricia_tree_t *tree, const char *string)
{
  prefix_t *prefix = ascii2prefix(0, string);

  if (prefix)
  {
    patricia_node_t *node = patricia_lookup(tree, prefix);
    Deref_Prefix(prefix);
    return node;
  }

  return NULL;
}

patricia_node_t *
patricia_make_and_lookup_addr(patricia_tree_t *tree, struct sockaddr *addr, int bitlen)
{
  int family;
  void *dest;

  if (addr->sa_family == AF_INET6)
  {
    if (bitlen == 0 || bitlen > 128)
      bitlen = 128;
    family = AF_INET6;
    dest = &((struct sockaddr_in6 *)addr)->sin6_addr;
  }
  else
  {
    if (bitlen == 0 || bitlen > 32)
      bitlen = 32;
    family = AF_INET;
    dest = &((struct sockaddr_in *)addr)->sin_addr;
  }

  prefix_t *prefix = New_Prefix(family, dest, bitlen);
  if (prefix)
  {
    patricia_node_t *node = patricia_lookup(tree, prefix);
    Deref_Prefix(prefix);
    return node;
  }

  return NULL;
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
  prefix_t *prefix = ascii2prefix(0, string);

  if (prefix)
  {
    patricia_node_t *node = patricia_search_exact(tree, prefix);
    Deref_Prefix(prefix);
    return node;
  }

  return NULL;
}

patricia_node_t *
patricia_try_search_best(patricia_tree_t *tree, const char *string)
{
  prefix_t *prefix = ascii2prefix(0, string);

  if (prefix)
  {
    patricia_node_t *node = patricia_search_best(tree, prefix);
    Deref_Prefix(prefix);
    return node;
  }

  return NULL;
}

patricia_node_t *
patricia_try_search_exact_addr(patricia_tree_t *tree, struct sockaddr *addr, int bitlen)
{
  int family;
  void *dest;

  if (addr->sa_family == AF_INET6)
  {
    if (bitlen == 0 || bitlen > 128)
      bitlen = 128;
    family = AF_INET6;
    dest = &((struct sockaddr_in6 *)addr)->sin6_addr;
  }
  else
  {
    if (bitlen == 0 || bitlen > 32)
      bitlen = 32;
    family = AF_INET;
    dest = &((struct sockaddr_in *)addr)->sin_addr;
  }

  prefix_t *prefix = New_Prefix(family, dest, bitlen);
  if (prefix)
  {
    patricia_node_t *node = patricia_search_exact(tree, prefix);
    Deref_Prefix(prefix);
    return node;
  }

  return NULL;
}

patricia_node_t *
patricia_try_search_best_addr(patricia_tree_t *tree, struct sockaddr *addr, int bitlen)
{
  int family;
  void *dest;

  if (addr->sa_family == AF_INET6)
  {
    if (bitlen == 0 || bitlen > 128)
      bitlen = 128;
    family = AF_INET6;
    dest = &((struct sockaddr_in6 *)addr)->sin6_addr;
  }
  else
  {
    if (bitlen == 0 || bitlen > 32)
      bitlen = 32;
    family = AF_INET;
    dest = &((struct sockaddr_in *)addr)->sin_addr;
  }

  prefix_t *prefix = New_Prefix(family, dest, bitlen);
  if (prefix)
  {
    patricia_node_t *node = patricia_search_best(tree, prefix);
    Deref_Prefix(prefix);
    return node;
  }

  return NULL;
}
/* } */

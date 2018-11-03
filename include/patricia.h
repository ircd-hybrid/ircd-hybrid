/*
 * $Id$
 * Dave Plonka <plonka@doit.wisc.edu>
 *
 * This file had been called "radix.h" in the MRT sources.
 *
 * I renamed it to "patricia.h" since it's not an implementation of a general
 * radix trie.  Also, pulled in various requirements from "mrt.h" and added
 * some other things it could be used as a standalone API.
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

#ifndef _PATRICIA_H
#define _PATRICIA_H

/* { from defs.h */
#define prefix_touchar(prefix) ((unsigned char *)&(prefix)->add.sin)
#define BIT_TEST(f, b)  ((f) & (b))
/* } */

#include <netinet/in.h>  /* for struct in_addr */
#include <sys/socket.h>  /* for AF_INET */

/* { from mrt.h */
typedef struct _prefix_t
{
  unsigned short family;  /* AF_INET | AF_INET6 */
  unsigned short bitlen;  /* same as mask? */
  int ref_count;  /* reference count */

  union
  {
    struct in_addr sin;
    struct in6_addr sin6;
  } add;
} prefix_t;
/* } */

typedef struct _patricia_node_t
{
  unsigned int bit;  /* flag if this node used */
  prefix_t *prefix;  /* who we are in patricia tree */
  struct _patricia_node_t *l, *r;  /* left and right children */
  struct _patricia_node_t *parent;  /* may be used */
  void *data;  /* pointer to data */
} patricia_node_t;

typedef struct _patricia_tree_t
{
  patricia_node_t *head;
  unsigned int maxbits;  /* for IP, 32 bit addresses */
  int num_active_node;  /* for debug purpose */
} patricia_tree_t;


extern patricia_node_t *patricia_search_exact(patricia_tree_t *, prefix_t *);
extern patricia_node_t *patricia_search_best(patricia_tree_t *, prefix_t *);
extern patricia_node_t *patricia_search_best2(patricia_tree_t *, prefix_t *, int);
extern patricia_node_t *patricia_lookup(patricia_tree_t *, prefix_t *);
extern void patricia_remove(patricia_tree_t *, patricia_node_t *);
extern patricia_tree_t *patricia_new(unsigned int);
extern void patricia_clear(patricia_tree_t *, void (*)(void *));
extern void patricia_destroy(patricia_tree_t *, void (*)(void *));
extern void patricia_process(patricia_tree_t *, void (*)(prefix_t *, void *));
extern const char *patricia_prefix_toa(const prefix_t *, int);
extern void patricia_lookup_then_remove(patricia_tree_t *, const char *);
extern patricia_node_t *patricia_try_search_exact(patricia_tree_t *, const char *);
extern patricia_node_t *patricia_try_search_best(patricia_tree_t *, const char *);
extern patricia_node_t *patricia_try_search_exact_addr(patricia_tree_t *, struct sockaddr *, int);
extern patricia_node_t *patricia_try_search_best_addr(patricia_tree_t *, struct sockaddr *, int);

/* { from demo.c */
extern patricia_node_t *patricia_make_and_lookup(patricia_tree_t *, const char *);
extern patricia_node_t *patricia_make_and_lookup_addr(patricia_tree_t *, struct sockaddr *, int);
/* } */

#define PATRICIA_MAXBITS   (sizeof(struct in6_addr) * 8)
#define PATRICIA_NBIT(x)   (0x80 >> ((x) & 0x7f))
#define PATRICIA_NBYTE(x)  ((x) >> 3)

#define PATRICIA_DATA_GET(node, type) (type *)((node)->data)
#define PATRICIA_DATA_SET(node, value) ((node)->data = (void *)(value))

#define PATRICIA_WALK(Xhead, Xnode) \
  do { \
    patricia_node_t *Xstack[PATRICIA_MAXBITS + 1]; \
    patricia_node_t **Xsp = Xstack; \
    patricia_node_t *Xrn = (Xhead); \
    while ((Xnode = Xrn)) { \
      if (Xnode->prefix)

#define PATRICIA_WALK_ALL(Xhead, Xnode) \
  do { \
    patricia_node_t *Xstack[PATRICIA_MAXBITS + 1]; \
    patricia_node_t **Xsp = Xstack; \
    patricia_node_t *Xrn = (Xhead); \
    while ((Xnode = Xrn)) { \
      if (1)

#define PATRICIA_WALK_BREAK { \
  if (Xsp != Xstack) { \
    Xrn = *(--Xsp); \
  } else { \
    Xrn = (patricia_node_t *)0; \
  } \
  continue; }

#define PATRICIA_WALK_END \
    if (Xrn->l) { \
      if (Xrn->r) { \
        *Xsp++ = Xrn->r; \
      } \
      Xrn = Xrn->l; \
    } else if (Xrn->r) { \
      Xrn = Xrn->r; \
    } else if (Xsp != Xstack) { \
      Xrn = *(--Xsp); \
    } else { \
      Xrn = (patricia_node_t *)0; \
    } \
  } \
} while (0)

#endif

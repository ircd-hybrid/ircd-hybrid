/*
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

#ifndef INCLUDED_patricia_h
#define INCLUDED_patricia_h
#include <stdbool.h>
#include <stddef.h>
#include <netinet/in.h>

struct io_addr;

typedef struct patricia_prefix
{
  int family;
  unsigned int bitlen;

  union
  {
    struct in_addr ipv4;
    struct in6_addr ipv6;
  } addr;
} patricia_prefix_t;

typedef struct patricia_node
{
  patricia_prefix_t *prefix;
  void *data;
  struct patricia_node *parent;
  struct patricia_node *left;
  struct patricia_node *right;
  unsigned int bit_index;
} patricia_node_t;

typedef struct patricia_tree
{
  patricia_node_t *root;
  int family;
} patricia_tree_t;

typedef void (*patricia_data_cleanup_fn)(void *);
typedef void (*patricia_foreach_fn)(const patricia_prefix_t *, void *);

extern void patricia_clear(patricia_tree_t *, patricia_data_cleanup_fn);
extern void patricia_destroy(patricia_tree_t *, patricia_data_cleanup_fn);
extern void patricia_foreach(const patricia_tree_t *, patricia_foreach_fn);
extern void patricia_node_set_data(patricia_node_t *, void *);
extern void patricia_remove(patricia_tree_t *, patricia_node_t *);
extern bool patricia_lookup_then_remove(patricia_tree_t *, const char *);
extern bool patricia_prefix_to_string(const patricia_prefix_t *, char *, size_t, bool);
extern void *patricia_node_get_data(const patricia_node_t *);
extern patricia_node_t *patricia_lookup(patricia_tree_t *, const patricia_prefix_t *);
extern patricia_node_t *patricia_make_and_lookup(patricia_tree_t *, const char *);
extern patricia_node_t *patricia_make_and_lookup_addr(patricia_tree_t *, const struct io_addr *, unsigned int);
extern patricia_node_t *patricia_search_best(const patricia_tree_t *, const patricia_prefix_t *);
extern patricia_node_t *patricia_search_best2(const patricia_tree_t *, const patricia_prefix_t *, bool);
extern patricia_node_t *patricia_search_exact(const patricia_tree_t *, const patricia_prefix_t *);
extern patricia_node_t *patricia_try_search_best(const patricia_tree_t *, const char *);
extern patricia_node_t *patricia_try_search_best_addr(const patricia_tree_t *, const struct io_addr *, unsigned int);
extern patricia_node_t *patricia_try_search_exact(const patricia_tree_t *, const char *);
extern patricia_node_t *patricia_try_search_exact_addr(const patricia_tree_t *, const struct io_addr *, unsigned int);
extern patricia_tree_t *patricia_create(int);
#endif  /* INCLUDED_patricia_h */

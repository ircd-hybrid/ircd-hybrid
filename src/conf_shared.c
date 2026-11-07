/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf_shared.c
 * \brief Implements shared {} block configuration management.
 */

#include <assert.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "conf_shared.h"

static list_t shared_list;

const list_t *
shared_get_list(void)
{
  return &shared_list;
}

void
shared_clear(void)
{
  list_node_t *node;

  while ((node = list_pop_head(&shared_list)))
  {
    struct SharedItem *const shared = node->data;
    assert(shared);

    io_free(shared->server);
    io_free(shared->user);
    io_free(shared->host);
    io_free(shared);
  }
}

struct SharedItem *
shared_make(void)
{
  struct SharedItem *const shared = io_calloc(sizeof(*shared));
  list_add_tail(shared, &shared->node, &shared_list);

  return shared;
}

const struct SharedItem *
shared_find(uint32_t type, const char *server, const char *user, const char *host)
{
  list_node_t *node;

  LIST_FOREACH(node, shared_list.head)
  {
    const struct SharedItem *const shared = node->data;
    if (shared->type & type)
      if (match(shared->server, server) == 0)
        if (match(shared->user, user) == 0 && match(shared->host, host) == 0)
          return shared;
  }

  return NULL;
}

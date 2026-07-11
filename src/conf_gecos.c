/*
 * SPDX-FileCopyrightText: 1998-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf_gecos.c
 * \brief Implements gecos {} block configuration management.
 */

#include <stdbool.h>
#include <stddef.h>

#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "client.h"
#include "conf_gecos.h"
#include "send.h"

static list_t gecos_list;

const list_t *
gecos_get_list(void)
{
  return &gecos_list;
}

void
gecos_clear(void)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, gecos_list.head)
  {
    struct GecosItem *const gecos = node->data;
    if (gecos->in_database == false)
      gecos_delete(gecos, false);
  }
}

void
gecos_delete(struct GecosItem *gecos, bool expired)
{
  if (expired)
    sendto_clients(UMODE_EXPIRATION, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Temporary X-line for [%s] expired",
                   gecos->mask);

  list_remove(&gecos->node, &gecos_list);
  io_free(gecos->mask);
  io_free(gecos->reason);
  io_free(gecos);
}

struct GecosItem *
gecos_make(void)
{
  struct GecosItem *const gecos = io_calloc(sizeof(*gecos));
  list_add_tail(gecos, &gecos->node, &gecos_list);

  return gecos;
}

struct GecosItem *
gecos_find(const char *name, int (*compare)(const char *, const char *))
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, gecos_list.head)
  {
    struct GecosItem *const gecos = node->data;
    if (gecos->expires_at &&
        (gecos->expires_at <= io_time_get(IO_TIME_REALTIME_SEC)))
      gecos_delete(gecos, true);
    else if (compare(gecos->mask, name) == 0)
      return gecos;
  }

  return NULL;
}

void
gecos_expire(void)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, gecos_list.head)
  {
    struct GecosItem *const gecos = node->data;
    if (gecos->expires_at &&
        (gecos->expires_at <= io_time_get(IO_TIME_REALTIME_SEC)))
      gecos_delete(gecos, true);
  }
}

/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file client_svstag.c
 * \brief Controls SVSTAGS.
 */

#include <stddef.h>

#include "list.h"
#include "memory.h"

#include "client_svstag.h"
#include "numeric.h"
#include "user_mode.h"

static void
svstag_free(struct ServicesTag *svstag, list_t *list)
{
  list_remove(&svstag->node, list);
  io_free(svstag->tag);
  io_free(svstag);
}

void
svstag_detach(list_t *list, unsigned int numeric)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, list->head)
  {
    struct ServicesTag *const svstag = node->data;
    if (svstag->numeric == numeric)
      svstag_free(svstag, list);
  }
}

void
svstag_attach(list_t *list, unsigned int numeric, const char *umodes, const char *tag)
{
  if (numeric >= ERR_LAST_ERR_MSG || *umodes != '+')
    return;

  struct ServicesTag *const svstag = io_calloc(sizeof(*svstag));
  svstag->numeric = numeric;
  svstag->tag = io_strdup(tag);

  for (const char *m = umodes + 1  /* + 1 to skip the '+' */; *m; ++m)
  {
    const struct UserMode *const mode = user_mode_find(*m);
    if (mode)
      svstag->umodes |= mode->mode_bit;
  }

  if (numeric != RPL_WHOISOPERATOR)
    list_add_tail(svstag, &svstag->node, list);
  else
    list_add(svstag, &svstag->node, list);
}

void
svstag_clear_list(list_t *list)
{
  while (list->head)
    svstag_free(list->head->data, list);
}

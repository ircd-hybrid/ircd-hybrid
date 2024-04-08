/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file client_svstag.c
 * \brief Controls SVSTAGS.
 */

#include "stdinc.h"
#include "list.h"
#include "client_svstag.h"
#include "memory.h"
#include "numeric.h"
#include "user.h"


static void
svstag_free(struct ServicesTag *svstag, list_t *list)
{
  list_delete(&svstag->node, list);
  xfree(svstag->tag);
  xfree(svstag);
}

void
svstag_detach(list_t *list, unsigned int numeric)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, list->head)
  {
    struct ServicesTag *svstag = node->data;

    if (svstag->numeric == numeric)
      svstag_free(svstag, list);
  }
}

void
svstag_attach(list_t *list, unsigned int numeric,
              const char *umodes, const char *tag)
{
  if (numeric >= ERR_LAST_ERR_MSG || *umodes != '+')
    return;

  struct ServicesTag *svstag = xcalloc(sizeof(*svstag));
  svstag->numeric = numeric;
  svstag->tag = xstrdup(tag);

  const struct user_modes *tab;
  for (const char *m = umodes + 1  /* + 1 to skip the '+' */; *m; ++m)
    if ((tab = umode_map[(unsigned char)*m]))
      svstag->umodes |= tab->flag;

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

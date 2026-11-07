/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file client_svstag.c
 * \brief Controls SVSTAGS.
 */

#include <stddef.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "client_svstag.h"

static void
_svstag_free(struct ServicesTag *svstag, list_t *list)
{
  list_remove(&svstag->node, list);
  io_free(svstag->text);
  io_free(svstag);
}

bool
svstag_attach(list_t *list, const char *text)
{
  if (string_is_empty(text))
    return false;

  struct ServicesTag *const svstag = io_calloc(sizeof(*svstag));
  svstag->text = io_strdup(text);

  list_add_tail(svstag, &svstag->node, list);
  return true;
}

void
svstag_clear_list(list_t *list)
{
  while (list->head)
    _svstag_free(list->head->data, list);
}

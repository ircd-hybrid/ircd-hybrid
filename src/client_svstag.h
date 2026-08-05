/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file client_svstag.h
 * \brief Controls SVSTAGS.
 */

#ifndef INCLUDED_client_svstag_h
#define INCLUDED_client_svstag_h
#include <stdbool.h>

#include "list.h"

struct ServicesTag
{
  list_node_t node;
  char *text;
};

extern void svstag_clear_list(list_t *);
extern bool svstag_attach(list_t *, const char *);
#endif  /* INCLUDED_client_svstag_h */

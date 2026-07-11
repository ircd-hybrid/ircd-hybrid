/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file client_svstag.h
 * \brief Controls SVSTAGS.
 */

#ifndef INCLUDED_client_svstag_h
#define INCLUDED_client_svstag_h
#include <stdint.h>

struct ServicesTag
{
  list_node_t node;
  char *tag;
  unsigned int numeric;
  uint64_t umodes;
};

extern void svstag_attach(list_t *, unsigned int, const char *, const char *);
extern void svstag_clear_list(list_t *);
extern void svstag_detach(list_t *, unsigned int);
#endif  /* INCLUDED_client_svstag_h */

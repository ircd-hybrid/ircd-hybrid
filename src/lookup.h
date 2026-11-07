/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_lookup_h
#define INCLUDED_lookup_h

struct Client;
struct LookupRequest;

extern void lookup_delete(struct LookupRequest *);
extern void lookup_start(struct Client *);
#endif  /* INCLUDED_lookup_h */

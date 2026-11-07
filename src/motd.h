/*
 * SPDX-FileCopyrightText: 2000 Kevin L. Mitchell <klmitch@mit.edu>
 * SPDX-FileCopyrightText: 2013-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file motd.h
 * \brief Message-of-the-day manipulation implementation.
 */

#ifndef INCLUDED_motd_h
#define INCLUDED_motd_h
#include <stddef.h>

extern void motd_add(const char *, const char *);
extern void motd_clear(void);
extern void motd_init(void);
extern void motd_recache(void);
extern void motd_report(struct Client *, size_t, char *[]);
extern void motd_send(struct Client *);
extern void motd_signon(struct Client *);
#endif  /* INCLUDED_motd_h */

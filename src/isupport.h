/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file isupport.h
 * @brief Declarations for managing IRC ISUPPORT functionality.
 */

#ifndef INCLUDED_isupport_h
#define INCLUDED_isupport_h

#include "io.h"

extern void isupport_add(const char *, const char *, ...) IO_AFP(2,3);
extern void isupport_delete(const char *);
extern void isupport_show(struct Client *);
#endif  /* INCLUDED_isupport_h */

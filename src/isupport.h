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

struct Client;

typedef enum
{
  ISUPPORT_SUCCESS = 0,
  ISUPPORT_INVALID_NAME,
  ISUPPORT_INVALID_VALUE,
  ISUPPORT_FORMAT_ERROR,
  ISUPPORT_TOO_LONG
} isupport_result_t;

extern void isupport_delete(const char *);
extern void isupport_notify_batch_begin(void);
extern void isupport_notify_batch_end(void);
extern void isupport_show(struct Client *);
extern isupport_result_t isupport_add(const char *, const char *, ...) IO_AFP(2,3);
extern const char *isupport_result_to_string(isupport_result_t);
#endif  /* INCLUDED_isupport_h */

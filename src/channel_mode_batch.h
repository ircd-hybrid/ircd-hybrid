/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_channel_mode_batch_h
#define INCLUDED_channel_mode_batch_h
#include <stddef.h>

#include "channel_mode.h"
#include "ircd_defs.h"

typedef enum
{
  CHANNEL_MODE_BATCH_SUCCESS,
  CHANNEL_MODE_BATCH_FULL,
  CHANNEL_MODE_BATCH_TOO_LONG
} channel_mode_batch_result_t;

struct ChannelModeBatch
{
  char modes[IRCD_BUFSIZE];
  char parameters[IRCD_BUFSIZE];
  size_t modes_length;
  size_t parameters_length;
  size_t parameter_count;
  size_t body_length_max;
  enum channel_mode_action last_action;
};

extern void channel_mode_batch_init(struct ChannelModeBatch *, size_t header_length);
extern void channel_mode_batch_reset(struct ChannelModeBatch *);
extern channel_mode_batch_result_t channel_mode_batch_append(struct ChannelModeBatch *, enum channel_mode_action, unsigned char, const char *);
#endif  /* INCLUDED_channel_mode_batch_h */

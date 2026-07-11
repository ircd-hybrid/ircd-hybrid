/*
 * SPDX-FileCopyrightText: 2015-2016 plexus development team
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_mute.c
 * \brief Implements message muting extended channel bans.
 */

#include "channel_mode.h"
#include "extban.h"

struct Extban extban_mute =
{
  .character = 'm',
  .type = EXTBAN_ACTING,
  .types = CHFL_BAN | CHFL_EXCEPTION
};

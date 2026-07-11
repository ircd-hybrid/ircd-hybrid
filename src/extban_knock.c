/*
 * SPDX-FileCopyrightText: 2022-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_knock.c
 * \brief Implements $K extban which bans users from using the KNOCK command.
 */

#include "channel_mode.h"
#include "extban.h"

struct Extban extban_knock =
{
  .character = 'K',
  .type = EXTBAN_ACTING,
  .types = CHFL_BAN | CHFL_EXCEPTION
};

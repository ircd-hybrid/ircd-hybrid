/*
 * SPDX-FileCopyrightText: 2020-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_nick.c
 * \brief Implements nick change restriction extended channel bans.
 */

#include "channel_mode.h"
#include "extban.h"

struct Extban extban_nick =
{
  .character = 'n',
  .type = EXTBAN_ACTING,
  .types = CHFL_BAN | CHFL_EXCEPTION
};

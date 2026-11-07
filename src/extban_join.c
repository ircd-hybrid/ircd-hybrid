/*
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_join.c
 * \brief Implements join restriction extended channel bans.
 */

#include "channel_mode.h"
#include "extban.h"

struct Extban extban_join =
{
  .character = 'j',
  .type = EXTBAN_ACTING,
  .types = CHFL_BAN | CHFL_EXCEPTION
};

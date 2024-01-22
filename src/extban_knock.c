/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2022-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file extban_knock.c
 * \brief Implements $K extban which bans users from using the KNOCK command.
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"


struct Extban extban_knock =
{
  .character = 'K',
  .type = EXTBAN_ACTING,
  .types = CHFL_BAN | CHFL_EXCEPTION
};

/*!
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

/*! \file client_input.h
 * \brief Processing of queued input received from local clients.
 */

#ifndef INCLUDED_client_input_h
#define INCLUDED_client_input_h

enum
{
  CLIENT_INPUT_HANDSHAKE_LINE_LIMIT = 10,
  CLIENT_INPUT_USER_LINE_BUDGET = 5,
  CLIENT_INPUT_USER_BURST_LINE_BUDGET = CLIENT_INPUT_USER_LINE_BUDGET * 8,
};

struct Client;

extern void client_input_flood_endgrace(struct Client *);
extern void client_input_flood_recalc(void *);
extern void client_input_process_recvq(struct Client *);
#endif  /* INCLUDED_client_input_h */

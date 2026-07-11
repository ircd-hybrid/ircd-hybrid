/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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

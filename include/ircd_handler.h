/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd_handler.h: A header for the IRC message handlers.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#ifndef INCLUDED_ircd_handler_h
#define INCLUDED_ircd_handler_h

struct Client;

/*
 * MessageHandler
 */
typedef enum HandlerType {
  UNREGISTERED_HANDLER,
  CLIENT_HANDLER,
  SERVER_HANDLER,
  ENCAP_HANDLER,
  OPER_HANDLER,
  DUMMY_HANDLER,
  LAST_HANDLER_TYPE
} HandlerType;

/*
 * MessageHandler function
 * Params:
 * struct Client* client_p   - connection message originated from
 * struct Client* source_p   - source of message, may be different from client_p
 * int            parc   - parameter count
 * char*          parv[] - parameter vector
 */
typedef void (*MessageHandler)(struct Client*, struct Client*, int, char*[]);


#endif /* INCLUDED_ircd_handler_h */

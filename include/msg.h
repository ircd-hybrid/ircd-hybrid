/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  msg.h: A header for the message handler structure.
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

#ifndef INCLUDED_msg_h
#define INCLUDED_msg_h

#include "ircd_handler.h"

/* 
 * Message table structure 
 */
struct Message
{
  const char *cmd;
  unsigned int count;      /* number of times command used */
  unsigned int rcount;     /* number of times command used by server */
  unsigned int parameters; /* at least this many args must be passed
                             * or an error will be sent to the user 
                             * before the m_func is even called 
                             */
  unsigned int maxpara;    /* maximum permitted parameters */
  unsigned int flags;      /* bit 0 set means that this command is allowed
			     * to be used only on the average of once per 2
			     * seconds -SRB
			     */
  unsigned long bytes;  /* bytes received for this message */
  /*
   * client_p = Connected client ptr
   * source_p = Source client ptr
   * parc = parameter count
   * parv = parameter variable array
   */
  /* handlers:
   * UNREGISTERED, CLIENT, SERVER, ENCAP, OPER, DUMMY, LAST
   */
  MessageHandler handlers[LAST_HANDLER_TYPE];
};

/*
 * Constants
 */
#define   MFLG_SLOW             0x001   /* Command can be executed roughly
                                         * once per 2 seconds.                
					 */
#define   MFLG_UNREG            0x002   /* Command available to unregistered
                                         * clients.                          
					 */
 
#define MAXPARA    15

#endif /* INCLUDED_msg_h */

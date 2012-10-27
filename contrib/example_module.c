/************************************************************************
 *   IRC - Internet Relay Chat, doc/example_module.c
 *   Copyright (C) 2001 Hybrid Development Team
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */

/* List of ircd includes from ../include/ 
 * These ones are necessary to build THIS module...
 */

#include "stdinc.h" /* includes setup.h */

#include "client.h" /* Required for IsClient, etc. */

#include "send.h" /* sendto_one, most useful function of all time */

#include "parse.h"

#include "modules.h" /* includes msg.h; use for the msgtab */

/* OTHER USEFUL INCLUDES:
 * 
 * #include "handlers.h" <-- include this file to be able to use default
 * functions in place of your own 'Access Denied' kind of function
 * 
 * #include "numeric.h" <-- include this file to be able to use form_str,
 * standard message formats (see messages.tab and *.lang in messages/)
 * Examples are strewn all across the ircd code, so just grep a bit to
 * find one!
 *
 * #include "irc_string.h" <-- best to include this if you use *any*
 * string comparison or parsing functions, although they may be available
 * natively for your OS the prototypes in irc_string.h may be required for
 * others. */

/*
 * Declare the void's initially up here, as modules don't have an
 * include file, we will normally have client_p, source_p, parc
 * and parv[] where:
 *
 * client_p == client issuing command
 * source_p == where the command came from
 * parc     == the number of parameters
 * parv     == an array of the parameters
 */


/*
 * mr_test
 *      parv[0] = sender prefix
 *      parv[1] = parameter
 */

/*
 * Here we have the functions themselves that we declared above,
 * and the fairly normal C coding
 */
static void
mr_test(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (parc == 1)
    sendto_one(source_p, ":%s NOTICE %s :You are unregistered and sent no parameters",
               me.name, source_p->name);
  else
    sendto_one(source_p, ":%s NOTICE %s :You are unregistered and sent parameter: %s", 
               me.name, source_p->name, parv[1]);
}

/*
 * m_test
 *      parv[0] = sender prefix
 *      parv[1] = parameter
 */
static void
m_test(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  if (parc == 1)
    sendto_one(source_p, ":%s NOTICE %s :You are a normal user, and sent no parameters",
               me.name, source_p->name);
  else
    sendto_one(source_p, ":%s NOTICE %s :You are a normal user, and send parameters: %s",
               me.name, source_p->name, parv[1]);
}

/*
 * ms_test
 *      parv[0] = sender prefix
 *      parv[1] = parameter
 */
static void
ms_test(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (parc == 1)
  {
    if (IsServer(source_p))
      sendto_one(source_p, ":%s NOTICE %s :You are a server, and sent no parameters",
                 me.name, source_p->name);
    else
      sendto_one(source_p, ":%s NOTICE %s :You are a remote client, and sent no parameters",
                 me.name, source_p->name);
  }
  else
  {
    if (IsServer(source_p))
      sendto_one(source_p, ":%s NOTICE %s :You are a server, and sent parameters: %s",
                 me.name, source_p->name, parv[1]);
    else
      sendto_one(source_p, ":%s NOTICE %s :You are a remote client, and sent parameters: %s",
                 me.name, source_p->name, parv[1]);
  }
}

/*
 * mo_test
 *      parv[0] = sender prefix
 *      parv[1] = parameter
 */
static void
mo_test(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (parc == 1)
    sendto_one(source_p, ":%s NOTICE %s :You are an operator, and sent no parameters",
               me.name, source_p->name);
  else
    sendto_one(source_p, ":%s NOTICE %s :You are an operator, and sent parameters: %s",
               me.name, source_p->name, parv[1]);
}

/*
 * Show the commands this module can handle in a msgtab
 * and give the msgtab a name, here its test_msgtab
 */
static struct Message test_msgtab = {

 /* Fields are in order:
  *-> "COMMAND", 0, 0, parc_count, maxparc, MFLG_SLOW, 0,
  *
  * where:
  * COMMAND == the /command you want
  * parc_count == the number of parameters needed
  *               (the clients name is one param, parv[0])
  * maxparc == the maximum parameters we allow
  * the 0's and MFLG_SLOW should not be changed..
  */

 /*
  * This would add the command "TEST" which requires no additional
  * parameters
  */
  "TEST", 0, 0, 1, MAXPARA, MFLG_SLOW, 0,

 /* Fields are in order:
  *-> {unregged, regged, remote, encap, oper, dummy}
  *
  * where:
  * unregged == function to call for unregistered clients
  * regged == function to call for normal users
  * remote == function to call for servers/remote users
  * encap == function to call for encap'd server/remote commands
  * oper == function to call for operators
  * dummy == function called when client is quarantined
  *
  * There are also some pre-coded functions for use:
  * m_unregistered: prevent the client using this if unregistered
  * m_not_oper:     tell the client it requires being an operator
  * m_ignore:       ignore the command when it comes from certain types
  * rfc1459_command_send_error: give an error when the command comes from certain types
  */
  { mr_test, m_test, ms_test, m_ignore, mo_test, m_ignore }

 /* It is normal for unregistered functions to be prefixed with mr_
  *   "      "       normal users to be prefixed with m_
  *   "      "       remote clients to be prefixed with ms_
  *   "      "       operators to be prefixed with mo_
  */
};
/* That's the msgtab finished */

/* Here we tell it what to do when the module is loaded */
static void
module_init(void)
{
  /* This will add the commands in test_msgtab (which is above) */
  mod_add_cmd(&test_msgtab);
}

/* here we tell it what to do when the module is unloaded */
static void
module_exit(void)
{
  /* This will remove the commands in test_msgtab (which is above) */
  mod_del_cmd(&test_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};

/* END OF EXAMPLE MODULE */

/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997 Jukka Santala (Donwulff)
 *  Copyright (c) 2000-2014 ircd-hybrid development team
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
 */

/*! \file m_watch.c
 * \brief Includes required functions for processing the WATCH command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "s_user.h"
#include "watch.h"


/*
 * RPL_NOWON        - Online at the moment (Succesfully added to WATCH-list)
 * RPL_NOWOFF       - Offline at the moment (Succesfully added to WATCH-list)
 * RPL_WATCHOFF     - Succesfully removed from WATCH-list.
 * ERR_TOOMANYWATCH - Take a guess :>  Too many WATCH entries.
 */
static void
show_watch(struct Client *client_p, const char *name,
           unsigned int rpl1, unsigned int rpl2)
{
  const struct Client *target_p = NULL;

  if ((target_p = find_person(client_p, name)))
    sendto_one(client_p, form_str(rpl1), me.name, client_p->name,
               target_p->name, target_p->username,
               target_p->host, target_p->tsinfo);
  else
    sendto_one(client_p, form_str(rpl2), me.name, client_p->name,
               name, "*", "*", 0);
}

/*
 * m_watch()
 *
 * parv[0] = command
 * parv[1] = watch options
 */
static int
m_watch(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  dlink_node *ptr = NULL;
  char *s = NULL;
  char *p = NULL;
  char *user;
  char def[2] = "l";
  unsigned int list_requested = 0;

  /*
   * Default to 'l' - list who's currently online
   */
  if (parc < 2)
    parv[1] = def;

  for (s = strtoken(&p, parv[1], ", "); s;
       s = strtoken(&p,    NULL, ", "))
  {
    if ((user = strchr(s, '!')))
      *user++ = '\0'; /* Not used */

    /*
     * Prefix of "+", they want to add a name to their WATCH
     * list.
     */
    if (*s == '+')
    {
      if (*(s + 1) != '\0')
      {
        if (dlink_list_length(&source_p->localClient->watches) >=
            ConfigFileEntry.max_watch)
        {
          sendto_one(source_p, form_str(ERR_TOOMANYWATCH), me.name,
                     source_p->name, s + 1, ConfigFileEntry.max_watch);
          continue;
        }

        watch_add_to_hash_table(s + 1, source_p);
      }

      show_watch(source_p, s + 1, RPL_NOWON, RPL_NOWOFF);
      continue;
    }

    /*
     * Prefix of "-", coward wants to remove somebody from their
     * WATCH list.  So do it. :-)
     */
    if (*s == '-')
    {
      watch_del_from_hash_table(s + 1, source_p);
      show_watch(source_p, s + 1, RPL_WATCHOFF, RPL_WATCHOFF);
      continue;
    }

    /*
     * Fancy "C" or "c", they want to nuke their WATCH list and start
     * over, so be it.
     */
    if (*s == 'C' || *s == 'c')
    {
      watch_del_watch_list(source_p);
      continue;
    }

    /*
     * Now comes the fun stuff, "S" or "s" returns a status report of
     * their WATCH list.  I imagine this could be CPU intensive if
     * it's done alot, perhaps an auto-lag on this?
     */
    if (*s == 'S' || *s == 's')
    {
      char buf[IRCD_BUFSIZE] = { '\0' };
      const struct Watch *anptr = NULL;
      unsigned int count = 0;

      if (list_requested & 0x1)
        continue;

      list_requested |= 0x1;

      /*
       * Send a list of how many users they have on their WATCH list
       * and how many WATCH lists they are on.
       */
      if ((anptr = watch_find_hash(source_p->name)))
        count = dlink_list_length(&anptr->watched_by);

      sendto_one(source_p, form_str(RPL_WATCHSTAT),
                 me.name, source_p->name,
                 dlink_list_length(&source_p->localClient->watches), count);

      /*
       * Send a list of everybody in their WATCH list.  Be careful
       * not to buffer overflow.
       */
      if ((ptr = source_p->localClient->watches.head) == NULL)
      {
        sendto_one(source_p, form_str(RPL_ENDOFWATCHLIST),
                   me.name, source_p->name, *s);
        continue;
      }

      anptr = ptr->data;
      strlcpy(buf, anptr->nick, sizeof(buf));

      count = strlen(source_p->name) + strlen(me.name) + 10 +
              strlen(buf);

      while ((ptr = ptr->next))
      {
        anptr = ptr->data;

        if (count + strlen(anptr->nick) + 1 > IRCD_BUFSIZE - 2)
        {
          sendto_one(source_p, form_str(RPL_WATCHLIST),
                     me.name, source_p->name, buf);
          buf[0] = '\0';
          count = strlen(source_p->name) + strlen(me.name) + 10;
        }

        strcat(buf, " ");
        strcat(buf, anptr->nick);
        count += (strlen(anptr->nick) + 1);
      }

      sendto_one(source_p, form_str(RPL_WATCHLIST),
                 me.name, source_p->name, buf);
      sendto_one(source_p, form_str(RPL_ENDOFWATCHLIST),
                 me.name, source_p->name, *s);
      continue;
    }

    /*
     * Well that was fun, NOT.  Now they want a list of everybody in
     * their WATCH list AND if they are online or offline? Sheesh,
     * greedy aren't we?
     */
    if (*s == 'L' || *s == 'l')
    {
      const struct Client *target_p = NULL;

      if (list_requested & 0x2)
        continue;

      list_requested |= 0x2;

      DLINK_FOREACH(ptr, source_p->localClient->watches.head)
      {
        const struct Watch *anptr = ptr->data;

        if ((target_p = find_person(source_p, anptr->nick)))
          sendto_one(source_p, form_str(RPL_NOWON), me.name, source_p->name,
                     target_p->name, target_p->username,
                     target_p->host, target_p->tsinfo);
        /*
         * But actually, only show them offline if it's a capital
         * 'L' (full list wanted).
         */
        else if (*s == 'L')
          sendto_one(source_p, form_str(RPL_NOWOFF), me.name,
                     source_p->name, anptr->nick,
                     "*", "*", anptr->lasttime);
      }

      sendto_one(source_p, form_str(RPL_ENDOFWATCHLIST),
                 me.name, source_p->name, *s);
      continue;
    }

    /* Hmm.. unknown prefix character.. Ignore it. :-) */
  }

  return 0;
}

static struct Message watch_msgtab =
{
  "WATCH", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_watch, m_ignore, m_ignore, m_watch, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&watch_msgtab);
  add_isupport("WATCH", NULL, ConfigFileEntry.max_watch);
}

static void
module_exit(void)
{
  mod_del_cmd(&watch_msgtab);
  delete_isupport("WATCH");
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};

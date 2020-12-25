/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2020 ircd-hybrid development team
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

/*! \file m_monitor.c
 * \brief Includes required functions for processing the MONITOR command.
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
#include "user.h"
#include "monitor.h"
#include "isupport.h"


static void
monitor_add(struct Client *source_p, char *list)
{
  char onbuf[IRCD_BUFSIZE];
  char ofbuf[IRCD_BUFSIZE];
  char *onbufptr = onbuf;
  char *ofbufptr = ofbuf;
  char *p = NULL;

  /* :me.name 730 source_p->name :nick!user@host,...\r\n */
  /* 1       23456              78                  9 10 */
  size_t len = strlen(me.name) + strlen(source_p->name) + 10;

  for (const char *name = strtok_r(list, ",", &p); name;
                   name = strtok_r(NULL, ",", &p))
  {
    if (EmptyString(name) || valid_nickname(name, true) == false)
      continue;

    if (dlink_list_length(&source_p->connection->monitors) >=
        ConfigGeneral.max_monitor)
    {
      char buf[IRCD_BUFSIZE];

      if (onbufptr != onbuf)
        sendto_one_numeric(source_p, &me, RPL_MONONLINE, onbuf);
      if (ofbufptr != ofbuf)
        sendto_one_numeric(source_p, &me, RPL_MONOFFLINE, ofbuf);

      if (EmptyString(p))
        snprintf(buf, sizeof(buf), "%s", name);
      else
        snprintf(buf, sizeof(buf), "%s,%s", name, p);

      sendto_one_numeric(source_p, &me, ERR_MONLISTFULL,
                         ConfigGeneral.max_monitor, buf);
      return;
    }

    if (monitor_add_to_hash_table(name, source_p) == false)
      continue;  /* Name is already being monitored */

    const struct Client *target_p = find_person(source_p, name);
    if (target_p == NULL)
    {
      size_t masklen = strlen(name) + 1;  /* +1 for comma */

      if ((ofbufptr - ofbuf) + masklen + len > sizeof(ofbuf))
      {
        sendto_one_numeric(source_p, &me, RPL_MONOFFLINE, ofbuf);
        ofbufptr = ofbuf;
      }

      if (ofbufptr != ofbuf)
        *ofbufptr++ = ',';

      ofbufptr += snprintf(ofbufptr, sizeof(ofbuf) - (ofbufptr - ofbuf), "%s", name);
    }
    else
    {
      size_t masklen = strlen(target_p->name) + strlen(target_p->username) +
                       strlen(target_p->host) + 3;  /* +3 for ! + @ + comma */

      if ((onbufptr - onbuf) + masklen + len > sizeof(onbuf))
      {
        sendto_one_numeric(source_p, &me, RPL_MONONLINE, onbuf);
        onbufptr = onbuf;
      }

      if (onbufptr != onbuf)
        *onbufptr++ = ',';

      onbufptr += snprintf(onbufptr, sizeof(onbuf) - (onbufptr - onbuf), "%s!%s@%s",
                           target_p->name, target_p->username, target_p->host);
    }
  }

  if (onbufptr != onbuf)
    sendto_one_numeric(source_p, &me, RPL_MONONLINE, onbuf);
  if (ofbufptr != ofbuf)
    sendto_one_numeric(source_p, &me, RPL_MONOFFLINE, ofbuf);
}

static void
monitor_del(struct Client *source_p, char *list)
{
  char *p = NULL;

  if (dlink_list_length(&source_p->connection->monitors) == 0)
    return;

  for (const char *name = strtok_r(list, ",", &p); name;
                   name = strtok_r(NULL, ",", &p))
    if (!EmptyString(name))
      monitor_del_from_hash_table(name, source_p);
}

static void
monitor_list(struct Client *source_p)
{
  char buf[IRCD_BUFSIZE];
  char *bufptr = buf;
  dlink_node *node;

  /* :me.name 732 source_p->name :name1,name2,...\r\n */
  /* 1       23456              78               9 10 */
  size_t len = strlen(me.name) + strlen(source_p->name) + 10;

  DLINK_FOREACH(node, source_p->connection->monitors.head)
  {
    const struct Monitor *monitor = node->data;

    if ((bufptr - buf) + strlen(monitor->name) + 1 /* +1 for comma */ + len > sizeof(buf))
    {
      sendto_one_numeric(source_p, &me, RPL_MONLIST, buf);
      bufptr = buf;
    }

    if (bufptr != buf)
      *bufptr++ = ',';

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), "%s", monitor->name);
  }

  if (bufptr != buf)
    sendto_one_numeric(source_p, &me, RPL_MONLIST, buf);
  sendto_one_numeric(source_p, &me, RPL_ENDOFMONLIST);
}

static void
monitor_status(struct Client *source_p)
{
  char onbuf[IRCD_BUFSIZE];
  char ofbuf[IRCD_BUFSIZE];
  char *onbufptr = onbuf;
  char *ofbufptr = ofbuf;
  dlink_node *node;

  /* :me.name 730 source_p->name :nick!user@host,...\r\n */
  /* 1       23456              78                  9 10 */
  size_t len = strlen(me.name) + strlen(source_p->name) + 10;

  DLINK_FOREACH(node, source_p->connection->monitors.head)
  {
    const struct Monitor *monitor = node->data;

    const struct Client *target_p = find_person(source_p, monitor->name);
    if (target_p == NULL)
    {
      size_t masklen = strlen(monitor->name) + 1;  /* +1 for comma */

      if ((ofbufptr - ofbuf) + masklen + len > sizeof(ofbuf))
      {
        sendto_one_numeric(source_p, &me, RPL_MONOFFLINE, ofbuf);
        ofbufptr = ofbuf;
      }

      if (ofbufptr != ofbuf)
        *ofbufptr++ = ',';

      ofbufptr += snprintf(ofbufptr, sizeof(ofbuf) - (ofbufptr - ofbuf), "%s", monitor->name);
    }
    else
    {
      size_t masklen = strlen(target_p->name) + strlen(target_p->username) +
                       strlen(target_p->host) + 3;  /* +3 for ! + @ + comma */

      if ((onbufptr - onbuf) + masklen + len > sizeof(onbuf))
      {
        sendto_one_numeric(source_p, &me, RPL_MONONLINE, onbuf);
        onbufptr = onbuf;
      }

      if (onbufptr != onbuf)
        *onbufptr++ = ',';

      onbufptr += snprintf(onbufptr, sizeof(onbuf) - (onbufptr - onbuf), "%s!%s@%s",
                           target_p->name, target_p->username, target_p->host);
    }
  }

  if (onbufptr != onbuf)
    sendto_one_numeric(source_p, &me, RPL_MONONLINE, onbuf);
  if (ofbufptr != ofbuf)
    sendto_one_numeric(source_p, &me, RPL_MONOFFLINE, ofbuf);
}

/*! \brief MONITOR command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = monitor options
 *      - parv[2] = comma-separated list of nicknames 
 */
static void
m_monitor(struct Client *source_p, int parc, char *parv[])
{
  switch (*parv[1])
  {
    case '+':
      if (EmptyString(parv[2]))
      {
        sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "MONITOR");
        return;
      }

      monitor_add(source_p, parv[2]);
      break;
    case '-':
      if (EmptyString(parv[2]))
      {
        sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "MONITOR");
        return;
      }

      monitor_del(source_p, parv[2]);
      break;

    case 'C':
    case 'c':
      monitor_clear_list(source_p);
      break;

    case 'L':
    case 'l':
      monitor_list(source_p);
      break;

    case 'S':
    case 's':
      monitor_status(source_p);
      break;
  }
}

static struct Message monitor_msgtab =
{
  .cmd = "MONITOR",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_monitor, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_monitor, .args_min = 2 }
};

static void
module_init(void)
{
  mod_add_cmd(&monitor_msgtab);
  isupport_add("MONITOR", NULL, ConfigGeneral.max_monitor);
}

static void
module_exit(void)
{
  mod_del_cmd(&monitor_msgtab);
  isupport_delete("MONITOR");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};

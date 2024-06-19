/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "user.h"
#include "monitor.h"
#include "isupport.h"


static void
monitor_add(struct Client *source, char *list)
{
  char onbuf[IRCD_BUFSIZE];
  char ofbuf[IRCD_BUFSIZE];
  char *onbufptr = onbuf;
  char *ofbufptr = ofbuf;
  char *p = NULL;

  /* :me.name 730 source->name :nick!user@host,...\r\n */
  /* 1       23456              78                  9 10 */
  size_t len = strlen(me.name) + strlen(source->name) + 10;

  for (const char *name = strtok_r(list, ",", &p); name;
                   name = strtok_r(NULL, ",", &p))
  {
    if (EmptyString(name) || valid_nickname(name, true) == false)
      continue;

    if (list_length(&source->connection->monitors) >=
        ConfigGeneral.max_monitor)
    {
      char buf[IRCD_BUFSIZE];

      if (onbufptr != onbuf)
        sendto_one_numeric(source, &me, RPL_MONONLINE, onbuf);
      if (ofbufptr != ofbuf)
        sendto_one_numeric(source, &me, RPL_MONOFFLINE, ofbuf);

      if (EmptyString(p))
        snprintf(buf, sizeof(buf), "%s", name);
      else
        snprintf(buf, sizeof(buf), "%s,%s", name, p);

      sendto_one_numeric(source, &me, ERR_MONLISTFULL,
                         ConfigGeneral.max_monitor, buf);
      return;
    }

    if (monitor_add_to_hash_table(name, source) == false)
      continue;  /* Name is already being monitored */

    const struct Client *target = find_person(source, name);
    if (target == NULL)
    {
      size_t masklen = strlen(name) + 1;  /* +1 for comma */

      if ((ofbufptr - ofbuf) + masklen + len > sizeof(ofbuf))
      {
        sendto_one_numeric(source, &me, RPL_MONOFFLINE, ofbuf);
        ofbufptr = ofbuf;
      }

      ofbufptr += snprintf(ofbufptr, sizeof(ofbuf) - (ofbufptr - ofbuf), ofbufptr != ofbuf ? ",%s" : "%s", name);
    }
    else
    {
      size_t masklen = strlen(target->name) + strlen(target->username) +
                       strlen(target->host) + 3;  /* +3 for ! + @ + comma */

      if ((onbufptr - onbuf) + masklen + len > sizeof(onbuf))
      {
        sendto_one_numeric(source, &me, RPL_MONONLINE, onbuf);
        onbufptr = onbuf;
      }

      onbufptr += snprintf(onbufptr, sizeof(onbuf) - (onbufptr - onbuf), onbufptr != onbuf ? ",%s!%s@%s" : "%s!%s@%s",
                           target->name, target->username, target->host);
    }
  }

  if (onbufptr != onbuf)
    sendto_one_numeric(source, &me, RPL_MONONLINE, onbuf);
  if (ofbufptr != ofbuf)
    sendto_one_numeric(source, &me, RPL_MONOFFLINE, ofbuf);
}

static void
monitor_del(struct Client *source, char *list)
{
  char *p = NULL;

  if (list_is_empty(&source->connection->monitors))
    return;

  for (const char *name = strtok_r(list, ",", &p); name;
                   name = strtok_r(NULL, ",", &p))
    if (!EmptyString(name))
      monitor_del_from_hash_table(name, source);
}

static void
monitor_list(struct Client *source)
{
  char buf[IRCD_BUFSIZE];
  char *bufptr = buf;
  list_node_t *node;

  /* :me.name 732 source->name :name1,name2,...\r\n */
  /* 1       23456              78               9 10 */
  size_t len = strlen(me.name) + strlen(source->name) + 10;

  LIST_FOREACH(node, source->connection->monitors.head)
  {
    const struct Monitor *monitor = node->data;

    if ((bufptr - buf) + strlen(monitor->name) + 1 /* +1 for comma */ + len > sizeof(buf))
    {
      sendto_one_numeric(source, &me, RPL_MONLIST, buf);
      bufptr = buf;
    }

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? ",%s" : "%s", monitor->name);
  }

  if (bufptr != buf)
    sendto_one_numeric(source, &me, RPL_MONLIST, buf);
  sendto_one_numeric(source, &me, RPL_ENDOFMONLIST);
}

static void
monitor_status(struct Client *source)
{
  char onbuf[IRCD_BUFSIZE];
  char ofbuf[IRCD_BUFSIZE];
  char *onbufptr = onbuf;
  char *ofbufptr = ofbuf;
  list_node_t *node;

  /* :me.name 730 source->name :nick!user@host,...\r\n */
  /* 1       23456              78                  9 10 */
  size_t len = strlen(me.name) + strlen(source->name) + 10;

  LIST_FOREACH(node, source->connection->monitors.head)
  {
    const struct Monitor *monitor = node->data;

    const struct Client *target = find_person(source, monitor->name);
    if (target == NULL)
    {
      size_t masklen = strlen(monitor->name) + 1;  /* +1 for comma */

      if ((ofbufptr - ofbuf) + masklen + len > sizeof(ofbuf))
      {
        sendto_one_numeric(source, &me, RPL_MONOFFLINE, ofbuf);
        ofbufptr = ofbuf;
      }

      ofbufptr += snprintf(ofbufptr, sizeof(ofbuf) - (ofbufptr - ofbuf), ofbufptr != ofbuf ? ",%s" : "%s", monitor->name);
    }
    else
    {
      size_t masklen = strlen(target->name) + strlen(target->username) +
                       strlen(target->host) + 3;  /* +3 for ! + @ + comma */

      if ((onbufptr - onbuf) + masklen + len > sizeof(onbuf))
      {
        sendto_one_numeric(source, &me, RPL_MONONLINE, onbuf);
        onbufptr = onbuf;
      }

      onbufptr += snprintf(onbufptr, sizeof(onbuf) - (onbufptr - onbuf), onbufptr != onbuf ? ",%s!%s@%s" : "%s!%s@%s",
                           target->name, target->username, target->host);
    }
  }

  if (onbufptr != onbuf)
    sendto_one_numeric(source, &me, RPL_MONONLINE, onbuf);
  if (ofbufptr != ofbuf)
    sendto_one_numeric(source, &me, RPL_MONOFFLINE, ofbuf);
}

/*! \brief MONITOR command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
m_monitor(struct Client *source, int parc, char *parv[])
{
  switch (*parv[1])
  {
    case '+':
      if (EmptyString(parv[2]))
      {
        sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, "MONITOR");
        return;
      }

      monitor_add(source, parv[2]);
      break;
    case '-':
      if (EmptyString(parv[2]))
      {
        sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, "MONITOR");
        return;
      }

      monitor_del(source, parv[2]);
      break;
    case 'C':
    case 'c':
      monitor_clear_list(source);
      break;
    case 'L':
    case 'l':
      monitor_list(source);
      break;
    case 'S':
    case 's':
      monitor_status(source);
      break;
  }
}

static struct Command monitor_msgtab =
{
  .name = "MONITOR",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_monitor, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_monitor, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&monitor_msgtab);
  isupport_add("MONITOR", NULL, ConfigGeneral.max_monitor);
}

static void
exit_handler(void)
{
  command_del(&monitor_msgtab);
  isupport_delete("MONITOR");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};

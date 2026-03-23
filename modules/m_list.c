/*
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

/*! \file m_list.c
 * \brief Includes required functions for processing the LIST command.
 */

#include "event.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "module.h"
#include "stdinc.h"
#include "client.h"
#include "hash.h"
#include "isupport.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "list_task.h"

static bool
parse_list_args(struct ListTask *lt, char *args)
{
  char *save = NULL;

  lt->exact_match = true;

  for (char *opt = strtok_r(args, ",", &save); opt;
             opt = strtok_r(NULL, ",", &save))
  {
    const char cmd = *opt;
    if (cmd == '<')
    {
      const int val = atoi(opt + 1);
      if (val <= 0)
        return false;

      lt->users_max = (unsigned int)val - 1;
    }
    else if (cmd == '>')
    {
      const int val = atoi(opt + 1);
      if (val < 0)
        return false;

      lt->users_min = (unsigned int)val + 1;
    }
    else if (cmd == 'C' || cmd == 'c')
    {
      const char subcmd = *(opt + 1);
      if (subcmd == '<' || subcmd == '>')
      {
        const int val = atoi(opt + 2);
        if (val < 0)
          return false;

        const unsigned int target = (unsigned int)(io_time_get(IO_TIME_REALTIME_SEC) - (60 * val));

        if (subcmd == '<')
          lt->created_max = target;
        else if (subcmd == '>')
          lt->created_min = target;
      }
      else
        return false;
    }
    else if (cmd == 'T' || cmd == 't')
    {
      const char subcmd = *(opt + 1);
      if (subcmd == ':')
      {
        const char *topic_str = opt + 2;
        if (string_is_empty(topic_str))
          return false;

        lt->topic = io_strndup(topic_str, TOPICLEN);
      }
      else if (subcmd == '<' || subcmd == '>')
      {
        const int val = atoi(opt + 2);
        if (val < 0)
          return false;

        const unsigned int target = (unsigned int)(io_time_get(IO_TIME_REALTIME_SEC) - (60 * val));

        if (subcmd == '<')
          lt->topicts_min = target;
        else if (subcmd == '>')
          lt->topicts_max = target;
      }
      else
        return false;
    }
    else
    {
      list_t *target_list = &lt->include_masks;
      const char *mask = opt;

      /* Handle exclusion masks. */
      if (*mask == '!')
      {
        target_list = &lt->exclude_masks;
        ++mask;
      }

      const char *const name = IsChanPrefix(*mask) ? mask + 1 : mask;
      if (has_wildcards(name))
      {
        if (target_list == &lt->include_masks)
          lt->exact_match = false;
      }
      else if (!IsChanPrefix(*mask))
        return false;  /* Exact matches must have a valid channel prefix. */

      list_add(io_strdup(mask), list_make_node(), target_list);
    }
  }

  if (list_is_empty(&lt->include_masks))
    lt->exact_match = false;

  return true;
}

static void
do_list(struct Client *client, char *arg)
{
  if (client->connection->list_task)
  {
    list_task_destroy(client->connection->list_task);
    sendto_one_numeric(client, &me, RPL_LISTEND);
    return;
  }

  struct ListTask *lt = list_task_create(client);

  if (!string_is_empty(arg))
  {
    if (!parse_list_args(lt, arg))
    {
      list_task_destroy(lt);
      sendto_one_numeric(client, &me, ERR_LISTSYNTAX);
      return;
    }
  }

  sendto_one_numeric(client, &me, RPL_LISTSTART);
  list_task_start(lt);
}

/*! \brief LIST command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name/list options
 */
static void
m_list(struct Client *source, int parc, char *parv[])
{
  do_list(source, parv[1]);
}

static struct Command command_table =
{
  .name = "LIST",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_list },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_list },
};

static void
init_handler(void)
{
  command_add(&command_table);
  isupport_add("ELIST", "%s", "CMNTU");
  isupport_add("SAFELIST", NULL);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  isupport_delete("ELIST");
  isupport_delete("SAFELIST");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};

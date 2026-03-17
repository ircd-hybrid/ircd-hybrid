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

static void
do_list(struct Client *source, char *arg)
{
  if (source->connection->list_task)
  {
    free_list_task(source);
    sendto_one_numeric(source, &me, RPL_LISTEND);
    return;
  }

  struct ListTask *lt = io_calloc(sizeof(*lt));
  lt->users_max = UINT_MAX;
  lt->created_max = UINT_MAX;
  lt->topicts_max = UINT_MAX;
  source->connection->list_task = lt;

  if (list_is_empty(&listing_client_list))
  {
    if (event_channel_list_pump == NULL)
    {
      event_channel_list_pump = event_create(ircd_event_manager, "event_channel_list_pump", channel_list_pump, 125, false, NULL, NULL);
      event_set_priority(event_channel_list_pump, 2);
    }

    event_schedule(event_channel_list_pump);
  }

  list_add(source, &lt->node, &listing_client_list);

  bool no_masked_channels = true;
  if (!string_is_empty(arg))
  {
    list_t *list;
    char *opt, *save = NULL;
    const char *topic;
    bool error = false;
    int i;

    for (opt = strtok_r(arg,  ",", &save); opt;
         opt = strtok_r(NULL, ",", &save))
    {
      switch (*opt)
      {
        case '<':
          if ((i = atoi(opt + 1)) > 0)
            lt->users_max = (unsigned int)i - 1;
          else
            error = true;
          break;
        case '>':
          if ((i = atoi(opt + 1)) >= 0)
            lt->users_min = (unsigned int)i + 1;
          else
            error = true;
          break;
        case 'C':
        case 'c':
          switch (*++opt)
          {
            case '<':
              if ((i = atoi(opt + 1)) >= 0)
                lt->created_max = (unsigned int)(io_time_get(IO_TIME_REALTIME_SEC) - 60 * i);
              else
                error = true;
              break;
            case '>':
              if ((i = atoi(opt + 1)) >= 0)
                lt->created_min = (unsigned int)(io_time_get(IO_TIME_REALTIME_SEC) - 60 * i);
              else
                error = true;
              break;
            default:
              error = true;
          }

          break;

        case 'T':
        case 't':
          switch (*++opt)
          {
            case '<':
              if ((i = atoi(opt + 1)) >= 0)
                lt->topicts_min = (unsigned int)(io_time_get(IO_TIME_REALTIME_SEC) - 60 * i);
              else
                error = true;
              break;
            case '>':
              if ((i = atoi(opt + 1)) >= 0)
                lt->topicts_max = (unsigned int)(io_time_get(IO_TIME_REALTIME_SEC) - 60 * i);
              else
                error = true;
              break;
            case ':':
              topic = opt + 1;
              if (!string_is_empty(topic))
                lt->topic = io_strndup(topic, TOPICLEN);
              else
                error = true;
              break;
            default:
              error = true;
          }

          break;

        default:
          if (*opt == '!')
          {
            list = &lt->exclude_masks;
            opt++;
          }
          else
            list = &lt->include_masks;

          if (has_wildcards(opt + !!IsChanPrefix(*opt)))
          {
            if (list == &lt->include_masks)
              no_masked_channels = false;
          }
          else if (!IsChanPrefix(*opt))
            error = true;

          if (error == false)
            list_add(io_strdup(opt), list_make_node(), list);
      }
    }

    if (error)
    {
      free_list_task(source);
      sendto_one_numeric(source, &me, ERR_LISTSYNTAX);
      return;
    }
  }

  sendto_one_numeric(source, &me, RPL_LISTSTART);
  safe_list_channels(source, (no_masked_channels && !list_is_empty(&lt->include_masks)));
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

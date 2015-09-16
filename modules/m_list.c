/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "user.h"
#include "memory.h"
#include "isupport.h"


static void
do_list(struct Client *source_p, char *arg)
{
  struct ListTask *lt = NULL;
  int no_masked_channels = 1;

  if (source_p->connection->list_task)
  {
    free_list_task(source_p);
    sendto_one_numeric(source_p, &me, RPL_LISTEND);
    return;
  }

  lt = MyCalloc(sizeof(struct ListTask));
  lt->users_max = UINT_MAX;
  lt->created_max = UINT_MAX;
  lt->topicts_max = UINT_MAX;
  source_p->connection->list_task = lt;

  if (!EmptyString(arg))
  {
    char *opt, *save = NULL;
    dlink_list *list = NULL;
    int i = 0, errors = 0;

    for (opt = strtok_r(arg,  ",", &save); opt;
         opt = strtok_r(NULL, ",", &save))
    {
      switch (*opt)
      {
        case '<':
          if ((i = atoi(opt + 1)) > 0)
            lt->users_max = (unsigned int)i - 1;
          else
            errors = 1;
          break;
        case '>':
          if ((i = atoi(opt + 1)) >= 0)
            lt->users_min = (unsigned int)i + 1;
          else
            errors = 1;
          break;
        case 'C':
        case 'c':
          switch (*++opt)
          {
            case '<':
              if ((i = atoi(opt + 1)) >= 0)
                lt->created_max = (unsigned int)(CurrentTime - 60 * i);
              else
                errors = 1;
              break;
            case '>':
              if ((i = atoi(opt + 1)) >= 0)
                lt->created_min = (unsigned int)(CurrentTime - 60 * i);
              else
                errors = 1;
              break;
            default:
              errors = 1;
          }

          break;

        case 'T':
        case 't':
          switch (*++opt)
          {
            case '<':
              if ((i = atoi(opt + 1)) >= 0)
                lt->topicts_min = (unsigned int)(CurrentTime - 60 * i);
              else
                errors = 1;
              break;
            case '>':
              if ((i = atoi(opt + 1)) >= 0)
                lt->topicts_max = (unsigned int)(CurrentTime - 60 * i);
              else
                errors = 1;
              break;
            case ':':
              if (strlcpy(lt->topic, opt + 1, sizeof(lt->topic)) == 0)
                errors = 1;
              break;
            default:
              errors = 1;
          }

          break;

        default:
          if (*opt == '!')
          {
            list = &lt->hide_mask;
            opt++;
          }
          else
            list = &lt->show_mask;

          if (has_wildcards(opt + !!IsChanPrefix(*opt)))
          {
            if (list == &lt->show_mask)
              no_masked_channels = 0;
          }
          else if (!IsChanPrefix(*opt))
            errors = 1;

          if (!errors)
            dlinkAdd(xstrdup(opt), make_dlink_node(), list);
      }
    }

    if (errors)
    {
      free_list_task(source_p);
      sendto_one_numeric(source_p, &me, ERR_LISTSYNTAX);
      return;
    }
  }

  dlinkAdd(source_p, &lt->node, &listing_client_list);

  sendto_one_numeric(source_p, &me, RPL_LISTSTART);
  safe_list_channels(source_p, no_masked_channels && lt->show_mask.head != NULL);
}

/*! \brief LIST command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name/list options
 */
static int
m_list(struct Client *source_p, int parc, char *parv[])
{
  do_list(source_p, parv[1]);
  return 0;
}

static struct Message list_msgtab =
{
  .cmd = "LIST",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_list,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_list
};

static void
module_init(void)
{
  mod_add_cmd(&list_msgtab);
  isupport_add("ELIST", "CMNTU", -1);
  isupport_add("SAFELIST", NULL, -1);
}

static void
module_exit(void)
{
  mod_del_cmd(&list_msgtab);
  isupport_delete("ELIST");
  isupport_delete("SAFELIST");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};

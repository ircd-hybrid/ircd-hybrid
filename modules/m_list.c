/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file m_list.c
 * \brief Includes required functions for processing the LIST command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "s_user.h"
#include "memory.h"


static void
do_list(struct Client *source_p, int parc, char *parv[])
{
  struct ListTask *lt = NULL;
  int no_masked_channels = 1;

  if (source_p->localClient->list_task)
  {
    free_list_task(source_p->localClient->list_task, source_p);
    sendto_one_numeric(source_p, &me, RPL_LISTEND);
    return;
  }

  lt = MyMalloc(sizeof(struct ListTask));
  lt->users_max = UINT_MAX;
  lt->created_max = UINT_MAX;
  lt->topicts_max = UINT_MAX;
  source_p->localClient->list_task = lt;

  if (parc > 1 && !EmptyString(parv[1]))
  {
    char *opt, *save = NULL;
    dlink_list *list = NULL;
    int i = 0, errors = 0;

    for (opt = strtoken(&save, parv[1], ","); opt;
         opt = strtoken(&save,    NULL, ","))
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
        case '-': break;
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
      free_list_task(lt, source_p);
      sendto_one_numeric(source_p, &me, ERR_LISTSYNTAX);
      return;
    }
  }

  dlinkAdd(source_p, make_dlink_node(), &listing_client_list);

  sendto_one_numeric(source_p, &me, RPL_LISTSTART);
  safe_list_channels(source_p, lt, no_masked_channels &&
                     lt->show_mask.head != NULL);
}

/*
** mo_list
**      parv[0] = command
**      parv[1] = channel
*/
static int
m_list(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  do_list(source_p, parc, parv);
  return 0;
}

static struct Message list_msgtab =
{
  "LIST", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_list, m_ignore, m_ignore, m_list, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&list_msgtab);
  add_isupport("ELIST", "CMNTU", -1);
  add_isupport("SAFELIST", NULL, -1);
}

static void
module_exit(void)
{
  mod_del_cmd(&list_msgtab);
  delete_isupport("ELIST");
  delete_isupport("SAFELIST");
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

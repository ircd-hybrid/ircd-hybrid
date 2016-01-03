/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file isupport.c
 * \brief Contains functions pertaining to RPL_ISUPPORT.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd.h"
#include "conf.h"
#include "send.h"
#include "numeric.h"
#include "client.h"
#include "irc_string.h"
#include "memory.h"
#include "isupport.h"
#include "channel_mode.h"
#include "parse.h"


/* Used for building up the isupport string,
 * used with init_isupport, add_isupport, delete_isupport
 */
struct Isupport
{
  dlink_node node;
  char *name;
  char *options;
  int number;
};

static dlink_list isupport_list;
static dlink_list isupport_list_lines;

/*
 * isupport_init()
 *
 * input        - NONE
 * output       - NONE
 * side effects - Must be called before isupport is enabled
 */
void
isupport_init(void)
{
  isupport_add("CALLERID", NULL, -1);
  isupport_add("CASEMAPPING", "ascii", -1);
  isupport_add("DEAF", "D", -1);
  isupport_add("KICKLEN", NULL, KICKLEN);
  isupport_add("MODES", NULL, MAXMODEPARAMS);
  isupport_add("PREFIX", "(ohv)" CMEMBER_STATUS_FLAGS, -1);
  isupport_add("STATUSMSG", CMEMBER_STATUS_FLAGS, -1);
  isupport_add("EXCEPTS", NULL, -1);
  isupport_add("INVEX", NULL, -1);
}

/*
 * isupport_add()
 *
 * input        - name of supported function
 *              - options if any
 *              - number if any
 * output       - NONE
 * side effects - Each supported item must call this when activated
 */
void
isupport_add(const char *name, const char *options, int n)
{
  dlink_node *node = NULL;
  struct Isupport *support = NULL;

  DLINK_FOREACH(node, isupport_list.head)
  {
    support = node->data;
    if (irccmp(support->name, name) == 0)
    {
      xfree(support->name);
      xfree(support->options);
      break;
    }
  }

  if (node == NULL)
  {
    support = xcalloc(sizeof(*support));
    dlinkAddTail(support, &support->node, &isupport_list);
  }

  support->name = xstrdup(name);
  if (options)
    support->options = xstrdup(options);
  support->number = n;

  isupport_rebuild();
}

/*
 * isupport_delete()
 *
 * input        - name of supported function
 * output       - NONE
 * side effects - Each supported item must call this when deactivated
 */
void
isupport_delete(const char *name)
{
  dlink_node *node = NULL;

  DLINK_FOREACH(node, isupport_list.head)
  {
    struct Isupport *support = node->data;

    if (irccmp(support->name, name) == 0)
    {
      dlinkDelete(node, &isupport_list);
      xfree(support->name);
      xfree(support->options);
      xfree(support);
      break;
    }
  }

  isupport_rebuild();
}

/*
 * issuport_rebuild()
 *
 * input        - NONE
 * output       - NONE
 * side effects - Destroy the isupport MessageFile lines, and rebuild.
 */
void
isupport_rebuild(void)
{
  char isupportbuffer[IRCD_BUFSIZE];
  char *p = isupportbuffer;
  dlink_node *node = NULL, *node_next = NULL;
  int n = 0;
  int tokens = 0;
  size_t len = 0;
  size_t reserve = strlen(me.name) + HOSTLEN + strlen(numeric_form(RPL_ISUPPORT));

  DLINK_FOREACH_SAFE(node, node_next, isupport_list_lines.head)
  {
    dlinkDelete(node, &isupport_list_lines);
    xfree(node->data);
    free_dlink_node(node);
  }

  DLINK_FOREACH(node, isupport_list.head)
  {
    struct Isupport *support = node->data;

    p += (n = sprintf(p, "%s", support->name));
    len += n;

    if (support->options)
    {
      p += (n = sprintf(p, "=%s", support->options));
      len += n;
    }

    if (support->number > 0)
    {
      p += (n = sprintf(p, "=%d", support->number));
      len += n;
    }

    *p++ = ' ';
    len++;
    *p = '\0';

    if (++tokens == (MAXPARA-2) || len >= (sizeof(isupportbuffer)-reserve))
    { /* arbritrary for now */
      if (*--p == ' ')
        *p = '\0';

      dlinkAddTail(xstrdup(isupportbuffer), make_dlink_node(), &isupport_list_lines);
      p = isupportbuffer;
      len = 0;
      n = 0;
      tokens = 0;
    }
  }

  if (len)
  {
    if (*--p == ' ')
      *p = '\0';
    dlinkAddTail(xstrdup(isupportbuffer), make_dlink_node(), &isupport_list_lines);
  }
}

/* isupport_show()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - display to client what we support (for them)
 */
void
isupport_show(struct Client *source_p)
{
  const dlink_node *node = NULL;

  DLINK_FOREACH(node, isupport_list_lines.head)
    sendto_one_numeric(source_p, &me, RPL_ISUPPORT, node->data);
}

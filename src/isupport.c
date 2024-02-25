/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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
#include "channel.h"
#include "channel_mode.h"
#include "parse.h"


/* Used for building up the isupport string,
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

static void
isupport_build_lines(void)
{
  char isupportbuffer[IRCD_BUFSIZE];
  char *p = isupportbuffer;
  int tokens = 0;
  size_t len = 0;
  size_t reserve = strlen(me.name) + HOSTLEN + strlen(numeric_form(RPL_ISUPPORT));

  dlink_node *node, *node_next;
  DLINK_FOREACH_SAFE(node, node_next, isupport_list_lines.head)
  {
    dlinkDelete(node, &isupport_list_lines);
    xfree(node->data);
    free_dlink_node(node);
  }

  DLINK_FOREACH(node, isupport_list.head)
  {
    struct Isupport *support = node->data;

    len += snprintf(p + len, sizeof(isupportbuffer) - len, "%s", support->name);

    if (support->options)
      len += snprintf(p + len, sizeof(isupportbuffer) - len, "=%s", support->options);
    if (support->number > 0)
      len += snprintf(p + len, sizeof(isupportbuffer) - len, "=%d", support->number);

    len += snprintf(p + len, sizeof(isupportbuffer) - len, " ");

    if (++tokens == (MAXPARA - 2) || len >= (sizeof(isupportbuffer) - reserve))
    {
      if (p[len - 1] == ' ')
        p[--len] = '\0';

      dlinkAddTail(xstrdup(isupportbuffer), make_dlink_node(), &isupport_list_lines);
      p = isupportbuffer;
      len = 0;
      tokens = 0;
    }
  }

  if (len > 0)
  {
    if (p[len - 1] == ' ')
      p[--len] = '\0';

    dlinkAddTail(xstrdup(isupportbuffer), make_dlink_node(), &isupport_list_lines);
  }
}

static struct Isupport *
isupport_find(const char *name)
{
  dlink_node *node;

  DLINK_FOREACH(node, isupport_list.head)
  {
    struct Isupport *support = node->data;
    if (irccmp(support->name, name) == 0)
      return support;
  }

  return NULL;
}

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
  isupport_add("BOT", "B", -1);
  isupport_add("CALLERID", NULL, -1);
  isupport_add("CASEMAPPING", "ascii", -1);
  isupport_add("DEAF", "D", -1);
  isupport_add("KICKLEN", NULL, KICKLEN);
  isupport_add("MODES", NULL, MAXMODEPARAMS);
  isupport_add("EXCEPTS", NULL, -1);
  isupport_add("INVEX", NULL, -1);
}

static struct Isupport *
isupport_create(const char *name, const char *options, int number)
{
  struct Isupport *support = xcalloc(sizeof(*support));
  support->name = xstrdup(name);
  support->options = (options) ? xstrdup(options) : NULL;
  support->number = number;
  dlinkAddTail(support, &support->node, &isupport_list);

  return support;
}

static void
isupport_destroy(struct Isupport *support)
{
  dlinkDelete(&support->node, &isupport_list);
  xfree(support->name);
  xfree(support->options);
  xfree(support);
}

void
isupport_add(const char *name, const char *options, int number)
{
  struct Isupport *support = isupport_find(name);
  if (support)
    isupport_destroy(support);

  isupport_create(name, options, number);

  isupport_build_lines();
}

void
isupport_delete(const char *name)
{
  struct Isupport *support = isupport_find(name);
  if (support)
  {
    isupport_destroy(support);
    isupport_build_lines();
  }
}

/* isupport_show()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - display to client what we support (for them)
 */
void
isupport_show(struct Client *client)
{
  dlink_node *node;

  DLINK_FOREACH(node, isupport_list_lines.head)
  {
    const char *const string = node->data;
    sendto_one_numeric(client, &me, RPL_ISUPPORT, string);
  }
}

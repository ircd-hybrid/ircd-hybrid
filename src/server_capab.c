/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file server_capab.c
 * \brief Server CAPAB related functions.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "server_capab.h"
#include "memory.h"


static dlink_list capab_list;  /* List of capabilities supported by this server */


/* capab_init()
 *
 * inputs       - none
 * output       - none
 */
void
capab_init(void)
{
  capab_add("EOB", CAPAB_EOB, true);
  capab_add("CLUSTER", CAPAB_CLUSTER, true);
  capab_add("RHOST", CAPAB_RHOST, true);
}

/* capab_add()
 *
 * inputs       - string name of CAPAB
 *              - int flag of capability
 * output       - NONE
 * side effects - Adds given capability name and bit mask to
 *                current supported capabilities. This allows
 *                modules to dynamically add or subtract their capability.
 */
void
capab_add(const char *name, unsigned int flag, bool active)
{
  struct Capability *cap = xcalloc(sizeof(*cap));

  cap->name = xstrdup(name);
  cap->cap = flag;
  cap->active = active;
  dlinkAdd(cap, &cap->node, &capab_list);
}

/* capab_del()
 *
 * inputs       - string name of CAPAB
 * output       - NONE
 * side effects - delete given capability from ones known.
 */
void
capab_del(const char *name)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, capab_list.head)
  {
    struct Capability *cap = node->data;

    if (irccmp(cap->name, name) == 0)
    {
      dlinkDelete(node, &capab_list);
      xfree(cap->name);
      xfree(cap);
    }
  }
}

/*
 * capab_find()
 *
 * inputs       - string name of capab to find
 * output       - 0 if not found CAPAB otherwise
 * side effects - none
 */
unsigned int
capab_find(const char *name)
{
  dlink_node *node;

  DLINK_FOREACH(node, capab_list.head)
  {
    const struct Capability *cap = node->data;

    if (irccmp(cap->name, name) == 0)
      return cap->cap;
  }

  return 0;
}

/*
 * capab_get() - show current server capabilities
 *
 * inputs       - pointer to a struct Client
 * output       - pointer to static string
 * side effects - build up string representing capabilities of server listed
 */
const char *
capab_get(const void *ptr, bool active)
{
  static char buf[IRCD_BUFSIZE];
  char *bufptr = buf;
  dlink_node *node;

  *bufptr = '\0';  /* buf is static */

  DLINK_FOREACH(node, capab_list.head)
  {
    const struct Capability *cap = node->data;

    if (active && cap->active == false)
      continue;
    if (ptr && !IsCapable(((const struct Client *)ptr), cap->cap))
      continue;

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s" : "%s", cap->name);
  }

  return buf;
}

/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2003 Piotr Nizynski, Advanced IRC Services Project Team
 *  Copyright (C) 2005 Hybrid Development Team
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
 *
 *  $Id$
 */

/*! \file hook.c
 * \brief Provides a generic event hooking interface.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "hook.h"
#include "ircd.h"
#include "memory.h"
#include "numeric.h"
#include "irc_string.h"
#include "send.h"
#include "client.h"

static dlink_list callback_list = { NULL, NULL, 0} ;

/*! \brief Creates a new callback.
 * \param name name used to identify the callback
 *            (can be NULL for anonymous callbacks)
 * \param func initial function attached to the chain
 *            (can be NULL to create an empty chain)
 * \return pointer to Callback structure or NULL if already exists
 * \note Once registered, a callback should never be freed!
 * That's because there may be modules which depend on it
 * (even if no functions are attached). That's also why
 * we dynamically allocate the struct here -- we don't want
 * to allow anyone to place it in module data, which can be
 * unloaded at any time.
 */
struct Callback *
register_callback(const char *name, CBFUNC *func)
{
  struct Callback *cb = NULL;

  if (name != NULL)
  {
    if ((cb = find_callback(name)) != NULL)
    {
      if (func != NULL)
        dlinkAddTail(func, MyMalloc(sizeof(dlink_node)), &cb->chain);

      return cb;
    }
  }

  cb = MyMalloc(sizeof(struct Callback));
  if (func != NULL)
    dlinkAdd(func, MyMalloc(sizeof(dlink_node)), &cb->chain);

  if (name != NULL)
  {
    DupString(cb->name, name);
    dlinkAdd(cb, &cb->node, &callback_list);
  }

  return cb;
}

/*! \brief Passes control down the callback hook chain.
 * \param cb  pointer to Callback structure
 * \param ... argument to pass
 * \return function return value
 */
void *
execute_callback(struct Callback *cb, ...)
{
  void *res;
  va_list args;

  cb->called++;
  cb->last = CurrentTime;

  if (!is_callback_present(cb))
    return NULL;

  va_start(args, cb);
  res = ((CBFUNC *) cb->chain.head->data)(args);
  va_end(args);

  return res;
}

/*! \brief Called by a hook function to pass code flow further
 *         in the hook chain.
 * \param this_hook pointer to dlink_node of the current hook function
 * \param ...       (original or modified) arguments to be passed
 * \return callback return value
 */
void *
pass_callback(dlink_node *this_hook, ...)
{
  void *res;
  va_list args;

  if (this_hook->next == NULL)
    return NULL;  /* reached the last one */

  va_start(args, this_hook);
  res = ((CBFUNC *) this_hook->next->data)(args);
  va_end(args);

  return res;
}

/*! \brief Finds a named callback.
 * \param name name of the callback
 * \return pointer to Callback structure or NULL if not found
 */
struct Callback *
find_callback(const char *name)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, callback_list.head)
  {
    struct Callback *cb = ptr->data;

    if (!irccmp(cb->name, name))
      return cb;
  }

  return NULL;
}

/*! \brief Installs a hook for the given callback.
 *
 * The new hook is installed at the beginning of the chain,
 * so it has full control over functions installed earlier.
 *
 * \param cb   pointer to Callback structure
 * \param hook address of hook function
 * \return pointer to dlink_node of the hook (used when passing
 *         control to the next hook in the chain);
 *         valid till uninstall_hook() is called
 */
dlink_node *
install_hook(struct Callback *cb, CBFUNC *hook)
{
  dlink_node *node = MyMalloc(sizeof(dlink_node));

  dlinkAdd(hook, node, &cb->chain);
  return node;
}

/*! \brief Removes a specific hook for the given callback.
 * \param cb   pointer to Callback structure
 * \param hook address of hook function
 */
void
uninstall_hook(struct Callback *cb, CBFUNC *hook)
{
  /* let it core if not found */
  dlink_node *ptr = dlinkFind(&cb->chain, hook);

  dlinkDelete(ptr, &cb->chain);
  MyFree(ptr);
}

/*! \brief Displays registered callbacks and lengths of their hook chains.
 *         (This is the handler of /stats h)
 * \param source_p pointer to struct Client
 */
void
stats_hooks(struct Client *source_p)
{
  dlink_node *ptr;
  char lastused[32];

  sendto_one(source_p, ":%s %d %s : %-20s %-20s Used     Hooks", me.name,
             RPL_STATSDEBUG, source_p->name, "Callback", "Last Execution");
  sendto_one(source_p, ":%s %d %s : ------------------------------------"
             "--------------------", me.name, RPL_STATSDEBUG, source_p->name);

  DLINK_FOREACH(ptr, callback_list.head)
  {
    struct Callback *cb = ptr->data;

    if (cb->last != 0)
      snprintf(lastused, sizeof(lastused), "%d seconds ago",
               (int) (CurrentTime - cb->last));
    else
      strcpy(lastused, "NEVER");

    sendto_one(source_p, ":%s %d %s : %-20s %-20s %-8u %d", me.name,
               RPL_STATSDEBUG, source_p->name, cb->name, lastused, cb->called,
	       dlink_list_length(&cb->chain));
  }

  sendto_one(source_p, ":%s %d %s : ", me.name, RPL_STATSDEBUG,
             source_p->name);
}

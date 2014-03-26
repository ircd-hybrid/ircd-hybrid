/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003 Piotr Nizynski, Advanced IRC Services Project Team
 *  Copyright (c) 2005-2014 ircd-hybrid development team
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


static dlink_list callback_list;


/*! \brief Creates a new callback.
 * \param name Name used to identify the callback
 *            (can be NULL for anonymous callbacks)
 * \param func Initial function attached to the chain
 *            (can be NULL to create an empty chain)
 * \return Pointer to Callback structure or NULL if already exists
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

  if (name)
  {
    if ((cb = find_callback(name)))
    {
      if (func)
        dlinkAddTail(func, MyMalloc(sizeof(dlink_node)), &cb->chain);

      return cb;
    }
  }

  cb = MyMalloc(sizeof(struct Callback));

  if (func)
    dlinkAdd(func, MyMalloc(sizeof(dlink_node)), &cb->chain);

  if (name)
  {
    cb->name = xstrdup(name);
    dlinkAdd(cb, &cb->node, &callback_list);
  }

  return cb;
}

/*! \brief Passes control down the callback hook chain.
 * \param cb  Pointer to Callback structure
 * \param ... Argument to pass
 * \return function Return value
 */
void *
execute_callback(struct Callback *cb, ...)
{
  void *res = NULL;
  va_list args;

  cb->called++;
  cb->last = CurrentTime;

  if (!is_callback_present(cb))
    return NULL;

  va_start(args, cb);
  res = ((CBFUNC *)cb->chain.head->data)(args);
  va_end(args);

  return res;
}

/*! \brief Called by a hook function to pass code flow further
 *         in the hook chain.
 * \param this_hook Pointer to dlink_node of the current hook function
 * \param ...       (original or modified) arguments to be passed
 * \return callback Return value
 */
void *
pass_callback(dlink_node *this_hook, ...)
{
  void *res = NULL;
  va_list args;

  if (this_hook->next == NULL)
    return NULL;  /* Reached the last one */

  va_start(args, this_hook);
  res = ((CBFUNC *)this_hook->next->data)(args);
  va_end(args);

  return res;
}

/*! \brief Finds a named callback.
 * \param name Name of the callback
 * \return Pointer to Callback structure or NULL if not found
 */
struct Callback *
find_callback(const char *name)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, callback_list.head)
    if (!irccmp(((struct Callback *)ptr->data)->name, name))
      return ptr->data;

  return NULL;
}

/*! \brief Installs a hook for the given callback.
 *
 * The new hook is installed at the beginning of the chain,
 * so it has full control over functions installed earlier.
 *
 * \param cb   Pointer to Callback structure
 * \param hook Address of hook function
 * \return Pointer to dlink_node of the hook (used when passing
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
 * \param cb   Pointer to Callback structure
 * \param hook Address of hook function
 */
void
uninstall_hook(struct Callback *cb, CBFUNC *hook)
{
  /* Let it core if not found */
  dlink_node *ptr = dlinkFind(&cb->chain, hook);

  dlinkDelete(ptr, &cb->chain);
  MyFree(ptr);
}

/*! \brief Displays registered callbacks and lengths of their hook chains.
 *         (This is the handler of /stats h)
 * \param source_p Pointer to struct Client
 */
void
stats_hooks(struct Client *source_p)
{
  char lastused[IRCD_BUFSIZE] = "";
  const dlink_node *ptr = NULL;

  sendto_one(source_p, ":%s %d %s : %-20s %-20s Used     Hooks", me.name,
             RPL_STATSDEBUG, source_p->name, "Callback", "Last Execution");
  sendto_one(source_p, ":%s %d %s : ------------------------------------"
             "--------------------", me.name, RPL_STATSDEBUG, source_p->name);

  DLINK_FOREACH(ptr, callback_list.head)
  {
    const struct Callback *cb = ptr->data;

    if (cb->last)
      snprintf(lastused, sizeof(lastused), "%d seconds ago",
               (int)(CurrentTime - cb->last));
    else
      strcpy(lastused, "NEVER");

    sendto_one(source_p, ":%s %d %s : %-20s %-20s %-8u %d", me.name,
               RPL_STATSDEBUG, source_p->name, cb->name, lastused, cb->called,
               dlink_list_length(&cb->chain));
  }
}

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

#include "stdinc.h"
#include "list.h"
#include "memory.h"
#include "irc_string.h"
#include "channel.h"
#include "client.h"
#include "conf.h"
#include "accept.h"

/*
 * accept processing, this adds a form of "caller ID" to ircd
 *
 * If a client puts themselves into "caller ID only" mode,
 * only clients that match a client pointer they have put on
 * the accept list will be allowed to message them.
 *
 * Diane Bruce, "Dianora" db@db.net
 */

/*! \brief Allocates and adds a struct AccepItem holding a nick!user\@host
 *         mask to a Client's acceptlist.
 *
 * \param nick nick portion of the nick!user\@host mask.
 * \param user user portion of the nick!user\@host mask.
 * \param host host portion of the nick!user\@host mask.
 * \param source_p The actual Client the new accept is added to.
 */
void
accept_add(const char *nick, const char *user, const char *host, list_t *list)
{
  struct AcceptItem *accept = io_calloc(sizeof(*accept));
  accept->nick = io_strdup(nick);
  accept->user = io_strdup(user);
  accept->host = io_strdup(host);
  list_add(accept, &accept->node, list);
}

void
accept_del(struct AcceptItem *accept, list_t *list)
{
  list_remove(&accept->node, list);
  io_free(accept->nick);
  io_free(accept->user);
  io_free(accept->host);
  io_free(accept);
}

/* del_all_accepts()
 *
 * inputs       - pointer to exiting client
 * output       - NONE
 * side effects - Walk through given clients acceptlist and remove all entries
 */
void
accept_clear_list(list_t *list)
{
  while (list->head)
    accept_del(list->head->data, list);
}

struct AcceptItem *
accept_find(const char *nick, const char *user, const char *host, list_t *list,
            int (*compare)(const char *, const char *))
{
  list_node_t *node;

  LIST_FOREACH(node, list->head)
  {
    struct AcceptItem *accept = node->data;

    if (compare(accept->nick, nick) == 0 &&
        compare(accept->user, user) == 0 &&
        compare(accept->host, host) == 0)
      return accept;
  }

  return NULL;
}

/* accept_message()
 *
 * inputs       - pointer to source client
 *              - pointer to target client
 * output       - 1 if accept this message 0 if not
 * side effects - See if source is on target's allow list
 */
bool
accept_message(struct Client *source, struct Client *target)
{
  list_node_t *node;

  if (HasFlag(source, FLAGS_SERVICE) ||
      (HasUMode(source, UMODE_OPER) && ConfigGeneral.opers_bypass_callerid))
    return true;

  if (source == target || accept_find(source->name, source->username, source->host,
                                      &target->connection->acceptlist, match))
    return true;

  if (!HasUMode(target, UMODE_CALLERID) && HasUMode(target, UMODE_SOFTCALLERID))
    LIST_FOREACH(node, target->channel.head)
      if (member_find_link(source, ((struct ChannelMember *)node->data)->channel))
        return true;

  return false;
}

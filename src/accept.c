/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stddef.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "accept.h"
#include "channel.h"
#include "client.h"
#include "conf.h"
#include "user_mode.h"

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
  struct AcceptItem *const accept = io_calloc(sizeof(*accept));
  accept->nick = io_strdup(nick);
  accept->user = io_strdup(user);
  accept->host = io_strdup(host);

  list_add_tail(accept, &accept->node, list);
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
    struct AcceptItem *const accept = node->data;
    if (compare(accept->nick, nick) == 0 &&
        compare(accept->user, user) == 0 &&
        compare(accept->host, host) == 0)
      return accept;
  }

  return NULL;
}

bool
accept_message(struct Client *source, struct Client *target)
{
  list_node_t *node;

  if (client_is_service(source) || (client_is_oper(source) && ConfigGeneral.opers_bypass_callerid))
    return true;

  if (source == target || accept_find(source->name, source->username, source->host,
                                      &target->connection->accept_list, match))
    return true;

  if (!user_mode_has_flag(target, UMODE_CALLERID) && user_mode_has_flag(target, UMODE_SOFTCALLERID))
    LIST_FOREACH(node, target->channel_member_list.head)
      if (channel_member_find(source, ((struct ChannelMember *)node->data)->channel))
        return true;

  return false;
}

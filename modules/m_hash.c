/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_hash.c
 * \brief Includes required functions for processing the HASH command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "channel.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "parse.h"
#include "send.h"

static void
do_hash(struct Client *source, enum hash_type type)
{
  unsigned int max_chain = 0;
  unsigned int buckets   = 0;
  unsigned int count     = 0;

  assert(type == HASH_TYPE_CLIENT || type == HASH_TYPE_ID || type == HASH_TYPE_CHANNEL);

  for (size_t i = 0; i < HASHSIZE; ++i)
  {
    const void *ptr = hash_get_bucket(type, i);
    if (ptr)
    {
      unsigned int len = 0;
      ++buckets;

      while (ptr)
      {
        if (type == HASH_TYPE_CLIENT)
          ptr = ((const struct Client *)ptr)->name_hash_next;
        else if (type == HASH_TYPE_ID)
          ptr = ((const struct Client *)ptr)->id_hash_next;
        else /* type == HASH_TYPE_CHANNEL */
          ptr = ((const struct Channel *)ptr)->hash_next;

        if (++len > max_chain)
          max_chain = len;
        count += len;
      }
    }
  }

  static const char *const strtype[] =
  {
    [HASH_TYPE_CLIENT] = "Client",
    [HASH_TYPE_ID] = "Id",
    [HASH_TYPE_CHANNEL] = "Channel",
  };

  sendto_one_notice(source, &me, ":%s: entries: %u buckets: %u max chain: %u",
                    strtype[type], count, buckets, max_chain);
}

/*! \brief HASH command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
mo_hash(struct Client *source, size_t parc, char *parv[])
{
  do_hash(source, HASH_TYPE_CLIENT);
  do_hash(source, HASH_TYPE_ID);
  do_hash(source, HASH_TYPE_CHANNEL);
}

static struct Command command_table =
{
  .name = "HASH",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_hash }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};

/*
 * SPDX-FileCopyrightText: 2004 Kevin L. Mitchell <klmitch@mit.edu>
 * SPDX-FileCopyrightText: 2006-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_cap.c
 * \brief Includes required functions for processing the CAP command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io_parse.h"
#include "io_string.h"
#include "module.h"

#include "cap.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user.h"

enum
{
  CAP_LS_VERSION_302 = 302,
  CAP_REPLY_LINE_LENGTH_MAX = IRCD_BUFSIZE - 2,
  CAP_REPLY_COMMAND_LENGTH = sizeof("CAP") - 1,
  CAP_REPLY_FINAL_SEPARATOR_LENGTH = sizeof(" :") - 1,
  CAP_REPLY_CONTINUED_SEPARATOR_LENGTH = sizeof(" * :") - 1,
};

static const struct Cap *
find_cap(const char **caplist_p, bool *negate_p)
{
  /* Skip leading whitespace. */
  const char *caplist = *caplist_p;
  while (*caplist && IsSpace(*caplist))
    ++caplist;

  *negate_p = *caplist == '-';  /* Check if the capability is negative. */
  if (*negate_p)
    ++caplist;  /* Move past the '-'. */

  const char *caplist_start = caplist;
  /* Move the pointer to the end of the capability name. */
  while (*caplist && !IsSpace(*caplist))
    ++caplist;

  /* If the capability name is empty, return NULL. */
  if (caplist_start == caplist)
  {
    *caplist_p = caplist;  /* Update the pointer for the next iteration. */
    return NULL;
  }

  const size_t name_len = caplist - caplist_start;
  char name[name_len + 1];
  strlcpy(name, caplist_start, sizeof(name));

  /* Skip trailing whitespace. */
  while (*caplist && IsSpace(*caplist))
    ++caplist;

  assert(caplist != *caplist_p || *caplist == '\0');  /* We *must* advance */

  /* Update the input pointer for the next capability in the list. */
  *caplist_p = *caplist ? caplist : NULL;

  return cap_find(name);  /* And return the capability (if any) */
}

static const char *
_cap_reply_get_destination(const struct Client *client)
{
  const char *const destination = client_get_id_or_name(client, client);
  if (string_is_empty(destination))
    return "*";

  return destination;
}

static size_t
_cap_reply_get_overhead(const struct Client *client, const char *subcommand, bool continued)
{
  assert(!string_is_empty(subcommand));
  assert(strchr(subcommand, ' ') == NULL);

  const char *const prefix = client_get_id_or_name(&me, client);
  const char *const destination = _cap_reply_get_destination(client);

  /*
   * Final line:
   *   :<prefix> CAP <destination> <subcommand> :<caplist>
   *
   * Continued line:
   *   :<prefix> CAP <destination> <subcommand> * :<caplist>
   *
   * Return the number of bytes before <caplist>, excluding CRLF.
   */
  return 1 + strlen(prefix) +
         1 + CAP_REPLY_COMMAND_LENGTH +
         1 + strlen(destination) +
         1 + strlen(subcommand) +
         (continued ? CAP_REPLY_CONTINUED_SEPARATOR_LENGTH : CAP_REPLY_FINAL_SEPARATOR_LENGTH);
}

static size_t
_cap_reply_get_caplist_limit(const struct Client *client, const char *subcommand)
{
  const size_t overhead = _cap_reply_get_overhead(client, subcommand, true);
  assert(overhead < CAP_REPLY_LINE_LENGTH_MAX);

  if (overhead >= CAP_REPLY_LINE_LENGTH_MAX)
    return 0;

  return CAP_REPLY_LINE_LENGTH_MAX - overhead;
}

static bool
_cap_reply_should_include(const struct Cap *cap, uint32_t *const set, uint32_t *const rem)
{
  if (set == NULL && rem == NULL)
    return true;
  if (set && (*set & cap->flag))
    return true;
  if (rem && (*rem & cap->flag))
    return true;

  return false;
}

static bool
_cap_reply_is_removed(const struct Cap *cap, uint32_t *const rem)
{
  return rem && (*rem & cap->flag);
}

static size_t
_cap_reply_get_entry_length(size_t caplist_len, const struct Cap *cap, bool removed)
{
  return (caplist_len != 0) + removed + cap->name_len;
}

static void
_cap_reply_append_entry(char *caplist, size_t *const caplist_len, const struct Cap *cap, bool removed)
{
  assert(caplist);
  assert(caplist_len);
  assert(cap);

  if (*caplist_len != 0)
    caplist[(*caplist_len)++] = ' ';

  if (removed)
    caplist[(*caplist_len)++] = '-';

  memcpy(caplist + *caplist_len, cap->name, cap->name_len);
  *caplist_len += cap->name_len;
  caplist[*caplist_len] = '\0';
}

static void
_cap_reply_send_line(struct Client *client, const char *subcommand, const char *caplist, bool continued)
{
  if (continued)
  {
    sendto_one_command(client, &me, "CAP", "%s * :%s", subcommand, caplist);
    return;
  }

  sendto_one_command(client, &me, "CAP", "%s :%s", subcommand, caplist);
}

/** Send a CAP \a subcmd list of capability changes to \a source.
 * If more than one line is necessary, each line before the last has
 * an added "*" parameter before that line's capability list.
 * @param[in] source Client receiving capability list.
 * @param[in] set Capabilities to show as set (with ack and sticky modifiers).
 * @param[in] rem Capabalities to show as removed (with no other modifier).
 * @param[in] subcmd Name of capability subcommand.
 */
static void
_cap_reply_send_list(struct Client *client, uint32_t *const set,
                     uint32_t *const rem, const char *subcommand)
{
  assert(!string_is_empty(subcommand));

  char caplist[IRCD_BUFSIZE] = "";
  size_t caplist_len = 0;
  const size_t caplist_limit = _cap_reply_get_caplist_limit(client, subcommand);

  list_node_t *node;
  LIST_FOREACH(node, cap_get_list()->head)
  {
    const struct Cap *const cap = node->data;
    if (!_cap_reply_should_include(cap, set, rem))
      continue;

    const bool removed = _cap_reply_is_removed(cap, rem);
    const size_t entry_len = _cap_reply_get_entry_length(caplist_len, cap, removed);
    assert(entry_len <= caplist_limit);

    if (entry_len > caplist_limit)
      continue;

    if ((caplist_len != 0) && caplist_len + entry_len > caplist_limit)
    {
      _cap_reply_send_line(client, subcommand, caplist, true);

      caplist[0] = '\0';
      caplist_len = 0;
    }

    _cap_reply_append_entry(caplist, &caplist_len, cap, removed);
  }

  _cap_reply_send_line(client, subcommand, caplist, false);
}

static bool
_cap_ls_supports_302(const char *arg)
{
  unsigned int version;

  const io_parse_status_t status = io_parse_uint(arg, &version);
  if (status == IO_PARSE_RANGE)
    return true;

  return status == IO_PARSE_OK && version >= CAP_LS_VERSION_302;
}

static void
cap_ls(struct Client *source, const char *arg)
{
  if (client_is_unknown(source))  /* Registration hasn't completed; suspend it... */
    source->connection->registration_flags |= REG_NEED_CAP;

  if (_cap_ls_supports_302(arg))
  {
    source->connection->cap_flags |= CAP_CAP_NOTIFY;
    client_set_flag(source, FLAGS_CAP302);
  }

  _cap_reply_send_list(source, NULL, NULL, "LS");  /* Send list of capabilities */
}

static void
cap_req(struct Client *source, const char *arg)
{
  uint32_t set = 0, rem = 0;
  uint32_t cs = source->connection->cap_flags;  /* Enabled capabilities */

  if (client_is_unknown(source))  /* Registration hasn't completed; suspend it... */
    source->connection->registration_flags |= REG_NEED_CAP;

  /* Walk through the capabilities list... */
  for (const char *cl = arg; cl; )
  {
    /* Look up capability... */
    bool error = false;
    bool negate;
    const struct Cap *const cap = find_cap(&cl, &negate);

    if (cap == NULL)
      error = true;
    else if (negate && (cap->flag & CAP_CAP_NOTIFY) && client_has_flag(source, FLAGS_CAP302))
      error = true;

    if (error)
    {
      sendto_one_command(source, &me, "CAP", "NAK :%s", arg);
      return;  /* Can't complete requested op... */
    }

    if (negate)
    {
      /* Set or clear the capability... */
      rem |=  cap->flag;
      set &= ~cap->flag;
      cs  &= ~cap->flag;
    }
    else
    {
      rem &= ~cap->flag;
      set |=  cap->flag;
      cs  |=  cap->flag;
    }
  }

  /* Notify client of accepted changes and copy over results. */
  _cap_reply_send_list(source, &set, &rem, "ACK");

  source->connection->cap_flags = cs;
}

static void
cap_end(struct Client *source, const char *arg)
{
  if (!client_is_unknown(source))  /* Registration has completed... */
    return;  /* So just ignore the message... */

  /* Capability negotiation is now done... */
  source->connection->registration_flags &= ~REG_NEED_CAP;

  /* If client is now done... */
  if (source->connection->registration_flags == 0)
    user_register_local(source);
}

static void
cap_list(struct Client *source, const char *arg)
{
  /* Send the list of the client's capabilities */
  _cap_reply_send_list(source, &source->connection->cap_flags, NULL, "LIST");
}

struct CapSubcommand
{
  const char *const name;
  void (*const handler)(struct Client *, const char *);
};

static const struct CapSubcommand cap_subcommands[] =
{
  /* Keep this table ordered by expected CAP negotiation frequency. */
  { "LS",   cap_ls   },
  { "REQ",  cap_req  },
  { "END",  cap_end  },
  { "LIST", cap_list }
};

static const struct CapSubcommand *
_cap_subcommand_find(const char *name)
{
  for (size_t i = 0; i < IO_ARRAY_LENGTH(cap_subcommands); ++i)
  {
    const struct CapSubcommand *const subcommand = &cap_subcommands[i];
    if (io_strcasecmp(name, subcommand->name) == 0)
      return subcommand;
  }

  return NULL;
}

/*! \brief CAP command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = CAP subcommand
 *      - parv[2] = space-separated list of capabilities
 */
static void
m_cap(struct Client *source, size_t parc, char *parv[])
{
  const char *const subcommand_name = parv[1];
  const char *const caplist = parv[2];

  const struct CapSubcommand *const subcommand = _cap_subcommand_find(subcommand_name);
  if (subcommand == NULL)
  {
    sendto_one_numeric(source, &me, ERR_INVALIDCAPCMD, subcommand_name);
    return;
  }

  subcommand->handler(source, caplist);
}

static struct Command command_table =
{
  .name = "CAP",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = m_cap, .args_min = 2 },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_cap, .args_min = 2 },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_cap, .args_min = 2 }
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
  .resident = true  /* XXX for now until caps are completely modular */
};

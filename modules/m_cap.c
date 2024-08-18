/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2004 Kevin L. Mitchell <klmitch@mit.edu>
 *  Copyright (c) 2006-2024 ircd-hybrid development team
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

/*! \file m_cap.c
 * \brief Includes required functions for processing the CAP command.
 */

#include "stdinc.h"
#include "misc.h"
#include "cap.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "user.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "irc_string.h"


static struct Cap *
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

/** Send a CAP \a subcmd list of capability changes to \a source.
 * If more than one line is necessary, each line before the last has
 * an added "*" parameter before that line's capability list.
 * @param[in] source Client receiving capability list.
 * @param[in] set Capabilities to show as set (with ack and sticky modifiers).
 * @param[in] rem Capabalities to show as removed (with no other modifier).
 * @param[in] subcmd Name of capability subcommand.
 */
static void
send_caplist(struct Client *source,
             const unsigned int *const set,
             const unsigned int *const rem, const char *subcmd)
{
  char capbuf[IRCD_BUFSIZE] = "";
  char cmdbuf[IRCD_BUFSIZE] = "";
  unsigned int loc = 0, len, clen;

  /* Set up the buffer for the final LS message... */
  clen = snprintf(cmdbuf, sizeof(cmdbuf), ":%s CAP %s %s ",
                  me.name, source->name[0] ? source->name : "*", subcmd);

  list_node_t *node;
  LIST_FOREACH(node, cap_get_list()->head)
  {
    const struct Cap *cap = node->data;

    /*
     * This is a little bit subtle, but just involves applying de
     * Morgan's laws to the obvious check: We must display the
     * capability if (and only if) it is set in \a rem or \a set, or
     * if both are null.
     */
    if (!(rem && (*rem & cap->flag)) &&
        !(set && (*set & cap->flag)) && (rem || set))
      continue;

    /* Build the prefix (space separator and any modifiers needed). */
    char pfx[4];
    unsigned int pfx_len = 0;

    if (loc)
      pfx[pfx_len++] = ' ';
    if (rem && (*rem & cap->flag))
      pfx[pfx_len++] = '-';

    pfx[pfx_len] = '\0';

    len = cap->name_len + pfx_len;  /* How much we'd add... */

    if (sizeof(capbuf) < (clen + loc + len + 15))
    {
      /* Would add too much; must flush */
      sendto_one(source, "%s* :%s", cmdbuf, capbuf);
      loc = 0;
      capbuf[0] = '\0';  /* Re-terminate the buffer... */
    }

    loc += snprintf(capbuf + loc, sizeof(capbuf) - loc, "%s%s", pfx, cap->name);
  }

  sendto_one(source, "%s:%s", cmdbuf, capbuf);
}

static void
cap_ls(struct Client *source, const char *arg)
{
  if (IsUnknown(source))  /* Registration hasn't completed; suspend it... */
    source->connection->registration |= REG_NEED_CAP;

  if (arg && atoi(arg) >= 302)
  {
    source->connection->cap |= CAP_CAP_NOTIFY;
    AddFlag(source, FLAGS_CAP302);
  }

  send_caplist(source, NULL, NULL, "LS");  /* Send list of capabilities */
}

static void
cap_req(struct Client *source, const char *arg)
{
  unsigned int set = 0, rem = 0;
  unsigned int cs = source->connection->cap;  /* Enabled capabilities */

  if (IsUnknown(source))  /* Registration hasn't completed; suspend it... */
    source->connection->registration |= REG_NEED_CAP;

  /* Walk through the capabilities list... */
  for (const char *cl = arg; cl; )
  {
    /* Look up capability... */
    bool error = false;
    bool negate;
    const struct Cap *cap = find_cap(&cl, &negate);

    if (cap == NULL)
      error = true;
    else if (negate && (cap->flag & CAP_CAP_NOTIFY) && HasFlag(source, FLAGS_CAP302))
      error = true;

    if (error)
    {
      sendto_one(source, ":%s CAP %s NAK :%s", me.name,
                 source->name[0] ? source->name : "*", arg);
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
  send_caplist(source, &set, &rem, "ACK");

  source->connection->cap = cs;
}

static void
cap_end(struct Client *source, const char *arg)
{
  if (!IsUnknown(source))  /* Registration has completed... */
    return;  /* So just ignore the message... */

  /* Capability negotiation is now done... */
  source->connection->registration &= ~REG_NEED_CAP;

  /* If client is now done... */
  if (source->connection->registration == 0)
    user_register_local(source);
}

static void
cap_list(struct Client *source, const char *arg)
{
  /* Send the list of the client's capabilities */
  send_caplist(source, &source->connection->cap, NULL, "LIST");
}

static struct subcmd
{
  const char *name;
  void (*proc)(struct Client *, const char *);
} cmdlist[] = {
  { "END",  cap_end  },
  { "LIST", cap_list },
  { "LS",   cap_ls   },
  { "REQ",  cap_req  }
};

static int
subcmd_cmp(const void *const name_, const void *const elem_)
{
  const char *const name = name_;
  const struct subcmd *const elem = elem_;
  return strcasecmp(name, elem->name);
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
m_cap(struct Client *source, int parc, char *parv[])
{
  const char *subcmd = parv[1], *caplist = parv[2];

  /* Find the subcommand handler */
  const struct subcmd *cmd = bsearch(subcmd, cmdlist, IO_ARRAY_LENGTH(cmdlist), sizeof(*cmd), subcmd_cmp);
  if (cmd == NULL)
  {
    sendto_one_numeric(source, &me, ERR_INVALIDCAPCMD, subcmd);
    return;
  }

  /* Then execute it... */
  cmd->proc(source, caplist);
}

static struct Command command_table =
{
  .name = "CAP",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_cap, .args_min = 2 },
  .handlers[CLIENT_HANDLER] = { .handler = m_cap, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_cap, .args_min = 2 }
};

static void
init_handler(void)
{
  cap_register(CAP_UHNAMES, "userhost-in-names", NULL);
  cap_register(CAP_MULTI_PREFIX, "multi-prefix", NULL);
  cap_register(CAP_AWAY_NOTIFY, "away-notify", NULL);
  cap_register(CAP_EXTENDED_JOIN, "extended-join", NULL);
  cap_register(CAP_ACCOUNT_NOTIFY, "account-notify", NULL);
  cap_register(CAP_CAP_NOTIFY, "cap-notify", NULL);
  cap_register(CAP_INVITE_NOTIFY, "invite-notify", NULL);
  cap_register(CAP_CHGHOST, "chghost", NULL);

  command_add(&command_table);
}

static void
exit_handler(void)
{
  cap_unregister("userhost-in-names");
  cap_unregister("multi-prefix");
  cap_unregister("away-notify");
  cap_unregister("extended-join");
  cap_unregister("account-notify");
  cap_unregister("cap-notify");
  cap_unregister("invite-notify");
  cap_unregister("chghost");

  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .resident = true  /* XXX for now until caps are completely modular */
};

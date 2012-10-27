/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2004 Kevin L. Mitchell <klmitch@mit.edu>
 *  Copyright (C) 2006 Hybrid Development Team
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

/** @file
 * @brief Capability negotiation commands
 * @version $Id$
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_user.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "common.h"
#include "packet.h"
#include "irc_string.h"

static void m_cap(struct Client *, struct Client *, int, char *[]);

struct Message cap_msgtab = {
  "CAP", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_cap, m_cap, m_ignore, m_ignore, m_cap, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&cap_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&cap_msgtab);
}

const char *_version = "$Revision: 33 $";
#endif

#define CAPFL_HIDDEN    0x0001  /**< Do not advertize this capability */
#define CAPFL_PROHIBIT  0x0002  /**< Client may not set this capability */
#define CAPFL_PROTO     0x0004  /**< Cap must be acknowledged by client */
#define CAPFL_STICKY    0x0008  /**< Cap may not be cleared once set */

typedef int (*bqcmp)(const void *, const void *);

static struct capabilities
{
  unsigned int cap;
  unsigned int flags;
  const char *name;
  size_t namelen;
} capab_list[] = {
#define _CAP(cap, flags, name)  \
	{ (cap), (flags), (name), sizeof(name) - 1 }
  _CAP(CAP_MULTI_PREFIX, 0, "multi-prefix")
#undef _CAP
};

#define CAPAB_LIST_LEN	(sizeof(capab_list) / sizeof(struct capabilities))

static int
capab_sort(const struct capabilities *cap1, const struct capabilities *cap2)
{
  return strcasecmp(cap1->name, cap2->name);
}

static int
capab_search(const char *key, const struct capabilities *cap)
{
  const char *rb = cap->name;

  while (ToLower(*key) == ToLower(*rb)) /* walk equivalent part of strings */
    if (*key++ == '\0')    /* hit the end, all right... */
      return 0;
    else    /* OK, let's move on... */
      rb++;

  /* If the character they differ on happens to be a space, and it happens
   * to be the same length as the capability name, then we've found a
   * match; otherwise, return the difference of the two.
   */
  return (IsSpace(*key) && *rb == '\0') ? 0 : (ToLower(*key) - ToLower(*rb));
}

static struct capabilities *
find_cap(const char **caplist_p, int *neg_p)
{
  static int inited = 0;
  const char *caplist = *caplist_p;
  struct capabilities *cap = 0;

  *neg_p = 0;    /* clear negative flag... */

  if (!inited)
  {
    /* First, let's sort the array... */
    qsort(capab_list, CAPAB_LIST_LEN, sizeof(struct capabilities), (bqcmp)capab_sort);
    ++inited;
  }

  /* Next, find first non-whitespace character... */
  while (*caplist && IsSpace(*caplist))
    ++caplist;

  /* We are now at the beginning of an element of the list; is it negative? */
  if (*caplist == '-') {
    ++caplist;    /* yes; step past the flag... */
    *neg_p = 1;    /* remember that it is negative... */
  }

  /* OK, now see if we can look up the capability... */
  if (*caplist) {
    if (!(cap = bsearch(caplist, capab_list, CAPAB_LIST_LEN,
                        sizeof(struct capabilities),
                        (bqcmp)capab_search)))
    {
      /* Couldn't find the capability; advance to first whitespace character */
      while (*caplist && !IsSpace(*caplist))
	++caplist;
    }
    else
      caplist += cap->namelen; /* advance to end of capability name */
  }

  assert(caplist != *caplist_p || !*caplist); /* we *must* advance */

  /* move ahead in capability list string--or zero pointer if we hit end */
  *caplist_p = *caplist ? caplist : 0;

  return cap;    /* and return the capability (if any) */
}

/** Send a CAP \a subcmd list of capability changes to \a sptr.
 * If more than one line is necessary, each line before the last has
 * an added "*" parameter before that line's capability list.
 * @param[in] sptr Client receiving capability list.
 * @param[in] set Capabilities to show as set (with ack and sticky modifiers).
 * @param[in] rem Capabalities to show as removed (with no other modifier).
 * @param[in] subcmd Name of capability subcommand.
 */
static int
send_caplist(struct Client *sptr, unsigned int set,
             unsigned int rem, const char *subcmd)
{
  char capbuf[IRCD_BUFSIZE] = "", pfx[16];
  char cmdbuf[IRCD_BUFSIZE] = "";
  int i, loc, len, flags, pfx_len, clen;

  /* set up the buffer for the final LS message... */
  clen = snprintf(cmdbuf, sizeof(capbuf), ":%s CAP %s %s ", me.name,
                  sptr->name[0] ? sptr->name : "*", subcmd);

  for (i = 0, loc = 0; i < CAPAB_LIST_LEN; ++i)
  {
    flags = capab_list[i].flags;

    /*
     * This is a little bit subtle, but just involves applying de
     * Morgan's laws to the obvious check: We must display the
     * capability if (and only if) it is set in \a rem or \a set, or
     * if both are null and the capability is hidden.
     */
    if (!(rem && (rem & capab_list[i].cap)) &&
        !(set && (set & capab_list[i].cap)) &&
         (rem || set || (flags & CAPFL_HIDDEN)))
      continue;

    /* Build the prefix (space separator and any modifiers needed). */
    pfx_len = 0;

    if (loc)
      pfx[pfx_len++] = ' ';
    if (rem && (rem & capab_list[i].cap))
      pfx[pfx_len++] = '-';
    else
    {
      if (flags & CAPFL_PROTO)
        pfx[pfx_len++] = '~';
      if (flags & CAPFL_STICKY)
        pfx[pfx_len++] = '=';
    }

    pfx[pfx_len] = '\0';

    len = capab_list[i].namelen + pfx_len;    /* how much we'd add... */

    if (sizeof(capbuf) < (clen + loc + len + 15))
    {
      /* would add too much; must flush */
      sendto_one(sptr, "%s* :%s", cmdbuf, capbuf);
      capbuf[(loc = 0)] = '\0';    /* re-terminate the buffer... */
    }

    loc += snprintf(capbuf + loc, sizeof(capbuf) - loc,
                    "%s%s", pfx, capab_list[i].name);
  }

  sendto_one(sptr, "%s:%s", cmdbuf, capbuf);

  return 0;    /* convenience return */
}

static int
cap_ls(struct Client *sptr, const char *caplist)
{
  if (IsUnknown(sptr)) /* registration hasn't completed; suspend it... */
    sptr->localClient->registration |= REG_NEED_CAP;

  return send_caplist(sptr, 0, 0, "LS"); /* send list of capabilities */
}

static int
cap_req(struct Client *sptr, const char *caplist)
{
  const char *cl = caplist;
  struct capabilities *cap;
  unsigned int set = 0, rem = 0;
  unsigned int cs = sptr->localClient->cap_client; /* capability set */
  unsigned int as = sptr->localClient->cap_active; /* active set */
  int neg;

  if (IsUnknown(sptr)) /* registration hasn't completed; suspend it... */
    sptr->localClient->registration |= REG_NEED_CAP;

  while (cl) { /* walk through the capabilities list... */
    if (!(cap = find_cap(&cl, &neg)) /* look up capability... */
	|| (!neg && (cap->flags & CAPFL_PROHIBIT)) /* is it prohibited? */
        || (neg && (cap->flags & CAPFL_STICKY))) { /* is it sticky? */
      sendto_one(sptr, ":%s CAP %s NAK :%s", me.name,
                 sptr->name[0] ? sptr->name : "*", caplist);
      return 0; /* can't complete requested op... */
    }

    if (neg)
    {
      /* set or clear the capability... */
      rem |=  cap->cap;
      set &= ~cap->cap;
      cs  &= ~cap->cap;

      if (!(cap->flags & CAPFL_PROTO))
        as &= ~cap->cap;
    }
    else
    {
      rem &= ~cap->cap;
      set |=  cap->cap;
      cs  |=  cap->cap;

      if (!(cap->flags & CAPFL_PROTO))
        as |= cap->cap;
    }
  }

  /* Notify client of accepted changes and copy over results. */
  send_caplist(sptr, set, rem, "ACK");

  sptr->localClient->cap_client = cs;
  sptr->localClient->cap_active = as;

  return 0;
}

static int
cap_ack(struct Client *sptr, const char *caplist)
{
  const char *cl = caplist;
  struct capabilities *cap = NULL;
  int neg;

  /*
   * Coming from the client, this generally indicates that the client
   * is using a new backwards-incompatible protocol feature.  As such,
   * it does not require further response from the server.
   */
  while (cl)
  {
    /* walk through the capabilities list... */
    if (!(cap = find_cap(&cl, &neg)) || /* look up capability... */
	(neg ? (sptr->localClient->cap_active & cap->cap) :
              !(sptr->localClient->cap_active & cap->cap))) /* uh... */
      continue;

    if (neg)    /* set or clear the active capability... */
      sptr->localClient->cap_active &= ~cap->cap;
    else
      sptr->localClient->cap_active |=  cap->cap;
  }

  return 0;
}

static int
cap_clear(struct Client *sptr, const char *caplist)
{
  struct capabilities *cap;
  unsigned int ii;
  unsigned int cleared = 0;

  for (ii = 0; ii < CAPAB_LIST_LEN; ++ii)
  {
    cap = &capab_list[ii];

    /* Only clear active non-sticky capabilities. */
    if (!(sptr->localClient->cap_active & cap->cap) || (cap->flags & CAPFL_STICKY))
      continue;

    cleared |= cap->cap;
    sptr->localClient->cap_client &= ~cap->cap;

    if (!(cap->flags & CAPFL_PROTO))
      sptr->localClient->cap_active &= ~cap->cap;
  }

  return send_caplist(sptr, 0, cleared, "ACK");
}

static int
cap_end(struct Client *sptr, const char *caplist)
{
  if (!IsUnknown(sptr))    /* registration has completed... */
    return 0;    /* so just ignore the message... */

  /* capability negotiation is now done... */
  sptr->localClient->registration &= ~REG_NEED_CAP;

  /* if client is now done... */
  if (!sptr->localClient->registration)
  {
    char buf[USERLEN + 1];

    strlcpy(buf, sptr->username, sizeof(buf));
    register_local_user(sptr, sptr, sptr->name, buf);
    return 0;
  }

  return 0;    /* Can't do registration yet... */
}

static int
cap_list(struct Client *sptr, const char *caplist)
{
  /* Send the list of the client's capabilities */
  return send_caplist(sptr, sptr->localClient->cap_client, 0, "LIST");
}

static struct subcmd
{
  char *cmd;
  int (*proc)(struct Client *sptr, const char *caplist);
} cmdlist[] = {
  { "ACK",   cap_ack   },
  { "CLEAR", cap_clear },
  { "END",   cap_end   },
  { "LIST",  cap_list  },
  { "LS",    cap_ls    },
  { "NAK",   0         },
  { "REQ",   cap_req   }
};

static int
subcmd_search(const char *cmd, const struct subcmd *elem)
{
  return strcasecmp(cmd, elem->cmd);
}

/** Handle a capability request or response from a client.
 * \param cptr Client that sent us the message.
 * \param sptr Original source of message.
 * \param parc Number of arguments.
 * \param parv Argument vector.
 */
static void
m_cap(struct Client *cptr, struct Client *sptr, int parc, char *parv[])
{
  char *subcmd, *caplist = 0;
  struct subcmd *cmd = NULL;

  if (parc < 2)    /* a subcommand is required */
    return;

  subcmd = parv[1];

  if (parc > 2)    /* a capability list was provided */
    caplist = parv[2];

  /* find the subcommand handler */
  if (!(cmd = bsearch(subcmd, cmdlist,
                      sizeof(cmdlist) / sizeof(struct subcmd),
                      sizeof(struct subcmd), (bqcmp)subcmd_search)))
  {
    sendto_one(sptr, form_str(ERR_INVALIDCAPCMD),
               me.name, sptr->name, subcmd);
    return;
  }

  /* then execute it... */
  if (cmd->proc)
    (cmd->proc)(sptr, caplist);
}

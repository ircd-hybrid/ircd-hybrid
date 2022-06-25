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

/*! \file channel_mode.c
 * \brief Controls modes on channels.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "conf.h"
#include "hostmask.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "memory.h"
#include "parse.h"
#include "extban.h"
#include "isupport.h"
#include "server_capab.h"


/** Buffer holding as list of channel modes to be used for RPL_MYINFO */
char cmode_rpl04[2][256];
/** Buffer holding as list of channel modes to be used for RPL_ISUPPORT */
char cmode_class[4][256];

static struct ChModeChange mode_changes[IRCD_BUFSIZE];
static unsigned int mode_count;
static unsigned int mode_limit;  /* number of modes set other than simple */
static unsigned int simple_modes_mask;  /* bit mask of simple modes already set */


/* check_string()
 *
 * inputs       - string to check
 * output       - pointer to modified string
 * side effects - Fixes a string so that the first white space found
 *                becomes an end of string marker (`\0`).
 *                returns the 'fixed' string or "*" if the string
 *                was NULL length or a NULL pointer.
 */
static void
check_string(char *s)
{
  char *str = s;

  assert(s);

  for (; *s; ++s)
  {
    if (IsSpace(*s))
    {
      *s = '\0';
      break;
    }
  }

  if (EmptyString(str))
    strcpy(str, "*");
}

static const char *
get_mask(const struct Ban *ban)
{
  static char buf[MODEBUFLEN];
  const size_t len = extban_format(ban->extban, buf);

  assert(len <= sizeof(buf));

  /* Matching extbans only use ban->host */
  if (ban->extban & extban_matching_mask())
    strlcpy(buf + len, ban->host, sizeof(buf) - len);
  else
    snprintf(buf + len, sizeof(buf) - len, "%s!%s@%s", ban->name, ban->user, ban->host);

  return buf;
}

/*
 * Ban functions to work with mode +b/e/I
 */
/* add the specified ID to the channel.
 *   -is 8/9/00
 */

const char *
add_id(struct Client *client, struct Channel *channel, const char *banid, dlink_list *list, unsigned int type)
{
  char mask[MODEBUFLEN];
  char *maskptr = mask;
  unsigned int extbans, offset;

  strlcpy(mask, banid, sizeof(mask));

  if (MyClient(client))
  {
    unsigned int num_mask = dlink_list_length(&channel->banlist) +
                            dlink_list_length(&channel->exceptlist) +
                            dlink_list_length(&channel->invexlist);

    /* Don't let local clients overflow the b/e/I lists */
    if (num_mask >= ((HasCMode(channel, MODE_EXTLIMIT)) ? ConfigChannel.max_bans_large :
                                                          ConfigChannel.max_bans))
    {
      sendto_one_numeric(client, &me, ERR_BANLISTFULL, channel->name, banid);
      return NULL;
    }

    collapse(mask);
  }

  enum extban_type etype = extban_parse(mask, &extbans, &offset);
  maskptr += offset;

  if (MyClient(client))
  {
    if (etype == EXTBAN_INVALID)
    {
      sendto_one_numeric(client, &me, ERR_INVALIDBAN, channel->name, mask);
      return NULL;
    }

    if (etype != EXTBAN_NONE && ConfigChannel.enable_extbans == 0)
    {
      sendto_one_numeric(client, &me, ERR_INVALIDBAN, channel->name, mask);
      return NULL;
    }

    unsigned int extban_acting = extbans & extban_acting_mask();
    if (extban_acting)
    {
      const struct Extban *extban = extban_find_flag(extban_acting);
      if (extban == NULL || !(extban->types & type))
      {
        sendto_one_numeric(client, &me, ERR_INVALIDBAN, channel->name, mask);
        return NULL;
      }
    }

    unsigned extban_matching = extbans & extban_matching_mask();
    if (extban_matching)
    {
      const struct Extban *extban = extban_find_flag(extban_matching);
      if (extban == NULL || !(extban->types & type))
      {
        sendto_one_numeric(client, &me, ERR_INVALIDBAN, channel->name, mask);
        return NULL;
      }
    }
  }

  /* Don't allow empty bans */
  if (EmptyString(maskptr))
    return NULL;

  struct Ban *ban = xcalloc(sizeof(*ban));
  ban->extban = extbans;
  ban->when = event_base->time.sec_real;

  check_string(maskptr);

  if (etype == EXTBAN_MATCHING)
    /* Matching extbans have their own format, don't try to parse it */
    strlcpy(ban->host, maskptr, sizeof(ban->host));
  else
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = maskptr;
    nuh.nickptr  = ban->name;
    nuh.userptr  = ban->user;
    nuh.hostptr  = ban->host;

    nuh.nicksize = sizeof(ban->name);
    nuh.usersize = sizeof(ban->user);
    nuh.hostsize = sizeof(ban->host);

    split_nuh(&nuh);

    ban->type = parse_netmask(ban->host, &ban->addr, &ban->bits);
  }

  if (MyClient(client))
    ban->banstr_len = strlcpy(ban->banstr, get_mask(ban), sizeof(ban->banstr));
  else
    ban->banstr_len = strlcpy(ban->banstr, banid, sizeof(ban->banstr));

  dlink_node *node;
  DLINK_FOREACH(node, list->head)
  {
    const struct Ban *tmp = node->data;

    if (irccmp(tmp->banstr, ban->banstr) == 0)
    {
      xfree(ban);
      return NULL;
    }
  }

  clear_ban_cache_list(&channel->members_local);

  if (IsClient(client))
    snprintf(ban->who, sizeof(ban->who), "%s!%s@%s", client->name,
             client->username, client->host);
  else if (IsHidden(client) || ConfigServerHide.hide_servers)
    strlcpy(ban->who, me.name, sizeof(ban->who));
  else
    strlcpy(ban->who, client->name, sizeof(ban->who));

  dlinkAdd(ban, &ban->node, list);

  return ban->banstr;
}

/*
 * inputs	- pointer to channel
 *		- pointer to ban id
 *		- type of ban, i.e. ban, exception, invex
 * output	- 0 for failure, 1 for success
 * side effects	-
 */
static const char *
del_id(struct Client *client, struct Channel *channel, const char *banid, dlink_list *list, unsigned int type)
{
  static char mask[MODEBUFLEN];
  dlink_node *node;

  assert(banid);

  /* TBD: n!u@h formatting fo local clients */

  DLINK_FOREACH(node, list->head)
  {
    struct Ban *ban = node->data;

    if (irccmp(banid, ban->banstr) == 0)
    {
      strlcpy(mask, ban->banstr, sizeof(mask));  /* caSe might be different in 'banid' */
      clear_ban_cache_list(&channel->members_local);
      remove_ban(ban, list);

      return mask;
    }
  }

  return NULL;
}

/* channel_modes()
 *
 * inputs       - pointer to channel
 *              - pointer to client
 *              - pointer to mode buf
 *              - pointer to parameter buf
 * output       - NONE
 * side effects - write the "simple" list of channel modes for channel
 * channel onto buffer mbuf with the parameters in pbuf.
 */
const char *
channel_modes(const struct Channel *channel, const struct Client *client, bool params)
{
  static char buf[MODEBUFLEN];
  char *bufptr = buf;
  bool server_or_member = false;

  *bufptr++ = '+';

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
    if (tab->mode && HasCMode(channel, tab->mode))
      *bufptr++ = tab->letter;

  if (channel->mode.limit)
  {
    *bufptr++ = 'l';

    if (params == true)
      server_or_member =
        (server_or_member == true || IsServer(client) || member_find_link(client, channel));
  }

  if (channel->mode.key[0])
  {
    *bufptr++ = 'k';

    if (params == true)
      server_or_member =
        (server_or_member == true || IsServer(client) || member_find_link(client, channel));
  }

  if (server_or_member == true)
  {
    if (channel->mode.limit)
      bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), " %u", channel->mode.limit);
    if (channel->mode.key[0])
      bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), " %s", channel->mode.key);
  }

  *bufptr = '\0';
  return buf;
}

/* fix_key()
 *
 * inputs       - pointer to key to clean up
 * output       - pointer to cleaned up key
 * side effects - input string is modified
 *
 * stolen from Undernet's ircd  -orabidoo
 */
static char *
fix_key(char *arg)
{
  unsigned char *s = (unsigned char *)arg;
  unsigned char *t = (unsigned char *)arg;

  for (unsigned char c; (c = *s) && s - (unsigned char *)arg < KEYLEN; ++s)
  {
    c &= 0x7f;

    if (c != ':' && c > ' ' && c != ',')
      *t++ = c;
  }

  *t = '\0';
  return arg;
}

/*
 * inputs       - pointer to channel
 * output       - none
 * side effects - clear ban cache
 */
void
clear_ban_cache_list(dlink_list *list)
{
  dlink_node *node;

  DLINK_FOREACH(node, list->head)
  {
    struct ChannelMember *member = node->data;
    member->flags &= ~(CHFL_BAN_SILENCED | CHFL_BAN_CHECKED);
  }
}

/*
 * Bitmasks for various error returns that channel_mode_set should only return
 * once per call  -orabidoo
 */
enum
{
  SM_ERR_NOOPS        = 1 << 0,  /* No chan ops */
  SM_ERR_UNKNOWN      = 1 << 1,
  SM_ERR_RPL_B        = 1 << 2,
  SM_ERR_RPL_E        = 1 << 3,
  SM_ERR_RPL_I        = 1 << 4,
  SM_ERR_NOTONCHANNEL = 1 << 5,  /* Client is not on channel */
  SM_ERR_NOTOPER      = 1 << 6,  /* Only irc-operators can change that mode */
  SM_ERR_ONLYSERVER   = 1 << 7   /* Only servers or services can change that mode */
};

static bool
channel_mode_can_change(struct Client *client, struct Channel *channel, int *errors, int rank,
                        const char c, const struct chan_mode *mode)
{
  if (mode->only_opers == true)
  {
    if (MyClient(client) && !HasUMode(client, UMODE_OPER))
    {
      if (!(*errors & SM_ERR_NOTOPER))
        sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);

      *errors |= SM_ERR_NOTOPER;
      return false;
    }
  }

  if (mode->only_servers == true)
  {
    if (!IsServer(client) && !HasFlag(client, FLAGS_SERVICE))
    {
      if (!(*errors & SM_ERR_ONLYSERVER))
        sendto_one_numeric(client, &me,
                           rank == CHACCESS_NOTONCHAN ? ERR_NOTONCHANNEL :
                           ERR_ONLYSERVERSCANCHANGE, channel->name);

      *errors |= SM_ERR_ONLYSERVER;
      return false;
    }
  }

  if (rank < mode->required_rank)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one_numeric(client, &me,
                         rank == CHACCESS_NOTONCHAN ? ERR_NOTONCHANNEL :
                         ERR_CHANOPRIVSNEEDED, channel->name);

    *errors |= SM_ERR_NOOPS;
    return false;
  }

  return true;
}

/* Mode functions handle mode changes for a particular mode... */
static void
chm_nosuch(struct Client *client, struct Channel *channel, int parc, int *parn, char **parv,
           int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (*errors & SM_ERR_UNKNOWN)
    return;

  *errors |= SM_ERR_UNKNOWN;
  sendto_one_numeric(client, &me, ERR_UNKNOWNMODE, c);
}

static void
chm_simple(struct Client *client, struct Channel *channel, int parc, int *parn, char **parv,
           int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (channel_mode_can_change(client, channel, errors, rank, c, mode) == false)
    return;

  /* If have already dealt with this simple mode, ignore it */
  if (simple_modes_mask & mode->mode)
    return;

  simple_modes_mask |= mode->mode;

  if (dir == MODE_ADD)  /* setting + */
  {
    if (MyClient(client) && HasCMode(channel, mode->mode))
      return;

    AddCMode(channel, mode->mode);
  }
  else if (dir == MODE_DEL)  /* setting - */
  {
    if (MyClient(client) && !HasCMode(channel, mode->mode))
      return;

    DelCMode(channel, mode->mode);
  }

  mode_changes[mode_count].letter = mode->letter;
  mode_changes[mode_count].arg = NULL;
  mode_changes[mode_count].id = NULL;
  mode_changes[mode_count++].dir = dir;
}

static void
chm_mask(struct Client *client, struct Channel *channel, int parc, int *parn, char **parv,
         int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  const char *ret = NULL;
  dlink_list *list;
  enum irc_numerics rpl_list = 0, rpl_endlist = 0;
  int errtype = 0;

  switch (mode->flag)
  {
    case CHFL_BAN:
      errtype = SM_ERR_RPL_B;
      list = &channel->banlist;
      rpl_list = RPL_BANLIST;
      rpl_endlist = RPL_ENDOFBANLIST;
      break;
    case CHFL_EXCEPTION:
      errtype = SM_ERR_RPL_E;
      list = &channel->exceptlist;
      rpl_list = RPL_EXCEPTLIST;
      rpl_endlist = RPL_ENDOFEXCEPTLIST;
      break;
    case CHFL_INVEX:
      errtype = SM_ERR_RPL_I;
      list = &channel->invexlist;
      rpl_list = RPL_INVEXLIST;
      rpl_endlist = RPL_ENDOFINVEXLIST;
      break;
    default:
      list = NULL;  /* Let it crash */
  }

  if (dir == MODE_QUERY || parc <= *parn)
  {
    if (*errors & errtype)
      return;

    *errors |= errtype;

    dlink_node *node;
    DLINK_FOREACH(node, list->head)
    {
      const struct Ban *ban = node->data;
      sendto_one_numeric(client, &me, rpl_list, channel->name,
                         ban->banstr, ban->who, ban->when);
    }

    sendto_one_numeric(client, &me, rpl_endlist, channel->name);
    return;
  }

  if (channel_mode_can_change(client, channel, errors, rank, c, mode) == false)
    return;

  if (MyClient(client) && (++mode_limit > MAXMODEPARAMS))
    return;

  char *mask = parv[*parn];
  ++(*parn);

  if (*mask == ':' || (!MyConnect(client) && strchr(mask, ' ')))
    return;

  if (dir == MODE_ADD)  /* setting + */
  {
    ret = add_id(client, channel, mask, list, mode->flag);
    if (ret == NULL)
      return;
  }
  else if (dir == MODE_DEL)  /* setting - */
  {
    ret = del_id(client, channel, mask, list, mode->flag);
    if (ret == NULL)
      return;
  }

  static char buf[MAXPARA][MODEBUFLEN];
  mask = buf[(*parn) - 1];
  strlcpy(mask, ret, sizeof(buf[(*parn) - 1]));

  mode_changes[mode_count].letter = mode->letter;
  mode_changes[mode_count].arg = mask;  /* At this point 'mask' is no longer than MODEBUFLEN */
  mode_changes[mode_count].id = NULL;
  mode_changes[mode_count++].dir = dir;
}

static void
chm_flag(struct Client *client, struct Channel *channel, int parc, int *parn, char **parv,
         int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (channel_mode_can_change(client, channel, errors, rank, c, mode) == false)
    return;

  if (dir == MODE_QUERY || parc <= *parn)
    return;

  struct Client *client_target = find_chasing(client, parv[(*parn)++]);
  if (client_target == NULL)
    return;  /* find_chasing sends ERR_NOSUCHNICK */

  struct ChannelMember *member = member_find_link(client_target, channel);
  if (member == NULL)
  {
    if (!(*errors & SM_ERR_NOTONCHANNEL))
      sendto_one_numeric(client, &me, ERR_USERNOTINCHANNEL, client_target->name, channel->name);

    *errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  if (MyClient(client) && (++mode_limit > MAXMODEPARAMS))
    return;

  if (dir == MODE_ADD)  /* setting + */
  {
    if (member_has_flags(member, mode->flag) == true)
      return;  /* No redundant mode changes */

    AddMemberFlag(member, mode->flag);
  }
  else if (dir == MODE_DEL)  /* setting - */
  {
    if (member_has_flags(member, mode->flag) == false)
      return;  /* No redundant mode changes */

    DelMemberFlag(member, mode->flag);
  }

  mode_changes[mode_count].letter = mode->letter;
  mode_changes[mode_count].arg = client_target->name;
  mode_changes[mode_count].id = client_target->id;
  mode_changes[mode_count++].dir = dir;
}

static void
chm_limit(struct Client *client, struct Channel *channel, int parc, int *parn, char **parv,
          int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (channel_mode_can_change(client, channel, errors, rank, c, mode) == false)
    return;

  if (dir == MODE_QUERY)
    return;

  if (dir == MODE_ADD && parc > *parn)
  {
    char *const lstr = parv[(*parn)++];
    int limit = 0;

    if (EmptyString(lstr) || (limit = atoi(lstr)) <= 0)
      return;

    sprintf(lstr, "%d", limit);

    /* If somebody sets MODE #channel +ll 1 2, accept latter --fl */
    for (unsigned int i = 0; i < mode_count; ++i)
      if (mode_changes[i].letter == mode->letter && mode_changes[i].dir == MODE_ADD)
        mode_changes[i].letter = 0;

    mode_changes[mode_count].letter = mode->letter;
    mode_changes[mode_count].arg = lstr;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].dir = dir;

    channel->mode.limit = limit;
  }
  else if (dir == MODE_DEL)
  {
    if (channel->mode.limit == 0)
      return;

    channel->mode.limit = 0;

    mode_changes[mode_count].letter = mode->letter;
    mode_changes[mode_count].arg = NULL;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].dir = dir;
  }
}

static void
chm_key(struct Client *client, struct Channel *channel, int parc, int *parn, char **parv,
        int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (channel_mode_can_change(client, channel, errors, rank, c, mode) == false)
    return;

  if (dir == MODE_QUERY)
    return;

  if (dir == MODE_ADD && parc > *parn)
  {
    char *const key = fix_key(parv[(*parn)++]);

    if (EmptyString(key))
      return;

    assert(key[0] != ' ');
    strlcpy(channel->mode.key, key, sizeof(channel->mode.key));

    /* If somebody does MODE #channel +kk a b, accept latter --fl */
    for (unsigned int i = 0; i < mode_count; ++i)
      if (mode_changes[i].letter == mode->letter && mode_changes[i].dir == MODE_ADD)
        mode_changes[i].letter = 0;

    mode_changes[mode_count].letter = mode->letter;
    mode_changes[mode_count].arg = key;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].dir = dir;
  }
  else if (dir == MODE_DEL)
  {
    if (parc > *parn)
      ++(*parn);

    if (channel->mode.key[0] == '\0')
      return;

    channel->mode.key[0] = '\0';

    mode_changes[mode_count].letter = mode->letter;
    mode_changes[mode_count].arg = "*";
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].dir = dir;
  }
}

/* send_mode_changes_server()
 * Input: the source client(client),
 *        the channel to send mode changes for(channel)
 * Output: None.
 * Side-effects: Sends the appropriate mode changes to servers.
 *
 */
static void
send_mode_changes_server(struct Client *client, struct Channel *channel)
{
  char modebuf[IRCD_BUFSIZE] = "";
  char parabuf[IRCD_BUFSIZE] = "";  /* Essential that parabuf[0] = '\0' */
  char *parptr = parabuf;
  unsigned int mbl = 0, pbl = 0, arglen = 0, modecount = 0, paracount = 0;
  unsigned int dir = MODE_QUERY;

  mbl = snprintf(modebuf, sizeof(modebuf), ":%s TMODE %ju %s ",
                 client->id, channel->creation_time, channel->name);

  /* Loop the list of modes we have */
  for (unsigned int i = 0; i < mode_count; ++i)
  {
    if (mode_changes[i].letter == 0)
      continue;

    const char *arg;
    if (mode_changes[i].id)
      arg = mode_changes[i].id;
    else
      arg = mode_changes[i].arg;

    if (arg)
      arglen = strlen(arg);
    else
      arglen = 0;

    /*
     * If we're creeping past the buf size, we need to send it and make
     * another line for the other modes
     */
    if ((paracount == MAXMODEPARAMS) ||
        ((arglen + mbl + pbl + 2 /* +2 for /r/n */ ) > sizeof(modebuf)))
    {
      if (modecount)
        sendto_server(client, 0, 0, paracount == 0 ? "%s" : "%s %s", modebuf, parabuf);

      modecount = 0;
      paracount = 0;

      mbl = snprintf(modebuf, sizeof(modebuf), ":%s TMODE %ju %s ",
                     client->id, channel->creation_time, channel->name);

      pbl = 0;
      parabuf[0] = '\0';
      parptr = parabuf;
      dir = MODE_QUERY;
    }

    if (dir != mode_changes[i].dir)
    {
      modebuf[mbl++] = (mode_changes[i].dir == MODE_ADD) ? '+' : '-';
      dir = mode_changes[i].dir;
    }

    modebuf[mbl++] = mode_changes[i].letter;
    modebuf[mbl] = '\0';
    ++modecount;

    if (arg)
    {
      int len = sprintf(parptr, (pbl == 0) ? "%s" : " %s", arg);
      pbl += len;
      parptr += len;
      ++paracount;
    }
  }

  if (modecount)
    sendto_server(client, 0, 0, paracount == 0 ? "%s" : "%s %s", modebuf, parabuf);
}

/* void send_mode_changes(struct Client *client,
 *                        struct Client *client,
 *                        struct Channel *channel)
 * Input: The client sending(client), the source client(client),
 *        the channel to send mode changes for(channel),
 *        mode change globals.
 * Output: None.
 * Side-effects: Sends the appropriate mode changes to other clients
 *               and propagates to servers.
 */
static void
send_mode_changes_client(struct Client *client, struct Channel *channel)
{
  char modebuf[IRCD_BUFSIZE] = "";
  char parabuf[IRCD_BUFSIZE] = "";  /* Essential that parabuf[0] = '\0' */
  char *parptr = parabuf;
  unsigned int mbl = 0, pbl = 0, arglen = 0, modecount = 0, paracount = 0;
  unsigned int dir = MODE_QUERY;

  if (IsClient(client))
    mbl = snprintf(modebuf, sizeof(modebuf), ":%s!%s@%s MODE %s ", client->name,
                   client->username, client->host, channel->name);
  else
    mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ", (IsHidden(client) ||
                   ConfigServerHide.hide_servers) ?
                   me.name : client->name, channel->name);

  for (unsigned int i = 0; i < mode_count; ++i)
  {
    if (mode_changes[i].letter == 0)
      continue;

    const char *arg = mode_changes[i].arg;
    if (arg)
      arglen = strlen(arg);
    else
      arglen = 0;

    if ((paracount == MAXMODEPARAMS) ||
        ((arglen + mbl + pbl + 2 /* +2 for /r/n */ ) > sizeof(modebuf)))
    {
      if (modecount)
        sendto_channel_local(NULL, channel, 0, 0, 0, paracount == 0 ? "%s" : "%s %s", modebuf, parabuf);

      modecount = 0;
      paracount = 0;

      if (IsClient(client))
        mbl = snprintf(modebuf, sizeof(modebuf), ":%s!%s@%s MODE %s ", client->name,
                       client->username, client->host, channel->name);
      else
        mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ", (IsHidden(client) ||
                       ConfigServerHide.hide_servers) ?
                       me.name : client->name, channel->name);

      pbl = 0;
      parabuf[0] = '\0';
      parptr = parabuf;
      dir = MODE_QUERY;
    }

    if (dir != mode_changes[i].dir)
    {
      modebuf[mbl++] = (mode_changes[i].dir == MODE_ADD) ? '+' : '-';
      dir = mode_changes[i].dir;
    }

    modebuf[mbl++] = mode_changes[i].letter;
    modebuf[mbl] = '\0';
    ++modecount;

    if (arg)
    {
      int len = sprintf(parptr, (pbl == 0) ? "%s" : " %s", arg);
      pbl += len;
      parptr += len;
      ++paracount;
    }
  }

  if (modecount)
    sendto_channel_local(NULL, channel, 0, 0, 0, paracount == 0 ? "%s" : "%s %s", modebuf, parabuf);
}

const struct chan_mode *cmode_map[256];
const struct chan_mode cmode_tab[] =
{
  { .letter = 'b', .flag = CHFL_BAN, .required_rank = CHACCESS_HALFOP, .func = chm_mask, .class = MODE_CLASS_A },
  { .letter = 'c', .mode = MODE_NOCTRL, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'e', .flag = CHFL_EXCEPTION, .required_rank = CHACCESS_HALFOP, .func = chm_mask, .class = MODE_CLASS_A },
  { .letter = 'i', .mode = MODE_INVITEONLY, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'k', .func = chm_key, .required_rank = CHACCESS_HALFOP, .class = MODE_CLASS_B },
  { .letter = 'l', .func = chm_limit, .required_rank = CHACCESS_HALFOP, .class = MODE_CLASS_C },
  { .letter = 'm', .mode = MODE_MODERATED, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'n', .mode = MODE_NOPRIVMSGS, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'p', .mode = MODE_PRIVATE, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'r', .mode = MODE_REGISTERED, .required_rank = CHACCESS_REMOTE, .only_servers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 's', .mode = MODE_SECRET, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 't', .mode = MODE_TOPICLIMIT, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'C', .mode = MODE_NOCTCP, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'I', .flag = CHFL_INVEX, .required_rank = CHACCESS_HALFOP, .func = chm_mask, .class = MODE_CLASS_A },
  { .letter = 'K', .mode = MODE_NOKNOCK, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'L', .mode = MODE_EXTLIMIT, .required_rank = CHACCESS_HALFOP, .only_opers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'M', .mode = MODE_MODREG, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'N', .mode = MODE_NONICKCHANGE, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'O', .mode = MODE_OPERONLY, .required_rank = CHACCESS_HALFOP, .only_opers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'R', .mode = MODE_REGONLY, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'S', .mode = MODE_SECUREONLY, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'T', .mode = MODE_NONOTICE, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = '\0' }
};

/*
 * XXX: Currently this needs to be sorted from highest to lowest rank.
 */
const struct chan_mode cflag_tab[] =
{
  { .letter = 'q', .prefix = '~', .flag = CHFL_CHANOWNER, .rank = CHACCESS_OWNER, .required_rank = CHACCESS_OWNER, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = 'a', .prefix = '&', .flag = CHFL_CHANADMIN, .rank = CHACCESS_ADMIN, .required_rank = CHACCESS_OWNER, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = 'o', .prefix = '@', .flag = CHFL_CHANOP, .rank = CHACCESS_OP, .required_rank = CHACCESS_OP, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = 'h', .prefix = '%', .flag = CHFL_HALFOP, .rank = CHACCESS_HALFOP, .required_rank = CHACCESS_OP, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = 'v', .prefix = '+', .flag = CHFL_VOICE, .rank = CHACCESS_VOICE, .required_rank = CHACCESS_HALFOP, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = '\0' }
};

void
channel_mode_init(void)
{
  char letter[8] = "";
  char prefix[8] = "";

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
    cmode_map[tab->letter] = tab;

  for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
  {
    if ((tab->rank == CHACCESS_OWNER && ConfigChannel.enable_owner == 0) ||
        (tab->rank == CHACCESS_ADMIN && ConfigChannel.enable_admin == 0))
      continue;

    cmode_map[tab->letter] = tab;

    const char lstr[] = { tab->letter, '\0' };
    const char pstr[] = { tab->prefix, '\0' };
    strlcat(letter, lstr, sizeof(letter));
    strlcat(prefix, pstr, sizeof(prefix));
  }

  for (unsigned int i = 0; i < 256; ++i)
  {
    const struct chan_mode *cmode = cmode_map[i];
    if (cmode == NULL)
      continue;

    const char str[] = { cmode->letter, '\0' };
    strlcat(cmode_rpl04[0], str, sizeof(cmode_rpl04[0]));

    if (cmode->class != MODE_CLASS_D)
      strlcat(cmode_rpl04[1], str, sizeof(cmode_rpl04[1]));

   /*
    * from draft-brocklesby-irc-isupport-03:
    * The IRC server MUST NOT list modes in CHANMODES which are also
    * present in the PREFIX parameter; however, for completeness, modes
    * described in PREFIX may be treated as type B modes.
    */
    if (cmode->prefix == '\0')
      strlcat(cmode_class[cmode->class], str, sizeof(cmode_class[cmode->class]));
  }

  char buf[IRCD_BUFSIZE];
  snprintf(buf, sizeof(buf), "%s,%s,%s,%s", cmode_class[MODE_CLASS_A],
           cmode_class[MODE_CLASS_B],
           cmode_class[MODE_CLASS_C],
           cmode_class[MODE_CLASS_D]);
  isupport_add("CHANMODES", buf, -1);


  snprintf(buf, sizeof(buf), "(%s)%s", letter, prefix);
  isupport_add("PREFIX", buf, -1);
  isupport_add("STATUSMSG", prefix, -1);

  capab_add("QOP", CAPAB_QOP, ConfigChannel.enable_owner != 0);
  capab_add("AOP", CAPAB_AOP, ConfigChannel.enable_admin != 0);
  capab_add("HOP", CAPAB_HOP, true);
}

/*
 * Input: The the client this originated
 *        from, the channel, the parameter count starting at the modes,
 *        the parameters, the channel name.
 * Output: None.
 * Side-effects: Changes the channel membership and modes appropriately,
 *               sends the appropriate MODE messages to the appropriate
 *               clients.
 */
void
channel_mode_set(struct Client *client, struct Channel *channel, int parc, char *parv[])
{
  int dir = MODE_ADD;
  int parn = 1;
  int errors = 0;
  int rank = CHACCESS_REMOTE;  /* Let hacked servers in for now... */

  if (MyClient(client))
    rank = member_highest_rank(member_find_link(client, channel));

  mode_count = 0;
  mode_limit = 0;
  simple_modes_mask = 0;

  for (const char *ml = parv[0]; *ml; ++ml)
  {
    switch (*ml)
    {
      case '+':
        dir = MODE_ADD;
        break;
      case '-':
        dir = MODE_DEL;
        break;
      case '=':
        dir = MODE_QUERY;
        break;
      default:
      {
        const struct chan_mode *mode = cmode_map[(unsigned char)*ml];

        if (mode)
          mode->func(client, channel, parc, &parn, parv, &errors, rank, dir, *ml, mode);
        else
          chm_nosuch(client, channel, parc, &parn, parv, &errors, rank, dir, *ml, NULL);
        break;
      }
    }
  }

  /* Bail out if we have nothing to do... */
  if (mode_count == 0)
    return;

  send_mode_changes_client(client, channel);
  send_mode_changes_server(client, channel);
}

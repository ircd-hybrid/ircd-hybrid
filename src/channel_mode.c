/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file channel_mode.c
 * \brief Controls modes on channels.
 */

#include <assert.h>
#include <stdlib.h>

#include "address.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "conf.h"
#include "extban.h"
#include "ircd.h"
#include "isupport.h"
#include "nuh.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "server_capab.h"
#include "user_mode.h"

/** Buffer holding a list of channel modes to be used for RPL_MYINFO */
char cmode_rpl04[2][256];
/** Buffer holding a list of channel modes to be used for RPL_ISUPPORT */
char cmode_class[4][256];

static struct ChModeChange mode_changes[IRCD_BUFSIZE];
static unsigned int mode_count;
static unsigned int mode_limit;  /* number of modes set other than simple */
static uint32_t simple_modes_mask;  /* bit mask of simple modes already set */

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

  if (string_is_empty(str))
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

const char *
add_id(struct Client *client, struct Channel *channel, const char *banid, list_t *list, uint32_t type)
{
  char mask[MODEBUFLEN];
  char *maskptr = mask;

  strlcpy(mask, banid, sizeof(mask));

  if (client_is_local_user(client))
  {
    unsigned int num_mask = list_length(&channel->ban_list) +
                            list_length(&channel->exception_list) +
                            list_length(&channel->invite_exception_list);

    /* Don't let local clients overflow the b/e/I lists */
    if (num_mask >= ((channel_has_mode(channel, MODE_EXTLIMIT)) ? ConfigChannel.max_bans_large : ConfigChannel.max_bans))
    {
      sendto_one_numeric(client, &me, ERR_BANLISTFULL, channel->name, banid);
      return NULL;
    }

    collapse(mask);
  }

  uint32_t extbans;
  size_t offset;
  enum extban_type etype = extban_parse(mask, &extbans, &offset);
  maskptr += offset;

  if (client_is_local_user(client))
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

    uint32_t extban_acting = extbans & extban_acting_mask();
    if (extban_acting)
    {
      const struct Extban *extban = extban_find_flag(extban_acting);
      if (extban == NULL || !(extban->types & type))
      {
        sendto_one_numeric(client, &me, ERR_INVALIDBAN, channel->name, mask);
        return NULL;
      }
    }

    uint32_t extban_matching = extbans & extban_matching_mask();
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
  if (string_is_empty(maskptr))
    return NULL;

  struct Ban *const ban = io_calloc(sizeof(*ban));
  ban->extban = extbans;
  ban->when = io_time_get(IO_TIME_REALTIME_SEC);

  check_string(maskptr);

  if (etype == EXTBAN_MATCHING)
    /* Matching extbans have their own format, don't try to parse it */
    strlcpy(ban->host, maskptr, sizeof(ban->host));
  else
  {
    struct nuh_split nuh =
    {
      .nuhmask = maskptr,
      .nickptr = ban->name,
      .userptr = ban->user,
      .hostptr = ban->host,
      .nicksize = sizeof(ban->name),
      .usersize = sizeof(ban->user),
      .hostsize = sizeof(ban->host)
    };

    nuh_split(&nuh);

    ban->type = address_parse_netmask(ban->host, &ban->addr, &ban->bits);
  }

  if (client_is_local_user(client))
    ban->banstr_len = strlcpy(ban->banstr, get_mask(ban), sizeof(ban->banstr));
  else
    ban->banstr_len = strlcpy(ban->banstr, banid, sizeof(ban->banstr));

  list_node_t *node;
  LIST_FOREACH(node, list->head)
  {
    const struct Ban *const tmp = node->data;
    if (io_strcasecmp(tmp->banstr, ban->banstr) == 0)
    {
      io_free(ban);
      return NULL;
    }
  }

  clear_ban_cache_list(&channel->local_member_list);

  if (client_is_user(client))
    snprintf(ban->who, sizeof(ban->who), "%s!%s@%s",
             client->name, client->username, client->host);
  else
    strlcpy(ban->who, client_get_visible_server_name(client), sizeof(ban->who));

  list_add_tail(ban, &ban->node, list);

  return ban->banstr;
}

static const char *
del_id(struct Client *client, struct Channel *channel, const char *banid, list_t *list, uint32_t type)
{
  static char mask[MODEBUFLEN];
  list_node_t *node;

  assert(banid);

  /* TBD: n!u@h formatting fo local clients */

  LIST_FOREACH(node, list->head)
  {
    struct Ban *const ban = node->data;
    if (io_strcasecmp(banid, ban->banstr) == 0)
    {
      strlcpy(mask, ban->banstr, sizeof(mask));  /* caSe might be different in 'banid' */
      clear_ban_cache_list(&channel->local_member_list);
      remove_ban(ban, list);

      return mask;
    }
  }

  return NULL;
}

const char *
channel_modes(const struct Channel *channel, const struct Client *client, bool params)
{
  static char buf[MODEBUFLEN];
  char *bufptr = buf;
  bool server_or_member = false;

  *bufptr++ = '+';

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
    if (tab->mode && channel_has_mode(channel, tab->mode))
      *bufptr++ = tab->letter;

  if (channel->mode.member_limit)
  {
    *bufptr++ = 'l';

    if (params)
      server_or_member =
        (server_or_member == true || client_is_server(client) || channel_member_find(channel, client));
  }

  if (channel->mode.key[0])
  {
    *bufptr++ = 'k';

    if (params)
      server_or_member =
        (server_or_member == true || client_is_server(client) || channel_member_find(channel, client));
  }

  if (server_or_member)
  {
    if (channel->mode.member_limit)
      bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), " %u", channel->mode.member_limit);
    if (channel->mode.key[0])
      bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), " %s", channel->mode.key);
  }

  *bufptr = '\0';
  return buf;
}

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

void
clear_ban_cache_list(list_t *list)
{
  list_node_t *node;

  LIST_FOREACH(node, list->head)
  {
    struct ChannelMember *const member = node->data;
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
  SM_ERR_ONLYSERVER   = 1 << 7,  /* Only servers or services can change that mode */
  SM_ERR_MLOCK        = 1 << 8,
  SM_ERR_NOSUCHNICK   = 1 << 9,
};

static bool
channel_mode_can_change(struct Client *client, struct Channel *channel, int *errors, int rank,
                        const char c, const struct chan_mode *mode)
{
  if (!client_is_local_user(client))
    return true;

  if (mode->only_opers)
  {
    if (!client_is_oper(client))
    {
      if (!(*errors & SM_ERR_NOTOPER))
        sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);

      *errors |= SM_ERR_NOTOPER;
      return false;
    }
  }

  if (mode->only_servers)
  {
    if (!client_is_server(client) && !client_is_service(client))
    {
      if (!(*errors & SM_ERR_ONLYSERVER))
        sendto_one_numeric(client, &me,
                           rank == CHACCESS_NOTONCHAN ? ERR_NOTONCHANNEL : ERR_ONLYSERVERSCANCHANGE, channel->name);

      *errors |= SM_ERR_ONLYSERVER;
      return false;
    }
  }

  if (rank < mode->required_rank)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one_numeric(client, &me,
                         rank == CHACCESS_NOTONCHAN ? ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED, channel->name);

    *errors |= SM_ERR_NOOPS;
    return false;
  }

  if (channel->mode_lock && strchr(channel->mode_lock, c))
  {
    if (!(*errors & SM_ERR_MLOCK))
      sendto_one_numeric(client, &me, ERR_MLOCKRESTRICTED, channel->name, c, channel->mode_lock);

    *errors |= SM_ERR_MLOCK;
    return false;
  }

  return true;
}

/* Mode functions handle mode changes for a particular mode... */
static void
chm_nosuch(struct Client *client, struct Channel *channel, int parc, int *parn, char *parv[],
           int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (*errors & SM_ERR_UNKNOWN)
    return;

  *errors |= SM_ERR_UNKNOWN;

  if (client_is_local_user(client))
    sendto_one_numeric(client, &me, ERR_UNKNOWNMODE, c);
}

static void
chm_simple(struct Client *client, struct Channel *channel, int parc, int *parn, char *parv[],
           int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (!channel_mode_can_change(client, channel, errors, rank, c, mode))
    return;

  /* If have already dealt with this simple mode, ignore it */
  if (simple_modes_mask & mode->mode)
    return;

  simple_modes_mask |= mode->mode;

  if (dir == MODE_ADD)  /* setting + */
  {
    if (client_is_local_user(client) && channel_has_mode(channel, mode->mode))
      return;

    channel_set_mode(channel, mode->mode);
  }
  else if (dir == MODE_DEL)  /* setting - */
  {
    if (client_is_local_user(client) && !channel_has_mode(channel, mode->mode))
      return;

    channel_unset_mode(channel, mode->mode);
  }

  mode_changes[mode_count].letter = mode->letter;
  mode_changes[mode_count].arg = NULL;
  mode_changes[mode_count].id = NULL;
  mode_changes[mode_count++].dir = dir;

  /*
   * TBR: backwards-compatibility code for servers that don't have channel mode 'z'.
   */
  if (mode->letter == 'S')
  {
    mode_changes[mode_count].letter = 'z';
    mode_changes[mode_count].arg = NULL;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].dir = dir;
  }
  else if (mode->letter == 'z')
  {
    mode_changes[mode_count].letter = 'S';
    mode_changes[mode_count].arg = NULL;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].dir = dir;
  }
}

static void
chm_mask(struct Client *client, struct Channel *channel, int parc, int *parn, char *parv[],
         int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  const char *ret = NULL;
  list_t *list;
  enum irc_numerics rpl_list = 0, rpl_endlist = 0;
  int errtype = 0;

  switch (mode->flag)
  {
    case CHFL_BAN:
      errtype = SM_ERR_RPL_B;
      list = &channel->ban_list;
      rpl_list = RPL_BANLIST;
      rpl_endlist = RPL_ENDOFBANLIST;
      break;
    case CHFL_EXCEPTION:
      errtype = SM_ERR_RPL_E;
      list = &channel->exception_list;
      rpl_list = RPL_EXCEPTLIST;
      rpl_endlist = RPL_ENDOFEXCEPTLIST;
      break;
    case CHFL_INVEX:
      errtype = SM_ERR_RPL_I;
      list = &channel->invite_exception_list;
      rpl_list = RPL_INVEXLIST;
      rpl_endlist = RPL_ENDOFINVEXLIST;
      break;
    default:
      list = NULL;  /* Let it crash */
  }

  if (parc <= *parn)
  {
    if (*errors & errtype)
      return;

    *errors |= errtype;

    list_node_t *node;
    LIST_FOREACH(node, list->head)
    {
      const struct Ban *const ban = node->data;
      sendto_one_numeric(client, &me, rpl_list, channel->name, ban->banstr, ban->who, ban->when);
    }

    sendto_one_numeric(client, &me, rpl_endlist, channel->name);
    return;
  }

  if (!channel_mode_can_change(client, channel, errors, rank, c, mode))
    return;

  if (client_is_local_user(client) && (++mode_limit > MAXMODEPARAMS))
    return;

  char *mask = parv[*parn];
  ++(*parn);

  if (*mask == ':' || (!client_is_local(client) && strchr(mask, ' ')))
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

  static char buf[PARSE_MAX_PARAMETERS][MODEBUFLEN];
  mask = buf[(*parn) - 1];
  strlcpy(mask, ret, sizeof(buf[(*parn) - 1]));

  mode_changes[mode_count].letter = mode->letter;
  mode_changes[mode_count].arg = mask;  /* At this point 'mask' is no longer than MODEBUFLEN */
  mode_changes[mode_count].id = NULL;
  mode_changes[mode_count++].dir = dir;
}

static void
chm_flag(struct Client *client, struct Channel *channel, int parc, int *parn, char *parv[],
         int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (!channel_mode_can_change(client, channel, errors, rank, c, mode))
    return;

  if (parc <= *parn)
    return;

  const char *const target_name = parv[(*parn)++];
  struct Client *const target = client_find_user_with_history(client, target_name, NULL);
  if (target == NULL)
  {
    if (client_is_local_user(client) &&
        !(*errors & SM_ERR_NOSUCHNICK))
      sendto_one_numeric(client, &me, ERR_NOSUCHNICK, target_name);

    *errors |= SM_ERR_NOSUCHNICK;
    return;
  }

  struct ChannelMember *member = channel_member_find(channel, target);
  if (member == NULL)
  {
    if (client_is_local_user(client) &&
        !(*errors & SM_ERR_NOTONCHANNEL))
      sendto_one_numeric(client, &me, ERR_USERNOTINCHANNEL, target->name, channel->name);

    *errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  if (client_is_local_user(client) && (++mode_limit > MAXMODEPARAMS))
    return;

  if (dir == MODE_ADD)  /* setting + */
  {
    if (channel_member_has_flags(member, mode->flag))
      return;  /* No redundant mode changes */

    channel_member_set_flags(member, mode->flag);
  }
  else if (dir == MODE_DEL)  /* setting - */
  {
    if (!channel_member_has_flags(member, mode->flag))
      return;  /* No redundant mode changes */

    channel_member_unset_flags(member, mode->flag);
  }

  mode_changes[mode_count].letter = mode->letter;
  mode_changes[mode_count].arg = target->name;
  mode_changes[mode_count].id = target->id;
  mode_changes[mode_count++].dir = dir;
}

static void
chm_limit(struct Client *client, struct Channel *channel, int parc, int *parn, char *parv[],
          int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (!channel_mode_can_change(client, channel, errors, rank, c, mode))
    return;

  if (dir == MODE_ADD && parc > *parn)
  {
    char *const lstr = parv[(*parn)++];
    int limit = 0;

    if (string_is_empty(lstr) || (limit = atoi(lstr)) <= 0)
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

    channel->mode.member_limit = limit;
  }
  else if (dir == MODE_DEL)
  {
    if (channel->mode.member_limit == 0)
      return;

    channel->mode.member_limit = 0;

    mode_changes[mode_count].letter = mode->letter;
    mode_changes[mode_count].arg = NULL;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].dir = dir;
  }
}

static void
chm_key(struct Client *client, struct Channel *channel, int parc, int *parn, char *parv[],
        int *errors, int rank, int dir, const char c, const struct chan_mode *mode)
{
  if (!channel_mode_can_change(client, channel, errors, rank, c, mode))
    return;

  if (dir == MODE_ADD && parc > *parn)
  {
    char *const key = fix_key(parv[(*parn)++]);

    if (string_is_empty(key))
      return;

    assert(*key != ' ');
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

static void
send_mode_changes_server(struct Client *client, struct Channel *channel)
{
  char modebuf[IRCD_BUFSIZE] = "";
  char parabuf[IRCD_BUFSIZE] = "";  /* Essential that parabuf[0] = '\0' */
  char *parptr = parabuf;
  unsigned int mbl = 0, pbl = 0, arglen = 0, modecount = 0, paracount = 0;
  unsigned int dir = MODE_NONE;

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
    if ((paracount == MAXMODEPARAMS) || ((arglen + mbl + pbl + 2 /* +2 for /r/n */ ) > sizeof(modebuf)))
    {
      if (modecount)
        sendto_servers(client, 0, 0, paracount == 0 ? "%s" : "%s %s", modebuf, parabuf);

      modecount = 0;
      paracount = 0;

      mbl = snprintf(modebuf, sizeof(modebuf), ":%s TMODE %ju %s ",
                     client->id, channel->creation_time, channel->name);

      pbl = 0;
      parabuf[0] = '\0';
      parptr = parabuf;
      dir = MODE_NONE;
    }

    if (dir != mode_changes[i].dir)
    {
      modebuf[mbl++] = mode_changes[i].dir == MODE_ADD ? '+' : '-';
      dir = mode_changes[i].dir;
    }

    modebuf[mbl++] = mode_changes[i].letter;
    modebuf[mbl] = '\0';
    ++modecount;

    if (arg)
    {
      int len = sprintf(parptr, pbl == 0 ? "%s" : " %s", arg);
      pbl += len;
      parptr += len;
      ++paracount;
    }
  }

  if (modecount)
    sendto_servers(client, 0, 0, paracount == 0 ? "%s" : "%s %s", modebuf, parabuf);
}

static void
send_mode_changes_client(struct Client *client, struct Channel *channel)
{
  char modebuf[IRCD_BUFSIZE] = "";
  char parabuf[IRCD_BUFSIZE] = "";  /* Essential that parabuf[0] = '\0' */
  char *parptr = parabuf;
  unsigned int mbl = 0, pbl = 0, arglen = 0, modecount = 0, paracount = 0;
  unsigned int dir = MODE_NONE;

  if (client_is_user(client))
    mbl = snprintf(modebuf, sizeof(modebuf), ":%s!%s@%s MODE %s ",
                   client->name, client->username, client->host, channel->name);
  else
    mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ",
                   client_get_visible_server_name(client), channel->name);

  for (unsigned int i = 0; i < mode_count; ++i)
  {
    if (mode_changes[i].letter == 0)
      continue;

    const char *arg = mode_changes[i].arg;
    if (arg)
      arglen = strlen(arg);
    else
      arglen = 0;

    if ((paracount == MAXMODEPARAMS) || ((arglen + mbl + pbl + 2 /* +2 for /r/n */ ) > sizeof(modebuf)))
    {
      if (modecount)
        sendto_channel_local(NULL, channel, 0, 0, 0, paracount == 0 ? "%s" : "%s %s", modebuf, parabuf);

      modecount = 0;
      paracount = 0;

      if (client_is_user(client))
        mbl = snprintf(modebuf, sizeof(modebuf), ":%s!%s@%s MODE %s ",
                       client->name, client->username, client->host, channel->name);
      else
        mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ",
                       client_get_visible_server_name(client), channel->name);

      pbl = 0;
      parabuf[0] = '\0';
      parptr = parabuf;
      dir = MODE_NONE;
    }

    if (dir != mode_changes[i].dir)
    {
      modebuf[mbl++] = mode_changes[i].dir == MODE_ADD ? '+' : '-';
      dir = mode_changes[i].dir;
    }

    modebuf[mbl++] = mode_changes[i].letter;
    modebuf[mbl] = '\0';
    ++modecount;

    if (arg)
    {
      int len = sprintf(parptr, pbl == 0 ? "%s" : " %s", arg);
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
  { .letter = 'c', .mode = MODE_NOCTRL, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'e', .flag = CHFL_EXCEPTION, .required_rank = CHACCESS_HALFOP, .func = chm_mask, .class = MODE_CLASS_A },
  { .letter = 'i', .mode = MODE_INVITEONLY, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'k', .func = chm_key, .required_rank = CHACCESS_HALFOP, .class = MODE_CLASS_B },
  { .letter = 'l', .func = chm_limit, .required_rank = CHACCESS_HALFOP, .class = MODE_CLASS_C },
  { .letter = 'm', .mode = MODE_MODERATED, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'n', .mode = MODE_NOPRIVMSGS, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'p', .mode = MODE_PRIVATE, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'r', .mode = MODE_REGISTERED, .required_rank = CHACCESS_REMOTE, .only_servers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 's', .mode = MODE_SECRET, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 't', .mode = MODE_TOPICLIMIT, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'z', .mode = MODE_SECUREONLY, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'C', .mode = MODE_NOCTCP, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'I', .flag = CHFL_INVEX, .required_rank = CHACCESS_HALFOP, .func = chm_mask, .class = MODE_CLASS_A },
  { .letter = 'K', .mode = MODE_NOKNOCK, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'L', .mode = MODE_EXTLIMIT, .required_rank = CHACCESS_OP, .only_opers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'M', .mode = MODE_MODREG, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'N', .mode = MODE_NONICKCHANGE, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'O', .mode = MODE_OPERONLY, .required_rank = CHACCESS_OP, .only_opers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'Q', .mode = MODE_NOKICK, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'R', .mode = MODE_REGONLY, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'S', .mode = MODE_SECUREONLY, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'T', .mode = MODE_NONOTICE, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'V', .mode = MODE_NOINVITE, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'Z', .mode = MODE_ISSECURE, .required_rank = CHACCESS_REMOTE, .only_servers = true, .func = chm_simple, .class = MODE_CLASS_D },
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

  isupport_add("CHANMODES", "%s,%s,%s,%s",
               cmode_class[MODE_CLASS_A], cmode_class[MODE_CLASS_B],
               cmode_class[MODE_CLASS_C], cmode_class[MODE_CLASS_D]);

  isupport_add("PREFIX", "(%s)%s", letter, prefix);
  isupport_add("STATUSMSG", "%s", prefix);
  isupport_add("MODES", "%d", MAXMODEPARAMS);
  isupport_add("EXCEPTS", NULL);
  isupport_add("INVEX", NULL);

  capab_add("QOP", CAPAB_QOP, ConfigChannel.enable_owner != 0);
  capab_add("AOP", CAPAB_AOP, ConfigChannel.enable_admin != 0);
  capab_add("HOP", CAPAB_HOP, true);
}

void
channel_mode_set(struct Client *client, struct Channel *channel, int parc, char *parv[])
{
  int dir = MODE_ADD;
  int parn = 1;
  int errors = 0;
  int rank = CHACCESS_REMOTE;  /* Let hacked servers in for now. */

  if (client_is_local_user(client))
    rank = channel_member_get_highest_rank(channel_member_find(channel, client));

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
      default:
      {
        const struct chan_mode *const mode = cmode_map[(unsigned char)*ml];
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

void
channel_mode_clear_member_statuses(struct Channel *channel, const char *source_name)
{
  char modebuf[MAXMODEPARAMS + 1];
  char parabuf[MAXMODEPARAMS * (NICKLEN + 1) + 1];
  char *mbuf = modebuf;
  char *pbuf = parabuf;
  unsigned int pargs = 0;

  list_node_t *node;
  LIST_FOREACH(node, channel->member_list.head)
  {
    struct ChannelMember *const member = node->data;

    for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
    {
      if (channel_member_has_flags(member, tab->flag))
      {
        member->flags &= ~tab->flag;
        *mbuf++ = tab->letter;
        pbuf += snprintf(pbuf, sizeof(parabuf) - (pbuf - parabuf), pbuf != parabuf ? " %s" : "%s",
                         member->client->name);

        if (++pargs >= MAXMODEPARAMS)
        {
          *mbuf = '\0';
          sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s -%s %s",
                               source_name, channel->name, modebuf, parabuf);

          mbuf = modebuf;
          pbuf = parabuf;
          pargs = 0;
        }
      }
    }
  }

  if (pargs)
  {
    *mbuf = '\0';
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s -%s %s",
                         source_name, channel->name, modebuf, parabuf);
  }
}

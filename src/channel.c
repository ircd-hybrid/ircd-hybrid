/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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

/*! \file channel.c
 * \brief Responsible for managing channels, members, bans and topics
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "conf.h"
#include "hostmask.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"             /* captab */
#include "s_user.h"
#include "send.h"
#include "event.h"
#include "memory.h"
#include "mempool.h"

struct config_channel_entry ConfigChannel;
dlink_list global_channel_list = { NULL, NULL, 0 };
mp_pool_t *ban_pool;    /*! \todo ban_pool shouldn't be a global var */

static mp_pool_t *member_pool = NULL;
static mp_pool_t *channel_pool = NULL;

static char buf[IRCD_BUFSIZE];
static char modebuf[MODEBUFLEN];
static char parabuf[MODEBUFLEN];


/*! \brief Initializes the channel blockheap, adds known channel CAPAB
 */
void
init_channels(void)
{
  add_capability("EX", CAP_EX, 1);
  add_capability("IE", CAP_IE, 1);
  add_capability("CHW", CAP_CHW, 1);

  channel_pool = mp_pool_new(sizeof(struct Channel), MP_CHUNK_SIZE_CHANNEL);
  ban_pool = mp_pool_new(sizeof(struct Ban), MP_CHUNK_SIZE_BAN);
  member_pool = mp_pool_new(sizeof(struct Membership), MP_CHUNK_SIZE_MEMBER);
}

/*! \brief adds a user to a channel by adding another link to the
 *         channels member chain.
 * \param chptr      pointer to channel to add client to
 * \param who        pointer to client (who) to add
 * \param flags      flags for chanops etc
 * \param flood_ctrl whether to count this join in flood calculations
 */
void
add_user_to_channel(struct Channel *chptr, struct Client *who,
                    unsigned int flags, int flood_ctrl)
{
  struct Membership *ms = NULL;

  if (GlobalSetOptions.joinfloodtime > 0)
  {
    if (flood_ctrl)
      chptr->number_joined++;

    chptr->number_joined -= (CurrentTime - chptr->last_join_time) *
      (((float)GlobalSetOptions.joinfloodcount) /
       (float)GlobalSetOptions.joinfloodtime);

    if (chptr->number_joined <= 0)
    {
      chptr->number_joined = 0;
      ClearJoinFloodNoticed(chptr);
    }
    else if (chptr->number_joined >= GlobalSetOptions.joinfloodcount)
    {
      chptr->number_joined = GlobalSetOptions.joinfloodcount;

      if (!IsSetJoinFloodNoticed(chptr))
      {
        SetJoinFloodNoticed(chptr);
        sendto_realops_flags(UMODE_BOTS, L_ALL, SEND_NOTICE,
                             "Possible Join Flooder %s on %s target: %s",
                             get_client_name(who, HIDE_IP),
                             who->servptr->name, chptr->chname);
      }
    }

    chptr->last_join_time = CurrentTime;
  }

  ms = mp_pool_get(member_pool);
  memset(ms, 0, sizeof(*ms));

  ms->client_p = who;
  ms->chptr = chptr;
  ms->flags = flags;

  dlinkAdd(ms, &ms->channode, &chptr->members);
  dlinkAdd(ms, &ms->usernode, &who->channel);
}

/*! \brief deletes an user from a channel by removing a link in the
 *         channels member chain.
 * \param member pointer to Membership struct
 */
void
remove_user_from_channel(struct Membership *member)
{
  struct Client *client_p = member->client_p;
  struct Channel *chptr = member->chptr;

  dlinkDelete(&member->channode, &chptr->members);
  dlinkDelete(&member->usernode, &client_p->channel);

  mp_pool_release(member);

  if (chptr->members.head == NULL)
    destroy_channel(chptr);
}

/* send_members()
 *
 * inputs       -
 * output       - NONE
 * side effects -
 */
static void
send_members(struct Client *client_p, struct Channel *chptr,
             char *lmodebuf, char *lparabuf)
{
  struct Membership *ms;
  dlink_node *ptr;
  int tlen;              /* length of text to append */
  char *t, *start;       /* temp char pointer */

  start = t = buf + ircsprintf(buf, ":%s SJOIN %lu %s %s %s:",
                               ID_or_name(&me, client_p),
                               (unsigned long)chptr->channelts,
                               chptr->chname, lmodebuf, lparabuf);

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;

    tlen = strlen(IsCapable(client_p, CAP_TS6) ?
      ID(ms->client_p) : ms->client_p->name) + 1;  /* nick + space */

    if (ms->flags & CHFL_CHANOP)
      tlen++;
#ifdef HALFOPS
    else if (ms->flags & CHFL_HALFOP)
      tlen++;
#endif
    if (ms->flags & CHFL_VOICE)
      tlen++;

    /* space will be converted into CR, but we also need space for LF..
     * That's why we use '- 1' here
     * -adx */
    if (t + tlen - buf > IRCD_BUFSIZE - 1)
    {
      *(t - 1) = '\0';  /* kill the space and terminate the string */
      sendto_one(client_p, "%s", buf);
      t = start;
    }

    if ((ms->flags & (CHFL_CHANOP | CHFL_HALFOP)))
      *t++ = (!(ms->flags & CHFL_CHANOP) && IsCapable(client_p, CAP_HOPS)) ?
        '%' : '@';
    if ((ms->flags & CHFL_VOICE))
      *t++ = '+';

    if (IsCapable(client_p, CAP_TS6))
      strcpy(t, ID(ms->client_p));
    else
      strcpy(t, ms->client_p->name);
    t += strlen(t);
    *t++ = ' ';
  }

  /* should always be non-NULL unless we have a kind of persistent channels */
  if (chptr->members.head != NULL)
    t--;  /* take the space out */
  *t = '\0';
  sendto_one(client_p, "%s", buf);
}

/*! \brief sends +b/+e/+I
 * \param client_p client pointer to server
 * \param chptr    pointer to channel
 * \param top      pointer to top of mode link list to send
 * \param flag     char flag flagging type of mode. Currently this can be 'b', e' or 'I'
 */
static void
send_mode_list(struct Client *client_p, struct Channel *chptr,
               dlink_list *top, char flag)
{
  int ts5 = !IsCapable(client_p, CAP_TS6);
  dlink_node *lp;
  struct Ban *banptr;
  char pbuf[IRCD_BUFSIZE];
  int tlen, mlen, cur_len, count = 0;
  char *mp = NULL, *pp = pbuf;

  if (top == NULL || top->length == 0)
    return;

  if (ts5)
    mlen = ircsprintf(buf, ":%s MODE %s +", me.name, chptr->chname);
  else
    mlen = ircsprintf(buf, ":%s BMASK %lu %s %c :", me.id,
                      (unsigned long)chptr->channelts, chptr->chname, flag);

  /* MODE needs additional one byte for space between buf and pbuf */
  cur_len = mlen + ts5;
  mp = buf + mlen;

  DLINK_FOREACH(lp, top->head)
  {
    banptr = lp->data;

    /* must add another b/e/I letter if we use MODE */
    tlen = banptr->len + 3 + ts5;

    /*
     * send buffer and start over if we cannot fit another ban,
     * or if the target is non-ts6 and we have too many modes in
     * in this line.
     */
    if (cur_len + (tlen - 1) > IRCD_BUFSIZE - 2 ||
        (!IsCapable(client_p, CAP_TS6) &&
         (count >= MAXMODEPARAMS || pp - pbuf >= MODEBUFLEN)))
    {
      *(pp - 1) = '\0';  /* get rid of trailing space on buffer */
      sendto_one(client_p, "%s%s%s", buf, ts5 ? " " : "", pbuf);

      cur_len = mlen + ts5;
      mp = buf + mlen;
      pp = pbuf;
      count = 0;
    }

    count++;
    if (ts5)
    {
      *mp++ = flag;
      *mp = '\0';
    }

    pp += ircsprintf(pp, "%s!%s@%s ", banptr->name, banptr->username,
                     banptr->host);
    cur_len += tlen;
  }

  *(pp - 1) = '\0';  /* get rid of trailing space on buffer */
  sendto_one(client_p, "%s%s%s", buf, ts5 ? " " : "", pbuf);
}

/*! \brief send "client_p" a full list of the modes for channel chptr
 * \param client_p pointer to client client_p
 * \param chptr    pointer to channel pointer
 */
void
send_channel_modes(struct Client *client_p, struct Channel *chptr)
{
  *modebuf = *parabuf = '\0';
  channel_modes(chptr, client_p, modebuf, parabuf);
  send_members(client_p, chptr, modebuf, parabuf);

  send_mode_list(client_p, chptr, &chptr->banlist, 'b');
  send_mode_list(client_p, chptr, &chptr->exceptlist, 'e');
  send_mode_list(client_p, chptr, &chptr->invexlist, 'I');
}

/*! \brief check channel name for invalid characters
 * \param name pointer to channel name string
 * \param local indicates whether it's a local or remote creation
 * \return 0 if invalid, 1 otherwise
 */
int
check_channel_name(const char *name, int local)
{
  const char *p = name;
  const int max_length = local ? LOCAL_CHANNELLEN : CHANNELLEN;
  assert(name != NULL);

  if (!IsChanPrefix(*p))
    return 0;

  if (!local || !ConfigChannel.disable_fake_channels)
  {
    while (*++p)
      if (!IsChanChar(*p))
        return 0;
  }
  else
  {
    while (*++p)
      if (!IsVisibleChanChar(*p))
        return 0;
  }

  return p - name <= max_length;
}

void
remove_ban(struct Ban *bptr, dlink_list *list)
{
  dlinkDelete(&bptr->node, list);

  MyFree(bptr->name);
  MyFree(bptr->username);
  MyFree(bptr->host);
  MyFree(bptr->who);

  mp_pool_release(bptr);
}

/* free_channel_list()
 *
 * inputs       - pointer to dlink_list
 * output       - NONE
 * side effects -
 */
void
free_channel_list(dlink_list *list)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, list->head)
    remove_ban(ptr->data, list);

  assert(list->tail == NULL && list->head == NULL);
}

/*! \brief Get Channel block for chname (and allocate a new channel
 *         block, if it didn't exist before)
 * \param chname channel name
 * \return channel block
 */
struct Channel *
make_channel(const char *chname)
{
  struct Channel *chptr = NULL;

  assert(!EmptyString(chname));

  chptr = mp_pool_get(channel_pool);

  memset(chptr, 0, sizeof(*chptr));

  /* doesn't hurt to set it here */
  chptr->channelts = CurrentTime;
  chptr->last_join_time = CurrentTime;

  strlcpy(chptr->chname, chname, sizeof(chptr->chname));
  dlinkAdd(chptr, &chptr->node, &global_channel_list);

  hash_add_channel(chptr);

  return chptr;
}

/*! \brief walk through this channel, and destroy it.
 * \param chptr channel pointer
 */
void
destroy_channel(struct Channel *chptr)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, chptr->invites.head)
    del_invite(chptr, ptr->data);

  /* free ban/exception/invex lists */
  free_channel_list(&chptr->banlist);
  free_channel_list(&chptr->exceptlist);
  free_channel_list(&chptr->invexlist);

  dlinkDelete(&chptr->node, &global_channel_list);
  hash_del_channel(chptr);

  mp_pool_release(chptr);
}

/*!
 * \param chptr pointer to channel
 * \return string pointer "=" if public, "@" if secret else "*"
 */
static const char *
channel_pub_or_secret(const struct Channel *chptr)
{
  if (SecretChannel(chptr))
    return "@";
  if (PrivateChannel(chptr))
    return "*";
  return "=";
}

/*! \brief lists all names on given channel
 * \param source_p pointer to client struct requesting names
 * \param chptr    pointer to channel block
 * \param show_eon show ENDOFNAMES numeric or not
 *                 (don't want it with /names with no params)
 */
void
channel_member_names(struct Client *source_p, struct Channel *chptr,
                     int show_eon)
{
  struct Client *target_p = NULL;
  struct Membership *ms = NULL;
  dlink_node *ptr = NULL;
  char lbuf[IRCD_BUFSIZE + 1];
  char *t = NULL, *start = NULL;
  int tlen = 0;
  int is_member = IsMember(source_p, chptr);
  int multi_prefix = HasCap(source_p, CAP_MULTI_PREFIX) != 0;

  if (PubChannel(chptr) || is_member)
  {
    t = lbuf + ircsprintf(lbuf, form_str(RPL_NAMREPLY),
                          me.name, source_p->name,
                          channel_pub_or_secret(chptr),
                          chptr->chname);
    start = t;

    DLINK_FOREACH(ptr, chptr->members.head)
    {
      ms       = ptr->data;
      target_p = ms->client_p;

      if (HasUMode(target_p, UMODE_INVISIBLE) && !is_member)
        continue;

      tlen = strlen(target_p->name) + 1;  /* nick + space */

      if (!multi_prefix)
      {
        if (ms->flags & (CHFL_CHANOP | CHFL_HALFOP | CHFL_VOICE))
          ++tlen;
      }
      else
      {
        if (ms->flags & CHFL_CHANOP)
          ++tlen;
        if (ms->flags & CHFL_HALFOP)
          ++tlen;
        if (ms->flags & CHFL_VOICE)
          ++tlen;
      }

      if (t + tlen - lbuf > IRCD_BUFSIZE - 2)
      {
        *(t - 1) = '\0';
        sendto_one(source_p, "%s", lbuf);
        t = start;
      }

      t += ircsprintf(t, "%s%s ", get_member_status(ms, multi_prefix),
                      target_p->name);
    }

    if (tlen != 0)
    {
      *(t - 1) = '\0';
      sendto_one(source_p, "%s", lbuf);
    }
  }

  if (show_eon)
    sendto_one(source_p, form_str(RPL_ENDOFNAMES),
               me.name, source_p->name, chptr->chname);
}

/*! \brief adds client to invite list
 * \param chptr pointer to channel block
 * \param who   pointer to client to add invite to
 */
void
add_invite(struct Channel *chptr, struct Client *who)
{
  del_invite(chptr, who);

  /*
   * delete last link in chain if the list is max length
   */
  if (dlink_list_length(&who->localClient->invited) >=
      ConfigChannel.max_chans_per_user)
    del_invite(who->localClient->invited.tail->data, who);

  /* add client to channel invite list */
  dlinkAdd(who, make_dlink_node(), &chptr->invites);

  /* add channel to the end of the client invite list */
  dlinkAdd(chptr, make_dlink_node(), &who->localClient->invited);
}

/*! \brief Delete Invite block from channel invite list
 *         and client invite list
 * \param chptr pointer to Channel struct
 * \param who   pointer to client to remove invites from
 */
void
del_invite(struct Channel *chptr, struct Client *who)
{
  dlink_node *ptr = NULL;

  if ((ptr = dlinkFindDelete(&who->localClient->invited, chptr)))
    free_dlink_node(ptr);

  if ((ptr = dlinkFindDelete(&chptr->invites, who)))
    free_dlink_node(ptr);
}

/* get_member_status()
 *
 * inputs       - pointer to struct Membership
 *              - YES if we can combine different flags
 * output       - string either @, +, % or "" depending on whether
 *                chanop, voiced or user
 * side effects -
 *
 * NOTE: Returned string is usually a static buffer
 * (like in get_client_name)
 */
const char *
get_member_status(const struct Membership *ms, int combine)
{
  static char buffer[4];
  char *p = NULL;

  if (ms == NULL)
    return "";
  p = buffer;

  if (ms->flags & CHFL_CHANOP)
  {
    if (!combine)
      return "@";
    *p++ = '@';
  }

#ifdef HALFOPS
  if (ms->flags & CHFL_HALFOP)
  {
    if (!combine)
      return "%";
    *p++ = '%';
  }
#endif

  if (ms->flags & CHFL_VOICE)
    *p++ = '+';
  *p = '\0';

  return buffer;
}

/*!
 * \param who  pointer to Client to check
 * \param list pointer to ban list to search
 * \return 1 if ban found for given n!u\@h mask, 0 otherwise
 *
 */
static int
find_bmask(const struct Client *who, const dlink_list *const list)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, list->head)
  {
    const struct Ban *bp = ptr->data;

    if (!match(bp->name, who->name) && !match(bp->username, who->username))
    {
      switch (bp->type)
      {
        case HM_HOST:
          if (!match(bp->host, who->host) || !match(bp->host, who->sockhost))
            return 1;
          break;
        case HM_IPV4:
          if (who->localClient->aftype == AF_INET)
            if (match_ipv4(&who->localClient->ip, &bp->addr, bp->bits))
              return 1;
          break;
#ifdef IPV6
        case HM_IPV6:
          if (who->localClient->aftype == AF_INET6)
            if (match_ipv6(&who->localClient->ip, &bp->addr, bp->bits))
              return 1;
          break;
#endif
        default:
          assert(0);
      }
    }
  }

  return 0;
}

/*!
 * \param chptr pointer to channel block
 * \param who   pointer to client to check access fo
 * \return 0 if not banned, 1 otherwise
 */
int
is_banned(const struct Channel *chptr, const struct Client *who)
{
  if (find_bmask(who, &chptr->banlist))
    if (!find_bmask(who, &chptr->exceptlist))
      return 1;

  return 0;
}

/*!
 * \param source_p pointer to client attempting to join
 * \param chptr    pointer to channel 
 * \param key      key sent by client attempting to join if present
 * \return ERR_BANNEDFROMCHAN, ERR_INVITEONLYCHAN, ERR_CHANNELISFULL
 *         or 0 if allowed to join.
 */
int
can_join(struct Client *source_p, struct Channel *chptr, const char *key)
{
  if (is_banned(chptr, source_p))
    return ERR_BANNEDFROMCHAN;

#ifdef HAVE_LIBCRYPTO
  if ((chptr->mode.mode & MODE_SSLONLY) && !source_p->localClient->fd.ssl)
    return ERR_SSLONLYCHAN;
#endif

  if ((chptr->mode.mode & MODE_REGONLY) && !HasUMode(source_p, UMODE_REGISTERED))
    return ERR_NEEDREGGEDNICK;

  if ((chptr->mode.mode & MODE_OPERONLY) && !HasUMode(source_p, UMODE_OPER))
    return ERR_OPERONLYCHAN;

  if (chptr->mode.mode & MODE_INVITEONLY)
    if (!dlinkFind(&source_p->localClient->invited, chptr))
      if (!find_bmask(source_p, &chptr->invexlist))
        return ERR_INVITEONLYCHAN;

  if (chptr->mode.key[0] && (!key || strcmp(chptr->mode.key, key)))
    return ERR_BADCHANNELKEY;

  if (chptr->mode.limit && dlink_list_length(&chptr->members) >=
      chptr->mode.limit)
    return ERR_CHANNELISFULL;

  return 0;
}

int
has_member_flags(struct Membership *ms, unsigned int flags)
{
  if (ms != NULL)
    return ms->flags & flags;
  return 0;
}

struct Membership *
find_channel_link(struct Client *client_p, struct Channel *chptr)
{
  dlink_node *ptr = NULL;

  if (!IsClient(client_p))
    return NULL;

  DLINK_FOREACH(ptr, client_p->channel.head)
    if (((struct Membership *)ptr->data)->chptr == chptr)
      return ptr->data;

  return NULL;
}

/*!
 * \param chptr    pointer to Channel struct
 * \param source_p pointer to Client struct
 * \param ms       pointer to Membership struct (can be NULL)
 * \return CAN_SEND_OPV if op or voiced on channel\n
 *         CAN_SEND_NONOP if can send to channel but is not an op\n
 *         ERR_CANNOTSENDTOCHAN or ERR_NEEDREGGEDNICK if they cannot send to channel\n
 */
int
can_send(struct Channel *chptr, struct Client *source_p, struct Membership *ms)
{
  if (IsServer(source_p) || HasFlag(source_p, FLAGS_SERVICE))
    return CAN_SEND_OPV;

  if (MyClient(source_p) && !IsExemptResv(source_p))
    if (!(HasUMode(source_p, UMODE_OPER) && ConfigFileEntry.oper_pass_resv))
      if (!hash_find_resv(chptr->chname) == ConfigChannel.restrict_channels)
        return ERR_CANNOTSENDTOCHAN;

  if (ms != NULL || (ms = find_channel_link(source_p, chptr)))
  {
    if (ms->flags & (CHFL_CHANOP|CHFL_HALFOP|CHFL_VOICE))
      return CAN_SEND_OPV;

    /* cache can send if quiet_on_ban and banned */
    if (ConfigChannel.quiet_on_ban && MyClient(source_p))
    {
      if (ms->flags & CHFL_BAN_SILENCED)
        return ERR_CANNOTSENDTOCHAN;

      if (!(ms->flags & CHFL_BAN_CHECKED))
      {
        if (is_banned(chptr, source_p))
        {
          ms->flags |= (CHFL_BAN_CHECKED|CHFL_BAN_SILENCED);
          return ERR_CANNOTSENDTOCHAN;
        }

        ms->flags |= CHFL_BAN_CHECKED;
      }
    }
  }
  else if (chptr->mode.mode & MODE_NOPRIVMSGS)
    return ERR_CANNOTSENDTOCHAN;

  if (chptr->mode.mode & MODE_MODERATED)
    return ERR_CANNOTSENDTOCHAN;

  return CAN_SEND_NONOP;
}

/*! \brief Updates the client's oper_warn_count_down, warns the
 *         IRC operators if necessary, and updates
 *         join_leave_countdown as needed.
 * \param source_p pointer to struct Client to check
 * \param name     channel name or NULL if this is a part.
 */
void
check_spambot_warning(struct Client *source_p, const char *name)
{
  int t_delta = 0;
  int decrement_count = 0;

  if ((GlobalSetOptions.spam_num &&
       (source_p->localClient->join_leave_count >=
        GlobalSetOptions.spam_num)))
  {
    if (source_p->localClient->oper_warn_count_down > 0)
      source_p->localClient->oper_warn_count_down--;
    else
      source_p->localClient->oper_warn_count_down = 0;

    if (source_p->localClient->oper_warn_count_down == 0)
    {
      /* Its already known as a possible spambot */
      if (name != NULL)
        sendto_realops_flags(UMODE_BOTS, L_ALL, SEND_NOTICE,
                             "User %s (%s@%s) trying to join %s is a possible spambot",
                             source_p->name, source_p->username,
                             source_p->host, name);
      else
        sendto_realops_flags(UMODE_BOTS, L_ALL, SEND_NOTICE,
                             "User %s (%s@%s) is a possible spambot",
                             source_p->name, source_p->username,
                             source_p->host);
      source_p->localClient->oper_warn_count_down = OPER_SPAM_COUNTDOWN;
    }
  }
  else
  {
    if ((t_delta = (CurrentTime - source_p->localClient->last_leave_time)) >
         JOIN_LEAVE_COUNT_EXPIRE_TIME)
    {
      decrement_count = (t_delta / JOIN_LEAVE_COUNT_EXPIRE_TIME);
      if (decrement_count > source_p->localClient->join_leave_count)
        source_p->localClient->join_leave_count = 0;
      else
        source_p->localClient->join_leave_count -= decrement_count;
    }
    else
    {
      if ((CurrentTime - (source_p->localClient->last_join_time)) <
          GlobalSetOptions.spam_time)
      {
        /* oh, its a possible spambot */
        source_p->localClient->join_leave_count++;
      }
    }

    if (name != NULL)
      source_p->localClient->last_join_time = CurrentTime;
    else
      source_p->localClient->last_leave_time = CurrentTime;
  }
}

/*! \brief compares usercount and servercount against their split
 *         values and adjusts splitmode accordingly
 * \param unused Unused address pointer
 */
void
check_splitmode(void *unused)
{
  if (splitchecking && (ConfigChannel.no_join_on_split ||
                        ConfigChannel.no_create_on_split))
  {
    const unsigned int server = dlink_list_length(&global_serv_list);

    if (!splitmode && ((server < split_servers) || (Count.total < split_users)))
    {
      splitmode = 1;

      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Network split, activating splitmode");
      eventAddIsh("check_splitmode", check_splitmode, NULL, 10);
    }
    else if (splitmode && (server > split_servers) && (Count.total > split_users))
    {
      splitmode = 0;

      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Network rejoined, deactivating splitmode");
      eventDelete(check_splitmode, NULL);
    }
  }
}

/*! \brief Sets the channel topic for chptr
 * \param chptr      Pointer to struct Channel
 * \param topic      The topic string
 * \param topic_info n!u\@h formatted string of the topic setter
 * \param topicts    timestamp on the topic
 */
void
set_channel_topic(struct Channel *chptr, const char *topic,
                  const char *topic_info, time_t topicts)
{
  strlcpy(chptr->topic, topic, sizeof(chptr->topic));
  strlcpy(chptr->topic_info, topic_info, sizeof(chptr->topic_info));
  chptr->topic_time = topicts; 
}

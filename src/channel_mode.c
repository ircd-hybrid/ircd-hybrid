/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
#include "s_serv.h"
#include "send.h"
#include "memory.h"
#include "mempool.h"
#include "parse.h"

/* 10 is a magic number in hybrid 6 NFI where it comes from -db */
#define BAN_FUDGE       10
#define NCHCAPS         (sizeof(channel_capabs)/sizeof(int))
#define NCHCAP_COMBOS   (1 << NCHCAPS)


static char nuh_mask[MAXPARA][IRCD_BUFSIZE];
/* some buffers for rebuilding channel/nick lists with ,'s */
static char modebuf[IRCD_BUFSIZE];
static char parabuf[MODEBUFLEN];
static struct ChModeChange mode_changes[IRCD_BUFSIZE];
static int mode_count;
static int mode_limit;  /* number of modes set other than simple */
static int simple_modes_mask;  /* bit mask of simple modes already set */
#ifdef HALFOPS
static int channel_capabs[] = { CAP_EX, CAP_IE, CAP_TS6, CAP_HOPS };
#else
static int channel_capabs[] = { CAP_EX, CAP_IE, CAP_TS6 };
#endif
static struct ChCapCombo chcap_combos[NCHCAP_COMBOS];
extern mp_pool_t *ban_pool;


/* check_string()
 *
 * inputs       - string to check
 * output       - pointer to modified string
 * side effects - Fixes a string so that the first white space found
 *                becomes an end of string marker (`\0`).
 *                returns the 'fixed' string or "*" if the string
 *                was NULL length or a NULL pointer.
 */
static char *
check_string(char *s)
{
  char *str = s;
  static char star[] = "*";

  if (EmptyString(str))
    return star;

  for (; *s; ++s)
  {
    if (IsSpace(*s))
    {
      *s = '\0';
      break;
    }
  }

  return EmptyString(str) ? star : str;
}

/*
 * Ban functions to work with mode +b/e/d/I
 */
/* add the specified ID to the channel.
 *   -is 8/9/00
 */

int
add_id(struct Client *client_p, struct Channel *chptr, char *banid, int type)
{
  dlink_list *list = NULL;
  dlink_node *ban = NULL;
  size_t len = 0;
  struct Ban *ban_p = NULL;
  unsigned int num_mask;
  char name[NICKLEN + 1];
  char user[USERLEN + 1];
  char host[HOSTLEN + 1];
  struct split_nuh_item nuh;

  /* dont let local clients overflow the b/e/I lists */
  if (MyClient(client_p))
  {
    num_mask = dlink_list_length(&chptr->banlist) +
               dlink_list_length(&chptr->exceptlist) +
               dlink_list_length(&chptr->invexlist);

    if (num_mask >= ConfigChannel.max_bans)
    {
      sendto_one(client_p, form_str(ERR_BANLISTFULL),
                 me.name, client_p->name, chptr->chname, banid);
      return 0;
    }

    collapse(banid);
  }

  nuh.nuhmask  = check_string(banid);
  nuh.nickptr  = name;
  nuh.userptr  = user;
  nuh.hostptr  = host;

  nuh.nicksize = sizeof(name);
  nuh.usersize = sizeof(user);
  nuh.hostsize = sizeof(host);

  split_nuh(&nuh);

  /*
   * Re-assemble a new n!u@h and print it back to banid for sending
   * the mode to the channel.
   */
  len = sprintf(banid, "%s!%s@%s", name, user, host);

  switch (type)
  {
    case CHFL_BAN:
      list = &chptr->banlist;
      clear_ban_cache(chptr);
      break;
    case CHFL_EXCEPTION:
      list = &chptr->exceptlist;
      clear_ban_cache(chptr);
      break;
    case CHFL_INVEX:
      list = &chptr->invexlist;
      break;
    default:
      assert(0);
      return 0;
  }

  DLINK_FOREACH(ban, list->head)
  {
    ban_p = ban->data;

    if (!irccmp(ban_p->name, name) &&
        !irccmp(ban_p->user, user) &&
        !irccmp(ban_p->host, host))
      return 0;
  }

  ban_p = mp_pool_get(ban_pool);
  memset(ban_p, 0, sizeof(*ban_p));
  ban_p->name = xstrdup(name);
  ban_p->user = xstrdup(user);
  ban_p->host = xstrdup(host);
  ban_p->when = CurrentTime;
  ban_p->len = len - 2;  /* -2 for @ and ! */
  ban_p->type = parse_netmask(host, &ban_p->addr, &ban_p->bits);

  if (IsClient(client_p))
  {
    ban_p->who = MyMalloc(strlen(client_p->name) +
                          strlen(client_p->username) +
                          strlen(client_p->host) + 3);
    sprintf(ban_p->who, "%s!%s@%s", client_p->name,
            client_p->username, client_p->host);
  }
  else if (IsHidden(client_p) || (IsServer(client_p) && ConfigServerHide.hide_servers))
    ban_p->who = xstrdup(me.name);
  else
    ban_p->who = xstrdup(client_p->name);

  dlinkAdd(ban_p, &ban_p->node, list);

  return 1;
}

/*
 * inputs	- pointer to channel
 *		- pointer to ban id
 *		- type of ban, i.e. ban, exception, invex
 * output	- 0 for failure, 1 for success
 * side effects	-
 */
static int
del_id(struct Channel *chptr, char *banid, int type)
{
  dlink_list *list;
  dlink_node *ban;
  struct Ban *banptr;
  char name[NICKLEN + 1];
  char user[USERLEN + 1];
  char host[HOSTLEN + 1];
  struct split_nuh_item nuh;

  assert(banid);

  nuh.nuhmask  = check_string(banid);
  nuh.nickptr  = name;
  nuh.userptr  = user;
  nuh.hostptr  = host;

  nuh.nicksize = sizeof(name);
  nuh.usersize = sizeof(user);
  nuh.hostsize = sizeof(host);

  split_nuh(&nuh);

  /*
   * Re-assemble a new n!u@h and print it back to banid for sending
   * the mode to the channel.
   */
  sprintf(banid, "%s!%s@%s", name, user, host);

  switch (type)
  {
    case CHFL_BAN:
      list = &chptr->banlist;
      clear_ban_cache(chptr);
      break;
    case CHFL_EXCEPTION:
      list = &chptr->exceptlist;
      clear_ban_cache(chptr);
      break;
    case CHFL_INVEX:
      list = &chptr->invexlist;
      break;
    default:
      assert(0);
      return 0;
  }

  DLINK_FOREACH(ban, list->head)
  {
    banptr = ban->data;

    if (!irccmp(name, banptr->name) &&
        !irccmp(user, banptr->user) &&
        !irccmp(host, banptr->host))
    {
      remove_ban(banptr, list);
      return 1;
    }
  }

  return 0;
}

const struct mode_letter chan_modes[] =
{
  { MODE_NOCTRL,     'c' },
  { MODE_INVITEONLY, 'i' },
  { MODE_MODERATED,  'm' },
  { MODE_NOPRIVMSGS, 'n' },
  { MODE_PRIVATE,    'p' },
  { MODE_REGISTERED, 'r' },
  { MODE_SECRET,     's' },
  { MODE_TOPICLIMIT, 't' },
  { MODE_MODREG,     'M' },
  { MODE_OPERONLY,   'O' },
  { MODE_REGONLY,    'R' },
  { MODE_SSLONLY,    'S' },
  { 0, '\0' }
};

/* channel_modes()
 *
 * inputs       - pointer to channel
 *              - pointer to client
 *              - pointer to mode buf
 *              - pointer to parameter buf
 * output       - NONE
 * side effects - write the "simple" list of channel modes for channel
 * chptr onto buffer mbuf with the parameters in pbuf.
 */
void
channel_modes(struct Channel *chptr, struct Client *client_p,
              char *mbuf, char *pbuf)
{
  const struct mode_letter *tab = chan_modes;

  *mbuf++ = '+';
  *pbuf = '\0';

  for (; tab->mode; ++tab)
    if (chptr->mode.mode & tab->mode)
      *mbuf++ = tab->letter;

  if (chptr->mode.limit)
  {
    *mbuf++ = 'l';

    if (IsServer(client_p) || HasFlag(client_p, FLAGS_SERVICE) || IsMember(client_p, chptr))
      pbuf += sprintf(pbuf, "%d ", chptr->mode.limit);
  }

  if (chptr->mode.key[0])
  {
    *mbuf++ = 'k';

    if (IsServer(client_p) || HasFlag(client_p, FLAGS_SERVICE) || IsMember(client_p, chptr))
      sprintf(pbuf, "%s ", chptr->mode.key);
  }

  *mbuf = '\0';
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
  unsigned char *s, *t, c;

  for (s = t = (unsigned char *)arg; (c = *s); s++)
  {
    c &= 0x7f;

    if (c != ':' && c > ' ' && c != ',')
      *t++ = c;
  }

  *t = '\0';
  return arg;
}

/* fix_key_old()
 *
 * inputs       - pointer to key to clean up
 * output       - pointer to cleaned up key
 * side effects - input string is modifed
 *
 * Here we attempt to be compatible with older non-hybrid servers.
 * We can't back down from the ':' issue however.  --Rodder
 */
static char *
fix_key_old(char *arg)
{
  unsigned char *s, *t, c;

  for (s = t = (unsigned char *)arg; (c = *s); s++)
  {
    c &= 0x7f;

    if ((c != 0x0a) && (c != ':') &&
        (c != 0x0d) && (c != ','))
      *t++ = c;
  }

  *t = '\0';
  return arg;
}

/* bitmasks for various error returns that set_channel_mode should only return
 * once per call  -orabidoo
 */

#define SM_ERR_NOTS         0x00000001 /* No TS on channel  */
#define SM_ERR_NOOPS        0x00000002 /* No chan ops       */
#define SM_ERR_UNKNOWN      0x00000004
#define SM_ERR_RPL_B        0x00000008
#define SM_ERR_RPL_E        0x00000010
#define SM_ERR_NOTONCHANNEL 0x00000020 /* Not on channel    */
#define SM_ERR_RPL_I        0x00000040
#define SM_ERR_NOTOPER      0x00000080
#define SM_ERR_ONLYSERVER   0x00000100

/* Now lets do some stuff to keep track of what combinations of
 * servers exist...
 * Note that the number of combinations doubles each time you add
 * something to this list. Each one is only quick if no servers use that
 * combination, but if the numbers get too high here MODE will get too
 * slow. I suggest if you get more than 7 here, you consider getting rid
 * of some and merging or something. If it wasn't for irc+cs we would
 * probably not even need to bother about most of these, but unfortunately
 * we do. -A1kmm
 */

/* void init_chcap_usage_counts(void)
 *
 * Inputs	- none
 * Output	- none
 * Side-effects	- Initialises the usage counts to zero. Fills in the
 *                chcap_yes and chcap_no combination tables.
 */
void
init_chcap_usage_counts(void)
{
  unsigned long m, c, y, n;

  memset(chcap_combos, 0, sizeof(chcap_combos));

  /* For every possible combination */
  for (m = 0; m < NCHCAP_COMBOS; m++)
  {
    /* Check each capab */
    for (c = y = n = 0; c < NCHCAPS; c++)
    {
      if ((m & (1 << c)) == 0)
        n |= channel_capabs[c];
      else
        y |= channel_capabs[c];
    }

    chcap_combos[m].cap_yes = y;
    chcap_combos[m].cap_no  = n;
  }
}

/* void set_chcap_usage_counts(struct Client *serv_p)
 * Input: serv_p; The client whose capabs to register.
 * Output: none
 * Side-effects: Increments the usage counts for the correct capab
 *               combination.
 */
void
set_chcap_usage_counts(struct Client *serv_p)
{
  int n;

  for (n = 0; n < NCHCAP_COMBOS; n++)
  {
    if (((serv_p->localClient->caps & chcap_combos[n].cap_yes) ==
         chcap_combos[n].cap_yes) &&
        ((serv_p->localClient->caps & chcap_combos[n].cap_no) == 0))
    {
      chcap_combos[n].count++;
      return;
    }
  }

  /* This should be impossible -A1kmm. */
  assert(0);
}

/* void set_chcap_usage_counts(struct Client *serv_p)
 *
 * Inputs	- serv_p; The client whose capabs to register.
 * Output	- none
 * Side-effects	- Decrements the usage counts for the correct capab
 *                combination.
 */
void
unset_chcap_usage_counts(struct Client *serv_p)
{
  int n;

  for (n = 0; n < NCHCAP_COMBOS; n++)
  {
    if ((serv_p->localClient->caps & chcap_combos[n].cap_yes) ==
        chcap_combos[n].cap_yes &&
        (serv_p->localClient->caps & chcap_combos[n].cap_no) == 0)
    {
      /* Hopefully capabs can't change dynamically or anything... */
      assert(chcap_combos[n].count > 0);
      chcap_combos[n].count--;
      return;
    }
  }

  /* This should be impossible -A1kmm. */
  assert(0);
}

/* Mode functions handle mode changes for a particular mode... */
static void
chm_nosuch(struct Client *client_p, struct Client *source_p,
           struct Channel *chptr, int parc, int *parn,
           char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  if (*errors & SM_ERR_UNKNOWN)
    return;

  *errors |= SM_ERR_UNKNOWN;
  sendto_one(source_p, form_str(ERR_UNKNOWNMODE), me.name,
             source_p->name, c);
}

static void
chm_simple(struct Client *client_p, struct Client *source_p, struct Channel *chptr,
           int parc, int *parn, char **parv, int *errors, int alev, int dir,
           char c, unsigned int d)
{
  if ((alev < CHACCESS_HALFOP) ||
      ((d == MODE_PRIVATE) && (alev < CHACCESS_CHANOP)))
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  /* If have already dealt with this simple mode, ignore it */
  if (simple_modes_mask & d)
    return;

  simple_modes_mask |= d;

  /* setting + */
  /* Apparently, (though no one has ever told the hybrid group directly)
   * admins don't like redundant mode checking. ok. It would have been nice
   * if you had have told us directly. I've left the original code snippets
   * in place.
   *
   * -Dianora
   */
  if (dir == MODE_ADD) /* && !(chptr->mode.mode & d)) */
  {
    chptr->mode.mode |= d;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count++].arg = NULL;
  }
  else if (dir == MODE_DEL) /* && (chptr->mode.mode & d)) */
  {
    /* setting - */

    chptr->mode.mode &= ~d;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = NULL;
  }
}

static void
chm_registered(struct Client *client_p, struct Client *source_p, struct Channel *chptr,
           int parc, int *parn, char **parv, int *errors, int alev, int dir,
           char c, unsigned int d)
{
  if (!IsServer(source_p) && !HasFlag(source_p, FLAGS_SERVICE))
  {
    if (!(*errors & SM_ERR_ONLYSERVER))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_ONLYSERVERSCANCHANGE),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_ONLYSERVER;
    return;
  }

  /* If have already dealt with this simple mode, ignore it */
  if (simple_modes_mask & d)
    return;

  simple_modes_mask |= d;

  /* setting + */
  /* Apparently, (though no one has ever told the hybrid group directly)
   * admins don't like redundant mode checking. ok. It would have been nice
   * if you had have told us directly. I've left the original code snippets
   * in place.
   *
   * -Dianora
   */
  if (dir == MODE_ADD) /* && !(chptr->mode.mode & d)) */
  {
    chptr->mode.mode |= d;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count++].arg = NULL;
  }
  else if (dir == MODE_DEL) /* && (chptr->mode.mode & d)) */
  {
    /* setting - */

    chptr->mode.mode &= ~d;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = NULL;
  }
}

static void
chm_operonly(struct Client *client_p, struct Client *source_p, struct Channel *chptr,
            int parc, int *parn, char **parv, int *errors, int alev, int dir,
            char c, unsigned int d)
{
  if ((alev < CHACCESS_HALFOP) ||
      ((d == MODE_PRIVATE) && (alev < CHACCESS_CHANOP)))
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }
  else if (MyClient(source_p) && !HasUMode(source_p, UMODE_OPER))
  {
    if (!(*errors & SM_ERR_NOTOPER))
    {
      if (alev == CHACCESS_NOTONCHAN)
        sendto_one(source_p, form_str(ERR_NOTONCHANNEL),
                   me.name, source_p->name, chptr->chname);
      else
        sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
                   me.name, source_p->name);
    }

    *errors |= SM_ERR_NOTOPER;
    return;
  }

  /* If have already dealt with this simple mode, ignore it */
  if (simple_modes_mask & d)
    return;

  simple_modes_mask |= d;

  if (dir == MODE_ADD) /* && !(chptr->mode.mode & d)) */
  {
    chptr->mode.mode |= d;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count++].arg = NULL;
  }
  else if (dir == MODE_DEL) /* && (chptr->mode.mode & d)) */
  {
    /* setting - */

    chptr->mode.mode &= ~d;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = NULL;
  }
}

static void
chm_ban(struct Client *client_p, struct Client *source_p,
        struct Channel *chptr, int parc, int *parn,
        char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  char *mask = NULL;

  if (dir == MODE_QUERY || parc <= *parn)
  {
    dlink_node *ptr = NULL;

    if (*errors & SM_ERR_RPL_B)
      return;

    *errors |= SM_ERR_RPL_B;

    DLINK_FOREACH(ptr, chptr->banlist.head)
    {
      const struct Ban *banptr = ptr->data;
      sendto_one(client_p, form_str(RPL_BANLIST),
                 me.name, client_p->name, chptr->chname,
                 banptr->name, banptr->user, banptr->host,
                 banptr->who, banptr->when);
    }

    sendto_one(source_p, form_str(RPL_ENDOFBANLIST), me.name,
               source_p->name, chptr->chname);
    return;
  }

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  mask = nuh_mask[*parn];
  memcpy(mask, parv[*parn], sizeof(nuh_mask[*parn]));
  ++*parn;

  if (IsServer(client_p))
    if (strchr(mask, ' '))
      return;

  switch (dir)
  {
    case MODE_ADD:
      if (!add_id(source_p, chptr, mask, CHFL_BAN))
        return;
      break;
    case MODE_DEL:
      if (!del_id(chptr, mask, CHFL_BAN))
        return;
      break;
    default:
      assert(0);
  }

  mode_changes[mode_count].letter = c;
  mode_changes[mode_count].dir = dir;
  mode_changes[mode_count].caps = 0;
  mode_changes[mode_count].nocaps = 0;
  mode_changes[mode_count].mems = ALL_MEMBERS;
  mode_changes[mode_count].id = NULL;
  mode_changes[mode_count++].arg = mask;
}

static void
chm_except(struct Client *client_p, struct Client *source_p,
           struct Channel *chptr, int parc, int *parn,
           char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  char *mask = NULL;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (dir == MODE_QUERY || parc <= *parn)
  {
    dlink_node *ptr = NULL;

    if (*errors & SM_ERR_RPL_E)
      return;

    *errors |= SM_ERR_RPL_E;

    DLINK_FOREACH(ptr, chptr->exceptlist.head)
    {
      const struct Ban *banptr = ptr->data;
      sendto_one(client_p, form_str(RPL_EXCEPTLIST),
                 me.name, client_p->name, chptr->chname,
                 banptr->name, banptr->user, banptr->host,
                 banptr->who, banptr->when);
    }

    sendto_one(source_p, form_str(RPL_ENDOFEXCEPTLIST), me.name,
               source_p->name, chptr->chname);
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  mask = nuh_mask[*parn];
  memcpy(mask, parv[*parn], sizeof(nuh_mask[*parn]));
  ++*parn;

  if (IsServer(client_p))
    if (strchr(mask, ' '))
      return;

  switch (dir)
  {
    case MODE_ADD:
      if (!add_id(source_p, chptr, mask, CHFL_EXCEPTION))
        return;
      break;
    case MODE_DEL:
      if (!del_id(chptr, mask, CHFL_EXCEPTION))
        return;
      break;
    default:
      assert(0);
  }

  mode_changes[mode_count].letter = c;
  mode_changes[mode_count].dir = dir;
  mode_changes[mode_count].caps = 0;
  mode_changes[mode_count].nocaps = 0;
  mode_changes[mode_count].mems = ONLY_CHANOPS;
  mode_changes[mode_count].id = NULL;
  mode_changes[mode_count++].arg = mask;
}

static void
chm_invex(struct Client *client_p, struct Client *source_p,
          struct Channel *chptr, int parc, int *parn,
          char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  char *mask = NULL;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (dir == MODE_QUERY || parc <= *parn)
  {
    dlink_node *ptr = NULL;

    if (*errors & SM_ERR_RPL_I)
      return;

    *errors |= SM_ERR_RPL_I;

    DLINK_FOREACH(ptr, chptr->invexlist.head)
    {
      const struct Ban *banptr = ptr->data;
      sendto_one(client_p, form_str(RPL_INVITELIST), me.name,
                 client_p->name, chptr->chname,
                 banptr->name, banptr->user, banptr->host,
                 banptr->who, banptr->when);
    }

    sendto_one(source_p, form_str(RPL_ENDOFINVITELIST), me.name,
               source_p->name, chptr->chname);
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  mask = nuh_mask[*parn];
  memcpy(mask, parv[*parn], sizeof(nuh_mask[*parn]));
  ++*parn;

  if (IsServer(client_p))
    if (strchr(mask, ' '))
      return;

  switch (dir)
  {
    case MODE_ADD:
      if (!add_id(source_p, chptr, mask, CHFL_INVEX))
        return;
      break;
    case MODE_DEL:
      if (!del_id(chptr, mask, CHFL_INVEX))
        return;
      break;
    default:
      assert(0);
  }

  mode_changes[mode_count].letter = c;
  mode_changes[mode_count].dir = dir;
  mode_changes[mode_count].caps = 0;
  mode_changes[mode_count].nocaps = 0;
  mode_changes[mode_count].mems = ONLY_CHANOPS;
  mode_changes[mode_count].id = NULL;
  mode_changes[mode_count++].arg = mask;
}

/*
 * inputs	- pointer to channel
 * output	- none
 * side effects	- clear ban cache
 */
void
clear_ban_cache(struct Channel *chptr)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    struct Membership *ms = ptr->data;

    if (MyConnect(ms->client_p))
      ms->flags &= ~(CHFL_BAN_SILENCED|CHFL_BAN_CHECKED);
  }
}

void
clear_ban_cache_client(struct Client *client_p)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, client_p->channel.head)
  {
    struct Membership *ms = ptr->data;
    ms->flags &= ~(CHFL_BAN_SILENCED|CHFL_BAN_CHECKED);
  }
}

static void
chm_voice(struct Client *client_p, struct Client *source_p,
          struct Channel *chptr, int parc, int *parn,
          char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  const char *opnick = NULL;
  struct Client *targ_p;
  struct Membership *member;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if ((dir == MODE_QUERY) || parc <= *parn)
    return;

  opnick = parv[(*parn)++];

  if ((targ_p = find_chasing(source_p, opnick, NULL)) == NULL)
    return;
  if (!IsClient(targ_p))
    return;

  if ((member = find_channel_link(targ_p, chptr)) == NULL)
  {
    if (!(*errors & SM_ERR_NOTONCHANNEL))
      sendto_one(source_p, form_str(ERR_USERNOTINCHANNEL),
                 me.name, source_p->name, opnick, chptr->chname);
    *errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  /* no redundant mode changes */
  if (dir == MODE_ADD &&  has_member_flags(member, CHFL_VOICE))
    return;
  if (dir == MODE_DEL && !has_member_flags(member, CHFL_VOICE))
    return;

  mode_changes[mode_count].letter = 'v';
  mode_changes[mode_count].dir = dir;
  mode_changes[mode_count].caps = 0;
  mode_changes[mode_count].nocaps = 0;
  mode_changes[mode_count].mems = ALL_MEMBERS;
  mode_changes[mode_count].id = targ_p->id;
  mode_changes[mode_count].arg = targ_p->name;
  mode_changes[mode_count++].client = targ_p;

  if (dir == MODE_ADD)
    AddMemberFlag(member, CHFL_VOICE);
  else
    DelMemberFlag(member, CHFL_VOICE);
}

#ifdef HALFOPS
static void
chm_hop(struct Client *client_p, struct Client *source_p,
       struct Channel *chptr, int parc, int *parn,
       char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  const char *opnick = NULL;
  struct Client *targ_p;
  struct Membership *member;

  /* *sigh* - dont allow halfops to set +/-h, they could fully control a
   * channel if there were no ops - it doesnt solve anything.. MODE_PRIVATE
   * when used with MODE_SECRET is paranoid - cant use +p
   *
   * it needs to be optional per channel - but not via +p, that or remove
   * paranoid.. -- fl_
   *
   * +p means paranoid, it is useless for anything else on modern IRC, as
   * list isn't really usable. If you want to have a private channel these
   * days, you set it +s. Halfops can no longer remove simple modes when
   * +p is set (although they can set +p) so it is safe to use this to
   * control whether they can (de)halfop...
   */
  if (alev <
      ((chptr->mode.mode & MODE_PRIVATE) ? CHACCESS_CHANOP : CHACCESS_HALFOP))
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if ((dir == MODE_QUERY) || (parc <= *parn))
    return;

  opnick = parv[(*parn)++];

  if ((targ_p = find_chasing(source_p, opnick, NULL)) == NULL)
    return;
  if (!IsClient(targ_p))
    return;

  if ((member = find_channel_link(targ_p, chptr)) == NULL)
  {
    if (!(*errors & SM_ERR_NOTONCHANNEL))
      sendto_one(source_p, form_str(ERR_USERNOTINCHANNEL),
                 me.name, source_p->name, opnick, chptr->chname);
    *errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  /* no redundant mode changes */
  if (dir == MODE_ADD &&  has_member_flags(member, CHFL_HALFOP | CHFL_CHANOP))
    return;
  if (dir == MODE_DEL && !has_member_flags(member, CHFL_HALFOP))
    return;

  mode_changes[mode_count].letter = 'h';
  mode_changes[mode_count].dir = dir;
  mode_changes[mode_count].caps = CAP_HOPS;
  mode_changes[mode_count].nocaps = 0;
  mode_changes[mode_count].mems = ALL_MEMBERS;
  mode_changes[mode_count].id = targ_p->id;
  mode_changes[mode_count].arg = targ_p->name;
  mode_changes[mode_count++].client = targ_p;

  mode_changes[mode_count].letter = 'o';
  mode_changes[mode_count].dir = dir;
  mode_changes[mode_count].caps = 0;
  mode_changes[mode_count].nocaps = CAP_HOPS;
  mode_changes[mode_count].mems = ONLY_SERVERS;
  mode_changes[mode_count].id = targ_p->id;
  mode_changes[mode_count].arg = targ_p->name;
  mode_changes[mode_count++].client = targ_p;

  if (dir == MODE_ADD)
  {
    AddMemberFlag(member, CHFL_HALFOP);
    DelMemberFlag(member, CHFL_DEOPPED);
  }
  else
    DelMemberFlag(member, CHFL_HALFOP);
}
#endif

static void
chm_op(struct Client *client_p, struct Client *source_p,
       struct Channel *chptr, int parc, int *parn,
       char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  const char *opnick = NULL;
  struct Client *targ_p;
  struct Membership *member;
  int caps = 0;

  if (alev < CHACCESS_CHANOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if ((dir == MODE_QUERY) || (parc <= *parn))
    return;

  opnick = parv[(*parn)++];

  if ((targ_p = find_chasing(source_p, opnick, NULL)) == NULL)
    return;
  if (!IsClient(targ_p))
    return;

  if ((member = find_channel_link(targ_p, chptr)) == NULL)
  {
    if (!(*errors & SM_ERR_NOTONCHANNEL))
      sendto_one(source_p, form_str(ERR_USERNOTINCHANNEL), me.name,
                 source_p->name, opnick, chptr->chname);
    *errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  /* no redundant mode changes */
  if (dir == MODE_ADD &&  has_member_flags(member, CHFL_CHANOP))
    return;
  if (dir == MODE_DEL && !has_member_flags(member, CHFL_CHANOP))
  {
#ifdef HALFOPS
    if (has_member_flags(member, CHFL_HALFOP))
    {
      --*parn;
      chm_hop(client_p, source_p, chptr, parc, parn, parv, errors, alev,
              dir, c, d);
    }
#endif
    return;
  }

#ifdef HALFOPS
  if (dir == MODE_ADD && has_member_flags(member, CHFL_HALFOP))
  {
    /* promoting from % to @ is visible only to CAP_HOPS servers */
    mode_changes[mode_count].letter = 'h';
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = caps = CAP_HOPS;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count].arg = targ_p->name;
    mode_changes[mode_count++].client = targ_p;
  }
#endif

  mode_changes[mode_count].letter = 'o';
  mode_changes[mode_count].dir = dir;
  mode_changes[mode_count].caps = caps;
  mode_changes[mode_count].nocaps = 0;
  mode_changes[mode_count].mems = ALL_MEMBERS;
  mode_changes[mode_count].id = targ_p->id;
  mode_changes[mode_count].arg = targ_p->name;
  mode_changes[mode_count++].client = targ_p;

  if (dir == MODE_ADD)
  {
    AddMemberFlag(member, CHFL_CHANOP);
    DelMemberFlag(member, CHFL_DEOPPED | CHFL_HALFOP);
  }
  else
    DelMemberFlag(member, CHFL_CHANOP);
}

static void
chm_limit(struct Client *client_p, struct Client *source_p,
          struct Channel *chptr, int parc, int *parn,
          char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  int i, limit;
  char *lstr;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (dir == MODE_QUERY)
    return;

  if ((dir == MODE_ADD) && parc > *parn)
  {
    lstr = parv[(*parn)++];

    if ((limit = atoi(lstr)) <= 0)
      return;

    sprintf(lstr, "%d", limit);

    /* if somebody sets MODE #channel +ll 1 2, accept latter --fl */
    for (i = 0; i < mode_count; i++)
      if (mode_changes[i].letter == c && mode_changes[i].dir == MODE_ADD)
        mode_changes[i].letter = 0;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = lstr;

    chptr->mode.limit = limit;
  }
  else if (dir == MODE_DEL)
  {
    if (!chptr->mode.limit)
      return;

    chptr->mode.limit = 0;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = NULL;
  }
}

static void
chm_key(struct Client *client_p, struct Client *source_p,
        struct Channel *chptr, int parc, int *parn,
        char **parv, int *errors, int alev, int dir, char c, unsigned int d)
{
  int i;
  char *key;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (dir == MODE_QUERY)
    return;

  if ((dir == MODE_ADD) && parc > *parn)
  {
    key = parv[(*parn)++];

    if (MyClient(source_p))
      fix_key(key);
    else
      fix_key_old(key);

    if (*key == '\0')
      return;

    assert(key[0] != ' ');
    strlcpy(chptr->mode.key, key, sizeof(chptr->mode.key));

    /* if somebody does MODE #channel +kk a b, accept latter --fl */
    for (i = 0; i < mode_count; i++)
      if (mode_changes[i].letter == c && mode_changes[i].dir == MODE_ADD)
        mode_changes[i].letter = 0;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = chptr->mode.key;
  }
  else if (dir == MODE_DEL)
  {
    if (parc > *parn)
      (*parn)++;

    if (chptr->mode.key[0] == '\0')
      return;

    chptr->mode.key[0] = '\0';

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = "*";
  }
}

struct ChannelMode
{
  void (*func)(struct Client *, struct Client *,
               struct Channel *, int, int *, char **,
               int *, int, int, char, unsigned int);
  unsigned int d;
};

static struct ChannelMode ModeTable[256] =
{
  { chm_nosuch,  0 },			/* 0x00 */
  { chm_nosuch,  0 },			/* 0x01 */
  { chm_nosuch,  0 },			/* 0x02 */
  { chm_nosuch,  0 },			/* 0x03 */
  { chm_nosuch,  0 },			/* 0x04 */
  { chm_nosuch,  0 },			/* 0x05 */
  { chm_nosuch,  0 },			/* 0x06 */
  { chm_nosuch,  0 },			/* 0x07 */
  { chm_nosuch,  0 },			/* 0x08 */
  { chm_nosuch,  0 },			/* 0x09 */
  { chm_nosuch,  0 },			/* 0x0a */
  { chm_nosuch,  0 },			/* 0x0b */
  { chm_nosuch,  0 },			/* 0x0c */
  { chm_nosuch,  0 },			/* 0x0d */
  { chm_nosuch,  0 },			/* 0x0e */
  { chm_nosuch,  0 },			/* 0x0f */
  { chm_nosuch,  0 },			/* 0x10 */
  { chm_nosuch,  0 },			/* 0x11 */
  { chm_nosuch,  0 },			/* 0x12 */
  { chm_nosuch,  0 },			/* 0x13 */
  { chm_nosuch,  0 },			/* 0x14 */
  { chm_nosuch,  0 },			/* 0x15 */
  { chm_nosuch,  0 },			/* 0x16 */
  { chm_nosuch,  0 },			/* 0x17 */
  { chm_nosuch,  0 },			/* 0x18 */
  { chm_nosuch,  0 },			/* 0x19 */
  { chm_nosuch,  0 },			/* 0x1a */
  { chm_nosuch,  0 },			/* 0x1b */
  { chm_nosuch,  0 },			/* 0x1c */
  { chm_nosuch,  0 },			/* 0x1d */
  { chm_nosuch,  0 },			/* 0x1e */
  { chm_nosuch,  0 },			/* 0x1f */
  { chm_nosuch,  0 },			/* 0x20 */
  { chm_nosuch,  0 },			/* 0x21 */
  { chm_nosuch,  0 },			/* 0x22 */
  { chm_nosuch,  0 },			/* 0x23 */
  { chm_nosuch,  0 },			/* 0x24 */
  { chm_nosuch,  0 },			/* 0x25 */
  { chm_nosuch,  0 },			/* 0x26 */
  { chm_nosuch,  0 },			/* 0x27 */
  { chm_nosuch,  0 },			/* 0x28 */
  { chm_nosuch,  0 },			/* 0x29 */
  { chm_nosuch,  0 },			/* 0x2a */
  { chm_nosuch,  0 },			/* 0x2b */
  { chm_nosuch,  0 },			/* 0x2c */
  { chm_nosuch,  0 },			/* 0x2d */
  { chm_nosuch,  0 },			/* 0x2e */
  { chm_nosuch,  0 },			/* 0x2f */
  { chm_nosuch,  0 },			/* 0x30 */
  { chm_nosuch,  0 },			/* 0x31 */
  { chm_nosuch,  0 },			/* 0x32 */
  { chm_nosuch,  0 },			/* 0x33 */
  { chm_nosuch,  0 },			/* 0x34 */
  { chm_nosuch,  0 },			/* 0x35 */
  { chm_nosuch,  0 },			/* 0x36 */
  { chm_nosuch,  0 },			/* 0x37 */
  { chm_nosuch,  0 },			/* 0x38 */
  { chm_nosuch,  0 },			/* 0x39 */
  { chm_nosuch,  0 },			/* 0x3a */
  { chm_nosuch,  0 },			/* 0x3b */
  { chm_nosuch,  0 },			/* 0x3c */
  { chm_nosuch,  0 },			/* 0x3d */
  { chm_nosuch,  0 },			/* 0x3e */
  { chm_nosuch,  0 },			/* 0x3f */
  { chm_nosuch,  0 },                   /* @ */
  { chm_nosuch,  0 },                   /* A */
  { chm_nosuch,  0 },                   /* B */
  { chm_nosuch,  0 },                   /* C */
  { chm_nosuch,  0 },                   /* D */
  { chm_nosuch,  0 },                   /* E */
  { chm_nosuch,  0 },                   /* F */
  { chm_nosuch,  0 },                   /* G */
  { chm_nosuch,  0 },                   /* H */
  { chm_invex,   0 },                   /* I */
  { chm_nosuch,  0 },                   /* J */
  { chm_nosuch,  0 },                   /* K */
  { chm_nosuch,  0 },                   /* L */
  { chm_simple, MODE_MODREG},           /* M */
  { chm_nosuch,  0 },                   /* N */
  { chm_operonly, MODE_OPERONLY},       /* O */
  { chm_nosuch,  0 },                   /* P */
  { chm_nosuch,  0 },                   /* Q */
  { chm_simple, MODE_REGONLY},          /* R */
  { chm_simple, MODE_SSLONLY},          /* S */
  { chm_nosuch,  0 },                   /* T */
  { chm_nosuch,  0 },                   /* U */
  { chm_nosuch,  0 },                   /* V */
  { chm_nosuch,  0 },                   /* W */
  { chm_nosuch,  0 },                   /* X */
  { chm_nosuch,  0 },                   /* Y */
  { chm_nosuch,  0 },                   /* Z */
  { chm_nosuch,  0 },
  { chm_nosuch,  0 },
  { chm_nosuch,  0 },
  { chm_nosuch,  0 },
  { chm_nosuch,  0 },
  { chm_nosuch,  0 },
  { chm_nosuch,  0 },                   /* a */
  { chm_ban,     0 },                   /* b */
  { chm_simple, MODE_NOCTRL},           /* c */
  { chm_nosuch,  0 },                   /* d */
  { chm_except,  0 },                   /* e */
  { chm_nosuch,  0 },                   /* f */
  { chm_nosuch,  0 },                   /* g */
#ifdef HALFOPS
  { chm_hop,     0 },                   /* h */
#else
  { chm_nosuch,  0 },                   /* h */
#endif
  { chm_simple,     MODE_INVITEONLY },  /* i */
  { chm_nosuch,     0               },  /* j */
  { chm_key,        0               },  /* k */
  { chm_limit,      0               },  /* l */
  { chm_simple,     MODE_MODERATED  },  /* m */
  { chm_simple,     MODE_NOPRIVMSGS },  /* n */
  { chm_op,         0               },  /* o */
  { chm_simple,     MODE_PRIVATE    },  /* p */
  { chm_nosuch,     0               },  /* q */
  { chm_registered, MODE_REGISTERED },  /* r */
  { chm_simple,     MODE_SECRET     },  /* s */
  { chm_simple,     MODE_TOPICLIMIT },  /* t */
  { chm_nosuch,     0               },  /* u */
  { chm_voice,      0               },  /* v */
  { chm_nosuch,     0               },  /* w */
  { chm_nosuch,     0               },  /* x */
  { chm_nosuch,     0               },  /* y */
  { chm_nosuch,     0               },  /* z */
  { chm_nosuch,  0 },			/* 0x7b */
  { chm_nosuch,  0 },			/* 0x7c */
  { chm_nosuch,  0 },			/* 0x7d */
  { chm_nosuch,  0 },			/* 0x7e */
  { chm_nosuch,  0 },			/* 0x7f */
  { chm_nosuch,  0 },			/* 0x80 */
  { chm_nosuch,  0 },			/* 0x81 */
  { chm_nosuch,  0 },			/* 0x82 */
  { chm_nosuch,  0 },			/* 0x83 */
  { chm_nosuch,  0 },			/* 0x84 */
  { chm_nosuch,  0 },			/* 0x85 */
  { chm_nosuch,  0 },			/* 0x86 */
  { chm_nosuch,  0 },			/* 0x87 */
  { chm_nosuch,  0 },			/* 0x88 */
  { chm_nosuch,  0 },			/* 0x89 */
  { chm_nosuch,  0 },			/* 0x8a */
  { chm_nosuch,  0 },			/* 0x8b */
  { chm_nosuch,  0 },			/* 0x8c */
  { chm_nosuch,  0 },			/* 0x8d */
  { chm_nosuch,  0 },			/* 0x8e */
  { chm_nosuch,  0 },			/* 0x8f */
  { chm_nosuch,  0 },			/* 0x90 */
  { chm_nosuch,  0 },			/* 0x91 */
  { chm_nosuch,  0 },			/* 0x92 */
  { chm_nosuch,  0 },			/* 0x93 */
  { chm_nosuch,  0 },			/* 0x94 */
  { chm_nosuch,  0 },			/* 0x95 */
  { chm_nosuch,  0 },			/* 0x96 */
  { chm_nosuch,  0 },			/* 0x97 */
  { chm_nosuch,  0 },			/* 0x98 */
  { chm_nosuch,  0 },			/* 0x99 */
  { chm_nosuch,  0 },			/* 0x9a */
  { chm_nosuch,  0 },			/* 0x9b */
  { chm_nosuch,  0 },			/* 0x9c */
  { chm_nosuch,  0 },			/* 0x9d */
  { chm_nosuch,  0 },			/* 0x9e */
  { chm_nosuch,  0 },			/* 0x9f */
  { chm_nosuch,  0 },			/* 0xa0 */
  { chm_nosuch,  0 },			/* 0xa1 */
  { chm_nosuch,  0 },			/* 0xa2 */
  { chm_nosuch,  0 },			/* 0xa3 */
  { chm_nosuch,  0 },			/* 0xa4 */
  { chm_nosuch,  0 },			/* 0xa5 */
  { chm_nosuch,  0 },			/* 0xa6 */
  { chm_nosuch,  0 },			/* 0xa7 */
  { chm_nosuch,  0 },			/* 0xa8 */
  { chm_nosuch,  0 },			/* 0xa9 */
  { chm_nosuch,  0 },			/* 0xaa */
  { chm_nosuch,  0 },			/* 0xab */
  { chm_nosuch,  0 },			/* 0xac */
  { chm_nosuch,  0 },			/* 0xad */
  { chm_nosuch,  0 },			/* 0xae */
  { chm_nosuch,  0 },			/* 0xaf */
  { chm_nosuch,  0 },			/* 0xb0 */
  { chm_nosuch,  0 },			/* 0xb1 */
  { chm_nosuch,  0 },			/* 0xb2 */
  { chm_nosuch,  0 },			/* 0xb3 */
  { chm_nosuch,  0 },			/* 0xb4 */
  { chm_nosuch,  0 },			/* 0xb5 */
  { chm_nosuch,  0 },			/* 0xb6 */
  { chm_nosuch,  0 },			/* 0xb7 */
  { chm_nosuch,  0 },			/* 0xb8 */
  { chm_nosuch,  0 },			/* 0xb9 */
  { chm_nosuch,  0 },			/* 0xba */
  { chm_nosuch,  0 },			/* 0xbb */
  { chm_nosuch,  0 },			/* 0xbc */
  { chm_nosuch,  0 },			/* 0xbd */
  { chm_nosuch,  0 },			/* 0xbe */
  { chm_nosuch,  0 },			/* 0xbf */
  { chm_nosuch,  0 },			/* 0xc0 */
  { chm_nosuch,  0 },			/* 0xc1 */
  { chm_nosuch,  0 },			/* 0xc2 */
  { chm_nosuch,  0 },			/* 0xc3 */
  { chm_nosuch,  0 },			/* 0xc4 */
  { chm_nosuch,  0 },			/* 0xc5 */
  { chm_nosuch,  0 },			/* 0xc6 */
  { chm_nosuch,  0 },			/* 0xc7 */
  { chm_nosuch,  0 },			/* 0xc8 */
  { chm_nosuch,  0 },			/* 0xc9 */
  { chm_nosuch,  0 },			/* 0xca */
  { chm_nosuch,  0 },			/* 0xcb */
  { chm_nosuch,  0 },			/* 0xcc */
  { chm_nosuch,  0 },			/* 0xcd */
  { chm_nosuch,  0 },			/* 0xce */
  { chm_nosuch,  0 },			/* 0xcf */
  { chm_nosuch,  0 },			/* 0xd0 */
  { chm_nosuch,  0 },			/* 0xd1 */
  { chm_nosuch,  0 },			/* 0xd2 */
  { chm_nosuch,  0 },			/* 0xd3 */
  { chm_nosuch,  0 },			/* 0xd4 */
  { chm_nosuch,  0 },			/* 0xd5 */
  { chm_nosuch,  0 },			/* 0xd6 */
  { chm_nosuch,  0 },			/* 0xd7 */
  { chm_nosuch,  0 },			/* 0xd8 */
  { chm_nosuch,  0 },			/* 0xd9 */
  { chm_nosuch,  0 },			/* 0xda */
  { chm_nosuch,  0 },			/* 0xdb */
  { chm_nosuch,  0 },			/* 0xdc */
  { chm_nosuch,  0 },			/* 0xdd */
  { chm_nosuch,  0 },			/* 0xde */
  { chm_nosuch,  0 },			/* 0xdf */
  { chm_nosuch,  0 },			/* 0xe0 */
  { chm_nosuch,  0 },			/* 0xe1 */
  { chm_nosuch,  0 },			/* 0xe2 */
  { chm_nosuch,  0 },			/* 0xe3 */
  { chm_nosuch,  0 },			/* 0xe4 */
  { chm_nosuch,  0 },			/* 0xe5 */
  { chm_nosuch,  0 },			/* 0xe6 */
  { chm_nosuch,  0 },			/* 0xe7 */
  { chm_nosuch,  0 },			/* 0xe8 */
  { chm_nosuch,  0 },			/* 0xe9 */
  { chm_nosuch,  0 },			/* 0xea */
  { chm_nosuch,  0 },			/* 0xeb */
  { chm_nosuch,  0 },			/* 0xec */
  { chm_nosuch,  0 },			/* 0xed */
  { chm_nosuch,  0 },			/* 0xee */
  { chm_nosuch,  0 },			/* 0xef */
  { chm_nosuch,  0 },			/* 0xf0 */
  { chm_nosuch,  0 },			/* 0xf1 */
  { chm_nosuch,  0 },			/* 0xf2 */
  { chm_nosuch,  0 },			/* 0xf3 */
  { chm_nosuch,  0 },			/* 0xf4 */
  { chm_nosuch,  0 },			/* 0xf5 */
  { chm_nosuch,  0 },			/* 0xf6 */
  { chm_nosuch,  0 },			/* 0xf7 */
  { chm_nosuch,  0 },			/* 0xf8 */
  { chm_nosuch,  0 },			/* 0xf9 */
  { chm_nosuch,  0 },			/* 0xfa */
  { chm_nosuch,  0 },			/* 0xfb */
  { chm_nosuch,  0 },			/* 0xfc */
  { chm_nosuch,  0 },			/* 0xfd */
  { chm_nosuch,  0 },			/* 0xfe */
  { chm_nosuch,  0 },			/* 0xff */
};

/* get_channel_access()
 *
 * inputs       - pointer to Client struct
 *              - pointer to Membership struct
 * output       - CHACCESS_CHANOP if we should let them have
 *                chanop level access, 0 for peon level access.
 * side effects - NONE
 */
static int
get_channel_access(const struct Client *source_p,
                   const struct Membership *member)
{
  /* Let hacked servers in for now... */
  if (!MyClient(source_p))
    return CHACCESS_CHANOP;

  if (member == NULL)
    return CHACCESS_NOTONCHAN;

  /* just to be sure.. */
  assert(source_p == member->client_p);

  if (has_member_flags(member, CHFL_CHANOP))
    return CHACCESS_CHANOP;

#ifdef HALFOPS
  if (has_member_flags(member, CHFL_HALFOP))
    return CHACCESS_HALFOP;
#endif

  return CHACCESS_PEON;
}

/* void send_cap_mode_changes(struct Client *client_p,
 *                        struct Client *source_p,
 *                        struct Channel *chptr, int cap, int nocap)
 * Input: The client sending(client_p), the source client(source_p),
 *        the channel to send mode changes for(chptr)
 * Output: None.
 * Side-effects: Sends the appropriate mode changes to capable servers.
 *
 * send_cap_mode_changes() will loop the server list itself, because
 * at this point in time we have 4 capabs for channels, CAP_IE, CAP_EX,
 * and a server could support any number of these..
 * so we make the modebufs per server, tailoring them to each servers
 * specific demand.  Its not very pretty, but its one of the few realistic
 * ways to handle having this many capabs for channel modes.. --fl_
 *
 * Reverted back to my original design, except that we now keep a count
 * of the number of servers which each combination as an optimisation, so
 * the capabs combinations which are not needed are not worked out. -A1kmm
 */
/* rewritten to ensure parabuf < MODEBUFLEN -db */

static void
send_cap_mode_changes(struct Client *client_p, struct Client *source_p,
                      struct Channel *chptr, unsigned int cap, unsigned int nocap)
{
  int i, mbl, pbl, arglen, nc, mc;
  int len;
  const char *arg = NULL;
  char *parptr;
  int dir = MODE_QUERY;

  mc = 0;
  nc = 0;
  pbl = 0;

  parabuf[0] = '\0';
  parptr = parabuf;

  if ((cap & CAP_TS6) && source_p->id[0] != '\0')
    mbl = snprintf(modebuf, sizeof(modebuf), ":%s TMODE %lu %s ", source_p->id,
                   (unsigned long)chptr->channelts, chptr->chname);
  else
    mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ", source_p->name,
                   chptr->chname);

  /* loop the list of - modes we have */
  for (i = 0; i < mode_count; i++)
  {
    /* if they dont support the cap we need, or they do support a cap they
     * cant have, then dont add it to the modebuf.. that way they wont see
     * the mode
     */
    if ((mode_changes[i].letter == 0) ||
        ((cap & mode_changes[i].caps) != mode_changes[i].caps) ||
        ((nocap & mode_changes[i].nocaps) != mode_changes[i].nocaps))
      continue;

    arg = "";

    if ((cap & CAP_TS6) && mode_changes[i].id)
      arg = mode_changes[i].id;
    if (*arg == '\0')
      arg = mode_changes[i].arg;

    /* if we're creeping past the buf size, we need to send it and make
     * another line for the other modes
     * XXX - this could give away server topology with uids being
     * different lengths, but not much we can do, except possibly break
     * them as if they were the longest of the nick or uid at all times,
     * which even then won't work as we don't always know the uid -A1kmm.
     */
    if (arg != NULL)
      arglen = strlen(arg);
    else
      arglen = 0;

    if ((mc == MAXMODEPARAMS) ||
        ((arglen + mbl + pbl + 2) > IRCD_BUFSIZE) ||
        (pbl + arglen + BAN_FUDGE) >= MODEBUFLEN)
    {
      if (nc != 0)
        sendto_server(client_p, cap, nocap, "%s %s", modebuf, parabuf);
      nc = 0;
      mc = 0;

      if ((cap & CAP_TS6) && source_p->id[0] != '\0')
        mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ", source_p->id,
                       chptr->chname);
      else
        mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ", source_p->name,
                       chptr->chname);

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
    nc++;

    if (arg != NULL)
    {
      len = sprintf(parptr, "%s ", arg);
      pbl += len;
      parptr += len;
      mc++;
    }
  }

  if (pbl && parabuf[pbl - 1] == ' ')
    parabuf[pbl - 1] = 0;

  if (nc != 0)
    sendto_server(client_p, cap, nocap, "%s %s", modebuf, parabuf);
}

/* void send_mode_changes(struct Client *client_p,
 *                        struct Client *source_p,
 *                        struct Channel *chptr)
 * Input: The client sending(client_p), the source client(source_p),
 *        the channel to send mode changes for(chptr),
 *        mode change globals.
 * Output: None.
 * Side-effects: Sends the appropriate mode changes to other clients
 *               and propagates to servers.
 */
/* ensure parabuf < MODEBUFLEN -db */
static void
send_mode_changes(struct Client *client_p, struct Client *source_p,
                  struct Channel *chptr)
{
  int i, mbl, pbl, arglen, nc, mc;
  int len;
  const char *arg = NULL;
  char *parptr;
  int dir = MODE_QUERY;

  /* bail out if we have nothing to do... */
  if (!mode_count)
    return;

  if (IsServer(source_p))
    mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ", (IsHidden(source_p) ||
                   ConfigServerHide.hide_servers) ?
                   me.name : source_p->name, chptr->chname);
  else
    mbl = snprintf(modebuf, sizeof(modebuf), ":%s!%s@%s MODE %s ", source_p->name,
                   source_p->username, source_p->host, chptr->chname);

  mc = 0;
  nc = 0;
  pbl = 0;

  parabuf[0] = '\0';
  parptr = parabuf;

  for (i = 0; i < mode_count; i++)
  {
    if (mode_changes[i].letter == 0 ||
        mode_changes[i].mems == NON_CHANOPS ||
        mode_changes[i].mems == ONLY_SERVERS)
      continue;

    arg = mode_changes[i].arg;
    if (arg != NULL)
      arglen = strlen(arg);
    else
      arglen = 0;

    if ((mc == MAXMODEPARAMS)  ||
        ((arglen + mbl + pbl + 2) > IRCD_BUFSIZE) ||
        ((arglen + pbl + BAN_FUDGE) >= MODEBUFLEN))
    {
      if (mbl && modebuf[mbl - 1] == '-')
        modebuf[mbl - 1] = '\0';

      if (nc != 0)
        sendto_channel_local(ALL_MEMBERS, 0, chptr, "%s %s", modebuf, parabuf);

      nc = 0;
      mc = 0;

      if (IsServer(source_p))
        mbl = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s ", (IsHidden(source_p) ||
                       ConfigServerHide.hide_servers) ?
                       me.name : source_p->name, chptr->chname);
      else
        mbl = snprintf(modebuf, sizeof(modebuf), ":%s!%s@%s MODE %s ", source_p->name,
                       source_p->username, source_p->host, chptr->chname);

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
    nc++;

    if (arg != NULL)
    {
      len = sprintf(parptr, "%s ", arg);
      pbl += len;
      parptr += len;
      mc++;
    }
  }

  if (pbl && parabuf[pbl - 1] == ' ')
    parabuf[pbl - 1] = 0;

  if (nc != 0)
    sendto_channel_local(ALL_MEMBERS, 0, chptr, "%s %s", modebuf, parabuf);

  nc = 0;
  mc = 0;

  /* Now send to servers... */
  for (i = 0; i < NCHCAP_COMBOS; i++)
    if (chcap_combos[i].count != 0)
      send_cap_mode_changes(client_p, source_p, chptr,
                            chcap_combos[i].cap_yes,
                            chcap_combos[i].cap_no);
}

/* void set_channel_mode(struct Client *client_p, struct Client *source_p,
 *               struct Channel *chptr, int parc, char **parv,
 *               char *chname)
 * Input: The client we received this from, the client this originated
 *        from, the channel, the parameter count starting at the modes,
 *        the parameters, the channel name.
 * Output: None.
 * Side-effects: Changes the channel membership and modes appropriately,
 *               sends the appropriate MODE messages to the appropriate
 *               clients.
 */
void
set_channel_mode(struct Client *client_p, struct Client *source_p, struct Channel *chptr,
                 struct Membership *member, int parc, char *parv[])
{
  int dir = MODE_ADD;
  int parn = 1;
  int alevel, errors = 0;
  char *ml = parv[0], c;

  mode_count = 0;
  mode_limit = 0;
  simple_modes_mask = 0;

  alevel = get_channel_access(source_p, member);

  for (; (c = *ml); ++ml)
  {
    switch (c)
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
        struct ChannelMode *tptr = &ModeTable[(unsigned char)c];

        tptr->func(client_p, source_p, chptr, parc, &parn,
                   parv, &errors, alevel, dir, c, tptr->d);
        break;
      }
    }
  }

  send_mode_changes(client_p, source_p, chptr);
}

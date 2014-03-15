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

/*! \file m_sjoin.c
 * \brief Includes required functions for processing the SJOIN command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "s_serv.h"
#include "conf.h"
#include "s_misc.h"


static char modebuf[MODEBUFLEN];
static char parabuf[MODEBUFLEN];
static char sendbuf[MODEBUFLEN];
static const char *para[MAXMODEPARAMS];
static char *mbuf;
static int pargs;

static void set_final_mode(struct Mode *, struct Mode *);
static void remove_our_modes(struct Channel *, struct Client *);
static void remove_a_mode(struct Channel *, struct Client *, int, char);
static void remove_ban_list(struct Channel *, struct Client *, dlink_list *, char);


/* ms_sjoin()
 *
 * parv[0] - command
 * parv[1] - TS
 * parv[2] - channel
 * parv[3] - modes + n arguments (key and/or limit)
 * parv[4+n] - flags+nick list (all in one parameter)
 *
 * process a SJOIN, taking the TS's into account to either ignore the
 * incoming modes or undo the existing ones or merge them, and JOIN
 * all the specified users while sending JOIN/MODEs to local clients
 */
static int
ms_sjoin(struct Client *source_p, int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  struct Client  *target_p = NULL;
  time_t         newts;
  time_t         oldts;
  time_t         tstosend;
  struct Mode mode, *oldmode;
  int            args = 0;
  char           keep_our_modes = 1;
  char           keep_new_modes = 1;
  char           have_many_nicks = 0;
  int            lcount;
  char           uid_prefix[4];
  char           *up = NULL;
  int            len_uid = 0;
  int            isnew = 0;
  int            buflen = 0;
  int            slen;
  unsigned       int fl;
  char           *s;
  char           *sptr;
  char uid_buf[IRCD_BUFSIZE];  /* buffer for modes/prefixes */
  char           *uid_ptr;
  char           *p; /* pointer used making sjbuf */
  dlink_node     *m;
  const char *servername = (ConfigServerHide.hide_servers || IsHidden(source_p)) ?
                            me.name : source_p->name;

  if (IsClient(source_p) || parc < 5)
    return 0;

  if (!check_channel_name(parv[2], 0))
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "*** Too long or invalid channel name from %s(via %s): %s",
                         source_p->name, source_p->from->name, parv[2]);
    return 0;
  }

  modebuf[0] = '\0';
  mbuf = modebuf;
  pargs = 0;
  newts = atol(parv[1]);

  mode.mode = 0;
  mode.limit = 0;
  mode.key[0] = '\0';

  for (s = parv[3]; *s; ++s)
  {
    switch (*s)
    {
      case 'c':
        mode.mode |= MODE_NOCTRL;
        break;
      case 't':
        mode.mode |= MODE_TOPICLIMIT;
        break;
      case 'n':
        mode.mode |= MODE_NOPRIVMSGS;
        break;
      case 's':
        mode.mode |= MODE_SECRET;
        break;
      case 'm':
        mode.mode |= MODE_MODERATED;
        break;
      case 'i':
        mode.mode |= MODE_INVITEONLY;
        break;
      case 'p':
        mode.mode |= MODE_PRIVATE;
        break;
      case 'r':
        mode.mode |= MODE_REGISTERED;
        break;
      case 'M':
        mode.mode |= MODE_MODREG;
        break;
      case 'O':
        mode.mode |= MODE_OPERONLY;
        break;
      case 'S':
        mode.mode |= MODE_SSLONLY;
        break;
      case 'k':
        strlcpy(mode.key, parv[4 + args], sizeof(mode.key));
        args++;

        if (parc < 5 + args)
          return 0;
        break;
      case 'l':
        mode.limit = atoi(parv[4 + args]);
        args++;

        if (parc < 5 + args)
          return 0;
        break;
    }
  }

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    isnew = 1;
    chptr = make_channel(parv[2]);
  }

  parabuf[0] = '\0';
  oldts = chptr->channelts;
  oldmode = &chptr->mode;

  if (ConfigFileEntry.ignore_bogus_ts)
  {
    if (newts < 800000000)
    {
      sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                           "*** Bogus TS %lu on %s ignored from %s",
                           (unsigned long)newts, chptr->chname,
                           source_p->name);

      newts = (oldts == 0) ? 0 : 800000000;
    }
  }
  else
  {
    if (!newts && !isnew && oldts)
    {
      sendto_channel_local(ALL_MEMBERS, 0, chptr,
                           ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to 0",
                           me.name, chptr->chname, chptr->chname, (unsigned long)oldts);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Server %s changing TS on %s from %lu to 0",
                           source_p->name, chptr->chname, (unsigned long)oldts);
    }
  }

  if (isnew)
    chptr->channelts = tstosend = newts;
  else if (newts == 0 || oldts == 0)
    chptr->channelts = tstosend = 0;
  else if (newts == oldts)
    tstosend = oldts;
  else if (newts < oldts)
  {
    keep_our_modes = 0;
    chptr->channelts = tstosend = newts;
  }
  else
  {
    keep_new_modes = 0;
    tstosend = oldts;
  }

  if (!keep_new_modes)
    mode = *oldmode;
  else if (keep_our_modes)
  {
    mode.mode |= oldmode->mode;
    if (oldmode->limit > mode.limit)
      mode.limit = oldmode->limit;
    if (strcmp(mode.key, oldmode->key) < 0)
      strcpy(mode.key, oldmode->key);
  }
  set_final_mode(&mode, oldmode);
  chptr->mode = mode;

  /* Lost the TS, other side wins, so remove modes on this side */
  if (!keep_our_modes)
  {
    remove_our_modes(chptr, source_p);

    if (chptr->topic[0])
    {
      set_channel_topic(chptr, "", "", 0, 0);
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s TOPIC %s :",
                           (IsHidden(source_p) ||
                           ConfigServerHide.hide_servers) ?
                           me.name : source_p->name, chptr->chname);
    }

    sendto_channel_local(ALL_MEMBERS, 0, chptr,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to %lu",
                         me.name, chptr->chname, chptr->chname,
                         (unsigned long)oldts, (unsigned long)newts);
  }

  if (*modebuf != '\0')
  {
    /* This _SHOULD_ be to ALL_MEMBERS
     * It contains only +imnpstlk, etc */
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s %s",
                         servername, chptr->chname, modebuf, parabuf);
  }

  if (parv[3][0] != '0' && keep_new_modes)
    channel_modes(chptr, source_p, modebuf, parabuf);
  else
  {
    modebuf[0] = '0';
    modebuf[1] = '\0';
  }

  buflen = snprintf(uid_buf, sizeof(uid_buf), ":%s SJOIN %lu %s %s %s:",
                    ID(source_p), (unsigned long)tstosend,
                    chptr->chname, modebuf, parabuf);
  uid_ptr = uid_buf + buflen;

  /* check we can fit a nick on the end, as well as \r\n and a prefix "
   * @%+", and a space.
   */
  if (buflen >= (IRCD_BUFSIZE - IRCD_MAX(NICKLEN, IDLEN) - 2 - 3 - 1))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Long SJOIN from server: %s(via %s) (ignored)",
                         source_p->name, source_p->from->name);
    return 0;
  }

  mbuf = modebuf;
  sendbuf[0] = '\0';
  pargs = 0;

  *mbuf++ = '+';

  s = parv[args + 4];
  while (*s == ' ')
    s++;
  if ((p = strchr(s, ' ')) != NULL)
  {
    *p++ = '\0';
    while (*p == ' ')
      p++;
    have_many_nicks = *p;
  }

  while (*s)
  {
    int valid_mode = 1;
    fl = 0;

    do
    {
      switch (*s)
      {
      case '@':
        fl |= CHFL_CHANOP;
        s++;
        break;
#ifdef HALFOPS
      case '%':
        fl |= CHFL_HALFOP;
        s++;
        break;
#endif
      case '+':
        fl |= CHFL_VOICE;
        s++;
        break;
      default:
        valid_mode = 0;
        break;
      }
    } while (valid_mode);

    target_p = find_chasing(source_p, s, NULL);
    assert(IsClient(target_p));

    /*
     * if the client doesnt exist, or if its fake direction/server, skip.
     * we cannot send ERR_NOSUCHNICK here because if its a UID, we cannot
     * lookup the nick, and its better to never send the numeric than only
     * sometimes.
     */
    if (target_p == NULL || target_p->from != source_p->from)
      goto nextnick;

    len_uid = strlen(ID(target_p));
    up = uid_prefix;

    if (keep_new_modes)
    {
      if (fl & CHFL_CHANOP)
      {
        *up++  = '@';
        len_uid++;
      }
#ifdef HALFOPS
      if (fl & CHFL_HALFOP)
      {
        *up++  = '%';
        len_uid++;
      }
#endif
      if (fl & CHFL_VOICE)
      {
        *up++  = '+';
        len_uid++;
      }
    }
    else
    {
      if (fl & (CHFL_CHANOP|CHFL_HALFOP))
        fl = CHFL_DEOPPED;
      else
        fl = 0;
    }
    *up = '\0';

    if ((uid_ptr - uid_buf + len_uid) > (IRCD_BUFSIZE - 2))
    {
      sendto_server(source_p, NOCAPS, NOCAPS, "%s", uid_buf);

      buflen = snprintf(uid_buf, sizeof(uid_buf), ":%s SJOIN %lu %s %s %s:",
                        ID(source_p), (unsigned long)tstosend,
                        chptr->chname, modebuf, parabuf);
      uid_ptr = uid_buf + buflen;
    }

    uid_ptr += sprintf(uid_ptr,  "%s%s ", uid_prefix, ID(target_p));

    if (!IsMember(target_p, chptr))
    {
      add_user_to_channel(chptr, target_p, fl, !have_many_nicks);
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN :%s",
                           target_p->name, target_p->username,
                           target_p->host, chptr->chname);
      if (target_p->away[0])
        sendto_channel_local_butone(target_p, 0, CAP_AWAY_NOTIFY, chptr,
                                    ":%s!%s@%s AWAY :%s",
                                    target_p->name, target_p->username,
                                    target_p->host, target_p->away);
    }

    if (fl & CHFL_CHANOP)
    {
      *mbuf++ = 'o';
      para[pargs++] = target_p->name;

      if (pargs >= MAXMODEPARAMS)
      {
        /*
         * Ok, the code is now going to "walk" through
         * sendbuf, filling in para strings. So, I will use sptr
         * to point into the sendbuf.
         * Notice, that ircsprintf() returns the number of chars
         * successfully inserted into string.
         * - Dianora
         */

        sptr = sendbuf;
        *mbuf = '\0';

        for(lcount = 0; lcount < MAXMODEPARAMS; lcount++)
        {
          slen = sprintf(sptr, " %s", para[lcount]);  /* see? */
          sptr += slen;  /* ready for next */
        }
        sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s%s",
                            servername, chptr->chname, modebuf, sendbuf);
        mbuf = modebuf;
        *mbuf++ = '+';

        sendbuf[0] = '\0';
        pargs = 0;
      }
    }
#ifdef HALFOPS
    if (fl & CHFL_HALFOP)
    {
      *mbuf++ = 'h';
      para[pargs++] = target_p->name;

      if (pargs >= MAXMODEPARAMS)
      {
        sptr = sendbuf;
        *mbuf = '\0';
        for(lcount = 0; lcount < MAXMODEPARAMS; lcount++)
        {
          slen = sprintf(sptr, " %s", para[lcount]);
          sptr += slen;
        }
        sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s%s",
                             servername, chptr->chname, modebuf, sendbuf);

        mbuf = modebuf;
        *mbuf++ = '+';

        sendbuf[0] = '\0';
        pargs = 0;
      }
    }
#endif
    if (fl & CHFL_VOICE)
    {
      *mbuf++ = 'v';
      para[pargs++] = target_p->name;

      if (pargs >= MAXMODEPARAMS)
      {
        sptr = sendbuf;
        *mbuf = '\0';
        for (lcount = 0; lcount < MAXMODEPARAMS; lcount++)
        {
          slen = sprintf(sptr, " %s", para[lcount]);
          sptr += slen;
        }
        sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s%s",
                             servername, chptr->chname, modebuf, sendbuf);

        mbuf = modebuf;
        *mbuf++ = '+';

        sendbuf[0] = '\0';
        pargs = 0;
      }
    }

  nextnick:
    if ((s = p) == NULL)
      break;
    while (*s == ' ')
      s++;
    if ((p = strchr(s, ' ')) != NULL)
    {
      *p++ = 0;
      while (*p == ' ')
        p++;
    }
  }

  *mbuf = '\0';
  *(uid_ptr - 1) = '\0';

  /*
   * checking for lcount < MAXMODEPARAMS at this time is wrong
   * since the code has already verified above that pargs < MAXMODEPARAMS
   * checking for para[lcount] != '\0' is also wrong, since
   * there is no place where para[lcount] is set!
   * - Dianora
   */

  if (pargs != 0)
  {
    sptr = sendbuf;

    for (lcount = 0; lcount < pargs; lcount++)
    {
      slen = sprintf(sptr, " %s", para[lcount]);
      sptr += slen;
    }

    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s%s",
                        servername, chptr->chname, modebuf, sendbuf);
  }

  /* If this happens, its the result of a malformed SJOIN
   * a remnant from the old persistent channel code. *sigh*
   * Or it could be the result of a client just leaving
   * and leaving us with a channel formed just as the client parts.
   * - Dianora
   */

  if ((dlink_list_length(&chptr->members) == 0) && isnew)
  {
    destroy_channel(chptr);
    return 0;
  }

  if (parv[4 + args][0] == '\0')
    return 0;

  sendto_server(source_p, NOCAPS, NOCAPS, "%s", uid_buf);

  if (!keep_our_modes)
  {
    if (dlink_list_length(&chptr->banlist) > 0)
      remove_ban_list(chptr, source_p, &chptr->banlist, 'b');

    if (dlink_list_length(&chptr->exceptlist) > 0)
      remove_ban_list(chptr, source_p, &chptr->exceptlist, 'e');

    if (dlink_list_length(&chptr->invexlist) > 0)
      remove_ban_list(chptr, source_p, &chptr->invexlist, 'I');
    clear_ban_cache(chptr);
  }

  return 0;
}

/* set_final_mode
 *
 * inputs	- channel mode
 *		- old channel mode
 * output	- NONE
 * side effects	- walk through all the channel modes turning off modes
 *		  that were on in oldmode but aren't on in mode.
 *		  Then walk through turning on modes that are on in mode
 *		  but were not set in oldmode.
 */
static void
set_final_mode(struct Mode *mode, struct Mode *oldmode)
{
  const struct mode_letter *tab;
  char *pbuf = parabuf;
  int len;

  *mbuf++ = '-';

  for (tab = chan_modes; tab->letter; ++tab)
  {
    if ((tab->mode & oldmode->mode) &&
        !(tab->mode & mode->mode))
      *mbuf++ = tab->letter;
  }

  if (oldmode->limit != 0 && mode->limit == 0)
    *mbuf++ = 'l';

  if (oldmode->key[0] && !mode->key[0])
  {
    *mbuf++ = 'k';
    len = sprintf(pbuf, "%s ", oldmode->key);
    pbuf += len;
    pargs++;
  }

  if (*(mbuf-1) == '-')
    *(mbuf-1) = '+';
  else
    *mbuf++ = '+';

  for (tab = chan_modes; tab->letter; ++tab)
  {
    if ((tab->mode & mode->mode) &&
        !(tab->mode & oldmode->mode))
      *mbuf++ = tab->letter;
  }

  if (mode->limit != 0 && oldmode->limit != mode->limit)
  {
    *mbuf++ = 'l';
    len = sprintf(pbuf, "%d ", mode->limit);
    pbuf += len;
    pargs++;
  }

  if (mode->key[0] && strcmp(oldmode->key, mode->key))
  {
    *mbuf++ = 'k';
    len = sprintf(pbuf, "%s ", mode->key);
    pbuf += len;
    pargs++;
  }
  if (*(mbuf-1) == '+')
    *(mbuf-1) = '\0';
  else
    *mbuf = '\0';
}

/* remove_our_modes()
 *
 * inputs	- pointer to channel to remove modes from
 *		- client pointer
 * output	- NONE
 * side effects	- Go through the local members, remove all their
 *		  chanop modes etc., this side lost the TS.
 */
static void
remove_our_modes(struct Channel *chptr, struct Client *source_p)
{
  remove_a_mode(chptr, source_p, CHFL_CHANOP, 'o');
#ifdef HALFOPS
  remove_a_mode(chptr, source_p, CHFL_HALFOP, 'h');
#endif
  remove_a_mode(chptr, source_p, CHFL_VOICE, 'v');
}

/* remove_a_mode()
 *
 * inputs	- pointer to channel
 *		- server or client removing the mode
 *		- mask o/h/v mask to be removed
 *		- flag o/h/v to be removed
 * output	- NONE
 * side effects	- remove ONE mode from all members of a channel
 */
static void
remove_a_mode(struct Channel *chptr, struct Client *source_p,
             int mask, char flag)
{
  dlink_node *ptr;
  struct Membership *ms;
  char lmodebuf[MODEBUFLEN];
  char *sp=sendbuf;
  const char *lpara[MAXMODEPARAMS];
  int count = 0;
  int i;
  int l;

  mbuf = lmodebuf;
  *mbuf++ = '-';
  *sp = '\0';

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;

    if ((ms->flags & mask) == 0)
      continue;

    ms->flags &= ~mask;

    lpara[count++] = ms->client_p->name;

    *mbuf++ = flag;

    if (count >= MAXMODEPARAMS)
    {
      for(i = 0; i < MAXMODEPARAMS; i++)
      {
        l = sprintf(sp, " %s", lpara[i]);
        sp += l;
      }

      *mbuf = '\0';
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s%s",
                           (IsHidden(source_p) || ConfigServerHide.hide_servers) ?
                           me.name : source_p->name,
                           chptr->chname, lmodebuf, sendbuf);
      mbuf = lmodebuf;
      *mbuf++ = '-';
      count = 0;
      sp = sendbuf;
      *sp = '\0';
    }
  }

  if (count != 0)
  {
    *mbuf = '\0';
    for(i = 0; i < count; i++)
    {
      l = sprintf(sp, " %s", lpara[i]);
      sp += l;
    }
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s%s",
                         (IsHidden(source_p) || ConfigServerHide.hide_servers) ?
                         me.name : source_p->name,
                         chptr->chname, lmodebuf, sendbuf);
  }
}

/* remove_ban_list()
 *
 * inputs	- channel, source, list to remove, char of mode
 * outputs	- none
 * side effects	- given ban list is removed, modes are sent to local clients
 */
static void
remove_ban_list(struct Channel *chptr, struct Client *source_p,
                dlink_list *list, char c)
{
  char lmodebuf[MODEBUFLEN];
  char lparabuf[IRCD_BUFSIZE];
  struct Ban *banptr = NULL;
  dlink_node *ptr = NULL;
  dlink_node *next_ptr = NULL;
  char *pbuf = NULL;
  int count = 0;
  int cur_len, mlen, plen;

  pbuf = lparabuf;
  cur_len = mlen = sprintf(lmodebuf, ":%s MODE %s -",
                           source_p->name, chptr->chname);
  mbuf = lmodebuf + mlen;

  DLINK_FOREACH_SAFE(ptr, next_ptr, list->head)
  {
    banptr = ptr->data;

    plen = banptr->len + 4;  /* another +b and "!@ " */
    if (count >= MAXMODEPARAMS ||
        (cur_len + 1 /* space between */ + (plen - 1)) > IRCD_BUFSIZE - 2)
    {
      /* NUL-terminate and remove trailing space */
      *mbuf = *(pbuf - 1) = '\0';
      sendto_channel_local(ALL_MEMBERS, 0, chptr, "%s %s", lmodebuf, lparabuf);
      cur_len = mlen;
      mbuf = lmodebuf + mlen;
      pbuf = lparabuf;
      count = 0;
    }

    *mbuf++ = c;
    cur_len += plen;
    pbuf += sprintf(pbuf, "%s!%s@%s ", banptr->name, banptr->user,
                    banptr->host);
    ++count;

    remove_ban(banptr, list);
  }

  *mbuf = *(pbuf - 1) = '\0';
  sendto_channel_local(ALL_MEMBERS, 0, chptr, "%s %s", lmodebuf, lparabuf);
}

static struct Message sjoin_msgtab =
{
  "SJOIN", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_ignore, ms_sjoin, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&sjoin_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&sjoin_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};

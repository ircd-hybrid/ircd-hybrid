/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file m_stats.c
 * \brief Includes required functions for processing the STATS command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "listener.h"
#include "gline.h"
#include "conf.h"
#include "conf_class.h"
#include "hostmask.h"
#include "numeric.h"
#include "send.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "misc.h"
#include "server.h"
#include "user.h"
#include "event.h"
#include "dbuf.h"
#include "parse.h"
#include "modules.h"
#include "resv.h"
#include "whowas.h"
#include "watch.h"
#include "res.h"
#include "motd.h"
#include "ipcache.h"


static const struct shared_flags
{
  const unsigned int type;
  const unsigned char letter;
} flag_table[] = {
  { SHARED_KLINE,   'K' },
  { SHARED_UNKLINE, 'U' },
  { SHARED_XLINE,   'X' },
  { SHARED_UNXLINE, 'Y' },
  { SHARED_RESV,    'Q' },
  { SHARED_UNRESV,  'R' },
  { SHARED_LOCOPS,  'L' },
  { SHARED_DLINE,   'D' },
  { SHARED_UNDLINE, 'E' },
  { 0, '\0' }
};

/*
 * inputs	- pointer to client requesting confitem report
 *		- ConfType to report
 * output	- none
 * side effects	-
 */
static void
report_confitem_types(struct Client *source_p, enum maskitem_type type)
{
  const dlink_node *node = NULL;
  const struct MaskItem *conf = NULL;
  char buf[IRCD_BUFSIZE];
  char *p = NULL;

  switch (type)
  {
    case CONF_XLINE:
      DLINK_FOREACH(node, xconf_items.head)
      {
        conf = node->data;
        sendto_one_numeric(source_p, &me, RPL_STATSXLINE,
                           conf->until ? 'x': 'X', conf->count,
                           conf->name, conf->reason);
      }

      break;

    case CONF_ULINE:
      DLINK_FOREACH(node, uconf_items.head)
      {
        conf = node->data;
        p = buf;

        *p++ = 'c';

        for (const struct shared_flags *shared = flag_table; shared->type; ++shared)
          if (shared->type & conf->flags)
            *p++ = shared->letter;
          else
            *p++ = ToLower(shared->letter);

        *p = '\0';

        sendto_one_numeric(source_p, &me, RPL_STATSULINE, conf->name,
                           conf->user ? conf->user: "*",
                           conf->host ? conf->host: "*", buf);
      }

      DLINK_FOREACH(node, cluster_items.head)
      {
        conf = node->data;
        p = buf;

        *p++ = 'C';

        for (const struct shared_flags *shared = flag_table; shared->type; ++shared)
          if (shared->type & conf->flags)
            *p++ = shared->letter;
          else
            *p++ = ToLower(shared->letter);

        *p = '\0';

        sendto_one_numeric(source_p, &me, RPL_STATSULINE, conf->name, "*", "*", buf);
      }

      break;

    case CONF_OPER:
      DLINK_FOREACH(node, oconf_items.head)
      {
        conf = node->data;

        /* Don't allow non opers to see oper privs */
        if (HasUMode(source_p, UMODE_OPER))
          sendto_one_numeric(source_p, &me, RPL_STATSOLINE, 'O', conf->user, conf->host,
                             conf->name, oper_privs_as_string(conf->port),
                             conf->class->name);
        else
          sendto_one_numeric(source_p, &me, RPL_STATSOLINE, 'O', conf->user, conf->host,
                             conf->name, "0", conf->class->name);
      }

      break;

    case CONF_SERVICE:
      DLINK_FOREACH(node, service_items.head)
      {
        conf = node->data;
        sendto_one_numeric(source_p, &me, RPL_STATSSERVICE, 'S', "*", conf->name, 0, 0);
      }

      break;

    case CONF_SERVER:
      DLINK_FOREACH(node, server_items.head)
      {
        p = buf;
        conf = node->data;

        buf[0] = '\0';

        if (IsConfAllowAutoConn(conf))
          *p++ = 'A';
        if (IsConfSSL(conf))
          *p++ = 'S';
        if (buf[0] == '\0')
          *p++ = '*';

        *p = '\0';

        /*
         * Allow admins to see actual ips unless hide_server_ips is enabled
         */
        if (!ConfigServerHide.hide_server_ips && HasUMode(source_p, UMODE_ADMIN))
          sendto_one_numeric(source_p, &me, RPL_STATSCLINE, 'C', conf->host,
                             buf, conf->name, conf->port,
                             conf->class->name);
        else
          sendto_one_numeric(source_p, &me, RPL_STATSCLINE, 'C',
                             "*@127.0.0.1", buf, conf->name, conf->port,
                             conf->class->name);
      }

      break;

    default:
      break;
  }
}

/* report_resv()
 *
 * inputs       - pointer to client pointer to report to.
 * output       - NONE
 * side effects - report all resvs to client.
 */
static void
report_resv(struct Client *source_p)
{
  const dlink_node *node = NULL;

  DLINK_FOREACH(node, cresv_items.head)
  {
    const struct MaskItem *conf = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSQLINE,
                       conf->until ? 'q' : 'Q', conf->count,
                       conf->name, conf->reason);
  }

  DLINK_FOREACH(node, nresv_items.head)
  {
    const struct MaskItem *conf = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSQLINE,
                       conf->until ? 'q' : 'Q', conf->count,
                       conf->name, conf->reason);
  }
}

/*
 * This is part of the STATS replies. There is no offical numeric for this
 * since this isn't an official command, in much the same way as HASH isn't.
 * It is also possible that some systems wont support this call or have
 * different field names for "struct rusage".
 * -avalon
 */
static void
stats_usage(struct Client *source_p, int parc, char *parv[])
{
  struct rusage rus;
  time_t secs;
  time_t rup;
#ifdef  hz
# define hzz hz
#else
# ifdef HZ
#  define hzz HZ
# else
  int hzz = 1;
# endif
#endif

  if (getrusage(RUSAGE_SELF, &rus) == -1)
  {
    sendto_one_notice(source_p, &me, ":Getruseage error: %s",
                      strerror(errno));
    return;
  }

  secs = rus.ru_utime.tv_sec + rus.ru_stime.tv_sec;

  if (secs == 0)
    secs = 1;

  rup = (CurrentTime - me.connection->since) * hzz;

  if (rup == 0)
    rup = 1;

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "R :CPU Secs %d:%02d User %d:%02d System %d:%02d",
                     (int)(secs/60), (int)(secs%60),
                     (int)(rus.ru_utime.tv_sec/60), (int)(rus.ru_utime.tv_sec%60),
                     (int)(rus.ru_stime.tv_sec/60), (int)(rus.ru_stime.tv_sec%60));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "R :RSS %ld ShMem %ld Data %ld Stack %ld",
                     rus.ru_maxrss,
                     (rus.ru_ixrss / rup), (rus.ru_idrss / rup),
                     (rus.ru_isrss / rup));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "R :Swaps %d Reclaims %d Faults %d",
                     (int)rus.ru_nswap,
                     (int)rus.ru_minflt, (int)rus.ru_majflt);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "R :Block in %d out %d",
                     (int)rus.ru_inblock,
                     (int)rus.ru_oublock);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "R :Msg Rcv %d Send %d",
                     (int)rus.ru_msgrcv,
                     (int)rus.ru_msgsnd);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "R :Signals %d Context Vol. %d Invol %d",
                     (int)rus.ru_nsignals,
                     (int)rus.ru_nvcsw, (int)rus.ru_nivcsw);
}

static void
stats_memory(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *gptr = NULL;
  const dlink_node *dlink = NULL;

  unsigned int local_client_conf_count = 0;      /* local client conf links */
  unsigned int users_counted = 0;                /* user structs */

  unsigned int channel_members = 0;
  unsigned int channel_invites = 0;
  unsigned int channel_bans = 0;
  unsigned int channel_except = 0;
  unsigned int channel_invex = 0;

  unsigned int wwu = 0;                  /* whowas users */
  unsigned int class_count = 0;          /* classes */
  unsigned int aways_counted = 0;
  unsigned int number_ips_stored = 0;        /* number of ip addresses hashed */

  uint64_t channel_memory = 0;
  uint64_t channel_ban_memory = 0;
  uint64_t channel_except_memory = 0;
  uint64_t channel_invex_memory = 0;

  unsigned int safelist_count = 0;
  uint64_t safelist_memory = 0;

  uint64_t wwm = 0;               /* whowas array memory used       */
  uint64_t conf_memory = 0;       /* memory used by conf lines      */
  uint64_t mem_ips_stored = 0;        /* memory used by ip address hash */

  uint64_t total_channel_memory = 0;
  uint64_t totww = 0;

  unsigned int local_client_count  = 0;
  unsigned int remote_client_count = 0;

  uint64_t local_client_memory_used  = 0;
  uint64_t remote_client_memory_used = 0;

  uint64_t total_memory = 0;
  unsigned int topic_count = 0;

  unsigned int watch_list_headers = 0;   /* watchlist headers     */
  unsigned int watch_list_entries = 0;   /* watchlist entries     */
  uint64_t watch_list_memory = 0; /* watchlist memory used */


  DLINK_FOREACH(gptr, global_client_list.head)
  {
    const struct Client *target_p = gptr->data;

    if (MyConnect(target_p))
    {
      ++local_client_count;
      local_client_conf_count += dlink_list_length(&target_p->connection->confs);
      watch_list_entries += dlink_list_length(&target_p->connection->watches);
    }
    else
      ++remote_client_count;

    if (IsClient(target_p))
    {
      ++users_counted;

      if (target_p->away[0])
        ++aways_counted;
    }
  }

  /* Count up all channels, ban lists, except lists, Invex lists */
  channel_memory = dlink_list_length(&channel_list) *
                   sizeof(struct Channel);
  DLINK_FOREACH(gptr, channel_list.head)
  {
    const struct Ban *actualBan;
    const struct Channel *chptr = gptr->data;

    channel_members += dlink_list_length(&chptr->members);
    channel_invites += dlink_list_length(&chptr->invites);

    if (chptr->topic[0])
      ++topic_count;

    channel_bans += dlink_list_length(&chptr->banlist);
    channel_ban_memory += dlink_list_length(&chptr->banlist) * sizeof(struct Ban);

    DLINK_FOREACH(dlink, chptr->banlist.head)
    {
      actualBan = dlink->data;
      assert(actualBan->who);

      channel_ban_memory += actualBan->len + 1;
      channel_ban_memory += strlen(actualBan->who) + 1;
    }

    channel_except += dlink_list_length(&chptr->exceptlist);
    channel_except_memory += dlink_list_length(&chptr->exceptlist) * sizeof(struct Ban);

    DLINK_FOREACH(dlink, chptr->exceptlist.head)
    {
      actualBan = dlink->data;
      assert(actualBan->who);

      channel_except_memory += actualBan->len + 1;
      channel_except_memory += strlen(actualBan->who) + 1;
    }

    channel_invex += dlink_list_length(&chptr->invexlist);
    channel_invex_memory += dlink_list_length(&chptr->invexlist) * sizeof(struct Ban);

    DLINK_FOREACH(dlink, chptr->invexlist.head)
    {
      actualBan = dlink->data;
      assert(actualBan->who);

      channel_invex_memory += actualBan->len + 1;
      channel_invex_memory += strlen(actualBan->who) + 1;
    }
  }

  if ((safelist_count = dlink_list_length(&listing_client_list)))
  {
    safelist_memory = safelist_count * sizeof(struct ListTask);
    DLINK_FOREACH(gptr, listing_client_list.head)
    {
      const struct Client *acptr = gptr->data;

      DLINK_FOREACH(dlink, acptr->connection->list_task->show_mask.head)
        safelist_memory += strlen(dlink->data);

      DLINK_FOREACH(dlink, acptr->connection->list_task->hide_mask.head)
        safelist_memory += strlen(dlink->data);
    }
  }

#if 0
  /* XXX THIS has to be fixed !!!! -db */
  /* count up all config items */
  DLINK_FOREACH(dlink, ConfigItemList.head)
  {
      aconf = dlink->data;
      conf_memory += aconf->host ? strlen(aconf->host)+1 : 0;
      conf_memory += aconf->passwd ? strlen(aconf->passwd)+1 : 0;
      conf_memory += aconf->name ? strlen(aconf->name)+1 : 0;
      conf_memory += sizeof(struct AccessItem);
  }
#endif
  /* count up all classes */
  class_count = dlink_list_length(class_get_list());

  whowas_count_memory(&wwu, &wwm);
  watch_count_memory(&watch_list_headers, &watch_list_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :WATCH headers %u(%llu) entries %d(%u)",
                     watch_list_headers,
                     watch_list_memory, watch_list_entries,
                     watch_list_entries * sizeof(dlink_node) * 2);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Clients %u(%u)",
                     users_counted,
                     (users_counted * sizeof(struct Client)));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :User aways %u", aways_counted);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Attached confs %u(%llu)",
                     local_client_conf_count,
                     (unsigned long long)(local_client_conf_count * sizeof(dlink_node)));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Resv channels %u(%lu) nicks %u(%lu)",
                     dlink_list_length(&cresv_items),
                     dlink_list_length(&cresv_items) * sizeof(struct MaskItem),
                     dlink_list_length(&nresv_items),
                     dlink_list_length(&nresv_items) * sizeof(struct MaskItem));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Classes %u(%llu)",
                     class_count, (unsigned long long)(class_count * sizeof(struct ClassItem)));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Channels %u(%llu) Topics %u(%u)",
                     dlink_list_length(&channel_list),
                     channel_memory, topic_count, topic_count *
                     (TOPICLEN + 1 + USERHOST_REPLYLEN));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Bans %u(%llu)",
                     channel_bans, channel_ban_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Exceptions %u(%llu)",
                     channel_except, channel_except_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Invex %u(%llu)",
                     channel_invex, channel_invex_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Channel members %u(%llu) invites %u(%llu)",
                     channel_members,
                     (unsigned long long)(channel_members * sizeof(struct Membership)),
                     channel_invites, (unsigned long long)channel_invites * sizeof(dlink_node) * 2);

  total_channel_memory = channel_memory + channel_ban_memory +
                         channel_members * sizeof(struct Membership) +
                         (channel_invites * sizeof(dlink_node)*2);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Safelist %u(%llu)",
                     safelist_count, safelist_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Whowas users %u(%llu)",
                     wwu, (unsigned long long)(wwu * sizeof(struct Client)));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Whowas array %u(%llu)",
                     NICKNAMEHISTORYLENGTH, wwm);

  totww = wwu * sizeof(struct Client) + wwm;

  motd_memory_count(source_p);
  ipcache_get_stats(&number_ips_stored, &mem_ips_stored);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :iphash %u(%llu)",
                     number_ips_stored, mem_ips_stored);

  total_memory = totww + total_channel_memory + conf_memory + class_count *
                 sizeof(struct ClassItem);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Total: whowas %llu channel %llu conf %llu",
                     totww, total_channel_memory, conf_memory);

  local_client_memory_used = local_client_count*(sizeof(struct Client) + sizeof(struct Connection));
  total_memory += local_client_memory_used;
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Local client Memory in use: %u(%llu)",
                     local_client_count, local_client_memory_used);

  remote_client_memory_used = remote_client_count * sizeof(struct Client);
  total_memory += remote_client_memory_used;
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :Remote client Memory in use: %u(%llu)",
                     remote_client_count, remote_client_memory_used);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "z :TOTAL: %llu",
                     me.name, RPL_STATSDEBUG, source_p->name,
                     total_memory);
}

static void
stats_dns_servers(struct Client *source_p, int parc, char *parv[])
{
  report_dns_servers(source_p);
}

static void
stats_connect(struct Client *source_p, int parc, char *parv[])
{
  report_confitem_types(source_p, CONF_SERVER);
}

/* stats_deny()
 *
 * input	- client to report to
 * output	- none
 * side effects - client is given dline list.
 */
static void
stats_deny(struct Client *source_p, int parc, char *parv[])
{
  const struct MaskItem *conf = NULL;
  const dlink_node *node = NULL;

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_DLINE)
        continue;

      conf = arec->conf;

      /* Don't report a tdline as a dline */
      if (conf->until)
        continue;

      sendto_one_numeric(source_p, &me, RPL_STATSDLINE, 'D', conf->host, conf->reason);
    }
  }
}

/* stats_tdeny()
 *
 * input        - client to report to
 * output       - none
 * side effects - client is given dline list.
 */
static void
stats_tdeny(struct Client *source_p, int parc, char *parv[])
{
  const struct MaskItem *conf = NULL;
  const dlink_node *node = NULL;

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_DLINE)
        continue;

      conf = arec->conf;

      /* Don't report a permanent dline as a tdline */
      if (!conf->until)
        continue;

      sendto_one_numeric(source_p, &me, RPL_STATSDLINE, 'd', conf->host, conf->reason);
    }
  }
}

/* stats_exempt()
 *
 * input        - client to report to
 * output       - none
 * side effects - client is given list of exempt blocks
 */
static void
stats_exempt(struct Client *source_p, int parc, char *parv[])
{
  const struct MaskItem *conf = NULL;
  const dlink_node *node = NULL;

  if (ConfigGeneral.stats_e_disabled)
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
    return;
  }

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_EXEMPT)
        continue;

      conf = arec->conf;
      sendto_one_numeric(source_p, &me, RPL_STATSDLINE, 'e', conf->host, "");
    }
  }
}

static void
stats_events(struct Client *source_p, int parc, char *parv[])
{
  show_events(source_p);
}

/* stats_pending_glines()
 *
 * input        - client pointer
 * output       - none
 * side effects - client is shown list of pending glines
 */
static void
stats_pending_glines(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *node = NULL;
  const struct gline_pending *glp_ptr = NULL;
  char timebuffer[MAX_DATE_STRING] = "";
  struct tm *tmptr = NULL;

  if (!ConfigGeneral.glines)
  {
    sendto_one_notice(source_p, &me, ":This server does not support G-Lines");
    return;
  }

  if (dlink_list_length(&pending_glines[GLINE_PENDING_ADD_TYPE]))
    sendto_one_notice(source_p, &me, ":Pending G-lines");

  DLINK_FOREACH(node, pending_glines[GLINE_PENDING_ADD_TYPE].head)
  {
    glp_ptr = node->data;
    tmptr   = localtime(&glp_ptr->vote_1.time_request);
    strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);

    sendto_one_notice(source_p, &me, ":1) %s!%s@%s on %s requested gline at %s for %s@%s [%s]",
                      glp_ptr->vote_1.oper_nick,
                      glp_ptr->vote_1.oper_user, glp_ptr->vote_1.oper_host,
                      glp_ptr->vote_1.oper_server, timebuffer,
                      glp_ptr->user, glp_ptr->host, glp_ptr->vote_1.reason);

    if (glp_ptr->vote_2.oper_nick[0])
    {
      tmptr = localtime(&glp_ptr->vote_2.time_request);
      strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);

      sendto_one_notice(source_p, &me, ":2) %s!%s@%s on %s requested gline at %s for %s@%s [%s]",
                        glp_ptr->vote_2.oper_nick,
                        glp_ptr->vote_2.oper_user, glp_ptr->vote_2.oper_host,
                        glp_ptr->vote_2.oper_server, timebuffer,
                        glp_ptr->user, glp_ptr->host, glp_ptr->vote_2.reason);
    }
  }

  sendto_one_notice(source_p, &me, ":End of Pending G-lines");

  if (dlink_list_length(&pending_glines[GLINE_PENDING_DEL_TYPE]))
    sendto_one_notice(source_p, &me, ":Pending UNG-lines");

  DLINK_FOREACH(node, pending_glines[GLINE_PENDING_DEL_TYPE].head)
  {
    glp_ptr = node->data;
    tmptr   = localtime(&glp_ptr->vote_1.time_request);
    strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);

    sendto_one_notice(source_p, &me, ":1) %s!%s@%s on %s requested ungline at %s for %s@%s [%s]",
                      glp_ptr->vote_1.oper_nick,
                      glp_ptr->vote_1.oper_user, glp_ptr->vote_1.oper_host,
                      glp_ptr->vote_1.oper_server, timebuffer,
                      glp_ptr->user, glp_ptr->host, glp_ptr->vote_1.reason);

    if (glp_ptr->vote_2.oper_nick[0])
    {
      tmptr = localtime(&glp_ptr->vote_2.time_request);
      strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);

      sendto_one_notice(source_p, &me, ":2) %s!%s@%s on %s requested ungline at %s for %s@%s [%s]",
                        glp_ptr->vote_2.oper_nick,
                        glp_ptr->vote_2.oper_user, glp_ptr->vote_2.oper_host,
                        glp_ptr->vote_2.oper_server, timebuffer,
                        glp_ptr->user, glp_ptr->host, glp_ptr->vote_2.reason);

    }
  }

  sendto_one_notice(source_p, &me, ":End of Pending UNG-lines");
}

/* stats_glines()
 *
 * input        - client pointer
 * output       - none
 * side effects - client is shown list of glines
 */
static void
stats_glines(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *node = NULL;

  if (!ConfigGeneral.glines)
  {
    sendto_one_notice(source_p, &me, ":This server does not support G-Lines");
    return;
  }

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type == CONF_GLINE)
      {
        const struct MaskItem *conf = arec->conf;

        sendto_one_numeric(source_p, &me, RPL_STATSKLINE, 'G',
                           conf->host ? conf->host : "*",
                           conf->user ? conf->user : "*",
                           conf->reason);

      }
    }
  }
}

static void
stats_hubleaf(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *node = NULL, *dptr = NULL;

  DLINK_FOREACH(node, server_items.head)
  {
    const struct MaskItem *conf = node->data;

    DLINK_FOREACH(dptr, conf->hub_list.head)
      sendto_one_numeric(source_p, &me, RPL_STATSHLINE, 'H', dptr->data, conf->name, 0, "*");
  }

  DLINK_FOREACH(node, server_items.head)
  {
    const struct MaskItem *conf = node->data;

    DLINK_FOREACH(dptr, conf->leaf_list.head)
      sendto_one_numeric(source_p, &me, RPL_STATSLLINE, 'L', dptr->data, conf->name, 0, "*");
  }
}

/*
 * show_iline_prefix()
 *
 * inputs       - pointer to struct Client requesting output
 *              - pointer to struct MaskItem
 *              - name to which iline prefix will be prefixed to
 * output       - pointer to static string with prefixes listed in ascii form
 * side effects - NONE
 */
static const char *
show_iline_prefix(const struct Client *sptr, const struct MaskItem *conf)
{
  static char prefix_of_host[USERLEN + 15];
  char *prefix_ptr = prefix_of_host;

  if (IsConfWebIRC(conf))
    *prefix_ptr++ = '<';
  if (IsNoTilde(conf))
    *prefix_ptr++ = '-';
  if (IsNeedIdentd(conf))
    *prefix_ptr++ = '+';
  if (!IsNeedPassword(conf))
    *prefix_ptr++ = '&';
  if (IsConfExemptResv(conf))
    *prefix_ptr++ = '$';
  if (IsConfDoSpoofIp(conf))
    *prefix_ptr++ = '=';
  if (MyOper(sptr) && IsConfExemptKline(conf))
    *prefix_ptr++ = '^';
  if (MyOper(sptr) && IsConfExemptGline(conf))
    *prefix_ptr++ = '_';
  if (MyOper(sptr) && IsConfExemptLimits(conf))
    *prefix_ptr++ = '>';
  if (IsConfCanFlood(conf))
    *prefix_ptr++ = '|';

  strlcpy(prefix_ptr, conf->user, USERLEN+1);

  return prefix_of_host;
}

static void
report_auth(struct Client *source_p, int parc, char *parv[])
{
  const struct MaskItem *conf = NULL;
  const dlink_node *node = NULL;

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_CLIENT)
        continue;

      conf = arec->conf;

      if (!MyOper(source_p) && IsConfDoSpoofIp(conf))
        continue;

      /* We are doing a partial list, based on what matches the u@h of the
       * sender, so prepare the strings for comparing --fl_
       */
      sendto_one_numeric(source_p, &me, RPL_STATSILINE, 'I',
                         conf->name == NULL ? "*" : conf->name,
                         show_iline_prefix(source_p, conf),
                         conf->host, conf->port,
                         conf->class->name);
    }
  }
}

static void
stats_auth(struct Client *source_p, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_i_oper_only == 2 && !HasUMode(source_p, UMODE_OPER))
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);

  /* If unopered, only return matching auth blocks */
  else if (ConfigGeneral.stats_i_oper_only == 1 && !HasUMode(source_p, UMODE_OPER))
  {
    const struct MaskItem *conf = NULL;

    if (MyConnect(source_p))
      conf = find_conf_by_address(source_p->host,
                                  &source_p->connection->ip, CONF_CLIENT,
                                  source_p->connection->aftype,
                                  source_p->username,
                                  source_p->connection->password, 1);
    else
      conf = find_conf_by_address(source_p->host, NULL, CONF_CLIENT, 0,
                                  source_p->username, NULL, 1);

    if (conf == NULL)
      return;

    sendto_one_numeric(source_p, &me, RPL_STATSILINE,
                       'I', "*", show_iline_prefix(source_p, conf),
                       conf->host, conf->port,
                       conf->class->name);
  }
  else  /* They are opered, or allowed to see all auth blocks */
    report_auth(source_p, 0, NULL);
}

/* report_Klines()
 * Inputs: Client to report to,
 *         type(==0 for perm, !=0 for temporary)
 *         mask
 * Output: None
 * Side effects: Reports configured K(or k)-lines to source_p.
 */
static void
report_Klines(struct Client *source_p, int tkline)
{
  const struct MaskItem *conf = NULL;
  const dlink_node *node = NULL;
  char c = '\0';

  if (tkline)
    c = 'k';
  else
    c = 'K';

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_KLINE)
        continue;

      conf = arec->conf;

      if ((!tkline && conf->until) ||
          (tkline && !conf->until))
        continue;

      sendto_one_numeric(source_p, &me, RPL_STATSKLINE, c, conf->host, conf->user,
                         conf->reason);
    }
  }
}

static void
stats_tklines(struct Client *source_p, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_k_oper_only == 2 && !HasUMode(source_p, UMODE_OPER))
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);

  /* If unopered, only return matching klines */
  else if (ConfigGeneral.stats_k_oper_only == 1 && !HasUMode(source_p, UMODE_OPER))
  {
    const struct MaskItem *conf = NULL;

    if (MyConnect(source_p))
      conf = find_conf_by_address(source_p->host,
                                  &source_p->connection->ip, CONF_KLINE,
                                  source_p->connection->aftype,
                                  source_p->username, NULL, 1);
    else
      conf = find_conf_by_address(source_p->host, NULL, CONF_KLINE, 0,
                                  source_p->username, NULL, 1);

    if (!conf)
      return;

    /* Don't report a permanent kline as a tkline */
    if (!conf->until)
      return;

    sendto_one_numeric(source_p, &me, RPL_STATSKLINE, 'k',
                       conf->host, conf->user, conf->reason);
  }
  else  /* They are opered, or allowed to see all klines */
    report_Klines(source_p, 1);
}

static void
stats_klines(struct Client *source_p, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_k_oper_only == 2 && !HasUMode(source_p, UMODE_OPER))
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);

  /* If unopered, only return matching klines */
  else if (ConfigGeneral.stats_k_oper_only == 1 && !HasUMode(source_p, UMODE_OPER))
  {
    const struct MaskItem *conf = NULL;

    /* Search for a kline */
    if (MyConnect(source_p))
      conf = find_conf_by_address(source_p->host,
                                  &source_p->connection->ip, CONF_KLINE,
                                  source_p->connection->aftype,
                                  source_p->username, NULL, 0);
    else
      conf = find_conf_by_address(source_p->host, NULL, CONF_KLINE, 0,
                                  source_p->username, NULL, 0);

    if (!conf)
      return;

    /* Don't report a tkline as a kline */
    if (conf->until)
      return;

    sendto_one_numeric(source_p, &me, RPL_STATSKLINE, 'K',
                       conf->host, conf->user, conf->reason);
  }
  else  /* They are opered, or allowed to see all klines */
    report_Klines(source_p, 0);
}

static void
stats_messages(struct Client *source_p, int parc, char *parv[])
{
  if (!HasUMode(source_p, UMODE_OPER) && ConfigGeneral.stats_m_oper_only)
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
  else
    report_messages(source_p);
}

static void
stats_oper(struct Client *source_p, int parc, char *parv[])
{
  if (!HasUMode(source_p, UMODE_OPER) && ConfigGeneral.stats_o_oper_only)
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
  else
    report_confitem_types(source_p, CONF_OPER);
}

/* stats_operedup()
 *
 * input	- client pointer
 * output	- none
 * side effects - client is shown a list of active opers
 */
static void
stats_operedup(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *node = NULL;
  unsigned int opercount = 0;
  char buf[IRCD_BUFSIZE] = "";

  DLINK_FOREACH(node, oper_list.head)
  {
    const struct Client *target_p = node->data;

    if (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER))
      continue;

    if (HasUMode(source_p, UMODE_OPER) || !HasUMode(target_p, UMODE_HIDEIDLE))
      snprintf(buf, sizeof(buf), "%u", idle_time_get(source_p, target_p));
    else
      strlcpy(buf, "n/a", sizeof(buf));

    if (MyClient(source_p) && HasUMode(source_p, UMODE_OPER))
      sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                         "p :[%c][%s] %s (%s@%s) Idle: %s",
                         HasUMode(target_p, UMODE_ADMIN) ? 'A' : 'O',
                         oper_privs_as_string(target_p->connection->operflags),
                         target_p->name, target_p->username, target_p->host, buf);
    else
      sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                         "p :[%c] %s (%s@%s) Idle: %s",
                         HasUMode(target_p, UMODE_ADMIN) ? 'A' : 'O',
                         target_p->name, target_p->username, target_p->host, buf);
    ++opercount;
  }

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "p :%u OPER(s)", opercount);
}

static void
stats_ports(struct Client *source_p, int parc, char *parv[])
{
  if (!HasUMode(source_p, UMODE_OPER) && ConfigGeneral.stats_P_oper_only)
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
  else
    show_ports(source_p);
}

static void
stats_resv(struct Client *source_p, int parc, char *parv[])
{
  report_resv(source_p);
}

static void
stats_service(struct Client *source_p, int parc, char *parv[])
{
  report_confitem_types(source_p, CONF_SERVICE);
}

static void
stats_tstats(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *node = NULL;
  struct ServerStatistics tmp;
  struct ServerStatistics *sp = &tmp;

  memcpy(sp, &ServerStats, sizeof(struct ServerStatistics));

  /*
   * must use the += operator. is_sv is not the number of currently
   * active server connections. Note the incrementation in
   * s_bsd.c:close_connection.
   */
  sp->is_sv += dlink_list_length(&local_server_list);

  DLINK_FOREACH(node, local_server_list.head)
  {
    const struct Client *target_p = node->data;

    sp->is_sbs += target_p->connection->send.bytes;
    sp->is_sbr += target_p->connection->recv.bytes;
    sp->is_sti += CurrentTime - target_p->connection->firsttime;
  }

  sp->is_cl += dlink_list_length(&local_client_list);

  DLINK_FOREACH(node, local_client_list.head)
  {
    const struct Client *target_p = node->data;

    sp->is_cbs += target_p->connection->send.bytes;
    sp->is_cbr += target_p->connection->recv.bytes;
    sp->is_cti += CurrentTime - target_p->connection->firsttime;
  }

  sp->is_ni += dlink_list_length(&unknown_list);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :accepts %u refused %u",
                     sp->is_ac, sp->is_ref);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :unknown commands %u prefixes %u",
                     sp->is_unco, sp->is_unpf);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :nick collisions %u unknown closes %u",
                     sp->is_kill, sp->is_ni);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :wrong direction %u empty %u",
                     sp->is_wrdi, sp->is_empt);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :numerics seen %u",
                     sp->is_num);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :auth successes %u fails %u",
                     sp->is_asuc, sp->is_abad);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :Client Server");
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :connected %u %u",
                     (unsigned int)sp->is_cl,
                     (unsigned int)sp->is_sv);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :bytes sent %llu %llu",
                     sp->is_cbs, sp->is_sbs);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :bytes recv %llu %llu",
                     sp->is_cbr, sp->is_sbr);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "t :time connected %u %u",
                     (unsigned int)sp->is_cti,
                     (unsigned int)sp->is_sti);
}

static void
stats_uptime(struct Client *source_p, int parc, char *parv[])
{
  if (!HasUMode(source_p, UMODE_OPER) && ConfigGeneral.stats_u_oper_only)
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
  else
  {
    time_t now = CurrentTime - me.connection->since;

    sendto_one_numeric(source_p, &me, RPL_STATSUPTIME, now / 86400,
                       (now / 3600) % 24, (now / 60) % 60, now % 60);

    if (!ConfigServerHide.disable_remote_commands || HasUMode(source_p, UMODE_OPER))
       sendto_one_numeric(source_p, &me, RPL_STATSCONN, Count.max_loc_con,
                          Count.max_loc_cli, Count.totalrestartcount);
  }
}

static void
stats_shared(struct Client *source_p, int parc, char *parv[])
{
  report_confitem_types(source_p, CONF_ULINE);
}

/* stats_servers()
 *
 * input	- client pointer
 * output	- none
 * side effects - client is shown lists of who connected servers
 */
static void
stats_servers(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *node = NULL;

  DLINK_FOREACH(node, local_server_list.head)
  {
    const struct Client *target_p = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                       "v :%s (%s!%s@%s) Idle: %d",
                       target_p->name,
                       (target_p->serv->by[0] ? target_p->serv->by : "Remote."),
                       "*", "*", (int)(CurrentTime - target_p->connection->lasttime));
  }

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "v :%u Server(s)",
                     dlink_list_length(&local_server_list));
}

static void
stats_gecos(struct Client *source_p, int parc, char *parv[])
{
  report_confitem_types(source_p, CONF_XLINE);
}

static void
stats_class(struct Client *source_p, int parc, char *parv[])
{
  const dlink_node *node = NULL;

  DLINK_FOREACH(node, class_get_list()->head)
  {
    const struct ClassItem *class = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSYLINE, 'Y',
                       class->name, class->ping_freq,
                       class->con_freq,
                       class->max_total, class->max_sendq,
                       class->max_recvq,
                       class->ref_count,
                       class->number_per_cidr, class->cidr_bitlen_ipv4,
                       class->number_per_cidr, class->cidr_bitlen_ipv6,
                       class->active ? "active" : "disabled");
  }
}

static void
stats_servlinks(struct Client *source_p, int parc, char *parv[])
{
  uint64_t sendB = 0, recvB = 0;
  time_t uptime = 0;
  dlink_node *node = NULL;

  if (ConfigServerHide.flatten_links && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
    return;
  }

  DLINK_FOREACH(node, local_server_list.head)
  {
    struct Client *target_p = node->data;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(source_p, UMODE_OPER))
        continue;

    sendB += target_p->connection->send.bytes;
    recvB += target_p->connection->recv.bytes;

    /* ":%s 211 %s %s %u %u %llu %u %llu :%u %u %s" */
    sendto_one_numeric(source_p, &me, RPL_STATSLINKINFO,
               get_client_name(target_p, HasUMode(source_p, UMODE_ADMIN) ? SHOW_IP : MASK_IP),
               dbuf_length(&target_p->connection->buf_sendq),
               target_p->connection->send.messages,
               target_p->connection->send.bytes >> 10,
               target_p->connection->recv.messages,
               target_p->connection->recv.bytes >> 10,
               (unsigned int)(CurrentTime - target_p->connection->firsttime),
               (CurrentTime > target_p->connection->since) ? (unsigned int)(CurrentTime - target_p->connection->since) : 0,
               HasUMode(source_p, UMODE_OPER) ? show_capabilities(target_p) : "TS");
  }

  sendB >>= 10;
  recvB >>= 10;

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT, "? :%u total server(s)",
                     dlink_list_length(&local_server_list));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT, "? :Sent total: %7.2f %s",
                     _GMKv(sendB), _GMKs(sendB));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT, "? :Recv total: %7.2f %s",
                     _GMKv(recvB), _GMKs(recvB));

  uptime = (CurrentTime - me.connection->since);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "? :Server send: %7.2f %s (%4.1f K/s)",
                     _GMKv((me.connection->send.bytes>>10)),
                     _GMKs((me.connection->send.bytes>>10)),
                     (float)((float)((me.connection->send.bytes) >> 10) /
                     (float)uptime));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "? :Server recv: %7.2f %s (%4.1f K/s)",
                     _GMKv((me.connection->recv.bytes>>10)),
                     _GMKs((me.connection->recv.bytes>>10)),
                     (float)((float)((me.connection->recv.bytes) >> 10) /
                     (float)uptime));
}

/* parse_stats_args()
 *
 * inputs       - arg count
 *              - args
 *              - doall flag
 *              - wild card or not
 * output       - pointer to name to use
 * side effects -
 * common parse routine for m_stats args
 *
 */
static const char *
parse_stats_args(struct Client *source_p, int parc, char *parv[], int *doall, int *wilds)
{
  if (parc > 2)
  {
    const char *name = parv[2];

    if (!irccmp(name, ID_or_name(&me, source_p)))
      *doall = 2;
    else if (!match(name, ID_or_name(&me, source_p)))
      *doall = 1;

    *wilds = has_wildcards(name);

    return name;
  }

  return NULL;
}

static void
stats_L_list(struct Client *source_p, const char *name, int doall, int wilds,
             dlink_list *list, const char statchar)
{
  dlink_node *node = NULL;

  /*
   * Send info about connections which match, or all if the
   * mask matches from. Only restrictions are on those who
   * are invisible not being visible to 'foreigners' who use
   * a wild card based search to list it.
   */
  DLINK_FOREACH(node, list->head)
  {
    struct Client *target_p = node->data;

    if (HasUMode(target_p, UMODE_INVISIBLE) && (doall || wilds) &&
        !(MyConnect(source_p) && HasUMode(source_p, UMODE_OPER)) &&
        !HasUMode(target_p, UMODE_OPER) && (target_p != source_p))
      continue;

    if (!doall && wilds && match(name, target_p->name))
      continue;

    if (!(doall || wilds) && irccmp(name, target_p->name))
      continue;

    /*
     * This basically shows ips for our opers if it's not a server/admin, or
     * it's one of our admins.
     */
    if (MyClient(source_p) && HasUMode(source_p, UMODE_OPER) &&
        (HasUMode(source_p, UMODE_ADMIN) ||
        (!IsServer(target_p) && !HasUMode(target_p, UMODE_ADMIN) &&
        !IsHandshake(target_p) && !IsConnecting(target_p))))
    {
      sendto_one_numeric(source_p, &me, RPL_STATSLINKINFO,
                 (IsUpper(statchar)) ?
                 get_client_name(target_p, SHOW_IP) :
                 get_client_name(target_p, HIDE_IP),
                 dbuf_length(&target_p->connection->buf_sendq),
                 target_p->connection->send.messages,
                 target_p->connection->send.bytes>>10,
                 target_p->connection->recv.messages,
                 target_p->connection->recv.bytes>>10,
                 (unsigned int)(CurrentTime - target_p->connection->firsttime),
                 (CurrentTime > target_p->connection->since) ? (unsigned int)(CurrentTime - target_p->connection->since) : 0,
                 IsServer(target_p) ? show_capabilities(target_p) : "-");
    }
    else
    {
      /* If it's a server, mask the real IP */
      if (IsServer(target_p) || IsHandshake(target_p) || IsConnecting(target_p))
        sendto_one_numeric(source_p, &me, RPL_STATSLINKINFO,
                   get_client_name(target_p, MASK_IP),
                   dbuf_length(&target_p->connection->buf_sendq),
                   target_p->connection->send.messages,
                   target_p->connection->send.bytes>>10,
                   target_p->connection->recv.messages,
                   target_p->connection->recv.bytes>>10,
                   (unsigned int)(CurrentTime - target_p->connection->firsttime),
                   (CurrentTime > target_p->connection->since) ? (unsigned int)(CurrentTime - target_p->connection->since):0,
                   IsServer(target_p) ? show_capabilities(target_p) : "-");
      else /* show the real IP */
        sendto_one_numeric(source_p, &me, RPL_STATSLINKINFO,
                   (IsUpper(statchar)) ?
                   get_client_name(target_p, SHOW_IP) :
                   get_client_name(target_p, HIDE_IP),
                   dbuf_length(&target_p->connection->buf_sendq),
                   target_p->connection->send.messages,
                   target_p->connection->send.bytes>>10,
                   target_p->connection->recv.messages,
                   target_p->connection->recv.bytes>>10,
                   (unsigned int)(CurrentTime - target_p->connection->firsttime),
                   (CurrentTime > target_p->connection->since) ? (unsigned int)(CurrentTime - target_p->connection->since):0,
                   IsServer(target_p) ? show_capabilities(target_p) : "-");
    }
  }
}

/*
 * stats_L
 *
 * inputs       - pointer to client to report to
 *              - doall flag
 *              - wild card or not
 * output       - NONE
 * side effects -
 */
static void
stats_L(struct Client *source_p, const char *name, int doall,
        int wilds, const char statchar)
{
  stats_L_list(source_p, name, doall, wilds, &unknown_list, statchar);
  stats_L_list(source_p, name, doall, wilds, &local_client_list, statchar);
  stats_L_list(source_p, name, doall, wilds, &local_server_list, statchar);
}

static void
stats_ltrace(struct Client *source_p, int parc, char *parv[])
{
  int doall = 0;
  int wilds = 0;
  const char *name = NULL;

  if ((name = parse_stats_args(source_p, parc, parv, &doall, &wilds)))
  {
    const char statchar = *parv[1];
    stats_L(source_p, name, doall, wilds, statchar);
  }
  else
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "STATS");
}

static const struct StatsStruct
{
  const unsigned char letter;
  void (*handler)(struct Client *, int, char *[]);
  const unsigned int need_oper;
  const unsigned int need_admin;
} stats_cmd_table[] = {
  /* letter  function          need_oper need_admin */
  { 'a',     stats_dns_servers,    1,      1 },
  { 'A',     stats_dns_servers,    1,      1 },
  { 'c',     stats_connect,        1,      0 },
  { 'C',     stats_connect,        1,      0 },
  { 'd',     stats_tdeny,          1,      0 },
  { 'D',     stats_deny,           1,      0 },
  { 'e',     stats_exempt,         1,      0 },
  { 'E',     stats_events,         1,      1 },
  { 'f',     fd_dump,              1,      1 },
  { 'F',     fd_dump,              1,      1 },
  { 'g',     stats_pending_glines, 1,      0 },
  { 'G',     stats_glines,         1,      0 },
  { 'h',     stats_hubleaf,        1,      1 },
  { 'H',     stats_hubleaf,        1,      0 },
  { 'i',     stats_auth,           0,      0 },
  { 'I',     stats_auth,           0,      0 },
  { 'k',     stats_tklines,        0,      0 },
  { 'K',     stats_klines,         0,      0 },
  { 'l',     stats_ltrace,         1,      0 },
  { 'L',     stats_ltrace,         1,      0 },
  { 'm',     stats_messages,       0,      0 },
  { 'M',     stats_messages,       0,      0 },
  { 'o',     stats_oper,           0,      0 },
  { 'O',     stats_oper,           0,      0 },
  { 'p',     stats_operedup,       0,      0 },
  { 'P',     stats_ports,          0,      0 },
  { 'q',     stats_resv,           1,      0 },
  { 'Q',     stats_resv,           1,      0 },
  { 'r',     stats_usage,          1,      0 },
  { 'R',     stats_usage,          1,      0 },
  { 's',     stats_service,        1,      0 },
  { 'S',     stats_service,        1,      0 },
  { 't',     stats_tstats,         1,      0 },
  { 'T',     motd_report,          1,      0 },
  { 'u',     stats_uptime,         0,      0 },
  { 'U',     stats_shared,         1,      0 },
  { 'v',     stats_servers,        1,      0 },
  { 'x',     stats_gecos,          1,      0 },
  { 'X',     stats_gecos,          1,      0 },
  { 'y',     stats_class,          1,      0 },
  { 'Y',     stats_class,          1,      0 },
  { 'z',     stats_memory,         1,      0 },
  { '?',     stats_servlinks,      0,      0 },
  { '\0',    NULL,                 0,      0 }
};

static void
do_stats(struct Client *source_p, int parc, char *parv[])
{
  const char statchar = *parv[1];

  if (statchar == '\0')
  {
    sendto_one_numeric(source_p, &me, RPL_ENDOFSTATS, '*');
    return;
  }

  for (const struct StatsStruct *tab = stats_cmd_table; tab->handler; ++tab)
  {
    if (tab->letter == statchar)
    {
      /* The stats table says what privs are needed, so check --fl_ */
      if ((tab->need_admin && !HasUMode(source_p, UMODE_ADMIN)) ||
          (tab->need_oper && !HasUMode(source_p, UMODE_OPER)))
      {
        sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
        break;
      }

      sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                           "STATS %c requested by %s (%s@%s) [%s]",
                           statchar, source_p->name, source_p->username,
                           source_p->host, source_p->servptr->name);
      tab->handler(source_p, parc, parv);
      break;
    }
  }

  sendto_one_numeric(source_p, &me, RPL_ENDOFSTATS, statchar);
}

/*
 * m_stats()
 *      parv[0] = command
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L
 */
static int
m_stats(struct Client *source_p, int parc, char *parv[])
{
  static time_t last_used = 0;

  /* Check the user is actually allowed to do /stats, and isn't flooding */
  if ((last_used + ConfigGeneral.pace_wait) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "STATS");
    return 0;
  }

  last_used = CurrentTime;

  /* Is the stats meant for us? */
  if (!ConfigServerHide.disable_remote_commands)
    if (hunt_server(source_p, ":%s STATS %s :%s", 2, parc, parv) != HUNTED_ISME)
      return 0;

  do_stats(source_p, parc, parv);
  return 0;
}

/*
 * ms_stats()
 *      parv[0] = command
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L, or target
 */
static int
ms_stats(struct Client *source_p, int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s STATS %s :%s", 2, parc, parv) != HUNTED_ISME)
     return 0;

  do_stats(source_p, parc, parv);
  return 0;
}

static struct Message stats_msgtab =
{
  "STATS", NULL, 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_stats, ms_stats, m_ignore, ms_stats, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&stats_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&stats_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};

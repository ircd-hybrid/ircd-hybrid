/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_stats.c: Sends the user statistics or config information.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"	 /* dlink_node/dlink_list */
#include "client.h"      /* Client */
#include "irc_string.h"  
#include "ircd.h"        /* me */
#include "listener.h"    /* show_ports */
#include "s_gline.h"
#include "conf.h"
#include "conf_class.h"
#include "hostmask.h"
#include "numeric.h"     /* ERR_xxx */
#include "send.h"        /* sendto_one */
#include "fdlist.h"      /* PF and friends */
#include "s_bsd.h"       /* highest_fd */
#include "s_misc.h"      /* serv_info */
#include "s_serv.h"      /* hunt_server */
#include "s_user.h"      /* show_opers */
#include "event.h"	 /* events */
#include "dbuf.h"
#include "hook.h"
#include "parse.h"
#include "modules.h"
#include "resv.h"  /* report_resv */
#include "whowas.h"
#include "watch.h"
#include "irc_res.h"


const char *from, *to;

/*
 * This is part of the STATS replies. There is no offical numeric for this
 * since this isnt an official command, in much the same way as HASH isnt.
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
    sendto_one(source_p, ":%s NOTICE %s :Getruseage error: %s",
               me.name, source_p->name, strerror(errno));
    return;
  }

  secs = rus.ru_utime.tv_sec + rus.ru_stime.tv_sec;

  if (secs == 0)
    secs = 1;

  rup = (CurrentTime - me.localClient->since) * hzz;

  if (rup == 0)
    rup = 1;

  sendto_one(source_p,
             ":%s %d %s R :CPU Secs %d:%d User %d:%d System %d:%d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)(secs/60), (int)(secs%60),
             (int)(rus.ru_utime.tv_sec/60), (int)(rus.ru_utime.tv_sec%60),
             (int)(rus.ru_stime.tv_sec/60), (int)(rus.ru_stime.tv_sec%60));
  sendto_one(source_p, ":%s %d %s R :RSS %ld ShMem %ld Data %ld Stack %ld",
             me.name, RPL_STATSDEBUG, source_p->name, rus.ru_maxrss,
             (rus.ru_ixrss / rup), (rus.ru_idrss / rup),
             (rus.ru_isrss / rup));
  sendto_one(source_p, ":%s %d %s R :Swaps %d Reclaims %d Faults %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_nswap,
             (int)rus.ru_minflt, (int)rus.ru_majflt);
  sendto_one(source_p, ":%s %d %s R :Block in %d out %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_inblock,
             (int)rus.ru_oublock);
  sendto_one(source_p, ":%s %d %s R :Msg Rcv %d Send %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_msgrcv,
             (int)rus.ru_msgsnd);
  sendto_one(source_p, ":%s %d %s R :Signals %d Context Vol. %d Invol %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_nsignals,
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
  unsigned int number_ips_stored;        /* number of ip addresses hashed */

  uint64_t channel_memory = 0;
  uint64_t channel_ban_memory = 0;
  uint64_t channel_except_memory = 0;
  uint64_t channel_invex_memory = 0;

  unsigned int safelist_count = 0;
  uint64_t safelist_memory = 0;

  uint64_t wwm = 0;               /* whowas array memory used       */
  uint64_t conf_memory = 0;       /* memory used by conf lines      */
  uint64_t mem_ips_stored;        /* memory used by ip address hash */

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
    struct Client *target_p = gptr->data;

    if (MyConnect(target_p))
    {
      ++local_client_count;
      local_client_conf_count += dlink_list_length(&target_p->localClient->confs);
      watch_list_entries += dlink_list_length(&target_p->localClient->watches);
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
  channel_memory = dlink_list_length(&global_channel_list) *
                   sizeof(struct Channel);
  DLINK_FOREACH(gptr, global_channel_list.head)
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

      DLINK_FOREACH(dlink, acptr->localClient->list_task->show_mask.head)
        safelist_memory += strlen(dlink->data);

      DLINK_FOREACH(dlink, acptr->localClient->list_task->hide_mask.head)
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

  count_whowas_memory(&wwu, &wwm);
  watch_count_memory(&watch_list_headers, &watch_list_memory);

  sendto_one(source_p, ":%s %d %s z :WATCH headers %u(%llu) entries %d(%u)",
             me.name, RPL_STATSDEBUG, source_p->name, watch_list_headers,
             watch_list_memory, watch_list_entries,
             watch_list_entries * sizeof(dlink_node) * 2);

  sendto_one(source_p, ":%s %d %s z :Clients %u(%u)",
             me.name, RPL_STATSDEBUG, source_p->name, users_counted,
             (users_counted * sizeof(struct Client)));

  sendto_one(source_p, ":%s %d %s z :User aways %u",
             me.name, RPL_STATSDEBUG, source_p->name,
             aways_counted);

  sendto_one(source_p, ":%s %d %s z :Attached confs %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             local_client_conf_count,
             (unsigned long long)(local_client_conf_count * sizeof(dlink_node)));

  sendto_one(source_p, ":%s %d %s z :Resv channels %u(%lu) nicks %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             dlink_list_length(&resv_channel_list),
             dlink_list_length(&resv_channel_list) * sizeof(struct MaskItem),
             dlink_list_length(&nresv_items),
             dlink_list_length(&nresv_items) * sizeof(struct MaskItem));

  sendto_one(source_p, ":%s %d %s z :Classes %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             class_count, (unsigned long long)(class_count * sizeof(struct ClassItem)));

  sendto_one(source_p, ":%s %d %s z :Channels %u(%llu) Topics %u(%u)",
             me.name, RPL_STATSDEBUG, source_p->name,
             dlink_list_length(&global_channel_list),
             channel_memory, topic_count, topic_count *
             (TOPICLEN + 1 + USERHOST_REPLYLEN));

  sendto_one(source_p, ":%s %d %s z :Bans %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             channel_bans, channel_ban_memory);

  sendto_one(source_p, ":%s %d %s z :Exceptions %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             channel_except, channel_except_memory);

  sendto_one(source_p, ":%s %d %s z :Invex %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             channel_invex, channel_invex_memory);

  sendto_one(source_p, ":%s %d %s z :Channel members %u(%llu) invites %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name, channel_members,
             (unsigned long long)(channel_members * sizeof(struct Membership)),
             channel_invites, (unsigned long long)channel_invites *
             sizeof(dlink_node) * 2);

  total_channel_memory = channel_memory + channel_ban_memory +
                         channel_members * sizeof(struct Membership) +
                         (channel_invites * sizeof(dlink_node)*2);

  sendto_one(source_p, ":%s %d %s z :Safelist %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             safelist_count, safelist_memory);

  sendto_one(source_p, ":%s %d %s z :Whowas users %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             wwu, (unsigned long long)(wwu * sizeof(struct Client)));

  sendto_one(source_p, ":%s %d %s z :Whowas array %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             NICKNAMEHISTORYLENGTH, wwm);

  totww = wwu * sizeof(struct Client) + wwm;

  count_ip_hash(&number_ips_stored,&mem_ips_stored);
  sendto_one(source_p, ":%s %d %s z :iphash %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             number_ips_stored, mem_ips_stored);

  total_memory = totww + total_channel_memory + conf_memory + class_count *
                 sizeof(struct ClassItem);
  sendto_one(source_p, ":%s %d %s z :Total: whowas %llu channel %llu conf %llu",
             me.name, RPL_STATSDEBUG, source_p->name, totww,
             total_channel_memory, conf_memory);

  local_client_memory_used = local_client_count*(sizeof(struct Client) + sizeof(struct LocalUser));
  total_memory += local_client_memory_used;
  sendto_one(source_p, ":%s %d %s z :Local client Memory in use: %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name, local_client_count,
             local_client_memory_used);

  remote_client_memory_used = remote_client_count * sizeof(struct Client);
  total_memory += remote_client_memory_used;
  sendto_one(source_p, ":%s %d %s z :Remote client Memory in use: %u(%llu)",
             me.name, RPL_STATSDEBUG, source_p->name, remote_client_count,
             remote_client_memory_used);

  sendto_one(source_p,
             ":%s %d %s z :TOTAL: %llu",
             me.name, RPL_STATSDEBUG, source_p->name,
             total_memory);
}

static void
stats_dns_servers(struct Client *source_p)
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
  struct MaskItem *conf;
  dlink_node *ptr = NULL;
  unsigned int i = 0;


  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type != CONF_DLINE)
        continue;

      conf = arec->conf;

      /* dont report a tdline as a dline */
      if (conf->until)
        continue;

      sendto_one(source_p, RPL_STATSDLINE,
                 from, to, 'D', conf->host, conf->reason);
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
  struct MaskItem *conf = NULL;
  dlink_node *ptr = NULL;
  unsigned int i = 0;


  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type != CONF_DLINE)
        continue;

      conf = arec->conf;

      /* dont report a permanent dline as a tdline */
      if (!conf->until)
        continue;

      sendto_one(source_p, RPL_STATSDLINE,
                 from, to, 'd', conf->host, conf->reason);
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
  struct MaskItem *conf;
  dlink_node *ptr = NULL;
  unsigned int i = 0;

  if (ConfigFileEntry.stats_e_disabled)
  {
    sendto_one(source_p, ERR_NOPRIVILEGES,
               from, to);
    return;
  }

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type != CONF_EXEMPT)
        continue;

      conf = arec->conf;

      sendto_one(source_p, RPL_STATSDLINE,
                 from, to, 'e', conf->host, conf->reason /* XXX */);
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
  const dlink_node *dn_ptr = NULL;
  const struct gline_pending *glp_ptr = NULL;
  char timebuffer[MAX_DATE_STRING] = { '\0' };
  struct tm *tmptr = NULL;

  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :This server does not support G-Lines",
               from, to); 
    return;
  }

  if (dlink_list_length(&pending_glines[GLINE_PENDING_ADD_TYPE]) > 0)
    sendto_one(source_p, ":%s NOTICE %s :Pending G-lines",
               from, to);

  DLINK_FOREACH(dn_ptr, pending_glines[GLINE_PENDING_ADD_TYPE].head)
  {
    glp_ptr = dn_ptr->data;
    tmptr   = localtime(&glp_ptr->vote_1.time_request);
    strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);

    sendto_one(source_p,
               ":%s NOTICE %s :1) %s!%s@%s on %s requested gline at %s for %s@%s [%s]",
               from, to, glp_ptr->vote_1.oper_nick,
               glp_ptr->vote_1.oper_user, glp_ptr->vote_1.oper_host,
               glp_ptr->vote_1.oper_server, timebuffer,
               glp_ptr->user, glp_ptr->host, glp_ptr->vote_1.reason);

    if (glp_ptr->vote_2.oper_nick[0] != '\0')
    {
      tmptr = localtime(&glp_ptr->vote_2.time_request);
      strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);
      sendto_one(source_p,
      ":%s NOTICE %s :2) %s!%s@%s on %s requested gline at %s for %s@%s [%s]",
               from, to, glp_ptr->vote_2.oper_nick,
               glp_ptr->vote_2.oper_user, glp_ptr->vote_2.oper_host,
               glp_ptr->vote_2.oper_server, timebuffer,
               glp_ptr->user, glp_ptr->host, glp_ptr->vote_2.reason);
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :End of Pending G-lines",
             from, to);

  if (dlink_list_length(&pending_glines[GLINE_PENDING_DEL_TYPE]) > 0)
    sendto_one(source_p, ":%s NOTICE %s :Pending UNG-lines",
               from, to);

  DLINK_FOREACH(dn_ptr, pending_glines[GLINE_PENDING_DEL_TYPE].head)
  {
    glp_ptr = dn_ptr->data;
    tmptr   = localtime(&glp_ptr->vote_1.time_request);
    strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);

    sendto_one(source_p,
               ":%s NOTICE %s :1) %s!%s@%s on %s requested ungline at %s for %s@%s [%s]",
               from, to, glp_ptr->vote_1.oper_nick,
               glp_ptr->vote_1.oper_user, glp_ptr->vote_1.oper_host,
               glp_ptr->vote_1.oper_server, timebuffer,
               glp_ptr->user, glp_ptr->host, glp_ptr->vote_1.reason);

    if (glp_ptr->vote_2.oper_nick[0] != '\0')
    {
      tmptr = localtime(&glp_ptr->vote_2.time_request);
      strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);
      sendto_one(source_p,
      ":%s NOTICE %s :2) %s!%s@%s on %s requested ungline at %s for %s@%s [%s]",
               from, to, glp_ptr->vote_2.oper_nick,
               glp_ptr->vote_2.oper_user, glp_ptr->vote_2.oper_host,
               glp_ptr->vote_2.oper_server, timebuffer,
               glp_ptr->user, glp_ptr->host, glp_ptr->vote_2.reason);

    }
  }

  sendto_one(source_p, ":%s NOTICE %s :End of Pending UNG-lines",
             from, to);
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
  dlink_node *ptr = NULL;
  unsigned int i = 0;

  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :This server does not support G-Lines",
               from, to);
    return;
  }

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      const struct AddressRec *arec = ptr->data;

      if (arec->type == CONF_GLINE)
      {
        const struct MaskItem *conf = arec->conf;

        sendto_one(source_p, RPL_STATSKLINE,
                   from, to, "G",
                   conf->host ? conf->host : "*",
                   conf->user ? conf->user : "*",
                   conf->reason ? conf->reason : CONF_NOREASON);
      }
    }
  }
}

static void
stats_hubleaf(struct Client *source_p, int parc, char *parv[])
{
  report_confitem_types(source_p, CONF_HUB);
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
  if (IsLimitIp(conf))
    *prefix_ptr++ = '!';
  if (IsNeedIdentd(conf))
    *prefix_ptr++ = '+';
  if (!IsNeedPassword(conf))
    *prefix_ptr++ = '&';
  if (IsConfExemptResv(conf))
    *prefix_ptr++ = '$';
  if (IsNoMatchIp(conf))
    *prefix_ptr++ = '%';
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
report_auth(struct Client *client_p, int parc, char *parv[])
{
  struct MaskItem *conf = NULL;
  dlink_node *ptr = NULL;
  unsigned int i;


  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type != CONF_CLIENT)
        continue;

      conf = arec->conf;

      if (!MyOper(client_p) && IsConfDoSpoofIp(conf))
        continue;

      /* We are doing a partial list, based on what matches the u@h of the
       * sender, so prepare the strings for comparing --fl_
       */
      if (ConfigFileEntry.hide_spoof_ips)
        sendto_one(client_p, RPL_STATSILINE, me.name,
                   client_p->name, 'I',
                   conf->name == NULL ? "*" : conf->name,
                   show_iline_prefix(client_p, conf),
                   IsConfDoSpoofIp(conf) ? "255.255.255.255" :
                   conf->host, conf->port,
                   conf->class ? conf->class->name : "<default>");

      else
        sendto_one(client_p, RPL_STATSILINE, me.name,
                   client_p->name, 'I',
                   conf->name == NULL ? "*" : conf->name,
                   show_iline_prefix(client_p, conf),
                   conf->host, conf->port,
                   conf->class ? conf->class->name : "<default>");
    }
  }
}

static void
stats_auth(struct Client *source_p, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if ((ConfigFileEntry.stats_i_oper_only == 2) && !HasUMode(source_p, UMODE_OPER))
    sendto_one(source_p, ERR_NOPRIVILEGES,
               from, to);

  /* If unopered, Only return matching auth blocks */
  else if ((ConfigFileEntry.stats_i_oper_only == 1) && !HasUMode(source_p, UMODE_OPER))
  {
    struct MaskItem *conf;

    if (MyConnect(source_p))
      conf = find_conf_by_address(source_p->host,
                                   &source_p->localClient->ip,
				   CONF_CLIENT,
				   source_p->localClient->aftype,
				   source_p->username,
                                   source_p->localClient->passwd, 1);
    else
      conf = find_conf_by_address(source_p->host, NULL, CONF_CLIENT,
                                   0, source_p->username, NULL, 1);

    if (conf == NULL)
      return;

    sendto_one(source_p, RPL_STATSILINE, from,
               to, 'I',
	       "*", show_iline_prefix(source_p, conf),
	       conf->host, conf->port,
	       conf->class ? conf->class->name : "<default>");
  }
  /* They are opered, or allowed to see all auth blocks */
  else
    report_auth(source_p, 0, NULL);
}

/* report_Klines()
 * Inputs: Client to report to,
 *         type(==0 for perm, !=0 for temporary)
 *         mask 
 * Output: None
 * Side effects: Reports configured K(or k)-lines to client_p.
 */
static void
report_Klines(struct Client *client_p, int tkline)
{
  struct MaskItem *conf = NULL;
  unsigned int i = 0;
  const char *p = NULL;
  dlink_node *ptr = NULL;

  if (tkline)
    p = "k";
  else
    p = "K";

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type != CONF_KLINE)
        continue;

      conf = arec->conf;

      if ((!tkline && conf->until) ||
          (tkline && !conf->until))
        continue;

      if (HasUMode(client_p, UMODE_OPER))
        sendto_one(client_p, RPL_STATSKLINE, me.name,
                   client_p->name, p, conf->host, conf->user,
                   conf->reason);
      else
        sendto_one(client_p, RPL_STATSKLINE, me.name,
                   client_p->name, p, conf->host, conf->user,
                   conf->reason);
    }
  }
}

static void
stats_tklines(struct Client *source_p, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if ((ConfigFileEntry.stats_k_oper_only == 2) && !HasUMode(source_p, UMODE_OPER))
    sendto_one(source_p, ERR_NOPRIVILEGES,
               from, to);

  /* If unopered, Only return matching klines */
  else if ((ConfigFileEntry.stats_k_oper_only == 1) && !HasUMode(source_p, UMODE_OPER))
  {
    struct MaskItem *conf = NULL;

    if (MyConnect(source_p))
      conf = find_conf_by_address(source_p->host,
                                  &source_p->localClient->ip,
				   CONF_KLINE,
				   source_p->localClient->aftype,
				   source_p->username, NULL, 1);
    else
      conf = find_conf_by_address(source_p->host, NULL, CONF_KLINE,
                                   0, source_p->username, NULL, 1);

    if (!conf)
      return;

    /* dont report a permanent kline as a tkline */
    if (!conf->until)
      return;

    sendto_one(source_p, RPL_STATSKLINE, from,
               to, "k", conf->host, conf->user, conf->reason);
  }
  /* Theyre opered, or allowed to see all klines */
  else {
    report_Klines(source_p, 1);
  }
}

static void
stats_klines(struct Client *source_p, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if ((ConfigFileEntry.stats_k_oper_only == 2) && !HasUMode(source_p, UMODE_OPER))
    sendto_one(source_p, ERR_NOPRIVILEGES,
               from, to);

  /* If unopered, Only return matching klines */
  else if ((ConfigFileEntry.stats_k_oper_only == 1) && !HasUMode(source_p, UMODE_OPER))
  {
    struct MaskItem *conf = NULL;

    /* search for a kline */
    if (MyConnect(source_p))
      conf = find_conf_by_address(source_p->host,
                                   &source_p->localClient->ip,
				   CONF_KLINE,
				   source_p->localClient->aftype,
				   source_p->username, NULL, 0);
    else
      conf = find_conf_by_address(source_p->host, NULL, CONF_KLINE,
                                   0, source_p->username, NULL, 0);

    if (!conf)
      return;

    /* dont report a tkline as a kline */
    if (conf->until)
      return;
      
    sendto_one(source_p, RPL_STATSKLINE, from,
               to, "K", conf->host, conf->user, conf->reason);
  }
  /* Theyre opered, or allowed to see all klines */
  else {
    report_Klines(source_p, 0);
    report_confitem_types(source_p, CONF_RKLINE);
  }
}

static void
stats_messages(struct Client *source_p, int parc, char *parv[])
{
  report_messages(source_p);
}

static void
stats_oper(struct Client *source_p, int parc, char *parv[])
{
  if (!HasUMode(source_p, UMODE_OPER) && ConfigFileEntry.stats_o_oper_only)
    sendto_one(source_p, ERR_NOPRIVILEGES,
               from, to);
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
  dlink_node *ptr;

  DLINK_FOREACH(ptr, oper_list.head)
  {
    const struct Client *target_p = ptr->data;

    if (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER))
      continue;

    if (MyClient(source_p) && HasUMode(source_p, UMODE_OPER))
      sendto_one(source_p, ":%s %d %s p :[%c][%s] %s (%s@%s) Idle: %u",
                 from, RPL_STATSDEBUG, to,
                 HasUMode(target_p, UMODE_ADMIN) ? 'A' : 'O',
		 oper_privs_as_string(target_p->localClient->operflags),
		 target_p->name, target_p->username, target_p->host,
                 idle_time_get(source_p, target_p));
    else
      sendto_one(source_p, ":%s %d %s p :[%c] %s (%s@%s) Idle: %u",
                 from, RPL_STATSDEBUG, to,
                 HasUMode(target_p, UMODE_ADMIN) ? 'A' : 'O',
		 target_p->name, target_p->username, target_p->host,
                 idle_time_get(source_p, target_p));
  }

  sendto_one(source_p, ":%s %d %s p :%u OPER(s)",
             from, RPL_STATSDEBUG, to, dlink_list_length(&oper_list));
}

static void
stats_ports(struct Client *source_p, int parc, char *parv[])
{
  if (!HasUMode(source_p, UMODE_OPER) && ConfigFileEntry.stats_P_oper_only)
    sendto_one(source_p, ERR_NOPRIVILEGES,
               from, to);
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
  const struct Client *target_p = NULL;
  const dlink_node *ptr = NULL;
  struct ServerStatistics *sp;
  struct ServerStatistics tmp;

  sp = &tmp;
  memcpy(sp, &ServerStats, sizeof(struct ServerStatistics));

  /*
   * must use the += operator. is_sv is not the number of currently
   * active server connections. Note the incrementation in
   * s_bsd.c:close_connection.
   */
  sp->is_sv += dlink_list_length(&serv_list);

  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    sp->is_sbs += target_p->localClient->send.bytes;
    sp->is_sbr += target_p->localClient->recv.bytes;
    sp->is_sti += CurrentTime - target_p->localClient->firsttime;
  }

  sp->is_cl += dlink_list_length(&local_client_list);

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    sp->is_cbs += target_p->localClient->send.bytes;
    sp->is_cbr += target_p->localClient->recv.bytes;
    sp->is_cti += CurrentTime - target_p->localClient->firsttime;
  }

  sp->is_ni += dlink_list_length(&unknown_list);

  sendto_one(source_p, ":%s %d %s T :accepts %u refused %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_ac, sp->is_ref);
  sendto_one(source_p, ":%s %d %s T :unknown commands %u prefixes %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_unco, sp->is_unpf);
  sendto_one(source_p, ":%s %d %s T :nick collisions %u unknown closes %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_kill, sp->is_ni);
  sendto_one(source_p, ":%s %d %s T :wrong direction %u empty %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_wrdi, sp->is_empt);
  sendto_one(source_p, ":%s %d %s T :numerics seen %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_num);
  sendto_one(source_p, ":%s %d %s T :auth successes %u fails %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_asuc, sp->is_abad);
  sendto_one(source_p, ":%s %d %s T :Client Server",
             me.name, RPL_STATSDEBUG, source_p->name);

  sendto_one(source_p, ":%s %d %s T :connected %u %u",
             me.name, RPL_STATSDEBUG, source_p->name,
             (unsigned int)sp->is_cl,
             (unsigned int)sp->is_sv);
  sendto_one(source_p, ":%s %d %s T :bytes sent %llu %llu",
             me.name, RPL_STATSDEBUG, source_p->name,
             sp->is_cbs, sp->is_sbs);
  sendto_one(source_p, ":%s %d %s T :bytes recv %llu %llu",
             me.name, RPL_STATSDEBUG, source_p->name,
             sp->is_cbr, sp->is_sbr);
  sendto_one(source_p, ":%s %d %s T :time connected %u %u",
             me.name, RPL_STATSDEBUG, source_p->name,
             (unsigned int)sp->is_cti,
             (unsigned int)sp->is_sti);
}

static void
stats_uptime(struct Client *source_p, int parc, char *parv[])
{
  time_t now = CurrentTime - me.localClient->since;

  sendto_one(source_p, RPL_STATSUPTIME, from, to,
             now / 86400, (now / 3600) % 24, (now / 60) % 60, now % 60);

  if (!ConfigFileEntry.disable_remote || HasUMode(source_p, UMODE_OPER))
     sendto_one(source_p, RPL_STATSCONN, from, to,
                Count.max_loc_con, Count.max_loc_cli, Count.totalrestartcount);
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
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, serv_list.head)
  {
    const struct Client *target_p = ptr->data;

    sendto_one(source_p, ":%s %d %s v :%s (%s!%s@%s) Idle: %d",
               from, RPL_STATSDEBUG, to, target_p->name,
               (target_p->serv->by[0] ? target_p->serv->by : "Remote."),
               "*", "*", (int)(CurrentTime - target_p->localClient->lasttime));
  }

  sendto_one(source_p, ":%s %d %s v :%u Server(s)",
             from, RPL_STATSDEBUG, to, dlink_list_length(&serv_list));
}

static void
stats_gecos(struct Client *source_p, int parc, char *parv[])
{
  report_confitem_types(source_p, CONF_XLINE);
  report_confitem_types(source_p, CONF_RXLINE);
}

static void
stats_class(struct Client *source_p, int parc, char *parv[])
{
  report_confitem_types(source_p, CONF_CLASS);
}

static void
stats_servlinks(struct Client *source_p, int parc, char *parv[])
{
  uint64_t sendB = 0, recvB = 0;
  time_t uptime = 0;
  dlink_node *ptr = NULL;

  if (ConfigServerHide.flatten_links && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one(source_p, ERR_NOPRIVILEGES,
               from, to);
    return;
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    struct Client *target_p = ptr->data;

    sendB += target_p->localClient->send.bytes;
    recvB += target_p->localClient->recv.bytes;

    /* ":%s 211 %s %s %u %u %llu %u %llu :%u %u %s" */
    sendto_one(source_p, RPL_STATSLINKINFO,
               from, to,
               get_client_name(target_p, HasUMode(source_p, UMODE_ADMIN) ? SHOW_IP : MASK_IP),
               dbuf_length(&target_p->localClient->buf_sendq),
               target_p->localClient->send.messages,
               target_p->localClient->send.bytes >> 10,
               target_p->localClient->recv.messages,
               target_p->localClient->recv.bytes >> 10,
               (unsigned)(CurrentTime - target_p->localClient->firsttime),
               (CurrentTime > target_p->localClient->since) ? (unsigned)(CurrentTime - target_p->localClient->since): 0,
               HasUMode(source_p, UMODE_OPER) ? show_capabilities(target_p) : "TS");
  }

  sendB >>= 10;
  recvB >>= 10;

  sendto_one(source_p, ":%s %d %s ? :%u total server(s)",
             from, RPL_STATSDEBUG, to, dlink_list_length(&serv_list));
  sendto_one(source_p, ":%s %d %s ? :Sent total : %7.2f %s",
             from, RPL_STATSDEBUG, to,
             _GMKv(sendB), _GMKs(sendB));
  sendto_one(source_p, ":%s %d %s ? :Recv total : %7.2f %s",
             from, RPL_STATSDEBUG, to,
             _GMKv(recvB), _GMKs(recvB));

  uptime = (CurrentTime - me.localClient->since);

  sendto_one(source_p, ":%s %d %s ? :Server send: %7.2f %s (%4.1f K/s)",
             from, RPL_STATSDEBUG, to,
             _GMKv((me.localClient->send.bytes>>10)),
             _GMKs((me.localClient->send.bytes>>10)),
             (float)((float)((me.localClient->send.bytes) >> 10) /
             (float)uptime));
  sendto_one(source_p, ":%s %d %s ? :Server recv: %7.2f %s (%4.1f K/s)",
             from, RPL_STATSDEBUG, to,
             _GMKv((me.localClient->recv.bytes>>10)),
             _GMKs((me.localClient->recv.bytes>>10)),
             (float)((float)((me.localClient->recv.bytes) >> 10) /
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
static char *
parse_stats_args(int parc, char *parv[], int *doall, int *wilds)
{
  char *name;

  if (parc > 2)
  {
    name = parv[2];

    if (!irccmp(name, from))
      *doall = 2;
    else if (!match(name, from))
      *doall = 1;

    *wilds = has_wildcards(name);

    return name;
  }

  return NULL;
}

static void
stats_L_list(struct Client *source_p,char *name, int doall, int wilds,
             dlink_list *list,char statchar)
{
  dlink_node *ptr;
  struct Client *target_p;

  /*
   * send info about connections which match, or all if the
   * mask matches from.  Only restrictions are on those who
   * are invisible not being visible to 'foreigners' who use
   * a wild card based search to list it.
   */
  DLINK_FOREACH(ptr, list->head)
  {
    target_p = ptr->data;

    if (HasUMode(target_p, UMODE_INVISIBLE) && (doall || wilds) &&
        !(MyConnect(source_p) && HasUMode(source_p, UMODE_OPER)) &&
        !HasUMode(target_p, UMODE_OPER) && (target_p != source_p))
      continue;
    if (!doall && wilds && match(name, target_p->name))
      continue;
    if (!(doall || wilds) && irccmp(name, target_p->name))
      continue;

    /* This basically shows ips for our opers if its not a server/admin, or
     * its one of our admins.  */
    if(MyClient(source_p) && HasUMode(source_p, UMODE_OPER) &&
       (HasUMode(source_p, UMODE_ADMIN) ||
       (!IsServer(target_p) && !HasUMode(target_p, UMODE_ADMIN) &&
       !IsHandshake(target_p) && !IsConnecting(target_p))))
    {
      sendto_one(source_p, RPL_STATSLINKINFO,
                 from, to,
                 (IsUpper(statchar)) ?
                 get_client_name(target_p, SHOW_IP) :
                 get_client_name(target_p, HIDE_IP),
                 dbuf_length(&target_p->localClient->buf_sendq),
                 target_p->localClient->send.messages,
                 target_p->localClient->send.bytes>>10,
                 target_p->localClient->recv.messages,
                 target_p->localClient->recv.bytes>>10,
                 (unsigned)(CurrentTime - target_p->localClient->firsttime),
                 (CurrentTime > target_p->localClient->since) ? (unsigned)(CurrentTime - target_p->localClient->since):0,
                 IsServer(target_p) ? show_capabilities(target_p) : "-");
    }
    else
    {
      /* If its a hidden ip, an admin, or a server, mask the real IP */
      if(IsIPSpoof(target_p) || IsServer(target_p) || HasUMode(target_p, UMODE_ADMIN)
         || IsHandshake(target_p) || IsConnecting(target_p))
        sendto_one(source_p, RPL_STATSLINKINFO,
                   from, to,
                   get_client_name(target_p, MASK_IP),
                   dbuf_length(&target_p->localClient->buf_sendq),
                   target_p->localClient->send.messages,
                   target_p->localClient->send.bytes>>10,
                   target_p->localClient->recv.messages,
                   target_p->localClient->recv.bytes>>10,
                   (unsigned)(CurrentTime - target_p->localClient->firsttime),
                   (CurrentTime > target_p->localClient->since) ? (unsigned)(CurrentTime - target_p->localClient->since):0,
                   IsServer(target_p) ? show_capabilities(target_p) : "-");
      else /* show the real IP */
        sendto_one(source_p, RPL_STATSLINKINFO,
                   from, to,
                   (IsUpper(statchar)) ?
                   get_client_name(target_p, SHOW_IP) :
                   get_client_name(target_p, HIDE_IP),
                   dbuf_length(&target_p->localClient->buf_sendq),
                   target_p->localClient->send.messages,
                   target_p->localClient->send.bytes>>10,
                   target_p->localClient->recv.messages,
                   target_p->localClient->recv.bytes>>10,
                   (unsigned)(CurrentTime - target_p->localClient->firsttime),
                   (CurrentTime > target_p->localClient->since) ? (unsigned)(CurrentTime - target_p->localClient->since):0,
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
stats_L(struct Client *source_p,char *name,int doall,
        int wilds,char statchar)
{
  stats_L_list(source_p, name, doall, wilds, &unknown_list, statchar);
  stats_L_list(source_p, name, doall, wilds, &local_client_list, statchar);
  stats_L_list(source_p, name, doall, wilds, &serv_list, statchar);
}

static void
stats_ltrace(struct Client *source_p, int parc, char *parv[])
{
  int doall = 0;
  int wilds = 0;
  char *name = NULL;
  char statchar;

  if ((name = parse_stats_args(parc, parv, &doall, &wilds)) != NULL)
  {
    statchar = parv[1][0];

    stats_L(source_p, name, doall, wilds, statchar);
  }
  else
    sendto_one(source_p, ERR_NEEDMOREPARAMS,
               from, to, "STATS");
}

static const struct StatsStruct
{
  const unsigned char letter;
  void (*handler)();
  const unsigned int need_oper;
  const unsigned int need_admin;
} stats_cmd_table[] = {
  /* letter     function            need_oper need_admin */
  { 'a',        stats_dns_servers,      1,      1       },
  { 'A',        stats_dns_servers,      1,      1       },
  { 'c',        stats_connect,          1,      0       },
  { 'C',        stats_connect,          1,      0       },
  { 'd',        stats_tdeny,            1,      0       },
  { 'D',        stats_deny,             1,      0       },
  { 'e',        stats_exempt,           1,      0       },
  { 'E',        stats_events,           1,      1       },
  { 'f',        fd_dump,                1,      1       },
  { 'F',        fd_dump,                1,      1       },
  { 'g',        stats_pending_glines,   1,      0       },
  { 'G',        stats_glines,           1,      0       },
  { 'h',        stats_hooks,            1,      1       },
  { 'H',        stats_hubleaf,          1,      0       },
  { 'i',        stats_auth,             0,      0       },
  { 'I',        stats_auth,             0,      0       },
  { 'k',        stats_tklines,          0,      0       },
  { 'K',        stats_klines,           0,      0       },
  { 'l',        stats_ltrace,           1,      0       },
  { 'L',        stats_ltrace,           1,      0       },
  { 'm',        stats_messages,         0,      0       },
  { 'M',        stats_messages,         0,      0       },
  { 'o',        stats_oper,             0,      0       },
  { 'O',        stats_oper,             0,      0       },
  { 'p',        stats_operedup,         0,      0       },
  { 'P',        stats_ports,            0,      0       },
  { 'q',        stats_resv,             1,      0       },
  { 'Q',        stats_resv,             1,      0       },
  { 'r',        stats_usage,            1,      0       },
  { 'R',        stats_usage,            1,      0       },
  { 'S',        stats_service,          1,      0       },
  { 't',        stats_tstats,           1,      0       },
  { 'T',        stats_tstats,           1,      0       },
  { 'u',        stats_uptime,           0,      0       },
  { 'U',        stats_shared,           1,      0       },
  { 'v',        stats_servers,          1,      0       },
  { 'x',        stats_gecos,            1,      0       },
  { 'X',        stats_gecos,            1,      0       },
  { 'y',        stats_class,            1,      0       },
  { 'Y',        stats_class,            1,      0       },
  { 'z',        stats_memory,           1,      0       },
  { '?',        stats_servlinks,        0,      0       },
  { '\0',       NULL,                   0,      0       }
};

static void
do_stats(struct Client *source_p, int parc, char *parv[])
{
  const struct StatsStruct *tab = stats_cmd_table;
  const char statchar = *parv[1];

  if (statchar == '\0')
  {
    sendto_one(source_p, RPL_ENDOFSTATS,
               from, to, '*');
    return;
  }

  for (; tab->handler; ++tab)
  {
    if (tab->letter == statchar)
    {
      /* The stats table says what privs are needed, so check --fl_ */
      if ((tab->need_admin && !HasUMode(source_p, UMODE_ADMIN)) ||
          (tab->need_oper && !HasUMode(source_p, UMODE_OPER)))
      {
        sendto_one(source_p, ERR_NOPRIVILEGES,
                   from, to);
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

  sendto_one(source_p, RPL_ENDOFSTATS,
             from, to, statchar);
}

/*
 * m_stats()
 *      parv[0] = sender prefix
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L
 * 
 * This will search the tables for the appropriate stats letter/command,
 * if found execute it.  
 */
static void
m_stats(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  static time_t last_used = 0;

  /* Is the stats meant for us? */
  if (!ConfigFileEntry.disable_remote)
    if (hunt_server(client_p, source_p, ":%s STATS %s :%s", 2,
                    parc, parv) != HUNTED_ISME)
      return;

  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  /* Check the user is actually allowed to do /stats, and isnt flooding */
  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    sendto_one(source_p, RPL_LOAD2HI,
               from, to);
    return;
  }

  last_used = CurrentTime;

  do_stats(source_p, parc, parv);
}

/*
 * mo_stats()
 *      parv[0] = sender prefix
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L, or target
 *
 * This will search the tables for the appropriate stats letter,
 * if found execute it.  
 */
static void
mo_stats(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s STATS %s :%s", 2,
                  parc, parv) != HUNTED_ISME)
     return;

  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  do_stats(source_p, parc, parv);
}

/*
 * ms_stats - STATS message handler
 *      parv[0] = sender prefix
 *      parv[1] = statistics selector (defaults to Message frequency)
 *      parv[2] = server name (current server defaulted, if omitted)
 */
static void
ms_stats(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s STATS %s :%s", 2,
                  parc, parv) != HUNTED_ISME)
    return;

  if (IsClient(source_p))
    mo_stats(client_p, source_p, parc, parv);
}

static struct Message stats_msgtab = {
  "STATS", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_stats, ms_stats, m_ignore, mo_stats, m_ignore }
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};

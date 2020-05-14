/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2020 ircd-hybrid development team
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
#include "parse.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_gecos.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "hostmask.h"
#include "numeric.h"
#include "send.h"
#include "fdlist.h"
#include "misc.h"
#include "server.h"
#include "server_capab.h"
#include "event.h"
#include "modules.h"
#include "whowas.h"
#include "watch.h"
#include "reslib.h"
#include "motd.h"
#include "ipcache.h"
#include "channel.h"
#include "channel_invite.h"


static const char *
oper_privs_as_string(const unsigned int flags)
{
  static const struct oper_flags
  {
    unsigned int flag;
    unsigned char letter;
  } flag_table[] = {
    { OPER_FLAG_ADMIN,          'A' },
    { OPER_FLAG_CLOSE,          'B' },
    { OPER_FLAG_CONNECT,        'C' },
    { OPER_FLAG_CONNECT_REMOTE, 'D' },
    { OPER_FLAG_DIE,            'E' },
    { OPER_FLAG_DLINE,          'F' },
    { OPER_FLAG_GLOBOPS,        'G' },
    { OPER_FLAG_JOIN_RESV,      'H' },
    { OPER_FLAG_KILL,           'I' },
    { OPER_FLAG_KILL_REMOTE,    'J' },
    { OPER_FLAG_KLINE,          'K' },
    { OPER_FLAG_LOCOPS,         'L' },
    { OPER_FLAG_MODULE,         'M' },
    { OPER_FLAG_NICK_RESV,      'N' },
    { OPER_FLAG_OPME,           'O' },
    { OPER_FLAG_REHASH,         'P' },
    { OPER_FLAG_REMOTEBAN,      'Q' },
    { OPER_FLAG_RESTART,        'R' },
    { OPER_FLAG_RESV,           'S' },
    { OPER_FLAG_SET,            'T' },
    { OPER_FLAG_SQUIT,          'U' },
    { OPER_FLAG_SQUIT_REMOTE,   'V' },
    { OPER_FLAG_UNDLINE,        'W' },
    { OPER_FLAG_UNKLINE,        'X' },
    { OPER_FLAG_UNRESV,         'Y' },
    { OPER_FLAG_UNXLINE,        'Z' },
    { OPER_FLAG_WALLOPS,        'a' },
    { OPER_FLAG_XLINE,          'b' },
    { 0, '\0' }
  };

  static char buf[sizeof(flag_table) / sizeof(flag_table[0])];
  char *p = buf;

  for (const struct oper_flags *tab = flag_table; tab->flag; ++tab)
    if (flags & tab->flag)
      *p++ = tab->letter;

  if (p == buf)
    *p++ = '0';

  *p = '\0';

  return buf;
}

static void
report_shared(struct Client *source_p)
{
  static const struct shared_types
  {
    unsigned int type;
    unsigned char letter;
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

  dlink_node *node;
  char buf[sizeof(flag_table) / sizeof(flag_table[0]) + 1];  /* +1 for 'c' */

  DLINK_FOREACH(node, shared_get_list()->head)
  {
    const struct SharedItem *shared = node->data;
    char *p = buf;

    *p++ = 'c';

    for (const struct shared_types *tab = flag_table; tab->type; ++tab)
      if (tab->type & shared->type)
        *p++ = tab->letter;
      else
        *p++ = ToLower(tab->letter);

    *p = '\0';

    sendto_one_numeric(source_p, &me, RPL_STATSULINE, shared->server,
                       shared->user, shared->host, buf);
  }
}

static void
report_cluster(struct Client *source_p)
{
  static const struct cluster_types
  {
    unsigned int type;
    unsigned char letter;
  } flag_table[] = {
    { CLUSTER_KLINE,   'K' },
    { CLUSTER_UNKLINE, 'U' },
    { CLUSTER_XLINE,   'X' },
    { CLUSTER_UNXLINE, 'Y' },
    { CLUSTER_RESV,    'Q' },
    { CLUSTER_UNRESV,  'R' },
    { CLUSTER_LOCOPS,  'L' },
    { CLUSTER_DLINE,   'D' },
    { CLUSTER_UNDLINE, 'E' },
    { 0, '\0' }
  };

  dlink_node *node;
  char buf[sizeof(flag_table) / sizeof(flag_table[0]) + 1];  /* +1 for 'C' */

  DLINK_FOREACH(node, cluster_get_list()->head)
  {
    const struct ClusterItem *cluster = node->data;
    char *p = buf;

    *p++ = 'C';

    for (const struct cluster_types *tab = flag_table; tab->type; ++tab)
      if (tab->type & cluster->type)
        *p++ = tab->letter;
      else
        *p++ = ToLower(tab->letter);

    *p = '\0';

    sendto_one_numeric(source_p, &me, RPL_STATSULINE, cluster->server,
                       "*", "*", buf);
  }
}

static void
stats_service(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  DLINK_FOREACH(node, service_get_list()->head)
  {
    const struct ServiceItem *service = node->data;
    sendto_one_numeric(source_p, &me, RPL_STATSSERVICE, "*", service->name, 0, 0);
  }
}

static void
stats_gecos(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  DLINK_FOREACH(node, gecos_get_list()->head)
  {
    const struct GecosItem *gecos = node->data;
    sendto_one_numeric(source_p, &me, RPL_STATSXLINE,
                       gecos->expire ? 'x' : 'X',
                       gecos->mask, gecos->reason);
  }
}

/*
 * inputs	- pointer to client requesting confitem report
 *		- ConfType to report
 * output	- none
 * side effects	-
 */
static void
stats_operator(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  if (!HasUMode(source_p, UMODE_OPER) && ConfigGeneral.stats_o_oper_only)
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
    return;
  }

  DLINK_FOREACH(node, operator_items.head)
  {
    const struct MaskItem *conf = node->data;

    /* Don't allow non opers to see oper privs */
    if (HasUMode(source_p, UMODE_OPER))
      sendto_one_numeric(source_p, &me, RPL_STATSOLINE, 'O', conf->user, conf->host,
                         conf->name, oper_privs_as_string(conf->port),
                         conf->class->name);
    else
      sendto_one_numeric(source_p, &me, RPL_STATSOLINE, 'O', conf->user, conf->host,
                         conf->name, "0", conf->class->name);
  }
}

static void
stats_connect(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  DLINK_FOREACH(node, connect_items.head)
  {
    char buf[8];
    char *p = buf;
    const struct MaskItem *conf = node->data;

    if (IsConfAllowAutoConn(conf))
      *p++ = 'A';
    if (IsConfTLS(conf))
      *p++ = 'S';
    if (p == buf)
      *p++ = '*';

    *p = '\0';

    /*
     * Allow admins to see actual ips unless 'hide_server_ips' is enabled
     */
    if (ConfigServerHide.hide_server_ips == 0 && HasUMode(source_p, UMODE_ADMIN))
      sendto_one_numeric(source_p, &me, RPL_STATSCLINE, 'C', conf->host,
                         buf, conf->name, conf->port, conf->class->name);
    else
      sendto_one_numeric(source_p, &me, RPL_STATSCLINE, 'C', "*@127.0.0.1",
                         buf, conf->name, conf->port, conf->class->name);
  }
}

/* report_resv()
 *
 * inputs       - pointer to client pointer to report to.
 * output       - NONE
 * side effects - report all resvs to client.
 */
static void
stats_resv(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  DLINK_FOREACH(node, resv_chan_get_list()->head)
  {
    const struct ResvItem *resv = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSQLINE,
                       resv->expire ? 'q' : 'Q',
                       resv->mask, resv->reason);
  }

  DLINK_FOREACH(node, resv_nick_get_list()->head)
  {
    const struct ResvItem *resv = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSQLINE,
                       resv->expire ? 'q' : 'Q',
                       resv->mask, resv->reason);
  }
}

static void
stats_memory(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node, *node2;

  unsigned int local_client_conf_count = 0;      /* local client conf links */

  unsigned int channel_members = 0;
  unsigned int channel_invites = 0;
  unsigned int channel_bans = 0;
  unsigned int channel_except = 0;
  unsigned int channel_invex = 0;

  unsigned int wwu = 0;                  /* whowas users */
  unsigned int number_ips_stored = 0;        /* number of ip addresses hashed */

  size_t channel_ban_memory = 0;
  size_t channel_except_memory = 0;
  size_t channel_invex_memory = 0;

  unsigned int safelist_count = 0;
  size_t safelist_memory = 0;

  size_t wwm = 0;               /* whowas array memory used       */
  size_t mem_ips_stored = 0;        /* memory used by ip address hash */

  unsigned int local_client_count  = 0;
  unsigned int remote_client_count = 0;

  size_t local_client_memory_used  = 0;
  size_t remote_client_memory_used = 0;

  unsigned int watch_list_headers = 0;   /* watchlist headers     */
  unsigned int watch_list_entries = 0;   /* watchlist entries     */
  size_t watch_list_memory = 0; /* watchlist memory used */

  unsigned int listener_count = 0;
  size_t listener_memory = 0;


  DLINK_FOREACH(node, local_server_list.head)
  {
    const struct Client *target_p = node->data;

    local_client_conf_count += dlink_list_length(&target_p->connection->confs);
  }

  DLINK_FOREACH(node, local_client_list.head)
  {
    const struct Client *target_p = node->data;

    local_client_conf_count += dlink_list_length(&target_p->connection->confs);
    watch_list_entries += dlink_list_length(&target_p->connection->watches);
  }

  local_client_count = dlink_list_length(&local_server_list) + dlink_list_length(&local_client_list);
  remote_client_count = dlink_list_length(&global_server_list) + dlink_list_length(&global_client_list) - local_client_count;

  /* Count up all members, invites, ban lists, except lists, Invex lists */
  DLINK_FOREACH(node, channel_get_list()->head)
  {
    const struct Channel *channel = node->data;

    channel_members += dlink_list_length(&channel->members);
    channel_invites += dlink_list_length(&channel->invites);

    channel_bans += dlink_list_length(&channel->banlist);
    channel_ban_memory += dlink_list_length(&channel->banlist) * sizeof(struct Ban);

    channel_except += dlink_list_length(&channel->exceptlist);
    channel_except_memory += dlink_list_length(&channel->exceptlist) * sizeof(struct Ban);

    channel_invex += dlink_list_length(&channel->invexlist);
    channel_invex_memory += dlink_list_length(&channel->invexlist) * sizeof(struct Ban);
  }

  safelist_count = dlink_list_length(&listing_client_list);
  if (safelist_count)
  {
    safelist_memory = safelist_count * sizeof(struct ListTask);

    DLINK_FOREACH(node, listing_client_list.head)
    {
      const struct Client *acptr = node->data;

      DLINK_FOREACH(node2, acptr->connection->list_task->show_mask.head)
        safelist_memory += strlen(node2->data);

      DLINK_FOREACH(node2, acptr->connection->list_task->hide_mask.head)
        safelist_memory += strlen(node2->data);
    }
  }

  watch_count_memory(&watch_list_headers, &watch_list_memory);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :WATCH headers %u(%zu) entries %u(%zu)",
                     watch_list_headers,
                     watch_list_memory,
                     watch_list_entries,
                     watch_list_entries * sizeof(dlink_node) * 2);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Clients %u(%zu)",
                     dlink_list_length(&global_client_list),
                     dlink_list_length(&global_client_list) * sizeof(struct Client));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Servers %u(%zu, %zu)",
                     dlink_list_length(&global_server_list),
                     dlink_list_length(&global_server_list) * sizeof(struct Client),
                     dlink_list_length(&global_server_list) * sizeof(struct Server));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Attached confs %u(%zu)",
                     local_client_conf_count,
                     local_client_conf_count * sizeof(dlink_node));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Resv channels %u(%zu) nicks %u(%zu)",
                     dlink_list_length(resv_chan_get_list()),
                     dlink_list_length(resv_chan_get_list()) * sizeof(struct ResvItem),
                     dlink_list_length(resv_nick_get_list()),
                     dlink_list_length(resv_nick_get_list()) * sizeof(struct ResvItem));

  listener_count_memory(&listener_count, &listener_memory);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Listeners %u(%zu)",
                     listener_count, listener_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Classes %u(%zu)",
                     dlink_list_length(class_get_list()),
                     dlink_list_length(class_get_list()) * sizeof(struct ClassItem));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Channels %u(%zu)",
                     dlink_list_length(channel_get_list()),
                     dlink_list_length(channel_get_list()) * sizeof(struct Channel));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Bans %u(%zu)",
                     channel_bans, channel_ban_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Exceptions %u(%zu)",
                     channel_except, channel_except_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Invex %u(%zu)",
                     channel_invex, channel_invex_memory);

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Channel members %u(%zu) invites %u(%zu)",
                     channel_members,
                     channel_members * sizeof(struct ChannelMember),
                     channel_invites,
                     channel_invites * sizeof(struct Invite));

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Safelist %u(%zu)",
                     safelist_count, safelist_memory);

  whowas_count_memory(&wwu, &wwm);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Whowas users %u(%zu)", wwu, wwm);

  motd_memory_count(source_p);

  ipcache_get_stats(&number_ips_stored, &mem_ips_stored);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :iphash %u(%zu)",
                     number_ips_stored, mem_ips_stored);

  local_client_memory_used = local_client_count * (sizeof(struct Client) + sizeof(struct Connection));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Local client Memory in use: %u(%zu)",
                     local_client_count, local_client_memory_used);

  remote_client_memory_used = remote_client_count * sizeof(struct Client);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Remote client Memory in use: %u(%zu)",
                     remote_client_count, remote_client_memory_used);
}

static void
stats_dns_servers(struct Client *source_p, int parc, char *parv[])
{
  char ipaddr[HOSTIPLEN + 1];

  for (unsigned int i = 0; i < irc_nscount; ++i)
  {
    getnameinfo((const struct sockaddr *)&irc_nsaddr_list[i], irc_nsaddr_list[i].ss_len,
                ipaddr, sizeof(ipaddr), NULL, 0, NI_NUMERICHOST);
    sendto_one_numeric(source_p, &me, RPL_STATSALINE, ipaddr);
  }
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
  dlink_node *node;

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_DLINE)
        continue;

      const struct MaskItem *conf = arec->conf;
      /* Don't report a temporary dline as permanent dline */
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
  dlink_node *node;

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_DLINE)
        continue;

      const struct MaskItem *conf = arec->conf;
      /* Don't report a permanent dline as temporary dline */
      if (conf->until == 0)
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
  dlink_node *node;

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

      const struct MaskItem *conf = arec->conf;
      sendto_one_numeric(source_p, &me, RPL_STATSDLINE, 'e', conf->host, "");
    }
  }
}

static void
stats_events(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "E :Operation                      Next Execution");
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "E :---------------------------------------------");

  DLINK_FOREACH(node, event_get_list()->head)
  {
    const struct event *ev = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                       "E :%-30s %-4ju seconds",
                       ev->name, ev->next - event_base->time.sec_monotonic);
  }
}

static void
stats_fdlist(struct Client *source_p, int parc, char *parv[])
{
  for (int fd = 0; fd <= highest_fd; ++fd)
  {
    const fde_t *F = &fd_table[fd];

    if (F->flags.open == true)
      sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                         "F :fd %-5d desc '%s'", F->fd, F->desc);
  }
}

static void
stats_hubleaf(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node, *node2;

  DLINK_FOREACH(node, connect_items.head)
  {
    const struct MaskItem *conf = node->data;

    DLINK_FOREACH(node2, conf->hub_list.head)
      sendto_one_numeric(source_p, &me, RPL_STATSHLINE, 'H', node2->data, conf->name, 0, "*");
  }

  DLINK_FOREACH(node, connect_items.head)
  {
    const struct MaskItem *conf = node->data;

    DLINK_FOREACH(node2, conf->leaf_list.head)
      sendto_one_numeric(source_p, &me, RPL_STATSLLINE, 'L', node2->data, conf->name, 0, "*");
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
show_iline_prefix(const struct Client *source_p, const struct MaskItem *conf)
{
  static char buf[USERLEN + 16];
  char *p = buf;

  if (IsConfWebIRC(conf))
    *p++ = '<';
  if (IsNoTilde(conf))
    *p++ = '-';
  if (IsNeedIdentd(conf))
    *p++ = '+';
  if (!IsNeedPassword(conf))
    *p++ = '&';
  if (IsConfExemptResv(conf))
    *p++ = '$';
  if (IsConfDoSpoofIp(conf))
    *p++ = '=';
  if (IsConfCanFlood(conf))
    *p++ = '|';
  if (HasUMode(source_p, UMODE_OPER))
  {
    if (IsConfExemptKline(conf))
      *p++ = '^';
    if (IsConfExemptXline(conf))
      *p++ = '!';
    if (IsConfExemptLimits(conf))
      *p++ = '>';
  }

  strlcpy(p, conf->user, USERLEN + 1);
  return buf;
}

static void
stats_auth(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_i_oper_only && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
    return;
  }

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_CLIENT)
        continue;

      const struct MaskItem *conf = arec->conf;
      if (IsConfDoSpoofIp(conf) && !HasUMode(source_p, UMODE_OPER))
        continue;

      sendto_one_numeric(source_p, &me, RPL_STATSILINE, 'I',
                         conf->name == NULL ? "*" : conf->name,
                         show_iline_prefix(source_p, conf),
                         conf->host, conf->port,
                         conf->class->name);
    }
  }
}

/* report_Klines()
 * Inputs: Client to report to,
 *         type(==0 for perm, !=0 for temporary)
 *         mask
 * Output: None
 * Side effects: Reports configured K(or k)-lines to source_p.
 */
static void
stats_kill(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_k_oper_only && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
    return;
  }

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_KLINE)
        continue;

      const struct MaskItem *conf = arec->conf;
      /* Don't report a temporary kline as permanent kline */
      if (conf->until)
        continue;

      sendto_one_numeric(source_p, &me, RPL_STATSKLINE, 'K', conf->host, conf->user,
                         conf->reason);
    }
  }
}

static void
stats_tkill(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_k_oper_only && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
    return;
  }

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_KLINE)
        continue;

      const struct MaskItem *conf = arec->conf;
      /* Don't report a permanent kline as temporary kline */
      if (conf->until == 0)
        continue;

      sendto_one_numeric(source_p, &me, RPL_STATSKLINE, 'k', conf->host, conf->user,
                         conf->reason);
    }
  }
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
stats_pseudo(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  DLINK_FOREACH(node, pseudo_get_list()->head)
  {
    const struct PseudoItem *pseudo = node->data;
    sendto_one_numeric(source_p, &me, RPL_STATSPSEUDO, pseudo->command,
                       pseudo->name, pseudo->nick, pseudo->serv,
                       pseudo->prepend ? pseudo->prepend : "*");
  }
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
  dlink_node *node;
  char buf[32];
  unsigned int opercount = 0;

  DLINK_FOREACH(node, oper_list.head)
  {
    const struct Client *target_p = node->data;

    if (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER))
      continue;

    if (HasUMode(source_p, UMODE_OPER) || !HasUMode(target_p, UMODE_HIDEIDLE))
      snprintf(buf, sizeof(buf), "%s", time_dissect(client_get_idle_time(source_p, target_p)));
    else
      strlcpy(buf, "n/a", sizeof(buf));

    if (MyConnect(source_p) && HasUMode(source_p, UMODE_OPER))
      sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                         "p :[%c][%s] %s (%s@%s) Idle: %s",
                         HasUMode(target_p, UMODE_ADMIN) ? 'A' : 'O',
                         oper_privs_as_string(target_p->connection->operflags),
                         target_p->name, target_p->username, target_p->host, buf);
    else
      sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                         "p :[%c] %s (%s@%s) Idle: %s",
                         HasUMode(target_p, UMODE_ADMIN) ? 'A' : 'O',
                         target_p->name, target_p->username, target_p->host, buf);
    ++opercount;
  }

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "p :%u OPER(s)", opercount);
}

/* show_ports()
 *
 * inputs       - pointer to client to show ports to
 * output       - none
 * side effects - send port listing to a client
 */
static void
stats_ports(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

  if (ConfigGeneral.stats_P_oper_only && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
    return;
  }

  DLINK_FOREACH(node, listener_get_list()->head)
  {
    char buf[8];
    char *p = buf;
    const struct Listener *listener = node->data;

    if (listener->flags & LISTENER_HIDDEN)
    {
      if (!HasUMode(source_p, UMODE_ADMIN))
        continue;
      *p++ = 'H';
    }

    if (listener->flags & LISTENER_SERVER)
      *p++ = 'S';
    if (listener->flags & LISTENER_TLS)
      *p++ = 'T';
    *p = '\0';

    if (HasUMode(source_p, UMODE_ADMIN) && ConfigServerHide.hide_server_ips == 0)
      sendto_one_numeric(source_p, &me, RPL_STATSPLINE, 'P', listener->port,
                         listener->name,
                         listener->ref_count, buf,
                         listener->active ? "active" : "disabled");
    else
      sendto_one_numeric(source_p, &me, RPL_STATSPLINE, 'P', listener->port,
                         me.name, listener->ref_count, buf,
                         listener->active ? "active" : "disabled");
  }
}

static void
stats_tstats(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;
  struct ServerStatistics sp = ServerStats;

  DLINK_FOREACH(node, local_server_list.head)
  {
    const struct Client *target_p = node->data;

    sp.is_sbs += target_p->connection->send.bytes;
    sp.is_sbr += target_p->connection->recv.bytes;
    sp.is_sti += event_base->time.sec_monotonic - target_p->connection->created_monotonic;
    sp.is_sv++;
  }

  DLINK_FOREACH(node, local_client_list.head)
  {
    const struct Client *target_p = node->data;

    sp.is_cbs += target_p->connection->send.bytes;
    sp.is_cbr += target_p->connection->recv.bytes;
    sp.is_cti += event_base->time.sec_monotonic - target_p->connection->created_monotonic;
    sp.is_cl++;
  }

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :accepts %u refused %u",
                     sp.is_ac, sp.is_ref);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :unknown commands %u prefixes %u",
                     sp.is_unco, sp.is_unpf);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :nick collisions %u unknown closes %u",
                     sp.is_kill, sp.is_ni);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :wrong direction %u empty %u",
                     sp.is_wrdi, sp.is_empt);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :numerics seen %u",
                     sp.is_num);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :auth successes %u fails %u",
                     sp.is_asuc, sp.is_abad);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :Client Server");
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :connected %u %u",
                     sp.is_cl, sp.is_sv);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :bytes sent %ju %ju",
                     sp.is_cbs, sp.is_sbs);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :bytes received %ju %ju",
                     sp.is_cbr, sp.is_sbr);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "t :time connected %ju %ju",
                     sp.is_cti, sp.is_sti);
}

static void
stats_uptime(struct Client *source_p, int parc, char *parv[])
{
  if (!HasUMode(source_p, UMODE_OPER) && ConfigGeneral.stats_u_oper_only)
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
  else
  {
    sendto_one_numeric(source_p, &me, RPL_STATSUPTIME,
                       time_dissect(event_base->time.sec_monotonic - me.connection->created_monotonic));
    if (ConfigServerHide.disable_remote_commands == 0 || HasUMode(source_p, UMODE_OPER))
       sendto_one_numeric(source_p, &me, RPL_STATSCONN, Count.max_loc_con,
                          Count.max_loc, Count.totalrestartcount);
  }
}

static void
stats_shared(struct Client *source_p, int parc, char *parv[])
{
  report_shared(source_p);
  report_cluster(source_p);
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
  dlink_node *node;

  DLINK_FOREACH(node, local_server_list.head)
  {
    const struct Client *target_p = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                       "v :%s (%s!%s@%s) Idle: %s",
                       target_p->name,
                       (target_p->serv->by[0] ? target_p->serv->by : "Remote."),
                       "*", "*", time_dissect(event_base->time.sec_monotonic - target_p->connection->last_data));
  }

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "v :%u Server(s)",
                     dlink_list_length(&local_server_list));
}

static void
stats_class(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;

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
  dlink_node *node;
  uintmax_t sendB = 0, recvB = 0;

  if (ConfigServerHide.flatten_links && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
    return;
  }

  DLINK_FOREACH(node, local_server_list.head)
  {
    const struct Client *target_p = node->data;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(source_p, UMODE_OPER))
        continue;

    sendB += target_p->connection->send.bytes;
    recvB += target_p->connection->recv.bytes;

    /* ":%s 211 %s %s %u %u %ju %u %ju :%ju %ju %s" */
    sendto_one_numeric(source_p, &me, RPL_STATSLINKINFO,
               client_get_name(target_p, HasUMode(source_p, UMODE_ADMIN) ? SHOW_IP : MASK_IP),
               dbuf_length(&target_p->connection->buf_sendq),
               target_p->connection->send.messages,
               target_p->connection->send.bytes >> 10,
               target_p->connection->recv.messages,
               target_p->connection->recv.bytes >> 10,
               (event_base->time.sec_monotonic - target_p->connection->created_monotonic),
               (event_base->time.sec_monotonic - target_p->connection->last_data),
               HasUMode(source_p, UMODE_OPER) ? capab_get(target_p) : "TS");
  }

  sendB >>= 10;
  recvB >>= 10;

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT, "? :%u total server(s)",
                     dlink_list_length(&local_server_list));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT, "? :Sent total: %7.2f %s",
                     _GMKv(sendB), _GMKs(sendB));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT, "? :Recv total: %7.2f %s",
                     _GMKv(recvB), _GMKs(recvB));

  uintmax_t uptime = (event_base->time.sec_monotonic - me.connection->created_monotonic);
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "? :Server send: %7.2f %s (%4.1f KiB/s)",
                     _GMKv((me.connection->send.bytes >> 10)),
                     _GMKs((me.connection->send.bytes >> 10)),
                     (float)((float)((me.connection->send.bytes) >> 10) /
                     (float)uptime));
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "? :Server recv: %7.2f %s (%4.1f KiB/s)",
                     _GMKv((me.connection->recv.bytes >> 10)),
                     _GMKs((me.connection->recv.bytes >> 10)),
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
parse_stats_args(struct Client *source_p, int parc, char *parv[], bool *doall, bool *wilds)
{
  if (parc > 2)
  {
    const char *name = parv[2];

    if (irccmp(name, ID_or_name(&me, source_p)) == 0)
      *doall = true;
    else if (match(name, ID_or_name(&me, source_p)) == 0)
      *doall = true;

    *wilds = has_wildcards(name);

    return name;
  }

  return NULL;
}

static void
stats_L_list(struct Client *source_p, const char *name, bool doall, bool wilds,
             dlink_list *list, const char statchar)
{
  dlink_node *node;

  /*
   * Send info about connections which match, or all if the
   * mask matches from.
   */
  DLINK_FOREACH(node, list->head)
  {
    const struct Client *target_p = node->data;
    enum addr_mask_type type;

    if (!doall && wilds && match(name, target_p->name))
      continue;

    if (!(doall || wilds) && irccmp(name, target_p->name))
      continue;

    if (IsUpper(statchar))
      type = SHOW_IP;
    else
      type = HIDE_IP;

    if (IsServer(target_p) || IsConnecting(target_p) || IsHandshake(target_p))
      if (!HasUMode(source_p, UMODE_ADMIN))
        type = MASK_IP;

    sendto_one_numeric(source_p, &me, RPL_STATSLINKINFO,
                       client_get_name(target_p, type),
                       dbuf_length(&target_p->connection->buf_sendq),
                       target_p->connection->send.messages,
                       target_p->connection->send.bytes >> 10,
                       target_p->connection->recv.messages,
                       target_p->connection->recv.bytes >> 10,
                       (event_base->time.sec_monotonic - target_p->connection->created_monotonic),
                       (event_base->time.sec_monotonic - target_p->connection->last_data),
                       IsServer(target_p) ? capab_get(target_p) : "-");
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
stats_L(struct Client *source_p, const char *name, bool doall,
        bool wilds, const char statchar)
{
  stats_L_list(source_p, name, doall, wilds, &unknown_list, statchar);
  stats_L_list(source_p, name, doall, wilds, &local_client_list, statchar);
  stats_L_list(source_p, name, doall, wilds, &local_server_list, statchar);
}

static void
stats_ltrace(struct Client *source_p, int parc, char *parv[])
{
  bool doall = false;
  bool wilds = false;
  const char *name;

  if ((name = parse_stats_args(source_p, parc, parv, &doall, &wilds)))
  {
    const char statchar = *parv[1];
    stats_L(source_p, name, doall, wilds, statchar);
  }
  else
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "STATS");
}

struct StatsStruct
{
  unsigned char letter;
  void (*handler)(struct Client *, int, char *[]);
  unsigned int required_modes;
};

static const struct StatsStruct *stats_map[256];
static const struct StatsStruct  stats_tab[] =
{
  { .letter = 'a', .handler = stats_dns_servers, .required_modes = UMODE_ADMIN },
  { .letter = 'A', .handler = stats_dns_servers, .required_modes = UMODE_ADMIN },
  { .letter = 'c', .handler = stats_connect, .required_modes = UMODE_OPER },
  { .letter = 'C', .handler = stats_connect, .required_modes = UMODE_OPER },
  { .letter = 'd', .handler = stats_tdeny, .required_modes = UMODE_OPER },
  { .letter = 'D', .handler = stats_deny, .required_modes = UMODE_OPER },
  { .letter = 'e', .handler = stats_exempt, .required_modes = UMODE_OPER },
  { .letter = 'E', .handler = stats_events, .required_modes = UMODE_ADMIN },
  { .letter = 'f', .handler = stats_fdlist, .required_modes = UMODE_ADMIN },
  { .letter = 'F', .handler = stats_fdlist, .required_modes = UMODE_ADMIN },
  { .letter = 'h', .handler = stats_hubleaf, .required_modes = UMODE_OPER },
  { .letter = 'H', .handler = stats_hubleaf, .required_modes = UMODE_OPER },
  { .letter = 'i', .handler = stats_auth },
  { .letter = 'I', .handler = stats_auth },
  { .letter = 'k', .handler = stats_tkill },
  { .letter = 'K', .handler = stats_kill },
  { .letter = 'l', .handler = stats_ltrace, .required_modes = UMODE_OPER },
  { .letter = 'L', .handler = stats_ltrace, .required_modes = UMODE_OPER },
  { .letter = 'm', .handler = stats_messages },
  { .letter = 'M', .handler = stats_messages },
  { .letter = 'o', .handler = stats_operator },
  { .letter = 'O', .handler = stats_operator },
  { .letter = 'p', .handler = stats_operedup },
  { .letter = 'P', .handler = stats_ports },
  { .letter = 'q', .handler = stats_resv, .required_modes = UMODE_OPER },
  { .letter = 'Q', .handler = stats_resv, .required_modes = UMODE_OPER },
  { .letter = 's', .handler = stats_pseudo, .required_modes = UMODE_OPER },
  { .letter = 'S', .handler = stats_service, .required_modes = UMODE_OPER },
  { .letter = 't', .handler = stats_tstats, .required_modes = UMODE_OPER },
  { .letter = 'T', .handler = motd_report, .required_modes = UMODE_OPER },
  { .letter = 'u', .handler = stats_uptime },
  { .letter = 'U', .handler = stats_shared, .required_modes = UMODE_OPER },
  { .letter = 'v', .handler = stats_servers, .required_modes = UMODE_OPER },
  { .letter = 'x', .handler = stats_gecos, .required_modes = UMODE_OPER },
  { .letter = 'X', .handler = stats_gecos, .required_modes = UMODE_OPER },
  { .letter = 'y', .handler = stats_class, .required_modes = UMODE_OPER },
  { .letter = 'Y', .handler = stats_class, .required_modes = UMODE_OPER },
  { .letter = 'z', .handler = stats_memory, .required_modes = UMODE_OPER },
  { .letter = '?', .handler = stats_servlinks },
  { .letter = '\0' }
};

static void
do_stats(struct Client *source_p, int parc, char *parv[])
{
  const unsigned char statchar = *parv[1];
  const struct StatsStruct *tab;

  if (statchar == '\0')
  {
    sendto_one_numeric(source_p, &me, RPL_ENDOFSTATS, '*');
    return;
  }

  if ((tab = stats_map[statchar]))
  {
    if (tab->required_modes == 0 || HasUMode(source_p, tab->required_modes))
      tab->handler(source_p, parc, parv);
    else
      sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);

    sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                         "STATS %c requested by %s (%s@%s) [%s]",
                         statchar, source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name);
  }

  sendto_one_numeric(source_p, &me, RPL_ENDOFSTATS, statchar);
}

/*
 * m_stats()
 *      parv[0] = command
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L
 */
static void
m_stats(struct Client *source_p, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  /* Check the user is actually allowed to do /stats, and isn't flooding */
  if ((last_used + ConfigGeneral.pace_wait) > event_base->time.sec_monotonic)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "STATS");
    return;
  }

  last_used = event_base->time.sec_monotonic;

  /* Is the stats meant for us? */
  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_hunt(source_p, ":%s STATS %s :%s", 2, parv)->ret != HUNTED_ISME)
      return;

  do_stats(source_p, parc, parv);
}

/*
 * ms_stats()
 *      parv[0] = command
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L, or target
 */
static void
ms_stats(struct Client *source_p, int parc, char *parv[])
{
  if (server_hunt(source_p, ":%s STATS %s :%s", 2, parv)->ret != HUNTED_ISME)
    return;

  do_stats(source_p, parc, parv);
}

static void
stats_init(void)
{
  for (const struct StatsStruct *tab = stats_tab; tab->letter; ++tab)
    stats_map[tab->letter] = tab;
}

static struct Message stats_msgtab =
{
  .cmd = "STATS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_stats, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = ms_stats, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_stats, .args_min = 2 }
};

static void
module_init(void)
{
  stats_init();
  mod_add_cmd(&stats_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&stats_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};

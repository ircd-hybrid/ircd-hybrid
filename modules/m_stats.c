/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include "io_time.h"
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
#include "address.h"
#include "numeric.h"
#include "send.h"
#include "fdlist.h"
#include "misc.h"
#include "server.h"
#include "server_capab.h"
#include "event.h"
#include "module.h"
#include "whowas.h"
#include "monitor.h"
#include "reslib.h"
#include "motd.h"
#include "ipcache.h"
#include "channel.h"
#include "channel_invite.h"
#include "stats.h"

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

  static char buf[IO_ARRAY_LENGTH(flag_table)];
  char *bufptr = buf;

  for (const struct oper_flags *tab = flag_table; tab->flag; ++tab)
    if (flags & tab->flag)
      *bufptr++ = tab->letter;

  if (bufptr == buf)
    *bufptr++ = '0';

  *bufptr = '\0';

  return buf;
}

static void
report_shared(struct Client *client)
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

  char buf[IO_ARRAY_LENGTH(flag_table) + 1];  /* +1 for 'c' */

  list_node_t *node;
  LIST_FOREACH(node, shared_get_list()->head)
  {
    const struct SharedItem *shared = node->data;
    char *bufptr = buf;

    *bufptr++ = 'c';

    for (const struct shared_types *tab = flag_table; tab->type; ++tab)
      if (tab->type & shared->type)
        *bufptr++ = tab->letter;
      else
        *bufptr++ = ToLower(tab->letter);

    *bufptr = '\0';

    sendto_one_numeric(client, &me, RPL_STATSULINE,
                       shared->server, shared->user, shared->host, buf);
  }
}

static void
report_cluster(struct Client *client)
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

  char buf[IO_ARRAY_LENGTH(flag_table) + 1];  /* +1 for 'C' */

  list_node_t *node;
  LIST_FOREACH(node, cluster_get_list()->head)
  {
    const struct ClusterItem *cluster = node->data;
    char *bufptr = buf;

    *bufptr++ = 'C';

    for (const struct cluster_types *tab = flag_table; tab->type; ++tab)
      if (tab->type & cluster->type)
        *bufptr++ = tab->letter;
      else
        *bufptr++ = ToLower(tab->letter);

    *bufptr = '\0';

    sendto_one_numeric(client, &me, RPL_STATSULINE, cluster->server, "*", "*", buf);
  }
}

static void
stats_service(struct Client *client, int parc, char *parv[])
{
  list_node_t *node;

  LIST_FOREACH(node, service_get_list()->head)
  {
    const struct ServiceItem *service = node->data;
    sendto_one_numeric(client, &me, RPL_STATSSERVICE, "*", service->name, 0, 0);
  }
}

static void
stats_gecos(struct Client *client, int parc, char *parv[])
{
  list_node_t *node;

  LIST_FOREACH(node, gecos_get_list()->head)
  {
    const struct GecosItem *gecos = node->data;
    sendto_one_numeric(client, &me, RPL_STATSXLINE,
                       gecos->expire ? 'x' : 'X', gecos->mask, gecos->reason);
  }
}

/*
 * inputs	- pointer to client requesting confitem report
 *		- ConfType to report
 * output	- none
 * side effects	-
 */
static void
stats_operator(struct Client *client, int parc, char *parv[])
{
  if (!HasUMode(client, UMODE_OPER) && ConfigGeneral.stats_o_oper_only)
  {
    sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);
    return;
  }

  list_node_t *node;
  LIST_FOREACH(node, operator_items.head)
  {
    const struct MaskItem *conf = node->data;

    /* Don't allow non opers to see oper privs */
    if (HasUMode(client, UMODE_OPER))
      sendto_one_numeric(client, &me, RPL_STATSOLINE, 'O', conf->user, conf->host,
                         conf->name, oper_privs_as_string(conf->port),
                         conf->class->name);
    else
      sendto_one_numeric(client, &me, RPL_STATSOLINE, 'O', conf->user, conf->host,
                         conf->name, "0", conf->class->name);
  }
}

static void
stats_connect(struct Client *client, int parc, char *parv[])
{
  list_node_t *node;

  LIST_FOREACH(node, connect_items.head)
  {
    char buf[8];
    char *bufptr = buf;
    const struct MaskItem *conf = node->data;

    if (IsConfAllowAutoConn(conf))
      *bufptr++ = 'A';
    if (IsConfTLS(conf))
      *bufptr++ = 'T';
    if (bufptr == buf)
      *bufptr++ = '*';

    *bufptr = '\0';

    /*
     * Allow admins to see actual ips unless 'hide_server_ips' is enabled
     */
    if (ConfigServerHide.hide_server_ips == 0 && HasUMode(client, UMODE_ADMIN))
      sendto_one_numeric(client, &me, RPL_STATSCLINE,
                         'C', conf->host, buf, conf->name, conf->port, conf->class->name);
    else
      sendto_one_numeric(client, &me, RPL_STATSCLINE,
                         'C', "*@127.0.0.1", buf, conf->name, conf->port, conf->class->name);
  }
}

/* report_resv()
 *
 * inputs       - pointer to client pointer to report to.
 * output       - NONE
 * side effects - report all resvs to client.
 */
static void
stats_resv(struct Client *client, int parc, char *parv[])
{
  list_node_t *node;

  LIST_FOREACH(node, resv_chan_get_list()->head)
  {
    const struct ResvItem *resv = node->data;
    sendto_one_numeric(client, &me, RPL_STATSQLINE,
                       resv->expire ? 'q' : 'Q', resv->mask, resv->reason);
  }

  LIST_FOREACH(node, resv_nick_get_list()->head)
  {
    const struct ResvItem *resv = node->data;
    sendto_one_numeric(client, &me, RPL_STATSQLINE,
                       resv->expire ? 'q' : 'Q', resv->mask, resv->reason);
  }
}

static void
stats_memory(struct Client *client, int parc, char *parv[])
{
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
  unsigned int monitor_list_headers = 0;   /* monitorlist headers     */
  unsigned int monitor_list_entries = 0;   /* monitorlist entries     */
  size_t monitor_list_memory = 0; /* monitorlist memory used */
  unsigned int listener_count = 0;
  size_t listener_memory = 0;

  list_node_t *node, *node2;
  LIST_FOREACH(node, local_server_list.head)
  {
    const struct Client *target = node->data;
    local_client_conf_count += list_length(&target->connection->confs);
  }

  LIST_FOREACH(node, local_client_list.head)
  {
    const struct Client *target = node->data;
    local_client_conf_count += list_length(&target->connection->confs);
    monitor_list_entries += list_length(&target->connection->monitors);
  }

  local_client_count = list_length(&local_server_list) +
                       list_length(&local_client_list);
  remote_client_count = list_length(&global_server_list) +
                        list_length(&global_client_list) - local_client_count;

  /* Count up all members, invites, ban lists, except lists, Invex lists */
  LIST_FOREACH(node, channel_get_list()->head)
  {
    const struct Channel *channel = node->data;
    channel_members += list_length(&channel->members);
    channel_invites += list_length(&channel->invites);

    channel_bans += list_length(&channel->banlist);
    channel_ban_memory += list_length(&channel->banlist) * sizeof(struct Ban);

    channel_except += list_length(&channel->exceptlist);
    channel_except_memory += list_length(&channel->exceptlist) * sizeof(struct Ban);

    channel_invex += list_length(&channel->invexlist);
    channel_invex_memory += list_length(&channel->invexlist) * sizeof(struct Ban);
  }

  safelist_count = list_length(&listing_client_list);
  if (safelist_count)
  {
    safelist_memory = safelist_count * sizeof(struct ListTask);

    LIST_FOREACH(node, listing_client_list.head)
    {
      const struct Client *acptr = node->data;

      LIST_FOREACH(node2, acptr->connection->list_task->show_mask.head)
        safelist_memory += strlen(node2->data);

      LIST_FOREACH(node2, acptr->connection->list_task->hide_mask.head)
        safelist_memory += strlen(node2->data);
    }
  }

  monitor_count_memory(&monitor_list_headers, &monitor_list_memory);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :MONITOR headers %u(%zu) entries %u(%zu)",
                     monitor_list_headers, monitor_list_memory, monitor_list_entries,
                     monitor_list_entries * sizeof(list_node_t) * 2);

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Clients %u(%zu)",
                     list_length(&global_client_list),
                     list_length(&global_client_list) * sizeof(struct Client));

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Servers %u(%zu, %zu)",
                     list_length(&global_server_list),
                     list_length(&global_server_list) * sizeof(struct Client),
                     list_length(&global_server_list) * sizeof(struct Server));

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Attached confs %u(%zu)",
                     local_client_conf_count,
                     local_client_conf_count * sizeof(list_node_t));

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "z :Resv channels %u(%zu) nicks %u(%zu)",
                     list_length(resv_chan_get_list()),
                     list_length(resv_chan_get_list()) * sizeof(struct ResvItem),
                     list_length(resv_nick_get_list()),
                     list_length(resv_nick_get_list()) * sizeof(struct ResvItem));

  listener_count_memory(&listener_count, &listener_memory);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Listeners %u(%zu)",
                     listener_count, listener_memory);

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Classes %u(%zu)",
                     list_length(class_get_list()),
                     list_length(class_get_list()) * sizeof(struct ClassItem));

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Channels %u(%zu)",
                     list_length(channel_get_list()),
                     list_length(channel_get_list()) * sizeof(struct Channel));

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Bans %u(%zu)",
                     channel_bans, channel_ban_memory);

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Exceptions %u(%zu)",
                     channel_except, channel_except_memory);

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Invex %u(%zu)",
                     channel_invex, channel_invex_memory);

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Channel members %u(%zu) invites %u(%zu)",
                     channel_members, channel_members * sizeof(struct ChannelMember),
                     channel_invites, channel_invites * sizeof(struct Invite));

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Safelist %u(%zu)",
                     safelist_count, safelist_memory);

  whowas_count_memory(&wwu, &wwm);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Whowas users %u(%zu)",
                     wwu, wwm);

  motd_memory_count(client);

  ipcache_get_stats(&number_ips_stored, &mem_ips_stored);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :iphash %u(%zu)",
                     number_ips_stored, mem_ips_stored);

  local_client_memory_used = local_client_count * (sizeof(struct Client) + sizeof(struct Connection));
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Local client Memory in use: %u(%zu)",
                     local_client_count, local_client_memory_used);

  remote_client_memory_used = remote_client_count * sizeof(struct Client);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Remote client Memory in use: %u(%zu)",
                     remote_client_count, remote_client_memory_used);
}

static void
stats_dns_servers(struct Client *client, int parc, char *parv[])
{
  for (unsigned int i = 0; i < reslib_nscount; ++i)
  {
    char buf[HOSTIPLEN + 1];
    getnameinfo((const struct sockaddr *)&reslib_nsaddr_list[i], reslib_nsaddr_list[i].ss_len,
                buf, sizeof(buf), NULL, 0, NI_NUMERICHOST);
    sendto_one_numeric(client, &me, RPL_STATSALINE, buf);
  }
}

/* stats_deny()
 *
 * input	- client to report to
 * output	- none
 * side effects - client is given dline list.
 */
static void
stats_deny(struct Client *client, int parc, char *parv[])
{
  for (unsigned int i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    list_node_t *node;
    LIST_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_DLINE)
        continue;

      const struct MaskItem *conf = arec->conf;
      /* Don't report a temporary dline as permanent dline */
      if (conf->until)
        continue;

      sendto_one_numeric(client, &me, RPL_STATSDLINE, 'D', conf->host, conf->reason);
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
stats_tdeny(struct Client *client, int parc, char *parv[])
{
  for (unsigned int i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    list_node_t *node;
    LIST_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_DLINE)
        continue;

      const struct MaskItem *conf = arec->conf;
      /* Don't report a permanent dline as temporary dline */
      if (conf->until == 0)
        continue;

      sendto_one_numeric(client, &me, RPL_STATSDLINE, 'd', conf->host, conf->reason);
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
stats_exempt(struct Client *client, int parc, char *parv[])
{
  if (ConfigGeneral.stats_e_disabled)
  {
    sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);
    return;
  }

  for (unsigned int i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    list_node_t *node;
    LIST_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_EXEMPT)
        continue;

      const struct MaskItem *conf = arec->conf;
      sendto_one_numeric(client, &me, RPL_STATSDLINE, 'e', conf->host, "");
    }
  }
}

static void
stats_events(struct Client *client, int parc, char *parv[])
{
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "E :Operation                      Next Execution");
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT,
                     "E :---------------------------------------------");

  list_node_t *node;
  LIST_FOREACH(node, event_get_list()->head)
  {
    const struct event *ev = node->data;
    sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "E :%-30s %-4ju seconds",
                       ev->name, ev->next - io_time_get(IO_TIME_MONOTONIC_SEC));
  }
}

static void
stats_fdlist(struct Client *client, int parc, char *parv[])
{
  for (int fd = 0; fd <= highest_fd; ++fd)
  {
    const fde_t *F = &fd_table[fd];

    if (F->flags.open)
      sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "F :fd %-5d desc '%s'",
                         F->fd, F->desc);
  }
}

static void
stats_hubleaf(struct Client *client, int parc, char *parv[])
{
  list_node_t *node, *node2;

  LIST_FOREACH(node, connect_items.head)
  {
    const struct MaskItem *conf = node->data;

    LIST_FOREACH(node2, conf->hub_list.head)
      sendto_one_numeric(client, &me, RPL_STATSHLINE, 'H', node2->data, conf->name, 0, "*");
  }

  LIST_FOREACH(node, connect_items.head)
  {
    const struct MaskItem *conf = node->data;

    LIST_FOREACH(node2, conf->leaf_list.head)
      sendto_one_numeric(client, &me, RPL_STATSLLINE, 'L', node2->data, conf->name, 0, "*");
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
show_iline_prefix(const struct Client *client, const struct MaskItem *conf)
{
  static char buf[USERLEN + 16];
  char *bufptr = buf;

  if (IsConfWebIRC(conf))
    *bufptr++ = '<';
  if (IsNoTilde(conf))
    *bufptr++ = '-';
  if (IsNeedIdentd(conf))
    *bufptr++ = '+';
  if (!IsNeedPassword(conf))
    *bufptr++ = '&';
  if (IsConfExemptResv(conf))
    *bufptr++ = '$';
  if (IsConfDoSpoofIp(conf))
    *bufptr++ = '=';
  if (IsConfCanFlood(conf))
    *bufptr++ = '|';
  if (HasUMode(client, UMODE_OPER))
  {
    if (IsConfExemptKline(conf))
      *bufptr++ = '^';
    if (IsConfExemptXline(conf))
      *bufptr++ = '!';
    if (IsConfExemptLimits(conf))
      *bufptr++ = '>';
  }

  strlcpy(bufptr, conf->user, USERLEN + 1);
  return buf;
}

static void
stats_auth(struct Client *client, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_i_oper_only && !HasUMode(client, UMODE_OPER))
  {
    sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);
    return;
  }

  for (unsigned int i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    list_node_t *node;
    LIST_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_CLIENT)
        continue;

      const struct MaskItem *conf = arec->conf;
      if (IsConfDoSpoofIp(conf) && !HasUMode(client, UMODE_OPER))
        continue;

      sendto_one_numeric(client, &me, RPL_STATSILINE, 'I',
                         conf->name == NULL ? "*" : conf->name,
                         show_iline_prefix(client, conf),
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
 * Side effects: Reports configured K(or k)-lines to client.
 */
static void
stats_kill(struct Client *client, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_k_oper_only && !HasUMode(client, UMODE_OPER))
  {
    sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);
    return;
  }

  for (unsigned int i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    list_node_t *node;
    LIST_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_KLINE)
        continue;

      const struct MaskItem *conf = arec->conf;
      /* Don't report a temporary kline as permanent kline */
      if (conf->until)
        continue;

      sendto_one_numeric(client, &me, RPL_STATSKLINE,
                         'K', conf->host, conf->user, conf->reason);
    }
  }
}

static void
stats_tkill(struct Client *client, int parc, char *parv[])
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if (ConfigGeneral.stats_k_oper_only && !HasUMode(client, UMODE_OPER))
  {
    sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);
    return;
  }

  for (unsigned int i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    list_node_t *node;
    LIST_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;

      if (arec->type != CONF_KLINE)
        continue;

      const struct MaskItem *conf = arec->conf;
      /* Don't report a permanent kline as temporary kline */
      if (conf->until == 0)
        continue;

      sendto_one_numeric(client, &me, RPL_STATSKLINE, 'k', conf->host, conf->user, conf->reason);
    }
  }
}

static void
stats_messages(struct Client *client, int parc, char *parv[])
{
  if (!HasUMode(client, UMODE_OPER) && ConfigGeneral.stats_m_oper_only)
    sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);
  else
    command_report(client);
}

static void
stats_pseudo(struct Client *client, int parc, char *parv[])
{
  list_node_t *node;

  LIST_FOREACH(node, pseudo_get_list()->head)
  {
    const struct PseudoItem *pseudo = node->data;
    sendto_one_numeric(client, &me, RPL_STATSPSEUDO,
                       pseudo->command, pseudo->name, pseudo->nick, pseudo->server,
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
stats_operedup(struct Client *client, int parc, char *parv[])
{
  unsigned int count = 0;

  list_node_t *node;
  LIST_FOREACH(node, oper_list.head)
  {
    const struct Client *target = node->data;

    if (HasUMode(target, UMODE_HIDDEN) && !HasUMode(client, UMODE_OPER))
      continue;

    const char *duration = "n/a";
    if (HasUMode(client, UMODE_OPER) || !HasUMode(target, UMODE_HIDEIDLE))
      duration = time_format_duration(client_get_idle_time(client, target));

    if (MyConnect(client) && HasUMode(client, UMODE_OPER))
      sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "p :[%c][%s] %s (%s@%s) Idle: %s",
                         HasUMode(target, UMODE_ADMIN) ? 'A' : 'O',
                         oper_privs_as_string(target->connection->operflags),
                         target->name, target->username, target->host, duration);
    else
      sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "p :[%c] %s (%s@%s) Idle: %s",
                         HasUMode(target, UMODE_ADMIN) ? 'A' : 'O',
                         target->name, target->username, target->host, duration);
    ++count;
  }

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "p :%u OPER(s)", count);
}

/* show_ports()
 *
 * inputs       - pointer to client to show ports to
 * output       - none
 * side effects - send port listing to a client
 */
static void
stats_ports(struct Client *client, int parc, char *parv[])
{
  if (ConfigGeneral.stats_P_oper_only && !HasUMode(client, UMODE_OPER))
  {
    sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);
    return;
  }

  list_node_t *node;
  LIST_FOREACH(node, listener_get_list()->head)
  {
    char buf[8];
    char *bufptr = buf;
    const struct Listener *listener = node->data;

    if (listener_has_flag(listener, LISTENER_HIDDEN))
    {
      if (!HasUMode(client, UMODE_ADMIN))
        continue;
      *bufptr++ = 'H';
    }

    if (listener_has_flag(listener, LISTENER_SERVER))
      *bufptr++ = 'S';
    if (listener_has_flag(listener, LISTENER_CLIENT))
      *bufptr++ = 'C';
    if (listener_has_flag(listener, LISTENER_TLS))
      *bufptr++ = 'T';
    if (listener_has_flag(listener, LISTENER_DEFER))
      *bufptr++ = 'D';
    *bufptr = '\0';

    if (HasUMode(client, UMODE_ADMIN) && ConfigServerHide.hide_server_ips == 0)
      sendto_one_numeric(client, &me, RPL_STATSPLINE,
                         'P', listener->port, listener->name, listener->ref_count, buf,
                         listener->active == true ? "active" : "disabled");
    else
      sendto_one_numeric(client, &me, RPL_STATSPLINE,
                         'P', listener->port, me.name, listener->ref_count, buf,
                         listener->active == true ? "active" : "disabled");
  }
}

static void
stats_tstats(struct Client *client, int parc, char *parv[])
{
  struct ServerStatistics sp = ServerStats;

  list_node_t *node;
  LIST_FOREACH(node, local_server_list.head)
  {
    const struct Client *target = node->data;
    sp.is_sbs += target->connection->send.bytes;
    sp.is_sbr += target->connection->recv.bytes;
    sp.is_sti += io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->created_monotonic;
    sp.is_sv++;
  }

  LIST_FOREACH(node, local_client_list.head)
  {
    const struct Client *target = node->data;
    sp.is_cbs += target->connection->send.bytes;
    sp.is_cbr += target->connection->recv.bytes;
    sp.is_cti += io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->created_monotonic;
    sp.is_cl++;
  }

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :accepts %u refused %u",
                     sp.is_ac, sp.is_ref);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :unknown commands %u prefixes %u",
                     sp.is_unco, sp.is_unpf);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :nick collisions %u unknown closes %u",
                     sp.is_kill, sp.is_ni);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :wrong direction %u empty %u",
                     sp.is_wrdi, sp.is_empt);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :numerics seen %u",
                     sp.is_num);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :auth successes %u fails %u",
                     sp.is_asuc, sp.is_abad);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :Client Server");
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :connected %u %u",
                     sp.is_cl, sp.is_sv);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :bytes sent %zu %zu",
                     sp.is_cbs, sp.is_sbs);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :bytes received %zu %zu",
                     sp.is_cbr, sp.is_sbr);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "t :time connected %ju %ju",
                     sp.is_cti, sp.is_sti);
}

static void
stats_uptime(struct Client *client, int parc, char *parv[])
{
  if (!HasUMode(client, UMODE_OPER) && ConfigGeneral.stats_u_oper_only)
    sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);
  else
  {
    sendto_one_numeric(client, &me, RPL_STATSUPTIME,
                       time_format_duration(io_time_get(IO_TIME_MONOTONIC_SEC) - me.connection->created_monotonic));
    if (ConfigServerHide.disable_remote_commands == 0 || HasUMode(client, UMODE_OPER))
       sendto_one_numeric(client, &me, RPL_STATSCONN, Count.max_loc_con,
                          Count.max_loc, Count.totalrestartcount);
  }
}

static void
stats_shared(struct Client *client, int parc, char *parv[])
{
  report_shared(client);
  report_cluster(client);
}

/* stats_servers()
 *
 * input	- client pointer
 * output	- none
 * side effects - client is shown lists of who connected servers
 */
static void
stats_servers(struct Client *client, int parc, char *parv[])
{
  list_node_t *node;

  LIST_FOREACH(node, local_server_list.head)
  {
    const struct Client *target = node->data;
    sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "v :%s (%s!%s@%s) Idle: %s",
                       target->name, (target->serv->by[0] ? target->serv->by : "Remote."),
                       "*", "*", time_format_duration(io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_data));
  }

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "v :%u Server(s)",
                     list_length(&local_server_list));
}

static void
stats_class(struct Client *client, int parc, char *parv[])
{
  list_node_t *node;

  LIST_FOREACH(node, class_get_list()->head)
  {
    const struct ClassItem *class = node->data;
    sendto_one_numeric(client, &me, RPL_STATSYLINE, 'Y',
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
stats_servlinks(struct Client *client, int parc, char *parv[])
{
  size_t send_bytes = 0, recv_bytes = 0;

  list_node_t *node;
  LIST_FOREACH(node, local_server_list.head)
  {
    const struct Client *target = node->data;
    send_bytes += target->connection->send.bytes;
    recv_bytes += target->connection->recv.bytes;

    /* ":%s 211 %s %s %u %u %zu %u %zu :%ju %ju %s" */
    sendto_one_numeric(client, &me, RPL_STATSLINKINFO,
                       client_get_name(target, HasUMode(client, UMODE_ADMIN) ? SHOW_IP : MASK_IP),
                       dbuf_length(&target->connection->buf_sendq),
                       target->connection->send.messages,
                       target->connection->send.bytes >> 10,
                       target->connection->recv.messages,
                       target->connection->recv.bytes >> 10,
                       (io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->created_monotonic),
                       (io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_data),
                       capab_get(target, true));
  }

  send_bytes >>= 10;
  recv_bytes >>= 10;

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "? :%u total server(s)",
                     list_length(&local_server_list));
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "? :Sent total: %7.2f %s",
                     _GMKv(send_bytes), _GMKs(send_bytes));
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "? :Recv total: %7.2f %s",
                     _GMKv(recv_bytes), _GMKs(recv_bytes));

  const uintmax_t uptime = (io_time_get(IO_TIME_MONOTONIC_SEC) - me.connection->created_monotonic);
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "? :Server send: %7.2f %s (%4.1f KiB/s)",
                     _GMKv((me.connection->send.bytes >> 10)),
                     _GMKs((me.connection->send.bytes >> 10)),
                     (float)((float)((me.connection->send.bytes) >> 10) / (float)uptime));
  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "? :Server recv: %7.2f %s (%4.1f KiB/s)",
                     _GMKv((me.connection->recv.bytes >> 10)),
                     _GMKs((me.connection->recv.bytes >> 10)),
                     (float)((float)((me.connection->recv.bytes) >> 10) / (float)uptime));
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
parse_stats_args(struct Client *client, int parc, char *parv[], bool *doall, bool *wilds)
{
  const char *const name = parv[2];

  if (EmptyString(name))
    return NULL;

  if (irccmp(name, ID_or_name(&me, client)) == 0)
    *doall = true;
  else if (match(name, ID_or_name(&me, client)) == 0)
    *doall = true;

  *wilds = has_wildcards(name);
  return name;
}

static void
stats_L_list(struct Client *client, const char *name, bool doall, bool wilds,
             list_t *list, unsigned char letter)
{
  list_node_t *node;

  /*
   * Send info about connections which match, or all if the
   * mask matches from.
   */
  LIST_FOREACH(node, list->head)
  {
    const struct Client *target = node->data;
    enum addr_mask_type type;

    if (!doall && wilds && match(name, target->name))
      continue;

    if (!(doall || wilds) && irccmp(name, target->name))
      continue;

    if (IsUpper(letter))
      type = SHOW_IP;
    else
      type = HIDE_IP;

    if (IsServer(target) || IsConnecting(target) || IsHandshake(target))
      if (!HasUMode(client, UMODE_ADMIN))
        type = MASK_IP;

    sendto_one_numeric(client, &me, RPL_STATSLINKINFO,
                       client_get_name(target, type),
                       dbuf_length(&target->connection->buf_sendq),
                       target->connection->send.messages,
                       target->connection->send.bytes >> 10,
                       target->connection->recv.messages,
                       target->connection->recv.bytes >> 10,
                       (io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->created_monotonic),
                       (io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_data),
                       IsServer(target) ? capab_get(target, true) : "-");
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
stats_L(struct Client *client, const char *name, bool doall, bool wilds, unsigned char letter)
{
  stats_L_list(client, name, doall, wilds, &unknown_list, letter);
  stats_L_list(client, name, doall, wilds, &local_client_list, letter);
  stats_L_list(client, name, doall, wilds, &local_server_list, letter);
}

static void
stats_ltrace(struct Client *client, int parc, char *parv[])
{
  bool doall = false;
  bool wilds = false;
  const char *name;

  if ((name = parse_stats_args(client, parc, parv, &doall, &wilds)))
  {
    unsigned char letter = *parv[1];
    stats_L(client, name, doall, wilds, letter);
  }
  else
    sendto_one_numeric(client, &me, ERR_NEEDMOREPARAMS, "STATS");
}

static const struct StatsHandler stats_tab[] =
{
  STATS_HANDLER_INIT('a', stats_dns_servers, UMODE_ADMIN),
  STATS_HANDLER_INIT('A', stats_dns_servers, UMODE_ADMIN),
  STATS_HANDLER_INIT('c', stats_connect, UMODE_OPER),
  STATS_HANDLER_INIT('C', stats_connect, UMODE_OPER),
  STATS_HANDLER_INIT('d', stats_tdeny, UMODE_OPER),
  STATS_HANDLER_INIT('D', stats_deny, UMODE_OPER),
  STATS_HANDLER_INIT('e', stats_exempt, UMODE_OPER),
  STATS_HANDLER_INIT('E', stats_events, UMODE_ADMIN),
  STATS_HANDLER_INIT('f', stats_fdlist, UMODE_ADMIN),
  STATS_HANDLER_INIT('F', stats_fdlist, UMODE_ADMIN),
  STATS_HANDLER_INIT('h', stats_hubleaf, UMODE_OPER),
  STATS_HANDLER_INIT('H', stats_hubleaf, UMODE_OPER),
  STATS_HANDLER_INIT('i', stats_auth, 0),
  STATS_HANDLER_INIT('I', stats_auth, 0),
  STATS_HANDLER_INIT('k', stats_tkill, 0),
  STATS_HANDLER_INIT('K', stats_kill, 0),
  STATS_HANDLER_INIT('l', stats_ltrace, UMODE_OPER),
  STATS_HANDLER_INIT('L', stats_ltrace, UMODE_OPER),
  STATS_HANDLER_INIT('m', stats_messages, 0),
  STATS_HANDLER_INIT('M', stats_messages, 0),
  STATS_HANDLER_INIT('o', stats_operator, 0),
  STATS_HANDLER_INIT('O', stats_operator, 0),
  STATS_HANDLER_INIT('p', stats_operedup, 0),
  STATS_HANDLER_INIT('P', stats_ports, 0),
  STATS_HANDLER_INIT('q', stats_resv, UMODE_OPER),
  STATS_HANDLER_INIT('Q', stats_resv, UMODE_OPER),
  STATS_HANDLER_INIT('s', stats_pseudo, UMODE_OPER),
  STATS_HANDLER_INIT('S', stats_service, UMODE_OPER),
  STATS_HANDLER_INIT('t', stats_tstats, UMODE_OPER),
  STATS_HANDLER_INIT('T', motd_report, UMODE_OPER),
  STATS_HANDLER_INIT('u', stats_uptime, 0),
  STATS_HANDLER_INIT('U', stats_shared, UMODE_OPER),
  STATS_HANDLER_INIT('v', stats_servers, UMODE_OPER),
  STATS_HANDLER_INIT('x', stats_gecos, UMODE_OPER),
  STATS_HANDLER_INIT('X', stats_gecos, UMODE_OPER),
  STATS_HANDLER_INIT('y', stats_class, UMODE_OPER),
  STATS_HANDLER_INIT('Y', stats_class, UMODE_OPER),
  STATS_HANDLER_INIT('z', stats_memory, UMODE_OPER),
  STATS_HANDLER_INIT('?', stats_servlinks, UMODE_OPER)
};

static void
do_stats(struct Client *client, int parc, char *parv[])
{
  const unsigned char letter = *parv[1];
  const struct StatsHandler *handler = stats_find(letter);

  if (handler)
  {
    if (stats_allowed(handler, client->umodes))
      handler->handler(client, parc, parv);
    else
      sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);

    sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "STATS %c requested by %s (%s@%s) [%s]",
                         letter, client->name, client->username, client->host, client->servptr->name);
  }

  sendto_one_numeric(client, &me, RPL_ENDOFSTATS, letter);
}

/*
 * m_stats()
 *      parv[0] = command
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L
 */
static void
m_stats(struct Client *client, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  /* Check the user is actually allowed to do /stats, and isn't flooding */
  if ((last_used + ConfigGeneral.pace_wait) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(client, &me, RPL_LOAD2HI, "STATS");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  /* Is the stats meant for us? */
  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_route_command(client, ":%s STATS %s :%s", 2, parv)->result != SERVER_ROUTE_ISME)
      return;

  do_stats(client, parc, parv);
}

/*
 * ms_stats()
 *      parv[0] = command
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L, or target
 */
static void
ms_stats(struct Client *client, int parc, char *parv[])
{
  if (server_route_command(client, ":%s STATS %s :%s", 2, parv)->result != SERVER_ROUTE_ISME)
    return;

  do_stats(client, parc, parv);
}

static struct Command command_table =
{
  .name = "STATS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_stats, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = ms_stats, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = ms_stats, .args_min = 2 }
};

static void
init_handler(void)
{
  stats_register_array(stats_tab, IO_ARRAY_LENGTH(stats_tab));
  command_add(&command_table);
}

static void
exit_handler(void)
{
  stats_unregister_array(stats_tab, IO_ARRAY_LENGTH(stats_tab));
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};

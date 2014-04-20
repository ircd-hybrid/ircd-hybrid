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

/*! \file m_info.c
 * \brief Includes required functions for processing the INFO command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_misc.h"
#include "s_serv.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"


/*
 * jdc -- Structure for our configuration value table
 */
struct InfoStruct
{
  const char *name;         /* Displayed variable name           */
  const unsigned int output_type; /* See below #defines                */
  const void *option;             /* Pointer reference to the value    */
  const char *desc;         /* ASCII description of the variable */
};

/* Types for output_type in InfoStruct */
#define OUTPUT_STRING     0x0001  /* Output option as %s w/ dereference  */
#define OUTPUT_STRING_PTR 0x0002  /* Output option as %s w/out deference */
#define OUTPUT_DECIMAL    0x0004  /* Output option as decimal (%d)       */
#define OUTPUT_BOOLEAN    0x0008  /* Output option as "ON" or "OFF"      */
#define OUTPUT_BOOLEAN_YN 0x0010  /* Output option as "YES" or "NO"      */
#define OUTPUT_BOOLEAN2   0x0020  /* Output option as "YES/NO/MASKED"    */

static const struct InfoStruct info_table[] =
{
  /* --[  START OF TABLE  ]-------------------------------------------- */

  {
    "DPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.dpath,
    "Root directory of installation"
  },
  {
    "SPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.spath,
    "Path to server executable"
  },
  {
    "MPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.mpath,
    "Path to main motd (Message of the Day) file"
  },
  {
    "CPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.configfile,
    "Path to main configuration file"
  },
  {
    "DLPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.dlinefile,
    "Path to D-line database file"
  },
  {
    "KPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.klinefile,
    "Path to K-line database file"
  },
  {
    "GPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.glinefile,
    "Path to G-line database file"
  },
  {
    "XPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.xlinefile,
    "Path to X-line database file"
  },
  {
    "RESVPATH",
    OUTPUT_STRING,
    &ConfigFileEntry.resvfile,
    "Path to resv database file"
  },
  {
    "network_name",
    OUTPUT_STRING,
    &ServerInfo.network_name,
    "Network name"
  },
  {
    "network_desc",
    OUTPUT_STRING,
    &ServerInfo.network_desc,
    "Network description"
  },
  {
    "hub",
    OUTPUT_BOOLEAN_YN,
    &ServerInfo.hub,
    "Server is a hub"
  },
  {
    "max_clients",
    OUTPUT_DECIMAL,
    &ServerInfo.max_clients,
    "Maximum number of clients permitted simultaneously on this server"
  },
  {
    "max_nick_length",
    OUTPUT_DECIMAL,
    &ServerInfo.max_nick_length,
    "Maximum nickname length"
  },
  {
    "max_topic_length",
    OUTPUT_DECIMAL,
    &ServerInfo.max_topic_length,
    "Maximum topic length"
  },
  {
    "use_logging",
    OUTPUT_BOOLEAN_YN,
    &ConfigLoggingEntry.use_logging,
    "Enable logging"
  },
  {
    "disable_fake_channels",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.disable_fake_channels,
    "Forbids channels with special ASCII characters in their name"
  },
  {
    "knock_delay",
    OUTPUT_DECIMAL,
    &ConfigChannel.knock_delay,
    "Delay between a users KNOCK attempts"
  },
  {
    "knock_delay_channel",
    OUTPUT_DECIMAL,
    &ConfigChannel.knock_delay_channel,
    "Delay between KNOCK attempts to a channel"
  },
  {
    "max_chans_per_user",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_chans_per_user,
    "Maximum number of channels a user can join"
  },
  {
    "max_chans_per_oper",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_chans_per_oper,
    "Maximum number of channels an oper can join"
  },
  {
    "max_bans",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_bans,
    "Total +b/e/I modes allowed in a channel"
  },
  {
    "default_split_user_count",
    OUTPUT_DECIMAL,
    &ConfigChannel.default_split_user_count,
    "Startup value of SPLITUSERS"
  },
  {
    "default_split_server_count",
    OUTPUT_DECIMAL,
    &ConfigChannel.default_split_server_count,
    "Startup value of SPLITNUM"
  },
  {
    "no_create_on_split",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.no_create_on_split,
    "Disallow creation of channels when split"
  },
  {
    "no_join_on_split",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.no_join_on_split,
    "Disallow joining channels when split"
  },
  {
    "flatten_links",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.flatten_links,
    "Flatten /links list"
  },
  {
    "links_delay",
    OUTPUT_DECIMAL,
    &ConfigServerHide.links_delay,
    "Links rehash delay"
  },
  {
    "hidden",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.hidden,
    "Hide this server from a flattened /links on remote servers"
  },
  {
    "hide_servers",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.hide_servers,
    "Hide servernames from users"
  },
  {
    "hide_services",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.hide_services,
    "Hides the location of services server"
  },
  {
    "hidden_name",
    OUTPUT_STRING,
    &ConfigServerHide.hidden_name,
    "Server name users see if hide_servers = yes"
  },
  {
    "hide_server_ips",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.hide_server_ips,
    "Prevent people from seeing server IP addresses"
  },
  {
    "gline_min_cidr",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.gline_min_cidr,
    "Minimum required length of a CIDR bitmask for IPv4 G-Lines"
  },
  {
    "gline_min_cidr6",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.gline_min_cidr6,
    "Minimum required length of a CIDR bitmask for IPv6 G-Lines"
  },
  {
    "invisible_on_connect",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.invisible_on_connect,
    "Automatically set mode +i on connecting users"
  },
  {
    "kill_chase_time_limit",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.kill_chase_time_limit,
    "Nick Change Tracker for KILL"
  },
  {
    "hide_spoof_ips",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.hide_spoof_ips,
    "Hide spoofed IP addresses"
  },
  {
    "ignore_bogus_ts",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.ignore_bogus_ts,
    "Ignore bogus timestamps from other servers"
  },
  {
    "cycle_on_host_change",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.cycle_on_host_change,
    "Send a fake QUIT/JOIN combination on host change"
  },
  {
    "disable_auth",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.disable_auth,
    "Completely disable ident lookups"
  },
  {
    "disable_remote_commands",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.disable_remote_commands,
    "Prevent users issuing commands on remote servers"
  },
  {
    "tkline_expire_notices",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.tkline_expire_notices,
    "Show temporary kline/xline expire notices"
  },
  {
    "default_floodcount",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.default_floodcount,
    "Startup value of FLOODCOUNT"
  },
  {
    "failed_oper_notice",
    OUTPUT_BOOLEAN,
    &ConfigFileEntry.failed_oper_notice,
    "Inform opers if someone tries to /oper with the wrong password"
  },
  {
    "dots_in_ident",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.dots_in_ident,
    "Number of permissable dots in an ident"
  },
  {
    "min_nonwildcard",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.min_nonwildcard,
    "Minimum non-wildcard chars in K/G lines"
  },
  {
    "min_nonwildcard_simple",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.min_nonwildcard_simple,
    "Minimum non-wildcards in gecos bans"
  },
  {
    "max_accept",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.max_accept,
    "Maximum nicknames on accept list"
  },
  {
    "anti_nick_flood",
    OUTPUT_BOOLEAN,
    &ConfigFileEntry.anti_nick_flood,
    "NICK flood protection"
  },
  {
    "max_nick_time",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.max_nick_time,
    "NICK flood protection time interval"
  },
  {
    "max_nick_changes",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.max_nick_changes,
    "NICK change threshhold setting"
  },
  {
    "anti_spam_exit_message_time",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.anti_spam_exit_message_time,
    "Duration a client must be connected for to have an exit message"
  },
  {
    "ts_warn_delta",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.ts_warn_delta,
    "Maximum permitted TS delta before displaying a warning"
  },
  {
    "ts_max_delta",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.ts_max_delta,
    "Maximum permitted TS delta from another server"
  },
  {
    "warn_no_nline",
    OUTPUT_BOOLEAN,
    &ConfigFileEntry.warn_no_nline,
    "Display warning if connecting server lacks N-line"
  },
  {
    "stats_e_disabled",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.stats_e_disabled,
    "Whether or not STATS e is disabled"
  },
  {
    "stats_o_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.stats_o_oper_only,
    "STATS O output is only shown to operators"
  },
  {
    "stats_P_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.stats_P_oper_only,
    "STATS P is only shown to operators"
  },
  {
    "stats_u_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.stats_u_oper_only,
    "STATS u is only shown to operators"
  },
  {
    "stats_i_oper_only",
    OUTPUT_BOOLEAN2,
    &ConfigFileEntry.stats_i_oper_only,
    "STATS I output is only shown to operators"
  },
  {
    "stats_k_oper_only",
    OUTPUT_BOOLEAN2,
    &ConfigFileEntry.stats_k_oper_only,
    "STATS K output is only shown to operators"
  },
  {
    "caller_id_wait",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.caller_id_wait,
    "Minimum delay between notifying UMODE +g users of messages"
  },
  {
    "opers_bypass_callerid",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.opers_bypass_callerid,
    "Allows IRC operators to message users who are +g (callerid)"
  },
  {
    "pace_wait_simple",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.pace_wait_simple,
    "Minimum delay between less intensive commands"
  },
  {
    "pace_wait",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.pace_wait,
    "Minimum delay between uses of certain commands"
  },
  {
    "short_motd",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.short_motd,
    "Do not show MOTD; only tell clients they should read it"
  },
  {
    "ping_cookie",
    OUTPUT_BOOLEAN,
    &ConfigFileEntry.ping_cookie,
    "Require ping cookies to connect"
  },
  {
    "no_oper_flood",
    OUTPUT_BOOLEAN,
    &ConfigFileEntry.no_oper_flood,
    "Reduce flood control for operators"
  },
  {
    "true_no_oper_flood",
    OUTPUT_BOOLEAN,
    &ConfigFileEntry.true_no_oper_flood,
    "Completely disable flood control for operators"
  },
  {
    "oper_pass_resv",
    OUTPUT_BOOLEAN_YN,
    &ConfigFileEntry.oper_pass_resv,
    "Opers can over-ride RESVs"
  },
  {
    "max_targets",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.max_targets,
    "The maximum number of PRIVMSG/NOTICE targets"
  },
  {
    "throttle_time",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.throttle_time,
    "Minimum time between client reconnects"
  },
  {
    "glines",
    OUTPUT_BOOLEAN,
    &ConfigFileEntry.glines,
    "G-line (network-wide K-line) support"
  },
  {
    "gline_duration",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.gline_time,
    "Expiry time for G-lines"
  },
  {
    "gline_request_duration",
    OUTPUT_DECIMAL,
    &ConfigFileEntry.gline_request_time,
    "Expiry time for pending G-lines"
  },

  /* --[  END OF TABLE  ]---------------------------------------------- */
  {
    NULL,
    0,
    NULL,
    0
  }
};

/* send_birthdate_online_time()
 *
 * inputs	- client pointer to send to
 * output	- NONE
 * side effects	- birthdate and online time are sent
 */
static void
send_birthdate_online_time(struct Client *source_p)
{
  sendto_one(source_p, ":%s %d %s :On-line since %s",
             ID_or_name(&me, source_p), RPL_INFO,
             ID_or_name(source_p, source_p),
             myctime(me.localClient->firsttime));
}

/* send_conf_options()
 *
 * inputs	- client pointer to send to
 * output	- NONE
 * side effects	- send config options to client
 */
static void
send_conf_options(struct Client *source_p)
{
  const struct InfoStruct *iptr = NULL;

  /*
   * Parse the info_table[] and do the magic.
   */
  for (iptr = info_table; iptr->name; ++iptr)
  {
    switch (iptr->output_type)
    {
      /* For "char *" references */
      case OUTPUT_STRING:
      {
        const char *option = *((const char *const *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   ID_or_name(&me, source_p), RPL_INFO, ID_or_name(source_p, source_p),
                   iptr->name, option ? option : "NONE",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* For "char foo[]" references */
      case OUTPUT_STRING_PTR:
      {
        const char *option = iptr->option;

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   ID_or_name(&me, source_p), RPL_INFO, ID_or_name(source_p, source_p),
                   iptr->name, option ? option : "NONE",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* Output info_table[i].option as a decimal value. */
      case OUTPUT_DECIMAL:
      {
        const int option = *((const int *const)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5d [%-30s]",
                   ID_or_name(&me, source_p), RPL_INFO, ID_or_name(source_p, source_p),
                   iptr->name, option, iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* Output info_table[i].option as "ON" or "OFF" */
      case OUTPUT_BOOLEAN:
      {
        const int option = *((const int *const)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   ID_or_name(&me, source_p), RPL_INFO, ID_or_name(source_p, source_p),
                   iptr->name, option ? "ON" : "OFF",
                   iptr->desc ? iptr->desc : "<none>");

        break;
      }

      /* Output info_table[i].option as "YES" or "NO" */
      case OUTPUT_BOOLEAN_YN:
      {
        const int option = *((const int *const)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   ID_or_name(&me, source_p), RPL_INFO, ID_or_name(source_p, source_p),
                   iptr->name, option ? "YES" : "NO",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      case OUTPUT_BOOLEAN2:
      {
        const int option = *((const int *const)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   ID_or_name(&me, source_p), RPL_INFO, ID_or_name(source_p, source_p),
                   iptr->name, option ? ((option == 1) ? "MASK" : "YES") : "NO",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }
    }
  }

  sendto_one_numeric(source_p, &me, RPL_INFO, "");
}

/* send_info_text()
 *
 * inputs       - client pointer to send info text to
 * output       - NONE
 * side effects - info text is sent to client
 */
static void
send_info_text(struct Client *source_p)
{
  const char **text = infotext;

  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "INFO requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  while (*text)
  {
    const char *line = *text++;

    if (*line == '\0')
      line = " ";

    sendto_one_numeric(source_p, &me, RPL_INFO, line);
  }

  if (HasUMode(source_p, UMODE_OPER))
    send_conf_options(source_p);

  send_birthdate_online_time(source_p);

  sendto_one_numeric(source_p, &me, RPL_ENDOFINFO);
}

/*! \brief INFO command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static int
m_info(struct Client *source_p, int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI);
    return 0;
  }

  last_used = CurrentTime;

  if (!ConfigServerHide.disable_remote_commands)
    if (hunt_server(source_p, ":%s INFO :%s", 1,
                    parc, parv) != HUNTED_ISME)
      return 0;

  send_info_text(source_p);
  return 0;
}

/*! \brief INFO command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static int
ms_info(struct Client *source_p, int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s INFO :%s", 1,
                  parc, parv) != HUNTED_ISME)
    return 0;

  send_info_text(source_p);
  return 0;
}

static struct Message info_msgtab =
{
  "INFO", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_info, ms_info, m_ignore, ms_info, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&info_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&info_msgtab);
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

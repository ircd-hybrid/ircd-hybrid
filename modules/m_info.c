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

/*! \file m_info.c
 * \brief Includes required functions for processing the INFO command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "misc.h"
#include "server.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "tls.h"


/*
 * jdc -- Structure for our configuration value table
 */
struct InfoStruct
{
  const char *name;  /* Displayed variable name */
  enum
  {
    OUTPUT_STRING = 1,  /* Output option as %s w/ dereference  */
    OUTPUT_STRING_PTR,  /* Output option as %s w/out deference */
    OUTPUT_DECIMAL,  /* Output option as decimal (%d) */
    OUTPUT_BOOLEAN,  /* Output option as "ON" or "OFF" */
    OUTPUT_BOOLEAN_YN  /* Output option as "YES" or "NO" */
  } output_type;  /* Type of output. See enum above */

  const void *option;  /* Pointer reference to the value */
  const char *desc;  /* ASCII description of the variable */
};

static const struct InfoStruct info_table[] =
{
  /* --[  START OF TABLE  ]-------------------------------------------- */

  {
    "DPATH",
    OUTPUT_STRING,
    &ConfigGeneral.dpath,
    "Root directory of installation"
  },
  {
    "SPATH",
    OUTPUT_STRING,
    &ConfigGeneral.spath,
    "Path to server executable"
  },
  {
    "MPATH",
    OUTPUT_STRING,
    &ConfigGeneral.mpath,
    "Path to main motd (Message of the Day) file"
  },
  {
    "CPATH",
    OUTPUT_STRING,
    &ConfigGeneral.configfile,
    "Path to main configuration file"
  },
  {
    "DLPATH",
    OUTPUT_STRING,
    &ConfigGeneral.dlinefile,
    "Path to D-line database file"
  },
  {
    "KPATH",
    OUTPUT_STRING,
    &ConfigGeneral.klinefile,
    "Path to K-line database file"
  },
  {
    "XPATH",
    OUTPUT_STRING,
    &ConfigGeneral.xlinefile,
    "Path to X-line database file"
  },
  {
    "RESVPATH",
    OUTPUT_STRING,
    &ConfigGeneral.resvfile,
    "Path to resv database file"
  },
  {
    "network_name",
    OUTPUT_STRING,
    &ConfigServerInfo.network_name,
    "Network name"
  },
  {
    "network_description",
    OUTPUT_STRING,
    &ConfigServerInfo.network_description,
    "Network description"
  },
  {
    "hub",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerInfo.hub,
    "Server is a hub"
  },
  {
    "default_max_clients",
    OUTPUT_DECIMAL,
    &ConfigServerInfo.default_max_clients,
    "The default maximum number of clients permitted simultaneously on this server"
  },
  {
    "max_nick_length",
    OUTPUT_DECIMAL,
    &ConfigServerInfo.max_nick_length,
    "Maximum nickname length"
  },
  {
    "max_topic_length",
    OUTPUT_DECIMAL,
    &ConfigServerInfo.max_topic_length,
    "Maximum topic length"
  },
  {
    "use_logging",
    OUTPUT_BOOLEAN_YN,
    &ConfigLog.use_logging,
    "Enable logging"
  },
  {
    "enable_extbans",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.enable_extbans,
    "Whether or not to enable extbans"
  },
  {
    "enable_owner",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.enable_owner,
    "Enables channel prefix mode +q (channel owner)"
  },
  {
    "enable_admin",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.enable_admin,
    "Enables channel prefix mode +a (channel admin)"
  },
  {
    "disable_fake_channels",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.disable_fake_channels,
    "Forbids channels with special ASCII characters in their name"
  },
  {
    "invite_client_count",
    OUTPUT_DECIMAL,
    &ConfigChannel.invite_client_count,
    "How many INVITE attempts are permitted in invite_client_time"
  },
  {
    "invite_client_time",
    OUTPUT_DECIMAL,
    &ConfigChannel.invite_client_time,
    "How many invite_client_count invites are allowed in this time"
  },
  {
    "invite_delay_channel",
    OUTPUT_DECIMAL,
    &ConfigChannel.invite_delay_channel,
    "Delay between INVITE attempts to a channel"
  },
  {
    "invite_expire_time",
    OUTPUT_DECIMAL,
    &ConfigChannel.invite_expire_time,
    "Amount of time an INVITE will be active until it expires"
  },
  {
    "knock_client_count",
    OUTPUT_DECIMAL,
    &ConfigChannel.knock_client_count,
    "How many KNOCK attempts are permitted in knock_client_time"
  },
  {
    "knock_client_time",
    OUTPUT_DECIMAL,
    &ConfigChannel.knock_client_time,
    "How many knock_client_count knocks are allowed in this time"
  },
  {
    "knock_delay_channel",
    OUTPUT_DECIMAL,
    &ConfigChannel.knock_delay_channel,
    "Delay between KNOCK attempts to a channel"
  },
  {
    "max_channels",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_channels,
    "Maximum number of channels a user can join"
  },
  {
    "max_invites",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_invites,
    "Maximum number of channels a user can be invited to"
  },
  {
    "max_bans",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_bans,
    "Total +b/e/I modes allowed in a channel"
  },
  {
    "max_bans_large",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_bans_large,
    "Total +b/e/I modes allowed in a +L channel"
  },
  {
    "flatten_links",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.flatten_links,
    "Flatten /links list"
  },
  {
    "flatten_links_delay",
    OUTPUT_DECIMAL,
    &ConfigServerHide.flatten_links_delay,
    "Links rehash delay"
  },
  {
    "flatten_links_file",
    OUTPUT_STRING,
    &ConfigServerHide.flatten_links_file,
    "Path to the flatten links cache file"
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
    "away_count",
    OUTPUT_DECIMAL,
    &ConfigGeneral.away_count,
    "How many AWAY attempts are permitted in away_time"
  },
  {
    "away_time",
    OUTPUT_DECIMAL,
    &ConfigGeneral.away_time,
    "How many away_count aways are allowed in this time"
  },
  {
    "dline_min_cidr",
    OUTPUT_DECIMAL,
    &ConfigGeneral.dline_min_cidr,
    "Minimum required length of a CIDR bitmask for IPv4 D-Lines"
  },
  {
    "dline_min_cidr6",
    OUTPUT_DECIMAL,
    &ConfigGeneral.dline_min_cidr6,
    "Minimum required length of a CIDR bitmask for IPv6 D-Lines"
  },
  {
    "kline_min_cidr",
    OUTPUT_DECIMAL,
    &ConfigGeneral.kline_min_cidr,
    "Minimum required length of a CIDR bitmask for IPv4 K-Lines"
  },
  {
    "kline_min_cidr6",
    OUTPUT_DECIMAL,
    &ConfigGeneral.kline_min_cidr6,
    "Minimum required length of a CIDR bitmask for IPv6 K-Lines"
  },
  {
    "invisible_on_connect",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.invisible_on_connect,
    "Automatically set mode +i on connecting users"
  },
  {
    "kill_chase_time_limit",
    OUTPUT_DECIMAL,
    &ConfigGeneral.kill_chase_time_limit,
    "Nick Change Tracker for KILL"
  },
  {
    "cycle_on_host_change",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.cycle_on_host_change,
    "Send a fake QUIT/JOIN combination on host change"
  },
  {
    "disable_auth",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.disable_auth,
    "Completely disable ident lookups"
  },
  {
    "disable_remote_commands",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.disable_remote_commands,
    "Prevent users issuing commands on remote servers"
  },
  {
    "default_floodcount",
    OUTPUT_DECIMAL,
    &ConfigGeneral.default_floodcount,
    "Startup value of FLOODCOUNT"
  },
  {
    "default_floodtime",
    OUTPUT_DECIMAL,
    &ConfigGeneral.default_floodtime,
    "Startup value of FLOODTIME"
  },
  {
    "failed_oper_notice",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.failed_oper_notice,
    "Inform opers if someone tries to /oper with the wrong credentials"
  },
  {
    "specials_in_ident",
    OUTPUT_DECIMAL,
    &ConfigGeneral.specials_in_ident,
    "Number of permissable '-', '_', or '.' characters in an ident"
  },
  {
    "min_nonwildcard",
    OUTPUT_DECIMAL,
    &ConfigGeneral.min_nonwildcard,
    "Minimum non-wildcard chars in K/D lines"
  },
  {
    "min_nonwildcard_simple",
    OUTPUT_DECIMAL,
    &ConfigGeneral.min_nonwildcard_simple,
    "Minimum non-wildcards in gecos bans"
  },
  {
    "max_monitor",
    OUTPUT_DECIMAL,
    &ConfigGeneral.max_monitor,
    "Maximum nicknames on monitor list"
  },
  {
    "max_accept",
    OUTPUT_DECIMAL,
    &ConfigGeneral.max_accept,
    "Maximum nicknames on accept list"
  },
  {
    "whowas_history_length",
    OUTPUT_DECIMAL,
    &ConfigGeneral.whowas_history_length,
    "Length of the WHOWAS nick name history list"
  },
  {
    "anti_nick_flood",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.anti_nick_flood,
    "NICK flood protection"
  },
  {
    "max_nick_time",
    OUTPUT_DECIMAL,
    &ConfigGeneral.max_nick_time,
    "NICK flood protection time interval"
  },
  {
    "max_nick_changes",
    OUTPUT_DECIMAL,
    &ConfigGeneral.max_nick_changes,
    "NICK change threshhold setting"
  },
  {
    "anti_spam_exit_message_time",
    OUTPUT_DECIMAL,
    &ConfigGeneral.anti_spam_exit_message_time,
    "Duration a client must be connected for to have an exit message"
  },
  {
    "ts_warn_delta",
    OUTPUT_DECIMAL,
    &ConfigGeneral.ts_warn_delta,
    "Maximum permitted TS delta before displaying a warning"
  },
  {
    "ts_max_delta",
    OUTPUT_DECIMAL,
    &ConfigGeneral.ts_max_delta,
    "Maximum permitted TS delta from another server"
  },
  {
    "warn_no_connect_block",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.warn_no_connect_block,
    "Display warning if connecting server lacks a connect{} block"
  },
  {
    "stats_e_disabled",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.stats_e_disabled,
    "Whether or not STATS e is disabled"
  },
  {
    "stats_m_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.stats_m_oper_only,
    "STATS m output is only shown to operators"
  },
  {
    "stats_o_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.stats_o_oper_only,
    "STATS O output is only shown to operators"
  },
  {
    "stats_P_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.stats_P_oper_only,
    "STATS P output is only shown to operators"
  },
  {
    "stats_u_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.stats_u_oper_only,
    "STATS u output is only shown to operators"
  },
  {
    "stats_i_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.stats_i_oper_only,
    "STATS I output is only shown to operators"
  },
  {
    "stats_k_oper_only",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.stats_k_oper_only,
    "STATS K output is only shown to operators"
  },
  {
    "caller_id_wait",
    OUTPUT_DECIMAL,
    &ConfigGeneral.caller_id_wait,
    "Minimum delay between notifying UMODE +g users of messages"
  },
  {
    "opers_bypass_callerid",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.opers_bypass_callerid,
    "Allows IRC operators to message users who are +g (callerid)"
  },
  {
    "pace_wait_simple",
    OUTPUT_DECIMAL,
    &ConfigGeneral.pace_wait_simple,
    "Minimum delay between less intensive commands"
  },
  {
    "pace_wait",
    OUTPUT_DECIMAL,
    &ConfigGeneral.pace_wait,
    "Minimum delay between uses of certain commands"
  },
  {
    "short_motd",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.short_motd,
    "Do not show MOTD; only tell clients they should read it"
  },
  {
    "ping_cookie",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.ping_cookie,
    "Require ping cookies to connect"
  },
  {
    "no_oper_flood",
    OUTPUT_BOOLEAN_YN,
    &ConfigGeneral.no_oper_flood,
    "Reduce flood control for operators"
  },
  {
    "max_targets",
    OUTPUT_DECIMAL,
    &ConfigGeneral.max_targets,
    "The maximum number of PRIVMSG/NOTICE targets"
  },
  {
    "throttle_count",
    OUTPUT_DECIMAL,
    &ConfigGeneral.throttle_count,
    "Number of connects in throttle_time before connections are blocked"
  },
  {
    "throttle_time",
    OUTPUT_DECIMAL,
    &ConfigGeneral.throttle_time,
    "Minimum time between client reconnects"
  },

  /* --[  END OF TABLE  ]---------------------------------------------- */
  {
    NULL,
    0,
    NULL,
    NULL
  }
};

static const char *infotext[] =
{
  "ircd-hybrid --",
  "Based on the original code written by Jarkko Oikarinen",
  "Copyright (c) 1988-1991 University of Oulu, Computing Center",
  "Copyright (c) 1997-2022 ircd-hybrid development team",
  "",
  "This program is free software; you can redistribute it and/or",
  "modify it under the terms of the GNU General Public License as",
  "published by the Free Software Foundation; either version 2, or",
  "(at your option) any later version.",
  "",
  "",
  "The core team as of this major release:",
  "",
  "Dianora, Diane Bruce <db@db.net>",
  "Michael, Michael Wobst <michael@wobst.fr>",
  "Rodder, Jon Lusky <lusky@blown.net>",
  "Wohali, Joan Touzet <joant@ieee.org>",
  "",
  "The following people have contributed blood, sweat, and/or code to",
  "recent releases of ircd-hybrid, in nick alphabetical order:",
  "",
  "A1kmm, Andrew Miller <a1kmm@mware.virtualave.net>",
  "Adam, Adam <Adam@anope.org>",
  "Adrian Chadd <adrian@creative.net.au>",
  "adx, Piotr Nizynski <nizynski@sysplex.pl>",
  "AndroSyn, Aaron Sethman <androsyn@ratbox.org>",
  "bane, Dragan Dosen <bane@idolnet.org>",
  "billy-jon, William Bierman III <bill@thebiermans.org>",
  "bysin, Ben Kittridge <bkittridge@cfl.rr.com>",
  "cosine, Patrick Alken <wnder@uwns.underworld.net>",
  "cryogen, Stuart Walsh <stu@ipng.org.uk>",
  "David-T, David Taylor <davidt@yadt.co.uk>",
  "Dom, Dominic Hargreaves <dom@earth.li>",
  "Fawkes, Christoph Ostermeier <fawkes@phat-net.de>",
  "fgeek, Henri Salo <henri@nerv.fi>",
  "fl, Lee Hardy <lee@leeh.co.uk>",
  "Garion, Joost Vunderink <garion@efnet.nl>",
  "Habeeb, David Supuran <habeeb@cfl.rr.com>",
  "Hwy101, W. Campbell <wcampbel@botbay.net>",
  "jmallett, Juli Mallett <jmallett@FreeBSD.org>",
  "joshk, Joshua Kwan <joshk@triplehelix.org>",
  "jv, Jakub Vlasek <jv@pilsedu.cz>",
  "k9, Jeremy Chadwick <ircd@jdc.parodius.com>",
  "kire, Erik Small <smalle@hawaii.edu>",
  "knight, Alan LeVee <alan.levee@prometheus-designs.net>",
  "kre, Dinko Korunic <kreator@fly.srk.fer.hr>",
  "madmax, Paul Lomax <madmax@efnet.org>",
  "metalrock, Jack Low <xxjack12xx@gmail.com>",
  "r0d3nt, Andrew Strutt <andrew.strutt@gmail.com>",
  "Riedel, Dennis Vink <dennis@drvink.com>",
  "scuzzy, David Todd <scuzzy@aniverse.net>",
  "spookey, David Colburn <spookey@spookey.org>",
  "TimeMr14C, Yusuf Iskenderoglu <uhc0@stud.uni-karlsruhe.de>",
  "toot, Toby Verrall <to7@antipope.fsnet.co.uk>",
  "vx0, Mark Miller <mark@oc768.net>",
  "wiz, Jason Dambrosio <jason@wiz.cx>",
  "Xride, S\xC3\xB8ren Straarup <xride@x12.dk>",
  "zb^3, Alfred Perlstein <alfred@freebsd.org>",
  "",
  NULL
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
  sendto_one_numeric(source_p, &me, RPL_INFO | SND_EXPLICIT,
                     ":On-line since %s",
                     date(me.connection->created_real));
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
  /*
   * Parse the info_table[] and do the magic.
   */
  for (const struct InfoStruct *iptr = info_table; iptr->name; ++iptr)
  {
    switch (iptr->output_type)
    {
      /* For "char *" references */
      case OUTPUT_STRING:
      {
        const char *option = *((const char *const *)iptr->option);

        sendto_one_numeric(source_p, &me, RPL_INFO | SND_EXPLICIT,
                           ":%-30s %-5s [%s]",
                           iptr->name, option ? option : "NONE",
                           iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* For "char foo[]" references */
      case OUTPUT_STRING_PTR:
      {
        const char *option = iptr->option;

        sendto_one_numeric(source_p, &me, RPL_INFO | SND_EXPLICIT,
                           ":%-30s %-5s [%s]",
                           iptr->name, option ? option : "NONE",
                           iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* Output info_table[i].option as a decimal value. */
      case OUTPUT_DECIMAL:
      {
        const unsigned int option = *((const unsigned int *const)iptr->option);

        sendto_one_numeric(source_p, &me, RPL_INFO | SND_EXPLICIT,
                           ":%-30s %-5u [%s]",
                           iptr->name, option, iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* Output info_table[i].option as "ON" or "OFF" */
      case OUTPUT_BOOLEAN:
      {
        const unsigned int option = *((const unsigned int *const)iptr->option);

        sendto_one_numeric(source_p, &me, RPL_INFO | SND_EXPLICIT,
                           ":%-30s %-5s [%s]",
                           iptr->name, option ? "ON" : "OFF",
                           iptr->desc ? iptr->desc : "<none>");

        break;
      }

      /* Output info_table[i].option as "YES" or "NO" */
      case OUTPUT_BOOLEAN_YN:
      {
        const unsigned int option = *((const unsigned int *const)iptr->option);

        sendto_one_numeric(source_p, &me, RPL_INFO | SND_EXPLICIT,
                           ":%-30s %-5s [%s]",
                           iptr->name, option ? "YES" : "NO",
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
  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "INFO requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  for (const char **text = infotext; *text; ++text)
  {
    const char *line = *text;

    if (*line == '\0')
      line = " ";

    sendto_one_numeric(source_p, &me, RPL_INFO, line);
  }

  if (HasUMode(source_p, UMODE_OPER))
  {
    send_conf_options(source_p);

    if (tls_is_initialized())
      sendto_one_numeric(source_p, &me, RPL_INFO, tls_get_version());
  }

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
static void
m_info(struct Client *source_p, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait) > event_base->time.sec_monotonic)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "INFO");
    return;
  }

  last_used = event_base->time.sec_monotonic;

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_hunt(source_p, ":%s INFO :%s", 1, parv)->ret != HUNTED_ISME)
      return;

  send_info_text(source_p);
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
static void
ms_info(struct Client *source_p, int parc, char *parv[])
{
  if (server_hunt(source_p, ":%s INFO :%s", 1, parv)->ret != HUNTED_ISME)
    return;

  send_info_text(source_p);
}

static struct Message info_msgtab =
{
  .cmd = "INFO",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_info },
  .handlers[SERVER_HANDLER] = { .handler = ms_info },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = ms_info }
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};

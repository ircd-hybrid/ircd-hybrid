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

/*! \file m_gline.c
 * \brief Includes required functions for processing the GLINE/GUNGLINE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "s_gline.h"
#include "channel.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "hostmask.h"
#include "numeric.h"
#include "s_bsd.h"
#include "s_misc.h"
#include "send.h"
#include "s_serv.h"
#include "hash.h"
#include "parse.h"
#include "modules.h"
#include "log.h"
#include "conf_db.h"
#include "memory.h"

#define GLINE_NOT_PLACED     0
#define GLINE_ALREADY_VOTED -1
#define GLINE_PLACED         1


static void
check_gline(struct AddressRec *arec)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, local_client_list.head)
  {
    struct Client *client_p = ptr->data;

    if (IsDead(client_p))
      continue;

    if (match(arec->username, client_p->username))
      continue;

    switch (arec->masktype)
    {
      case HM_IPV4:
        if (client_p->localClient->aftype == AF_INET)
          if (match_ipv4(&client_p->localClient->ip, &arec->Mask.ipa.addr, arec->Mask.ipa.bits))
            conf_try_ban(client_p, arec->conf);
        break;
      case HM_IPV6:
        if (client_p->localClient->aftype == AF_INET6)
          if (match_ipv6(&client_p->localClient->ip, &arec->Mask.ipa.addr, arec->Mask.ipa.bits))
            conf_try_ban(client_p, arec->conf);
        break;
      default:  /* HM_HOST */
        if (!match(arec->Mask.hostname, client_p->host))
          conf_try_ban(client_p, arec->conf);
        break;
    }
  }
}

/*! \brief Adds a GLINE to the configuration subsystem.
 *
 * \param source_p Operator requesting gline
 * \param user     Username covered by the gline
 * \param host     Hostname covered by the gline
 * \param reason   Reason for the gline
 */
static void
set_local_gline(const struct Client *source_p, const char *user,
                const char *host, const char *reason)
{
  char buffer[IRCD_BUFSIZE];
  struct MaskItem *conf = conf_make(CONF_GLINE);

  snprintf(buffer, sizeof(buffer), "%s (%s)", reason, smalldate(CurrentTime));
  conf->reason = xstrdup(buffer);
  conf->user = xstrdup(user);
  conf->host = xstrdup(host);

  conf->setat = CurrentTime;
  conf->until = CurrentTime + ConfigFileEntry.gline_time;
  SetConfDatabase(conf);

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                       "%s added G-Line for [%s@%s] [%s]",
                       get_oper_name(source_p),
                       conf->user, conf->host, conf->reason);
  ilog(LOG_TYPE_GLINE, "%s added G-Line for [%s@%s] [%s]",
       get_oper_name(source_p), conf->user, conf->host, conf->reason);

  check_gline(add_conf_by_address(CONF_GLINE, conf));
}

/*! \brief Removes a GLINE from the configuration subsystem.
 *
 * \param user     Username covered by the gline
 * \param host     Hostname covered by the gline
 */
static int
remove_gline_match(const char *user, const char *host)
{
  struct irc_ssaddr iphost, *piphost;
  struct MaskItem *conf;
  int t = 0;
  int aftype = 0;

  if ((t = parse_netmask(host, &iphost, NULL)) != HM_HOST)
  {
#ifdef IPV6
    if (t == HM_IPV6)
      aftype = AF_INET6;
    else
#endif
      aftype = AF_INET;
    piphost = &iphost;
  }
  else
    piphost = NULL;

  if ((conf = find_conf_by_address(host, piphost, CONF_GLINE, aftype, user, NULL, 0)))
  {
    if (IsConfDatabase(conf))
    {
      delete_one_address_conf(host, conf);
      return 1;
    }
  }

  return 0;
}

/*! \brief This function is called once a majority of opers have agreed on a
 *         GLINE/GUNGLINE, and it can be placed. The information about an
 *         operator being passed to us happens to be the operator who pushed us
 *         over the "majority" level needed. See check_majority() for more
 *         information.
 *
 * \param source_p Operator requesting gline
 * \param user     Username covered by the gline
 * \param host     Hostname covered by the gline
 * \param reason   Reason for the gline
 * \param type     Valid values are either GLINE_PENDING_ADD_TYPE, or
 *                 GLINE_PENDING_DEL_TYPE
 */
static void
add_new_majority(const struct Client *source_p, const char *user,
                 const char *host, const char *reason, const unsigned int type)
{
  struct gline_pending *pending = MyMalloc(sizeof(struct gline_pending));

  strlcpy(pending->vote_1.oper_nick, source_p->name, sizeof(pending->vote_1.oper_nick));
  strlcpy(pending->vote_1.oper_user, source_p->username, sizeof(pending->vote_1.oper_user));
  strlcpy(pending->vote_1.oper_host, source_p->host, sizeof(pending->vote_1.oper_host));
  strlcpy(pending->vote_1.oper_server, source_p->servptr->name, sizeof(pending->vote_1.oper_server));

  strlcpy(pending->user, user, sizeof(pending->user));
  strlcpy(pending->host, host, sizeof(pending->host));
  strlcpy(pending->vote_1.reason, reason, sizeof(pending->vote_1.reason));

  pending->last_gline_time = CurrentTime;
  pending->vote_1.time_request = CurrentTime;

  dlinkAdd(pending, &pending->node, &pending_glines[type]);
}

/*! \brief See if there is a majority agreement on a GLINE on the given user.
 *         There must be at least 3 different opers agreeing on this
 *         GLINE/GUNGLINE
 *
 * \param source_p Operator requesting gline
 * \param user     Username covered by the gline
 * \param host     Hostname covered by the gline
 * \param reason   Reason for the gline
 * \param type     Valid values are either GLINE_PENDING_ADD_TYPE, or
 *                 GLINE_PENDING_DEL_TYPE 
 *
 * \return
 *         - GLINE_ALREADY_VOTED  returned if oper/server has already voted
 *         - GLINE_PLACED         returned if this triggers a gline
 *         - GLINE_NOT_PLACED     returned if not triggered
 */
static int
check_majority(const struct Client *source_p, const char *user,
               const char *host, const char *reason, const int type)
{
  dlink_node *dn_ptr = NULL;

  cleanup_glines(NULL);

  /* if its already glined, why bother? :) -- fl_ */
  if ((type == GLINE_PENDING_ADD_TYPE) && find_is_glined(host, user))
    return GLINE_NOT_PLACED;

  DLINK_FOREACH(dn_ptr, pending_glines[type].head)
  {
    struct gline_pending *gp_ptr = dn_ptr->data;

    if (irccmp(gp_ptr->user, user) ||
        irccmp(gp_ptr->host, host))
      continue;

    if ((!irccmp(gp_ptr->vote_1.oper_user, source_p->username) &&
        !irccmp(gp_ptr->vote_1.oper_host, source_p->host))     ||
        !irccmp(gp_ptr->vote_1.oper_server, source_p->servptr->name))
      return GLINE_ALREADY_VOTED;

    if (gp_ptr->vote_2.oper_user[0] != '\0')
    {
      /* if two other opers on two different servers have voted yes */
      if ((!irccmp(gp_ptr->vote_2.oper_user, source_p->username) &&
          !irccmp(gp_ptr->vote_2.oper_host, source_p->host))     ||
          !irccmp(gp_ptr->vote_2.oper_server, source_p->servptr->name))
        return GLINE_ALREADY_VOTED;

      if (type == GLINE_PENDING_DEL_TYPE)
      {
        if (remove_gline_match(user, host))
        {
          sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                               "%s has removed the G-Line for: [%s@%s]",
                               get_oper_name(source_p), user, host);
          ilog(LOG_TYPE_GLINE, "%s removed G-Line for [%s@%s]",
               get_oper_name(source_p), user, host);
        }
      }
      else
        /* trigger the gline using the original reason --fl */
        set_local_gline(source_p, user, host, gp_ptr->vote_1.reason);

      cleanup_glines(gp_ptr);
      return GLINE_PLACED;
    }

    strlcpy(gp_ptr->vote_2.oper_nick, source_p->name,
            sizeof(gp_ptr->vote_2.oper_nick));
    strlcpy(gp_ptr->vote_2.oper_user, source_p->username,
            sizeof(gp_ptr->vote_2.oper_user));
    strlcpy(gp_ptr->vote_2.oper_host, source_p->host,
            sizeof(gp_ptr->vote_2.oper_host));
    strlcpy(gp_ptr->vote_2.reason, reason,
            sizeof(gp_ptr->vote_2.reason));
    strlcpy(gp_ptr->vote_2.oper_server, source_p->servptr->name,
            sizeof(gp_ptr->vote_2.oper_server));
    gp_ptr->last_gline_time = CurrentTime;
    gp_ptr->vote_2.time_request = CurrentTime;
    return GLINE_NOT_PLACED;
  }

  /*
   * Didn't find this user@host gline in pending gline list
   * so add it.
   */
  add_new_majority(source_p, user, host, reason, type);
  return GLINE_NOT_PLACED;
}

/* ms_gline()
 *
 * inputs       - The usual for a m_ function
 * output       -
 * side effects -
 *
 * Place a G line if 3 opers agree on the identical user@host
 *
 * Allow this server to pass along GLINE if received and
 * GLINES is not defined.
 *
 */
static int
ms_gline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  const char *reason = NULL;      /* reason for "victims" demise       */
  const char *user = NULL;
  const char *host = NULL;        /* user and host of GLINE "victim"   */
  const char *p = NULL;

  if (!IsClient(source_p))
    return 0;

  if (parc != 4 || EmptyString(parv[3]))
    return 0;

  assert(source_p->servptr != NULL);

  user   = parv[1];
  host   = parv[2];
  reason = parv[3];

  sendto_server(source_p->from, CAP_GLN|CAP_TS6, NOCAPS,
                ":%s GLINE %s %s :%s",
                ID(source_p), user, host, reason);
  sendto_server(source_p->from, CAP_GLN, CAP_TS6,
                ":%s GLINE %s %s :%s",
                source_p->name, user, host, reason);

  if (!ConfigFileEntry.glines)
    return 0;

  if (!valid_wild_card(source_p, 1, 2, user, host))
    return 0;

  if ((p = strchr(host, '/')))
  {
    int bitlen = strtol(++p, NULL, 10);
    int min_bitlen = strchr(host, ':') ? ConfigFileEntry.gline_min_cidr6 :
                                             ConfigFileEntry.gline_min_cidr;

    if (bitlen < min_bitlen)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s is requesting a GLINE with a CIDR mask < %d for [%s@%s] [%s]",
                           get_oper_name(source_p), min_bitlen,
                           user, host, reason);
      return 0;
    }
  }

  /* If at least 3 opers agree this user should be G lined then do it */
  if (check_majority(source_p, user, host, reason, GLINE_PENDING_ADD_TYPE) ==
      GLINE_ALREADY_VOTED)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "oper or server has already voted");
    return 0;
  }

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                        "%s requesting G-Line for [%s@%s] [%s]",
                        get_oper_name(source_p),
                        user, host, reason);
  ilog(LOG_TYPE_GLINE, "G-Line for [%s@%s] [%s] requested by %s",
       user, host, reason, get_oper_name(source_p));
  return 0;
}

/*! \brief GLINE command handler (called by operators)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = user\@host mask
 *      - parv[2] = reason
 */
static int
mo_gline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *user = NULL;
  char *host = NULL;
  char *reason = NULL;
  char *p;

  if (!HasOFlag(source_p, OPER_FLAG_GLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "gline");
    return 0;
  }

  if (!ConfigFileEntry.glines)
  {
    sendto_one_notice(source_p, &me, ":GLINE disabled");
    return 0;
  }

  if (parse_aline("GLINE", source_p, parc, parv, AWILD,
                  &user, &host, NULL, NULL, &reason) < 0)
    return 0;

  if ((p = strchr(host, '/')) != NULL)
  {
    int bitlen = strtol(++p, NULL, 10);
    int min_bitlen = strchr(host, ':') ? ConfigFileEntry.gline_min_cidr6 :
                                         ConfigFileEntry.gline_min_cidr;
    if (bitlen < min_bitlen)
    {
      sendto_one_notice(source_p, &me, ":Cannot set G-Lines with CIDR length < %d",
                        min_bitlen);
      return 0;
    }
  }
  
  /* If at least 3 opers agree this user should be G lined then do it */
  if (check_majority(source_p, user, host, reason, GLINE_PENDING_ADD_TYPE) ==
      GLINE_ALREADY_VOTED)
  {
    sendto_one_notice(source_p, &me, ":This server or oper has already voted");
    return 0;
  }

  /*
   * call these two functions first so the 'requesting' notice always comes
   * before the 'has triggered' notice.  -bill
   */
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                       "%s requesting G-Line for [%s@%s] [%s]",
                       get_oper_name(source_p),
                       user, host, reason);
  ilog(LOG_TYPE_GLINE, "G-Line for [%s@%s] [%s] requested by %s",
       user, host, reason, get_oper_name(source_p));

  /* 4 param version for hyb-7 servers */
  sendto_server(NULL, CAP_GLN|CAP_TS6, NOCAPS,
		":%s GLINE %s %s :%s",
		ID(source_p), user, host, reason);
  sendto_server(NULL, CAP_GLN, CAP_TS6,
		":%s GLINE %s %s :%s",
		source_p->name, user, host, reason);
  return 0;
}

static void
do_sungline(struct Client *source_p, const char *user,
            const char *host, const char *reason, int prop)
{
  assert(source_p->servptr != NULL);

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                       "%s requesting UNG-Line for [%s@%s] [%s]",
                       get_oper_name(source_p), user, host, reason);
  ilog(LOG_TYPE_GLINE, "UNG-Line for [%s@%s] [%s] requested by %s",
       user, host, reason, get_oper_name(source_p));

  /* If at least 3 opers agree this user should be un G lined then do it */
  if (check_majority(source_p, user, host, reason, GLINE_PENDING_DEL_TYPE) ==
      GLINE_ALREADY_VOTED)
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "oper or server has already voted");

  if (prop)
  {
    sendto_server(source_p->from, CAP_ENCAP|CAP_TS6, NOCAPS,
                  ":%s ENCAP * GUNGLINE %s %s :%s",
                  ID(source_p), user, host, reason);
    sendto_server(source_p->from, CAP_ENCAP, CAP_TS6,
                  ":%s ENCAP * GUNGLINE %s %s :%s",
                  source_p->name, user, host, reason);
  }
}

/*! \brief GUNGLINE command handler (called in response to an encapsulated
 *                  GUNGLINE command)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = username
 *      - parv[2] = hostname
 *      - parv[3] = reason
 */
static int
me_gungline(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  if (ConfigFileEntry.glines)
    do_sungline(source_p, parv[1], parv[2], parv[3], 0);
  return 0;
}

/*! \brief GUNGLINE command handler (called by operators)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = user\@host mask
 *      - parv[2] = reason
 */
static int
mo_gungline(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  char *user = NULL;
  char *host = NULL;
  char *reason = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_GLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "gline");
    return 0;
  }

  if (!ConfigFileEntry.glines)
  {
    sendto_one_notice(source_p, &me, ":GUNGLINE disabled");
    return 0;
  }

  if (parse_aline("GUNGLINE", source_p, parc, parv, 0, &user,
                  &host, NULL, NULL, &reason) < 0)
    return 0;

  do_sungline(source_p, user, host, reason, 1);
  return 0;
}

/*
 * gline enforces 3 parameters to force operator to give a reason
 * a gline is not valid with "No reason"
 * -db
 */
static struct Message gline_msgtab =
{
  "GLINE", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_gline, m_ignore, mo_gline, m_ignore }
};

static struct Message ungline_msgtab =
{
  "GUNGLINE", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, me_gungline, mo_gungline, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&gline_msgtab);
  mod_add_cmd(&ungline_msgtab);
  add_capability("GLN", CAP_GLN, 1);
}

static void
module_exit(void)
{
  mod_del_cmd(&gline_msgtab);
  mod_del_cmd(&ungline_msgtab);
  delete_capability("GLN");
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

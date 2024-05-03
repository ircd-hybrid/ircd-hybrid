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

#include "stdinc.h"
#include "irc_string.h"
#include "numeric.h"
#include "conf.h"
#include "client.h"
#include "send.h"
#include "aline.h"

/* valid_wild_card_simple()
 *
 * inputs       - data to check for sufficient non-wildcard characters
 * outputs      - 1 if valid, else 0
 * side effects - none
 */
bool
valid_wild_card_simple(const char *data)
{
  const unsigned char *p = (const unsigned char *)data;
  unsigned char tmpch = '\0';
  unsigned int nonwild = 0, wild = 0;

  while ((tmpch = *p++))
  {
    if (tmpch == '\\' && *p)
    {
      ++p;
      if (++nonwild >= ConfigGeneral.min_nonwildcard_simple)
        return true;
    }
    else if (!IsMWildChar(tmpch))
    {
      if (++nonwild >= ConfigGeneral.min_nonwildcard_simple)
        return true;
    }
    else
      ++wild;
  }

  return wild == 0;
}

/* valid_wild_card()
 *
 * input        - pointer to client
 *		- int flag, 0 for no warning oper 1 for warning oper
 *		- count of following varargs to check
 * output       - 0 if not valid, 1 if valid
 * side effects - NOTICE is given to client if warn is 1
 */
bool
valid_wild_card(int count, ...)
{
  unsigned char tmpch = '\0';
  unsigned int nonwild = 0;
  va_list args;

  /*
   * Now we must check the user and host to make sure there
   * are at least NONWILDCHARS non-wildcard characters in
   * them, otherwise assume they are attempting to kline
   * *@* or some variant of that. This code will also catch
   * people attempting to kline *@*.tld, as long as NONWILDCHARS
   * is greater than 3. In that case, there are only 3 non-wild
   * characters (tld), so if NONWILDCHARS is 4, the kline will
   * be disallowed.
   * -wnder
   */

  va_start(args, count);

  while (count--)
  {
    const unsigned char *p = va_arg(args, const unsigned char *);
    if (p == NULL)
      continue;

    while ((tmpch = *p++))
    {
      if (!IsKWildChar(tmpch))
      {
        /*
         * If we find enough non-wild characters, we can
         * break - no point in searching further.
         */
        if (++nonwild >= ConfigGeneral.min_nonwildcard)
        {
          va_end(args);
          return true;
        }
      }
    }
  }

  va_end(args);
  return false;
}

static intmax_t
valid_aline_time(const char *data)
{
  static const unsigned int max_aline_time = 24*60*360;
  const unsigned char *p = (const unsigned char *)data;
  unsigned char tmpch = '\0';
  intmax_t result = 0;

  while ((tmpch = *p++))
  {
    if (!IsDigit(tmpch))
      return -1;

    result *= 10;
    result += (tmpch & 0xF);
  }

  if (result > max_aline_time)
    result = max_aline_time;

  result = result * 60;  /* Turn it into seconds */

  return result;
}

/* parse_aline
 *
 * input        - pointer to cmd name being used
 *              - pointer to client using cmd
 *              - parc parameter count
 *              - parv[] list of parameters to parse
 *		- parse_flags bit map of things to test
 *		- pointer to user or string to parse into
 *              - pointer to host or NULL to parse into if non NULL
 *              - pointer to optional tkline time or NULL
 *              - pointer to target_server to parse into if non NULL
 *              - pointer to reason to parse into
 *
 * output       - 1 if valid, 0 if not valid
 * side effects - A generalised k/d/x etc. line parser,
 *               "ALINE [time] user@host|string [ON] target :reason"
 *                will parse returning a parsed user, host if
 *                h_p pointer is non NULL, string otherwise.
 *                if tkline_time pointer is non NULL a tk line will be set
 *                to non zero if found.
 *                if tkline_time pointer is NULL and tk line is found,
 *                error is reported.
 *                if target_server is NULL and an "ON" is found error
 *                is reported.
 *                if reason pointer is NULL ignore pointer,
 *                this allows use of parse_a_line in unkline etc.
 *
 * - Dianora
 */
bool
parse_aline(const char *cmd, struct Client *client, int parc, char **parv, struct aline_ctx *aline)
{
  static char default_reason[] = CONF_NOREASON;
  static char user[USERLEN * 2 + 1];
  static char host[HOSTLEN * 2 + 1];
  intmax_t duration;

  ++parv;
  --parc;

  if (aline->add && (duration = valid_aline_time(*parv)) >= 0)
  {
    aline->duration = duration;
    ++parv;
    --parc;
  }

  if (parc == 0)
  {
    sendto_one_numeric(client, &me, ERR_NEEDMOREPARAMS, cmd);
    return false;
  }

  if (aline->simple_mask)
  {
    aline->mask = *parv;
    aline->user = NULL;
    aline->host = NULL;
  }
  else
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = *parv;
    nuh.nickptr  = NULL;
    nuh.userptr  = user;
    nuh.hostptr  = host;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(user);
    nuh.hostsize = sizeof(host);

    split_nuh(&nuh);

    aline->mask = NULL;
    aline->user = user;
    aline->host = host;
  }

  ++parv;
  --parc;

  if (parc)
  {
    if (irccmp(*parv, "ON") == 0)
    {
      ++parv;
      --parc;

      if (!HasOFlag(client, OPER_FLAG_REMOTEBAN))
      {
        sendto_one_numeric(client, &me, ERR_NOPRIVS, "remoteban");
        return false;
      }

      if (parc == 0 || EmptyString(*parv))
      {
        sendto_one_numeric(client, &me, ERR_NEEDMOREPARAMS, cmd);
        return false;
      }

      aline->server = *parv;
      ++parv;
      --parc;
    }
    else
      aline->server = NULL;
  }

  if (aline->add)
  {
    if (parc == 0 || EmptyString(*parv))
      aline->reason = default_reason;
    else
      aline->reason = *parv;
  }

  return true;
}

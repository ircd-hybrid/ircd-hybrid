/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include "io_string.h"
#include "aline.h"
#include "client.h"
#include "conf.h"
#include "conf_oper.h"
#include "nuh.h"
#include "numeric.h"
#include "send.h"

bool
aline_valid_mask_simple(const char *data)
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

bool
aline_valid_mask(int count, ...)
{
  unsigned char tmpch = '\0';
  unsigned int nonwild = 0;

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
  va_list args;
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
_aline_valid_time(const char *data)
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

bool
aline_parse(const char *cmd, struct Client *client, int parc, char *parv[], struct aline_ctx *aline)
{
  static char default_reason[] = CONF_NOREASON;
  static char user[USERLEN * 2 + 1];
  static char host[HOSTLEN * 2 + 1];
  intmax_t duration;

  ++parv;
  --parc;

  if (aline->add && (duration = _aline_valid_time(*parv)) >= 0)
  {
    aline->duration = duration;
    ++parv;
    --parc;
  }

  if (parc == 0 || string_is_empty(*parv))
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
    struct nuh_split nuh =
    {
      .nuhmask = *parv,
      .nickptr = NULL,
      .userptr = user,
      .hostptr = host,
      .nicksize = 0,
      .usersize = sizeof(user),
      .hostsize = sizeof(host)
    };

    nuh_split(&nuh);

    aline->mask = NULL;
    aline->user = user;
    aline->host = host;
  }

  ++parv;
  --parc;

  if (parc)
  {
    if (io_strcasecmp(*parv, "ON") == 0)
    {
      ++parv;
      --parc;

      if (!client_has_oper_flag(client, OPER_FLAG_REMOTEBAN))
      {
        sendto_one_numeric(client, &me, ERR_NOPRIVS, "remoteban");
        return false;
      }

      if (parc == 0 || string_is_empty(*parv))
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
    if (parc == 0 || string_is_empty(*parv))
      aline->reason = default_reason;
    else
      aline->reason = *parv;
  }

  return true;
}

/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include "io_parse.h"
#include "io_string.h"

#include "aline.h"
#include "client.h"
#include "conf.h"
#include "conf_oper.h"
#include "nuh.h"
#include "numeric.h"
#include "send.h"

enum
{
  ALINE_MAX_DURATION_MINUTES = 24 * 60 * 360
};

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

static bool
_aline_parse_duration(const char *text, uintmax_t *duration_out)
{
  uintmax_t minutes;

  const io_parse_status_t status =
    io_parse_uintmax_range(text, 0, ALINE_MAX_DURATION_MINUTES, &minutes);
  if (status == IO_PARSE_RANGE)
    minutes = ALINE_MAX_DURATION_MINUTES;
  else if (status != IO_PARSE_OK)
    return false;

  *duration_out = minutes * 60U;
  return true;
}

bool
aline_parse(const char *cmd, struct Client *client, int parc, char *parv[], struct aline_ctx *aline)
{
  static char default_reason[] = CONF_NOREASON;
  static char user[USERLEN * 2 + 1];
  static char host[HOSTLEN * 2 + 1];

  ++parv;
  --parc;

  if (aline->add)
  {
    aline->duration = 0;

    uintmax_t duration;
    if (parc > 0 && _aline_parse_duration(*parv, &duration))
    {
      aline->duration = duration;
      ++parv;
      --parc;
    }
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

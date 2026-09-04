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
  const unsigned int minimum = ConfigGeneral.min_nonwildcard_simple;
  if (minimum == 0)
    return true;

  unsigned int nonwild = 0;
  bool has_wildcard = false;

  for (const unsigned char *p = (const unsigned char *)data; *p; ++p)
  {
    if (*p == '\\' && p[1] != '\0')
      ++p;
    else if (*p == '*' || *p == '?')
    {
      has_wildcard = true;
      continue;
    }

    if (++nonwild >= minimum)
      return true;
  }

  return has_wildcard == false;
}

static bool
_aline_mask_char_is_nonwild(unsigned char ch)
{
  return ch != '*' &&
         ch != '?' &&
         ch != ':' &&
         ch != '.';
}

bool
aline_valid_mask(size_t count, const char *const masks[])
{
  const unsigned int minimum = ConfigGeneral.min_nonwildcard;
  if (minimum == 0)
    return true;

  unsigned int nonwild = 0;

  for (size_t i = 0; i < count; ++i)
  {
    if (masks[i] == NULL)
      continue;

    for (const unsigned char *p = (const unsigned char *)masks[i]; *p; ++p)
    {
      if (!_aline_mask_char_is_nonwild(*p))
        continue;

      if (++nonwild >= minimum)
        return true;
    }
  }

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
aline_parse(const char *cmd, struct Client *client, size_t parc, char *parv[], struct aline_ctx *aline)
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

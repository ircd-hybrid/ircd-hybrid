/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file id.c
 * \brief Contains functions pertaining to SID/UID generation.
 * \version $Id$
 */

#include "stdinc.h"
#include "id.h"
#include "irc_string.h"
#include "client.h"

static char new_uid[TOTALSIDUID + 1];  /* Allow for \0 */

int
valid_sid(const char *sid)
{
  if (strlen(sid) == IRC_MAXSID)
    if (IsDigit(*sid))
      if (IsAlNum(*(sid + 1)) && IsAlNum(*(sid + 2)))
        return 1;

  return 0;
}

/*
 * init_uid()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - new_uid is filled in with server id portion (sid)
 *                (first 3 bytes). Rest is filled in with '9'.
 *
 */
void
init_uid(void)
{
  snprintf(new_uid, sizeof(new_uid), "%s999999", me.id);
}

/*
 * add_one_to_uid
 *
 * inputs       - index number into new_uid
 * output       - NONE
 * side effects - new_uid is incremented by one
 *                note this is a recursive function
 */
static void
add_one_to_uid(unsigned int i)
{
  if (i < IRC_MAXSID)
    return;

  if (new_uid[i] == 'Z')
    new_uid[i] = '0';
  else if (new_uid[i] == '9')
  {
    new_uid[i] = 'A';
    add_one_to_uid(i - 1);
  }
  else
    ++new_uid[i];
}

/*
 * uid_get
 *
 * inputs       - struct Client *
 * output       - new UID is returned to caller
 * side effects - new_uid is incremented by one.
 */
const char *
uid_get(void)
{
  add_one_to_uid(TOTALSIDUID - 1);  /* Index from 0 */
  return new_uid;
}

void
generate_sid(void)
{
  unsigned int sid = 0;
  const char *p;

  for (p = me.name; *p; ++p)
    sid = 5 * sid + *p;
  for (p = me.info; *p; ++p)
    sid = 5 * sid + *p;

  snprintf(me.id, IRC_MAXSID + 1, "%03d", sid % 1000);
}

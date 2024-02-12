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

/**
 * @file id.c
 * @brief Contains functions pertaining to SID/UID generation.
 */

#include "stdinc.h"
#include "id.h"
#include "irc_string.h"
#include "client.h"

/**
 * @brief Array to store the generated User ID (UID).
 *
 * This array holds the User ID (UID) generated by functions in this module.
 * The UID is a unique identifier for users on the IRC network, combining Server ID (SID) and User ID (UID).
 * The array size is TOTALSIDUID + 1, accommodating the UID and null terminator.
 */
static char new_uid[TOTALSIDUID + 1];

/**
 * @brief Checks if the provided Server ID (SID) is valid.
 *
 * @param sid Pointer to the SID string to be validated.
 * @return Returns true if the SID is valid, false otherwise.
 *
 * The SID must be exactly IRC_MAXSID characters long and consist of ASCII uppercase letters and digits.
 * The first character must be a digit.
 */
bool
valid_sid(const char *sid)
{
  if (strlen(sid) != IRC_MAXSID)
    return false;

  if (!IsDigit(*sid))
    return false;

  for (unsigned int i = 1; i < IRC_MAXSID; ++i)
    if (!IsUpper(*(sid + i)) && !IsDigit(*(sid + i)))
      return false;

  return true;
}

/**
 * @brief Checks if the provided User ID (UID) is valid.
 *
 * @param uid Pointer to the UID string to be validated.
 * @return Returns true if the UID is valid, false otherwise.
 *
 * The UID must be exactly TOTALSIDUID characters long and consist of ASCII uppercase letters and digits.
 * The first character must be a digit.
 */
bool
valid_uid(const char *uid)
{
  if (strlen(uid) != TOTALSIDUID)
    return false;

  if (!IsDigit(*uid))
    return false;

  for (unsigned int i = 1; i < TOTALSIDUID; ++i)
    if (!IsUpper(*(uid + i)) && !IsDigit(*(uid + i)))
      return false;

  return true;
}

/**
 * @brief Initializes the User ID (UID) by filling in the server ID portion (SID).
 *
 * This function initializes the UID by filling in the server ID portion (SID) with the value from
 * the 'me.id' variable, and the remaining portion with '999999'.
 */
void
init_uid(void)
{
  snprintf(new_uid, sizeof(new_uid), "%s999999", me.id);
}

/**
 * @brief Increments the User ID (UID) by one.
 *
 * @param i Index number into new_uid.
 *
 * This function increments the User ID (UID) by one. It starts from the rightmost character and
 * propagates any carry-over to the leftmost characters if needed.
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

/**
 * @brief Gets the next available User ID (UID) and increments it by one.
 *
 * @return Returns the new UID.
 *
 * This function retrieves the next available User ID (UID) and increments it by one for future use.
 */
const char *
uid_get(void)
{
  add_one_to_uid(TOTALSIDUID - 1);  /* Index from 0 */
  return new_uid;
}

/**
 * @brief Generates a server ID (SID) based on the server's name and information.
 *
 * This function generates a Server ID (SID) based on the server's name and information.
 * It uses a hashing algorithm to calculate the SID value from the server's name and additional information.
 */
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

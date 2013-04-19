/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  numeric.c: Numeric handling functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"

#include "numeric.h"
#include "irc_string.h"
#include "memory.h"
#include "log.h"
#include "send.h"
#include "client.h"
#include "messages.tab"

static char used_locale[LOCALE_LENGTH] = "standard";

/*
 * form_str
 *
 * inputs	- numeric
 * output	- corresponding string
 * side effects	- NONE
 */
const char* form_str(int numeric)
{
  assert(-1 < numeric);
  assert(numeric < ERR_LAST_ERR_MSG);

  if (numeric > ERR_LAST_ERR_MSG)
    numeric = ERR_LAST_ERR_MSG;
  if (numeric < 0)
    numeric = ERR_LAST_ERR_MSG;

  assert(replies[numeric].standard != NULL);

  return (replies[numeric].translated != NULL ? replies[numeric].translated :
                                                replies[numeric].standard);
}

/* Attempts to change a numeric with index "reply" to "new_reply".
 * Returns 1 if ok, 0 otherwise.
 */
static int
change_reply(const char *locale, int linecnt, int reply, char *new_reply)
{
  int found;
  char *new = new_reply;
  const char *old = replies[reply].standard;

  for (; *new; new++)
  {
    if (*new == '%')
    {
      if (!*++new) break;
      if (*new != '%')
      {
        /* We've just found a format symbol. Check if it is the next format
         * symbol in the original reply.
         */
        for (; *new >= '0' && *new <= '9'; new++); /* skip size prefix */
        found = 0;
        for (; *old; old++)
        {
          if (*old == '%')
	  {
	    if (!*++old) break;  /* shouldn't happen */
	    if (*old != '%')
            {
              for (; *old >= '0' && *old <= '9'; old++); /* skip size prefix */
              if (*new != *old++)
              {
                ilog(LOG_TYPE_IRCD, "Incompatible format symbols (%s.lang, %d)",
                     locale, linecnt);
                return 0;
              }
              found = 1;
              break;
            }
	  }
        }
        if (!found)
        {
          ilog(LOG_TYPE_IRCD, "Too many format symbols (%s.lang, %d)", locale, linecnt);
          return(0);
        }
      }
    }
  }

  MyFree(replies[reply].translated);
  replies[reply].translated = xstrdup(new_reply);
  return(1);
}

/* Loads a language file. Errors are logged into the log file. */
void
set_locale(const char *locale)
{
  int i, res = 1, linecnt = 0;
  char buffer[IRCD_BUFSIZE + 1];
  char *ident, *reply;
  FILE *f;

  /* Restore standard replies */
  for (i = 0; i <= ERR_LAST_ERR_MSG; i++)   /* 0 isn't a magic number! ;> */
  {
    if (replies[i].translated != NULL)
    {
      MyFree(replies[i].translated);
      replies[i].translated = NULL;
    }
  }

  if (strchr(locale, '/') != NULL)
  {
    strlcpy(used_locale, "standard", sizeof(used_locale));  /* XXX paranoid */
    return;
  }

  /* yes, I know - the slash isn't necessary. But I have to be sure
   * that it'll work even if some lame admin won't put "/" at the end
   * of MSGPATH.
   */
  snprintf(buffer, sizeof(buffer), "%s/%s.lang", MSGPATH, locale);
  if ((f = fopen(buffer, "r")) == NULL)
  {
    strlcpy(used_locale, "standard", sizeof(used_locale));  /* XXX */
    return;
  }

  /* Process the language file */
  while (fgets(buffer, sizeof(buffer), f))
  {
    ++linecnt;
    if (buffer[0] == ';')
      continue;   /* that's a comment */

    if ((ident = strpbrk(buffer, "\r\n")) != NULL)
      *ident = '\0';

    /* skip spaces if there are any */
    for (ident = buffer; *ident == ' ' || *ident == '\t'; ident++)/* null */;
    if (*ident == '\0')
      continue;		   /* empty line */

    /* skip after the reply identificator */
    for (reply = ident; *reply != ' ' && *reply != '\t' && *reply != ':';
      reply++)
      if (*reply == '\0') goto error;

    if (*reply == ' ' || *reply == '\t')
    {
      for (*reply++ = '\0'; *reply == ' ' || *reply == '\t'; reply++);
      if (*reply != ':')
      {
        error:
        ilog(LOG_TYPE_IRCD, "Invalid line in language file (%s.lang, %d)",
             locale, linecnt);
	res = 0;
	continue;
      }
    }
    else
      *reply++ = '\0';
    if (*ident == '\0')
      goto error;

    /* skip to the beginning of reply */
    while (*reply == ' ' || *reply == '\t') reply++;
    if (*reply == '\0')
      goto error;

    for (i = 0; i <= ERR_LAST_ERR_MSG; i++)
    {
      if (replies[i].name != NULL)
      {
        if (irccmp(replies[i].name, ident) == 0)
        {
          if (!change_reply(locale, linecnt, i, reply)) res = 0;
          i = -1;
          break;
        }
      }
    }
    if (i != -1)
    {
      ilog(LOG_TYPE_IRCD,
	   "Unknown numeric %s (%s.lang, %d)", ident, locale, linecnt);
      res = 0;
    }
  }
  fclose(f);

  strlcpy(used_locale, locale, sizeof(used_locale));
  if (!res)
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Language file [%s] contains "
                         "errors, check server log file for more details",
			 used_locale);
}

/* Returns the name of current locale. */
const char *
get_locale(void)
{
  return used_locale;
}

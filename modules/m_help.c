/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2024 ircd-hybrid development team
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

/*! \file m_help.c
 * \brief Includes required functions for processing the HELP command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "defaults.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "module.h"
#include "irc_string.h"


enum { HELPLEN = 400 };

static void
sendhelpfile(struct Client *source, const char *path, const char *topic)
{
  FILE *file = fopen(path, "r");
  if (file == NULL)
  {
    sendto_one_numeric(source, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  char line[HELPLEN];
  if (fgets(line, sizeof(line), file) == NULL)
  {
    sendto_one_numeric(source, &me, ERR_HELPNOTFOUND, topic);
    fclose(file);
    return;
  }

  char *p = strpbrk(line, "\r\n");
  if (p)
    *p = '\0';

  sendto_one_numeric(source, &me, RPL_HELPSTART, topic, line);

  while (fgets(line, sizeof(line), file))
  {
    p = strpbrk(line, "\r\n");
    if (p)
      *p = '\0';

    sendto_one_numeric(source, &me, RPL_HELPTXT, topic, line);
  }

  fclose(file);
  sendto_one_numeric(source, &me, RPL_ENDOFHELP, topic);
}

static void
do_help(struct Client *source, char *topic)
{
  char h_index[] = "index";

  if (EmptyString(topic))
    topic = h_index;
  else
    for (char *p = topic; *p; ++p)
      *p = ToLower(*p);

  if (strpbrk(topic, "/\\"))
  {
    sendto_one_numeric(source, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  char path[sizeof(HPATH) + IRCD_BUFSIZE + 1];  /* +1 for / */
  snprintf(path, sizeof(path), "%s/%s", HPATH, topic);

  struct stat sb;
  if (stat(path, &sb) < 0)
  {
    sendto_one_numeric(source, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  if (!S_ISREG(sb.st_mode))
  {
    sendto_one_numeric(source, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  sendhelpfile(source, path, topic);
}

/*! \brief HELP command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = help topic
 */
static void
m_help(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait_simple) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "HELP");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  do_help(source, parv[1]);
}

/*! \brief HELP command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = help topic
 */
static void
mo_help(struct Client *source, int parc, char *parv[])
{
  do_help(source, parv[1]);
}

static struct Command command_table =
{
  .name = "HELP",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_help },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_help }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};

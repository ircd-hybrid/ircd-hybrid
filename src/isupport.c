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
 * @file isupport.c
 * @brief Implementation of IRC ISUPPORT messages (RPL_ISUPPORT) in ircd-hybrid.
 *
 * The ISUPPORT mechanism provides a means for IRC servers to communicate their
 * capabilities and configuration settings to clients during the connection
 * establishment phase. This file contains functions and structures necessary for
 * handling and managing ISUPPORT messages within the ircd-hybrid server.
 */

#include "stdinc.h"
#include "list.h"
#include "ircd.h"
#include "conf.h"
#include "send.h"
#include "numeric.h"
#include "client.h"
#include "irc_string.h"
#include "memory.h"
#include "isupport.h"
#include "channel.h"
#include "channel_mode.h"
#include "parse.h"

/**
 * @struct Isupport
 * @brief Structure representing an IRC ISUPPORT option.
 *
 * This structure encapsulates an IRC ISUPPORT option, including its name, options, and
 * numerical value if applicable.
 */
struct Isupport
{
  dlink_node node;  /**< Node for linking Isupport structures in a list. */
  char *name;  /**< Name of the ISUPPORT option. */
  char *options;  /**< Options associated with the ISUPPORT option. */
  int number;  /**< Numerical value associated with the ISUPPORT option. */
};

/**
 * @var isupport_list
 * @brief List containing Isupport structures representing active ISUPPORT options.
 *
 * The isupport_list is a linked list that stores Isupport structures, each representing
 * a unique ISUPPORT option in the ircd-hybrid server. This list serves as the central
 * repository for managing and organizing ISUPPORT options. Various operations, such as
 * addition, deletion, and retrieval, are performed on this list to maintain and update
 * ISUPPORT options dynamically.
 */
static dlink_list isupport_list;

/**
 * @var isupport_list_lines
 * @brief List containing formatted ISUPPORT strings for transmission.
 *
 * The isupport_list_lines is a linked list that stores formatted ISUPPORT strings, each
 * representing a line of ISUPPORT information suitable for sending to clients. These
 * strings are constructed based on the options stored in the isupport_list. The list is
 * updated and rebuilt as needed to reflect the current set of supported features and
 * configurations.
 */
static dlink_list isupport_list_lines;

/**
 * @brief Clears the list of lines used for RPL_ISUPPORT messages.
 *
 * This function removes all stored lines in preparation for rebuilding
 * the RPL_ISUPPORT response. It iterates through the list of lines,
 * deallocates memory, and frees the associated data.
 */
static void
isupport_clear_lines(void)
{
  while (isupport_list_lines.head)
  {
    dlink_node *node = isupport_list_lines.head;
    dlinkDelete(node, &isupport_list_lines);
    xfree(node->data);
    free_dlink_node(node);
  }
}

/**
 * @brief Constructs formatted lines for ISUPPORT messages.
 *
 * This function constructs formatted lines for ISUPPORT messages based on the ISUPPORT
 * options stored in the isupport_list. Each line represents a set of ISUPPORT options,
 * and the resulting lines are stored in isupport_list_lines.
 */
static void
isupport_build_lines(void)
{
  char buf[IRCD_BUFSIZE];
  char *bufptr = buf;
  int tokens = 0;
  size_t len = 0;
  size_t reserve = strlen(me.name) + HOSTLEN + strlen(numeric_form(RPL_ISUPPORT));

  isupport_clear_lines();

  dlink_node *node;
  DLINK_FOREACH(node, isupport_list.head)
  {
    const struct Isupport *support = node->data;

    len += snprintf(bufptr + len, sizeof(buf) - len, "%s", support->name);

    if (support->options)
      len += snprintf(bufptr + len, sizeof(buf) - len, "=%s", support->options);
    if (support->number > 0)
      len += snprintf(bufptr + len, sizeof(buf) - len, "=%d", support->number);

    len += snprintf(bufptr + len, sizeof(buf) - len, " ");

    if (++tokens == (MAXPARA - 2) || len >= (sizeof(buf) - reserve))
    {
      if (bufptr[len - 1] == ' ')
        bufptr[--len] = '\0';

      dlinkAddTail(xstrdup(buf), make_dlink_node(), &isupport_list_lines);
      bufptr = buf;
      len = 0;
      tokens = 0;
    }
  }

  if (len > 0)
  {
    if (bufptr[len - 1] == ' ')
      bufptr[--len] = '\0';

    dlinkAddTail(xstrdup(buf), make_dlink_node(), &isupport_list_lines);
  }
}

/**
 * @brief Finds an ISUPPORT option by name.
 *
 * Searches the list of ISUPPORT options for an option with the specified name.
 *
 * @param name The name of the ISUPPORT option to find.
 * @return A pointer to the Isupport structure if found, otherwise NULL.
 */
static struct Isupport *
isupport_find(const char *name)
{
  dlink_node *node;

  DLINK_FOREACH(node, isupport_list.head)
  {
    struct Isupport *support = node->data;
    if (irccmp(support->name, name) == 0)
      return support;
  }

  return NULL;
}

/**
 * @brief Initializes the ISUPPORT system with default options.
 *
 * This function initializes the ISUPPORT system with default options. The default
 * options include, but are not limited to, BOT, CALLERID, CASEMAPPING, DEAF,
 * KICKLEN, MODES, EXCEPTS, and INVEX.
 */
void
isupport_init(void)
{
  isupport_add("BOT", "B", -1);
  isupport_add("CALLERID", NULL, -1);
  isupport_add("CASEMAPPING", "ascii", -1);
  isupport_add("DEAF", "D", -1);
  isupport_add("KICKLEN", NULL, KICKLEN);
  isupport_add("MODES", NULL, MAXMODEPARAMS);
  isupport_add("EXCEPTS", NULL, -1);
  isupport_add("INVEX", NULL, -1);
}

/**
 * @brief Creates a new ISUPPORT option.
 *
 * Creates a new ISUPPORT option with the specified name, options, and number.
 *
 * @param name The name of the ISUPPORT option.
 * @param options The options associated with the ISUPPORT option.
 * @param number The numerical value associated with the ISUPPORT option.
 * @return A pointer to the newly created Isupport structure.
 */
static struct Isupport *
isupport_create(const char *name, const char *options, int number)
{
  struct Isupport *support = xcalloc(sizeof(*support));
  support->name = xstrdup(name);
  support->options = (options) ? xstrdup(options) : NULL;
  support->number = number;
  dlinkAddTail(support, &support->node, &isupport_list);

  return support;
}

/**
 * @brief Destroys an ISUPPORT option.
 *
 * Removes an ISUPPORT option from the list and deallocates its memory.
 *
 * @param support A pointer to the Isupport structure to destroy.
 */
static void
isupport_destroy(struct Isupport *support)
{
  dlinkDelete(&support->node, &isupport_list);
  xfree(support->name);
  xfree(support->options);
  xfree(support);
}

/**
 * @brief Adds or updates an ISUPPORT option.
 *
 * Adds a new ISUPPORT option or updates an existing one with the specified name,
 * options, and number. If an option with the same name exists, it is replaced.
 * After modification, the ISUPPORT lines are rebuilt.
 *
 * @param name The name of the ISUPPORT option.
 * @param options The options associated with the ISUPPORT option.
 * @param number The numerical value associated with the ISUPPORT option.
 */
void
isupport_add(const char *name, const char *options, int number)
{
  struct Isupport *support = isupport_find(name);
  if (support)
    isupport_destroy(support);

  isupport_create(name, options, number);

  /* Rebuild ISUPPORT lines after modification. */
  isupport_build_lines();
}

/**
 * @brief Deletes an ISUPPORT option.
 *
 * Deletes an ISUPPORT option with the specified name. After deletion,
 * the ISUPPORT lines are rebuilt.
 *
 * @param name The name of the ISUPPORT option to delete.
 */
void
isupport_delete(const char *name)
{
  struct Isupport *support = isupport_find(name);
  if (support)
  {
    isupport_destroy(support);

    /* Rebuild ISUPPORT lines after modification. */
    isupport_build_lines();
  }
}

/**
 * @brief Displays ISUPPORT information to a client.
 *
 * Sends formatted ISUPPORT messages to a client to inform them about the
 * server's supported features and settings.
 *
 * @param client A pointer to the Client structure.
 */
void
isupport_show(struct Client *client)
{
  dlink_node *node;

  DLINK_FOREACH(node, isupport_list_lines.head)
  {
    const char *const string = node->data;
    sendto_one_numeric(client, &me, RPL_ISUPPORT, string);
  }
}

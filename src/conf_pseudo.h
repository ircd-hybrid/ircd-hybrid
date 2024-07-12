/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2024 ircd-hybrid development team
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
 * @file conf_pseudo.h
 * @brief Handles pseudo commands/service aliases.
 *
 * This file provides declarations for managing pseudo/custom commands, commonly
 * known as service aliases. Pseudo commands allow for creating custom commands
 * with specific targets and handling.
 */

#ifndef INCLUDED_conf_pseudo_h
#define INCLUDED_conf_pseudo_h

/**
 * @struct PseudoItem
 * @brief Structure representing a pseudo command item.
 *
 * This structure holds information about a pseudo command, including its name,
 * associated nick, server, prepend text, and the actual command to be executed.
 */
struct PseudoItem
{
  list_node_t node;  /**< Node for linking into the pseudo command list. */
  struct Command command_struct;  /**< Command structure for handling the pseudo command. */
  char *name;  /**< Name of the pseudo command, used for error messages. */
  char *nick;  /**< Associated nick for the pseudo command. */
  char *server;  /**< Associated server for the pseudo command. */
  char *prepend;  /**< Optional text to be prepended to the user's message. */
  char *command;  /**< Actual command/alias to be executed. */
};

extern void pseudo_register(const char *, const char *, const char *, const char *, const char *);
extern void pseudo_clear(void);
extern const list_t *pseudo_get_list(void);
#endif  /* INCLUDED_conf_pseudo_h */

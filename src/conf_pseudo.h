/*
 * SPDX-FileCopyrightText: 2014-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
#include "list.h"

#include "command.h"

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

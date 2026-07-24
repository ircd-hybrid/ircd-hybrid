/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_list.c
 * \brief Includes required functions for processing the LIST command.
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "module.h"

#include "client.h"
#include "ircd.h"
#include "isupport.h"
#include "list_task.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

static bool
_parse_list_uint(const char *text, unsigned int *value_out)
{
  if (string_is_empty(text))
    return false;

  unsigned int value = 0;
  for (const char *p = text; *p; ++p)
  {
    const unsigned char ch = (unsigned char)*p;
    if (!IsDigit(ch))
      return false;

    const unsigned int digit = (unsigned int)(ch - '0');
    if (value > (UINT_MAX - digit) / 10U)
      return false;

    value = (value * 10U) + digit;
  }

  *value_out = value;
  return true;
}

static uintmax_t
_list_age_filter_cutoff(uintmax_t now, unsigned int minutes)
{
  const uintmax_t seconds = (uintmax_t)minutes * 60ULL;
  return seconds > now ? 0 : now - seconds;
}

static bool
_parse_list_user_count_filter(struct ListTask *task, char modifier, const char *value_text)
{
  assert(modifier == '<' || modifier == '>');

  unsigned int value = 0;
  if (!_parse_list_uint(value_text, &value))
    return false;

  /*
   * ELIST <val matches channels with less than val users.
   * ELIST >val matches channels with more than val users.
   */
  if (modifier == '<')
  {
    if (value == 0)
      return false;

    task->users_max = value - 1;
    return true;
  }

  if (value == UINT_MAX)
    return false;

  task->users_min = value + 1;
  return true;
}

static bool
_parse_list_creation_time_filter(struct ListTask *task, char modifier, const char *value_text, uintmax_t now)
{
  if (modifier != '<' && modifier != '>')
    return false;

  unsigned int minutes = 0;
  if (!_parse_list_uint(value_text, &minutes))
    return false;

  const uintmax_t cutoff_time = _list_age_filter_cutoff(now, minutes);

  /*
   * ELIST C<val matches channels created less than val minutes ago.
   * ELIST C>val matches channels created more than val minutes ago.
   */
  if (modifier == '<')
    task->creation_time_min = cutoff_time;
  else
    task->creation_time_max = cutoff_time;

  task->has_creation_time_filter = true;
  return true;
}

static bool
_parse_list_topic_filter(struct ListTask *task, char modifier, const char *value_text, uintmax_t now)
{
  if (modifier == ':')
  {
    if (string_is_empty(value_text))
      return false;

    io_free(task->topic);
    task->topic = io_strdup(value_text);
    return true;
  }

  if (modifier != '<' && modifier != '>')
    return false;

  unsigned int minutes = 0;
  if (!_parse_list_uint(value_text, &minutes))
    return false;

  const uintmax_t cutoff_time = _list_age_filter_cutoff(now, minutes);

  /*
   * ELIST T<val matches topics set less than val minutes ago.
   * ELIST T>val matches topics set more than val minutes ago.
   */
  if (modifier == '<')
    task->topic_time_min = cutoff_time;
  else
    task->topic_time_max = cutoff_time;

  task->has_topic_time_filter = true;
  return true;
}

static bool
_parse_list_mask_filter(struct ListTask *task, const char *option)
{
  if (string_is_empty(option))
    return false;

  list_t *target_list = &task->include_masks;
  const char *mask = option;

  /* Handle exclusion masks. */
  if (*mask == '!')
  {
    target_list = &task->exclude_masks;
    ++mask;
  }

  if (string_is_empty(mask))
    return false;

  const bool has_channel_prefix = IsChanPrefix(*mask);
  const char *const name = has_channel_prefix ? mask + 1 : mask;
  if (has_channel_prefix && string_is_empty(name))
    return false;

  if (has_wildcards(name))
  {
    /*
     * exact_match only describes the include side. Exclusion masks are still
     * evaluated after an exact channel lookup.
     */
    if (target_list == &task->include_masks)
      task->exact_match = false;
  }
  else if (has_channel_prefix == false)
    return false;  /* Exact matches must have a valid channel prefix. */

  list_add_tail(io_strdup(mask), list_make_node(), target_list);
  return true;
}

static bool
_parse_list_option(struct ListTask *task, const char *option, uintmax_t now)
{
  if (string_is_empty(option))
    return false;

  if (option[0] == '<' || option[0] == '>')
    return _parse_list_user_count_filter(task, option[0], option + 1);

  if (option[0] == 'C' || option[0] == 'c')
  {
    const char modifier = option[1];
    return _parse_list_creation_time_filter(task, modifier, modifier ? option + 2 : "", now);
  }

  if (option[0] == 'T' || option[0] == 't')
  {
    const char modifier = option[1];
    return _parse_list_topic_filter(task, modifier, modifier ? option + 2 : "", now);
  }

  return _parse_list_mask_filter(task, option);
}

static bool
_parse_list_args(struct ListTask *task, char *args)
{
  if (string_is_empty(args))
    return true;

  task->exact_match = true;

  const uintmax_t now = io_time_get(IO_TIME_REALTIME_SEC);
  char *saveptr = NULL;
  for (char *option = strtok_r(args, ",", &saveptr); option;
             option = strtok_r(NULL, ",", &saveptr))
  {
    if (!_parse_list_option(task, option, now))
      return false;
  }

  if (list_is_empty(&task->include_masks))
    task->exact_match = false;

  return true;
}

static void
_list_process_request(struct Client *client, char *arg)
{
  if (client->connection->list_task)
  {
    list_task_destroy(client->connection->list_task);
    sendto_one_numeric(client, &me, RPL_LISTEND);
    return;
  }

  struct ListTask *const task = list_task_create(client);
  if (!string_is_empty(arg) && !_parse_list_args(task, arg))
  {
    list_task_destroy(task);
    sendto_one_numeric(client, &me, ERR_LISTSYNTAX);
    sendto_one_numeric(client, &me, RPL_LISTEND);
    return;
  }

  sendto_one_numeric(client, &me, RPL_LISTSTART);
  list_task_start(task);
}

/*! \brief LIST command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name/list options
 */
static void
m_list(struct Client *source, int parc, char *parv[])
{
  _list_process_request(source, parv[1]);
}

static struct Command command_table =
{
  .name = "LIST",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_list },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_list },
};

static void
init_handler(void)
{
  command_add(&command_table);
  isupport_add("ELIST", "%s", "CMNTU");
  isupport_add("SAFELIST", NULL);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  isupport_delete("ELIST");
  isupport_delete("SAFELIST");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};

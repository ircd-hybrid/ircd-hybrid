/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_set.c
 * \brief Includes required functions for processing the SET command.
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_parse.h"
#include "io_string.h"
#include "misc.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "conf.h"
#include "defaults.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

enum SetOptionType
{
  SET_OPTION_BOOL,
  SET_OPTION_UINT,
};

struct SetOption
{
  const char *const name;
  enum SetOptionType type;
  unsigned int *const value;
  unsigned int value_min;
  unsigned int value_max;
};

static const struct SetOption set_options[] =
{
  {
    .name = "AUTOCONNECT",
    .type = SET_OPTION_BOOL,
    .value = &GlobalSetOptions.autoconnect
  },
  {
    .name = "FLOODCOUNT",
    .type = SET_OPTION_UINT,
    .value = &GlobalSetOptions.floodcount,
    .value_min = 0,
    .value_max = INT_MAX
  },
  {
    .name = "FLOODTIME",
    .type = SET_OPTION_UINT,
    .value = &GlobalSetOptions.floodtime,
    .value_min = 0,
    .value_max = INT_MAX
  },
  {
    .name = "MAX",
    .type = SET_OPTION_UINT,
    .value = &GlobalSetOptions.maxclients,
    .value_min = 1,
    .value_max = INT_MAX
  },
  {
    .name = "SPAMNUM",
    .type = SET_OPTION_UINT,
    .value = &GlobalSetOptions.spam_num,
    .value_min = MIN_SPAM_NUM,
    .value_max = INT_MAX
  },
  {
    .name = "SPAMTIME",
    .type = SET_OPTION_UINT,
    .value = &GlobalSetOptions.spam_time,
    .value_min = MIN_SPAM_TIME,
    .value_max = INT_MAX
  },
  {
    .name = "JFLOODTIME",
    .type = SET_OPTION_UINT,
    .value = &GlobalSetOptions.joinfloodtime,
    .value_min = 0,
    .value_max = INT_MAX
  },
  {
    .name = "JFLOODCOUNT",
    .type = SET_OPTION_UINT,
    .value = &GlobalSetOptions.joinfloodcount,
    .value_min = 0,
    .value_max = INT_MAX
  }
};

static const struct SetOption *
_set_option_find(const char *name)
{
  for (size_t i = 0; i < IO_ARRAY_LENGTH(set_options); ++i)
  {
    const struct SetOption *const option = &set_options[i];
    if (io_strcasecmp(name, option->name) == 0)
      return option;
  }

  return NULL;
}

static io_parse_status_t
_set_option_parse_value(const struct SetOption *option, const char *text, unsigned int *value_out)
{
  switch (option->type)
  {
    case SET_OPTION_BOOL:
    {
      bool value;
      const io_parse_status_t status = io_parse_bool(text, &value);
      if (status != IO_PARSE_OK)
        return status;

      *value_out = value;
      return IO_PARSE_OK;
    }

    case SET_OPTION_UINT:
      assert(option->value_min <= option->value_max);
      return io_parse_uint_range(text, option->value_min, option->value_max, value_out);
  }

  assert(0);
  return IO_PARSE_INVALID;
}

static void
_set_option_report(struct Client *source, const struct SetOption *option)
{
  assert(source);
  assert(option);
  assert(option->name);
  assert(option->value);

  switch (option->type)
  {
    case SET_OPTION_BOOL:
      sendto_one_notice(source, &me, ":%s is currently %s",
                        option->name, *option->value ? "true" : "false");
      return;
    case SET_OPTION_UINT:
      sendto_one_notice(source, &me, ":%s is currently %u",
                        option->name, *option->value);
      return;
  }

  assert(0);
}

static void
_set_option_report_change(struct Client *source, const struct SetOption *option)
{
  assert(source);
  assert(option);
  assert(option->name);
  assert(option->value);

  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  switch (option->type)
  {
    case SET_OPTION_BOOL:
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "%s has changed %s to %s",
                     source_name, option->name, *option->value ? "true" : "false");
      return;
    case SET_OPTION_UINT:
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "%s has changed %s to %u",
                     source_name, option->name, *option->value);
      return;
  }

  assert(0);
}

static void
mo_set(struct Client *source, int parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_SET))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "set");
    return;
  }

  const char *const option_name = parv[1];
  const struct SetOption *const option = _set_option_find(option_name);
  if (option == NULL)
  {
    sendto_one_notice(source, &me, ":Invalid SET option: %s", option_name);
    return;
  }

  const char *const value_text = parv[2];
  if (string_is_empty(value_text))
  {
    _set_option_report(source, option);
    return;
  }

  unsigned int value;
  const io_parse_status_t status = _set_option_parse_value(option, value_text, &value);
  if (status != IO_PARSE_OK)
  {
    if (option->type == SET_OPTION_BOOL)
    {
      sendto_one_notice(source, &me, ":Value for %s must be either true or false",
                        option->name);
      return;
    }

    if (status == IO_PARSE_RANGE)
    {
      sendto_one_notice(source, &me, ":Value for %s must be between %u and %u",
                        option->name, option->value_min, option->value_max);
      return;
    }

    sendto_one_notice(source, &me, ":Value for %s must be an unsigned decimal integer",
                      option->name);
    return;
  }

  *option->value = value;
  _set_option_report_change(source, option);

}

static struct Command command_table =
{
  .name = "SET",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_set, .args_min = 2 }
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

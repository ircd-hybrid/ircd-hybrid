/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_bmask.c
 * \brief Includes required functions for processing the BMASK command.
 */

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "io_parse.h"
#include "io_string.h"
#include "list.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "channel_mode_batch.h"
#include "client.h"
#include "ircd.h"
#include "ircd_module.h"
#include "parse.h"
#include "send.h"

static void
_bmask_flush_modes(const struct Channel *channel, const char *header, struct ChannelModeBatch *batch)
{
  if (batch->modes_length)
    sendto_channel_local(NULL, channel, 0, 0, 0, "%s%s%s%s",
                         header, batch->modes, batch->parameter_count ? " " : "", batch->parameters);

  channel_mode_batch_reset(batch);
}

/*! \brief BMASK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = timestamp
 *      - parv[2] = channel name
 *      - parv[3] = type of ban to add ('b' 'I' or 'e')
 *      - parv[4] = space delimited list of masks to add
 */
static void
ms_bmask(struct Client *source, size_t parc, char *parv[])
{
  char banbuf[IRCD_BUFSIZE];
  const char *mask;
  char *s, *t;
  list_t *list = NULL;
  size_t tlen = 0;
  uint32_t type = 0;

  struct Channel *channel = channel_find(parv[2]);
  if (channel == NULL)
    return;

  uintmax_t channel_timestamp;
  if (io_parse_uintmax(parv[1], &channel_timestamp) != IO_PARSE_OK)
    return;

  /* Their TS is higher, drop it. */
  if (channel_timestamp > channel->creation_time)
    return;

  switch (*parv[3])
  {
    case 'b':
      type = CHFL_BAN;
      list = &channel->ban_list;
      break;
    case 'e':
      type = CHFL_EXCEPTION;
      list = &channel->exception_list;
      break;
    case 'I':
      type = CHFL_INVEX;
      list = &channel->invite_exception_list;
      break;
    default:
      return;
  }

  strlcpy(banbuf, parv[4], sizeof(banbuf));
  s = banbuf;

  char header[IRCD_BUFSIZE];
  const int header_length = snprintf(header, sizeof(header), ":%s MODE %s ",
                                     client_get_visible_server_name(source), channel->name);
  assert(header_length >= 0 && (size_t)header_length < sizeof(header));

  struct ChannelModeBatch batch;
  channel_mode_batch_init(&batch, (size_t)header_length);

  do
  {
    if ((t = strchr(s, ' ')))
      *t++ = '\0';
    tlen = strlen(s);

    /* I don't even want to begin parsing this.. */
    if (tlen > MODEBUFLEN)
      break;

    if (tlen && *s != ':' && (mask = add_id(source, channel, s, list, type)))
    {
      channel_mode_batch_result_t result = channel_mode_batch_append(&batch, MODE_ADD, (unsigned char)*parv[3], mask);
      if (result == CHANNEL_MODE_BATCH_FULL)
      {
        _bmask_flush_modes(channel, header, &batch);
        result = channel_mode_batch_append(&batch, MODE_ADD, (unsigned char)*parv[3], mask);
      }

      assert(result == CHANNEL_MODE_BATCH_SUCCESS);
      (void)result;
    }

    s = t;
  } while (s);

  _bmask_flush_modes(channel, header, &batch);

  sendto_servers(source, 0, 0, ":%s BMASK %ju %s %s :%s",
                 source->id, channel->creation_time, channel->name, parv[3], parv[4]);
}

static struct Command command_table =
{
  .name = "BMASK",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_bmask, .args_min = 5 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_commands(&command_table, 1, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  command_del(&command_table);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "m_bmask",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};

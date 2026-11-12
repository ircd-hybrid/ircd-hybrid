/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <string.h>

#include "io_string.h"

#include "channel_mode_batch.h"

void
channel_mode_batch_init(struct ChannelModeBatch *batch, size_t header_length)
{
  assert(batch);

  batch->body_length_max = header_length < IRCD_BUFSIZE - 2 ? IRCD_BUFSIZE - 2 - header_length : 0;
  channel_mode_batch_reset(batch);
}

void
channel_mode_batch_reset(struct ChannelModeBatch *batch)
{
  assert(batch);

  batch->modes[0] = '\0';
  batch->parameters[0] = '\0';
  batch->modes_length = 0;
  batch->parameters_length = 0;
  batch->parameter_count = 0;
  batch->last_action = MODE_NONE;
}

channel_mode_batch_result_t
channel_mode_batch_append(struct ChannelModeBatch *batch, enum channel_mode_action action,
                          unsigned char letter, const char *parameter)
{
  assert(batch);
  assert(action == MODE_ADD || action == MODE_DEL);
  assert(io_ascii_is_alpha(letter));
  assert(parameter == NULL ||
         (!string_is_empty(parameter) && *parameter != ':' && strpbrk(parameter, " \r\n") == NULL));

  const size_t parameter_length = parameter ? strlen(parameter) : 0;
  const size_t minimum_overhead = 2 + (parameter != NULL);  /* Sign, letter, optional separator. */

  if (batch->body_length_max < minimum_overhead ||
      parameter_length > batch->body_length_max - minimum_overhead)
    return CHANNEL_MODE_BATCH_TOO_LONG;

  const size_t length = batch->modes_length + batch->parameters_length + (batch->parameter_count != 0);
  const size_t added_length = 1 + (batch->last_action != action) + (parameter ? parameter_length + 1 : 0);

  assert(length <= batch->body_length_max);

  if ((parameter && batch->parameter_count == MAXMODEPARAMS) ||
      added_length > batch->body_length_max - length)
    return CHANNEL_MODE_BATCH_FULL;

  if (parameter)
  {
    const size_t separator_length = batch->parameter_count != 0;
    char *const output = batch->parameters + batch->parameters_length;

    /* Preserve parameters borrowed from either output buffer before modifying it. */
    memmove(output + separator_length, parameter, parameter_length + 1);
    if (separator_length)
      *output = ' ';

    batch->parameters_length += separator_length + parameter_length;
    ++batch->parameter_count;
  }

  if (batch->last_action != action)
  {
    batch->modes[batch->modes_length++] = action == MODE_ADD ? '+' : '-';
    batch->last_action = action;
  }

  batch->modes[batch->modes_length++] = (char)letter;
  batch->modes[batch->modes_length] = '\0';

  return CHANNEL_MODE_BATCH_SUCCESS;
}

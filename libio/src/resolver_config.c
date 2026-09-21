/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "address.h"
#include "io.h"
#include "io_string.h"
#include "resolver_config.h"

#ifndef RESOLVER_CONFIG_RESOLV_CONF_PATH
#define RESOLVER_CONFIG_RESOLV_CONF_PATH "/etc/resolv.conf"
#endif

enum
{
  RESOLVER_CONFIG_RESOLV_CONF_LINE_CAPACITY = 1024,
  RESOLVER_CONFIG_DEFAULT_NAMESERVER_PORT = 53
};

static const char resolver_config_default_nameserver_address[] = "127.0.0.1";

enum resolver_config_line_read_result
{
  RESOLVER_CONFIG_LINE_READ_OK,
  RESOLVER_CONFIG_LINE_READ_EOF,
  RESOLVER_CONFIG_LINE_READ_TOO_LONG,
  RESOLVER_CONFIG_LINE_READ_INVALID,
  RESOLVER_CONFIG_LINE_READ_ERROR
};

enum resolver_config_file_load_result
{
  RESOLVER_CONFIG_FILE_LOAD_OK,
  RESOLVER_CONFIG_FILE_LOAD_NOT_FOUND,
  RESOLVER_CONFIG_FILE_LOAD_ERROR
};

enum resolver_config_nameserver_add_result
{
  RESOLVER_CONFIG_NAMESERVER_ADDED,
  RESOLVER_CONFIG_NAMESERVER_DUPLICATE,
  RESOLVER_CONFIG_NAMESERVER_INVALID,
  RESOLVER_CONFIG_NAMESERVER_CAPACITY_REACHED
};

static enum resolver_config_line_read_result
_resolver_config_read_line(FILE *file, char *line, size_t line_capacity)
{
  assert(file);
  assert(line);
  assert(line_capacity > 1);

  size_t line_length = 0;
  bool is_invalid = false;
  bool is_too_long = false;

  for (;;)
  {
    const int character = fgetc(file);
    if (character == EOF)
    {
      if (ferror(file))
      {
        if (errno == EINTR)
        {
          clearerr(file);
          continue;
        }

        return RESOLVER_CONFIG_LINE_READ_ERROR;
      }

      if (line_length == 0 && !is_invalid && !is_too_long)
        return RESOLVER_CONFIG_LINE_READ_EOF;

      break;
    }

    if (character == '\n')
      break;

    if (character == '\0')
    {
      is_invalid = true;
      continue;
    }

    if (is_invalid || is_too_long)
      continue;

    if (line_length + 1 >= line_capacity)
    {
      is_too_long = true;
      continue;
    }

    line[line_length++] = (char)character;
  }

  if (is_invalid)
    return RESOLVER_CONFIG_LINE_READ_INVALID;

  if (is_too_long)
    return RESOLVER_CONFIG_LINE_READ_TOO_LONG;

  if (line_length > 0 && line[line_length - 1] == '\r')
    --line_length;

  line[line_length] = '\0';
  return RESOLVER_CONFIG_LINE_READ_OK;
}

static char *
_resolver_config_next_token(char **cursor)
{
  assert(cursor);
  assert(*cursor);

  char *position = *cursor;
  while (*position && io_ascii_is_space((unsigned char)*position))
    ++position;

  if (*position == '\0' || *position == '#' || *position == ';')
  {
    *cursor = position;
    return NULL;
  }

  char *const token = position;

  while (*position && !io_ascii_is_space((unsigned char)*position))
    ++position;

  if (*position)
    *position++ = '\0';

  *cursor = position;
  return token;
}

static enum resolver_config_nameserver_add_result
_resolver_config_add_nameserver(struct resolver_config *config, const char *address_string)
{
  assert(config);
  assert(address_string);
  assert(config->nameserver_count <= IO_ARRAY_LENGTH(config->nameservers));

  struct io_addr address = { 0 };
  if (!address_from_string(address_string, &address))
    return RESOLVER_CONFIG_NAMESERVER_INVALID;

  address_unmap_ipv4(&address);

  if (!address_is_specified(&address))
    return RESOLVER_CONFIG_NAMESERVER_INVALID;

  const bool port_set = address_set_port(&address, RESOLVER_CONFIG_DEFAULT_NAMESERVER_PORT);
  assert(port_set);

  if (!port_set)
    return RESOLVER_CONFIG_NAMESERVER_INVALID;

  if (resolver_config_contains_nameserver(config, &address))
    return RESOLVER_CONFIG_NAMESERVER_DUPLICATE;

  if (config->nameserver_count >= IO_ARRAY_LENGTH(config->nameservers))
    return RESOLVER_CONFIG_NAMESERVER_CAPACITY_REACHED;

  address_copy(&config->nameservers[config->nameserver_count], &address);
  ++config->nameserver_count;

  return RESOLVER_CONFIG_NAMESERVER_ADDED;
}

static bool
_resolver_config_set_default_nameserver(struct resolver_config *config)
{
  assert(config);
  assert(config->nameserver_count == 0);

  const enum resolver_config_nameserver_add_result result =
    _resolver_config_add_nameserver(config, resolver_config_default_nameserver_address);
  assert(result == RESOLVER_CONFIG_NAMESERVER_ADDED);

  if (result != RESOLVER_CONFIG_NAMESERVER_ADDED)
    return false;

  return true;
}

static void
_resolver_config_parse_line(struct resolver_config *config, char *line)
{
  assert(config);
  assert(line);

  char *cursor = line;
  char *const directive = _resolver_config_next_token(&cursor);
  if (directive == NULL)
    return;

  if (io_strcasecmp(directive, "nameserver"))
    return;

  char *const argument = _resolver_config_next_token(&cursor);
  if (argument == NULL)
    return;

  if (_resolver_config_next_token(&cursor))
    return;

  _resolver_config_add_nameserver(config, argument);
}

static bool
_resolver_config_parse_stream(FILE *file, struct resolver_config *config)
{
  assert(file);
  assert(config);

  char line[RESOLVER_CONFIG_RESOLV_CONF_LINE_CAPACITY];

  for (;;)
  {
    const enum resolver_config_line_read_result line_result =
      _resolver_config_read_line(file, line, sizeof(line));
    switch (line_result)
    {
      case RESOLVER_CONFIG_LINE_READ_OK:
        _resolver_config_parse_line(config, line);
        break;
      case RESOLVER_CONFIG_LINE_READ_TOO_LONG:
      case RESOLVER_CONFIG_LINE_READ_INVALID:
        break;
      case RESOLVER_CONFIG_LINE_READ_EOF:
        return true;
      case RESOLVER_CONFIG_LINE_READ_ERROR:
        return false;
    }
  }
}

static FILE *
_resolver_config_open_file(const char *path)
{
  assert(path);

  FILE *file;

  do
    file = fopen(path, "r");
  while (file == NULL && errno == EINTR);

  return file;
}

static enum resolver_config_file_load_result
_resolver_config_load_file(const char *path, struct resolver_config *config)
{
  assert(path);
  assert(config);
  assert(config->nameserver_count == 0);

  FILE *const file = _resolver_config_open_file(path);
  if (file == NULL)
  {
    if (errno == ENOENT)
      return RESOLVER_CONFIG_FILE_LOAD_NOT_FOUND;

    return RESOLVER_CONFIG_FILE_LOAD_ERROR;
  }

  const bool parse_success =
    _resolver_config_parse_stream(file, config);

  fclose(file);
  return parse_success ? RESOLVER_CONFIG_FILE_LOAD_OK : RESOLVER_CONFIG_FILE_LOAD_ERROR;
}

bool
resolver_config_load(struct resolver_config *config)
{
  assert(config);

  struct resolver_config candidate = { 0 };

  const enum resolver_config_file_load_result file_result =
    _resolver_config_load_file(RESOLVER_CONFIG_RESOLV_CONF_PATH, &candidate);
  if (file_result == RESOLVER_CONFIG_FILE_LOAD_ERROR)
    return false;

  if (candidate.nameserver_count == 0 &&
      !_resolver_config_set_default_nameserver(&candidate))
    return false;

  *config = candidate;
  return true;
}

bool
resolver_config_has_family(const struct resolver_config *config, int family)
{
  assert(config);
  assert(config->nameserver_count <= IO_ARRAY_LENGTH(config->nameservers));

  for (size_t i = 0; i < config->nameserver_count; ++i)
    if (address_get_family(&config->nameservers[i]) == family)
      return true;

  return false;
}

bool
resolver_config_contains_nameserver(const struct resolver_config *config,
                                    const struct io_addr *nameserver)
{
  assert(config);
  assert(nameserver);
  assert(config->nameserver_count <= IO_ARRAY_LENGTH(config->nameservers));

  for (size_t i = 0; i < config->nameserver_count; ++i)
    if (address_equal_with_port(&config->nameservers[i], nameserver))
      return true;

  return false;
}

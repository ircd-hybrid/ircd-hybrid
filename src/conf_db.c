/*
 * SPDX-FileCopyrightText: 2012-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf_db.c
 * \brief Includes file utilities for database handling
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <jansson.h>  /**< Jansson JSON library. */

#include "log.h"
#include "memory.h"

#include "conf.h"
#include "conf_db.h"
#include "conf_gecos.h"
#include "conf_resv.h"

void
save_kline_database(const char *filename)
{
  json_t *root = json_object();
  json_t *kline_array = json_array();
  json_object_set_new(root, "k_lines", kline_array);

  for (size_t i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    list_node_t *node;
    LIST_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;
      if (arec->type != CONF_KLINE || !IsConfDatabase(arec->conf))
        continue;

      json_error_t error;
      json_t *entry = json_pack_ex(&error, 0, "{s:s, s:s, s:s, s:I, s:I}",
                                   "user", arec->conf->user,
                                   "host", arec->conf->host,
                                   "reason", arec->conf->reason,
                                   "created_at", arec->conf->setat,
                                   "expires_at", arec->conf->until);
      if (entry == NULL)
      {
        log_write(LOG_TYPE_IRCD, "Error packing kline: line %d, column %d, position %d: %s",
                  error.line, error.column, error.position, error.text);
        continue;
      }

      json_array_append_new(kline_array, entry);
    }
  }

  if (json_dump_file(root, filename, JSON_INDENT(4)))
    log_write(LOG_TYPE_IRCD, "Error writing JSON data to file '%s'", filename);

  json_decref(root);
}

void
load_kline_database(const char *filename)
{
  json_error_t error;

  json_t *root = json_load_file(filename, 0, &error);
  if (root == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Error loading JSON file '%s': %s (line %d)",
              filename, error.text, error.line);
    return;
  }

  json_t *k_lines = json_object_get(root, "k_lines");
  if (json_is_array(k_lines) == 0)
  {
    log_write(LOG_TYPE_IRCD, "Error: 'k_lines' is not an array in '%s'", filename);
    json_decref(root);
    return;
  }

  size_t index;
  json_t *entry;
  json_array_foreach(k_lines, index, entry)
  {
    const char *user, *host, *reason;
    uint64_t created_at, expires_at;
    int res = json_unpack_ex(entry, &error, 0, "{s:s, s:s, s:s, s:I, s:I}",
                             "user", &user,
                             "host", &host,
                             "reason", &reason,
                             "created_at", &created_at,
                             "expires_at", &expires_at);

    if (res)
    {
      log_write(LOG_TYPE_IRCD, "Error unpacking kline at index %zu: line %d, column %d, position %d: %s",
                index, error.line, error.column, error.position, error.text);
      continue;
    }

    struct MaskItem *conf = conf_make(CONF_KLINE);
    conf->user = io_strdup(user);
    conf->host = io_strdup(host);
    conf->reason = io_strdup(reason);
    conf->setat = created_at;
    conf->until = expires_at;

    SetConfDatabase(conf);
    add_conf_by_address(CONF_KLINE, conf);
  }

  json_decref(root);
}

void
save_dline_database(const char *filename)
{
  json_t *root = json_object();
  json_t *dline_array = json_array();
  json_object_set_new(root, "d_lines", dline_array);

  for (size_t i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    list_node_t *node;
    LIST_FOREACH(node, atable[i].head)
    {
      const struct AddressRec *arec = node->data;
      if (arec->type != CONF_DLINE || !IsConfDatabase(arec->conf))
        continue;

      json_error_t error;
      json_t *entry = json_pack_ex(&error, 0, "{s:s, s:s, s:I, s:I}",
                                   "host", arec->conf->host,
                                   "reason", arec->conf->reason,
                                   "created_at", arec->conf->setat,
                                   "expires_at", arec->conf->until);
      if (entry == NULL)
      {
        log_write(LOG_TYPE_IRCD, "Error packing dline: line %d, column %d, position %d: %s",
                  error.line, error.column, error.position, error.text);
        continue;
      }

      json_array_append_new(dline_array, entry);
    }
  }

  if (json_dump_file(root, filename, JSON_INDENT(4)))
    log_write(LOG_TYPE_IRCD, "Error writing JSON data to file '%s'", filename);

  json_decref(root);
}

void
load_dline_database(const char *filename)
{
  json_error_t error;

  json_t *root = json_load_file(filename, 0, &error);
  if (root == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Error loading JSON file '%s': %s (line %d)",
              filename, error.text, error.line);
    return;
  }

  json_t *d_lines = json_object_get(root, "d_lines");
  if (json_is_array(d_lines) == 0)
  {
    log_write(LOG_TYPE_IRCD, "Error: 'd_lines' is not an array in '%s'", filename);
    json_decref(root);
    return;
  }

  size_t index;
  json_t *entry;
  json_array_foreach(d_lines, index, entry)
  {
    const char *host, *reason;
    uint64_t created_at, expires_at;
    int res = json_unpack_ex(entry, &error, 0, "{s:s, s:s, s:I, s:I}",
                             "host", &host,
                             "reason", &reason,
                             "created_at", &created_at,
                             "expires_at", &expires_at);
    if (res)
    {
      log_write(LOG_TYPE_IRCD, "Error unpacking dline at index %zu: line %d, column %d, position %d: %s",
                index, error.line, error.column, error.position, error.text);
      continue;
    }

    struct MaskItem *conf = conf_make(CONF_DLINE);
    conf->host = io_strdup(host);
    conf->reason = io_strdup(reason);
    conf->setat = created_at;
    conf->until = expires_at;

    SetConfDatabase(conf);
    add_conf_by_address(CONF_DLINE, conf);
  }

  json_decref(root);
}

void
save_resv_database(const char *filename)
{
  json_t *root = json_object();
  json_t *resv_array = json_array();
  json_object_set_new(root, "resv", resv_array);

  list_node_t *node;
  LIST_FOREACH(node, resv_chan_get_list()->head)
  {
    const struct ResvItem *resv = node->data;
    if (resv->in_database == false)
      continue;

    json_error_t error;
    json_t *entry = json_pack_ex(&error, 0, "{s:s, s:s, s:I, s:I}",
                                 "mask", resv->mask,
                                 "reason", resv->reason,
                                 "created_at", resv->created_at,
                                 "expires_at", resv->expires_at);
    if (entry == NULL)
    {
      log_write(LOG_TYPE_IRCD, "Error packing resv: line %d, column %d, position %d: %s",
                error.line, error.column, error.position, error.text);
      continue;
    }

    json_array_append_new(resv_array, entry);
  }

  LIST_FOREACH(node, resv_nick_get_list()->head)
  {
    const struct ResvItem *resv = node->data;
    if (resv->in_database == false)
      continue;

    json_error_t error;
    json_t *entry = json_pack_ex(&error, 0, "{s:s, s:s, s:I, s:I}",
                                 "mask", resv->mask,
                                 "reason", resv->reason,
                                 "created_at", resv->created_at,
                                 "expires_at", resv->expires_at);
    if (entry == NULL)
    {
      log_write(LOG_TYPE_IRCD, "Error packing resv: line %d, column %d, position %d: %s",
                error.line, error.column, error.position, error.text);
      continue;
    }

    json_array_append_new(resv_array, entry);
  }

  if (json_dump_file(root, filename, JSON_INDENT(4)))
    log_write(LOG_TYPE_IRCD, "Error writing JSON data to file '%s'", filename);

  json_decref(root);
}

void
load_resv_database(const char *filename)
{
  json_error_t error;

  json_t *root = json_load_file(filename, 0, &error);
  if (root == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Error loading JSON file '%s': %s (line %d)",
              filename, error.text, error.line);
    return;
  }

  json_t *resv_array = json_object_get(root, "resv");
  if (json_is_array(resv_array) == 0)
  {
    log_write(LOG_TYPE_IRCD, "Error: 'resv' is not an array in '%s'", filename);
    json_decref(root);
    return;
  }

  size_t index;
  json_t *entry;
  json_array_foreach(resv_array, index, entry)
  {
    const char *mask, *reason;
    uint64_t created_at, expires_at;
    int res = json_unpack_ex(entry, &error, 0, "{s:s, s:s, s:I, s:I}",
                             "mask", &mask,
                             "reason", &reason,
                             "created_at", &created_at,
                             "expires_at", &expires_at);
    if (res)
    {
      log_write(LOG_TYPE_IRCD, "Error unpacking resv at index %zu: line %d, column %d, position %d: %s",
                index, error.line, error.column, error.position, error.text);
      continue;
    }

    struct ResvItem *resv = resv_make(mask, reason, NULL);
    resv->created_at = created_at;
    resv->expires_at = expires_at;
    resv->in_database = true;
  }

  json_decref(root);
}

void
save_xline_database(const char *filename)
{
  json_t *root = json_object();
  json_t *xline_array = json_array();
  json_object_set_new(root, "x_lines", xline_array);

  list_node_t *node;
  LIST_FOREACH(node, gecos_get_list()->head)
  {
    const struct GecosItem *gecos = node->data;
    if (gecos->in_database == false)
      continue;

    json_error_t error;
    json_t *entry = json_pack_ex(&error, 0, "{s:s, s:s, s:I, s:I}",
                                 "mask", gecos->mask,
                                 "reason", gecos->reason,
                                 "created_at", gecos->created_at,
                                 "expires_at", gecos->expires_at);
    if (entry == NULL)
    {
      log_write(LOG_TYPE_IRCD, "Error packing xline: line %d, column %d, position %d: %s",
                error.line, error.column, error.position, error.text);
      continue;
    }

    json_array_append_new(xline_array, entry);
  }

  if (json_dump_file(root, filename, JSON_INDENT(4)))
    log_write(LOG_TYPE_IRCD, "Error writing JSON data to file '%s'", filename);

  json_decref(root);
}

void
load_xline_database(const char *filename)
{
  json_error_t error;

  json_t *root = json_load_file(filename, 0, &error);
  if (root == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Error loading JSON file '%s': %s (line %d)",
              filename, error.text, error.line);
    return;
  }

  json_t *x_lines = json_object_get(root, "x_lines");
  if (json_is_array(x_lines) == 0)
  {
    log_write(LOG_TYPE_IRCD, "Error: 'x_lines' is not an array in '%s'", filename);
    json_decref(root);
    return;
  }

  size_t index;
  json_t *entry;
  json_array_foreach(x_lines, index, entry)
  {
    const char *mask, *reason;
    uint64_t created_at, expires_at;
    int res = json_unpack_ex(entry, &error, 0, "{s:s, s:s, s:I, s:I}",
                             "mask", &mask,
                             "reason", &reason,
                             "created_at", &created_at,
                             "expires_at", &expires_at);
    if (res)
    {
      log_write(LOG_TYPE_IRCD, "Error unpacking xline at index %zu: line %d, column %d, position %d: %s",
                index, error.line, error.column, error.position, error.text);
      continue;
    }

    struct GecosItem *gecos = gecos_make();
    gecos->mask = io_strdup(mask);
    gecos->reason = io_strdup(reason);
    gecos->created_at = created_at;
    gecos->expires_at = expires_at;
    gecos->in_database = true;
  }

  json_decref(root);
}

void
save_all_databases(void *unused)
{
  save_kline_database(ConfigGeneral.klinefile);
  save_dline_database(ConfigGeneral.dlinefile);
  save_xline_database(ConfigGeneral.xlinefile);
  save_resv_database(ConfigGeneral.resvfile);
}

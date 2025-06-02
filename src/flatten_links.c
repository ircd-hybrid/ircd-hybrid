/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
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

#include "stdinc.h"
#include "memory.h"
#include "io_string.h"
#include "list.h"
#include "log.h"
#include "ircd.h"
#include "numeric.h"
#include "client.h"
#include "conf.h"
#include "send.h"
#include "flatten_links.h"


static event_handle_t event_flatten_links_write_file;
static list_t flatten_links;

void
flatten_links_handle_event_state(uintmax_t new_interval_seconds)
{
  uintmax_t interval_ms = new_interval_seconds * 1000ULL;
  if (interval_ms > 0)
  {
    if (event_flatten_links_write_file == NULL)
      event_flatten_links_write_file = event_create(ircd_event_manager, "flatten_links_write_file", flatten_links_write_file, interval_ms, false, NULL, NULL);
    else
      event_set_interval_ms(event_flatten_links_write_file, interval_ms);

    event_schedule(event_flatten_links_write_file);
  }
  else if (event_flatten_links_write_file && event_is_scheduled(event_flatten_links_write_file))
    event_unschedule(event_flatten_links_write_file);
}

void
flatten_links_init(void)
{
  flatten_links_read_file();
  flatten_links_handle_event_state(ConfigServerHide.flatten_links_delay);
}

void
flatten_links_send(struct Client *client)
{
  /*
   * Print our own info so at least it looks like a normal links, then
   * print out the file (which may or may not be empty).
   */
  sendto_one_numeric(client, &me, RPL_LINKS, me.name, me.name, 0, me.info);

  list_node_t *node;
  LIST_FOREACH(node, flatten_links.head)
  {
    const char *const string = node->data;
    sendto_one_numeric(client, &me, RPL_LINKS | SND_EXPLICIT, "%s", string);
  }

  sendto_one_numeric(client, &me, RPL_ENDOFLINKS, "*");
}

void
flatten_links_clear(void)
{
  while (flatten_links.head)
  {
    list_node_t *node = flatten_links.head;
    list_remove(node, &flatten_links);
    io_free(node->data);
    list_free_node(node);
  }
}

void
flatten_links_add(const char *const data)
{
  list_add_tail(io_strdup(data), list_make_node(), &flatten_links);
}

void
flatten_links_write_file(void *unused)
{
  if (string_is_empty(ConfigServerHide.flatten_links_file))
    return;

  FILE *file = fopen(ConfigServerHide.flatten_links_file, "w");
  if (file == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Couldn't open \"%s\": %s",
              ConfigServerHide.flatten_links_file, strerror(errno));
    return;
  }

  flatten_links_clear();

  list_node_t *node;
  LIST_FOREACH(node, global_server_list.head)
  {
    const struct Client *client = node->data;

    /*
     * Skip hidden servers, aswell as ourselves, since we already send
     * ourselves in /links
     */
    if (IsHidden(client) || IsMe(client))
      continue;

    if (HasFlag(client, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      continue;

    /*
     * Attempt to format the file in such a way it follows the usual links output
     * ie  "servername uplink :hops info"
     * Mostly for aesthetic reasons - makes it look pretty in mIRC ;)
     * - madmax
     */
    char buf[IRCD_BUFSIZE];
    snprintf(buf, sizeof(buf), "%s %s :1 %s", client->name, me.name, client->info);
    flatten_links_add(buf);

    strlcat(buf, "\n", sizeof(buf));
    fputs(buf, file);
  }

  fclose(file);
}

void
flatten_links_read_file(void)
{
  if (string_is_empty(ConfigServerHide.flatten_links_file))
    return;

  FILE *file = fopen(ConfigServerHide.flatten_links_file, "r");
  if (file == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Couldn't open \"%s\": %s",
              ConfigServerHide.flatten_links_file, strerror(errno));
    return;
  }

  char buf[IRCD_BUFSIZE];
  while (fgets(buf, sizeof(buf), file))
  {
    char *p = strchr(buf, '\n');
    if (p)
      *p = '\0';

    flatten_links_add(buf);
  }

  fclose(file);
}

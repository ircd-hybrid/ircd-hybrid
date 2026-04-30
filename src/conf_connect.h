/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#ifndef INCLUDED_conf_connect_h
#define INCLUDED_conf_connect_h
#include <stdbool.h>
#include <stdint.h>

#include "address.h"
#include "list.h"

#include "conf_class.h"

typedef enum
{
  CONNECT_FLAG_ALLOW_AUTO_CONN    = 1 << 0,
  CONNECT_FLAG_USE_TLS            = 1 << 1,
  CONNECT_FLAG_ENCRYPTED_PASSWORD = 1 << 2,
} connect_flags_t;

typedef enum
{
  CONNECT_AUTH_FAIL_NAME = 1,
  CONNECT_AUTH_FAIL_HOST,
  CONNECT_AUTH_FAIL_TLS,
  CONNECT_AUTH_FAIL_CERTFP,
  CONNECT_AUTH_FAIL_PASSWORD,
  CONNECT_AUTH_SUCCESS,
} connect_auth_result_t;

struct ConnectItem
{
  list_node_t node;
  struct ClassItem *klass;
  char *name;
  char *host;
  char *accept_password;
  char *send_password;
  char *tls_cert_fingerprint;
  char *cipher_list;
  struct io_addr remote_addr;
  struct io_addr bind_addr;
  list_t hub_masks;
  list_t leaf_masks;
  int address_family;
  uint16_t port;
  uint32_t flags;
  uint32_t timeout;
  uint32_t ref_count;
  uintmax_t autoconnect_hold_until;
  bool active;
  bool dns_pending;
  bool dns_failed;
};

extern void connect_assign_class(struct ConnectItem *, const char *);
extern void connect_decref(struct ConnectItem *);
extern void connect_destroy(struct ConnectItem *);
extern void connect_dns_lookup(struct ConnectItem *);
extern void connect_incref(struct ConnectItem *);
extern void connect_mark_all_inactive(void);
extern void connect_sweep_inactive(void);
extern connect_auth_result_t connect_authenticate_server(const char *, const struct Client *, struct ConnectItem **);
extern list_t *connect_get_list(void);
extern struct ConnectItem *connect_create(void);
extern struct ConnectItem *connect_find(const char *);
extern const char *connect_auth_result_to_string(connect_auth_result_t);
#endif  /* INCLUDED_conf_connect_h */

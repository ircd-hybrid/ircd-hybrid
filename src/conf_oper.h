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

#ifndef INCLUDED_conf_oper_h
#define INCLUDED_conf_oper_h

#include <stdint.h>
#include <stdbool.h>

#include "address.h"
#include "client.h"
#include "conf_class.h"
#include "list.h"

typedef enum
{
  OPER_AUTH_FAIL_NAME = 1,
  OPER_AUTH_FAIL_HOST,
  OPER_AUTH_FAIL_TLS,
  OPER_AUTH_FAIL_CERTFP,
  OPER_AUTH_FAIL_CLASS_FULL,
  OPER_AUTH_FAIL_PASSWORD,
  OPER_AUTH_SUCCESS,
} oper_auth_result_t;

typedef enum
{
  OPER_CONF_FLAG_REQUIRE_TLS        = 1 << 0,
  OPER_CONF_FLAG_EXEMPT_LIMITS      = 1 << 1,
  OPER_CONF_FLAG_ENCRYPTED_PASSWORD = 1 << 2,
} oper_conf_flags_t;

typedef enum
{
  OPER_FLAG_ADMIN          = 1 <<  0,  /**< Oper can set user mode +a */
  OPER_FLAG_CLOSE          = 1 <<  1,  /**< Oper can use CLOSE command */
  OPER_FLAG_CONNECT        = 1 <<  2,  /**< Oper can do local CONNECT */
  OPER_FLAG_CONNECT_REMOTE = 1 <<  3,  /**< Oper can do remote CONNECT */
  OPER_FLAG_DIE            = 1 <<  4,  /**< Oper can use DIE command */
  OPER_FLAG_DLINE          = 1 <<  5,  /**< Oper can use DLINE command */
  OPER_FLAG_GLOBOPS        = 1 <<  6,  /**< Oper can use GLOBOPS command */
  OPER_FLAG_JOIN_RESV      = 1 <<  7,  /**< Oper can use JOIN on resv {} channels */
  OPER_FLAG_KILL           = 1 <<  8,  /**< Oper can KILL local users */
  OPER_FLAG_KILL_REMOTE    = 1 <<  9,  /**< Oper can KILL remote users */
  OPER_FLAG_KLINE          = 1 << 10,  /**< Oper can use KLINE command */
  OPER_FLAG_LOCOPS         = 1 << 11,  /**< Oper can use LOCOPS command */
  OPER_FLAG_MODULE         = 1 << 12,  /**< Oper can use MODULE command */
  OPER_FLAG_NICK_RESV      = 1 << 13,  /**< Oper can use NICK on resv {} nicks */
  OPER_FLAG_OPME           = 1 << 14,  /**< Oper can use OPME command */
  OPER_FLAG_REHASH         = 1 << 15,  /**< Oper can use REHASH command */
  OPER_FLAG_REHASH_REMOTE  = 1 << 16,  /**< Oper can do remote REHASH command */
  OPER_FLAG_REMOTEBAN      = 1 << 17,  /**< Oper can set remote bans */
  OPER_FLAG_RESTART        = 1 << 18,  /**< Oper can use RESTART command */
  OPER_FLAG_RESV           = 1 << 19,  /**< Oper can use RESV command */
  OPER_FLAG_SET            = 1 << 20,  /**< Oper can use SET command */
  OPER_FLAG_SQUIT          = 1 << 21,  /**< Oper can do local SQUIT */
  OPER_FLAG_SQUIT_REMOTE   = 1 << 22,  /**< Oper can do remote SQUIT */
  OPER_FLAG_UNDLINE        = 1 << 23,  /**< Oper can use UNDLINE command */
  OPER_FLAG_UNKLINE        = 1 << 24,  /**< Oper can use UNKLINE command */
  OPER_FLAG_UNRESV         = 1 << 25,  /**< Oper can use UNRESV command */
  OPER_FLAG_UNXLINE        = 1 << 26,  /**< Oper can use UNXLINE command */
  OPER_FLAG_WALLOPS        = 1 << 27,  /**< Oper can use WALLOPS command */
  OPER_FLAG_XLINE          = 1 << 28,  /**< Oper can use XLINE command */
  OPER_FLAG_MESSAGE_MASS   = 1 << 29,  /**< Oper can send mass messages */
} oper_priv_flags_t;

struct OperItem
{
  char *name;
  char *user;
  char *host;
  char *password;
  char *tls_cert_fingerprint;
  char *whois_text;
  char *modes;
  struct ClassItem *klass;
  enum hostmask_type htype;
  struct io_addr addr;
  int bits;
  oper_conf_flags_t flags;
  oper_priv_flags_t oper_privs;
  list_node_t node;
};

extern void oper_assign_class(struct OperItem *, const char *);
extern void oper_free(struct OperItem *);
extern void oper_free_all(void);
extern oper_auth_result_t oper_authenticate(const struct Client *, const char *, const char *, struct OperItem **);
extern list_t *oper_get_list(void);
extern struct OperItem *oper_create(void);
extern const char *oper_auth_result_to_string(oper_auth_result_t);
#endif  /* INCLUDED_conf_oper_h */

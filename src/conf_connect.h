#ifndef INCLUDED_conf_connect_h
#define INCLUDED_conf_connect_h

#include "list.h"
#include "address.h"
#include "conf_class.h"

typedef enum
{
  CONNECT_FLAG_ALLOW_AUTO_CONN    = 1 << 0,
  CONNECT_FLAG_USE_TLS            = 1 << 1,
  CONNECT_FLAG_ENCRYPTED_PASSWORD = 1 << 2,
} connect_flags_t;

struct ConnectItem
{
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

  struct ClassItem *class;

  int port;
  int address_family;
  unsigned int flags;
  unsigned int timeout;

  list_node_t node;
  unsigned int ref_count;
  bool active;
  bool dns_pending;
  bool dns_failed;
  uintmax_t autoconnect_hold_until;
};

extern struct ConnectItem *connect_create(void);
extern void connect_free(struct ConnectItem *);
extern void connect_dns_lookup(struct ConnectItem *);
extern void connect_mark_all_inactive(void);
extern void connect_free_inactive(void);
extern void connect_assign_class(struct ConnectItem *, const char *);
extern bool connect_match_password(const char *, const struct ConnectItem *);
extern struct ConnectItem *connect_find(const char *);
extern list_t *connect_get_list(void);
extern void connect_incref(struct ConnectItem *);
extern void connect_decref(struct ConnectItem *);
#endif  /* INCLUDED_conf_connect_h */

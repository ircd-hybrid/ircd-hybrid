#include "stdinc.h"
#include "memory.h"
#include "io_string.h"
#include "res.h"
#include "reslib.h"
#include "client.h"
#include "conf_connect.h"
#include "conf_class.h"
#include "send.h"

static list_t connect_items;

void
connect_assign_class(struct ConnectItem *connect, const char *class_name)
{
  assert(connect);

  if (!string_is_empty(class_name))
    connect->class = class_find(class_name, true);

  if (connect->class == NULL)
  {
    connect->class = class_default;
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Warning: Class '%s' not found for connect block '%s'. Defaulting to class '%s'.",
                   string_default(class_name, "<not specified>"), connect->name, connect->class->name);
  }
}

void
connect_mark_all_inactive(void)
{
  list_node_t *node;
  LIST_FOREACH(node, connect_items.head)
  {
    struct ConnectItem *const connect = node->data;
    connect->active = false;
  }
}

void
connect_free_inactive(void)
{
  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, connect_items.head)
  {
    struct ConnectItem *const connect = node->data;
    if (connect->active == false && connect->ref_count == 0)
    {
      list_remove(&connect->node, &connect_items);
      connect_free(connect);
    }
  }
}

struct ConnectItem *
connect_create(void)
{
  struct ConnectItem *const connect = io_calloc(sizeof(*connect));
  connect->active = true;
  connect->address_family = AF_INET;

  list_add(connect, &connect->node, &connect_items);
  return connect;
}

void
connect_free(struct ConnectItem *connect)
{
  assert(connect);

  if (connect->dns_pending)
    delete_resolver_queries(connect);

  if (connect->accept_password)
    memset(connect->accept_password, 0, strlen(connect->accept_password));
  if (connect->send_password)
    memset(connect->send_password, 0, strlen(connect->send_password));

  io_free(connect->name);
  io_free(connect->host);
  io_free(connect->accept_password);
  io_free(connect->send_password);
  io_free(connect->tls_cert_fingerprint);
  io_free(connect->cipher_list);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, connect->hub_masks.head)
  {
    io_free(node->data);
    list_remove(node, &connect->hub_masks);
    list_free_node(node);
  }

  LIST_FOREACH_SAFE(node, node_next, connect->leaf_masks.head)
  {
    io_free(node->data);
    list_remove(node, &connect->leaf_masks);
    list_free_node(node);
  }

  io_free(connect);
}

static void
connect_dns_callback(void *vptr, const struct io_addr *addr, const char *name, size_t name_length)
{
  struct ConnectItem *const connect = vptr;
  connect->dns_pending = false;

  if (addr)
    address_copy(&connect->remote_addr, addr);
  else
    connect->dns_failed = true;
}

void
connect_dns_lookup(struct ConnectItem *connect)
{
  if (address_from_string(connect->host, &connect->remote_addr))
    return;

  /*
   * By this point connect->host possibly is not a numerical network address. Do a nameserver
   * lookup of the connect host. If the connect entry is currently doing a ns lookup do nothing.
   */
  if (connect->dns_pending)
    return;

  connect->dns_pending = true;

  if (connect->address_family == AF_INET)
    gethost_byname_type(connect_dns_callback, connect, connect->host, T_A);
  else
    gethost_byname_type(connect_dns_callback, connect, connect->host, T_AAAA);
}

struct ConnectItem *
connect_find(const char *name)
{
  list_node_t *node;
  LIST_FOREACH(node, connect_items.head)
  {
    struct ConnectItem *const connect = node->data;
    if (match(name, connect->name) == 0)
      return connect;
  }

  return NULL;
}

bool
connect_match_password(const char *password, const struct ConnectItem *connect)
{
  if (string_is_empty(password) || string_is_empty(connect->accept_password))
    return false;

  const char *encr;
  if (connect->flags & CONNECT_FLAG_ENCRYPTED_PASSWORD)
    encr = crypt(password, connect->accept_password);
  else
    encr = password;

  return encr && strcmp(encr, connect->accept_password) == 0;
}

list_t *
connect_get_list(void)
{
  return &connect_items;
}

void
connect_incref(struct ConnectItem *connect)
{
  if (connect)
    connect->ref_count++;
}

void
connect_decref(struct ConnectItem *connect)
{
  assert(connect);
  assert(connect->ref_count > 0);

  connect->ref_count--;

  if (connect->ref_count == 0 && connect->active == false)
  {
    list_remove(&connect->node, &connect_items);
    connect_free(connect);
  }
}

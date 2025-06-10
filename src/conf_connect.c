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
connect_assign_class(struct ConnectItem *conf, const char *class_name)
{
  assert(conf);

  if (!string_is_empty(class_name))
    conf->class = class_find(class_name, true);

  if (conf->class == NULL)
  {
    conf->class = class_default;
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Warning: Class '%s' not found for connect block '%s'. Defaulting to class '%s'.",
                   string_or_empty(class_name), conf->name, conf->class->name);
  }
}

void
connect_mark_all_inactive(void)
{
  list_node_t *node;
  LIST_FOREACH(node, connect_items.head)
  {
    struct ConnectItem *const conf = node->data;
    conf->active = false;
  }
}

void
connect_free_inactive(void)
{
  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, connect_items.head)
  {
    struct ConnectItem *const conf = node->data;
    if (conf->active == false && conf->ref_count == 0)
    {
      list_remove(&conf->node, &connect_items);
      connect_free(conf);
    }
  }
}

struct ConnectItem *
connect_create(void)
{
  struct ConnectItem *const conf = io_calloc(sizeof(*conf));
  conf->active = true;
  conf->address_family = AF_INET;

  list_add(conf, &conf->node, &connect_items);
  return conf;
}

void
connect_free(struct ConnectItem *conf)
{
  assert(conf);

  if (conf->dns_pending)
    delete_resolver_queries(conf);

  if (conf->accept_password)
    memset(conf->accept_password, 0, strlen(conf->accept_password));
  if (conf->send_password)
    memset(conf->send_password, 0, strlen(conf->send_password));

  io_free(conf->name);
  io_free(conf->host);
  io_free(conf->accept_password);
  io_free(conf->send_password);
  io_free(conf->tls_cert_fingerprint);
  io_free(conf->cipher_list);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, conf->hub_masks.head)
  {
    io_free(node->data);
    list_remove(node, &conf->hub_masks);
    list_free_node(node);
  }

  LIST_FOREACH_SAFE(node, node_next, conf->leaf_masks.head)
  {
    io_free(node->data);
    list_remove(node, &conf->leaf_masks);
    list_free_node(node);
  }

  io_free(conf);
}

static void
connect_dns_callback(void *vptr, const struct io_addr *addr, const char *name, size_t namelength)
{
  struct ConnectItem *const conf = vptr;
  conf->dns_pending = false;

  if (addr)
    address_copy(&conf->remote_addr, addr);
  else
    conf->dns_failed = true;
}

void
connect_dns_lookup(struct ConnectItem *conf)
{
  if (address_from_string(conf->host, &conf->remote_addr))
    return;

  /*
   * By this point conf->host possibly is not a numerical network address. Do a nameserver
   * lookup of the conf host. If the conf entry is currently doing a ns lookup do nothing.
   */
  if (conf->dns_pending)
    return;

  conf->dns_pending = true;

  if (conf->address_family == AF_INET)
    gethost_byname_type(connect_dns_callback, conf, conf->host, T_A);
  else
    gethost_byname_type(connect_dns_callback, conf, conf->host, T_AAAA);
}

struct ConnectItem *
connect_find(const char *name)
{
  list_node_t *node;
  LIST_FOREACH(node, connect_items.head)
  {
    struct ConnectItem *const conf = node->data;
    if (match(name, conf->name) == 0)
    {
      conf->active = true;
      return conf;
    }
  }

  return NULL;
}

bool
connect_match_password(const char *password, const struct ConnectItem *conf)
{
  if (string_is_empty(password) || string_is_empty(conf->accept_password))
    return false;

  const char *encr;
  if (conf->flags & CONNECT_FLAG_ENCRYPTED_PASSWORD)
    encr = crypt(password, conf->accept_password);
  else
    encr = password;

  return encr && strcmp(encr, conf->accept_password) == 0;
}

list_t *
connect_get_list(void)
{
  return &connect_items;
}

void
connect_incref(struct ConnectItem *conf)
{
  if (conf)
    conf->ref_count++;
}

void
connect_decref(struct ConnectItem *conf)
{
  assert(conf);
  assert(conf->ref_count > 0);

  conf->ref_count--;

  if (conf->ref_count == 0 && conf->active == false)
  {
    list_find_remove(&connect_items, conf);
    connect_free(conf);
  }
}

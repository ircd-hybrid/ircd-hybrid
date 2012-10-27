/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_serv.c: Server related functions.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#include "stdinc.h"
#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include "rsa.h"
#endif
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"
#include "dbuf.h"
#include "event.h"
#include "fdlist.h"
#include "hash.h"
#include "irc_string.h"
#include "inet_misc.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "s_bsd.h"
#include "irc_getnameinfo.h"
#include "numeric.h"
#include "packet.h"
#include "irc_res.h"
#include "s_conf.h"
#include "s_serv.h"
#include "s_log.h"
#include "s_user.h"
#include "send.h"
#include "memory.h"
#include "channel.h" /* chcap_usage_counts stuff...*/

#define MIN_CONN_FREQ 300

static dlink_list cap_list = { NULL, NULL, 0 };
static void server_burst(struct Client *);
static int fork_server(struct Client *);
static void burst_all(struct Client *);
static void send_tb(struct Client *client_p, struct Channel *chptr);

static CNCB serv_connect_callback;

static void start_io(struct Client *);
static void burst_members(struct Client *, struct Channel *);

static SlinkRplHnd slink_error;
static SlinkRplHnd slink_zipstats;


#ifdef HAVE_LIBCRYPTO
struct EncCapability CipherTable[] =
{
#ifdef HAVE_EVP_BF_CFB
  { "BF/168",     CAP_ENC_BF_168,     24, CIPHER_BF     },
  { "BF/128",     CAP_ENC_BF_128,     16, CIPHER_BF     },
#endif
#ifdef HAVE_EVP_CAST5_CFB
  { "CAST/128",   CAP_ENC_CAST_128,   16, CIPHER_CAST   },
#endif
#ifdef HAVE_EVP_IDEA_CFB
  { "IDEA/128",   CAP_ENC_IDEA_128,   16, CIPHER_IDEA   },
#endif
#ifdef HAVE_EVP_RC5_32_12_16_CFB
  { "RC5.16/128", CAP_ENC_RC5_16_128, 16, CIPHER_RC5_16 },
  { "RC5.12/128", CAP_ENC_RC5_12_128, 16, CIPHER_RC5_12 },
  { "RC5.8/128",  CAP_ENC_RC5_8_128,  16, CIPHER_RC5_8  },
#endif
#ifdef HAVE_EVP_DES_EDE3_CFB
  { "3DES/168",   CAP_ENC_3DES_168,   24, CIPHER_3DES   },
#endif
#ifdef HAVE_EVP_DES_CFB
  { "DES/56",     CAP_ENC_DES_56,      8, CIPHER_DES    },
#endif
  { 0,            0,                   0, 0             }
};
#endif

struct SlinkRplDef slinkrpltab[] = {
  { SLINKRPL_ERROR,    slink_error,    SLINKRPL_FLAG_DATA },
  { SLINKRPL_ZIPSTATS, slink_zipstats, SLINKRPL_FLAG_DATA },
  { 0,                 0,              0 },
};


void
slink_error(unsigned int rpl, unsigned int len, unsigned char *data,
            struct Client *server_p)
{
  assert(rpl == SLINKRPL_ERROR);
  assert(len < 256);

  data[len-1] = '\0';

  sendto_realops_flags(UMODE_ALL, L_ALL, "SlinkError for %s: %s",
                       server_p->name, data);
  /* XXX should this be exit_client? */
  exit_client(server_p, &me, "servlink error -- terminating link");
}

void
slink_zipstats(unsigned int rpl, unsigned int len, unsigned char *data,
               struct Client *server_p)
{
  struct ZipStats zipstats;
  uint64_t in = 0, in_wire = 0, out = 0, out_wire = 0;
  int i = 0;

  assert(rpl == SLINKRPL_ZIPSTATS);
  assert(len == 16);
  assert(IsCapable(server_p, CAP_ZIP));

  /* Yes, it needs to be done this way, no we cannot let the compiler
   * work with the pointer to the structure.  This works around a GCC
   * bug on SPARC that affects all versions at the time of this writing.
   * I will feed you to the creatures living in RMS's beard if you do
   * not leave this as is, without being sure that you are not causing
   * regression for most of our installed SPARC base.
   * -jmallett, 04/27/2002
   */
  memcpy(&zipstats, &server_p->localClient->zipstats, sizeof(struct ZipStats));

  in |= (data[i++] << 24);
  in |= (data[i++] << 16);
  in |= (data[i++] <<  8);
  in |= (data[i++]      );

  in_wire |= (data[i++] << 24);
  in_wire |= (data[i++] << 16);
  in_wire |= (data[i++] <<  8);
  in_wire |= (data[i++]      );

  out |= (data[i++] << 24);
  out |= (data[i++] << 16);
  out |= (data[i++] <<  8);
  out |= (data[i++]      );

  out_wire |= (data[i++] << 24);
  out_wire |= (data[i++] << 16);
  out_wire |= (data[i++] <<  8);
  out_wire |= (data[i++]      );

  /* This macro adds b to a if a plus b is not an overflow, and sets the
   * value of a to b if it is.
   * Add and Set if No Overflow.
   */
#define	ASNO(a, b) a = (a + b >= a ? a + b : b)

  ASNO(zipstats.in, in);
  ASNO(zipstats.out, out);
  ASNO(zipstats.in_wire, in_wire);
  ASNO(zipstats.out_wire, out_wire);

  if (zipstats.in > 0)
    zipstats.in_ratio = (((double)(zipstats.in - zipstats.in_wire) /
                         (double)zipstats.in) * 100.00);
  else
    zipstats.in_ratio = 0;

  if (zipstats.out > 0)
    zipstats.out_ratio = (((double)(zipstats.out - zipstats.out_wire) /
                          (double)zipstats.out) * 100.00);
  else
    zipstats.out_ratio = 0;

  memcpy(&server_p->localClient->zipstats, &zipstats, sizeof(struct ZipStats));
}

void
collect_zipstats(void *unused)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, serv_list.head)
  {
    struct Client *target_p = ptr->data;

    if (IsCapable(target_p, CAP_ZIP))
    {
      /* only bother if we haven't already got something queued... */
      if (!target_p->localClient->slinkq)
      {
        target_p->localClient->slinkq     = MyMalloc(1); /* sigh.. */
        target_p->localClient->slinkq[0]  = SLINKCMD_ZIPSTATS;
        target_p->localClient->slinkq_ofs = 0;
        target_p->localClient->slinkq_len = 1;
        send_queued_slink_write(target_p);
      }
    }
  }
}

#ifdef HAVE_LIBCRYPTO
struct EncCapability *
check_cipher(struct Client *client_p, struct AccessItem *aconf)
{
  struct EncCapability *epref = NULL;

  /* Use connect{} specific info if available */
  if (aconf->cipher_preference)
    epref = aconf->cipher_preference;
  else if (ConfigFileEntry.default_cipher_preference)
    epref = ConfigFileEntry.default_cipher_preference;

  /*
   * If the server supports the capability in hand, return the matching
   * conf struct.  Otherwise, return NULL (an error).
   */
  if (epref && IsCapableEnc(client_p, epref->cap))
    return epref;

  return NULL;
}
#endif /* HAVE_LIBCRYPTO */

/* my_name_for_link()
 * return wildcard name of my server name 
 * according to given config entry --Jto
 */
const char *
my_name_for_link(struct ConfItem *conf)
{
  struct AccessItem *aconf;

  aconf = (struct AccessItem *)map_to_conf(conf);
  if (aconf->fakename != NULL)
    return aconf->fakename;
  else
    return me.name;
}

/*
 * write_links_file
 *
 * inputs	- void pointer which is not used
 * output	- NONE
 * side effects	- called from an event, write out list of linked servers
 *		  but in no particular order.
 */
void
write_links_file(void* notused)
{
  MessageFileLine *next_mptr = 0;
  MessageFileLine *mptr = 0;
  MessageFileLine *currentMessageLine = 0;
  MessageFileLine *newMessageLine = 0;
  MessageFile *MessageFileptr;
  const char *p;
  FBFILE *file;
  char buff[512];
  dlink_node *ptr;

  MessageFileptr = &ConfigFileEntry.linksfile;

  if ((file = fbopen(MessageFileptr->fileName, "w")) == NULL)
    return;

  for (mptr = MessageFileptr->contentsOfFile; mptr; mptr = next_mptr)
  {
    next_mptr = mptr->next;
    MyFree(mptr);
  }

  MessageFileptr->contentsOfFile = NULL;
  currentMessageLine             = NULL;

  DLINK_FOREACH(ptr, global_serv_list.head)
  {
    size_t nbytes = 0;
    struct Client *target_p = ptr->data;

    /* skip ourselves, we send ourselves in /links */
    if (IsMe(target_p))
      continue;

    /* skip hidden servers */
    if (IsHidden(target_p) && !ConfigServerHide.disable_hidden)
      continue;

    if (target_p->info[0])
      p = target_p->info;
    else
      p = "(Unknown Location)";

    newMessageLine = MyMalloc(sizeof(MessageFileLine));

    /* Attempt to format the file in such a way it follows the usual links output
     * ie  "servername uplink :hops info"
     * Mostly for aesthetic reasons - makes it look pretty in mIRC ;)
     * - madmax
     */

    /* 
     * For now, check this ircsprintf wont overflow - it shouldnt on a
     * default config but it is configurable..
     * This should be changed to an snprintf at some point, but I'm wanting to
     * know if this is a cause of a bug - cryogen
     */
    assert(strlen(target_p->name) + strlen(me.name) + 6 + strlen(p) <= 
            MESSAGELINELEN);
    ircsprintf(newMessageLine->line, "%s %s :1 %s",
               target_p->name, me.name, p);
    newMessageLine->next = NULL;

    if (MessageFileptr->contentsOfFile)
    {
      if (currentMessageLine)
        currentMessageLine->next = newMessageLine;
      currentMessageLine = newMessageLine;
    }
    else
    {
      MessageFileptr->contentsOfFile = newMessageLine;
      currentMessageLine = newMessageLine;
    }

    nbytes = ircsprintf(buff, "%s %s :1 %s\n", target_p->name, me.name, p);
    fbputs(buff, file, nbytes);
  }

  fbclose(file);
}

/* hunt_server()
 *      Do the basic thing in delivering the message (command)
 *      across the relays to the specific server (server) for
 *      actions.
 *
 *      Note:   The command is a format string and *MUST* be
 *              of prefixed style (e.g. ":%s COMMAND %s ...").
 *              Command can have only max 8 parameters.
 *
 *      server  parv[server] is the parameter identifying the
 *              target server.
 *
 *      *WARNING*
 *              parv[server] is replaced with the pointer to the
 *              real servername from the matched client (I'm lazy
 *              now --msa).
 *
 *      returns: (see #defines)
 */
int
hunt_server(struct Client *client_p, struct Client *source_p, const char *command,
            int server, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Client *target_tmp = NULL;
  dlink_node *ptr;
  int wilds;

  /* Assume it's me, if no server
   */
  if (parc <= server || EmptyString(parv[server]) ||
      match(me.name, parv[server]) ||
      match(parv[server], me.name) ||
      !strcmp(parv[server], me.id))
    return(HUNTED_ISME);

  /* These are to pickup matches that would cause the following
   * message to go in the wrong direction while doing quick fast
   * non-matching lookups.
   */
  if (MyClient(source_p))
    target_p = find_client(parv[server]);
  else
    target_p = find_person(client_p, parv[server]);

  if (target_p)
    if (target_p->from == source_p->from && !MyConnect(target_p))
      target_p = NULL;

  if (target_p == NULL && (target_p = find_server(parv[server])))
    if (target_p->from == source_p->from && !MyConnect(target_p))
      target_p = NULL;

  collapse(parv[server]);
  wilds = (strchr(parv[server], '?') || strchr(parv[server], '*'));

  /* Again, if there are no wild cards involved in the server
   * name, use the hash lookup
   */
  if (target_p == NULL)
  {
    if (!wilds)
    {
      if (!(target_p = find_server(parv[server])))
      {
        sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
                   me.name, parv[0], parv[server]);
        return(HUNTED_NOSUCH);
      }
    }
    else
    {
      DLINK_FOREACH(ptr, global_client_list.head)
      {
        target_tmp = ptr->data;

        if (match(parv[server], target_tmp->name))
        {
          if (target_tmp->from == source_p->from && !MyConnect(target_tmp))
            continue;
          target_p = ptr->data;

          if (IsRegistered(target_p) && (target_p != client_p))
            break;
        }
      }
    }
  }

  if (target_p != NULL)
  {
    if(!IsRegistered(target_p))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
                 me.name, parv[0], parv[server]);
      return HUNTED_NOSUCH;
    }

    if (IsMe(target_p) || MyClient(target_p))
      return HUNTED_ISME;

    if (!match(target_p->name, parv[server]))
      parv[server] = target_p->name;

    /* This is a little kludgy but should work... */
    if (IsClient(source_p) &&
        ((MyConnect(target_p) && IsCapable(target_p, CAP_TS6)) ||
         (!MyConnect(target_p) && IsCapable(target_p->from, CAP_TS6))))
      parv[0] = ID(source_p);

    sendto_one(target_p, command, parv[0],
               parv[1], parv[2], parv[3], parv[4],
               parv[5], parv[6], parv[7], parv[8]);
    return(HUNTED_PASS);
  } 

  sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
             me.name, parv[0], parv[server]);
  return(HUNTED_NOSUCH);
}

/* try_connections()
 *
 * inputs	- void pointer which is not used
 * output	- NONE
 * side effects	-
 * scan through configuration and try new connections.
 * Returns the calendar time when the next call to this
 * function should be made latest. (No harm done if this
 * is called earlier or later...)
 */
void
try_connections(void *unused)
{
  dlink_node *ptr;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct ClassItem *cltmp;
  int confrq;

  /* TODO: change this to set active flag to 0 when added to event! --Habeeb */
  if (GlobalSetOptions.autoconn == 0)
    return;

  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;
    aconf = map_to_conf(conf);

    /* Also when already connecting! (update holdtimes) --SRB 
     */
    if (!(aconf->status & CONF_SERVER) || !aconf->port ||
        !(IsConfAllowAutoConn(aconf)))
      continue;

    cltmp = map_to_conf(aconf->class_ptr);

    /* Skip this entry if the use of it is still on hold until
     * future. Otherwise handle this entry (and set it on hold
     * until next time). Will reset only hold times, if already
     * made one successfull connection... [this algorithm is
     * a bit fuzzy... -- msa >;) ]
     */
    if (aconf->hold > CurrentTime)
      continue;

    if (cltmp == NULL)
      confrq = DEFAULT_CONNECTFREQUENCY;
    else
    {
      confrq = ConFreq(cltmp);
      if (confrq < MIN_CONN_FREQ )
	confrq = MIN_CONN_FREQ;
    }

    aconf->hold = CurrentTime + confrq;

    /* Found a CONNECT config with port specified, scan clients
     * and see if this server is already connected?
     */
    if (find_server(conf->name) != NULL)
      continue;

    if (CurrUserCount(cltmp) < MaxTotal(cltmp))
    {
      /* Go to the end of the list, if not already last */
      if (ptr->next != NULL)
      {
        dlinkDelete(ptr, &server_items);
        dlinkAddTail(conf, &conf->node, &server_items);
      }

      if (find_servconn_in_progress(conf->name))
        return;

      /* We used to only print this if serv_connect() actually
       * succeeded, but since comm_tcp_connect() can call the callback
       * immediately if there is an error, we were getting error messages
       * in the wrong order. SO, we just print out the activated line,
       * and let serv_connect() / serv_connect_callback() print an
       * error afterwards if it fails.
       *   -- adrian
       */
      if (ConfigServerHide.hide_server_ips)
        sendto_realops_flags(UMODE_ALL, L_ALL, "Connection to %s activated.",
                             conf->name);
      else
        sendto_realops_flags(UMODE_ALL, L_ALL, "Connection to %s[%s] activated.",
                             conf->name, aconf->host);

      serv_connect(aconf, NULL);
      /* We connect only one at time... */
      return;
    }
  }
}

int
check_server(const char *name, struct Client *client_p, int cryptlink)
{
  dlink_node *ptr;
  struct ConfItem *conf           = NULL;
  struct ConfItem *server_conf    = NULL;
  struct AccessItem *server_aconf = NULL;
  struct AccessItem *aconf        = NULL;
  int error = -1;

  assert(client_p != NULL);

  if (client_p == NULL)
    return(error);

  if (strlen(name) > HOSTLEN)
    return(-4);

  /* loop through looking for all possible connect items that might work */
  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;
    aconf = map_to_conf(conf);

    if (!match(name, conf->name))
      continue;

    error = -3;

    /* XXX: Fix me for IPv6                    */
    /* XXX sockhost is the IPv4 ip as a string */
    if (match(aconf->host, client_p->host) || 
        match(aconf->host, client_p->sockhost))
    {
      error = -2;
#ifdef HAVE_LIBCRYPTO
      if (cryptlink && IsConfCryptLink(aconf))
      {
        if (aconf->rsa_public_key)
          server_conf = conf;
      }
      else if (!(cryptlink || IsConfCryptLink(aconf)))
#endif /* HAVE_LIBCRYPTO */
      {
        /* A NULL password is as good as a bad one */
        if (EmptyString(client_p->localClient->passwd))
          return(-2);

	/* code in s_conf.c should not have allowed this to be NULL */
	if (aconf->passwd == NULL)
	  return(-2);

        if (IsConfEncrypted(aconf))
        {
          if (strcmp(aconf->passwd,
              (const char *)crypt(client_p->localClient->passwd,
				  aconf->passwd)) == 0)
            server_conf = conf;
        }
        else
        {
          if (strcmp(aconf->passwd, client_p->localClient->passwd) == 0)
            server_conf = conf;
        }
      }
    }
  }

  if (server_conf == NULL)
    return(error);

  attach_conf(client_p, server_conf);

  /* Now find all leaf or hub config items for this server */
  DLINK_FOREACH(ptr, hub_items.head)
  {
    conf = ptr->data;

    if (!match(name, conf->name))
      continue;
    attach_conf(client_p, conf);
  }

  DLINK_FOREACH(ptr, leaf_items.head)
  {
    conf = ptr->data;

    if (!match(name, conf->name))
      continue;
    attach_conf(client_p, conf);
  }

  server_aconf = map_to_conf(server_conf);

#ifdef HAVE_LIBZ /* otherwise, clear it unconditionally */
  if (!IsConfCompressed(server_aconf))
#endif
    ClearCap(client_p, CAP_ZIP);
  if (!IsConfCryptLink(server_aconf))
    ClearCap(client_p, CAP_ENC);
  if (!IsConfTopicBurst(server_aconf))
  {
    ClearCap(client_p, CAP_TB);
    ClearCap(client_p, CAP_TBURST);
  }

  /* Don't unset CAP_HUB here even if the server isn't a hub,
   * it only indicates if the server thinks it's lazylinks are
   * leafs or not.. if you unset it, bad things will happen
   */
  if (aconf != NULL)
  {
    struct sockaddr_in *v4;
#ifdef IPV6
    struct sockaddr_in6 *v6;
#endif
    switch (aconf->aftype)
    {
#ifdef IPV6
      case AF_INET6: 
        v6 = (struct sockaddr_in6 *)&aconf->ipnum;

        if (IN6_IS_ADDR_UNSPECIFIED(&v6->sin6_addr))
          memcpy(&aconf->ipnum, &client_p->localClient->ip, sizeof(struct irc_ssaddr));
        break;
#endif
      case AF_INET:
        v4 = (struct sockaddr_in *)&aconf->ipnum;

        if (v4->sin_addr.s_addr == INADDR_NONE)
          memcpy(&aconf->ipnum, &client_p->localClient->ip, sizeof(struct irc_ssaddr)); 
        break;
    }
  }

  return(0);
}

/* add_capability()
 *
 * inputs	- string name of CAPAB
 *		- int flag of capability
 * output	- NONE
 * side effects	- Adds given capability name and bit mask to
 *		  current supported capabilities. This allows
 *		  modules to dynamically add or subtract their capability.
 */
void
add_capability(const char *capab_name, int cap_flag, int add_to_default)
{
  struct Capability *cap = MyMalloc(sizeof(*cap));

  DupString(cap->name, capab_name);
  cap->cap = cap_flag;
  dlinkAdd(cap, &cap->node, &cap_list);

  if (add_to_default)
    default_server_capabs |= cap_flag;
}

/* delete_capability()
 *
 * inputs	- string name of CAPAB
 * output	- NONE
 * side effects	- delete given capability from ones known.
 */
int
delete_capability(const char *capab_name)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct Capability *cap;

  DLINK_FOREACH_SAFE(ptr, next_ptr, cap_list.head)
  {
    cap = ptr->data;

    if (cap->cap != 0)
    {
      if (irccmp(cap->name, capab_name) == 0)
      {
	default_server_capabs &= ~(cap->cap);
	dlinkDelete(ptr, &cap_list);
	MyFree(cap->name);
	cap->name = NULL;
	MyFree(cap);
      }
    }
  }

  return 0;
}

/*
 * find_capability()
 *
 * inputs	- string name of capab to find
 * output	- 0 if not found CAPAB otherwise
 * side effects	- none
 */
int
find_capability(const char *capab)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, cap_list.head)
  {
    const struct Capability *cap = ptr->data;

    if (cap->cap && !irccmp(cap->name, capab))
      return cap->cap;
  }

  return 0;
}

/* send_capabilities()
 *
 * inputs	- Client pointer to send to
 *		- Pointer to AccessItem (for crypt)
 *		- int flag of capabilities that this server can send
 *		- int flag of encryption capabilities
 * output	- NONE
 * side effects	- send the CAPAB line to a server  -orabidoo
 *
 */
void
send_capabilities(struct Client *client_p, struct AccessItem *aconf,
                  int cap_can_send, int enc_can_send)
{
  struct Capability *cap=NULL;
  char msgbuf[IRCD_BUFSIZE];
  char *t;
  int tl;
  dlink_node *ptr;
#ifdef HAVE_LIBCRYPTO
  const struct EncCapability *epref = NULL;
  char *capend;
  int sent_cipher = 0;
#endif

  t = msgbuf;

  DLINK_FOREACH(ptr, cap_list.head)
  {
    cap = ptr->data;

    if (cap->cap & (cap_can_send|default_server_capabs))
    {
      tl = ircsprintf(t, "%s ", cap->name);
      t += tl;
    }
  }
#ifdef HAVE_LIBCRYPTO
  if (enc_can_send)
  {
    capend = t;
    strcpy(t, "ENC:");
    t += 4;

    /* use connect{} specific info if available */
    if (aconf->cipher_preference)
      epref = aconf->cipher_preference;
    else if (ConfigFileEntry.default_cipher_preference)
      epref = ConfigFileEntry.default_cipher_preference;

    if (epref && (epref->cap & enc_can_send))
    {
      /* Leave the space -- it is removed later. */
      tl = ircsprintf(t, "%s ", epref->name);
      t += tl;
      sent_cipher = 1;
    }

    if (!sent_cipher)
      t = capend; /* truncate string before ENC:, below */
  }
#endif
  *(t - 1) = '\0';
  sendto_one(client_p, "CAPAB :%s", msgbuf);
}

/* sendnick_TS()
 * 
 * inputs	- client (server) to send nick towards
 *          - client to send nick for
 * output	- NONE
 * side effects	- NICK message is sent towards given client_p
 */
void
sendnick_TS(struct Client *client_p, struct Client *target_p)
{
  static char ubuf[12];

  if (!IsClient(target_p))
    return;

  send_umode(NULL, target_p, 0, IsOperHiddenAdmin(target_p) ?
    SEND_UMODES & ~UMODE_ADMIN : SEND_UMODES, ubuf);

  if (ubuf[0] == '\0')
  {
    ubuf[0] = '+';
    ubuf[1] = '\0';
  }

  /* XXX Both of these need to have a :me.name or :mySID!?!?! */
  if (HasID(target_p) && IsCapable(client_p, CAP_TS6))
    sendto_one(client_p, ":%s UID %s %d %lu %s %s %s %s %s :%s",
               target_p->servptr->id,
               target_p->name, target_p->hopcount + 1,
               (unsigned long) target_p->tsinfo,
               ubuf, target_p->username, target_p->host,
               (MyClient(target_p) && IsIPSpoof(target_p)) ?
               "0" : target_p->sockhost, target_p->id, target_p->info);
  else
    sendto_one(client_p, "NICK %s %d %lu %s %s %s %s :%s",
	       target_p->name, target_p->hopcount + 1,
	       (unsigned long) target_p->tsinfo,
	       ubuf, target_p->username, target_p->host,
	       target_p->servptr->name, target_p->info);

  if (IsConfAwayBurst((struct AccessItem *)map_to_conf(client_p->serv->sconf)))
    if (!EmptyString(target_p->away))
      sendto_one(client_p, ":%s AWAY :%s", target_p->name,
                 target_p->away);

}

/*
 * show_capabilities - show current server capabilities
 *
 * inputs       - pointer to a struct Client
 * output       - pointer to static string
 * side effects - build up string representing capabilities of server listed
 */
const char *
show_capabilities(struct Client *target_p)
{
  static char msgbuf[IRCD_BUFSIZE];
  char *t = msgbuf;
  dlink_node *ptr;

  t += ircsprintf(msgbuf, "TS ");

  DLINK_FOREACH(ptr, cap_list.head)
  {
    const struct Capability *cap = ptr->data;

    if (IsCapable(target_p, cap->cap))
      t += ircsprintf(t, "%s ", cap->name);
  }
#ifdef HAVE_LIBCRYPTO
  if (IsCapable(target_p, CAP_ENC) &&
      target_p->localClient->in_cipher &&
      target_p->localClient->out_cipher)
    t += ircsprintf(t, "ENC:%s ",
                    target_p->localClient->in_cipher->name);
#endif
  *(t - 1) = '\0';

  return(msgbuf);
}

/* make_server()
 *
 * inputs       - pointer to client struct
 * output       - pointer to struct Server
 * side effects - add's an Server information block to a client
 *                if it was not previously allocated.
 */
struct Server *
make_server(struct Client *client_p)
{
  if (client_p->serv == NULL)
    client_p->serv = MyMalloc(sizeof(struct Server));

  return client_p->serv;
}

/* server_estab()
 *
 * inputs       - pointer to a struct Client
 * output       -
 * side effects -
 */
void
server_estab(struct Client *client_p)
{
  struct Client *target_p;
  struct ConfItem *conf;
  struct AccessItem *aconf=NULL;
  char *host;
  const char *inpath;
  static char inpath_ip[HOSTLEN * 2 + USERLEN + 6];
  dlink_node *m;
  dlink_node *ptr;

  assert(client_p != NULL);

  strlcpy(inpath_ip, get_client_name(client_p, SHOW_IP), sizeof(inpath_ip));

  inpath = get_client_name(client_p, MASK_IP); /* "refresh" inpath with host */
  host   = client_p->name;

  if ((conf = find_conf_name(&client_p->localClient->confs, host, SERVER_TYPE))
      == NULL)
  {
    /* This shouldn't happen, better tell the ops... -A1kmm */
    sendto_realops_flags(UMODE_ALL, L_ALL, "Warning: Lost connect{} block "
                         "for server %s(this shouldn't happen)!", host);
    exit_client(client_p, &me, "Lost connect{} block!");
    return;
  }

  MyFree(client_p->localClient->passwd);
  client_p->localClient->passwd = NULL;

  /* Its got identd, since its a server */
  SetGotId(client_p);

  /* If there is something in the serv_list, it might be this
   * connecting server..
   */
  if (!ServerInfo.hub && serv_list.head)   
  {
    if (client_p != serv_list.head->data || serv_list.head->next)
    {
      ++ServerStats.is_ref;
      sendto_one(client_p, "ERROR :I'm a leaf not a hub");
      exit_client(client_p, &me, "I'm a leaf");
      return;
    }
  }

  aconf = (struct AccessItem *)map_to_conf(conf);

  if (IsUnknown(client_p) && !IsConfCryptLink(aconf))
  {
    /* jdc -- 1.  Use EmptyString(), not [0] index reference.
     *        2.  Check aconf->spasswd, not aconf->passwd.
     */
    if (!EmptyString(aconf->spasswd))
    {
      /* only send ts6 format PASS if we have ts6 enabled */
    if (me.id[0] != '\0')		/* Send TS 6 form only if id */
        sendto_one(client_p, "PASS %s TS %d %s",
                   aconf->spasswd, TS_CURRENT, me.id);
      else
        sendto_one(client_p, "PASS %s TS 5",
                   aconf->spasswd);
    }

    /* Pass my info to the new server
     *
     * If this is a HUB, pass on CAP_HUB
     * Pass on ZIP if supported
     * Pass on TB if supported.
     * - Dianora
     */

    send_capabilities(client_p, aconf, (ServerInfo.hub ? CAP_HUB : 0)
      | (IsConfCompressed(aconf) ? CAP_ZIP : 0)
      | (IsConfTopicBurst(aconf) ? CAP_TBURST|CAP_TB : 0), 0);

    /* SERVER is the last command sent before switching to ziplinks.
     * We set TCPNODELAY on the socket to make sure it gets sent out
     * on the wire immediately.  Otherwise, it could be sitting in
     * a kernel buffer when we start sending zipped data, and the
     * parser on the receiving side can't hand both unzipped and zipped
     * data in one packet. --Rodder
     *
     * currently we only need to call send_queued_write,
     * Nagle is already disabled at this point --adx
     */
    sendto_one(client_p, "SERVER %s 1 :%s%s",
               my_name_for_link(conf), 
               ConfigServerHide.hidden ? "(H) " : "",
               (me.info[0]) ? (me.info) : "IRCers United");
    send_queued_write(client_p);
  }

  /* Hand the server off to servlink now */
  if (IsCapable(client_p, CAP_ENC) || IsCapable(client_p, CAP_ZIP))
  {
    if (fork_server(client_p) < 0)
    {
      sendto_realops_flags(UMODE_ALL, L_ADMIN,
                           "Warning: fork failed for server %s -- check servlink_path (%s)",
                           get_client_name(client_p, HIDE_IP), ConfigFileEntry.servlink_path);
      sendto_realops_flags(UMODE_ALL, L_OPER, "Warning: fork failed for server "
                           "%s -- check servlink_path (%s)",
                           get_client_name(client_p, MASK_IP),
                           ConfigFileEntry.servlink_path);
      exit_client(client_p, &me, "fork failed");
      return;
    }

    start_io(client_p);
    SetServlink(client_p);
  }

  /* only send ts6 format SVINFO if we have ts6 enabled */ 
  sendto_one(client_p, "SVINFO %d %d 0 :%lu",
             (me.id[0] ? TS_CURRENT : 5), TS_MIN,
             (unsigned long)CurrentTime);

  /* assumption here is if they passed the correct TS version, they also passed an SID */
  if (IsCapable(client_p, CAP_TS6))
    hash_add_id(client_p);

  /* XXX Does this ever happen? I don't think so -db */
  detach_conf(client_p, OPER_TYPE);

  /* *WARNING*
  **    In the following code in place of plain server's
  **    name we send what is returned by get_client_name
  **    which may add the "sockhost" after the name. It's
  **    *very* *important* that there is a SPACE between
  **    the name and sockhost (if present). The receiving
  **    server will start the information field from this
  **    first blank and thus puts the sockhost into info.
  **    ...a bit tricky, but you have been warned, besides
  **    code is more neat this way...  --msa
  */
  client_p->servptr = &me;

  if (IsClosing(client_p))
    return;

  SetServer(client_p);

  /* Update the capability combination usage counts. -A1kmm */
  set_chcap_usage_counts(client_p);

  /* Some day, all these lists will be consolidated *sigh* */
  dlinkAdd(client_p, &client_p->lnode, &me.serv->server_list);

  m = dlinkFind(&unknown_list, client_p);
  assert(NULL != m);

  dlinkDelete(m, &unknown_list);
  dlinkAdd(client_p, m, &serv_list);

  Count.myserver++;

  dlinkAdd(client_p, make_dlink_node(), &global_serv_list);
  hash_add_client(client_p);

  /* doesnt duplicate client_p->serv if allocated this struct already */
  make_server(client_p);

  /* fixing eob timings.. -gnp */
  client_p->firsttime = CurrentTime;

  /* Show the real host/IP to admins */
  sendto_realops_flags(UMODE_ALL, L_ADMIN,
                       "Link with %s established: (%s) link",
                       inpath_ip,show_capabilities(client_p));
  /* Now show the masked hostname/IP to opers */
  sendto_realops_flags(UMODE_ALL, L_OPER,
                       "Link with %s established: (%s) link",
                       inpath,show_capabilities(client_p));
  ilog(L_NOTICE, "Link with %s established: (%s) link",
       inpath_ip, show_capabilities(client_p));

  client_p->serv->sconf = conf;

  if (HasServlink(client_p))
  {
    /* we won't overflow FD_DESC_SZ here, as it can hold
     * client_p->name + 64
     */
    fd_note(&client_p->localClient->fd, "slink data: %s", client_p->name);
    fd_note(&client_p->localClient->ctrlfd, "slink ctrl: %s", client_p->name);
  }
  else
    fd_note(&client_p->localClient->fd, "Server: %s", client_p->name);

  /* Old sendto_serv_but_one() call removed because we now
  ** need to send different names to different servers
  ** (domain name matching) Send new server to other servers.
  */
  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    if (target_p == client_p)
      continue;

    if ((conf = target_p->serv->sconf) &&
         match(my_name_for_link(conf), client_p->name))
      continue;

    if (IsCapable(target_p, CAP_TS6) && HasID(client_p))
      sendto_one(target_p, ":%s SID %s 2 %s :%s%s",
                 me.id, client_p->name, client_p->id,
                 IsHidden(client_p) ? "(H) " : "",
                 client_p->info);
    else
      sendto_one(target_p,":%s SERVER %s 2 :%s%s", 
                 me.name, client_p->name,
                 IsHidden(client_p) ? "(H) " : "",
                 client_p->info);
  }

  /* Pass on my client information to the new server
  **
  ** First, pass only servers (idea is that if the link gets
  ** cancelled beacause the server was already there,
  ** there are no NICK's to be cancelled...). Of course,
  ** if cancellation occurs, all this info is sent anyway,
  ** and I guess the link dies when a read is attempted...? --msa
  ** 
  ** Note: Link cancellation to occur at this point means
  ** that at least two servers from my fragment are building
  ** up connection this other fragment at the same time, it's
  ** a race condition, not the normal way of operation...
  **
  ** ALSO NOTE: using the get_client_name for server names--
  **    see previous *WARNING*!!! (Also, original inpath
  **    is destroyed...)
  */

  conf = client_p->serv->sconf;

  DLINK_FOREACH_PREV(ptr, global_serv_list.tail)
  {
    target_p = ptr->data;

    /* target_p->from == target_p for target_p == client_p */
    if (target_p->from == client_p)
      continue;

    if (match(my_name_for_link(conf), target_p->name))
      continue;

    if (IsCapable(client_p, CAP_TS6))
    {
      if (HasID(target_p))
        sendto_one(client_p, ":%s SID %s %d %s :%s%s",
                   ID(target_p->servptr), target_p->name, target_p->hopcount+1,
                   target_p->id, IsHidden(target_p) ? "(H) " : "",
                   target_p->info);
      else  /* introducing non-ts6 server */
        sendto_one(client_p, ":%s SERVER %s %d :%s%s",
                   ID(target_p->servptr), target_p->name, target_p->hopcount+1,
                   IsHidden(target_p) ? "(H) " : "", target_p->info);
    }
    else
      sendto_one(client_p, ":%s SERVER %s %d :%s%s", 
                 target_p->servptr->name, target_p->name, target_p->hopcount+1,
                 IsHidden(target_p) ? "(H) " : "", target_p->info);
  }

  server_burst(client_p);
}

static void
start_io(struct Client *server)
{
  struct LocalUser *lserver = server->localClient;
  int alloclen = 1;
  char *buf;
  dlink_node *ptr;
  struct dbuf_block *block;

  /* calculate how many bytes to allocate */
  if (IsCapable(server, CAP_ZIP))
    alloclen += 6;
#ifdef HAVE_LIBCRYPTO
  if (IsCapable(server, CAP_ENC))
    alloclen += 16 + lserver->in_cipher->keylen + lserver->out_cipher->keylen;
#endif
  alloclen += dbuf_length(&lserver->buf_recvq);
  alloclen += dlink_list_length(&lserver->buf_recvq.blocks) * 3;
  alloclen += dbuf_length(&lserver->buf_sendq);
  alloclen += dlink_list_length(&lserver->buf_sendq.blocks) * 3;

  /* initialize servlink control sendq */
  lserver->slinkq = buf = MyMalloc(alloclen);
  lserver->slinkq_ofs = 0;
  lserver->slinkq_len = alloclen;

  if (IsCapable(server, CAP_ZIP))
  {
    /* ziplink */
    *buf++ = SLINKCMD_SET_ZIP_OUT_LEVEL;
    *buf++ = 0; /* |          */
    *buf++ = 1; /* \ len is 1 */
    *buf++ = ConfigFileEntry.compression_level;
    *buf++ = SLINKCMD_START_ZIP_IN;
    *buf++ = SLINKCMD_START_ZIP_OUT;
  }
#ifdef HAVE_LIBCRYPTO
  if (IsCapable(server, CAP_ENC))
  {
    /* Decryption settings */
    *buf++ = SLINKCMD_SET_CRYPT_IN_CIPHER;
    *buf++ = 0; /* /                     (upper 8-bits of len) */
    *buf++ = 1; /* \ cipher id is 1 byte (lower 8-bits of len) */
    *buf++ = lserver->in_cipher->cipherid;
    *buf++ = SLINKCMD_SET_CRYPT_IN_KEY;
    *buf++ = 0; /* keylen < 256 */
    *buf++ = lserver->in_cipher->keylen;
    memcpy(buf, lserver->in_key, lserver->in_cipher->keylen);
    buf += lserver->in_cipher->keylen;
    /* Encryption settings */
    *buf++ = SLINKCMD_SET_CRYPT_OUT_CIPHER;
    *buf++ = 0; /* /                     (upper 8-bits of len) */
    *buf++ = 1; /* \ cipher id is 1 byte (lower 8-bits of len) */
    *buf++ = lserver->out_cipher->cipherid;
    *buf++ = SLINKCMD_SET_CRYPT_OUT_KEY;
    *buf++ = 0; /* keylen < 256 */
    *buf++ = lserver->out_cipher->keylen;
    memcpy(buf, lserver->out_key, lserver->out_cipher->keylen);
    buf += lserver->out_cipher->keylen;
    *buf++ = SLINKCMD_START_CRYPT_IN;
    *buf++ = SLINKCMD_START_CRYPT_OUT;
  }
#endif

  /* pass the whole recvq to servlink */
  DLINK_FOREACH (ptr, lserver->buf_recvq.blocks.head)
  {
    block = ptr->data;
    *buf++ = SLINKCMD_INJECT_RECVQ;
    *buf++ = (block->size >> 8);
    *buf++ = (block->size & 0xff);
    memcpy(buf, &block->data[0], block->size);
    buf += block->size;
  }

  dbuf_clear(&lserver->buf_recvq);

  /* pass the whole sendq to servlink */
  DLINK_FOREACH (ptr, lserver->buf_sendq.blocks.head)
  {
    block = ptr->data;
    *buf++ = SLINKCMD_INJECT_SENDQ;
    *buf++ = (block->size >> 8);
    *buf++ = (block->size & 0xff);
    memcpy(buf, &block->data[0], block->size);
    buf += block->size;
  }

  dbuf_clear(&lserver->buf_sendq);

  /* start io */
  *buf++ = SLINKCMD_INIT;

  /* schedule a write */ 
  send_queued_slink_write(server);
}

/* fork_server()
 *
 * inputs       - struct Client *server
 * output       - success: 0 / failure: -1
 * side effect  - fork, and exec SERVLINK to handle this connection
 */
static int
fork_server(struct Client *server)
{
#ifndef HAVE_SOCKETPAIR
  return -1;
#else
  int i;
  int slink_fds[2][2];
  /* 0? - ctrl  | 1? - data  
   * ?0 - child | ?1 - parent */

  if (socketpair(AF_UNIX, SOCK_STREAM, 0, slink_fds[0]) < 0)
    return -1;
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, slink_fds[1]) < 0)
    goto free_ctrl_fds;

  if ((i = fork()) < 0)
  {
    close(slink_fds[1][0]);  close(slink_fds[1][1]);
    free_ctrl_fds:
    close(slink_fds[0][0]);  close(slink_fds[0][1]);
    return -1;
  }

  if (i == 0)
  {
    char fd_str[3][6];   /* store 3x sizeof("65535") */
    char *kid_argv[7];

#ifdef O_ASYNC
    fcntl(server->localClient->fd.fd, F_SETFL,
          fcntl(server->localClient->fd.fd, F_GETFL, 0) & ~O_ASYNC);
#endif
    close_fds(&server->localClient->fd);
    close(slink_fds[0][1]);
    close(slink_fds[1][1]);

    sprintf(fd_str[0], "%d", slink_fds[0][0]);
    sprintf(fd_str[1], "%d", slink_fds[1][0]);
    sprintf(fd_str[2], "%d", server->localClient->fd.fd);

    kid_argv[0] = "-slink";
    kid_argv[1] = kid_argv[2] = fd_str[0];  /* ctrl */
    kid_argv[3] = kid_argv[4] = fd_str[1];  /* data */
    kid_argv[5] = fd_str[2];    /* network */
    kid_argv[6] = NULL;

    execv(ConfigFileEntry.servlink_path, kid_argv);

    _exit(1);
  }

  /* close the network fd and the child ends of the pipes */
  fd_close(&server->localClient->fd);
  close(slink_fds[0][0]);
  close(slink_fds[1][0]);

  execute_callback(setup_socket_cb, slink_fds[0][1]);
  execute_callback(setup_socket_cb, slink_fds[1][1]);

  fd_open(&server->localClient->ctrlfd, slink_fds[0][1], 1, "slink ctrl");
  fd_open(&server->localClient->fd, slink_fds[1][1], 1, "slink data");

  read_ctrl_packet(&server->localClient->ctrlfd, server);
  read_packet(&server->localClient->fd, server);

  return 0;
#endif
}

/* server_burst()
 *
 * inputs       - struct Client pointer server
 *              -
 * output       - none
 * side effects - send a server burst
 * bugs		- still too long
 */
static void
server_burst(struct Client *client_p)
{
  /* Send it in the shortened format with the TS, if
  ** it's a TS server; walk the list of channels, sending
  ** all the nicks that haven't been sent yet for each
  ** channel, then send the channel itself -- it's less
  ** obvious than sending all nicks first, but on the
  ** receiving side memory will be allocated more nicely
  ** saving a few seconds in the handling of a split
  ** -orabidoo
  */

  burst_all(client_p);

  /* EOB stuff is now in burst_all */
  /* Always send a PING after connect burst is done */
  sendto_one(client_p, "PING :%s", ID_or_name(&me, client_p));
}

/* burst_all()
 *
 * inputs	- pointer to server to send burst to 
 * output	- NONE
 * side effects - complete burst of channels/nicks is sent to client_p
 */
static void
burst_all(struct Client *client_p)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, global_channel_list.head)
  {
    struct Channel *chptr = ptr->data;

    if (dlink_list_length(&chptr->members) != 0)
    {
      burst_members(client_p, chptr);
      send_channel_modes(client_p, chptr);

      if (IsCapable(client_p, CAP_TBURST) ||
          IsCapable(client_p, CAP_TB))
	send_tb(client_p, chptr);
    }
  }

  /* also send out those that are not on any channel
   */
  DLINK_FOREACH(ptr, global_client_list.head)
  {
    struct Client *target_p = ptr->data;

    if (!IsBursted(target_p) && target_p->from != client_p)
      sendnick_TS(client_p, target_p);
    
    ClearBursted(target_p);
  }

  /* We send the time we started the burst, and let the remote host determine an EOB time,
  ** as otherwise we end up sending a EOB of 0   Sending here means it gets sent last -- fl
  */
  /* Its simpler to just send EOB and use the time its been connected.. --fl_ */
  if (IsCapable(client_p, CAP_EOB))
    sendto_one(client_p, ":%s EOB", ID_or_name(&me, client_p));
}

/*
 * send_tb
 *
 * inputs       - pointer to Client
 *              - pointer to channel
 * output       - NONE
 * side effects - Called on a server burst when
 *                server is CAP_TB|CAP_TBURST capable
 */
static void
send_tb(struct Client *client_p, struct Channel *chptr)
{
  /*
   * We may also send an empty topic here, but only if topic_time isn't 0,
   * i.e. if we had a topic that got unset.  This is required for syncing
   * topics properly.
   *
   * Imagine the following scenario: Our downlink introduces a channel
   * to us with a TS that is equal to ours, but the channel topic on
   * their side got unset while the servers were in splitmode, which means
   * their 'topic' is newer.  They simply wanted to unset it, so we have to
   * deal with it in a more sophisticated fashion instead of just resetting
   * it to their old topic they had before.  Read m_tburst.c:ms_tburst
   * for further information   -Michael
   */
  if (chptr->topic_time != 0)
  {
    if (IsCapable(client_p, CAP_TBURST))
      sendto_one(client_p, ":%s TBURST %lu %s %lu %s :%s",
                 me.name, (unsigned long)chptr->channelts, chptr->chname,
                 (unsigned long)chptr->topic_time,
                 chptr->topic_info ? chptr->topic_info : "",
                 chptr->topic ? chptr->topic : "");
    else if (IsCapable(client_p, CAP_TB))
    {
      if (ConfigChannel.burst_topicwho)
      {
        sendto_one(client_p, ":%s TB %s %lu %s :%s",
                   me.name, chptr->chname,
                   (unsigned long)chptr->topic_time,
                   chptr->topic_info, chptr->topic ? chptr->topic : "");
      }
      else
      {
        sendto_one(client_p, ":%s TB %s %lu :%s",
                   me.name, chptr->chname,
                   (unsigned long)chptr->topic_time,
                   chptr->topic ? chptr->topic : "");
      }
    }
  }
}

/* burst_members()
 *
 * inputs	- pointer to server to send members to
 * 		- dlink_list pointer to membership list to send
 * output	- NONE
 * side effects	-
 */
static void
burst_members(struct Client *client_p, struct Channel *chptr)
{
  struct Client *target_p;
  struct Membership *ms;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms       = ptr->data;
    target_p = ms->client_p;

    if (!IsBursted(target_p))
    {
      SetBursted(target_p);

      if (target_p->from != client_p)
        sendnick_TS(client_p, target_p);
    }
  }
}

/* New server connection code
 * Based upon the stuff floating about in s_bsd.c
 *   -- adrian
 */

/* serv_connect() - initiate a server connection
 *
 * inputs	- pointer to conf 
 *		- pointer to client doing the connect
 * output	-
 * side effects	-
 *
 * This code initiates a connection to a server. It first checks to make
 * sure the given server exists. If this is the case, it creates a socket,
 * creates a client, saves the socket information in the client, and
 * initiates a connection to the server through comm_connect_tcp(). The
 * completion of this goes through serv_completed_connection().
 *
 * We return 1 if the connection is attempted, since we don't know whether
 * it suceeded or not, and 0 if it fails in here somewhere.
 */
int
serv_connect(struct AccessItem *aconf, struct Client *by)
{
  struct ConfItem *conf;
  struct Client *client_p;
  char buf[HOSTIPLEN];

  /* conversion structs */
  struct sockaddr_in *v4;
  /* Make sure aconf is useful */
  assert(aconf != NULL);

  if(aconf == NULL)
    return (0);

  /* XXX should be passing struct ConfItem in the first place */
  conf = unmap_conf_item(aconf);

  /* log */
  irc_getnameinfo((struct sockaddr*)&aconf->ipnum, aconf->ipnum.ss_len,
		  buf, HOSTIPLEN, NULL, 0, NI_NUMERICHOST);
  ilog(L_NOTICE, "Connect to %s[%s] @%s", aconf->user, aconf->host,
       buf);

  /* Still processing a DNS lookup? -> exit */
  if (aconf->dns_pending)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Error connecting to %s: DNS lookup for connect{} in progress.",
                         conf->name);
    return (0);
  }

  if (aconf->dns_failed)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Error connecting to %s: DNS lookup for connect{} failed.",
                         conf->name);
    return (0);
  }

  /* Make sure this server isn't already connected
   * Note: aconf should ALWAYS be a valid C: line
   */
  if ((client_p = find_server(conf->name)) != NULL)
  { 
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
		         "Server %s already present from %s",
		         conf->name, get_client_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_ALL, L_OPER,
		         "Server %s already present from %s",
		         conf->name, get_client_name(client_p, MASK_IP));
    if (by && IsClient(by) && !MyClient(by))
      sendto_one(by, ":%s NOTICE %s :Server %s already present from %s",
	         me.name, by->name, conf->name,
	         get_client_name(client_p, MASK_IP));
    return (0);
  }
    
  /* Create a local client */
  client_p = make_client(NULL);

  /* Copy in the server, hostname, fd */
  strlcpy(client_p->name, conf->name, sizeof(client_p->name));
  strlcpy(client_p->host, aconf->host, sizeof(client_p->host));

  /* We already converted the ip once, so lets use it - stu */
  strlcpy(client_p->sockhost, buf, HOSTIPLEN);

  /* create a socket for the server connection */ 
  if (comm_open(&client_p->localClient->fd, aconf->ipnum.ss.ss_family,
                SOCK_STREAM, 0, NULL) < 0)
  {
    /* Eek, failure to create the socket */
    report_error(L_ALL,
		 "opening stream socket to %s: %s", conf->name, errno);
    SetDead(client_p);
    exit_client(client_p, &me, "Connection failed");
    return (0);
  }

  /* servernames are always guaranteed under HOSTLEN chars */
  fd_note(&client_p->localClient->fd, "Server: %s", conf->name);

  /* Attach config entries to client here rather than in
   * serv_connect_callback(). This to avoid null pointer references.
   */
  if (!attach_connect_block(client_p, conf->name, aconf->host))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
		         "Host %s is not enabled for connecting:no C/N-line",
			 conf->name);
    if (by && IsClient(by) && !MyClient(by))  
      sendto_one(by, ":%s NOTICE %s :Connect to host %s failed.",
	         me.name, by->name, client_p->name);
    SetDead(client_p);
    exit_client(client_p, client_p, "Connection failed");
    return (0);
  }

  /* at this point we have a connection in progress and C/N lines
   * attached to the client, the socket info should be saved in the
   * client and it should either be resolved or have a valid address.
   *
   * The socket has been connected or connect is in progress.
   */
  make_server(client_p);

  if (by && IsClient(by))
    strlcpy(client_p->serv->by, by->name, sizeof(client_p->serv->by));
  else
    strlcpy(client_p->serv->by, "AutoConn.", sizeof(client_p->serv->by));

  SetConnecting(client_p);
  dlinkAdd(client_p, &client_p->node, &global_client_list);
  /* from def_fam */
  client_p->localClient->aftype = aconf->aftype;

  /* Now, initiate the connection */
  /* XXX assume that a non 0 type means a specific bind address 
   * for this connect.
   */
  switch (aconf->aftype)
  {
    case AF_INET:
      v4 = (struct sockaddr_in*)&aconf->my_ipnum;
      if (v4->sin_addr.s_addr != 0)
      {
        struct irc_ssaddr ipn;
        memset(&ipn, 0, sizeof(struct irc_ssaddr));
        ipn.ss.ss_family = AF_INET;
        ipn.ss_port = 0;
        memcpy(&ipn, &aconf->my_ipnum, sizeof(struct irc_ssaddr));
	comm_connect_tcp(&client_p->localClient->fd, aconf->host, aconf->port,
			 (struct sockaddr *)&ipn, ipn.ss_len, 
			 serv_connect_callback, client_p, aconf->aftype,
			 CONNECTTIMEOUT);
      }
      else if (ServerInfo.specific_ipv4_vhost)
      {
        struct irc_ssaddr ipn;
        memset(&ipn, 0, sizeof(struct irc_ssaddr));
        ipn.ss.ss_family = AF_INET;
        ipn.ss_port = 0;
        memcpy(&ipn, &ServerInfo.ip, sizeof(struct irc_ssaddr));
        comm_connect_tcp(&client_p->localClient->fd, aconf->host, aconf->port,
                         (struct sockaddr *)&ipn, ipn.ss_len,
                         serv_connect_callback, client_p, aconf->aftype,
			 CONNECTTIMEOUT);
      }
      else
        comm_connect_tcp(&client_p->localClient->fd, aconf->host, aconf->port, 
                         NULL, 0, serv_connect_callback, client_p, aconf->aftype, 
                         CONNECTTIMEOUT);
      break;
#ifdef IPV6
    case AF_INET6:
      {
	struct irc_ssaddr ipn;
	struct sockaddr_in6 *v6;
	struct sockaddr_in6 *v6conf;

	memset(&ipn, 0, sizeof(struct irc_ssaddr));
	v6conf = (struct sockaddr_in6 *)&aconf->my_ipnum;
	v6 = (struct sockaddr_in6 *)&ipn;

	if (memcmp(&v6conf->sin6_addr, &v6->sin6_addr,
		   sizeof(struct in6_addr)) != 0)
	{
	  memcpy(&ipn, &aconf->my_ipnum, sizeof(struct irc_ssaddr));
	  ipn.ss.ss_family = AF_INET6;
	  ipn.ss_port = 0;
	  comm_connect_tcp(&client_p->localClient->fd,
			   aconf->host, aconf->port,
			   (struct sockaddr *)&ipn, ipn.ss_len, 
			   serv_connect_callback, client_p,
			   aconf->aftype, CONNECTTIMEOUT);
	}
	else if (ServerInfo.specific_ipv6_vhost)
        {
	  memcpy(&ipn, &ServerInfo.ip6, sizeof(struct irc_ssaddr));
	  ipn.ss.ss_family = AF_INET6;
	  ipn.ss_port = 0;
	  comm_connect_tcp(&client_p->localClient->fd,
			   aconf->host, aconf->port,
			   (struct sockaddr *)&ipn, ipn.ss_len,
			   serv_connect_callback, client_p,
			   aconf->aftype, CONNECTTIMEOUT);
	}
	else
	  comm_connect_tcp(&client_p->localClient->fd,
			   aconf->host, aconf->port, 
			   NULL, 0, serv_connect_callback, client_p,
			   aconf->aftype, CONNECTTIMEOUT);
      }
#endif
  }
  return (1);
}

/* serv_connect_callback() - complete a server connection.
 * 
 * This routine is called after the server connection attempt has
 * completed. If unsucessful, an error is sent to ops and the client
 * is closed. If sucessful, it goes through the initialisation/check
 * procedures, the capabilities are sent, and the socket is then
 * marked for reading.
 */
static void
serv_connect_callback(fde_t *fd, int status, void *data)
{
  struct Client *client_p = data;
  struct ConfItem *conf=NULL;
  struct AccessItem *aconf=NULL;

  /* First, make sure its a real client! */
  assert(client_p != NULL);
  assert(&client_p->localClient->fd == fd);

  /* Next, for backward purposes, record the ip of the server */
  memcpy(&client_p->localClient->ip, &fd->connect.hostaddr,
         sizeof(struct irc_ssaddr));
  /* Check the status */
  if (status != COMM_OK)
  {
    /* We have an error, so report it and quit
     * Admins get to see any IP, mere opers don't *sigh*
     */
     if (ConfigServerHide.hide_server_ips)
       sendto_realops_flags(UMODE_ALL, L_ADMIN,
                            "Error connecting to %s: %s",
                            client_p->name, comm_errstr(status));
     else
       sendto_realops_flags(UMODE_ALL, L_ADMIN,
	      		    "Error connecting to %s[%s]: %s", client_p->name,
			    client_p->host, comm_errstr(status));

     sendto_realops_flags(UMODE_ALL, L_OPER,
			  "Error connecting to %s: %s",
			  client_p->name, comm_errstr(status));

     /* If a fd goes bad, call dead_link() the socket is no
      * longer valid for reading or writing.
      */
     dead_link_on_write(client_p, 0);
     return;
  }

  /* COMM_OK, so continue the connection procedure */
  /* Get the C/N lines */
  conf = find_conf_name(&client_p->localClient->confs,
			client_p->name, SERVER_TYPE); 
  if (conf == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
	                 "Lost connect{} block for %s", get_client_name(client_p, HIDE_IP));
    sendto_realops_flags(UMODE_ALL, L_OPER,
		         "Lost connect{} block for %s", get_client_name(client_p, MASK_IP));

    exit_client(client_p, &me, "Lost connect{} block");
    return;
  }

  aconf = (struct AccessItem *)map_to_conf(conf);
  /* Next, send the initial handshake */
  SetHandshake(client_p);

#ifdef HAVE_LIBCRYPTO
  /* Handle all CRYPTLINK links in cryptlink_init */
  if (IsConfCryptLink(aconf))
  {
    cryptlink_init(client_p, conf, fd);
    return;
  }
#endif

  /* jdc -- Check and send spasswd, not passwd. */
  if (!EmptyString(aconf->spasswd) && (me.id[0] != '\0'))
      /* Send TS 6 form only if id */
    sendto_one(client_p, "PASS %s TS %d %s",
               aconf->spasswd, TS_CURRENT, me.id);
  else
    sendto_one(client_p, "PASS %s TS 5",
               aconf->spasswd);

  /* Pass my info to the new server
   *
   * If this is a HUB, pass on CAP_HUB
   * Pass on ZIP if supported
   * Pass on TB if supported.
   * - Dianora
   */
  send_capabilities(client_p, aconf, (ServerInfo.hub ? CAP_HUB : 0)
                    | (IsConfCompressed(aconf) ? CAP_ZIP : 0)
                    | (IsConfTopicBurst(aconf) ? CAP_TBURST|CAP_TB : 0), 0);

  sendto_one(client_p, "SERVER %s 1 :%s%s",
             my_name_for_link(conf), 
	     ConfigServerHide.hidden ? "(H) " : "", 
	     me.info);

  /* If we've been marked dead because a send failed, just exit
   * here now and save everyone the trouble of us ever existing.
   */
  if (IsDead(client_p)) 
  {
      sendto_realops_flags(UMODE_ALL, L_ADMIN,
			   "%s[%s] went dead during handshake",
                           client_p->name,
			   client_p->host);
      sendto_realops_flags(UMODE_ALL, L_OPER,
			   "%s went dead during handshake", client_p->name);
      return;
  }

  /* don't move to serv_list yet -- we haven't sent a burst! */
  /* If we get here, we're ok, so lets start reading some data */
  comm_setselect(fd, COMM_SELECT_READ, read_packet, client_p, 0);
}

struct Client *
find_servconn_in_progress(const char *name)
{
  dlink_node *ptr;
  struct Client *cptr;

  DLINK_FOREACH(ptr, unknown_list.head)
  {
    cptr = ptr->data;

    if (cptr && cptr->name[0])
      if (match(cptr->name, name) || match(name, cptr->name))
        return cptr;
  }
  
  return NULL;
}

#ifdef HAVE_LIBCRYPTO
/*
 * sends a CRYPTLINK SERV command.
 */
void
cryptlink_init(struct Client *client_p, struct ConfItem *conf, fde_t *fd)
{
  struct AccessItem *aconf;
  char *encrypted;
  unsigned char *key_to_send;
  char randkey[CIPHERKEYLEN];
  int enc_len;

  /* get key */
  if ((!ServerInfo.rsa_private_key) ||
      (!RSA_check_key(ServerInfo.rsa_private_key)) )
  {
    cryptlink_error(client_p, "SERV", "Invalid RSA private key",
                                      "Invalid RSA private key");
    return;
  }

  aconf = (struct AccessItem *)map_to_conf(conf);

  if (aconf->rsa_public_key == NULL)
  {
    cryptlink_error(client_p, "SERV", "Invalid RSA public key",
                                      "Invalid RSA public key");
    return;
  }

  if (get_randomness((unsigned char *)randkey, CIPHERKEYLEN) != 1)
  {
    cryptlink_error(client_p, "SERV", "Couldn't generate keyphrase",
                                      "Couldn't generate keyphrase");
    return;
  }

  encrypted = MyMalloc(RSA_size(ServerInfo.rsa_private_key));
  enc_len   = RSA_public_encrypt(CIPHERKEYLEN,
                                 (unsigned char *)randkey,
                                 (unsigned char *)encrypted,
                                 aconf->rsa_public_key,
                                 RSA_PKCS1_PADDING);

  memcpy(client_p->localClient->in_key, randkey, CIPHERKEYLEN);

  if (enc_len <= 0)
  {
    report_crypto_errors();
    MyFree(encrypted);
    cryptlink_error(client_p, "SERV", "Couldn't encrypt data",
                                      "Couldn't encrypt data");
    return;
  }

  if (!(base64_block(&key_to_send, encrypted, enc_len)))
  {
    MyFree(encrypted);
    cryptlink_error(client_p, "SERV", "Couldn't base64 encode key",
                                      "Couldn't base64 encode key");
    return;
  }

  send_capabilities(client_p, aconf, (ServerInfo.hub ? CAP_HUB : 0)
                    | (IsConfCompressed(aconf) ? CAP_ZIP : 0)
                    | (IsConfTopicBurst(aconf) ? CAP_TBURST|CAP_TB : 0), CAP_ENC_MASK);

  if (me.id[0])
    sendto_one(client_p, "PASS . TS %d %s", TS_CURRENT, me.id);

  sendto_one(client_p, "CRYPTLINK SERV %s %s :%s%s",
             my_name_for_link(conf), key_to_send,
             ConfigServerHide.hidden ? "(H) " : "", me.info);

  SetHandshake(client_p);
  SetWaitAuth(client_p);

  MyFree(encrypted);
  MyFree(key_to_send);

  if (IsDead(client_p))
    cryptlink_error(client_p, "SERV", "Went dead during handshake",
                                      "Went dead during handshake");
  else if (fd != NULL)
    /* If we get here, we're ok, so lets start reading some data */
    comm_setselect(fd, COMM_SELECT_READ, read_packet, client_p, 0);
}

void
cryptlink_error(struct Client *client_p, const char *type,
                const char *reason, const char *client_reason)
{
  sendto_realops_flags(UMODE_ALL, L_ADMIN, "%s: CRYPTLINK %s error - %s",
                       get_client_name(client_p, SHOW_IP), type, reason);
  sendto_realops_flags(UMODE_ALL, L_OPER,  "%s: CRYPTLINK %s error - %s",
                       get_client_name(client_p, MASK_IP), type, reason);
  ilog(L_ERROR, "%s: CRYPTLINK %s error - %s",
       get_client_name(client_p, SHOW_IP), type, reason);

  /* If client_reason isn't NULL, then exit the client with the message
   * defined in the call.
   */
  if ((client_reason != NULL) && (!IsDead(client_p)))
    exit_client(client_p, &me, client_reason);
}

static char base64_chars[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

static char base64_values[] =
{
/* 00-15   */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 16-31   */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 32-47   */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
/* 48-63   */ 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1,  0, -1, -1,
/* 64-79   */ -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
/* 80-95   */ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
/* 96-111  */ -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
/* 112-127 */ 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
/* 128-143 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 144-159 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 160-175 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 186-191 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 192-207 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 208-223 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 224-239 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 240-255 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

/*
 * base64_block will allocate and return a new block of memory
 * using MyMalloc().  It should be freed after use.
 */
int
base64_block(unsigned char **output, char *data, int len)
{
  unsigned char *out;
  unsigned char *in = (unsigned char*)data;
  unsigned long int q_in;
  int i;
  int count = 0;

  out = MyMalloc(((((len + 2) - ((len + 2) % 3)) / 3) * 4) + 1);

  /* process 24 bits at a time */
  for( i = 0; i < len; i += 3)
  {
    q_in = 0;

    if ( i + 2 < len )
    {
      q_in  = (in[i+2] & 0xc0) << 2;
      q_in |=  in[i+2];
    }

    if ( i + 1 < len )
    {
      q_in |= (in[i+1] & 0x0f) << 10;
      q_in |= (in[i+1] & 0xf0) << 12;
    }

    q_in |= (in[i]   & 0x03) << 20;
    q_in |=  in[i]           << 22;

    q_in &= 0x3f3f3f3f;

    out[count++] = base64_chars[((q_in >> 24)       )];
    out[count++] = base64_chars[((q_in >> 16) & 0xff)];
    out[count++] = base64_chars[((q_in >>  8) & 0xff)];
    out[count++] = base64_chars[((q_in      ) & 0xff)];
  }
  if ( (i - len) > 0 )
  {
    out[count-1] = '=';
    if ( (i - len) > 1 )
      out[count-2] = '=';
  }

  out[count] = '\0';
  *output = out;
  return (count);
}

/*
 * unbase64_block will allocate and return a new block of memory
 * using MyMalloc().  It should be freed after use.
 */
int
unbase64_block(unsigned char **output, char *data, int len)
{
  unsigned char *out;
  unsigned char *in = (unsigned char*)data;
  unsigned long int q_in;
  int i;
  int count = 0;

  if ((len % 4) != 0)
    return (0);

  out = MyMalloc(((len / 4) * 3) + 1);

  /* process 32 bits at a time */
  for( i = 0; (i + 3) < len; i+=4)
  {
    /* compress input (chars a, b, c and d) as follows:
     * (after converting ascii -> base64 value)
     *
     * |00000000aaaaaabbbbbbccccccdddddd|
     * |  765432  107654  321076  543210|
     */

    q_in = 0;

    if (base64_values[in[i+3]] > -1)
      q_in |= base64_values[in[i+3]]      ;
    if (base64_values[in[i+2]] > -1)
      q_in |= base64_values[in[i+2]] <<  6;
    if (base64_values[in[i+1]] > -1)
      q_in |= base64_values[in[i+1]] << 12;
    if (base64_values[in[i  ]] > -1)
      q_in |= base64_values[in[i  ]] << 18;

    out[count++] = (q_in >> 16) & 0xff;
    out[count++] = (q_in >>  8) & 0xff;
    out[count++] = (q_in      ) & 0xff;
  }

  if (in[i-1] == '=') count--;
  if (in[i-2] == '=') count--;

  out[count] = '\0';
  *output = out;
  return (count);
}

#endif /* HAVE_LIBCRYPTO */


/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_cryptlink.c: Used to negotiate an encrypted link.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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

/*
 * CRYPTLINK protocol.
 *
 * Please see doc/cryptlink.txt for a description of this protocol.
 *
 */

#include "stdinc.h"
#ifdef HAVE_LIBCRYPTO

#include "list.h"
#include "handlers.h"
#include "client.h"      /* client struct */
#include "ircd.h"        /* me */
#include "modules.h"
#include "numeric.h"     /* ERR_xxx */
#include "send.h"        /* sendto_one */
#include <openssl/rsa.h> /* rsa.h is implicit when building this */
#include "rsa.h"
#include "msg.h"
#include "parse.h"
#include "irc_string.h"  /* strncpy_irc */
#include "memory.h"
#include "common.h"      /* TRUE bleah */
#include "event.h"
#include "hash.h"        /* add_to_client_hash_table */
#include "s_conf.h"      /* struct AccessItem */
#include "s_log.h"       /* log level defines */
#include "s_serv.h"      /* server_estab, check_server, my_name_for_link */
#include "motd.h"

static char *parse_cryptserv_args(struct Client *client_p,
                                  char *parv[], int parc, char *info,
                                  char *key);

static void mr_cryptlink(struct Client *, struct Client *, int, char **);
static void cryptlink_serv(struct Client *, struct Client *, int, char **);
static void cryptlink_auth(struct Client *, struct Client *, int, char **);

struct Message cryptlink_msgtab = {
  "CRYPTLINK", 0, 0, 4, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {mr_cryptlink, m_ignore, rfc1459_command_send_error, m_ignore, m_ignore, m_ignore}
};

struct CryptLinkStruct
{
  const char *cmd;   /* CRYPTLINK <command> to match */
  void (*handler)(); /* Function to call             */
};

static struct CryptLinkStruct cryptlink_cmd_table[] =
{
  /* command	function	*/
  { "AUTH",	cryptlink_auth,	},
  { "SERV",	cryptlink_serv,	},
  /* End of table */
  { NULL,	NULL,	}
};

void 
_modinit(void)
{
  mod_add_cmd(&cryptlink_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&cryptlink_msgtab);
}

const char *_version = "$Revision$";

/* mr_cryptlink - CRYPTLINK message handler
 *      parv[0] == CRYPTLINK
 *      parv[1] = command (SERV, AUTH)
 *      parv[2] = Parameters specific to each command (parv[1]):
 *                   SERV - parc must be >= 5
 *                          parv[0] == CRYPTLINK
 *                          parv[1] == SERV
 *                          parv[2] == server name
 *                          parv[3] == keyphrase
 *                          parv[4] == :server info (M-line)
 *                   AUTH - parc must be >= 4
 *                          parv[0] == CRYPTLINK
 *                          parv[1] == AUTH
 *                          parv[2] == cipher (eg. BF/168)
 *                          parv[3] == keyphrase
 */
static void
mr_cryptlink(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  int i;

  for (i = 0; cryptlink_cmd_table[i].handler; i++)
  {
    /* Traverse through the command table */
    if (!irccmp(cryptlink_cmd_table[i].cmd, parv[1]))
    {
      /*
       * Match found.  Time to execute the function
       */
      cryptlink_cmd_table[i].handler(client_p, source_p, parc, parv);
    }
  }
}

/*
 * cryptlink_auth - CRYPTLINK AUTH message handler
 *        parv[1] = secret key
 */
static void
cryptlink_auth(struct Client *client_p, struct Client *source_p,
               int parc, char *parv[])
{
  struct EncCapability *ecap;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  int   enc_len;
  int   len;
  unsigned char *enc;
  unsigned char *key;

  if (parc < 4)
  {
    cryptlink_error(client_p, "AUTH", "Invalid params",
                    "CRYPTLINK AUTH - Invalid params");
    return;
  }

  if (!IsWaitAuth(client_p))
    return;

  for (ecap = CipherTable; ecap->name; ecap++)
  {
    if ((!irccmp(ecap->name, parv[2])) &&
        (IsCapableEnc(client_p, ecap->cap)))
    {
      client_p->localClient->in_cipher = ecap;
      break;
    }
  }

  if (client_p->localClient->in_cipher == NULL)
  {
    cryptlink_error(client_p, "AUTH", "Invalid cipher", "Invalid cipher");
    return;
  }

  if (!(enc_len = unbase64_block(&enc, parv[3], strlen(parv[3]))))
  {
    cryptlink_error(client_p, "AUTH",
                    "Could not base64 decode response",
                    "Malformed CRYPTLINK AUTH reply");
    return;
  }

  if (verify_private_key() == -1)
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
      "verify_private_key() returned -1.  Check log for information.");
  }

  key = MyMalloc(RSA_size(ServerInfo.rsa_private_key));
  len = RSA_private_decrypt(enc_len, (unsigned char *)enc,(unsigned char *)key,
                            ServerInfo.rsa_private_key,
                            RSA_PKCS1_PADDING);

  if (len < client_p->localClient->in_cipher->keylen)
  {
    report_crypto_errors();
    if (len < 0)
    {
      cryptlink_error(client_p, "AUTH",
                      "Decryption failed",
                      "Malformed CRYPTLINK AUTH reply");
    }
    else
    {
      cryptlink_error(client_p, "AUTH",
                      "Not enough random data sent",
                      "Malformed CRYPTLINK AUTH reply");
    }
    MyFree(enc);
    MyFree(key);
    return;
  }

  if (memcmp(key, client_p->localClient->in_key,
             client_p->localClient->in_cipher->keylen) != 0)
  {
    cryptlink_error(client_p, "AUTH",
                    "Unauthorized server connection attempt",
                    "Malformed CRYPTLINK AUTH reply");
    return;
  }

  conf = find_conf_name(&client_p->localClient->confs,
                         client_p->name, SERVER_TYPE);

  if (conf == NULL)
  {
    cryptlink_error(client_p, "AUTH",
                    "Lost C-line for server",
                    "Lost C-line");
    return;
  }

  aconf = (struct AccessItem *)map_to_conf(conf);

  if (!(client_p->localClient->out_cipher ||
      (client_p->localClient->out_cipher = check_cipher(client_p, aconf))))
  {
    cryptlink_error(client_p, "AUTH",
                    "Couldn't find compatible cipher",
                    "Couldn't find compatible cipher");
    return;
  }

  /* set hopcount */
  client_p->hopcount = 1;

  SetCryptIn(client_p);
  ClearWaitAuth(client_p);
  server_estab(client_p);
}

/*
 * cryptlink_serv - CRYPTLINK SERV message handler
 *        parv[0] == CRYPTLINK
 *        parv[1] == SERV
 *        parv[2] == server name
 *        parv[3] == keyphrase
 *        parv[4] == :server info (M-line)
 */
static void
cryptlink_serv(struct Client *client_p, struct Client *source_p,
               int parc, char *parv[])
{
  char info[REALLEN + 1];
  char *name;
  struct Client *target_p;
  char *key = client_p->localClient->out_key;
  unsigned char *b64_key;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  char *encrypted;
  const char *p;
  int enc_len;

  /*
  if (client_p->name[0] != 0)
  return;
  */

  if ((parc < 5) || (*parv[4] == '\0'))
  {
    cryptlink_error(client_p, "SERV", "Invalid params",
                    "CRYPTLINK SERV - Invalid params");
    return;
  }

  if ((name = parse_cryptserv_args(client_p, parv, parc, info, key)) == NULL)
  {
    cryptlink_error(client_p, "SERV", "Invalid params",
                    "CRYPTLINK SERV - Invalid params");
    return;
  }

  /* CRYPTLINK SERV support => TS support */
  client_p->tsinfo = TS_DOESTS;

  if (!valid_servname(name))
  {
    exit_client(client_p, client_p, "Bogus server name");
    return;
  }

  /* Now we just have to call check_server and everything should be
   * checked for us... -A1kmm. */
  switch (check_server(name, client_p, CHECK_SERVER_CRYPTLINK))
  {
    case -1:
      if (ConfigFileEntry.warn_no_nline)
      {
        cryptlink_error(client_p, "SERV",
          "Unauthorized server connection attempt: No entry for server",
          NULL);
      }
      exit_client(client_p, client_p, "Invalid server name");
      return;
      break;
    case -2:
      cryptlink_error(client_p, "SERV",
        "Unauthorized server connection attempt: CRYPTLINK not "
                                      "enabled on remote server",
        "CRYPTLINK not enabled");
      return;
      break;
    case -3:
      cryptlink_error(client_p, "SERV",
        "Unauthorized server connection attempt: Invalid host",
        "Invalid host");
      return;
      break;
  }

  if ((target_p = find_server(name)))
  {
    /*
     * This link is trying feed me a server that I already have
     * access through another path -- multiple paths not accepted
     * currently, kill this link immediately!!
     *
     * Rather than KILL the link which introduced it, KILL the
     * youngest of the two links. -avalon
     *
     * Definitely don't do that here. This is from an unregistered
     * connect - A1kmm.
     */
    cryptlink_error(client_p, "SERV",
                    "Attempt to re-introduce existing server",
                    "Server Exists");
    return;
  }

  conf = find_conf_name(&client_p->localClient->confs,
			name, SERVER_TYPE);
  if (conf == NULL)
  {
    cryptlink_error(client_p, "AUTH",
                    "Lost C-line for server",
                    "Lost C-line" );
    return;
  }

  /*
   * if we are connecting (Handshake), we already have the name from the
   * connect {} block in client_p->name
   */
  strlcpy(client_p->name, name, sizeof(client_p->name));

  p = info;

  if (!strncmp(info, "(H)", 3))
  {
    SetHidden(client_p);

    if ((p = strchr(info, ' ')) != NULL)
    {
      p++;
      if (*p == '\0')
        p = "(Unknown Location)";
    }
    else
      p = "(Unknown Location)";
  }

  strlcpy(client_p->info, p, sizeof(client_p->info));
  client_p->hopcount = 0;

  aconf = (struct AccessItem *)map_to_conf(conf);

  if (!(client_p->localClient->out_cipher ||
      (client_p->localClient->out_cipher = check_cipher(client_p, aconf))))
  {
    cryptlink_error(client_p, "AUTH",
                    "Couldn't find compatible cipher",
                    "Couldn't find compatible cipher");
    return;
  }

  encrypted = MyMalloc(RSA_size(ServerInfo.rsa_private_key));
  enc_len   = RSA_public_encrypt(client_p->localClient->out_cipher->keylen,
                               (unsigned char *)key,
                               (unsigned char *)encrypted,
                               aconf->rsa_public_key,
                               RSA_PKCS1_PADDING);

  if (enc_len <= 0)
  {
    report_crypto_errors();
    MyFree(encrypted);
    cryptlink_error(client_p, "AUTH",
                    "Couldn't encrypt data",
                    "Couldn't encrypt data");
    return;
  }

  base64_block(&b64_key, encrypted, enc_len);

  MyFree(encrypted);

  if (!IsWaitAuth(client_p))
    cryptlink_init(client_p, conf, NULL);

  sendto_one(client_p, "CRYPTLINK AUTH %s %s",
             client_p->localClient->out_cipher->name,
             b64_key);

  /* needed for old servers that can't shove data back into slink */
  send_queued_write(client_p);

  SetCryptOut(client_p);
  MyFree(b64_key);
}

/* parse_cryptserv_args()
 *
 * inputs	- parv parameters
 *		- parc count
 *		- info string (to be filled in by this routine)
 *		- key (to be filled in by this routine)
 * output	- NULL if invalid params, server name otherwise
 * side effects	- parv[2] is trimmed to HOSTLEN size if needed.
 */
static char *
parse_cryptserv_args(struct Client *client_p, char *parv[],
                     int parc, char *info, char *key)
{
  char *name;
  unsigned char *tmp, *out;
  int len;
  int decoded_len;

  info[0] = '\0';

  name = parv[2];

  /* parv[2] contains encrypted auth data */
  if (!(decoded_len = unbase64_block(&tmp, parv[3],
                                     strlen(parv[3]))))
  {
    cryptlink_error(client_p, "SERV",
                    "Couldn't base64 decode data",
                    NULL);
    return(NULL);
  }

  if (verify_private_key() == -1)
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
      "verify_private_key() returned -1.  Check log for information.");
  }

  if (ServerInfo.rsa_private_key == NULL)
  {
    cryptlink_error(client_p, "SERV", "No local private key found", NULL);
    return(NULL);
  }

  out = MyMalloc(RSA_size(ServerInfo.rsa_private_key));
  len = RSA_private_decrypt(decoded_len, tmp, out,
                            ServerInfo.rsa_private_key,
                            RSA_PKCS1_PADDING);

  MyFree(tmp);

  if (len < CIPHERKEYLEN)
  {
    report_crypto_errors();
    if (len < 0)
    {
      cryptlink_error(client_p, "AUTH", "Decryption failed", NULL);
    }
    else
    {
      cryptlink_error(client_p, "AUTH", "Not enough random data sent", NULL);
    }
    MyFree(out);
    return(NULL);
  }

  memcpy(key, out, CIPHERKEYLEN);
  MyFree(out);

  strlcpy(info, parv[4], REALLEN + 1);

  if (strlen(name) > HOSTLEN)
    name[HOSTLEN] = '\0';

  return(name);
}
#endif

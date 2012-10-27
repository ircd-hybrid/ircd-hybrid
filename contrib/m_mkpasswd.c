/*
 *  m_mkpasswd.c: Encrypts a password online, DES or MD5.
 *
 *  Copyright 2002 W. Campbell and the ircd-hybrid development team
 *  Based on mkpasswd.c, originally by Nelson Minar (minar@reed.edu)
 *
 *  You can use this code in any way as long as these names remain.
 *
 *  $Id$
 */

#include "handlers.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "modules.h"

static void m_mkpasswd(struct Client *, struct Client *, int, char *[]);
static void mo_mkpasswd(struct Client *, struct Client *, int, char *[]);
static char *des(void);
static char *md5(void);

static const char saltChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

struct Message mkpasswd_msgtab = {
  "MKPASSWD", 0, 0, 1, 2, MFLG_SLOW, 0,
  {m_unregistered, m_mkpasswd, m_ignore, m_ignore, mo_mkpasswd, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&mkpasswd_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&mkpasswd_msgtab);
}

const char *_version = "$Revision$";
#endif

static void
m_mkpasswd(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  static time_t last_used = 0;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "MKPASSWD");
    return;
  }

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  if (parv[2] == NULL)
    sendto_one(source_p, ":%s NOTICE %s :DES Encryption for [%s]: %s",
               me.name, source_p->name, parv[1], crypt(parv[1],
               des()));
  else if (!irccmp(parv[2], "DES"))
    sendto_one(source_p, ":%s NOTICE %s :DES Encryption for [%s]: %s",
               me.name, source_p->name, parv[1], crypt(parv[1],
               des()));
  else if (!irccmp(parv[2], "MD5"))
    sendto_one(source_p, ":%s NOTICE %s :MD5 Encryption for [%s]: %s",
               me.name, source_p->name, parv[1], crypt(parv[1],
               md5()));
  else
    sendto_one(source_p, ":%s NOTICE %s :Syntax: MKPASSWD pass [DES|MD5]",
               me.name, source_p->name);
}

/*
** mo_mkpasswd
**      parv[0] = sender prefix
**      parv[1] = parameter
*/
static void
mo_mkpasswd(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "MKPASSWD");
    return;
  }

  if (parv[2] == NULL)
    sendto_one(source_p, ":%s NOTICE %s :DES Encryption for [%s]: %s",
               me.name, source_p->name, parv[1], crypt(parv[1],
               des()));
  else if (!irccmp(parv[2], "DES"))
    sendto_one(source_p, ":%s NOTICE %s :DES Encryption for [%s]: %s",
               me.name, source_p->name, parv[1], crypt(parv[1],
               des()));
  else if (!irccmp(parv[2], "MD5"))
    sendto_one(source_p, ":%s NOTICE %s :MD5 Encryption for [%s]: %s",
               me.name, source_p->name, parv[1], crypt(parv[1],
               md5()));
  else
    sendto_one(source_p, ":%s NOTICE %s :Syntax: MKPASSWD pass [DES|MD5]",
               me.name, source_p->name);
}

static char *
des(void)
{
  static char salt[3];

  salt[0] = saltChars[rand() % 64];
  salt[1] = saltChars[rand() % 64];
  salt[2] = '\0';

  return salt;
}

static char *
md5(void)
{
  static char salt[13];
  int i;

  salt[0] = '$';
  salt[1] = '1';
  salt[2] = '$';

  for (i = 3; i < 11; i++)
    salt[i] = saltChars[rand() % 64];

  salt[11] = '$';
  salt[12] = '\0';

  return salt;
}

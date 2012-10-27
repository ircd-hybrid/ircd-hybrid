/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_spoof.c: Supports dynamic auth{} creation/deletion.
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

/* MODULE CONFIGURATION FOLLOWS -- please read!! */

/*
 * change to #define if you want to propagate received SPOOF/DELSPOOF messages
 * to other servers. This allows you create subnets inside which spoofs are
 * propagated. By manipulating PROPAGATE_SPOOF and RECEIVE_SPOOF, you can
 * prepare boundary hubs of such subnets.
 *
 * I realize a shared{} could be better, but I don't want to touch core code.
 *
 * If you decide to enable this, remember to load m_spoof on all servers
 * I am connected to, or you'll get plenty of "Unknown command" errors...
 */
#undef PROPAGATE_SPOOF

/*
 * this server is allowed to receive spoofs/delspoofs from other servers.
 * Use in conjunction with PROPAGATE_SPOOF (on target servers).
 */
#undef RECEIVE_SPOOF

/* where to put dynamic auth's -- this must be included from ircd.conf!
 * Ideally put .include "spoof.conf" before all other auths.
 * #undef if you want only a propagating hub server, not storing any data */
#define SPOOF_FILE "etc/spoof.conf"

/* disable if you don't want opers notices/logs */
#define LOG_SPOOF


/* END OF MODULE CONFIGURATION */

/* Usage: SPOOF <umask@hmask> <free.form.spoof|-> [flags|- [password]]
 *            -- Appends an auth{} block. Flags consist of characters:
 *            t (no_tilde), i (need_ident), k (kline_exempt),
 *            g (gline_exempt), l (exceed_limit), o (class = "opers"),
 *            f (can_flood), p (need_password), everything other is ignored.
 *        DELSPOOF <umask@hmask>
 *            -- Removes an auth{} block of exact umask@hmask, if found
 *
 * These commands are restricted to admins, so make sure your oper{} block
 * has admin = yes or so.
 */

#if !defined(PROPAGATE_SPOOF) && !defined(SPOOF_FILE)
#error You disabled both SPOOF_FILE and PROPAGATE_SPOOF, what do you expect me to do?
#endif

/* List of ircd includes from ../include/ */
#include "stdinc.h"
#include "list.h"
#include "handlers.h"
#include "client.h"
#include "common.h"     /* FALSE bleah */
#include "hash.h"
#include "hostmask.h"
#include "ircd.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

static void mo_spoof(struct Client *, struct Client *, int, char *[]);
static void mo_delspoof(struct Client *, struct Client *, int, char *[]);

struct Message spoof_msgtab = {
  "SPOOF", 0, 0, 3, 0, MFLG_SLOW, 0,
#ifdef RECEIVE_SPOOF
  {m_unregistered, m_not_oper, mo_spoof, m_ignore, mo_spoof, m_ignore}
#else
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_spoof, m_ignore}
#endif
};

struct Message delspoof_msgtab = {
  "DELSPOOF", 0, 0, 1, 0, MFLG_SLOW, 0,
#ifdef RECEIVE_SPOOF
  {m_unregistered, m_not_oper, mo_delspoof, m_ignore, mo_delspoof, m_ignore}
#else
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_delspoof, m_ignore}
#endif
};

void
_modinit(void)
{
  mod_add_cmd(&spoof_msgtab);
  mod_add_cmd(&delspoof_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&delspoof_msgtab);
  mod_del_cmd(&spoof_msgtab);
}

const char *_version = "$Revision$";

#ifdef SPOOF_FILE
static void
try_flag(FBFILE *f, int *flags, int flag, const char *string)
{
  if ((*flags & flag))
  {
    fbputs(string, f, strlen(string));

    *flags &= ~flag;
    fbputs(*flags ? ", " : ";\n", f, 2);
  }
}
#endif

static void
mo_spoof(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *host, *spoof, *password;
  const char *tmp = NULL;
  const char *user = NULL;
  const char *flags = NULL;
  int i = 0;
#ifdef SPOOF_FILE
  int class_opers;
  FBFILE *f;
  char buffer[1024];
  struct AddressRec *arec;
#endif

  if (MyConnect(source_p) && !IsOperAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "SPOOF");
    return;
  }

  /* check the user@host mask */
  if (strchr(parv[1], '!') != NULL)
  {
    syntax:
    if (MyConnect(source_p))
      sendto_one(source_p, ":%s NOTICE %s :Syntax: SPOOF <umask@hmask> "
                 "<spoof/-> [flags/- [password]]", me.name, source_p->name);
    return;
  }

  (void) collapse(parv[1]);

  for (tmp = parv[1]; *tmp; tmp++)
    if (!IsKWildChar(*tmp))
      if (++i >= ConfigFileEntry.min_nonwildcard)
        break;
  if (i < ConfigFileEntry.min_nonwildcard)
  {
    if (MyConnect(source_p))
      sendto_one(source_p, ":%s NOTICE %s :Not enough non-wildcard characters "
                           "in user@host mask",
                           me.name, source_p->name);
    return;
  }

  host = strchr(parv[1], '@');
  if (host)
  {
    user = parv[1];
    *host = '\0';
    host++;
  }
  else
  {
    user = "*";
    host = parv[1];
  }

  /* check the spoof field */
  spoof = parv[2];
  if (spoof == NULL || !*spoof)
    goto syntax;

  if (spoof[0] != '-' || spoof[1] != '\0')
  {
    for (tmp = spoof; *tmp; tmp++)
      if (!IsHostChar(*tmp)) {
        if (MyConnect(source_p))
          sendto_one(source_p, ":%s NOTICE %s :The spoof [%s] is invalid",
                     me.name, source_p->name, spoof);
        return;
      }
    if (strlen(spoof) >= HOSTLEN) {
      if (MyConnect(source_p))
        sendto_one(source_p, ":%s NOTICE %s :Spoofs must be less than %d.."
                             "ignoring it", me.name, source_p->name, HOSTLEN);
      return;
    }
  }

  flags = (parc > 3) ? parv[3] : "-";
  password = (parc > 4 && parv[4][0]) ? parv[4] : NULL;

#ifdef PROPAGATE_SPOOF
  sendto_server(client_p, NULL, NOCAPS, NOCAPS,
                ":%s SPOOF %s@%s %s %s :%s",
                source_p->name, user, host, spoof, flags, password ? password : "");
#endif

#ifdef SPOOF_FILE
  /* Walk through auth {} items and check if we have another auth block
   * for this hostname */
  for (i = 0; i < ATABLE_SIZE; i++)
    for (arec = atable[i]; arec; arec = arec->next)
      if (arec->type == CONF_CLIENT && !irccmp(arec->aconf->host, host) &&
        !irccmp(arec->aconf->user, user))
      {
        /* auth entry already exists */
        if (MyConnect(source_p))
          sendto_one(source_p,
                     ":%s NOTICE %s :auth for %s@%s already exists, you need "
                     "to use /DELSPOOF first", me.name, source_p->name, user, host);
#ifdef LOG_SPOOF
        sendto_realops_flags(UMODE_ALL, L_ALL,
                             "%s attemped to re-add auth for %s@%s "
                             "[spoof: %s, flags: %s]", source_p->name, user, host,
                             spoof, flags);
#endif
        return;
      }

  /* Add the spoof to the the spoof file */
  if ((f = fbopen(SPOOF_FILE, "a")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Could not open %s file, auth for %s@%s "
                         "[spoof: %s, flags: %s, requested by %s] not added",
                         SPOOF_FILE, user, host, spoof, flags, source_p->name);
    return;
  }

  /* write the auth {} block */
  fbputs("auth {\n", f, 7);
  i = ircsprintf(buffer, "\tuser = \"%s@%s\";\n", user, host);
  fbputs(buffer, f, i);
  if (spoof[0] != '-' || spoof[1] != '\0')
  {
    i = ircsprintf(buffer, "\tspoof = \"%s\";\n", spoof);
    fbputs(buffer, f, i);
  }
  if (password)
  {
    i = ircsprintf(buffer, "\tpassword = \"%s\";\n", password);
    fbputs(buffer, f, i);
  }

  /* process given flags */
  i = class_opers = 0;
  for (tmp = flags; *tmp; ++tmp)
    switch (*tmp)
    {
      case 't': i |= CONF_FLAGS_NO_TILDE;      /* no_tilde = yes; */
                break;
      case 'i': i |= CONF_FLAGS_NEED_IDENTD;   /* need_ident = yes; */
                break;
      case 'k': i |= CONF_FLAGS_EXEMPTKLINE;   /* kline_exempt = yes; */
                break;
      case 'g': i |= CONF_FLAGS_EXEMPTGLINE;   /* gline_exempt = yes; */
                break;
      case 'l': i |= CONF_FLAGS_NOLIMIT;       /* exceed_limit = yes; */
                break;
      case 'o': class_opers = 1;               /* class = "opers"; */
                break;
      case 'f': i |= CONF_FLAGS_CAN_FLOOD;     /* can_flood = yes; */
                break;
      case 'p': i|= CONF_FLAGS_NEED_PASSWORD;  /* need_password = yes; */
    }

  if (i)
  {
    fbputs("\tflags = ", f, 9);
    try_flag(f, &i, CONF_FLAGS_NO_TILDE, "no_tilde");
    try_flag(f, &i, CONF_FLAGS_NEED_IDENTD, "need_ident");
    try_flag(f, &i, CONF_FLAGS_EXEMPTKLINE, "kline_exempt");
    try_flag(f, &i, CONF_FLAGS_EXEMPTGLINE, "gline_exempt");
    try_flag(f, &i, CONF_FLAGS_NOLIMIT, "exceed_limit");
    try_flag(f, &i, CONF_FLAGS_CAN_FLOOD, "can_flood");
    try_flag(f, &i, CONF_FLAGS_NEED_PASSWORD, "need_password");
  }

  if (class_opers)
    fbputs("\tclass = \"opers\";\n", f, 18);
  else
    fbputs("\tclass = \"users\";\n", f, 18);

  fbputs("};\n\n", f, 4);
  fbclose(f);

  rehash(0);
#endif

#ifdef LOG_SPOOF
  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "%s added auth for %s@%s [spoof: %s, flags: %s]",
                       source_p->name, user, host, spoof, flags);
  ilog(L_TRACE, "%s added auth for %s@%s [spoof: %s, flags: %s]",
                source_p->name, user, host, spoof, flags);
#endif
}

/* Now, our job is a bit harder. I will scan through the SPOOF_FILE
 * and read all auths{} (assuming they are written in our line formatting..),
 * then rewrite them skipping the one to delete. --adx */
static void
mo_delspoof(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
#ifdef SPOOF_FILE
  FBFILE *f, *fout;
  int ignore_it = 1, spoof_found = 0;
  char buffer[1024], *tmp;
#endif
  const char *user = NULL;
  char *host = NULL;

  if (MyConnect(source_p) && !IsOperAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS), me.name, parv[0], "DELSPOOF");
    return;
  }

  if (parv[1] == NULL || !*parv[1])
  {
    if (MyConnect(source_p))
      sendto_one(source_p, ":%s NOTICE %s :Syntax: /DELSPOOF <user@host>",
                           me.name, source_p->name);
    return;
  }

  /* check user@host mask */
  (void) collapse(parv[1]);

  host = strchr(parv[1], '@');
  if (host != NULL)
  {
    user = parv[1];
    *host = '\0';
    host++;
  }
  else
  {
    user = "*";
    host = parv[1];
  }

#ifdef PROPAGATE_SPOOF
  sendto_server(client_p, NULL, NOCAPS, NOCAPS,
                ":%s DELSPOOF %s@%s", source_p->name, user, host);
#endif

#ifdef SPOOF_FILE
  if ((f = fbopen(SPOOF_FILE, "r")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Could not open %s file, auth for %s@%s not deleted "
                         "(requested by %s)",
                         SPOOF_FILE, user, host, source_p->name);
    return;
  }

  if ((fout = fbopen(SPOOF_FILE ".new", "w")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Could not create %s.new file, auth for %s@%s not "
                         "deleted (requested by %s)",
                         SPOOF_FILE, user, host, source_p->name);
    return;
  }

  while (fbgets(buffer, 1024, f))
  {
    if (!ircncmp(buffer, "auth {", 6))
    {
      /* don't process it yet.. we have to check whether the user="..."; field
       * matches the user@host mask which is being deleted
       */
      ignore_it = 1;
      continue;
    }

    /* a simple parser substitute... */
    for (tmp = buffer; *tmp == '\t' || *tmp == ' '; tmp++)
      ;
    if (!ircncmp(tmp, "user", 4))
    {
      for (tmp += 4; *tmp == '\t' || *tmp == ' '; tmp++)
        ;
      if (*tmp == '=') {
        for (++tmp; *tmp == '\t' || *tmp == ' '; tmp++)
          ;
        if (*tmp == '\"')
        {
          /* yuppi, we've just reached the user="..."; field */
          int matches;
          char *tmp2 = strchr(++tmp, '\"');

          if (tmp2 != NULL)
            *tmp2 = '\0';
          tmp2 = strchr(tmp, '@');

          /* is it matching our mask? */
          if (tmp2 == NULL)
            matches = !irccmp(user, "*") && !irccmp(host, tmp);
          else
          {
            *tmp2++ = '\0';
            matches = !irccmp(user, tmp) && !irccmp(host, tmp2);
          }

          if (!matches)
          {
            /* no.. so leave it unchanged */
            if (ignore_it)
            {
              ignore_it = 0;
              fbputs("auth {\n", fout, 7);
              /* user="..." should be the first field in the auth {}; block,
               * otherwise we could have problems...
               */
            }

            fbputs("\tuser = \"", fout, 9);
            if (tmp2 == NULL)
              fbputs("*", fout, 1);
            else
              fbputs(tmp, fout, strlen(tmp));
            fbputs("@", fout, 1);
            fbputs(tmp2, fout, strlen(tmp2));
            fbputs("\";\n", fout, 3);
          }
          else
          {
            /* we've got it! - omit and continue working */
            spoof_found = 1;
          }

          continue;
        }
      }
    }

    if (!ignore_it)
      fbputs(buffer, fout, strlen(buffer));
  }

  fbclose(f);
  fbclose(fout);

  if (!spoof_found)
  {
    if (MyConnect(source_p))
      sendto_one(source_p, ":%s NOTICE %s :No auth for %s@%s found",
                 me.name, source_p->name, user, host);
    unlink(SPOOF_FILE ".new");
    return;
  }

  unlink(SPOOF_FILE);
  rename(SPOOF_FILE ".new", SPOOF_FILE);
  rehash(0);
#endif

#ifdef LOG_SPOOF
  sendto_realops_flags(UMODE_ALL, L_ALL, "%s deleted auth for %s@%s",
                       source_p->name, user, host);
#endif
}

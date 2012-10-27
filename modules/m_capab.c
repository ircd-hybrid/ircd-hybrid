/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_capab.c: Negotiates capabilities with a remote server.
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

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "irc_string.h"
#include "s_serv.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

static void mr_capab(struct Client *, struct Client *, int, char **);

struct Message capab_msgtab = {
  "CAPAB", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {mr_capab, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&capab_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&capab_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
 * mr_capab - CAPAB message handler
 *      parv[0] = sender prefix
 *      parv[1] = space-separated list of capabilities
 *
 */
static void
mr_capab(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  int i;
  int cap;
  char *p;
  char *s;
#ifdef HAVE_LIBCRYPTO
  struct EncCapability *ecap;
  unsigned int cipher = 0;
#endif

  /* ummm, this shouldn't happen. Could argue this should be logged etc. */
  if (client_p->localClient == NULL)
    return;

  if (client_p->localClient->caps && !(IsCapable(client_p, CAP_TS6)))
  {
    exit_client(client_p, client_p, "CAPAB received twice");
    return;
  }
  else
    SetCapable(client_p, CAP_CAP);

  for (i = 1; i < parc; i++)
  {
    for (s = strtoken(&p, parv[i], " "); s; s = strtoken(&p, NULL, " "))
    {
#ifdef HAVE_LIBCRYPTO
      if ((strncmp(s, "ENC:", 4) == 0))
      {
        /* Skip the "ENC:" portion */
        s += 4;

        /* Check the remaining portion against the list of ciphers we
         * have available (CipherTable).
         */
        for (ecap = CipherTable; ecap->name; ecap++)
        {
          if ((irccmp(ecap->name, s) == 0) && (ecap->cap & CAP_ENC_MASK))
          {
            cipher = ecap->cap;
            break;
          }
        }
        /* Since the name and capabilities matched, use it. */
        if (cipher != 0)
        {
          SetCapable(client_p, CAP_ENC);
          client_p->localClient->enc_caps |= cipher;
        }
        else
        {
          /* cipher is still zero; we didn't find a matching entry. */
          exit_client(client_p, client_p,
	              "Cipher selected is not available here.");
          return;
        }
      }
      else /* normal capab */
#endif
        if ((cap = find_capability(s)) != 0)
          SetCapable(client_p, cap);
    }
  }
}

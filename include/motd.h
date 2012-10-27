/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  motd.h: A header for the MOTD functions.
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

#ifndef INCLUDED_motd_h
#define INCLUDED_motd_h
#include "ircd_defs.h"   


#define MESSAGELINELEN 256

struct MessageFileLine
{
  struct MessageFileLine *next;
  char line[MESSAGELINELEN + 1];
};

typedef struct MessageFileLine MessageFileLine;

typedef enum {
  USER_MOTD,
  USER_LINKS,
  ISSUPPORT
} MotdType;
  
struct MessageFile
{
  MessageFileLine *contentsOfFile;
  MotdType motdType;
  char fileName[PATH_MAX + 1];
  char lastChangedDate[MAX_DATE_STRING + 1];
};

typedef struct MessageFile MessageFile;

struct Client;

extern void init_message_file(MotdType, const char *, struct MessageFile *);
extern int send_message_file(struct Client *, struct MessageFile *);
extern int read_message_file(MessageFile *);
extern MessageFile *init_MessageLine(void);
extern void addto_MessageLine(MessageFile *, const char *);
extern void destroy_MessageLine(MessageFile *);

#endif /* INCLUDED_motd_h */

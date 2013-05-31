/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  motd.c: Message of the day functions.
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
 *  $Id: motd.c 1834 2013-04-19 19:50:27Z michael $
 */

#include "stdinc.h"
#include "list.h"
#include "message.h"
#include "ircd.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "conf.h"
#include "send.h"
#include "numeric.h"
#include "client.h"
#include "irc_string.h"
#include "memory.h"
#include "s_serv.h"

/*
** init_message_file
**
*/
void
init_message_file(MessageType msgType, const char *fileName, MessageFile *msg)
{
  strlcpy(msg->fileName, fileName, sizeof(msg->fileName));
  msg->msgType = msgType;
  msg->contentsOfFile = NULL;
}

/*
** send_message_file
**
** This function split off so a server notice could be generated on a
** user requested motd, but not on each connecting client.
*/
int
send_message_file(struct Client *source_p, MessageFile *motdToPrint)
{
  MessageFileLine *linePointer;
  MessageType msgType;
  const char *from, *to;

  if (motdToPrint == NULL)
    return(-1);

  msgType = motdToPrint->msgType;

  from = ID_or_name(&me, source_p->from);
  to = ID_or_name(source_p, source_p->from);

  switch (msgType)
  {
    case USER_LINKS:
      if (motdToPrint->contentsOfFile != NULL)
      {
	for (linePointer = motdToPrint->contentsOfFile; linePointer;
	     linePointer = linePointer->next)
	{
	  sendto_one(source_p, ":%s 364 %s %s", /* XXX */
		     from, to, linePointer->line);
	}
      }
      break;

  case ISSUPPORT:
      if (motdToPrint->contentsOfFile != NULL)
      {
	for (linePointer = motdToPrint->contentsOfFile; linePointer;
	     linePointer = linePointer->next)
	{
	  sendto_one(source_p, form_str(RPL_ISUPPORT),
		     me.name, source_p->name, linePointer->line);
	}
      }
    break;

    default:
      break;
  }

  return(0);
}

/*
 * read_message_file() - original From CoMSTuD, added Aug 29, 1996
 *
 * inputs	- pointer to MessageFileptr
 * output	-
 * side effects	-
 */
int
read_message_file(MessageFile *MessageFileptr)
{
  /* used to clear out old MessageFile entries */
  MessageFileLine *mptr = 0;
  MessageFileLine *next_mptr = 0;

  /* used to add new MessageFile entries */
  MessageFileLine *newMessageLine = 0;
  MessageFileLine *currentMessageLine = 0;

  char buffer[MESSAGELINELEN];
  char *p;
  FILE *file;

  for (mptr = MessageFileptr->contentsOfFile; mptr; mptr = next_mptr)
  {
    next_mptr = mptr->next;
    MyFree(mptr);
  }

  MessageFileptr->contentsOfFile = NULL;

  if ((file = fopen(MessageFileptr->fileName, "r")) == NULL)
    return(-1);

  while (fgets(buffer, sizeof(buffer), file))
  {
    if ((p = strchr(buffer, '\n')) != NULL)
      *p = '\0';

    newMessageLine = (MessageFileLine *)MyMalloc(sizeof(MessageFileLine));
    strlcpy(newMessageLine->line, buffer, sizeof(newMessageLine->line));
    newMessageLine->next = NULL;

    if (MessageFileptr->contentsOfFile != NULL)
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
  }

  fclose(file);
  return(0);
}

/*
 * init_MessageLine
 *
 * inputs	- NONE
 * output	- pointer to new MessageFile
 * side effects	- Use this when an internal Message File is wanted
 *		  without reading an actual file. The MessageFile 
 *		  is init'ed, but must have content added to it through
 *		  addto_MessageLine()
 */

MessageFile *
init_MessageLine(void)
{
  MessageFile *mf;
  MessageFileLine *mptr = NULL;

  mf = MyMalloc(sizeof(MessageFile));
  mf->msgType = ISSUPPORT;	/* XXX maybe pass it alone in args? */
  mptr = MyMalloc(sizeof(MessageFileLine));
  mf->contentsOfFile = mptr;
  return(mf);
}

/*
 * addto_MessageLine
 *
 * inputs	- Pointer to existing MessageFile
 *		- New string to add to this MessageFile
 * output	- NONE
 * side effects	- Use this when an internal MessageFile is wanted
 *		  without reading an actual file. Content is added
 *		  to this MessageFile through this function.
 */

void
addto_MessageLine(MessageFile *mf, const char *str)
{
  MessageFileLine *mptr = mf->contentsOfFile;
  MessageFileLine *nmptr = NULL;

  if (mptr == NULL)
  {
    mptr = MyMalloc(sizeof(MessageFileLine));
    strcpy(mptr->line, str);
    mf->contentsOfFile = mptr;
  }
  else
  {
    while (mptr->next != NULL)
      mptr = mptr->next;
    nmptr = MyMalloc(sizeof(MessageFileLine));
    strcpy(nmptr->line, str);
    mptr->next = nmptr;
  }
}

/*
 * destroy_MessageLine(MessageFile *mf)
 *
 * inputs	- pointer to the MessageFile to destroy
 * output	- NONE
 * side effects	- All the MessageLines attached to the given mf
 *		  Are freed then one MessageLine is recreated
 */
void
destroy_MessageLine(MessageFile *mf)
{
  MessageFileLine *mptr = mf->contentsOfFile;
  MessageFileLine *nmptr = NULL;

  if (mptr == NULL)
    return;

  for (mptr = mf->contentsOfFile; mptr != NULL; mptr = nmptr)
  {
    nmptr = mptr->next;
    MyFree(mptr);
  } 
  mf->contentsOfFile = NULL;
}

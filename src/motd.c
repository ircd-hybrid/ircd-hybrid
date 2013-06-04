/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2000 Kevin L. Mitchell <klmitch@mit.edu>
 *  Copyright (C) 2013 by the Hybrid Development Team.
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
 */

/*! \file motd.c
 * \brief Message-of-the-day manipulation implementation.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd.h"
#include "conf.h"
#include "send.h"
#include "s_serv.h"
#include "numeric.h"
#include "client.h"
#include "irc_string.h"
#include "memory.h"
#include "log.h"
#include "motd.h"
#include "hostmask.h"


/** Global list of messages of the day. */
static struct
{
  struct Motd *local;     /**< Local MOTD. */
  struct Motd *remote;    /**< Remote MOTD. */
  dlink_list other;       /**< MOTDs specified in configuration file. */
  dlink_list cachelist;   /**< List of MotdCache entries. */
} MotdList;


/*! \brief Create a struct Motd and initialize it.
 * \param hostmask Hostmask (or connection class name) to filter on.
 * \param path Path to MOTD file.
 */
static struct Motd *
motd_create(const char *hostmask, const char *path)
{
  struct Motd *tmp = MyMalloc(sizeof(struct Motd));

  if (EmptyString(hostmask))
    tmp->type = MOTD_UNIVERSAL;
  else if (class_find(hostmask, 1))
    tmp->type = MOTD_CLASS;
  else
  {
    switch (parse_netmask(hostmask, &tmp->address, &tmp->addrbits))
    {
      case HM_IPV4:
      tmp->type = MOTD_IPMASKV4;
      break;
#ifdef IPV6
    case HM_IPV6:
      tmp->type = MOTD_IPMASKV6;
      break;
#endif
    default: /* HM_HOST */
      tmp->type = MOTD_HOSTMASK;
      break;
    }
  }

  if (hostmask != NULL)
    tmp->hostmask = xstrdup(hostmask);

  tmp->path = xstrdup(path);
  tmp->maxcount = MOTD_MAXLINES;

  return tmp;
}

/*! brief\ This function reads a motd out of a file (if needed) and caches it.
 * If a matching cache entry already exists, reuse it. Otherwise,
 * allocate and populate a new MotdCache for it.
 * \param motd Specification for MOTD file.
 * \return Matching MotdCache entry.
 */
static struct MotdCache *
motd_cache(struct Motd *motd)
{
  FILE *file = NULL;
  struct MotdCache *cache = NULL;
  struct stat sb;
  char line[MOTD_LINESIZE + 2]; /* \r\n */
  char *tmp = line;
  unsigned int i = 0;
  dlink_node *ptr = NULL;

  assert(motd);
  assert(motd->path);

  if (motd->cache)
    return motd->cache;

  /* try to find it in the list of cached files... */
  DLINK_FOREACH(ptr, MotdList.cachelist.head)
  {
    cache = ptr->data;

    if (!strcmp(cache->path, motd->path) && cache->maxcount == motd->maxcount)
    {
      cache->ref++; /* increase reference count... */
      motd->cache = cache; /* remember cache... */
      return motd->cache; /* return it */
    }
  }

  /* need the file's modification time */
  if (stat(motd->path, &sb) == -1)
  {
    ilog(LOG_TYPE_IRCD, "Couldn't stat \"%s\": %s", motd->path,
         strerror(errno));
    return 0;
  }

  /* gotta read in the file, now */
  if ((file = fopen(motd->path, "r")) == NULL)
  {
    ilog(LOG_TYPE_IRCD, "Couldn't open \"%s\": %s", motd->path,
         strerror(errno));
    return 0;
  }

  /* Ok, allocate a structure; we'll realloc later to trim memory */
  cache = MyMalloc(sizeof(struct MotdCache) + (MOTD_LINESIZE * (MOTD_MAXLINES - 1)));
  cache->ref = 1;
  cache->path = xstrdup(motd->path);
  cache->maxcount = motd->maxcount;
  cache->modtime = *localtime((time_t *)&sb.st_mtime); /* store modtime */

  while (cache->count < cache->maxcount && fgets(line, sizeof(line), file))
  {
    /* copy over line, stopping when we overflow or hit line end */
    for (; i < (MOTD_LINESIZE - 1) && *tmp && *tmp != '\r' && *tmp != '\n'; ++tmp, ++i)
      cache->motd[cache->count][i] = *tmp;
    cache->motd[cache->count][i] = '\0';

    cache->count++;
  }

  fclose(file); /* close the file */

  /* trim memory usage a little */
  motd->cache = MyMalloc(sizeof(struct MotdCache) +
                         (MOTD_LINESIZE * (cache->count - 1)));
  memcpy(motd->cache, cache, sizeof(struct MotdCache) +
         (MOTD_LINESIZE * (cache->count - 1)));
  MyFree(cache);

  /* now link it in... */
  dlinkAdd(motd->cache, &motd->cache->node, &MotdList.cachelist);

  return motd->cache;
}

/*! \brief Clear and dereference the Motd::cache element of \a motd.
 * If the MotdCache::ref count goes to zero, free it.
 * \param motd MOTD to uncache.
 */
static void
motd_decache(struct Motd *motd)
{
  struct MotdCache *cache = NULL;

  assert(motd);

  if ((cache = motd->cache) == NULL) /* we can be called for records with no cache */
    return;

  motd->cache = NULL; /* zero the cache */

  if (--cache->ref == 0) /* reduce reference count... */
  {
    dlinkDelete(&cache->node, &MotdList.cachelist);
    MyFree(cache->path); /* free path info... */
    MyFree(cache); /* very simple for a reason... */
  }
}

/*! \brief Deallocate a MOTD structure.
 * If it has cached content, uncache it.
 * \param motd MOTD to destroy.
 */
static void
motd_destroy(struct Motd *motd)
{
  assert(motd);

  if (motd->cache)  /* drop the cache */
    motd_decache(motd);

  dlinkDelete(&motd->node, &MotdList.other);
  MyFree(motd->path);  /* we always must have a path */
  MyFree(motd->hostmask);
  MyFree(motd);
}

/*! \brief Find the first matching MOTD block for a user.
 * If the user is remote, always use remote MOTD.
 * Otherwise, if there is a hostmask- or class-based MOTD that matches
 * the user, use it.
 * Otherwise, use the local MOTD.
 * \param client_p Client to find MOTD for.
 * \return Pointer to first matching MOTD for the client.
 */
static struct Motd *
motd_lookup(struct Client *client_p)
{
  dlink_node *ptr = NULL;
  const struct ClassItem *class = NULL;

  assert(client_p);

  if (!MyClient(client_p)) /* not my user, always return remote motd */
    return MotdList.remote;

  class = get_class_ptr(&client_p->localClient->confs);
  assert(class);

  /* check the motd blocks first */
  DLINK_FOREACH(ptr, MotdList.other.head)
  {
    struct Motd *motd = ptr->data;

    switch (motd->type)
    {
      case MOTD_CLASS:
        if (!match(motd->hostmask, class->name))
          return motd;
        break;
      case MOTD_HOSTMASK:
        if (!match(motd->hostmask, client_p->host))
          return motd;
        break;
      case MOTD_IPMASKV4:
          if (client_p->localClient->aftype == AF_INET)
            if (match_ipv4(&client_p->localClient->ip, &motd->address, motd->addrbits))
              return motd;
        break;
#ifdef IPV6
      case MOTD_IPMASKV6:
          if (client_p->localClient->aftype == AF_INET6)
            if (match_ipv6(&client_p->localClient->ip, &motd->address, motd->addrbits))
              return motd;
        break;
#endif
      default: break;
    }
  }

  return MotdList.local; /* Ok, return the default motd */
}

/*! \brief Send the content of a MotdCache to a user.
 * If \a cache is NULL, simply send ERR_NOMOTD to the client.
 * \param source_p Client to send MOTD to.
 * \param cache MOTD body to send to client.
 */
static void
motd_forward(struct Client *source_p, const struct MotdCache *cache)
{
  unsigned int i = 0;
  const char *from = ID_or_name(&me, source_p->from);
  const char *to = ID_or_name(source_p, source_p->from);

  assert(source_p);

  if (!cache)  /* no motd to send */
  {
    sendto_one(source_p, form_str(ERR_NOMOTD), from, to);
    return;
  }

  /* send the motd */
  sendto_one(source_p, form_str(RPL_MOTDSTART),
             from, to, me.name);

  for (; i < cache->count; ++i)
    sendto_one(source_p, form_str(RPL_MOTD),
               from, to, cache->motd[i]);
  sendto_one(source_p, form_str(RPL_ENDOFMOTD), from, to);
}

/*! \brief Find the MOTD for a client and send it.
 * \param client_p Client being greeted.
 */
void
motd_send(struct Client *client_p)
{
  assert(client_p);

  motd_forward(client_p, motd_cache(motd_lookup(client_p)));
}

/*! \brief Send the signon MOTD to a user.
 * If FEAT_NODEFAULTMOTD is true and a matching MOTD exists for the
 * user, direct the client to type /MOTD to read it.  Otherwise, call
 * motd_forward() for the user.
 * \param source_p Client that has just connected.
 */
void
motd_signon(struct Client *source_p)
{
  const struct MotdCache *cache = motd_cache(motd_lookup(source_p));

  if (!ConfigFileEntry.short_motd || !cache)
    motd_forward(source_p, cache);
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :*** Notice -- motd was last changed at %d/%d/%d %d:%02d",
               me.name, source_p->name, cache->modtime.tm_year + 1900,
               cache->modtime.tm_mon + 1,
               cache->modtime.tm_mday,
               cache->modtime.tm_hour,
               cache->modtime.tm_min);
    sendto_one(source_p,
               ":%s NOTICE %s :*** Notice -- Please read the motd if you haven't "
               "read it", me.name, source_p->name);
    sendto_one(source_p, form_str(RPL_MOTDSTART),
               me.name, source_p->name, me.name);
    sendto_one(source_p, form_str(RPL_MOTD),
               me.name, source_p->name,
               "*** This is the short motd ***");
    sendto_one(source_p, form_str(RPL_ENDOFMOTD),
               me.name, source_p->name);
  }
}

/*! \brief Clear all cached MOTD bodies.
 * The local and remote MOTDs are re-cached immediately.
 */
void
motd_recache(void)
{
  dlink_node *ptr = NULL;

  motd_decache(MotdList.local); /* decache local and remote MOTDs */
  motd_decache(MotdList.remote);

  DLINK_FOREACH(ptr, MotdList.other.head)  /* now all the others */
    motd_decache(ptr->data);

  /* now recache local and remote MOTDs */
  motd_cache(MotdList.local);
  motd_cache(MotdList.remote);
}

/*! \brief Re-cache the local and remote MOTDs.
 * If they already exist, they are deallocated first.
 */
void
motd_init(void)
{
  if (MotdList.local)  /* destroy old local... */
    motd_destroy(MotdList.local);

  MotdList.local = motd_create(0, MPATH);
  motd_cache(MotdList.local);  /* init local and cache it */

  if (MotdList.remote)  /* destroy old remote... */
    motd_destroy(MotdList.remote);

  MotdList.remote = motd_create(0, MPATH);
  motd_cache(MotdList.remote);  /* init remote and cache it */
}

/* \brief Add a new MOTD.
 * \param hostmask Hostmask (or connection class name) to send this to.
 * \param path Pathname of file to send.
 */
void
motd_add(const char *hostmask, const char *path)
{
  struct Motd *motd = motd_create(hostmask, path);  /* create the motd */

  dlinkAdd(motd, &motd->node, &MotdList.other);
}

/*! \brief Clear out all MOTDs.
 * Compared to motd_recache(), this destroys all hostmask- or
 * class-based MOTDs rather than simply uncaching them.
 * Re-cache the local and remote MOTDs.
 */
void
motd_clear(void)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  motd_decache(MotdList.local);  /* decache local and remote MOTDs */
  motd_decache(MotdList.remote);

  DLINK_FOREACH_SAFE(ptr, ptr_next, MotdList.other.head)  /* destroy other MOTDs */
    motd_destroy(ptr->data);

  /* now recache local and remote MOTDs */
  motd_cache(MotdList.local);
  motd_cache(MotdList.remote);
}

/*! \brief Report list of non-default MOTDs.
 * \param source_p Client requesting statistics.
 */
void
motd_report(struct Client *source_p)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, MotdList.other.head)
  {
    const struct Motd *motd = ptr->data;

    sendto_one(source_p, form_str(RPL_STATSTLINE),
               me.name, source_p->name,
               motd->hostmask, motd->path);
  }
}

/*! \brief Report MOTD memory usage to a client.
 * \param source_p Client requesting memory usage.
 */
void
motd_memory_count(struct Client *source_p)
{
  const dlink_node *ptr = NULL;
  unsigned int mt  = 0;  /* motd count */
  unsigned int mtc = 0;  /* motd cache count */
  size_t mtm  = 0;  /* memory consumed by motd */
  size_t mtcm = 0;  /* memory consumed by motd cache */

  if (MotdList.local)
  {
    mt++;
    mtm += sizeof(struct Motd);
    mtm += MotdList.local->path ? (strlen(MotdList.local->path) + 1) : 0;
  }

  if (MotdList.remote)
  {
    mt++;
    mtm += sizeof(struct Motd);
    mtm += MotdList.remote->path ? (strlen(MotdList.remote->path) + 1) : 0;
  }

  DLINK_FOREACH(ptr, MotdList.other.head)
  {
    const struct MotdCache *motd = ptr->data;

    mt++;
    mtm += sizeof(struct Motd);
    mtm += motd->path ? (strlen(motd->path) + 1) : 0;
  }

  DLINK_FOREACH(ptr, MotdList.cachelist.head)
  {
    const struct MotdCache *cache = ptr->data;

    mtc++;
    mtcm += sizeof(struct MotdCache) + (MOTD_LINESIZE * (cache->count - 1));
  }

  sendto_one(source_p, ":%s %d %s z :Motds %u(%u) Cache %u(%u)",
             me.name, RPL_STATSDEBUG, source_p->name,
             mt, mtm, mtc, mtcm);
}

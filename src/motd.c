/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000 Kevin L. Mitchell <klmitch@mit.edu>
 *  Copyright (c) 2013-2024 ircd-hybrid development team
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file motd.c
 * \brief Message-of-the-day manipulation implementation.
 */

#include "stdinc.h"
#include "defaults.h"
#include "list.h"
#include "ircd.h"
#include "conf.h"
#include "send.h"
#include "numeric.h"
#include "client.h"
#include "irc_string.h"
#include "memory.h"
#include "log.h"
#include "motd.h"
#include "address.h"
#include "misc.h"

/** Global list of messages of the day. */
static struct
{
  struct Motd *local;    /**< Local MOTD. */
  struct Motd *remote;   /**< Remote MOTD. */
  list_t other;      /**< MOTDs specified in configuration file. */
  list_t cachelist;  /**< List of MotdCache entries. */
} MotdList;


/*! \brief Create a struct Motd and initialize it.
 * \param mask Hostmask (or connection class name) to filter on.
 * \param path Path to MOTD file.
 */
static struct Motd *
motd_create(const char *mask, const char *path)
{
  struct Motd *motd = io_calloc(sizeof(*motd));

  if (EmptyString(mask))
    motd->type = MOTD_UNIVERSAL;
  else if (class_find(mask, true))
    motd->type = MOTD_CLASS;
  else
  {
    switch (parse_netmask(mask, &motd->address, &motd->addrbits))
    {
      case HM_IPV4:
        motd->type = MOTD_IPMASKV4;
        break;
      case HM_IPV6:
        motd->type = MOTD_IPMASKV6;
        break;
      default:  /* HM_HOST */
        motd->type = MOTD_HOSTMASK;
        break;
    }
  }

  motd->mask = mask ? io_strdup(mask) : NULL;
  motd->path = io_strdup(path);
  motd->maxcount = MOTD_MAXLINES;

  return motd;
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
  if (motd == NULL)
    return NULL;

  if (motd->cache)
    return motd->cache;

  /* Try to find it in the list of cached files */
  list_node_t *node;
  LIST_FOREACH(node, MotdList.cachelist.head)
  {
    struct MotdCache *cache = node->data;

    if (strcmp(cache->path, motd->path) == 0 && cache->maxcount == motd->maxcount)
    {
      cache->ref++;  /* Increase reference count */
      motd->cache = cache;  /* Remember cache */
      return motd->cache;  /* Return it */
    }
  }

  /* Need the file's modification time */
  struct stat sb;
  if (stat(motd->path, &sb))
  {
    log_write(LOG_TYPE_IRCD, "Couldn't stat \"%s\": %s", motd->path, strerror(errno));
    return 0;
  }

  /* Gotta read in the file, now */
  FILE *file = fopen(motd->path, "r");
  if (file == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Couldn't open \"%s\": %s", motd->path, strerror(errno));
    return 0;
  }

  /* Ok, allocate a structure; we'll realloc later to trim memory */
  struct MotdCache *cache = io_calloc(sizeof(*cache) + (MOTD_LINESIZE * MOTD_MAXLINES));
  cache->ref = 1;
  cache->path = io_strdup(motd->path);
  cache->maxcount = motd->maxcount;
  cache->modtime = sb.st_mtime;  /* Store modtime */

  char line[MOTD_LINESIZE + 2];  /* +2 for \r\n */
  while (cache->count < cache->maxcount && fgets(line, sizeof(line), file))
  {
    unsigned int i = 0;
    /* Copy over line, stopping when we overflow or hit line end */
    for (char *tmp = line; i < (MOTD_LINESIZE - 1) && *tmp && *tmp != '\r' && *tmp != '\n'; ++tmp, ++i)
      cache->motd[cache->count][i] = *tmp;

    cache->motd[cache->count][i] = '\0';
    cache->count++;
  }

  fclose(file);  /* Close the file */

  /* Trim memory usage a little */
  motd->cache = io_calloc(sizeof(*motd->cache) + (MOTD_LINESIZE * cache->count));
  memcpy(motd->cache, cache, sizeof(*motd->cache) + (MOTD_LINESIZE * cache->count));
  io_free(cache);

  /* Now link it in */
  list_add(motd->cache, &motd->cache->node, &MotdList.cachelist);

  return motd->cache;
}

/*! \brief Clear and dereference the Motd::cache element of \a motd.
 * If the MotdCache::ref count goes to zero, free it.
 * \param motd MOTD to uncache.
 */
static void
motd_decache(struct Motd *motd)
{
  if (motd == NULL)
    return;

  struct MotdCache *cache = motd->cache;
  if (cache == NULL)  /* We can be called for records with no cache */
    return;

  motd->cache = NULL;  /* Zero the cache */

  if (--cache->ref == 0)  /* Reduce reference count */
  {
    list_remove(&cache->node, &MotdList.cachelist);
    io_free(cache->path);  /* Free path info */
    io_free(cache);  /* Very simple for a reason */
  }
}

/*! \brief Deallocate a MOTD structure.
 * If it has cached content, uncache it.
 * \param motd MOTD to destroy.
 */
static void
motd_destroy(struct Motd *motd)
{
  if (motd == NULL)
    return;

  if (motd->cache)  /* Drop the cache */
    motd_decache(motd);

  io_free(motd->path);  /* We always must have a path */
  io_free(motd->mask);
  io_free(motd);
}

/*! \brief Find the first matching MOTD block for a user.
 * If the user is remote, always use remote MOTD.
 * Otherwise, if there is a hostmask- or class-based MOTD that matches
 * the user, use it.
 * Otherwise, use the local MOTD.
 * \param client Client to find MOTD for.
 * \return Pointer to first matching MOTD for the client.
 */
static struct Motd *
motd_lookup(const struct Client *client)
{
  assert(client);

  if (!MyConnect(client))  /* Not my user, always return remote motd */
    return MotdList.remote;

  /* Check the motd blocks first */
  list_node_t *node;
  LIST_FOREACH(node, MotdList.other.head)
  {
    struct Motd *motd = node->data;

    switch (motd->type)
    {
      case MOTD_CLASS:
      {
        const struct ClassItem *class = class_get_ptr(&client->connection->confs);
        if (match(motd->mask, class->name) == 0)
          return motd;
        break;
      }

      case MOTD_HOSTMASK:
        if (match(motd->mask, client->realhost) == 0 ||
            match(motd->mask, client->sockhost) == 0 || match(motd->mask, client->host) == 0)
          return motd;
        break;
      case MOTD_IPMASKV6:
      case MOTD_IPMASKV4:
        if (address_compare(&client->addr, &motd->address, false, false, motd->addrbits))
          return motd;
        break;
      default: break;
    }
  }

  return MotdList.local;  /* Ok, return the default motd */
}

/*! \brief Send the content of a MotdCache to a user.
 * If \a cache is NULL, simply send ERR_NOMOTD to the client.
 * \param client Client to send MOTD to.
 * \param cache  MOTD body to send to client.
 */
static void
motd_forward(struct Client *client, const struct MotdCache *cache)
{
  if (cache == NULL)  /* No motd to send */
  {
    sendto_one_numeric(client, &me, ERR_NOMOTD);
    return;
  }

  /* Send the motd */
  sendto_one_numeric(client, &me, RPL_MOTDSTART, me.name);

  for (unsigned int i = 0; i < cache->count; ++i)
    sendto_one_numeric(client, &me, RPL_MOTD, cache->motd[i]);

  sendto_one_numeric(client, &me, RPL_ENDOFMOTD);
}

/*! \brief Find the MOTD for a client and send it.
 * \param client Client being greeted.
 */
void
motd_send(struct Client *client)
{
  assert(client);

  motd_forward(client, motd_cache(motd_lookup(client)));
}

/*! \brief Send the signon MOTD to a user.
 * If general::short_motd is true and a matching MOTD exists for the
 * user, direct the client to type /MOTD to read it. Otherwise, call
 * motd_forward() for the user.
 * \param client Client that has just connected.
 */
void
motd_signon(struct Client *client)
{
  const struct MotdCache *cache = motd_cache(motd_lookup(client));

  if (ConfigGeneral.short_motd == 0 || cache == NULL)
    motd_forward(client, cache);
  else
  {
    sendto_one_notice(client, &me, ":*** Notice -- motd was last changed at %s",
                      date_iso8601(cache->modtime));
    sendto_one_notice(client, &me, ":*** Notice -- Please read the motd if you haven't read it");
    sendto_one_numeric(client, &me, RPL_MOTDSTART, me.name);
    sendto_one_numeric(client, &me, RPL_MOTD, "*** This is the short motd ***");
    sendto_one_numeric(client, &me, RPL_ENDOFMOTD);
  }
}

/*! \brief Clear all cached MOTD bodies.
 * The local and remote MOTDs are re-cached immediately.
 */
void
motd_recache(void)
{
  if (MotdList.local)
    motd_decache(MotdList.local);  /* Decache local and remote MOTDs */

  if (MotdList.remote)
    motd_decache(MotdList.remote);

  list_node_t *node;
  LIST_FOREACH(node, MotdList.other.head)  /* Now all the others */
    motd_decache(node->data);

  /* Now recache local and remote MOTDs */
  motd_cache(MotdList.local);
  motd_cache(MotdList.remote);
}

/*! \brief Re-cache the local and remote MOTDs.
 * If they already exist, they are deallocated first.
 */
void
motd_init(void)
{
  if (MotdList.local)  /* Destroy old local MOTD */
  {
    motd_destroy(MotdList.local);
    MotdList.local = NULL;
  }

  if (MotdList.remote)  /* Destroy old remote MOTD */
  {
    motd_destroy(MotdList.remote);
    MotdList.remote = NULL;
  }

  const char *const path = ConfigServerInfo.motd_file;
  if (EmptyString(path))
    return;

  MotdList.local = motd_create(NULL, path);
  motd_cache(MotdList.local);  /* Initialize local MOTD and cache it */

  MotdList.remote = motd_create(NULL, path);
  motd_cache(MotdList.remote);  /* Initialize remote MOTD and cache it */
}

/* \brief Add a new MOTD.
 * \param mask Hostmask (or connection class name) to send this to.
 * \param path Pathname of file to send.
 */
void
motd_add(const char *mask, const char *path)
{
  struct Motd *motd = motd_create(mask, path);  /* Create the motd */

  list_add(motd, &motd->node, &MotdList.other);
}

/*! \brief Clear out all MOTDs.
 * Compared to motd_recache(), this destroys all hostmask- or
 * class-based MOTDs rather than simply uncaching them.
 * Re-cache the local and remote MOTDs.
 */
void
motd_clear(void)
{
  motd_decache(MotdList.local);  /* Decache local and remote MOTDs */
  motd_decache(MotdList.remote);

  while (MotdList.other.head)  /* Destroy other MOTDs */
  {
    struct Motd *motd = MotdList.other.head->data;
    list_remove(&motd->node, &MotdList.other);
    motd_destroy(motd);
  }

  /* Now recache local and remote MOTDs */
  motd_cache(MotdList.local);
  motd_cache(MotdList.remote);
}

/*! \brief Report list of non-default MOTDs.
 * \param client Client requesting statistics.
 */
void
motd_report(struct Client *client, int parc, char *parv[])
{
  list_node_t *node;

  LIST_FOREACH(node, MotdList.other.head)
  {
    const struct Motd *motd = node->data;
    sendto_one_numeric(client, &me, RPL_STATSTLINE, motd->mask, motd->path);
  }
}

/*! \brief Report MOTD memory usage to a client.
 * \param client Client requesting memory usage.
 */
void
motd_memory_count(struct Client *client)
{
  unsigned int mt = 0;  /* Motd count */
  size_t mtm = 0;  /* Memory consumed by motd */

  if (MotdList.local)
  {
    ++mt;
    mtm += sizeof(struct Motd);
    mtm += MotdList.local->path ? strlen(MotdList.local->path) + 1 : 0;
  }

  if (MotdList.remote)
  {
    ++mt;
    mtm += sizeof(struct Motd);
    mtm += MotdList.remote->path ? strlen(MotdList.remote->path) + 1 : 0;
  }

  list_node_t *node;
  LIST_FOREACH(node, MotdList.other.head)
  {
    const struct Motd *motd = node->data;
    ++mt;
    mtm += sizeof(struct Motd);
    mtm += motd->path ? strlen(motd->path) + 1 : 0;
    mtm += motd->mask ? strlen(motd->mask) + 1 : 0;
  }

  unsigned int mtc = 0;  /* Motd cache count */
  size_t mtcm = 0;  /* Memory consumed by motd cache */

  LIST_FOREACH(node, MotdList.cachelist.head)
  {
    const struct MotdCache *cache = node->data;
    ++mtc;
    mtcm += sizeof(struct MotdCache) + (MOTD_LINESIZE * (cache->count - 1));
    mtcm += cache->path ? strlen(cache->path) + 1 : 0;
  }

  sendto_one_numeric(client, &me, RPL_STATSDEBUG | SND_EXPLICIT, "z :Motds %u(%zu) Cache %u(%zu)",
                     mt, mtm, mtc, mtcm);
}

/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (C) 1996-2009 by Andrew Church <achurch@achurch.org>
 *  Copyright (c) 2012-2014 ircd-hybrid development team
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

/*! \file conf_db.c
 * \brief Includes file utilities for database handling
 * \version $Id$
 */


#include "stdinc.h"
#include "conf_db.h"
#include "memory.h"
#include "log.h"
#include "send.h"
#include "irc_string.h"
#include "conf.h"
#include "hostmask.h"
#include "resv.h"


/*! \brief Return the version number on the file.  Return 0 if there is no version
 * number or the number doesn't make sense (i.e. less than 1 or greater
 * than FILE_VERSION).
 *
 * \param f dbFile Struct Member
 * \return int 0 if failure, 1 > is the version number
 */
uint32_t
get_file_version(struct dbFILE *f)
{
  uint32_t version = 0;

  if (read_uint32(&version, f) == -1)
  {
    ilog(LOG_TYPE_IRCD, "Error reading version number on %s: %s",
         f->filename, strerror(errno));
    return 0;
  }

  if (version < 1)
  {
    ilog(LOG_TYPE_IRCD, "Invalid version number (%u) on %s",
         version, f->filename);
    return 0;
  }

  return version;
}

/*! \brief Write the current version number to the file.
 * \param f dbFile Struct Member
 * \param version Database version
 * \return 0 on error, 1 on success.
 */
int
write_file_version(struct dbFILE *f, uint32_t version)
{
  if (write_uint32(version, f) == -1)
  {
    ilog(LOG_TYPE_IRCD, "Error writing version number on %s",
         f->filename);
    return 0;
  }

  return 1;
}

/*! \brief Open the database for reading
 * \param filename File to open as the database
 * \return dbFile struct
 */
static struct dbFILE *
open_db_read(const char *filename)
{
  struct dbFILE *f = MyCalloc(sizeof(*f));
  FILE *fp = NULL;

  strlcpy(f->filename, filename, sizeof(f->filename));

  f->mode = 'r';
  fp = fopen(f->filename, "rb");

  if (!fp)
  {
    int errno_save = errno;

    if (errno != ENOENT)
      ilog(LOG_TYPE_IRCD, "Cannot read database file %s", f->filename);

    MyFree(f);
    errno = errno_save;
    return NULL;
  }

  f->fp = fp;
  return f;
}

/*! \brief Open the database for writting
 * \param filename File to open as the database
 * \param version Database version
 * \return dbFile struct
 */
static struct dbFILE *
open_db_write(const char *filename, uint32_t version)
{
  struct dbFILE *f = MyCalloc(sizeof(*f));
  int fd = 0;

  strlcpy(f->filename, filename, sizeof(f->filename));

  filename = f->filename;
  f->mode = 'w';

  snprintf(f->tempname, sizeof(f->tempname), "%s.new", filename);

  if (f->tempname[0] == '\0' || !strcmp(f->tempname, filename))
  {
    ilog(LOG_TYPE_IRCD, "Opening database file %s for write: Filename too long",
         filename);
    MyFree(f);
    errno = ENAMETOOLONG;
    return NULL;
  }

  remove(f->tempname);

  /* Use open() to avoid people sneaking a new file in under us */
  fd = open(f->tempname, O_WRONLY | O_CREAT | O_EXCL, 0666);
  if (fd >= 0)
    f->fp = fdopen(fd, "wb");

  if (!f->fp || !write_file_version(f, version))
  {
    int errno_save = errno;
    static int walloped = 0;

    if (!walloped++)
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Cannot create temporary database file %s",
                           f->tempname);

    errno = errno_save;
    ilog(LOG_TYPE_IRCD, "Cannot create temporary database file %s",
        f->tempname);

    if (f->fp)
      fclose(f->fp);

    remove(f->tempname);
    MyFree(f);

    errno = errno_save;
    return NULL;
  }

  return f;
}

/*! \brief Open a database file for reading (*mode == 'r') or writing (*mode == 'w').
 * Return the stream pointer, or NULL on error.  When opening for write, the
 * file actually opened is a temporary file, which will be renamed to the
 * original file on close.
 *
 * `version' is only used when opening a file for writing, and indicates the
 * version number to write to the file.
 *
 * \param filename File to open as the database
 * \param mode Mode for writting or reading
 * \param version Database version
 * \return dbFile struct
 */
struct dbFILE *
open_db(const char *filename, const char *mode, uint32_t version)
{
  switch (*mode)
  {
    case 'r':
      return open_db_read(filename);
      break;
    case 'w':
      return open_db_write(filename, version);
      break;
    default:
      errno = EINVAL;
      return NULL;
  }
}

/*! \brief  Restore the database file to its condition before open_db(). This is
 * identical to close_db() for files open for reading; however, for files
 * open for writing, we discard the new temporary file instead of renaming
 * it over the old file.  The value of errno is preserved.
 *
 * \param dbFile struct
 */
void
restore_db(struct dbFILE *f)
{
  int errno_save = errno;

  if (f->fp)
    fclose(f->fp);
  if (f->mode == 'w' && f->tempname[0])
    remove(f->tempname);

  MyFree(f);
  errno = errno_save;
}

/*! \brief Close a database file.  If the file was opened for write, moves the new
 * file over the old one, and logs/wallops an error message if the rename()
 * fails.
 *
 * \param dbFile struct
 * \return -1 on error, 0 on success.
 */
int
close_db(struct dbFILE *f)
{
  int res;

  if (!f->fp)
  {
    errno = EINVAL;
    return -1;
  }

  res = fclose(f->fp);
  f->fp = NULL;

  if (res != 0)
    return -1;

  if (f->mode == 'w' && f->tempname[0] && strcmp(f->tempname, f->filename))
  {
    if (rename(f->tempname, f->filename) < 0)
    {
      int errno_save = errno;

      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE, "Unable to move new "
                           "data to database file %s; new data NOT saved.",
                           f->filename);
      errno = errno_save;
      ilog(LOG_TYPE_IRCD, "Unable to move new data to database file %s; new "
           "data NOT saved.", f->filename);
      remove(f->tempname);
    }
  }

  MyFree(f);
  return 0;
}

/*
 * Read and write 2-, 4- and 8-byte quantities, pointers, and strings.  All
 * multibyte values are stored in big-endian order (most significant byte
 * first).  A pointer is stored as a byte, either 0 if NULL or 1 if not,
 * and read pointers are returned as either (void *)0 or (void *)1.  A
 * string is stored with a 2-byte unsigned length (including the trailing
 * \0) first; a length of 0 indicates that the string pointer is NULL.
 * Written strings are truncated silently at 4294967294 bytes, and are always
 * null-terminated.
 */

/*! \brief Read a unsigned 8bit integer
 *
 * \param ret 8bit integer to read
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
read_uint8(uint8_t*ret, struct dbFILE *f)
{
  int c = fgetc(f->fp);

  if (c == EOF)
    return -1;

  *ret = c;
  return 0;
}

/*! \brief Write a 8bit integer
 *
 * \param val 8bit integer to write
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
write_uint8(uint8_t val, struct dbFILE *f)
{
  if (fputc(val, f->fp) == EOF)
    return -1;

  return 0;
}

/*! \brief Read a unsigned 8bit integer
 *
 * \param ret 16bit integer to read
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
read_uint16(uint16_t *ret, struct dbFILE *f)
{
  int c1 = fgetc(f->fp);
  int c2 = fgetc(f->fp);

  if (c1 == EOF || c2 == EOF)
    return -1;

  *ret = c1 << 8 | c2;
  return 0;
}

/*! \brief Write a unsigned 16bit integer
 *
 * \param val 16bit integer to write
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
write_uint16(uint16_t val, struct dbFILE *f)
{
  if (fputc((val >> 8) & 0xFF, f->fp) == EOF ||
      fputc(val        & 0xFF, f->fp) == EOF)
    return -1;

  return 0;
}

/*! \brief Read a unsigned 32bit integer
 *
 * \param ret unsigned 32bit integer to read
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
read_uint32(uint32_t *ret, struct dbFILE *f)
{
  int c1 = fgetc(f->fp);
  int c2 = fgetc(f->fp);
  int c3 = fgetc(f->fp);
  int c4 = fgetc(f->fp);

  if (c1 == EOF || c2 == EOF || c3 == EOF || c4 == EOF)
    return -1;

  *ret = c1 << 24 | c2 << 16 | c3 << 8 | c4;
  return 0;
}


/*! \brief Write a unsigned 32bit integer
 *
 * \param val unsigned 32bit integer to write
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
write_uint32(uint32_t val, struct dbFILE *f)
{
  if (fputc((val >> 24) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val >> 16) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val >>  8) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val)       & 0xFF, f->fp) == EOF)
    return -1;
  return 0;
}

/*! \brief Read a unsigned 64bit integer
 *
 * \param ret unsigned 64bit integer to read
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
read_uint64(uint64_t *ret, struct dbFILE *f)
{
  int64_t c1 = fgetc(f->fp);
  int64_t c2 = fgetc(f->fp);
  int64_t c3 = fgetc(f->fp);
  int64_t c4 = fgetc(f->fp);
  int64_t c5 = fgetc(f->fp);
  int64_t c6 = fgetc(f->fp);
  int64_t c7 = fgetc(f->fp);
  int64_t c8 = fgetc(f->fp);

  if (c1 == EOF || c2 == EOF || c3 == EOF || c4 == EOF ||
      c5 == EOF || c6 == EOF || c7 == EOF || c8 == EOF)
    return -1;

  *ret = c1 << 56 | c2 << 48 | c3 << 40 | c4 << 32 |
         c5 << 24 | c6 << 16 | c7 <<  8 | c8;
  return 0;
}


/*! \brief Write a unsigned 64bit integer
 *
 * \param val unsigned 64bit integer to write
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
write_uint64(uint64_t val, struct dbFILE *f)
{
  if (fputc((val >> 56) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val >> 48) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val >> 40) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val >> 32) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val >> 24) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val >> 16) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val >>  8) & 0xFF, f->fp) == EOF)
    return -1;
  if (fputc((val)       & 0xFF, f->fp) == EOF)
    return -1;
  return 0;
}

/*! \brief Read Pointer
 *
 * \param ret pointer to read
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
read_ptr(void **ret, struct dbFILE *f)
{
  int c = fgetc(f->fp);

  if (c == EOF)
    return -1;

  *ret = (c ? (void *)1 : (void *)0);
  return 0;
}


/*! \brief Write Pointer
 *
 * \param ptr pointer to write
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
write_ptr(const void *ptr, struct dbFILE *f)
{
  if (fputc(ptr ? 1 : 0, f->fp) == EOF)
    return -1;
  return 0;
}

/*! \brief Read String
 *
 * \param ret string
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
read_string(char **ret, struct dbFILE *f)
{
  char *s = NULL;
  uint32_t len = 0;

  if (read_uint32(&len, f) < 0)
    return -1;

  if (len == 0)
  {
    *ret = NULL;
    return 0;
  }

  s = MyCalloc(len);

  if (len != fread(s, 1, len, f->fp))
  {
    MyFree(s);
    return -1;
  }

  *ret = s;
  return 0;
}

/*! \brief Write String
 *
 * \param s string
 * \param dbFile struct
 * \return -1 on error, 0 otherwise.
 */
int
write_string(const char *s, struct dbFILE *f)
{
  uint32_t len = 0;

  if (!s)
    return write_uint32(0, f);

  len = strlen(s);

  if (len > 4294967294)
    len = 4294967294;
  if (write_uint32(len + 1, f) < 0)
    return -1;
  if (len > 0 && fwrite(s, 1, len, f->fp) != len)
    return -1;
  if (fputc(0, f->fp) == EOF)
    return -1;

  return 0;
}

#define SAFE_READ(x) do {                             \
    if ((x) < 0) {                                    \
        break;                                        \
    }                                                 \
} while (0)

#define SAFE_WRITE(x,db) do {                         \
    if ((x) < 0) {                                    \
        restore_db(f);                                \
        ilog(LOG_TYPE_IRCD, "Write error on %s", db); \
        return;                                       \
    }                                                 \
} while (0)

void
save_kline_database(void)
{
  uint32_t i = 0;
  uint32_t records = 0;
  struct dbFILE *f = NULL;
  dlink_node *ptr = NULL;

  if (!(f = open_db(KPATH, "w", KLINE_DB_VERSION)))
    return;

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type == CONF_KLINE && IsConfDatabase(arec->conf))
        ++records;
    }
  }

  SAFE_WRITE(write_uint32(records, f), KPATH);

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type == CONF_KLINE && IsConfDatabase(arec->conf))
      {
        SAFE_WRITE(write_string(arec->conf->user, f), KPATH);
        SAFE_WRITE(write_string(arec->conf->host, f), KPATH);
        SAFE_WRITE(write_string(arec->conf->reason, f), KPATH);
        SAFE_WRITE(write_uint64(arec->conf->setat, f), KPATH);
        SAFE_WRITE(write_uint64(arec->conf->until, f), KPATH);
      }
    }
  }

  close_db(f);
}

void
load_kline_database(void)
{
  struct dbFILE *f = NULL;
  struct MaskItem *conf = NULL;
  char *field_1 = NULL;
  char *field_2 = NULL;
  char *field_3 = NULL;
  uint32_t i = 0;
  uint32_t records = 0;
  uint64_t field_4 = 0;
  uint64_t field_5 = 0;

  if (!(f = open_db(KPATH, "r", KLINE_DB_VERSION)))
    return;

  if (get_file_version(f) < 1)
  {
    close_db(f);
    return;
  }

  read_uint32(&records, f);

  for (i = 0; i < records; ++i)
  {
    SAFE_READ(read_string(&field_1, f));
    SAFE_READ(read_string(&field_2, f));
    SAFE_READ(read_string(&field_3, f));
    SAFE_READ(read_uint64(&field_4, f));
    SAFE_READ(read_uint64(&field_5, f));

    conf = conf_make(CONF_KLINE);
    conf->user = field_1;
    conf->host = field_2;
    conf->reason = field_3;
    conf->setat = field_4;
    conf->until = field_5;
    SetConfDatabase(conf);

    add_conf_by_address(CONF_KLINE, conf);
  }

  close_db(f);
}

void
save_dline_database(void)
{
  uint32_t i = 0;
  uint32_t records = 0;
  struct dbFILE *f = NULL;
  dlink_node *ptr = NULL;

  if (!(f = open_db(DLPATH, "w", KLINE_DB_VERSION)))
    return;

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type == CONF_DLINE && IsConfDatabase(arec->conf))
        ++records;
    }
  }

  SAFE_WRITE(write_uint32(records, f), DLPATH);

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type == CONF_DLINE && IsConfDatabase(arec->conf))
      {
        SAFE_WRITE(write_string(arec->conf->host, f), DLPATH);
        SAFE_WRITE(write_string(arec->conf->reason, f), DLPATH);
        SAFE_WRITE(write_uint64(arec->conf->setat, f), DLPATH);
        SAFE_WRITE(write_uint64(arec->conf->until, f), DLPATH);
      }
    }
  }

  close_db(f);
}

void
load_dline_database(void)
{
  struct dbFILE *f = NULL;
  struct MaskItem *conf = NULL;
  char *field_1 = NULL;
  char *field_2 = NULL;
  uint32_t i = 0;
  uint32_t records = 0;
  uint64_t field_3 = 0;
  uint64_t field_4 = 0;

  if (!(f = open_db(DLPATH, "r", KLINE_DB_VERSION)))
    return;

  if (get_file_version(f) < 1)
  {
    close_db(f);
    return;
  }

  read_uint32(&records, f);

  for (i = 0; i < records; ++i)
  {
    SAFE_READ(read_string(&field_1, f));
    SAFE_READ(read_string(&field_2, f));
    SAFE_READ(read_uint64(&field_3, f));
    SAFE_READ(read_uint64(&field_4, f));

    conf = conf_make(CONF_DLINE);
    conf->host = field_1;
    conf->reason = field_2;
    conf->setat = field_3;
    conf->until = field_4;
    SetConfDatabase(conf);

    add_conf_by_address(CONF_DLINE, conf);
  }

  close_db(f);
}

void
save_gline_database(void)
{
  uint32_t i = 0;
  uint32_t records = 0;
  struct dbFILE *f = NULL;
  dlink_node *ptr = NULL;

  if (!(f = open_db(GPATH, "w", KLINE_DB_VERSION)))
    return;

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type == CONF_GLINE && IsConfDatabase(arec->conf))
        ++records;
    }
  }

  SAFE_WRITE(write_uint32(records, f), GPATH);

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH(ptr, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (arec->type == CONF_GLINE && IsConfDatabase(arec->conf))
      {
        SAFE_WRITE(write_string(arec->conf->user, f), GPATH);
        SAFE_WRITE(write_string(arec->conf->host, f), GPATH);
        SAFE_WRITE(write_string(arec->conf->reason, f), GPATH);
        SAFE_WRITE(write_uint64(arec->conf->setat, f), GPATH);
        SAFE_WRITE(write_uint64(arec->conf->until, f), GPATH);
      }
    }
  }

  close_db(f);
}

void
load_gline_database(void)
{
  struct dbFILE *f = NULL;
  struct MaskItem *conf = NULL;
  char *field_1 = NULL;
  char *field_2 = NULL;
  char *field_3 = NULL;
  uint32_t i = 0;
  uint32_t records = 0;
  uint64_t field_4 = 0;
  uint64_t field_5 = 0;

  if (!(f = open_db(GPATH, "r", KLINE_DB_VERSION)))
    return;

  if (get_file_version(f) < 1)
  {
    close_db(f);
    return;
  }

  read_uint32(&records, f);

  for (i = 0; i < records; ++i)
  {
    SAFE_READ(read_string(&field_1, f));
    SAFE_READ(read_string(&field_2, f));
    SAFE_READ(read_string(&field_3, f));
    SAFE_READ(read_uint64(&field_4, f));
    SAFE_READ(read_uint64(&field_5, f));

    conf = conf_make(CONF_GLINE);
    conf->user = field_1;
    conf->host = field_2;
    conf->reason = field_3;
    conf->setat = field_4;
    conf->until = field_5;
    SetConfDatabase(conf);

    add_conf_by_address(CONF_GLINE, conf);
  }

  close_db(f);
}

void
save_resv_database(void)
{
  uint32_t records = 0;
  struct dbFILE *f = NULL;
  dlink_node *ptr = NULL;
  struct MaskItem *conf = NULL;

  if (!(f = open_db(RESVPATH, "w", KLINE_DB_VERSION)))
    return;

  DLINK_FOREACH(ptr, cresv_items.head)
  {
    conf = ptr->data;

    if (IsConfDatabase(conf))
      ++records;
  }

  DLINK_FOREACH(ptr, nresv_items.head)
  {
    conf = ptr->data;

    if (IsConfDatabase(conf))
      ++records;
  }

  SAFE_WRITE(write_uint32(records, f), RESVPATH);

  DLINK_FOREACH(ptr, cresv_items.head)
  {
    conf = ptr->data;

    if (!IsConfDatabase(conf))
      continue;

    SAFE_WRITE(write_string(conf->name, f), RESVPATH);
    SAFE_WRITE(write_string(conf->reason, f), RESVPATH);
    SAFE_WRITE(write_uint64(conf->setat, f), RESVPATH);
    SAFE_WRITE(write_uint64(conf->until, f), RESVPATH);
  }

  DLINK_FOREACH(ptr, nresv_items.head)
  {
    conf = ptr->data;

    if (!IsConfDatabase(conf))
      continue;

    SAFE_WRITE(write_string(conf->name, f), RESVPATH);
    SAFE_WRITE(write_string(conf->reason, f), RESVPATH);
    SAFE_WRITE(write_uint64(conf->setat, f), RESVPATH);
    SAFE_WRITE(write_uint64(conf->until, f), RESVPATH);
  }

  close_db(f);
}

void
load_resv_database(void)
{
  uint32_t i = 0;
  uint32_t records = 0;
  uint64_t tmp64_hold = 0, tmp64_setat = 0;
  struct dbFILE *f = NULL;
  char *name = NULL;
  char *reason = NULL;
  struct MaskItem *conf = NULL;

  if (!(f = open_db(RESVPATH, "r", KLINE_DB_VERSION)))
    return;

  if (get_file_version(f) < 1)
  {
    close_db(f);
    return;
  }

  read_uint32(&records, f);

  for (i = 0; i < records; ++i)
  {
    SAFE_READ(read_string(&name, f));
    SAFE_READ(read_string(&reason, f));
    SAFE_READ(read_uint64(&tmp64_setat, f));
    SAFE_READ(read_uint64(&tmp64_hold, f));

    if ((conf = create_resv(name, reason, NULL)) == NULL)
      continue;

    conf->setat = tmp64_setat;
    conf->until = tmp64_hold;
    SetConfDatabase(conf);

    MyFree(name);
    MyFree(reason);
  }

  close_db(f);
}

void
save_xline_database(void)
{
  uint32_t records = 0;
  struct dbFILE *f = NULL;
  dlink_node *ptr = NULL;
  struct MaskItem *conf = NULL;

  if (!(f = open_db(XPATH, "w", KLINE_DB_VERSION)))
    return;

  DLINK_FOREACH(ptr, xconf_items.head)
  {
    conf = ptr->data;

    if (IsConfDatabase(conf))
      ++records;
  }

  SAFE_WRITE(write_uint32(records, f), XPATH);

  DLINK_FOREACH(ptr, xconf_items.head)
  {
    conf = ptr->data;

    if (!IsConfDatabase(conf))
      continue;

    SAFE_WRITE(write_string(conf->name, f), XPATH);
    SAFE_WRITE(write_string(conf->reason, f), XPATH);
    SAFE_WRITE(write_uint64(conf->setat, f), XPATH);
    SAFE_WRITE(write_uint64(conf->until, f), XPATH);
  }

  close_db(f);
}

void
load_xline_database(void)
{
  uint32_t i = 0;
  uint32_t records = 0;
  uint64_t tmp64_hold = 0, tmp64_setat = 0;
  struct dbFILE *f = NULL;
  char *name = NULL;
  char *reason = NULL;
  struct MaskItem *conf = NULL;

  if (!(f = open_db(XPATH, "r", KLINE_DB_VERSION)))
    return;

  if (get_file_version(f) < 1)
  {
    close_db(f);
    return;
  }

  read_uint32(&records, f);

  for (i = 0; i < records; ++i)
  {
    SAFE_READ(read_string(&name, f));
    SAFE_READ(read_string(&reason, f));
    SAFE_READ(read_uint64(&tmp64_setat, f));
    SAFE_READ(read_uint64(&tmp64_hold, f));

    conf = conf_make(CONF_XLINE);

    SetConfDatabase(conf);

    conf->name = name;
    conf->reason = reason;
    conf->setat = tmp64_setat;
    conf->until = tmp64_hold;
  }

  close_db(f);
}

void
save_all_databases(void *unused)
{
  save_kline_database();
  save_dline_database();
  save_gline_database();
  save_xline_database();
  save_resv_database();
}

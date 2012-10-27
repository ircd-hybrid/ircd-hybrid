/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  fileio.c: Provides a file input-output interface to ircd.
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
#include "fileio.h"
#include "irc_string.h"
#include "memory.h"
#include "s_log.h"

/* The following are to get the fd manipulation routines. eww. */
#include "fdlist.h"


/*
 * Wrappers around open() / close() for fileio, since a whole bunch of
 * code that should be using the fbopen() / fbclose() code isn't.
 * Grr. -- adrian
 */
int
file_open(fde_t *F, const char *filename, int mode, int fmode)
{
  int fd;
#ifdef _WIN32
  DWORD dwDesiredAccess = 0;

  switch (mode & ~(O_CREAT | O_TRUNC | O_APPEND))
  {
    case O_RDONLY:
      dwDesiredAccess = GENERIC_READ;
      break;
    case O_WRONLY:
      dwDesiredAccess = GENERIC_WRITE;
      break;
    case O_RDWR:
      dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
  }

  fd = (int) CreateFile(
    filename,
    dwDesiredAccess,
    FILE_SHARE_READ | ((dwDesiredAccess & GENERIC_WRITE) ? 0:FILE_SHARE_WRITE),
    NULL,
    ((mode & O_CREAT) == 0) ? OPEN_EXISTING :
    ((mode & O_TRUNC) ? CREATE_ALWAYS : OPEN_ALWAYS),
    FILE_ATTRIBUTE_NORMAL,
    NULL
  );

  if (fd == (int)INVALID_HANDLE_VALUE)
  {
    errno = GetLastError();
    return -1;
  }

  if ((mode & O_APPEND))
    SetFilePointer((HANDLE)fd, 0, NULL, FILE_END);
#else
  if (number_fd == hard_fdlimit)
  {
    errno = ENFILE;
    return -1;
  }

  if ((fd = open(filename, mode, fmode)) < 0)
    return -1;
#endif

  fd_open(F, fd, 0, filename);
  return 0;
}

void
file_close(fde_t *F)
{
  fd_close(F);
}

FBFILE *
fbopen(const char *filename, const char *mode)
{
  FBFILE *fb = MyMalloc(sizeof(FBFILE));
  int openmode = 0;
  int pmode = 0;

  while (*mode)
    switch (*mode++)
    {
      case 'r':
        openmode = O_RDONLY;
        break;
      case 'w':
        openmode = O_WRONLY | O_CREAT | O_TRUNC;
        pmode = 0644;
        break;
      case 'a':
        openmode = O_WRONLY | O_CREAT | O_APPEND;
        pmode = 0644;
        break;
      case '+':
        openmode &= ~(O_RDONLY | O_WRONLY);
        openmode |= O_RDWR;
    }

  if (file_open(&fb->F, filename, openmode, pmode) < 0)
  {
    MyFree(fb);
    return NULL;
  }

  fb->ptr = fb->endp = fb->buf;
  fb->flags = 0;
  fb->pbptr = NULL;
  return fb;
}

int
fbrewind(FBFILE *fb)
{
  fb->ptr   = fb->endp = fb->buf;
  fb->flags = 0;
  fb->pbptr = NULL;

#ifdef _WIN32
  SetFilePointer((HANDLE)fb->F.fd, 0, NULL, FILE_BEGIN);
#else
  lseek(fb->F.fd, 0, SEEK_SET);
#endif
  return 0;
}

void
fbclose(FBFILE *fb)
{
  if (fb == NULL)
    return;
  file_close(&fb->F);
  MyFree(fb);
}

static int
fbfill(FBFILE *fb)
{
  int n;

  if (fb->flags)
    return -1;

#ifdef _WIN32
  if (!ReadFile((HANDLE)fb->F.fd, fb->buf, BUFSIZ, (LPDWORD)&n, NULL))
    n = -1;
#else
  n = read(fb->F.fd, fb->buf, BUFSIZ);
#endif

  if (n > 0)
  {
    fb->ptr  = fb->buf;
    fb->endp = fb->buf + n;
  }
  else if (n < 0)
    fb->flags |= FB_FAIL;
  else
    fb->flags |= FB_EOF;

  return n;
}

int
fbgetc(FBFILE *fb)
{
  if (fb->pbptr != NULL)
    if ((fb->pbptr == (fb->pbuf + BUFSIZ)) || !*fb->pbptr)
      fb->pbptr = NULL;

  if (fb->ptr < fb->endp || fbfill(fb) > 0)
    return *fb->ptr++;

  return EOF;
}

void
fbungetc(char c, FBFILE *fb)
{
  if (fb->pbptr == NULL)
    fb->pbptr = fb->pbuf + BUFSIZ;

  if (fb->pbptr != fb->pbuf)
    *--fb->pbptr = c;
}

char *
fbgets(char *buf, size_t len, FBFILE *fb)
{
  char *p = buf;
  assert(0 < len);

  if (fb->pbptr != NULL)
  {
    strlcpy(buf, fb->pbptr, len);
    fb->pbptr = NULL;
    return buf;
  }

  if (fb->ptr == fb->endp && fbfill(fb) < 1)
    return NULL;

  --len;

  while (len--)
  {
    *p = *fb->ptr++;

    if ('\n' == *p)
    {
      ++p;
      break;
    }

    /* deal with CR's */
    else if ('\r' == *p)
    {
      if (fb->ptr < fb->endp || fbfill(fb) > 0)
      {
        if ('\n' == *fb->ptr)
          ++fb->ptr;
      }

      *p++ = '\n';
      break;
    }

    ++p;

    if (fb->ptr == fb->endp && fbfill(fb) < 1)
      break;
  }

  *p = '\0';
  return buf;
}

int
fbputs(const char *str, FBFILE *fb, size_t nbytes)
{
  int n = -1;

  if (0 == fb->flags)
  {
    assert(strlen(str) == nbytes);
#ifdef _WIN32
    if (!WriteFile((HANDLE)fb->F.fd, str, nbytes, (LPDWORD)&n, NULL))
      n = -1;
#else
    n = write(fb->F.fd, str, nbytes);
#endif
    if (n == -1)
      fb->flags |= FB_FAIL;
  }

  return n;
}

int
save_spare_fd(const char *spare_purpose)
{
  int spare_fd = open(PATH_DEVNULL, O_RDONLY, 0);

  if (spare_fd < 0)
  {
    ilog(L_NOTICE, "Failed to reserve low fd for %s - open failed", spare_purpose);
    return -1;
  }
  else if (spare_fd > 255)
  {
    ilog(L_NOTICE, "Failed to reserve low fd for %s - too high", spare_purpose);
    close(spare_fd);
    return -1;
  }

  return spare_fd;
}

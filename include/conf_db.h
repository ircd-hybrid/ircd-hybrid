/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 1996-2002 by Andrew Church <achurch@achurch.org>
 *  Copyright (C) 2012 by the Hybrid Development Team.
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

/*! \file conf_db.h
 * \brief Includes file utilities for database handling
 * \version $Id: conf_db.h 1569 2012-10-16 18:46:53Z michael $
 */

#ifndef DATAFILES_H
#define DATAFILES_H

struct dbFILE
{
  int mode;			/**< 'r' for reading, 'w' for writing */
  FILE *fp;			/**< The normal file descriptor */
  FILE *backupfp;		/**< Open file pointer to a backup copy of
				 *    the database file (if non-NULL) */
  char filename[PATH_MAX + 1];	/**< Name of the database file */
  char backupname[PATH_MAX + 1];	/**< Name of the backup file */
};

extern void check_file_version(struct dbFILE *);
extern int get_file_version(struct dbFILE *);
extern int write_file_version(struct dbFILE *, uint32_t);

extern struct dbFILE *open_db(const char *, const char *, const char *, uint32_t);
extern void restore_db(struct dbFILE *);	/* Restore to state before open_db() */
extern void close_db(struct dbFILE *);
extern void backup_databases(void); 

#define read_db(f,buf,len)	(fread((buf),1,(len),(f)->fp))
#define write_db(f,buf,len)	(fwrite((buf),1,(len),(f)->fp))
#define getc_db(f)		(fgetc((f)->fp))

extern int read_uint8(unsigned char *, struct dbFILE *);
extern int write_uint8(unsigned char, struct dbFILE *);
extern int read_uint16(uint16_t *, struct dbFILE *);
extern int write_uint16(uint16_t, struct dbFILE *);
extern int read_uint32(uint32_t *, struct dbFILE *);
extern int write_uint32(uint32_t, struct dbFILE *);
extern int read_uint64(uint64_t *, struct dbFILE *);
extern int write_uint64(uint64_t, struct dbFILE *);
extern int read_ptr(void **, struct dbFILE *);
extern int write_ptr(const void *, struct dbFILE *);
extern int read_string(char **, struct dbFILE *);
extern int write_string(const char *, struct dbFILE *);


#define read_buffer(buf,f)	(read_db((f),(buf),sizeof(buf)) == sizeof(buf))
#define write_buffer(buf,f)	(write_db((f),(buf),sizeof(buf)) == sizeof(buf))
#define read_buflen(buf,len,f)	(read_db((f),(buf),(len)) == (len))
#define write_buflen(buf,len,f)	(write_db((f),(buf),(len)) == (len))
#define read_variable(var,f)	(read_db((f),&(var),sizeof(var)) == sizeof(var))
#define write_variable(var,f)	(write_db((f),&(var),sizeof(var)) == sizeof(var))
#endif

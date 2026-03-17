/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2012-2026 ircd-hybrid development team
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

/*! \file conf_db.h
 * \brief Includes file utilities for database handling
 */

#ifndef INCLUDED_conf_db_h
#define INCLUDED_conf_db_h

extern void load_kline_database(const char *);
extern void save_kline_database(const char *);
extern void load_dline_database(const char *);
extern void save_dline_database(const char *);
extern void load_xline_database(const char *);
extern void save_xline_database(const char *);
extern void load_resv_database(const char *);
extern void save_resv_database(const char *);
extern void save_all_databases(void *);
#endif  /* INCLUDED_conf_db_h */

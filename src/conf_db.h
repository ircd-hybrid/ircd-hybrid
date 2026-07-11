/*
 * SPDX-FileCopyrightText: 2012-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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

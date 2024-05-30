/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

#ifndef INCLUDED_aline_h
#define INCLUDED_aline_h

struct aline_ctx
{
  bool add;
  bool simple_mask;
  char *mask;
  char *user;
  char *host;
  char *reason;
  char *server;
  uintmax_t duration;
};

extern bool aline_valid_mask_simple(const char *);
extern bool aline_valid_mask(int, ...);
extern bool aline_parse(const char *, struct Client *, int, char *[], struct aline_ctx *);
#endif  /* INCLUDED_aline_h */

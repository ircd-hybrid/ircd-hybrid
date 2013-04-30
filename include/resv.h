/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  resv.h: A header for the RESV functions.
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

#ifndef INCLUDED_resv_h
#define INCLUDED_resv_h

extern dlink_list nresv_items;
extern dlink_list resv_channel_list;

extern struct MaskItem *create_resv(const char *, const char *, const dlink_list *);
extern int valid_wild_card_simple(const char *);
extern int resv_find_exempt(const struct Client *, const struct MaskItem *);
extern struct MaskItem *match_find_resv(const char *);
#endif  /* INCLUDED_resv_h */

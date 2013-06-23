/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
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

#include "patchlevel.h"
#include "serno.h"
#include "ircd.h"

const char *ircd_version = PATCHLEVEL;
const char *serno = SERIALNUM;

const char *infotext[] =
{
  "IRC --",
  "Based on the original code written by Jarkko Oikarinen",
  "Copyright 1988, 1989, 1990, 1991 University of Oulu, Computing Center",
  "Copyright (c) 1997-2013 Hybrid Development Team",
  "",
  "This program is free software; you can redistribute it and/or",
  "modify it under the terms of the GNU General Public License as",
  "published by the Free Software Foundation; either version 2, or",
  "(at your option) any later version.",
  "",
  "",
  "The hybrid team is a group of ircd coders who were frustrated",
  "with the instability and all-out dirtiness of the EFnet ircd's",
  "available. hybrid is the name for the collective efforts of a group",
  "of people, all of us.",
  "",
  "Anyone is welcome to contribute to this effort. You are encouraged",
  "to participate in the Hybrid mailing list. To subscribe to the",
  "Hybrid List, use this link:",
  "  https://lists.ircd-hybrid.org/mailman/listinfo/hybrid",
  "",
  "The core team as, of this major release:",
  "",
  "billy-jon, William Bierman III <bill@mu.org>",
  "cryogen, Stuart Walsh <stu@ipng.org.uk>",
  "Dianora, Diane Bruce <db@db.net>",
  "metalrock, Jack Low <jclow@csupomona.edu>",
  "Michael, Michael Wobst <michael@wobst.at>",
  "Rodder, Jon Lusky <lusky@blown.net>",
  "Wohali, Joan Touzet <joant@ieee.org>",
  "",
  "The following people have contributed blood, sweat, and/or code to",
  "recent releases of Hybrid, in nick alphabetical order:",
  "",
  "A1kmm, Andrew Miller <a1kmm@mware.virtualave.net>",
  "adx, Piotr Nizynski <nizynski@sysplex.pl>",
  "AndroSyn, Aaron Sethman <androsyn@ratbox.org>",
  "bane, Dragan Dosen <bane@idolnet.org>",
  "bysin, Ben Kittridge <bkittridge@cfl.rr.com>",
  "cosine, Patrick Alken <wnder@uwns.underworld.net>",
  "David-T, David Taylor <davidt@yadt.co.uk>",
  "Dominic, Dominic Hargreaves <dom@earth.li>",
  "fgeek, Henri Salo <henri@nerv.fi>",
  "fl, Lee Hardy <lee@leeh.co.uk>",
  "Garion, Joost Vunderink <garion@efnet.nl>",
  "Habeeb, David Supuran <habeeb@cfl.rr.com>",
  "Hwy101, W. Campbell <wcampbel@botbay.net>",
  "jmallett, Juli Mallett <jmallett@FreeBSD.org>",
  "joshk, Joshua Kwan <joshk@triplehelix.org>",
  "jv, Jakub Vlasek <jv@pilsedu.cz>",
  "k9, Jeremy Chadwick <ircd@jdc.parodius.com>",
  "kire, Erik Small <smalle@hawaii.edu>",
  "knight, Alan LeVee <alan.levee@prometheus-designs.net>",
  "kre, Dinko Korunic <kreator@fly.srk.fer.hr>",
  "madmax, Paul Lomax <madmax@efnet.org>",
  "nenolod, William Pitcock <nenolod@nenolod.net>",
  "Riedel, Dennis Vink, <riedel@chaotic.nl>",
  "scuzzy, David Todd <scuzzy@aniverse.net>",
  "spookey, David Colburn <spookey@spookey.org>",
  "TimeMr14C, Yusuf Iskenderoglu <uhc0@stud.uni-karlsruhe.de>",
  "toot, Toby Verrall <to7@antipope.fsnet.co.uk>",
  "vx0, Mark Miller <mark@oc768.net>",
  "wiz, Jason Dambrosio <jason@wiz.cx>",
  "Xride, Søren Straarup <xride@x12.dk>",
  "zb^3, Alfred Perlstein <alfred@freebsd.org>",
  "",
  "Others are welcome. Always. And if we left anyone off the above list,",
  "be sure to let us know that too. Many others have contributed to",
  "previous versions of this ircd and its ancestors, too many to list",
  "here.",
  "",
  "Send bug fixes/complaints/rotten tomatoes to bugs@ircd-hybrid.org.",
  "", 0
};

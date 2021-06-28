/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2021 ircd-hybrid development team
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

/*! \file hostmask.h
 * \brief A header for the hostmask code.
 * \version $Id$
 */

#ifndef INCLUDED_hostmask_h
#define INCLUDED_hostmask_h

enum { ATABLE_SIZE = 0x1000 };

enum hostmask_type
{
  HM_HOST,
  HM_IPV4,
  HM_IPV6
};

struct AddressRec
{
  /* masktype: HM_HOST, HM_IPV4, HM_IPV6 -A1kmm */
  enum hostmask_type masktype;
  /* type: CONF_CLIENT, CONF_DLINE, CONF_KLINE etc... -A1kmm */
  enum maskitem_type type;

  union
  {
    struct
    {
      /* Pointer into MaskItem... -A1kmm */
      struct irc_ssaddr addr;
      int bits;
    } ipa;

    /* Pointer into MaskItem... -A1kmm */
    const char *hostname;
  } Mask;

  /* Higher precedences overrule lower ones... */
  unsigned int precedence;

  /* Only checked if !(type & 1)... */
  const char *username;
  struct MaskItem *conf;

  dlink_node node;
};

extern dlink_list atable[ATABLE_SIZE];
extern int parse_netmask(const char *, struct irc_ssaddr *, int *);
extern bool address_compare(const void *, const void *, bool, bool, int);
extern bool match_ipv6(const struct irc_ssaddr *, const struct irc_ssaddr *, int);
extern bool match_ipv4(const struct irc_ssaddr *, const struct irc_ssaddr *, int);

extern struct AddressRec *add_conf_by_address(const unsigned int, struct MaskItem *);
extern void delete_one_address_conf(const char *, struct MaskItem *);
extern void clear_out_address_conf(void);
extern void hostmask_expire_temporary(void);

extern struct MaskItem *find_address_conf(const char *, const char *, const struct irc_ssaddr *, const char *);
extern struct MaskItem *find_dline_conf(const struct irc_ssaddr *);
extern struct MaskItem *find_conf_by_address(const char *, const struct irc_ssaddr *, unsigned int, const char *, const char *, int);
#endif  /* INCLUDED_hostmask_h */

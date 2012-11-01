/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hostmask.c: Code to efficiently find IP & hostmask based configs.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
#include "memory.h"
#include "ircd_defs.h"
#include "list.h"
#include "conf.h"
#include "hostmask.h"
#include "send.h"
#include "irc_string.h"
#include "ircd.h"


#define DigitParse(ch) do { \
                       if (ch >= '0' && ch <= '9') \
                         ch = ch - '0'; \
                       else if (ch >= 'A' && ch <= 'F') \
                         ch = ch - 'A' + 10; \
                       else if (ch >= 'a' && ch <= 'f') \
                         ch = ch - 'a' + 10; \
                       } while (0);

/* The mask parser/type determination code... */

/* int try_parse_v6_netmask(const char *, struct irc_ssaddr *, int *);
 * Input: A possible IPV6 address as a string.
 * Output: An integer describing whether it is an IPV6 or hostmask,
 *         an address(if it is IPV6), a bitlength(if it is IPV6).
 * Side effects: None
 * Comments: Called from parse_netmask
 */
/* Fixed so ::/0 (any IPv6 address) is valid 
   Also a bug in DigitParse above.
   -Gozem 2002-07-19 gozem@linux.nu
*/
#ifdef IPV6
static int
try_parse_v6_netmask(const char *text, struct irc_ssaddr *addr, int *b)
{
  const char *p;
  char c;
  int d[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  int dp = 0;
  int nyble = 4;
  int finsert = -1;
  int bits = 128;
  int deficit = 0;
  short dc[8];
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)addr;

  for (p = text; (c = *p); p++)
    if (IsXDigit(c))
    {
      if (nyble == 0)
        return HM_HOST;
      DigitParse(c);
      d[dp] |= c << (4 * --nyble);
    }
    else if (c == ':')
    {
      if (p > text && *(p - 1) == ':')
      {
        if (finsert >= 0)
          return HM_HOST;
        finsert = dp;
      }
      else
      {
        /* If there were less than 4 hex digits, e.g. :ABC: shift right
         * so we don't interpret it as ABC0 -A1kmm */
        d[dp] = d[dp] >> 4 * nyble;
        nyble = 4;
        if (++dp >= 8)
          return HM_HOST;
      }
    }
    else if (c == '*')
    {
      /* * must be last, and * is ambiguous if there is a ::... -A1kmm */
      if (finsert >= 0 || *(p + 1) || dp == 0 || *(p - 1) != ':')
        return HM_HOST;
      bits = dp * 16;
    }
    else if (c == '/')
    {
      char *after;

      d[dp] = d[dp] >> 4 * nyble;
      dp++;
      bits = strtoul(p + 1, &after, 10);

      if (bits < 0 || *after)
        return HM_HOST;
      if (bits > dp * 4 && !(finsert >= 0 && bits <= 128))
        return HM_HOST;
      break;
    }
    else
      return HM_HOST;

  d[dp] = d[dp] >> 4 * nyble;

  if (c == 0)
    dp++;
  if (finsert < 0 && bits == 0)
    bits = dp * 16;

  /* How many words are missing? -A1kmm */
  deficit = bits / 16 + ((bits % 16) ? 1 : 0) - dp;

  /* Now fill in the gaps(from ::) in the copied table... -A1kmm */
  for (dp = 0, nyble = 0; dp < 8; dp++)
  {
    if (nyble == finsert && deficit)
    {
      dc[dp] = 0;
      deficit--;
    }
    else
      dc[dp] = d[nyble++];
  }

  /* Set unused bits to 0... -A1kmm */
  if (bits < 128 && (bits % 16 != 0))
    dc[bits / 16] &= ~((1 << (15 - bits % 16)) - 1);
  for (dp = bits / 16 + (bits % 16 ? 1 : 0); dp < 8; dp++)
    dc[dp] = 0;

  /* And assign... -A1kmm */
  if (addr)
    for (dp = 0; dp < 8; dp++)
      /* The cast is a kludge to make netbsd work. */
      ((unsigned short *)&v6->sin6_addr)[dp] = htons(dc[dp]);

  if (b != NULL)
    *b = bits;
  return HM_IPV6;
}
#endif

/* int try_parse_v4_netmask(const char *, struct irc_ssaddr *, int *);
 * Input: A possible IPV4 address as a string.
 * Output: An integer describing whether it is an IPV4 or hostmask,
 *         an address(if it is IPV4), a bitlength(if it is IPV4).
 * Side effects: None
 * Comments: Called from parse_netmask
 */
static int
try_parse_v4_netmask(const char *text, struct irc_ssaddr *addr, int *b)
{
  const char *p;
  const char *digits[4];
  unsigned char addb[4];
  int n = 0, bits = 0;
  char c;
  struct sockaddr_in *v4 = (struct sockaddr_in *)addr;

  digits[n++] = text;

  for (p = text; (c = *p); p++)
    if (c >= '0' && c <= '9')   /* empty */
      ;
    else if (c == '.')
    {
      if (n >= 4)
        return HM_HOST;

      digits[n++] = p + 1;
    }
    else if (c == '*')
    {
      if (*(p + 1) || n == 0 || *(p - 1) != '.')
        return HM_HOST;

      bits = (n - 1) * 8;
      break;
    }
    else if (c == '/')
    {
      char *after;
      bits = strtoul(p + 1, &after, 10);

      if (!bits || *after)
        return HM_HOST;
      if (bits > n * 8)
        return HM_HOST;

      break;
    }
    else
      return HM_HOST;

  if (n < 4 && bits == 0)
    bits = n * 8;
  if (bits)
    while (n < 4)
      digits[n++] = "0";

  for (n = 0; n < 4; n++)
    addb[n] = strtoul(digits[n], NULL, 10);

  if (bits == 0)
    bits = 32;

  /* Set unused bits to 0... -A1kmm */
  if (bits < 32 && bits % 8)
    addb[bits / 8] &= ~((1 << (8 - bits % 8)) - 1);
  for (n = bits / 8 + (bits % 8 ? 1 : 0); n < 4; n++)
    addb[n] = 0;
  if (addr)
    v4->sin_addr.s_addr =
      htonl(addb[0] << 24 | addb[1] << 16 | addb[2] << 8 | addb[3]);
  if (b != NULL)
    *b = bits;
  return HM_IPV4;
}

/* int parse_netmask(const char *, struct irc_ssaddr *, int *);
 * Input: A hostmask, or an IPV4/6 address.
 * Output: An integer describing whether it is an IPV4, IPV6 address or a
 *         hostmask, an address(if it is an IP mask),
 *         a bitlength(if it is IP mask).
 * Side effects: None
 */
int
parse_netmask(const char *text, struct irc_ssaddr *addr, int *b)
{
#ifdef IPV6
  if (strchr(text, ':'))
    return try_parse_v6_netmask(text, addr, b);
#endif
  if (strchr(text, '.'))
    return try_parse_v4_netmask(text, addr, b);
  return HM_HOST;
}

/* The address matching stuff... */
/* int match_ipv6(struct irc_ssaddr *, struct irc_ssaddr *, int)
 * Input: An IP address, an IP mask, the number of bits in the mask.
 * Output: if match, -1 else 0
 * Side effects: None
 */
#ifdef IPV6
int
match_ipv6(const struct irc_ssaddr *addr, const struct irc_ssaddr *mask, int bits)
{
  int i, m, n = bits / 8;
  const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)addr;
  const struct sockaddr_in6 *v6mask = (const struct sockaddr_in6 *)mask;

  for (i = 0; i < n; i++)
    if (v6->sin6_addr.s6_addr[i] != v6mask->sin6_addr.s6_addr[i])
      return 0;
  if ((m = bits % 8) == 0)
    return -1;
  if ((v6->sin6_addr.s6_addr[n] & ~((1 << (8 - m)) - 1)) ==
      v6mask->sin6_addr.s6_addr[n])
    return -1;
  return 0;
}
#endif

/* int match_ipv4(struct irc_ssaddr *, struct irc_ssaddr *, int)
 * Input: An IP address, an IP mask, the number of bits in the mask.
 * Output: if match, -1 else 0
 * Side Effects: None
 */
int
match_ipv4(const struct irc_ssaddr *addr, const struct irc_ssaddr *mask, int bits)
{
  const struct sockaddr_in *v4 = (const struct sockaddr_in *)addr;
  const struct sockaddr_in *v4mask = (const struct sockaddr_in *)mask;

  if ((ntohl(v4->sin_addr.s_addr) & ~((1 << (32 - bits)) - 1)) !=
      ntohl(v4mask->sin_addr.s_addr))
    return 0;
  return -1;
}

/*
 * mask_addr
 *
 * inputs       - pointer to the ip to mask
 *              - bitlen
 * output       - NONE
 * side effects -
 */
void
mask_addr(struct irc_ssaddr *ip, int bits)
{
  int mask;
#ifdef IPV6
  struct sockaddr_in6 *v6_base_ip;
  int i, m, n;
#endif
  struct sockaddr_in *v4_base_ip;

#ifdef IPV6
  if (ip->ss.ss_family != AF_INET6)
#endif
  {
    v4_base_ip = (struct sockaddr_in *)ip;

    mask = ~((1 << (32 - bits)) - 1);
    v4_base_ip->sin_addr.s_addr = htonl(ntohl(v4_base_ip->sin_addr.s_addr) & mask);
  }
#ifdef IPV6
  else
  {
    n = bits / 8;
    m = bits % 8;
    v6_base_ip = (struct sockaddr_in6 *)ip;

    mask = ~((1 << (8 - m)) -1 );
    v6_base_ip->sin6_addr.s6_addr[n] = v6_base_ip->sin6_addr.s6_addr[n] & mask;

    for (i = n + 1; i < 16; i++)
      v6_base_ip->sin6_addr.s6_addr[i] = 0;
  }
#endif
}

/* Hashtable stuff...now external as its used in m_stats.c */
dlink_list atable[ATABLE_SIZE];

void
init_host_hash(void)
{
  memset(&atable, 0, sizeof(atable));
}

/* unsigned long hash_ipv4(struct irc_ssaddr*)
 * Input: An IP address.
 * Output: A hash value of the IP address.
 * Side effects: None
 */
static uint32_t
hash_ipv4(struct irc_ssaddr *addr, int bits)
{
  if (bits != 0)
  {
    struct sockaddr_in *v4 = (struct sockaddr_in *)addr;
    uint32_t av = ntohl(v4->sin_addr.s_addr) & ~((1 << (32 - bits)) - 1);

    return (av ^ (av >> 12) ^ (av >> 24)) & (ATABLE_SIZE - 1);
  }

  return 0;
}

/* unsigned long hash_ipv6(struct irc_ssaddr*)
 * Input: An IP address.
 * Output: A hash value of the IP address.
 * Side effects: None
 */
#ifdef IPV6
static uint32_t
hash_ipv6(struct irc_ssaddr *addr, int bits)
{
  uint32_t v = 0, n;
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)addr;

  for (n = 0; n < 16; n++)
  {
    if (bits >= 8)
    {
      v ^= v6->sin6_addr.s6_addr[n];
      bits -= 8;
    }
    else if (bits)
    {
      v ^= v6->sin6_addr.s6_addr[n] & ~((1 << (8 - bits)) - 1);
      return v & (ATABLE_SIZE - 1);
    }
    else
      return v & (ATABLE_SIZE - 1);
  }
  return v & (ATABLE_SIZE - 1);
}
#endif

/* int hash_text(const char *start)
 * Input: The start of the text to hash.
 * Output: The hash of the string between 1 and (TH_MAX-1)
 * Side-effects: None.
 */
static uint32_t
hash_text(const char *start)
{
  const char *p = start;
  uint32_t h = 0;

  for (; *p; ++p)
    h = (h << 4) - (h + (unsigned char)ToLower(*p));

  return h & (ATABLE_SIZE - 1);
}

/* unsigned long get_hash_mask(const char *)
 * Input: The text to hash.
 * Output: The hash of the string right of the first '.' past the last
 *         wildcard in the string.
 * Side-effects: None.
 */
static uint32_t
get_mask_hash(const char *text)
{
  const char *hp = "", *p;

  for (p = text + strlen(text) - 1; p >= text; p--)
    if (IsMWildChar(*p))
      return hash_text(hp);
    else if (*p == '.')
      hp = p + 1;
  return hash_text(text);
}

/* struct AccessItem *find_conf_by_address(const char *, struct irc_ssaddr *,
 *                                         int type, int fam, const char *username)
 * Input: The hostname, the address, the type of mask to find, the address
 *        family, the username.
 * Output: The matching value with the highest precedence.
 * Side-effects: None
 * Note: Setting bit 0 of the type means that the username is ignored.
 * Warning: IsNeedPassword for everything that is not an auth{} entry
 * should always be true (i.e. aconf->flags & CONF_FLAGS_NEED_PASSWORD == 0)
 */
struct AccessItem *
find_conf_by_address(const char *name, struct irc_ssaddr *addr, unsigned int type,
                     int fam, const char *username, const char *password, int do_match)
{
  unsigned int hprecv = 0;
  dlink_node *ptr = NULL;
  struct AccessItem *hprec = NULL;
  struct AddressRec *arec;
  int b;
  int (*cmpfunc)(const char *, const char *) = do_match ? match : irccmp;

  if (username == NULL)
    username = "";
  if (password == NULL)
    password = "";

  if (addr)
  {
    /* Check for IPV6 matches... */
#ifdef IPV6
    if (fam == AF_INET6)
    {
      for (b = 128; b >= 0; b -= 16)
      {
        DLINK_FOREACH(ptr, atable[hash_ipv6(addr, b)].head)
        {
          arec = ptr->data; 

          if (arec->type == (type & ~0x1) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV6 &&
              match_ipv6(addr, &arec->Mask.ipa.addr,
                         arec->Mask.ipa.bits) &&
              (type & 0x1 || cmpfunc(arec->username, username) == do_match) &&
	      (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
	       match_conf_password(password, arec->aconf)))
          {
            hprecv = arec->precedence;
            hprec = arec->aconf;
          }
        }
      }
    }
    else
#endif
    if (fam == AF_INET)
    {
      for (b = 32; b >= 0; b -= 8)
      {
        DLINK_FOREACH(ptr, atable[hash_ipv4(addr, b)].head)
        {
          arec = ptr->data;

          if (arec->type == (type & ~0x1) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV4 &&
              match_ipv4(addr, &arec->Mask.ipa.addr,
                         arec->Mask.ipa.bits) &&
              (type & 0x1 || cmpfunc(arec->username, username) == do_match) &&
	      (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
	       match_conf_password(password, arec->aconf)))
          {
            hprecv = arec->precedence;
            hprec = arec->aconf;
          }
        }
      }
    }
  }

  if (name != NULL)
  {
    const char *p = name;

    while (1)
    {
        DLINK_FOREACH(ptr, atable[hash_text(p)].head)
        {
          arec = ptr->data;
          if ((arec->type == (type & ~0x1)) &&
            arec->precedence > hprecv &&
            (arec->masktype == HM_HOST) &&
            cmpfunc(arec->Mask.hostname, name) == do_match &&
            (type & 0x1 || cmpfunc(arec->username, username) == do_match) &&
            (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
             match_conf_password(password, arec->aconf)))
        {
          hprecv = arec->precedence;
          hprec = arec->aconf;
        }
      }
      p = strchr(p, '.');
      if (p == NULL)
        break;
      p++;
    }

    DLINK_FOREACH(ptr, atable[0].head)
    {
      arec = ptr->data;

      if (arec->type == (type & ~0x1) &&
          arec->precedence > hprecv &&
          arec->masktype == HM_HOST &&
          cmpfunc(arec->Mask.hostname, name) == do_match &&
          (type & 0x1 || cmpfunc(arec->username, username) == do_match) &&
          (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
           match_conf_password(password, arec->aconf)))
      {
        hprecv = arec->precedence;
        hprec = arec->aconf;
      }
    }
  }

  return hprec;
}

/* struct AccessItem* find_address_conf(const char*, const char*,
 * 	                               struct irc_ssaddr*, int, char *);
 * Input: The hostname, username, address, address family.
 * Output: The applicable AccessItem.
 * Side-effects: None
 */
struct AccessItem *
find_address_conf(const char *host, const char *user,
                  struct irc_ssaddr *ip, int aftype, char *password)
{
  struct AccessItem *iconf, *kconf;

  /* Find the best auth{} block... If none, return NULL -A1kmm */
  if ((iconf = find_conf_by_address(host, ip, CONF_CLIENT, aftype, user,
                                    password, 1)) == NULL)
    return NULL;

  /* If they are exempt from K-lines, return the best auth{} block. -A1kmm */
  if (IsConfExemptKline(iconf))
    return iconf;

  /* Find the best K-line... -A1kmm */
  kconf = find_conf_by_address(host, ip, CONF_KLINE, aftype, user, NULL, 1);

  /*
   * If they are K-lined, return the K-line. Otherwise, return the
   * auth{} block. -A1kmm
   */
  if (kconf != NULL)
    return kconf;

  kconf = find_conf_by_address(host, ip, CONF_GLINE, aftype, user, NULL, 1);
  if (kconf != NULL && !IsConfExemptGline(iconf))
    return kconf;

  return iconf;
}

/* struct AccessItem* find_dline_conf(struct irc_ssaddr*, int)
 *
 * Input:	An address, an address family.
 * Output:	The best matching D-line or exempt line.
 * Side effects: None.
 */
struct AccessItem *
find_dline_conf(struct irc_ssaddr *addr, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(NULL, addr, CONF_EXEMPTDLINE | 1, aftype,
                               NULL, NULL, 1);
  if (eline != NULL)
    return eline;

  return find_conf_by_address(NULL, addr, CONF_DLINE | 1, aftype, NULL, NULL, 1);
}

/* void add_conf_by_address(int, struct AccessItem *aconf)
 * Input: 
 * Output: None
 * Side-effects: Adds this entry to the hash table.
 */
void
add_conf_by_address(const unsigned int type, struct AccessItem *aconf)
{
  const char *address;
  const char *username;
  static unsigned int prec_value = 0xFFFFFFFF;
  int bits = 0;
  struct AddressRec *arec;

  address = aconf->host;
  username = aconf->user;

  assert(type != 0); 
  assert(aconf != NULL);

  if (EmptyString(address))
    address = "/NOMATCH!/";

  arec = MyMalloc(sizeof(struct AddressRec));
  arec->masktype = parse_netmask(address, &arec->Mask.ipa.addr, &bits);
  arec->Mask.ipa.bits = bits;
  arec->username = username;
  arec->aconf = aconf;
  arec->precedence = prec_value--;
  arec->type = type;

  switch (arec->masktype)
  {
    case HM_IPV4:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 8;
      dlinkAdd(arec, &arec->node, &atable[hash_ipv4(&arec->Mask.ipa.addr, bits)]);
      break;
#ifdef IPV6
    case HM_IPV6:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 16;
      dlinkAdd(arec, &arec->node, &atable[hash_ipv6(&arec->Mask.ipa.addr, bits)]);
      break;
#endif
    default: /* HM_HOST */
      arec->Mask.hostname = address;
      dlinkAdd(arec, &arec->node, &atable[get_mask_hash(address)]);
      break;
  }
}

/* void delete_one_address(const char*, struct AccessItem*)
 * Input: An address string, the associated AccessItem.
 * Output: None
 * Side effects: Deletes an address record. Frees the AccessItem if there
 *               is nothing referencing it, sets it as illegal otherwise.
 */
void
delete_one_address_conf(const char *address, struct AccessItem *aconf)
{
  int bits = 0;
  uint32_t hv = 0;
  dlink_node *ptr = NULL, *ptr_next = NULL;
  struct irc_ssaddr addr;

  switch (parse_netmask(address, &addr, &bits))
  {
    case HM_IPV4:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 8;
      hv = hash_ipv4(&addr, bits);
      break;
#ifdef IPV6
    case HM_IPV6:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 16;
      hv = hash_ipv6(&addr, bits);
      break;
#endif
    default: /* HM_HOST */
      hv = get_mask_hash(address);
      break;
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, atable[hv].head)
  {
    struct AddressRec *arec = ptr->data;

    if (arec->aconf == aconf)
    {
      dlinkDelete(&arec->node, &atable[hv]);
      aconf->status |= CONF_ILLEGAL;

      if (!aconf->clients)
        free_access_item(aconf);

      MyFree(arec);
      return;
    }
  }
}

/* void clear_out_address_conf(void)
 * Input: None
 * Output: None
 * Side effects: Clears out all address records in the hash table,
 *               frees them, and frees the AccessItems if nothing references
 *               them, otherwise sets them as illegal.   
 */
void
clear_out_address_conf(void)
{
  unsigned int i = 0;
  dlink_node *ptr = NULL, *ptr_next = NULL;
 
  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH_SAFE(ptr, ptr_next, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      /* We keep the temporary K-lines and destroy the
       * permanent ones, just to be confusing :) -A1kmm
       */  
      if (!(arec->aconf->flags & CONF_FLAGS_TEMPORARY))
      {
      /* XXX HACK */
        if (arec->type == CONF_KLINE && !IsConfMain(arec->aconf))
          continue;

        dlinkDelete(&arec->node, &atable[i]);
        /* unlink it from link list - Dianora */
        arec->aconf->status |= CONF_ILLEGAL;

        if (!arec->aconf->clients)
          free_access_item(arec->aconf);
        MyFree(arec);
      }
    }
  }
}

static void
hostmask_send_expiration(struct AddressRec *arec)
{
  char ban_type = '\0';

  if (!ConfigFileEntry.tkline_expire_notices)
    return;

  switch (arec->type)
  {
    case CONF_KLINE:
      ban_type = 'K';
      break;
    case CONF_DLINE:
      ban_type = 'D';
      break;
    case CONF_GLINE:
      ban_type = 'G';
      break;
  }
  
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                       "Temporary %c-line for [%s@%s] expired", ban_type,
                       (arec->aconf->user) ? arec->aconf->user : "*",
                       (arec->aconf->host) ? arec->aconf->host : "*");
}

void
hostmask_expire_temporary(void)
{
  unsigned int i = 0;
  dlink_node *ptr = NULL, *ptr_next = NULL;

  for (i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH_SAFE(ptr, ptr_next, atable[i].head)
    {
      struct AddressRec *arec = ptr->data;

      if (!IsConfTemporary(arec->aconf) || arec->aconf->hold > CurrentTime)
        continue;

      switch (arec->type)
      {
        case CONF_KLINE:
        case CONF_DLINE:
        case CONF_GLINE:
          hostmask_send_expiration(arec);

          dlinkDelete(&arec->node, &atable[i]);
          free_access_item(arec->aconf);
          MyFree(arec);
          break;
      }
    }
  }
}

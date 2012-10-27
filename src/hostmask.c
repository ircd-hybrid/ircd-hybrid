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
#include "tools.h"
#include "s_conf.h"
#include "hostmask.h"
#include "numeric.h"
#include "send.h"
#include "irc_string.h"

#ifdef IPV6
static int try_parse_v6_netmask(const char *, struct irc_ssaddr *, int *);
static unsigned long hash_ipv6(struct irc_ssaddr *, int);
#endif
static int try_parse_v4_netmask(const char *, struct irc_ssaddr *, int *);
static unsigned long hash_ipv4(struct irc_ssaddr *, int);

#define DigitParse(ch) do { \
                       if (ch >= '0' && ch <= '9') \
                         ch = ch - '0'; \
                       else if (ch >= 'A' && ch <= 'F') \
                         ch = ch - 'A' + 10; \
                       else if (ch >= 'a' && ch <= 'f') \
                         ch = ch - 'a' + 10; \
                       } while(0);

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
  struct sockaddr_in6 *v6 = (struct sockaddr_in6*) addr;

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
  struct sockaddr_in *v4 = (struct sockaddr_in*) addr;

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
match_ipv6(struct irc_ssaddr *addr, struct irc_ssaddr *mask, int bits)
{
  int i, m, n = bits / 8;
  struct sockaddr_in6 *v6 = (struct sockaddr_in6*)addr;
  struct sockaddr_in6 *v6mask = (struct sockaddr_in6*)mask;

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
match_ipv4(struct irc_ssaddr *addr, struct irc_ssaddr *mask, int bits)
{
  struct sockaddr_in *v4 = (struct sockaddr_in*) addr;
  struct sockaddr_in *v4mask = (struct sockaddr_in*) mask;
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
    v4_base_ip = (struct sockaddr_in*)ip;
    mask = ~((1 << (32 - bits)) - 1);
    v4_base_ip->sin_addr.s_addr =
      htonl(ntohl(v4_base_ip->sin_addr.s_addr) & mask);
  }
#ifdef IPV6
  else
  {
    n = bits / 8;
    m = bits % 8;
    v6_base_ip = (struct sockaddr_in6*)ip;

    mask = ~((1 << (8 - m)) -1 );
    v6_base_ip->sin6_addr.s6_addr[n] = v6_base_ip->sin6_addr.s6_addr[n] & mask;
    for (i = n + 1; i < 16; i++)
      v6_base_ip->sin6_addr.s6_addr[i] = 0;
  }
#endif
}

/* Hashtable stuff...now external as its used in m_stats.c */
struct AddressRec *atable[ATABLE_SIZE];

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
static unsigned long
hash_ipv4(struct irc_ssaddr *addr, int bits)
{
  if (bits != 0)
  {
    struct sockaddr_in *v4 = (struct sockaddr_in *)addr;
    unsigned long av = ntohl(v4->sin_addr.s_addr) & ~((1 << (32 - bits)) - 1);
    return((av ^ (av >> 12) ^ (av >> 24)) & (ATABLE_SIZE - 1));
  }

  return(0);
}

/* unsigned long hash_ipv6(struct irc_ssaddr*)
 * Input: An IP address.
 * Output: A hash value of the IP address.
 * Side effects: None
 */
#ifdef IPV6
static unsigned long
hash_ipv6(struct irc_ssaddr *addr, int bits)
{
  unsigned long v = 0, n;
  struct sockaddr_in6 *v6 = (struct sockaddr_in6*) addr;
  
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
static int
hash_text(const char *start)
{
  const char *p = start;
  unsigned long h = 0;

  while (*p)
  {
    h = (h << 4) - (h + (unsigned char)ToLower(*p++));
  }
  return (h & (ATABLE_SIZE - 1));
}

/* unsigned long get_hash_mask(const char *)
 * Input: The text to hash.
 * Output: The hash of the string right of the first '.' past the last
 *         wildcard in the string.
 * Side-effects: None.
 */
static unsigned long
get_mask_hash(const char *text)
{
  const char *hp = "", *p;

  for (p = text + strlen(text) - 1; p >= text; p--)
    if (*p == '*' || *p == '?')
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
find_conf_by_address(const char *name, struct irc_ssaddr *addr, int type,
                     int fam, const char *username, const char *password)
{
  unsigned long hprecv = 0;
  struct AccessItem *hprec = NULL;
  struct AddressRec *arec;
  int b;

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
        for (arec = atable[hash_ipv6(addr, b)]; arec; arec = arec->next)
          if (arec->type == (type & ~0x1) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV6 &&
              match_ipv6(addr, &arec->Mask.ipa.addr,
                         arec->Mask.ipa.bits) &&
              (type & 0x1 || match(arec->username, username)) &&
	      (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
	       match_conf_password(password, arec->aconf)))
          {
            hprecv = arec->precedence;
            hprec = arec->aconf;
          }
      }
    }
    else
#endif
    if (fam == AF_INET)
    {
      for (b = 32; b >= 0; b -= 8)
      {
        for (arec = atable[hash_ipv4(addr, b)]; arec; arec = arec->next)
          if (arec->type == (type & ~0x1) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV4 &&
              match_ipv4(addr, &arec->Mask.ipa.addr,
                         arec->Mask.ipa.bits) &&
              (type & 0x1 || match(arec->username, username)) &&
	      (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
	       match_conf_password(password, arec->aconf)))
          {
            hprecv = arec->precedence;
            hprec = arec->aconf;
          }
      }
    }
  }

  if (name != NULL)
  {
    const char *p = name;

    while (1)
    {
      for (arec = atable[hash_text(p)]; arec != NULL; arec = arec->next)
        if ((arec->type == (type & ~0x1)) &&
            arec->precedence > hprecv &&
            (arec->masktype == HM_HOST) &&
            match(arec->Mask.hostname, name) &&
            (type & 0x1 || match(arec->username, username)) &&
            (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
             match_conf_password(password, arec->aconf)))
        {
          hprecv = arec->precedence;
          hprec = arec->aconf;
        }
      p = strchr(p, '.');
      if (p == NULL)
        break;
      p++;
    }
    for (arec = atable[0]; arec; arec = arec->next)
      if (arec->type == (type & ~0x1) &&
          arec->precedence > hprecv &&
          arec->masktype == HM_HOST &&
          match(arec->Mask.hostname, name) &&
          (type & 0x1 || match(arec->username, username)) &&
          (IsNeedPassword(arec->aconf) || arec->aconf->passwd == NULL ||
           match_conf_password(password, arec->aconf)))
      {
        hprecv = arec->precedence;
        hprec = arec->aconf;
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

  /* Find the best I-line... If none, return NULL -A1kmm */
  if ((iconf = find_conf_by_address(host, ip, CONF_CLIENT, aftype, user,
                                    password)) == NULL)
    return(NULL);

  /* If they are exempt from K-lines, return the best I-line. -A1kmm */
  if (IsConfExemptKline(iconf))
    return(iconf);

  /* Find the best K-line... -A1kmm */
  kconf = find_conf_by_address(host, ip, CONF_KILL, aftype, user, NULL);

  /* If they are K-lined, return the K-line. Otherwise, return the
   * I-line. -A1kmm */
  if (kconf != NULL)
    return(kconf);

  kconf = find_conf_by_address(host, ip, CONF_GLINE, aftype, user, NULL);
  if (kconf != NULL && !IsConfExemptGline(iconf))
    return(kconf);

  return(iconf);
}

struct AccessItem *
find_gline_conf(const char *host, const char *user,
                struct irc_ssaddr *ip, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(host, ip, CONF_EXEMPTKLINE, aftype,
                               user, NULL);
  if (eline != NULL)
    return(eline);

  return(find_conf_by_address(host, ip, CONF_GLINE, aftype, user, NULL));
}

/* find_kline_conf
 *
 * inputs	- pointer to hostname
 *		- pointer to username
 *		- incoming IP and type (IPv4 vs. IPv6)
 * outut	- pointer to kline conf if found NULL if not
 * side effects	-
 */
struct AccessItem *
find_kline_conf(const char *host, const char *user,
		struct irc_ssaddr *ip, int aftype)
{
  struct AccessItem *eline;

  eline = find_conf_by_address(host, ip, CONF_EXEMPTKLINE, aftype,
                               user, NULL);
  if (eline != NULL)
    return(eline);

  return(find_conf_by_address(host, ip, CONF_KILL, aftype, user, NULL));
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
                               NULL, NULL);
  if (eline != NULL)
    return(eline);
  return(find_conf_by_address(NULL, addr, CONF_DLINE | 1, aftype, NULL, NULL));
}

/* void add_conf_by_address(int, struct AccessItem *aconf)
 * Input: 
 * Output: None
 * Side-effects: Adds this entry to the hash table.
 */
void
add_conf_by_address(int type, struct AccessItem *aconf)
{
  const char *address;
  const char *username;
  static unsigned long prec_value = 0xFFFFFFFF;
  int masktype, bits;
  unsigned long hv;
  struct AddressRec *arec;

  address = aconf->host;
  username = aconf->user;

  assert(type != 0); 
  assert(aconf != NULL);

  if (EmptyString(address))
    address = "/NOMATCH!/";

  arec = MyMalloc(sizeof(struct AddressRec));
  masktype = parse_netmask(address, &arec->Mask.ipa.addr, &bits);
  arec->Mask.ipa.bits = bits;
  arec->masktype = masktype;
#ifdef IPV6
  if (masktype == HM_IPV6)
  {
    /* We have to do this, since we do not re-hash for every bit -A1kmm. */
    bits -= bits % 16;
    arec->next = atable[(hv = hash_ipv6(&arec->Mask.ipa.addr, bits))];
    atable[hv] = arec;
  }
  else 
#endif
  if (masktype == HM_IPV4)
  {
    /* We have to do this, since we do not re-hash for every bit -A1kmm. */
    bits -= bits % 8;
    arec->next = atable[(hv = hash_ipv4(&arec->Mask.ipa.addr, bits))];
    atable[hv] = arec;
  }
  else
  {
    arec->Mask.hostname = address;
    arec->next = atable[(hv = get_mask_hash(address))];
    atable[hv] = arec;
  }
  arec->username = username;
  arec->aconf = aconf;
  arec->precedence = prec_value--;
  arec->type = type;
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
  int masktype, bits;
  unsigned long hv;
  struct AddressRec *arec, *arecl = NULL;
  struct irc_ssaddr addr;
  masktype = parse_netmask(address, &addr, &bits);

#ifdef IPV6
  if (masktype == HM_IPV6)
  {
    /* We have to do this, since we do not re-hash for every bit -A1kmm. */
    bits -= bits % 16;
    hv = hash_ipv6(&addr, bits);
  }
  else
#endif
  if (masktype == HM_IPV4)
  {
    /* We have to do this, since we do not re-hash for every bit -A1kmm. */
    bits -= bits % 8;
    hv = hash_ipv4(&addr, bits);
  }
  else
    hv = get_mask_hash(address);
  for (arec = atable[hv]; arec; arec = arec->next)
  {
    if (arec->aconf == aconf)
    {
      if (arecl)
        arecl->next = arec->next;
      else
        atable[hv] = arec->next;
      aconf->status |= CONF_ILLEGAL;
      if (aconf->clients == 0)
        free_access_item(aconf);
      MyFree(arec);
      return;
    }
    arecl = arec;
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
  int i;
  struct AddressRec *arec;
  struct AddressRec *last_arec;
  struct AddressRec *next_arec;
 
  for (i = 0; i < ATABLE_SIZE; i++)
  {
    last_arec = NULL;
    for (arec = atable[i]; arec; arec = next_arec)
    {
      /* We keep the temporary K-lines and destroy the
       * permanent ones, just to be confusing :) -A1kmm
       */  
      next_arec = arec->next;

      if (arec->aconf->flags & CONF_FLAGS_TEMPORARY)
      {
        last_arec = arec;
      }
      else   
      {
        /* unlink it from link list - Dianora */
  
        if (last_arec == NULL)
        {
          atable[i] = next_arec;
        }
        else
        {
          last_arec->next = next_arec;
        }

        arec->aconf->status |= CONF_ILLEGAL;
        if (arec->aconf->clients == 0)
          free_access_item(arec->aconf);
        MyFree(arec);
      }
    }
  }
}

/*
 * show_iline_prefix()
 *
 * inputs       - pointer to struct Client requesting output
 *              - pointer to struct AccessItem 
 *              - name to which iline prefix will be prefixed to
 * output       - pointer to static string with prefixes listed in ascii form
 * side effects - NONE
 */
char *
show_iline_prefix(struct Client *sptr, struct AccessItem *aconf, const char *name)
{
  static char prefix_of_host[USERLEN + 14];
  char *prefix_ptr;

  prefix_ptr = prefix_of_host;
  if (IsNoTilde(aconf))
    *prefix_ptr++ = '-';
  if (IsLimitIp(aconf))
    *prefix_ptr++ = '!';
  if (IsNeedIdentd(aconf))
    *prefix_ptr++ = '+';
  if (!IsNeedPassword(aconf))
    *prefix_ptr++ = '&';
  if (IsConfExemptResv(aconf))
    *prefix_ptr++ = '$';
  if (IsNoMatchIp(aconf))
    *prefix_ptr++ = '%';
  if (IsConfDoSpoofIp(aconf))
    *prefix_ptr++ = '=';
  if (MyOper(sptr) && IsConfExemptKline(aconf))
    *prefix_ptr++ = '^';
  if (MyOper(sptr) && IsConfExemptGline(aconf))
    *prefix_ptr++ = '_';
  if (MyOper(sptr) && IsConfExemptLimits(aconf))
    *prefix_ptr++ = '>';
  if (MyOper(sptr) && IsConfIdlelined(aconf))
    *prefix_ptr++ = '<';
  if (IsConfCanFlood(aconf))
    *prefix_ptr++ = '|';
  strlcpy(prefix_ptr, name, USERLEN);

  return(prefix_of_host);
}

/* report_auth()
 *
 * Inputs: pointer to client to report to
 * Output: None
 * Side effects: Reports configured auth{} blocks to client_p
 */
void
report_auth(struct Client *client_p)
{
  struct AddressRec *arec;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  int i;

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec = arec->next)
    {
      if (arec->type == CONF_CLIENT)
      {
        aconf = arec->aconf;

        if (!MyOper(client_p) && IsConfDoSpoofIp(aconf))
          continue;

	conf = unmap_conf_item(aconf);

        /* We are doing a partial list, based on what matches the u@h of the
         * sender, so prepare the strings for comparing --fl_
	 */
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(client_p, form_str(RPL_STATSILINE), me.name,
                     client_p->name, 'I',
		     conf->name == NULL ? "*" : conf->name,
		     show_iline_prefix(client_p, aconf, aconf->user),
                     IsConfDoSpoofIp(aconf) ? "255.255.255.255" :
                     aconf->host, aconf->port,
		     aconf->class_ptr ? aconf->class_ptr->name : "<default>");
		     
        else
          sendto_one(client_p, form_str(RPL_STATSILINE), me.name,
                     client_p->name, 'I',
		     conf->name == NULL ? "*" : conf->name,
		     show_iline_prefix(client_p, aconf, aconf->user),
                     aconf->host, aconf->port,
		     aconf->class_ptr ? aconf->class_ptr->name : "<default>");
      }
    }
  }
}

/* report_Klines()
 * Inputs: Client to report to,
 *	   type(==0 for perm, !=0 for temporary)
 *	   mask 
 * Output: None
 * Side effects: Reports configured K(or k)-lines to client_p.
 */
void
report_Klines(struct Client *client_p, int tkline)
{
  struct AddressRec *arec = NULL;
  struct AccessItem *aconf = NULL;
  int i;
  const char *p = NULL;

  if (tkline)
    p = "k";
  else
    p = "K";

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec = arec->next)
    {
      if (arec->type == CONF_KILL)
      {
        if ((tkline && !((aconf = arec->aconf)->flags & CONF_FLAGS_TEMPORARY)) ||
            (!tkline && ((aconf = arec->aconf)->flags & CONF_FLAGS_TEMPORARY)))
          continue;

	if (IsOper(client_p))
	  sendto_one(client_p, form_str(RPL_STATSKLINE), me.name,
                     client_p->name, p, aconf->host, aconf->user,
		     aconf->reason, aconf->oper_reason ? aconf->oper_reason : "");
	else
          sendto_one(client_p, form_str(RPL_STATSKLINE), me.name,
                     client_p->name, p, aconf->host, aconf->user,
		     aconf->reason, "");
      }
    }
  }
}

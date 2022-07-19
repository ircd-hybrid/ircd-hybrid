/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2022 ircd-hybrid development team
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

/*! \file hostmask.c
 * \brief Code to efficiently find IP & hostmask based configs.
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
                       } while (false);

/* Hashtable stuff...now external as it's used in m_stats.c */
dlink_list atable[ATABLE_SIZE];

/* The mask parser/type determination code... */

/* int try_parse_v6_netmask(const char *, struct irc_ssaddr *, int *);
 * Input: A possible IPV6 address as a string.
 * Output: An integer describing whether it is an IPV6 or hostmask,
 *         an address(if it is IPV6), a bitlength(if it is IPV6).
 * Side effects: None
 * Comments: Called from parse_netmask
 */
static int
try_parse_v6_netmask(const char *text, struct irc_ssaddr *addr, int *b)
{
  char c;
  int d[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  int dp = 0;
  int nyble = 4;
  int finsert = -1;
  int bits = 128;
  int deficit = 0;
  uint16_t dc[8];
  struct sockaddr_in6 *const v6 = (struct sockaddr_in6 *)addr;

  for (const char *p = text; (c = *p); ++p)
  {
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
        /*
         * If there were less than 4 hex digits, e.g. :ABC: shift right
         * so we don't interpret it as ABC0 -A1kmm
         */
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

      bits = strtoul(p + 1, &after, 10);

      if (bits < 0 || bits > 128 || *after)
        return HM_HOST;
      /* 16 bits for each hextet, plus 4 for each parsed nyble */
      if (bits > dp * 16 + (4 - nyble) * 4 && !(finsert >= 0))
        return HM_HOST;
      break;
    }
    else
      return HM_HOST;
  }

  d[dp] = d[dp] >> 4 * nyble;

  if (c == 0)
    ++dp;
  if (finsert < 0 && bits == 0)
    bits = dp * 16;

  /* How many words are missing? -A1kmm */
  deficit = bits / 16 + ((bits % 16) ? 1 : 0) - dp;

  /* Now fill in the gaps(from ::) in the copied table... -A1kmm */
  for (dp = 0, nyble = 0; dp < 8; ++dp)
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
  for (dp = bits / 16 + (bits % 16 ? 1 : 0); dp < 8; ++dp)
    dc[dp] = 0;

  /* And assign... -A1kmm */
  if (addr)
  {
    v6->sin6_family = AF_INET6;

    for (dp = 0; dp < 8; ++dp)
      /* The cast is a kludge to make netbsd work. */
      ((uint16_t *)&v6->sin6_addr)[dp] = htons(dc[dp]);
  }

  if (b)
    *b = bits;
  return HM_IPV6;
}

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
  const char *digits[4];
  uint8_t addb[4];
  int n = 0, bits = 0;
  char c;
  struct sockaddr_in *const v4 = (struct sockaddr_in *)addr;

  digits[n++] = text;

  for (const char *p = text; (c = *p); ++p)
  {
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
      if (*(p + 1) || n == 1 || *(p - 1) != '.')
        return HM_HOST;

      bits = (n - 1) * 8;
      break;
    }
    else if (c == '/')
    {
      char *after;
      bits = strtoul(p + 1, &after, 10);

      if (bits < 0 || *after)
        return HM_HOST;
      if (bits > n * 8)
        return HM_HOST;

      break;
    }
    else
      return HM_HOST;
  }

  if (n < 4 && bits == 0)
    bits = n * 8;
  if (bits)
    while (n < 4)
      digits[n++] = "0";

  for (n = 0; n < 4; ++n)
    addb[n] = strtoul(digits[n], NULL, 10);

  if (bits == 0)
    bits = 32;

  /* Set unused bits to 0... -A1kmm */
  if (bits < 32 && bits % 8)
    addb[bits / 8] &= ~((1 << (8 - bits % 8)) - 1);
  for (n = bits / 8 + (bits % 8 ? 1 : 0); n < 4; ++n)
    addb[n] = 0;
  if (addr)
  {
    v4->sin_family = AF_INET;
    v4->sin_addr.s_addr =
      htonl((unsigned int)addb[0] << 24 |
            (unsigned int)addb[1] << 16 |
            (unsigned int)addb[2] <<  8 |
            (unsigned int)addb[3]);
  }

  if (b)
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
  if (addr)
    memset(addr, 0, sizeof(*addr));

  if (strchr(text, '.'))
    return try_parse_v4_netmask(text, addr, b);
  if (strchr(text, ':'))
    return try_parse_v6_netmask(text, addr, b);

  return HM_HOST;
}

bool
address_compare(const void *p1, const void *p2, bool exact, bool port, int bits)
{
  const struct irc_ssaddr *const addr = p1;
  const struct irc_ssaddr *const mask = p2;

  if (addr->ss.ss_family != mask->ss.ss_family)
    return false;

  if (addr->ss.ss_family == AF_INET)
  {
    const struct sockaddr_in *const sin1 = (const struct sockaddr_in *)addr;
    const struct sockaddr_in *const sin2 = (const struct sockaddr_in *)mask;

    if (port == true && (sin1->sin_port != sin2->sin_port))
      return false; 
    if (exact == true)
      return sin1->sin_addr.s_addr == sin2->sin_addr.s_addr;
    return match_ipv4(addr, mask, bits);
  }
  else if (addr->ss.ss_family == AF_INET6)
  {
    const struct sockaddr_in6 *const sin1 = (const struct sockaddr_in6 *)addr;
    const struct sockaddr_in6 *const sin2 = (const struct sockaddr_in6 *)mask;

    if (port == true && (sin1->sin6_port != sin2->sin6_port))
      return false;

    if (exact == true)
      return memcmp(sin1->sin6_addr.s6_addr,
                    sin2->sin6_addr.s6_addr, sizeof(struct in6_addr)) == 0;
    return match_ipv6(addr, mask, bits);
  }

  return false;
}

/* The address matching stuff... */
/* int match_ipv6(struct irc_ssaddr *, struct irc_ssaddr *, int)
 * Input: An IP address, an IP mask, the number of bits in the mask.
 * Output: if match, -1 else 0
 * Side effects: None
 */
bool
match_ipv6(const struct irc_ssaddr *addr, const struct irc_ssaddr *mask, int bits)
{
  int i, m, n = bits / 8;
  const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)addr;
  const struct sockaddr_in6 *const v6mask = (const struct sockaddr_in6 *)mask;

  for (i = 0; i < n; ++i)
    if (v6->sin6_addr.s6_addr[i] != v6mask->sin6_addr.s6_addr[i])
      return false;

  if ((m = bits % 8) == 0)
    return true;
  if ((v6->sin6_addr.s6_addr[n] & ~((1 << (8 - m)) - 1)) ==
      v6mask->sin6_addr.s6_addr[n])
    return true;
  return false;
}

/* int match_ipv4(struct irc_ssaddr *, struct irc_ssaddr *, int)
 * Input: An IP address, an IP mask, the number of bits in the mask.
 * Output: if match, -1 else 0
 * Side Effects: None
 */
bool
match_ipv4(const struct irc_ssaddr *addr, const struct irc_ssaddr *mask, int bits)
{
  const struct sockaddr_in *const v4 = (const struct sockaddr_in *)addr;
  const struct sockaddr_in *const v4mask = (const struct sockaddr_in *)mask;

  if ((ntohl(v4->sin_addr.s_addr) & ~((1 << (32 - bits)) - 1)) ==
      ntohl(v4mask->sin_addr.s_addr))
    return true;
  return false;
}

/* unsigned long hash_ipv4(struct irc_ssaddr*)
 * Input: An IP address.
 * Output: A hash value of the IP address.
 * Side effects: None
 */
static uint32_t
hash_ipv4(const struct irc_ssaddr *addr, int bits)
{
  if (bits)
  {
    const struct sockaddr_in *const v4 = (const struct sockaddr_in *)addr;
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
static uint32_t
hash_ipv6(const struct irc_ssaddr *addr, int bits)
{
  uint32_t v = 0, n;
  const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)addr;

  for (n = 0; n < 16; ++n)
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

/* int hash_text(const char *start)
 * Input: The start of the text to hash.
 * Output: The hash of the string between 1 and (TH_MAX-1)
 * Side-effects: None.
 */
static uint32_t
hash_text(const char *start)
{
  uint32_t h = 0;

  for (const char *p = start; *p; ++p)
    h = (h << 4) - (h + ToLower(*p));

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

  for (p = text + strlen(text) - 1; p >= text; --p)
    if (IsMWildChar(*p))
      return hash_text(hp);
    else if (*p == '.')
      hp = p + 1;
  return hash_text(text);
}

/* struct MaskItem *find_conf_by_address(const char *, struct irc_ssaddr *,
 *                                         int type, int fam, const char *username)
 * Input: The hostname, the address, the type of mask to find, the address
 *        family, the username.
 * Output: The matching value with the highest precedence.
 * Side-effects: None
 * Note: Setting bit 0 of the type means that the username is ignored.
 * Warning: IsNeedPassword for everything that is not an auth{} entry
 * should always be true (i.e. conf->flags & CONF_FLAGS_NEED_PASSWORD == 0)
 */
struct MaskItem *
find_conf_by_address(const char *name, const struct irc_ssaddr *addr, unsigned int type,
                     const char *username, const char *password, int do_match)
{
  unsigned int hprecv = 0;
  dlink_node *node;
  struct MaskItem *hprec = NULL;
  struct AddressRec *arec = NULL;
  int (*cmpfunc)(const char *, const char *) = do_match ? match : irccmp;

  if (addr)
  {
    /* Check for IPV6 matches... */
    if (addr->ss.ss_family == AF_INET6)
    {
      for (int b = 128; b >= 0; b -= 16)
      {
        DLINK_FOREACH(node, atable[hash_ipv6(addr, b)].head)
        {
          arec = node->data;

          if ((arec->type == type) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV6 &&
              match_ipv6(addr, &arec->Mask.ipa.addr,
                         arec->Mask.ipa.bits) &&
              (!username || !cmpfunc(arec->username, username)) &&
              (IsNeedPassword(arec->conf) || arec->conf->passwd == NULL ||
               match_conf_password(password, arec->conf)))
          {
            hprecv = arec->precedence;
            hprec = arec->conf;
          }
        }
      }
    }
    else if (addr->ss.ss_family == AF_INET)
    {
      for (int b = 32; b >= 0; b -= 8)
      {
        DLINK_FOREACH(node, atable[hash_ipv4(addr, b)].head)
        {
          arec = node->data;

          if ((arec->type == type) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV4 &&
              match_ipv4(addr, &arec->Mask.ipa.addr,
                         arec->Mask.ipa.bits) &&
              (!username || !cmpfunc(arec->username, username)) &&
              (IsNeedPassword(arec->conf) || arec->conf->passwd == NULL ||
               match_conf_password(password, arec->conf)))
          {
            hprecv = arec->precedence;
            hprec = arec->conf;
          }
        }
      }
    }
  }

  if (name)
  {
    const char *p = name;

    while (true)
    {
        DLINK_FOREACH(node, atable[hash_text(p)].head)
        {
          arec = node->data;
          if ((arec->type == type) &&
            arec->precedence > hprecv &&
            (arec->masktype == HM_HOST) &&
            !cmpfunc(arec->Mask.hostname, name) &&
            (!username || !cmpfunc(arec->username, username)) &&
            (IsNeedPassword(arec->conf) || arec->conf->passwd == NULL ||
             match_conf_password(password, arec->conf)))
        {
          hprecv = arec->precedence;
          hprec = arec->conf;
        }
      }

      if ((p = strchr(p, '.')) == NULL)
        break;
      ++p;
    }

    DLINK_FOREACH(node, atable[0].head)
    {
      arec = node->data;

      if (arec->type == type &&
          arec->precedence > hprecv &&
          arec->masktype == HM_HOST &&
          !cmpfunc(arec->Mask.hostname, name) &&
          (!username || !cmpfunc(arec->username, username)) &&
          (IsNeedPassword(arec->conf) || arec->conf->passwd == NULL ||
           match_conf_password(password, arec->conf)))
      {
        hprecv = arec->precedence;
        hprec = arec->conf;
      }
    }
  }

  return hprec;
}

/* struct MaskItem* find_address_conf(const char*, const char*,
 * 	                               struct irc_ssaddr*, int, char *);
 * Input: The hostname, username, address, address family.
 * Output: The applicable MaskItem.
 * Side-effects: None
 */
struct MaskItem *
find_address_conf(const char *host, const char *user, const struct irc_ssaddr *addr, const char *password)
{
  struct MaskItem *authcnf = NULL, *killcnf = NULL;

  /* Find the best auth{} block... If none, return NULL -A1kmm */
  if ((authcnf = find_conf_by_address(host, addr, CONF_CLIENT, user, password, 1)) == NULL)
    return NULL;

  /* If they are exempt from K-lines, return the best auth{} block. -A1kmm */
  if (IsConfExemptKline(authcnf))
    return authcnf;

  /* Find the best K-line... -A1kmm */
  killcnf = find_conf_by_address(host, addr, CONF_KLINE, user, NULL, 1);

  /*
   * If they are K-lined, return the K-line. Otherwise, return the
   * auth {} block. -A1kmm
   */
  if (killcnf)
    return killcnf;

  return authcnf;
}

/* struct MaskItem* find_dline_conf(struct irc_ssaddr*, int)
 *
 * Input:	An address, an address family.
 * Output:	The best matching D-line or exempt line.
 * Side effects: None.
 */
struct MaskItem *
find_dline_conf(const struct irc_ssaddr *addr)
{
  struct MaskItem *eline;

  eline = find_conf_by_address(NULL, addr, CONF_EXEMPT, NULL, NULL, 1);
  if (eline)
    return eline;

  return find_conf_by_address(NULL, addr, CONF_DLINE, NULL, NULL, 1);
}

/* void add_conf_by_address(int, struct MaskItem *aconf)
 * Input:
 * Output: None
 * Side-effects: Adds this entry to the hash table.
 */
struct AddressRec *
add_conf_by_address(const unsigned int type, struct MaskItem *conf)
{
  const char *const hostname = conf->host;
  const char *const username = conf->user;
  static unsigned int prec_value = UINT_MAX;
  int bits = 0;

  assert(type && !EmptyString(hostname));

  struct AddressRec *arec = xcalloc(sizeof(*arec));
  arec->masktype = parse_netmask(hostname, &arec->Mask.ipa.addr, &bits);
  arec->Mask.ipa.bits = bits;
  arec->username = username;
  arec->conf = conf;
  arec->precedence = prec_value--;
  arec->type = type;

  switch (arec->masktype)
  {
    case HM_IPV4:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 8;
      dlinkAdd(arec, &arec->node, &atable[hash_ipv4(&arec->Mask.ipa.addr, bits)]);
      break;
    case HM_IPV6:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 16;
      dlinkAdd(arec, &arec->node, &atable[hash_ipv6(&arec->Mask.ipa.addr, bits)]);
      break;
    default: /* HM_HOST */
      arec->Mask.hostname = hostname;
      dlinkAdd(arec, &arec->node, &atable[get_mask_hash(hostname)]);
      break;
  }

  return arec;
}

/* void delete_one_address(const char*, struct MaskItem*)
 * Input: An address string, the associated MaskItem.
 * Output: None
 * Side effects: Deletes an address record. Frees the MaskItem if there
 *               is nothing referencing it, sets it as illegal otherwise.
 */
void
delete_one_address_conf(const char *address, struct MaskItem *conf)
{
  int bits = 0;
  uint32_t hv = 0;
  dlink_node *node;
  struct irc_ssaddr addr;

  switch (parse_netmask(address, &addr, &bits))
  {
    case HM_IPV4:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 8;
      hv = hash_ipv4(&addr, bits);
      break;
    case HM_IPV6:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 16;
      hv = hash_ipv6(&addr, bits);
      break;
    default: /* HM_HOST */
      hv = get_mask_hash(address);
      break;
  }

  DLINK_FOREACH(node, atable[hv].head)
  {
    struct AddressRec *arec = node->data;

    if (arec->conf == conf)
    {
      dlinkDelete(&arec->node, &atable[hv]);

      if (conf->ref_count == 0)
        conf_free(conf);

      xfree(arec);
      return;
    }
  }
}

/* void clear_out_address_conf(void)
 * Input: None
 * Output: None
 * Side effects: Clears out all address records in the hash table,
 *               frees them, and frees the MaskItems if nothing references
 *               them, otherwise sets them as illegal.
 */
void
clear_out_address_conf(void)
{
  dlink_node *node, *node_next;

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH_SAFE(node, node_next, atable[i].head)
    {
      struct AddressRec *arec = node->data;

      /*
       * Destroy the ircd.conf items and keep those that are in the databases
       */
      if (IsConfDatabase(arec->conf))
        continue;

      dlinkDelete(&arec->node, &atable[i]);
      arec->conf->active = false;

      if (arec->conf->ref_count == 0)
        conf_free(arec->conf);
      xfree(arec);
    }
  }
}

static void
hostmask_send_expiration(const struct AddressRec *const arec)
{
  char ban_type = '?';

  switch (arec->type)
  {
    case CONF_KLINE:
      ban_type = 'K';
      break;
    case CONF_DLINE:
      ban_type = 'D';
      break;
    default: break;
  }

  sendto_realops_flags(UMODE_EXPIRATION, L_ALL, SEND_NOTICE,
                       "Temporary %c-line for [%s@%s] expired", ban_type,
                       (arec->conf->user) ? arec->conf->user : "*",
                       (arec->conf->host) ? arec->conf->host : "*");
}

void
hostmask_expire_temporary(void)
{
  dlink_node *node, *node_next;

  for (unsigned int i = 0; i < ATABLE_SIZE; ++i)
  {
    DLINK_FOREACH_SAFE(node, node_next, atable[i].head)
    {
      struct AddressRec *arec = node->data;

      if (arec->conf->until == 0 || arec->conf->until > event_base->time.sec_real)
        continue;

      switch (arec->type)
      {
        case CONF_KLINE:
        case CONF_DLINE:
          hostmask_send_expiration(arec);

          dlinkDelete(&arec->node, &atable[i]);
          conf_free(arec->conf);
          xfree(arec);
          break;
        default: break;
      }
    }
  }
}

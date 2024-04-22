/*
 * include/reslib.h (C)opyright 1992 Darren Reed.
 *
 */
#ifndef INCLUDED_reslib_h
#define INCLUDED_reslib_h

#include "config.h"  /* WORDS_BIGENDIAN */
#include "address.h"


/*%
 * Inline versions of get/put short/long.  Pointer is advanced.
 */
#define RESLIB_NS_GET16(s, cp) do { \
	const unsigned char *t_cp = (const unsigned char *)(cp); \
	(s) = ((uint16_t)t_cp[0] << 8) \
	    | ((uint16_t)t_cp[1]) \
	    ; \
	(cp) += NS_INT16SZ; \
} while (0)

#define RESLIB_NS_GET32(l, cp) do { \
	const unsigned char *t_cp = (const unsigned char *)(cp); \
	(l) = ((uint32_t)t_cp[0] << 24) \
	    | ((uint32_t)t_cp[1] << 16) \
	    | ((uint32_t)t_cp[2] << 8) \
	    | ((uint32_t)t_cp[3]) \
	    ; \
	(cp) += NS_INT32SZ; \
} while (0)

#define RESLIB_NS_PUT16(s, cp) do { \
	uint16_t t_s = (uint16_t)(s); \
	unsigned char *t_cp = (unsigned char *)(cp); \
	*t_cp++ = t_s >> 8; \
	*t_cp   = t_s; \
	(cp) += NS_INT16SZ; \
} while (0)

#define RESLIB_NS_PUT32(l, cp) do { \
	uint32_t t_l = (uint32_t)(l); \
	unsigned char *t_cp = (unsigned char *)(cp); \
	*t_cp++ = t_l >> 24; \
	*t_cp++ = t_l >> 16; \
	*t_cp++ = t_l >> 8; \
	*t_cp   = t_l; \
	(cp) += NS_INT32SZ; \
} while (0)

/** Maximum number of nameservers in /etc/resolv.conf we care about */
#define RESLIB_MAXNS 8

/*
 * From RFC 1035:
 *
 * Domain names in messages are expressed in terms of a sequence of labels.
 * Each label is represented as a one octet length field followed by that
 * number of octets.  Since every domain name ends with the null label of
 * the root, a domain name is terminated by a length byte of zero.  The
 * high order two bits of every length octet must be zero, and the
 * remaining six bits of the length field limit the label to 63 octets or
 * less.
 *
 * To simplify implementations, the total length of a domain name (i.e.,
 * label octets and label length octets) is restricted to 255 octets or
 * less.
 */
#define RFC1035_MAX_DOMAIN_LENGTH 255


/* Here we define some values lifted from nameser.h */
#define NS_INT16SZ 2  /**< #/bytes of data in a uint16_t */
#define NS_IN6ADDRSZ 16  /**< IPv6 T_AAAA */
#define NS_INADDRSZ 4  /**< IPv4 T_A */
#define NS_INT32SZ 4  /**< #/bytes of data in a uint32_t */
#define NS_CMPRSFLGS 0xc0  /**< Flag bits indicating name compression. */
#define NS_MAXCDNAME 255  /**< maximum compressed domain name */
#define QUERY 0
#define NO_ERRORS 0
#define SERVFAIL 2  /**< Server failure. */
#define NXDOMAIN 3  /**< Name error. */
#define T_A 1
#define T_AAAA 28
#define T_PTR 12
#define T_CNAME 5
#define C_IN 1
#define QFIXEDSZ 4  /**< #/bytes of fixed data in query */
#define HFIXEDSZ 12  /**< #/bytes of fixed data in header */

/*%
 * Structure for query header.  The order of the fields is machine- and
 * compiler-dependent, depending on the byte/bit order and the layout
 * of bit fields.  We use bit fields only in int variables, as this
 * is all ANSI requires.  This requires a somewhat confusing rearrangement.
 */
typedef struct
{
  unsigned  id : 16;  /**< Query identification number */
#ifdef WORDS_BIGENDIAN
  /* Fields in third byte */
  unsigned  qr : 1;  /**< Response flag */
  unsigned  opcode : 4;  /**< Purpose of message */
  unsigned  aa : 1;  /**< Authoritive answer */
  unsigned  tc : 1;  /**< Truncated message */
  unsigned  rd : 1;  /**< Recursion desired */

  /* Fields in fourth byte */
  unsigned  ra : 1;  /**< Recursion available */
  unsigned  unused : 1;  /**< Unused bits (MBZ as of 4.9.3a3) */
  unsigned  ad : 1;  /**< Authentic data from named */
  unsigned  cd : 1;  /**< Checking disabled by resolver */
  unsigned  rcode : 4;  /**< Response code */
#else
  /* Fields in third byte */
  unsigned  rd : 1;  /**< Recursion desired */
  unsigned  tc : 1;  /**< Truncated message */
  unsigned  aa : 1;  /**< Authoritive answer */
  unsigned  opcode : 4;  /**< Purpose of message */
  unsigned  qr : 1;  /**< Response flag */

  /* Fields in fourth byte */
  unsigned  rcode : 4;  /**< Response code */
  unsigned  cd : 1;  /**< Checking disabled by resolver */
  unsigned  ad : 1;  /**< Authentic data from named */
  unsigned  unused : 1;  /**< Unused bits (MBZ as of 4.9.3a3) */
  unsigned  ra : 1;  /**< Recursion available */
#endif
  /* Remaining bytes */
  unsigned  qdcount : 16;  /**< Number of question entries */
  unsigned  ancount : 16;  /**< Number of answer entries */
  unsigned  nscount : 16;  /**< Number of authority entries */
  unsigned  arcount : 16;  /**< Number of resource entries */
} HEADER;

extern struct io_addr reslib_nsaddr_list[];
extern unsigned int reslib_nscount;
extern void reslib_res_init(void);
extern int reslib_dn_expand(const unsigned char *, const unsigned char *, const unsigned char *, char *, int);
extern int reslib_dn_skipname(const unsigned char *, const unsigned char *);
extern unsigned int reslib_ns_get16(const unsigned char *);
extern unsigned long reslib_ns_get32(const unsigned char *);
extern int reslib_res_mkquery(const char *, int class, int, unsigned char *, int);
#endif  /* INCLUDED_reslib_h */

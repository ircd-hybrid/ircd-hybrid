/*
 * include/irc_reslib.h (C)opyright 1992 Darren Reed.
 *
 * $Id$
 */
#ifndef INCLUDED_ircdreslib_h
#define INCLUDED_ircdreslib_h

/*
 * Inline versions of get/put short/long.  Pointer is advanced.
 */
#define IRC_NS_GET16(s, cp) { \
	const unsigned char *t_cp = (const unsigned char *)(cp); \
	(s) = ((uint16_t)t_cp[0] << 8) \
	    | ((uint16_t)t_cp[1]) \
	    ; \
	(cp) += NS_INT16SZ; \
}

#define IRC_NS_GET32(l, cp) { \
	const unsigned char *t_cp = (const unsigned char *)(cp); \
	(l) = ((uint32_t)t_cp[0] << 24) \
	    | ((uint32_t)t_cp[1] << 16) \
	    | ((uint32_t)t_cp[2] << 8) \
	    | ((uint32_t)t_cp[3]) \
	    ; \
	(cp) += NS_INT32SZ; \
}

#define IRC_NS_PUT16(s, cp) { \
	uint16_t t_s = (uint16_t)(s); \
	unsigned char *t_cp = (unsigned char *)(cp); \
	*t_cp++ = t_s >> 8; \
	*t_cp   = t_s; \
	(cp) += NS_INT16SZ; \
}

#define IRC_NS_PUT32(l, cp) { \
	uint32_t t_l = (uint32_t)(l); \
	unsigned char *t_cp = (unsigned char *)(cp); \
	*t_cp++ = t_l >> 24; \
	*t_cp++ = t_l >> 16; \
	*t_cp++ = t_l >> 8; \
	*t_cp   = t_l; \
	(cp) += NS_INT32SZ; \
}

extern struct irc_ssaddr irc_nsaddr_list[];
extern unsigned int irc_nscount;
extern void irc_res_init(void);
extern int irc_dn_expand(const unsigned char *msg, const unsigned char *eom, const unsigned char *src, char *dst, int dstsiz);
extern int irc_dn_skipname(const unsigned char *ptr, const unsigned char *eom);
extern unsigned int irc_ns_get16(const unsigned char *src);
extern unsigned long irc_ns_get32(const unsigned char *src);
extern void irc_ns_put16(unsigned int src, unsigned char *dst);
extern void irc_ns_put32(unsigned long src, unsigned char *dst);
extern int irc_res_mkquery(const char *dname, int class, int type, unsigned char *buf, int buflen);
#endif /* INCLUDED_res_h */


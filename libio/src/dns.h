/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file dns.h
 * @brief DNS wire-format encoding and decoding interfaces.
 */

#ifndef INCLUDED_dns_h
#define INCLUDED_dns_h
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum
{
  DNS_HEADER_WIRE_SIZE = 12,
  DNS_LABEL_MAX_LENGTH = 63,
  DNS_NAME_WIRE_MAX_LENGTH = 255,

  /*
   * A 255-octet wire name can contain at most 250 data octets across four
   * labels. Escaping every data octet as "\\DDD" therefore requires at most
   * 1000 characters plus three label separators.
   */
  DNS_NAME_TEXT_MAX_LENGTH = 1003,
  DNS_NAME_TEXT_CAPACITY = DNS_NAME_TEXT_MAX_LENGTH + 1,

  DNS_QUESTION_FIXED_WIRE_SIZE = 4,
  DNS_QUERY_WIRE_MAX_LENGTH =
    DNS_HEADER_WIRE_SIZE + DNS_NAME_WIRE_MAX_LENGTH + DNS_QUESTION_FIXED_WIRE_SIZE,

  DNS_TYPE_A = 1,
  DNS_TYPE_CNAME = 5,
  DNS_TYPE_PTR = 12,
  DNS_TYPE_AAAA = 28,
  DNS_TYPE_OPT = 41,

  DNS_CLASS_IN = 1,

  DNS_OPCODE_QUERY = 0,

  DNS_RESPONSE_CODE_NOERROR = 0,
  DNS_RESPONSE_CODE_FORMERR = 1,
  DNS_RESPONSE_CODE_SERVFAIL = 2,
  DNS_RESPONSE_CODE_NXDOMAIN = 3,
  DNS_RESPONSE_CODE_NOTIMP = 4,
  DNS_RESPONSE_CODE_REFUSED = 5,

  DNS_HEADER_FLAG_RESPONSE = 0x8000,
  DNS_HEADER_OPCODE_MASK = 0x7800,
  DNS_HEADER_OPCODE_SHIFT = 11,
  DNS_HEADER_FLAG_AUTHORITATIVE_ANSWER = 0x0400,
  DNS_HEADER_FLAG_TRUNCATED = 0x0200,
  DNS_HEADER_FLAG_RECURSION_DESIRED = 0x0100,
  DNS_HEADER_FLAG_RECURSION_AVAILABLE = 0x0080,
  DNS_HEADER_FLAG_RESERVED = 0x0040,
  DNS_HEADER_FLAG_AUTHENTIC_DATA = 0x0020,
  DNS_HEADER_FLAG_CHECKING_DISABLED = 0x0010,
  DNS_HEADER_RESPONSE_CODE_MASK = 0x000f
};

/** Borrowed immutable view of one complete DNS message. */
struct dns_message_view
{
  const unsigned char *data;
  size_t length;
};

/** Byte range relative to the beginning of a DNS message. */
struct dns_span
{
  size_t offset;
  size_t length;
};

/** Sequential decoder cursor over a borrowed DNS message. */
struct dns_reader
{
  struct dns_message_view packet;
  size_t offset;
};

/** DNS header fields in host byte order. */
struct dns_header
{
  uint16_t transaction_id;
  uint16_t flags;
  uint16_t question_count;
  uint16_t answer_count;
  uint16_t authority_count;
  uint16_t additional_count;
};

/** Decoded DNS question borrowing its encoded QNAME from the packet. */
struct dns_question
{
  struct dns_span name;
  uint16_t type;
  uint16_t class;
};

/** Decoded DNS resource record borrowing NAME and RDATA from the packet. */
struct dns_record
{
  struct dns_span name;
  uint16_t type;
  uint16_t class;
  uint32_t ttl;
  struct dns_span rdata;
};

/** Description of a complete single-question DNS query. */
struct dns_query
{
  const char *name;
  uint16_t transaction_id;
  uint16_t type;
  uint16_t class;
  bool recursion_desired;
};

static inline bool
dns_header_is_response(const struct dns_header *header)
{
  assert(header);
  return (header->flags & DNS_HEADER_FLAG_RESPONSE) != 0;
}

static inline bool
dns_header_is_authoritative_answer(const struct dns_header *header)
{
  assert(header);
  return (header->flags & DNS_HEADER_FLAG_AUTHORITATIVE_ANSWER) != 0;
}

static inline bool
dns_header_is_truncated(const struct dns_header *header)
{
  assert(header);
  return (header->flags & DNS_HEADER_FLAG_TRUNCATED) != 0;
}

static inline bool
dns_header_recursion_desired(const struct dns_header *header)
{
  assert(header);
  return (header->flags & DNS_HEADER_FLAG_RECURSION_DESIRED) != 0;
}

static inline bool
dns_header_recursion_available(const struct dns_header *header)
{
  assert(header);
  return (header->flags & DNS_HEADER_FLAG_RECURSION_AVAILABLE) != 0;
}

static inline bool
dns_header_authentic_data(const struct dns_header *header)
{
  assert(header);
  return (header->flags & DNS_HEADER_FLAG_AUTHENTIC_DATA) != 0;
}

static inline bool
dns_header_checking_disabled(const struct dns_header *header)
{
  assert(header);
  return (header->flags & DNS_HEADER_FLAG_CHECKING_DISABLED) != 0;
}

static inline uint8_t
dns_header_get_opcode(const struct dns_header *header)
{
  assert(header);
  return (uint8_t)((header->flags & DNS_HEADER_OPCODE_MASK) >> DNS_HEADER_OPCODE_SHIFT);
}

static inline uint8_t
dns_header_get_response_code(const struct dns_header *header)
{
  assert(header);
  return (uint8_t)(header->flags & DNS_HEADER_RESPONSE_CODE_MASK);
}

extern void dns_reader_init(struct dns_reader *, const void *, size_t);
extern bool dns_reader_read_header(struct dns_reader *, struct dns_header *);
extern bool dns_reader_read_question(struct dns_reader *, struct dns_question *);
extern bool dns_reader_read_record(struct dns_reader *, struct dns_record *);
extern bool dns_name_decode(const struct dns_message_view *, struct dns_span, char *, size_t, size_t *);
extern bool dns_name_equal_text(const struct dns_message_view *, struct dns_span, const char *);
extern bool dns_query_encode(const struct dns_query *, void *, size_t, size_t *);
#endif  /* INCLUDED_dns_h */


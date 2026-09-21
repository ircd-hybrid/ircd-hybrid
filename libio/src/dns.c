/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file dns.c
 * @brief DNS wire-format encoding and decoding.
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "dns.h"

_Static_assert(CHAR_BIT == 8, "DNS handling requires 8-bit bytes");
_Static_assert(DNS_LABEL_MAX_LENGTH == 0x3f,
               "DNS_LABEL_MAX_LENGTH must match the DNS label format");
_Static_assert(DNS_NAME_WIRE_MAX_LENGTH == 255,
               "DNS_NAME_WIRE_MAX_LENGTH must include the root label");
_Static_assert(DNS_NAME_TEXT_MAX_LENGTH == 1003,
               "DNS_NAME_TEXT_MAX_LENGTH must match the reversible text format");
_Static_assert(DNS_QUERY_WIRE_MAX_LENGTH ==
               DNS_HEADER_WIRE_SIZE + DNS_NAME_WIRE_MAX_LENGTH + DNS_QUESTION_FIXED_WIRE_SIZE,
               "DNS_QUERY_WIRE_MAX_LENGTH is inconsistent");

enum
{
  DNS_LABEL_TYPE_MASK = 0xc0,
  DNS_LABEL_TYPE_ORDINARY = 0x00,
  DNS_LABEL_TYPE_POINTER = 0xc0,
  DNS_POINTER_OFFSET_MASK = 0x3fff,

  /*
   * Bound all pointer hops per name, including those separated by labels.
   * Pointer-only hops do not increase the expanded name length.
   */
  DNS_NAME_MAX_POINTER_HOPS = 256,
};

struct dns_cursor
{
  struct dns_message_view packet;
  size_t offset;
};

struct dns_writer
{
  unsigned char *data;
  size_t capacity;
  size_t offset;
};

static bool
_dns_packet_view_is_valid(const struct dns_message_view *packet)
{
  return packet && (packet->data || packet->length == 0);
}

static bool
_dns_packet_view_contains_span(const struct dns_message_view *packet, struct dns_span span)
{
  return _dns_packet_view_is_valid(packet) &&
         span.offset <= packet->length &&
         span.length <= packet->length - span.offset;
}

static bool
_dns_cursor_is_valid(const struct dns_cursor *cursor)
{
  return cursor && _dns_packet_view_is_valid(&cursor->packet) &&
         cursor->offset <= cursor->packet.length;
}

static bool
_dns_cursor_has_bytes(const struct dns_cursor *cursor, size_t length)
{
  return _dns_cursor_is_valid(cursor) && length <= cursor->packet.length - cursor->offset;
}

static bool
_dns_cursor_read_uint8(struct dns_cursor *cursor, uint8_t *value)
{
  assert(_dns_cursor_is_valid(cursor));
  assert(value);

  if (!_dns_cursor_has_bytes(cursor, 1))
    return false;

  const uint8_t decoded = cursor->packet.data[cursor->offset];

  ++cursor->offset;
  *value = decoded;
  return true;
}

static bool
_dns_cursor_read_uint16(struct dns_cursor *cursor, uint16_t *value)
{
  assert(_dns_cursor_is_valid(cursor));
  assert(value);

  if (!_dns_cursor_has_bytes(cursor, 2))
    return false;

  const unsigned char *const data = cursor->packet.data + cursor->offset;
  const uint16_t decoded = (uint16_t)(((uint16_t)data[0] << 8) | (uint16_t)data[1]);

  cursor->offset += 2;
  *value = decoded;
  return true;
}

static bool
_dns_cursor_read_uint32(struct dns_cursor *cursor, uint32_t *value)
{
  assert(_dns_cursor_is_valid(cursor));
  assert(value);

  if (!_dns_cursor_has_bytes(cursor, 4))
    return false;

  const unsigned char *const data = cursor->packet.data + cursor->offset;
  const uint32_t decoded = ((uint32_t)data[0] << 24) |
                           ((uint32_t)data[1] << 16) |
                           ((uint32_t)data[2] << 8) |
                           (uint32_t)data[3];

  cursor->offset += 4;
  *value = decoded;
  return true;
}

static bool
_dns_cursor_read_span(struct dns_cursor *cursor, size_t length, struct dns_span *span)
{
  assert(_dns_cursor_is_valid(cursor));
  assert(span);

  if (!_dns_cursor_has_bytes(cursor, length))
    return false;

  const struct dns_span decoded =
  {
    .offset = cursor->offset,
    .length = length
  };

  cursor->offset += length;
  *span = decoded;
  return true;
}

static bool
_dns_cursor_skip_bytes(struct dns_cursor *cursor, size_t length)
{
  assert(_dns_cursor_is_valid(cursor));

  if (!_dns_cursor_has_bytes(cursor, length))
    return false;

  cursor->offset += length;
  return true;
}

static bool
_dns_writer_is_valid(const struct dns_writer *writer)
{
  return writer && writer->data && writer->offset <= writer->capacity;
}

static bool
_dns_writer_has_space(const struct dns_writer *writer, size_t length)
{
  return _dns_writer_is_valid(writer) && length <= writer->capacity - writer->offset;
}

static bool
_dns_writer_write_uint8(struct dns_writer *writer, uint8_t value)
{
  assert(_dns_writer_is_valid(writer));

  if (!_dns_writer_has_space(writer, 1))
    return false;

  writer->data[writer->offset++] = value;
  return true;
}

static bool
_dns_writer_write_uint16(struct dns_writer *writer, uint16_t value)
{
  assert(_dns_writer_is_valid(writer));

  if (!_dns_writer_has_space(writer, 2))
    return false;

  writer->data[writer->offset++] = (unsigned char)(value >> 8);
  writer->data[writer->offset++] = (unsigned char)value;
  return true;
}

static bool
_dns_name_text_octet_is_literal(unsigned char octet)
{
  return octet >= 0x21 && octet <= 0x7e && octet != '.' && octet != '\\';
}

static size_t
_dns_name_text_octet_length(unsigned char octet)
{
  if (_dns_name_text_octet_is_literal(octet))
    return 1;

  if (octet == '.' || octet == '\\')
    return 2;

  return 4;
}

static size_t
_dns_name_text_write_octet(char *output, unsigned char octet)
{
  assert(output);

  if (_dns_name_text_octet_is_literal(octet))
  {
    output[0] = (char)octet;
    return 1;
  }

  output[0] = '\\';

  if (octet == '.' || octet == '\\')
  {
    output[1] = (char)octet;
    return 2;
  }

  output[1] = (char)('0' + octet / 100);
  output[2] = (char)('0' + (octet / 10) % 10);
  output[3] = (char)('0' + octet % 10);
  return 4;
}

static bool
_dns_name_parse_wire(const struct dns_message_view *packet, struct dns_span encoded_name,
                     char *output, size_t *output_length)
{
  assert(_dns_packet_view_is_valid(packet));
  assert(output_length);

  if (!_dns_packet_view_contains_span(packet, encoded_name) ||
      encoded_name.length == 0 ||
      encoded_name.offset < DNS_HEADER_WIRE_SIZE)
    return false;

  const size_t encoded_end = encoded_name.offset + encoded_name.length;
  size_t offset = encoded_name.offset;
  size_t read_limit = encoded_end;
  size_t expanded_wire_length = 0;
  size_t text_length = 0;
  size_t pointer_hops = 0;
  bool has_label = false;

  for (;;)
  {
    if (offset >= read_limit)
      return false;

    const size_t label_offset = offset;
    const unsigned char label_octet = packet->data[offset++];
    const unsigned char label_type = label_octet & DNS_LABEL_TYPE_MASK;

    if (label_type == DNS_LABEL_TYPE_ORDINARY)
    {
      const size_t label_length = label_octet;
      if (label_length == 0)
      {
        if (pointer_hops == 0 && offset != encoded_end)
          return false;

        if (expanded_wire_length >= DNS_NAME_WIRE_MAX_LENGTH)
          return false;

        ++expanded_wire_length;

        assert(expanded_wire_length <= DNS_NAME_WIRE_MAX_LENGTH);
        assert(text_length <= DNS_NAME_TEXT_MAX_LENGTH);

        *output_length = text_length;
        return true;
      }

      if (label_length > DNS_LABEL_MAX_LENGTH || label_length > read_limit - offset)
        return false;

      if (expanded_wire_length > DNS_NAME_WIRE_MAX_LENGTH - (label_length + 1))
        return false;

      expanded_wire_length += label_length + 1;

      if (has_label)
      {
        if (text_length == DNS_NAME_TEXT_MAX_LENGTH)
          return false;

        if (output)
          output[text_length] = '.';

        ++text_length;
      }

      for (size_t i = 0; i < label_length; ++i)
      {
        const unsigned char octet = packet->data[offset + i];

        const size_t octet_length = _dns_name_text_octet_length(octet);
        if (octet_length > DNS_NAME_TEXT_MAX_LENGTH - text_length)
          return false;

        if (output)
          text_length += _dns_name_text_write_octet(output + text_length, octet);
        else
          text_length += octet_length;
      }

      offset += label_length;
      has_label = true;
      continue;
    }

    if (label_type != DNS_LABEL_TYPE_POINTER || offset >= read_limit)
      return false;

    const size_t target_offset =
      (((size_t)label_octet << 8) | packet->data[offset++]) & DNS_POINTER_OFFSET_MASK;

    if ((pointer_hops == 0 && offset != encoded_end) ||
        target_offset < DNS_HEADER_WIRE_SIZE ||
        target_offset >= label_offset ||
        target_offset >= packet->length)
      return false;


    if (pointer_hops == DNS_NAME_MAX_POINTER_HOPS)
      return false;

    ++pointer_hops;
    read_limit = label_offset;
    offset = target_offset;
  }
}

static bool
_dns_cursor_read_name_span(struct dns_cursor *cursor, struct dns_span *span)
{
  assert(_dns_cursor_is_valid(cursor));
  assert(span);

  struct dns_cursor next = *cursor;
  const size_t name_offset = next.offset;

  for (;;)
  {
    uint8_t label_octet;
    if (!_dns_cursor_read_uint8(&next, &label_octet))
      return false;

    const unsigned char label_type = label_octet & DNS_LABEL_TYPE_MASK;

    if (label_type == DNS_LABEL_TYPE_ORDINARY)
    {
      if (label_octet == 0)
        break;

      if (!_dns_cursor_skip_bytes(&next, label_octet))
        return false;

      if (next.offset - name_offset >= DNS_NAME_WIRE_MAX_LENGTH)
        return false;

      continue;
    }

    if (label_type != DNS_LABEL_TYPE_POINTER || !_dns_cursor_skip_bytes(&next, 1))
      return false;

    break;
  }

  const struct dns_span decoded =
  {
    .offset = name_offset,
    .length = next.offset - name_offset
  };

  size_t text_length;
  if (!_dns_name_parse_wire(&cursor->packet, decoded, NULL, &text_length))
    return false;

  *cursor = next;
  *span = decoded;
  return true;
}

static bool
_dns_cursor_read_header(struct dns_cursor *cursor, struct dns_header *header)
{
  assert(_dns_cursor_is_valid(cursor));
  assert(header);

  struct dns_cursor next = *cursor;
  struct dns_header decoded;

  if (!_dns_cursor_read_uint16(&next, &decoded.transaction_id) ||
      !_dns_cursor_read_uint16(&next, &decoded.flags) ||
      !_dns_cursor_read_uint16(&next, &decoded.question_count) ||
      !_dns_cursor_read_uint16(&next, &decoded.answer_count) ||
      !_dns_cursor_read_uint16(&next, &decoded.authority_count) ||
      !_dns_cursor_read_uint16(&next, &decoded.additional_count))
    return false;

  if (decoded.flags & DNS_HEADER_FLAG_RESERVED)
    return false;

  *cursor = next;
  *header = decoded;
  return true;
}

static bool
_dns_cursor_read_question(struct dns_cursor *cursor, struct dns_question *question)
{
  assert(_dns_cursor_is_valid(cursor));
  assert(question);

  struct dns_cursor next = *cursor;
  struct dns_question decoded;

  if (!_dns_cursor_read_name_span(&next, &decoded.name) ||
      !_dns_cursor_read_uint16(&next, &decoded.type) ||
      !_dns_cursor_read_uint16(&next, &decoded.class))
    return false;

  *cursor = next;
  *question = decoded;
  return true;
}

static bool
_dns_cursor_read_record(struct dns_cursor *cursor, struct dns_record *record)
{
  assert(_dns_cursor_is_valid(cursor));
  assert(record);

  struct dns_cursor next = *cursor;
  struct dns_record decoded;
  uint16_t rdata_length;

  if (!_dns_cursor_read_name_span(&next, &decoded.name) ||
      !_dns_cursor_read_uint16(&next, &decoded.type) ||
      !_dns_cursor_read_uint16(&next, &decoded.class) ||
      !_dns_cursor_read_uint32(&next, &decoded.ttl) ||
      !_dns_cursor_read_uint16(&next, &rdata_length) ||
      !_dns_cursor_read_span(&next, rdata_length, &decoded.rdata))
    return false;

  *cursor = next;
  *record = decoded;
  return true;
}

static bool
_dns_ascii_is_digit(unsigned char character)
{
  return character >= '0' && character <= '9';
}

static unsigned char
_dns_ascii_fold(unsigned char character)
{
  if (character >= 'A' && character <= 'Z')
    return (unsigned char)(character + ('a' - 'A'));

  return character;
}

static bool
_dns_name_text_read_octet(const char **cursor, unsigned char *octet)
{
  assert(cursor);
  assert(*cursor);
  assert(octet);

  const unsigned char character = (unsigned char)**cursor;
  if (character == '\0' || character == '.')
    return false;

  if (character != '\\')
  {
    if (!_dns_name_text_octet_is_literal(character))
      return false;

    *octet = character;
    ++*cursor;
    return true;
  }

  const char *escaped = *cursor + 1;
  const unsigned char first = (unsigned char)escaped[0];
  if (first == '\0')
    return false;

  if (first == '.' || first == '\\')
  {
    *octet = first;
    *cursor = escaped + 1;
    return true;
  }

  if (!_dns_ascii_is_digit(first))
    return false;

  ++escaped;
  const unsigned char second = (unsigned char)*escaped;
  if (!_dns_ascii_is_digit(second))
    return false;

  ++escaped;
  const unsigned char third = (unsigned char)*escaped;
  if (!_dns_ascii_is_digit(third))
    return false;

  const unsigned int value = (unsigned int)(first - '0') * 100 +
                             (unsigned int)(second - '0') * 10 +
                             (unsigned int)(third - '0');
  if (value > UINT8_MAX)
    return false;

  *octet = (unsigned char)value;
  *cursor = escaped + 1;
  return true;
}

static bool
_dns_name_text_read_label(const char **cursor, unsigned char *label, size_t *label_length, bool *is_last)
{
  assert(cursor);
  assert(*cursor);
  assert(label);
  assert(label_length);
  assert(is_last);

  size_t length = 0;

  while (**cursor && **cursor != '.')
  {
    unsigned char octet;
    if (!_dns_name_text_read_octet(cursor, &octet) || length == DNS_LABEL_MAX_LENGTH)
      return false;

    label[length++] = octet;
  }

  if (length == 0)
    return false;

  bool label_is_last = true;
  if (**cursor == '.')
  {
    ++*cursor;
    label_is_last = **cursor == '\0';
  }

  *label_length = length;
  *is_last = label_is_last;
  return true;
}

static bool
_dns_name_text_equal(const char *first, const char *second)
{
  assert(first);
  assert(second);

  const bool first_is_root =
    first[0] == '\0' || (first[0] == '.' && first[1] == '\0');
  const bool second_is_root =
    second[0] == '\0' || (second[0] == '.' && second[1] == '\0');

  if (first_is_root || second_is_root)
    return first_is_root && second_is_root;

  size_t wire_length = 1;

  for (;;)
  {
    unsigned char first_label[DNS_LABEL_MAX_LENGTH];
    unsigned char second_label[DNS_LABEL_MAX_LENGTH];
    size_t first_length;
    size_t second_length;
    bool first_is_last;
    bool second_is_last;

    if (!_dns_name_text_read_label(&first, first_label, &first_length, &first_is_last) ||
        !_dns_name_text_read_label(&second, second_label, &second_length, &second_is_last))
      return false;

    if (first_length != second_length || first_is_last != second_is_last)
      return false;

    if (wire_length > DNS_NAME_WIRE_MAX_LENGTH - (first_length + 1))
      return false;

    wire_length += first_length + 1;

    for (size_t i = 0; i < first_length; ++i)
      if (_dns_ascii_fold(first_label[i]) != _dns_ascii_fold(second_label[i]))
        return false;

    if (first_is_last)
      return true;
  }
}

static bool
_dns_writer_write_name(struct dns_writer *writer, const char *name)
{
  assert(_dns_writer_is_valid(writer));
  assert(name);

  const size_t name_offset = writer->offset;

  if (name[0] == '\0' || (name[0] == '.' && name[1] == '\0'))
    return _dns_writer_write_uint8(writer, 0);

  const char *cursor = name;

  for (;;)
  {
    const size_t label_length_offset = writer->offset;
    if (!_dns_writer_write_uint8(writer, 0))
      return false;

    size_t label_length = 0;
    while (*cursor && *cursor != '.')
    {
      unsigned char octet;
      if (!_dns_name_text_read_octet(&cursor, &octet) || label_length == DNS_LABEL_MAX_LENGTH ||
          !_dns_writer_write_uint8(writer, octet))
        return false;

      ++label_length;
    }

    if (label_length == 0)
      return false;

    assert(label_length <= DNS_LABEL_MAX_LENGTH);
    writer->data[label_length_offset] = (unsigned char)label_length;

    if (*cursor == '\0')
      break;

    ++cursor;
    if (*cursor == '\0')
      break;
  }

  if (!_dns_writer_write_uint8(writer, 0))
    return false;

  return writer->offset - name_offset <= DNS_NAME_WIRE_MAX_LENGTH;
}

void
dns_reader_init(struct dns_reader *reader, const void *packet, size_t packet_length)
{
  assert(reader);
  assert(packet || packet_length == 0);

  reader->packet = (struct dns_message_view)
  {
    .data = packet,
    .length = packet_length
  };

  reader->offset = 0;
}

bool
dns_reader_read_header(struct dns_reader *reader, struct dns_header *header)
{
  assert(reader);
  assert(_dns_packet_view_is_valid(&reader->packet));
  assert(reader->offset == 0);
  assert(header);

  struct dns_cursor cursor =
  {
    .packet = reader->packet,
    .offset = reader->offset
  };

  struct dns_header decoded;
  if (!_dns_cursor_read_header(&cursor, &decoded))
    return false;

  reader->offset = cursor.offset;
  *header = decoded;
  return true;
}

bool
dns_reader_read_question(struct dns_reader *reader, struct dns_question *question)
{
  assert(reader);
  assert(_dns_packet_view_is_valid(&reader->packet));
  assert(reader->offset >= DNS_HEADER_WIRE_SIZE);
  assert(reader->offset <= reader->packet.length);
  assert(question);

  struct dns_cursor cursor =
  {
    .packet = reader->packet,
    .offset = reader->offset
  };

  struct dns_question decoded;
  if (!_dns_cursor_read_question(&cursor, &decoded))
    return false;

  reader->offset = cursor.offset;
  *question = decoded;
  return true;
}

bool
dns_reader_read_record(struct dns_reader *reader, struct dns_record *record)
{
  assert(reader);
  assert(_dns_packet_view_is_valid(&reader->packet));
  assert(reader->offset >= DNS_HEADER_WIRE_SIZE);
  assert(reader->offset <= reader->packet.length);
  assert(record);

  struct dns_cursor cursor =
  {
    .packet = reader->packet,
    .offset = reader->offset
  };

  struct dns_record decoded;
  if (!_dns_cursor_read_record(&cursor, &decoded))
    return false;

  reader->offset = cursor.offset;
  *record = decoded;
  return true;
}

bool
dns_name_decode(const struct dns_message_view *packet, struct dns_span encoded_name,
                char *name, size_t name_capacity, size_t *name_length)
{
  assert(_dns_packet_view_is_valid(packet));
  assert(name);
  assert(name_length);

  char decoded[DNS_NAME_TEXT_CAPACITY];
  size_t decoded_length;

  if (!_dns_name_parse_wire(packet, encoded_name, decoded, &decoded_length))
    return false;

  assert(decoded_length <= DNS_NAME_TEXT_MAX_LENGTH);

  if (decoded_length >= name_capacity)
    return false;

  decoded[decoded_length] = '\0';
  memcpy(name, decoded, decoded_length + 1);
  *name_length = decoded_length;
  return true;
}

bool
dns_name_equal_text(const struct dns_message_view *packet, struct dns_span encoded_name, const char *name)
{
  assert(_dns_packet_view_is_valid(packet));
  assert(name);

  char decoded[DNS_NAME_TEXT_CAPACITY];
  size_t decoded_length;

  if (!_dns_name_parse_wire(packet, encoded_name, decoded, &decoded_length))
    return false;

  assert(decoded_length <= DNS_NAME_TEXT_MAX_LENGTH);
  decoded[decoded_length] = '\0';

  return _dns_name_text_equal(decoded, name);
}

bool
dns_query_encode(const struct dns_query *query, void *packet, size_t packet_capacity, size_t *packet_length)
{
  assert(query);
  assert(query->name);
  assert(packet);
  assert(packet_length);

  unsigned char encoded[DNS_QUERY_WIRE_MAX_LENGTH];
  struct dns_writer writer =
  {
    .data = encoded,
    .capacity = sizeof(encoded),
    .offset = 0
  };

  const uint16_t flags = query->recursion_desired ? DNS_HEADER_FLAG_RECURSION_DESIRED : 0;

  if (!_dns_writer_write_uint16(&writer, query->transaction_id) ||
      !_dns_writer_write_uint16(&writer, flags) ||
      !_dns_writer_write_uint16(&writer, 1) ||
      !_dns_writer_write_uint16(&writer, 0) ||
      !_dns_writer_write_uint16(&writer, 0) ||
      !_dns_writer_write_uint16(&writer, 0) ||
      !_dns_writer_write_name(&writer, query->name) ||
      !_dns_writer_write_uint16(&writer, query->type) ||
      !_dns_writer_write_uint16(&writer, query->class))
    return false;

  assert(writer.offset <= sizeof(encoded));

  if (writer.offset > packet_capacity)
    return false;

  memcpy(packet, encoded, writer.offset);
  *packet_length = writer.offset;
  return true;
}

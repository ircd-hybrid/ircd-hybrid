/*
 * SPDX-FileCopyrightText: 2019 Shivaram Lingamneni
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: MIT
 */

/**
 * @file cloak.c
 * @brief Implements hostname cloaking functionality.
 *
 * This file contains the implementation of a hostname cloaking module designed to obfuscate IP addresses
 * by generating unique and cryptographically secure cloaked hostnames. The cloaking process involves applying
 * CIDR masking, computing a Message Authentication Code (MAC) using SHA3, and encoding the result in base32,
 * followed by appending a configurable suffix to the cloaked hostname.
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "base32.h"
#include "io_string.h"
#include "memory.h"
#include "sha3.h"
#include "cloak.h"
#include "ircd_defs.h"

/**
 * @struct cloak_config
 * @brief Configuration structure for hostname cloaking.
 *
 * This structure holds the configuration parameters for the hostname cloaking functionality.
 * It includes flags for enabling/disabling cloaking, CIDR lengths for IPv4 and IPv6,
 * the number of bits for MAC computation, secret key, and suffix for the cloaked hostname.
 */
struct cloak_config
{
  bool enabled;  /**< Flag indicating whether cloaking is enabled or not. */
  size_t cidr_len_ipv4;  /**< CIDR length for IPv4 addresses. */
  size_t cidr_len_ipv6;  /**< CIDR length for IPv6 addresses. */
  size_t num_bits;  /**< Number of bits for the MAC computation. */
  size_t num_bytes;  /**< Number of bytes derived from num_bits. */
  char *secret;  /**< Secret key used in the MAC computation. */
  size_t secret_len;  /**< Length of the secret key. */
  char *suffix;  /**< Suffix appended to the cloaked hostname. */
  size_t suffix_len;  /**< Length of the suffix. */
};

/**
 * @var config
 * @brief Configuration structure pointer for hostname cloaking.
 *
 * This static variable holds a pointer to the configuration structure used
 * in the hostname cloaking module.
 */
static struct cloak_config *config;

/**
 * @brief Enable cloaking functionality.
 *
 * This function sets the cloaking enabled flag to true, allowing the system to perform hostname cloaking.
 * Call this function to activate the cloaking feature.
 */
void
cloak_set_enabled(void)
{
  config->enabled = true;
}

/**
 * @brief Disable cloaking functionality.
 *
 * This function sets the cloaking enabled flag to false, preventing the system from performing hostname cloaking.
 * Call this function to deactivate the cloaking feature.
 */
void
cloak_set_disabled(void)
{
  config->enabled = false;
}

/**
 * @brief Set the CIDR length for IPv4 addresses.
 *
 * If the provided value is greater than 32, it is capped to 32 to ensure a valid CIDR length.
 * Call this function to configure the CIDR length for IPv4 addresses used in the cloaking process.
 * The CIDR length determines the network prefix length for IPv4 addresses during cloaking,
 * specifying the range of IP addresses that are considered equivalent for cloaking purposes.
 *
 * @param value The CIDR length value.
 */
void
cloak_set_cidr_len_ipv4(int value)
{
  if (value > 32)
    value = 32;
  config->cidr_len_ipv4 = value;
}

/**
 * @brief Set the CIDR length for IPv6 addresses.
 *
 * If the provided value is greater than 128, it is capped to 128 to ensure a valid CIDR length.
 * Call this function to configure the CIDR length for IPv6 addresses used in the cloaking process.
 * The CIDR length determines the network prefix length for IPv6 addresses during cloaking,
 * specifying the range of IP addresses that are considered equivalent for cloaking purposes.
 *
 * @param value The CIDR length value.
 */
void
cloak_set_cidr_len_ipv6(int value)
{
  if (value > 128)
    value = 128;
  config->cidr_len_ipv6 = value;
}

/**
 * @brief Set the number of bits for the MAC computation.
 *
 * If the provided value is 0, it is set to 64. If it is greater than 256, it is capped to 256 to ensure a valid range.
 * The num_bytes field is updated accordingly based on the provided or adjusted num_bits value.
 * Call this function to configure the number of bits used in the MAC computation for cloaking.
 * The number of bits determines the length of the cryptographic hash used in the MAC computation,
 * influencing the strength of the cloaking mechanism.
 *
 * @param value The number of bits value.
 */
void
cloak_set_num_bits(int value)
{
  if (value == 0)
    value = 64;
  else if (value > 256)
    value = 256;

  config->num_bits = value;
  config->num_bytes = config->num_bits / 8;

  if (config->num_bits % 8)
    config->num_bytes += 1;
}

/**
 * @brief Set the secret key for the MAC computation.
 *
 * If the provided value is an empty string, no action is taken.
 * Call this function to configure the secret key used in the MAC computation for cloaking.
 *
 * @param value The secret key.
 */
void
cloak_set_secret(const char *value)
{
  if (string_is_empty(value))
    return;

  io_free(config->secret);
  config->secret = io_strdup(value);
  config->secret_len = strlen(config->secret);
}

/**
 * @brief Set the suffix appended to the cloaked hostname.
 *
 * If the provided value is an empty string, no action is taken.
 * Call this function to configure the suffix appended to the cloaked hostname during the cloaking process.
 *
 * @param value The suffix value.
 */
void
cloak_set_suffix(const char *value)
{
  if (string_is_empty(value))
    return;

  io_free(config->suffix);
  config->suffix = io_strdup(value);
  config->suffix_len = strlen(config->suffix);
}

/**
 * @brief Initialize the cloaking configuration with default values.
 *
 * This function allocates memory for the configuration structure and sets default values.
 * It is idempotent, meaning it has no effect if called more than once.
 */
void
cloak_init(void)
{
  if (config)
    return;

  config = io_calloc(sizeof(*config));
  cloak_set_enabled();
  cloak_set_num_bits(80);
  cloak_set_cidr_len_ipv4(32);
  cloak_set_cidr_len_ipv6(64);
  cloak_set_secret("_WPJFgJb2M9rDC3tZmPTTzvyfcWerKebmEG84bKeTdNw");
  cloak_set_suffix("irc");
}

/**
 * @brief Compute the MAC and compose the cloaked hostname for the given address.
 *
 * This function takes an io_addr structure, extracts the address and its length,
 * combines it with the secret key, computes the SHA3 hash, and finally creates a cloaked
 * hostname by encoding the hash in base32 and appending the configured suffix.
 *
 * @param addr The address structure to be cloaked.
 * @return The statically allocated cloaked hostname string.
 */
static const char *
_cloak_mac_and_compose(const struct io_addr *addr)
{
  const void *addr_ptr;
  size_t addr_len;

  /* Determine the address pointer and length based on the address family (IPv4 or IPv6). */
  if (address_is_ipv6(addr))
  {
    const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *const)&addr->ss;
    addr_ptr = &v6->sin6_addr;
    addr_len = sizeof(struct in6_addr);
  }
  else
  {
    const struct sockaddr_in *const v4 = (const struct sockaddr_in *const)&addr->ss;
    addr_ptr = &v4->sin_addr;
    addr_len = sizeof(struct in_addr);
  }

  /* Compute SHA3 hash. */
  sha3_context_t ctx_sha3;
  sha3_init512(&ctx_sha3);
  sha3_update(&ctx_sha3, config->secret, config->secret_len);
  sha3_update(&ctx_sha3, addr_ptr, addr_len);
  const uint8_t *const digest_sha3 = sha3_finalize(&ctx_sha3);

  /* Encode the hash in base32. */
  unsigned char digest_b32[BASE32_LEN(config->num_bytes) + 1];
  memset(digest_b32, 0, sizeof(digest_b32));

  base32_context_t ctx_base32;
  base32_init(&ctx_base32);
  base32_set_config(&ctx_base32, BASE32_NO_PADDING | BASE32_LOWER_CASE);
  base32_encode(&ctx_base32, digest_sha3, config->num_bytes, digest_b32);

  /* Compose the cloaked hostname by combining the base32 hash and suffix. */
  static char cloak[HOSTLEN + 1];
  snprintf(cloak, sizeof(cloak), "%s.%s", digest_b32, config->suffix);
  return cloak;
}

/**
 * @brief Compute the cloaked hostname for the given address, considering the configured parameters.
 *
 * This function checks if cloaking is enabled and if the necessary parameters, such as the number of bits
 * and the secret key, are provided. If cloaking is disabled or the configuration is incomplete, it
 * returns NULL.
 *
 * @param addr The address structure to be cloaked.
 * @return The cloaked hostname, or NULL if cloaking is disabled or the configuration is incomplete.
 */
const char *
cloak_compute(const struct io_addr *addr)
{
  if (config->enabled == 0)
    return NULL;
  if (config->num_bits == 0 || string_is_empty(config->secret))
    return NULL;

  struct io_addr tmp;
  address_copy(&tmp, addr);

  if (address_is_ipv6(addr))
    address_mask(&tmp, config->cidr_len_ipv6);
  else /* address_is_ipv4(addr) == true */
    address_mask(&tmp, config->cidr_len_ipv4);

  return _cloak_mac_and_compose(&tmp);
}

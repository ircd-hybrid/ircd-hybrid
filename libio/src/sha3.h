#ifndef INCLUDED_sha3_h
#define INCLUDED_sha3_h

#include <stdint.h>

/* -------------------------------------------------------------------------
 * Works when compiled for either 32-bit or 64-bit targets, optimized for
 * 64 bit.
 *
 * Canonical implementation of Init/Update/Finalize for SHA-3 byte input.
 *
 * SHA3-256, SHA3-384, SHA-512 are implemented. SHA-224 can easily be added.
 *
 * Based on code from http://keccak.noekeon.org/ .
 *
 * I place the code that I wrote into public domain, free to use.
 *
 * I would appreciate if you give credits to this work if you used it to
 * write or test * your code.
 *
 * Aug 2015. Andrey Jivsov. crypto@brainhub.org
 * ---------------------------------------------------------------------- */

/* 'Words' here refers to uint64_t */
#define SHA3_KECCAK_SPONGE_WORDS (((1600) / 8 /* Bits to byte. */ ) / sizeof(uint64_t))

typedef struct sha3_context_
{
  uint64_t saved;  /* The portion of the input message that we didn't consume yet. */

  union
  {
    /* Keccak's state */
    uint64_t s[SHA3_KECCAK_SPONGE_WORDS];
    uint8_t sb[SHA3_KECCAK_SPONGE_WORDS * 8];
  } u;

  unsigned byteIndex;  /* 0..7--the next byte after the set one (starts from 0; 0--none are buffered). */
  unsigned wordIndex;  /* 0..24--the next word to integrate input (starts from 0). */
  unsigned capacityWords;  /* The double size of the hash output in words (e.g. 16 for Keccak 512). */
} sha3_context;

typedef enum
{
  SHA3_FLAGS_NONE = 0,
  SHA3_FLAGS_KECCAK
} sha3_flags_t;

typedef enum
{
  SHA3_RESULT_OK = 0,
  SHA3_RESULT_BAD_PARAMS
} sha3_result_t;

extern void sha3_Init256(void *);
extern void sha3_Init384(void *);
extern void sha3_Init512(void *);
extern void sha3_Update(void *, void const *, size_t);
extern void const *sha3_Finalize(void *);
extern sha3_flags_t sha3_SetFlags(void *, sha3_flags_t);
extern sha3_result_t sha3_Init(void *, unsigned);
#endif  /* INCLUDED_sha3_h */

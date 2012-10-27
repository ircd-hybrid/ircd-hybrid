/*
 * encspeed.c - originally written by einride
 *            - modified for ircd-hybrid-7 by davidt
 *
 * $Id$
 */

#include "setup.h"

#ifndef HAVE_LIBCRYPTO
#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("No OpenSSL support.\n");
  return 0;
}

#else
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include <openssl/evp.h>
#include <openssl/rand.h>

#define CIPHER_BF128 0
#define CIPHER_BF168 1
#define CIPHER_3DES168 2
#define CIPHER_DES56 3
#define CIPHER_CAST128 4
#define CIPHER_IDEA128 5
#define CIPHER_RC58128 6
#define CIPHER_RC512128 7
#define CIPHER_RC516128 8

#define NUM_CIPHERS 9

#define MAXKEYSIZE 64
#define BLOCKSIZE  1000
#define BLOCKCOUNT 20000
#define TICKINT 1000

struct timeval tvstart, tvstop;

static void starttimer(void) {
  gettimeofday(&tvstart, 0);
}

static double stoptimer(void) {
  gettimeofday(&tvstop, 0);
  return (tvstop.tv_sec - tvstart.tv_sec) + ( (tvstop.tv_usec - tvstart.tv_usec) / 1000000.0);  
}

#define DATASIZE ( (double) (BLOCKSIZE * BLOCKCOUNT) / (1024.0*1024.0))

int main(int argc, char * argv[]) {
  int i, n, skipped = 0;
  int bs = BLOCKSIZE;
  const char *cipherstr = NULL;
  char key[MAXKEYSIZE];
  char iv[MAXKEYSIZE];
  char plaintext[BLOCKSIZE];
  char ciphertext[BLOCKSIZE];
  double elapsed;
  
  EVP_CIPHER_CTX  ctx;
  const EVP_CIPHER   *cipher;
  
  printf("Encryption speed test\n\n");

  for(n = 0; n < NUM_CIPHERS; n++)
  {
    /* setup cipher */
    if (skipped)
    {
      printf("%20.20s encryption: not supported by OpenSSL\n", cipherstr);
      printf("%20.20s decryption: not supported by OpenSSL\n", cipherstr);
    }

    skipped = 1;
    switch(n)
    {
      case CIPHER_BF168:
        cipherstr = "Blowfish 168-bit";
#ifdef HAVE_EVP_BF_CFB
        cipher = EVP_bf_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 24);
#else
        continue;
#endif
        break;
      case CIPHER_BF128:
        cipherstr = "Blowfish 128-bit";
#ifdef HAVE_EVP_BF_CFB
        cipher = EVP_bf_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 16);
#else
        continue;
#endif
        break;
      case CIPHER_CAST128:
        cipherstr = "CAST 128-bit";
#ifdef HAVE_EVP_CAST5_CFB
        cipher = EVP_cast5_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 16);
#else
        continue;
#endif
        break;
      case CIPHER_IDEA128:
        cipherstr = "IDEA 128-bit";
#ifdef HAVE_EVP_IDEA_CFB
        cipher = EVP_idea_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 16);
#else
        continue;
#endif
        break;
      case CIPHER_DES56:
        cipherstr = "DES 56-bit";
#ifdef HAVE_EVP_DES_CFB
        cipher = EVP_des_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 8);
#else
        continue;
#endif
        break;
      case CIPHER_3DES168:
        cipherstr = "3DES 168-bit";
#ifdef HAVE_EVP_DES_EDE3_CFB
        cipher = EVP_des_ede3_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 24);
#else
        continue;
#endif
        break;
      case CIPHER_RC58128:
        cipherstr = "RC5 8 round 128-bit";
#ifdef HAVE_EVP_RC5_32_12_16_CFB
        cipher = EVP_rc5_32_12_16_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 8);
        EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_SET_RC5_ROUNDS, 8, NULL);
#else
        continue;
#endif
        break;
      case CIPHER_RC512128:
        cipherstr = "RC5 12 round 128-bit";
#ifdef HAVE_EVP_RC5_32_12_16_CFB
        cipher = EVP_rc5_32_12_16_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 12);
        EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_SET_RC5_ROUNDS, 12, NULL);
#else
        continue;
#endif
        break;
      case CIPHER_RC516128:
        cipherstr = "RC5 16 round 128-bit";
#ifdef HAVE_EVP_RC5_32_12_16_CFB
        cipher = EVP_rc5_32_12_16_cfb();
        EVP_EncryptInit(&ctx, cipher, NULL, NULL);
        EVP_CIPHER_CTX_set_key_length(&ctx, 16);
        EVP_CIPHER_CTX_ctrl(&ctx, EVP_CTRL_SET_RC5_ROUNDS, 16, NULL);
#else
        continue;
#endif
        break;
      default:
        exit(1);
    }

    skipped = 0;

    RAND_pseudo_bytes((unsigned char *)key, MAXKEYSIZE);
    RAND_pseudo_bytes((unsigned char *)iv, MAXKEYSIZE);
    RAND_pseudo_bytes((unsigned char *)plaintext, BLOCKSIZE);
    RAND_pseudo_bytes((unsigned char *)ciphertext, BLOCKSIZE);
    
    EVP_EncryptInit(&ctx, NULL, (unsigned char *)key, (unsigned char *)iv);
    
    printf("%20.20s encryption: ", cipherstr);
    fflush(stdout);

    starttimer();
    bs = BLOCKSIZE;
    for (i=1;i<=BLOCKCOUNT;i++) {
      if (!(i % TICKINT)) {
        printf(".");
        fflush(stdout);
      }
      EVP_EncryptUpdate(&ctx, (unsigned char *)ciphertext, &bs,
                        (unsigned char *)plaintext, BLOCKSIZE);
      bs = BLOCKSIZE;
    }
    EVP_EncryptFinal(&ctx, (unsigned char *)ciphertext, &bs);
    elapsed=stoptimer();
    printf(" done, %f MB/sec\n", DATASIZE / elapsed);

    EVP_DecryptInit(&ctx, NULL, (unsigned char *)key, (unsigned char *)iv);

    printf("%20.20s decryption: ", cipherstr);
    fflush(stdout);

    starttimer();
    bs = BLOCKSIZE;
    for (i=1;i<=BLOCKCOUNT;i++) {
      if (!(i % TICKINT)) {
        printf(".");
        fflush(stdout);
      }
      EVP_DecryptUpdate(&ctx, (unsigned char *)ciphertext, &bs,
                        (unsigned char *)plaintext, BLOCKSIZE);
      bs = BLOCKSIZE;
    }
    EVP_DecryptFinal(&ctx, (unsigned char *)ciphertext, &bs);
    elapsed=stoptimer();
    printf(" done, %f MB/sec\n", DATASIZE / elapsed);
  }

  if (skipped)
  {
    printf("%20.20s encryption: not supported by OpenSSL\n", cipherstr);
    printf("%20.20s decryption: not supported by OpenSSL\n", cipherstr);
  }

  return(0);
}
#endif

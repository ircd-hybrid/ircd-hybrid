/* simple password generator by Nelson Minar (minar@reed.edu)
** copyright 1991, all rights reserved.
** You can use this code as long as my name stays with it.
**
** Modernization, getopt, etc for the Hybrid IRCD team
** by W. Campbell
**
** /dev/random for salt generation added by
** Aaron Sethman <androsyn@ratbox.org>
**
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <fcntl.h>

enum
{
  FLAG_SHA256   = 1 << 0,
  FLAG_SHA512   = 1 << 1,
  FLAG_BLOWFISH = 1 << 2,
};

enum
{
  SHA_SALT_LENGTH = 16,
  BLOWFISH_SALT_LENGTH = 22
};

static const char *make_sha256_salt(void);
static const char *make_sha512_salt(void);
static const char *make_blowfish_salt(unsigned int);
static const char *generate_random_salt(char *, unsigned int);
static const char *generate_poor_salt(char *, unsigned int);
static void full_usage(void);
static void brief_usage(void);

static const char saltChars[] =
       "./ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
       /* 0 .. 63, ascii - 64 */

int
main(int argc, char *argv[])
{
  unsigned int flag = 0;
  int rounds = 0;

  opterr = 0;
  for (int c = 0; (c = getopt(argc, argv, ":56br:h")) != -1; )
  {
    switch (c)
    {
      case '5':
        flag |= FLAG_SHA256;
        break;
      case '6':
        flag |= FLAG_SHA512;
        break;
      case 'b':
        flag |= FLAG_BLOWFISH;
        rounds = 4;
        break;
      case 'r':
        if ((rounds = atoi(optarg)) < 0)
          rounds = 0;
        break;
      case 'h':
        full_usage();
        /* NOT REACHED */
        break;
      case '?':
        /* Keep -? distinct from getopt()'s other error returns. */
        if (optopt == '?')
          brief_usage();

        fprintf(stderr, "Invalid option: -%c\n", optopt);
        return EXIT_FAILURE;
      case ':':
        fprintf(stderr, "Option -%c requires an argument\n", optopt);
        return EXIT_FAILURE;
      default:
        return EXIT_FAILURE;
    }
  }

  if (optind != argc)
  {
    fprintf(stderr, "Unexpected positional argument\n");
    return EXIT_FAILURE;
  }

  const char *salt;
  if (flag & FLAG_SHA256)
    salt = make_sha256_salt();
  else if (flag & FLAG_SHA512)
    salt = make_sha512_salt();
  else if (flag & FLAG_BLOWFISH)
    salt = make_blowfish_salt(rounds);
  else
  {
    fprintf(stderr, "No hashing algorithm specified\n");
    return EXIT_FAILURE;
  }

  const char *const plaintext = getpass("plaintext: ");
  if (plaintext == NULL)
  {
    fprintf(stderr, "getpass() failed\n");
    return EXIT_FAILURE;
  }

  errno = 0;
  const char *const hash = crypt(plaintext, salt);
  if (hash == NULL || hash[0] == '*')
  {
    if (errno)
      fprintf(stderr, "crypt() failed: %s\n", strerror(errno));
    else
      fprintf(stderr, "crypt() failed\n");

    return EXIT_FAILURE;
  }

  printf("%s\n", hash);
  return EXIT_SUCCESS;
}

static const char *
make_sha256_salt(void)
{
  static char salt[SHA_SALT_LENGTH + sizeof("$5$$")] = "$5$";

  generate_random_salt(&salt[3], SHA_SALT_LENGTH);

  salt[sizeof(salt) - 2] = '$';
  salt[sizeof(salt) - 1] = '\0';

  return salt;
}

static const char *
make_sha512_salt(void)
{
  static char salt[SHA_SALT_LENGTH + sizeof("$6$$")] = "$6$";

  generate_random_salt(&salt[3], SHA_SALT_LENGTH);

  salt[sizeof(salt) - 2] = '$';
  salt[sizeof(salt) - 1] = '\0';

  return salt;
}

static const char *
make_blowfish_salt(unsigned int rounds)
{
  static char salt[BLOWFISH_SALT_LENGTH + sizeof("$2a$00$$")];
  char tbuf[3];

  snprintf(tbuf, sizeof(tbuf), "%02u", rounds);
  snprintf(salt, sizeof(salt), "$2a$%s$", tbuf);

  generate_random_salt(&salt[7], BLOWFISH_SALT_LENGTH);

  salt[sizeof(salt) - 2] = '$';
  salt[sizeof(salt) - 1] = '\0';

  return salt;
}

static const char *
generate_poor_salt(char *salt, unsigned int length)
{
  srandom(time(NULL));

  for (unsigned int i = 0; i < length; ++i)
    salt[i] = saltChars[random() % 64];

  return salt;
}

static const char *
generate_random_salt(char *salt, unsigned int length)
{
  char *buf;
  int fd;

  if ((fd = open("/dev/random", O_RDONLY)) < 0)
    return generate_poor_salt(salt, length);

  buf = calloc(1, length);

  if (read(fd, buf, length) != (ssize_t)length)
  {
    close(fd);
    free(buf);

    return generate_poor_salt(salt, length);
  }

  for (unsigned int i = 0; i < length; ++i)
    salt[i] = saltChars[abs(buf[i]) % 64];

  close(fd);
  free(buf);

  return salt;
}

static void
full_usage(void)
{
  printf("mkpasswd [-5|-6|-b] [-r rounds]\n");
  printf("-5 Generate a SHA-256 password\n");
  printf("-6 Generate a SHA-512 password\n");
  printf("-b Generate a Blowfish password\n");
  printf("-r Specify a number of rounds for a Blowfish password;\n");
  printf("   default is 4, no more than 6 recommended\n");
  printf("The password is prompted for; salts are generated automatically.\n");
  printf("Example: mkpasswd -6\n");
  exit(EXIT_SUCCESS);
}

static void
brief_usage(void)
{
  printf("mkpasswd - password hash generator\n");
  printf(" SHA-256:  mkpasswd -5\n");
  printf(" SHA-512:  mkpasswd -6\n");
  printf("Blowfish:  mkpasswd -b [-r rounds]\n");
  printf("Use -h for full usage\n");
  exit(EXIT_SUCCESS);
}

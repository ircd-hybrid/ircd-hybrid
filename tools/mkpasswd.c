/* simple password generator by Nelson Minar (minar@reed.edu)
** copyright 1991, all rights reserved.
** You can use this code as long as my name stays with it.
**
** md5 patch by W. Campbell <wcampbel@botbay.net>
** Modernization, getopt, etc for the Hybrid IRCD team
** by W. Campbell
**
** /dev/random for salt generation added by
** Aaron Sethman <androsyn@ratbox.org>
**
** $Id$
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

enum
{
  FLAG_MD5      = 0x00000001,
  FLAG_SALT     = 0x00000002,
  FLAG_PASS     = 0x00000004,
  FLAG_LENGTH   = 0x00000008,
  FLAG_BLOWFISH = 0x00000010,
  FLAG_ROUNDS   = 0x00000020,
  FLAG_RAW      = 0x00000040,
  FLAG_SHA256   = 0x00000080,
  FLAG_SHA512   = 0x00000100
};


extern char *crypt();


static const char *make_sha256_salt(unsigned int);
static const char *make_sha256_salt_para(const char *);
static const char *make_sha512_salt(unsigned int);
static const char *make_sha512_salt_para(const char *);
static const char *make_md5_salt(unsigned int);
static const char *make_md5_salt_para(const char *);
static const char *make_blowfish_salt(unsigned int, unsigned int);
static const char *make_blowfish_salt_para(unsigned int, const char *);
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
  const char *plaintext = NULL;
  const char *saltpara = NULL;
  const char *salt = NULL;
  const char *ret = NULL;
  unsigned int flag = 0;
  int length = 0; /* Not Set */
  int rounds = 0; /* Not set, since extended DES needs 25 and blowfish needs
                  ** 4 by default, a side effect of this being the encryption
                  ** type parameter must be specified before the rounds
                  ** parameter.
                  */

  for (int c = 0; (c = getopt(argc, argv, "56mbr:h?l:s:p:R:")) != -1; )
  {
    switch (c)
    {
      case '5':
        flag |= FLAG_SHA256;
        break;
      case '6':
        flag |= FLAG_SHA512;
        break;
      case 'm':
        flag |= FLAG_MD5;
        break;
      case 'b':
        flag |= FLAG_BLOWFISH;
        rounds = 4;
        break;
      case 'l':
        flag |= FLAG_LENGTH;
        if ((length = atoi(optarg)) < 0)
          length = 0;
        break;
      case 'r':
        flag |= FLAG_ROUNDS;
        if ((rounds = atoi(optarg)) < 0)
          rounds = 0;
        break;
      case 's':
        flag |= FLAG_SALT;
        saltpara = optarg;
        break;
      case 'p':
        flag |= FLAG_PASS;
        plaintext = optarg;
        break;
      case 'R':
        flag |= FLAG_RAW;
        saltpara = optarg;
        break;
      case 'h':
        full_usage();
        /* NOT REACHED */
        break;
      case '?':
        brief_usage();
        /* NOT REACHED */
        break;
      default:
        printf("Invalid Option: -%c\n", c);
        break;
    }
  }

  if (flag & FLAG_SHA256)
  {
    if (length == 0)
      length = 16;
    if (flag & FLAG_SALT)
      salt = make_sha256_salt_para(saltpara);
    else
      salt = make_sha256_salt(length);
  }
  else if (flag & FLAG_SHA512)
  {
    if (length == 0)
      length = 16;
    if (flag & FLAG_SALT)
      salt = make_sha512_salt_para(saltpara);
    else
      salt = make_sha512_salt(length);
  }
  else if (flag & FLAG_BLOWFISH)
  {
    if (length == 0)
      length = 22;
    if (flag & FLAG_SALT)
      salt = make_blowfish_salt_para(rounds, saltpara);
    else
      salt = make_blowfish_salt(rounds, length);
  }
  else if (flag & FLAG_RAW)
    salt = saltpara;
  else  /* Default to MD5 */
  {
    if (length == 0)
      length = 8;
    if (flag & FLAG_SALT)
      salt = make_md5_salt_para(saltpara);
    else
      salt = make_md5_salt(length);
  }

  if (flag & FLAG_PASS)
  {
    if (!plaintext)
      printf("Please enter a valid password\n");
  }
  else
    plaintext = getpass("plaintext: ");

  if ((ret = crypt(plaintext, salt)))
    printf("%s\n", ret);
  else
    printf("crypt() failed: invalid or unsupported setting\n");

  return 0;
}

static const char *
make_sha256_salt_para(const char *saltpara)
{
  static char salt[21];

  if (saltpara && strlen(saltpara) <= 16)
  {
    snprintf(salt, sizeof(salt), "$5$%s$", saltpara);
    return salt;
  }

  printf("Invalid salt, please use up to 16 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}

static const char *
make_sha256_salt(unsigned int length)
{
  static char salt[21];

  if (length > 16)
  {
    printf("SHA-256 salt length too long\n");
    exit(0);
  }

  salt[0] = '$';
  salt[1] = '5';
  salt[2] = '$';

  generate_random_salt(&salt[3], length);

  salt[length + 3] = '$';
  salt[length + 4] = '\0';

  return salt;
}

static const char *
make_sha512_salt_para(const char *saltpara)
{
  static char salt[21];

  if (saltpara && strlen(saltpara) <= 16)
  {
    snprintf(salt, sizeof(salt), "$6$%s$", saltpara);
    return salt;
  }

  printf("Invalid salt, please use up to 16 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}

static const char *
make_sha512_salt(unsigned int length)
{
  static char salt[21];

  if (length > 16)
  {
    printf("SHA-512 salt length too long\n");
    exit(0);
  }

  salt[0] = '$';
  salt[1] = '6';
  salt[2] = '$';

  generate_random_salt(&salt[3], length);

  salt[length + 3] = '$';
  salt[length + 4] = '\0';

  return salt;
}

static const char *
make_md5_salt_para(const char *saltpara)
{
  static char salt[21];

  if (saltpara && strlen(saltpara) <= 16)
  {
    snprintf(salt, sizeof(salt), "$1$%s$", saltpara);
    return salt;
  }

  printf("Invalid salt, please use up to 16 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}

static const char *
make_md5_salt(unsigned int length)
{
  static char salt[21];

  if (length > 16)
  {
    printf("MD5 salt length too long\n");
    exit(0);
  }

  salt[0] = '$';
  salt[1] = '1';
  salt[2] = '$';

  generate_random_salt(&salt[3], length);

  salt[length + 3] = '$';
  salt[length + 4] = '\0';

  return salt;
}

static const char *
make_blowfish_salt_para(unsigned int rounds, const char *saltpara)
{
  static char salt[31];
  char tbuf[3];

  if (saltpara && strlen(saltpara) >= 22)
  {
    snprintf(tbuf, sizeof(tbuf), "%02u", rounds);
    snprintf(salt, sizeof(salt), "$2a$%s$%s$", tbuf, saltpara);
    return salt;
  }

  printf("Invalid salt, please use at least 22 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}

static const char *
make_blowfish_salt(unsigned int rounds, unsigned int length)
{
  static char salt[31];
  char tbuf[3];

  if (length < 22)
  {
    printf("Blowfish salt length too short\n");
    exit(0);
  }

  snprintf(tbuf, sizeof(tbuf), "%02u", rounds);
  snprintf(salt, sizeof(salt), "$2a$%s$", tbuf);

  generate_random_salt(&salt[7], length);

  salt[length + 7] = '$';
  salt[length + 8] = '\0';

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

  if (read(fd, buf, length) != length)
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
  printf("mkpasswd [-5|-6|-b|-m] [-l saltlength] [-r rounds] [-s salt] [-p plaintext]\n");
  printf("         [-R rawsalt]\n");
  printf("-5 Generate a SHA-256 password\n");
  printf("-6 Generate a SHA-512 password\n");
  printf("-b Generate a Blowfish password\n");
  printf("-m Generate an MD5 password\n");
  printf("-l Specify a length for a random MD5 or Blowfish salt\n");
  printf("-r Specify a number of rounds for a Blowfish password;\n");
  printf("   default is 4, no more than 6 recommended\n");
  printf("-s Specify a salt, up to 16 alphanumeric characters for SHA/MD5,\n");
  printf("   and at least 22 for Blowfish\n");
  printf("-R Specify a raw salt passed directly to crypt()\n");
  printf("-p Specify a plaintext password to use\n");
  printf("Example: mkpasswd -6 -s 3dr -p test\n");
  exit(0);
}

static void
brief_usage(void)
{
  printf("mkpasswd - password hash generator\n");
  printf("     MD5:  mkpasswd [-m] [-l saltlength] [-s salt] [-p plaintext]\n");
  printf(" SHA-256:  mkpasswd -5 [-l saltlength] [-s salt] [-p plaintext]\n");
  printf(" SHA-512:  mkpasswd -6 [-l saltlength] [-s salt] [-p plaintext]\n");
  printf("Blowfish:  mkpasswd -b [-r rounds] [-l saltlength] [-s salt]\n");
  printf("                           [-p plaintext]\n");
  printf("     Raw:  mkpasswd -R <rawsalt> [-p plaintext]\n");
  printf("Use -h for full usage\n");
  exit(0);
}

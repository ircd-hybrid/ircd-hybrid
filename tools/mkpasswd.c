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

#define FLAG_MD5      0x00000001
#define FLAG_DES      0x00000002
#define FLAG_SALT     0x00000004
#define FLAG_PASS     0x00000008
#define FLAG_LENGTH   0x00000010
#define FLAG_BLOWFISH 0x00000020
#define FLAG_ROUNDS   0x00000040
#define FLAG_EXT      0x00000080
#define FLAG_RAW      0x00000100
#define FLAG_SHA256   0x00000200
#define FLAG_SHA512   0x00000400


extern char *crypt();


static char *make_sha256_salt(int);
static char *make_sha256_salt_para(char *);
static char *make_sha512_salt(int);
static char *make_sha512_salt_para(char *);
static char *make_des_salt(void);
static char *make_ext_salt(int);
static char *make_ext_salt_para(int, char *);
static char *make_md5_salt(int);
static char *make_md5_salt_para(char *);
static char *make_bf_salt(int, int);
static char *make_bf_salt_para(int, char *);
static char *int_to_base64(int);
static char *generate_random_salt(char *, int);
static char *generate_poor_salt(char *, int);
static void full_usage(void);
static void brief_usage(void);

static const char saltChars[] =
       "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
       /* 0 .. 63, ascii - 64 */

int
main(int argc, char *argv[])
{
  const char *plaintext = NULL;
  int c;
  char *saltpara = NULL;
  char *salt;
  int flag = 0;
  int length = 0; /* Not Set */
  int rounds = 0; /* Not set, since extended DES needs 25 and blowfish needs
                  ** 4 by default, a side effect of this being the encryption
                  ** type parameter must be specified before the rounds
                  ** parameter.
                  */

  while ((c = getopt(argc, argv, "56mdber:h?l:s:p:R:")) != -1)
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
      case 'd':
        flag |= FLAG_DES;
        break;
      case 'b':
        flag |= FLAG_BLOWFISH;
        rounds = 4;
        break;
      case 'e':
        flag |= FLAG_EXT;
        rounds = 25;
        break;
      case 'l':
        flag |= FLAG_LENGTH;
        length = atoi(optarg);
        break;
      case 'r':
        flag |= FLAG_ROUNDS;
        rounds = atoi(optarg);
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

  if (flag & FLAG_MD5)
  {
    if (length == 0)
      length = 8;
    if (flag & FLAG_SALT)
      salt = make_md5_salt_para(saltpara);
    else
      salt = make_md5_salt(length);
  }
  else if (flag & FLAG_SHA256)
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
      salt = make_bf_salt_para(rounds, saltpara);
    else
      salt = make_bf_salt(rounds, length);
  }
  else if (flag & FLAG_EXT)
  {
    /* XXX - rounds needs to be done */
    if (flag & FLAG_SALT)
    {
      if ((strlen(saltpara) == 4))
      {
        salt = make_ext_salt_para(rounds, saltpara);
      }
      else
      {
        printf("Invalid salt, please enter 4 alphanumeric characters\n");
        exit(1);
      }
    }
    else
    {
      salt = make_ext_salt(rounds);
    }
  }
  else if (flag & FLAG_RAW)
  {
    salt = saltpara;
  }
  else /* Default to DES */
  {
    if (flag & FLAG_SALT)
    {
      if ((strlen(saltpara) == 2))
      {
        salt = saltpara;
      }
      else
      {
        printf("Invalid salt, please enter 2 alphanumeric characters\n");
        exit(1);
      }
    }
    else
    {
      salt = make_des_salt();
    }
  }

  if (flag & FLAG_PASS)
  {
    if (!plaintext)
      printf("Please enter a valid password\n");
  }
  else
    plaintext = getpass("plaintext: ");

  printf("%s\n", crypt(plaintext, salt));
  return 0;
}

static char *
make_des_salt(void)
{
  static char salt[3];

  generate_random_salt(salt, 2);
  salt[2] = '\0';
  return salt;
}

static char *
int_to_base64(int value)
{
  static char buf[5];
  int i;

  for (i = 0; i < 4; i++)
  {
    buf[i] = saltChars[value & 63];
    value >>= 6;  /* Right shifting 6 places is the same as dividing by 64 */
  }

  buf[i] = '\0';  /* not REALLY needed as it's static, and thus initialized
                  ** to \0.
                  */
  return buf;
}

static char *
make_ext_salt(int rounds)
{
  static char salt[10];

  sprintf(salt, "_%s", int_to_base64(rounds));
  generate_random_salt(&salt[5], 4);
  salt[9] = '\0';

  return salt;
}

static char *
make_ext_salt_para(int rounds, char *saltpara)
{
  static char salt[10];

  sprintf(salt, "_%s%s", int_to_base64(rounds), saltpara);
  return salt;
}

static char *
make_sha256_salt_para(char *saltpara)
{
  static char salt[21];

  if (saltpara && (strlen(saltpara) <= 16))
  {
    /* sprintf used because of portability requirements, the length
     ** is checked above, so it should not be too much of a concern
     */
    sprintf(salt, "$5$%s$", saltpara);
    return salt;
  }

  printf("Invalid Salt, please use up to 16 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}

static char *
make_sha256_salt(int length)
{
  static char salt[21];

  if (length > 16)
  {
    printf("SHA256 salt length too long\n");
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

static char *
make_sha512_salt_para(char *saltpara)
{
  static char salt[21];

  if (saltpara && (strlen(saltpara) <= 16))
  {
    /* sprintf used because of portability requirements, the length
     ** is checked above, so it should not be too much of a concern
     */
    sprintf(salt, "$6$%s$", saltpara);
    return salt;
  }

  printf("Invalid Salt, please use up to 16 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}

static char *
make_sha512_salt(int length)
{
  static char salt[21];

  if (length > 16)
  {
    printf("SHA512 salt length too long\n");
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

static char *
make_md5_salt_para(char *saltpara)
{
  static char salt[21];

  if (saltpara && (strlen(saltpara) <= 16))
  {
    /* sprintf used because of portability requirements, the length
    ** is checked above, so it should not be too much of a concern
    */
    sprintf(salt, "$1$%s$", saltpara);
    return salt;
  }

  printf("Invalid Salt, please use up to 16 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}

static char *
make_md5_salt(int length)
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
  salt[length+3] = '$';
  salt[length+4] = '\0';

  return salt;
}

static char *
make_bf_salt_para(int rounds, char *saltpara)
{
  static char salt[31];
  char tbuf[3];

  if (saltpara && (strlen(saltpara) <= 22))
  {
    /* sprintf used because of portability requirements, the length
    ** is checked above, so it should not be too much of a concern
    */
    sprintf(tbuf, "%02d", rounds);
    sprintf(salt, "$2a$%s$%s$", tbuf, saltpara);
    return salt;
  }

  printf("Invalid Salt, please use up to 22 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}

static char *
make_bf_salt(int rounds, int length)
{
  static char salt[31];
  char tbuf[3];

  if (length > 22)
  {
    printf("BlowFish salt length too long\n");
    exit(0);
  }

  sprintf(tbuf, "%02d", rounds);
  sprintf(salt, "$2a$%s$", tbuf);
  generate_random_salt(&salt[7], length);
  salt[length+7] = '$';
  salt[length+8] = '\0';

  return salt;
}

static char *
generate_poor_salt(char *salt, int length)
{
  int i;

  srandom(time(NULL));

  for (i = 0; i < length; i++)
    salt[i] = saltChars[random() % 64];

  return salt;
}

static char *
generate_random_salt(char *salt, int length)
{
  char *buf;
  int fd, i;

  if ((fd = open("/dev/random", O_RDONLY)) < 0)
    return generate_poor_salt(salt, length);

  buf = calloc(1, length);

  if (read(fd, buf, length) != length)
  {
    free(buf);
    return generate_poor_salt(salt, length);
  }

  for (i = 0; i < length; i++)
    salt[i] = saltChars[abs(buf[i]) % 64];

  free(buf);

  return salt;
}

static void
full_usage(void)
{
  printf("mkpasswd [-5|-6|-m|-d|-b|-e] [-l saltlength] [-r rounds] [-s salt] [-p plaintext]\n");
  printf("         [-R rawsalt]\n");
  printf("-5 Generate a SHA-256 password\n");
  printf("-6 Generate a SHA-512 password\n");
  printf("-m Generate an MD5 password\n");
  printf("-d Generate a DES password\n");
  printf("-b Generate a BlowFish password\n");
  printf("-e Generate an Extended DES password\n");
  printf("-l Specify a length for a random MD5 or BlowFish salt\n");
  printf("-r Specify a number of rounds for a BlowFish or Extended DES password\n");
  printf("   BlowFish:  default 4, no more than 6 recommended\n");
  printf("   Extended DES:  default 25\n");
  printf("-s Specify a salt, 2 alphanumeric characters for DES, up to 16 for SHA/MD5,\n");
  printf("   up to 22 for BlowFish, and 4 for Extended DES\n");
  printf("-R Specify a raw salt passed directly to crypt()\n");
  printf("-p Specify a plaintext password to use\n");
  printf("Example: mkpasswd -m -s 3dr -p test\n");
  exit(0);
}

static void
brief_usage(void)
{
  printf("mkpasswd - password hash generator\n");
  printf("Standard DES:  mkpasswd [-d] [-s salt] [-p plaintext]\n");
  printf("Extended DES:  mkpasswd -e [-r rounds] [-s salt] [-p plaintext]\n");
  printf("     SHA-256:  mkpasswd -5 [-l saltlength] [-s salt] [-p plaintext]\n");
  printf("     SHA-512:  mkpasswd -6 [-l saltlength] [-s salt] [-p plaintext]\n");
  printf("         MD5:  mkpasswd -m [-l saltlength] [-s salt] [-p plaintext]\n");
  printf("    BlowFish:  mkpasswd -b [-r rounds] [-l saltlength] [-s salt]\n");
  printf("                           [-p plaintext]\n");
  printf("         Raw:  mkpasswd -R <rawsalt> [-p plaintext]\n");
  printf("Use -h for full usage\n");
  exit(0);
}

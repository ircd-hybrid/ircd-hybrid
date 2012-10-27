/* include/setup.h suitable for Windows compilers */
/* $Id$ */


/*** BEGIN OF STANDARD CONFIGURATION SETTINGS ***/


/* Set up your maximum allowed nickname length here. */
#define _NICKLEN 20

/* Maximum topic length (<=390) */
#define TOPICLEN 160

/* If you plan to move your installed ircd from C:\ircd to
 * some other directory, modify the setting here.
 * Remember to escape backslashes by typing them twice! */
#define IRCD_PREFIX "c:/ircd"

/* If you want %halfops (chanmode +h) support on your network,
 * uncomment the following line. */
/* #define HALFOPS 1 */

/* If you need additional non standard features provided in
 * contrib/ modules, uncomment the following line. */
/* #define BUILD_CONTRIB 1 */


/*** END OF STANDARD CONFIGURATION SETTINGS ***/


#ifndef _WIN32
#define _WIN32
#endif

/* Size of the ban heap. */
#define BAN_HEAP_SIZE 128

/* Size of the channel heap. */
#define CHANNEL_HEAP_SIZE 256

/* Size of the client heap. */
#define CLIENT_HEAP_SIZE 256

/* Size of the dbuf heap. */
#define DBUF_HEAP_SIZE 64

/* Size of the dlink_node heap. */
#define DNODE_HEAP_SIZE 256

/* Define if this ircd will be an EFnet server. */
/* #undef EFNET */

/* Define to 1 if you have the `basename' function. */
#define HAVE_BASENAME 1

/* Define to 1 if you have the <crypt.h> header file. */
/* #undef HAVE_CRYPT_H */

/* Define to 1 if you have the <devpoll.h> header file. */
/* #undef HAVE_DEVPOLL_H */

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you have the `dlfunc' function. */
/* #undef HAVE_DLFUNC */

/* Define if the dlopen function is available. */
/* #undef HAVE_DLOPEN */

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the `EVP_bf_cfb' function. */
/* #undef HAVE_EVP_BF_CFB */

/* Define to 1 if you have the `EVP_cast5_cfb' function. */
/* #undef HAVE_EVP_CAST5_CFB */

/* Define to 1 if you have the `EVP_des_cfb' function. */
/* #undef HAVE_EVP_DES_CFB */

/* Define to 1 if you have the `EVP_des_ede3_cfb' function. */
/* #undef HAVE_EVP_DES_EDE3_CFB */

/* Define to 1 if you have the `EVP_idea_cfb' function. */
/* #undef HAVE_EVP_IDEA_CFB */

/* Define to 1 if you have the `EVP_rc5_32_12_16_cfb' function. */
/* #undef HAVE_EVP_RC5_32_12_16_CFB */

/* Define to 1 if you have the <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */

/* Define to 1 if you have the `crypto' library (-lcrypto). */
/* #undef HAVE_LIBCRYPTO */

/* Define to 1 if you have the <libgen.h> header file. */
/* #undef HAVE_LIBGEN_H */

/* Define to 1 if zlib (-lz) is available. */
/* #undef HAVE_LIBZ */

/* Define to 1 if you have the `lrand48' function. */
/* #undef HAVE_LRAND48 */

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
/* #undef HAVE_MACH_O_DYLD_H */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `mmap' function. */
/* #undef HAVE_MMAP */

/* Define if the shl_load function is available. */
/* #undef HAVE_SHL_LOAD */

/* Define to 1 if you have the `snprintf' function. */
/* #undef HAVE_SNPRINTF */

/* Define to 1 if you have the `socketpair' function. */
/* #undef HAVE_SOCKETPAIR */

/* Define to 1 if you have the `srand48' function. */
/* #undef HAVE_SRAND48 */

/* Define to 1 if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcat' function. */
/* #undef HAVE_STRLCAT */

/* Define to 1 if you have the `strlcpy' function. */
/* #undef HAVE_STRLCPY */

/* Define to 1 if you have the `strtok_r' function. */
/* #undef HAVE_STRTOK_R */

/* Define to 1 if the system has the type `struct addrinfo'. */
/* #undef HAVE_STRUCT_ADDRINFO */

/* Define to 1 if the system has the type `struct sockaddr_storage'. */
/* #undef HAVE_STRUCT_SOCKADDR_STORAGE */

/* Define to 1 if you have the <sys/devpoll.h> header file. */
/* #undef HAVE_SYS_DEVPOLL_H */

/* Define to 1 if you have the <sys/param.h> header file. */
/* #undef HAVE_SYS_PARAM_H */

/* Define to 1 if you have the <sys/resource.h> header file. */
/* #undef HAVE_SYS_RESOURCE_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/syslog.h> header file. */
#define HAVE_SYS_SYSLOG_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/wait.h> header file. */
/* #undef HAVE_SYS_WAIT_H */

/* Define to 1 if the system has the type `uintptr_t'. */
/* #undef HAVE_UINTPTR_T */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to 1 if you have the `vsnprintf' function. */
/* #undef HAVE_VSNPRINTF */

/* Define to 1 if you have the <wait.h> header file. */
/* #undef HAVE_WAIT_H */

/* Miscellaneous sanity checks for the ircd. Makes it slightly slower */
#define INVARIANTS 1

/* Define if IPv6 support is present and available. */
/* #undef IPV6 */

/* Size of the local client heap. */
#define LCLIENT_HEAP_SIZE 128

/* Log facility to use for syslog() */
/* #undef LOG_FACILITY */

/* Define this to disable debugging support. */
/* #undef NDEBUG */

/* Nickname length */
#define NICKLEN (_NICKLEN+1)

/* Size of the WHOWAS array. */
#define NICKNAMEHISTORYLENGTH 1500

/* Disable the block allocator. */
/* #undef NOBALLOC */

/* Define to 1 if your system has no in6addr_any. */
/* #undef NO_IN6ADDR_ANY */

/* Define if you have no native inet_aton() function. */
#define NO_INET_ATON 1

/* Define if you have no native inet_ntop() function. */
#define NO_INET_NTOP 1

/* Define if you have no native inet_pton() function. */
#define NO_INET_PTON 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "ircd-hybrid"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "ircd-hybrid 7.2"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "ircd-hybrid"

/* Define to the version of this package. */
#define PACKAGE_VERSION "7.2"

/* Path to /dev/null */
#define PATH_DEVNULL "nul"

/* This is the type of IO loop we are using */
#define SELECT_TYPE "WSAAsyncSelect"

/* Suffix for shared libraries on this platform. */
/* #undef SHARED_SUFFIX */

/* The size of a `int64_t', as computed by sizeof. */
#define SIZEOF_INT64_T 8

/* The size of a `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* Define to 1 if sockaddr_in has a 'sin_len' member. */
/* #undef SOCKADDR_IN_HAS_LEN */

/* Define to 1 if dynamic modules can't be used. */
#define STATIC_MODULES 1

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if string.h may be included along with strings.h */
/* #undef STRING_WITH_STRINGS */

/* Send connect notices for other servers to syslog */
/* #undef SYSLOG_CONNECT */

/* Send oper kills to syslog */
/* #undef SYSLOG_KILL */

/* Send /OPER successes to syslog */
/* #undef SYSLOG_OPER */

/* Send remote squits for all servers to syslog */
/* #undef SYSLOG_SQUIT */

/* Send user log stuff to syslog */
/* #undef SYSLOG_USERS */

/* Size of the topic heap. */
#define TOPIC_HEAP_SIZE 256

/* If enabled, server links to your network must have a minimum of TS5. */
/* #undef TS5_ONLY */

/* Use kqueue() for I/O loop */
/* #undef USE_KQUEUE */

/* Send vital ircd messages to syslog */
/* #undef USE_SYSLOG */

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */

/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif

/* This is needed to use strtok_r on Solaris. */
/* #undef __EXTENSIONS__ */

/* If system does not define in_port_t, define it to what it should be. */
#define in_port_t u_short

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#define inline
#endif

/* Define to `long long' if <sys/types.h> does not define. */
/* #undef int64_t */

/* If system does not define sa_family_t, define it here. */
#define sa_family_t u_short

/* If we don't have a real socklen_t, unsigned int is good enough. */
#define socklen_t unsigned int

/* Broken glibc implementations use __ss_family instead of ss_family. Define
   to __ss_family if true. */
/* #undef ss_family */

/* If system does not define u_int16_t, define a usable substitute. */
#define u_int16_t unsigned short int

/* If system does not define u_int32_t, define to unsigned long int here. */
#define u_int32_t unsigned int

/* Define to `unsigned long long' if <sys/types.h> does not define. */
#define uint64_t unsigned __int64

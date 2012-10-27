dnl $Id$
dnl Process this file with autoconf to produce a configure script.

dnl TODO: clean up all the OpenSSL and shared module checking stuff;
dnl the most major changes have already been made and it looks like
dnl said functions need to be just about as complex as they already are.

AC_PREREQ(2.57)

dnl Sneaky way to get an Id tag into the configure script
AC_COPYRIGHT([$Id$])

AC_INIT([ircd-hybrid],[7.2])

AC_CONFIG_HEADER(include/setup.h)

AC_PREFIX_DEFAULT(/usr/local/ircd)

AC_GNU_SOURCE

OLD_CFLAGS="$CFLAGS"
dnl Checks for programs.
AC_PROG_CC
AC_LANG(C)

dnl Make sure autoconf doesn't interfere with cflags -jmallett
CFLAGS="$OLD_CFLAGS"

dnl Check for various compilers. -jmallett
dnl But if $CC turns out to be gcc, sure as hell it's, well, gcc. -joshk

if test "$ac_cv_c_compiler_gnu" != yes; then

SGS=no
AC_MSG_CHECKING($CC -version for TenDRA or MIPSpro)
case `$CC -version 2>&1` in
*TenDRA*)
	AC_MSG_RESULT([yes, TenDRA])
	IRC_CFLAGS=""
	CPPFLAGS="$CPPFLAGS -Ylonglong -Yansi -Ysystem"
	SGS=yes
	TenDRA=yes
;;
*MIPSpro*)
	AC_MSG_RESULT([yes, MIPSpro])
	MIPSpro=yes
	SGS=yes
;;
*)
	AC_MSG_RESULT(no)
	TenDRA=no
	MIPSpro=no
;;
esac

AC_MSG_CHECKING([$CC -V for Sun Workshop, Forte, HPUX or Tru64 cc])
case `$CC -V 2>&1` in
*Sun*WorkShop* | *Forte*Developer* | *Sun*C*)
	AC_MSG_RESULT(Sun Workshop/Forte)
	IRC_CFLAGS="-xO3 -xdepend -xinline=dlinkAdd,dlinkAddBefore,dlinkAddTail,dlinkDelete,dlink_list_length,dlink_node,dlinkMoveList,_MyMalloc,_MyRealloc,_MyFree,_DupString"
	SunWorkShop=yes
	SGS=yes
;;
*Tru64*)
	AC_MSG_RESULT(Tru64 cc)
	IRC_CFLAGS=""
	CPPFLAGS="-I/usr/local/include"
	Tru=yes
;;
*HP*ANSI*)
	AC_MSG_RESULT(HPUX cc)
	HPUX=yes
	IRC_CFLAGS="+e"
;;
*)
	AC_MSG_RESULT(no)
;;
esac

fi

AC_MSG_CHECKING([uname -s for Cygwin, Solaris or HPUX])
case `uname -s` in
        HP-UX*)
	dnl only do this if we haven't already detected the newer one
	dnl and we're not already using gcc
	
		if test "$HPUX" != yes -a "$ac_cv_c_compiler_gnu" = no; then
        	        AC_MSG_RESULT(assuming old HPUX with its own cc)  
			IRC_CFLAGS="$IRC_CFLAGS +e"
			HPUX=yes
		else
			AC_MSG_RESULT(already using newer HPUX)
		fi
	;;
	CYGWIN*)
		AC_MSG_RESULT(Cygwin)
		CYGWIN=yes
	;;
	SunOS*)
		AC_MSG_RESULT(SunOS or Solaris)
		AC_DEFINE(__EXTENSIONS__, 1, [This is needed to use strtok_r on Solaris.])
	;;
	*)
		AC_MSG_RESULT(no)
	;;
esac

if test "$ac_cv_c_compiler_gnu" = yes; then
	AC_MSG_CHECKING(if $CC is Apple GCC)
	
	if expr "`$CC -v 2>&1 | tail -1`" : ".*Apple" >/dev/null; then
		AppleGCC=yes
	else
		AppleGCC=no
	fi

	AC_MSG_RESULT($AppleGCC)

	IRC_CFLAGS="$IRC_CFLAGS -Wall -O2"
fi

dnl If we support -g, use it!
if test "$ac_cv_prog_cc_g" = yes; then
	dnl Tru64 needs -g3 for -O2
	if test "$Tru" = yes; then
		IRC_CFLAGS="$IRC_CFLAGS -g3"
	else
		IRC_CFLAGS="$IRC_CFLAGS -g"
	fi
fi

dnl SVR4 SGS based on what we know about the compiler -jmallett
AC_MSG_CHECKING(if $CC supports the SVR4 SGS interfaces)
if test "$SGS" = "yes"; then
	AC_MSG_RESULT(yes)
else
	AC_MSG_RESULT(no)
fi

dnl We prefer gcc -MM because it's a lot less bloated
AC_PATH_PROG(MKDEP, mkdep)
AC_PATH_PROG(MAKEDEPEND, makedepend)

AC_MSG_CHECKING(how to generate dependency info)

STDOUT="> .depend"

if test "$ac_cv_c_compiler_gnu" = yes; then
	AC_MSG_RESULT(gcc -MM)
	MKDEP="$CC -MM"
elif test ! -z "$MKDEP"; then
	AC_MSG_RESULT(mkdep)

	dnl Tru64's mkdep is very loud
	if test -z "$Tru"; then
		STDOUT=""
	else
		STDOUT=" 2> /dev/null"
	fi
elif test "$SunWorkShop" = yes; then
	AC_MSG_RESULT($CC -xM)
	MKDEP="$CC -xM"
	STDOUT="> .depend 2> /dev/null"
elif test ! -z "$MAKEDEPEND"; then
	AC_MSG_RESULT(makedepend)
	MKDEP="$MAKEDEPEND -f-"
else
	AC_MSG_RESULT([nothing suitable.. forget it!])
	MKDEP=":"
fi

AC_SUBST(MKDEP)
AC_SUBST(STDOUT)

dnl check for /dev/null so we can use it to hold evil fd's
AC_MSG_CHECKING([for /dev/null])
if test -c /dev/null ; then
	AC_DEFINE(PATH_DEVNULL, "/dev/null", [Path to /dev/null])
	AC_MSG_RESULT(yes)
else
	AC_DEFINE(PATH_DEVNULL, "devnull.log", [Path to /dev/null])
	AC_MSG_RESULT(no - using devnull.log)
fi

dnl jdc -- If CFLAGS is defined, best use it everywhere...
dnl NOTE: jv says it must be added to the *END*, because things like
dnl "gcc -O9 -O2" will result in -O2 getting preference.  How stupid.
if test ! -z "$CFLAGS"; then
	IRC_CFLAGS="$IRC_CFLAGS $CFLAGS"
fi

AC_ISC_POSIX
AC_C_INLINE
AC_PROG_GCC_TRADITIONAL
AC_PROG_MAKE_SET
AC_PROG_INSTALL
AC_PATH_PROG(RM, rm)
AC_PATH_PROG(CP, cp)
AC_PATH_PROG(MV, mv)
AC_PATH_PROG(LN, ln)
AC_PATH_PROG(SED, sed)
AC_PATH_PROG(AR, ar)
AC_PATH_PROG(LD, ld)
AC_PATH_PROG(TEST, [test], [test])

dnl use directory structure of cached as default (hack)
if test "$libexecdir" = '${exec_prefix}/libexec' &&
   test "$localstatedir" = '${prefix}/var'; then
	libexecdir='${bindir}'
	localstatedir='${prefix}'
fi

dnl Checks for header files.
AC_HEADER_STDC

AC_CHECK_HEADERS([crypt.h inttypes.h stdint.h sys/resource.h sys/param.h errno.h sys/syslog.h stddef.h libgen.h sys/wait.h wait.h link.h])

dnl Networking Functions
dnl ====================

AC_SEARCH_LIBS(socket, socket, , [AC_MSG_ERROR([You have no socket()! Aborting.])])

dnl Don't use them if they're available natively... else, they're available in inet_misc
AC_SEARCH_LIBS(inet_aton, resolv, , [inet_misc=1; AC_DEFINE(NO_INET_ATON, 1, [Define if you have no native inet_aton() function.])])
AC_SEARCH_LIBS(inet_pton, resolv nsl, , [inet_misc=1; AC_DEFINE(NO_INET_PTON, 1, [Define if you have no native inet_pton() function.])])
AC_SEARCH_LIBS(inet_ntop, resolv nsl, , [inet_misc=1; AC_DEFINE(NO_INET_NTOP, 1, [Define if you have no native inet_ntop() function.])])

if test "$inet_misc" = 1; then
	AC_SUBST(INET_MISC, inet_misc.c)
fi

AC_CHECK_TYPES([struct sockaddr_storage], , ,
[[#include <sys/types.h>
#include <sys/socket.h>
]])

if test "$ac_cv_type_struct_sockaddr_storage" = no; then
	AC_CHECK_MEMBER([struct sockaddr_in.sin_len],
	[AC_DEFINE(SOCKADDR_IN_HAS_LEN, 1, [Define to 1 if sockaddr_in has a 'sin_len' member.])])
fi

AC_CHECK_TYPES([struct addrinfo], , , [[#include <netdb.h>]])

AC_CHECK_TYPE(socklen_t, ,
[AC_DEFINE([socklen_t], [unsigned int],
[If we don't have a real socklen_t, unsigned int is good enough.])],
[#include <sys/types.h>
#include <sys/socket.h>])

dnl Tru64 accepts *both*
if test -z "$Tru"; then

AC_MSG_CHECKING(for broken glibc with __ss_family)
AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM(
[#include <sys/types.h>
#include <sys/socket.h>],
[struct sockaddr_storage s; s.__ss_family = AF_INET;])],
[
	AC_MSG_RESULT(yes)
	AC_DEFINE(ss_family, __ss_family, [Broken glibc implementations use __ss_family instead of ss_family. Define to __ss_family if true.])
],
[AC_MSG_RESULT(no)])

fi

AC_MSG_CHECKING([for core IPv6 support])

AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM(
	[[#define IN_AUTOCONF
	#include "include/stdinc.h"]],
	[[struct sockaddr_in6 s; 
	  struct sockaddr_storage t;
	  s.sin6_family = 0;]]
	)],
[
	if test "$CYGWIN" = "yes"; then
		AC_MSG_RESULT([no, Cygwin's IPv6 is incomplete])
		have_v6=no
	else
		have_v6=yes
		AC_DEFINE(IPV6, 1, [Define if IPv6 support is present and available.])
		AC_MSG_RESULT(yes)
		AC_MSG_CHECKING([for struct in6addr_any])
		AC_COMPILE_IFELSE(
			[AC_LANG_PROGRAM(
				[[#define IN_AUTOCONF
				#include "include/stdinc.h"]],
				[[struct in6_addr a = in6addr_any;]]
			)],
			[AC_MSG_RESULT(yes)],
			[
				AC_MSG_RESULT(no)
				AC_DEFINE(NO_IN6ADDR_ANY, 1, [Define to 1 if your system has no in6addr_any.])
				inet_misc=1
			]
		)
	fi
],
[AC_MSG_RESULT(no)
have_v6="no"])

AC_SEARCH_LIBS(crypt, [crypt descrypt],,)

CRYPT_LIB=$ac_cv_search_crypt

if test "$CRYPT_LIB" = "none required"; then
	unset CRYPT_LIB
elif test "$CRYPT_LIB" = no; then
	CRYPT_C=crypt.c
	unset CRYPT_LIB
fi

AC_SUBST(CRYPT_C)
AC_SUBST(CRYPT_LIB)

dnl See whether we can include both string.h and strings.h.
AC_CACHE_CHECK([whether string.h and strings.h may both be included],
gcc_cv_header_string,
[
	AC_COMPILE_IFELSE(
	[#include <string.h>
	#include <strings.h>], 
	[gcc_cv_header_string=yes],
	[gcc_cv_header_string=no])
])

if test "$gcc_cv_header_string" = "yes"; then
	AC_DEFINE(STRING_WITH_STRINGS, 1, [Define to 1 if string.h may be included along with strings.h])
fi

AC_C_BIGENDIAN

dnl Check for stdarg.h - if we can't find it, halt configure
AC_CHECK_HEADER(stdarg.h, , [AC_MSG_ERROR([** stdarg.h could not be found - ircd-hybrid will not compile without it **])])

dnl Checks for the existence of strlcat, strlcpy, basename...
dnl This more reliable test only works with gcc though.

if test "$ac_cv_c_compiler_gnu" = yes; then

AC_MSG_CHECKING(for strlcpy)
save_CFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wimplicit -Werror"

AC_LINK_IFELSE(
	[AC_LANG_PROGRAM(
		[[#include <string.h>
		#include <stdlib.h>]],
		[[char *a = malloc(6), *b = strdup("hello");
		strlcpy(a, b, 6);]]
	)],
	[AC_MSG_RESULT(yes)
	AC_DEFINE(HAVE_STRLCPY, 1, [Define if strlcpy is available (most BSDs.)])],
	[AC_MSG_RESULT(no)]
)

AC_MSG_CHECKING(for strlcat)
AC_LINK_IFELSE(
	[AC_LANG_PROGRAM(
		[[#include <string.h>
		#include <stdlib.h>]],
		[[char *a = malloc(6), *b = strdup("hello");
		strlcat(a, b, 6);]]
	)],
	[AC_MSG_RESULT(yes)
	AC_DEFINE(HAVE_STRLCAT, 1, [Define if strlcat is available (most BSDs.)])],
	[AC_MSG_RESULT(no)]
)

CFLAGS=$save_CFLAGS

else

dnl Better than nothing. The more complicated test above probably fixes powerpc,
dnl so who cares.

AC_CHECK_FUNCS([strlcat strlcpy])

fi

AC_CHECK_SIZEOF(int64_t)
AC_CHECK_SIZEOF(long long)

if test "$ac_cv_sizeof_int64_t" = 8; then
  AC_CHECK_TYPE(uint64_t)
  AC_CHECK_TYPE(int64_t)
elif test "$ac_cv_sizeof_long_long" = 8; then
  AC_CHECK_TYPE(uint64_t, unsigned long long)
  AC_CHECK_TYPE(int64_t, long long)
else
  AC_MSG_ERROR([Your system doesn't appear to have 64 bit integers.  Aborting.])
fi

AC_CHECK_TYPE([u_int32_t], [],
[
	AC_CHECK_TYPE([uint32_t],
	[
		AC_DEFINE(u_int32_t, [uint32_t], [If system does not define u_int32_t, define a reasonable substitute.])
	],
	[
		AC_MSG_WARN([system has no u_int32_t or uint32_t, default to unsigned long int])
		AC_DEFINE(u_int32_t, [unsigned long int], [If system does not define u_int32_t, define to unsigned long int here.])
	])
])

AC_CHECK_TYPE([u_int16_t], [],
[
	AC_CHECK_TYPE([uint16_t],
	[
		AC_DEFINE(u_int16_t, [uint16_t], [If system does not define u_int16_t, define a usable substitute])
	],
	[
		AC_MSG_WARN([system has no u_int16_t or uint16_t, default to unsigned short int])
		AC_DEFINE(u_int16_t, [unsigned short int], [If system does not define u_int16_t, define a usable substitute.])
	])
])

AC_CHECK_TYPE([in_port_t], [],
[AC_DEFINE(in_port_t, [u_int16_t], [If system does not define in_port_t, define it to what it should be.])], 
[[#include <sys/types.h>
#include <netinet/in.h>]])

AC_CHECK_TYPE([sa_family_t], [],
[AC_DEFINE(sa_family_t, [u_int16_t], [If system does not define sa_family_t, define it here.])],
[[#include <sys/types.h>
#include <sys/socket.h>]])

dnl check for various functions...
AC_CHECK_FUNCS([socketpair basename mmap snprintf vsnprintf lrand48 srand48 strtok_r usleep])

if test "$ac_cv_func_snprintf" = no -o "$ac_cv_func_vsnprintf" = no; then
	SNPRINTF_C="snprintf.c"
fi

AC_SUBST(SNPRINTF_C)

dnl Specialized functions checks
dnl ============================

dnl OpenSSL support
AC_MSG_CHECKING(for OpenSSL)
AC_ARG_ENABLE(openssl,
[AC_HELP_STRING([--enable-openssl[=DIR]],[Enable OpenSSL support (DIR optional).])
AC_HELP_STRING([--disable-openssl],[Disable OpenSSL support.])],
[cf_enable_openssl=$enableval],
[cf_enable_openssl="auto"])

if test "$cf_enable_openssl" != "no" ; then
	cf_openssl_basedir=""
	if test "$cf_enable_openssl" != "auto" &&
	test "$cf_enable_openssl" != "yes" ; then
		dnl Support for --enable-openssl=/some/place
		cf_openssl_basedir="`echo ${cf_enable_openssl} | sed 's/\/$//'`"
	else
	dnl Do the auto-probe here.  Check some common directory paths.
		for dirs in /usr/local/ssl /usr/pkg /usr/local \
		/usr/local/openssl /usr/sfw; do
			if test -f "${dirs}/include/openssl/opensslv.h" ; then
				cf_openssl_basedir="${dirs}"
			break
			fi
		done
		unset dirs
	fi
	dnl Now check cf_openssl_found to see if we found anything.
	if test ! -z "$cf_openssl_basedir"; then
		if test -f "${cf_openssl_basedir}/include/openssl/opensslv.h" ; then
			SSL_INCLUDES="-I${cf_openssl_basedir}/include"
			SSL_LIBS="-L${cf_openssl_basedir}/lib"
		else
		dnl OpenSSL wasn't found in the directory specified.  Naughty
		dnl administrator...
		cf_openssl_basedir=""
		fi
	else
	dnl Check for stock FreeBSD 4.x and 5.x systems, since their files
	dnl are in /usr/include and /usr/lib.  In this case, we don't want to
	dnl change INCLUDES or LIBS, but still want to enable OpenSSL.
	dnl We can't do this check above, because some people want two versions
	dnl of OpenSSL installed (stock FreeBSD 4.x/5.x and /usr/local/ssl)
	dnl and they want /usr/local/ssl to have preference.
		if test -f "/usr/include/openssl/opensslv.h" ; then
			cf_openssl_basedir="/usr"
		fi
	fi

	dnl If we have a basedir defined, then everything is okay.  Otherwise,
	dnl we have a problem.
	if test ! -z "$cf_openssl_basedir"; then
		AC_MSG_RESULT($cf_openssl_basedir)
		cf_enable_openssl="yes"
	else
		AC_MSG_RESULT([not found. Specify a correct path?])
		cf_enable_openssl="no"
	fi
	unset cf_openssl_basedir
else
	dnl If --disable-openssl was specified
	AC_MSG_RESULT(disabled)
fi

save_CPPFLAGS="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS $SSL_INCLUDES"
save_LIBS="$LIBS"
LIBS="$LIBS $SSL_LIBS"
if test "$cf_enable_openssl" != no; then
	dnl Check OpenSSL version (must be 0.9.6 or above!)
	AC_MSG_CHECKING(for OpenSSL 0.9.6 or above)
	AC_RUN_IFELSE(
		AC_LANG_PROGRAM(
	    	[#include <openssl/opensslv.h>
		#include <stdlib.h>],
		[[if (OPENSSL_VERSION_NUMBER >= 0x00906000)
		exit(0); else exit(1);]]),
	cf_openssl_version_ok=yes,
	cf_openssl_version_ok=no,
	cf_openssl_version_ok=no)

	if test "$cf_openssl_version_ok" = yes; then
		AC_MSG_RESULT(found)

		dnl Work around pmake/gmake conditional incompatibilities
		AC_SUBST(ENCSPEED, encspeed)
		
		dnl Do all the HAVE_LIBCRYPTO magic -- and check for ciphers
		CPPFLAGS="$CPPFLAGS $SSL_LIBS"
		AC_CHECK_LIB(crypto, RSA_free)
		if test "$ac_cv_lib_crypto_RSA_free" = yes; then
			LIBS="$LIBS -lcrypto"
			cf_openssl_ciphers=''
			AC_CHECK_FUNCS(EVP_bf_cfb,
			cf_openssl_ciphers="${cf_openssl_ciphers}BF/168 BF/128 ")
			AC_CHECK_FUNCS(EVP_cast5_cfb,
			cf_openssl_ciphers="${cf_openssl_ciphers}CAST/128 ")
			AC_CHECK_FUNCS(EVP_idea_cfb,
			cf_openssl_ciphers="${cf_openssl_ciphers}IDEA/128 ")
			AC_CHECK_FUNCS(EVP_rc5_32_12_16_cfb,
			cf_openssl_ciphers="${cf_openssl_ciphers}RC5.16/128 RC5.12/128 RC5.8/128 ")
			AC_CHECK_FUNCS(EVP_des_ede3_cfb,
			cf_openssl_ciphers="${cf_openssl_ciphers}3DES/168 ")
			AC_CHECK_FUNCS(EVP_des_cfb,
			cf_openssl_ciphers="${cf_openssl_ciphers}DES/56 ")
		fi
		SSL_LIBS="$SSL_LIBS -lssl -lcrypto"
		SSL_SRCS_ENABLE='$(SSL_SRCS)'
	else
	        AC_MSG_RESULT(no - OpenSSL support disabled)
	fi
fi

CPPFLAGS="$save_CPPFLAGS"
LIBS="$save_LIBS"

dnl End OpenSSL detection

dnl Specialized functions and libraries
dnl ===================================

AC_ARG_WITH(zlib-path,
AC_HELP_STRING([--with-zlib-path=DIR],[Path to libz.so for ziplinks support.]),
[LIBS="$LIBS -L$withval"],)

AC_ARG_ENABLE(zlib,
AC_HELP_STRING([--disable-zlib],[Disable ziplinks support]),
[zlib=$enableval],[zlib=yes])

if test "$zlib" = yes; then

AC_CHECK_HEADER(zlib.h, [
	AC_CHECK_LIB(z, zlibVersion,
	[
		AC_SUBST(ZLIB_LD, -lz)
		AC_DEFINE(HAVE_LIBZ, 1, [Define to 1 if zlib (-lz) is available.])
	], zlib=no)
], zlib=no)

fi

dnl IO Loop Selection
dnl =================

AC_ARG_ENABLE(poll,
AC_HELP_STRING([--enable-poll],[Force poll() usage.]),
[SELECT_TYPE_EXPLICIT="poll"; echo "Forcing poll() to be enabled"],)

AC_ARG_ENABLE(select,
AC_HELP_STRING([--enable-select],[Force select() usage.]),
[SELECT_TYPE_EXPLICIT="select"; echo "Forcing select() to be enabled"],)
    
AC_ARG_ENABLE(kqueue,
AC_HELP_STRING([--enable-kqueue],[Force kqueue() usage.]),
[SELECT_TYPE_EXPLICIT="kqueue"; echo "Forcing kqueue() to be enabled"],)

AC_ARG_ENABLE(devpoll,
AC_HELP_STRING([--enable-devpoll],[Force usage of /dev/poll.]),
[SELECT_TYPE_EXPLICIT="devpoll"
echo "Forcing /dev/poll to be enabled"
dnl These need to be defined or not defined
AC_CHECK_HEADERS([sys/devpoll.h devpoll.h])],)

AC_ARG_ENABLE(rtsigio,
AC_HELP_STRING([--enable-rtsigio],[Enable SIGIO with RT Signals (Linux only)]),
[SELECT_TYPE_EXPLICIT="sigio"; echo "Forcing Linux RT Sigio to be enabled"],)

AC_ARG_ENABLE(epoll,
AC_HELP_STRING([--enable-epoll], [Enable Linux epoll support.]),
[SELECT_TYPE_EXPLICIT="epoll"; echo "Forcing Linux epoll to be enabled"],)

if test ! -z "$SELECT_TYPE_EXPLICIT"; then
	SELECT_TYPE="$SELECT_TYPE_EXPLICIT"
else

AC_CHECK_FUNC([kevent],
[
	SELECT_TYPE="kqueue"
],
[
	AC_CHECK_HEADER(sys/epoll.h, [HAS_EPOLL=1], [HAS_EPOLL=0])
	if test $HAS_EPOLL -eq 1; then
		AC_MSG_CHECKING(for epoll support in kernel)
		AC_TRY_RUN(
#include <sys/epoll.h>
#include <sys/syscall.h>
#if defined(__stub_epoll_create) || defined(__stub___epoll_create) || defined(EPOLL_NEED_BODY)
#if !defined(__NR_epoll_create)
#if defined(__ia64__)
#define __NR_epoll_create 1243
#elif defined(__x86_64__)
#define __NR_epoll_create 214
#elif defined(__sparc64__) || defined(__sparc__)
#define __NR_epoll_create 193
#elif defined(__s390__) || defined(__m68k__)
#define __NR_epoll_create 249
#elif defined(__ppc64__) || defined(__ppc__)
#define __NR_epoll_create 236
#elif defined(__parisc__) || defined(__arm26__) || defined(__arm__)
#define __NR_epoll_create 224
#elif defined(__alpha__)
#define __NR_epoll_create 407
#elif defined(__sh64__)
#define __NR_epoll_create 282
#elif defined(__i386__) || defined(__sh__) || defined(__m32r__) || defined(__h8300__) || defined(__frv__)
#define __NR_epoll_create 254
#else
#error No system call numbers defined for epoll family.
#endif
#endif
_syscall1(int, epoll_create, int, size)
#endif
main() { return epoll_create(256) == -1 ? 1 : 0; },
		[AC_MSG_RESULT(yes)
		SELECT_TYPE="epoll"],
		[AC_MSG_RESULT(no)
		HAS_EPOLL=0],
		[AC_MSG_RESULT(no)
		HAS_EPOLL=0])
	fi
	if test $HAS_EPOLL -eq 0; then
		AC_MSG_CHECKING(for /dev/poll)
		if test -c "/dev/poll"; then
			AC_MSG_RESULT(yes)
			AC_CHECK_HEADERS([devpoll.h sys/devpoll.h])
			SELECT_TYPE="devpoll"
		else
			AC_MSG_RESULT(no)
			AC_MSG_CHECKING(for RT Signal IO)

			dnl check for rtsig readiness notification under Linux
			dnl (but don't use it unless kernel 2.4 or higher)
			AC_EGREP_CPP(YUP_HAVE_F_SETSIG,
			[#define _GNU_SOURCE
			#include <fcntl.h>
			#ifdef F_SETSIG
			 YUP_HAVE_F_SETSIG
			#endif
			],
			[
				SELECT_TYPE="sigio"
				AC_MSG_RESULT(yes)
			],
			[
				AC_MSG_RESULT(no)
				AC_CHECK_FUNC(poll, [SELECT_TYPE="poll"],
				[
					AC_CHECK_FUNC(select, [SELECT_TYPE="select"],
					[AC_MSG_ERROR([Couldn't find anything to use for IO loop. Is your C environment POSIXly sane?])
					])
				])
			])
		fi
	fi
])

fi

echo "Using $SELECT_TYPE for select loop."

AC_DEFINE_UNQUOTED(SELECT_TYPE, "$SELECT_TYPE", [This is the type of IO loop we are using])
AC_SUBST(SELECT_TYPE)


dnl Debug-related options
dnl =====================

AC_ARG_ENABLE(clobber,
AC_HELP_STRING([--enable-clobber], [Don't preserve old binaries on make install]),
[clobber=$enableval], [clobber=no])

if test "$clobber" = yes; then
	AC_SUBST(CLOBBER, yes)
fi

AC_ARG_ENABLE(assert,
AC_HELP_STRING([--enable-assert],[Enable assert().]),
[assert=$enableval], [assert=no])

if test "$assert" = no; then
	AC_DEFINE(NDEBUG, 1, [Define this to disable debugging support.])
fi

AC_MSG_CHECKING(if you want to do a profile build)
AC_ARG_ENABLE(profile,
AC_HELP_STRING([--enable-profile],[Enable profiling]),
[profile=$enableval], [profile=no])

if test "$profile" = yes; then
	if test "$ac_cv_c_compiler_gnu" = yes; then
		IRC_CFLAGS="$IRC_CFLAGS -pg -static"
		AC_MSG_RESULT="yes, adding -pg -static"
	else
		AC_MSG_RESULT([no, profile builds only work with gcc])
	fi
else
	AC_MSG_RESULT(no)
fi

dnl Check if we want to use efence
AC_MSG_CHECKING(if you want ElectricFence)
AC_ARG_ENABLE(efence,
AC_HELP_STRING([--enable-efence],[Enable ElectricFence (memory debugger).]),
[
if test "$enableval" != no; then
	if test ! -z "$enableval" -a "$enableval" != yes; then
		LIBS="$LIBS -L$enableval"
	fi

	AC_CHECK_LIB(efence, malloc,
	[
		LIBS="$LIBS -lefence"
		AC_MSG_RESULT(yes)
	],
	[AC_MSG_RESULT(not found, disabling)])
else
	AC_MSG_RESULT(no)
fi
],[AC_MSG_RESULT(no)])

dnl Check if we want to enable the block allocator
AC_MSG_CHECKING(if you want the block allocator)
AC_ARG_ENABLE(block-alloc,
AC_HELP_STRING([--disable-block-alloc],[Disable the block allocator (Only useful with ElectricFence)]),
[balloc=$enableval], [balloc=yes])

if test "$balloc" = no; then
	AC_SUBST(BALLOC_C, [])
	AC_DEFINE(NOBALLOC, 1, [Disable the block allocator.])
else
	AC_SUBST(BALLOC_C, balloc.c)
fi

AC_MSG_RESULT($balloc)

AC_ARG_ENABLE(warnings,
AC_HELP_STRING([--enable-warnings],[Enable all sorts of warnings for debugging.]),
[IRC_CFLAGS="$IRC_CFLAGS -Wcast-qual -Wmissing-declarations -Wmissing-prototypes -Wnested-externs -Wredundant-decls -Wshadow -Wwrite-strings -W -Wno-unused"],[])

dnl Server Tweaks
dnl =============

AC_ARG_ENABLE(small-net,
AC_HELP_STRING([--enable-small-net],[Enable small network support.]),
[small_net=$enableval], [small_net=no])

if test "$small_net" = yes; then
	AC_DEFINE([NICKNAMEHISTORYLENGTH], 1500, [Size of the WHOWAS array.])
	AC_DEFINE([CHANNEL_HEAP_SIZE], 256, [Size of the channel heap.])
	AC_DEFINE([BAN_HEAP_SIZE], 128, [Size of the ban heap.])
	AC_DEFINE([CLIENT_HEAP_SIZE], 256, [Size of the client heap.])
	AC_DEFINE([LCLIENT_HEAP_SIZE], 128, [Size of the local client heap.])
	AC_DEFINE([DNODE_HEAP_SIZE], 256, [Size of the dlink_node heap.])
	AC_DEFINE([TOPIC_HEAP_SIZE], 256, [Size of the topic heap.])
	AC_DEFINE([DBUF_HEAP_SIZE], 64, [Size of the dbuf heap.])
else
	AC_DEFINE([NICKNAMEHISTORYLENGTH], 15000, [Size of the WHOWAS array.])
	AC_DEFINE([CHANNEL_HEAP_SIZE], 1024, [Size of the channel heap.])
	AC_DEFINE([BAN_HEAP_SIZE], 1024, [Size of the ban heap.])
	AC_DEFINE([CLIENT_HEAP_SIZE], 1024, [Size of the client heap.])
	AC_DEFINE([LCLIENT_HEAP_SIZE], 512, [Size of the local client heap.])
	AC_DEFINE([DNODE_HEAP_SIZE], 2048, [Size of the dlink_node heap.])
	AC_DEFINE([TOPIC_HEAP_SIZE], 1024, [Size of the topic heap.])
	AC_DEFINE([DBUF_HEAP_SIZE], 512, [Size of the dbuf heap.])
fi

AC_ARG_ENABLE(efnet,
AC_HELP_STRING([--enable-efnet],[For IRCDs running on EFnet.]),
[efnet=$enableval], [efnet=no])

if test "$efnet" = yes; then
	AC_DEFINE(EFNET, 1, [Define if this ircd will be an EFnet server.])
	AC_DEFINE(TS5_ONLY, 1, [If enabled, server links to your network must have a minimum of TS5.])
	echo "Building ircd for use with EFnet"
	EXAMPLE_CONF=example.efnet.conf
else
	AC_DEFINE(INVARIANTS, 1, [Miscellaneous sanity checks for the ircd. Makes it slightly slower])
	EXAMPLE_CONF=example.conf
fi

AC_ARG_ENABLE(gline-voting,
AC_HELP_STRING([--disable-gline-voting],[Disable G-line voting.]),
[gline_voting=$enableval], [gline_voting=yes])

if test "$gline_voting" = yes; then
	AC_DEFINE(GLINE_VOTING, 1, [Define this if you want to enable gline voting.])
	echo "Building ircd with G-Line voting support"
fi

AC_ARG_ENABLE(halfops,
AC_HELP_STRING([--enable-halfops],[Enable halfops support.]),
[halfops=$enableval], [halfops=no])

if test "$halfops" = yes; then
	AC_DEFINE(HALFOPS, 1, [Define if you want halfops support.])
fi

AC_SUBST(EXAMPLE_CONF)

AC_MSG_CHECKING(for syslog options)

AC_ARG_ENABLE(syslog,
AC_HELP_STRING([--enable-syslog="EVENTS"], [Enable syslog for events: kill, squit, connect, users, oper, space separated in quotes (default: disabled)]),
[
dnl Hopelessly swiped from the mozilla source (kind of)

dnl We must have these headers for it to work..
if test "$ac_cv_header_sys_syslog_h" = yes -o "$ac_cv_header_syslog_h" = yes; then

if test "$enableval" != no; then
	syslogstuff=core

for option in $enableval; do
case "$option" in
	kill)
		syslogstuff="$syslogstuff kill"
		AC_DEFINE(SYSLOG_KILL, 1, [Send oper kills to syslog])
	;;
	squit)
		syslogstuff="$syslogstuff squit"
		AC_DEFINE(SYSLOG_SQUIT, 1, [Send remote squits for all servers to syslog])
	;;
	connect)
		syslogstuff="$syslogstuff connect"
		AC_DEFINE(SYSLOG_CONNECT, 1, [Send connect notices for other servers to syslog])
	;;
	users)
		syslogstuff="$syslogstuff users"
		AC_DEFINE(SYSLOG_USERS, 1, [Send user log stuff to syslog])
	;;
	oper)
		syslogstuff="$syslogstuff oper"
		AC_DEFINE(SYSLOG_OPER, 1, [Send /OPER successes to syslog])
	;;
dnl yes is okay, shut up you
	yes)
	;;
	*)
		AC_MSG_WARN(unknown event $option)
	;;
esac
done
	
	if test ! -z "$syslogstuff" -o "$enableval" = yes; then
		AC_DEFINE(USE_SYSLOG, 1, [Send vital ircd messages to syslog])
	fi
else dnl $enableval is no
	syslogstuff=none
fi

else dnl checking for syslog.h's
	AC_MSG_WARN([both syslog.h and sys/syslog.h unavailable, not enabling syslog])
	syslogstuff=none
fi
],[syslogstuff=none])

AC_MSG_RESULT($syslogstuff)

AC_ARG_WITH(syslog-facility,
AC_HELP_STRING([--with-syslog-facility=LOG], [Define the log facility to use with ircd's syslog output (default LOG_LOCAL4)]),
[facility=$withval],[facility="LOG_LOCAL4"])

if test "$syslogstuff" != none; then
AC_DEFINE_UNQUOTED(LOG_FACILITY, $facility, [Log facility to use for syslog()])
fi

AC_ARG_WITH(nicklen,
AC_HELP_STRING([--with-nicklen=LENGTH],[Set the nick length to LENGTH (default 9)]),
	NICKLEN="$withval", NICKLEN="9")

AC_ARG_WITH(topiclen,           
AC_HELP_STRING([--with-topiclen=NUMBER],[Set the max topic length to NUMBER (default 160, max 390)]),
[
 if test $withval -ge 390; then
	TOPICLEN=390
	AC_MSG_WARN([TOPICLEN has a hard limit of 390. Setting TOPICLEN=390])
 else
 	TOPICLEN=$withval
 fi
], [TOPICLEN=160])

AC_DEFINE_UNQUOTED(TOPICLEN, ${TOPICLEN}, [Maximum topic length (<=390)])
AC_DEFINE_UNQUOTED(NICKLEN, (${NICKLEN}+1), [Nickname length])

AC_ARG_ENABLE(shared-modules,
AC_HELP_STRING([--disable-shared-modules],[ Disable shared modules.]),
[shared_modules=$enableval], [shared_modules="yes"])

dnl Some first-stage sanity checks.
if test "$shared_modules" = yes; then
  	
	if test "$profile" = "no"; then
		shared_modules="yes"
	else
		AC_MSG_WARN([disabling shared modules; cannot coexist with profile builds])
		shared_modules="no"
	fi

	if test "$CYGWIN" = yes; then
		AC_MSG_WARN([disabling shared modules; Cygwin is at present unable to build them.])
		shared_modules="no"
	fi

	dnl TenDRA's cc is called tcc too.
	if test "$CC" = tcc -a "$TenDRA" = "no"; then
		AC_MSG_WARN([disabling shared modules: Tiny C Compiler can't create PIC])
		shared_modules="no"
	fi
fi

dnl Second stage: check for functions and headers.
if test "$shared_modules" = yes; then
	DYNLINK_C=dynlink.c
	AC_CHECK_HEADERS(dlfcn.h)
	AC_SEARCH_LIBS(shl_load, dld, 
	[
	  AC_DEFINE(HAVE_SHL_LOAD, 1, [Define if the shl_load function is available.])
	  SUFFIX=".sl"
	  MOD_TARGET=hpux_shared
	  SEDOBJ="s/\.o/.sl/g"  
	],
	dnl !shl_load:
	[
          dnl standard dlopen
          AC_SEARCH_LIBS(dlopen, [dl c_r],
	  [
	    AC_DEFINE(HAVE_DLOPEN, 1, [Define if the dlopen function is available.])
	    SUFFIX=".so"
	    MOD_TARGET=shared_modules
	    SEDOBJ="s/\.o/.so/g"
	    if test "$AppleGCC" = yes; then
              AC_CHECK_HEADERS([mach-o/dyld.h])
            fi
	    AC_CHECK_FUNC(dlsym, ,
	    [
	      AC_MSG_WARN([dlsym is not available, shared modules disabled])
	      shared_modules=no
	    ])
	    AC_CHECK_FUNCS(dlfunc dlinfo)
	  ],
	  [
	    shared_modules=no
	  ])
	])
fi

AC_DEFINE_UNQUOTED(SHARED_SUFFIX, "$SUFFIX", [Suffix for shared libraries on this platform.])

dnl Third stage - wrangling the linker.
if test "$shared_modules" = yes; then
	# The GNU linker requires the -export-dynamic option to make
	# all symbols visible in the dynamic symbol table.
	hold_ldflags=$LDFLAGS
	AC_MSG_CHECKING(for the ld -export-dynamic flag)
	LDFLAGS="${LDFLAGS} -Wl,-export-dynamic"
	AC_LINK_IFELSE(AC_LANG_PROGRAM([],[int i;]), found=yes, found=no)
	LDFLAGS=$hold_ldflags

	if expr "`uname -s`" : ^IRIX >/dev/null 2>&1; then
		found="no, IRIX ld uses -B,dynamic"
		LDFLAGS="${LDFLAGS} -Wl,-B,dynamic"
	fi

	AC_MSG_RESULT($found)

	if test "$found" = yes; then
		LDFLAGS="${LDFLAGS} -Wl,-export-dynamic"
	fi

	AC_MSG_CHECKING(for compiler option to produce PIC)
	dnl The order should be here to check for groups of compilers,
	dnl then for odd compilers, then if no PICFLAGS were set up,
	dnl check for GCC and set defaults, or else error. -jmallett
	if test "$SGS" = "yes"; then
		AC_MSG_RESULT([SVR4 SGS interfaces: -KPIC -DPIC -G])
		PICFLAGS="-KPIC -DPIC -G"
	fi
	
	if test "$AppleGCC" = "yes"; then
		AC_MSG_RESULT([Darwin Mach-O bundles: -fno-common -bundle -flat_namespace -undefined suppress])
		PICFLAGS="-fno-common -bundle -flat_namespace -undefined suppress"
	fi
	dnl Please note, that on HPUX two different stages of module compilation occurs, since
	dnl while compiling modules, the compiler does not allow you to give arguments
	dnl to the linker. (I did not design this) 
	dnl So we need -c in the first stage of module compilation.
	dnl In the second stage, we link the modules via ld -b.
	dnl Additionally, HPUX does not like -export-dynamic, it likes -E instead.
	dnl -TimeMr14C
	if test "$HPUX" = "yes" -a "$ac_cv_c_compiler_gnu" = no; then
		AC_MSG_RESULT(HP-UX cc: +z -r -q -n)
		PICFLAGS="+z -r -q -n -c"
		AC_MSG_CHECKING([if +ESfic is required on this platform])
		
		if expr "`$CC +ESfic 2>&1`" : ".*neither supported.*" >/dev/null; then 
			AC_MSG_RESULT(no)
		else
			AC_MSG_RESULT(yes)
			PICFLAGS="$PICFLAGS +ESfic"
		fi

		LDFLAGS="${LDFLAGS} -Wl,-E"
	fi
	if test "$Tru" = yes -a "$ac_cv_c_compiler_gnu" = no; then
		AC_MSG_RESULT([Tru64: -shared -expect_unresolved '*'])
		PICFLAGS="-shared -expect_unresolved '*' "
		LDFLAGS="-call_shared"
	fi
	if test -z "$PICFLAGS"; then
		if test "$ac_cv_c_compiler_gnu" = "yes"; then
			AC_MSG_RESULT(gcc: -fPIC -DPIC -shared)
			PICFLAGS="-fPIC -DPIC -shared"
		else
			AC_MSG_RESULT(no)
			shared_modules=no
		fi
	fi
fi

if test "$shared_modules" = no; then
	DYNLINK_C=""
	MOD_TARGET="libmodules.a"
	MODULES_LIBS="../modules/libmodules.a"
	SEDOBJ=""
	AC_DEFINE(STATIC_MODULES, 1, [Define to 1 if dynamic modules can't be used.])
	AC_MSG_WARN([shared module support has been disabled!])
fi

AC_SUBST(MODULES_LIBS)
AC_SUBST(MOD_TARGET)

AC_SUBST(SSL_SRCS_ENABLE)
AC_SUBST(SSL_INCLUDES)
AC_SUBST(SSL_LIBS)

AC_SUBST(PICFLAGS)
AC_SUBST(IRC_CFLAGS)
AC_SUBST(SEDOBJ)

AC_SUBST(DYNLINK_C)

if test "$prefix" = "NONE"; then 
	AC_DEFINE_UNQUOTED(IRCD_PREFIX, "$ac_default_prefix", [Prefix where the ircd is installed.])

else

dnl Don't get bitten by Cygwin's stupidity if the user specified
dnl a custom prefix with a trailing slash

	prefix=`echo $prefix | sed 's/\/$//'`
	AC_DEFINE_UNQUOTED(IRCD_PREFIX, "$prefix", [Prefix where the ircd is installed.])
	
fi

AC_CONFIG_FILES(		\
	Makefile		\
	etc/Makefile		\
	servlink/Makefile	\
	contrib/Makefile	\
	contrib/help/Makefile	\
	src/Makefile		\
	messages/Makefile	\
	modules/Makefile	\
	tools/Makefile		\
	doc/Makefile		\
	help/Makefile		\
	lib/Makefile		\
	lib/pcre/Makefile
)

AC_OUTPUT

dnl Configure options probably changed
rm -f src/.depend modules/.depend servlink/.depend contrib/.depend lib/pcre/.depend

dnl Make it look sexay!

echo
echo "Compiling $PACKAGE_NAME $PACKAGE_VERSION"
echo

echo "Installing into: $prefix"

echo "Ziplinks ................ $zlib"

if test ! -z "$cf_openssl_ciphers"; then
	tmpresult="yes - ${cf_openssl_ciphers}"
else
	tmpresult=no
fi

echo "OpenSSL ................. $tmpresult"

if test "$shared_modules" = yes; then
	tmpresult=shared
else
	tmpresult=static
fi

echo  "Modules ................. $tmpresult"
echo  "IPv6 support ............ $have_v6"
echo  "Net I/O implementation .. $SELECT_TYPE"

if test "$efnet" = "yes"; then
	tmpresult="yes (use example.efnet.conf)"
else
	tmpresult="no (use example.conf)"
fi

echo "EFnet server ............ $tmpresult"
echo "Halfops support ......... $halfops"
echo "Small network ........... $small_net"
echo "G-Line voting ........... $gline_voting"
echo
echo "Configured limits:"
echo "NICKLEN ................. $NICKLEN"
echo "TOPICLEN ................ $TOPICLEN"
echo

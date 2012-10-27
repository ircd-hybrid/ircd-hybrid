# $Id$
# This file is by Joshua Kwan, and the source is in the public domain.

AC_INIT
AC_CONFIG_FILES(Makefile)

AC_COPYRIGHT([$Id$])

AC_PROG_CC

AC_CHECK_LIB(crypto, RSA_private_decrypt, [LIBS="-lcrypto"],
[
	LIBS="$LIBS -L/usr/local/lib"
	AC_CHECK_LIB(crypto, RSA_private_decrypt, [LIBS="$LIBS -lcrypto"], 
		[AC_MSG_ERROR([Could not find libcrypto.])])
])

AC_MSG_CHECKING([for location of OpenSSL includes])

for dirs in /usr /usr/local/ssl /usr/pkg /usr/local /usr/local/openssl ; do
	if test -f "${dirs}/include/openssl/opensslv.h" ; then
		INCLUDES="${dirs}/include"
		break
	fi
done

AC_MSG_RESULT($INCLUDES)
AC_SUBST(INCLUDES)

if test "$ac_cv_c_compiler_gnu" = yes; then
	CFLAGS="$CFLAGS -Wall"
fi

if test "$ac_cv_prog_cc_g" = yes; then
	CFLAGS="$CFLAGS -g"
fi

AC_SUBST(CFLAGS)

AC_OUTPUT

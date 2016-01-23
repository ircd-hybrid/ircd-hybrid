AC_DEFUN([AX_ARG_GNUTLS], [
AC_ARG_ENABLE(gnutls,
[  --enable-gnutls             Enable GnuTLS support.
  --disable-gnutls             Disable GnuTLS support. ],
[ cf_enable_gnutls=$enableval ],
[ cf_enable_gnutls="auto" ])

if test "$cf_enable_openssl" != "auto" &&
   test "$cf_enable_openssl" != "yes"; then
  if test "$cf_enable_gnutls" != "no"; then
    AC_CHECK_HEADER(gnutls/gnutls.h, [AC_CHECK_LIB(gnutls, gnutls_init)], [], [])
  fi
fi
])

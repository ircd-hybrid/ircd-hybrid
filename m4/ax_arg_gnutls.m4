AC_DEFUN([AX_ARG_GNUTLS], [
AC_ARG_ENABLE(gnutls,
[  --enable-gnutls             Enable GnuTLS support.
  --disable-gnutls             Disable GnuTLS support. ],
[ cf_enable_gnutls=$enableval ],
[ cf_enable_gnutls="auto" ])

if test "$cf_enable_openssl" != "auto" &&
   test "$cf_enable_openssl" != "yes"; then
  if test "$cf_enable_gnutls" != "no"; then

    AC_CHECK_HEADER(gnutls/gnutls.h, [
      AC_RUN_IFELSE([
        AC_LANG_PROGRAM([
          #include <gnutls/gnutls.h>
          #include <stdlib.h>], [
          exit(!(GNUTLS_VERSION_NUMBER >= 0x030308)); ])], [ AC_CHECK_LIB(gnutls, gnutls_init, [], [])], [], [])])

    AC_MSG_CHECKING(for GnuTLS 3.3.8 and above)
    AS_IF([test "$ac_cv_lib_gnutls_gnutls_init" = "yes"],
          [AC_MSG_RESULT(found)], [AC_MSG_RESULT(no - GnuTLS support disabled)])

  fi
fi
])

AC_DEFUN([AX_ARG_WOLFSSL], [
AC_ARG_ENABLE(wolfssl,
[  --enable-wolfssl             Enable wolfSSL support.
  --disable-wolfssl             Disable wolfSSL support. ],
[ cf_enable_wolfssl=$enableval ],
[ cf_enable_wolfssl="auto" ])

if test "$cf_enable_openssl" != "auto" &&
   test "$cf_enable_openssl" != "yes"; then
  if test "$cf_enable_gnutls" = "no"; then

    AC_CHECK_HEADER(wolfssl/ssl.h, [
      AC_RUN_IFELSE([
        AC_LANG_PROGRAM([
          #include <wolfssl/version.h>
          #include <stdlib.h>], [
          exit(!(LIBWOLFSSL_VERSION_HEX >= 0x04003000)); ])], [ AC_CHECK_LIB(wolfssl, wolfSSL_X509_digest, [], [])], [], [])])

    AC_MSG_CHECKING(for wolfSSL 4.3.0 and above built with extended/full OpenSSL compatibility layer)
    AS_IF([test "$ac_cv_lib_wolfssl_wolfSSL_X509_digest" = "yes"],
          [AC_MSG_RESULT(found)], [AC_MSG_RESULT(no - wolfSSL support disabled)])

  fi
fi
])

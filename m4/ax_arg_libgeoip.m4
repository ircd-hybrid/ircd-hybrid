AC_DEFUN([AX_ARG_LIBGEOIP],[
  AC_ARG_ENABLE(libgeoip,
    [AS_HELP_STRING([--disable-libgeoip],[Disable GeoIP support])], [],
      [AC_CHECK_HEADER(GeoIP.h,
        [AC_SEARCH_LIBS(GeoIP_id_by_ipnum_v6_gl, GeoIP,
          [AC_DEFINE(HAVE_LIBGEOIP, 1, [Define to 1 if libGeoIP (-lGeoIP) is available.])])])], [])
])

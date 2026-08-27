AC_DEFUN([AX_CHECK_STRFTIME_MINUS_E], [
  AC_CACHE_CHECK(
    [whether strftime supports GNU-style %-e],
    [ax_cv_func_strftime_minus_e],
    [
      AC_RUN_IFELSE(
        [AC_LANG_PROGRAM(
          [[
#include <string.h>
#include <time.h>
          ]],
          [[
char buf[32];
struct tm tm;

memset(&tm, 0, sizeof(tm));
tm.tm_mday = 2;
tm.tm_mon = 0;
tm.tm_year = 100;

return strftime(buf, sizeof(buf), "%-e", &tm) > 0 && strcmp(buf, "2") == 0 ? 0 : 1;
          ]]
        )],
        [ax_cv_func_strftime_minus_e=yes],
        [ax_cv_func_strftime_minus_e=no],
        [ax_cv_func_strftime_minus_e=no]
      )
    ]
  )

  AS_IF(
    [test "x$ax_cv_func_strftime_minus_e" = xyes],
    [AC_DEFINE(
      [HAVE_STRFTIME_MINUS_E],
      [1],
      [Define to 1 if strftime supports the GNU %-e extension.]
    )]
  )
])

AC_DEFUN([AX_CHECK_STRFTIME_MINUS_E], [
  AC_ARG_WITH([strftime-minus-e],
    [AS_HELP_STRING([--with-strftime-minus-e],
      [Control the check for GNU strftime %-e support @<:@auto/yes/no@:>@])],
    [],
    [with_strftime_minus_e=auto]
  )

  AC_CACHE_CHECK([for GNU-style “%-e” no-padding day-of-month],
    [ax_cv_func_strftime_minus_e],
    [
      ax_cv_func_strftime_minus_e="$with_strftime_minus_e"

      AS_IF([test "x$ax_cv_func_strftime_minus_e" = xauto], [
        AC_RUN_IFELSE(
          [AC_LANG_PROGRAM(
            [[#include <time.h>
              #include <string.h>
              #include <stdio.h>
            ]],
            [[
              char buf[32];
              struct tm tm;
              memset(&tm, 0, sizeof(tm));
              tm.tm_mday = 2; tm.tm_mon = 0; tm.tm_year = 100;
              if (strftime(buf, sizeof(buf), "%-e", &tm) > 0 && strcmp(buf, "2") == 0)
                return 0;
              return 1;
            ]]
          )],
          [ax_cv_func_strftime_minus_e=yes],
          [ax_cv_func_strftime_minus_e=no],
          [
            ax_cv_func_strftime_minus_e=no
            AC_MSG_WARN([Cannot run test for strftime %-e support.])
            AC_MSG_WARN([Assuming 'no'. Use --with-strftime-minus-e=yes to override.])
          ]
        )
      ])
    ]
  )

  if test "x$ax_cv_func_strftime_minus_e" = xyes; then
    AC_DEFINE([HAVE_STRFTIME_MINUS_E], [1],
      [Define to 1 if strftime supports the GNU %-e extension.])
  fi
])

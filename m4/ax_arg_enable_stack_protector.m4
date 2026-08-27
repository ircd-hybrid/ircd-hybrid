AC_DEFUN([AX_ARG_ENABLE_STACK_PROTECTOR], [
  AC_REQUIRE([AC_PROG_CC])
  AC_LANG_PUSH([C])

  AC_CACHE_CHECK(
    [whether $CC supports -fstack-protector-strong],
    [ax_cv_c_stack_protector_strong],
    [
      ax_save_CFLAGS=$CFLAGS
      CFLAGS="$CFLAGS -fstack-protector-strong"

      AC_LINK_IFELSE(
        [AC_LANG_PROGRAM(
          [],
          [[
volatile char buffer[16];

buffer[0] = 0;
return buffer[0];
          ]]
        )],
        [ax_cv_c_stack_protector_strong=yes],
        [ax_cv_c_stack_protector_strong=no]
      )

      CFLAGS=$ax_save_CFLAGS
    ]
  )

  AS_IF(
    [test "x$ax_cv_c_stack_protector_strong" = xyes],
    [CFLAGS="$CFLAGS -fstack-protector-strong"],
    [
      AC_CACHE_CHECK(
        [whether $CC supports -fstack-protector],
        [ax_cv_c_stack_protector],
        [
          ax_save_CFLAGS=$CFLAGS
          CFLAGS="$CFLAGS -fstack-protector"

          AC_LINK_IFELSE(
            [AC_LANG_PROGRAM(
              [],
              [[
volatile char buffer[16];

buffer[0] = 0;
return buffer[0];
              ]]
            )],
            [ax_cv_c_stack_protector=yes],
            [ax_cv_c_stack_protector=no]
          )

          CFLAGS=$ax_save_CFLAGS
        ]
      )

      AS_IF(
        [test "x$ax_cv_c_stack_protector" = xyes],
        [CFLAGS="$CFLAGS -fstack-protector"]
      )
    ]
  )

  AC_LANG_POP([C])
])

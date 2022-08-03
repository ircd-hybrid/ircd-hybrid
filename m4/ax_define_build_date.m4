AC_DEFUN([AX_DEFINE_BUILD_DATE],[
  LC_ALL=C
  LANGUAGE=C
  export LC_ALL
  export LANGUAGE

  DATE_FMT="+%B %-e %Y at %T%z"
  SOURCE_DATE_EPOCH="${SOURCE_DATE_EPOCH:-$(date +%s)}"
  BUILD_DATE=$(date -u -d "@$SOURCE_DATE_EPOCH" "$DATE_FMT" 2>/dev/null || date -u -r "$SOURCE_DATE_EPOCH" "$DATE_FMT" 2>/dev/null || date -u "$DATE_FMT")
  AC_DEFINE_UNQUOTED([AX_BUILD_DATE],["$BUILD_DATE"],[Defines the build date])
])

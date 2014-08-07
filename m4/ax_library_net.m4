AC_DEFUN([AX_LIBRARY_NET],[
  AC_CHECK_FUNC(getaddrinfo, [], AC_SEARCH_LIBS(getaddrinfo, nsl))
  AC_CHECK_FUNC(getnameinfo, [], AC_SEARCH_LIBS(getnameinfo, nsl))
  AC_SEARCH_LIBS([socket],[socket],,[AC_MSG_ERROR([socket library not found])])
])

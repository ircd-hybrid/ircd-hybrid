/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  rlimits.h: sidestep configure test for RLIMIT_* values.
 *
 *  This code is in the public domain.
 *
 *  $Id$
 */

#ifndef INCLUDED_rlimits_h
#define INCLUDED_rlimits_h

#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>

/* This nest of #ifdefs is because not all 'cpp's support #elif */

#ifdef RLIMIT_FDMAX
# define RLIMIT_FD_MAX RLIMIT_FDMAX
#else
# ifdef RLIMIT_NOFILE
#  define RLIMIT_FD_MAX RLIMIT_NOFILE
# else
#  ifdef RLIMIT_OPEN_MAX
#   define RLIMIT_FD_MAX RLIMIT_OPEN_MAX
#  else
#   warning No file descriptor limit was found
#  endif
# endif
#endif

#endif /* HAVE_SYS_RESOURCE_H */

#endif /* INCLUDED_rlimits_h */

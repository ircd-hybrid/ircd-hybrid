AM_CPPFLAGS = -I$(top_srcdir)/src
noinst_LTLIBRARIES = libio.la

libio_la_SOURCES =  address.c     \
                    address.h     \
                    base32.c      \
                    base32.h      \
                    comm.c        \
                    comm.h        \
                    comm_epoll.c  \
                    comm_kqueue.c \
                    comm_poll.c   \
                    dbuf.c        \
                    dbuf.h        \
                    event.c       \
                    event.h       \
                    fdlist.c      \
                    fdlist.h      \
                    hook.c        \
                    hook.h        \
                    io.h          \
                    io_getopt.c   \
                    io_getopt.h   \
                    irc_string.c  \
                    irc_string.h  \
                    list.c        \
                    list.h        \
                    log.c         \
                    log.h         \
                    match.c       \
                    misc.c        \
                    misc.h        \
                    memory.c      \
                    memory.h      \
                    patricia.c    \
                    patricia.h    \
                    res.c         \
                    res.h         \
                    reslib.c      \
                    reslib.h      \
                    rng_mt.c      \
                    rng_mt.h      \
                    sha3.c        \
                    sha3.h        \
                    tls.h         \
                    tls_gnutls.c  \
                    tls_gnutls.h  \
                    tls_none.c    \
                    tls_none.h    \
                    tls_openssl.c \
                    tls_openssl.h \
                    tls_wolfssl.c \
                    tls_wolfssl.h

libio_la_LIBADD = @LTLIBOBJS@

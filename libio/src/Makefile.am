AM_CPPFLAGS = $(LTDLINCL) -I$(top_srcdir)/src
noinst_LTLIBRARIES = libio.la
libio_la_DEPENDENCIES = $(LTDLDEPS)
libio_la_LIBADD = @LTLIBOBJS@ $(LIBLTDL)
libio_la_LDFLAGS = -export-dynamic -avoid-version

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
                    io_signal.c   \
                    io_signal.h   \
                    irc_string.c  \
                    irc_string.h  \
                    io_time.c     \
                    io_time.h     \
                    list.c        \
                    list.h        \
                    log.c         \
                    log.h         \
                    match.c       \
                    misc.c        \
                    misc.h        \
                    memory.c      \
                    memory.h      \
                    module.c      \
                    module.h      \
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

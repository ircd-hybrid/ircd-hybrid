AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = ircd

AM_YFLAGS = -d

AM_CPPFLAGS = $(LTDLINCL) -I$(top_srcdir)/include
ircd_LDFLAGS = -export-dynamic
ircd_LDADD = $(LIBLTDL)
ircd_DEPENDENCIES = $(LTDLDEPS)

ircd_SOURCES = channel.c         \
               channel_mode.c    \
               client.c          \
               conf.c            \
               conf_class.c      \
               conf_db.c         \
               conf_parser.y     \
               conf_lexer.l      \
               dbuf.c            \
               event.c           \
               fdlist.c          \
               getopt.c          \
               gline.c           \
               hash.c            \
               hook.c            \
               hostmask.c        \
               irc_res.c         \
               irc_reslib.c      \
               irc_string.c      \
               ircd.c            \
               ircd_signal.c     \
               list.c            \
               listener.c        \
               log.c             \
               match.c           \
               memory.c          \
               mempool.c         \
               modules.c         \
               motd.c            \
               rng_mt.c          \
               numeric.c         \
               packet.c          \
               parse.c           \
               s_bsd_epoll.c     \
               s_bsd_poll.c      \
               s_bsd_devpoll.c   \
               s_bsd_kqueue.c    \
               s_bsd_select.c    \
               restart.c         \
               resv.c            \
               rsa.c             \
               s_auth.c          \
               s_bsd.c           \
               s_misc.c          \
               s_serv.c          \
               s_user.c          \
               send.c            \
               version.c         \
               watch.c           \
               whowas.c

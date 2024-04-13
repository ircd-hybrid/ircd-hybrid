AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = ircd

AM_YFLAGS = -d

AM_CPPFLAGS = $(LTDLINCL) -I$(top_srcdir)/include -I$(top_srcdir)/libio/src
ircd_LDFLAGS = -export-dynamic
ircd_LDADD = $(LIBLTDL) ../libio/src/.libs/libio.a
ircd_DEPENDENCIES = $(LTDLDEPS)

ircd_SOURCES = accept.c          \
               auth.c            \
               channel.c         \
               channel_invite.c  \
               channel_mode.c    \
               client.c          \
               client_svstag.c   \
               cloak.c           \
               command.c         \
               conf.c            \
               conf_class.c      \
               conf_cluster.c    \
               conf_db.c         \
               conf_gecos.c      \
               conf_pseudo.c     \
               conf_resv.c       \
               conf_service.c    \
               conf_shared.c     \
               conf_parser.y     \
               conf_lexer.l      \
               extban.c          \
               extban_account.c  \
               extban_channel.c  \
               extban_fingerprint.c \
               extban_gecos.c    \
               extban_join.c     \
               extban_knock.c    \
               extban_mute.c     \
               extban_nick.c     \
               extban_operclass.c \
               extban_server.c   \
               extban_tlsinfo.c  \
               extban_usermode.c \
               fdlist.c          \
               hash.c            \
               hostmask.c        \
               id.c              \
               ipcache.c         \
               ircd.c            \
               ircd_signal.c     \
               isupport.c        \
               listener.c        \
               modules.c         \
               monitor.c         \
               motd.c            \
               numeric.c         \
               packet.c          \
               parse.c           \
               s_bsd_epoll.c     \
               s_bsd_poll.c      \
               s_bsd_kqueue.c    \
               tls_gnutls.c      \
               tls_none.c        \
               tls_openssl.c     \
               tls_wolfssl.c     \
               res.c             \
               reslib.c          \
               restart.c         \
               s_bsd.c           \
               send.c            \
               server.c          \
               server_capab.c    \
               user.c            \
               whowas.c

AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = ircd

AM_YFLAGS = -d
AM_CPPFLAGS = $(LTDLINCL) -I$(top_srcdir)/libio/src -I$(top_srcdir)/src

ircd_LDFLAGS = -export-dynamic
ircd_LDADD = $(LIBLTDL) ../libio/src/.libs/libio.a
ircd_DEPENDENCIES = $(LTDLDEPS)

ircd_SOURCES = accept.c          \
               accept.h          \
               auth.c            \
               auth.h            \
               channel.c         \
               channel.h         \
               channel_invite.c  \
               channel_invite.h  \
               channel_mode.c    \
               channel_mode.h    \
               client.c          \
               client.h          \
               client_svstag.c   \
               client_svstag.h   \
               cloak.c           \
               cloak.h           \
               command.c         \
               command.h         \
               conf.c            \
               conf.h            \
               conf_class.c      \
               conf_class.h      \
               conf_cluster.c    \
               conf_cluster.h    \
               conf_db.c         \
               conf_db.h         \
               conf_gecos.c      \
               conf_gecos.h      \
               conf_pseudo.c     \
               conf_pseudo.h     \
               conf_resv.c       \
               conf_resv.h       \
               conf_service.c    \
               conf_service.h    \
               conf_shared.c     \
               conf_shared.h     \
               conf_parser.y     \
               conf_lexer.l      \
               defaults.h        \
               extban.c          \
               extban.h          \
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
               fdlist.h          \
               hash.c            \
               hash.h            \
               hostmask.c        \
               hostmask.h        \
               id.c              \
               id.h              \
               ipcache.c         \
               ipcache.h         \
               ircd.c            \
               ircd.h            \
               ircd_defs.h       \
               ircd_signal.c     \
               ircd_signal.h     \
               isupport.c        \
               isupport.h        \
               listener.c        \
               listener.h        \
               modules.c         \
               modules.h         \
               monitor.c         \
               monitor.h         \
               motd.c            \
               motd.h            \
               numeric.c         \
               numeric.h         \
               packet.c          \
               packet.h          \
               parse.c           \
               parse.h           \
               stdinc.h          \
               s_bsd_epoll.c     \
               s_bsd_poll.c      \
               s_bsd_kqueue.c    \
               tls.h             \
               tls_gnutls.c      \
               tls_gnutls.h      \
               tls_none.c        \
               tls_none.h        \
               tls_openssl.c     \
               tls_openssl.h     \
               tls_wolfssl.c     \
               tls_wolfssl.h     \
               restart.c         \
               restart.h         \
               send.c            \
               send.h            \
               server.c          \
               server.h          \
               server_capab.c    \
               server_capab.h    \
               user.c            \
               user.h            \
               whowas.c          \
               whowas.h

AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = ircd

AM_YFLAGS = -d
AM_CPPFLAGS = -I$(top_srcdir)/libio/src -I$(top_srcdir)/src
ircd_LDFLAGS = -export-dynamic
ircd_LDADD = ../libio/src/.libs/libio.la
ircd_DEPENDENCIES = ../libio/src/.libs/libio.la

ircd_SOURCES = accept.c          \
               accept.h          \
               aline.c           \
               aline.h           \
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
               hash.c            \
               hash.h            \
               id.c              \
               id.h              \
               info.c            \
               info.h            \
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
               stats.c           \
               stats.h           \
               stdinc.h          \
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

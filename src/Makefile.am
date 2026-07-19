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
               cap.c             \
               cap.h             \
               channel.c         \
               channel.h         \
               channel_invite.c  \
               channel_invite.h  \
               channel_member.c  \
               channel_member.h  \
               channel_mode.c    \
               channel_mode.h    \
               client.c          \
               client.h          \
               client_find.c     \
               client_find.h     \
               client_format.c   \
               client_format.h   \
               client_id.c       \
               client_id.h       \
               client_input.c    \
               client_input.h    \
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
               conf_connect.c    \
               conf_connect.h    \
               conf_db.c         \
               conf_db.h         \
               conf_gecos.c      \
               conf_gecos.h      \
               conf_oper.c       \
               conf_oper.h       \
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
               info.c            \
               info.h            \
               ipcache.c         \
               ipcache.h         \
               ircd.c            \
               ircd.h            \
               ircd_defs.h       \
               ircd_exit.c       \
               ircd_exit.h       \
               ircd_hook.c       \
               ircd_hook.h       \
               ircd_signal.c     \
               ircd_signal.h     \
               isupport.c        \
               isupport.h        \
               links_cache.c     \
               links_cache.h     \
               list_task.c       \
               list_task.h       \
               listener.c        \
               listener.h        \
               lookup.c          \
               lookup.h          \
               monitor.c         \
               monitor.h         \
               motd.c            \
               motd.h            \
               nuh.c             \
               nuh.h             \
               numeric.c         \
               numeric.h         \
               packet.c          \
               packet.h          \
               parse.c           \
               parse.h           \
               stats.c           \
               stats.h           \
               send.c            \
               send.h            \
               server.c          \
               server.h          \
               server_capab.c    \
               server_capab.h    \
               user.c            \
               user.h            \
               user_mode.c       \
               user_mode.h       \
               whowas.c          \
               whowas.h

install-exec-hook:
	if test -d $(DESTDIR)$(pkglibdir)-old; then \
		rm -rf $(DESTDIR)$(pkglibdir)-old; \
	fi
	if test -d $(DESTDIR)$(pkglibdir); then \
		mv $(DESTDIR)$(pkglibdir) $(DESTDIR)$(pkglibdir)-old; \
	fi

AUTOMAKE_OPTIONS = foreign
MODULE_FLAGS = -module -avoid-version

AM_CPPFLAGS = -I$(top_srcdir)/include
modulesdir = $(pkglibdir)/modules


m_bmask_la_LDFLAGS = $(MODULE_FLAGS)
m_die_la_LDFLAGS = $(MODULE_FLAGS)
m_error_la_LDFLAGS = $(MODULE_FLAGS)
m_join_la_LDFLAGS = $(MODULE_FLAGS)
m_kick_la_LDFLAGS = $(MODULE_FLAGS)
m_kill_la_LDFLAGS = $(MODULE_FLAGS)
m_message_la_LDFLAGS = $(MODULE_FLAGS)
m_mlock_la_LDFLAGS = $(MODULE_FLAGS)
m_mode_la_LDFLAGS = $(MODULE_FLAGS)
m_nick_la_LDFLAGS = $(MODULE_FLAGS)
m_part_la_LDFLAGS = $(MODULE_FLAGS)
m_quit_la_LDFLAGS = $(MODULE_FLAGS)
m_server_la_LDFLAGS = $(MODULE_FLAGS)
m_sjoin_la_LDFLAGS = $(MODULE_FLAGS)
m_squit_la_LDFLAGS = $(MODULE_FLAGS)
m_tmode_la_LDFLAGS = $(MODULE_FLAGS)

m_bmask_la_SOURCES = m_bmask.c
m_die_la_SOURCES = m_die.c
m_error_la_SOURCES = m_error.c
m_join_la_SOURCES = m_join.c
m_kick_la_SOURCES = m_kick.c
m_kill_la_SOURCES = m_kill.c
m_message_la_SOURCES = m_message.c
m_mlock_la_SOURCES = m_mlock.c
m_mode_la_SOURCES = m_mode.c
m_nick_la_SOURCES = m_nick.c
m_part_la_SOURCES = m_part.c
m_quit_la_SOURCES = m_quit.c
m_server_la_SOURCES = m_server.c
m_sjoin_la_SOURCES = m_sjoin.c
m_squit_la_SOURCES = m_squit.c
m_tmode_la_SOURCES = m_tmode.c

modules_LTLIBRARIES = m_bmask.la   \
                      m_die.la     \
                      m_error.la   \
                      m_join.la    \
                      m_kick.la    \
                      m_kill.la    \
                      m_message.la \
                      m_mlock.la   \
                      m_mode.la    \
                      m_nick.la    \
                      m_part.la    \
                      m_quit.la    \
                      m_server.la  \
                      m_sjoin.la   \
                      m_squit.la   \
                      m_tmode.la

modules: $(modules_LTLIBRARIES)

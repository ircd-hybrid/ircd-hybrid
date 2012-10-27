AUTOMAKE_OPTIONS = foreign
MODULE_FLAGS = -module -avoid-version

AM_CPPFLAGS = -I$(top_srcdir)/include
modulesdir = $(pkglibdir)/modules/autoload

modules_LTLIBRARIES = example_module.la     \
                      ip_cloaking.la        \
                      m_change.la           \
                      m_clearchan.la        \
                      m_ctrace.la           \
                      m_force.la            \
                      m_ltrace.la           \
                      m_ojoin.la            \
                      m_operspy.la          \
                      m_opme.la             \
                      m_webirc.la

example_module_la_LDFLAGS = $(MODULE_FLAGS)
ip_cloaking_la_LDFLAGS = $(MODULE_FLAGS)
m_change_la_LDFLAGS = $(MODULE_FLAGS)
m_clearchan_la_LDFLAGS = $(MODULE_FLAGS)
m_ctrace_la_LDFLAGS = $(MODULE_FLAGS)
m_force_la_LDFLAGS = $(MODULE_FLAGS)
m_ltrace_la_LDFLAGS = $(MODULE_FLAGS)
m_ojoin_la_LDFLAGS = $(MODULE_FLAGS)
m_operspy_la_LDFLAGS = $(MODULE_FLAGS)
m_opme_la_LDFLAGS = $(MODULE_FLAGS)
m_webirc_la_LDFLAGS = $(MODULE_FLAGS)


example_module_la_SOURCES = example_module.c
ip_cloaking_la_SOURCES = ip_cloaking.c
m_change_la_SOURCES = m_change.c
m_clearchan_la_SOURCES = m_clearchan.c
m_ctrace_la_SOURCES = m_ctrace.c
m_force_la_SOURCES = m_force.c
m_ltrace_la_SOURCES = m_ltrace.c
m_ojoin_la_SOURCES = m_ojoin.c
m_operspy_la_SOURCES = m_operspy.c
m_opme_la_SOURCES = m_opme.c
m_webirc_la_SOURCES = m_webirc.c

modules: $(modules_LTLIBRARIES)

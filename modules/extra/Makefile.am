AUTOMAKE_OPTIONS = foreign
MODULE_FLAGS = -module -avoid-version

AM_CPPFLAGS = -I$(top_srcdir)/include
modulesdir = $(pkglibdir)/modules/extra

modules_LTLIBRARIES = m_opme.la

m_opme_la_LDFLAGS = $(MODULE_FLAGS)

m_opme_la_SOURCES = m_opme.c

modules: $(modules_LTLIBRARIES)

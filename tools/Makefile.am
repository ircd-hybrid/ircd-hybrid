AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = mkpasswd
if ENABLE_SSL
bin_PROGRAMS += respond
respond_SOURCES = respond.c
endif
mkpasswd_SOURCES = mkpasswd.c

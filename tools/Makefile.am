AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = mkpasswd
mkpasswd_SOURCES = mkpasswd.c

install-exec-hook:
	if test -d $(DESTDIR)$(pkglibdir)-old; then \
		rm -rf $(DESTDIR)$(pkglibdir)-old; \
	fi
	if test -d $(DESTDIR)$(pkglibdir); then \
		mv $(DESTDIR)$(pkglibdir) $(DESTDIR)$(pkglibdir)-old; \
	fi

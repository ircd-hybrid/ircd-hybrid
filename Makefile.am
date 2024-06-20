ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = foreign
SUBDIRS = libltdl libio src modules tools doc help

install-data-local:
	$(INSTALL) -d $(DESTDIR)${localstatedir}/lib
	$(INSTALL) -d $(DESTDIR)${localstatedir}/log
	$(INSTALL) -d $(DESTDIR)${localstatedir}/run


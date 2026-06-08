AM_CFLAGS = -DANDROID -I$(srcdir)/include

lib_LTLIBRARIES = libcompat.la
libcompat_la_SOURCES = pthread.c qsort.c getenv.c progname.c strverscmp.c versionsort.c
include_HEADERS = include/compat.h
libcompat_includedir = $(includedir)/libcompat
libcompat_include_HEADERS = include/libcompat/pthread.h include/libcompat/qsort.h include/libcompat/getenv.h include/libcompat/progname.h include/libcompat/strverscmp.h include/libcompat/versionsort.h
libcompat_la_LDFLAGS = -version-info 1:0:0

install-data-hook:
	$(LN_S) -f compat.h $(DESTDIR)$(includedir)/libcompat.h

install_lib: install-exec

install_headers: install-data

.PHONY: install_lib install_headers

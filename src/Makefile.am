AM_CFLAGS = -DANDROID -I$(srcdir)/include

COMPAT_SOURCES = pthread.c qsort.c getenv.c progname.c strverscmp.c versionsort.c mntent.c memory.c spawn.c search.c

lib_LTLIBRARIES = libcompat.la
libcompat_la_SOURCES = $(COMPAT_SOURCES)
libcompat_la_LDFLAGS = -version-info 1:0:0 -shared

noinst_LIBRARIES = libcompat.a
libcompat_a_SOURCES = $(COMPAT_SOURCES)

include_HEADERS = include/compat.h
libcompat_includedir = $(includedir)/libcompat
libcompat_include_HEADERS = include/libcompat/pthread.h include/libcompat/qsort.h include/libcompat/getenv.h include/libcompat/progname.h include/libcompat/strverscmp.h include/libcompat/versionsort.h include/libcompat/mntent.h include/libcompat/param.h include/libcompat/memory.h include/libcompat/execinfo.h include/libcompat/spawn.h include/libcompat/search.h

install-data-hook:
	$(LN_S) -f compat.h $(DESTDIR)$(includedir)/libcompat.h
	$(MKDIR_P) $(DESTDIR)$(libdir)
	$(INSTALL_DATA) libcompat.a $(DESTDIR)$(libdir)/libcompat.a

install_lib: install-exec

install_dev: install-data

.PHONY: install_lib install_dev

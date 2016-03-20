# preamble

NULL =
AM_CPPFLAGS =
AM_CFLAGS =
BUILT_SOURCES =
CLEANFILES =
EXTRA_DIST =
DISTCLEANFILES =
lib_LTLIBRARIES =
bin_PROGRAMS =

AM_CPPFLAGS += \
	$(MAMAN_CFLAGS) \
	$(NULL)

AM_CFLAGS += \
	$(MAMAN_CFLAGS) \
	$(NULL)

source_h = \
	$(top_srcdir)/maman/maman-bar.h \
	$(top_srcdir)/maman/maman-ibaz.h \
	$(top_srcdir)/maman/maman-baz.h \
	$(NULL)

source_c = \
	maman-bar.c \
	maman-ibaz.c \
	maman-baz.c \
	$(NULL)

lib_LTLIBRARIES += libmaman-1.0.la
libmaman_1_0_la_LIBADD = $(MAMAN_LIBS)
libmaman_1_0_la_SOURCES = $(source_c) $(source_h)

mamanincludedir = $(includedir)/maman
mamaninclude_DATA = \
	$(source_h) \
	$(NULL)

-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS = Maman_1_0_gir
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(srcdir) --warn-all
INTROSPECTION_COMPILER_ARGS =

if HAVE_INTROSPECTION
introspection_sources = $(libmaman_1_0_la_SOURCES)

Maman-1.0.gir: libmaman-1.0.la
Maman_1_0_gir_INCLUDES = GObject-2.0
Maman_1_0_gir_CFLAGS = $(AM_CPPFLAGS)
Maman_1_0_gir_PACKAGES =
Maman_1_0_gir_LIBS = libmaman-1.0.la
Maman_1_0_gir_FILES = $(introspection_sources)
Maman_1_0_gir_NAMESPACE = Maman
INTROSPECTION_GIRS += Maman-1.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)
endif

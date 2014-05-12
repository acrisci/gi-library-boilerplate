m4_define([maman_major_version], [0])
m4_define([maman_minor_version], [0])
m4_define([maman_micro_version], [1])

m4_define([maman_version], [maman_major_version.maman_minor_version.maman_micro_version])

AC_PREREQ(2.69)

AC_INIT([Maman], [maman_version], [SendBugsHere@example.com])

AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build/autotools])
AC_CONFIG_SRCDIR([maman])
AC_CONFIG_HEADER([config.h])

# Checks for programs
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries
PKG_CHECK_MODULES([GOBJECT], [gobject-2.0 >= 2.38])

# Checks for typedefs, structures, and compiler characteristics
AC_PROG_CC_STDC

# Compiler flags
MAMAN_CFLAGS="$GOBJECT_CFLAGS"
MAMAN_LIBS="$GOBJECT_LIBS"

AM_INIT_AUTOMAKE([-Wall -Werror foreign -Wno-portability])
AM_PATH_GLIB_2_0
AM_PROG_AR
AM_SILENT_RULES([yes])
LT_INIT

# Versioning
MAMAN_MAJOR_VERSION=maman_major_version
MAMAN_MINOR_VERSION=maman_minor_version
MAMAN_MICRO_VERSION=maman_micro_version
MAMAN_VERSION=maman_version
AC_SUBST(MAMAN_MAJOR_VERSION)
AC_SUBST(MAMAN_MINOR_VERSION)
AC_SUBST(MAMAN_MICRO_VERSION)
AC_SUBST(MAMAN_VERSION)

# Introspection
GOBJECT_INTROSPECTION_CHECK([1.38.0])

# Output
AC_SUBST(MAMAN_CFLAGS)
AC_SUBST(MAMAN_LIBS)

AC_CONFIG_FILES([Makefile maman/Makefile])

AC_OUTPUT

AC_PREREQ(2.69)

AC_INIT([Maman], [1.0.0], [SendBugsHere@example.com])

AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build/autotools])
AC_CONFIG_SRCDIR([maman])
AC_CONFIG_HEADER([config.h])

# Checks for programs
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries
PKG_CHECK_MODULES([GOBJECT], [gobject-2.0 >= 2.38])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_PROG_AR
LT_INIT

GOBJECT_INTROSPECTION_CHECK([1.38.0])

AC_CONFIG_FILES([Makefile maman/Makefile])

AC_OUTPUT

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libbuf], [1.00], [gregory6316@gmail.com])
AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/libbuf.c])
AC_CONFIG_HEADERS([config.h])
#
PKG_CHECK_MODULES([CHECK],[check])
# Checks for programs.
AC_PROG_CC



# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.


# Checks for library functions.


AC_CONFIG_FILES([Makefile
                src/Makefile
                tests/Makefile])
              
AC_ARG_ENABLE([gcov],
              [AS_HELP_STRING([--enable-gcov], 
              [use Gcov to test the test suite])],
              [], 
              [enable_gcov=no])
AM_CONDITIONAL([COND_GCOV],[test '!' "$enable_gcov" = no])
AC_OUTPUT

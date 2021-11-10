#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([rhasher.c], [1.00], [gregory6316@gmail.com])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([rhash is needed!])])
AC_CHECK_LIB([readline],[readline],[],[])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--enable-readline], [Enable readline mode]),
    AC_DEFINE(USE_READLINE,[1],[Readline mode]),
    [readline_mode="no"]
  )
AS_IF([test "x$readline_mode" = "xno"], [
    AC_SUBST(LIBS, ["-lrhash"])
])
# Checks for library functions.
AC_CHECK_FUNCS([strerror])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

dnl Process this file with autoconf to create configure.

AC_PREREQ([2.60])

dnl Tell the user about autoconf.html in the --help output
m4_divert_once([HELP_END], [
See docs/autoconf.html for more details on the options for Mesa.])

AC_INIT([weaksyms], [1.0])
AC_CONFIG_AUX_DIR([bin])
AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([foreign])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])],
    [AC_SUBST([AM_DEFAULT_VERBOSITY], [1])])

m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

dnl Check for progs
AC_PROG_CPP
AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_AS

LT_PREREQ([2.2])
LT_INIT([disable-static])

AC_PROG_INSTALL

dnl Add flags for gcc and g++
if test "x$GCC" = xyes; then
    CFLAGS="$CFLAGS -Wall -std=c99"
    CFLAGS="$CFLAGS -Werror=implicit-function-declaration"
    CFLAGS="$CFLAGS -Werror=missing-prototypes"
    # Work around aliasing bugs - developers should comment this out
    CFLAGS="$CFLAGS -fno-strict-aliasing"
fi

AC_CONFIG_FILES([
	Makefile
])

AC_OUTPUT

AC_PREREQ([2.69])
AC_INIT([linux_traffic_signals], [1.0])

AC_CONFIG_SRCDIR([src/core/main.cc])
AC_CONFIG_HEADERS([config.h])

AC_INCLUDES_DEFAULT

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])

AC_LANG(C++)
AC_PROG_CXXCPP

AC_SEARCH_LIBS([initscr], [curses], [have_ncurses=yes], [have_ncurses=no])

if test "x${have_ncurses}" = xyes; then
    AC_CHECK_HEADERS([ncurses.h], [], [have_ncurses=no])

    if test "x${have_ncurses}" = xno; then
        AC_MSG_ERROR([
            ---------------------------------
            ncurses.h is missing. 
            You need to install dev package.
            ---------------------------------
        ])
    fi
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
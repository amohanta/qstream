#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([qstream], [0.1], [urpc@gmx.de])
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

AX_BOOST_BASE([1.34.0])
AX_BOOST_THREAD

if !($HAVE_BOOST_THREAD)
then
   echo "Sorry, you need the Thread-Lib from Boost."
   echo "Please install from http://www.boost.org"
   exit 1
fi

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([arpa/inet.h fcntl.h netdb.h netinet/in.h stdlib.h sys/socket.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_STRUCT_TM

# Checks for library functions.
AC_FUNC_SELECT_ARGTYPES
AC_FUNC_STRFTIME
AC_CHECK_FUNCS([gettimeofday memset select socket strstr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

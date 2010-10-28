#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#~ AC_PREREQ([2.63])
AC_PREREQ([2.0])
AC_INIT(pdfbeamer, 0.2, ich@benjaminreh.de)
AM_INIT_AUTOMAKE(@PACKAGE_NAME@, @PACKAGE_VERSION@)
#~ AC_CONFIG_SRCDIR([interfaces/serial/connections.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(DEPS, [gtkmm-2.4 >= 2.8])
#~ AC_CHECK_LIB(boost_program_options-gcc-mt, main, DEPS_LIBS+=" -lboost_program_options-gcc-mt", [
	#~ AC_CHECK_LIB(boost_program_options-mt, main, DEPS_LIBS+=" -lboost_program_options-mt", [
		#~ AC_CHECK_LIB(boost_program_options, main, DEPS_LIBS+=" -lboost_program_options", [
			#~ AC_MSG_ERROR("Linking against boost::program-options library failed.")
			#~ ])
	#~ ])
#~ ])
#~ AC_CHECK_LIB(boost_serialization-gcc-mt, main, DEPS_LIBS+=" -lboost_serialization-gcc-mt", [
	#~ AC_CHECK_LIB(boost_serialization-mt, main, DEPS_LIBS+=" -lboost_serialization-mt", [
		#~ AC_CHECK_LIB(boost_serialization, main, DEPS_LIBS+=" -lboost_serialization", [
			#~ AC_MSG_ERROR("Linking against boost::serialization library failed.")
			#~ ])
	#~ ])
#~ ])
#~ AC_SUBST(DEPS_CFLAGS)
#~ AC_SUBST(DEPS_LIBS)
# Checks for header files.
AC_CHECK_HEADERS([fcntl.h string.h strings.h termios.h])

AC_PROG_LIBTOOL
AC_SUBST(LIBTOOL_DEPS)

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_FORK
AC_CHECK_FUNCS([bzero dup2 select])

AC_CONFIG_FILES([Makefile
				])
AC_OUTPUT

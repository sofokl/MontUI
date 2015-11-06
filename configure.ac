AC_INIT([MontUI],[0.1])
AM_INIT_AUTOMAKE

AM_PROG_VALAC([0.24])
AM_PROG_CC_C_O

dnl ###########################################################################
dnl Dependencies
dnl ###########################################################################

GLIB_REQUIRED=2.0.0
GOBJ_REQUIRED=2.0.0
GTK_REQUIRED=3.12
LIBSOUP_REQUIRED=2.0

PKG_CHECK_MODULES(MontUI_U, [
  glib-2.0 >= $GLIB_REQUIRED
  gobject-2.0 >= $GOBJ_REQUIRED
  gtk+-3.0 >= $GTK_REQUIRED
  libsoup-2.4 >= $LIBSOUP_REQUIRED
])

AC_SUBST([GLIB_REQUIRED])

dnl ###########################################################################
dnl Files to generate
dnl ###########################################################################

AC_CONFIG_FILES([
Makefile
src/Makefile
])
AC_OUTPUT

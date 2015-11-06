bin_PROGRAMS = MontUI

MontUI_SOURCES = \
	config.vapi \
	main.vala

MontUI_CFLAGS = \
	-DDATA_DIRECTORY=\"$(datadir)/MontUI\" \
	$(MontUI_U_CFLAGS)

MontUI_VALAFLAGS = \
	--pkg gtk+-3.0 \
	--target-glib $(GLIB_REQUIRED)

MontUI_LDADD = \
	$(MontUI_U_LIBS)


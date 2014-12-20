lib_LTLIBRARIES = foo_dri.la libvdpau_foo.la

bin_PROGRAMS = user

# Comment out in order to get the VDPAU module dlopened first.
AM_CPPFLAGS = -DUSE_FOO_DRI_FIRST

COMMON_LDFLAGS = \
	-shared \
	-shrext .so \
	-module \
	-avoid-version \
	-no-undefined \
	-Wl,--no-undefined \
	-Wl,--version-script=$(srcdir)/weaksyms.sym \
	-Wl,--dynamic-list=$(srcdir)/weaksyms.dyn

COMMON_LDADD = \
	-ldl

foo_dri_la_LDFLAGS = $(COMMON_LDFLAGS)
libvdpau_foo_la_LDFLAGS = $(COMMON_LDFLAGS)

user_LDADD = $(COMMON_LDADD)

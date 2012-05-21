include $(top_srcdir)/Makefile.decl

NULL =

# third party
THIRDPARTY_SOURCES = \
	$(top_srcdir)/src/3rdparty/conversions.c \
	$(top_srcdir)/src/3rdparty/smsutil.c \
	$(top_srcdir)/src/3rdparty/storage.c \
	$(top_srcdir)/src/3rdparty/util.c \
	\
	$(top_srcdir)/src/3rdparty/ppp/crc-ccitt.c \
	$(top_srcdir)/src/3rdparty/ppp/gathdlc.c \
	$(top_srcdir)/src/3rdparty/ppp/gatio.c \
	$(top_srcdir)/src/3rdparty/ppp/gatppp.c \
	$(top_srcdir)/src/3rdparty/ppp/gatutil.c \
	$(top_srcdir)/src/3rdparty/ppp/ppp_auth.c \
	$(top_srcdir)/src/3rdparty/ppp/ppp_cp.c \
	$(top_srcdir)/src/3rdparty/ppp/ppp_ipcp.c \
	$(top_srcdir)/src/3rdparty/ppp/ppp_lcp.c \
	$(top_srcdir)/src/3rdparty/ppp/ppp_net.c \
	$(top_srcdir)/src/3rdparty/ppp/ringbuffer.c \
	\
	$(NULL)

AM_CFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/src/3rdparty \
	-I$(top_srcdir)/src/3rdparty/ppp \
	$(FSO_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(GEE_CFLAGS) \
	$(GSMMUX_CFLAGS) \
	-DG_LOG_DOMAIN=\"fsogsm.lib\" \
	$(NULL)

VALAC_ARGS = \
	--basedir $(top_srcdir) \
	--vapidir $(top_srcdir)/vapi \
	--vapidir $(top_srcdir)/src/lib \
	--pkg glib-2.0 \
	--pkg gio-2.0 \
	--pkg gee-1.0 \
	--pkg fso-glib-1.0 \
	--pkg fsosystem-2.0 \
	--pkg fsoframework-2.0 \
	--pkg fsotransport-2.0 \
	--pkg fsogsm3rdparty \
	--pkg config \
	--header fsogsm.h \
	--library fsogsm-2.0

if WANT_DEBUG
VALAC_ARGS += -g -D DEBUG
AM_CFLAGS += -ggdb -O0
endif

BUILT_SOURCES = .vala.stamp fsogsm-2.0.vapi

lib_LTLIBRARIES = \
	libfsogsm.la
	$(NULL)

libfsogsm_la_VALASOURCES = \
	at/atcall.vala \
	at/atchannel.vala \
	at/atcommand.vala \
	at/atcommands.vala \
	at/atcommandqueue.vala \
	at/atcallmediators.vala \
	at/atcbmediators.vala \
	at/atdebugmediators.vala \
	at/atdevicemediators.vala \
	at/atmediatorhelpers.vala \
	at/atmonitormediators.vala \
	at/atnetworkmediators.vala \
	at/atpdpmediators.vala \
	at/atsimmediators.vala \
	at/atsmsmediators.vala \
	at/atvmmediators.vala \
	at/atparser.vala \
	at/atpdp.vala \
	at/atsms.vala \
	at/atunsolicited.vala \
	\
	call.vala \
	codes.vala \
	consts.vala \
	channel.vala \
	lowlevel.vala \
	mediator.vala \
	mediatorhelpers.vala \
	modem.vala \
	phonebook.vala \
	pdp.vala \
	sms.vala \
	smsstorage.vala \
	watchdog.vala \
	$(NULL)

if WANT_MUX
VALAC_ARGS += --pkg gsm0710mux-1.0
libfsogsm_la_VALASOURCES += \
	muxtransport.vala \
	$(NULL)
endif

libfsogsm_la_SOURCES = \
	$(BUILT_SOURCES) \
	$(libfsogsm_la_VALASOURCES:.vala=.c) \
	$(THIRDPARTY_SOURCES) \
	$(NULL)

fsogsmincludedir = $(includedir)/fsoframework-2.0
fsogsminclude_HEADERS = fsogsm.h

$(BUILT_SOURCES): $(libfsogsm_la_VALASOURCES)
	$(VALAC) -C $(VALAC_ARGS) $^
	touch $@

libfsogsm_la_LIBADD = \
	$(FSO_LIBS) \
	$(GLIB_LIBS) \
	$(GEE_LIBS) \
	$(GSMMUX_LIBS) \
	$(THIRDPARTY_LIBS) \
	$(NULL)

vapidir = $(datadir)/vala/vapi

dist_vapi_DATA = \
	fsogsm-2.0.vapi \
	fsogsm-2.0.deps \
	$(NULL)

EXTRA_DIST += \
	$(libfsogsm_la_VALASOURCES) \
	$(libfsogsm_la_SOURCES) \
	$(BUILT_SOURCES)

CLEANFILES = \
	$(BUILT_SOURCES) \
        $(libfsogsm_la_VALASOURCES:.vala=.c) \
	$(NULL)

MAINTAINERCLEANFILES = \
	$(CLEANFILES) \
	Makefile.in
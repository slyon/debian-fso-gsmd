/* main.c generated by valac 0.16.0, the Vala compiler
 * generated from main.vala, do not modify */

/*
 * Copyright (C) 2009-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <fsoframework.h>
#include <signal.h>
#include <fsobasics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <config.h>
#include <gio/gio.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))


extern GMainLoop* mainloop;
GMainLoop* mainloop = NULL;
extern FsoFrameworkSubsystem* subsystem;
FsoFrameworkSubsystem* subsystem = NULL;
extern gboolean use_session_bus;
gboolean use_session_bus = FALSE;
extern gboolean show_version;
gboolean show_version = FALSE;

void sighandler (gint signum);
static gboolean __lambda2_ (void);
static gboolean ___lambda2__gsource_func (gpointer self);
gint _vala_main (gchar** args, int args_length1);
static void _sighandler_sighandler_t (gint signal);

const GOptionEntry options[3] = {{"test", 't', 0, G_OPTION_ARG_NONE, &use_session_bus, "Operate on DBus session bus for testing purpose", NULL}, {"version", 'v', 0, G_OPTION_ARG_NONE, &show_version, "Display version number", NULL}, {NULL}};

static gboolean __lambda2_ (void) {
	gboolean result = FALSE;
	FsoFrameworkSubsystem* _tmp0_;
	GMainLoop* _tmp1_;
	_tmp0_ = subsystem;
	fso_framework_subsystem_shutdown (_tmp0_);
	_tmp1_ = mainloop;
	g_main_loop_quit (_tmp1_);
	result = FALSE;
	return result;
}


static gboolean ___lambda2__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda2_ ();
	return result;
}


void sighandler (gint signum) {
	gint _tmp0_;
	FsoFrameworkLogger* _tmp1_;
	gint _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	_tmp0_ = signum;
	signal (_tmp0_, NULL);
	_tmp1_ = fso_framework_theLogger;
	_tmp2_ = signum;
	_tmp3_ = g_strdup_printf ("received signal -%d, exiting.", _tmp2_);
	_tmp4_ = _tmp3_;
	fso_framework_logger_info (_tmp1_, _tmp4_);
	_g_free0 (_tmp4_);
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, ___lambda2__gsource_func, NULL, NULL);
}


static void _sighandler_sighandler_t (gint signal) {
	sighandler (signal);
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	gboolean _tmp12_;
	gchar* _tmp16_ = NULL;
	gchar* bin;
	GBusType _tmp17_ = 0;
	gboolean _tmp18_;
	GBusType _tmp19_;
	GBusType bus_type;
	GBusType _tmp20_;
	FsoFrameworkDBusSubsystem* _tmp21_;
	FsoFrameworkSubsystem* _tmp22_;
	FsoFrameworkSubsystem* _tmp23_;
	guint _tmp24_ = 0U;
	guint count;
	FsoFrameworkLogger* _tmp25_;
	guint _tmp26_;
	gchar* _tmp27_ = NULL;
	gchar* _tmp28_;
	guint _tmp29_;
	FsoFrameworkLogger* _tmp40_;
	const gchar* _tmp41_;
	gchar* _tmp42_ = NULL;
	gchar* _tmp43_;
	GError * _inner_error_ = NULL;
	{
		GOptionContext* _tmp0_;
		GOptionContext* opt_context;
		GOptionContext* _tmp1_;
		GOptionContext* _tmp2_;
		GOptionContext* _tmp3_;
		GOptionContext* _tmp4_;
		GOptionContext* _tmp5_;
		_tmp0_ = g_option_context_new ("");
		opt_context = _tmp0_;
		_tmp1_ = opt_context;
		g_option_context_set_summary (_tmp1_, "FreeSmartphone.org GSM daemon");
		_tmp2_ = opt_context;
		g_option_context_set_description (_tmp2_, "This daemon implements the freesmartphone.org GSM API");
		_tmp3_ = opt_context;
		g_option_context_set_help_enabled (_tmp3_, TRUE);
		_tmp4_ = opt_context;
		g_option_context_add_main_entries (_tmp4_, options, NULL);
		_tmp5_ = opt_context;
		g_option_context_parse (_tmp5_, &args_length1, &args, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_option_context_free0 (opt_context);
			if (_inner_error_->domain == G_OPTION_ERROR) {
				goto __catch0_g_option_error;
			}
			_g_option_context_free0 (opt_context);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
		_g_option_context_free0 (opt_context);
	}
	goto __finally0;
	__catch0_g_option_error:
	{
		GError* e = NULL;
		FILE* _tmp6_;
		GError* _tmp7_;
		const gchar* _tmp8_;
		FILE* _tmp9_;
		gchar** _tmp10_;
		gint _tmp10__length1;
		const gchar* _tmp11_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp6_ = stdout;
		_tmp7_ = e;
		_tmp8_ = _tmp7_->message;
		fprintf (_tmp6_, "%s\n", _tmp8_);
		_tmp9_ = stdout;
		_tmp10_ = args;
		_tmp10__length1 = args_length1;
		_tmp11_ = _tmp10_[0];
		fprintf (_tmp9_, "Run '%s --help' to see a full list of available command line options.\n", _tmp11_);
		result = 1;
		_g_error_free0 (e);
		return result;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	_tmp12_ = show_version;
	if (_tmp12_) {
		FILE* _tmp13_;
		gchar* _tmp14_ = NULL;
		gchar* _tmp15_;
		_tmp13_ = stdout;
		_tmp14_ = g_strdup_printf ("fsogsmd %s\n", PACKAGE_VERSION);
		_tmp15_ = _tmp14_;
		fprintf (_tmp13_, "%s", _tmp15_);
		_g_free0 (_tmp15_);
		result = 1;
		return result;
	}
	_tmp16_ = fso_framework_utility_programName ();
	bin = _tmp16_;
	_tmp18_ = use_session_bus;
	if (_tmp18_) {
		_tmp17_ = G_BUS_TYPE_SESSION;
	} else {
		_tmp17_ = G_BUS_TYPE_SYSTEM;
	}
	_tmp19_ = _tmp17_;
	bus_type = _tmp19_;
	_tmp20_ = bus_type;
	_tmp21_ = fso_framework_dbus_subsystem_new ("fsogsm", _tmp20_);
	_g_object_unref0 (subsystem);
	subsystem = (FsoFrameworkSubsystem*) _tmp21_;
	_tmp22_ = subsystem;
	fso_framework_subsystem_registerPlugins (_tmp22_);
	_tmp23_ = subsystem;
	_tmp24_ = fso_framework_subsystem_loadPlugins (_tmp23_);
	count = _tmp24_;
	_tmp25_ = fso_framework_theLogger;
	_tmp26_ = count;
	_tmp27_ = g_strdup_printf ("loaded %u plugins", _tmp26_);
	_tmp28_ = _tmp27_;
	fso_framework_logger_info (_tmp25_, _tmp28_);
	_g_free0 (_tmp28_);
	_tmp29_ = count;
	if (_tmp29_ > ((guint) 0)) {
		GMainLoop* _tmp30_;
		FsoFrameworkLogger* _tmp31_;
		const gchar* _tmp32_;
		gchar* _tmp33_ = NULL;
		gchar* _tmp34_;
		GMainLoop* _tmp35_;
		FsoFrameworkLogger* _tmp36_;
		const gchar* _tmp37_;
		gchar* _tmp38_ = NULL;
		gchar* _tmp39_;
		_tmp30_ = g_main_loop_new (NULL, FALSE);
		_g_main_loop_unref0 (mainloop);
		mainloop = _tmp30_;
		_tmp31_ = fso_framework_theLogger;
		_tmp32_ = bin;
		_tmp33_ = g_strdup_printf ("%s => mainloop", _tmp32_);
		_tmp34_ = _tmp33_;
		fso_framework_logger_info (_tmp31_, _tmp34_);
		_g_free0 (_tmp34_);
		signal (SIGINT, _sighandler_sighandler_t);
		signal (SIGTERM, _sighandler_sighandler_t);
		signal (SIGBUS, _sighandler_sighandler_t);
		signal (SIGSEGV, _sighandler_sighandler_t);
		_tmp35_ = mainloop;
		g_main_loop_run (_tmp35_);
		_tmp36_ = fso_framework_theLogger;
		_tmp37_ = bin;
		_tmp38_ = g_strdup_printf ("mainloop => %s", _tmp37_);
		_tmp39_ = _tmp38_;
		fso_framework_logger_info (_tmp36_, _tmp39_);
		_g_free0 (_tmp39_);
	}
	_tmp40_ = fso_framework_theLogger;
	_tmp41_ = bin;
	_tmp42_ = g_strdup_printf ("%s exit", _tmp41_);
	_tmp43_ = _tmp42_;
	fso_framework_logger_info (_tmp40_, _tmp43_);
	_g_free0 (_tmp43_);
	result = 0;
	_g_free0 (bin);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}




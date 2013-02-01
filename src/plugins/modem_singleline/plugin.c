/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

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
#include <fsogsm.h>
#include <stdlib.h>
#include <string.h>
#include <fsotransport.h>
#include <gee.h>
#include <fsoframework.h>
#include <fsobasics.h>


#define SINGLELINE_TYPE_MODEM (singleline_modem_get_type ())
#define SINGLELINE_MODEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SINGLELINE_TYPE_MODEM, SinglelineModem))
#define SINGLELINE_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SINGLELINE_TYPE_MODEM, SinglelineModemClass))
#define SINGLELINE_IS_MODEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SINGLELINE_TYPE_MODEM))
#define SINGLELINE_IS_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SINGLELINE_TYPE_MODEM))
#define SINGLELINE_MODEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SINGLELINE_TYPE_MODEM, SinglelineModemClass))

typedef struct _SinglelineModem SinglelineModem;
typedef struct _SinglelineModemClass SinglelineModemClass;
typedef struct _SinglelineModemPrivate SinglelineModemPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _SinglelineModem {
	FsoGsmAbstractModem parent_instance;
	SinglelineModemPrivate * priv;
};

struct _SinglelineModemClass {
	FsoGsmAbstractModemClass parent_class;
};


static gpointer singleline_modem_parent_class = NULL;
static GType singleline_modem_type_id = 0;

GType singleline_modem_get_type (void) G_GNUC_CONST;
GType singleline_modem_register_type (GTypeModule * module);
enum  {
	SINGLELINE_MODEM_DUMMY_PROPERTY
};
#define SINGLELINE_MODEM_CHANNEL_NAME "main"
static gchar* singleline_modem_real_repr (FsoFrameworkAbstractObject* base);
static void singleline_modem_real_createChannels (FsoGsmAbstractModem* base);
static FsoGsmChannel* singleline_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query);
SinglelineModem* singleline_modem_new (void);
SinglelineModem* singleline_modem_construct (GType object_type);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static gchar* singleline_modem_real_repr (FsoFrameworkAbstractObject* base) {
	SinglelineModem * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (SinglelineModem*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void singleline_modem_real_createChannels (FsoGsmAbstractModem* base) {
	SinglelineModem * self;
	FsoFrameworkTransportSpec* _tmp0_;
	FsoFrameworkTransportSpec* _tmp1_;
	FsoFrameworkTransport* _tmp2_ = NULL;
	FsoFrameworkTransport* transport;
	FsoGsmStateBasedAtParser* _tmp3_;
	FsoGsmStateBasedAtParser* parser;
	FsoGsmAtChannel* _tmp4_;
	FsoGsmAtChannel* _tmp5_;
	self = (SinglelineModem*) base;
	_tmp0_ = fso_gsm_abstract_modem_get_modem_transport_spec ((FsoGsmAbstractModem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = fso_framework_transport_spec_create (_tmp1_);
	transport = _tmp2_;
	_tmp3_ = fso_gsm_state_based_at_parser_new ();
	parser = _tmp3_;
	_tmp4_ = fso_gsm_at_channel_new ((FsoGsmModem*) self, SINGLELINE_MODEM_CHANNEL_NAME, transport, (FsoFrameworkParser*) parser);
	_tmp5_ = _tmp4_;
	_g_object_unref0 (_tmp5_);
	_g_object_unref0 (parser);
	_g_object_unref0 (transport);
}


static FsoGsmChannel* singleline_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query) {
	SinglelineModem * self;
	FsoGsmChannel* result = NULL;
	GeeHashMap* _tmp0_;
	gpointer _tmp1_ = NULL;
	self = (SinglelineModem*) base;
	g_return_val_if_fail (command != NULL, NULL);
	g_return_val_if_fail (query != NULL, NULL);
	_tmp0_ = ((FsoGsmAbstractModem*) self)->channels;
	_tmp1_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp0_, SINGLELINE_MODEM_CHANNEL_NAME);
	result = (FsoGsmChannel*) _tmp1_;
	return result;
}


SinglelineModem* singleline_modem_construct (GType object_type) {
	SinglelineModem * self = NULL;
	self = (SinglelineModem*) fso_gsm_abstract_modem_construct (object_type);
	return self;
}


SinglelineModem* singleline_modem_new (void) {
	return singleline_modem_construct (SINGLELINE_TYPE_MODEM);
}


static void singleline_modem_class_init (SinglelineModemClass * klass) {
	singleline_modem_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = singleline_modem_real_repr;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createChannels = singleline_modem_real_createChannels;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->channelForCommand = singleline_modem_real_channelForCommand;
}


static void singleline_modem_instance_init (SinglelineModem * self) {
}


/**
 * @class Singleline.Modem
 *
 * This modem plugin supports standard AT modems that do not use a multiplexing mode.
 *
 **/
GType singleline_modem_get_type (void) {
	return singleline_modem_type_id;
}


GType singleline_modem_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SinglelineModemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) singleline_modem_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SinglelineModem), 0, (GInstanceInitFunc) singleline_modem_instance_init, NULL };
	singleline_modem_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_MODEM, "SinglelineModem", &g_define_type_info, 0);
	return singleline_modem_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	FsoFrameworkLogger* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "fsogsm.singleline fso_factory_function");
	_tmp1_ = g_strdup ("fsogsmd.modem_singleline");
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	singleline_modem_register_type (module);
}




/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2012 Simon Busch
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


#define PHONESIM_TYPE_MODEM (phonesim_modem_get_type ())
#define PHONESIM_MODEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PHONESIM_TYPE_MODEM, PhonesimModem))
#define PHONESIM_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PHONESIM_TYPE_MODEM, PhonesimModemClass))
#define PHONESIM_IS_MODEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PHONESIM_TYPE_MODEM))
#define PHONESIM_IS_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PHONESIM_TYPE_MODEM))
#define PHONESIM_MODEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PHONESIM_TYPE_MODEM, PhonesimModemClass))

typedef struct _PhonesimModem PhonesimModem;
typedef struct _PhonesimModemClass PhonesimModemClass;
typedef struct _PhonesimModemPrivate PhonesimModemPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _PhonesimModem {
	FsoGsmAbstractModem parent_instance;
	PhonesimModemPrivate * priv;
};

struct _PhonesimModemClass {
	FsoGsmAbstractModemClass parent_class;
};


static gpointer phonesim_modem_parent_class = NULL;
static GType phonesim_modem_type_id = 0;

GType phonesim_modem_get_type (void) G_GNUC_CONST;
GType phonesim_modem_register_type (GTypeModule * module);
enum  {
	PHONESIM_MODEM_DUMMY_PROPERTY
};
#define PHONESIM_MODEM_CHANNEL_NAME "main"
static gchar* phonesim_modem_real_repr (FsoFrameworkAbstractObject* base);
static void phonesim_modem_real_createChannels (FsoGsmAbstractModem* base);
static FsoGsmChannel* phonesim_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query);
PhonesimModem* phonesim_modem_new (void);
PhonesimModem* phonesim_modem_construct (GType object_type);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static gchar* phonesim_modem_real_repr (FsoFrameworkAbstractObject* base) {
	PhonesimModem * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (PhonesimModem*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void phonesim_modem_real_createChannels (FsoGsmAbstractModem* base) {
	PhonesimModem * self;
	FsoFrameworkTransportSpec* _tmp0_;
	FsoFrameworkTransportSpec* _tmp1_;
	FsoFrameworkTransport* _tmp2_ = NULL;
	FsoFrameworkTransport* transport;
	FsoGsmStateBasedAtParser* _tmp3_;
	FsoGsmStateBasedAtParser* parser;
	FsoGsmAtChannel* _tmp4_;
	FsoGsmAtChannel* _tmp5_;
	self = (PhonesimModem*) base;
	_tmp0_ = fso_gsm_abstract_modem_get_modem_transport_spec ((FsoGsmAbstractModem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = fso_framework_transport_spec_create (_tmp1_);
	transport = _tmp2_;
	_tmp3_ = fso_gsm_state_based_at_parser_new ();
	parser = _tmp3_;
	_tmp4_ = fso_gsm_at_channel_new ((FsoGsmModem*) self, PHONESIM_MODEM_CHANNEL_NAME, transport, (FsoFrameworkParser*) parser);
	_tmp5_ = _tmp4_;
	_g_object_unref0 (_tmp5_);
	_g_object_unref0 (parser);
	_g_object_unref0 (transport);
}


static FsoGsmChannel* phonesim_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query) {
	PhonesimModem * self;
	FsoGsmChannel* result = NULL;
	GeeHashMap* _tmp0_;
	gpointer _tmp1_ = NULL;
	self = (PhonesimModem*) base;
	g_return_val_if_fail (command != NULL, NULL);
	g_return_val_if_fail (query != NULL, NULL);
	_tmp0_ = ((FsoGsmAbstractModem*) self)->channels;
	_tmp1_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp0_, PHONESIM_MODEM_CHANNEL_NAME);
	result = (FsoGsmChannel*) _tmp1_;
	return result;
}


PhonesimModem* phonesim_modem_construct (GType object_type) {
	PhonesimModem * self = NULL;
	self = (PhonesimModem*) fso_gsm_abstract_modem_construct (object_type);
	return self;
}


PhonesimModem* phonesim_modem_new (void) {
	return phonesim_modem_construct (PHONESIM_TYPE_MODEM);
}


static void phonesim_modem_class_init (PhonesimModemClass * klass) {
	phonesim_modem_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = phonesim_modem_real_repr;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createChannels = phonesim_modem_real_createChannels;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->channelForCommand = phonesim_modem_real_channelForCommand;
}


static void phonesim_modem_instance_init (PhonesimModem * self) {
}


GType phonesim_modem_get_type (void) {
	return phonesim_modem_type_id;
}


GType phonesim_modem_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (PhonesimModemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) phonesim_modem_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PhonesimModem), 0, (GInstanceInitFunc) phonesim_modem_instance_init, NULL };
	phonesim_modem_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_MODEM, "PhonesimModem", &g_define_type_info, 0);
	return phonesim_modem_type_id;
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
	fso_framework_logger_debug (_tmp0_, "fsogsm.phonesim fso_factory_function");
	_tmp1_ = g_strdup ("fsogsmd.modem_phonesim");
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	phonesim_modem_register_type (module);
}




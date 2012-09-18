/* unsolicited.c generated by valac 0.16.0, the Vala compiler
 * generated from unsolicited.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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
#include <fsobasics.h>
#include <fsogsm.h>
#include <gisicomm.h>
#include <stdlib.h>
#include <string.h>
#include <freesmartphone.h>


#define NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER (nokia_isi_isi_unsolicited_handler_get_type ())
#define NOKIA_ISI_ISI_UNSOLICITED_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER, NokiaIsiIsiUnsolicitedHandler))
#define NOKIA_ISI_ISI_UNSOLICITED_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER, NokiaIsiIsiUnsolicitedHandlerClass))
#define NOKIA_ISI_IS_ISI_UNSOLICITED_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER))
#define NOKIA_ISI_IS_ISI_UNSOLICITED_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER))
#define NOKIA_ISI_ISI_UNSOLICITED_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER, NokiaIsiIsiUnsolicitedHandlerClass))

typedef struct _NokiaIsiIsiUnsolicitedHandler NokiaIsiIsiUnsolicitedHandler;
typedef struct _NokiaIsiIsiUnsolicitedHandlerClass NokiaIsiIsiUnsolicitedHandlerClass;
typedef struct _NokiaIsiIsiUnsolicitedHandlerPrivate NokiaIsiIsiUnsolicitedHandlerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))

#define FSO_GSM_TYPE_ISI_CALL_HANDLER (fso_gsm_isi_call_handler_get_type ())
#define FSO_GSM_ISI_CALL_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_ISI_CALL_HANDLER, FsoGsmIsiCallHandler))
#define FSO_GSM_ISI_CALL_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_ISI_CALL_HANDLER, FsoGsmIsiCallHandlerClass))
#define FSO_GSM_IS_ISI_CALL_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_ISI_CALL_HANDLER))
#define FSO_GSM_IS_ISI_CALL_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_ISI_CALL_HANDLER))
#define FSO_GSM_ISI_CALL_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_ISI_CALL_HANDLER, FsoGsmIsiCallHandlerClass))

typedef struct _FsoGsmIsiCallHandler FsoGsmIsiCallHandler;
typedef struct _FsoGsmIsiCallHandlerClass FsoGsmIsiCallHandlerClass;

struct _NokiaIsiIsiUnsolicitedHandler {
	FsoFrameworkAbstractObject parent_instance;
	NokiaIsiIsiUnsolicitedHandlerPrivate * priv;
};

struct _NokiaIsiIsiUnsolicitedHandlerClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _NokiaIsiIsiUnsolicitedHandlerPrivate {
	FsoGsmModem* modem;
};


static gpointer nokia_isi_isi_unsolicited_handler_parent_class = NULL;
extern GIsiCommModemAccess* nokia_isi_isimodem;
static GType nokia_isi_isi_unsolicited_handler_type_id = 0;

GType nokia_isi_isi_unsolicited_handler_get_type (void) G_GNUC_CONST;
GType nokia_isi_isi_unsolicited_handler_register_type (GTypeModule * module);
#define NOKIA_ISI_ISI_UNSOLICITED_HANDLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER, NokiaIsiIsiUnsolicitedHandlerPrivate))
enum  {
	NOKIA_ISI_ISI_UNSOLICITED_HANDLER_DUMMY_PROPERTY
};
NokiaIsiIsiUnsolicitedHandler* nokia_isi_isi_unsolicited_handler_new (FsoGsmModem* modem);
NokiaIsiIsiUnsolicitedHandler* nokia_isi_isi_unsolicited_handler_construct (GType object_type, FsoGsmModem* modem);
static void nokia_isi_isi_unsolicited_handler_onSignalStrengthUpdate (NokiaIsiIsiUnsolicitedHandler* self, guint8 rssi);
static void _nokia_isi_isi_unsolicited_handler_onSignalStrengthUpdate_gisi_comm_network_signal_strength (GIsiCommNetwork* _sender, guint8 rssi, gpointer self);
static void nokia_isi_isi_unsolicited_handler_onRegistrationStatusUpdate (NokiaIsiIsiUnsolicitedHandler* self, GIsiCommNetworkISI_RegStatus* istatus);
static void _nokia_isi_isi_unsolicited_handler_onRegistrationStatusUpdate_gisi_comm_network_registration_status (GIsiCommNetwork* _sender, GIsiCommNetworkISI_RegStatus* status, gpointer self);
static void nokia_isi_isi_unsolicited_handler_onCallStatusUpdate (NokiaIsiIsiUnsolicitedHandler* self, GIsiCommCallISI_CallStatus* istatus);
static void _nokia_isi_isi_unsolicited_handler_onCallStatusUpdate_gisi_comm_call_status_changed (GIsiCommCall* _sender, GIsiCommCallISI_CallStatus* status, gpointer self);
static gchar* nokia_isi_isi_unsolicited_handler_real_repr (FsoFrameworkAbstractObject* base);
const gchar* NET_registration_status_to_string (guint8 self);
static const char* _NET_registration_status_to_string (guint8 value);
GHashTable* nokia_isi_isiRegStatusToFsoRegStatus (GIsiCommNetworkISI_RegStatus* istatus);
GType fso_gsm_isi_call_handler_get_type (void) G_GNUC_CONST;
GType fso_gsm_isi_call_handler_register_type (GTypeModule * module);
void fso_gsm_isi_call_handler_handleStatusUpdate (FsoGsmIsiCallHandler* self, GIsiCommCallISI_CallStatus* istatus);
static void nokia_isi_isi_unsolicited_handler_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _nokia_isi_isi_unsolicited_handler_onSignalStrengthUpdate_gisi_comm_network_signal_strength (GIsiCommNetwork* _sender, guint8 rssi, gpointer self) {
	nokia_isi_isi_unsolicited_handler_onSignalStrengthUpdate (self, rssi);
}


static void _nokia_isi_isi_unsolicited_handler_onRegistrationStatusUpdate_gisi_comm_network_registration_status (GIsiCommNetwork* _sender, GIsiCommNetworkISI_RegStatus* status, gpointer self) {
	nokia_isi_isi_unsolicited_handler_onRegistrationStatusUpdate (self, status);
}


static void _nokia_isi_isi_unsolicited_handler_onCallStatusUpdate_gisi_comm_call_status_changed (GIsiCommCall* _sender, GIsiCommCallISI_CallStatus* status, gpointer self) {
	nokia_isi_isi_unsolicited_handler_onCallStatusUpdate (self, status);
}


NokiaIsiIsiUnsolicitedHandler* nokia_isi_isi_unsolicited_handler_construct (GType object_type, FsoGsmModem* modem) {
	NokiaIsiIsiUnsolicitedHandler * self = NULL;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	GIsiCommModemAccess* _tmp2_;
	GIsiCommNetwork* _tmp3_;
	GIsiCommModemAccess* _tmp4_;
	GIsiCommNetwork* _tmp5_;
	GIsiCommModemAccess* _tmp6_;
	GIsiCommCall* _tmp7_;
	g_return_val_if_fail (modem != NULL, NULL);
	self = (NokiaIsiIsiUnsolicitedHandler*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = modem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->modem);
	self->priv->modem = _tmp1_;
	_tmp2_ = nokia_isi_isimodem;
	_tmp3_ = _tmp2_->net;
	g_signal_connect_object (_tmp3_, "signal-strength", (GCallback) _nokia_isi_isi_unsolicited_handler_onSignalStrengthUpdate_gisi_comm_network_signal_strength, self, 0);
	_tmp4_ = nokia_isi_isimodem;
	_tmp5_ = _tmp4_->net;
	g_signal_connect_object (_tmp5_, "registration-status", (GCallback) _nokia_isi_isi_unsolicited_handler_onRegistrationStatusUpdate_gisi_comm_network_registration_status, self, 0);
	_tmp6_ = nokia_isi_isimodem;
	_tmp7_ = _tmp6_->call;
	g_signal_connect_object (_tmp7_, "status-changed", (GCallback) _nokia_isi_isi_unsolicited_handler_onCallStatusUpdate_gisi_comm_call_status_changed, self, 0);
	return self;
}


NokiaIsiIsiUnsolicitedHandler* nokia_isi_isi_unsolicited_handler_new (FsoGsmModem* modem) {
	return nokia_isi_isi_unsolicited_handler_construct (NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER, modem);
}


static gchar* nokia_isi_isi_unsolicited_handler_real_repr (FsoFrameworkAbstractObject* base) {
	NokiaIsiIsiUnsolicitedHandler * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (NokiaIsiIsiUnsolicitedHandler*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void nokia_isi_isi_unsolicited_handler_onSignalStrengthUpdate (NokiaIsiIsiUnsolicitedHandler* self, guint8 rssi) {
	FsoGsmModem* _tmp0_;
	gpointer _tmp1_ = NULL;
	FreeSmartphoneGSMNetwork* obj;
	guint8 _tmp2_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->modem;
	_tmp1_ = fso_gsm_modem_theDevice (_tmp0_, FREE_SMARTPHONE_GSM_TYPE_NETWORK, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	obj = (FreeSmartphoneGSMNetwork*) _tmp1_;
	_tmp2_ = rssi;
	g_signal_emit_by_name (obj, "signal-strength", (gint) ((gint32) _tmp2_));
	_g_object_unref0 (obj);
}


static const char* _NET_registration_status_to_string (guint8 value) {
	switch (value) {
		case NET_REG_STATUS_HOME:
		return "NET_REG_STATUS_HOME";
		case NET_REG_STATUS_ROAM:
		return "NET_REG_STATUS_ROAM";
		case NET_REG_STATUS_ROAM_BLINK:
		return "NET_REG_STATUS_ROAM_BLINK";
		case NET_REG_STATUS_NOSERV:
		return "NET_REG_STATUS_NOSERV";
		case NET_REG_STATUS_NOSERV_SEARCHING:
		return "NET_REG_STATUS_NOSERV_SEARCHING";
		case NET_REG_STATUS_NOSERV_NOTSEARCHING:
		return "NET_REG_STATUS_NOSERV_NOTSEARCHING";
		case NET_REG_STATUS_NOSERV_NOSIM:
		return "NET_REG_STATUS_NOSERV_NOSIM";
		case NET_REG_STATUS_POWER_OFF:
		return "NET_REG_STATUS_POWER_OFF";
		case NET_REG_STATUS_NSPS:
		return "NET_REG_STATUS_NSPS";
		case NET_REG_STATUS_NSPS_NO_COVERAGE:
		return "NET_REG_STATUS_NSPS_NO_COVERAGE";
		case NET_REG_STATUS_NOSERV_SIM_REJECTED_BY_NW:
		return "NET_REG_STATUS_NOSERV_SIM_REJECTED_BY_NW";
	}
	return NULL;
}


static void nokia_isi_isi_unsolicited_handler_onRegistrationStatusUpdate (NokiaIsiIsiUnsolicitedHandler* self, GIsiCommNetworkISI_RegStatus* istatus) {
	GIsiCommNetworkISI_RegStatus _tmp0_;
	guint8 _tmp1_;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	GIsiCommNetworkISI_RegStatus _tmp5_;
	guint8 _tmp6_;
	FsoGsmModem* _tmp8_;
	gpointer _tmp9_ = NULL;
	FreeSmartphoneGSMNetwork* obj;
	GIsiCommNetworkISI_RegStatus _tmp10_;
	GHashTable* _tmp11_ = NULL;
	GHashTable* _tmp12_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (istatus != NULL);
	_tmp0_ = *istatus;
	_tmp1_ = _tmp0_.status;
	_tmp2_ = _NET_registration_status_to_string (_tmp1_);
	_tmp3_ = g_strconcat ("on registration status update w/ isi status ", _tmp2_, NULL);
	_tmp4_ = _tmp3_;
	g_debug ("unsolicited.vala:56: %s", _tmp4_);
	_g_free0 (_tmp4_);
	_tmp5_ = *istatus;
	_tmp6_ = _tmp5_.status;
	switch (_tmp6_) {
		case NET_REG_STATUS_HOME:
		case NET_REG_STATUS_ROAM:
		case NET_REG_STATUS_ROAM_BLINK:
		{
			FsoGsmModem* _tmp7_;
			_tmp7_ = self->priv->modem;
			fso_gsm_modem_advanceToState (_tmp7_, FSO_GSM_MODEM_STATUS_ALIVE_REGISTERED, FALSE);
			break;
		}
		default:
		{
			break;
		}
	}
	_tmp8_ = self->priv->modem;
	_tmp9_ = fso_gsm_modem_theDevice (_tmp8_, FREE_SMARTPHONE_GSM_TYPE_NETWORK, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	obj = (FreeSmartphoneGSMNetwork*) _tmp9_;
	_tmp10_ = *istatus;
	_tmp11_ = nokia_isi_isiRegStatusToFsoRegStatus (&_tmp10_);
	_tmp12_ = _tmp11_;
	g_signal_emit_by_name (obj, "status", _tmp12_);
	_g_hash_table_unref0 (_tmp12_);
	_g_object_unref0 (obj);
}


static void nokia_isi_isi_unsolicited_handler_onCallStatusUpdate (NokiaIsiIsiUnsolicitedHandler* self, GIsiCommCallISI_CallStatus* istatus) {
	FsoGsmModem* _tmp0_;
	FsoGsmCallHandler* _tmp1_;
	FsoGsmCallHandler* _tmp2_;
	FsoGsmIsiCallHandler* _tmp3_;
	FsoGsmIsiCallHandler* callhandler;
	GIsiCommCallISI_CallStatus _tmp4_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (istatus != NULL);
	_tmp0_ = self->priv->modem;
	_tmp1_ = fso_gsm_modem_get_callhandler (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = _g_object_ref0 (FSO_GSM_IS_ISI_CALL_HANDLER (_tmp2_) ? ((FsoGsmIsiCallHandler*) _tmp2_) : NULL);
	callhandler = _tmp3_;
	_tmp4_ = *istatus;
	fso_gsm_isi_call_handler_handleStatusUpdate (callhandler, &_tmp4_);
	_g_object_unref0 (callhandler);
}


static void nokia_isi_isi_unsolicited_handler_class_init (NokiaIsiIsiUnsolicitedHandlerClass * klass) {
	nokia_isi_isi_unsolicited_handler_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (NokiaIsiIsiUnsolicitedHandlerPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = nokia_isi_isi_unsolicited_handler_real_repr;
	G_OBJECT_CLASS (klass)->finalize = nokia_isi_isi_unsolicited_handler_finalize;
}


static void nokia_isi_isi_unsolicited_handler_instance_init (NokiaIsiIsiUnsolicitedHandler * self) {
	self->priv = NOKIA_ISI_ISI_UNSOLICITED_HANDLER_GET_PRIVATE (self);
}


static void nokia_isi_isi_unsolicited_handler_finalize (GObject* obj) {
	NokiaIsiIsiUnsolicitedHandler * self;
	self = NOKIA_ISI_ISI_UNSOLICITED_HANDLER (obj);
	_g_object_unref0 (self->priv->modem);
	G_OBJECT_CLASS (nokia_isi_isi_unsolicited_handler_parent_class)->finalize (obj);
}


/**
 * @class IsiUnsolicited
 **/
GType nokia_isi_isi_unsolicited_handler_get_type (void) {
	return nokia_isi_isi_unsolicited_handler_type_id;
}


GType nokia_isi_isi_unsolicited_handler_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (NokiaIsiIsiUnsolicitedHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) nokia_isi_isi_unsolicited_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NokiaIsiIsiUnsolicitedHandler), 0, (GInstanceInitFunc) nokia_isi_isi_unsolicited_handler_instance_init, NULL };
	nokia_isi_isi_unsolicited_handler_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "NokiaIsiIsiUnsolicitedHandler", &g_define_type_info, 0);
	return nokia_isi_isi_unsolicited_handler_type_id;
}




/* service.c generated by valac 0.16.1, the Vala compiler
 * generated from service.vala, do not modify */

/*
 * Copyright (C) 2009-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *                         Simon Busch <morphis@gravedo.de>
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
#include <freesmartphone.h>
#include <stdlib.h>
#include <string.h>


#define FSO_GSM_TYPE_SERVICE (fso_gsm_service_get_type ())
#define FSO_GSM_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_SERVICE, FsoGsmService))
#define FSO_GSM_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_SERVICE, FsoGsmServiceClass))
#define FSO_GSM_IS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_SERVICE))
#define FSO_GSM_IS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_SERVICE))
#define FSO_GSM_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_SERVICE, FsoGsmServiceClass))

typedef struct _FsoGsmService FsoGsmService;
typedef struct _FsoGsmServiceClass FsoGsmServiceClass;
typedef struct _FsoGsmServicePrivate FsoGsmServicePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _FsoGsmService {
	FsoFrameworkAbstractObject parent_instance;
	FsoGsmServicePrivate * priv;
	FsoGsmModem* modem;
};

struct _FsoGsmServiceClass {
	FsoFrameworkAbstractObjectClass parent_class;
};


static gpointer fso_gsm_service_parent_class = NULL;
static GType fso_gsm_service_type_id = 0;

GType fso_gsm_service_get_type (void) G_GNUC_CONST;
GType fso_gsm_service_register_type (GTypeModule * module);
enum  {
	FSO_GSM_SERVICE_DUMMY_PROPERTY
};
void fso_gsm_service_checkAvailability (FsoGsmService* self, FsoGsmModemStatus required, GError** error);
const gchar* fso_gsm_modem_status_to_string (FsoGsmModemStatus self);
void fso_gsm_service_assignModem (FsoGsmService* self, FsoGsmModem* modem);
static gchar* fso_gsm_service_real_repr (FsoFrameworkAbstractObject* base);
FsoGsmService* fso_gsm_service_new (void);
FsoGsmService* fso_gsm_service_construct (GType object_type);
static void fso_gsm_service_finalize (GObject* obj);


void fso_gsm_service_checkAvailability (FsoGsmService* self, FsoGsmModemStatus required, GError** error) {
	FsoGsmModem* _tmp0_;
	gboolean _tmp2_ = FALSE;
	FsoGsmModem* _tmp3_;
	FsoGsmModemStatus _tmp4_ = 0;
	FsoGsmModemStatus _tmp5_;
	gboolean _tmp8_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->modem;
	if (_tmp0_ == NULL) {
		GError* _tmp1_;
		_tmp1_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_UNAVAILABLE, "There is no underlying hardware present... stop talking to a vapourwar" \
"e modem!");
		_inner_error_ = _tmp1_;
		if (_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp3_ = self->modem;
	_tmp4_ = fso_gsm_modem_status (_tmp3_);
	_tmp5_ = required;
	if (_tmp4_ < _tmp5_) {
		_tmp2_ = TRUE;
	} else {
		FsoGsmModem* _tmp6_;
		FsoGsmModemStatus _tmp7_ = 0;
		_tmp6_ = self->modem;
		_tmp7_ = fso_gsm_modem_status (_tmp6_);
		_tmp2_ = _tmp7_ >= FSO_GSM_MODEM_STATUS_SUSPENDING;
	}
	_tmp8_ = _tmp2_;
	if (_tmp8_) {
		FsoGsmModem* _tmp9_;
		FsoGsmModemStatus _tmp10_ = 0;
		GEnumValue* _tmp11_;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_;
		GError* _tmp14_;
		GError* _tmp15_;
		_tmp9_ = self->modem;
		_tmp10_ = fso_gsm_modem_status (_tmp9_);
		_tmp11_ = g_enum_get_value (g_type_class_ref (FSO_GSM_MODEM_TYPE_STATUS), _tmp10_);
		_tmp12_ = g_strconcat ("This function is not available while modem is in state ", (_tmp11_ != NULL) ? _tmp11_->value_name : NULL, NULL);
		_tmp13_ = _tmp12_;
		_tmp14_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_UNAVAILABLE, _tmp13_);
		_tmp15_ = _tmp14_;
		_g_free0 (_tmp13_);
		_inner_error_ = _tmp15_;
		if (_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void fso_gsm_service_assignModem (FsoGsmService* self, FsoGsmModem* modem) {
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (modem != NULL);
	_tmp0_ = modem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->modem);
	self->modem = _tmp1_;
}


static gchar* fso_gsm_service_real_repr (FsoFrameworkAbstractObject* base) {
	FsoGsmService * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoGsmService*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


FsoGsmService* fso_gsm_service_construct (GType object_type) {
	FsoGsmService * self = NULL;
	self = (FsoGsmService*) fso_framework_abstract_object_construct (object_type);
	return self;
}


FsoGsmService* fso_gsm_service_new (void) {
	return fso_gsm_service_construct (FSO_GSM_TYPE_SERVICE);
}


static void fso_gsm_service_class_init (FsoGsmServiceClass * klass) {
	fso_gsm_service_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = fso_gsm_service_real_repr;
	G_OBJECT_CLASS (klass)->finalize = fso_gsm_service_finalize;
}


static void fso_gsm_service_instance_init (FsoGsmService * self) {
}


static void fso_gsm_service_finalize (GObject* obj) {
	FsoGsmService * self;
	self = FSO_GSM_SERVICE (obj);
	_g_object_unref0 (self->modem);
	G_OBJECT_CLASS (fso_gsm_service_parent_class)->finalize (obj);
}


GType fso_gsm_service_get_type (void) {
	return fso_gsm_service_type_id;
}


GType fso_gsm_service_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (FsoGsmServiceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_gsm_service_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoGsmService), 0, (GInstanceInitFunc) fso_gsm_service_instance_init, NULL };
	fso_gsm_service_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "FsoGsmService", &g_define_type_info, 0);
	return fso_gsm_service_type_id;
}




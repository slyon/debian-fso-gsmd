/* unsolicited.c generated by valac 0.16.1, the Vala compiler
 * generated from unsolicited.vala, do not modify */

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
#include <fsobasics.h>


#define CINTERION_MC75_TYPE_UNSOLICITED_RESPONSE_HANDLER (cinterion_mc75_unsolicited_response_handler_get_type ())
#define CINTERION_MC75_UNSOLICITED_RESPONSE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CINTERION_MC75_TYPE_UNSOLICITED_RESPONSE_HANDLER, CinterionMc75UnsolicitedResponseHandler))
#define CINTERION_MC75_UNSOLICITED_RESPONSE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CINTERION_MC75_TYPE_UNSOLICITED_RESPONSE_HANDLER, CinterionMc75UnsolicitedResponseHandlerClass))
#define CINTERION_MC75_IS_UNSOLICITED_RESPONSE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CINTERION_MC75_TYPE_UNSOLICITED_RESPONSE_HANDLER))
#define CINTERION_MC75_IS_UNSOLICITED_RESPONSE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CINTERION_MC75_TYPE_UNSOLICITED_RESPONSE_HANDLER))
#define CINTERION_MC75_UNSOLICITED_RESPONSE_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CINTERION_MC75_TYPE_UNSOLICITED_RESPONSE_HANDLER, CinterionMc75UnsolicitedResponseHandlerClass))

typedef struct _CinterionMc75UnsolicitedResponseHandler CinterionMc75UnsolicitedResponseHandler;
typedef struct _CinterionMc75UnsolicitedResponseHandlerClass CinterionMc75UnsolicitedResponseHandlerClass;
typedef struct _CinterionMc75UnsolicitedResponseHandlerPrivate CinterionMc75UnsolicitedResponseHandlerPrivate;

#define CINTERION_MC75_TYPE_CINTERION_PLUS_CIEV (cinterion_mc75_cinterion_plus_ciev_get_type ())
#define CINTERION_MC75_CINTERION_PLUS_CIEV(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CINTERION_MC75_TYPE_CINTERION_PLUS_CIEV, CinterionMc75CinterionPlusCIEV))
#define CINTERION_MC75_CINTERION_PLUS_CIEV_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CINTERION_MC75_TYPE_CINTERION_PLUS_CIEV, CinterionMc75CinterionPlusCIEVClass))
#define CINTERION_MC75_IS_CINTERION_PLUS_CIEV(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CINTERION_MC75_TYPE_CINTERION_PLUS_CIEV))
#define CINTERION_MC75_IS_CINTERION_PLUS_CIEV_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CINTERION_MC75_TYPE_CINTERION_PLUS_CIEV))
#define CINTERION_MC75_CINTERION_PLUS_CIEV_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CINTERION_MC75_TYPE_CINTERION_PLUS_CIEV, CinterionMc75CinterionPlusCIEVClass))

typedef struct _CinterionMc75CinterionPlusCIEV CinterionMc75CinterionPlusCIEV;
typedef struct _CinterionMc75CinterionPlusCIEVClass CinterionMc75CinterionPlusCIEVClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _CinterionMc75UnsolicitedResponseHandler {
	FsoGsmAtUnsolicitedResponseHandler parent_instance;
	CinterionMc75UnsolicitedResponseHandlerPrivate * priv;
};

struct _CinterionMc75UnsolicitedResponseHandlerClass {
	FsoGsmAtUnsolicitedResponseHandlerClass parent_class;
	void (*dachSSIM_READY) (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs);
	void (*dachSIND) (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs);
};


static gpointer cinterion_mc75_unsolicited_response_handler_parent_class = NULL;
static GType cinterion_mc75_unsolicited_response_handler_type_id = 0;

GType cinterion_mc75_unsolicited_response_handler_get_type (void) G_GNUC_CONST;
GType cinterion_mc75_unsolicited_response_handler_register_type (GTypeModule * module);
enum  {
	CINTERION_MC75_UNSOLICITED_RESPONSE_HANDLER_DUMMY_PROPERTY
};
CinterionMc75UnsolicitedResponseHandler* cinterion_mc75_unsolicited_response_handler_new (FsoGsmModem* modem);
CinterionMc75UnsolicitedResponseHandler* cinterion_mc75_unsolicited_response_handler_construct (GType object_type, FsoGsmModem* modem);
void cinterion_mc75_unsolicited_response_handler_dachSSIM_READY (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs);
static void _cinterion_mc75_unsolicited_response_handler_dachSSIM_READY_unsolicited_response_handler_func (const gchar* prefix, const gchar* rhs, gpointer self);
void cinterion_mc75_unsolicited_response_handler_dachSIND (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs);
static void _cinterion_mc75_unsolicited_response_handler_dachSIND_unsolicited_response_handler_func (const gchar* prefix, const gchar* rhs, gpointer self);
static void cinterion_mc75_unsolicited_response_handler_real_dachSSIM_READY (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs);
static void cinterion_mc75_unsolicited_response_handler_real_dachSIND (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs);
static void cinterion_mc75_unsolicited_response_handler_real_plusCIEV (FsoGsmAtUnsolicitedResponseHandler* base, const gchar* prefix, const gchar* rhs);
GType cinterion_mc75_cinterion_plus_ciev_get_type (void) G_GNUC_CONST;
GType cinterion_mc75_cinterion_plus_ciev_register_type (GTypeModule * module);


static void _cinterion_mc75_unsolicited_response_handler_dachSSIM_READY_unsolicited_response_handler_func (const gchar* prefix, const gchar* rhs, gpointer self) {
	cinterion_mc75_unsolicited_response_handler_dachSSIM_READY (self, prefix, rhs);
}


static void _cinterion_mc75_unsolicited_response_handler_dachSIND_unsolicited_response_handler_func (const gchar* prefix, const gchar* rhs, gpointer self) {
	cinterion_mc75_unsolicited_response_handler_dachSIND (self, prefix, rhs);
}


CinterionMc75UnsolicitedResponseHandler* cinterion_mc75_unsolicited_response_handler_construct (GType object_type, FsoGsmModem* modem) {
	CinterionMc75UnsolicitedResponseHandler * self = NULL;
	FsoGsmModem* _tmp0_;
	g_return_val_if_fail (modem != NULL, NULL);
	_tmp0_ = modem;
	self = (CinterionMc75UnsolicitedResponseHandler*) fso_gsm_at_unsolicited_response_handler_construct (object_type, _tmp0_);
	fso_gsm_base_unsolicited_response_handler_registerUrc ((FsoGsmBaseUnsolicitedResponseHandler*) self, "^SSIM READY", _cinterion_mc75_unsolicited_response_handler_dachSSIM_READY_unsolicited_response_handler_func, self);
	fso_gsm_base_unsolicited_response_handler_registerUrc ((FsoGsmBaseUnsolicitedResponseHandler*) self, "^SIND", _cinterion_mc75_unsolicited_response_handler_dachSIND_unsolicited_response_handler_func, self);
	return self;
}


CinterionMc75UnsolicitedResponseHandler* cinterion_mc75_unsolicited_response_handler_new (FsoGsmModem* modem) {
	return cinterion_mc75_unsolicited_response_handler_construct (CINTERION_MC75_TYPE_UNSOLICITED_RESPONSE_HANDLER, modem);
}


static void cinterion_mc75_unsolicited_response_handler_real_dachSSIM_READY (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs) {
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoFrameworkLogger* _tmp2_;
	FsoGsmModem* _tmp3_;
	FsoGsmModem* _tmp4_;
	g_return_if_fail (prefix != NULL);
	g_return_if_fail (rhs != NULL);
	_tmp0_ = fso_gsm_base_unsolicited_response_handler_get_modem ((FsoGsmBaseUnsolicitedResponseHandler*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = ((FsoFrameworkAbstractObject*) _tmp1_)->logger;
	fso_framework_logger_info (_tmp2_, "mc75i sim ready");
	_tmp3_ = fso_gsm_base_unsolicited_response_handler_get_modem ((FsoGsmBaseUnsolicitedResponseHandler*) self);
	_tmp4_ = _tmp3_;
	fso_gsm_modem_advanceToState (_tmp4_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_READY, FALSE);
}


void cinterion_mc75_unsolicited_response_handler_dachSSIM_READY (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs) {
	g_return_if_fail (self != NULL);
	CINTERION_MC75_UNSOLICITED_RESPONSE_HANDLER_GET_CLASS (self)->dachSSIM_READY (self, prefix, rhs);
}


static void cinterion_mc75_unsolicited_response_handler_real_dachSIND (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs) {
	g_return_if_fail (prefix != NULL);
	g_return_if_fail (rhs != NULL);
}


void cinterion_mc75_unsolicited_response_handler_dachSIND (CinterionMc75UnsolicitedResponseHandler* self, const gchar* prefix, const gchar* rhs) {
	g_return_if_fail (self != NULL);
	CINTERION_MC75_UNSOLICITED_RESPONSE_HANDLER_GET_CLASS (self)->dachSIND (self, prefix, rhs);
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void cinterion_mc75_unsolicited_response_handler_real_plusCIEV (FsoGsmAtUnsolicitedResponseHandler* base, const gchar* prefix, const gchar* rhs) {
	CinterionMc75UnsolicitedResponseHandler * self;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	gpointer _tmp2_ = NULL;
	CinterionMc75CinterionPlusCIEV* ciev;
	CinterionMc75CinterionPlusCIEV* _tmp3_;
	const gchar* _tmp4_;
	const gchar* _tmp5_ = NULL;
	const gchar* _tmp6_;
	const gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_;
	FsoGsmConstantsAtResponse _tmp10_ = 0;
	gboolean _tmp11_;
	self = (CinterionMc75UnsolicitedResponseHandler*) base;
	g_return_if_fail (prefix != NULL);
	g_return_if_fail (rhs != NULL);
	_tmp0_ = fso_gsm_base_unsolicited_response_handler_get_modem ((FsoGsmBaseUnsolicitedResponseHandler*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = fso_gsm_modem_createAtCommand (_tmp1_, CINTERION_MC75_TYPE_CINTERION_PLUS_CIEV, (GBoxedCopyFunc) g_object_ref, g_object_unref, "+CIEV");
	ciev = (CinterionMc75CinterionPlusCIEV*) _tmp2_;
	_tmp3_ = ciev;
	_tmp4_ = prefix;
	_tmp5_ = string_to_string (_tmp4_);
	_tmp6_ = rhs;
	_tmp7_ = string_to_string (_tmp6_);
	_tmp8_ = g_strconcat (_tmp5_, ": ", _tmp7_, NULL);
	_tmp9_ = _tmp8_;
	_tmp10_ = fso_gsm_abstract_at_command_validateUrc ((FsoGsmAbstractAtCommand*) _tmp3_, _tmp9_);
	_tmp11_ = _tmp10_ == FSO_GSM_CONSTANTS_AT_RESPONSE_VALID;
	_g_free0 (_tmp9_);
	if (_tmp11_) {
		FsoFrameworkLogger* _tmp12_;
		CinterionMc75CinterionPlusCIEV* _tmp13_;
		gconstpointer _tmp14_;
		CinterionMc75CinterionPlusCIEV* _tmp15_;
		gconstpointer _tmp16_;
		gchar* _tmp17_ = NULL;
		gchar* _tmp18_;
		_tmp12_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp13_ = ciev;
		_tmp14_ = ((FsoGsmTwoParamsAtCommand*) _tmp13_)->value1;
		_tmp15_ = ciev;
		_tmp16_ = ((FsoGsmTwoParamsAtCommand*) _tmp15_)->value2;
		_tmp17_ = g_strdup_printf ("Received unhandled +CIEV %s, %d", (const gchar*) _tmp14_, GPOINTER_TO_INT (_tmp16_));
		_tmp18_ = _tmp17_;
		fso_framework_logger_warning (_tmp12_, _tmp18_);
		_g_free0 (_tmp18_);
	} else {
		FsoFrameworkLogger* _tmp19_;
		const gchar* _tmp20_;
		const gchar* _tmp21_ = NULL;
		gchar* _tmp22_ = NULL;
		gchar* _tmp23_;
		_tmp19_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp20_ = rhs;
		_tmp21_ = string_to_string (_tmp20_);
		_tmp22_ = g_strconcat ("Received invalid +CIEV message ", _tmp21_, ". Please report", NULL);
		_tmp23_ = _tmp22_;
		fso_framework_logger_warning (_tmp19_, _tmp23_);
		_g_free0 (_tmp23_);
	}
	_g_object_unref0 (ciev);
}


static void cinterion_mc75_unsolicited_response_handler_class_init (CinterionMc75UnsolicitedResponseHandlerClass * klass) {
	cinterion_mc75_unsolicited_response_handler_parent_class = g_type_class_peek_parent (klass);
	CINTERION_MC75_UNSOLICITED_RESPONSE_HANDLER_CLASS (klass)->dachSSIM_READY = cinterion_mc75_unsolicited_response_handler_real_dachSSIM_READY;
	CINTERION_MC75_UNSOLICITED_RESPONSE_HANDLER_CLASS (klass)->dachSIND = cinterion_mc75_unsolicited_response_handler_real_dachSIND;
	FSO_GSM_AT_UNSOLICITED_RESPONSE_HANDLER_CLASS (klass)->plusCIEV = cinterion_mc75_unsolicited_response_handler_real_plusCIEV;
}


static void cinterion_mc75_unsolicited_response_handler_instance_init (CinterionMc75UnsolicitedResponseHandler * self) {
}


GType cinterion_mc75_unsolicited_response_handler_get_type (void) {
	return cinterion_mc75_unsolicited_response_handler_type_id;
}


GType cinterion_mc75_unsolicited_response_handler_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (CinterionMc75UnsolicitedResponseHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) cinterion_mc75_unsolicited_response_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (CinterionMc75UnsolicitedResponseHandler), 0, (GInstanceInitFunc) cinterion_mc75_unsolicited_response_handler_instance_init, NULL };
	cinterion_mc75_unsolicited_response_handler_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_AT_UNSOLICITED_RESPONSE_HANDLER, "CinterionMc75UnsolicitedResponseHandler", &g_define_type_info, 0);
	return cinterion_mc75_unsolicited_response_handler_type_id;
}




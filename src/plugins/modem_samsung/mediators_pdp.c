/* mediators_pdp.c generated by valac 0.16.0, the Vala compiler
 * generated from mediators_pdp.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Simon Busch <morphis@gravedo.de>
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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <freesmartphone.h>


#define TYPE_SAMSUNG_PDP_SET_CREDENTIALS (samsung_pdp_set_credentials_get_type ())
#define SAMSUNG_PDP_SET_CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SAMSUNG_PDP_SET_CREDENTIALS, SamsungPdpSetCredentials))
#define SAMSUNG_PDP_SET_CREDENTIALS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SAMSUNG_PDP_SET_CREDENTIALS, SamsungPdpSetCredentialsClass))
#define IS_SAMSUNG_PDP_SET_CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SAMSUNG_PDP_SET_CREDENTIALS))
#define IS_SAMSUNG_PDP_SET_CREDENTIALS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SAMSUNG_PDP_SET_CREDENTIALS))
#define SAMSUNG_PDP_SET_CREDENTIALS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SAMSUNG_PDP_SET_CREDENTIALS, SamsungPdpSetCredentialsClass))

typedef struct _SamsungPdpSetCredentials SamsungPdpSetCredentials;
typedef struct _SamsungPdpSetCredentialsClass SamsungPdpSetCredentialsClass;
typedef struct _SamsungPdpSetCredentialsPrivate SamsungPdpSetCredentialsPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _fso_gsm_context_params_unref0(var) ((var == NULL) ? NULL : (var = (fso_gsm_context_params_unref (var), NULL)))
typedef struct _SamsungPdpSetCredentialsRunData SamsungPdpSetCredentialsRunData;

struct _SamsungPdpSetCredentials {
	FsoGsmPdpSetCredentials parent_instance;
	SamsungPdpSetCredentialsPrivate * priv;
};

struct _SamsungPdpSetCredentialsClass {
	FsoGsmPdpSetCredentialsClass parent_class;
};

struct _SamsungPdpSetCredentialsRunData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungPdpSetCredentials* self;
	gchar* apn;
	gchar* username;
	gchar* password;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoGsmModemData* _tmp2_;
	FsoGsmModemData* data;
	const gchar* _tmp3_;
	const gchar* _tmp4_;
	const gchar* _tmp5_;
	FsoGsmContextParams* _tmp6_;
};


static gpointer samsung_pdp_set_credentials_parent_class = NULL;
static GType samsung_pdp_set_credentials_type_id = 0;

GType samsung_pdp_set_credentials_get_type (void) G_GNUC_CONST;
GType samsung_pdp_set_credentials_register_type (GTypeModule * module);
enum  {
	SAMSUNG_PDP_SET_CREDENTIALS_DUMMY_PROPERTY
};
static void samsung_pdp_set_credentials_real_run_data_free (gpointer _data);
static void samsung_pdp_set_credentials_real_run (FsoGsmPdpSetCredentials* base, const gchar* apn, const gchar* username, const gchar* password, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean samsung_pdp_set_credentials_real_run_co (SamsungPdpSetCredentialsRunData* _data_);
SamsungPdpSetCredentials* samsung_pdp_set_credentials_new (void);
SamsungPdpSetCredentials* samsung_pdp_set_credentials_construct (GType object_type);


static void samsung_pdp_set_credentials_real_run_data_free (gpointer _data) {
	SamsungPdpSetCredentialsRunData* _data_;
	_data_ = _data;
	_g_free0 (_data_->apn);
	_g_free0 (_data_->username);
	_g_free0 (_data_->password);
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungPdpSetCredentialsRunData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void samsung_pdp_set_credentials_real_run (FsoGsmPdpSetCredentials* base, const gchar* apn, const gchar* username, const gchar* password, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungPdpSetCredentials * self;
	SamsungPdpSetCredentialsRunData* _data_;
	SamsungPdpSetCredentials* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	const gchar* _tmp5_;
	gchar* _tmp6_;
	self = (SamsungPdpSetCredentials*) base;
	_data_ = g_slice_new0 (SamsungPdpSetCredentialsRunData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_pdp_set_credentials_real_run);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_pdp_set_credentials_real_run_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = apn;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->apn = _tmp2_;
	_tmp3_ = username;
	_tmp4_ = g_strdup (_tmp3_);
	_data_->username = _tmp4_;
	_tmp5_ = password;
	_tmp6_ = g_strdup (_tmp5_);
	_data_->password = _tmp6_;
	samsung_pdp_set_credentials_real_run_co (_data_);
}


static void samsung_pdp_set_credentials_real_run_finish (FsoGsmPdpSetCredentials* base, GAsyncResult* _res_, GError** error) {
	SamsungPdpSetCredentialsRunData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean samsung_pdp_set_credentials_real_run_co (SamsungPdpSetCredentialsRunData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_abstract_mediator_get_modem ((FsoGsmAbstractMediator*) _data_->self);
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = fso_gsm_modem_data (_data_->_tmp1_);
	_data_->data = _data_->_tmp2_;
	_data_->_tmp3_ = _data_->apn;
	_data_->_tmp4_ = _data_->username;
	_data_->_tmp5_ = _data_->password;
	_data_->_tmp6_ = fso_gsm_context_params_new (_data_->_tmp3_, _data_->_tmp4_, _data_->_tmp5_);
	_fso_gsm_context_params_unref0 (_data_->data->contextParams);
	_data_->data->contextParams = _data_->_tmp6_;
	_g_object_unref0 (_data_->data);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


SamsungPdpSetCredentials* samsung_pdp_set_credentials_construct (GType object_type) {
	SamsungPdpSetCredentials * self = NULL;
	self = (SamsungPdpSetCredentials*) fso_gsm_pdp_set_credentials_construct (object_type);
	return self;
}


SamsungPdpSetCredentials* samsung_pdp_set_credentials_new (void) {
	return samsung_pdp_set_credentials_construct (TYPE_SAMSUNG_PDP_SET_CREDENTIALS);
}


static void samsung_pdp_set_credentials_class_init (SamsungPdpSetCredentialsClass * klass) {
	samsung_pdp_set_credentials_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_PDP_SET_CREDENTIALS_CLASS (klass)->run = samsung_pdp_set_credentials_real_run;
	FSO_GSM_PDP_SET_CREDENTIALS_CLASS (klass)->run_finish = samsung_pdp_set_credentials_real_run_finish;
}


static void samsung_pdp_set_credentials_instance_init (SamsungPdpSetCredentials * self) {
}


/**
 * PDP Mediators
 **/
GType samsung_pdp_set_credentials_get_type (void) {
	return samsung_pdp_set_credentials_type_id;
}


GType samsung_pdp_set_credentials_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SamsungPdpSetCredentialsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) samsung_pdp_set_credentials_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SamsungPdpSetCredentials), 0, (GInstanceInitFunc) samsung_pdp_set_credentials_instance_init, NULL };
	samsung_pdp_set_credentials_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_PDP_SET_CREDENTIALS, "SamsungPdpSetCredentials", &g_define_type_info, 0);
	return samsung_pdp_set_credentials_type_id;
}




/* mediators_sim.c generated by valac 0.16.1, the Vala compiler
 * generated from mediators_sim.vala, do not modify */

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
#include <freesmartphone.h>
#include <stdlib.h>
#include <string.h>
#include <radio.h>
#include <fsotransport.h>
#include <fsobasics.h>


#define TYPE_SAMSUNG_SIM_GET_AUTH_STATUS (samsung_sim_get_auth_status_get_type ())
#define SAMSUNG_SIM_GET_AUTH_STATUS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SAMSUNG_SIM_GET_AUTH_STATUS, SamsungSimGetAuthStatus))
#define SAMSUNG_SIM_GET_AUTH_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SAMSUNG_SIM_GET_AUTH_STATUS, SamsungSimGetAuthStatusClass))
#define IS_SAMSUNG_SIM_GET_AUTH_STATUS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SAMSUNG_SIM_GET_AUTH_STATUS))
#define IS_SAMSUNG_SIM_GET_AUTH_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SAMSUNG_SIM_GET_AUTH_STATUS))
#define SAMSUNG_SIM_GET_AUTH_STATUS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SAMSUNG_SIM_GET_AUTH_STATUS, SamsungSimGetAuthStatusClass))

typedef struct _SamsungSimGetAuthStatus SamsungSimGetAuthStatus;
typedef struct _SamsungSimGetAuthStatusClass SamsungSimGetAuthStatusClass;
typedef struct _SamsungSimGetAuthStatusPrivate SamsungSimGetAuthStatusPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _SamsungSimGetAuthStatusRunData SamsungSimGetAuthStatusRunData;

#define TYPE_SAMSUNG_SIM_SEND_AUTH_CODE (samsung_sim_send_auth_code_get_type ())
#define SAMSUNG_SIM_SEND_AUTH_CODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SAMSUNG_SIM_SEND_AUTH_CODE, SamsungSimSendAuthCode))
#define SAMSUNG_SIM_SEND_AUTH_CODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SAMSUNG_SIM_SEND_AUTH_CODE, SamsungSimSendAuthCodeClass))
#define IS_SAMSUNG_SIM_SEND_AUTH_CODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SAMSUNG_SIM_SEND_AUTH_CODE))
#define IS_SAMSUNG_SIM_SEND_AUTH_CODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SAMSUNG_SIM_SEND_AUTH_CODE))
#define SAMSUNG_SIM_SEND_AUTH_CODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SAMSUNG_SIM_SEND_AUTH_CODE, SamsungSimSendAuthCodeClass))

typedef struct _SamsungSimSendAuthCode SamsungSimSendAuthCode;
typedef struct _SamsungSimSendAuthCodeClass SamsungSimSendAuthCodeClass;
typedef struct _SamsungSimSendAuthCodePrivate SamsungSimSendAuthCodePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define SAMSUNG_TYPE_IPC_CHANNEL (samsung_ipc_channel_get_type ())
#define SAMSUNG_IPC_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannel))
#define SAMSUNG_IPC_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannelClass))
#define SAMSUNG_IS_IPC_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_IPC_CHANNEL))
#define SAMSUNG_IS_IPC_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_IPC_CHANNEL))
#define SAMSUNG_IPC_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannelClass))

typedef struct _SamsungIpcChannel SamsungIpcChannel;
typedef struct _SamsungIpcChannelClass SamsungIpcChannelClass;
typedef struct _SamsungSimSendAuthCodeRunData SamsungSimSendAuthCodeRunData;

#define TYPE_SAMSUNG_SIM_GET_INFORMATION (samsung_sim_get_information_get_type ())
#define SAMSUNG_SIM_GET_INFORMATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SAMSUNG_SIM_GET_INFORMATION, SamsungSimGetInformation))
#define SAMSUNG_SIM_GET_INFORMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SAMSUNG_SIM_GET_INFORMATION, SamsungSimGetInformationClass))
#define IS_SAMSUNG_SIM_GET_INFORMATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SAMSUNG_SIM_GET_INFORMATION))
#define IS_SAMSUNG_SIM_GET_INFORMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SAMSUNG_SIM_GET_INFORMATION))
#define SAMSUNG_SIM_GET_INFORMATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SAMSUNG_SIM_GET_INFORMATION, SamsungSimGetInformationClass))

typedef struct _SamsungSimGetInformation SamsungSimGetInformation;
typedef struct _SamsungSimGetInformationClass SamsungSimGetInformationClass;
typedef struct _SamsungSimGetInformationPrivate SamsungSimGetInformationPrivate;
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
typedef struct _SamsungSimGetInformationRunData SamsungSimGetInformationRunData;

struct _SamsungSimGetAuthStatus {
	FsoGsmSimGetAuthStatus parent_instance;
	SamsungSimGetAuthStatusPrivate * priv;
};

struct _SamsungSimGetAuthStatusClass {
	FsoGsmSimGetAuthStatusClass parent_class;
};

struct _SamsungSimGetAuthStatusRunData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSimGetAuthStatus* self;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoGsmModemData* _tmp2_;
	FsoGsmModemData* data;
	FreeSmartphoneGSMSIMAuthStatus _tmp3_;
};

struct _SamsungSimSendAuthCode {
	FsoGsmSimSendAuthCode parent_instance;
	SamsungSimSendAuthCodePrivate * priv;
};

struct _SamsungSimSendAuthCodeClass {
	FsoGsmSimSendAuthCodeClass parent_class;
};

struct _SamsungSimSendAuthCodeRunData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSimSendAuthCode* self;
	gchar* pin;
	struct ipc_message_info* response;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoGsmChannel* _tmp2_;
	SamsungIpcChannel* channel;
	FsoGsmModem* _tmp3_;
	FsoGsmModem* _tmp4_;
	FsoGsmModemData* _tmp5_;
	FsoGsmModemData* _tmp6_;
	FreeSmartphoneGSMSIMAuthStatus _tmp7_;
	gboolean _tmp8_;
	gboolean _tmp9_;
	const gchar* _tmp10_;
	gint _tmp11_;
	gint _tmp12_;
	const gchar* _tmp13_;
	gint _tmp14_;
	gint _tmp15_;
	gboolean _tmp16_;
	const gchar* _tmp17_;
	gint _tmp18_;
	gint _tmp19_;
	gchar* _tmp20_;
	gchar* _tmp21_;
	gchar* _tmp22_;
	gchar* _tmp23_;
	GError* _tmp24_;
	GError* _tmp25_;
	struct ipc_sec_pin_status_set pinStatusMessage;
	const gchar* _tmp26_;
	SamsungIpcChannel* _tmp27_;
	struct ipc_sec_pin_status_set _tmp28_;
	guint8* _tmp29_;
	gint _tmp29__length1;
	guint8* _tmp30_;
	gint _tmp30__length1;
	struct ipc_message_info* _tmp31_;
	struct ipc_message_info* _tmp32_;
	guint8* _tmp33_;
	gint _tmp33__length1;
	struct ipc_gen_phone_res* phoneresp;
	FsoFrameworkLogger* _tmp34_;
	struct ipc_gen_phone_res* _tmp35_;
	guint16 _tmp36_;
	gchar* _tmp37_;
	gchar* _tmp38_;
	gboolean _tmp39_;
	struct ipc_gen_phone_res* _tmp40_;
	guint16 _tmp41_;
	GError* _tmp42_;
	GError * _inner_error_;
};

struct _SamsungSimGetInformation {
	FsoGsmSimGetInformation parent_instance;
	SamsungSimGetInformationPrivate * priv;
};

struct _SamsungSimGetInformationClass {
	FsoGsmSimGetInformationClass parent_class;
};

struct _SamsungSimGetInformationRunData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSimGetInformation* self;
	struct ipc_message_info* response;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoGsmChannel* _tmp2_;
	SamsungIpcChannel* channel;
	GHashFunc _tmp3_;
	GEqualFunc _tmp4_;
	GHashTable* _tmp5_;
	GHashTable* _tmp6_;
	struct ipc_sec_rsim_access_request rsimreq;
	gint _tmp7_;
	SamsungIpcChannel* _tmp8_;
	struct ipc_sec_rsim_access_request _tmp9_;
	guint8* _tmp10_;
	gint _tmp10__length1;
	guint8* _tmp11_;
	gint _tmp11__length1;
	struct ipc_message_info* _tmp12_;
	struct ipc_message_info* _tmp13_;
	FsoFrameworkLogger* _tmp14_;
	GHashTable* _tmp15_;
	GHashTable* _tmp16_;
	gchar* _tmp17_;
	struct ipc_message_info* _tmp18_;
	struct ipc_message_info _tmp19_;
	gchar* _tmp20_;
	gchar* _tmp21_;
	GVariant* _tmp22_;
	GHashTable* _tmp23_;
	GHashTable* _tmp24_;
	gchar* _tmp25_;
	GVariant* _tmp26_;
	GHashTable* _tmp27_;
	GHashTable* _tmp28_;
	gchar* _tmp29_;
	GVariant* _tmp30_;
	GHashTable* _tmp31_;
	GHashTable* _tmp32_;
	gchar* _tmp33_;
	GVariant* _tmp34_;
};


static gpointer samsung_sim_get_auth_status_parent_class = NULL;
static GType samsung_sim_get_auth_status_type_id = 0;
static gpointer samsung_sim_send_auth_code_parent_class = NULL;
static GType samsung_sim_send_auth_code_type_id = 0;
static gpointer samsung_sim_get_information_parent_class = NULL;
static GType samsung_sim_get_information_type_id = 0;

GType samsung_sim_get_auth_status_get_type (void) G_GNUC_CONST;
GType samsung_sim_get_auth_status_register_type (GTypeModule * module);
enum  {
	SAMSUNG_SIM_GET_AUTH_STATUS_DUMMY_PROPERTY
};
static void samsung_sim_get_auth_status_real_run_data_free (gpointer _data);
static void samsung_sim_get_auth_status_real_run (FsoGsmSimGetAuthStatus* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean samsung_sim_get_auth_status_real_run_co (SamsungSimGetAuthStatusRunData* _data_);
SamsungSimGetAuthStatus* samsung_sim_get_auth_status_new (void);
SamsungSimGetAuthStatus* samsung_sim_get_auth_status_construct (GType object_type);
GType samsung_sim_send_auth_code_get_type (void) G_GNUC_CONST;
GType samsung_sim_send_auth_code_register_type (GTypeModule * module);
enum  {
	SAMSUNG_SIM_SEND_AUTH_CODE_DUMMY_PROPERTY
};
static void samsung_sim_send_auth_code_real_run_data_free (gpointer _data);
static void samsung_sim_send_auth_code_real_run (FsoGsmSimSendAuthCode* base, const gchar* pin, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean samsung_sim_send_auth_code_real_run_co (SamsungSimSendAuthCodeRunData* _data_);
GType samsung_ipc_channel_get_type (void) G_GNUC_CONST;
GType samsung_ipc_channel_register_type (GTypeModule * module);
void samsung_ipc_channel_enqueue_async (SamsungIpcChannel* self, int type, unsigned short command, guint8* data, int data_length1, gint retry, gint timeout, GAsyncReadyCallback _callback_, gpointer _user_data_);
struct ipc_message_info* samsung_ipc_channel_enqueue_finish (SamsungIpcChannel* self, GAsyncResult* _res_);
static void samsung_sim_send_auth_code_run_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
SamsungSimSendAuthCode* samsung_sim_send_auth_code_new (void);
SamsungSimSendAuthCode* samsung_sim_send_auth_code_construct (GType object_type);
GType samsung_sim_get_information_get_type (void) G_GNUC_CONST;
GType samsung_sim_get_information_register_type (GTypeModule * module);
enum  {
	SAMSUNG_SIM_GET_INFORMATION_DUMMY_PROPERTY
};
static void samsung_sim_get_information_real_run_data_free (gpointer _data);
static void samsung_sim_get_information_real_run (FsoGsmSimGetInformation* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean samsung_sim_get_information_real_run_co (SamsungSimGetInformationRunData* _data_);
static void _g_free0_ (gpointer var);
static void _g_variant_unref0_ (gpointer var);
static void samsung_sim_get_information_run_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static GVariant* _variant_new1 (gchar* value);
static GVariant* _variant_new2 (const gchar* value);
static GVariant* _variant_new3 (const gchar* value);
static GVariant* _variant_new4 (const gchar* value);
SamsungSimGetInformation* samsung_sim_get_information_new (void);
SamsungSimGetInformation* samsung_sim_get_information_construct (GType object_type);


static void samsung_sim_get_auth_status_real_run_data_free (gpointer _data) {
	SamsungSimGetAuthStatusRunData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungSimGetAuthStatusRunData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void samsung_sim_get_auth_status_real_run (FsoGsmSimGetAuthStatus* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSimGetAuthStatus * self;
	SamsungSimGetAuthStatusRunData* _data_;
	SamsungSimGetAuthStatus* _tmp0_;
	self = (SamsungSimGetAuthStatus*) base;
	_data_ = g_slice_new0 (SamsungSimGetAuthStatusRunData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sim_get_auth_status_real_run);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sim_get_auth_status_real_run_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	samsung_sim_get_auth_status_real_run_co (_data_);
}


static void samsung_sim_get_auth_status_real_run_finish (FsoGsmSimGetAuthStatus* base, GAsyncResult* _res_, GError** error) {
	SamsungSimGetAuthStatusRunData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean samsung_sim_get_auth_status_real_run_co (SamsungSimGetAuthStatusRunData* _data_) {
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
	_data_->_tmp3_ = _data_->data->simAuthStatus;
	((FsoGsmSimGetAuthStatus*) _data_->self)->status = _data_->_tmp3_;
	_g_object_unref0 (_data_->data);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


SamsungSimGetAuthStatus* samsung_sim_get_auth_status_construct (GType object_type) {
	SamsungSimGetAuthStatus * self = NULL;
	self = (SamsungSimGetAuthStatus*) fso_gsm_sim_get_auth_status_construct (object_type);
	return self;
}


SamsungSimGetAuthStatus* samsung_sim_get_auth_status_new (void) {
	return samsung_sim_get_auth_status_construct (TYPE_SAMSUNG_SIM_GET_AUTH_STATUS);
}


static void samsung_sim_get_auth_status_class_init (SamsungSimGetAuthStatusClass * klass) {
	samsung_sim_get_auth_status_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_SIM_GET_AUTH_STATUS_CLASS (klass)->run = samsung_sim_get_auth_status_real_run;
	FSO_GSM_SIM_GET_AUTH_STATUS_CLASS (klass)->run_finish = samsung_sim_get_auth_status_real_run_finish;
}


static void samsung_sim_get_auth_status_instance_init (SamsungSimGetAuthStatus * self) {
}


GType samsung_sim_get_auth_status_get_type (void) {
	return samsung_sim_get_auth_status_type_id;
}


GType samsung_sim_get_auth_status_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SamsungSimGetAuthStatusClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) samsung_sim_get_auth_status_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SamsungSimGetAuthStatus), 0, (GInstanceInitFunc) samsung_sim_get_auth_status_instance_init, NULL };
	samsung_sim_get_auth_status_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_SIM_GET_AUTH_STATUS, "SamsungSimGetAuthStatus", &g_define_type_info, 0);
	return samsung_sim_get_auth_status_type_id;
}


static void samsung_sim_send_auth_code_real_run_data_free (gpointer _data) {
	SamsungSimSendAuthCodeRunData* _data_;
	_data_ = _data;
	_g_free0 (_data_->pin);
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungSimSendAuthCodeRunData, _data_);
}


static void samsung_sim_send_auth_code_real_run (FsoGsmSimSendAuthCode* base, const gchar* pin, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSimSendAuthCode * self;
	SamsungSimSendAuthCodeRunData* _data_;
	SamsungSimSendAuthCode* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	self = (SamsungSimSendAuthCode*) base;
	_data_ = g_slice_new0 (SamsungSimSendAuthCodeRunData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sim_send_auth_code_real_run);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sim_send_auth_code_real_run_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = pin;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->pin = _tmp2_;
	samsung_sim_send_auth_code_real_run_co (_data_);
}


static void samsung_sim_send_auth_code_real_run_finish (FsoGsmSimSendAuthCode* base, GAsyncResult* _res_, GError** error) {
	SamsungSimSendAuthCodeRunData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static guint8* samsung_ipc_security_pin_status_set_message_get_data (struct ipc_sec_pin_status_set* self, int* result_length1) {
	guint8* result;
	guint8* res;
	gint res_length1;
	gint _res_size_;
	gint _tmp0_;
	guint8* _tmp1_;
	gint _tmp1__length1;
	guint8* _tmp2_;
	gint _tmp2__length1;
	g_return_val_if_fail (self != NULL, NULL);
	res = (guint8*) (&(*self));
	res_length1 = -1;
	_res_size_ = res_length1;
	res_length1 = (gint) sizeof (struct ipc_sec_pin_status_set);
	_tmp0_ = res_length1;
	_tmp1_ = res;
	_tmp1__length1 = res_length1;
	_tmp2_ = _tmp1_;
	_tmp2__length1 = _tmp1__length1;
	if (result_length1) {
		*result_length1 = _tmp2__length1;
	}
	result = _tmp2_;
	return result;
}


static void samsung_sim_send_auth_code_run_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	SamsungSimSendAuthCodeRunData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_sim_send_auth_code_real_run_co (_data_);
}


static gboolean samsung_sim_send_auth_code_real_run_co (SamsungSimSendAuthCodeRunData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_abstract_mediator_get_modem ((FsoGsmAbstractMediator*) _data_->self);
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = fso_gsm_modem_channel (_data_->_tmp1_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp2_) ? ((SamsungIpcChannel*) _data_->_tmp2_) : NULL;
	_data_->_tmp3_ = fso_gsm_abstract_mediator_get_modem ((FsoGsmAbstractMediator*) _data_->self);
	_data_->_tmp4_ = _data_->_tmp3_;
	_data_->_tmp5_ = NULL;
	_data_->_tmp5_ = fso_gsm_modem_data (_data_->_tmp4_);
	_data_->_tmp6_ = _data_->_tmp5_;
	_data_->_tmp7_ = _data_->_tmp6_->simAuthStatus;
	_data_->_tmp8_ = _data_->_tmp7_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_READY;
	_g_object_unref0 (_data_->_tmp6_);
	if (_data_->_tmp8_) {
		_g_object_unref0 (_data_->channel);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp10_ = _data_->pin;
	_data_->_tmp11_ = strlen (_data_->_tmp10_);
	_data_->_tmp12_ = _data_->_tmp11_;
	if (_data_->_tmp12_ != 4) {
		_data_->_tmp13_ = _data_->pin;
		_data_->_tmp14_ = strlen (_data_->_tmp13_);
		_data_->_tmp15_ = _data_->_tmp14_;
		_data_->_tmp9_ = _data_->_tmp15_ != 8;
	} else {
		_data_->_tmp9_ = FALSE;
	}
	_data_->_tmp16_ = _data_->_tmp9_;
	if (_data_->_tmp16_) {
		_data_->_tmp17_ = _data_->pin;
		_data_->_tmp18_ = strlen (_data_->_tmp17_);
		_data_->_tmp19_ = _data_->_tmp18_;
		_data_->_tmp20_ = NULL;
		_data_->_tmp20_ = g_strdup_printf ("%i", _data_->_tmp19_);
		_data_->_tmp21_ = _data_->_tmp20_;
		_data_->_tmp22_ = NULL;
		_data_->_tmp22_ = g_strconcat ("Got pin with invalid length of ", _data_->_tmp21_, NULL);
		_data_->_tmp23_ = _data_->_tmp22_;
		_data_->_tmp24_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, _data_->_tmp23_);
		_data_->_tmp25_ = _data_->_tmp24_;
		_g_free0 (_data_->_tmp23_);
		_g_free0 (_data_->_tmp21_);
		_data_->_inner_error_ = _data_->_tmp25_;
		if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->channel);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->channel);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	memset (&_data_->pinStatusMessage, 0, sizeof (struct ipc_sec_pin_status_set));
	_data_->_tmp26_ = _data_->pin;
	ipc_sec_pin_status_set_setup (&_data_->pinStatusMessage, IPC_SEC_PIN_TYPE_PIN1, _data_->_tmp26_, "");
	_data_->_tmp27_ = _data_->channel;
	_data_->_tmp28_ = _data_->pinStatusMessage;
	_data_->_tmp29_ = samsung_ipc_security_pin_status_set_message_get_data (&_data_->_tmp28_, &_data_->_tmp29__length1);
	_data_->_tmp30_ = _data_->_tmp29_;
	_data_->_tmp30__length1 = _data_->_tmp29__length1;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->_tmp27_, IPC_TYPE_SET, IPC_SEC_PIN_STATUS, _data_->_tmp30_, _data_->_tmp30__length1, 0, 5, samsung_sim_send_auth_code_run_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp31_ = NULL;
	_data_->_tmp31_ = samsung_ipc_channel_enqueue_finish (_data_->_tmp27_, _data_->_res_);
	_data_->response = _data_->_tmp31_;
	_data_->_tmp32_ = _data_->response;
	_data_->_tmp33_ = (*_data_->_tmp32_).data;
	_data_->_tmp33__length1 = (*_data_->_tmp32_).length;
	_data_->phoneresp = (struct ipc_gen_phone_res*) _data_->_tmp33_;
	_data_->_tmp34_ = fso_framework_theLogger;
	_data_->_tmp35_ = _data_->phoneresp;
	_data_->_tmp36_ = (*_data_->_tmp35_).code;
	_data_->_tmp37_ = NULL;
	_data_->_tmp37_ = g_strdup_printf ("code = 0x%04x", (guint) _data_->_tmp36_);
	_data_->_tmp38_ = _data_->_tmp37_;
	_data_->_tmp39_ = FALSE;
	_data_->_tmp39_ = fso_framework_logger_debug (_data_->_tmp34_, _data_->_tmp38_);
	g_assert (_data_->_tmp39_);
	_g_free0 (_data_->_tmp38_);
	_data_->_tmp40_ = _data_->phoneresp;
	_data_->_tmp41_ = (*_data_->_tmp40_).code;
	if (((gint) _data_->_tmp41_) != 0x8000) {
		_data_->_tmp42_ = g_error_new_literal (FREE_SMARTPHONE_GSM_ERROR, FREE_SMARTPHONE_GSM_ERROR_SIM_AUTH_FAILED, "SIM card authentication failed");
		_data_->_inner_error_ = _data_->_tmp42_;
		if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			 (&_data_->pinStatusMessage);
			_g_object_unref0 (_data_->channel);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			 (&_data_->pinStatusMessage);
			_g_object_unref0 (_data_->channel);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	 (&_data_->pinStatusMessage);
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


SamsungSimSendAuthCode* samsung_sim_send_auth_code_construct (GType object_type) {
	SamsungSimSendAuthCode * self = NULL;
	self = (SamsungSimSendAuthCode*) fso_gsm_sim_send_auth_code_construct (object_type);
	return self;
}


SamsungSimSendAuthCode* samsung_sim_send_auth_code_new (void) {
	return samsung_sim_send_auth_code_construct (TYPE_SAMSUNG_SIM_SEND_AUTH_CODE);
}


static void samsung_sim_send_auth_code_class_init (SamsungSimSendAuthCodeClass * klass) {
	samsung_sim_send_auth_code_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_SIM_SEND_AUTH_CODE_CLASS (klass)->run = samsung_sim_send_auth_code_real_run;
	FSO_GSM_SIM_SEND_AUTH_CODE_CLASS (klass)->run_finish = samsung_sim_send_auth_code_real_run_finish;
}


static void samsung_sim_send_auth_code_instance_init (SamsungSimSendAuthCode * self) {
}


GType samsung_sim_send_auth_code_get_type (void) {
	return samsung_sim_send_auth_code_type_id;
}


GType samsung_sim_send_auth_code_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SamsungSimSendAuthCodeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) samsung_sim_send_auth_code_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SamsungSimSendAuthCode), 0, (GInstanceInitFunc) samsung_sim_send_auth_code_instance_init, NULL };
	samsung_sim_send_auth_code_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_SIM_SEND_AUTH_CODE, "SamsungSimSendAuthCode", &g_define_type_info, 0);
	return samsung_sim_send_auth_code_type_id;
}


static void samsung_sim_get_information_real_run_data_free (gpointer _data) {
	SamsungSimGetInformationRunData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungSimGetInformationRunData, _data_);
}


static void samsung_sim_get_information_real_run (FsoGsmSimGetInformation* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSimGetInformation * self;
	SamsungSimGetInformationRunData* _data_;
	SamsungSimGetInformation* _tmp0_;
	self = (SamsungSimGetInformation*) base;
	_data_ = g_slice_new0 (SamsungSimGetInformationRunData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sim_get_information_real_run);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sim_get_information_real_run_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	samsung_sim_get_information_real_run_co (_data_);
}


static void samsung_sim_get_information_real_run_finish (FsoGsmSimGetInformation* base, GAsyncResult* _res_, GError** error) {
	SamsungSimGetInformationRunData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_variant_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_variant_unref (var), NULL));
}


static guint8* samsung_ipc_security_rsim_access_request_message_get_data (struct ipc_sec_rsim_access_request* self, int* result_length1) {
	guint8* result;
	guint8* res;
	gint res_length1;
	gint _res_size_;
	gint _tmp0_;
	guint8* _tmp1_;
	gint _tmp1__length1;
	guint8* _tmp2_;
	gint _tmp2__length1;
	g_return_val_if_fail (self != NULL, NULL);
	res = (guint8*) (&(*self));
	res_length1 = -1;
	_res_size_ = res_length1;
	res_length1 = (gint) sizeof (struct ipc_sec_rsim_access_request);
	_tmp0_ = res_length1;
	_tmp1_ = res;
	_tmp1__length1 = res_length1;
	_tmp2_ = _tmp1_;
	_tmp2__length1 = _tmp1__length1;
	if (result_length1) {
		*result_length1 = _tmp2__length1;
	}
	result = _tmp2_;
	return result;
}


static void samsung_sim_get_information_run_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	SamsungSimGetInformationRunData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_sim_get_information_real_run_co (_data_);
}


static GVariant* _variant_new1 (gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new2 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new3 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new4 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static gboolean samsung_sim_get_information_real_run_co (SamsungSimGetInformationRunData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_abstract_mediator_get_modem ((FsoGsmAbstractMediator*) _data_->self);
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = fso_gsm_modem_channel (_data_->_tmp1_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp2_) ? ((SamsungIpcChannel*) _data_->_tmp2_) : NULL;
	_data_->_tmp3_ = g_str_hash;
	_data_->_tmp4_ = g_str_equal;
	_data_->_tmp5_ = g_hash_table_new_full (_data_->_tmp3_, _data_->_tmp4_, _g_free0_, _g_variant_unref0_);
	_data_->_tmp6_ = _data_->_tmp5_;
	fso_gsm_sim_get_information_set_info ((FsoGsmSimGetInformation*) _data_->self, _data_->_tmp6_);
	_g_hash_table_unref0 (_data_->_tmp6_);
	memset (&_data_->rsimreq, 0, sizeof (struct ipc_sec_rsim_access_request));
	_data_->rsimreq.command = IPC_SEC_RSIM_COMMAND_READ_BINARY;
	_data_->_tmp7_ = 0;
	_data_->_tmp7_ = fso_gsm_constants_simFilesystemEntryNameToCode ("EFspn");
	_data_->rsimreq.fileid = (guint16) _data_->_tmp7_;
	_data_->_tmp8_ = _data_->channel;
	_data_->_tmp9_ = _data_->rsimreq;
	_data_->_tmp10_ = samsung_ipc_security_rsim_access_request_message_get_data (&_data_->_tmp9_, &_data_->_tmp10__length1);
	_data_->_tmp11_ = _data_->_tmp10_;
	_data_->_tmp11__length1 = _data_->_tmp10__length1;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->_tmp8_, IPC_TYPE_GET, IPC_SEC_RSIM_ACCESS, _data_->_tmp11_, _data_->_tmp11__length1, 0, 5, samsung_sim_get_information_run_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp12_ = NULL;
	_data_->_tmp12_ = samsung_ipc_channel_enqueue_finish (_data_->_tmp8_, _data_->_res_);
	_data_->response = _data_->_tmp12_;
	_data_->_tmp13_ = _data_->response;
	if (_data_->_tmp13_ == NULL) {
		_data_->_tmp14_ = fso_framework_theLogger;
		fso_framework_logger_error (_data_->_tmp14_, "Could not retrieve provider name from SIM!");
		 (&_data_->rsimreq);
		_g_object_unref0 (_data_->channel);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp15_ = fso_gsm_sim_get_information_get_info ((FsoGsmSimGetInformation*) _data_->self);
	_data_->_tmp16_ = _data_->_tmp15_;
	_data_->_tmp17_ = g_strdup ("issuer");
	_data_->_tmp18_ = _data_->response;
	_data_->_tmp19_ = *_data_->_tmp18_;
	_data_->_tmp20_ = NULL;
	_data_->_tmp20_ = ipc_sec_rsim_access_response_get_file_data (&_data_->_tmp19_);
	_data_->_tmp21_ = _data_->_tmp20_;
	_data_->_tmp22_ = _variant_new1 (_data_->_tmp21_);
	g_hash_table_insert (_data_->_tmp16_, _data_->_tmp17_, _data_->_tmp22_);
	_g_free0 (_data_->_tmp21_);
	_data_->_tmp23_ = fso_gsm_sim_get_information_get_info ((FsoGsmSimGetInformation*) _data_->self);
	_data_->_tmp24_ = _data_->_tmp23_;
	_data_->_tmp25_ = g_strdup ("phonebooks");
	_data_->_tmp26_ = _variant_new2 ("");
	g_hash_table_insert (_data_->_tmp24_, _data_->_tmp25_, _data_->_tmp26_);
	_data_->_tmp27_ = fso_gsm_sim_get_information_get_info ((FsoGsmSimGetInformation*) _data_->self);
	_data_->_tmp28_ = _data_->_tmp27_;
	_data_->_tmp29_ = g_strdup ("slots");
	_data_->_tmp30_ = _variant_new3 ("0");
	g_hash_table_insert (_data_->_tmp28_, _data_->_tmp29_, _data_->_tmp30_);
	_data_->_tmp31_ = fso_gsm_sim_get_information_get_info ((FsoGsmSimGetInformation*) _data_->self);
	_data_->_tmp32_ = _data_->_tmp31_;
	_data_->_tmp33_ = g_strdup ("used");
	_data_->_tmp34_ = _variant_new4 ("0");
	g_hash_table_insert (_data_->_tmp32_, _data_->_tmp33_, _data_->_tmp34_);
	 (&_data_->rsimreq);
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


SamsungSimGetInformation* samsung_sim_get_information_construct (GType object_type) {
	SamsungSimGetInformation * self = NULL;
	self = (SamsungSimGetInformation*) fso_gsm_sim_get_information_construct (object_type);
	return self;
}


SamsungSimGetInformation* samsung_sim_get_information_new (void) {
	return samsung_sim_get_information_construct (TYPE_SAMSUNG_SIM_GET_INFORMATION);
}


static void samsung_sim_get_information_class_init (SamsungSimGetInformationClass * klass) {
	samsung_sim_get_information_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_SIM_GET_INFORMATION_CLASS (klass)->run = samsung_sim_get_information_real_run;
	FSO_GSM_SIM_GET_INFORMATION_CLASS (klass)->run_finish = samsung_sim_get_information_real_run_finish;
}


static void samsung_sim_get_information_instance_init (SamsungSimGetInformation * self) {
}


GType samsung_sim_get_information_get_type (void) {
	return samsung_sim_get_information_type_id;
}


GType samsung_sim_get_information_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SamsungSimGetInformationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) samsung_sim_get_information_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SamsungSimGetInformation), 0, (GInstanceInitFunc) samsung_sim_get_information_instance_init, NULL };
	samsung_sim_get_information_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_SIM_GET_INFORMATION, "SamsungSimGetInformation", &g_define_type_info, 0);
	return samsung_sim_get_information_type_id;
}




/* isidevicemediators.c generated by valac 0.14.2, the Vala compiler
 * generated from isidevicemediators.vala, do not modify */

/*
 * Copyright (C) 2010-2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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
#include <gisicomm.h>
#include <mtc.h>
#include <fsobasics.h>


#define NOKIA_ISI_TYPE_ISI_DEVICE_GET_INFORMATION (nokia_isi_isi_device_get_information_get_type ())
#define NOKIA_ISI_ISI_DEVICE_GET_INFORMATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_ISI_DEVICE_GET_INFORMATION, NokiaIsiIsiDeviceGetInformation))
#define NOKIA_ISI_ISI_DEVICE_GET_INFORMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_ISI_DEVICE_GET_INFORMATION, NokiaIsiIsiDeviceGetInformationClass))
#define NOKIA_ISI_IS_ISI_DEVICE_GET_INFORMATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_ISI_DEVICE_GET_INFORMATION))
#define NOKIA_ISI_IS_ISI_DEVICE_GET_INFORMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_ISI_DEVICE_GET_INFORMATION))
#define NOKIA_ISI_ISI_DEVICE_GET_INFORMATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_ISI_DEVICE_GET_INFORMATION, NokiaIsiIsiDeviceGetInformationClass))

typedef struct _NokiaIsiIsiDeviceGetInformation NokiaIsiIsiDeviceGetInformation;
typedef struct _NokiaIsiIsiDeviceGetInformationClass NokiaIsiIsiDeviceGetInformationClass;
typedef struct _NokiaIsiIsiDeviceGetInformationPrivate NokiaIsiIsiDeviceGetInformationPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block6Data Block6Data;
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
typedef struct _NokiaIsiIsiDeviceGetInformationRunData NokiaIsiIsiDeviceGetInformationRunData;

#define NOKIA_ISI_TYPE_ISI_DEVICE_SET_FUNCTIONALITY (nokia_isi_isi_device_set_functionality_get_type ())
#define NOKIA_ISI_ISI_DEVICE_SET_FUNCTIONALITY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_ISI_DEVICE_SET_FUNCTIONALITY, NokiaIsiIsiDeviceSetFunctionality))
#define NOKIA_ISI_ISI_DEVICE_SET_FUNCTIONALITY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_ISI_DEVICE_SET_FUNCTIONALITY, NokiaIsiIsiDeviceSetFunctionalityClass))
#define NOKIA_ISI_IS_ISI_DEVICE_SET_FUNCTIONALITY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_ISI_DEVICE_SET_FUNCTIONALITY))
#define NOKIA_ISI_IS_ISI_DEVICE_SET_FUNCTIONALITY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_ISI_DEVICE_SET_FUNCTIONALITY))
#define NOKIA_ISI_ISI_DEVICE_SET_FUNCTIONALITY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_ISI_DEVICE_SET_FUNCTIONALITY, NokiaIsiIsiDeviceSetFunctionalityClass))

typedef struct _NokiaIsiIsiDeviceSetFunctionality NokiaIsiIsiDeviceSetFunctionality;
typedef struct _NokiaIsiIsiDeviceSetFunctionalityClass NokiaIsiIsiDeviceSetFunctionalityClass;
typedef struct _NokiaIsiIsiDeviceSetFunctionalityPrivate NokiaIsiIsiDeviceSetFunctionalityPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _Block7Data Block7Data;
#define _fso_gsm_constants_unref0(var) ((var == NULL) ? NULL : (var = (fso_gsm_constants_unref (var), NULL)))

#define NOKIA_ISI_TYPE_MODEM (nokia_isi_modem_get_type ())
#define NOKIA_ISI_MODEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_MODEM, NokiaIsiModem))
#define NOKIA_ISI_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_MODEM, NokiaIsiModemClass))
#define NOKIA_ISI_IS_MODEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_MODEM))
#define NOKIA_ISI_IS_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_MODEM))
#define NOKIA_ISI_MODEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_MODEM, NokiaIsiModemClass))

typedef struct _NokiaIsiModem NokiaIsiModem;
typedef struct _NokiaIsiModemClass NokiaIsiModemClass;
typedef struct _NokiaIsiIsiDeviceSetFunctionalityRunData NokiaIsiIsiDeviceSetFunctionalityRunData;

struct _NokiaIsiIsiDeviceGetInformation {
	FsoGsmDeviceGetInformation parent_instance;
	NokiaIsiIsiDeviceGetInformationPrivate * priv;
};

struct _NokiaIsiIsiDeviceGetInformationClass {
	FsoGsmDeviceGetInformationClass parent_class;
};

struct _Block6Data {
	int _ref_count_;
	NokiaIsiIsiDeviceGetInformation * self;
	gpointer _async_data_;
};

struct _NokiaIsiIsiDeviceGetInformationRunData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	NokiaIsiIsiDeviceGetInformation* self;
	Block6Data* _data6_;
	GHashFunc _tmp0_;
	GEqualFunc _tmp1_;
	GHashTable* _tmp2_;
	GHashTable* _tmp3_;
	GIsiCommModemAccess* _tmp4_;
	GIsiCommPhoneInfo* _tmp5_;
	GIsiCommModemAccess* _tmp6_;
	GIsiCommPhoneInfo* _tmp7_;
	GIsiCommModemAccess* _tmp8_;
	GIsiCommPhoneInfo* _tmp9_;
	GIsiCommModemAccess* _tmp10_;
	GIsiCommPhoneInfo* _tmp11_;
};

struct _NokiaIsiIsiDeviceSetFunctionality {
	FsoGsmDeviceSetFunctionality parent_instance;
	NokiaIsiIsiDeviceSetFunctionalityPrivate * priv;
};

struct _NokiaIsiIsiDeviceSetFunctionalityClass {
	FsoGsmDeviceSetFunctionalityClass parent_class;
};

struct _Block7Data {
	int _ref_count_;
	NokiaIsiIsiDeviceSetFunctionality * self;
	gchar* curlevel;
	gpointer _async_data_;
};

struct _NokiaIsiIsiDeviceSetFunctionalityRunData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	NokiaIsiIsiDeviceSetFunctionality* self;
	gchar* level;
	gboolean autoregister;
	gchar* pin;
	Block7Data* _data7_;
	FsoGsmConstants* _tmp0_;
	FsoGsmConstants* _tmp1_;
	const gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	gint value;
	gint _tmp5_;
	GError* _tmp6_;
	gchar* _tmp7_;
	GIsiCommModemAccess* _tmp8_;
	GIsiCommMTC* _tmp9_;
	const gchar* _tmp10_;
	const gchar* _tmp11_;
	FsoGsmModem* _tmp12_;
	FsoFrameworkLogger* _tmp13_;
	const gchar* _tmp14_;
	const gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	gboolean _tmp18_;
	gboolean on;
	gboolean online;
	const gchar* _tmp19_;
	const gchar* _tmp20_;
	GQuark _tmp22_;
	GIsiCommModemAccess* _tmp23_;
	GIsiCommMTC* _tmp24_;
	gboolean _tmp25_;
	gboolean _tmp26_;
	FsoGsmModem* _tmp27_;
	FsoGsmModemData* _tmp28_;
	FsoGsmModemData* data;
	FsoGsmModemData* _tmp29_;
	gboolean _tmp30_;
	const gchar* _tmp31_;
	FsoGsmModemData* _tmp32_;
	const gchar* _tmp33_;
	gchar* _tmp34_;
	FsoGsmModem* _tmp35_;
	FsoGsmWatchDog* _tmp36_;
	FsoGsmWatchDog* _tmp37_;
	GError * _inner_error_;
};


static gpointer nokia_isi_isi_device_get_information_parent_class = NULL;
extern GIsiCommModemAccess* nokia_isi_isimodem;
static GType nokia_isi_isi_device_get_information_type_id = 0;
static gpointer nokia_isi_isi_device_set_functionality_parent_class = NULL;
extern NokiaIsiModem* nokia_isi_modem;
static GType nokia_isi_isi_device_set_functionality_type_id = 0;

GType nokia_isi_isi_device_get_information_get_type (void) G_GNUC_CONST;
GType nokia_isi_isi_device_get_information_register_type (GTypeModule * module);
enum  {
	NOKIA_ISI_ISI_DEVICE_GET_INFORMATION_DUMMY_PROPERTY
};
static void nokia_isi_isi_device_get_information_real_run_data_free (gpointer _data);
static void nokia_isi_isi_device_get_information_real_run (FsoGsmDeviceGetInformation* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean nokia_isi_isi_device_get_information_real_run_co (NokiaIsiIsiDeviceGetInformationRunData* _data_);
static Block6Data* block6_data_ref (Block6Data* _data6_);
static void block6_data_unref (Block6Data* _data6_);
static void _g_free0_ (gpointer var);
static void _g_variant_unref0_ (gpointer var);
static void __lambda4_ (Block6Data* _data6_, GIsiCommErrorCode _error_, const gchar* msg);
static GVariant* _variant_new5 (const gchar* value);
static void ___lambda4__gisi_comm_string_result_func (GIsiCommErrorCode _error_, const gchar* _result_, gpointer self);
static void __lambda5_ (Block6Data* _data6_, GIsiCommErrorCode _error_, const gchar* msg);
static GVariant* _variant_new6 (const gchar* value);
static void ___lambda5__gisi_comm_string_result_func (GIsiCommErrorCode _error_, const gchar* _result_, gpointer self);
static void __lambda6_ (Block6Data* _data6_, GIsiCommErrorCode _error_, const gchar* msg);
static GVariant* _variant_new7 (const gchar* value);
static void ___lambda6__gisi_comm_string_result_func (GIsiCommErrorCode _error_, const gchar* _result_, gpointer self);
static void __lambda7_ (Block6Data* _data6_, GIsiCommErrorCode _error_, const gchar* msg);
static GVariant* _variant_new8 (const gchar* value);
static void ___lambda7__gisi_comm_string_result_func (GIsiCommErrorCode _error_, const gchar* _result_, gpointer self);
NokiaIsiIsiDeviceGetInformation* nokia_isi_isi_device_get_information_new (void);
NokiaIsiIsiDeviceGetInformation* nokia_isi_isi_device_get_information_construct (GType object_type);
GType nokia_isi_isi_device_set_functionality_get_type (void) G_GNUC_CONST;
GType nokia_isi_isi_device_set_functionality_register_type (GTypeModule * module);
enum  {
	NOKIA_ISI_ISI_DEVICE_SET_FUNCTIONALITY_DUMMY_PROPERTY
};
static void nokia_isi_isi_device_set_functionality_real_run_data_free (gpointer _data);
static void nokia_isi_isi_device_set_functionality_real_run (FsoGsmDeviceSetFunctionality* base, const gchar* level, gboolean autoregister, const gchar* pin, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean nokia_isi_isi_device_set_functionality_real_run_co (NokiaIsiIsiDeviceSetFunctionalityRunData* _data_);
static Block7Data* block7_data_ref (Block7Data* _data7_);
static void block7_data_unref (Block7Data* _data7_);
static void __lambda8_ (Block7Data* _data7_, GIsiCommErrorCode err, guint8 cur, guint8 tgt);
GType nokia_isi_modem_get_type (void) G_GNUC_CONST;
GType nokia_isi_modem_register_type (GTypeModule * module);
gchar* nokia_isi_modem_deviceFunctionalityModemStateToString (NokiaIsiModem* self, guint8 state);
static void ___lambda8__gisi_comm_mtc_states_result_func (GIsiCommErrorCode _error_, guint8 current, guint8 target, gpointer self);
static void ___lambda9_ (Block7Data* _data7_, GIsiCommErrorCode err, gint res);
static void ____lambda9__gisi_comm_int_result_func (GIsiCommErrorCode _error_, gint _result_, gpointer self);
void nokia_isi_gatherSimStatusAndUpdate (GAsyncReadyCallback _callback_, gpointer _user_data_);
void nokia_isi_gatherSimStatusAndUpdate_finish (GAsyncResult* _res_, GError** error);
static void nokia_isi_isi_device_set_functionality_run_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
NokiaIsiIsiDeviceSetFunctionality* nokia_isi_isi_device_set_functionality_new (void);
NokiaIsiIsiDeviceSetFunctionality* nokia_isi_isi_device_set_functionality_construct (GType object_type);


static void nokia_isi_isi_device_get_information_real_run_data_free (gpointer _data) {
	NokiaIsiIsiDeviceGetInformationRunData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (NokiaIsiIsiDeviceGetInformationRunData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void nokia_isi_isi_device_get_information_real_run (FsoGsmDeviceGetInformation* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	NokiaIsiIsiDeviceGetInformation * self;
	NokiaIsiIsiDeviceGetInformationRunData* _data_;
	NokiaIsiIsiDeviceGetInformation* _tmp0_;
	self = (NokiaIsiIsiDeviceGetInformation*) base;
	_data_ = g_slice_new0 (NokiaIsiIsiDeviceGetInformationRunData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, nokia_isi_isi_device_get_information_real_run);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, nokia_isi_isi_device_get_information_real_run_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	nokia_isi_isi_device_get_information_real_run_co (_data_);
}


static void nokia_isi_isi_device_get_information_real_run_finish (FsoGsmDeviceGetInformation* base, GAsyncResult* _res_, GError** error) {
	NokiaIsiIsiDeviceGetInformationRunData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static Block6Data* block6_data_ref (Block6Data* _data6_) {
	g_atomic_int_inc (&_data6_->_ref_count_);
	return _data6_;
}


static void block6_data_unref (Block6Data* _data6_) {
	if (g_atomic_int_dec_and_test (&_data6_->_ref_count_)) {
		_g_object_unref0 (_data6_->self);
		g_slice_free (Block6Data, _data6_);
	}
}


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_variant_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_variant_unref (var), NULL));
}


static GVariant* _variant_new5 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static void __lambda4_ (Block6Data* _data6_, GIsiCommErrorCode _error_, const gchar* msg) {
	NokiaIsiIsiDeviceGetInformation * self;
	const gchar* _tmp0_ = NULL;
	GIsiCommErrorCode _tmp1_;
	GHashTable* _tmp3_;
	GHashTable* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	GVariant* _tmp7_;
	self = _data6_->self;
	_tmp1_ = _error_;
	if (_tmp1_ != GISI_COMM_ERROR_CODE_OK) {
		_tmp0_ = "<unknown>";
	} else {
		const gchar* _tmp2_;
		_tmp2_ = msg;
		_tmp0_ = _tmp2_;
	}
	_tmp3_ = fso_gsm_device_get_information_get_info ((FsoGsmDeviceGetInformation*) self);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strdup ("manufacturer");
	_tmp6_ = _tmp0_;
	_tmp7_ = _variant_new5 (_tmp6_);
	g_hash_table_insert (_tmp4_, _tmp5_, _tmp7_);
	nokia_isi_isi_device_get_information_real_run_co (_data6_->_async_data_);
}


static void ___lambda4__gisi_comm_string_result_func (GIsiCommErrorCode _error_, const gchar* _result_, gpointer self) {
	__lambda4_ (self, _error_, _result_);
}


static GVariant* _variant_new6 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static void __lambda5_ (Block6Data* _data6_, GIsiCommErrorCode _error_, const gchar* msg) {
	NokiaIsiIsiDeviceGetInformation * self;
	const gchar* _tmp0_ = NULL;
	GIsiCommErrorCode _tmp1_;
	GHashTable* _tmp3_;
	GHashTable* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	GVariant* _tmp7_;
	self = _data6_->self;
	_tmp1_ = _error_;
	if (_tmp1_ != GISI_COMM_ERROR_CODE_OK) {
		_tmp0_ = "<unknown>";
	} else {
		const gchar* _tmp2_;
		_tmp2_ = msg;
		_tmp0_ = _tmp2_;
	}
	_tmp3_ = fso_gsm_device_get_information_get_info ((FsoGsmDeviceGetInformation*) self);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strdup ("model");
	_tmp6_ = _tmp0_;
	_tmp7_ = _variant_new6 (_tmp6_);
	g_hash_table_insert (_tmp4_, _tmp5_, _tmp7_);
	nokia_isi_isi_device_get_information_real_run_co (_data6_->_async_data_);
}


static void ___lambda5__gisi_comm_string_result_func (GIsiCommErrorCode _error_, const gchar* _result_, gpointer self) {
	__lambda5_ (self, _error_, _result_);
}


static GVariant* _variant_new7 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static void __lambda6_ (Block6Data* _data6_, GIsiCommErrorCode _error_, const gchar* msg) {
	NokiaIsiIsiDeviceGetInformation * self;
	const gchar* _tmp0_ = NULL;
	GIsiCommErrorCode _tmp1_;
	GHashTable* _tmp3_;
	GHashTable* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	GVariant* _tmp7_;
	self = _data6_->self;
	_tmp1_ = _error_;
	if (_tmp1_ != GISI_COMM_ERROR_CODE_OK) {
		_tmp0_ = "<unknown>";
	} else {
		const gchar* _tmp2_;
		_tmp2_ = msg;
		_tmp0_ = _tmp2_;
	}
	_tmp3_ = fso_gsm_device_get_information_get_info ((FsoGsmDeviceGetInformation*) self);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strdup ("revision");
	_tmp6_ = _tmp0_;
	_tmp7_ = _variant_new7 (_tmp6_);
	g_hash_table_insert (_tmp4_, _tmp5_, _tmp7_);
	nokia_isi_isi_device_get_information_real_run_co (_data6_->_async_data_);
}


static void ___lambda6__gisi_comm_string_result_func (GIsiCommErrorCode _error_, const gchar* _result_, gpointer self) {
	__lambda6_ (self, _error_, _result_);
}


static GVariant* _variant_new8 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static void __lambda7_ (Block6Data* _data6_, GIsiCommErrorCode _error_, const gchar* msg) {
	NokiaIsiIsiDeviceGetInformation * self;
	const gchar* _tmp0_ = NULL;
	GIsiCommErrorCode _tmp1_;
	GHashTable* _tmp3_;
	GHashTable* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	GVariant* _tmp7_;
	self = _data6_->self;
	_tmp1_ = _error_;
	if (_tmp1_ != GISI_COMM_ERROR_CODE_OK) {
		_tmp0_ = "<unknown>";
	} else {
		const gchar* _tmp2_;
		_tmp2_ = msg;
		_tmp0_ = _tmp2_;
	}
	_tmp3_ = fso_gsm_device_get_information_get_info ((FsoGsmDeviceGetInformation*) self);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strdup ("imei");
	_tmp6_ = _tmp0_;
	_tmp7_ = _variant_new8 (_tmp6_);
	g_hash_table_insert (_tmp4_, _tmp5_, _tmp7_);
	nokia_isi_isi_device_get_information_real_run_co (_data6_->_async_data_);
}


static void ___lambda7__gisi_comm_string_result_func (GIsiCommErrorCode _error_, const gchar* _result_, gpointer self) {
	__lambda7_ (self, _error_, _result_);
}


static gboolean nokia_isi_isi_device_get_information_real_run_co (NokiaIsiIsiDeviceGetInformationRunData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		case 3:
		goto _state_3;
		case 4:
		goto _state_4;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_data6_ = g_slice_new0 (Block6Data);
	_data_->_data6_->_ref_count_ = 1;
	_data_->_data6_->self = g_object_ref (_data_->self);
	_data_->_data6_->_async_data_ = _data_;
	_data_->_tmp0_ = g_str_hash;
	_data_->_tmp1_ = g_str_equal;
	_data_->_tmp2_ = g_hash_table_new_full (_data_->_tmp0_, _data_->_tmp1_, _g_free0_, _g_variant_unref0_);
	_data_->_tmp3_ = _data_->_tmp2_;
	fso_gsm_device_get_information_set_info ((FsoGsmDeviceGetInformation*) _data_->self, _data_->_tmp3_);
	_g_hash_table_unref0 (_data_->_tmp3_);
	_data_->_tmp4_ = nokia_isi_isimodem;
	_data_->_tmp5_ = _data_->_tmp4_->info;
	gisi_comm_phone_info_readManufacturer (_data_->_tmp5_, ___lambda4__gisi_comm_string_result_func, block6_data_ref (_data_->_data6_), block6_data_unref);
	_data_->_state_ = 1;
	return FALSE;
	_state_1:
	;
	_data_->_tmp6_ = nokia_isi_isimodem;
	_data_->_tmp7_ = _data_->_tmp6_->info;
	gisi_comm_phone_info_readModel (_data_->_tmp7_, ___lambda5__gisi_comm_string_result_func, block6_data_ref (_data_->_data6_), block6_data_unref);
	_data_->_state_ = 2;
	return FALSE;
	_state_2:
	;
	_data_->_tmp8_ = nokia_isi_isimodem;
	_data_->_tmp9_ = _data_->_tmp8_->info;
	gisi_comm_phone_info_readVersion (_data_->_tmp9_, ___lambda6__gisi_comm_string_result_func, block6_data_ref (_data_->_data6_), block6_data_unref);
	_data_->_state_ = 3;
	return FALSE;
	_state_3:
	;
	_data_->_tmp10_ = nokia_isi_isimodem;
	_data_->_tmp11_ = _data_->_tmp10_->info;
	gisi_comm_phone_info_readSerial (_data_->_tmp11_, ___lambda7__gisi_comm_string_result_func, block6_data_ref (_data_->_data6_), block6_data_unref);
	_data_->_state_ = 4;
	return FALSE;
	_state_4:
	;
	block6_data_unref (_data_->_data6_);
	_data_->_data6_ = NULL;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


NokiaIsiIsiDeviceGetInformation* nokia_isi_isi_device_get_information_construct (GType object_type) {
	NokiaIsiIsiDeviceGetInformation * self = NULL;
	self = (NokiaIsiIsiDeviceGetInformation*) fso_gsm_device_get_information_construct (object_type);
	return self;
}


NokiaIsiIsiDeviceGetInformation* nokia_isi_isi_device_get_information_new (void) {
	return nokia_isi_isi_device_get_information_construct (NOKIA_ISI_TYPE_ISI_DEVICE_GET_INFORMATION);
}


static void nokia_isi_isi_device_get_information_class_init (NokiaIsiIsiDeviceGetInformationClass * klass) {
	nokia_isi_isi_device_get_information_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_DEVICE_GET_INFORMATION_CLASS (klass)->run = nokia_isi_isi_device_get_information_real_run;
	FSO_GSM_DEVICE_GET_INFORMATION_CLASS (klass)->run_finish = nokia_isi_isi_device_get_information_real_run_finish;
}


static void nokia_isi_isi_device_get_information_instance_init (NokiaIsiIsiDeviceGetInformation * self) {
}


GType nokia_isi_isi_device_get_information_get_type (void) {
	return nokia_isi_isi_device_get_information_type_id;
}


GType nokia_isi_isi_device_get_information_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (NokiaIsiIsiDeviceGetInformationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) nokia_isi_isi_device_get_information_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NokiaIsiIsiDeviceGetInformation), 0, (GInstanceInitFunc) nokia_isi_isi_device_get_information_instance_init, NULL };
	nokia_isi_isi_device_get_information_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_DEVICE_GET_INFORMATION, "NokiaIsiIsiDeviceGetInformation", &g_define_type_info, 0);
	return nokia_isi_isi_device_get_information_type_id;
}


static void nokia_isi_isi_device_set_functionality_real_run_data_free (gpointer _data) {
	NokiaIsiIsiDeviceSetFunctionalityRunData* _data_;
	_data_ = _data;
	_g_free0 (_data_->level);
	_g_free0 (_data_->pin);
	_g_object_unref0 (_data_->self);
	g_slice_free (NokiaIsiIsiDeviceSetFunctionalityRunData, _data_);
}


static void nokia_isi_isi_device_set_functionality_real_run (FsoGsmDeviceSetFunctionality* base, const gchar* level, gboolean autoregister, const gchar* pin, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	NokiaIsiIsiDeviceSetFunctionality * self;
	NokiaIsiIsiDeviceSetFunctionalityRunData* _data_;
	NokiaIsiIsiDeviceSetFunctionality* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	gboolean _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	self = (NokiaIsiIsiDeviceSetFunctionality*) base;
	_data_ = g_slice_new0 (NokiaIsiIsiDeviceSetFunctionalityRunData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, nokia_isi_isi_device_set_functionality_real_run);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, nokia_isi_isi_device_set_functionality_real_run_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = level;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->level = _tmp2_;
	_tmp3_ = autoregister;
	_data_->autoregister = _tmp3_;
	_tmp4_ = pin;
	_tmp5_ = g_strdup (_tmp4_);
	_data_->pin = _tmp5_;
	nokia_isi_isi_device_set_functionality_real_run_co (_data_);
}


static void nokia_isi_isi_device_set_functionality_real_run_finish (FsoGsmDeviceSetFunctionality* base, GAsyncResult* _res_, GError** error) {
	NokiaIsiIsiDeviceSetFunctionalityRunData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static Block7Data* block7_data_ref (Block7Data* _data7_) {
	g_atomic_int_inc (&_data7_->_ref_count_);
	return _data7_;
}


static void block7_data_unref (Block7Data* _data7_) {
	if (g_atomic_int_dec_and_test (&_data7_->_ref_count_)) {
		_g_object_unref0 (_data7_->self);
		_g_free0 (_data7_->curlevel);
		g_slice_free (Block7Data, _data7_);
	}
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void __lambda8_ (Block7Data* _data7_, GIsiCommErrorCode err, guint8 cur, guint8 tgt) {
	NokiaIsiIsiDeviceSetFunctionality * self;
	GIsiCommErrorCode _tmp0_;
	self = _data7_->self;
	_tmp0_ = err;
	if (_tmp0_ == GISI_COMM_ERROR_CODE_OK) {
		NokiaIsiModem* _tmp1_;
		guint8 _tmp2_;
		gchar* _tmp3_ = NULL;
		FsoGsmModem* _tmp4_;
		FsoFrameworkLogger* _tmp5_;
		const gchar* _tmp6_;
		const gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		gchar* _tmp9_;
		_tmp1_ = nokia_isi_modem;
		_tmp2_ = cur;
		_tmp3_ = nokia_isi_modem_deviceFunctionalityModemStateToString (_tmp1_, _tmp2_);
		_g_free0 (_data7_->curlevel);
		_data7_->curlevel = _tmp3_;
		_tmp4_ = fso_gsm_theModem;
		_tmp5_ = ((FsoFrameworkAbstractObject*) _tmp4_)->logger;
		_tmp6_ = _data7_->curlevel;
		_tmp7_ = string_to_string (_tmp6_);
		_tmp8_ = g_strconcat ("current level is ", _tmp7_, NULL);
		_tmp9_ = _tmp8_;
		fso_framework_logger_debug (_tmp5_, _tmp9_);
		_g_free0 (_tmp9_);
	}
	nokia_isi_isi_device_set_functionality_real_run_co (_data7_->_async_data_);
}


static void ___lambda8__gisi_comm_mtc_states_result_func (GIsiCommErrorCode _error_, guint8 current, guint8 target, gpointer self) {
	__lambda8_ (self, _error_, current, target);
}


static void ___lambda9_ (Block7Data* _data7_, GIsiCommErrorCode err, gint res) {
	NokiaIsiIsiDeviceSetFunctionality * self;
	GIsiCommErrorCode _tmp0_;
	GError * _inner_error_ = NULL;
	self = _data7_->self;
	_tmp0_ = err;
	if (_tmp0_ != GISI_COMM_ERROR_CODE_OK) {
		GError* _tmp1_;
		_tmp1_ = g_error_new_literal (FREE_SMARTPHONE_GSM_ERROR, FREE_SMARTPHONE_GSM_ERROR_DEVICE_FAILED, "Unknown ISI Error");
		_inner_error_ = _tmp1_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	nokia_isi_isi_device_set_functionality_real_run_co (_data7_->_async_data_);
}


static void ____lambda9__gisi_comm_int_result_func (GIsiCommErrorCode _error_, gint _result_, gpointer self) {
	___lambda9_ (self, _error_, _result_);
}


static void nokia_isi_isi_device_set_functionality_run_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	NokiaIsiIsiDeviceSetFunctionalityRunData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	nokia_isi_isi_device_set_functionality_real_run_co (_data_);
}


static gboolean nokia_isi_isi_device_set_functionality_real_run_co (NokiaIsiIsiDeviceSetFunctionalityRunData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		case 3:
		goto _state_3;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_data7_ = g_slice_new0 (Block7Data);
	_data_->_data7_->_ref_count_ = 1;
	_data_->_data7_->self = g_object_ref (_data_->self);
	_data_->_data7_->_async_data_ = _data_;
	_data_->_tmp0_ = NULL;
	_data_->_tmp0_ = fso_gsm_constants_instance ();
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->_tmp2_ = _data_->level;
	_data_->_tmp3_ = 0;
	_data_->_tmp3_ = fso_gsm_constants_deviceFunctionalityStringToStatus (_data_->_tmp1_, _data_->_tmp2_);
	_data_->_tmp4_ = _data_->_tmp3_;
	_fso_gsm_constants_unref0 (_data_->_tmp1_);
	_data_->value = _data_->_tmp4_;
	_data_->_tmp5_ = _data_->value;
	if (_data_->_tmp5_ == (-1)) {
		_data_->_tmp6_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, "Functionality needs to be one of \"minimal\", \"airplane\", or \"full\"" \
".");
		_data_->_inner_error_ = _data_->_tmp6_;
		if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			block7_data_unref (_data_->_data7_);
			_data_->_data7_ = NULL;
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			block7_data_unref (_data_->_data7_);
			_data_->_data7_ = NULL;
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp7_ = g_strdup ("unknown");
	_data_->_data7_->curlevel = _data_->_tmp7_;
	_data_->_tmp8_ = nokia_isi_isimodem;
	_data_->_tmp9_ = _data_->_tmp8_->mtc;
	gisi_comm_mtc_readState (_data_->_tmp9_, ___lambda8__gisi_comm_mtc_states_result_func, _data_->_data7_);
	_data_->_state_ = 1;
	return FALSE;
	_state_1:
	;
	_data_->_tmp10_ = _data_->_data7_->curlevel;
	_data_->_tmp11_ = _data_->level;
	if (g_strcmp0 (_data_->_tmp10_, _data_->_tmp11_) != 0) {
		static GQuark _tmp21_label0 = 0;
		static GQuark _tmp21_label1 = 0;
		_data_->_tmp12_ = fso_gsm_theModem;
		_data_->_tmp13_ = ((FsoFrameworkAbstractObject*) _data_->_tmp12_)->logger;
		_data_->_tmp14_ = _data_->level;
		_data_->_tmp15_ = NULL;
		_data_->_tmp15_ = string_to_string (_data_->_tmp14_);
		_data_->_tmp16_ = NULL;
		_data_->_tmp16_ = g_strconcat ("setting Functionality to ", _data_->_tmp15_, NULL);
		_data_->_tmp17_ = _data_->_tmp16_;
		_data_->_tmp18_ = FALSE;
		_data_->_tmp18_ = fso_framework_logger_debug (_data_->_tmp13_, _data_->_tmp17_);
		g_assert (_data_->_tmp18_);
		_g_free0 (_data_->_tmp17_);
		_data_->on = FALSE;
		_data_->online = FALSE;
		_data_->_tmp19_ = _data_->level;
		_data_->_tmp22_ = 0U;
		_data_->_tmp20_ = _data_->_tmp19_;
		_data_->_tmp22_ = (NULL == _data_->_tmp20_) ? 0 : g_quark_from_string (_data_->_tmp20_);
		if (_data_->_tmp22_ == ((0 != _tmp21_label0) ? _tmp21_label0 : (_tmp21_label0 = g_quark_from_static_string ("full")))) {
			switch (0) {
				default:
				{
					_data_->on = TRUE;
					_data_->online = TRUE;
					break;
				}
			}
		} else if (_data_->_tmp22_ == ((0 != _tmp21_label1) ? _tmp21_label1 : (_tmp21_label1 = g_quark_from_static_string ("airplane")))) {
			switch (0) {
				default:
				{
					_data_->on = TRUE;
					break;
				}
			}
		}
		_data_->_tmp23_ = nokia_isi_isimodem;
		_data_->_tmp24_ = _data_->_tmp23_->mtc;
		_data_->_tmp25_ = _data_->on;
		_data_->_tmp26_ = _data_->online;
		gisi_comm_mtc_setState (_data_->_tmp24_, _data_->_tmp25_, _data_->_tmp26_, ____lambda9__gisi_comm_int_result_func, _data_->_data7_);
		_data_->_state_ = 2;
		return FALSE;
		_state_2:
		;
	}
	_data_->_tmp27_ = fso_gsm_theModem;
	_data_->_tmp28_ = NULL;
	_data_->_tmp28_ = fso_gsm_modem_data (_data_->_tmp27_);
	_data_->data = _data_->_tmp28_;
	_data_->_tmp29_ = _data_->data;
	_data_->_tmp30_ = _data_->autoregister;
	_data_->_tmp29_->keepRegistration = _data_->_tmp30_;
	_data_->_tmp31_ = _data_->pin;
	if (g_strcmp0 (_data_->_tmp31_, "") != 0) {
		_data_->_tmp32_ = _data_->data;
		_data_->_tmp33_ = _data_->pin;
		_data_->_tmp34_ = g_strdup (_data_->_tmp33_);
		_g_free0 (_data_->_tmp32_->simPin);
		_data_->_tmp32_->simPin = _data_->_tmp34_;
		_data_->_tmp35_ = fso_gsm_theModem;
		_data_->_tmp36_ = fso_gsm_modem_get_watchdog (_data_->_tmp35_);
		_data_->_tmp37_ = _data_->_tmp36_;
		fso_gsm_watch_dog_resetUnlockMarker (_data_->_tmp37_);
	}
	_data_->_state_ = 3;
	nokia_isi_gatherSimStatusAndUpdate (nokia_isi_isi_device_set_functionality_run_ready, _data_);
	return FALSE;
	_state_3:
	nokia_isi_gatherSimStatusAndUpdate_finish (_data_->_res_, &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->data);
			block7_data_unref (_data_->_data7_);
			_data_->_data7_ = NULL;
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->data);
			block7_data_unref (_data_->_data7_);
			_data_->_data7_ = NULL;
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_g_object_unref0 (_data_->data);
	block7_data_unref (_data_->_data7_);
	_data_->_data7_ = NULL;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


NokiaIsiIsiDeviceSetFunctionality* nokia_isi_isi_device_set_functionality_construct (GType object_type) {
	NokiaIsiIsiDeviceSetFunctionality * self = NULL;
	self = (NokiaIsiIsiDeviceSetFunctionality*) fso_gsm_device_set_functionality_construct (object_type);
	return self;
}


NokiaIsiIsiDeviceSetFunctionality* nokia_isi_isi_device_set_functionality_new (void) {
	return nokia_isi_isi_device_set_functionality_construct (NOKIA_ISI_TYPE_ISI_DEVICE_SET_FUNCTIONALITY);
}


static void nokia_isi_isi_device_set_functionality_class_init (NokiaIsiIsiDeviceSetFunctionalityClass * klass) {
	nokia_isi_isi_device_set_functionality_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_DEVICE_SET_FUNCTIONALITY_CLASS (klass)->run = nokia_isi_isi_device_set_functionality_real_run;
	FSO_GSM_DEVICE_SET_FUNCTIONALITY_CLASS (klass)->run_finish = nokia_isi_isi_device_set_functionality_real_run_finish;
}


static void nokia_isi_isi_device_set_functionality_instance_init (NokiaIsiIsiDeviceSetFunctionality * self) {
}


GType nokia_isi_isi_device_set_functionality_get_type (void) {
	return nokia_isi_isi_device_set_functionality_type_id;
}


GType nokia_isi_isi_device_set_functionality_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (NokiaIsiIsiDeviceSetFunctionalityClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) nokia_isi_isi_device_set_functionality_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NokiaIsiIsiDeviceSetFunctionality), 0, (GInstanceInitFunc) nokia_isi_isi_device_set_functionality_instance_init, NULL };
	nokia_isi_isi_device_set_functionality_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_DEVICE_SET_FUNCTIONALITY, "NokiaIsiIsiDeviceSetFunctionality", &g_define_type_info, 0);
	return nokia_isi_isi_device_set_functionality_type_id;
}




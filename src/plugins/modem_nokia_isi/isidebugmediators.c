/* isidebugmediators.c generated by valac 0.14.2, the Vala compiler
 * generated from isidebugmediators.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <freesmartphone.h>
#include <stdio.h>
#include <gisicomm.h>
#include <fsobasics.h>


#define NOKIA_ISI_TYPE_ISI_DEBUG_COMMAND (nokia_isi_isi_debug_command_get_type ())
#define NOKIA_ISI_ISI_DEBUG_COMMAND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_ISI_DEBUG_COMMAND, NokiaIsiIsiDebugCommand))
#define NOKIA_ISI_ISI_DEBUG_COMMAND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_ISI_DEBUG_COMMAND, NokiaIsiIsiDebugCommandClass))
#define NOKIA_ISI_IS_ISI_DEBUG_COMMAND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_ISI_DEBUG_COMMAND))
#define NOKIA_ISI_IS_ISI_DEBUG_COMMAND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_ISI_DEBUG_COMMAND))
#define NOKIA_ISI_ISI_DEBUG_COMMAND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_ISI_DEBUG_COMMAND, NokiaIsiIsiDebugCommandClass))

typedef struct _NokiaIsiIsiDebugCommand NokiaIsiIsiDebugCommand;
typedef struct _NokiaIsiIsiDebugCommandClass NokiaIsiIsiDebugCommandClass;
typedef struct _NokiaIsiIsiDebugCommandPrivate NokiaIsiIsiDebugCommandPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block5Data Block5Data;
#define _gisi_comm_abstract_base_client_unref0(var) ((var == NULL) ? NULL : (var = (gisi_comm_abstract_base_client_unref (var), NULL)))
typedef struct _NokiaIsiIsiDebugCommandRunData NokiaIsiIsiDebugCommandRunData;

struct _NokiaIsiIsiDebugCommand {
	FsoGsmDebugCommand parent_instance;
	NokiaIsiIsiDebugCommandPrivate * priv;
};

struct _NokiaIsiIsiDebugCommandClass {
	FsoGsmDebugCommandClass parent_class;
};

struct _Block5Data {
	int _ref_count_;
	NokiaIsiIsiDebugCommand * self;
	gpointer _async_data_;
};

struct _NokiaIsiIsiDebugCommandRunData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	NokiaIsiIsiDebugCommand* self;
	gchar* command;
	gchar* category;
	Block5Data* _data5_;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar** _tmp7_;
	gchar** _tmp8_;
	gint _tmp8__length1;
	gboolean _tmp9_;
	const gchar* _tmp10_;
	const gchar* _tmp11_;
	gchar* _tmp12_;
	gchar* _tmp13_;
	GError* _tmp14_;
	GError* _tmp15_;
	guint8* _tmp16_;
	guint8* req;
	gint req_length1;
	gint _req_size_;
	const gchar* _tmp17_;
	gchar** _tmp18_;
	gchar** _tmp19_;
	gchar** byte_collection;
	gint byte_collection_length1;
	gint _byte_collection_size_;
	gint byte_it;
	gchar* _tmp20_;
	gchar* byte;
	guint8 b;
	const gchar* _tmp21_;
	gint _tmp22_;
	const gchar* _tmp23_;
	const gchar* _tmp24_;
	gchar* _tmp25_;
	gchar* _tmp26_;
	GError* _tmp27_;
	GError* _tmp28_;
	guint8* _tmp29_;
	gint _tmp29__length1;
	guint8 _tmp30_;
	GIsiCommAbstractBaseClient* client;
	const gchar* _tmp31_;
	GIsiCommModemAccess* _tmp32_;
	GIsiCommMTC* _tmp33_;
	GIsiCommAbstractBaseClient* _tmp34_;
	const gchar* _tmp35_;
	GIsiCommModemAccess* _tmp36_;
	GIsiCommSIM* _tmp37_;
	GIsiCommAbstractBaseClient* _tmp38_;
	const gchar* _tmp39_;
	GIsiCommModemAccess* _tmp40_;
	GIsiCommSIMAuth* _tmp41_;
	GIsiCommAbstractBaseClient* _tmp42_;
	const gchar* _tmp43_;
	GIsiCommModemAccess* _tmp44_;
	GIsiCommNetwork* _tmp45_;
	GIsiCommAbstractBaseClient* _tmp46_;
	const gchar* _tmp47_;
	GIsiCommModemAccess* _tmp48_;
	GIsiCommCall* _tmp49_;
	GIsiCommAbstractBaseClient* _tmp50_;
	const gchar* _tmp51_;
	GIsiCommModemAccess* _tmp52_;
	GIsiCommPhoneInfo* _tmp53_;
	GIsiCommAbstractBaseClient* _tmp54_;
	GIsiCommAbstractBaseClient* _tmp55_;
	guint8* _tmp56_;
	gint _tmp56__length1;
	GError * _inner_error_;
};


static gpointer nokia_isi_isi_debug_command_parent_class = NULL;
extern GIsiCommModemAccess* nokia_isi_isimodem;
static GType nokia_isi_isi_debug_command_type_id = 0;

GType nokia_isi_isi_debug_command_get_type (void) G_GNUC_CONST;
GType nokia_isi_isi_debug_command_register_type (GTypeModule * module);
enum  {
	NOKIA_ISI_ISI_DEBUG_COMMAND_DUMMY_PROPERTY
};
static void nokia_isi_isi_debug_command_real_run_data_free (gpointer _data);
static void nokia_isi_isi_debug_command_real_run (FsoGsmDebugCommand* base, const gchar* command, const gchar* category, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean nokia_isi_isi_debug_command_real_run_co (NokiaIsiIsiDebugCommandRunData* _data_);
static Block5Data* block5_data_ref (Block5Data* _data5_);
static void block5_data_unref (Block5Data* _data5_);
static gboolean _vala_string_array_contains (gchar** stack, int stack_length, gchar* needle);
static void _vala_array_add2 (guint8** array, int* length, int* size, guint8 value);
static void __lambda23_ (Block5Data* _data5_, GIsiCommErrorCode _error_, guint8* answer, int answer_length1);
static void ___lambda23__gisi_comm_byte_array_result_func (GIsiCommErrorCode code, guint8* array, int array_length1, gpointer self);
NokiaIsiIsiDebugCommand* nokia_isi_isi_debug_command_new (void);
NokiaIsiIsiDebugCommand* nokia_isi_isi_debug_command_construct (GType object_type);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


static void nokia_isi_isi_debug_command_real_run_data_free (gpointer _data) {
	NokiaIsiIsiDebugCommandRunData* _data_;
	_data_ = _data;
	_g_free0 (_data_->command);
	_g_free0 (_data_->category);
	_g_object_unref0 (_data_->self);
	g_slice_free (NokiaIsiIsiDebugCommandRunData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void nokia_isi_isi_debug_command_real_run (FsoGsmDebugCommand* base, const gchar* command, const gchar* category, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	NokiaIsiIsiDebugCommand * self;
	NokiaIsiIsiDebugCommandRunData* _data_;
	NokiaIsiIsiDebugCommand* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	self = (NokiaIsiIsiDebugCommand*) base;
	_data_ = g_slice_new0 (NokiaIsiIsiDebugCommandRunData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, nokia_isi_isi_debug_command_real_run);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, nokia_isi_isi_debug_command_real_run_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = command;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->command = _tmp2_;
	_tmp3_ = category;
	_tmp4_ = g_strdup (_tmp3_);
	_data_->category = _tmp4_;
	nokia_isi_isi_debug_command_real_run_co (_data_);
}


static void nokia_isi_isi_debug_command_real_run_finish (FsoGsmDebugCommand* base, GAsyncResult* _res_, GError** error) {
	NokiaIsiIsiDebugCommandRunData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static Block5Data* block5_data_ref (Block5Data* _data5_) {
	g_atomic_int_inc (&_data5_->_ref_count_);
	return _data5_;
}


static void block5_data_unref (Block5Data* _data5_) {
	if (g_atomic_int_dec_and_test (&_data5_->_ref_count_)) {
		_g_object_unref0 (_data5_->self);
		g_slice_free (Block5Data, _data5_);
	}
}


static gboolean _vala_string_array_contains (gchar** stack, int stack_length, gchar* needle) {
	int i;
	for (i = 0; i < stack_length; i++) {
		if (g_strcmp0 (stack[i], needle) == 0) {
			return TRUE;
		}
	}
	return FALSE;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void _vala_array_add2 (guint8** array, int* length, int* size, guint8 value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (guint8, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static gpointer _gisi_comm_abstract_base_client_ref0 (gpointer self) {
	return self ? gisi_comm_abstract_base_client_ref (self) : NULL;
}


static void __lambda23_ (Block5Data* _data5_, GIsiCommErrorCode _error_, guint8* answer, int answer_length1) {
	NokiaIsiIsiDebugCommand * self;
	GIsiCommErrorCode _tmp0_;
	self = _data5_->self;
	_tmp0_ = _error_;
	if (_tmp0_ == GISI_COMM_ERROR_CODE_OK) {
		guint8* _tmp1_;
		gint _tmp1__length1;
		gchar* _tmp2_ = NULL;
		gchar* _tmp3_;
		_tmp1_ = answer;
		_tmp1__length1 = answer_length1;
		_tmp2_ = fso_framework_string_handling_hexdump (_tmp1_, _tmp1__length1, 16, "", (guchar) '?');
		_tmp3_ = _tmp2_;
		fso_gsm_debug_command_set_response ((FsoGsmDebugCommand*) self, _tmp3_);
		_g_free0 (_tmp3_);
	} else {
		fso_gsm_debug_command_set_response ((FsoGsmDebugCommand*) self, "<ISI COMMUNICATION ERROR>");
	}
	nokia_isi_isi_debug_command_real_run_co (_data5_->_async_data_);
}


static void ___lambda23__gisi_comm_byte_array_result_func (GIsiCommErrorCode code, guint8* array, int array_length1, gpointer self) {
	__lambda23_ (self, code, array, array_length1);
}


static gboolean nokia_isi_isi_debug_command_real_run_co (NokiaIsiIsiDebugCommandRunData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_data5_ = g_slice_new0 (Block5Data);
	_data_->_data5_->_ref_count_ = 1;
	_data_->_data5_->self = g_object_ref (_data_->self);
	_data_->_data5_->_async_data_ = _data_;
	_data_->_tmp0_ = _data_->command;
	_data_->_tmp1_ = g_strdup ("MTC");
	_data_->_tmp2_ = g_strdup ("SIM");
	_data_->_tmp3_ = g_strdup ("SIMAUTH");
	_data_->_tmp4_ = g_strdup ("NET");
	_data_->_tmp5_ = g_strdup ("CALL");
	_data_->_tmp6_ = g_strdup ("PHONEINFO");
	_data_->_tmp7_ = NULL;
	_data_->_tmp7_ = g_new0 (gchar*, 6 + 1);
	_data_->_tmp7_[0] = _data_->_tmp1_;
	_data_->_tmp7_[1] = _data_->_tmp2_;
	_data_->_tmp7_[2] = _data_->_tmp3_;
	_data_->_tmp7_[3] = _data_->_tmp4_;
	_data_->_tmp7_[4] = _data_->_tmp5_;
	_data_->_tmp7_[5] = _data_->_tmp6_;
	_data_->_tmp8_ = _data_->_tmp7_;
	_data_->_tmp8__length1 = 6;
	_data_->_tmp9_ = !_vala_string_array_contains (_data_->_tmp8_, 6, _data_->_tmp0_);
	_data_->_tmp8_ = (_vala_array_free (_data_->_tmp8_, _data_->_tmp8__length1, (GDestroyNotify) g_free), NULL);
	if (_data_->_tmp9_) {
		_data_->_tmp10_ = _data_->command;
		_data_->_tmp11_ = NULL;
		_data_->_tmp11_ = string_to_string (_data_->_tmp10_);
		_data_->_tmp12_ = NULL;
		_data_->_tmp12_ = g_strconcat ("Subsystem ", _data_->_tmp11_, " not known", NULL);
		_data_->_tmp13_ = _data_->_tmp12_;
		_data_->_tmp14_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, _data_->_tmp13_);
		_data_->_tmp15_ = _data_->_tmp14_;
		_g_free0 (_data_->_tmp13_);
		_data_->_inner_error_ = _data_->_tmp15_;
		if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			block5_data_unref (_data_->_data5_);
			_data_->_data5_ = NULL;
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			block5_data_unref (_data_->_data5_);
			_data_->_data5_ = NULL;
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp16_ = NULL;
	_data_->_tmp16_ = g_new0 (guint8, 0);
	_data_->req = _data_->_tmp16_;
	_data_->req_length1 = 0;
	_data_->_req_size_ = _data_->req_length1;
	_data_->_tmp17_ = _data_->category;
	_data_->_tmp19_ = NULL;
	_data_->_tmp19_ = _data_->_tmp18_ = g_strsplit (_data_->_tmp17_, " ", 0);
	{
		_data_->byte_collection_length1 = 0;
		_data_->_byte_collection_size_ = 0;
		_data_->byte_collection = _data_->_tmp19_;
		_data_->byte_collection_length1 = _vala_array_length (_data_->_tmp18_);
		_data_->byte_it = 0;
		for (_data_->byte_it = 0; _data_->byte_it < _vala_array_length (_data_->_tmp18_); _data_->byte_it = _data_->byte_it + 1) {
			_data_->_tmp20_ = g_strdup (_data_->byte_collection[_data_->byte_it]);
			_data_->byte = _data_->_tmp20_;
			{
				_data_->b = (guint8) 0;
				_data_->_tmp21_ = _data_->byte;
				_data_->_tmp22_ = 0;
				_data_->_tmp22_ = sscanf (_data_->_tmp21_, "%X", &_data_->b);
				if (0 == _data_->_tmp22_) {
					_data_->_tmp23_ = _data_->byte;
					_data_->_tmp24_ = NULL;
					_data_->_tmp24_ = string_to_string (_data_->_tmp23_);
					_data_->_tmp25_ = NULL;
					_data_->_tmp25_ = g_strconcat ("Can't parse ", _data_->_tmp24_, " in command", NULL);
					_data_->_tmp26_ = _data_->_tmp25_;
					_data_->_tmp27_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INVALID_PARAMETER, _data_->_tmp26_);
					_data_->_tmp28_ = _data_->_tmp27_;
					_g_free0 (_data_->_tmp26_);
					_data_->_inner_error_ = _data_->_tmp28_;
					if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
						g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
						g_error_free (_data_->_inner_error_);
						_g_free0 (_data_->byte);
						_data_->byte_collection = (_vala_array_free (_data_->byte_collection, _data_->byte_collection_length1, (GDestroyNotify) g_free), NULL);
						_data_->req = (g_free (_data_->req), NULL);
						block5_data_unref (_data_->_data5_);
						_data_->_data5_ = NULL;
						if (_data_->_state_ == 0) {
							g_simple_async_result_complete_in_idle (_data_->_async_result);
						} else {
							g_simple_async_result_complete (_data_->_async_result);
						}
						g_object_unref (_data_->_async_result);
						return FALSE;
					} else {
						_g_free0 (_data_->byte);
						_data_->byte_collection = (_vala_array_free (_data_->byte_collection, _data_->byte_collection_length1, (GDestroyNotify) g_free), NULL);
						_data_->req = (g_free (_data_->req), NULL);
						block5_data_unref (_data_->_data5_);
						_data_->_data5_ = NULL;
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
						g_clear_error (&_data_->_inner_error_);
						return FALSE;
					}
				}
				_data_->_tmp29_ = _data_->req;
				_data_->_tmp29__length1 = _data_->req_length1;
				_data_->_tmp30_ = _data_->b;
				_vala_array_add2 (&_data_->req, &_data_->req_length1, &_data_->_req_size_, _data_->_tmp30_);
				_g_free0 (_data_->byte);
			}
		}
		_data_->byte_collection = (_vala_array_free (_data_->byte_collection, _data_->byte_collection_length1, (GDestroyNotify) g_free), NULL);
	}
	_data_->client = NULL;
	_data_->_tmp31_ = _data_->command;
	if (g_strcmp0 (_data_->_tmp31_, "MTC") == 0) {
		_data_->_tmp32_ = nokia_isi_isimodem;
		_data_->_tmp33_ = _data_->_tmp32_->mtc;
		_data_->_tmp34_ = _gisi_comm_abstract_base_client_ref0 ((GIsiCommAbstractBaseClient*) _data_->_tmp33_);
		_gisi_comm_abstract_base_client_unref0 (_data_->client);
		_data_->client = _data_->_tmp34_;
	} else {
		_data_->_tmp35_ = _data_->command;
		if (g_strcmp0 (_data_->_tmp35_, "SIM") == 0) {
			_data_->_tmp36_ = nokia_isi_isimodem;
			_data_->_tmp37_ = _data_->_tmp36_->sim;
			_data_->_tmp38_ = _gisi_comm_abstract_base_client_ref0 ((GIsiCommAbstractBaseClient*) _data_->_tmp37_);
			_gisi_comm_abstract_base_client_unref0 (_data_->client);
			_data_->client = _data_->_tmp38_;
		} else {
			_data_->_tmp39_ = _data_->command;
			if (g_strcmp0 (_data_->_tmp39_, "SIMAUTH") == 0) {
				_data_->_tmp40_ = nokia_isi_isimodem;
				_data_->_tmp41_ = _data_->_tmp40_->simauth;
				_data_->_tmp42_ = _gisi_comm_abstract_base_client_ref0 ((GIsiCommAbstractBaseClient*) _data_->_tmp41_);
				_gisi_comm_abstract_base_client_unref0 (_data_->client);
				_data_->client = _data_->_tmp42_;
			} else {
				_data_->_tmp43_ = _data_->command;
				if (g_strcmp0 (_data_->_tmp43_, "NET") == 0) {
					_data_->_tmp44_ = nokia_isi_isimodem;
					_data_->_tmp45_ = _data_->_tmp44_->net;
					_data_->_tmp46_ = _gisi_comm_abstract_base_client_ref0 ((GIsiCommAbstractBaseClient*) _data_->_tmp45_);
					_gisi_comm_abstract_base_client_unref0 (_data_->client);
					_data_->client = _data_->_tmp46_;
				} else {
					_data_->_tmp47_ = _data_->command;
					if (g_strcmp0 (_data_->_tmp47_, "CALL") == 0) {
						_data_->_tmp48_ = nokia_isi_isimodem;
						_data_->_tmp49_ = _data_->_tmp48_->call;
						_data_->_tmp50_ = _gisi_comm_abstract_base_client_ref0 ((GIsiCommAbstractBaseClient*) _data_->_tmp49_);
						_gisi_comm_abstract_base_client_unref0 (_data_->client);
						_data_->client = _data_->_tmp50_;
					} else {
						_data_->_tmp51_ = _data_->command;
						if (g_strcmp0 (_data_->_tmp51_, "PHONEINFO") == 0) {
							_data_->_tmp52_ = nokia_isi_isimodem;
							_data_->_tmp53_ = _data_->_tmp52_->info;
							_data_->_tmp54_ = _gisi_comm_abstract_base_client_ref0 ((GIsiCommAbstractBaseClient*) _data_->_tmp53_);
							_gisi_comm_abstract_base_client_unref0 (_data_->client);
							_data_->client = _data_->_tmp54_;
						}
					}
				}
			}
		}
	}
	_data_->_tmp55_ = _data_->client;
	_data_->_tmp56_ = _data_->req;
	_data_->_tmp56__length1 = _data_->req_length1;
	gisi_comm_abstract_base_client_sendGenericRequest (_data_->_tmp55_, _data_->_tmp56_, _data_->_tmp56__length1, ___lambda23__gisi_comm_byte_array_result_func, _data_->_data5_);
	_data_->_state_ = 1;
	return FALSE;
	_state_1:
	;
	_gisi_comm_abstract_base_client_unref0 (_data_->client);
	_data_->req = (g_free (_data_->req), NULL);
	block5_data_unref (_data_->_data5_);
	_data_->_data5_ = NULL;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


NokiaIsiIsiDebugCommand* nokia_isi_isi_debug_command_construct (GType object_type) {
	NokiaIsiIsiDebugCommand * self = NULL;
	self = (NokiaIsiIsiDebugCommand*) fso_gsm_debug_command_construct (object_type);
	return self;
}


NokiaIsiIsiDebugCommand* nokia_isi_isi_debug_command_new (void) {
	return nokia_isi_isi_debug_command_construct (NOKIA_ISI_TYPE_ISI_DEBUG_COMMAND);
}


static void nokia_isi_isi_debug_command_class_init (NokiaIsiIsiDebugCommandClass * klass) {
	nokia_isi_isi_debug_command_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_DEBUG_COMMAND_CLASS (klass)->run = nokia_isi_isi_debug_command_real_run;
	FSO_GSM_DEBUG_COMMAND_CLASS (klass)->run_finish = nokia_isi_isi_debug_command_real_run_finish;
}


static void nokia_isi_isi_debug_command_instance_init (NokiaIsiIsiDebugCommand * self) {
}


GType nokia_isi_isi_debug_command_get_type (void) {
	return nokia_isi_isi_debug_command_type_id;
}


GType nokia_isi_isi_debug_command_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (NokiaIsiIsiDebugCommandClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) nokia_isi_isi_debug_command_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NokiaIsiIsiDebugCommand), 0, (GInstanceInitFunc) nokia_isi_isi_debug_command_instance_init, NULL };
	nokia_isi_isi_debug_command_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_DEBUG_COMMAND, "NokiaIsiIsiDebugCommand", &g_define_type_info, 0);
	return nokia_isi_isi_debug_command_type_id;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}




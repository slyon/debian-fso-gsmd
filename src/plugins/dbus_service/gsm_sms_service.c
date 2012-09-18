/* gsm_sms_service.c generated by valac 0.16.0, the Vala compiler
 * generated from gsm_sms_service.vala, do not modify */

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
#include <fsobasics.h>
#include <fsogsm.h>
#include <freesmartphone.h>
#include <gio/gio.h>
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

#define FSO_GSM_TYPE_GSM_SMS_SERVICE (fso_gsm_gsm_sms_service_get_type ())
#define FSO_GSM_GSM_SMS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_GSM_SMS_SERVICE, FsoGsmGsmSmsService))
#define FSO_GSM_GSM_SMS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_GSM_SMS_SERVICE, FsoGsmGsmSmsServiceClass))
#define FSO_GSM_IS_GSM_SMS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_GSM_SMS_SERVICE))
#define FSO_GSM_IS_GSM_SMS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_GSM_SMS_SERVICE))
#define FSO_GSM_GSM_SMS_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_GSM_SMS_SERVICE, FsoGsmGsmSmsServiceClass))

typedef struct _FsoGsmGsmSmsService FsoGsmGsmSmsService;
typedef struct _FsoGsmGsmSmsServiceClass FsoGsmGsmSmsServiceClass;
typedef struct _FsoGsmGsmSmsServicePrivate FsoGsmGsmSmsServicePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _FsoGsmGsmSmsServiceGetSizeForTextMessageData FsoGsmGsmSmsServiceGetSizeForTextMessageData;
typedef struct _FsoGsmGsmSmsServiceRetrieveTextMessagesData FsoGsmGsmSmsServiceRetrieveTextMessagesData;
typedef struct _FsoGsmGsmSmsServiceSendTextMessageData FsoGsmGsmSmsServiceSendTextMessageData;

struct _FsoGsmService {
	FsoFrameworkAbstractObject parent_instance;
	FsoGsmServicePrivate * priv;
	FsoGsmModem* modem;
};

struct _FsoGsmServiceClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _FsoGsmGsmSmsService {
	FsoGsmService parent_instance;
	FsoGsmGsmSmsServicePrivate * priv;
};

struct _FsoGsmGsmSmsServiceClass {
	FsoGsmServiceClass parent_class;
};

struct _FsoGsmGsmSmsServiceGetSizeForTextMessageData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmGsmSmsService* self;
	gchar* contents;
	guint result;
	FsoGsmModem* _tmp0_;
	gpointer _tmp1_;
	FsoGsmSmsGetSizeForTextMessage* m;
	FsoGsmSmsGetSizeForTextMessage* _tmp2_;
	const gchar* _tmp3_;
	FsoGsmSmsGetSizeForTextMessage* _tmp4_;
	guint _tmp5_;
	guint _tmp6_;
	GError * _inner_error_;
};

struct _FsoGsmGsmSmsServiceRetrieveTextMessagesData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmGsmSmsService* self;
	FreeSmartphoneGSMSIMMessage* result;
	gint result_length1;
	FsoGsmModem* _tmp0_;
	gpointer _tmp1_;
	FsoGsmSmsRetrieveTextMessages* m;
	FsoGsmSmsRetrieveTextMessages* _tmp2_;
	FsoGsmSmsRetrieveTextMessages* _tmp3_;
	FreeSmartphoneGSMSIMMessage* _tmp4_;
	gint _tmp4__length1;
	FreeSmartphoneGSMSIMMessage* _tmp5_;
	gint _tmp5__length1;
	FreeSmartphoneGSMSIMMessage* _tmp6_;
	gint _tmp6__length1;
	FreeSmartphoneGSMSIMMessage* _tmp7_;
	gint _tmp7__length1;
	GError * _inner_error_;
};

struct _FsoGsmGsmSmsServiceSendTextMessageData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmGsmSmsService* self;
	gchar* recipient_number;
	gchar* contents;
	gboolean want_report;
	gint transaction_index;
	gchar* timestamp;
	FsoGsmModem* _tmp0_;
	gpointer _tmp1_;
	FsoGsmSmsSendTextMessage* m;
	FsoGsmSmsSendTextMessage* _tmp2_;
	const gchar* _tmp3_;
	const gchar* _tmp4_;
	gboolean _tmp5_;
	FsoGsmSmsSendTextMessage* _tmp6_;
	gint _tmp7_;
	gint _tmp8_;
	FsoGsmSmsSendTextMessage* _tmp9_;
	const gchar* _tmp10_;
	const gchar* _tmp11_;
	gchar* _tmp12_;
	GError * _inner_error_;
};


static gpointer fso_gsm_gsm_sms_service_parent_class = NULL;
static FreeSmartphoneGSMSMSIface* fso_gsm_gsm_sms_service_free_smartphone_gsm_sms_parent_iface = NULL;
static GType fso_gsm_gsm_sms_service_type_id = 0;

GType fso_gsm_service_get_type (void) G_GNUC_CONST;
GType fso_gsm_service_register_type (GTypeModule * module);
GType fso_gsm_gsm_sms_service_get_type (void) G_GNUC_CONST;
GType fso_gsm_gsm_sms_service_register_type (GTypeModule * module);
enum  {
	FSO_GSM_GSM_SMS_SERVICE_DUMMY_PROPERTY
};
static void fso_gsm_gsm_sms_service_real_get_size_for_text_message_data_free (gpointer _data);
static void fso_gsm_gsm_sms_service_real_get_size_for_text_message (FreeSmartphoneGSMSMS* base, const gchar* contents, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_gsm_sms_service_real_get_size_for_text_message_co (FsoGsmGsmSmsServiceGetSizeForTextMessageData* _data_);
void fso_gsm_service_checkAvailability (FsoGsmService* self, FsoGsmModemStatus required, GError** error);
static void fso_gsm_gsm_sms_service_get_size_for_text_message_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void _vala_FreeSmartphoneGSMSIMMessage_array_free (FreeSmartphoneGSMSIMMessage* array, gint array_length);
static void fso_gsm_gsm_sms_service_real_retrieve_text_messages_data_free (gpointer _data);
static void fso_gsm_gsm_sms_service_real_retrieve_text_messages (FreeSmartphoneGSMSMS* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_gsm_sms_service_real_retrieve_text_messages_co (FsoGsmGsmSmsServiceRetrieveTextMessagesData* _data_);
static void fso_gsm_gsm_sms_service_retrieve_text_messages_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static FreeSmartphoneGSMSIMMessage* _vala_array_dup2 (FreeSmartphoneGSMSIMMessage* self, int length);
static void fso_gsm_gsm_sms_service_real_send_text_message_data_free (gpointer _data);
static void fso_gsm_gsm_sms_service_real_send_text_message (FreeSmartphoneGSMSMS* base, const gchar* recipient_number, const gchar* contents, gboolean want_report, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_gsm_sms_service_real_send_text_message_co (FsoGsmGsmSmsServiceSendTextMessageData* _data_);
static void fso_gsm_gsm_sms_service_send_text_message_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
FsoGsmGsmSmsService* fso_gsm_gsm_sms_service_new (void);
FsoGsmGsmSmsService* fso_gsm_gsm_sms_service_construct (GType object_type);
FsoGsmService* fso_gsm_service_new (void);
FsoGsmService* fso_gsm_service_construct (GType object_type);


static void fso_gsm_gsm_sms_service_real_get_size_for_text_message_data_free (gpointer _data) {
	FsoGsmGsmSmsServiceGetSizeForTextMessageData* _data_;
	_data_ = _data;
	_g_free0 (_data_->contents);
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmGsmSmsServiceGetSizeForTextMessageData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void fso_gsm_gsm_sms_service_real_get_size_for_text_message (FreeSmartphoneGSMSMS* base, const gchar* contents, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmGsmSmsService * self;
	FsoGsmGsmSmsServiceGetSizeForTextMessageData* _data_;
	FsoGsmGsmSmsService* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	self = (FsoGsmGsmSmsService*) base;
	_data_ = g_slice_new0 (FsoGsmGsmSmsServiceGetSizeForTextMessageData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_gsm_sms_service_real_get_size_for_text_message);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_gsm_sms_service_real_get_size_for_text_message_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = contents;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->contents = _tmp2_;
	fso_gsm_gsm_sms_service_real_get_size_for_text_message_co (_data_);
}


static guint fso_gsm_gsm_sms_service_real_get_size_for_text_message_finish (FreeSmartphoneGSMSMS* base, GAsyncResult* _res_, GError** error) {
	guint result;
	FsoGsmGsmSmsServiceGetSizeForTextMessageData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return 0U;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static void fso_gsm_gsm_sms_service_get_size_for_text_message_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FsoGsmGsmSmsServiceGetSizeForTextMessageData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	fso_gsm_gsm_sms_service_real_get_size_for_text_message_co (_data_);
}


static gboolean fso_gsm_gsm_sms_service_real_get_size_for_text_message_co (FsoGsmGsmSmsServiceGetSizeForTextMessageData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	fso_gsm_service_checkAvailability ((FsoGsmService*) _data_->self, FSO_GSM_MODEM_STATUS_ALIVE_NO_SIM, &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp0_ = ((FsoGsmService*) _data_->self)->modem;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = fso_gsm_modem_createMediator (_data_->_tmp0_, FSO_GSM_TYPE_SMS_GET_SIZE_FOR_TEXT_MESSAGE, (GBoxedCopyFunc) g_object_ref, g_object_unref, &_data_->_inner_error_);
	_data_->m = (FsoGsmSmsGetSizeForTextMessage*) _data_->_tmp1_;
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp2_ = _data_->m;
	_data_->_tmp3_ = _data_->contents;
	_data_->_state_ = 1;
	fso_gsm_sms_get_size_for_text_message_run (_data_->_tmp2_, _data_->_tmp3_, fso_gsm_gsm_sms_service_get_size_for_text_message_ready, _data_);
	return FALSE;
	_state_1:
	fso_gsm_sms_get_size_for_text_message_run_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->m);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->m);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp4_ = _data_->m;
	_data_->_tmp5_ = fso_gsm_sms_get_size_for_text_message_get_size (_data_->_tmp4_);
	_data_->_tmp6_ = _data_->_tmp5_;
	_data_->result = _data_->_tmp6_;
	_g_object_unref0 (_data_->m);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	_g_object_unref0 (_data_->m);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void _vala_FreeSmartphoneGSMSIMMessage_array_free (FreeSmartphoneGSMSIMMessage* array, gint array_length) {
	if (array != NULL) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			free_smartphone_gsm_sim_message_destroy (&array[i]);
		}
	}
	g_free (array);
}


static void fso_gsm_gsm_sms_service_real_retrieve_text_messages_data_free (gpointer _data) {
	FsoGsmGsmSmsServiceRetrieveTextMessagesData* _data_;
	_data_ = _data;
	_data_->result = (_vala_FreeSmartphoneGSMSIMMessage_array_free (_data_->result, _data_->result_length1), NULL);
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmGsmSmsServiceRetrieveTextMessagesData, _data_);
}


static void fso_gsm_gsm_sms_service_real_retrieve_text_messages (FreeSmartphoneGSMSMS* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmGsmSmsService * self;
	FsoGsmGsmSmsServiceRetrieveTextMessagesData* _data_;
	FsoGsmGsmSmsService* _tmp0_;
	self = (FsoGsmGsmSmsService*) base;
	_data_ = g_slice_new0 (FsoGsmGsmSmsServiceRetrieveTextMessagesData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_gsm_sms_service_real_retrieve_text_messages);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_gsm_sms_service_real_retrieve_text_messages_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	fso_gsm_gsm_sms_service_real_retrieve_text_messages_co (_data_);
}


static FreeSmartphoneGSMSIMMessage* fso_gsm_gsm_sms_service_real_retrieve_text_messages_finish (FreeSmartphoneGSMSMS* base, GAsyncResult* _res_, int* result_length1, GError** error) {
	FreeSmartphoneGSMSIMMessage* result;
	FsoGsmGsmSmsServiceRetrieveTextMessagesData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	*result_length1 = _data_->result_length1;
	_data_->result = NULL;
	return result;
}


static void fso_gsm_gsm_sms_service_retrieve_text_messages_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FsoGsmGsmSmsServiceRetrieveTextMessagesData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	fso_gsm_gsm_sms_service_real_retrieve_text_messages_co (_data_);
}


static FreeSmartphoneGSMSIMMessage* _vala_array_dup2 (FreeSmartphoneGSMSIMMessage* self, int length) {
	FreeSmartphoneGSMSIMMessage* result;
	int i;
	result = g_new0 (FreeSmartphoneGSMSIMMessage, length);
	for (i = 0; i < length; i++) {
		FreeSmartphoneGSMSIMMessage _tmp0_ = {0};
		free_smartphone_gsm_sim_message_copy (&self[i], &_tmp0_);
		result[i] = _tmp0_;
	}
	return result;
}


static gboolean fso_gsm_gsm_sms_service_real_retrieve_text_messages_co (FsoGsmGsmSmsServiceRetrieveTextMessagesData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	fso_gsm_service_checkAvailability ((FsoGsmService*) _data_->self, FSO_GSM_MODEM_STATUS_ALIVE_SIM_READY, &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp0_ = ((FsoGsmService*) _data_->self)->modem;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = fso_gsm_modem_createMediator (_data_->_tmp0_, FSO_GSM_TYPE_SMS_RETRIEVE_TEXT_MESSAGES, (GBoxedCopyFunc) g_object_ref, g_object_unref, &_data_->_inner_error_);
	_data_->m = (FsoGsmSmsRetrieveTextMessages*) _data_->_tmp1_;
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp2_ = _data_->m;
	_data_->_state_ = 1;
	fso_gsm_sms_retrieve_text_messages_run (_data_->_tmp2_, fso_gsm_gsm_sms_service_retrieve_text_messages_ready, _data_);
	return FALSE;
	_state_1:
	fso_gsm_sms_retrieve_text_messages_run_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->m);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->m);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp3_ = _data_->m;
	_data_->_tmp4_ = fso_gsm_sms_retrieve_text_messages_get_messagebook (_data_->_tmp3_, &_data_->_tmp4__length1);
	_data_->_tmp5_ = _data_->_tmp4_;
	_data_->_tmp5__length1 = _data_->_tmp4__length1;
	_data_->_tmp6_ = (_data_->_tmp5_ != NULL) ? _vala_array_dup2 (_data_->_tmp5_, _data_->_tmp5__length1) : ((gpointer) _data_->_tmp5_);
	_data_->_tmp6__length1 = _data_->_tmp5__length1;
	_data_->_tmp7_ = _data_->_tmp6_;
	_data_->_tmp7__length1 = _data_->_tmp6__length1;
	_data_->result_length1 = _data_->_tmp7__length1;
	_data_->result = _data_->_tmp7_;
	_g_object_unref0 (_data_->m);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	_g_object_unref0 (_data_->m);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void fso_gsm_gsm_sms_service_real_send_text_message_data_free (gpointer _data) {
	FsoGsmGsmSmsServiceSendTextMessageData* _data_;
	_data_ = _data;
	_g_free0 (_data_->recipient_number);
	_g_free0 (_data_->contents);
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmGsmSmsServiceSendTextMessageData, _data_);
}


static void fso_gsm_gsm_sms_service_real_send_text_message (FreeSmartphoneGSMSMS* base, const gchar* recipient_number, const gchar* contents, gboolean want_report, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmGsmSmsService * self;
	FsoGsmGsmSmsServiceSendTextMessageData* _data_;
	FsoGsmGsmSmsService* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	gboolean _tmp5_;
	self = (FsoGsmGsmSmsService*) base;
	_data_ = g_slice_new0 (FsoGsmGsmSmsServiceSendTextMessageData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_gsm_sms_service_real_send_text_message);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_gsm_sms_service_real_send_text_message_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = recipient_number;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->recipient_number = _tmp2_;
	_tmp3_ = contents;
	_tmp4_ = g_strdup (_tmp3_);
	_data_->contents = _tmp4_;
	_tmp5_ = want_report;
	_data_->want_report = _tmp5_;
	fso_gsm_gsm_sms_service_real_send_text_message_co (_data_);
}


static void fso_gsm_gsm_sms_service_real_send_text_message_finish (FreeSmartphoneGSMSMS* base, GAsyncResult* _res_, gint* transaction_index, gchar** timestamp, GError** error) {
	FsoGsmGsmSmsServiceSendTextMessageData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	if (transaction_index) {
		*transaction_index = _data_->transaction_index;
	}
	if (timestamp) {
		*timestamp = _data_->timestamp;
	} else {
		_g_free0 (_data_->timestamp);
	}
	_data_->timestamp = NULL;
}


static void fso_gsm_gsm_sms_service_send_text_message_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FsoGsmGsmSmsServiceSendTextMessageData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	fso_gsm_gsm_sms_service_real_send_text_message_co (_data_);
}


static gboolean fso_gsm_gsm_sms_service_real_send_text_message_co (FsoGsmGsmSmsServiceSendTextMessageData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	fso_gsm_service_checkAvailability ((FsoGsmService*) _data_->self, FSO_GSM_MODEM_STATUS_ALIVE_REGISTERED, &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp0_ = ((FsoGsmService*) _data_->self)->modem;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = fso_gsm_modem_createMediator (_data_->_tmp0_, FSO_GSM_TYPE_SMS_SEND_TEXT_MESSAGE, (GBoxedCopyFunc) g_object_ref, g_object_unref, &_data_->_inner_error_);
	_data_->m = (FsoGsmSmsSendTextMessage*) _data_->_tmp1_;
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp2_ = _data_->m;
	_data_->_tmp3_ = _data_->recipient_number;
	_data_->_tmp4_ = _data_->contents;
	_data_->_tmp5_ = _data_->want_report;
	_data_->_state_ = 1;
	fso_gsm_sms_send_text_message_run (_data_->_tmp2_, _data_->_tmp3_, _data_->_tmp4_, _data_->_tmp5_, fso_gsm_gsm_sms_service_send_text_message_ready, _data_);
	return FALSE;
	_state_1:
	fso_gsm_sms_send_text_message_run_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		if ((((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->m);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->m);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp6_ = _data_->m;
	_data_->_tmp7_ = fso_gsm_sms_send_text_message_get_transaction_index (_data_->_tmp6_);
	_data_->_tmp8_ = _data_->_tmp7_;
	_data_->transaction_index = _data_->_tmp8_;
	_data_->_tmp9_ = _data_->m;
	_data_->_tmp10_ = fso_gsm_sms_send_text_message_get_timestamp (_data_->_tmp9_);
	_data_->_tmp11_ = _data_->_tmp10_;
	_data_->_tmp12_ = g_strdup (_data_->_tmp11_);
	_g_free0 (_data_->timestamp);
	_data_->timestamp = _data_->_tmp12_;
	_g_object_unref0 (_data_->m);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


FsoGsmGsmSmsService* fso_gsm_gsm_sms_service_construct (GType object_type) {
	FsoGsmGsmSmsService * self = NULL;
	self = (FsoGsmGsmSmsService*) fso_gsm_service_construct (object_type);
	return self;
}


FsoGsmGsmSmsService* fso_gsm_gsm_sms_service_new (void) {
	return fso_gsm_gsm_sms_service_construct (FSO_GSM_TYPE_GSM_SMS_SERVICE);
}


static void fso_gsm_gsm_sms_service_class_init (FsoGsmGsmSmsServiceClass * klass) {
	fso_gsm_gsm_sms_service_parent_class = g_type_class_peek_parent (klass);
}


static void fso_gsm_gsm_sms_service_free_smartphone_gsm_sms_interface_init (FreeSmartphoneGSMSMSIface * iface) {
	fso_gsm_gsm_sms_service_free_smartphone_gsm_sms_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_size_for_text_message = (guint (*)(FreeSmartphoneGSMSMS*, const gchar*, GError**)) fso_gsm_gsm_sms_service_real_get_size_for_text_message;
	iface->get_size_for_text_message_finish = fso_gsm_gsm_sms_service_real_get_size_for_text_message_finish;
	iface->retrieve_text_messages = (FreeSmartphoneGSMSIMMessage* (*)(FreeSmartphoneGSMSMS*, int*, GError**)) fso_gsm_gsm_sms_service_real_retrieve_text_messages;
	iface->retrieve_text_messages_finish = fso_gsm_gsm_sms_service_real_retrieve_text_messages_finish;
	iface->send_text_message = (void (*)(FreeSmartphoneGSMSMS*, const gchar*, const gchar*, gboolean, gint*, gchar**, GError**)) fso_gsm_gsm_sms_service_real_send_text_message;
	iface->send_text_message_finish = fso_gsm_gsm_sms_service_real_send_text_message_finish;
}


static void fso_gsm_gsm_sms_service_instance_init (FsoGsmGsmSmsService * self) {
}


GType fso_gsm_gsm_sms_service_get_type (void) {
	return fso_gsm_gsm_sms_service_type_id;
}


GType fso_gsm_gsm_sms_service_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (FsoGsmGsmSmsServiceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_gsm_gsm_sms_service_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoGsmGsmSmsService), 0, (GInstanceInitFunc) fso_gsm_gsm_sms_service_instance_init, NULL };
	static const GInterfaceInfo free_smartphone_gsm_sms_info = { (GInterfaceInitFunc) fso_gsm_gsm_sms_service_free_smartphone_gsm_sms_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	fso_gsm_gsm_sms_service_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_SERVICE, "FsoGsmGsmSmsService", &g_define_type_info, 0);
	g_type_module_add_interface (module, fso_gsm_gsm_sms_service_type_id, FREE_SMARTPHONE_GSM_TYPE_SMS, &free_smartphone_gsm_sms_info);
	return fso_gsm_gsm_sms_service_type_id;
}




/* isismsmediators.c generated by valac 0.16.1, the Vala compiler
 * generated from isismsmediators.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Klaus 'mrmoku' Kurzmann <mok@fluxnetz.de>
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
#include <gee.h>


#define NOKIA_ISI_TYPE_ISI_SMS_SEND_TEXT_MESSAGE (nokia_isi_isi_sms_send_text_message_get_type ())
#define NOKIA_ISI_ISI_SMS_SEND_TEXT_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_ISI_SMS_SEND_TEXT_MESSAGE, NokiaIsiIsiSmsSendTextMessage))
#define NOKIA_ISI_ISI_SMS_SEND_TEXT_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_ISI_SMS_SEND_TEXT_MESSAGE, NokiaIsiIsiSmsSendTextMessageClass))
#define NOKIA_ISI_IS_ISI_SMS_SEND_TEXT_MESSAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_ISI_SMS_SEND_TEXT_MESSAGE))
#define NOKIA_ISI_IS_ISI_SMS_SEND_TEXT_MESSAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_ISI_SMS_SEND_TEXT_MESSAGE))
#define NOKIA_ISI_ISI_SMS_SEND_TEXT_MESSAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_ISI_SMS_SEND_TEXT_MESSAGE, NokiaIsiIsiSmsSendTextMessageClass))

typedef struct _NokiaIsiIsiSmsSendTextMessage NokiaIsiIsiSmsSendTextMessage;
typedef struct _NokiaIsiIsiSmsSendTextMessageClass NokiaIsiIsiSmsSendTextMessageClass;
typedef struct _NokiaIsiIsiSmsSendTextMessagePrivate NokiaIsiIsiSmsSendTextMessagePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _NokiaIsiIsiSmsSendTextMessageRunData NokiaIsiIsiSmsSendTextMessageRunData;

struct _NokiaIsiIsiSmsSendTextMessage {
	FsoGsmSmsSendTextMessage parent_instance;
	NokiaIsiIsiSmsSendTextMessagePrivate * priv;
};

struct _NokiaIsiIsiSmsSendTextMessageClass {
	FsoGsmSmsSendTextMessageClass parent_class;
};

struct _NokiaIsiIsiSmsSendTextMessageRunData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	NokiaIsiIsiSmsSendTextMessage* self;
	gchar* recipient_number;
	gchar* contents;
	gboolean want_report;
	const gchar* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoGsmModem* _tmp2_;
	FsoGsmSmsHandler* _tmp3_;
	FsoGsmSmsHandler* _tmp4_;
	const gchar* _tmp5_;
	const gchar* _tmp6_;
	gboolean _tmp7_;
	GeeArrayList* _tmp8_;
	GeeArrayList* hexpdus;
	FsoGsmModem* _tmp9_;
	FsoGsmModem* _tmp10_;
	FsoGsmSmsHandler* _tmp11_;
	FsoGsmSmsHandler* _tmp12_;
	guint16 _tmp13_;
	gboolean _tmp14_;
	FsoGsmModem* _tmp15_;
	FsoGsmModem* _tmp16_;
	FsoGsmSmsHandler* _tmp17_;
	FsoGsmSmsHandler* _tmp18_;
	GeeArrayList* _tmp19_;
	GError * _inner_error_;
};


static gpointer nokia_isi_isi_sms_send_text_message_parent_class = NULL;
static GType nokia_isi_isi_sms_send_text_message_type_id = 0;

GType nokia_isi_isi_sms_send_text_message_get_type (void) G_GNUC_CONST;
GType nokia_isi_isi_sms_send_text_message_register_type (GTypeModule * module);
enum  {
	NOKIA_ISI_ISI_SMS_SEND_TEXT_MESSAGE_DUMMY_PROPERTY
};
static void nokia_isi_isi_sms_send_text_message_real_run_data_free (gpointer _data);
static void nokia_isi_isi_sms_send_text_message_real_run (FsoGsmSmsSendTextMessage* base, const gchar* recipient_number, const gchar* contents, gboolean want_report, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean nokia_isi_isi_sms_send_text_message_real_run_co (NokiaIsiIsiSmsSendTextMessageRunData* _data_);
NokiaIsiIsiSmsSendTextMessage* nokia_isi_isi_sms_send_text_message_new (void);
NokiaIsiIsiSmsSendTextMessage* nokia_isi_isi_sms_send_text_message_construct (GType object_type);


static void nokia_isi_isi_sms_send_text_message_real_run_data_free (gpointer _data) {
	NokiaIsiIsiSmsSendTextMessageRunData* _data_;
	_data_ = _data;
	_g_free0 (_data_->recipient_number);
	_g_free0 (_data_->contents);
	_g_object_unref0 (_data_->self);
	g_slice_free (NokiaIsiIsiSmsSendTextMessageRunData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void nokia_isi_isi_sms_send_text_message_real_run (FsoGsmSmsSendTextMessage* base, const gchar* recipient_number, const gchar* contents, gboolean want_report, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	NokiaIsiIsiSmsSendTextMessage * self;
	NokiaIsiIsiSmsSendTextMessageRunData* _data_;
	NokiaIsiIsiSmsSendTextMessage* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	gboolean _tmp5_;
	self = (NokiaIsiIsiSmsSendTextMessage*) base;
	_data_ = g_slice_new0 (NokiaIsiIsiSmsSendTextMessageRunData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, nokia_isi_isi_sms_send_text_message_real_run);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, nokia_isi_isi_sms_send_text_message_real_run_data_free);
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
	nokia_isi_isi_sms_send_text_message_real_run_co (_data_);
}


static void nokia_isi_isi_sms_send_text_message_real_run_finish (FsoGsmSmsSendTextMessage* base, GAsyncResult* _res_, GError** error) {
	NokiaIsiIsiSmsSendTextMessageRunData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean nokia_isi_isi_sms_send_text_message_real_run_co (NokiaIsiIsiSmsSendTextMessageRunData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->recipient_number;
	fso_gsm_validatePhoneNumber (_data_->_tmp0_, &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
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
	_data_->_tmp1_ = fso_gsm_abstract_mediator_get_modem ((FsoGsmAbstractMediator*) _data_->self);
	_data_->_tmp2_ = _data_->_tmp1_;
	_data_->_tmp3_ = fso_gsm_modem_get_smshandler (_data_->_tmp2_);
	_data_->_tmp4_ = _data_->_tmp3_;
	_data_->_tmp5_ = _data_->recipient_number;
	_data_->_tmp6_ = _data_->contents;
	_data_->_tmp7_ = _data_->want_report;
	_data_->_tmp8_ = NULL;
	_data_->_tmp8_ = fso_gsm_sms_handler_formatTextMessage (_data_->_tmp4_, _data_->_tmp5_, _data_->_tmp6_, _data_->_tmp7_);
	_data_->hexpdus = _data_->_tmp8_;
	_data_->_tmp9_ = fso_gsm_abstract_mediator_get_modem ((FsoGsmAbstractMediator*) _data_->self);
	_data_->_tmp10_ = _data_->_tmp9_;
	_data_->_tmp11_ = fso_gsm_modem_get_smshandler (_data_->_tmp10_);
	_data_->_tmp12_ = _data_->_tmp11_;
	_data_->_tmp13_ = 0U;
	_data_->_tmp13_ = fso_gsm_sms_handler_lastReferenceNumber (_data_->_tmp12_);
	fso_gsm_sms_send_text_message_set_transaction_index ((FsoGsmSmsSendTextMessage*) _data_->self, (gint) _data_->_tmp13_);
	fso_gsm_sms_send_text_message_set_timestamp ((FsoGsmSmsSendTextMessage*) _data_->self, "now");
	_data_->_tmp14_ = _data_->want_report;
	if (_data_->_tmp14_) {
		_data_->_tmp15_ = fso_gsm_abstract_mediator_get_modem ((FsoGsmAbstractMediator*) _data_->self);
		_data_->_tmp16_ = _data_->_tmp15_;
		_data_->_tmp17_ = fso_gsm_modem_get_smshandler (_data_->_tmp16_);
		_data_->_tmp18_ = _data_->_tmp17_;
		_data_->_tmp19_ = _data_->hexpdus;
		fso_gsm_sms_handler_storeTransactionIndizesForSentMessage (_data_->_tmp18_, _data_->_tmp19_);
	}
	_g_object_unref0 (_data_->hexpdus);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


NokiaIsiIsiSmsSendTextMessage* nokia_isi_isi_sms_send_text_message_construct (GType object_type) {
	NokiaIsiIsiSmsSendTextMessage * self = NULL;
	self = (NokiaIsiIsiSmsSendTextMessage*) fso_gsm_sms_send_text_message_construct (object_type);
	return self;
}


NokiaIsiIsiSmsSendTextMessage* nokia_isi_isi_sms_send_text_message_new (void) {
	return nokia_isi_isi_sms_send_text_message_construct (NOKIA_ISI_TYPE_ISI_SMS_SEND_TEXT_MESSAGE);
}


static void nokia_isi_isi_sms_send_text_message_class_init (NokiaIsiIsiSmsSendTextMessageClass * klass) {
	nokia_isi_isi_sms_send_text_message_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_SMS_SEND_TEXT_MESSAGE_CLASS (klass)->run = nokia_isi_isi_sms_send_text_message_real_run;
	FSO_GSM_SMS_SEND_TEXT_MESSAGE_CLASS (klass)->run_finish = nokia_isi_isi_sms_send_text_message_real_run_finish;
}


static void nokia_isi_isi_sms_send_text_message_instance_init (NokiaIsiIsiSmsSendTextMessage * self) {
}


GType nokia_isi_isi_sms_send_text_message_get_type (void) {
	return nokia_isi_isi_sms_send_text_message_type_id;
}


GType nokia_isi_isi_sms_send_text_message_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (NokiaIsiIsiSmsSendTextMessageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) nokia_isi_isi_sms_send_text_message_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NokiaIsiIsiSmsSendTextMessage), 0, (GInstanceInitFunc) nokia_isi_isi_sms_send_text_message_instance_init, NULL };
	nokia_isi_isi_sms_send_text_message_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_SMS_SEND_TEXT_MESSAGE, "NokiaIsiIsiSmsSendTextMessage", &g_define_type_info, 0);
	return nokia_isi_isi_sms_send_text_message_type_id;
}




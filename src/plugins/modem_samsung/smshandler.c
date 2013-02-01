/* smshandler.c generated by valac 0.16.1, the Vala compiler
 * generated from smshandler.vala, do not modify */

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
#include <fsotransport.h>
#include <radio.h>
#include <fsobasics.h>


#define SAMSUNG_TYPE_SMS_HANDLER (samsung_sms_handler_get_type ())
#define SAMSUNG_SMS_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_SMS_HANDLER, SamsungSmsHandler))
#define SAMSUNG_SMS_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_SMS_HANDLER, SamsungSmsHandlerClass))
#define SAMSUNG_IS_SMS_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_SMS_HANDLER))
#define SAMSUNG_IS_SMS_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_SMS_HANDLER))
#define SAMSUNG_SMS_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_SMS_HANDLER, SamsungSmsHandlerClass))

typedef struct _SamsungSmsHandler SamsungSmsHandler;
typedef struct _SamsungSmsHandlerClass SamsungSmsHandlerClass;
typedef struct _SamsungSmsHandlerPrivate SamsungSmsHandlerPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SAMSUNG_TYPE_IPC_CHANNEL (samsung_ipc_channel_get_type ())
#define SAMSUNG_IPC_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannel))
#define SAMSUNG_IPC_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannelClass))
#define SAMSUNG_IS_IPC_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_IPC_CHANNEL))
#define SAMSUNG_IS_IPC_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_IPC_CHANNEL))
#define SAMSUNG_IPC_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannelClass))

typedef struct _SamsungIpcChannel SamsungIpcChannel;
typedef struct _SamsungIpcChannelClass SamsungIpcChannelClass;
typedef struct _samsung_sms_handler_retrieveImsiFromSIMData samsung_sms_handler_retrieveImsiFromSIMData;
typedef struct _samsung_sms_handler_acknowledgeSmsMessageData samsung_sms_handler_acknowledgeSmsMessageData;
typedef struct _samsung_sms_handler_readSmsMessageFromSIMData samsung_sms_handler_readSmsMessageFromSIMData;
typedef struct _samsung_sms_handler_fillStorageWithMessageFromSIMData samsung_sms_handler_fillStorageWithMessageFromSIMData;

struct _SamsungSmsHandler {
	FsoGsmAbstractSmsHandler parent_instance;
	SamsungSmsHandlerPrivate * priv;
};

struct _SamsungSmsHandlerClass {
	FsoGsmAbstractSmsHandlerClass parent_class;
};

struct _samsung_sms_handler_retrieveImsiFromSIMData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSmsHandler* self;
	gchar* result;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoGsmChannel* _tmp2_;
	SamsungIpcChannel* channel;
	struct ipc_message_info* response;
	struct ipc_sec_rsim_access_request rsimreq;
	gint _tmp3_;
	SamsungIpcChannel* _tmp4_;
	struct ipc_sec_rsim_access_request _tmp5_;
	guint8* _tmp6_;
	gint _tmp6__length1;
	guint8* _tmp7_;
	gint _tmp7__length1;
	struct ipc_message_info* _tmp8_;
	gchar* _tmp9_;
	struct ipc_message_info* _tmp10_;
	struct ipc_message_info* _tmp11_;
	struct ipc_message_info _tmp12_;
	gchar* _tmp13_;
	gchar* _tmp14_;
};

struct _samsung_sms_handler_acknowledgeSmsMessageData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSmsHandler* self;
	gboolean result;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoGsmChannel* _tmp2_;
	SamsungIpcChannel* channel;
	struct ipc_message_info* response;
	struct ipc_sms_deliv_report_msg ackmsg;
	SamsungIpcChannel* _tmp3_;
	struct ipc_sms_deliv_report_msg _tmp4_;
	guint8* _tmp5_;
	gint _tmp5__length1;
	guint8* _tmp6_;
	gint _tmp6__length1;
	struct ipc_message_info* _tmp7_;
	struct ipc_message_info* _tmp8_;
	FsoFrameworkLogger* _tmp9_;
};

struct _samsung_sms_handler_readSmsMessageFromSIMData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSmsHandler* self;
	guint index;
	gchar* hexpdu;
	gint tpdulen;
	gboolean result;
	gchar* _tmp0_;
};

struct _samsung_sms_handler_fillStorageWithMessageFromSIMData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSmsHandler* self;
};


static gpointer samsung_sms_handler_parent_class = NULL;
static GType samsung_sms_handler_type_id = 0;

GType samsung_sms_handler_get_type (void) G_GNUC_CONST;
GType samsung_sms_handler_register_type (GTypeModule * module);
enum  {
	SAMSUNG_SMS_HANDLER_DUMMY_PROPERTY
};
static void samsung_sms_handler_real_retrieveImsiFromSIM_data_free (gpointer _data);
static void samsung_sms_handler_real_retrieveImsiFromSIM (FsoGsmAbstractSmsHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean samsung_sms_handler_real_retrieveImsiFromSIM_co (samsung_sms_handler_retrieveImsiFromSIMData* _data_);
GType samsung_ipc_channel_get_type (void) G_GNUC_CONST;
GType samsung_ipc_channel_register_type (GTypeModule * module);
void samsung_ipc_channel_enqueue_async (SamsungIpcChannel* self, int type, unsigned short command, guint8* data, int data_length1, gint retry, gint timeout, GAsyncReadyCallback _callback_, gpointer _user_data_);
struct ipc_message_info* samsung_ipc_channel_enqueue_finish (SamsungIpcChannel* self, GAsyncResult* _res_);
static void samsung_sms_handler_retrieveImsiFromSIM_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void samsung_sms_handler_real_acknowledgeSmsMessage_data_free (gpointer _data);
static void samsung_sms_handler_real_acknowledgeSmsMessage (FsoGsmAbstractSmsHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean samsung_sms_handler_real_acknowledgeSmsMessage_co (samsung_sms_handler_acknowledgeSmsMessageData* _data_);
static void samsung_sms_handler_acknowledgeSmsMessage_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void samsung_sms_handler_real_readSmsMessageFromSIM_data_free (gpointer _data);
static void samsung_sms_handler_real_readSmsMessageFromSIM (FsoGsmAbstractSmsHandler* base, guint index, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean samsung_sms_handler_real_readSmsMessageFromSIM_co (samsung_sms_handler_readSmsMessageFromSIMData* _data_);
static void samsung_sms_handler_real_fillStorageWithMessageFromSIM_data_free (gpointer _data);
static void samsung_sms_handler_real_fillStorageWithMessageFromSIM (FsoGsmAbstractSmsHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean samsung_sms_handler_real_fillStorageWithMessageFromSIM_co (samsung_sms_handler_fillStorageWithMessageFromSIMData* _data_);
SamsungSmsHandler* samsung_sms_handler_new (FsoGsmModem* modem);
SamsungSmsHandler* samsung_sms_handler_construct (GType object_type, FsoGsmModem* modem);
static gchar* samsung_sms_handler_real_repr (FsoFrameworkAbstractObject* base);


static void samsung_sms_handler_real_retrieveImsiFromSIM_data_free (gpointer _data) {
	samsung_sms_handler_retrieveImsiFromSIMData* _data_;
	_data_ = _data;
	_g_free0 (_data_->result);
	_g_object_unref0 (_data_->self);
	g_slice_free (samsung_sms_handler_retrieveImsiFromSIMData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void samsung_sms_handler_real_retrieveImsiFromSIM (FsoGsmAbstractSmsHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSmsHandler * self;
	samsung_sms_handler_retrieveImsiFromSIMData* _data_;
	SamsungSmsHandler* _tmp0_;
	self = (SamsungSmsHandler*) base;
	_data_ = g_slice_new0 (samsung_sms_handler_retrieveImsiFromSIMData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sms_handler_real_retrieveImsiFromSIM);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sms_handler_real_retrieveImsiFromSIM_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	samsung_sms_handler_real_retrieveImsiFromSIM_co (_data_);
}


static gchar* samsung_sms_handler_real_retrieveImsiFromSIM_finish (FsoGsmAbstractSmsHandler* base, GAsyncResult* _res_) {
	gchar* result;
	samsung_sms_handler_retrieveImsiFromSIMData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
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


static void samsung_sms_handler_retrieveImsiFromSIM_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	samsung_sms_handler_retrieveImsiFromSIMData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_sms_handler_real_retrieveImsiFromSIM_co (_data_);
}


static gboolean samsung_sms_handler_real_retrieveImsiFromSIM_co (samsung_sms_handler_retrieveImsiFromSIMData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_abstract_sms_handler_get_modem ((FsoGsmAbstractSmsHandler*) _data_->self);
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = fso_gsm_modem_channel (_data_->_tmp1_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp2_) ? ((SamsungIpcChannel*) _data_->_tmp2_) : NULL;
	_data_->response = NULL;
	memset (&_data_->rsimreq, 0, sizeof (struct ipc_sec_rsim_access_request));
	_data_->rsimreq.command = IPC_SEC_RSIM_COMMAND_READ_BINARY;
	_data_->_tmp3_ = 0;
	_data_->_tmp3_ = fso_gsm_constants_simFilesystemEntryNameToCode ("EFimsi");
	_data_->rsimreq.fileid = (guint16) _data_->_tmp3_;
	_data_->_tmp4_ = _data_->channel;
	_data_->_tmp5_ = _data_->rsimreq;
	_data_->_tmp6_ = samsung_ipc_security_rsim_access_request_message_get_data (&_data_->_tmp5_, &_data_->_tmp6__length1);
	_data_->_tmp7_ = _data_->_tmp6_;
	_data_->_tmp7__length1 = _data_->_tmp6__length1;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->_tmp4_, IPC_TYPE_GET, IPC_SEC_RSIM_ACCESS, _data_->_tmp7_, _data_->_tmp7__length1, 0, 5, samsung_sms_handler_retrieveImsiFromSIM_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp8_ = NULL;
	_data_->_tmp8_ = samsung_ipc_channel_enqueue_finish (_data_->_tmp4_, _data_->_res_);
	_data_->response = _data_->_tmp8_;
	_data_->_tmp10_ = _data_->response;
	if (_data_->_tmp10_ != NULL) {
		_data_->_tmp11_ = _data_->response;
		_data_->_tmp12_ = *_data_->_tmp11_;
		_data_->_tmp13_ = NULL;
		_data_->_tmp13_ = ipc_sec_rsim_access_response_get_file_data (&_data_->_tmp12_);
		_g_free0 (_data_->_tmp9_);
		_data_->_tmp9_ = _data_->_tmp13_;
	} else {
		_data_->_tmp14_ = g_strdup ("unknown");
		_g_free0 (_data_->_tmp9_);
		_data_->_tmp9_ = _data_->_tmp14_;
	}
	_data_->result = _data_->_tmp9_;
	 (&_data_->rsimreq);
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	_g_free0 (_data_->_tmp9_);
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


static void samsung_sms_handler_real_acknowledgeSmsMessage_data_free (gpointer _data) {
	samsung_sms_handler_acknowledgeSmsMessageData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (samsung_sms_handler_acknowledgeSmsMessageData, _data_);
}


static void samsung_sms_handler_real_acknowledgeSmsMessage (FsoGsmAbstractSmsHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSmsHandler * self;
	samsung_sms_handler_acknowledgeSmsMessageData* _data_;
	SamsungSmsHandler* _tmp0_;
	self = (SamsungSmsHandler*) base;
	_data_ = g_slice_new0 (samsung_sms_handler_acknowledgeSmsMessageData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sms_handler_real_acknowledgeSmsMessage);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sms_handler_real_acknowledgeSmsMessage_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	samsung_sms_handler_real_acknowledgeSmsMessage_co (_data_);
}


static gboolean samsung_sms_handler_real_acknowledgeSmsMessage_finish (FsoGsmAbstractSmsHandler* base, GAsyncResult* _res_) {
	gboolean result;
	samsung_sms_handler_acknowledgeSmsMessageData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static guint8* samsung_ipc_sms_deliver_report_message_get_data (struct ipc_sms_deliv_report_msg* self, int* result_length1) {
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
	res_length1 = (gint) sizeof (struct ipc_sms_deliv_report_msg);
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


static void samsung_sms_handler_acknowledgeSmsMessage_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	samsung_sms_handler_acknowledgeSmsMessageData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_sms_handler_real_acknowledgeSmsMessage_co (_data_);
}


static gboolean samsung_sms_handler_real_acknowledgeSmsMessage_co (samsung_sms_handler_acknowledgeSmsMessageData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_abstract_sms_handler_get_modem ((FsoGsmAbstractSmsHandler*) _data_->self);
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = fso_gsm_modem_channel (_data_->_tmp1_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp2_) ? ((SamsungIpcChannel*) _data_->_tmp2_) : NULL;
	_data_->response = NULL;
	memset (&_data_->ackmsg, 0, sizeof (struct ipc_sms_deliv_report_msg));
	_data_->ackmsg.type = IPC_SMS_TYPE_STATUS_REPORT;
	_data_->ackmsg.error = IPC_SMS_ACK_NO_ERROR;
	_data_->ackmsg.msg_tpid = (guint8) 0;
	_data_->_tmp3_ = _data_->channel;
	_data_->_tmp4_ = _data_->ackmsg;
	_data_->_tmp5_ = samsung_ipc_sms_deliver_report_message_get_data (&_data_->_tmp4_, &_data_->_tmp5__length1);
	_data_->_tmp6_ = _data_->_tmp5_;
	_data_->_tmp6__length1 = _data_->_tmp5__length1;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->_tmp3_, IPC_TYPE_EXEC, IPC_SMS_DELIVER_REPORT, _data_->_tmp6_, _data_->_tmp6__length1, 0, 5, samsung_sms_handler_acknowledgeSmsMessage_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp7_ = NULL;
	_data_->_tmp7_ = samsung_ipc_channel_enqueue_finish (_data_->_tmp3_, _data_->_res_);
	_data_->response = _data_->_tmp7_;
	_data_->_tmp8_ = _data_->response;
	if (_data_->_tmp8_ == NULL) {
		_data_->_tmp9_ = ((FsoFrameworkAbstractObject*) _data_->self)->logger;
		fso_framework_logger_error (_data_->_tmp9_, "Failed to acknowledge incoming SMS message!");
		_data_->result = FALSE;
		_g_object_unref0 (_data_->channel);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->result = TRUE;
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void samsung_sms_handler_real_readSmsMessageFromSIM_data_free (gpointer _data) {
	samsung_sms_handler_readSmsMessageFromSIMData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (samsung_sms_handler_readSmsMessageFromSIMData, _data_);
}


static void samsung_sms_handler_real_readSmsMessageFromSIM (FsoGsmAbstractSmsHandler* base, guint index, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSmsHandler * self;
	samsung_sms_handler_readSmsMessageFromSIMData* _data_;
	SamsungSmsHandler* _tmp0_;
	guint _tmp1_;
	self = (SamsungSmsHandler*) base;
	_data_ = g_slice_new0 (samsung_sms_handler_readSmsMessageFromSIMData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sms_handler_real_readSmsMessageFromSIM);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sms_handler_real_readSmsMessageFromSIM_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = index;
	_data_->index = _tmp1_;
	samsung_sms_handler_real_readSmsMessageFromSIM_co (_data_);
}


static gboolean samsung_sms_handler_real_readSmsMessageFromSIM_finish (FsoGsmAbstractSmsHandler* base, GAsyncResult* _res_, gchar** hexpdu, gint* tpdulen) {
	gboolean result;
	samsung_sms_handler_readSmsMessageFromSIMData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	if (hexpdu) {
		*hexpdu = _data_->hexpdu;
	} else {
		_g_free0 (_data_->hexpdu);
	}
	_data_->hexpdu = NULL;
	if (tpdulen) {
		*tpdulen = _data_->tpdulen;
	}
	result = _data_->result;
	return result;
}


static gboolean samsung_sms_handler_real_readSmsMessageFromSIM_co (samsung_sms_handler_readSmsMessageFromSIMData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = g_strdup ("");
	_g_free0 (_data_->hexpdu);
	_data_->hexpdu = _data_->_tmp0_;
	_data_->tpdulen = 0;
	_data_->result = TRUE;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void samsung_sms_handler_real_fillStorageWithMessageFromSIM_data_free (gpointer _data) {
	samsung_sms_handler_fillStorageWithMessageFromSIMData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (samsung_sms_handler_fillStorageWithMessageFromSIMData, _data_);
}


static void samsung_sms_handler_real_fillStorageWithMessageFromSIM (FsoGsmAbstractSmsHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSmsHandler * self;
	samsung_sms_handler_fillStorageWithMessageFromSIMData* _data_;
	SamsungSmsHandler* _tmp0_;
	self = (SamsungSmsHandler*) base;
	_data_ = g_slice_new0 (samsung_sms_handler_fillStorageWithMessageFromSIMData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sms_handler_real_fillStorageWithMessageFromSIM);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sms_handler_real_fillStorageWithMessageFromSIM_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	samsung_sms_handler_real_fillStorageWithMessageFromSIM_co (_data_);
}


static void samsung_sms_handler_real_fillStorageWithMessageFromSIM_finish (FsoGsmAbstractSmsHandler* base, GAsyncResult* _res_) {
	samsung_sms_handler_fillStorageWithMessageFromSIMData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean samsung_sms_handler_real_fillStorageWithMessageFromSIM_co (samsung_sms_handler_fillStorageWithMessageFromSIMData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


SamsungSmsHandler* samsung_sms_handler_construct (GType object_type, FsoGsmModem* modem) {
	SamsungSmsHandler * self = NULL;
	FsoGsmModem* _tmp0_;
	g_return_val_if_fail (modem != NULL, NULL);
	_tmp0_ = modem;
	self = (SamsungSmsHandler*) fso_gsm_abstract_sms_handler_construct (object_type, _tmp0_);
	return self;
}


SamsungSmsHandler* samsung_sms_handler_new (FsoGsmModem* modem) {
	return samsung_sms_handler_construct (SAMSUNG_TYPE_SMS_HANDLER, modem);
}


static gchar* samsung_sms_handler_real_repr (FsoFrameworkAbstractObject* base) {
	SamsungSmsHandler * self;
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	FsoGsmISmsStorage* _tmp1_;
	FsoGsmISmsStorage* _tmp2_;
	self = (SamsungSmsHandler*) base;
	_tmp1_ = fso_gsm_sms_handler_get_storage ((FsoGsmSmsHandler*) self);
	_tmp2_ = _tmp1_;
	if (_tmp2_ != NULL) {
		FsoGsmISmsStorage* _tmp3_;
		FsoGsmISmsStorage* _tmp4_;
		gchar* _tmp5_ = NULL;
		_tmp3_ = fso_gsm_sms_handler_get_storage ((FsoGsmSmsHandler*) self);
		_tmp4_ = _tmp3_;
		_tmp5_ = fso_framework_abstract_object_repr ((FsoFrameworkAbstractObject*) _tmp4_);
		_g_free0 (_tmp0_);
		_tmp0_ = _tmp5_;
	} else {
		gchar* _tmp6_;
		_tmp6_ = g_strdup ("<None>");
		_g_free0 (_tmp0_);
		_tmp0_ = _tmp6_;
	}
	result = _tmp0_;
	return result;
}


static void samsung_sms_handler_class_init (SamsungSmsHandlerClass * klass) {
	samsung_sms_handler_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_ABSTRACT_SMS_HANDLER_CLASS (klass)->retrieveImsiFromSIM = samsung_sms_handler_real_retrieveImsiFromSIM;
	FSO_GSM_ABSTRACT_SMS_HANDLER_CLASS (klass)->retrieveImsiFromSIM_finish = samsung_sms_handler_real_retrieveImsiFromSIM_finish;
	FSO_GSM_ABSTRACT_SMS_HANDLER_CLASS (klass)->acknowledgeSmsMessage = samsung_sms_handler_real_acknowledgeSmsMessage;
	FSO_GSM_ABSTRACT_SMS_HANDLER_CLASS (klass)->acknowledgeSmsMessage_finish = samsung_sms_handler_real_acknowledgeSmsMessage_finish;
	FSO_GSM_ABSTRACT_SMS_HANDLER_CLASS (klass)->readSmsMessageFromSIM = samsung_sms_handler_real_readSmsMessageFromSIM;
	FSO_GSM_ABSTRACT_SMS_HANDLER_CLASS (klass)->readSmsMessageFromSIM_finish = samsung_sms_handler_real_readSmsMessageFromSIM_finish;
	FSO_GSM_ABSTRACT_SMS_HANDLER_CLASS (klass)->fillStorageWithMessageFromSIM = samsung_sms_handler_real_fillStorageWithMessageFromSIM;
	FSO_GSM_ABSTRACT_SMS_HANDLER_CLASS (klass)->fillStorageWithMessageFromSIM_finish = samsung_sms_handler_real_fillStorageWithMessageFromSIM_finish;
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = samsung_sms_handler_real_repr;
}


static void samsung_sms_handler_instance_init (SamsungSmsHandler * self) {
}


/**
 * @class Samsung.SmsHandler
 **/
GType samsung_sms_handler_get_type (void) {
	return samsung_sms_handler_type_id;
}


GType samsung_sms_handler_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SamsungSmsHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) samsung_sms_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SamsungSmsHandler), 0, (GInstanceInitFunc) samsung_sms_handler_instance_init, NULL };
	samsung_sms_handler_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_SMS_HANDLER, "SamsungSmsHandler", &g_define_type_info, 0);
	return samsung_sms_handler_type_id;
}




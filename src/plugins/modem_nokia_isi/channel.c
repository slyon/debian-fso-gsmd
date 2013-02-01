/* channel.c generated by valac 0.16.1, the Vala compiler
 * generated from channel.vala, do not modify */

/*
 * Copyright (C) 2009-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 * Copyright (C) 2010-2012 Denis 'GNUtoo' Carikli <GNUtoo@no-log.org>
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
#include <fsotransport.h>
#include <fsogsm.h>
#include <stdlib.h>
#include <string.h>
#include <fsobasics.h>
#include <gio/gio.h>
#include <gisicomm.h>
#include <freesmartphone.h>


#define TYPE_ISI_CHANNEL (isi_channel_get_type ())
#define ISI_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ISI_CHANNEL, IsiChannel))
#define ISI_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ISI_CHANNEL, IsiChannelClass))
#define IS_ISI_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ISI_CHANNEL))
#define IS_ISI_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ISI_CHANNEL))
#define ISI_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ISI_CHANNEL, IsiChannelClass))

typedef struct _IsiChannel IsiChannel;
typedef struct _IsiChannelClass IsiChannelClass;
typedef struct _IsiChannelPrivate IsiChannelPrivate;

#define NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER (nokia_isi_isi_unsolicited_handler_get_type ())
#define NOKIA_ISI_ISI_UNSOLICITED_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER, NokiaIsiIsiUnsolicitedHandler))
#define NOKIA_ISI_ISI_UNSOLICITED_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER, NokiaIsiIsiUnsolicitedHandlerClass))
#define NOKIA_ISI_IS_ISI_UNSOLICITED_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER))
#define NOKIA_ISI_IS_ISI_UNSOLICITED_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER))
#define NOKIA_ISI_ISI_UNSOLICITED_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_ISI_UNSOLICITED_HANDLER, NokiaIsiIsiUnsolicitedHandlerClass))

typedef struct _NokiaIsiIsiUnsolicitedHandler NokiaIsiIsiUnsolicitedHandler;
typedef struct _NokiaIsiIsiUnsolicitedHandlerClass NokiaIsiIsiUnsolicitedHandlerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _IsiChannelOpenData IsiChannelOpenData;

#define TYPE_ISI_TRANSPORT (isi_transport_get_type ())
#define ISI_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ISI_TRANSPORT, IsiTransport))
#define ISI_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ISI_TRANSPORT, IsiTransportClass))
#define IS_ISI_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ISI_TRANSPORT))
#define IS_ISI_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ISI_TRANSPORT))
#define ISI_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ISI_TRANSPORT, IsiTransportClass))

typedef struct _IsiTransport IsiTransport;
typedef struct _IsiTransportClass IsiTransportClass;
typedef struct _IsiChannelPoweronData IsiChannelPoweronData;

#define NOKIA_ISI_TYPE_ISI_SIM_GET_AUTH_STATUS (nokia_isi_isi_sim_get_auth_status_get_type ())
#define NOKIA_ISI_ISI_SIM_GET_AUTH_STATUS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_ISI_SIM_GET_AUTH_STATUS, NokiaIsiIsiSimGetAuthStatus))
#define NOKIA_ISI_ISI_SIM_GET_AUTH_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_ISI_SIM_GET_AUTH_STATUS, NokiaIsiIsiSimGetAuthStatusClass))
#define NOKIA_ISI_IS_ISI_SIM_GET_AUTH_STATUS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_ISI_SIM_GET_AUTH_STATUS))
#define NOKIA_ISI_IS_ISI_SIM_GET_AUTH_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_ISI_SIM_GET_AUTH_STATUS))
#define NOKIA_ISI_ISI_SIM_GET_AUTH_STATUS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_ISI_SIM_GET_AUTH_STATUS, NokiaIsiIsiSimGetAuthStatusClass))

typedef struct _NokiaIsiIsiSimGetAuthStatus NokiaIsiIsiSimGetAuthStatus;
typedef struct _NokiaIsiIsiSimGetAuthStatusClass NokiaIsiIsiSimGetAuthStatusClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _IsiChannelInitializeData IsiChannelInitializeData;
typedef struct _IsiChannelShutdownData IsiChannelShutdownData;
typedef struct _IsiChannelSuspendData IsiChannelSuspendData;
typedef struct _IsiChannelResumeData IsiChannelResumeData;

struct _IsiChannel {
	FsoFrameworkAbstractCommandQueue parent_instance;
	IsiChannelPrivate * priv;
	gchar* name;
};

struct _IsiChannelClass {
	FsoFrameworkAbstractCommandQueueClass parent_class;
};

struct _IsiChannelPrivate {
	NokiaIsiIsiUnsolicitedHandler* unsolicitedHandler;
	FsoGsmModem* modem;
	gboolean _is_initialized;
};

struct _IsiChannelOpenData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	IsiChannel* self;
	gboolean result;
	FsoFrameworkTransport* _tmp0_;
	FsoFrameworkTransport* _tmp1_;
	gboolean _tmp2_;
};

struct _IsiChannelPoweronData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	IsiChannel* self;
	FsoGsmModem* _tmp0_;
	NokiaIsiIsiUnsolicitedHandler* _tmp1_;
	GIsiCommModemAccess* _tmp2_;
	GIsiCommModemAccess* _tmp3_;
};

struct _IsiChannelInitializeData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	IsiChannel* self;
	NokiaIsiIsiSimGetAuthStatus* _tmp0_;
	NokiaIsiIsiSimGetAuthStatus* getAuthStatus;
	NokiaIsiIsiSimGetAuthStatus* _tmp1_;
	NokiaIsiIsiSimGetAuthStatus* _tmp2_;
	FreeSmartphoneGSMSIMAuthStatus _tmp3_;
	FsoGsmModem* _tmp4_;
	gboolean _tmp5_;
	NokiaIsiIsiSimGetAuthStatus* _tmp6_;
	FreeSmartphoneGSMSIMAuthStatus _tmp7_;
	NokiaIsiIsiSimGetAuthStatus* _tmp8_;
	FreeSmartphoneGSMSIMAuthStatus _tmp9_;
	gboolean _tmp10_;
	FsoGsmModem* _tmp11_;
	GError* e1;
	GError* _tmp12_;
	FsoGsmModem* _tmp13_;
	FsoGsmModem* _tmp14_;
	FsoFrameworkLogger* _tmp15_;
	GError* _tmp16_;
	const gchar* _tmp17_;
	const gchar* _tmp18_;
	gchar* _tmp19_;
	gchar* _tmp20_;
	GError* e2;
	FsoGsmModem* _tmp21_;
	FsoFrameworkLogger* _tmp22_;
	GError* _tmp23_;
	const gchar* _tmp24_;
	const gchar* _tmp25_;
	gchar* _tmp26_;
	gchar* _tmp27_;
	GError * _inner_error_;
};

struct _IsiChannelShutdownData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	IsiChannel* self;
	gboolean _tmp0_;
};

typedef void (*IsiChannelUnsolicitedHandler) (const gchar* prefix, const gchar* response, const gchar* pdu, void* user_data);
struct _IsiChannelSuspendData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	IsiChannel* self;
	gboolean result;
};

struct _IsiChannelResumeData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	IsiChannel* self;
	gboolean result;
};


static gpointer isi_channel_parent_class = NULL;
extern GIsiCommModemAccess* nokia_isi_isimodem;
static FsoGsmChannelIface* isi_channel_fso_gsm_channel_parent_iface = NULL;
static GType isi_channel_type_id = 0;

GType isi_channel_get_type (void) G_GNUC_CONST;
GType isi_channel_register_type (GTypeModule * module);
GType nokia_isi_isi_unsolicited_handler_get_type (void) G_GNUC_CONST;
GType nokia_isi_isi_unsolicited_handler_register_type (GTypeModule * module);
#define ISI_CHANNEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_ISI_CHANNEL, IsiChannelPrivate))
enum  {
	ISI_CHANNEL_DUMMY_PROPERTY
};
static void isi_channel_onModemStatusChanged (IsiChannel* self, FsoGsmModem* modem, FsoGsmModemStatus status);
void isi_channel_initialize (IsiChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void isi_channel_initialize_finish (IsiChannel* self, GAsyncResult* _res_);
void isi_channel_poweron (IsiChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void isi_channel_poweron_finish (IsiChannel* self, GAsyncResult* _res_);
void isi_channel_shutdown (IsiChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void isi_channel_shutdown_finish (IsiChannel* self, GAsyncResult* _res_);
static void isi_channel_real_open_data_free (gpointer _data);
static void isi_channel_real_open (FsoFrameworkAbstractCommandQueue* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean isi_channel_real_open_co (IsiChannelOpenData* _data_);
static void isi_channel_open_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void isi_channel_real_onReadFromTransport (FsoFrameworkAbstractCommandQueue* base, FsoFrameworkTransport* t);
GType isi_transport_get_type (void) G_GNUC_CONST;
GType isi_transport_register_type (GTypeModule * module);
IsiChannel* isi_channel_new (FsoGsmModem* modem, const gchar* name, IsiTransport* transport);
IsiChannel* isi_channel_construct (GType object_type, FsoGsmModem* modem, const gchar* name, IsiTransport* transport);
static void _isi_channel_onModemStatusChanged_fso_gsm_modem_signal_status_changed (FsoGsmModem* _sender, FsoGsmModemStatus status, gpointer self);
static void isi_channel_poweron_data_free (gpointer _data);
static gboolean isi_channel_poweron_co (IsiChannelPoweronData* _data_);
NokiaIsiIsiUnsolicitedHandler* nokia_isi_isi_unsolicited_handler_new (FsoGsmModem* modem);
NokiaIsiIsiUnsolicitedHandler* nokia_isi_isi_unsolicited_handler_construct (GType object_type, FsoGsmModem* modem);
static void isi_channel_poweron_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void isi_channel_initialize_data_free (gpointer _data);
static gboolean isi_channel_initialize_co (IsiChannelInitializeData* _data_);
NokiaIsiIsiSimGetAuthStatus* nokia_isi_isi_sim_get_auth_status_new (void);
NokiaIsiIsiSimGetAuthStatus* nokia_isi_isi_sim_get_auth_status_construct (GType object_type);
GType nokia_isi_isi_sim_get_auth_status_get_type (void) G_GNUC_CONST;
GType nokia_isi_isi_sim_get_auth_status_register_type (GTypeModule * module);
static void isi_channel_initialize_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void isi_channel_shutdown_data_free (gpointer _data);
static gboolean isi_channel_shutdown_co (IsiChannelShutdownData* _data_);
void isi_channel_registerUnsolicitedHandler (IsiChannel* self, IsiChannelUnsolicitedHandler urchandler, void* urchandler_target);
static void isi_channel_real_injectResponse (FsoGsmChannel* base, const gchar* response);
static void isi_channel_real_suspend_data_free (gpointer _data);
static void isi_channel_real_suspend (FsoGsmChannel* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean isi_channel_real_suspend_co (IsiChannelSuspendData* _data_);
static void isi_channel_real_resume_data_free (gpointer _data);
static void isi_channel_real_resume (FsoGsmChannel* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean isi_channel_real_resume_co (IsiChannelResumeData* _data_);
static void isi_channel_finalize (GObject* obj);


static void isi_channel_onModemStatusChanged (IsiChannel* self, FsoGsmModem* modem, FsoGsmModemStatus status) {
	FsoGsmModemStatus _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (modem != NULL);
	_tmp0_ = status;
	switch (_tmp0_) {
		case FSO_GSM_MODEM_STATUS_INITIALIZING:
		{
			isi_channel_initialize (self, NULL, NULL);
			break;
		}
		case FSO_GSM_MODEM_STATUS_ALIVE_SIM_READY:
		{
			isi_channel_poweron (self, NULL, NULL);
			break;
		}
		case FSO_GSM_MODEM_STATUS_CLOSING:
		{
			isi_channel_shutdown (self, NULL, NULL);
			break;
		}
		default:
		{
			break;
		}
	}
}


static void isi_channel_real_open_data_free (gpointer _data) {
	IsiChannelOpenData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (IsiChannelOpenData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void isi_channel_real_open (FsoFrameworkAbstractCommandQueue* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	IsiChannel * self;
	IsiChannelOpenData* _data_;
	IsiChannel* _tmp0_;
	self = (IsiChannel*) base;
	_data_ = g_slice_new0 (IsiChannelOpenData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, isi_channel_real_open);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, isi_channel_real_open_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	isi_channel_real_open_co (_data_);
}


static gboolean isi_channel_real_open_finish (FsoFrameworkAbstractCommandQueue* base, GAsyncResult* _res_) {
	gboolean result;
	IsiChannelOpenData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static void isi_channel_open_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	IsiChannelOpenData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	isi_channel_real_open_co (_data_);
}


static gboolean isi_channel_real_open_co (IsiChannelOpenData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_framework_command_queue_get_transport ((FsoFrameworkCommandQueue*) _data_->self);
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->_state_ = 1;
	fso_framework_transport_openAsync (_data_->_tmp1_, isi_channel_open_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp2_ = FALSE;
	_data_->_tmp2_ = fso_framework_transport_openAsync_finish (_data_->_tmp1_, _data_->_res_);
	_data_->result = _data_->_tmp2_;
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


static void isi_channel_real_onReadFromTransport (FsoFrameworkAbstractCommandQueue* base, FsoFrameworkTransport* t) {
	IsiChannel * self;
	self = (IsiChannel*) base;
	g_return_if_fail (t != NULL);
	g_assert_not_reached ();
}


static void _isi_channel_onModemStatusChanged_fso_gsm_modem_signal_status_changed (FsoGsmModem* _sender, FsoGsmModemStatus status, gpointer self) {
	isi_channel_onModemStatusChanged (self, _sender, status);
}


IsiChannel* isi_channel_construct (GType object_type, FsoGsmModem* modem, const gchar* name, IsiTransport* transport) {
	IsiChannel * self = NULL;
	IsiTransport* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	FsoGsmModem* _tmp3_;
	FsoGsmModem* _tmp4_;
	FsoGsmModem* _tmp5_;
	const gchar* _tmp6_;
	FsoGsmModem* _tmp7_;
	g_return_val_if_fail (modem != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (transport != NULL, NULL);
	_tmp0_ = transport;
	self = (IsiChannel*) fso_framework_abstract_command_queue_construct (object_type, (FsoFrameworkTransport*) _tmp0_);
	_tmp1_ = name;
	_tmp2_ = g_strdup (_tmp1_);
	_g_free0 (self->name);
	self->name = _tmp2_;
	_tmp3_ = modem;
	_tmp4_ = _g_object_ref0 (_tmp3_);
	_g_object_unref0 (self->priv->modem);
	self->priv->modem = _tmp4_;
	_tmp5_ = modem;
	_tmp6_ = name;
	fso_gsm_modem_registerChannel (_tmp5_, _tmp6_, (FsoGsmChannel*) self);
	_tmp7_ = modem;
	g_signal_connect_object (_tmp7_, "signal-status-changed", (GCallback) _isi_channel_onModemStatusChanged_fso_gsm_modem_signal_status_changed, self, 0);
	return self;
}


IsiChannel* isi_channel_new (FsoGsmModem* modem, const gchar* name, IsiTransport* transport) {
	return isi_channel_construct (TYPE_ISI_CHANNEL, modem, name, transport);
}


static void isi_channel_poweron_data_free (gpointer _data) {
	IsiChannelPoweronData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (IsiChannelPoweronData, _data_);
}


void isi_channel_poweron (IsiChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	IsiChannelPoweronData* _data_;
	IsiChannel* _tmp0_;
	_data_ = g_slice_new0 (IsiChannelPoweronData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, isi_channel_poweron);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, isi_channel_poweron_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	isi_channel_poweron_co (_data_);
}


void isi_channel_poweron_finish (IsiChannel* self, GAsyncResult* _res_) {
	IsiChannelPoweronData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void isi_channel_poweron_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	IsiChannelPoweronData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	isi_channel_poweron_co (_data_);
}


static gboolean isi_channel_poweron_co (IsiChannelPoweronData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->self->priv->modem;
	_data_->_tmp1_ = nokia_isi_isi_unsolicited_handler_new (_data_->_tmp0_);
	_g_object_unref0 (_data_->self->priv->unsolicitedHandler);
	_data_->self->priv->unsolicitedHandler = _data_->_tmp1_;
	_data_->_tmp2_ = nokia_isi_isimodem;
	_data_->_state_ = 1;
	gisi_comm_modem_access_poweron (_data_->_tmp2_, isi_channel_poweron_ready, _data_);
	return FALSE;
	_state_1:
	gisi_comm_modem_access_poweron_finish (_data_->_tmp2_, _data_->_res_);
	_data_->_tmp3_ = nokia_isi_isimodem;
	fso_framework_data_sharing_setValueForKey ("NokiaIsi.isimodem", _data_->_tmp3_);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void isi_channel_initialize_data_free (gpointer _data) {
	IsiChannelInitializeData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (IsiChannelInitializeData, _data_);
}


void isi_channel_initialize (IsiChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	IsiChannelInitializeData* _data_;
	IsiChannel* _tmp0_;
	_data_ = g_slice_new0 (IsiChannelInitializeData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, isi_channel_initialize);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, isi_channel_initialize_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	isi_channel_initialize_co (_data_);
}


void isi_channel_initialize_finish (IsiChannel* self, GAsyncResult* _res_) {
	IsiChannelInitializeData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void isi_channel_initialize_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	IsiChannelInitializeData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	isi_channel_initialize_co (_data_);
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gboolean isi_channel_initialize_co (IsiChannelInitializeData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = nokia_isi_isi_sim_get_auth_status_new ();
	_data_->getAuthStatus = _data_->_tmp0_;
	{
		_data_->_tmp1_ = _data_->getAuthStatus;
		_data_->_state_ = 1;
		fso_gsm_sim_get_auth_status_run ((FsoGsmSimGetAuthStatus*) _data_->_tmp1_, isi_channel_initialize_ready, _data_);
		return FALSE;
		_state_1:
		fso_gsm_sim_get_auth_status_run_finish ((FsoGsmSimGetAuthStatus*) _data_->_tmp1_, _data_->_res_, &_data_->_inner_error_);
		if (_data_->_inner_error_ != NULL) {
			if (_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) {
				goto __catch0_free_smartphone_gsm_error;
			}
			goto __catch0_g_error;
		}
		_data_->_tmp2_ = _data_->getAuthStatus;
		_data_->_tmp3_ = ((FsoGsmSimGetAuthStatus*) _data_->_tmp2_)->status;
		if (_data_->_tmp3_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_READY) {
			_data_->_tmp4_ = _data_->self->priv->modem;
			fso_gsm_modem_advanceToState (_data_->_tmp4_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_UNLOCKED, FALSE);
		} else {
			_data_->_tmp6_ = _data_->getAuthStatus;
			_data_->_tmp7_ = ((FsoGsmSimGetAuthStatus*) _data_->_tmp6_)->status;
			if (_data_->_tmp7_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_PIN_REQUIRED) {
				_data_->_tmp5_ = TRUE;
			} else {
				_data_->_tmp8_ = _data_->getAuthStatus;
				_data_->_tmp9_ = ((FsoGsmSimGetAuthStatus*) _data_->_tmp8_)->status;
				_data_->_tmp5_ = _data_->_tmp9_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_PUK_REQUIRED;
			}
			_data_->_tmp10_ = _data_->_tmp5_;
			if (_data_->_tmp10_) {
				_data_->_tmp11_ = _data_->self->priv->modem;
				fso_gsm_modem_advanceToState (_data_->_tmp11_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_LOCKED, FALSE);
			}
		}
	}
	goto __finally0;
	__catch0_free_smartphone_gsm_error:
	{
		_data_->e1 = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp12_ = _data_->e1;
		if (g_error_matches (_data_->_tmp12_, FREE_SMARTPHONE_GSM_ERROR, FREE_SMARTPHONE_GSM_ERROR_SIM_NOT_PRESENT)) {
			_data_->_tmp13_ = _data_->self->priv->modem;
			fso_gsm_modem_advanceToState (_data_->_tmp13_, FSO_GSM_MODEM_STATUS_ALIVE_NO_SIM, FALSE);
		} else {
			_data_->_tmp14_ = _data_->self->priv->modem;
			_data_->_tmp15_ = ((FsoFrameworkAbstractObject*) _data_->_tmp14_)->logger;
			_data_->_tmp16_ = _data_->e1;
			_data_->_tmp17_ = _data_->_tmp16_->message;
			_data_->_tmp18_ = NULL;
			_data_->_tmp18_ = string_to_string (_data_->_tmp17_);
			_data_->_tmp19_ = NULL;
			_data_->_tmp19_ = g_strconcat ("Unexpected FSO error: ", _data_->_tmp18_, " - what now?", NULL);
			_data_->_tmp20_ = _data_->_tmp19_;
			fso_framework_logger_error (_data_->_tmp15_, _data_->_tmp20_);
			_g_free0 (_data_->_tmp20_);
		}
		_g_error_free0 (_data_->e1);
	}
	goto __finally0;
	__catch0_g_error:
	{
		_data_->e2 = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp21_ = _data_->self->priv->modem;
		_data_->_tmp22_ = ((FsoFrameworkAbstractObject*) _data_->_tmp21_)->logger;
		_data_->_tmp23_ = _data_->e2;
		_data_->_tmp24_ = _data_->_tmp23_->message;
		_data_->_tmp25_ = NULL;
		_data_->_tmp25_ = string_to_string (_data_->_tmp24_);
		_data_->_tmp26_ = NULL;
		_data_->_tmp26_ = g_strconcat ("Can't get SIM auth status: ", _data_->_tmp25_, " - what now?", NULL);
		_data_->_tmp27_ = _data_->_tmp26_;
		fso_framework_logger_error (_data_->_tmp22_, _data_->_tmp27_);
		_g_free0 (_data_->_tmp27_);
		_g_error_free0 (_data_->e2);
	}
	__finally0:
	if (_data_->_inner_error_ != NULL) {
		_g_object_unref0 (_data_->getAuthStatus);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
		g_clear_error (&_data_->_inner_error_);
		return FALSE;
	}
	_g_object_unref0 (_data_->getAuthStatus);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void isi_channel_shutdown_data_free (gpointer _data) {
	IsiChannelShutdownData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (IsiChannelShutdownData, _data_);
}


void isi_channel_shutdown (IsiChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	IsiChannelShutdownData* _data_;
	IsiChannel* _tmp0_;
	_data_ = g_slice_new0 (IsiChannelShutdownData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, isi_channel_shutdown);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, isi_channel_shutdown_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	isi_channel_shutdown_co (_data_);
}


void isi_channel_shutdown_finish (IsiChannel* self, GAsyncResult* _res_) {
	IsiChannelShutdownData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean isi_channel_shutdown_co (IsiChannelShutdownData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = _data_->self->priv->_is_initialized;
	if (_data_->_tmp0_) {
		_data_->self->priv->_is_initialized = FALSE;
	}
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


void isi_channel_registerUnsolicitedHandler (IsiChannel* self, IsiChannelUnsolicitedHandler urchandler, void* urchandler_target) {
	g_return_if_fail (self != NULL);
}


static void isi_channel_real_injectResponse (FsoGsmChannel* base, const gchar* response) {
	IsiChannel * self;
	self = (IsiChannel*) base;
	g_return_if_fail (response != NULL);
	g_assert_not_reached ();
}


static void isi_channel_real_suspend_data_free (gpointer _data) {
	IsiChannelSuspendData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (IsiChannelSuspendData, _data_);
}


static void isi_channel_real_suspend (FsoGsmChannel* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	IsiChannel * self;
	IsiChannelSuspendData* _data_;
	IsiChannel* _tmp0_;
	self = (IsiChannel*) base;
	_data_ = g_slice_new0 (IsiChannelSuspendData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, isi_channel_real_suspend);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, isi_channel_real_suspend_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	isi_channel_real_suspend_co (_data_);
}


static gboolean isi_channel_real_suspend_finish (FsoGsmChannel* base, GAsyncResult* _res_) {
	gboolean result;
	IsiChannelSuspendData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static gboolean isi_channel_real_suspend_co (IsiChannelSuspendData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
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


static void isi_channel_real_resume_data_free (gpointer _data) {
	IsiChannelResumeData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (IsiChannelResumeData, _data_);
}


static void isi_channel_real_resume (FsoGsmChannel* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	IsiChannel * self;
	IsiChannelResumeData* _data_;
	IsiChannel* _tmp0_;
	self = (IsiChannel*) base;
	_data_ = g_slice_new0 (IsiChannelResumeData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, isi_channel_real_resume);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, isi_channel_real_resume_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	isi_channel_real_resume_co (_data_);
}


static gboolean isi_channel_real_resume_finish (FsoGsmChannel* base, GAsyncResult* _res_) {
	gboolean result;
	IsiChannelResumeData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static gboolean isi_channel_real_resume_co (IsiChannelResumeData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
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


static void isi_channel_class_init (IsiChannelClass * klass) {
	isi_channel_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (IsiChannelPrivate));
	FSO_FRAMEWORK_ABSTRACT_COMMAND_QUEUE_CLASS (klass)->open = isi_channel_real_open;
	FSO_FRAMEWORK_ABSTRACT_COMMAND_QUEUE_CLASS (klass)->open_finish = isi_channel_real_open_finish;
	FSO_FRAMEWORK_ABSTRACT_COMMAND_QUEUE_CLASS (klass)->onReadFromTransport = isi_channel_real_onReadFromTransport;
	G_OBJECT_CLASS (klass)->finalize = isi_channel_finalize;
}


static void isi_channel_fso_gsm_channel_interface_init (FsoGsmChannelIface * iface) {
	isi_channel_fso_gsm_channel_parent_iface = g_type_interface_peek_parent (iface);
	iface->injectResponse = (void (*)(FsoGsmChannel*, const gchar*)) isi_channel_real_injectResponse;
	iface->suspend = (gboolean (*)(FsoGsmChannel*)) isi_channel_real_suspend;
	iface->suspend_finish = isi_channel_real_suspend_finish;
	iface->resume = (gboolean (*)(FsoGsmChannel*)) isi_channel_real_resume;
	iface->resume_finish = isi_channel_real_resume_finish;
}


static void isi_channel_instance_init (IsiChannel * self) {
	self->priv = ISI_CHANNEL_GET_PRIVATE (self);
}


static void isi_channel_finalize (GObject* obj) {
	IsiChannel * self;
	self = ISI_CHANNEL (obj);
	_g_object_unref0 (self->priv->unsolicitedHandler);
	_g_object_unref0 (self->priv->modem);
	_g_free0 (self->name);
	G_OBJECT_CLASS (isi_channel_parent_class)->finalize (obj);
}


GType isi_channel_get_type (void) {
	return isi_channel_type_id;
}


GType isi_channel_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (IsiChannelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) isi_channel_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (IsiChannel), 0, (GInstanceInitFunc) isi_channel_instance_init, NULL };
	static const GInterfaceInfo fso_gsm_channel_info = { (GInterfaceInitFunc) isi_channel_fso_gsm_channel_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	isi_channel_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_COMMAND_QUEUE, "IsiChannel", &g_define_type_info, 0);
	g_type_module_add_interface (module, isi_channel_type_id, FSO_GSM_TYPE_CHANNEL, &fso_gsm_channel_info);
	return isi_channel_type_id;
}




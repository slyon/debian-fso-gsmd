/* unsolicited.c generated by valac 0.16.1, the Vala compiler
 * generated from unsolicited.vala, do not modify */

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
#include <fsobasics.h>
#include <fsogsm.h>
#include <radio.h>
#include <fsotransport.h>
#include <freesmartphone.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define SAMSUNG_TYPE_UNSOLICITED_RESPONSE_HANDLER (samsung_unsolicited_response_handler_get_type ())
#define SAMSUNG_UNSOLICITED_RESPONSE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_UNSOLICITED_RESPONSE_HANDLER, SamsungUnsolicitedResponseHandler))
#define SAMSUNG_UNSOLICITED_RESPONSE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_UNSOLICITED_RESPONSE_HANDLER, SamsungUnsolicitedResponseHandlerClass))
#define SAMSUNG_IS_UNSOLICITED_RESPONSE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_UNSOLICITED_RESPONSE_HANDLER))
#define SAMSUNG_IS_UNSOLICITED_RESPONSE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_UNSOLICITED_RESPONSE_HANDLER))
#define SAMSUNG_UNSOLICITED_RESPONSE_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_UNSOLICITED_RESPONSE_HANDLER, SamsungUnsolicitedResponseHandlerClass))

typedef struct _SamsungUnsolicitedResponseHandler SamsungUnsolicitedResponseHandler;
typedef struct _SamsungUnsolicitedResponseHandlerClass SamsungUnsolicitedResponseHandlerClass;
typedef struct _SamsungUnsolicitedResponseHandlerPrivate SamsungUnsolicitedResponseHandlerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SAMSUNG_TYPE_IPC_CHANNEL (samsung_ipc_channel_get_type ())
#define SAMSUNG_IPC_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannel))
#define SAMSUNG_IPC_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannelClass))
#define SAMSUNG_IS_IPC_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_IPC_CHANNEL))
#define SAMSUNG_IS_IPC_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_IPC_CHANNEL))
#define SAMSUNG_IPC_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannelClass))

typedef struct _SamsungIpcChannel SamsungIpcChannel;
typedef struct _SamsungIpcChannelClass SamsungIpcChannelClass;

#define SAMSUNG_TYPE_CALL_HANDLER (samsung_call_handler_get_type ())
#define SAMSUNG_CALL_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_CALL_HANDLER, SamsungCallHandler))
#define SAMSUNG_CALL_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_CALL_HANDLER, SamsungCallHandlerClass))
#define SAMSUNG_IS_CALL_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_CALL_HANDLER))
#define SAMSUNG_IS_CALL_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_CALL_HANDLER))
#define SAMSUNG_CALL_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_CALL_HANDLER, SamsungCallHandlerClass))

typedef struct _SamsungCallHandler SamsungCallHandler;
typedef struct _SamsungCallHandlerClass SamsungCallHandlerClass;
#define _g_free0(var) (var = (g_free (var), NULL))

#define SAMSUNG_TYPE_PDP_HANDLER (samsung_pdp_handler_get_type ())
#define SAMSUNG_PDP_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_PDP_HANDLER, SamsungPdpHandler))
#define SAMSUNG_PDP_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_PDP_HANDLER, SamsungPdpHandlerClass))
#define SAMSUNG_IS_PDP_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_PDP_HANDLER))
#define SAMSUNG_IS_PDP_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_PDP_HANDLER))
#define SAMSUNG_PDP_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_PDP_HANDLER, SamsungPdpHandlerClass))

typedef struct _SamsungPdpHandler SamsungPdpHandler;
typedef struct _SamsungPdpHandlerClass SamsungPdpHandlerClass;
typedef struct _SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData;

struct _SamsungUnsolicitedResponseHandler {
	FsoFrameworkAbstractObject parent_instance;
	SamsungUnsolicitedResponseHandlerPrivate * priv;
};

struct _SamsungUnsolicitedResponseHandlerClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _SamsungUnsolicitedResponseHandlerPrivate {
	FsoGsmModem* modem;
};

struct _SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungUnsolicitedResponseHandler* self;
	FsoGsmModem* _tmp0_;
	FsoGsmChannel* _tmp1_;
	SamsungIpcChannel* channel;
	struct ipc_message_info* response;
	guint8* _tmp2_;
	guint8* _tmp3_;
	gint _tmp3__length1;
	struct ipc_message_info* _tmp4_;
};


static gpointer samsung_unsolicited_response_handler_parent_class = NULL;
extern guint8 samsung_modem_state_sim_icc_type;
extern gint32 samsung_modem_state_network_signal_strength;
extern gint8 samsung_modem_state_sim_status;
extern guint8 samsung_modem_state_power_state;
static GType samsung_unsolicited_response_handler_type_id = 0;

GType samsung_unsolicited_response_handler_get_type (void) G_GNUC_CONST;
GType samsung_unsolicited_response_handler_register_type (GTypeModule * module);
#define SAMSUNG_UNSOLICITED_RESPONSE_HANDLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SAMSUNG_TYPE_UNSOLICITED_RESPONSE_HANDLER, SamsungUnsolicitedResponseHandlerPrivate))
enum  {
	SAMSUNG_UNSOLICITED_RESPONSE_HANDLER_DUMMY_PROPERTY
};
SamsungUnsolicitedResponseHandler* samsung_unsolicited_response_handler_new (FsoGsmModem* modem);
SamsungUnsolicitedResponseHandler* samsung_unsolicited_response_handler_construct (GType object_type, FsoGsmModem* modem);
void samsung_unsolicited_response_handler_process (SamsungUnsolicitedResponseHandler* self, struct ipc_message_info* response);
GType samsung_ipc_channel_get_type (void) G_GNUC_CONST;
GType samsung_ipc_channel_register_type (GTypeModule * module);
GType samsung_call_handler_get_type (void) G_GNUC_CONST;
GType samsung_call_handler_register_type (GTypeModule * module);
static void samsung_unsolicited_response_handler_handle_sim_status (SamsungUnsolicitedResponseHandler* self, struct ipc_message_info* response);
static void samsung_unsolicited_response_handler_handle_power_state (SamsungUnsolicitedResponseHandler* self, guint8 power_state);
static void samsung_unsolicited_response_handler_handle_signal_strength (SamsungUnsolicitedResponseHandler* self, guint8 rssi);
static void samsung_unsolicited_response_handler_handle_gprs_ip_configuration (SamsungUnsolicitedResponseHandler* self, struct ipc_message_info* response);
void samsung_call_handler_syncCallStatusAsync (SamsungCallHandler* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void samsung_call_handler_syncCallStatusAsync_finish (SamsungCallHandler* self, GAsyncResult* _res_);
static gboolean ___lambda2_ (SamsungUnsolicitedResponseHandler* self);
static void samsung_unsolicited_response_handler_handle_sms_device_ready (SamsungUnsolicitedResponseHandler* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void samsung_unsolicited_response_handler_handle_sms_device_ready_finish (SamsungUnsolicitedResponseHandler* self, GAsyncResult* _res_);
static gboolean ____lambda2__gsource_func (gpointer self);
static gchar* samsung_unsolicited_response_handler_real_repr (FsoFrameworkAbstractObject* base);
void updateSimAuthStatus (FsoGsmModem* modem, FreeSmartphoneGSMSIMAuthStatus status);
GType samsung_pdp_handler_get_type (void) G_GNUC_CONST;
GType samsung_pdp_handler_register_type (GTypeModule * module);
gchar* ipAddrFromByteArray (guint8* data, gint size);
void samsung_pdp_handler_handleIpConfiguration (SamsungPdpHandler* self, const gchar* local, const gchar* subnetmask, const gchar* gateway, const gchar* dns1, const gchar* dns2, GAsyncReadyCallback _callback_, gpointer _user_data_);
void samsung_pdp_handler_handleIpConfiguration_finish (SamsungPdpHandler* self, GAsyncResult* _res_);
static void samsung_unsolicited_response_handler_handle_sms_device_ready_data_free (gpointer _data);
static gboolean samsung_unsolicited_response_handler_handle_sms_device_ready_co (SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData* _data_);
void samsung_ipc_channel_enqueue_async (SamsungIpcChannel* self, int type, unsigned short command, guint8* data, int data_length1, gint retry, gint timeout, GAsyncReadyCallback _callback_, gpointer _user_data_);
struct ipc_message_info* samsung_ipc_channel_enqueue_finish (SamsungIpcChannel* self, GAsyncResult* _res_);
static void samsung_unsolicited_response_handler_handle_sms_device_ready_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void samsung_unsolicited_response_handler_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


SamsungUnsolicitedResponseHandler* samsung_unsolicited_response_handler_construct (GType object_type, FsoGsmModem* modem) {
	SamsungUnsolicitedResponseHandler * self = NULL;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	g_return_val_if_fail (modem != NULL, NULL);
	self = (SamsungUnsolicitedResponseHandler*) fso_framework_abstract_object_construct (object_type);
	_tmp0_ = modem;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->modem);
	self->priv->modem = _tmp1_;
	return self;
}


SamsungUnsolicitedResponseHandler* samsung_unsolicited_response_handler_new (FsoGsmModem* modem) {
	return samsung_unsolicited_response_handler_construct (SAMSUNG_TYPE_UNSOLICITED_RESPONSE_HANDLER, modem);
}


/**
     * Handling the various possible unsolicited responses we get from the modem
     **/
static unsigned short samsung_ipc_response_get_command (struct ipc_message_info* self) {
	unsigned short result;
	guint8 _tmp0_;
	guint8 _tmp1_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = (*self).group;
	_tmp1_ = (*self).index;
	result = (unsigned short) ((_tmp0_ << 8) | _tmp1_);
	return result;
}


static void samsung_ipc_response_set_command (struct ipc_message_info* self, unsigned short value) {
	unsigned short _tmp0_;
	unsigned short _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	(*self).group = (guint8) (_tmp0_ >> 8);
	_tmp1_ = value;
	(*self).index = (guint8) (_tmp1_ & 0xff);
}


static gboolean ___lambda2_ (SamsungUnsolicitedResponseHandler* self) {
	gboolean result = FALSE;
	samsung_unsolicited_response_handler_handle_sms_device_ready (self, NULL, NULL);
	result = FALSE;
	return result;
}


static gboolean ____lambda2__gsource_func (gpointer self) {
	gboolean result;
	result = ___lambda2_ (self);
	return result;
}


void samsung_unsolicited_response_handler_process (SamsungUnsolicitedResponseHandler* self, struct ipc_message_info* response) {
	FsoGsmModem* _tmp0_;
	FsoGsmChannel* _tmp1_ = NULL;
	SamsungIpcChannel* channel;
	FsoGsmModem* _tmp2_;
	FsoGsmCallHandler* _tmp3_;
	FsoGsmCallHandler* _tmp4_;
	SamsungCallHandler* _tmp5_;
	SamsungCallHandler* callhandler;
	struct ipc_message_info _tmp6_;
	unsigned short _tmp7_;
	unsigned short _tmp8_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (response != NULL);
	_tmp0_ = self->priv->modem;
	_tmp1_ = fso_gsm_modem_channel (_tmp0_, "main");
	channel = SAMSUNG_IS_IPC_CHANNEL (_tmp1_) ? ((SamsungIpcChannel*) _tmp1_) : NULL;
	_tmp2_ = self->priv->modem;
	_tmp3_ = fso_gsm_modem_get_callhandler (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = _g_object_ref0 (SAMSUNG_IS_CALL_HANDLER (_tmp4_) ? ((SamsungCallHandler*) _tmp4_) : NULL);
	callhandler = _tmp5_;
	_tmp6_ = *response;
	_tmp7_ = samsung_ipc_response_get_command (&_tmp6_);
	_tmp8_ = _tmp7_;
	switch (_tmp8_) {
		case IPC_PWR_PHONE_PWR_UP:
		{
			break;
		}
		case IPC_SEC_SIM_ICC_TYPE:
		{
			struct ipc_message_info _tmp9_;
			guint8* _tmp10_;
			gint _tmp10__length1;
			guint8 _tmp11_;
			_tmp9_ = *response;
			_tmp10_ = _tmp9_.data;
			_tmp10__length1 = _tmp9_.length;
			_tmp11_ = _tmp10_[0];
			samsung_modem_state_sim_icc_type = _tmp11_;
			break;
		}
		case IPC_SEC_PIN_STATUS:
		{
			struct ipc_message_info _tmp12_;
			_tmp12_ = *response;
			samsung_unsolicited_response_handler_handle_sim_status (self, &_tmp12_);
			break;
		}
		case IPC_NET_REGIST:
		{
			FsoGsmModem* _tmp13_;
			_tmp13_ = self->priv->modem;
			fso_gsm_triggerUpdateNetworkStatus (_tmp13_, NULL, NULL);
			break;
		}
		case IPC_PWR_PHONE_STATE:
		{
			struct ipc_message_info _tmp14_;
			guint8* _tmp15_;
			gint _tmp15__length1;
			guint8 _tmp16_;
			guint8 power_state;
			guint8 _tmp17_;
			_tmp14_ = *response;
			_tmp15_ = _tmp14_.data;
			_tmp15__length1 = _tmp14_.length;
			_tmp16_ = _tmp15_[0];
			power_state = _tmp16_;
			_tmp17_ = power_state;
			samsung_unsolicited_response_handler_handle_power_state (self, _tmp17_);
			break;
		}
		case IPC_DISP_RSSI_INFO:
		{
			FsoGsmModem* _tmp18_;
			FsoGsmModemStatus _tmp19_ = 0;
			struct ipc_message_info _tmp20_;
			guint8* _tmp21_;
			gint _tmp21__length1;
			guint8 _tmp22_;
			FsoGsmModem* _tmp23_;
			gpointer _tmp24_ = NULL;
			FreeSmartphoneGSMNetwork* obj;
			FreeSmartphoneGSMNetwork* _tmp25_;
			gint32 _tmp26_;
			_tmp18_ = self->priv->modem;
			_tmp19_ = fso_gsm_modem_status (_tmp18_);
			if (_tmp19_ != FSO_GSM_MODEM_STATUS_ALIVE_REGISTERED) {
				break;
			}
			_tmp20_ = *response;
			_tmp21_ = _tmp20_.data;
			_tmp21__length1 = _tmp20_.length;
			_tmp22_ = _tmp21_[0];
			samsung_unsolicited_response_handler_handle_signal_strength (self, _tmp22_);
			_tmp23_ = self->priv->modem;
			_tmp24_ = fso_gsm_modem_theDevice (_tmp23_, FREE_SMARTPHONE_GSM_TYPE_NETWORK, (GBoxedCopyFunc) g_object_ref, g_object_unref);
			obj = (FreeSmartphoneGSMNetwork*) _tmp24_;
			_tmp25_ = obj;
			_tmp26_ = samsung_modem_state_network_signal_strength;
			g_signal_emit_by_name (_tmp25_, "signal-strength", (gint) _tmp26_);
			_g_object_unref0 (obj);
			break;
		}
		case IPC_GPRS_IP_CONFIGURATION:
		{
			struct ipc_message_info _tmp27_;
			_tmp27_ = *response;
			samsung_unsolicited_response_handler_handle_gprs_ip_configuration (self, &_tmp27_);
			break;
		}
		case IPC_CALL_INCOMING:
		case IPC_CALL_RELEASE:
		case IPC_CALL_STATUS:
		case IPC_CALL_OUTGOING:
		{
			SamsungCallHandler* _tmp28_;
			_tmp28_ = callhandler;
			samsung_call_handler_syncCallStatusAsync (_tmp28_, NULL, NULL);
			break;
		}
		case IPC_SMS_DEVICE_READY:
		{
			g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, ____lambda2__gsource_func, g_object_ref (self), g_object_unref);
			break;
		}
		default:
		break;
	}
	_g_object_unref0 (callhandler);
	_g_object_unref0 (channel);
}


static gchar* samsung_unsolicited_response_handler_real_repr (FsoFrameworkAbstractObject* base) {
	SamsungUnsolicitedResponseHandler * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (SamsungUnsolicitedResponseHandler*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void samsung_unsolicited_response_handler_handle_signal_strength (SamsungUnsolicitedResponseHandler* self, guint8 rssi) {
	gint _tmp0_ = 0;
	guint8 _tmp1_;
	gint _tmp4_;
	gint r;
	gint _tmp5_ = 0;
	FsoGsmModem* _tmp6_;
	gpointer _tmp7_ = NULL;
	FreeSmartphoneGSMNetwork* obj;
	gint32 _tmp8_;
	g_return_if_fail (self != NULL);
	_tmp1_ = rssi;
	if (((gint) _tmp1_) < 0x6f) {
		guint8 _tmp2_;
		guint8 _tmp3_;
		_tmp2_ = rssi;
		_tmp3_ = rssi;
		_tmp0_ = (((_tmp2_ - 0x71) * (-1)) - (((_tmp3_ - 0x71) * (-1)) % 2)) / 2;
	} else {
		_tmp0_ = 0;
	}
	_tmp4_ = _tmp0_;
	r = _tmp4_;
	_tmp5_ = fso_gsm_constants_networkSignalToPercentage (r);
	samsung_modem_state_network_signal_strength = (gint32) _tmp5_;
	_tmp6_ = self->priv->modem;
	_tmp7_ = fso_gsm_modem_theDevice (_tmp6_, FREE_SMARTPHONE_GSM_TYPE_NETWORK, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	obj = (FreeSmartphoneGSMNetwork*) _tmp7_;
	_tmp8_ = samsung_modem_state_network_signal_strength;
	g_signal_emit_by_name (obj, "signal-strength", (gint) _tmp8_);
	_g_object_unref0 (obj);
}


static void samsung_unsolicited_response_handler_handle_sim_status (SamsungUnsolicitedResponseHandler* self, struct ipc_message_info* response) {
	struct ipc_message_info _tmp0_;
	guint8* _tmp1_;
	gint _tmp1__length1;
	struct ipc_sec_pin_status_response* message;
	struct ipc_sec_pin_status_response* _tmp2_;
	gint8 _tmp3_;
	gint8 _tmp4_;
	struct ipc_sec_pin_status_response* _tmp5_;
	gint8 _tmp6_;
	FsoFrameworkLogger* _tmp7_;
	struct ipc_sec_pin_status_response* _tmp8_;
	gint8 _tmp9_;
	gchar* _tmp10_ = NULL;
	gchar* _tmp11_;
	gboolean _tmp12_ = FALSE;
	struct ipc_sec_pin_status_response* _tmp13_;
	gint8 _tmp14_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (response != NULL);
	_tmp0_ = *response;
	_tmp1_ = _tmp0_.data;
	_tmp1__length1 = _tmp0_.length;
	message = (struct ipc_sec_pin_status_response*) _tmp1_;
	_tmp2_ = message;
	_tmp3_ = (*_tmp2_).type;
	_tmp4_ = samsung_modem_state_sim_status;
	if (_tmp3_ == _tmp4_) {
		return;
	}
	_tmp5_ = message;
	_tmp6_ = (*_tmp5_).type;
	samsung_modem_state_sim_status = _tmp6_;
	_tmp7_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp8_ = message;
	_tmp9_ = (*_tmp8_).type;
	_tmp10_ = g_strdup_printf ("sim status changed to status = 0x%02x", (guint) _tmp9_);
	_tmp11_ = _tmp10_;
	_tmp12_ = fso_framework_logger_debug (_tmp7_, _tmp11_);
	g_assert (_tmp12_);
	_g_free0 (_tmp11_);
	_tmp13_ = message;
	_tmp14_ = (*_tmp13_).type;
	switch ((guint8) _tmp14_) {
		case IPC_SEC_PIN_SIM_INIT_COMPLETE:
		{
			FsoGsmModem* _tmp15_;
			_tmp15_ = self->priv->modem;
			updateSimAuthStatus (_tmp15_, FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_READY);
			break;
		}
		case IPC_SEC_PIN_SIM_LOCK_SC:
		{
			struct ipc_sec_pin_status_response* _tmp16_;
			gint8 _tmp17_;
			_tmp16_ = message;
			_tmp17_ = (*_tmp16_).key;
			switch (_tmp17_) {
				case IPC_SEC_PIN_SIM_LOCK_SC_PIN1_REQ:
				{
					FsoGsmModem* _tmp18_;
					_tmp18_ = self->priv->modem;
					updateSimAuthStatus (_tmp18_, FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_PIN_REQUIRED);
					break;
				}
				case IPC_SEC_PIN_SIM_LOCK_SC_PUK_REQ:
				{
					FsoGsmModem* _tmp19_;
					_tmp19_ = self->priv->modem;
					updateSimAuthStatus (_tmp19_, FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_PUK_REQUIRED);
					break;
				}
				case IPC_SEC_PIN_SIM_LOCK_SC_CARD_BLOCKED:
				{
					FsoGsmModem* _tmp20_;
					_tmp20_ = self->priv->modem;
					fso_gsm_modem_advanceToState (_tmp20_, FSO_GSM_MODEM_STATUS_ALIVE_NO_SIM, FALSE);
					break;
				}
				default:
				break;
			}
			break;
		}
		case IPC_SEC_PIN_SIM_PB_INIT_COMPLETE:
		{
			break;
		}
		case IPC_SEC_PIN_SIM_LOCK_FD:
		case IPC_SEC_PIN_SIM_SIM_LOCK_REQUIRED:
		case IPC_SEC_PIN_SIM_CARD_ERROR:
		case IPC_SEC_PIN_SIM_CARD_NOT_PRESENT:
		{
			FsoGsmModem* _tmp21_;
			_tmp21_ = self->priv->modem;
			fso_gsm_modem_advanceToState (_tmp21_, FSO_GSM_MODEM_STATUS_ALIVE_NO_SIM, FALSE);
			break;
		}
		default:
		break;
	}
}


static void samsung_unsolicited_response_handler_handle_power_state (SamsungUnsolicitedResponseHandler* self, guint8 power_state) {
	guint8 _tmp0_;
	guint8 _tmp1_;
	FsoFrameworkLogger* _tmp2_;
	guint8 _tmp3_;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_;
	gboolean _tmp6_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = power_state;
	_tmp1_ = samsung_modem_state_power_state;
	if (_tmp0_ == _tmp1_) {
		return;
	}
	_tmp2_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp3_ = power_state;
	_tmp4_ = g_strdup_printf ("phone state changed to state = 0x%02x", (guint) _tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = fso_framework_logger_debug (_tmp2_, _tmp5_);
	g_assert (_tmp6_);
	_g_free0 (_tmp5_);
}


static void samsung_unsolicited_response_handler_handle_gprs_ip_configuration (SamsungUnsolicitedResponseHandler* self, struct ipc_message_info* response) {
	FsoGsmModem* _tmp0_;
	FsoGsmIPdpHandler* _tmp1_;
	FsoGsmIPdpHandler* _tmp2_;
	SamsungPdpHandler* _tmp3_;
	SamsungPdpHandler* pdphandler;
	SamsungPdpHandler* _tmp4_;
	struct ipc_message_info _tmp5_;
	guint8* _tmp6_;
	gint _tmp6__length1;
	struct ipc_gprs_ip_configuration* ipresp;
	struct ipc_gprs_ip_configuration* _tmp7_;
	guint8* _tmp8_;
	gint _tmp8__length1;
	gchar* _tmp9_ = NULL;
	gchar* local;
	struct ipc_gprs_ip_configuration* _tmp10_;
	guint8* _tmp11_;
	gint _tmp11__length1;
	gchar* _tmp12_ = NULL;
	gchar* gateway;
	struct ipc_gprs_ip_configuration* _tmp13_;
	guint8* _tmp14_;
	gint _tmp14__length1;
	gchar* _tmp15_ = NULL;
	gchar* subnetmask;
	struct ipc_gprs_ip_configuration* _tmp16_;
	guint8* _tmp17_;
	gint _tmp17__length1;
	gchar* _tmp18_ = NULL;
	gchar* dns1;
	struct ipc_gprs_ip_configuration* _tmp19_;
	guint8* _tmp20_;
	gint _tmp20__length1;
	gchar* _tmp21_ = NULL;
	gchar* dns2;
	SamsungPdpHandler* _tmp22_;
	const gchar* _tmp23_;
	const gchar* _tmp24_;
	const gchar* _tmp25_;
	const gchar* _tmp26_;
	const gchar* _tmp27_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (response != NULL);
	_tmp0_ = self->priv->modem;
	_tmp1_ = fso_gsm_modem_get_pdphandler (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = _g_object_ref0 (SAMSUNG_IS_PDP_HANDLER (_tmp2_) ? ((SamsungPdpHandler*) _tmp2_) : NULL);
	pdphandler = _tmp3_;
	_tmp4_ = pdphandler;
	if (_tmp4_ == NULL) {
		_g_object_unref0 (pdphandler);
		return;
	}
	_tmp5_ = *response;
	_tmp6_ = _tmp5_.data;
	_tmp6__length1 = _tmp5_.length;
	ipresp = (struct ipc_gprs_ip_configuration*) _tmp6_;
	_tmp7_ = ipresp;
	_tmp8_ = (*_tmp7_).ip;
	_tmp8__length1 = -1;
	_tmp9_ = ipAddrFromByteArray (_tmp8_, 4);
	local = _tmp9_;
	_tmp10_ = ipresp;
	_tmp11_ = (*_tmp10_).gateway;
	_tmp11__length1 = -1;
	_tmp12_ = ipAddrFromByteArray (_tmp11_, 4);
	gateway = _tmp12_;
	_tmp13_ = ipresp;
	_tmp14_ = (*_tmp13_).subnet_mask;
	_tmp14__length1 = -1;
	_tmp15_ = ipAddrFromByteArray (_tmp14_, 4);
	subnetmask = _tmp15_;
	_tmp16_ = ipresp;
	_tmp17_ = (*_tmp16_).dns1;
	_tmp17__length1 = -1;
	_tmp18_ = ipAddrFromByteArray (_tmp17_, 4);
	dns1 = _tmp18_;
	_tmp19_ = ipresp;
	_tmp20_ = (*_tmp19_).dns2;
	_tmp20__length1 = -1;
	_tmp21_ = ipAddrFromByteArray (_tmp20_, 4);
	dns2 = _tmp21_;
	_tmp22_ = pdphandler;
	_tmp23_ = local;
	_tmp24_ = subnetmask;
	_tmp25_ = gateway;
	_tmp26_ = dns1;
	_tmp27_ = dns2;
	samsung_pdp_handler_handleIpConfiguration (_tmp22_, _tmp23_, _tmp24_, _tmp25_, _tmp26_, _tmp27_, NULL, NULL);
	_g_free0 (dns2);
	_g_free0 (dns1);
	_g_free0 (subnetmask);
	_g_free0 (gateway);
	_g_free0 (local);
	_g_object_unref0 (pdphandler);
}


static void samsung_unsolicited_response_handler_handle_sms_device_ready_data_free (gpointer _data) {
	SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData, _data_);
}


static void samsung_unsolicited_response_handler_handle_sms_device_ready (SamsungUnsolicitedResponseHandler* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData* _data_;
	SamsungUnsolicitedResponseHandler* _tmp0_;
	_data_ = g_slice_new0 (SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_unsolicited_response_handler_handle_sms_device_ready);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_unsolicited_response_handler_handle_sms_device_ready_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	samsung_unsolicited_response_handler_handle_sms_device_ready_co (_data_);
}


static void samsung_unsolicited_response_handler_handle_sms_device_ready_finish (SamsungUnsolicitedResponseHandler* self, GAsyncResult* _res_) {
	SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void samsung_unsolicited_response_handler_handle_sms_device_ready_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_unsolicited_response_handler_handle_sms_device_ready_co (_data_);
}


static gboolean samsung_unsolicited_response_handler_handle_sms_device_ready_co (SamsungUnsolicitedResponseHandlerHandleSmsDeviceReadyData* _data_) {
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
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = fso_gsm_modem_channel (_data_->_tmp0_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp1_) ? ((SamsungIpcChannel*) _data_->_tmp1_) : NULL;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = g_new0 (guint8, 0);
	_data_->_tmp3_ = _data_->_tmp2_;
	_data_->_tmp3__length1 = 0;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->channel, IPC_TYPE_SET, IPC_SMS_DEVICE_READY, _data_->_tmp3_, 0, 0, 5, samsung_unsolicited_response_handler_handle_sms_device_ready_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp4_ = NULL;
	_data_->_tmp4_ = samsung_ipc_channel_enqueue_finish (_data_->channel, _data_->_res_);
	_data_->response = _data_->_tmp4_;
	_data_->_tmp3_ = (g_free (_data_->_tmp3_), NULL);
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void samsung_unsolicited_response_handler_class_init (SamsungUnsolicitedResponseHandlerClass * klass) {
	samsung_unsolicited_response_handler_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SamsungUnsolicitedResponseHandlerPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = samsung_unsolicited_response_handler_real_repr;
	G_OBJECT_CLASS (klass)->finalize = samsung_unsolicited_response_handler_finalize;
}


static void samsung_unsolicited_response_handler_instance_init (SamsungUnsolicitedResponseHandler * self) {
	self->priv = SAMSUNG_UNSOLICITED_RESPONSE_HANDLER_GET_PRIVATE (self);
}


static void samsung_unsolicited_response_handler_finalize (GObject* obj) {
	SamsungUnsolicitedResponseHandler * self;
	self = SAMSUNG_UNSOLICITED_RESPONSE_HANDLER (obj);
	_g_object_unref0 (self->priv->modem);
	G_OBJECT_CLASS (samsung_unsolicited_response_handler_parent_class)->finalize (obj);
}


GType samsung_unsolicited_response_handler_get_type (void) {
	return samsung_unsolicited_response_handler_type_id;
}


GType samsung_unsolicited_response_handler_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SamsungUnsolicitedResponseHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) samsung_unsolicited_response_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SamsungUnsolicitedResponseHandler), 0, (GInstanceInitFunc) samsung_unsolicited_response_handler_instance_init, NULL };
	samsung_unsolicited_response_handler_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "SamsungUnsolicitedResponseHandler", &g_define_type_info, 0);
	return samsung_unsolicited_response_handler_type_id;
}




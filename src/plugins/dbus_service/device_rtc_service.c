/* device_rtc_service.c generated by valac 0.16.0, the Vala compiler
 * generated from device_rtc_service.vala, do not modify */

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


#define FSO_GSM_TYPE_SERVICE (fso_gsm_service_get_type ())
#define FSO_GSM_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_SERVICE, FsoGsmService))
#define FSO_GSM_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_SERVICE, FsoGsmServiceClass))
#define FSO_GSM_IS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_SERVICE))
#define FSO_GSM_IS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_SERVICE))
#define FSO_GSM_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_SERVICE, FsoGsmServiceClass))

typedef struct _FsoGsmService FsoGsmService;
typedef struct _FsoGsmServiceClass FsoGsmServiceClass;
typedef struct _FsoGsmServicePrivate FsoGsmServicePrivate;

#define FSO_GSM_TYPE_DEVICE_RTC_SERVICE (fso_gsm_device_rtc_service_get_type ())
#define FSO_GSM_DEVICE_RTC_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_DEVICE_RTC_SERVICE, FsoGsmDeviceRtcService))
#define FSO_GSM_DEVICE_RTC_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_DEVICE_RTC_SERVICE, FsoGsmDeviceRtcServiceClass))
#define FSO_GSM_IS_DEVICE_RTC_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_DEVICE_RTC_SERVICE))
#define FSO_GSM_IS_DEVICE_RTC_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_DEVICE_RTC_SERVICE))
#define FSO_GSM_DEVICE_RTC_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_DEVICE_RTC_SERVICE, FsoGsmDeviceRtcServiceClass))

typedef struct _FsoGsmDeviceRtcService FsoGsmDeviceRtcService;
typedef struct _FsoGsmDeviceRtcServiceClass FsoGsmDeviceRtcServiceClass;
typedef struct _FsoGsmDeviceRtcServicePrivate FsoGsmDeviceRtcServicePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _FsoGsmDeviceRtcServiceGetCurrentTimeData FsoGsmDeviceRtcServiceGetCurrentTimeData;
typedef struct _FsoGsmDeviceRtcServiceSetCurrentTimeData FsoGsmDeviceRtcServiceSetCurrentTimeData;
typedef struct _FsoGsmDeviceRtcServiceGetWakeupTimeData FsoGsmDeviceRtcServiceGetWakeupTimeData;
typedef struct _FsoGsmDeviceRtcServiceSetWakeupTimeData FsoGsmDeviceRtcServiceSetWakeupTimeData;

struct _FsoGsmService {
	FsoFrameworkAbstractObject parent_instance;
	FsoGsmServicePrivate * priv;
	FsoGsmModem* modem;
};

struct _FsoGsmServiceClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _FsoGsmDeviceRtcService {
	FsoGsmService parent_instance;
	FsoGsmDeviceRtcServicePrivate * priv;
};

struct _FsoGsmDeviceRtcServiceClass {
	FsoGsmServiceClass parent_class;
};

struct _FsoGsmDeviceRtcServiceGetCurrentTimeData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmDeviceRtcService* self;
	gint result;
	FsoGsmModem* _tmp0_;
	gpointer _tmp1_;
	FsoGsmDeviceGetCurrentTime* m;
	FsoGsmDeviceGetCurrentTime* _tmp2_;
	GError* e;
	GError* _tmp3_;
	const gchar* _tmp4_;
	GError* _tmp5_;
	FsoGsmDeviceGetCurrentTime* _tmp6_;
	gint _tmp7_;
	gint _tmp8_;
	GError * _inner_error_;
};

struct _FsoGsmDeviceRtcServiceSetCurrentTimeData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmDeviceRtcService* self;
	gint seconds_since_epoch;
	FsoGsmModem* _tmp0_;
	gpointer _tmp1_;
	FsoGsmDeviceSetCurrentTime* m;
	FsoGsmDeviceSetCurrentTime* _tmp2_;
	gint _tmp3_;
	GError* e;
	GError* _tmp4_;
	const gchar* _tmp5_;
	GError* _tmp6_;
	GError * _inner_error_;
};

struct _FsoGsmDeviceRtcServiceGetWakeupTimeData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmDeviceRtcService* self;
	gint result;
	FsoGsmModem* _tmp0_;
	gpointer _tmp1_;
	FsoGsmDeviceGetAlarmTime* m;
	FsoGsmDeviceGetAlarmTime* _tmp2_;
	GError* e;
	GError* _tmp3_;
	const gchar* _tmp4_;
	GError* _tmp5_;
	FsoGsmDeviceGetAlarmTime* _tmp6_;
	gint _tmp7_;
	gint _tmp8_;
	GError * _inner_error_;
};

struct _FsoGsmDeviceRtcServiceSetWakeupTimeData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmDeviceRtcService* self;
	gint seconds_since_epoch;
	FsoGsmModem* _tmp0_;
	gpointer _tmp1_;
	FsoGsmDeviceSetAlarmTime* m;
	FsoGsmDeviceSetAlarmTime* _tmp2_;
	gint _tmp3_;
	GError* e;
	GError* _tmp4_;
	const gchar* _tmp5_;
	GError* _tmp6_;
	gint _tmp7_;
	GError * _inner_error_;
};


static gpointer fso_gsm_device_rtc_service_parent_class = NULL;
static FreeSmartphoneDeviceRealtimeClockIface* fso_gsm_device_rtc_service_free_smartphone_device_realtime_clock_parent_iface = NULL;
static GType fso_gsm_device_rtc_service_type_id = 0;

GType fso_gsm_service_get_type (void) G_GNUC_CONST;
GType fso_gsm_service_register_type (GTypeModule * module);
GType fso_gsm_device_rtc_service_get_type (void) G_GNUC_CONST;
GType fso_gsm_device_rtc_service_register_type (GTypeModule * module);
enum  {
	FSO_GSM_DEVICE_RTC_SERVICE_DUMMY_PROPERTY
};
static void fso_gsm_device_rtc_service_real_get_current_time_data_free (gpointer _data);
static void fso_gsm_device_rtc_service_real_get_current_time (FreeSmartphoneDeviceRealtimeClock* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_device_rtc_service_real_get_current_time_co (FsoGsmDeviceRtcServiceGetCurrentTimeData* _data_);
void fso_gsm_service_checkAvailability (FsoGsmService* self, FsoGsmModemStatus required, GError** error);
static void fso_gsm_device_rtc_service_get_current_time_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void fso_gsm_device_rtc_service_real_set_current_time_data_free (gpointer _data);
static void fso_gsm_device_rtc_service_real_set_current_time (FreeSmartphoneDeviceRealtimeClock* base, gint seconds_since_epoch, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_device_rtc_service_real_set_current_time_co (FsoGsmDeviceRtcServiceSetCurrentTimeData* _data_);
static void fso_gsm_device_rtc_service_set_current_time_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void fso_gsm_device_rtc_service_real_get_wakeup_time_data_free (gpointer _data);
static void fso_gsm_device_rtc_service_real_get_wakeup_time (FreeSmartphoneDeviceRealtimeClock* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_device_rtc_service_real_get_wakeup_time_co (FsoGsmDeviceRtcServiceGetWakeupTimeData* _data_);
static void fso_gsm_device_rtc_service_get_wakeup_time_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void fso_gsm_device_rtc_service_real_set_wakeup_time_data_free (gpointer _data);
static void fso_gsm_device_rtc_service_real_set_wakeup_time (FreeSmartphoneDeviceRealtimeClock* base, gint seconds_since_epoch, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_device_rtc_service_real_set_wakeup_time_co (FsoGsmDeviceRtcServiceSetWakeupTimeData* _data_);
static void fso_gsm_device_rtc_service_set_wakeup_time_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
FsoGsmDeviceRtcService* fso_gsm_device_rtc_service_new (void);
FsoGsmDeviceRtcService* fso_gsm_device_rtc_service_construct (GType object_type);
FsoGsmService* fso_gsm_service_new (void);
FsoGsmService* fso_gsm_service_construct (GType object_type);


static void fso_gsm_device_rtc_service_real_get_current_time_data_free (gpointer _data) {
	FsoGsmDeviceRtcServiceGetCurrentTimeData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmDeviceRtcServiceGetCurrentTimeData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void fso_gsm_device_rtc_service_real_get_current_time (FreeSmartphoneDeviceRealtimeClock* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmDeviceRtcService * self;
	FsoGsmDeviceRtcServiceGetCurrentTimeData* _data_;
	FsoGsmDeviceRtcService* _tmp0_;
	self = (FsoGsmDeviceRtcService*) base;
	_data_ = g_slice_new0 (FsoGsmDeviceRtcServiceGetCurrentTimeData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_device_rtc_service_real_get_current_time);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_device_rtc_service_real_get_current_time_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	fso_gsm_device_rtc_service_real_get_current_time_co (_data_);
}


static gint fso_gsm_device_rtc_service_real_get_current_time_finish (FreeSmartphoneDeviceRealtimeClock* base, GAsyncResult* _res_, GError** error) {
	gint result;
	FsoGsmDeviceRtcServiceGetCurrentTimeData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return 0;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static void fso_gsm_device_rtc_service_get_current_time_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FsoGsmDeviceRtcServiceGetCurrentTimeData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	fso_gsm_device_rtc_service_real_get_current_time_co (_data_);
}


static gboolean fso_gsm_device_rtc_service_real_get_current_time_co (FsoGsmDeviceRtcServiceGetCurrentTimeData* _data_) {
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
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	_data_->_tmp1_ = fso_gsm_modem_createMediator (_data_->_tmp0_, FSO_GSM_TYPE_DEVICE_GET_CURRENT_TIME, (GBoxedCopyFunc) g_object_ref, g_object_unref, &_data_->_inner_error_);
	_data_->m = (FsoGsmDeviceGetCurrentTime*) _data_->_tmp1_;
	if (_data_->_inner_error_ != NULL) {
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	{
		_data_->_tmp2_ = _data_->m;
		_data_->_state_ = 1;
		fso_gsm_device_get_current_time_run (_data_->_tmp2_, fso_gsm_device_rtc_service_get_current_time_ready, _data_);
		return FALSE;
		_state_1:
		fso_gsm_device_get_current_time_run_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error_);
		if (_data_->_inner_error_ != NULL) {
			if (_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) {
				goto __catch3_free_smartphone_gsm_error;
			}
			goto __finally3;
		}
	}
	goto __finally3;
	__catch3_free_smartphone_gsm_error:
	{
		_data_->e = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp3_ = _data_->e;
		_data_->_tmp4_ = _data_->_tmp3_->message;
		_data_->_tmp5_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_SYSTEM_ERROR, _data_->_tmp4_);
		_data_->_inner_error_ = _data_->_tmp5_;
		_g_error_free0 (_data_->e);
		goto __finally3;
	}
	__finally3:
	if (_data_->_inner_error_ != NULL) {
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	_data_->_tmp7_ = fso_gsm_device_get_current_time_get_since_epoch (_data_->_tmp6_);
	_data_->_tmp8_ = _data_->_tmp7_;
	_data_->result = _data_->_tmp8_;
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


static void fso_gsm_device_rtc_service_real_set_current_time_data_free (gpointer _data) {
	FsoGsmDeviceRtcServiceSetCurrentTimeData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmDeviceRtcServiceSetCurrentTimeData, _data_);
}


static void fso_gsm_device_rtc_service_real_set_current_time (FreeSmartphoneDeviceRealtimeClock* base, gint seconds_since_epoch, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmDeviceRtcService * self;
	FsoGsmDeviceRtcServiceSetCurrentTimeData* _data_;
	FsoGsmDeviceRtcService* _tmp0_;
	gint _tmp1_;
	self = (FsoGsmDeviceRtcService*) base;
	_data_ = g_slice_new0 (FsoGsmDeviceRtcServiceSetCurrentTimeData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_device_rtc_service_real_set_current_time);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_device_rtc_service_real_set_current_time_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = seconds_since_epoch;
	_data_->seconds_since_epoch = _tmp1_;
	fso_gsm_device_rtc_service_real_set_current_time_co (_data_);
}


static void fso_gsm_device_rtc_service_real_set_current_time_finish (FreeSmartphoneDeviceRealtimeClock* base, GAsyncResult* _res_, GError** error) {
	FsoGsmDeviceRtcServiceSetCurrentTimeData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void fso_gsm_device_rtc_service_set_current_time_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FsoGsmDeviceRtcServiceSetCurrentTimeData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	fso_gsm_device_rtc_service_real_set_current_time_co (_data_);
}


static gboolean fso_gsm_device_rtc_service_real_set_current_time_co (FsoGsmDeviceRtcServiceSetCurrentTimeData* _data_) {
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
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	_data_->_tmp1_ = fso_gsm_modem_createMediator (_data_->_tmp0_, FSO_GSM_TYPE_DEVICE_SET_CURRENT_TIME, (GBoxedCopyFunc) g_object_ref, g_object_unref, &_data_->_inner_error_);
	_data_->m = (FsoGsmDeviceSetCurrentTime*) _data_->_tmp1_;
	if (_data_->_inner_error_ != NULL) {
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	{
		_data_->_tmp2_ = _data_->m;
		_data_->_tmp3_ = _data_->seconds_since_epoch;
		_data_->_state_ = 1;
		fso_gsm_device_set_current_time_run (_data_->_tmp2_, _data_->_tmp3_, fso_gsm_device_rtc_service_set_current_time_ready, _data_);
		return FALSE;
		_state_1:
		fso_gsm_device_set_current_time_run_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error_);
		if (_data_->_inner_error_ != NULL) {
			if (_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) {
				goto __catch4_free_smartphone_gsm_error;
			}
			goto __finally4;
		}
	}
	goto __finally4;
	__catch4_free_smartphone_gsm_error:
	{
		_data_->e = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp4_ = _data_->e;
		_data_->_tmp5_ = _data_->_tmp4_->message;
		_data_->_tmp6_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_SYSTEM_ERROR, _data_->_tmp5_);
		_data_->_inner_error_ = _data_->_tmp6_;
		_g_error_free0 (_data_->e);
		goto __finally4;
	}
	__finally4:
	if (_data_->_inner_error_ != NULL) {
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	_g_object_unref0 (_data_->m);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void fso_gsm_device_rtc_service_real_get_wakeup_time_data_free (gpointer _data) {
	FsoGsmDeviceRtcServiceGetWakeupTimeData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmDeviceRtcServiceGetWakeupTimeData, _data_);
}


static void fso_gsm_device_rtc_service_real_get_wakeup_time (FreeSmartphoneDeviceRealtimeClock* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmDeviceRtcService * self;
	FsoGsmDeviceRtcServiceGetWakeupTimeData* _data_;
	FsoGsmDeviceRtcService* _tmp0_;
	self = (FsoGsmDeviceRtcService*) base;
	_data_ = g_slice_new0 (FsoGsmDeviceRtcServiceGetWakeupTimeData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_device_rtc_service_real_get_wakeup_time);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_device_rtc_service_real_get_wakeup_time_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	fso_gsm_device_rtc_service_real_get_wakeup_time_co (_data_);
}


static gint fso_gsm_device_rtc_service_real_get_wakeup_time_finish (FreeSmartphoneDeviceRealtimeClock* base, GAsyncResult* _res_, GError** error) {
	gint result;
	FsoGsmDeviceRtcServiceGetWakeupTimeData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return 0;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static void fso_gsm_device_rtc_service_get_wakeup_time_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FsoGsmDeviceRtcServiceGetWakeupTimeData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	fso_gsm_device_rtc_service_real_get_wakeup_time_co (_data_);
}


static gboolean fso_gsm_device_rtc_service_real_get_wakeup_time_co (FsoGsmDeviceRtcServiceGetWakeupTimeData* _data_) {
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
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	_data_->_tmp1_ = fso_gsm_modem_createMediator (_data_->_tmp0_, FSO_GSM_TYPE_DEVICE_GET_ALARM_TIME, (GBoxedCopyFunc) g_object_ref, g_object_unref, &_data_->_inner_error_);
	_data_->m = (FsoGsmDeviceGetAlarmTime*) _data_->_tmp1_;
	if (_data_->_inner_error_ != NULL) {
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	{
		_data_->_tmp2_ = _data_->m;
		_data_->_state_ = 1;
		fso_gsm_device_get_alarm_time_run (_data_->_tmp2_, fso_gsm_device_rtc_service_get_wakeup_time_ready, _data_);
		return FALSE;
		_state_1:
		fso_gsm_device_get_alarm_time_run_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error_);
		if (_data_->_inner_error_ != NULL) {
			if (_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) {
				goto __catch5_free_smartphone_gsm_error;
			}
			goto __finally5;
		}
	}
	goto __finally5;
	__catch5_free_smartphone_gsm_error:
	{
		_data_->e = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp3_ = _data_->e;
		_data_->_tmp4_ = _data_->_tmp3_->message;
		_data_->_tmp5_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_SYSTEM_ERROR, _data_->_tmp4_);
		_data_->_inner_error_ = _data_->_tmp5_;
		_g_error_free0 (_data_->e);
		goto __finally5;
	}
	__finally5:
	if (_data_->_inner_error_ != NULL) {
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	_data_->_tmp7_ = fso_gsm_device_get_alarm_time_get_since_epoch (_data_->_tmp6_);
	_data_->_tmp8_ = _data_->_tmp7_;
	_data_->result = _data_->_tmp8_;
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


static void fso_gsm_device_rtc_service_real_set_wakeup_time_data_free (gpointer _data) {
	FsoGsmDeviceRtcServiceSetWakeupTimeData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmDeviceRtcServiceSetWakeupTimeData, _data_);
}


static void fso_gsm_device_rtc_service_real_set_wakeup_time (FreeSmartphoneDeviceRealtimeClock* base, gint seconds_since_epoch, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmDeviceRtcService * self;
	FsoGsmDeviceRtcServiceSetWakeupTimeData* _data_;
	FsoGsmDeviceRtcService* _tmp0_;
	gint _tmp1_;
	self = (FsoGsmDeviceRtcService*) base;
	_data_ = g_slice_new0 (FsoGsmDeviceRtcServiceSetWakeupTimeData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_device_rtc_service_real_set_wakeup_time);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_device_rtc_service_real_set_wakeup_time_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = seconds_since_epoch;
	_data_->seconds_since_epoch = _tmp1_;
	fso_gsm_device_rtc_service_real_set_wakeup_time_co (_data_);
}


static void fso_gsm_device_rtc_service_real_set_wakeup_time_finish (FreeSmartphoneDeviceRealtimeClock* base, GAsyncResult* _res_, GError** error) {
	FsoGsmDeviceRtcServiceSetWakeupTimeData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void fso_gsm_device_rtc_service_set_wakeup_time_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FsoGsmDeviceRtcServiceSetWakeupTimeData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	fso_gsm_device_rtc_service_real_set_wakeup_time_co (_data_);
}


static gboolean fso_gsm_device_rtc_service_real_set_wakeup_time_co (FsoGsmDeviceRtcServiceSetWakeupTimeData* _data_) {
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
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	_data_->_tmp1_ = fso_gsm_modem_createMediator (_data_->_tmp0_, FSO_GSM_TYPE_DEVICE_SET_ALARM_TIME, (GBoxedCopyFunc) g_object_ref, g_object_unref, &_data_->_inner_error_);
	_data_->m = (FsoGsmDeviceSetAlarmTime*) _data_->_tmp1_;
	if (_data_->_inner_error_ != NULL) {
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	{
		_data_->_tmp2_ = _data_->m;
		_data_->_tmp3_ = _data_->seconds_since_epoch;
		_data_->_state_ = 1;
		fso_gsm_device_set_alarm_time_run (_data_->_tmp2_, _data_->_tmp3_, fso_gsm_device_rtc_service_set_wakeup_time_ready, _data_);
		return FALSE;
		_state_1:
		fso_gsm_device_set_alarm_time_run_finish (_data_->_tmp2_, _data_->_res_, &_data_->_inner_error_);
		if (_data_->_inner_error_ != NULL) {
			if (_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) {
				goto __catch6_free_smartphone_gsm_error;
			}
			goto __finally6;
		}
	}
	goto __finally6;
	__catch6_free_smartphone_gsm_error:
	{
		_data_->e = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp4_ = _data_->e;
		_data_->_tmp5_ = _data_->_tmp4_->message;
		_data_->_tmp6_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_SYSTEM_ERROR, _data_->_tmp5_);
		_data_->_inner_error_ = _data_->_tmp6_;
		_g_error_free0 (_data_->e);
		goto __finally6;
	}
	__finally6:
	if (_data_->_inner_error_ != NULL) {
		if (((_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) || (_data_->_inner_error_->domain == G_DBUS_ERROR)) || (_data_->_inner_error_->domain == G_IO_ERROR)) {
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
	_data_->_tmp7_ = _data_->seconds_since_epoch;
	g_signal_emit_by_name ((FreeSmartphoneDeviceRealtimeClock*) _data_->self, "wakeup-time-changed", _data_->_tmp7_);
	_g_object_unref0 (_data_->m);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


FsoGsmDeviceRtcService* fso_gsm_device_rtc_service_construct (GType object_type) {
	FsoGsmDeviceRtcService * self = NULL;
	self = (FsoGsmDeviceRtcService*) fso_gsm_service_construct (object_type);
	return self;
}


FsoGsmDeviceRtcService* fso_gsm_device_rtc_service_new (void) {
	return fso_gsm_device_rtc_service_construct (FSO_GSM_TYPE_DEVICE_RTC_SERVICE);
}


static void fso_gsm_device_rtc_service_class_init (FsoGsmDeviceRtcServiceClass * klass) {
	fso_gsm_device_rtc_service_parent_class = g_type_class_peek_parent (klass);
}


static void fso_gsm_device_rtc_service_free_smartphone_device_realtime_clock_interface_init (FreeSmartphoneDeviceRealtimeClockIface * iface) {
	fso_gsm_device_rtc_service_free_smartphone_device_realtime_clock_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_current_time = (gint (*)(FreeSmartphoneDeviceRealtimeClock*, GError**)) fso_gsm_device_rtc_service_real_get_current_time;
	iface->get_current_time_finish = fso_gsm_device_rtc_service_real_get_current_time_finish;
	iface->set_current_time = (void (*)(FreeSmartphoneDeviceRealtimeClock*, gint, GError**)) fso_gsm_device_rtc_service_real_set_current_time;
	iface->set_current_time_finish = fso_gsm_device_rtc_service_real_set_current_time_finish;
	iface->get_wakeup_time = (gint (*)(FreeSmartphoneDeviceRealtimeClock*, GError**)) fso_gsm_device_rtc_service_real_get_wakeup_time;
	iface->get_wakeup_time_finish = fso_gsm_device_rtc_service_real_get_wakeup_time_finish;
	iface->set_wakeup_time = (void (*)(FreeSmartphoneDeviceRealtimeClock*, gint, GError**)) fso_gsm_device_rtc_service_real_set_wakeup_time;
	iface->set_wakeup_time_finish = fso_gsm_device_rtc_service_real_set_wakeup_time_finish;
}


static void fso_gsm_device_rtc_service_instance_init (FsoGsmDeviceRtcService * self) {
}


GType fso_gsm_device_rtc_service_get_type (void) {
	return fso_gsm_device_rtc_service_type_id;
}


GType fso_gsm_device_rtc_service_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (FsoGsmDeviceRtcServiceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_gsm_device_rtc_service_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoGsmDeviceRtcService), 0, (GInstanceInitFunc) fso_gsm_device_rtc_service_instance_init, NULL };
	static const GInterfaceInfo free_smartphone_device_realtime_clock_info = { (GInterfaceInitFunc) fso_gsm_device_rtc_service_free_smartphone_device_realtime_clock_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	fso_gsm_device_rtc_service_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_SERVICE, "FsoGsmDeviceRtcService", &g_define_type_info, 0);
	g_type_module_add_interface (module, fso_gsm_device_rtc_service_type_id, FREE_SMARTPHONE_DEVICE_TYPE_REALTIME_CLOCK, &free_smartphone_device_realtime_clock_info);
	return fso_gsm_device_rtc_service_type_id;
}



/* gsm_hz_service.c generated by valac 0.16.1, the Vala compiler
 * generated from gsm_hz_service.vala, do not modify */

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

#define FSO_GSM_TYPE_GSM_HZ_SERVICE (fso_gsm_gsm_hz_service_get_type ())
#define FSO_GSM_GSM_HZ_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_GSM_HZ_SERVICE, FsoGsmGsmHzService))
#define FSO_GSM_GSM_HZ_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_GSM_HZ_SERVICE, FsoGsmGsmHzServiceClass))
#define FSO_GSM_IS_GSM_HZ_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_GSM_HZ_SERVICE))
#define FSO_GSM_IS_GSM_HZ_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_GSM_HZ_SERVICE))
#define FSO_GSM_GSM_HZ_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_GSM_HZ_SERVICE, FsoGsmGsmHzServiceClass))

typedef struct _FsoGsmGsmHzService FsoGsmGsmHzService;
typedef struct _FsoGsmGsmHzServiceClass FsoGsmGsmHzServiceClass;
typedef struct _FsoGsmGsmHzServicePrivate FsoGsmGsmHzServicePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _FsoGsmGsmHzServiceGetHomeZoneStatusData FsoGsmGsmHzServiceGetHomeZoneStatusData;
typedef struct _FsoGsmGsmHzServiceGetKnownHomeZonesData FsoGsmGsmHzServiceGetKnownHomeZonesData;

struct _FsoGsmService {
	FsoFrameworkAbstractObject parent_instance;
	FsoGsmServicePrivate * priv;
	FsoGsmModem* modem;
};

struct _FsoGsmServiceClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _FsoGsmGsmHzService {
	FsoGsmService parent_instance;
	FsoGsmGsmHzServicePrivate * priv;
};

struct _FsoGsmGsmHzServiceClass {
	FsoGsmServiceClass parent_class;
};

struct _FsoGsmGsmHzServiceGetHomeZoneStatusData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmGsmHzService* self;
	gchar* result;
	GError* _tmp0_;
	GError * _inner_error_;
};

struct _FsoGsmGsmHzServiceGetKnownHomeZonesData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FsoGsmGsmHzService* self;
	gchar** result;
	gint result_length1;
	GError* _tmp0_;
	GError * _inner_error_;
};


static gpointer fso_gsm_gsm_hz_service_parent_class = NULL;
static FreeSmartphoneGSMHZIface* fso_gsm_gsm_hz_service_free_smartphone_gsm_hz_parent_iface = NULL;
static GType fso_gsm_gsm_hz_service_type_id = 0;

GType fso_gsm_service_get_type (void) G_GNUC_CONST;
GType fso_gsm_service_register_type (GTypeModule * module);
GType fso_gsm_gsm_hz_service_get_type (void) G_GNUC_CONST;
GType fso_gsm_gsm_hz_service_register_type (GTypeModule * module);
enum  {
	FSO_GSM_GSM_HZ_SERVICE_DUMMY_PROPERTY
};
static void fso_gsm_gsm_hz_service_real_get_home_zone_status_data_free (gpointer _data);
static void fso_gsm_gsm_hz_service_real_get_home_zone_status (FreeSmartphoneGSMHZ* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_gsm_hz_service_real_get_home_zone_status_co (FsoGsmGsmHzServiceGetHomeZoneStatusData* _data_);
void fso_gsm_service_checkAvailability (FsoGsmService* self, FsoGsmModemStatus required, GError** error);
static void fso_gsm_gsm_hz_service_real_get_known_home_zones_data_free (gpointer _data);
static void fso_gsm_gsm_hz_service_real_get_known_home_zones (FreeSmartphoneGSMHZ* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean fso_gsm_gsm_hz_service_real_get_known_home_zones_co (FsoGsmGsmHzServiceGetKnownHomeZonesData* _data_);
FsoGsmGsmHzService* fso_gsm_gsm_hz_service_new (void);
FsoGsmGsmHzService* fso_gsm_gsm_hz_service_construct (GType object_type);
FsoGsmService* fso_gsm_service_new (void);
FsoGsmService* fso_gsm_service_construct (GType object_type);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static void fso_gsm_gsm_hz_service_real_get_home_zone_status_data_free (gpointer _data) {
	FsoGsmGsmHzServiceGetHomeZoneStatusData* _data_;
	_data_ = _data;
	_g_free0 (_data_->result);
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmGsmHzServiceGetHomeZoneStatusData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void fso_gsm_gsm_hz_service_real_get_home_zone_status (FreeSmartphoneGSMHZ* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmGsmHzService * self;
	FsoGsmGsmHzServiceGetHomeZoneStatusData* _data_;
	FsoGsmGsmHzService* _tmp0_;
	self = (FsoGsmGsmHzService*) base;
	_data_ = g_slice_new0 (FsoGsmGsmHzServiceGetHomeZoneStatusData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_gsm_hz_service_real_get_home_zone_status);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_gsm_hz_service_real_get_home_zone_status_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	fso_gsm_gsm_hz_service_real_get_home_zone_status_co (_data_);
}


static gchar* fso_gsm_gsm_hz_service_real_get_home_zone_status_finish (FreeSmartphoneGSMHZ* base, GAsyncResult* _res_, GError** error) {
	gchar* result;
	FsoGsmGsmHzServiceGetHomeZoneStatusData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static gboolean fso_gsm_gsm_hz_service_real_get_home_zone_status_co (FsoGsmGsmHzServiceGetHomeZoneStatusData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
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
	_data_->_tmp0_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "Not yet implemented");
	_data_->_inner_error_ = _data_->_tmp0_;
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
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void fso_gsm_gsm_hz_service_real_get_known_home_zones_data_free (gpointer _data) {
	FsoGsmGsmHzServiceGetKnownHomeZonesData* _data_;
	_data_ = _data;
	_data_->result = (_vala_array_free (_data_->result, _data_->result_length1, (GDestroyNotify) g_free), NULL);
	_g_object_unref0 (_data_->self);
	g_slice_free (FsoGsmGsmHzServiceGetKnownHomeZonesData, _data_);
}


static void fso_gsm_gsm_hz_service_real_get_known_home_zones (FreeSmartphoneGSMHZ* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsoGsmGsmHzService * self;
	FsoGsmGsmHzServiceGetKnownHomeZonesData* _data_;
	FsoGsmGsmHzService* _tmp0_;
	self = (FsoGsmGsmHzService*) base;
	_data_ = g_slice_new0 (FsoGsmGsmHzServiceGetKnownHomeZonesData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fso_gsm_gsm_hz_service_real_get_known_home_zones);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fso_gsm_gsm_hz_service_real_get_known_home_zones_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	fso_gsm_gsm_hz_service_real_get_known_home_zones_co (_data_);
}


static gchar** fso_gsm_gsm_hz_service_real_get_known_home_zones_finish (FreeSmartphoneGSMHZ* base, GAsyncResult* _res_, int* result_length1, GError** error) {
	gchar** result;
	FsoGsmGsmHzServiceGetKnownHomeZonesData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	*result_length1 = _data_->result_length1;
	_data_->result = NULL;
	return result;
}


static gboolean fso_gsm_gsm_hz_service_real_get_known_home_zones_co (FsoGsmGsmHzServiceGetKnownHomeZonesData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
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
	_data_->_tmp0_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "Not yet implemented");
	_data_->_inner_error_ = _data_->_tmp0_;
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
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


FsoGsmGsmHzService* fso_gsm_gsm_hz_service_construct (GType object_type) {
	FsoGsmGsmHzService * self = NULL;
	self = (FsoGsmGsmHzService*) fso_gsm_service_construct (object_type);
	return self;
}


FsoGsmGsmHzService* fso_gsm_gsm_hz_service_new (void) {
	return fso_gsm_gsm_hz_service_construct (FSO_GSM_TYPE_GSM_HZ_SERVICE);
}


static void fso_gsm_gsm_hz_service_class_init (FsoGsmGsmHzServiceClass * klass) {
	fso_gsm_gsm_hz_service_parent_class = g_type_class_peek_parent (klass);
}


static void fso_gsm_gsm_hz_service_free_smartphone_gsm_hz_interface_init (FreeSmartphoneGSMHZIface * iface) {
	fso_gsm_gsm_hz_service_free_smartphone_gsm_hz_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_home_zone_status = (gchar* (*)(FreeSmartphoneGSMHZ*, GError**)) fso_gsm_gsm_hz_service_real_get_home_zone_status;
	iface->get_home_zone_status_finish = fso_gsm_gsm_hz_service_real_get_home_zone_status_finish;
	iface->get_known_home_zones = (gchar** (*)(FreeSmartphoneGSMHZ*, int*, GError**)) fso_gsm_gsm_hz_service_real_get_known_home_zones;
	iface->get_known_home_zones_finish = fso_gsm_gsm_hz_service_real_get_known_home_zones_finish;
}


static void fso_gsm_gsm_hz_service_instance_init (FsoGsmGsmHzService * self) {
}


GType fso_gsm_gsm_hz_service_get_type (void) {
	return fso_gsm_gsm_hz_service_type_id;
}


GType fso_gsm_gsm_hz_service_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (FsoGsmGsmHzServiceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_gsm_gsm_hz_service_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoGsmGsmHzService), 0, (GInstanceInitFunc) fso_gsm_gsm_hz_service_instance_init, NULL };
	static const GInterfaceInfo free_smartphone_gsm_hz_info = { (GInterfaceInitFunc) fso_gsm_gsm_hz_service_free_smartphone_gsm_hz_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	fso_gsm_gsm_hz_service_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_SERVICE, "FsoGsmGsmHzService", &g_define_type_info, 0);
	g_type_module_add_interface (module, fso_gsm_gsm_hz_service_type_id, FREE_SMARTPHONE_GSM_TYPE_HZ, &free_smartphone_gsm_hz_info);
	return fso_gsm_gsm_hz_service_type_id;
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




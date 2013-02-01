/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

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
#include <fsogsm.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <freesmartphone.h>
#include <fsobasics.h>
#include <gisicomm.h>
#include <fsoframework.h>


#define PDP_TYPE_NOKIA_ISI (pdp_nokia_isi_get_type ())
#define PDP_NOKIA_ISI(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDP_TYPE_NOKIA_ISI, PdpNokiaIsi))
#define PDP_NOKIA_ISI_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDP_TYPE_NOKIA_ISI, PdpNokiaIsiClass))
#define PDP_IS_NOKIA_ISI(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDP_TYPE_NOKIA_ISI))
#define PDP_IS_NOKIA_ISI_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDP_TYPE_NOKIA_ISI))
#define PDP_NOKIA_ISI_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDP_TYPE_NOKIA_ISI, PdpNokiaIsiClass))

typedef struct _PdpNokiaIsi PdpNokiaIsi;
typedef struct _PdpNokiaIsiClass PdpNokiaIsiClass;
typedef struct _PdpNokiaIsiPrivate PdpNokiaIsiPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _gisi_comm_modem_access_unref0(var) ((var == NULL) ? NULL : (var = (gisi_comm_modem_access_unref (var), NULL)))
typedef struct _PdpNokiaIsiScActivateData PdpNokiaIsiScActivateData;
typedef struct _PdpNokiaIsiScDeactivateData PdpNokiaIsiScDeactivateData;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
typedef struct _pdp_nokia_isi_statusUpdateData pdp_nokia_isi_statusUpdateData;
#define _fso_gsm_route_info_unref0(var) ((var == NULL) ? NULL : (var = (fso_gsm_route_info_unref (var), NULL)))

struct _PdpNokiaIsi {
	FsoGsmPdpHandler parent_instance;
	PdpNokiaIsiPrivate * priv;
};

struct _PdpNokiaIsiClass {
	FsoGsmPdpHandlerClass parent_class;
};

struct _PdpNokiaIsiScActivateData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PdpNokiaIsi* self;
	FsoGsmModem* _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoGsmModemData* _tmp2_;
	FsoGsmModemData* data;
	void* _tmp3_;
	GIsiCommModemAccess* _tmp4_;
	GIsiCommModemAccess* isimodem;
	GIsiCommModemAccess* _tmp5_;
	GIsiCommGPDS* _tmp6_;
	GIsiCommModemAccess* _tmp7_;
	GIsiCommGPDS* _tmp8_;
	FsoGsmModemData* _tmp9_;
	FsoGsmContextParams* _tmp10_;
	GError* _tmp11_;
	FsoGsmModemData* _tmp12_;
	FsoGsmContextParams* _tmp13_;
	const gchar* _tmp14_;
	GError* _tmp15_;
	GIsiCommModemAccess* _tmp16_;
	GIsiCommGPDS* _tmp17_;
	FsoGsmModemData* _tmp18_;
	FsoGsmContextParams* _tmp19_;
	const gchar* _tmp20_;
	FsoGsmModemData* _tmp21_;
	FsoGsmContextParams* _tmp22_;
	const gchar* _tmp23_;
	FsoGsmModemData* _tmp24_;
	FsoGsmContextParams* _tmp25_;
	const gchar* _tmp26_;
	GError * _inner_error_;
};

struct _PdpNokiaIsiScDeactivateData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PdpNokiaIsi* self;
	void* _tmp0_;
	GIsiCommModemAccess* _tmp1_;
	GIsiCommModemAccess* isimodem;
	GIsiCommGPDS* _tmp2_;
};

struct _pdp_nokia_isi_statusUpdateData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	PdpNokiaIsi* self;
	gchar* status;
	GHashTable* properties;
};


static gpointer pdp_nokia_isi_parent_class = NULL;
static GType pdp_nokia_isi_type_id = 0;

GType pdp_nokia_isi_get_type (void) G_GNUC_CONST;
GType pdp_nokia_isi_register_type (GTypeModule * module);
enum  {
	PDP_NOKIA_ISI_DUMMY_PROPERTY
};
#define PDP_NOKIA_ISI_MODULE_NAME "fsogsm.pdp_nokia_isi"
static gchar* pdp_nokia_isi_real_repr (FsoFrameworkAbstractObject* base);
static void pdp_nokia_isi_real_sc_activate_data_free (gpointer _data);
static void pdp_nokia_isi_real_sc_activate (FsoGsmPdpHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean pdp_nokia_isi_real_sc_activate_co (PdpNokiaIsiScActivateData* _data_);
static void pdp_nokia_isi_onContextActivated (PdpNokiaIsi* self, const gchar* iface, const gchar* ip, const gchar* dns1, const gchar* dns2);
static void _pdp_nokia_isi_onContextActivated_gisi_comm_gpds_context_activated (GIsiCommGPDS* _sender, const gchar* iface, const gchar* ip, const gchar* dns1, const gchar* dns2, gpointer self);
static void pdp_nokia_isi_onContextDeactivated (PdpNokiaIsi* self);
static void _pdp_nokia_isi_onContextDeactivated_gisi_comm_gpds_context_deactivated (GIsiCommGPDS* _sender, gpointer self);
static void __lambda2_ (PdpNokiaIsi* self, GIsiCommErrorCode err);
static void ___lambda2__gisi_comm_void_result_func (GIsiCommErrorCode _error_, gpointer self);
static void pdp_nokia_isi_real_sc_deactivate_data_free (gpointer _data);
static void pdp_nokia_isi_real_sc_deactivate (FsoGsmPdpHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean pdp_nokia_isi_real_sc_deactivate_co (PdpNokiaIsiScDeactivateData* _data_);
static void pdp_nokia_isi_real_statusUpdate_data_free (gpointer _data);
static void pdp_nokia_isi_real_statusUpdate (FsoGsmPdpHandler* base, const gchar* status, GHashTable* properties, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean pdp_nokia_isi_real_statusUpdate_co (pdp_nokia_isi_statusUpdateData* _data_);
PdpNokiaIsi* pdp_nokia_isi_new (void);
PdpNokiaIsi* pdp_nokia_isi_construct (GType object_type);
static GObject * pdp_nokia_isi_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static gchar* pdp_nokia_isi_real_repr (FsoFrameworkAbstractObject* base) {
	PdpNokiaIsi * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (PdpNokiaIsi*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void pdp_nokia_isi_real_sc_activate_data_free (gpointer _data) {
	PdpNokiaIsiScActivateData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (PdpNokiaIsiScActivateData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void pdp_nokia_isi_real_sc_activate (FsoGsmPdpHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PdpNokiaIsi * self;
	PdpNokiaIsiScActivateData* _data_;
	PdpNokiaIsi* _tmp0_;
	self = (PdpNokiaIsi*) base;
	_data_ = g_slice_new0 (PdpNokiaIsiScActivateData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, pdp_nokia_isi_real_sc_activate);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, pdp_nokia_isi_real_sc_activate_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	pdp_nokia_isi_real_sc_activate_co (_data_);
}


static void pdp_nokia_isi_real_sc_activate_finish (FsoGsmPdpHandler* base, GAsyncResult* _res_, GError** error) {
	PdpNokiaIsiScActivateData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gpointer _gisi_comm_modem_access_ref0 (gpointer self) {
	return self ? gisi_comm_modem_access_ref (self) : NULL;
}


static void _pdp_nokia_isi_onContextActivated_gisi_comm_gpds_context_activated (GIsiCommGPDS* _sender, const gchar* iface, const gchar* ip, const gchar* dns1, const gchar* dns2, gpointer self) {
	pdp_nokia_isi_onContextActivated (self, iface, ip, dns1, dns2);
}


static void _pdp_nokia_isi_onContextDeactivated_gisi_comm_gpds_context_deactivated (GIsiCommGPDS* _sender, gpointer self) {
	pdp_nokia_isi_onContextDeactivated (self);
}


static void __lambda2_ (PdpNokiaIsi* self, GIsiCommErrorCode err) {
	GIsiCommErrorCode _tmp0_;
	GError * _inner_error_ = NULL;
	_tmp0_ = err;
	if (_tmp0_ != GISI_COMM_ERROR_CODE_OK) {
		GError* _tmp1_;
		_tmp1_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "Failed to activate the GPRS context");
		_inner_error_ = _tmp1_;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void ___lambda2__gisi_comm_void_result_func (GIsiCommErrorCode _error_, gpointer self) {
	__lambda2_ (self, _error_);
}


static gboolean pdp_nokia_isi_real_sc_activate_co (PdpNokiaIsiScActivateData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_pdp_handler_get_modem ((FsoGsmPdpHandler*) _data_->self);
	_data_->_tmp1_ = _data_->_tmp0_;
	_data_->_tmp2_ = NULL;
	_data_->_tmp2_ = fso_gsm_modem_data (_data_->_tmp1_);
	_data_->data = _data_->_tmp2_;
	_data_->_tmp3_ = NULL;
	_data_->_tmp3_ = fso_framework_data_sharing_valueForKey ("NokiaIsi.isimodem");
	_data_->_tmp4_ = _gisi_comm_modem_access_ref0 (GISI_COMM_IS_MODEM_ACCESS (_data_->_tmp3_) ? ((GIsiCommModemAccess*) _data_->_tmp3_) : NULL);
	_data_->isimodem = _data_->_tmp4_;
	_data_->_tmp5_ = _data_->isimodem;
	_data_->_tmp6_ = _data_->_tmp5_->gpds;
	g_signal_connect_object (_data_->_tmp6_, "context-activated", (GCallback) _pdp_nokia_isi_onContextActivated_gisi_comm_gpds_context_activated, _data_->self, 0);
	_data_->_tmp7_ = _data_->isimodem;
	_data_->_tmp8_ = _data_->_tmp7_->gpds;
	g_signal_connect_object (_data_->_tmp8_, "context-deactivated", (GCallback) _pdp_nokia_isi_onContextDeactivated_gisi_comm_gpds_context_deactivated, _data_->self, 0);
	_data_->_tmp9_ = _data_->data;
	_data_->_tmp10_ = _data_->_tmp9_->contextParams;
	if (_data_->_tmp10_ == NULL) {
		_data_->_tmp11_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "Context parameters not set");
		_data_->_inner_error_ = _data_->_tmp11_;
		if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_gisi_comm_modem_access_unref0 (_data_->isimodem);
			_g_object_unref0 (_data_->data);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_gisi_comm_modem_access_unref0 (_data_->isimodem);
			_g_object_unref0 (_data_->data);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp12_ = _data_->data;
	_data_->_tmp13_ = _data_->_tmp12_->contextParams;
	_data_->_tmp14_ = _data_->_tmp13_->apn;
	if (_data_->_tmp14_ == NULL) {
		_data_->_tmp15_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "APN not set");
		_data_->_inner_error_ = _data_->_tmp15_;
		if ((_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) || (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR)) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_gisi_comm_modem_access_unref0 (_data_->isimodem);
			_g_object_unref0 (_data_->data);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_gisi_comm_modem_access_unref0 (_data_->isimodem);
			_g_object_unref0 (_data_->data);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_data_->_tmp16_ = _data_->isimodem;
	_data_->_tmp17_ = _data_->_tmp16_->gpds;
	_data_->_tmp18_ = _data_->data;
	_data_->_tmp19_ = _data_->_tmp18_->contextParams;
	_data_->_tmp20_ = _data_->_tmp19_->apn;
	_data_->_tmp21_ = _data_->data;
	_data_->_tmp22_ = _data_->_tmp21_->contextParams;
	_data_->_tmp23_ = _data_->_tmp22_->username;
	_data_->_tmp24_ = _data_->data;
	_data_->_tmp25_ = _data_->_tmp24_->contextParams;
	_data_->_tmp26_ = _data_->_tmp25_->password;
	gisi_comm_gpds_activate (_data_->_tmp17_, _data_->_tmp20_, _data_->_tmp23_, _data_->_tmp26_, ___lambda2__gisi_comm_void_result_func, _data_->self, NULL, NULL);
	_gisi_comm_modem_access_unref0 (_data_->isimodem);
	_g_object_unref0 (_data_->data);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void pdp_nokia_isi_real_sc_deactivate_data_free (gpointer _data) {
	PdpNokiaIsiScDeactivateData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (PdpNokiaIsiScDeactivateData, _data_);
}


static void pdp_nokia_isi_real_sc_deactivate (FsoGsmPdpHandler* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PdpNokiaIsi * self;
	PdpNokiaIsiScDeactivateData* _data_;
	PdpNokiaIsi* _tmp0_;
	self = (PdpNokiaIsi*) base;
	_data_ = g_slice_new0 (PdpNokiaIsiScDeactivateData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, pdp_nokia_isi_real_sc_deactivate);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, pdp_nokia_isi_real_sc_deactivate_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	pdp_nokia_isi_real_sc_deactivate_co (_data_);
}


static void pdp_nokia_isi_real_sc_deactivate_finish (FsoGsmPdpHandler* base, GAsyncResult* _res_, GError** error) {
	PdpNokiaIsiScDeactivateData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean pdp_nokia_isi_real_sc_deactivate_co (PdpNokiaIsiScDeactivateData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = NULL;
	_data_->_tmp0_ = fso_framework_data_sharing_valueForKey ("NokiaIsi.isimodem");
	_data_->_tmp1_ = _gisi_comm_modem_access_ref0 (GISI_COMM_IS_MODEM_ACCESS (_data_->_tmp0_) ? ((GIsiCommModemAccess*) _data_->_tmp0_) : NULL);
	_data_->isimodem = _data_->_tmp1_;
	_data_->_tmp2_ = _data_->isimodem->gpds;
	gisi_comm_gpds_deactivate (_data_->_tmp2_, NULL, NULL);
	_gisi_comm_modem_access_unref0 (_data_->isimodem);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void pdp_nokia_isi_real_statusUpdate_data_free (gpointer _data) {
	pdp_nokia_isi_statusUpdateData* _data_;
	_data_ = _data;
	_g_free0 (_data_->status);
	_g_hash_table_unref0 (_data_->properties);
	_g_object_unref0 (_data_->self);
	g_slice_free (pdp_nokia_isi_statusUpdateData, _data_);
}


static gpointer _g_hash_table_ref0 (gpointer self) {
	return self ? g_hash_table_ref (self) : NULL;
}


static void pdp_nokia_isi_real_statusUpdate (FsoGsmPdpHandler* base, const gchar* status, GHashTable* properties, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	PdpNokiaIsi * self;
	pdp_nokia_isi_statusUpdateData* _data_;
	PdpNokiaIsi* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	GHashTable* _tmp3_;
	GHashTable* _tmp4_;
	self = (PdpNokiaIsi*) base;
	_data_ = g_slice_new0 (pdp_nokia_isi_statusUpdateData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, pdp_nokia_isi_real_statusUpdate);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, pdp_nokia_isi_real_statusUpdate_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = status;
	_tmp2_ = g_strdup (_tmp1_);
	_data_->status = _tmp2_;
	_tmp3_ = properties;
	_tmp4_ = _g_hash_table_ref0 (_tmp3_);
	_data_->properties = _tmp4_;
	pdp_nokia_isi_real_statusUpdate_co (_data_);
}


static void pdp_nokia_isi_real_statusUpdate_finish (FsoGsmPdpHandler* base, GAsyncResult* _res_) {
	pdp_nokia_isi_statusUpdateData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean pdp_nokia_isi_real_statusUpdate_co (pdp_nokia_isi_statusUpdateData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	g_assert_not_reached ();
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void pdp_nokia_isi_onContextActivated (PdpNokiaIsi* self, const gchar* iface, const gchar* ip, const gchar* dns1, const gchar* dns2) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	gchar* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_;
	FsoGsmRouteInfo* _tmp10_ = NULL;
	FsoGsmRouteInfo* route;
	g_return_if_fail (self != NULL);
	g_return_if_fail (iface != NULL);
	g_return_if_fail (ip != NULL);
	g_return_if_fail (dns1 != NULL);
	g_return_if_fail (dns2 != NULL);
	_tmp0_ = iface;
	_tmp1_ = g_strdup (_tmp0_);
	_tmp2_ = ip;
	_tmp3_ = g_strdup (_tmp2_);
	_tmp4_ = g_strdup ("255.255.255.255");
	_tmp5_ = g_strdup ("0.0.0.0");
	_tmp6_ = dns1;
	_tmp7_ = g_strdup (_tmp6_);
	_tmp8_ = dns2;
	_tmp9_ = g_strdup (_tmp8_);
	_tmp10_ = fso_gsm_route_info_new ();
	_g_free0 (_tmp10_->iface);
	_tmp10_->iface = _tmp1_;
	_g_free0 (_tmp10_->ipv4addr);
	_tmp10_->ipv4addr = _tmp3_;
	_g_free0 (_tmp10_->ipv4mask);
	_tmp10_->ipv4mask = _tmp4_;
	_g_free0 (_tmp10_->ipv4gateway);
	_tmp10_->ipv4gateway = _tmp5_;
	_g_free0 (_tmp10_->dns1);
	_tmp10_->dns1 = _tmp7_;
	_g_free0 (_tmp10_->dns2);
	_tmp10_->dns2 = _tmp9_;
	route = _tmp10_;
	fso_gsm_ipdp_handler_connectedWithNewDefaultRoute ((FsoGsmIPdpHandler*) self, route, NULL, NULL);
	_fso_gsm_route_info_unref0 (route);
}


static void pdp_nokia_isi_onContextDeactivated (PdpNokiaIsi* self) {
	g_return_if_fail (self != NULL);
}


PdpNokiaIsi* pdp_nokia_isi_construct (GType object_type) {
	PdpNokiaIsi * self = NULL;
	self = (PdpNokiaIsi*) fso_gsm_pdp_handler_construct (object_type);
	return self;
}


PdpNokiaIsi* pdp_nokia_isi_new (void) {
	return pdp_nokia_isi_construct (PDP_TYPE_NOKIA_ISI);
}


static GObject * pdp_nokia_isi_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	PdpNokiaIsi * self;
	parent_class = G_OBJECT_CLASS (pdp_nokia_isi_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = PDP_NOKIA_ISI (obj);
	return obj;
}


static void pdp_nokia_isi_class_init (PdpNokiaIsiClass * klass) {
	pdp_nokia_isi_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = pdp_nokia_isi_real_repr;
	FSO_GSM_PDP_HANDLER_CLASS (klass)->sc_activate = pdp_nokia_isi_real_sc_activate;
	FSO_GSM_PDP_HANDLER_CLASS (klass)->sc_activate_finish = pdp_nokia_isi_real_sc_activate_finish;
	FSO_GSM_PDP_HANDLER_CLASS (klass)->sc_deactivate = pdp_nokia_isi_real_sc_deactivate;
	FSO_GSM_PDP_HANDLER_CLASS (klass)->sc_deactivate_finish = pdp_nokia_isi_real_sc_deactivate_finish;
	FSO_GSM_PDP_HANDLER_CLASS (klass)->statusUpdate = pdp_nokia_isi_real_statusUpdate;
	FSO_GSM_PDP_HANDLER_CLASS (klass)->statusUpdate_finish = pdp_nokia_isi_real_statusUpdate_finish;
	G_OBJECT_CLASS (klass)->constructor = pdp_nokia_isi_constructor;
}


static void pdp_nokia_isi_instance_init (PdpNokiaIsi * self) {
}


/**
 * @class Pdp.Isi
 *
 * Pdp Handler implemented with the proprietary Qualcomm Management Interface protocol
 **/
GType pdp_nokia_isi_get_type (void) {
	return pdp_nokia_isi_type_id;
}


GType pdp_nokia_isi_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (PdpNokiaIsiClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pdp_nokia_isi_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PdpNokiaIsi), 0, (GInstanceInitFunc) pdp_nokia_isi_instance_init, NULL };
	pdp_nokia_isi_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_PDP_HANDLER, "PdpNokiaIsi", &g_define_type_info, 0);
	return pdp_nokia_isi_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	FsoFrameworkLogger* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = fso_framework_theLogger;
	fso_framework_logger_debug (_tmp0_, "pdp_nokia_isi fso_factory_function");
	_tmp1_ = g_strdup (PDP_NOKIA_ISI_MODULE_NAME);
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	pdp_nokia_isi_register_type (module);
}




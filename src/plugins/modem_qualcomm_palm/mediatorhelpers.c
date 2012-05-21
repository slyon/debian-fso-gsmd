/* mediatorhelpers.c generated by valac 0.14.2, the Vala compiler
 * generated from mediatorhelpers.vala, do not modify */

/*
 * Copyright (C) 2009-2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *                         Simon Busch <morphis@gravedo.de>
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
#include <stdlib.h>
#include <string.h>
#include <msmcomm-specs.h>
#include <freesmartphone.h>
#include <fsogsm.h>
#include <fsobasics.h>
#include <gio/gio.h>


#define MSM_DATA_TYPE_NETWORK_INFO (msm_data_network_info_get_type ())
typedef struct _MsmDataNetworkInfo MsmDataNetworkInfo;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _gatherSimOperatorsData gatherSimOperatorsData;
typedef struct _gatherSimStatusAndUpdateData gatherSimStatusAndUpdateData;
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
typedef struct _triggerUpdateNetworkStatusData triggerUpdateNetworkStatusData;

struct _MsmDataNetworkInfo {
	MsmcommNetworkRegistrationStatus reg_status;
	MsmcommNetworkServiceStatus service_status;
	MsmcommNetworkDataService data_service;
	gchar* operator_name;
	guint rssi;
	guint ecio;
	guint mcc;
	guint mnc;
};

struct _gatherSimOperatorsData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
};

struct _gatherSimStatusAndUpdateData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	gboolean _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoFrameworkLogger* _tmp2_;
	gboolean _tmp3_;
	FsoGsmModem* _tmp4_;
	FsoGsmModemData* _tmp5_;
	FsoGsmModemData* data;
	FsoGsmModem* _tmp6_;
	FsoFrameworkLogger* _tmp7_;
	FreeSmartphoneGSMSIMAuthStatus _tmp8_;
	GEnumValue* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	FsoGsmModem* _tmp12_;
	gpointer _tmp13_;
	FreeSmartphoneGSMSIM* obj;
	FreeSmartphoneGSMSIM* _tmp14_;
	FreeSmartphoneGSMSIMAuthStatus _tmp15_;
	FsoGsmModemData* _tmp16_;
	FreeSmartphoneGSMSIMAuthStatus _tmp17_;
	FreeSmartphoneGSMSIMAuthStatus _tmp18_;
	FsoGsmModemData* _tmp19_;
	FreeSmartphoneGSMSIMAuthStatus _tmp20_;
	FsoGsmModem* _tmp21_;
	FsoGsmModemStatus _tmp22_;
	FsoGsmModemStatus modemStatus;
	gboolean _tmp23_;
	FsoGsmModemStatus _tmp24_;
	FsoGsmModemStatus _tmp25_;
	gboolean _tmp26_;
	FreeSmartphoneGSMSIMAuthStatus _tmp27_;
	FsoGsmModem* _tmp28_;
	FsoGsmModem* _tmp29_;
};

struct _triggerUpdateNetworkStatusData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	gboolean _tmp0_;
	FsoGsmModem* _tmp1_;
	FsoFrameworkLogger* _tmp2_;
	gboolean _tmp3_;
	FsoGsmModem* _tmp4_;
	FsoGsmModemStatus _tmp5_;
	FsoGsmModemStatus mstat;
	gboolean _tmp6_;
	FsoGsmModemStatus _tmp7_;
	FsoGsmModemStatus _tmp8_;
	gboolean _tmp9_;
	FsoGsmModem* _tmp10_;
	FsoFrameworkLogger* _tmp11_;
	FsoGsmModemStatus _tmp12_;
	GEnumValue* _tmp13_;
	gchar* _tmp14_;
	gchar* _tmp15_;
	gboolean _tmp16_;
	gboolean _tmp17_;
	MsmDataNetworkInfo _tmp18_;
	MsmcommNetworkRegistrationStatus _tmp19_;
	MsmDataNetworkInfo _tmp20_;
	MsmcommNetworkRegistrationStatus _tmp21_;
	gboolean _tmp22_;
	FsoGsmModemStatus _tmp23_;
	FsoGsmModem* _tmp24_;
	GHashFunc _tmp25_;
	GEqualFunc _tmp26_;
	GHashTable* _tmp27_;
	GHashTable* status;
	GHashTable* _tmp28_;
	FsoGsmModem* _tmp29_;
	gpointer _tmp30_;
	FreeSmartphoneGSMNetwork* network;
	FreeSmartphoneGSMNetwork* _tmp31_;
	GHashTable* _tmp32_;
	FreeSmartphoneGSMNetwork* _tmp33_;
	MsmDataNetworkInfo _tmp34_;
	guint _tmp35_;
	gint32 _tmp36_;
};


extern MsmDataNetworkInfo msm_data_network_info;
extern guint msm_data_cell_id;
extern gboolean inGatherSimStatusAndUpdate;
gboolean inGatherSimStatusAndUpdate = FALSE;
extern gboolean inTriggerUpdateNetworkStatus;
gboolean inTriggerUpdateNetworkStatus = FALSE;
extern FreeSmartphoneGSMSIMAuthStatus msm_data_sim_auth_status;

void fillNetworkStatusInfo (GHashTable* status);
gint32 convertRawRssiToPercentage (guint raw_rssi);
GType msm_data_network_info_get_type (void) G_GNUC_CONST;
MsmDataNetworkInfo* msm_data_network_info_dup (const MsmDataNetworkInfo* self);
void msm_data_network_info_free (MsmDataNetworkInfo* self);
void msm_data_network_info_copy (const MsmDataNetworkInfo* self, MsmDataNetworkInfo* dest);
void msm_data_network_info_destroy (MsmDataNetworkInfo* self);
static GVariant* _variant_new5 (gint32 value);
static GVariant* _variant_new6 (const gchar* value);
static GVariant* _variant_new7 (const gchar* value);
static GVariant* _variant_new8 (const gchar* value);
gchar* networkRegistrationStatusToString (MsmcommNetworkRegistrationStatus reg_status);
static GVariant* _variant_new9 (gchar* value);
static GVariant* _variant_new10 (const gchar* value);
static GVariant* _variant_new11 (const gchar* value);
static GVariant* _variant_new12 (gchar* value);
gchar* networkDataServiceToActString (MsmcommNetworkDataService data_service);
static GVariant* _variant_new13 (gchar* value);
static GVariant* _variant_new14 (gchar* value);
void updateMsmSimAuthStatus (FreeSmartphoneGSMSIMAuthStatus status);
const gchar* free_smartphone_gsm_sim_auth_status_to_string (FreeSmartphoneGSMSIMAuthStatus self);
static void gatherSimOperators_data_free (gpointer _data);
void gatherSimOperators (GAsyncReadyCallback _callback_, gpointer _user_data_);
void gatherSimOperators_finish (GAsyncResult* _res_, GError** error);
static gboolean gatherSimOperators_co (gatherSimOperatorsData* _data_);
static void gatherSimStatusAndUpdate_data_free (gpointer _data);
void gatherSimStatusAndUpdate (GAsyncReadyCallback _callback_, gpointer _user_data_);
void gatherSimStatusAndUpdate_finish (GAsyncResult* _res_, GError** error);
static gboolean gatherSimStatusAndUpdate_co (gatherSimStatusAndUpdateData* _data_);
static void triggerUpdateNetworkStatus_data_free (gpointer _data);
void triggerUpdateNetworkStatus (GAsyncReadyCallback _callback_, gpointer _user_data_);
void triggerUpdateNetworkStatus_finish (GAsyncResult* _res_);
static gboolean triggerUpdateNetworkStatus_co (triggerUpdateNetworkStatusData* _data_);
const gchar* fso_gsm_modem_status_to_string (FsoGsmModemStatus self);
static void _g_free0_ (gpointer var);
static void _g_variant_unref0_ (gpointer var);


/**
 * Public helpers
 **/
static GVariant* _variant_new5 (gint32 value) {
	return g_variant_ref_sink (g_variant_new_int32 (value));
}


static GVariant* _variant_new6 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new7 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new8 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new9 (gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new10 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new11 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new12 (gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new13 (gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new14 (gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


void fillNetworkStatusInfo (GHashTable* status) {
	GHashTable* _tmp0_;
	gchar* _tmp1_;
	MsmDataNetworkInfo _tmp2_;
	guint _tmp3_;
	gint32 _tmp4_ = 0;
	GVariant* _tmp5_;
	GHashTable* _tmp6_;
	gchar* _tmp7_;
	MsmDataNetworkInfo _tmp8_;
	const gchar* _tmp9_;
	GVariant* _tmp10_;
	GHashTable* _tmp11_;
	gchar* _tmp12_;
	MsmDataNetworkInfo _tmp13_;
	const gchar* _tmp14_;
	GVariant* _tmp15_;
	GHashTable* _tmp16_;
	gchar* _tmp17_;
	MsmDataNetworkInfo _tmp18_;
	const gchar* _tmp19_;
	GVariant* _tmp20_;
	GHashTable* _tmp21_;
	gchar* _tmp22_;
	MsmDataNetworkInfo _tmp23_;
	MsmcommNetworkRegistrationStatus _tmp24_;
	gchar* _tmp25_ = NULL;
	GVariant* _tmp26_;
	GHashTable* _tmp27_;
	gchar* _tmp28_;
	GVariant* _tmp29_;
	GHashTable* _tmp30_;
	gchar* _tmp31_;
	GVariant* _tmp32_;
	GHashTable* _tmp33_;
	gchar* _tmp34_;
	guint _tmp35_;
	gchar* _tmp36_ = NULL;
	GVariant* _tmp37_;
	GHashTable* _tmp38_;
	gchar* _tmp39_;
	MsmDataNetworkInfo _tmp40_;
	MsmcommNetworkDataService _tmp41_;
	gchar* _tmp42_ = NULL;
	GVariant* _tmp43_;
	gboolean _tmp44_ = FALSE;
	MsmDataNetworkInfo _tmp45_;
	MsmcommNetworkRegistrationStatus _tmp46_;
	gboolean _tmp49_;
	g_return_if_fail (status != NULL);
	_tmp0_ = status;
	_tmp1_ = g_strdup ("strength");
	_tmp2_ = msm_data_network_info;
	_tmp3_ = _tmp2_.rssi;
	_tmp4_ = convertRawRssiToPercentage (_tmp3_);
	_tmp5_ = _variant_new5 (_tmp4_);
	g_hash_table_insert (_tmp0_, _tmp1_, _tmp5_);
	_tmp6_ = status;
	_tmp7_ = g_strdup ("provider");
	_tmp8_ = msm_data_network_info;
	_tmp9_ = _tmp8_.operator_name;
	_tmp10_ = _variant_new6 (_tmp9_);
	g_hash_table_insert (_tmp6_, _tmp7_, _tmp10_);
	_tmp11_ = status;
	_tmp12_ = g_strdup ("network");
	_tmp13_ = msm_data_network_info;
	_tmp14_ = _tmp13_.operator_name;
	_tmp15_ = _variant_new7 (_tmp14_);
	g_hash_table_insert (_tmp11_, _tmp12_, _tmp15_);
	_tmp16_ = status;
	_tmp17_ = g_strdup ("display");
	_tmp18_ = msm_data_network_info;
	_tmp19_ = _tmp18_.operator_name;
	_tmp20_ = _variant_new8 (_tmp19_);
	g_hash_table_insert (_tmp16_, _tmp17_, _tmp20_);
	_tmp21_ = status;
	_tmp22_ = g_strdup ("registration");
	_tmp23_ = msm_data_network_info;
	_tmp24_ = _tmp23_.reg_status;
	_tmp25_ = networkRegistrationStatusToString (_tmp24_);
	_tmp26_ = _variant_new9 (_tmp25_);
	g_hash_table_insert (_tmp21_, _tmp22_, _tmp26_);
	_tmp27_ = status;
	_tmp28_ = g_strdup ("mode");
	_tmp29_ = _variant_new10 ("automatic");
	g_hash_table_insert (_tmp27_, _tmp28_, _tmp29_);
	_tmp30_ = status;
	_tmp31_ = g_strdup ("lac");
	_tmp32_ = _variant_new11 ("unknown");
	g_hash_table_insert (_tmp30_, _tmp31_, _tmp32_);
	_tmp33_ = status;
	_tmp34_ = g_strdup ("cid");
	_tmp35_ = msm_data_cell_id;
	_tmp36_ = g_strdup_printf ("%u", _tmp35_);
	_tmp37_ = _variant_new12 (_tmp36_);
	g_hash_table_insert (_tmp33_, _tmp34_, _tmp37_);
	_tmp38_ = status;
	_tmp39_ = g_strdup ("act");
	_tmp40_ = msm_data_network_info;
	_tmp41_ = _tmp40_.data_service;
	_tmp42_ = networkDataServiceToActString (_tmp41_);
	_tmp43_ = _variant_new13 (_tmp42_);
	g_hash_table_insert (_tmp38_, _tmp39_, _tmp43_);
	_tmp45_ = msm_data_network_info;
	_tmp46_ = _tmp45_.reg_status;
	if (_tmp46_ == MSMCOMM_NETWORK_REGISTRATION_STATUS_HOME) {
		_tmp44_ = TRUE;
	} else {
		MsmDataNetworkInfo _tmp47_;
		MsmcommNetworkRegistrationStatus _tmp48_;
		_tmp47_ = msm_data_network_info;
		_tmp48_ = _tmp47_.reg_status;
		_tmp44_ = _tmp48_ == MSMCOMM_NETWORK_REGISTRATION_STATUS_ROAMING;
	}
	_tmp49_ = _tmp44_;
	if (_tmp49_) {
		GHashTable* _tmp50_;
		gchar* _tmp51_;
		MsmDataNetworkInfo _tmp52_;
		guint _tmp53_;
		MsmDataNetworkInfo _tmp54_;
		guint _tmp55_;
		gchar* _tmp56_ = NULL;
		GVariant* _tmp57_;
		_tmp50_ = status;
		_tmp51_ = g_strdup ("code");
		_tmp52_ = msm_data_network_info;
		_tmp53_ = _tmp52_.mcc;
		_tmp54_ = msm_data_network_info;
		_tmp55_ = _tmp54_.mnc;
		_tmp56_ = g_strdup_printf ("%03u%02u", _tmp53_, _tmp55_);
		_tmp57_ = _variant_new14 (_tmp56_);
		g_hash_table_insert (_tmp50_, _tmp51_, _tmp57_);
	}
}


void updateMsmSimAuthStatus (FreeSmartphoneGSMSIMAuthStatus status) {
	FsoGsmModem* _tmp0_;
	FsoFrameworkLogger* _tmp1_;
	FreeSmartphoneGSMSIMAuthStatus _tmp2_;
	GEnumValue* _tmp3_;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_;
	FsoGsmModem* _tmp6_;
	gpointer _tmp7_ = NULL;
	FreeSmartphoneGSMSIM* obj;
	FreeSmartphoneGSMSIM* _tmp8_;
	FreeSmartphoneGSMSIMAuthStatus _tmp9_;
	FsoGsmModem* _tmp10_;
	FsoGsmModemData* _tmp11_ = NULL;
	FsoGsmModemData* data;
	FreeSmartphoneGSMSIMAuthStatus _tmp12_;
	FsoGsmModemData* _tmp13_;
	FreeSmartphoneGSMSIMAuthStatus _tmp14_;
	_tmp0_ = fso_gsm_theModem;
	_tmp1_ = ((FsoFrameworkAbstractObject*) _tmp0_)->logger;
	_tmp2_ = status;
	_tmp3_ = g_enum_get_value (g_type_class_ref (FREE_SMARTPHONE_GSM_TYPE_SIM_AUTH_STATUS), _tmp2_);
	_tmp4_ = g_strconcat ("SIM Auth status now ", (_tmp3_ != NULL) ? _tmp3_->value_name : NULL, NULL);
	_tmp5_ = _tmp4_;
	fso_framework_logger_info (_tmp1_, _tmp5_);
	_g_free0 (_tmp5_);
	_tmp6_ = fso_gsm_theModem;
	_tmp7_ = fso_gsm_modem_theDevice (_tmp6_, FREE_SMARTPHONE_GSM_TYPE_SIM, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	obj = (FreeSmartphoneGSMSIM*) _tmp7_;
	_tmp8_ = obj;
	_tmp9_ = status;
	g_signal_emit_by_name (_tmp8_, "auth-status", _tmp9_);
	_tmp10_ = fso_gsm_theModem;
	_tmp11_ = fso_gsm_modem_data (_tmp10_);
	data = _tmp11_;
	_tmp12_ = status;
	_tmp13_ = data;
	_tmp14_ = _tmp13_->simAuthStatus;
	if (_tmp12_ != _tmp14_) {
		FsoGsmModemData* _tmp15_;
		FreeSmartphoneGSMSIMAuthStatus _tmp16_;
		FsoGsmModem* _tmp17_;
		FsoGsmModemStatus _tmp18_ = 0;
		FsoGsmModemStatus modemStatus;
		FsoGsmModemStatus _tmp19_;
		_tmp15_ = data;
		_tmp16_ = status;
		_tmp15_->simAuthStatus = _tmp16_;
		_tmp17_ = fso_gsm_theModem;
		_tmp18_ = fso_gsm_modem_status (_tmp17_);
		modemStatus = _tmp18_;
		_tmp19_ = modemStatus;
		if (_tmp19_ == FSO_GSM_MODEM_STATUS_INITIALIZING) {
			FreeSmartphoneGSMSIMAuthStatus _tmp20_;
			_tmp20_ = status;
			if (_tmp20_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_READY) {
				FsoGsmModem* _tmp21_;
				_tmp21_ = fso_gsm_theModem;
				fso_gsm_modem_advanceToState (_tmp21_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_UNLOCKED, FALSE);
			} else {
				FsoGsmModem* _tmp22_;
				_tmp22_ = fso_gsm_theModem;
				fso_gsm_modem_advanceToState (_tmp22_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_LOCKED, FALSE);
			}
		} else {
			FsoGsmModemStatus _tmp23_;
			_tmp23_ = modemStatus;
			if (_tmp23_ == FSO_GSM_MODEM_STATUS_ALIVE_SIM_LOCKED) {
				FreeSmartphoneGSMSIMAuthStatus _tmp24_;
				_tmp24_ = status;
				if (_tmp24_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_READY) {
					FsoGsmModem* _tmp25_;
					_tmp25_ = fso_gsm_theModem;
					fso_gsm_modem_advanceToState (_tmp25_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_UNLOCKED, FALSE);
				}
			} else {
				gboolean _tmp26_ = FALSE;
				FsoGsmModemStatus _tmp27_;
				gboolean _tmp29_;
				_tmp27_ = modemStatus;
				if (_tmp27_ == FSO_GSM_MODEM_STATUS_ALIVE_REGISTERED) {
					_tmp26_ = TRUE;
				} else {
					FsoGsmModemStatus _tmp28_;
					_tmp28_ = modemStatus;
					_tmp26_ = _tmp28_ == FSO_GSM_MODEM_STATUS_ALIVE_SIM_UNLOCKED;
				}
				_tmp29_ = _tmp26_;
				if (_tmp29_) {
					FreeSmartphoneGSMSIMAuthStatus _tmp30_;
					_tmp30_ = status;
					if (_tmp30_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_PIN_REQUIRED) {
						FsoGsmModem* _tmp31_;
						_tmp31_ = fso_gsm_theModem;
						fso_gsm_modem_advanceToState (_tmp31_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_LOCKED, TRUE);
					}
				}
			}
		}
	}
	_g_object_unref0 (data);
	_g_object_unref0 (obj);
}


static void gatherSimOperators_data_free (gpointer _data) {
	gatherSimOperatorsData* _data_;
	_data_ = _data;
	g_slice_free (gatherSimOperatorsData, _data_);
}


void gatherSimOperators (GAsyncReadyCallback _callback_, gpointer _user_data_) {
	gatherSimOperatorsData* _data_;
	_data_ = g_slice_new0 (gatherSimOperatorsData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, gatherSimOperators);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, gatherSimOperators_data_free);
	gatherSimOperators_co (_data_);
}


void gatherSimOperators_finish (GAsyncResult* _res_, GError** error) {
	gatherSimOperatorsData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


/**
 * Modem facilities helpers
 **/
static gboolean gatherSimOperators_co (gatherSimOperatorsData* _data_) {
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


static void gatherSimStatusAndUpdate_data_free (gpointer _data) {
	gatherSimStatusAndUpdateData* _data_;
	_data_ = _data;
	g_slice_free (gatherSimStatusAndUpdateData, _data_);
}


void gatherSimStatusAndUpdate (GAsyncReadyCallback _callback_, gpointer _user_data_) {
	gatherSimStatusAndUpdateData* _data_;
	_data_ = g_slice_new0 (gatherSimStatusAndUpdateData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, gatherSimStatusAndUpdate);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, gatherSimStatusAndUpdate_data_free);
	gatherSimStatusAndUpdate_co (_data_);
}


void gatherSimStatusAndUpdate_finish (GAsyncResult* _res_, GError** error) {
	gatherSimStatusAndUpdateData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean gatherSimStatusAndUpdate_co (gatherSimStatusAndUpdateData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = inGatherSimStatusAndUpdate;
	if (_data_->_tmp0_) {
		_data_->_tmp1_ = fso_gsm_theModem;
		_data_->_tmp2_ = ((FsoFrameworkAbstractObject*) _data_->_tmp1_)->logger;
		_data_->_tmp3_ = FALSE;
		_data_->_tmp3_ = fso_framework_logger_debug (_data_->_tmp2_, "already gathering sim status... ignoring additional trigger");
		g_assert (_data_->_tmp3_);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	inGatherSimStatusAndUpdate = TRUE;
	_data_->_tmp4_ = fso_gsm_theModem;
	_data_->_tmp5_ = NULL;
	_data_->_tmp5_ = fso_gsm_modem_data (_data_->_tmp4_);
	_data_->data = _data_->_tmp5_;
	_data_->_tmp6_ = fso_gsm_theModem;
	_data_->_tmp7_ = ((FsoFrameworkAbstractObject*) _data_->_tmp6_)->logger;
	_data_->_tmp8_ = msm_data_sim_auth_status;
	_data_->_tmp9_ = g_enum_get_value (g_type_class_ref (FREE_SMARTPHONE_GSM_TYPE_SIM_AUTH_STATUS), _data_->_tmp8_);
	_data_->_tmp10_ = NULL;
	_data_->_tmp10_ = g_strconcat ("SIM Auth status ", (_data_->_tmp9_ != NULL) ? _data_->_tmp9_->value_name : NULL, NULL);
	_data_->_tmp11_ = _data_->_tmp10_;
	fso_framework_logger_info (_data_->_tmp7_, _data_->_tmp11_);
	_g_free0 (_data_->_tmp11_);
	_data_->_tmp12_ = fso_gsm_theModem;
	_data_->_tmp13_ = NULL;
	_data_->_tmp13_ = fso_gsm_modem_theDevice (_data_->_tmp12_, FREE_SMARTPHONE_GSM_TYPE_SIM, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	_data_->obj = (FreeSmartphoneGSMSIM*) _data_->_tmp13_;
	_data_->_tmp14_ = _data_->obj;
	_data_->_tmp15_ = msm_data_sim_auth_status;
	g_signal_emit_by_name (_data_->_tmp14_, "auth-status", _data_->_tmp15_);
	_data_->_tmp16_ = _data_->data;
	_data_->_tmp17_ = _data_->_tmp16_->simAuthStatus;
	_data_->_tmp18_ = msm_data_sim_auth_status;
	if (_data_->_tmp17_ != _data_->_tmp18_) {
		_data_->_tmp19_ = _data_->data;
		_data_->_tmp20_ = msm_data_sim_auth_status;
		_data_->_tmp19_->simAuthStatus = _data_->_tmp20_;
		_data_->_tmp21_ = fso_gsm_theModem;
		_data_->_tmp22_ = 0;
		_data_->_tmp22_ = fso_gsm_modem_status (_data_->_tmp21_);
		_data_->modemStatus = _data_->_tmp22_;
		_data_->_tmp24_ = _data_->modemStatus;
		if (_data_->_tmp24_ >= FSO_GSM_MODEM_STATUS_INITIALIZING) {
			_data_->_tmp25_ = _data_->modemStatus;
			_data_->_tmp23_ = _data_->_tmp25_ <= FSO_GSM_MODEM_STATUS_ALIVE_REGISTERED;
		} else {
			_data_->_tmp23_ = FALSE;
		}
		_data_->_tmp26_ = _data_->_tmp23_;
		if (_data_->_tmp26_) {
			_data_->_tmp27_ = msm_data_sim_auth_status;
			if (_data_->_tmp27_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_READY) {
				_data_->_tmp28_ = fso_gsm_theModem;
				fso_gsm_modem_advanceToState (_data_->_tmp28_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_UNLOCKED, TRUE);
			} else {
				_data_->_tmp29_ = fso_gsm_theModem;
				fso_gsm_modem_advanceToState (_data_->_tmp29_, FSO_GSM_MODEM_STATUS_ALIVE_SIM_LOCKED, TRUE);
			}
		}
	}
	inGatherSimStatusAndUpdate = FALSE;
	_g_object_unref0 (_data_->obj);
	_g_object_unref0 (_data_->data);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void triggerUpdateNetworkStatus_data_free (gpointer _data) {
	triggerUpdateNetworkStatusData* _data_;
	_data_ = _data;
	g_slice_free (triggerUpdateNetworkStatusData, _data_);
}


void triggerUpdateNetworkStatus (GAsyncReadyCallback _callback_, gpointer _user_data_) {
	triggerUpdateNetworkStatusData* _data_;
	_data_ = g_slice_new0 (triggerUpdateNetworkStatusData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, triggerUpdateNetworkStatus);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, triggerUpdateNetworkStatus_data_free);
	triggerUpdateNetworkStatus_co (_data_);
}


void triggerUpdateNetworkStatus_finish (GAsyncResult* _res_) {
	triggerUpdateNetworkStatusData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


/**
 * Update network status if something in network state has changed
 **/
static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_variant_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_variant_unref (var), NULL));
}


static gboolean triggerUpdateNetworkStatus_co (triggerUpdateNetworkStatusData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = inTriggerUpdateNetworkStatus;
	if (_data_->_tmp0_) {
		_data_->_tmp1_ = fso_gsm_theModem;
		_data_->_tmp2_ = ((FsoFrameworkAbstractObject*) _data_->_tmp1_)->logger;
		_data_->_tmp3_ = FALSE;
		_data_->_tmp3_ = fso_framework_logger_debug (_data_->_tmp2_, "already gathering network status... ignoring additional trigger");
		g_assert (_data_->_tmp3_);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	inTriggerUpdateNetworkStatus = TRUE;
	_data_->_tmp4_ = fso_gsm_theModem;
	_data_->_tmp5_ = 0;
	_data_->_tmp5_ = fso_gsm_modem_status (_data_->_tmp4_);
	_data_->mstat = _data_->_tmp5_;
	_data_->_tmp7_ = _data_->mstat;
	if (_data_->_tmp7_ != FSO_GSM_MODEM_STATUS_ALIVE_SIM_READY) {
		_data_->_tmp8_ = _data_->mstat;
		_data_->_tmp6_ = _data_->_tmp8_ != FSO_GSM_MODEM_STATUS_ALIVE_REGISTERED;
	} else {
		_data_->_tmp6_ = FALSE;
	}
	_data_->_tmp9_ = _data_->_tmp6_;
	if (_data_->_tmp9_) {
		_data_->_tmp10_ = fso_gsm_theModem;
		_data_->_tmp11_ = ((FsoFrameworkAbstractObject*) _data_->_tmp10_)->logger;
		_data_->_tmp12_ = _data_->mstat;
		_data_->_tmp13_ = g_enum_get_value (g_type_class_ref (FSO_GSM_MODEM_TYPE_STATUS), _data_->_tmp12_);
		_data_->_tmp14_ = NULL;
		_data_->_tmp14_ = g_strconcat ("triggerUpdateNetworkStatus() ignored while modem is in status ", (_data_->_tmp13_ != NULL) ? _data_->_tmp13_->value_name : NULL, NULL);
		_data_->_tmp15_ = _data_->_tmp14_;
		_data_->_tmp16_ = FALSE;
		_data_->_tmp16_ = fso_framework_logger_debug (_data_->_tmp11_, _data_->_tmp15_);
		g_assert (_data_->_tmp16_);
		_g_free0 (_data_->_tmp15_);
		inTriggerUpdateNetworkStatus = FALSE;
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp18_ = msm_data_network_info;
	_data_->_tmp19_ = _data_->_tmp18_.reg_status;
	if (_data_->_tmp19_ == MSMCOMM_NETWORK_REGISTRATION_STATUS_HOME) {
		_data_->_tmp17_ = TRUE;
	} else {
		_data_->_tmp20_ = msm_data_network_info;
		_data_->_tmp21_ = _data_->_tmp20_.reg_status;
		_data_->_tmp17_ = _data_->_tmp21_ == MSMCOMM_NETWORK_REGISTRATION_STATUS_ROAMING;
	}
	_data_->_tmp22_ = _data_->_tmp17_;
	if (_data_->_tmp22_) {
		_data_->_tmp23_ = _data_->mstat;
		if (_data_->_tmp23_ != FSO_GSM_MODEM_STATUS_ALIVE_REGISTERED) {
			_data_->_tmp24_ = fso_gsm_theModem;
			fso_gsm_modem_advanceToState (_data_->_tmp24_, FSO_GSM_MODEM_STATUS_ALIVE_REGISTERED, FALSE);
		}
	}
	_data_->_tmp25_ = g_str_hash;
	_data_->_tmp26_ = g_str_equal;
	_data_->_tmp27_ = g_hash_table_new_full (_data_->_tmp25_, _data_->_tmp26_, _g_free0_, _g_variant_unref0_);
	_data_->status = _data_->_tmp27_;
	_data_->_tmp28_ = _data_->status;
	fillNetworkStatusInfo (_data_->_tmp28_);
	_data_->_tmp29_ = fso_gsm_theModem;
	_data_->_tmp30_ = NULL;
	_data_->_tmp30_ = fso_gsm_modem_theDevice (_data_->_tmp29_, FREE_SMARTPHONE_GSM_TYPE_NETWORK, (GBoxedCopyFunc) g_object_ref, g_object_unref);
	_data_->network = (FreeSmartphoneGSMNetwork*) _data_->_tmp30_;
	_data_->_tmp31_ = _data_->network;
	_data_->_tmp32_ = _data_->status;
	g_signal_emit_by_name (_data_->_tmp31_, "status", _data_->_tmp32_);
	_data_->_tmp33_ = _data_->network;
	_data_->_tmp34_ = msm_data_network_info;
	_data_->_tmp35_ = _data_->_tmp34_.rssi;
	_data_->_tmp36_ = 0;
	_data_->_tmp36_ = convertRawRssiToPercentage (_data_->_tmp35_);
	g_signal_emit_by_name (_data_->_tmp33_, "signal-strength", (gint) _data_->_tmp36_);
	inTriggerUpdateNetworkStatus = FALSE;
	_g_object_unref0 (_data_->network);
	_g_hash_table_unref0 (_data_->status);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}



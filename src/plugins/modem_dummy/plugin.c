/* plugin.c generated by valac 0.14.2, the Vala compiler
 * generated from plugin.vala, do not modify */

/**
 * Copyright (C) 2009-2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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
#include <gee.h>
#include <fsoframework.h>
#include <fsobasics.h>


#define DUMMY_TYPE_MODEM (dummy_modem_get_type ())
#define DUMMY_MODEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DUMMY_TYPE_MODEM, DummyModem))
#define DUMMY_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DUMMY_TYPE_MODEM, DummyModemClass))
#define DUMMY_IS_MODEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DUMMY_TYPE_MODEM))
#define DUMMY_IS_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DUMMY_TYPE_MODEM))
#define DUMMY_MODEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DUMMY_TYPE_MODEM, DummyModemClass))

typedef struct _DummyModem DummyModem;
typedef struct _DummyModemClass DummyModemClass;
typedef struct _DummyModemPrivate DummyModemPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _DummyModemOpenData DummyModemOpenData;
typedef struct _DummyModemCloseData DummyModemCloseData;

struct _DummyModem {
	FsoGsmAbstractModem parent_instance;
	DummyModemPrivate * priv;
};

struct _DummyModemClass {
	FsoGsmAbstractModemClass parent_class;
};

struct _DummyModemOpenData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DummyModem* self;
	gboolean result;
	gchar* _tmp0_;
};

struct _DummyModemCloseData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DummyModem* self;
};


static gpointer dummy_modem_parent_class = NULL;
extern gchar* fso_gsm_modem_pin;
static GType dummy_modem_type_id = 0;

GType dummy_modem_get_type (void) G_GNUC_CONST;
GType dummy_modem_register_type (GTypeModule * module);
enum  {
	DUMMY_MODEM_DUMMY_PROPERTY
};
#define DUMMY_MODEM_CHANNEL_NAME "main"
static gchar* dummy_modem_real_repr (FsoFrameworkAbstractObject* base);
static FsoGsmChannel* dummy_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query);
static void dummy_modem_real_open_data_free (gpointer _data);
static void dummy_modem_real_open (FsoGsmAbstractModem* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean dummy_modem_real_open_co (DummyModemOpenData* _data_);
static void dummy_modem_real_close_data_free (gpointer _data);
static void dummy_modem_real_close (FsoGsmAbstractModem* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean dummy_modem_real_close_co (DummyModemCloseData* _data_);
static void dummy_modem_real_registerCustomMediators (FsoGsmAbstractModem* base, GeeHashMap* mediators);
void fso_gsm_registerDummyMediators (GeeHashMap* table);
static FsoGsmCallHandler* dummy_modem_real_createCallHandler (FsoGsmAbstractModem* base);
static FsoGsmSmsHandler* dummy_modem_real_createSmsHandler (FsoGsmAbstractModem* base);
static FsoGsmPhonebookHandler* dummy_modem_real_createPhonebookHandler (FsoGsmAbstractModem* base);
static FsoGsmWatchDog* dummy_modem_real_createWatchDog (FsoGsmAbstractModem* base);
DummyModem* dummy_modem_new (void);
DummyModem* dummy_modem_construct (GType object_type);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static gchar* dummy_modem_real_repr (FsoFrameworkAbstractObject* base) {
	DummyModem * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (DummyModem*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static FsoGsmChannel* dummy_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query) {
	DummyModem * self;
	FsoGsmChannel* result = NULL;
	FsoGsmChannel* _tmp0_;
	self = (DummyModem*) base;
	g_return_val_if_fail (command != NULL, NULL);
	g_return_val_if_fail (query != NULL, NULL);
	_tmp0_ = _g_object_ref0 (FSO_GSM_CHANNEL (NULL));
	result = _tmp0_;
	return result;
}


static void dummy_modem_real_open_data_free (gpointer _data) {
	DummyModemOpenData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DummyModemOpenData, _data_);
}


static void dummy_modem_real_open (FsoGsmAbstractModem* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DummyModem * self;
	DummyModemOpenData* _data_;
	DummyModem* _tmp0_;
	self = (DummyModem*) base;
	_data_ = g_slice_new0 (DummyModemOpenData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, dummy_modem_real_open);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, dummy_modem_real_open_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	dummy_modem_real_open_co (_data_);
}


static gboolean dummy_modem_real_open_finish (FsoGsmAbstractModem* base, GAsyncResult* _res_) {
	gboolean result;
	DummyModemOpenData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	return result;
}


static gboolean dummy_modem_real_open_co (DummyModemOpenData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = g_strdup ("1234");
	_g_free0 (fso_gsm_modem_pin);
	fso_gsm_modem_pin = _data_->_tmp0_;
	fso_gsm_modem_advanceToState ((FsoGsmModem*) _data_->self, FSO_GSM_MODEM_STATUS_ALIVE_SIM_LOCKED, FALSE);
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


static void dummy_modem_real_close_data_free (gpointer _data) {
	DummyModemCloseData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DummyModemCloseData, _data_);
}


static void dummy_modem_real_close (FsoGsmAbstractModem* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DummyModem * self;
	DummyModemCloseData* _data_;
	DummyModem* _tmp0_;
	self = (DummyModem*) base;
	_data_ = g_slice_new0 (DummyModemCloseData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, dummy_modem_real_close);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, dummy_modem_real_close_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	dummy_modem_real_close_co (_data_);
}


static void dummy_modem_real_close_finish (FsoGsmAbstractModem* base, GAsyncResult* _res_) {
	DummyModemCloseData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean dummy_modem_real_close_co (DummyModemCloseData* _data_) {
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


static void dummy_modem_real_registerCustomMediators (FsoGsmAbstractModem* base, GeeHashMap* mediators) {
	DummyModem * self;
	GeeHashMap* _tmp0_;
	self = (DummyModem*) base;
	g_return_if_fail (mediators != NULL);
	_tmp0_ = mediators;
	fso_gsm_registerDummyMediators (_tmp0_);
}


static FsoGsmCallHandler* dummy_modem_real_createCallHandler (FsoGsmAbstractModem* base) {
	DummyModem * self;
	FsoGsmCallHandler* result = NULL;
	FsoGsmNullCallHandler* _tmp0_;
	self = (DummyModem*) base;
	_tmp0_ = fso_gsm_null_call_handler_new ();
	result = (FsoGsmCallHandler*) _tmp0_;
	return result;
}


static FsoGsmSmsHandler* dummy_modem_real_createSmsHandler (FsoGsmAbstractModem* base) {
	DummyModem * self;
	FsoGsmSmsHandler* result = NULL;
	FsoGsmNullSmsHandler* _tmp0_;
	self = (DummyModem*) base;
	_tmp0_ = fso_gsm_null_sms_handler_new ();
	result = (FsoGsmSmsHandler*) _tmp0_;
	return result;
}


static FsoGsmPhonebookHandler* dummy_modem_real_createPhonebookHandler (FsoGsmAbstractModem* base) {
	DummyModem * self;
	FsoGsmPhonebookHandler* result = NULL;
	self = (DummyModem*) base;
	result = NULL;
	return result;
}


static FsoGsmWatchDog* dummy_modem_real_createWatchDog (FsoGsmAbstractModem* base) {
	DummyModem * self;
	FsoGsmWatchDog* result = NULL;
	FsoGsmNullWatchDog* _tmp0_;
	self = (DummyModem*) base;
	_tmp0_ = fso_gsm_null_watch_dog_new ();
	result = (FsoGsmWatchDog*) _tmp0_;
	return result;
}


DummyModem* dummy_modem_construct (GType object_type) {
	DummyModem * self = NULL;
	self = (DummyModem*) fso_gsm_abstract_modem_construct (object_type);
	return self;
}


DummyModem* dummy_modem_new (void) {
	return dummy_modem_construct (DUMMY_TYPE_MODEM);
}


static void dummy_modem_class_init (DummyModemClass * klass) {
	dummy_modem_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = dummy_modem_real_repr;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->channelForCommand = dummy_modem_real_channelForCommand;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->open = dummy_modem_real_open;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->open_finish = dummy_modem_real_open_finish;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->close = dummy_modem_real_close;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->close_finish = dummy_modem_real_close_finish;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->registerCustomMediators = dummy_modem_real_registerCustomMediators;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createCallHandler = dummy_modem_real_createCallHandler;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createSmsHandler = dummy_modem_real_createSmsHandler;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createPhonebookHandler = dummy_modem_real_createPhonebookHandler;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createWatchDog = dummy_modem_real_createWatchDog;
}


static void dummy_modem_instance_init (DummyModem * self) {
}


/**
 * @class Dummy.Modem
 *
 * This modem plugin simulates a modem based on fixed parameters.
 *
 **/
GType dummy_modem_get_type (void) {
	return dummy_modem_type_id;
}


GType dummy_modem_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (DummyModemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) dummy_modem_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DummyModem), 0, (GInstanceInitFunc) dummy_modem_instance_init, NULL };
	dummy_modem_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_MODEM, "DummyModem", &g_define_type_info, 0);
	return dummy_modem_type_id;
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
	fso_framework_logger_debug (_tmp0_, "fsogsm.dummy fso_factory_function");
	_tmp1_ = g_strdup ("fsogsmd.modem_dummy");
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	fso_gsm_dummy_at_debug_command_register_type (module);
	fso_gsm_dummy_at_debug_inject_response_register_type (module);
	fso_gsm_dummy_at_debug_ping_register_type (module);
	fso_gsm_dummy_at_device_get_alarm_time_register_type (module);
	fso_gsm_dummy_at_device_get_current_time_register_type (module);
	fso_gsm_dummy_at_device_get_functionality_register_type (module);
	fso_gsm_dummy_at_device_get_information_register_type (module);
	fso_gsm_dummy_at_device_get_features_register_type (module);
	fso_gsm_dummy_at_device_get_microphone_muted_register_type (module);
	fso_gsm_dummy_at_device_get_speaker_volume_register_type (module);
	fso_gsm_dummy_at_device_get_power_status_register_type (module);
	fso_gsm_dummy_at_device_set_alarm_time_register_type (module);
	fso_gsm_dummy_at_device_set_current_time_register_type (module);
	fso_gsm_dummy_at_device_set_functionality_register_type (module);
	fso_gsm_dummy_at_device_set_microphone_muted_register_type (module);
	fso_gsm_dummy_at_device_set_speaker_volume_register_type (module);
	fso_gsm_dummy_at_sim_change_auth_code_register_type (module);
	fso_gsm_dummy_at_sim_delete_entry_register_type (module);
	fso_gsm_dummy_at_sim_delete_message_register_type (module);
	fso_gsm_dummy_at_sim_get_auth_status_register_type (module);
	fso_gsm_dummy_at_sim_get_information_register_type (module);
	fso_gsm_dummy_at_sim_get_auth_code_required_register_type (module);
	fso_gsm_dummy_at_sim_get_service_center_number_register_type (module);
	fso_gsm_dummy_at_sim_retrieve_message_register_type (module);
	fso_gsm_dummy_at_sim_retrieve_phonebook_register_type (module);
	fso_gsm_dummy_at_sim_set_auth_code_required_register_type (module);
	fso_gsm_dummy_at_sim_send_auth_code_register_type (module);
	fso_gsm_dummy_at_sim_set_service_center_number_register_type (module);
	fso_gsm_dummy_at_sim_write_entry_register_type (module);
	fso_gsm_dummy_at_sim_unlock_register_type (module);
	fso_gsm_dummy_at_sms_send_text_message_register_type (module);
	fso_gsm_dummy_at_sms_retrieve_text_messages_register_type (module);
	fso_gsm_dummy_at_network_get_signal_strength_register_type (module);
	fso_gsm_dummy_at_network_get_status_register_type (module);
	fso_gsm_dummy_at_network_list_providers_register_type (module);
	fso_gsm_dummy_at_network_register_register_type (module);
	fso_gsm_dummy_at_call_activate_register_type (module);
	fso_gsm_dummy_at_call_hold_active_register_type (module);
	fso_gsm_dummy_at_call_initiate_register_type (module);
	fso_gsm_dummy_at_call_list_calls_register_type (module);
	fso_gsm_dummy_at_call_send_dtmf_register_type (module);
	fso_gsm_dummy_at_call_release_register_type (module);
	fso_gsm_dummy_at_call_release_all_register_type (module);
	fso_gsm_dummy_at_pdp_activate_context_register_type (module);
	fso_gsm_dummy_at_pdp_deactivate_context_register_type (module);
	fso_gsm_dummy_at_pdp_get_credentials_register_type (module);
	fso_gsm_dummy_at_pdp_set_credentials_register_type (module);
	dummy_modem_register_type (module);
}




/* plugin.c generated by valac 0.14.2, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
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
#include <fsotransport.h>
#include <gee.h>
#include <fsoframework.h>
#include <fsobasics.h>


#define QUALCOMM_HTC_TYPE_MODEM (qualcomm_htc_modem_get_type ())
#define QUALCOMM_HTC_MODEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUALCOMM_HTC_TYPE_MODEM, QualcommHtcModem))
#define QUALCOMM_HTC_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUALCOMM_HTC_TYPE_MODEM, QualcommHtcModemClass))
#define QUALCOMM_HTC_IS_MODEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUALCOMM_HTC_TYPE_MODEM))
#define QUALCOMM_HTC_IS_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUALCOMM_HTC_TYPE_MODEM))
#define QUALCOMM_HTC_MODEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUALCOMM_HTC_TYPE_MODEM, QualcommHtcModemClass))

typedef struct _QualcommHtcModem QualcommHtcModem;
typedef struct _QualcommHtcModemClass QualcommHtcModemClass;
typedef struct _QualcommHtcModemPrivate QualcommHtcModemPrivate;
#define _fso_gsm_at_command_sequence_unref0(var) ((var == NULL) ? NULL : (var = (fso_gsm_at_command_sequence_unref (var), NULL)))

#define FSO_GSM_TYPE_HTC_AT_PARSER (fso_gsm_htc_at_parser_get_type ())
#define FSO_GSM_HTC_AT_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_HTC_AT_PARSER, FsoGsmHtcAtParser))
#define FSO_GSM_HTC_AT_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_HTC_AT_PARSER, FsoGsmHtcAtParserClass))
#define FSO_GSM_IS_HTC_AT_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_HTC_AT_PARSER))
#define FSO_GSM_IS_HTC_AT_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_HTC_AT_PARSER))
#define FSO_GSM_HTC_AT_PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_HTC_AT_PARSER, FsoGsmHtcAtParserClass))

typedef struct _FsoGsmHtcAtParser FsoGsmHtcAtParser;
typedef struct _FsoGsmHtcAtParserClass FsoGsmHtcAtParserClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define QUALCOMM_HTC_TYPE_UNSOLICITED_RESPONSE_HANDLER (qualcomm_htc_unsolicited_response_handler_get_type ())
#define QUALCOMM_HTC_UNSOLICITED_RESPONSE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUALCOMM_HTC_TYPE_UNSOLICITED_RESPONSE_HANDLER, QualcommHtcUnsolicitedResponseHandler))
#define QUALCOMM_HTC_UNSOLICITED_RESPONSE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUALCOMM_HTC_TYPE_UNSOLICITED_RESPONSE_HANDLER, QualcommHtcUnsolicitedResponseHandlerClass))
#define QUALCOMM_HTC_IS_UNSOLICITED_RESPONSE_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUALCOMM_HTC_TYPE_UNSOLICITED_RESPONSE_HANDLER))
#define QUALCOMM_HTC_IS_UNSOLICITED_RESPONSE_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUALCOMM_HTC_TYPE_UNSOLICITED_RESPONSE_HANDLER))
#define QUALCOMM_HTC_UNSOLICITED_RESPONSE_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUALCOMM_HTC_TYPE_UNSOLICITED_RESPONSE_HANDLER, QualcommHtcUnsolicitedResponseHandlerClass))

typedef struct _QualcommHtcUnsolicitedResponseHandler QualcommHtcUnsolicitedResponseHandler;
typedef struct _QualcommHtcUnsolicitedResponseHandlerClass QualcommHtcUnsolicitedResponseHandlerClass;

struct _QualcommHtcModem {
	FsoGsmAbstractModem parent_instance;
	QualcommHtcModemPrivate * priv;
};

struct _QualcommHtcModemClass {
	FsoGsmAbstractModemClass parent_class;
};


static gpointer qualcomm_htc_modem_parent_class = NULL;
static GType qualcomm_htc_modem_type_id = 0;

GType qualcomm_htc_modem_get_type (void) G_GNUC_CONST;
GType qualcomm_htc_modem_register_type (GTypeModule * module);
enum  {
	QUALCOMM_HTC_MODEM_DUMMY_PROPERTY
};
#define QUALCOMM_HTC_MODEM_CHANNEL_NAME "main"
static gchar* qualcomm_htc_modem_real_repr (FsoFrameworkAbstractObject* base);
static void qualcomm_htc_modem_real_configureData (FsoGsmAbstractModem* base);
static void qualcomm_htc_modem_real_createChannels (FsoGsmAbstractModem* base);
FsoGsmHtcAtParser* fso_gsm_htc_at_parser_new (void);
FsoGsmHtcAtParser* fso_gsm_htc_at_parser_construct (GType object_type);
GType fso_gsm_htc_at_parser_get_type (void) G_GNUC_CONST;
GType fso_gsm_htc_at_parser_register_type (GTypeModule * module);
static FsoGsmChannel* qualcomm_htc_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query);
static FsoGsmUnsolicitedResponseHandler* qualcomm_htc_modem_real_createUnsolicitedHandler (FsoGsmAbstractModem* base);
QualcommHtcUnsolicitedResponseHandler* qualcomm_htc_unsolicited_response_handler_new (void);
QualcommHtcUnsolicitedResponseHandler* qualcomm_htc_unsolicited_response_handler_construct (GType object_type);
GType qualcomm_htc_unsolicited_response_handler_get_type (void) G_GNUC_CONST;
GType qualcomm_htc_unsolicited_response_handler_register_type (GTypeModule * module);
static void qualcomm_htc_modem_real_registerCustomAtCommands (FsoGsmAbstractModem* base, GeeHashMap* commands);
void qualcomm_htc_registerCustomAtCommands (GeeHashMap* table);
QualcommHtcModem* qualcomm_htc_modem_new (void);
QualcommHtcModem* qualcomm_htc_modem_construct (GType object_type);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gchar* qualcomm_htc_modem_real_repr (FsoFrameworkAbstractObject* base) {
	QualcommHtcModem * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (QualcommHtcModem*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static void qualcomm_htc_modem_real_configureData (FsoGsmAbstractModem* base) {
	QualcommHtcModem * self;
	FsoGsmModemData* _tmp0_;
	FsoGsmModemData* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	gchar** _tmp12_ = NULL;
	gchar** _tmp13_;
	gint _tmp13__length1;
	FsoGsmAtCommandSequence* _tmp14_;
	FsoGsmAtCommandSequence* _tmp15_;
	gchar* _tmp16_;
	gchar** _tmp17_ = NULL;
	gchar** _tmp18_;
	gint _tmp18__length1;
	FsoGsmAtCommandSequence* _tmp19_;
	FsoGsmAtCommandSequence* _tmp20_;
	gchar* _tmp21_;
	gchar* _tmp22_;
	gchar* _tmp23_;
	gchar** _tmp24_ = NULL;
	gchar** _tmp25_;
	gint _tmp25__length1;
	FsoGsmAtCommandSequence* _tmp26_;
	FsoGsmAtCommandSequence* _tmp27_;
	gchar* _tmp28_;
	gchar* _tmp29_;
	gchar* _tmp30_;
	gchar** _tmp31_ = NULL;
	gchar** _tmp32_;
	gint _tmp32__length1;
	FsoGsmAtCommandSequence* _tmp33_;
	FsoGsmAtCommandSequence* _tmp34_;
	self = (QualcommHtcModem*) base;
	_tmp0_ = ((FsoGsmAbstractModem*) self)->modem_data;
	g_assert (_tmp0_ != NULL);
	_tmp1_ = ((FsoGsmAbstractModem*) self)->modem_data;
	_tmp1_->simHasReadySignal = TRUE;
	_tmp2_ = g_strdup ("+CLIP=1");
	_tmp3_ = g_strdup ("+COLP=0");
	_tmp4_ = g_strdup ("+CCWA=1");
	_tmp5_ = g_strdup ("+CSSN=1,1");
	_tmp6_ = g_strdup ("+CTZU=1");
	_tmp7_ = g_strdup ("+CTZR=1");
	_tmp8_ = g_strdup ("+CREG=2");
	_tmp9_ = g_strdup ("+CGREG=2");
	_tmp10_ = g_strdup ("+CGEREP=2,1");
	_tmp11_ = g_strdup ("+HTCCTZR=2");
	_tmp12_ = g_new0 (gchar*, 10 + 1);
	_tmp12_[0] = _tmp2_;
	_tmp12_[1] = _tmp3_;
	_tmp12_[2] = _tmp4_;
	_tmp12_[3] = _tmp5_;
	_tmp12_[4] = _tmp6_;
	_tmp12_[5] = _tmp7_;
	_tmp12_[6] = _tmp8_;
	_tmp12_[7] = _tmp9_;
	_tmp12_[8] = _tmp10_;
	_tmp12_[9] = _tmp11_;
	_tmp13_ = _tmp12_;
	_tmp13__length1 = 10;
	_tmp14_ = fso_gsm_at_command_sequence_new (_tmp13_, 10);
	_tmp15_ = _tmp14_;
	fso_gsm_modem_registerAtCommandSequence ((FsoGsmModem*) self, "main", "init", _tmp15_);
	_fso_gsm_at_command_sequence_unref0 (_tmp15_);
	_tmp13_ = (_vala_array_free (_tmp13_, _tmp13__length1, (GDestroyNotify) g_free), NULL);
	_tmp16_ = g_strdup ("+CNMI=2,1,2,2,1");
	_tmp17_ = g_new0 (gchar*, 1 + 1);
	_tmp17_[0] = _tmp16_;
	_tmp18_ = _tmp17_;
	_tmp18__length1 = 1;
	_tmp19_ = fso_gsm_at_command_sequence_new (_tmp18_, 1);
	_tmp20_ = _tmp19_;
	fso_gsm_modem_registerAtCommandSequence ((FsoGsmModem*) self, "main", "registered", _tmp20_);
	_fso_gsm_at_command_sequence_unref0 (_tmp20_);
	_tmp18_ = (_vala_array_free (_tmp18_, _tmp18__length1, (GDestroyNotify) g_free), NULL);
	_tmp21_ = g_strdup ("+CREG=0");
	_tmp22_ = g_strdup ("+CGREG=0");
	_tmp23_ = g_strdup ("+CGEREP=0,0");
	_tmp24_ = g_new0 (gchar*, 3 + 1);
	_tmp24_[0] = _tmp21_;
	_tmp24_[1] = _tmp22_;
	_tmp24_[2] = _tmp23_;
	_tmp25_ = _tmp24_;
	_tmp25__length1 = 3;
	_tmp26_ = fso_gsm_at_command_sequence_new (_tmp25_, 3);
	_tmp27_ = _tmp26_;
	fso_gsm_modem_registerAtCommandSequence ((FsoGsmModem*) self, "main", "suspend", _tmp27_);
	_fso_gsm_at_command_sequence_unref0 (_tmp27_);
	_tmp25_ = (_vala_array_free (_tmp25_, _tmp25__length1, (GDestroyNotify) g_free), NULL);
	_tmp28_ = g_strdup ("+CREG=2");
	_tmp29_ = g_strdup ("+CGREG=2");
	_tmp30_ = g_strdup ("+CGEREP=2,1");
	_tmp31_ = g_new0 (gchar*, 3 + 1);
	_tmp31_[0] = _tmp28_;
	_tmp31_[1] = _tmp29_;
	_tmp31_[2] = _tmp30_;
	_tmp32_ = _tmp31_;
	_tmp32__length1 = 3;
	_tmp33_ = fso_gsm_at_command_sequence_new (_tmp32_, 3);
	_tmp34_ = _tmp33_;
	fso_gsm_modem_registerAtCommandSequence ((FsoGsmModem*) self, "main", "resume", _tmp34_);
	_fso_gsm_at_command_sequence_unref0 (_tmp34_);
	_tmp32_ = (_vala_array_free (_tmp32_, _tmp32__length1, (GDestroyNotify) g_free), NULL);
}


static void qualcomm_htc_modem_real_createChannels (FsoGsmAbstractModem* base) {
	QualcommHtcModem * self;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	gint _tmp2_;
	FsoFrameworkTransport* _tmp3_ = NULL;
	FsoFrameworkTransport* transport;
	FsoGsmHtcAtParser* _tmp4_;
	FsoGsmHtcAtParser* parser;
	FsoGsmAtChannel* _tmp5_;
	FsoGsmAtChannel* _tmp6_;
	self = (QualcommHtcModem*) base;
	_tmp0_ = ((FsoGsmAbstractModem*) self)->modem_transport;
	_tmp1_ = ((FsoGsmAbstractModem*) self)->modem_port;
	_tmp2_ = ((FsoGsmAbstractModem*) self)->modem_speed;
	_tmp3_ = fso_framework_transport_create (_tmp0_, _tmp1_, (guint) _tmp2_, TRUE, TRUE);
	transport = _tmp3_;
	_tmp4_ = fso_gsm_htc_at_parser_new ();
	parser = _tmp4_;
	_tmp5_ = fso_gsm_at_channel_new (QUALCOMM_HTC_MODEM_CHANNEL_NAME, transport, (FsoFrameworkParser*) parser);
	_tmp6_ = _tmp5_;
	_g_object_unref0 (_tmp6_);
	_g_object_unref0 (parser);
	_g_object_unref0 (transport);
}


static FsoGsmChannel* qualcomm_htc_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query) {
	QualcommHtcModem * self;
	FsoGsmChannel* result = NULL;
	GeeHashMap* _tmp0_;
	gpointer _tmp1_ = NULL;
	self = (QualcommHtcModem*) base;
	g_return_val_if_fail (command != NULL, NULL);
	g_return_val_if_fail (query != NULL, NULL);
	_tmp0_ = ((FsoGsmAbstractModem*) self)->channels;
	_tmp1_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp0_, QUALCOMM_HTC_MODEM_CHANNEL_NAME);
	result = (FsoGsmChannel*) _tmp1_;
	return result;
}


static FsoGsmUnsolicitedResponseHandler* qualcomm_htc_modem_real_createUnsolicitedHandler (FsoGsmAbstractModem* base) {
	QualcommHtcModem * self;
	FsoGsmUnsolicitedResponseHandler* result = NULL;
	QualcommHtcUnsolicitedResponseHandler* _tmp0_;
	self = (QualcommHtcModem*) base;
	_tmp0_ = qualcomm_htc_unsolicited_response_handler_new ();
	result = (FsoGsmUnsolicitedResponseHandler*) _tmp0_;
	return result;
}


static void qualcomm_htc_modem_real_registerCustomAtCommands (FsoGsmAbstractModem* base, GeeHashMap* commands) {
	QualcommHtcModem * self;
	GeeHashMap* _tmp0_;
	self = (QualcommHtcModem*) base;
	g_return_if_fail (commands != NULL);
	_tmp0_ = commands;
	qualcomm_htc_registerCustomAtCommands (_tmp0_);
}


QualcommHtcModem* qualcomm_htc_modem_construct (GType object_type) {
	QualcommHtcModem * self = NULL;
	self = (QualcommHtcModem*) fso_gsm_abstract_modem_construct (object_type);
	return self;
}


QualcommHtcModem* qualcomm_htc_modem_new (void) {
	return qualcomm_htc_modem_construct (QUALCOMM_HTC_TYPE_MODEM);
}


static void qualcomm_htc_modem_class_init (QualcommHtcModemClass * klass) {
	qualcomm_htc_modem_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = qualcomm_htc_modem_real_repr;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->configureData = qualcomm_htc_modem_real_configureData;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createChannels = qualcomm_htc_modem_real_createChannels;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->channelForCommand = qualcomm_htc_modem_real_channelForCommand;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createUnsolicitedHandler = qualcomm_htc_modem_real_createUnsolicitedHandler;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->registerCustomAtCommands = qualcomm_htc_modem_real_registerCustomAtCommands;
}


static void qualcomm_htc_modem_instance_init (QualcommHtcModem * self) {
}


/**
 * @class QualcommHtc.Modem
 *
 * This modem plugin supports the Qualcomm MSM 7xxx chipset with HTC firmware as found
 * in devices such as
 * - HTC Dream (T-Mobile G1, Google ADP-1)
 * - HTC Magic
 * - HTC Raphael
 * - HTC Blackstone
 * - HTC Diamond
 *
 * The HTC firmware comes with some bugs in the parser and non-standard AT extensions,
 * which is the reason we can't cover these modems with the 'singleline' plugin.
 **/
GType qualcomm_htc_modem_get_type (void) {
	return qualcomm_htc_modem_type_id;
}


GType qualcomm_htc_modem_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (QualcommHtcModemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) qualcomm_htc_modem_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (QualcommHtcModem), 0, (GInstanceInitFunc) qualcomm_htc_modem_instance_init, NULL };
	qualcomm_htc_modem_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_MODEM, "QualcommHtcModem", &g_define_type_info, 0);
	return qualcomm_htc_modem_type_id;
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
	fso_framework_logger_debug (_tmp0_, "fsogsm.qualcomm_htc fso_factory_function");
	_tmp1_ = g_strdup ("fsogsmd.modem_qualcomm_htc");
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	fso_gsm_htc_at_parser_register_type (module);
	qualcomm_htc_plus_htcctzv_register_type (module);
	qualcomm_htc_my_plus_ceer_register_type (module);
	qualcomm_htc_unsolicited_response_handler_register_type (module);
	qualcomm_htc_modem_register_type (module);
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




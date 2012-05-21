/* testatcommand.c generated by valac 0.14.2, the Vala compiler
 * generated from testatcommand.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <fsogsm.h>
#include <freesmartphone.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))


extern GeeHashMap* commands;
GeeHashMap* commands = NULL;

void setup (void);
FsoGsmAtCommand* atCommandFactory (const gchar* command);
void test_atcommand_PlusCFUN (void);
void test_atcommand_PlusCGCLASS (void);
void test_atcommand_PlusCGMI (void);
void test_atcommand_PlusCGMM (void);
void test_atcommand_PlusCGMR (void);
void test_atcommand_PlusCGSN (void);
void test_atcommand_PlusCOPS (void);
void test_atcommand_PlusCPIN (void);
void test_atcommand_PlusFCLASS (void);
void _vala_main (gchar** args, int args_length1);
static void _test_atcommand_PlusCFUN_gcallback (void);
static void _test_atcommand_PlusCGCLASS_gcallback (void);
static void _test_atcommand_PlusCGMM_gcallback (void);
static void _test_atcommand_PlusCGMR_gcallback (void);
static void _test_atcommand_PlusCGSN_gcallback (void);
static void _test_atcommand_PlusCOPS_gcallback (void);
static void _test_atcommand_PlusCPIN_gcallback (void);
static void _test_atcommand_PlusFCLASS_gcallback (void);


void setup (void) {
	GeeHashMap* _tmp0_;
	GeeHashMap* _tmp1_;
	_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, FSO_GSM_TYPE_AT_COMMAND, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	_g_object_unref0 (commands);
	commands = _tmp0_;
	_tmp1_ = commands;
	fso_gsm_registerGenericAtCommands (_tmp1_);
}


FsoGsmAtCommand* atCommandFactory (const gchar* command) {
	FsoGsmAtCommand* result = NULL;
	GeeHashMap* _tmp0_;
	GeeHashMap* _tmp1_;
	const gchar* _tmp2_;
	gpointer _tmp3_ = NULL;
	FsoGsmAtCommand* cmd;
	g_return_val_if_fail (command != NULL, NULL);
	_tmp0_ = commands;
	g_assert (_tmp0_ != NULL);
	_tmp1_ = commands;
	_tmp2_ = command;
	_tmp3_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp1_, _tmp2_);
	cmd = (FsoGsmAtCommand*) _tmp3_;
	g_assert (cmd != NULL);
	result = cmd;
	return result;
}


void test_atcommand_PlusCFUN (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusCFUN* cmd;
	FsoGsmPlusCFUN* _tmp1_;
	FsoGsmPlusCFUN* _tmp2_;
	gconstpointer _tmp3_;
	FsoGsmPlusCFUN* _tmp4_;
	gconstpointer _tmp5_;
	FsoGsmPlusCFUN* _tmp6_;
	FsoGsmPlusCFUN* _tmp7_;
	gconstpointer _tmp8_;
	FsoGsmPlusCFUN* _tmp10_;
	gchar* _tmp11_ = NULL;
	gchar* str;
	const gchar* _tmp12_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+CFUN");
	cmd = FSO_GSM_PLUS_CFUN (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "+CFUN: 0", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = ((FsoGsmSimpleAtCommand*) _tmp2_)->value;
	g_message ("testatcommand.vala:46: cmd.value = %d", GPOINTER_TO_INT (_tmp3_));
	_tmp4_ = cmd;
	_tmp5_ = ((FsoGsmSimpleAtCommand*) _tmp4_)->value;
	g_assert (GPOINTER_TO_INT (_tmp5_) == 0);
	_tmp6_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp6_, "+CFUN: 1", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp7_ = cmd;
	_tmp8_ = ((FsoGsmSimpleAtCommand*) _tmp7_)->value;
	g_assert (GPOINTER_TO_INT (_tmp8_) == 1);
	{
		FsoGsmPlusCFUN* _tmp9_;
		_tmp9_ = cmd;
		fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp9_, "+CFUN: NOTANINTEGER", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		g_assert_not_reached ();
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp10_ = cmd;
	_tmp11_ = fso_gsm_simple_at_command_issue ((FsoGsmSimpleAtCommand*) _tmp10_, GINT_TO_POINTER (1));
	str = _tmp11_;
	_tmp12_ = str;
	g_assert (g_strcmp0 (_tmp12_, "+CFUN=1") == 0);
	_g_free0 (str);
	_g_object_unref0 (cmd);
}


void test_atcommand_PlusCGCLASS (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusCGCLASS* cmd;
	FsoGsmPlusCGCLASS* _tmp1_;
	FsoGsmPlusCGCLASS* _tmp2_;
	gconstpointer _tmp3_;
	FsoGsmPlusCGCLASS* _tmp4_;
	FsoGsmPlusCGCLASS* _tmp5_;
	gconstpointer _tmp6_;
	FsoGsmPlusCGCLASS* _tmp8_;
	gchar* _tmp9_ = NULL;
	gchar* str;
	const gchar* _tmp10_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+CGCLASS");
	cmd = FSO_GSM_PLUS_CGCLASS (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "+CGCLASS: \"A\"", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = ((FsoGsmSimpleAtCommand*) _tmp2_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp3_, "A") == 0);
	_tmp4_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp4_, "+CGCLASS: A", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = cmd;
	_tmp6_ = ((FsoGsmSimpleAtCommand*) _tmp5_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp6_, "A") == 0);
	{
		FsoGsmPlusCGCLASS* _tmp7_;
		_tmp7_ = cmd;
		fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp7_, "PREFIX MISSING", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		g_assert_not_reached ();
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (e);
	}
	__finally1:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp8_ = cmd;
	_tmp9_ = fso_gsm_simple_at_command_issue ((FsoGsmSimpleAtCommand*) _tmp8_, "BX");
	str = _tmp9_;
	_tmp10_ = str;
	g_assert (g_strcmp0 (_tmp10_, "+CGCLASS=\"BX\"") == 0);
	_g_free0 (str);
	_g_object_unref0 (cmd);
}


void test_atcommand_PlusCGMI (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusCGMI* cmd;
	FsoGsmPlusCGMI* _tmp1_;
	FsoGsmPlusCGMI* _tmp2_;
	gconstpointer _tmp3_;
	FsoGsmPlusCGMI* _tmp4_;
	FsoGsmPlusCGMI* _tmp5_;
	gconstpointer _tmp6_;
	FsoGsmPlusCGMI* _tmp7_;
	FsoGsmPlusCGMI* _tmp8_;
	gconstpointer _tmp9_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+CGMI");
	cmd = FSO_GSM_PLUS_CGMI (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "+CGMI: FIC/OpenMoko", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = ((FsoGsmSimpleAtCommand*) _tmp2_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp3_, "FIC/OpenMoko") == 0);
	_tmp4_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp4_, "+CGMI: \"SIEMENS\"", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = cmd;
	_tmp6_ = ((FsoGsmSimpleAtCommand*) _tmp5_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp6_, "SIEMENS") == 0);
	_tmp7_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp7_, "HTC", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp8_ = cmd;
	_tmp9_ = ((FsoGsmSimpleAtCommand*) _tmp8_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp9_, "HTC") == 0);
	_g_object_unref0 (cmd);
}


void test_atcommand_PlusCGMM (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusCGMM* cmd;
	FsoGsmPlusCGMM* _tmp1_;
	FsoGsmPlusCGMM* _tmp2_;
	gconstpointer _tmp3_;
	FsoGsmPlusCGMM* _tmp4_;
	FsoGsmPlusCGMM* _tmp5_;
	gconstpointer _tmp6_;
	FsoGsmPlusCGMM* _tmp7_;
	FsoGsmPlusCGMM* _tmp8_;
	gconstpointer _tmp9_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+CGMM");
	cmd = FSO_GSM_PLUS_CGMM (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "+CGMM: \"Neo1973 GTA01/GTA02 Embedded GSM Modem\"", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = ((FsoGsmSimpleAtCommand*) _tmp2_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp3_, "Neo1973 GTA01/GTA02 Embedded GSM Modem") == 0);
	_tmp4_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp4_, "+CGMM: SIEMENS", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = cmd;
	_tmp6_ = ((FsoGsmSimpleAtCommand*) _tmp5_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp6_, "SIEMENS") == 0);
	_tmp7_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp7_, "HTC", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp8_ = cmd;
	_tmp9_ = ((FsoGsmSimpleAtCommand*) _tmp8_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp9_, "HTC") == 0);
	_g_object_unref0 (cmd);
}


void test_atcommand_PlusCGMR (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusCGMR* cmd;
	FsoGsmPlusCGMR* _tmp1_;
	FsoGsmPlusCGMR* _tmp2_;
	gconstpointer _tmp3_;
	FsoGsmPlusCGMR* _tmp4_;
	FsoGsmPlusCGMR* _tmp5_;
	gconstpointer _tmp6_;
	FsoGsmPlusCGMR* _tmp7_;
	FsoGsmPlusCGMR* _tmp8_;
	gconstpointer _tmp9_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+CGMR");
	cmd = FSO_GSM_PLUS_CGMR (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "+CGMR: \"GSM: gsm_ac_gp_fd_pu_em_cph_ds_vc_cal35_ri_36_amd8_ts0-Moko11" \
"b1\"", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = ((FsoGsmSimpleAtCommand*) _tmp2_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp3_, "GSM: gsm_ac_gp_fd_pu_em_cph_ds_vc_cal35_ri_36_amd8_ts0-Moko11b1") == 0);
	_tmp4_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp4_, "+CGMR: SIEMENS", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = cmd;
	_tmp6_ = ((FsoGsmSimpleAtCommand*) _tmp5_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp6_, "SIEMENS") == 0);
	_tmp7_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp7_, "HTC", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp8_ = cmd;
	_tmp9_ = ((FsoGsmSimpleAtCommand*) _tmp8_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp9_, "HTC") == 0);
	_g_object_unref0 (cmd);
}


void test_atcommand_PlusCGSN (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusCGSN* cmd;
	FsoGsmPlusCGSN* _tmp1_;
	FsoGsmPlusCGSN* _tmp2_;
	gconstpointer _tmp3_;
	FsoGsmPlusCGSN* _tmp4_;
	FsoGsmPlusCGSN* _tmp5_;
	gconstpointer _tmp6_;
	FsoGsmPlusCGSN* _tmp7_;
	FsoGsmPlusCGSN* _tmp8_;
	gconstpointer _tmp9_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+CGSN");
	cmd = FSO_GSM_PLUS_CGSN (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "+CGSN: 1234567890", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = ((FsoGsmSimpleAtCommand*) _tmp2_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp3_, "1234567890") == 0);
	_tmp4_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp4_, "+CGSN: \"1234567890\"", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = cmd;
	_tmp6_ = ((FsoGsmSimpleAtCommand*) _tmp5_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp6_, "1234567890") == 0);
	_tmp7_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp7_, "1234567890", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp8_ = cmd;
	_tmp9_ = ((FsoGsmSimpleAtCommand*) _tmp8_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp9_, "1234567890") == 0);
	_g_object_unref0 (cmd);
}


void test_atcommand_PlusCOPS (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusCOPS* cmd;
	FsoGsmPlusCOPS* _tmp1_;
	FsoGsmPlusCOPS* _tmp2_;
	gint _tmp3_;
	FsoGsmPlusCOPS* _tmp4_;
	gint _tmp5_;
	FsoGsmPlusCOPS* _tmp6_;
	const gchar* _tmp7_;
	FsoGsmPlusCOPS* _tmp8_;
	FsoGsmPlusCOPS* _tmp9_;
	gint _tmp10_;
	FsoGsmPlusCOPS* _tmp11_;
	gint _tmp12_;
	FsoGsmPlusCOPS* _tmp13_;
	const gchar* _tmp14_;
	FsoGsmPlusCOPS* _tmp15_;
	FsoGsmPlusCOPS* _tmp16_;
	FreeSmartphoneGSMNetworkProvider* _tmp17_;
	gint _tmp17__length1;
	FsoGsmPlusCOPS* _tmp18_;
	FreeSmartphoneGSMNetworkProvider* _tmp19_;
	gint _tmp19__length1;
	FreeSmartphoneGSMNetworkProvider _tmp20_;
	const gchar* _tmp21_;
	FsoGsmPlusCOPS* _tmp22_;
	FreeSmartphoneGSMNetworkProvider* _tmp23_;
	gint _tmp23__length1;
	FreeSmartphoneGSMNetworkProvider _tmp24_;
	const gchar* _tmp25_;
	FsoGsmPlusCOPS* _tmp26_;
	FreeSmartphoneGSMNetworkProvider* _tmp27_;
	gint _tmp27__length1;
	FreeSmartphoneGSMNetworkProvider _tmp28_;
	const gchar* _tmp29_;
	FsoGsmPlusCOPS* _tmp30_;
	FreeSmartphoneGSMNetworkProvider* _tmp31_;
	gint _tmp31__length1;
	FreeSmartphoneGSMNetworkProvider _tmp32_;
	const gchar* _tmp33_;
	FsoGsmPlusCOPS* _tmp34_;
	FreeSmartphoneGSMNetworkProvider* _tmp35_;
	gint _tmp35__length1;
	FreeSmartphoneGSMNetworkProvider _tmp36_;
	const gchar* _tmp37_;
	FsoGsmPlusCOPS* _tmp38_;
	FreeSmartphoneGSMNetworkProvider* _tmp39_;
	gint _tmp39__length1;
	FreeSmartphoneGSMNetworkProvider _tmp40_;
	const gchar* _tmp41_;
	FsoGsmPlusCOPS* _tmp42_;
	FreeSmartphoneGSMNetworkProvider* _tmp43_;
	gint _tmp43__length1;
	FreeSmartphoneGSMNetworkProvider _tmp44_;
	const gchar* _tmp45_;
	FsoGsmPlusCOPS* _tmp46_;
	FreeSmartphoneGSMNetworkProvider* _tmp47_;
	gint _tmp47__length1;
	FreeSmartphoneGSMNetworkProvider _tmp48_;
	const gchar* _tmp49_;
	FsoGsmPlusCOPS* _tmp50_;
	FreeSmartphoneGSMNetworkProvider* _tmp51_;
	gint _tmp51__length1;
	FreeSmartphoneGSMNetworkProvider _tmp52_;
	const gchar* _tmp53_;
	FsoGsmPlusCOPS* _tmp54_;
	FreeSmartphoneGSMNetworkProvider* _tmp55_;
	gint _tmp55__length1;
	FreeSmartphoneGSMNetworkProvider _tmp56_;
	const gchar* _tmp57_;
	FsoGsmPlusCOPS* _tmp58_;
	FreeSmartphoneGSMNetworkProvider* _tmp59_;
	gint _tmp59__length1;
	FreeSmartphoneGSMNetworkProvider _tmp60_;
	const gchar* _tmp61_;
	FsoGsmPlusCOPS* _tmp62_;
	FreeSmartphoneGSMNetworkProvider* _tmp63_;
	gint _tmp63__length1;
	FreeSmartphoneGSMNetworkProvider _tmp64_;
	const gchar* _tmp65_;
	FsoGsmPlusCOPS* _tmp66_;
	FreeSmartphoneGSMNetworkProvider* _tmp67_;
	gint _tmp67__length1;
	FreeSmartphoneGSMNetworkProvider _tmp68_;
	const gchar* _tmp69_;
	FsoGsmPlusCOPS* _tmp70_;
	FreeSmartphoneGSMNetworkProvider* _tmp71_;
	gint _tmp71__length1;
	FreeSmartphoneGSMNetworkProvider _tmp72_;
	const gchar* _tmp73_;
	FsoGsmPlusCOPS* _tmp74_;
	FreeSmartphoneGSMNetworkProvider* _tmp75_;
	gint _tmp75__length1;
	FreeSmartphoneGSMNetworkProvider _tmp76_;
	const gchar* _tmp77_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+COPS");
	cmd = FSO_GSM_PLUS_COPS (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "+COPS: 2", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = _tmp2_->status;
	g_assert (_tmp3_ == 2);
	_tmp4_ = cmd;
	_tmp5_ = _tmp4_->mode;
	g_assert (_tmp5_ == (-1));
	_tmp6_ = cmd;
	_tmp7_ = _tmp6_->oper;
	g_assert (g_strcmp0 (_tmp7_, "") == 0);
	_tmp8_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp8_, "+COPS: 0,3,\"E-Plus\"", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp9_ = cmd;
	_tmp10_ = _tmp9_->status;
	g_assert (_tmp10_ == 0);
	_tmp11_ = cmd;
	_tmp12_ = _tmp11_->mode;
	g_assert (_tmp12_ == 3);
	_tmp13_ = cmd;
	_tmp14_ = _tmp13_->oper;
	g_assert (g_strcmp0 (_tmp14_, "E-Plus") == 0);
	_tmp15_ = cmd;
	fso_gsm_abstract_at_command_parseTest ((FsoGsmAbstractAtCommand*) _tmp15_, "+COPS: (1,\"E-Plus\",\"E-Plus\",\"26203\"),(2,\"Vodafone.de\",\"Vodafo" \
"ne\",\"26202\",2),(3,\"T-Mobile D\",\"TMO D\",\"26201\")", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp16_ = cmd;
	_tmp17_ = _tmp16_->providers;
	_tmp17__length1 = _tmp16_->providers_length1;
	g_assert (_tmp17__length1 == 3);
	_tmp18_ = cmd;
	_tmp19_ = _tmp18_->providers;
	_tmp19__length1 = _tmp18_->providers_length1;
	_tmp20_ = _tmp19_[0];
	_tmp21_ = _tmp20_.status;
	g_assert (g_strcmp0 (_tmp21_, "available") == 0);
	_tmp22_ = cmd;
	_tmp23_ = _tmp22_->providers;
	_tmp23__length1 = _tmp22_->providers_length1;
	_tmp24_ = _tmp23_[0];
	_tmp25_ = _tmp24_.longname;
	g_assert (g_strcmp0 (_tmp25_, "E-Plus") == 0);
	_tmp26_ = cmd;
	_tmp27_ = _tmp26_->providers;
	_tmp27__length1 = _tmp26_->providers_length1;
	_tmp28_ = _tmp27_[0];
	_tmp29_ = _tmp28_.shortname;
	g_assert (g_strcmp0 (_tmp29_, "E-Plus") == 0);
	_tmp30_ = cmd;
	_tmp31_ = _tmp30_->providers;
	_tmp31__length1 = _tmp30_->providers_length1;
	_tmp32_ = _tmp31_[0];
	_tmp33_ = _tmp32_.mccmnc;
	g_assert (g_strcmp0 (_tmp33_, "26203") == 0);
	_tmp34_ = cmd;
	_tmp35_ = _tmp34_->providers;
	_tmp35__length1 = _tmp34_->providers_length1;
	_tmp36_ = _tmp35_[0];
	_tmp37_ = _tmp36_.act;
	g_assert (g_strcmp0 (_tmp37_, "GSM") == 0);
	_tmp38_ = cmd;
	_tmp39_ = _tmp38_->providers;
	_tmp39__length1 = _tmp38_->providers_length1;
	_tmp40_ = _tmp39_[1];
	_tmp41_ = _tmp40_.status;
	g_assert (g_strcmp0 (_tmp41_, "current") == 0);
	_tmp42_ = cmd;
	_tmp43_ = _tmp42_->providers;
	_tmp43__length1 = _tmp42_->providers_length1;
	_tmp44_ = _tmp43_[1];
	_tmp45_ = _tmp44_.longname;
	g_assert (g_strcmp0 (_tmp45_, "Vodafone.de") == 0);
	_tmp46_ = cmd;
	_tmp47_ = _tmp46_->providers;
	_tmp47__length1 = _tmp46_->providers_length1;
	_tmp48_ = _tmp47_[1];
	_tmp49_ = _tmp48_.shortname;
	g_assert (g_strcmp0 (_tmp49_, "Vodafone") == 0);
	_tmp50_ = cmd;
	_tmp51_ = _tmp50_->providers;
	_tmp51__length1 = _tmp50_->providers_length1;
	_tmp52_ = _tmp51_[1];
	_tmp53_ = _tmp52_.mccmnc;
	g_assert (g_strcmp0 (_tmp53_, "26202") == 0);
	_tmp54_ = cmd;
	_tmp55_ = _tmp54_->providers;
	_tmp55__length1 = _tmp54_->providers_length1;
	_tmp56_ = _tmp55_[1];
	_tmp57_ = _tmp56_.act;
	g_assert (g_strcmp0 (_tmp57_, "UMTS") == 0);
	_tmp58_ = cmd;
	_tmp59_ = _tmp58_->providers;
	_tmp59__length1 = _tmp58_->providers_length1;
	_tmp60_ = _tmp59_[2];
	_tmp61_ = _tmp60_.status;
	g_assert (g_strcmp0 (_tmp61_, "forbidden") == 0);
	_tmp62_ = cmd;
	_tmp63_ = _tmp62_->providers;
	_tmp63__length1 = _tmp62_->providers_length1;
	_tmp64_ = _tmp63_[2];
	_tmp65_ = _tmp64_.longname;
	g_assert (g_strcmp0 (_tmp65_, "T-Mobile D") == 0);
	_tmp66_ = cmd;
	_tmp67_ = _tmp66_->providers;
	_tmp67__length1 = _tmp66_->providers_length1;
	_tmp68_ = _tmp67_[2];
	_tmp69_ = _tmp68_.shortname;
	g_assert (g_strcmp0 (_tmp69_, "TMO D") == 0);
	_tmp70_ = cmd;
	_tmp71_ = _tmp70_->providers;
	_tmp71__length1 = _tmp70_->providers_length1;
	_tmp72_ = _tmp71_[2];
	_tmp73_ = _tmp72_.mccmnc;
	g_assert (g_strcmp0 (_tmp73_, "26201") == 0);
	_tmp74_ = cmd;
	_tmp75_ = _tmp74_->providers;
	_tmp75__length1 = _tmp74_->providers_length1;
	_tmp76_ = _tmp75_[2];
	_tmp77_ = _tmp76_.act;
	g_assert (g_strcmp0 (_tmp77_, "GSM") == 0);
	_g_object_unref0 (cmd);
}


void test_atcommand_PlusCPIN (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusCPIN* cmd;
	FsoGsmPlusCPIN* _tmp1_;
	FsoGsmPlusCPIN* _tmp2_;
	FreeSmartphoneGSMSIMAuthStatus _tmp3_;
	FsoGsmPlusCPIN* _tmp4_;
	FsoGsmPlusCPIN* _tmp5_;
	FreeSmartphoneGSMSIMAuthStatus _tmp6_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+CPIN");
	cmd = FSO_GSM_PLUS_CPIN (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "+CPIN: \"SIM PIN\"", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = _tmp2_->status;
	g_assert (_tmp3_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_PIN_REQUIRED);
	_tmp4_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp4_, "+CPIN: READY", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = cmd;
	_tmp6_ = _tmp5_->status;
	g_assert (_tmp6_ == FREE_SMARTPHONE_GSM_SIM_AUTH_STATUS_READY);
	{
		FsoGsmPlusCPIN* _tmp7_;
		_tmp7_ = cmd;
		fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp7_, "+CPIN THIS FAILS", &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
		}
		g_assert_not_reached ();
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (e);
	}
	__finally2:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (cmd);
}


void test_atcommand_PlusFCLASS (void) {
	FsoGsmAtCommand* _tmp0_ = NULL;
	FsoGsmPlusFCLASS* cmd;
	FsoGsmPlusFCLASS* _tmp1_;
	FsoGsmPlusFCLASS* _tmp2_;
	gconstpointer _tmp3_;
	FsoGsmPlusFCLASS* _tmp4_;
	FsoGsmPlusFCLASS* _tmp5_;
	gconstpointer _tmp6_;
	GError * _inner_error_ = NULL;
	_tmp0_ = atCommandFactory ("+FCLASS");
	cmd = FSO_GSM_PLUS_FCLASS (_tmp0_);
	_tmp1_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp1_, "0", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = cmd;
	_tmp3_ = ((FsoGsmSimpleAtCommand*) _tmp2_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp3_, "0") == 0);
	_tmp4_ = cmd;
	fso_gsm_abstract_at_command_parse ((FsoGsmAbstractAtCommand*) _tmp4_, "2.0", &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (cmd);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = cmd;
	_tmp6_ = ((FsoGsmSimpleAtCommand*) _tmp5_)->value;
	g_assert (g_strcmp0 ((const gchar*) _tmp6_, "2.0") == 0);
	_g_object_unref0 (cmd);
}


static void _test_atcommand_PlusCFUN_gcallback (void) {
	test_atcommand_PlusCFUN ();
}


static void _test_atcommand_PlusCGCLASS_gcallback (void) {
	test_atcommand_PlusCGCLASS ();
}


static void _test_atcommand_PlusCGMM_gcallback (void) {
	test_atcommand_PlusCGMM ();
}


static void _test_atcommand_PlusCGMR_gcallback (void) {
	test_atcommand_PlusCGMR ();
}


static void _test_atcommand_PlusCGSN_gcallback (void) {
	test_atcommand_PlusCGSN ();
}


static void _test_atcommand_PlusCOPS_gcallback (void) {
	test_atcommand_PlusCOPS ();
}


static void _test_atcommand_PlusCPIN_gcallback (void) {
	test_atcommand_PlusCPIN ();
}


static void _test_atcommand_PlusFCLASS_gcallback (void) {
	test_atcommand_PlusFCLASS ();
}


void _vala_main (gchar** args, int args_length1) {
	g_test_init (&args_length1, &args, NULL);
	setup ();
	g_test_add_func ("/AtCommand/+CFUN", _test_atcommand_PlusCFUN_gcallback);
	g_test_add_func ("/AtCommand/+CGCLASS", _test_atcommand_PlusCGCLASS_gcallback);
	g_test_add_func ("/AtCommand/+CGMM", _test_atcommand_PlusCGMM_gcallback);
	g_test_add_func ("/AtCommand/+CGMR", _test_atcommand_PlusCGMR_gcallback);
	g_test_add_func ("/AtCommand/+CGSN", _test_atcommand_PlusCGSN_gcallback);
	g_test_add_func ("/AtCommand/+COPS", _test_atcommand_PlusCOPS_gcallback);
	g_test_add_func ("/AtCommand/+CPIN", _test_atcommand_PlusCPIN_gcallback);
	g_test_add_func ("/AtCommand/+FCLASS", _test_atcommand_PlusFCLASS_gcallback);
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
}




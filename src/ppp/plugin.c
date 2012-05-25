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
 **/

#include <glib.h>
#include <glib-object.h>
#include <freesmartphone.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <./pppd-local.h>
#include <pppd/fsm.h>
#include <pppd/ipcp.h>
#include <arpa/inet.h>
#include <fsoframework.h>

#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _FsogsmdReportStatusData FsogsmdReportStatusData;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _FsogsmdReportStatusData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	GHashTable* properties;
	FreeSmartphoneGSMPDP* _tmp0_;
	gint _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	GHashTable* _tmp4_;
	GError* e0;
	GError* _tmp5_;
	const gchar* _tmp6_;
	const gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	GError* e1;
	GError* _tmp10_;
	const gchar* _tmp11_;
	const gchar* _tmp12_;
	gchar* _tmp13_;
	gchar* _tmp14_;
	GError* e2;
	GError* _tmp15_;
	const gchar* _tmp16_;
	const gchar* _tmp17_;
	gchar* _tmp18_;
	gchar* _tmp19_;
	GError* e3;
	GError* _tmp20_;
	const gchar* _tmp21_;
	const gchar* _tmp22_;
	gchar* _tmp23_;
	gchar* _tmp24_;
	GError * _inner_error_;
};


extern FreeSmartphoneGSMPDP* fsogsmd_pdp;
FreeSmartphoneGSMPDP* fsogsmd_pdp = NULL;

static void fsogsmd_report_status_data_free (gpointer _data);
void fsogsmd_report_status (GHashTable* properties, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fsogsmd_report_status_finish (GAsyncResult* _res_);
static gboolean fsogsmd_report_status_co (FsogsmdReportStatusData* _data_);
static void fsogsmd_report_status_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
void fsogsmd_on_phase_change (gint arg);
static void _g_free0_ (gpointer var);
static void _g_variant_unref0_ (gpointer var);
void fsogsmd_on_ip_up (gint arg);
static GVariant* _variant_new1 (const gchar* value);
static GVariant* _variant_new2 (guint32 value);
static GVariant* _variant_new3 (guint32 value);
static GVariant* _variant_new4 (guint32 value);
static GVariant* _variant_new5 (guint32 value);
static GVariant* _variant_new6 (guint32 value);
static GVariant* _variant_new7 (guint32 value);
void fsogsmd_on_exit (gint arg);
gint fsogsmd_get_chap_check (void);
gint fsogsmd_get_pap_check (void);
gint fsogsmd_get_credentials (const gchar* username, const gchar* password);
void plugin_init (void);
static void _fsogsmd_on_phase_change_notify_func (gpointer self, gint arg);
static void _fsogsmd_on_exit_notify_func (gpointer self, gint arg);
static void _fsogsmd_on_ip_up_notify_func (gpointer self, gint arg);
static gint _fsogsmd_get_credentials_chap_passwd_hook_func (const gchar* user, const gchar* passwd);
static gint _fsogsmd_get_chap_check_chap_check_hook_func (void);
static gint _fsogsmd_get_credentials_pap_passwd_hook_func (const gchar* user, const gchar* passwd);
static gint _fsogsmd_get_pap_check_pap_check_hook_func (void);


static void fsogsmd_report_status_data_free (gpointer _data) {
	FsogsmdReportStatusData* _data_;
	_data_ = _data;
	_g_hash_table_unref0 (_data_->properties);
	g_slice_free (FsogsmdReportStatusData, _data_);
}


static gpointer _g_hash_table_ref0 (gpointer self) {
	return self ? g_hash_table_ref (self) : NULL;
}


void fsogsmd_report_status (GHashTable* properties, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FsogsmdReportStatusData* _data_;
	GHashTable* _tmp0_;
	GHashTable* _tmp1_;
	_data_ = g_slice_new0 (FsogsmdReportStatusData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, fsogsmd_report_status);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fsogsmd_report_status_data_free);
	_tmp0_ = properties;
	_tmp1_ = _g_hash_table_ref0 (_tmp0_);
	_data_->properties = _tmp1_;
	fsogsmd_report_status_co (_data_);
}


void fsogsmd_report_status_finish (GAsyncResult* _res_) {
	FsogsmdReportStatusData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void fsogsmd_report_status_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FsogsmdReportStatusData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	fsogsmd_report_status_co (_data_);
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gboolean fsogsmd_report_status_co (FsogsmdReportStatusData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		_data_->_tmp0_ = fsogsmd_pdp;
		_data_->_tmp1_ = phase;
		_data_->_tmp2_ = NULL;
		_data_->_tmp2_ = g_strdup_printf ("%i", _data_->_tmp1_);
		_data_->_tmp3_ = _data_->_tmp2_;
		_data_->_tmp4_ = _data_->properties;
		_data_->_state_ = 1;
		free_smartphone_gsm_pdp_internal_status_update (_data_->_tmp0_, _data_->_tmp3_, _data_->_tmp4_, fsogsmd_report_status_ready, _data_);
		return FALSE;
		_state_1:
		free_smartphone_gsm_pdp_internal_status_update_finish (_data_->_tmp0_, _data_->_res_, &_data_->_inner_error_);
		_g_free0 (_data_->_tmp3_);
		if (_data_->_inner_error_ != NULL) {
			if (_data_->_inner_error_->domain == FREE_SMARTPHONE_GSM_ERROR) {
				goto __catch0_free_smartphone_gsm_error;
			}
			if (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
				goto __catch0_free_smartphone_error;
			}
			if (_data_->_inner_error_->domain == G_DBUS_ERROR) {
				goto __catch0_g_dbus_error;
			}
			if (_data_->_inner_error_->domain == G_IO_ERROR) {
				goto __catch0_g_io_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	goto __finally0;
	__catch0_free_smartphone_gsm_error:
	{
		_data_->e0 = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp5_ = _data_->e0;
		_data_->_tmp6_ = _data_->_tmp5_->message;
		_data_->_tmp7_ = NULL;
		_data_->_tmp7_ = string_to_string (_data_->_tmp6_);
		_data_->_tmp8_ = NULL;
		_data_->_tmp8_ = g_strconcat ("Can't report status to fsogsmd: ", _data_->_tmp7_, NULL);
		_data_->_tmp9_ = _data_->_tmp8_;
		error (_data_->_tmp9_, NULL);
		_g_free0 (_data_->_tmp9_);
		_g_error_free0 (_data_->e0);
	}
	goto __finally0;
	__catch0_free_smartphone_error:
	{
		_data_->e1 = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp10_ = _data_->e1;
		_data_->_tmp11_ = _data_->_tmp10_->message;
		_data_->_tmp12_ = NULL;
		_data_->_tmp12_ = string_to_string (_data_->_tmp11_);
		_data_->_tmp13_ = NULL;
		_data_->_tmp13_ = g_strconcat ("Can't report status to fsogsmd: ", _data_->_tmp12_, NULL);
		_data_->_tmp14_ = _data_->_tmp13_;
		error (_data_->_tmp14_, NULL);
		_g_free0 (_data_->_tmp14_);
		_g_error_free0 (_data_->e1);
	}
	goto __finally0;
	__catch0_g_dbus_error:
	{
		_data_->e2 = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp15_ = _data_->e2;
		_data_->_tmp16_ = _data_->_tmp15_->message;
		_data_->_tmp17_ = NULL;
		_data_->_tmp17_ = string_to_string (_data_->_tmp16_);
		_data_->_tmp18_ = NULL;
		_data_->_tmp18_ = g_strconcat ("Can't report status to fsogsmd: ", _data_->_tmp17_, NULL);
		_data_->_tmp19_ = _data_->_tmp18_;
		error (_data_->_tmp19_, NULL);
		_g_free0 (_data_->_tmp19_);
		_g_error_free0 (_data_->e2);
	}
	goto __finally0;
	__catch0_g_io_error:
	{
		_data_->e3 = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp20_ = _data_->e3;
		_data_->_tmp21_ = _data_->_tmp20_->message;
		_data_->_tmp22_ = NULL;
		_data_->_tmp22_ = string_to_string (_data_->_tmp21_);
		_data_->_tmp23_ = NULL;
		_data_->_tmp23_ = g_strconcat ("Can't report status to fsogsmd: ", _data_->_tmp22_, NULL);
		_data_->_tmp24_ = _data_->_tmp23_;
		error (_data_->_tmp24_, NULL);
		_g_free0 (_data_->_tmp24_);
		_g_error_free0 (_data_->e3);
	}
	__finally0:
	if (_data_->_inner_error_ != NULL) {
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


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_variant_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_variant_unref (var), NULL));
}


void fsogsmd_on_phase_change (gint arg) {
	gint _tmp0_;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	GHashFunc _tmp5_;
	GEqualFunc _tmp6_;
	GHashTable* _tmp7_;
	GHashTable* _tmp8_;
	_tmp0_ = arg;
	_tmp1_ = g_strdup_printf ("%i", _tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_strconcat ("on_phase_change: ", _tmp2_, NULL);
	_tmp4_ = _tmp3_;
	info (_tmp4_, NULL);
	_g_free0 (_tmp4_);
	_g_free0 (_tmp2_);
	_tmp5_ = g_str_hash;
	_tmp6_ = g_str_equal;
	_tmp7_ = g_hash_table_new_full (_tmp5_, _tmp6_, _g_free0_, _g_variant_unref0_);
	_tmp8_ = _tmp7_;
	fsogsmd_report_status (_tmp8_, NULL, NULL);
	_g_hash_table_unref0 (_tmp8_);
}


static GVariant* _variant_new1 (const gchar* value) {
	return g_variant_ref_sink (g_variant_new_string (value));
}


static GVariant* _variant_new2 (guint32 value) {
	return g_variant_ref_sink (g_variant_new_uint32 (value));
}


static GVariant* _variant_new3 (guint32 value) {
	return g_variant_ref_sink (g_variant_new_uint32 (value));
}


static GVariant* _variant_new4 (guint32 value) {
	return g_variant_ref_sink (g_variant_new_uint32 (value));
}


static GVariant* _variant_new5 (guint32 value) {
	return g_variant_ref_sink (g_variant_new_uint32 (value));
}


static GVariant* _variant_new6 (guint32 value) {
	return g_variant_ref_sink (g_variant_new_uint32 (value));
}


static GVariant* _variant_new7 (guint32 value) {
	return g_variant_ref_sink (g_variant_new_uint32 (value));
}


void fsogsmd_on_ip_up (gint arg) {
	struct ipcp_options* _tmp0_;
	gint _tmp0__length1;
	struct ipcp_options _tmp1_;
	guint32 _tmp2_;
	guint32 ouraddr;
	gchar* _tmp3_;
	gint _tmp3__length1;
	gchar* _tmp4_;
	gchar* iface;
	GHashFunc _tmp5_;
	GEqualFunc _tmp6_;
	GHashTable* _tmp7_;
	GHashTable* properties;
	GHashTable* _tmp8_;
	gchar* _tmp9_;
	const gchar* _tmp10_;
	GVariant* _tmp11_;
	GHashTable* _tmp12_;
	gchar* _tmp13_;
	GVariant* _tmp14_;
	gint _tmp15_;
	guint32 _tmp16_ = 0U;
	guint32 fantasyaddr;
	struct ipcp_options* _tmp17_;
	gint _tmp17__length1;
	struct ipcp_options _tmp18_;
	guint32 _tmp19_;
	guint32 hisaddr;
	struct ipcp_options* _tmp20_;
	gint _tmp20__length1;
	struct ipcp_options _tmp21_;
	guint32* _tmp22_;
	gint _tmp22__length1;
	guint32 _tmp23_;
	guint32 dns1;
	struct ipcp_options* _tmp24_;
	gint _tmp24__length1;
	struct ipcp_options _tmp25_;
	guint32* _tmp26_;
	gint _tmp26__length1;
	guint32 _tmp27_;
	guint32 dns2;
	struct ipcp_options* _tmp28_;
	gint _tmp28__length1;
	struct ipcp_options _tmp29_;
	guint32 _tmp30_;
	guint32 peer_hisaddr;
	guint32 _tmp31_;
	guint32 _tmp32_;
	gboolean _tmp33_ = FALSE;
	guint32 _tmp34_;
	gboolean _tmp37_;
	guint32 _tmp53_;
	guint32 _tmp58_;
	GHashTable* _tmp63_;
	info ("on_ip_up", NULL);
	_tmp0_ = ipcp_gotoptions;
	_tmp0__length1 = -1;
	_tmp1_ = _tmp0_[0];
	_tmp2_ = _tmp1_.ouraddr;
	ouraddr = _tmp2_;
	if (ouraddr == ((guint32) 0)) {
		info ("on_ip_up: ouraddr is empty; can't proceed", NULL);
		g_assert_not_reached ();
	}
	_tmp3_ = ifname;
	_tmp3__length1 = -1;
	_tmp4_ = g_strdup ((const gchar*) _tmp3_);
	iface = _tmp4_;
	_tmp5_ = g_str_hash;
	_tmp6_ = g_str_equal;
	_tmp7_ = g_hash_table_new_full (_tmp5_, _tmp6_, _g_free0_, _g_variant_unref0_);
	properties = _tmp7_;
	_tmp8_ = properties;
	_tmp9_ = g_strdup ("iface");
	_tmp10_ = iface;
	_tmp11_ = _variant_new1 (_tmp10_);
	g_hash_table_insert (_tmp8_, _tmp9_, _tmp11_);
	_tmp12_ = properties;
	_tmp13_ = g_strdup ("local");
	_tmp14_ = _variant_new2 (ouraddr);
	g_hash_table_insert (_tmp12_, _tmp13_, _tmp14_);
	_tmp15_ = ifunit;
	_tmp16_ = htonl ((guint32) (0x0a404040 + _tmp15_));
	fantasyaddr = _tmp16_;
	_tmp17_ = ipcp_gotoptions;
	_tmp17__length1 = -1;
	_tmp18_ = _tmp17_[0];
	_tmp19_ = _tmp18_.hisaddr;
	hisaddr = _tmp19_;
	_tmp20_ = ipcp_gotoptions;
	_tmp20__length1 = -1;
	_tmp21_ = _tmp20_[0];
	_tmp22_ = _tmp21_.dnsaddr;
	_tmp22__length1 = -1;
	_tmp23_ = _tmp22_[0];
	dns1 = _tmp23_;
	_tmp24_ = ipcp_gotoptions;
	_tmp24__length1 = -1;
	_tmp25_ = _tmp24_[0];
	_tmp26_ = _tmp25_.dnsaddr;
	_tmp26__length1 = -1;
	_tmp27_ = _tmp26_[1];
	dns2 = _tmp27_;
	_tmp28_ = ipcp_hisoptions;
	_tmp28__length1 = -1;
	_tmp29_ = _tmp28_[0];
	_tmp30_ = _tmp29_.hisaddr;
	peer_hisaddr = _tmp30_;
	_tmp31_ = hisaddr;
	_tmp32_ = peer_hisaddr;
	info ("on_ip_up: our remote address is %u, his remote address is %u", _tmp31_, _tmp32_, NULL);
	_tmp34_ = peer_hisaddr;
	if (_tmp34_ != ((guint32) 0)) {
		guint32 _tmp35_;
		guint32 _tmp36_;
		_tmp35_ = peer_hisaddr;
		_tmp36_ = fantasyaddr;
		_tmp33_ = _tmp35_ != _tmp36_;
	} else {
		_tmp33_ = FALSE;
	}
	_tmp37_ = _tmp33_;
	if (_tmp37_) {
		GHashTable* _tmp38_;
		gchar* _tmp39_;
		guint32 _tmp40_;
		GVariant* _tmp41_;
		_tmp38_ = properties;
		_tmp39_ = g_strdup ("gateway");
		_tmp40_ = peer_hisaddr;
		_tmp41_ = _variant_new3 (_tmp40_);
		g_hash_table_insert (_tmp38_, _tmp39_, _tmp41_);
	} else {
		guint32 _tmp42_;
		_tmp42_ = hisaddr;
		if (_tmp42_ != ((guint32) 0)) {
			GHashTable* _tmp43_;
			gchar* _tmp44_;
			guint32 _tmp45_;
			GVariant* _tmp46_;
			_tmp43_ = properties;
			_tmp44_ = g_strdup ("gateway");
			_tmp45_ = hisaddr;
			_tmp46_ = _variant_new4 (_tmp45_);
			g_hash_table_insert (_tmp43_, _tmp44_, _tmp46_);
		} else {
			guint32 _tmp47_;
			guint32 _tmp48_;
			_tmp47_ = peer_hisaddr;
			_tmp48_ = fantasyaddr;
			if (_tmp47_ == _tmp48_) {
				GHashTable* _tmp49_;
				gchar* _tmp50_;
				guint32 _tmp51_;
				GVariant* _tmp52_;
				_tmp49_ = properties;
				_tmp50_ = g_strdup ("gateway");
				_tmp51_ = fantasyaddr;
				_tmp52_ = _variant_new5 (_tmp51_);
				g_hash_table_insert (_tmp49_, _tmp50_, _tmp52_);
			} else {
				g_assert_not_reached ();
			}
		}
	}
	_tmp53_ = dns1;
	if (_tmp53_ != ((guint32) 0)) {
		GHashTable* _tmp54_;
		gchar* _tmp55_;
		guint32 _tmp56_;
		GVariant* _tmp57_;
		_tmp54_ = properties;
		_tmp55_ = g_strdup ("dns1");
		_tmp56_ = dns1;
		_tmp57_ = _variant_new6 (_tmp56_);
		g_hash_table_insert (_tmp54_, _tmp55_, _tmp57_);
	}
	_tmp58_ = dns2;
	if (_tmp58_ != ((guint32) 0)) {
		GHashTable* _tmp59_;
		gchar* _tmp60_;
		guint32 _tmp61_;
		GVariant* _tmp62_;
		_tmp59_ = properties;
		_tmp60_ = g_strdup ("dns2");
		_tmp61_ = dns2;
		_tmp62_ = _variant_new7 (_tmp61_);
		g_hash_table_insert (_tmp59_, _tmp60_, _tmp62_);
	}
	_tmp63_ = properties;
	fsogsmd_report_status (_tmp63_, NULL, NULL);
	_g_hash_table_unref0 (properties);
	_g_free0 (iface);
}


void fsogsmd_on_exit (gint arg) {
	info ("on_exit", NULL);
}


gint fsogsmd_get_chap_check (void) {
	gint result = 0;
	info ("get_chap_check", NULL);
	result = 1;
	return result;
}


gint fsogsmd_get_pap_check (void) {
	gint result = 0;
	info ("get_pap_check", NULL);
	result = 1;
	return result;
}


gint fsogsmd_get_credentials (const gchar* username, const gchar* password) {
	gint result = 0;
	gboolean _tmp0_ = FALSE;
	const gchar* _tmp1_;
	gboolean _tmp3_;
	info ("get_credentials", NULL);
	_tmp1_ = username;
	if (_tmp1_ != NULL) {
		const gchar* _tmp2_;
		_tmp2_ = password;
		_tmp0_ = _tmp2_ == NULL;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		result = 1;
		return result;
	}
	username = "";
	password = "";
	result = 1;
	return result;
}


static void _fsogsmd_on_phase_change_notify_func (gpointer self, gint arg) {
	fsogsmd_on_phase_change (arg);
}


static void _fsogsmd_on_exit_notify_func (gpointer self, gint arg) {
	fsogsmd_on_exit (arg);
}


static void _fsogsmd_on_ip_up_notify_func (gpointer self, gint arg) {
	fsogsmd_on_ip_up (arg);
}


static gint _fsogsmd_get_credentials_chap_passwd_hook_func (const gchar* user, const gchar* passwd) {
	gint result;
	result = fsogsmd_get_credentials (user, passwd);
	return result;
}


static gint _fsogsmd_get_chap_check_chap_check_hook_func (void) {
	gint result;
	result = fsogsmd_get_chap_check ();
	return result;
}


static gint _fsogsmd_get_credentials_pap_passwd_hook_func (const gchar* user, const gchar* passwd) {
	gint result;
	result = fsogsmd_get_credentials (user, passwd);
	return result;
}


static gint _fsogsmd_get_pap_check_pap_check_hook_func (void) {
	gint result;
	result = fsogsmd_get_pap_check ();
	return result;
}


void plugin_init (void) {
	GError * _inner_error_ = NULL;
	info ("fsogsmd plugin init", NULL);
	add_notifier (&phasechange, _fsogsmd_on_phase_change_notify_func, NULL);
	add_notifier (&exitnotify, _fsogsmd_on_exit_notify_func, NULL);
	add_notifier (&ip_up_notifier, _fsogsmd_on_ip_up_notify_func, NULL);
	chap_passwd_hook = _fsogsmd_get_credentials_chap_passwd_hook_func;
	chap_check_hook = _fsogsmd_get_chap_check_chap_check_hook_func;
	pap_passwd_hook = _fsogsmd_get_credentials_pap_passwd_hook_func;
	pap_check_hook = _fsogsmd_get_pap_check_pap_check_hook_func;
	{
		FreeSmartphoneGSMPDP* _tmp0_ = NULL;
		FreeSmartphoneGSMPDP* _tmp1_;
		_tmp0_ = g_initable_new (FREE_SMARTPHONE_GSM_TYPE_PDP_PROXY, NULL, &_inner_error_, "g-flags", 0, "g-name", FSO_FRAMEWORK_GSM_ServiceDBusName, "g-bus-type", G_BUS_TYPE_SYSTEM, "g-object-path", FSO_FRAMEWORK_GSM_DeviceServicePath, "g-interface-name", "org.freesmartphone.GSM.PDP", NULL);
		_tmp1_ = (FreeSmartphoneGSMPDP*) _tmp0_;
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		_g_object_unref0 (fsogsmd_pdp);
		fsogsmd_pdp = _tmp1_;
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError* e = NULL;
		GError* _tmp2_;
		const gchar* _tmp3_;
		const gchar* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp2_ = e;
		_tmp3_ = _tmp2_->message;
		_tmp4_ = string_to_string (_tmp3_);
		_tmp5_ = g_strconcat ("IOError while initializing plugin: ", _tmp4_, NULL);
		_tmp6_ = _tmp5_;
		error (_tmp6_, NULL);
		_g_free0 (_tmp6_);
		_g_error_free0 (e);
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}




/* testcb.c generated by valac 0.14.2, the Vala compiler
 * generated from testcb.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <smsutil.h>
#include <conversions.h>
#include <util.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _cbs_free0(var) ((var == NULL) ? NULL : (var = (cbs_free (var), NULL)))
#define _g_slist_free0(var) ((var == NULL) ? NULL : (var = (g_slist_free (var), NULL)))



void test_cb_decode1 (void);
void test_cb_decode2 (void);
void test_cb_decode3 (void);
void _vala_main (gchar** args, int args_length1);
static void _test_cb_decode1_gcallback (void);
static void _test_cb_decode2_gcallback (void);
static void _test_cb_decode3_gcallback (void);


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static struct cbs* cbs_newFromHexPdu (const gchar* hexpdu, gint tpdulen) {
	struct cbs* result = NULL;
	glong items_written;
	gchar* _tmp0_ = NULL;
	gchar* binpdu;
	gint binpdu_length1;
	gint _binpdu_size_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	gint _tmp2__length1;
	glong _tmp3_ = 0L;
	glong _tmp4_;
	struct cbs* _tmp5_;
	struct cbs* cb;
	gchar* _tmp6_;
	gint _tmp6__length1;
	gint _tmp7_;
	struct cbs* _tmp8_;
	gboolean _tmp9_ = FALSE;
	gboolean res;
	gboolean _tmp10_;
	g_return_val_if_fail (hexpdu != NULL, NULL);
	items_written = (glong) (-1);
	_tmp0_ = g_new0 (gchar, 1024);
	binpdu = _tmp0_;
	binpdu_length1 = 1024;
	_binpdu_size_ = binpdu_length1;
	_tmp1_ = hexpdu;
	_tmp2_ = binpdu;
	_tmp2__length1 = binpdu_length1;
	decode_hex_own_buf (_tmp1_, (glong) (-1), &_tmp3_, (gchar) 0, _tmp2_);
	items_written = _tmp3_;
	_tmp4_ = items_written;
	g_assert (_tmp4_ != ((glong) (-1)));
	_tmp5_ = cbs_new ();
	cb = _tmp5_;
	_tmp6_ = binpdu;
	_tmp6__length1 = binpdu_length1;
	_tmp7_ = tpdulen;
	_tmp8_ = cb;
	_tmp9_ = cbs_decode (_tmp6_, _tmp7_, _tmp8_);
	res = _tmp9_;
	_tmp10_ = res;
	if (!_tmp10_) {
		gint _tmp11_;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_;
		const gchar* _tmp14_;
		const gchar* _tmp15_ = NULL;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_;
		_tmp11_ = tpdulen;
		_tmp12_ = g_strdup_printf ("%i", _tmp11_);
		_tmp13_ = _tmp12_;
		_tmp14_ = hexpdu;
		_tmp15_ = string_to_string (_tmp14_);
		_tmp16_ = g_strconcat ("Cb.Message::newFromHexPdu: could not decode message w/ tpdulen ", _tmp13_, " and hexpdu ", _tmp15_, NULL);
		_tmp17_ = _tmp16_;
		g_warning ("fsogsm3rdparty.vapi:852: %s", _tmp17_);
		_g_free0 (_tmp17_);
		_g_free0 (_tmp13_);
		result = NULL;
		_cbs_free0 (cb);
		binpdu = (g_free (binpdu), NULL);
		return result;
	} else {
		result = cb;
		binpdu = (g_free (binpdu), NULL);
		return result;
	}
	_cbs_free0 (cb);
	binpdu = (g_free (binpdu), NULL);
}


static gchar* cbs_language_to_string (enum cbs_language lang) {
	gchar* result = NULL;
	enum cbs_language _tmp0_;
	_tmp0_ = lang;
	switch (_tmp0_) {
		case CBS_LANGUAGE_GERMAN:
		{
			gchar* _tmp1_;
			_tmp1_ = g_strdup ("de");
			result = _tmp1_;
			return result;
		}
		case CBS_LANGUAGE_ENGLISH:
		{
			gchar* _tmp2_;
			_tmp2_ = g_strdup ("en");
			result = _tmp2_;
			return result;
		}
		case CBS_LANGUAGE_ITALIAN:
		{
			gchar* _tmp3_;
			_tmp3_ = g_strdup ("it");
			result = _tmp3_;
			return result;
		}
		case CBS_LANGUAGE_FRENCH:
		{
			gchar* _tmp4_;
			_tmp4_ = g_strdup ("fr");
			result = _tmp4_;
			return result;
		}
		case CBS_LANGUAGE_SPANISH:
		{
			gchar* _tmp5_;
			_tmp5_ = g_strdup ("es");
			result = _tmp5_;
			return result;
		}
		case CBS_LANGUAGE_DUTCH:
		{
			gchar* _tmp6_;
			_tmp6_ = g_strdup ("nl");
			result = _tmp6_;
			return result;
		}
		case CBS_LANGUAGE_SWEDISH:
		{
			gchar* _tmp7_;
			_tmp7_ = g_strdup ("se");
			result = _tmp7_;
			return result;
		}
		case CBS_LANGUAGE_DANISH:
		{
			gchar* _tmp8_;
			_tmp8_ = g_strdup ("dk");
			result = _tmp8_;
			return result;
		}
		case CBS_LANGUAGE_PORTUGESE:
		{
			gchar* _tmp9_;
			_tmp9_ = g_strdup ("pg");
			result = _tmp9_;
			return result;
		}
		case CBS_LANGUAGE_FINNISH:
		{
			gchar* _tmp10_;
			_tmp10_ = g_strdup ("fi");
			result = _tmp10_;
			return result;
		}
		case CBS_LANGUAGE_NORWEGIAN:
		{
			gchar* _tmp11_;
			_tmp11_ = g_strdup ("no");
			result = _tmp11_;
			return result;
		}
		case CBS_LANGUAGE_GREEK:
		{
			gchar* _tmp12_;
			_tmp12_ = g_strdup ("gr");
			result = _tmp12_;
			return result;
		}
		case CBS_LANGUAGE_TURKISH:
		{
			gchar* _tmp13_;
			_tmp13_ = g_strdup ("tr");
			result = _tmp13_;
			return result;
		}
		case CBS_LANGUAGE_HUNGARIAN:
		{
			gchar* _tmp14_;
			_tmp14_ = g_strdup ("hu");
			result = _tmp14_;
			return result;
		}
		case CBS_LANGUAGE_POLISH:
		{
			gchar* _tmp15_;
			_tmp15_ = g_strdup ("pl");
			result = _tmp15_;
			return result;
		}
		case CBS_LANGUAGE_CZECH:
		{
			gchar* _tmp16_;
			_tmp16_ = g_strdup ("cz");
			result = _tmp16_;
			return result;
		}
		case CBS_LANGUAGE_HEBREW:
		{
			gchar* _tmp17_;
			_tmp17_ = g_strdup ("il");
			result = _tmp17_;
			return result;
		}
		case CBS_LANGUAGE_ARABIC:
		{
			gchar* _tmp18_;
			_tmp18_ = g_strdup ("ae");
			result = _tmp18_;
			return result;
		}
		case CBS_LANGUAGE_RUSSIAN:
		{
			gchar* _tmp19_;
			_tmp19_ = g_strdup ("ru");
			result = _tmp19_;
			return result;
		}
		case CBS_LANGUAGE_ICELANDIC:
		{
			gchar* _tmp20_;
			_tmp20_ = g_strdup ("is");
			result = _tmp20_;
			return result;
		}
		default:
		{
			gchar* _tmp21_;
			_tmp21_ = g_strdup ("unspecified");
			result = _tmp21_;
			return result;
		}
	}
}


static gchar* cbs_decode_all (struct cbs* self, gchar** language) {
	gchar* _vala_language = NULL;
	gchar* result = NULL;
	gboolean udhi = FALSE;
	enum sms_class cls = 0;
	enum sms_charset charset = 0;
	gboolean compressed = FALSE;
	enum cbs_language lang = 0;
	gboolean iso639 = FALSE;
	guint8 _tmp0_;
	gboolean _tmp1_ = FALSE;
	enum sms_class _tmp2_ = 0;
	enum sms_charset _tmp3_ = 0;
	gboolean _tmp4_ = FALSE;
	enum cbs_language _tmp5_ = 0;
	gboolean _tmp6_ = FALSE;
	gboolean _tmp7_ = FALSE;
	gchar* _tmp9_ = NULL;
	gchar* iso639_2;
	gint iso639_2_length1;
	gint _iso639_2_size_;
	GSList* list;
	GSList* _tmp10_;
	gchar* _tmp11_;
	gint _tmp11__length1;
	gchar* _tmp12_ = NULL;
	gchar* text;
	gchar* _tmp13_ = NULL;
	gchar* _tmp14_;
	gint _tmp14__length1;
	gchar _tmp15_;
	const gchar* _tmp20_;
	gchar* _tmp21_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->dcs;
	_tmp7_ = cbs_dcs_decode (_tmp0_, &_tmp1_, &_tmp2_, &_tmp3_, &_tmp4_, &_tmp5_, &_tmp6_);
	udhi = _tmp1_;
	cls = _tmp2_;
	charset = _tmp3_;
	compressed = _tmp4_;
	lang = _tmp5_;
	iso639 = _tmp6_;
	if (!_tmp7_) {
		gchar* _tmp8_;
		g_warning ("fsogsm3rdparty.vapi:814: %s", "Cb.Message::to_string: could not decode dcs");
		_tmp8_ = g_strdup ("<unknown/invalid>");
		result = _tmp8_;
		if (language) {
			*language = _vala_language;
		} else {
			_g_free0 (_vala_language);
		}
		return result;
	}
	_tmp9_ = g_new0 (gchar, 3);
	iso639_2 = _tmp9_;
	iso639_2_length1 = 3;
	_iso639_2_size_ = iso639_2_length1;
	list = NULL;
	list = g_slist_append (list, self);
	_tmp10_ = list;
	_tmp11_ = iso639_2;
	_tmp11__length1 = iso639_2_length1;
	_tmp12_ = cbs_decode_text (_tmp10_, _tmp11_);
	text = _tmp12_;
	_tmp14_ = iso639_2;
	_tmp14__length1 = iso639_2_length1;
	_tmp15_ = _tmp14_[0];
	if (_tmp15_ != '\0') {
		gchar* _tmp16_;
		gint _tmp16__length1;
		gchar* _tmp17_;
		_tmp16_ = iso639_2;
		_tmp16__length1 = iso639_2_length1;
		_tmp17_ = g_strdup ((const gchar*) _tmp16_);
		_g_free0 (_tmp13_);
		_tmp13_ = _tmp17_;
	} else {
		enum cbs_language _tmp18_;
		gchar* _tmp19_ = NULL;
		_tmp18_ = lang;
		_tmp19_ = cbs_language_to_string (_tmp18_);
		_g_free0 (_tmp13_);
		_tmp13_ = _tmp19_;
	}
	_tmp20_ = _tmp13_;
	_tmp21_ = g_strdup (_tmp20_);
	_g_free0 (_vala_language);
	_vala_language = _tmp21_;
	result = text;
	_g_free0 (_tmp13_);
	_g_slist_free0 (list);
	iso639_2 = (g_free (iso639_2), NULL);
	if (language) {
		*language = _vala_language;
	} else {
		_g_free0 (_vala_language);
	}
	return result;
}


void test_cb_decode1 (void) {
	gchar* _tmp0_;
	gchar* hexpdu;
	gint hexpdulen;
	struct cbs* _tmp1_ = NULL;
	struct cbs* msg;
	gchar* lang = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* text;
	const gchar* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_;
	_tmp0_ = g_strdup ("011000320111C2327BFC76BBCBEE46A3D168341A8D46A3D168341A8D46A3D168341A8D" \
"46A3D168341A8D46A3D168341A8D46A3D168341A8D46A3D168341A8D46A3D168341A8D" \
"46A3D168341A8D46A3D168341A8D46A3D100");
	hexpdu = _tmp0_;
	hexpdulen = 88;
	_tmp1_ = cbs_newFromHexPdu (hexpdu, hexpdulen);
	msg = _tmp1_;
	_tmp3_ = cbs_decode_all (msg, &_tmp2_);
	_g_free0 (lang);
	lang = _tmp2_;
	text = _tmp3_;
	_tmp4_ = string_to_string (lang);
	_tmp5_ = string_to_string (text);
	_tmp6_ = g_strconcat ("lang = ", _tmp4_, "; text = ", _tmp5_, NULL);
	_tmp7_ = _tmp6_;
	g_message ("testcb.vala:35: %s", _tmp7_);
	_g_free0 (_tmp7_);
	g_assert (g_strcmp0 (lang, "en") == 0);
	g_assert (g_strcmp0 (text, "Belconnen") == 0);
	_g_free0 (text);
	_g_free0 (lang);
	_cbs_free0 (msg);
	_g_free0 (hexpdu);
}


void test_cb_decode2 (void) {
	gchar* _tmp0_;
	gchar* hexpdu;
	gint hexpdulen;
	struct cbs* _tmp1_ = NULL;
	struct cbs* msg;
	gchar* lang = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* text;
	const gchar* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_;
	_tmp0_ = g_strdup ("001000DD001133DAED46ABD56AB5186CD668341A8D46A3D168341A8D46A3D168341A8D" \
"46A3D168341A8D46A3D168341A8D46A3D168341A8D46A3D168341A8D46A3D168341A8D" \
"46A3D168341A8D46A3D168341A8D46A3D100");
	hexpdu = _tmp0_;
	hexpdulen = 88;
	_tmp1_ = cbs_newFromHexPdu (hexpdu, hexpdulen);
	msg = _tmp1_;
	_tmp3_ = cbs_decode_all (msg, &_tmp2_);
	_g_free0 (lang);
	lang = _tmp2_;
	text = _tmp3_;
	_tmp4_ = string_to_string (lang);
	_tmp5_ = string_to_string (text);
	_tmp6_ = g_strconcat ("lang = ", _tmp4_, "; text = ", _tmp5_, NULL);
	_tmp7_ = _tmp6_;
	g_message ("testcb.vala:53: %s", _tmp7_);
	_g_free0 (_tmp7_);
	g_assert (g_strcmp0 (lang, "de") == 0);
	g_assert (g_strcmp0 (text, "347745555103") == 0);
	_g_free0 (text);
	_g_free0 (lang);
	_cbs_free0 (msg);
	_g_free0 (hexpdu);
}


void test_cb_decode3 (void) {
	gchar* _tmp0_;
	gchar* hexpdu;
	gint hexpdulen;
	struct cbs* _tmp1_ = NULL;
	struct cbs* msg;
	gchar* lang = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* text;
	const gchar* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_;
	_tmp0_ = g_strdup ("001000DD001133DAED46ABD56AB5186CD668341A8D46");
	hexpdu = _tmp0_;
	hexpdulen = 22;
	_tmp1_ = cbs_newFromHexPdu (hexpdu, hexpdulen);
	msg = _tmp1_;
	_tmp3_ = cbs_decode_all (msg, &_tmp2_);
	_g_free0 (lang);
	lang = _tmp2_;
	text = _tmp3_;
	_tmp4_ = string_to_string (lang);
	_tmp5_ = string_to_string (text);
	_tmp6_ = g_strconcat ("lang = ", _tmp4_, "; text = ", _tmp5_, NULL);
	_tmp7_ = _tmp6_;
	g_message ("testcb.vala:71: %s", _tmp7_);
	_g_free0 (_tmp7_);
	g_assert (g_strcmp0 (lang, "de") == 0);
	g_assert (g_strcmp0 (text, "347745555103") == 0);
	_g_free0 (text);
	_g_free0 (lang);
	_cbs_free0 (msg);
	_g_free0 (hexpdu);
}


static void _test_cb_decode1_gcallback (void) {
	test_cb_decode1 ();
}


static void _test_cb_decode2_gcallback (void) {
	test_cb_decode2 ();
}


static void _test_cb_decode3_gcallback (void) {
	test_cb_decode3 ();
}


void _vala_main (gchar** args, int args_length1) {
	g_test_init (&args_length1, &args, NULL);
	g_test_add_func ("/3rdparty/Cb/Decode1", _test_cb_decode1_gcallback);
	g_test_add_func ("/3rdparty/Cb/Decode2", _test_cb_decode2_gcallback);
	g_test_add_func ("/3rdparty/Cb/Decode3", _test_cb_decode3_gcallback);
	g_test_run ();
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
}



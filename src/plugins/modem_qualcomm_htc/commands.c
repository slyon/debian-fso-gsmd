/* commands.c generated by valac 0.16.1, the Vala compiler
 * generated from commands.vala, do not modify */

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
#include <fsobasics.h>
#include <gee.h>


#define QUALCOMM_HTC_TYPE_PLUS_HTCCTZV (qualcomm_htc_plus_htcctzv_get_type ())
#define QUALCOMM_HTC_PLUS_HTCCTZV(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUALCOMM_HTC_TYPE_PLUS_HTCCTZV, QualcommHtcPlusHTCCTZV))
#define QUALCOMM_HTC_PLUS_HTCCTZV_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUALCOMM_HTC_TYPE_PLUS_HTCCTZV, QualcommHtcPlusHTCCTZVClass))
#define QUALCOMM_HTC_IS_PLUS_HTCCTZV(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUALCOMM_HTC_TYPE_PLUS_HTCCTZV))
#define QUALCOMM_HTC_IS_PLUS_HTCCTZV_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUALCOMM_HTC_TYPE_PLUS_HTCCTZV))
#define QUALCOMM_HTC_PLUS_HTCCTZV_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUALCOMM_HTC_TYPE_PLUS_HTCCTZV, QualcommHtcPlusHTCCTZVClass))

typedef struct _QualcommHtcPlusHTCCTZV QualcommHtcPlusHTCCTZV;
typedef struct _QualcommHtcPlusHTCCTZVClass QualcommHtcPlusHTCCTZVClass;
typedef struct _QualcommHtcPlusHTCCTZVPrivate QualcommHtcPlusHTCCTZVPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define QUALCOMM_HTC_TYPE_MY_PLUS_CEER (qualcomm_htc_my_plus_ceer_get_type ())
#define QUALCOMM_HTC_MY_PLUS_CEER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUALCOMM_HTC_TYPE_MY_PLUS_CEER, QualcommHtcMyPlusCEER))
#define QUALCOMM_HTC_MY_PLUS_CEER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUALCOMM_HTC_TYPE_MY_PLUS_CEER, QualcommHtcMyPlusCEERClass))
#define QUALCOMM_HTC_IS_MY_PLUS_CEER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUALCOMM_HTC_TYPE_MY_PLUS_CEER))
#define QUALCOMM_HTC_IS_MY_PLUS_CEER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUALCOMM_HTC_TYPE_MY_PLUS_CEER))
#define QUALCOMM_HTC_MY_PLUS_CEER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUALCOMM_HTC_TYPE_MY_PLUS_CEER, QualcommHtcMyPlusCEERClass))

typedef struct _QualcommHtcMyPlusCEER QualcommHtcMyPlusCEER;
typedef struct _QualcommHtcMyPlusCEERClass QualcommHtcMyPlusCEERClass;
typedef struct _QualcommHtcMyPlusCEERPrivate QualcommHtcMyPlusCEERPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _QualcommHtcPlusHTCCTZV {
	FsoGsmAbstractAtCommand parent_instance;
	QualcommHtcPlusHTCCTZVPrivate * priv;
	gint year;
	gint month;
	gint day;
	gint hour;
	gint minute;
	gint second;
	gint tzoffset;
};

struct _QualcommHtcPlusHTCCTZVClass {
	FsoGsmAbstractAtCommandClass parent_class;
};

struct _QualcommHtcMyPlusCEER {
	FsoGsmPlusCEER parent_instance;
	QualcommHtcMyPlusCEERPrivate * priv;
};

struct _QualcommHtcMyPlusCEERClass {
	FsoGsmPlusCEERClass parent_class;
};


static gpointer qualcomm_htc_plus_htcctzv_parent_class = NULL;
static GType qualcomm_htc_plus_htcctzv_type_id = 0;
static gpointer qualcomm_htc_my_plus_ceer_parent_class = NULL;
static GType qualcomm_htc_my_plus_ceer_type_id = 0;

GType qualcomm_htc_plus_htcctzv_get_type (void) G_GNUC_CONST;
GType qualcomm_htc_plus_htcctzv_register_type (GTypeModule * module);
enum  {
	QUALCOMM_HTC_PLUS_HTCCTZV_DUMMY_PROPERTY
};
QualcommHtcPlusHTCCTZV* qualcomm_htc_plus_htcctzv_new (void);
QualcommHtcPlusHTCCTZV* qualcomm_htc_plus_htcctzv_construct (GType object_type);
static void qualcomm_htc_plus_htcctzv_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error);
static void qualcomm_htc_plus_htcctzv_finalize (GObject* obj);
GType qualcomm_htc_my_plus_ceer_get_type (void) G_GNUC_CONST;
GType qualcomm_htc_my_plus_ceer_register_type (GTypeModule * module);
enum  {
	QUALCOMM_HTC_MY_PLUS_CEER_DUMMY_PROPERTY
};
QualcommHtcMyPlusCEER* qualcomm_htc_my_plus_ceer_new (void);
QualcommHtcMyPlusCEER* qualcomm_htc_my_plus_ceer_construct (GType object_type);
static void qualcomm_htc_my_plus_ceer_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error);
void qualcomm_htc_registerCustomAtCommands (GeeHashMap* table);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


QualcommHtcPlusHTCCTZV* qualcomm_htc_plus_htcctzv_construct (GType object_type) {
	QualcommHtcPlusHTCCTZV * self = NULL;
	GError * _inner_error_ = NULL;
	self = (QualcommHtcPlusHTCCTZV*) fso_gsm_abstract_at_command_construct (object_type);
	{
		gchar* _tmp0_;
		gchar* str;
		GRegex* _tmp1_;
		GRegex* _tmp2_;
		_tmp0_ = g_strdup ("\\+HTCCTZV: \"?(?P<year>\\d?\\d)/(?P<month>\\d?\\d)/(?P<day>\\d?\\d),(" \
"?P<hour>\\d?\\d):(?P<minute>\\d?\\d):(?P<second>\\d?\\d)(?P<sign>[\\+-" \
"])(?P<tzoffset>\\d\\d)?,1\"?\"");
		str = _tmp0_;
		_tmp1_ = g_regex_new (str, 0, 0, &_inner_error_);
		_tmp2_ = _tmp1_;
		if (_inner_error_ != NULL) {
			_g_free0 (str);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch0_g_regex_error;
			}
			_g_free0 (str);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_g_regex_unref0 (((FsoGsmAbstractAtCommand*) self)->re);
		((FsoGsmAbstractAtCommand*) self)->re = _tmp2_;
		_g_free0 (str);
	}
	goto __finally0;
	__catch0_g_regex_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_assert_not_reached ();
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


QualcommHtcPlusHTCCTZV* qualcomm_htc_plus_htcctzv_new (void) {
	return qualcomm_htc_plus_htcctzv_construct (QUALCOMM_HTC_TYPE_PLUS_HTCCTZV);
}


static void qualcomm_htc_plus_htcctzv_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error) {
	QualcommHtcPlusHTCCTZV * self;
	const gchar* _tmp0_;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	gint _tmp4_ = 0;
	gint _tmp5_ = 0;
	gint _tmp6_ = 0;
	gint _tmp7_ = 0;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_;
	gboolean _tmp10_;
	GError * _inner_error_ = NULL;
	self = (QualcommHtcPlusHTCCTZV*) base;
	g_return_if_fail (response != NULL);
	_tmp0_ = response;
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (qualcomm_htc_plus_htcctzv_parent_class)->parse (FSO_GSM_ABSTRACT_AT_COMMAND (self), _tmp0_, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == FSO_GSM_AT_COMMAND_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp1_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "year");
	self->year = 2000 + _tmp1_;
	_tmp2_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "month");
	self->month = _tmp2_;
	_tmp3_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "day");
	self->day = _tmp3_;
	_tmp4_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "hour");
	self->hour = _tmp4_;
	_tmp5_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "minute");
	self->minute = _tmp5_;
	_tmp6_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "second");
	self->second = _tmp6_;
	_tmp7_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "tzoffset");
	self->tzoffset = _tmp7_ * 15;
	_tmp8_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "sign");
	_tmp9_ = _tmp8_;
	_tmp10_ = g_strcmp0 (_tmp9_, "-") == 0;
	_g_free0 (_tmp9_);
	if (_tmp10_) {
		gint _tmp11_;
		_tmp11_ = self->tzoffset;
		self->tzoffset = -_tmp11_;
	}
}


static void qualcomm_htc_plus_htcctzv_class_init (QualcommHtcPlusHTCCTZVClass * klass) {
	qualcomm_htc_plus_htcctzv_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (klass)->parse = qualcomm_htc_plus_htcctzv_real_parse;
	G_OBJECT_CLASS (klass)->finalize = qualcomm_htc_plus_htcctzv_finalize;
}


static void qualcomm_htc_plus_htcctzv_instance_init (QualcommHtcPlusHTCCTZV * self) {
}


static void qualcomm_htc_plus_htcctzv_finalize (GObject* obj) {
	QualcommHtcPlusHTCCTZV * self;
	self = QUALCOMM_HTC_PLUS_HTCCTZV (obj);
	G_OBJECT_CLASS (qualcomm_htc_plus_htcctzv_parent_class)->finalize (obj);
}


/**
 * +HTCCTZV: "10/05/02,15:27:30+08,1"
 **/
GType qualcomm_htc_plus_htcctzv_get_type (void) {
	return qualcomm_htc_plus_htcctzv_type_id;
}


GType qualcomm_htc_plus_htcctzv_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (QualcommHtcPlusHTCCTZVClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) qualcomm_htc_plus_htcctzv_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (QualcommHtcPlusHTCCTZV), 0, (GInstanceInitFunc) qualcomm_htc_plus_htcctzv_instance_init, NULL };
	qualcomm_htc_plus_htcctzv_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_AT_COMMAND, "QualcommHtcPlusHTCCTZV", &g_define_type_info, 0);
	return qualcomm_htc_plus_htcctzv_type_id;
}


QualcommHtcMyPlusCEER* qualcomm_htc_my_plus_ceer_construct (GType object_type) {
	QualcommHtcMyPlusCEER * self = NULL;
	gchar* _tmp2_;
	gchar** _tmp3_ = NULL;
	GError * _inner_error_ = NULL;
	self = (QualcommHtcMyPlusCEER*) fso_gsm_plus_ceer_construct (object_type);
	{
		GRegex* _tmp0_;
		GRegex* _tmp1_;
		_tmp0_ = g_regex_new ("\\+CEER: (?P<reason>[A-Z a-z]+)", 0, 0, &_inner_error_);
		_tmp1_ = _tmp0_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch1_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_g_regex_unref0 (((FsoGsmAbstractAtCommand*) self)->re);
		((FsoGsmAbstractAtCommand*) self)->re = _tmp1_;
	}
	goto __finally1;
	__catch1_g_regex_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_assert_not_reached ();
		_g_error_free0 (e);
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp2_ = g_strdup ("+CEER: ");
	_tmp3_ = g_new0 (gchar*, 1 + 1);
	_tmp3_[0] = _tmp2_;
	((FsoGsmAbstractAtCommand*) self)->prefix = (_vala_array_free (((FsoGsmAbstractAtCommand*) self)->prefix, ((FsoGsmAbstractAtCommand*) self)->prefix_length1, (GDestroyNotify) g_free), NULL);
	((FsoGsmAbstractAtCommand*) self)->prefix = _tmp3_;
	((FsoGsmAbstractAtCommand*) self)->prefix_length1 = 1;
	return self;
}


QualcommHtcMyPlusCEER* qualcomm_htc_my_plus_ceer_new (void) {
	return qualcomm_htc_my_plus_ceer_construct (QUALCOMM_HTC_TYPE_MY_PLUS_CEER);
}


static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = needle;
	_tmp1_ = strstr ((gchar*) self, (gchar*) _tmp0_);
	result = _tmp1_ != NULL;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void qualcomm_htc_my_plus_ceer_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error) {
	QualcommHtcMyPlusCEER * self;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	gchar* r;
	const gchar* _tmp2_;
	gboolean _tmp3_ = FALSE;
	GError * _inner_error_ = NULL;
	self = (QualcommHtcMyPlusCEER*) base;
	g_return_if_fail (response != NULL);
	_tmp0_ = response;
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (qualcomm_htc_my_plus_ceer_parent_class)->parse ((FsoGsmAbstractAtCommand*) FSO_GSM_PLUS_CEER (self), _tmp0_, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == FSO_GSM_AT_COMMAND_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp1_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "reason");
	r = _tmp1_;
	_tmp2_ = r;
	_tmp3_ = string_contains (_tmp2_, "Call rejected");
	if (_tmp3_) {
		gchar* _tmp4_;
		_tmp4_ = g_strdup ("local-reject");
		_g_free0 (((FsoGsmPlusCEER*) self)->reason);
		((FsoGsmPlusCEER*) self)->reason = _tmp4_;
	} else {
		const gchar* _tmp5_;
		gboolean _tmp6_ = FALSE;
		_tmp5_ = r;
		_tmp6_ = string_contains (_tmp5_, "Client ended call");
		if (_tmp6_) {
			gchar* _tmp7_;
			_tmp7_ = g_strdup ("local-cancel");
			_g_free0 (((FsoGsmPlusCEER*) self)->reason);
			((FsoGsmPlusCEER*) self)->reason = _tmp7_;
		} else {
			const gchar* _tmp8_;
			gboolean _tmp9_ = FALSE;
			_tmp8_ = r;
			_tmp9_ = string_contains (_tmp8_, "Network ended call");
			if (_tmp9_) {
				gchar* _tmp10_;
				_tmp10_ = g_strdup ("remote-cancel");
				_g_free0 (((FsoGsmPlusCEER*) self)->reason);
				((FsoGsmPlusCEER*) self)->reason = _tmp10_;
			} else {
				FsoFrameworkLogger* _tmp11_;
				const gchar* _tmp12_;
				const gchar* _tmp13_ = NULL;
				gchar* _tmp14_ = NULL;
				gchar* _tmp15_;
				_tmp11_ = fso_framework_theLogger;
				_tmp12_ = r;
				_tmp13_ = string_to_string (_tmp12_);
				_tmp14_ = g_strconcat ("Unknown +CEER cause '", _tmp13_, "'; please report to Mickey <smartphones-userland@linuxtogo.org>", NULL);
				_tmp15_ = _tmp14_;
				fso_framework_logger_info (_tmp11_, _tmp15_);
				_g_free0 (_tmp15_);
			}
		}
	}
	_g_free0 (r);
}


static void qualcomm_htc_my_plus_ceer_class_init (QualcommHtcMyPlusCEERClass * klass) {
	qualcomm_htc_my_plus_ceer_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (klass)->parse = qualcomm_htc_my_plus_ceer_real_parse;
}


static void qualcomm_htc_my_plus_ceer_instance_init (QualcommHtcMyPlusCEER * self) {
}


GType qualcomm_htc_my_plus_ceer_get_type (void) {
	return qualcomm_htc_my_plus_ceer_type_id;
}


GType qualcomm_htc_my_plus_ceer_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (QualcommHtcMyPlusCEERClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) qualcomm_htc_my_plus_ceer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (QualcommHtcMyPlusCEER), 0, (GInstanceInitFunc) qualcomm_htc_my_plus_ceer_instance_init, NULL };
	qualcomm_htc_my_plus_ceer_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_PLUS_CEER, "QualcommHtcMyPlusCEER", &g_define_type_info, 0);
	return qualcomm_htc_my_plus_ceer_type_id;
}


/**
 * Register all custom commands
 **/
void qualcomm_htc_registerCustomAtCommands (GeeHashMap* table) {
	GeeHashMap* _tmp0_;
	QualcommHtcPlusHTCCTZV* _tmp1_;
	QualcommHtcPlusHTCCTZV* _tmp2_;
	GeeHashMap* _tmp3_;
	QualcommHtcMyPlusCEER* _tmp4_;
	QualcommHtcMyPlusCEER* _tmp5_;
	g_return_if_fail (table != NULL);
	_tmp0_ = table;
	_tmp1_ = qualcomm_htc_plus_htcctzv_new ();
	_tmp2_ = _tmp1_;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp0_, "+HTCCTZV", (FsoGsmAtCommand*) _tmp2_);
	_g_object_unref0 (_tmp2_);
	_tmp3_ = table;
	_tmp4_ = qualcomm_htc_my_plus_ceer_new ();
	_tmp5_ = _tmp4_;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp3_, "+CEER", (FsoGsmAtCommand*) _tmp5_);
	_g_object_unref0 (_tmp5_);
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




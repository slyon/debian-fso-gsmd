/* commands.c generated by valac 0.16.0, the Vala compiler
 * generated from commands.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Klaus 'mrmoku' Kurzmann   <mok@fluxnetz.de>
 *               2011-2012 Lukas 'slyon' Märdian     <lukasmaerdian@gmail.com>
 *               2012 Simon Busch               <morphis@gravedo.de>
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
#include <gee.h>


#define GTM601_TYPE_PLUS_CHUP (gtm601_plus_chup_get_type ())
#define GTM601_PLUS_CHUP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTM601_TYPE_PLUS_CHUP, Gtm601PlusCHUP))
#define GTM601_PLUS_CHUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTM601_TYPE_PLUS_CHUP, Gtm601PlusCHUPClass))
#define GTM601_IS_PLUS_CHUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTM601_TYPE_PLUS_CHUP))
#define GTM601_IS_PLUS_CHUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTM601_TYPE_PLUS_CHUP))
#define GTM601_PLUS_CHUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTM601_TYPE_PLUS_CHUP, Gtm601PlusCHUPClass))

typedef struct _Gtm601PlusCHUP Gtm601PlusCHUP;
typedef struct _Gtm601PlusCHUPClass Gtm601PlusCHUPClass;
typedef struct _Gtm601PlusCHUPPrivate Gtm601PlusCHUPPrivate;

#define GTM601_TYPE_UNDERSCORE_OWANCALL (gtm601_underscore_owancall_get_type ())
#define GTM601_UNDERSCORE_OWANCALL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTM601_TYPE_UNDERSCORE_OWANCALL, Gtm601UnderscoreOWANCALL))
#define GTM601_UNDERSCORE_OWANCALL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTM601_TYPE_UNDERSCORE_OWANCALL, Gtm601UnderscoreOWANCALLClass))
#define GTM601_IS_UNDERSCORE_OWANCALL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTM601_TYPE_UNDERSCORE_OWANCALL))
#define GTM601_IS_UNDERSCORE_OWANCALL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTM601_TYPE_UNDERSCORE_OWANCALL))
#define GTM601_UNDERSCORE_OWANCALL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTM601_TYPE_UNDERSCORE_OWANCALL, Gtm601UnderscoreOWANCALLClass))

typedef struct _Gtm601UnderscoreOWANCALL Gtm601UnderscoreOWANCALL;
typedef struct _Gtm601UnderscoreOWANCALLClass Gtm601UnderscoreOWANCALLClass;
typedef struct _Gtm601UnderscoreOWANCALLPrivate Gtm601UnderscoreOWANCALLPrivate;

#define GTM601_TYPE_UNDERSCORE_OWANDATA (gtm601_underscore_owandata_get_type ())
#define GTM601_UNDERSCORE_OWANDATA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTM601_TYPE_UNDERSCORE_OWANDATA, Gtm601UnderscoreOWANDATA))
#define GTM601_UNDERSCORE_OWANDATA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTM601_TYPE_UNDERSCORE_OWANDATA, Gtm601UnderscoreOWANDATAClass))
#define GTM601_IS_UNDERSCORE_OWANDATA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTM601_TYPE_UNDERSCORE_OWANDATA))
#define GTM601_IS_UNDERSCORE_OWANDATA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTM601_TYPE_UNDERSCORE_OWANDATA))
#define GTM601_UNDERSCORE_OWANDATA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTM601_TYPE_UNDERSCORE_OWANDATA, Gtm601UnderscoreOWANDATAClass))

typedef struct _Gtm601UnderscoreOWANDATA Gtm601UnderscoreOWANDATA;
typedef struct _Gtm601UnderscoreOWANDATAClass Gtm601UnderscoreOWANDATAClass;
typedef struct _Gtm601UnderscoreOWANDATAPrivate Gtm601UnderscoreOWANDATAPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define GTM601_TYPE_EXT_PLUS_CEER (gtm601_ext_plus_ceer_get_type ())
#define GTM601_EXT_PLUS_CEER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTM601_TYPE_EXT_PLUS_CEER, Gtm601ExtPlusCEER))
#define GTM601_EXT_PLUS_CEER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTM601_TYPE_EXT_PLUS_CEER, Gtm601ExtPlusCEERClass))
#define GTM601_IS_EXT_PLUS_CEER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTM601_TYPE_EXT_PLUS_CEER))
#define GTM601_IS_EXT_PLUS_CEER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTM601_TYPE_EXT_PLUS_CEER))
#define GTM601_EXT_PLUS_CEER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTM601_TYPE_EXT_PLUS_CEER, Gtm601ExtPlusCEERClass))

typedef struct _Gtm601ExtPlusCEER Gtm601ExtPlusCEER;
typedef struct _Gtm601ExtPlusCEERClass Gtm601ExtPlusCEERClass;
typedef struct _Gtm601ExtPlusCEERPrivate Gtm601ExtPlusCEERPrivate;

#define GTM601_TYPE_UNDERSCORE_OSIGQ (gtm601_underscore_osigq_get_type ())
#define GTM601_UNDERSCORE_OSIGQ(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTM601_TYPE_UNDERSCORE_OSIGQ, Gtm601UnderscoreOSIGQ))
#define GTM601_UNDERSCORE_OSIGQ_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTM601_TYPE_UNDERSCORE_OSIGQ, Gtm601UnderscoreOSIGQClass))
#define GTM601_IS_UNDERSCORE_OSIGQ(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTM601_TYPE_UNDERSCORE_OSIGQ))
#define GTM601_IS_UNDERSCORE_OSIGQ_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTM601_TYPE_UNDERSCORE_OSIGQ))
#define GTM601_UNDERSCORE_OSIGQ_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTM601_TYPE_UNDERSCORE_OSIGQ, Gtm601UnderscoreOSIGQClass))

typedef struct _Gtm601UnderscoreOSIGQ Gtm601UnderscoreOSIGQ;
typedef struct _Gtm601UnderscoreOSIGQClass Gtm601UnderscoreOSIGQClass;
typedef struct _Gtm601UnderscoreOSIGQPrivate Gtm601UnderscoreOSIGQPrivate;

#define GTM601_TYPE_UNDERSCORE_OPSYS (gtm601_underscore_opsys_get_type ())
#define GTM601_UNDERSCORE_OPSYS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTM601_TYPE_UNDERSCORE_OPSYS, Gtm601UnderscoreOPSYS))
#define GTM601_UNDERSCORE_OPSYS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTM601_TYPE_UNDERSCORE_OPSYS, Gtm601UnderscoreOPSYSClass))
#define GTM601_IS_UNDERSCORE_OPSYS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTM601_TYPE_UNDERSCORE_OPSYS))
#define GTM601_IS_UNDERSCORE_OPSYS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTM601_TYPE_UNDERSCORE_OPSYS))
#define GTM601_UNDERSCORE_OPSYS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTM601_TYPE_UNDERSCORE_OPSYS, Gtm601UnderscoreOPSYSClass))

typedef struct _Gtm601UnderscoreOPSYS Gtm601UnderscoreOPSYS;
typedef struct _Gtm601UnderscoreOPSYSClass Gtm601UnderscoreOPSYSClass;
typedef struct _Gtm601UnderscoreOPSYSPrivate Gtm601UnderscoreOPSYSPrivate;

#define GTM601_UNDERSCORE_OPSYS_TYPE_RADIO_ACCESS_MODE (gtm601_underscore_opsys_radio_access_mode_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _Gtm601PlusCHUP {
	FsoGsmV250terCommand parent_instance;
	Gtm601PlusCHUPPrivate * priv;
};

struct _Gtm601PlusCHUPClass {
	FsoGsmV250terCommandClass parent_class;
};

struct _Gtm601UnderscoreOWANCALL {
	FsoGsmV250terCommand parent_instance;
	Gtm601UnderscoreOWANCALLPrivate * priv;
};

struct _Gtm601UnderscoreOWANCALLClass {
	FsoGsmV250terCommandClass parent_class;
};

struct _Gtm601UnderscoreOWANDATA {
	FsoGsmAbstractAtCommand parent_instance;
	Gtm601UnderscoreOWANDATAPrivate * priv;
	gboolean connected;
	gchar* ip;
	gchar* gateway;
	gchar* dns1;
	gchar* dns2;
	gchar* nbns1;
	gchar* nbns2;
	gchar* speed;
};

struct _Gtm601UnderscoreOWANDATAClass {
	FsoGsmAbstractAtCommandClass parent_class;
};

struct _Gtm601ExtPlusCEER {
	FsoGsmPlusCEER parent_instance;
	Gtm601ExtPlusCEERPrivate * priv;
};

struct _Gtm601ExtPlusCEERClass {
	FsoGsmPlusCEERClass parent_class;
};

struct _Gtm601UnderscoreOSIGQ {
	FsoGsmAbstractAtCommand parent_instance;
	Gtm601UnderscoreOSIGQPrivate * priv;
	gint strength;
};

struct _Gtm601UnderscoreOSIGQClass {
	FsoGsmAbstractAtCommandClass parent_class;
};

struct _Gtm601UnderscoreOPSYS {
	FsoGsmAbstractAtCommand parent_instance;
	Gtm601UnderscoreOPSYSPrivate * priv;
};

struct _Gtm601UnderscoreOPSYSClass {
	FsoGsmAbstractAtCommandClass parent_class;
};

typedef enum  {
	GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_GSM = 0,
	GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_UMTS = 1,
	GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_ANY = 5
} Gtm601UnderscoreOPSYSRadioAccessMode;


static gpointer gtm601_plus_chup_parent_class = NULL;
static GType gtm601_plus_chup_type_id = 0;
static gpointer gtm601_underscore_owancall_parent_class = NULL;
static GType gtm601_underscore_owancall_type_id = 0;
static gpointer gtm601_underscore_owandata_parent_class = NULL;
static GType gtm601_underscore_owandata_type_id = 0;
static gpointer gtm601_ext_plus_ceer_parent_class = NULL;
static GType gtm601_ext_plus_ceer_type_id = 0;
static gpointer gtm601_underscore_osigq_parent_class = NULL;
static GType gtm601_underscore_osigq_type_id = 0;
static gpointer gtm601_underscore_opsys_parent_class = NULL;
static GType gtm601_underscore_opsys_type_id = 0;

GType gtm601_plus_chup_get_type (void) G_GNUC_CONST;
GType gtm601_plus_chup_register_type (GTypeModule * module);
enum  {
	GTM601_PLUS_CHUP_DUMMY_PROPERTY
};
Gtm601PlusCHUP* gtm601_plus_chup_new (void);
Gtm601PlusCHUP* gtm601_plus_chup_construct (GType object_type);
GType gtm601_underscore_owancall_get_type (void) G_GNUC_CONST;
GType gtm601_underscore_owancall_register_type (GTypeModule * module);
enum  {
	GTM601_UNDERSCORE_OWANCALL_DUMMY_PROPERTY
};
Gtm601UnderscoreOWANCALL* gtm601_underscore_owancall_new (void);
Gtm601UnderscoreOWANCALL* gtm601_underscore_owancall_construct (GType object_type);
gchar* gtm601_underscore_owancall_issue (Gtm601UnderscoreOWANCALL* self, gboolean connect);
GType gtm601_underscore_owandata_get_type (void) G_GNUC_CONST;
GType gtm601_underscore_owandata_register_type (GTypeModule * module);
enum  {
	GTM601_UNDERSCORE_OWANDATA_DUMMY_PROPERTY
};
Gtm601UnderscoreOWANDATA* gtm601_underscore_owandata_new (void);
Gtm601UnderscoreOWANDATA* gtm601_underscore_owandata_construct (GType object_type);
static void gtm601_underscore_owandata_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error);
gchar* gtm601_underscore_owandata_issue (Gtm601UnderscoreOWANDATA* self);
static void gtm601_underscore_owandata_finalize (GObject* obj);
GType gtm601_ext_plus_ceer_get_type (void) G_GNUC_CONST;
GType gtm601_ext_plus_ceer_register_type (GTypeModule * module);
enum  {
	GTM601_EXT_PLUS_CEER_DUMMY_PROPERTY
};
Gtm601ExtPlusCEER* gtm601_ext_plus_ceer_new (void);
Gtm601ExtPlusCEER* gtm601_ext_plus_ceer_construct (GType object_type);
static void gtm601_ext_plus_ceer_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error);
GType gtm601_underscore_osigq_get_type (void) G_GNUC_CONST;
GType gtm601_underscore_osigq_register_type (GTypeModule * module);
enum  {
	GTM601_UNDERSCORE_OSIGQ_DUMMY_PROPERTY
};
Gtm601UnderscoreOSIGQ* gtm601_underscore_osigq_new (void);
Gtm601UnderscoreOSIGQ* gtm601_underscore_osigq_construct (GType object_type);
static void gtm601_underscore_osigq_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error);
static void gtm601_underscore_osigq_finalize (GObject* obj);
GType gtm601_underscore_opsys_get_type (void) G_GNUC_CONST;
GType gtm601_underscore_opsys_register_type (GTypeModule * module);
enum  {
	GTM601_UNDERSCORE_OPSYS_DUMMY_PROPERTY
};
GType gtm601_underscore_opsys_radio_access_mode_get_type (void) G_GNUC_CONST;
gchar* gtm601_underscore_opsys_issue (Gtm601UnderscoreOPSYS* self, Gtm601UnderscoreOPSYSRadioAccessMode mode);
Gtm601UnderscoreOPSYS* gtm601_underscore_opsys_new (void);
Gtm601UnderscoreOPSYS* gtm601_underscore_opsys_construct (GType object_type);
void gtm601_registerCustomAtCommands (GeeHashMap* table);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


Gtm601PlusCHUP* gtm601_plus_chup_construct (GType object_type) {
	Gtm601PlusCHUP * self = NULL;
	self = (Gtm601PlusCHUP*) fso_gsm_v250ter_command_construct (object_type, "+CHUP");
	return self;
}


Gtm601PlusCHUP* gtm601_plus_chup_new (void) {
	return gtm601_plus_chup_construct (GTM601_TYPE_PLUS_CHUP);
}


static void gtm601_plus_chup_class_init (Gtm601PlusCHUPClass * klass) {
	gtm601_plus_chup_parent_class = g_type_class_peek_parent (klass);
}


static void gtm601_plus_chup_instance_init (Gtm601PlusCHUP * self) {
}


GType gtm601_plus_chup_get_type (void) {
	return gtm601_plus_chup_type_id;
}


GType gtm601_plus_chup_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (Gtm601PlusCHUPClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gtm601_plus_chup_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Gtm601PlusCHUP), 0, (GInstanceInitFunc) gtm601_plus_chup_instance_init, NULL };
	gtm601_plus_chup_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_V250TER_COMMAND, "Gtm601PlusCHUP", &g_define_type_info, 0);
	return gtm601_plus_chup_type_id;
}


Gtm601UnderscoreOWANCALL* gtm601_underscore_owancall_construct (GType object_type) {
	Gtm601UnderscoreOWANCALL * self = NULL;
	self = (Gtm601UnderscoreOWANCALL*) fso_gsm_v250ter_command_construct (object_type, "_OWANCALL");
	return self;
}


Gtm601UnderscoreOWANCALL* gtm601_underscore_owancall_new (void) {
	return gtm601_underscore_owancall_construct (GTM601_TYPE_UNDERSCORE_OWANCALL);
}


gchar* gtm601_underscore_owancall_issue (Gtm601UnderscoreOWANCALL* self, gboolean connect) {
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	gboolean _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = connect;
	if (_tmp1_) {
		_tmp0_ = "_OWANCALL=1,1,1";
	} else {
		_tmp0_ = "_OWANCALL=1,0,1";
	}
	_tmp2_ = _tmp0_;
	_tmp3_ = g_strdup (_tmp2_);
	result = _tmp3_;
	return result;
}


static void gtm601_underscore_owancall_class_init (Gtm601UnderscoreOWANCALLClass * klass) {
	gtm601_underscore_owancall_parent_class = g_type_class_peek_parent (klass);
}


static void gtm601_underscore_owancall_instance_init (Gtm601UnderscoreOWANCALL * self) {
}


GType gtm601_underscore_owancall_get_type (void) {
	return gtm601_underscore_owancall_type_id;
}


GType gtm601_underscore_owancall_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (Gtm601UnderscoreOWANCALLClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gtm601_underscore_owancall_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Gtm601UnderscoreOWANCALL), 0, (GInstanceInitFunc) gtm601_underscore_owancall_instance_init, NULL };
	gtm601_underscore_owancall_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_V250TER_COMMAND, "Gtm601UnderscoreOWANCALL", &g_define_type_info, 0);
	return gtm601_underscore_owancall_type_id;
}


Gtm601UnderscoreOWANDATA* gtm601_underscore_owandata_construct (GType object_type) {
	Gtm601UnderscoreOWANDATA * self = NULL;
	gchar* _tmp0_;
	gchar* str;
	gchar* _tmp3_;
	gchar** _tmp4_ = NULL;
	GError * _inner_error_ = NULL;
	self = (Gtm601UnderscoreOWANDATA*) fso_gsm_abstract_at_command_construct (object_type);
	_tmp0_ = g_strdup ("_OWANDATA: (?P<connected>[01]), (?P<ip>[0-9.]+), (?P<gw>[0-9.]+), (?P<" \
"dns1>[0-9.]+), (?P<dns2>[0-9.]+), (?P<nbns1>[0-9.]+), (?P<nbns2>[0-9.]" \
"+),(?P<speed>\\d+)");
	str = _tmp0_;
	{
		GRegex* _tmp1_;
		GRegex* _tmp2_;
		_tmp1_ = g_regex_new (str, 0, 0, &_inner_error_);
		_tmp2_ = _tmp1_;
		if (_inner_error_ != NULL) {
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
		_g_free0 (str);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp3_ = g_strdup ("_OWANDATA: ");
	_tmp4_ = g_new0 (gchar*, 1 + 1);
	_tmp4_[0] = _tmp3_;
	((FsoGsmAbstractAtCommand*) self)->prefix = (_vala_array_free (((FsoGsmAbstractAtCommand*) self)->prefix, ((FsoGsmAbstractAtCommand*) self)->prefix_length1, (GDestroyNotify) g_free), NULL);
	((FsoGsmAbstractAtCommand*) self)->prefix = _tmp4_;
	((FsoGsmAbstractAtCommand*) self)->prefix_length1 = 1;
	_g_free0 (str);
	return self;
}


Gtm601UnderscoreOWANDATA* gtm601_underscore_owandata_new (void) {
	return gtm601_underscore_owandata_construct (GTM601_TYPE_UNDERSCORE_OWANDATA);
}


static void gtm601_underscore_owandata_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error) {
	Gtm601UnderscoreOWANDATA * self;
	const gchar* _tmp0_;
	gint _tmp1_ = 0;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	GError * _inner_error_ = NULL;
	self = (Gtm601UnderscoreOWANDATA*) base;
	g_return_if_fail (response != NULL);
	_tmp0_ = response;
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (gtm601_underscore_owandata_parent_class)->parse (FSO_GSM_ABSTRACT_AT_COMMAND (self), _tmp0_, &_inner_error_);
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
	_tmp1_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "connected");
	self->connected = _tmp1_ == 1;
	_tmp2_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "ip");
	_g_free0 (self->ip);
	self->ip = _tmp2_;
	_tmp3_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "gw");
	_g_free0 (self->gateway);
	self->gateway = _tmp3_;
	_tmp4_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "dns1");
	_g_free0 (self->dns1);
	self->dns1 = _tmp4_;
	_tmp5_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "dns2");
	_g_free0 (self->dns2);
	self->dns2 = _tmp5_;
	_tmp6_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "nbns1");
	_g_free0 (self->nbns1);
	self->nbns1 = _tmp6_;
	_tmp7_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "nbns2");
	_g_free0 (self->nbns2);
	self->nbns2 = _tmp7_;
	_tmp8_ = fso_gsm_abstract_at_command_to_string ((FsoGsmAbstractAtCommand*) self, "speed");
	_g_free0 (self->speed);
	self->speed = _tmp8_;
}


gchar* gtm601_underscore_owandata_issue (Gtm601UnderscoreOWANDATA* self) {
	gchar* result = NULL;
	gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup ("_OWANDATA?");
	result = _tmp0_;
	return result;
}


static void gtm601_underscore_owandata_class_init (Gtm601UnderscoreOWANDATAClass * klass) {
	gtm601_underscore_owandata_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (klass)->parse = gtm601_underscore_owandata_real_parse;
	G_OBJECT_CLASS (klass)->finalize = gtm601_underscore_owandata_finalize;
}


static void gtm601_underscore_owandata_instance_init (Gtm601UnderscoreOWANDATA * self) {
}


static void gtm601_underscore_owandata_finalize (GObject* obj) {
	Gtm601UnderscoreOWANDATA * self;
	self = GTM601_UNDERSCORE_OWANDATA (obj);
	_g_free0 (self->ip);
	_g_free0 (self->gateway);
	_g_free0 (self->dns1);
	_g_free0 (self->dns2);
	_g_free0 (self->nbns1);
	_g_free0 (self->nbns2);
	_g_free0 (self->speed);
	G_OBJECT_CLASS (gtm601_underscore_owandata_parent_class)->finalize (obj);
}


GType gtm601_underscore_owandata_get_type (void) {
	return gtm601_underscore_owandata_type_id;
}


GType gtm601_underscore_owandata_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (Gtm601UnderscoreOWANDATAClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gtm601_underscore_owandata_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Gtm601UnderscoreOWANDATA), 0, (GInstanceInitFunc) gtm601_underscore_owandata_instance_init, NULL };
	gtm601_underscore_owandata_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_AT_COMMAND, "Gtm601UnderscoreOWANDATA", &g_define_type_info, 0);
	return gtm601_underscore_owandata_type_id;
}


Gtm601ExtPlusCEER* gtm601_ext_plus_ceer_construct (GType object_type) {
	Gtm601ExtPlusCEER * self = NULL;
	gchar* _tmp2_;
	gchar** _tmp3_ = NULL;
	GError * _inner_error_ = NULL;
	self = (Gtm601ExtPlusCEER*) fso_gsm_plus_ceer_construct (object_type);
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


Gtm601ExtPlusCEER* gtm601_ext_plus_ceer_new (void) {
	return gtm601_ext_plus_ceer_construct (GTM601_TYPE_EXT_PLUS_CEER);
}


static void gtm601_ext_plus_ceer_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error) {
	Gtm601ExtPlusCEER * self;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	GError * _inner_error_ = NULL;
	self = (Gtm601ExtPlusCEER*) base;
	g_return_if_fail (response != NULL);
	_tmp0_ = response;
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (gtm601_ext_plus_ceer_parent_class)->parse ((FsoGsmAbstractAtCommand*) FSO_GSM_PLUS_CEER (self), _tmp0_, &_inner_error_);
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
	_g_free0 (((FsoGsmPlusCEER*) self)->reason);
	((FsoGsmPlusCEER*) self)->reason = _tmp1_;
}


static void gtm601_ext_plus_ceer_class_init (Gtm601ExtPlusCEERClass * klass) {
	gtm601_ext_plus_ceer_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (klass)->parse = gtm601_ext_plus_ceer_real_parse;
}


static void gtm601_ext_plus_ceer_instance_init (Gtm601ExtPlusCEER * self) {
}


GType gtm601_ext_plus_ceer_get_type (void) {
	return gtm601_ext_plus_ceer_type_id;
}


GType gtm601_ext_plus_ceer_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (Gtm601ExtPlusCEERClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gtm601_ext_plus_ceer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Gtm601ExtPlusCEER), 0, (GInstanceInitFunc) gtm601_ext_plus_ceer_instance_init, NULL };
	gtm601_ext_plus_ceer_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_PLUS_CEER, "Gtm601ExtPlusCEER", &g_define_type_info, 0);
	return gtm601_ext_plus_ceer_type_id;
}


Gtm601UnderscoreOSIGQ* gtm601_underscore_osigq_construct (GType object_type) {
	Gtm601UnderscoreOSIGQ * self = NULL;
	gchar* _tmp2_;
	gchar** _tmp3_ = NULL;
	GError * _inner_error_ = NULL;
	self = (Gtm601UnderscoreOSIGQ*) fso_gsm_abstract_at_command_construct (object_type);
	{
		GRegex* _tmp0_;
		GRegex* _tmp1_;
		_tmp0_ = g_regex_new ("_OSIGQ: (?P<strength>[0-9.]+),(?P<unknown>[0-9.]+)", 0, 0, &_inner_error_);
		_tmp1_ = _tmp0_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch2_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_g_regex_unref0 (((FsoGsmAbstractAtCommand*) self)->re);
		((FsoGsmAbstractAtCommand*) self)->re = _tmp1_;
	}
	goto __finally2;
	__catch2_g_regex_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_assert_not_reached ();
		_g_error_free0 (e);
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp2_ = g_strdup ("_OSIGQ: ");
	_tmp3_ = g_new0 (gchar*, 1 + 1);
	_tmp3_[0] = _tmp2_;
	((FsoGsmAbstractAtCommand*) self)->prefix = (_vala_array_free (((FsoGsmAbstractAtCommand*) self)->prefix, ((FsoGsmAbstractAtCommand*) self)->prefix_length1, (GDestroyNotify) g_free), NULL);
	((FsoGsmAbstractAtCommand*) self)->prefix = _tmp3_;
	((FsoGsmAbstractAtCommand*) self)->prefix_length1 = 1;
	return self;
}


Gtm601UnderscoreOSIGQ* gtm601_underscore_osigq_new (void) {
	return gtm601_underscore_osigq_construct (GTM601_TYPE_UNDERSCORE_OSIGQ);
}


static void gtm601_underscore_osigq_real_parse (FsoGsmAbstractAtCommand* base, const gchar* response, GError** error) {
	Gtm601UnderscoreOSIGQ * self;
	const gchar* _tmp0_;
	gint _tmp1_ = 0;
	GError * _inner_error_ = NULL;
	self = (Gtm601UnderscoreOSIGQ*) base;
	g_return_if_fail (response != NULL);
	_tmp0_ = response;
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (gtm601_underscore_osigq_parent_class)->parse (FSO_GSM_ABSTRACT_AT_COMMAND (self), _tmp0_, &_inner_error_);
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
	_tmp1_ = fso_gsm_abstract_at_command_to_int ((FsoGsmAbstractAtCommand*) self, "strength");
	self->strength = _tmp1_;
}


static void gtm601_underscore_osigq_class_init (Gtm601UnderscoreOSIGQClass * klass) {
	gtm601_underscore_osigq_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_ABSTRACT_AT_COMMAND_CLASS (klass)->parse = gtm601_underscore_osigq_real_parse;
	G_OBJECT_CLASS (klass)->finalize = gtm601_underscore_osigq_finalize;
}


static void gtm601_underscore_osigq_instance_init (Gtm601UnderscoreOSIGQ * self) {
	self->strength = 0;
}


static void gtm601_underscore_osigq_finalize (GObject* obj) {
	Gtm601UnderscoreOSIGQ * self;
	self = GTM601_UNDERSCORE_OSIGQ (obj);
	G_OBJECT_CLASS (gtm601_underscore_osigq_parent_class)->finalize (obj);
}


GType gtm601_underscore_osigq_get_type (void) {
	return gtm601_underscore_osigq_type_id;
}


GType gtm601_underscore_osigq_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (Gtm601UnderscoreOSIGQClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gtm601_underscore_osigq_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Gtm601UnderscoreOSIGQ), 0, (GInstanceInitFunc) gtm601_underscore_osigq_instance_init, NULL };
	gtm601_underscore_osigq_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_AT_COMMAND, "Gtm601UnderscoreOSIGQ", &g_define_type_info, 0);
	return gtm601_underscore_osigq_type_id;
}


GType gtm601_underscore_opsys_radio_access_mode_get_type (void) {
	static volatile gsize gtm601_underscore_opsys_radio_access_mode_type_id__volatile = 0;
	if (g_once_init_enter (&gtm601_underscore_opsys_radio_access_mode_type_id__volatile)) {
		static const GEnumValue values[] = {{GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_GSM, "GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_GSM", "gsm"}, {GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_UMTS, "GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_UMTS", "umts"}, {GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_ANY, "GTM601_UNDERSCORE_OPSYS_RADIO_ACCESS_MODE_ANY", "any"}, {0, NULL, NULL}};
		GType gtm601_underscore_opsys_radio_access_mode_type_id;
		gtm601_underscore_opsys_radio_access_mode_type_id = g_enum_register_static ("Gtm601UnderscoreOPSYSRadioAccessMode", values);
		g_once_init_leave (&gtm601_underscore_opsys_radio_access_mode_type_id__volatile, gtm601_underscore_opsys_radio_access_mode_type_id);
	}
	return gtm601_underscore_opsys_radio_access_mode_type_id__volatile;
}


gchar* gtm601_underscore_opsys_issue (Gtm601UnderscoreOPSYS* self, Gtm601UnderscoreOPSYSRadioAccessMode mode) {
	gchar* result = NULL;
	Gtm601UnderscoreOPSYSRadioAccessMode _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = mode;
	_tmp1_ = g_strdup_printf ("_OPSYS=%i,2", (gint) _tmp0_);
	result = _tmp1_;
	return result;
}


Gtm601UnderscoreOPSYS* gtm601_underscore_opsys_construct (GType object_type) {
	Gtm601UnderscoreOPSYS * self = NULL;
	self = (Gtm601UnderscoreOPSYS*) fso_gsm_abstract_at_command_construct (object_type);
	return self;
}


Gtm601UnderscoreOPSYS* gtm601_underscore_opsys_new (void) {
	return gtm601_underscore_opsys_construct (GTM601_TYPE_UNDERSCORE_OPSYS);
}


static void gtm601_underscore_opsys_class_init (Gtm601UnderscoreOPSYSClass * klass) {
	gtm601_underscore_opsys_parent_class = g_type_class_peek_parent (klass);
}


static void gtm601_underscore_opsys_instance_init (Gtm601UnderscoreOPSYS * self) {
}


GType gtm601_underscore_opsys_get_type (void) {
	return gtm601_underscore_opsys_type_id;
}


GType gtm601_underscore_opsys_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (Gtm601UnderscoreOPSYSClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gtm601_underscore_opsys_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Gtm601UnderscoreOPSYS), 0, (GInstanceInitFunc) gtm601_underscore_opsys_instance_init, NULL };
	gtm601_underscore_opsys_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_AT_COMMAND, "Gtm601UnderscoreOPSYS", &g_define_type_info, 0);
	return gtm601_underscore_opsys_type_id;
}


void gtm601_registerCustomAtCommands (GeeHashMap* table) {
	GeeHashMap* _tmp0_;
	Gtm601PlusCHUP* _tmp1_;
	Gtm601PlusCHUP* _tmp2_;
	GeeHashMap* _tmp3_;
	Gtm601UnderscoreOWANCALL* _tmp4_;
	Gtm601UnderscoreOWANCALL* _tmp5_;
	GeeHashMap* _tmp6_;
	Gtm601UnderscoreOWANDATA* _tmp7_;
	Gtm601UnderscoreOWANDATA* _tmp8_;
	GeeHashMap* _tmp9_;
	Gtm601ExtPlusCEER* _tmp10_;
	Gtm601ExtPlusCEER* _tmp11_;
	GeeHashMap* _tmp12_;
	Gtm601UnderscoreOSIGQ* _tmp13_;
	Gtm601UnderscoreOSIGQ* _tmp14_;
	GeeHashMap* _tmp15_;
	Gtm601UnderscoreOPSYS* _tmp16_;
	Gtm601UnderscoreOPSYS* _tmp17_;
	g_return_if_fail (table != NULL);
	_tmp0_ = table;
	_tmp1_ = gtm601_plus_chup_new ();
	_tmp2_ = _tmp1_;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp0_, "H", (FsoGsmAtCommand*) _tmp2_);
	_g_object_unref0 (_tmp2_);
	_tmp3_ = table;
	_tmp4_ = gtm601_underscore_owancall_new ();
	_tmp5_ = _tmp4_;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp3_, "_OWANCALL", (FsoGsmAtCommand*) _tmp5_);
	_g_object_unref0 (_tmp5_);
	_tmp6_ = table;
	_tmp7_ = gtm601_underscore_owandata_new ();
	_tmp8_ = _tmp7_;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp6_, "_OWANDATA", (FsoGsmAtCommand*) _tmp8_);
	_g_object_unref0 (_tmp8_);
	_tmp9_ = table;
	_tmp10_ = gtm601_ext_plus_ceer_new ();
	_tmp11_ = _tmp10_;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp9_, "+CEER", (FsoGsmAtCommand*) _tmp11_);
	_g_object_unref0 (_tmp11_);
	_tmp12_ = table;
	_tmp13_ = gtm601_underscore_osigq_new ();
	_tmp14_ = _tmp13_;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp12_, "_OSIGQ", (FsoGsmAtCommand*) _tmp14_);
	_g_object_unref0 (_tmp14_);
	_tmp15_ = table;
	_tmp16_ = gtm601_underscore_opsys_new ();
	_tmp17_ = _tmp16_;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp15_, "_OPSYS", (FsoGsmAtCommand*) _tmp17_);
	_g_object_unref0 (_tmp17_);
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




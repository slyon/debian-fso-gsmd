/* atparser.c generated by valac 0.16.1, the Vala compiler
 * generated from atparser.vala, do not modify */

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
#include <fsotransport.h>
#include <stdlib.h>
#include <string.h>


#define FSO_GSM_TYPE_STATE_BASED_AT_PARSER (fso_gsm_state_based_at_parser_get_type ())
#define FSO_GSM_STATE_BASED_AT_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_STATE_BASED_AT_PARSER, FsoGsmStateBasedAtParser))
#define FSO_GSM_STATE_BASED_AT_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_STATE_BASED_AT_PARSER, FsoGsmStateBasedAtParserClass))
#define FSO_GSM_IS_STATE_BASED_AT_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_STATE_BASED_AT_PARSER))
#define FSO_GSM_IS_STATE_BASED_AT_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_STATE_BASED_AT_PARSER))
#define FSO_GSM_STATE_BASED_AT_PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_STATE_BASED_AT_PARSER, FsoGsmStateBasedAtParserClass))

typedef struct _FsoGsmStateBasedAtParser FsoGsmStateBasedAtParser;
typedef struct _FsoGsmStateBasedAtParserClass FsoGsmStateBasedAtParserClass;
typedef struct _FsoGsmStateBasedAtParserPrivate FsoGsmStateBasedAtParserPrivate;

#define FSO_GSM_STATE_BASED_AT_PARSER_TYPE_STATE (fso_gsm_state_based_at_parser_state_get_type ())
#define _g_free0(var) (var = (g_free (var), NULL))

struct _FsoGsmStateBasedAtParser {
	FsoFrameworkBaseParser parent_instance;
	FsoGsmStateBasedAtParserPrivate * priv;
};

struct _FsoGsmStateBasedAtParserClass {
	FsoFrameworkBaseParserClass parent_class;
};

typedef enum  {
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID,
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_START,
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_START_R,
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_V0_RESULT,
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_A,
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_INLINE,
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_CONTINUATION,
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE,
	FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE_R
} FsoGsmStateBasedAtParserState;

struct _FsoGsmStateBasedAtParserPrivate {
	FsoGsmStateBasedAtParserState state;
	gchar* curline;
	gint curline_length1;
	gint _curline_size_;
	gchar** solicited;
	gint solicited_length1;
	gint _solicited_size_;
	gchar** unsolicited;
	gint unsolicited_length1;
	gint _unsolicited_size_;
	gboolean pendingUnsolicitedPDU;
	gboolean pendingSolicitedPDU;
	gchar** final_responses;
	gint final_responses_length1;
	gint _final_responses_size_;
	gchar** unsolicited_pdu;
	gint unsolicited_pdu_length1;
	gint _unsolicited_pdu_size_;
	gchar** solicited_pdu;
	gint solicited_pdu_length1;
	gint _solicited_pdu_size_;
};


static gpointer fso_gsm_state_based_at_parser_parent_class = NULL;

GType fso_gsm_state_based_at_parser_get_type (void) G_GNUC_CONST;
GType fso_gsm_state_based_at_parser_state_get_type (void) G_GNUC_CONST;
#define FSO_GSM_STATE_BASED_AT_PARSER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_GSM_TYPE_STATE_BASED_AT_PARSER, FsoGsmStateBasedAtParserPrivate))
enum  {
	FSO_GSM_STATE_BASED_AT_PARSER_DUMMY_PROPERTY
};
gboolean fso_gsm_state_based_at_parser_isFinalResponse (FsoGsmStateBasedAtParser* self);
gboolean fso_gsm_state_based_at_parser_hasUnsolicitedPdu (FsoGsmStateBasedAtParser* self);
gboolean fso_gsm_state_based_at_parser_hasSolicitedPdu (FsoGsmStateBasedAtParser* self);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_resetAll (FsoGsmStateBasedAtParser* self, gboolean soli);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_resetLine (FsoGsmStateBasedAtParser* self, gboolean end);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_dispatch (FsoGsmStateBasedAtParser* self, FsoGsmStateBasedAtParserState curstate, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_start (FsoGsmStateBasedAtParser* self, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_start_r (FsoGsmStateBasedAtParser* self, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_v0_result (FsoGsmStateBasedAtParser* self, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_echo_a (FsoGsmStateBasedAtParser* self, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_echo_inline (FsoGsmStateBasedAtParser* self, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_continuation (FsoGsmStateBasedAtParser* self, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_inline (FsoGsmStateBasedAtParser* self, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_inline_r (FsoGsmStateBasedAtParser* self, gchar c);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_invalid (FsoGsmStateBasedAtParser* self, gchar c);
static void _vala_array_add8 (gchar** array, int* length, int* size, gchar value);
static void _vala_array_add9 (gchar** array, int* length, int* size, gchar value);
static void _vala_array_add10 (gchar** array, int* length, int* size, gchar value);
static void _vala_array_add11 (gchar** array, int* length, int* size, gchar value);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_endofline (FsoGsmStateBasedAtParser* self);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_endoflineSurelySolicited (FsoGsmStateBasedAtParser* self);
static void _vala_array_add12 (gchar** array, int* length, int* size, gchar value);
static void _vala_array_add13 (gchar** array, int* length, int* size, gchar value);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_endoflineSurelyUnsolicited (FsoGsmStateBasedAtParser* self);
FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_endoflinePerhapsSolicited (FsoGsmStateBasedAtParser* self);
static void _vala_array_add14 (gchar*** array, int* length, int* size, gchar* value);
static void _vala_array_add15 (gchar*** array, int* length, int* size, gchar* value);
static void _vala_array_add16 (gchar*** array, int* length, int* size, gchar* value);
static void _vala_array_add17 (gchar*** array, int* length, int* size, gchar* value);
FsoGsmStateBasedAtParser* fso_gsm_state_based_at_parser_new (void);
FsoGsmStateBasedAtParser* fso_gsm_state_based_at_parser_construct (GType object_type);
static gint fso_gsm_state_based_at_parser_real_feed (FsoFrameworkBaseParser* base, gchar* data, gint len);
static void fso_gsm_state_based_at_parser_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


GType fso_gsm_state_based_at_parser_state_get_type (void) {
	static volatile gsize fso_gsm_state_based_at_parser_state_type_id__volatile = 0;
	if (g_once_init_enter (&fso_gsm_state_based_at_parser_state_type_id__volatile)) {
		static const GEnumValue values[] = {{FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID", "invalid"}, {FSO_GSM_STATE_BASED_AT_PARSER_STATE_START, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_START", "start"}, {FSO_GSM_STATE_BASED_AT_PARSER_STATE_START_R, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_START_R", "start-r"}, {FSO_GSM_STATE_BASED_AT_PARSER_STATE_V0_RESULT, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_V0_RESULT", "v0-result"}, {FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_A, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_A", "echo-a"}, {FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_INLINE, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_INLINE", "echo-inline"}, {FSO_GSM_STATE_BASED_AT_PARSER_STATE_CONTINUATION, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_CONTINUATION", "continuation"}, {FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE", "inline"}, {FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE_R, "FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE_R", "inline-r"}, {0, NULL, NULL}};
		GType fso_gsm_state_based_at_parser_state_type_id;
		fso_gsm_state_based_at_parser_state_type_id = g_enum_register_static ("FsoGsmStateBasedAtParserState", values);
		g_once_init_leave (&fso_gsm_state_based_at_parser_state_type_id__volatile, fso_gsm_state_based_at_parser_state_type_id);
	}
	return fso_gsm_state_based_at_parser_state_type_id__volatile;
}


gboolean fso_gsm_state_based_at_parser_isFinalResponse (FsoGsmStateBasedAtParser* self) {
	gboolean result = FALSE;
	gchar** _tmp0_;
	gint _tmp0__length1;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->final_responses;
	_tmp0__length1 = self->priv->final_responses_length1;
	{
		gchar** line_collection = NULL;
		gint line_collection_length1 = 0;
		gint _line_collection_size_ = 0;
		gint line_it = 0;
		line_collection = _tmp0_;
		line_collection_length1 = _tmp0__length1;
		for (line_it = 0; line_it < _tmp0__length1; line_it = line_it + 1) {
			gchar* _tmp1_;
			gchar* line = NULL;
			_tmp1_ = g_strdup (line_collection[line_it]);
			line = _tmp1_;
			{
				gchar* _tmp2_;
				gint _tmp2__length1;
				const gchar* _tmp3_;
				gboolean _tmp4_ = FALSE;
				_tmp2_ = self->priv->curline;
				_tmp2__length1 = self->priv->curline_length1;
				_tmp3_ = line;
				_tmp4_ = g_str_has_prefix ((const gchar*) _tmp2_, _tmp3_);
				if (_tmp4_) {
					result = TRUE;
					_g_free0 (line);
					return result;
				}
				_g_free0 (line);
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean fso_gsm_state_based_at_parser_hasUnsolicitedPdu (FsoGsmStateBasedAtParser* self) {
	gboolean result = FALSE;
	gchar** _tmp0_;
	gint _tmp0__length1;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->unsolicited_pdu;
	_tmp0__length1 = self->priv->unsolicited_pdu_length1;
	{
		gchar** line_collection = NULL;
		gint line_collection_length1 = 0;
		gint _line_collection_size_ = 0;
		gint line_it = 0;
		line_collection = _tmp0_;
		line_collection_length1 = _tmp0__length1;
		for (line_it = 0; line_it < _tmp0__length1; line_it = line_it + 1) {
			gchar* _tmp1_;
			gchar* line = NULL;
			_tmp1_ = g_strdup (line_collection[line_it]);
			line = _tmp1_;
			{
				gchar* _tmp2_;
				gint _tmp2__length1;
				const gchar* _tmp3_;
				gboolean _tmp4_ = FALSE;
				_tmp2_ = self->priv->curline;
				_tmp2__length1 = self->priv->curline_length1;
				_tmp3_ = line;
				_tmp4_ = g_str_has_prefix ((const gchar*) _tmp2_, _tmp3_);
				if (_tmp4_) {
					result = TRUE;
					_g_free0 (line);
					return result;
				}
				_g_free0 (line);
			}
		}
	}
	result = FALSE;
	return result;
}


gboolean fso_gsm_state_based_at_parser_hasSolicitedPdu (FsoGsmStateBasedAtParser* self) {
	gboolean result = FALSE;
	gchar** _tmp0_;
	gint _tmp0__length1;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->solicited_pdu;
	_tmp0__length1 = self->priv->solicited_pdu_length1;
	{
		gchar** line_collection = NULL;
		gint line_collection_length1 = 0;
		gint _line_collection_size_ = 0;
		gint line_it = 0;
		line_collection = _tmp0_;
		line_collection_length1 = _tmp0__length1;
		for (line_it = 0; line_it < _tmp0__length1; line_it = line_it + 1) {
			gchar* _tmp1_;
			gchar* line = NULL;
			_tmp1_ = g_strdup (line_collection[line_it]);
			line = _tmp1_;
			{
				gchar* _tmp2_;
				gint _tmp2__length1;
				const gchar* _tmp3_;
				gboolean _tmp4_ = FALSE;
				_tmp2_ = self->priv->curline;
				_tmp2__length1 = self->priv->curline_length1;
				_tmp3_ = line;
				_tmp4_ = g_str_has_prefix ((const gchar*) _tmp2_, _tmp3_);
				if (_tmp4_) {
					result = TRUE;
					_g_free0 (line);
					return result;
				}
				_g_free0 (line);
			}
		}
	}
	result = FALSE;
	return result;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_resetAll (FsoGsmStateBasedAtParser* self, gboolean soli) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar** _tmp0_ = NULL;
	gboolean _tmp1_;
	FsoGsmStateBasedAtParserState _tmp3_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = g_new0 (gchar*, 0 + 1);
	self->priv->unsolicited = (_vala_array_free (self->priv->unsolicited, self->priv->unsolicited_length1, (GDestroyNotify) g_free), NULL);
	self->priv->unsolicited = _tmp0_;
	self->priv->unsolicited_length1 = 0;
	self->priv->_unsolicited_size_ = self->priv->unsolicited_length1;
	_tmp1_ = soli;
	if (_tmp1_) {
		gchar** _tmp2_ = NULL;
		_tmp2_ = g_new0 (gchar*, 0 + 1);
		self->priv->solicited = (_vala_array_free (self->priv->solicited, self->priv->solicited_length1, (GDestroyNotify) g_free), NULL);
		self->priv->solicited = _tmp2_;
		self->priv->solicited_length1 = 0;
		self->priv->_solicited_size_ = self->priv->solicited_length1;
	}
	_tmp3_ = fso_gsm_state_based_at_parser_resetLine (self, TRUE);
	result = _tmp3_;
	return result;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_resetLine (FsoGsmStateBasedAtParser* self, gboolean end) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar* _tmp0_ = NULL;
	FsoGsmStateBasedAtParserState _tmp1_ = 0;
	gboolean _tmp2_;
	FsoGsmStateBasedAtParserState _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = g_new0 (gchar, 0);
	self->priv->curline = (g_free (self->priv->curline), NULL);
	self->priv->curline = _tmp0_;
	self->priv->curline_length1 = 0;
	self->priv->_curline_size_ = self->priv->curline_length1;
	_tmp2_ = end;
	if (_tmp2_) {
		_tmp1_ = FSO_GSM_STATE_BASED_AT_PARSER_STATE_START;
	} else {
		_tmp1_ = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE;
	}
	_tmp3_ = _tmp1_;
	result = _tmp3_;
	return result;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_dispatch (FsoGsmStateBasedAtParser* self, FsoGsmStateBasedAtParserState curstate, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	FsoGsmStateBasedAtParserState _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = curstate;
	switch (_tmp0_) {
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_START:
		{
			gchar _tmp1_;
			FsoGsmStateBasedAtParserState _tmp2_ = 0;
			_tmp1_ = c;
			_tmp2_ = fso_gsm_state_based_at_parser_start (self, _tmp1_);
			result = _tmp2_;
			return result;
		}
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_START_R:
		{
			gchar _tmp3_;
			FsoGsmStateBasedAtParserState _tmp4_ = 0;
			_tmp3_ = c;
			_tmp4_ = fso_gsm_state_based_at_parser_start_r (self, _tmp3_);
			result = _tmp4_;
			return result;
		}
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_V0_RESULT:
		{
			gchar _tmp5_;
			FsoGsmStateBasedAtParserState _tmp6_ = 0;
			_tmp5_ = c;
			_tmp6_ = fso_gsm_state_based_at_parser_v0_result (self, _tmp5_);
			result = _tmp6_;
			return result;
		}
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_A:
		{
			gchar _tmp7_;
			FsoGsmStateBasedAtParserState _tmp8_ = 0;
			_tmp7_ = c;
			_tmp8_ = fso_gsm_state_based_at_parser_echo_a (self, _tmp7_);
			result = _tmp8_;
			return result;
		}
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_INLINE:
		{
			gchar _tmp9_;
			FsoGsmStateBasedAtParserState _tmp10_ = 0;
			_tmp9_ = c;
			_tmp10_ = fso_gsm_state_based_at_parser_echo_inline (self, _tmp9_);
			result = _tmp10_;
			return result;
		}
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_CONTINUATION:
		{
			gchar _tmp11_;
			FsoGsmStateBasedAtParserState _tmp12_ = 0;
			_tmp11_ = c;
			_tmp12_ = fso_gsm_state_based_at_parser_continuation (self, _tmp11_);
			result = _tmp12_;
			return result;
		}
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE:
		{
			gchar _tmp13_;
			FsoGsmStateBasedAtParserState _tmp14_ = 0;
			_tmp13_ = c;
			_tmp14_ = fso_gsm_state_based_at_parser_inline (self, _tmp13_);
			result = _tmp14_;
			return result;
		}
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE_R:
		{
			gchar _tmp15_;
			FsoGsmStateBasedAtParserState _tmp16_ = 0;
			_tmp15_ = c;
			_tmp16_ = fso_gsm_state_based_at_parser_inline_r (self, _tmp15_);
			result = _tmp16_;
			return result;
		}
		case FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID:
		{
			gchar _tmp17_;
			FsoGsmStateBasedAtParserState _tmp18_ = 0;
			_tmp17_ = c;
			_tmp18_ = fso_gsm_state_based_at_parser_invalid (self, _tmp17_);
			result = _tmp18_;
			return result;
		}
		default:
		{
			g_assert_not_reached ();
		}
	}
}


static void _vala_array_add8 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void _vala_array_add9 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_start (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	FsoFrameworkParserHaveCommandFunc _tmp1_;
	void* _tmp1__target;
	gboolean _tmp2_ = FALSE;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	switch (_tmp0_) {
		case '\r':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_START_R;
			return result;
		}
		case '\n':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE;
			return result;
		}
		default:
		break;
	}
	_tmp1_ = ((FsoFrameworkBaseParser*) self)->haveCommand;
	_tmp1__target = ((FsoFrameworkBaseParser*) self)->haveCommand_target;
	_tmp2_ = _tmp1_ (_tmp1__target);
	if (_tmp2_) {
		gchar _tmp3_;
		_tmp3_ = c;
		switch (_tmp3_) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			{
				result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_V0_RESULT;
				return result;
			}
			case '\r':
			{
				result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_START_R;
				return result;
			}
			case 'A':
			case 'a':
			{
				result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_A;
				return result;
			}
			case '>':
			{
				result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_CONTINUATION;
				return result;
			}
			default:
			{
				gchar* _tmp4_;
				gint _tmp4__length1;
				gchar _tmp5_;
				_tmp4_ = self->priv->curline;
				_tmp4__length1 = self->priv->curline_length1;
				_tmp5_ = c;
				_vala_array_add8 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, _tmp5_);
				result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE;
				return result;
			}
		}
	} else {
		gchar* _tmp6_;
		gint _tmp6__length1;
		gchar _tmp7_;
		_tmp6_ = self->priv->curline;
		_tmp6__length1 = self->priv->curline_length1;
		_tmp7_ = c;
		_vala_array_add9 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, _tmp7_);
		result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE;
		return result;
	}
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_echo_a (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	switch (_tmp0_) {
		case 'T':
		case 't':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_INLINE;
			return result;
		}
		default:
		break;
	}
	result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID;
	return result;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_echo_inline (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	switch (_tmp0_) {
		case '\r':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_START_R;
			return result;
		}
		default:
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_ECHO_INLINE;
			return result;
		}
	}
}


static void _vala_array_add10 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void _vala_array_add11 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_v0_result (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	switch (_tmp0_) {
		case '\r':
		{
			gchar* _tmp1_;
			gint _tmp1__length1;
			gchar* _tmp2_;
			gint _tmp2__length1;
			FsoGsmStateBasedAtParserState _tmp3_ = 0;
			_tmp1_ = self->priv->curline;
			_tmp1__length1 = self->priv->curline_length1;
			_vala_array_add10 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, 'O');
			_tmp2_ = self->priv->curline;
			_tmp2__length1 = self->priv->curline_length1;
			_vala_array_add11 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, 'K');
			_tmp3_ = fso_gsm_state_based_at_parser_endofline (self);
			result = _tmp3_;
			return result;
		}
		default:
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID;
			return result;
		}
	}
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_continuation (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	switch (_tmp0_) {
		case ' ':
		{
			gchar* _tmp1_ = NULL;
			FsoGsmStateBasedAtParserState _tmp2_ = 0;
			_tmp1_ = g_new0 (gchar, 2);
			_tmp1_[0] = '>';
			_tmp1_[1] = ' ';
			self->priv->curline = (g_free (self->priv->curline), NULL);
			self->priv->curline = _tmp1_;
			self->priv->curline_length1 = 2;
			self->priv->_curline_size_ = self->priv->curline_length1;
			_tmp2_ = fso_gsm_state_based_at_parser_endoflineSurelySolicited (self);
			result = _tmp2_;
			return result;
		}
		default:
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID;
			return result;
		}
	}
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_start_r (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	switch (_tmp0_) {
		case '\r':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_START_R;
			return result;
		}
		case '\n':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE;
			return result;
		}
		default:
		break;
	}
	result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID;
	return result;
}


static void _vala_array_add12 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_inline (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	switch (_tmp0_) {
		case '>':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_CONTINUATION;
			return result;
		}
		case '\r':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE_R;
			return result;
		}
		default:
		{
			gchar* _tmp1_;
			gint _tmp1__length1;
			gchar _tmp2_;
			_tmp1_ = self->priv->curline;
			_tmp1__length1 = self->priv->curline_length1;
			_tmp2_ = c;
			_vala_array_add12 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, _tmp2_);
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE;
			return result;
		}
	}
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_inline_r (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	switch (_tmp0_) {
		case '\r':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE_R;
			return result;
		}
		case '\n':
		{
			FsoGsmStateBasedAtParserState _tmp1_ = 0;
			_tmp1_ = fso_gsm_state_based_at_parser_endofline (self);
			result = _tmp1_;
			return result;
		}
		default:
		break;
	}
	result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID;
	return result;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_invalid (FsoGsmStateBasedAtParser* self, gchar c) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	g_warning ("atparser.vala:302: Invalid Parser State! Trying to resync...");
	_tmp0_ = c;
	switch (_tmp0_) {
		case '\n':
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_START;
			return result;
		}
		default:
		{
			result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID;
			return result;
		}
	}
}


static void _vala_array_add13 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_endofline (FsoGsmStateBasedAtParser* self) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar* _tmp0_;
	gint _tmp0__length1;
	gchar* _tmp1_;
	gint _tmp1__length1;
	FsoFrameworkParserHaveCommandFunc _tmp2_;
	void* _tmp2__target;
	gboolean _tmp3_ = FALSE;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->curline;
	_tmp0__length1 = self->priv->curline_length1;
	if (_tmp0__length1 == 0) {
		result = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INLINE;
		return result;
	}
	_tmp1_ = self->priv->curline;
	_tmp1__length1 = self->priv->curline_length1;
	_vala_array_add13 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, (gchar) 0x0);
	_tmp2_ = ((FsoFrameworkBaseParser*) self)->haveCommand;
	_tmp2__target = ((FsoFrameworkBaseParser*) self)->haveCommand_target;
	_tmp3_ = _tmp2_ (_tmp2__target);
	if (!_tmp3_) {
		FsoGsmStateBasedAtParserState _tmp4_ = 0;
		_tmp4_ = fso_gsm_state_based_at_parser_endoflineSurelyUnsolicited (self);
		result = _tmp4_;
		return result;
	} else {
		FsoGsmStateBasedAtParserState _tmp5_ = 0;
		_tmp5_ = fso_gsm_state_based_at_parser_endoflinePerhapsSolicited (self);
		result = _tmp5_;
		return result;
	}
}


static void _vala_array_add14 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


static void _vala_array_add15 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_endoflinePerhapsSolicited (FsoGsmStateBasedAtParser* self) {
	FsoGsmStateBasedAtParserState result = 0;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp2_;
	gboolean _tmp4_;
	FsoFrameworkParserExpectedPrefixFunc _tmp9_;
	void* _tmp9__target;
	gchar* _tmp10_;
	gint _tmp10__length1;
	gboolean _tmp11_ = FALSE;
	gboolean _tmp13_ = FALSE;
	gchar** _tmp14_;
	gint _tmp14__length1;
	gchar* _tmp15_;
	gint _tmp15__length1;
	gchar* _tmp16_;
	FsoGsmStateBasedAtParserState _tmp17_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = fso_gsm_state_based_at_parser_isFinalResponse (self);
	if (_tmp0_) {
		FsoGsmStateBasedAtParserState _tmp1_ = 0;
		_tmp1_ = fso_gsm_state_based_at_parser_endoflineSurelySolicited (self);
		result = _tmp1_;
		return result;
	}
	_tmp2_ = self->priv->pendingUnsolicitedPDU;
	if (_tmp2_) {
		FsoGsmStateBasedAtParserState _tmp3_ = 0;
		_tmp3_ = fso_gsm_state_based_at_parser_endoflineSurelyUnsolicited (self);
		result = _tmp3_;
		return result;
	}
	_tmp4_ = self->priv->pendingSolicitedPDU;
	if (_tmp4_) {
		gchar** _tmp5_;
		gint _tmp5__length1;
		gchar* _tmp6_;
		gint _tmp6__length1;
		gchar* _tmp7_;
		FsoGsmStateBasedAtParserState _tmp8_ = 0;
		_tmp5_ = self->priv->solicited;
		_tmp5__length1 = self->priv->solicited_length1;
		_tmp6_ = self->priv->curline;
		_tmp6__length1 = self->priv->curline_length1;
		_tmp7_ = g_strdup ((const gchar*) _tmp6_);
		_vala_array_add14 (&self->priv->solicited, &self->priv->solicited_length1, &self->priv->_solicited_size_, _tmp7_);
		self->priv->pendingSolicitedPDU = FALSE;
		_tmp8_ = fso_gsm_state_based_at_parser_resetLine (self, FALSE);
		result = _tmp8_;
		return result;
	}
	_tmp9_ = ((FsoFrameworkBaseParser*) self)->expectedPrefix;
	_tmp9__target = ((FsoFrameworkBaseParser*) self)->expectedPrefix_target;
	_tmp10_ = self->priv->curline;
	_tmp10__length1 = self->priv->curline_length1;
	_tmp11_ = _tmp9_ ((const gchar*) _tmp10_, _tmp9__target);
	if (!_tmp11_) {
		FsoGsmStateBasedAtParserState _tmp12_ = 0;
		_tmp12_ = fso_gsm_state_based_at_parser_endoflineSurelyUnsolicited (self);
		result = _tmp12_;
		return result;
	}
	_tmp13_ = fso_gsm_state_based_at_parser_hasSolicitedPdu (self);
	self->priv->pendingSolicitedPDU = _tmp13_;
	_tmp14_ = self->priv->solicited;
	_tmp14__length1 = self->priv->solicited_length1;
	_tmp15_ = self->priv->curline;
	_tmp15__length1 = self->priv->curline_length1;
	_tmp16_ = g_strdup ((const gchar*) _tmp15_);
	_vala_array_add15 (&self->priv->solicited, &self->priv->solicited_length1, &self->priv->_solicited_size_, _tmp16_);
	_tmp17_ = fso_gsm_state_based_at_parser_resetLine (self, FALSE);
	result = _tmp17_;
	return result;
}


static void _vala_array_add16 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_endoflineSurelySolicited (FsoGsmStateBasedAtParser* self) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar** _tmp0_;
	gint _tmp0__length1;
	gchar* _tmp1_;
	gint _tmp1__length1;
	gchar* _tmp2_;
	FsoFrameworkParserSolicitedCompletedFunc _tmp3_;
	void* _tmp3__target;
	gchar** _tmp4_;
	gint _tmp4__length1;
	FsoGsmStateBasedAtParserState _tmp5_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->solicited;
	_tmp0__length1 = self->priv->solicited_length1;
	_tmp1_ = self->priv->curline;
	_tmp1__length1 = self->priv->curline_length1;
	_tmp2_ = g_strdup ((const gchar*) _tmp1_);
	_vala_array_add16 (&self->priv->solicited, &self->priv->solicited_length1, &self->priv->_solicited_size_, _tmp2_);
	_tmp3_ = ((FsoFrameworkBaseParser*) self)->solicitedCompleted;
	_tmp3__target = ((FsoFrameworkBaseParser*) self)->solicitedCompleted_target;
	_tmp4_ = self->priv->solicited;
	_tmp4__length1 = self->priv->solicited_length1;
	_tmp3_ (_tmp4_, _tmp4__length1, _tmp3__target);
	_tmp5_ = fso_gsm_state_based_at_parser_resetAll (self, TRUE);
	result = _tmp5_;
	return result;
}


static void _vala_array_add17 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


FsoGsmStateBasedAtParserState fso_gsm_state_based_at_parser_endoflineSurelyUnsolicited (FsoGsmStateBasedAtParser* self) {
	FsoGsmStateBasedAtParserState result = 0;
	gchar** _tmp0_;
	gint _tmp0__length1;
	gchar* _tmp1_;
	gint _tmp1__length1;
	gchar* _tmp2_;
	gboolean _tmp3_;
	gboolean _tmp7_ = FALSE;
	FsoFrameworkParserUnsolicitedCompletedFunc _tmp9_;
	void* _tmp9__target;
	gchar** _tmp10_;
	gint _tmp10__length1;
	FsoGsmStateBasedAtParserState _tmp11_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->unsolicited;
	_tmp0__length1 = self->priv->unsolicited_length1;
	_tmp1_ = self->priv->curline;
	_tmp1__length1 = self->priv->curline_length1;
	_tmp2_ = g_strdup ((const gchar*) _tmp1_);
	_vala_array_add17 (&self->priv->unsolicited, &self->priv->unsolicited_length1, &self->priv->_unsolicited_size_, _tmp2_);
	_tmp3_ = self->priv->pendingUnsolicitedPDU;
	if (_tmp3_) {
		FsoFrameworkParserUnsolicitedCompletedFunc _tmp4_;
		void* _tmp4__target;
		gchar** _tmp5_;
		gint _tmp5__length1;
		FsoGsmStateBasedAtParserState _tmp6_ = 0;
		self->priv->pendingUnsolicitedPDU = FALSE;
		_tmp4_ = ((FsoFrameworkBaseParser*) self)->unsolicitedCompleted;
		_tmp4__target = ((FsoFrameworkBaseParser*) self)->unsolicitedCompleted_target;
		_tmp5_ = self->priv->unsolicited;
		_tmp5__length1 = self->priv->unsolicited_length1;
		_tmp4_ (_tmp5_, _tmp5__length1, _tmp4__target);
		_tmp6_ = fso_gsm_state_based_at_parser_resetAll (self, FALSE);
		result = _tmp6_;
		return result;
	}
	_tmp7_ = fso_gsm_state_based_at_parser_hasUnsolicitedPdu (self);
	if (_tmp7_) {
		FsoGsmStateBasedAtParserState _tmp8_ = 0;
		self->priv->pendingUnsolicitedPDU = TRUE;
		_tmp8_ = fso_gsm_state_based_at_parser_resetLine (self, FALSE);
		result = _tmp8_;
		return result;
	}
	_tmp9_ = ((FsoFrameworkBaseParser*) self)->unsolicitedCompleted;
	_tmp9__target = ((FsoFrameworkBaseParser*) self)->unsolicitedCompleted_target;
	_tmp10_ = self->priv->unsolicited;
	_tmp10__length1 = self->priv->unsolicited_length1;
	_tmp9_ (_tmp10_, _tmp10__length1, _tmp9__target);
	_tmp11_ = fso_gsm_state_based_at_parser_resetAll (self, FALSE);
	result = _tmp11_;
	return result;
}


FsoGsmStateBasedAtParser* fso_gsm_state_based_at_parser_construct (GType object_type) {
	FsoGsmStateBasedAtParser * self = NULL;
	FsoGsmStateBasedAtParserState _tmp0_ = 0;
	self = (FsoGsmStateBasedAtParser*) fso_framework_base_parser_construct (object_type);
	_tmp0_ = fso_gsm_state_based_at_parser_resetAll (self, TRUE);
	self->priv->state = _tmp0_;
	return self;
}


FsoGsmStateBasedAtParser* fso_gsm_state_based_at_parser_new (void) {
	return fso_gsm_state_based_at_parser_construct (FSO_GSM_TYPE_STATE_BASED_AT_PARSER);
}


static gint fso_gsm_state_based_at_parser_real_feed (FsoFrameworkBaseParser* base, gchar* data, gint len) {
	FsoGsmStateBasedAtParser * self;
	gint result = 0;
	gint _tmp0_;
	FsoGsmStateBasedAtParserState _tmp10_;
	self = (FsoGsmStateBasedAtParser*) base;
	_tmp0_ = len;
	g_assert (_tmp0_ > 0);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp1_;
			_tmp1_ = TRUE;
			while (TRUE) {
				gboolean _tmp2_;
				gint _tmp4_;
				gint _tmp5_;
				gchar* _tmp6_;
				gchar c;
				FsoGsmStateBasedAtParserState _tmp7_;
				gchar _tmp8_;
				FsoGsmStateBasedAtParserState _tmp9_ = 0;
				_tmp2_ = _tmp1_;
				if (!_tmp2_) {
					gint _tmp3_;
					_tmp3_ = i;
					i = _tmp3_ + 1;
				}
				_tmp1_ = FALSE;
				_tmp4_ = i;
				_tmp5_ = len;
				if (!(_tmp4_ < _tmp5_)) {
					break;
				}
				_tmp6_ = data;
				data = _tmp6_ + 1;
				c = *_tmp6_;
				_tmp7_ = self->priv->state;
				_tmp8_ = c;
				_tmp9_ = fso_gsm_state_based_at_parser_dispatch (self, _tmp7_, _tmp8_);
				self->priv->state = _tmp9_;
			}
		}
	}
	_tmp10_ = self->priv->state;
	result = (gint) _tmp10_;
	return result;
}


static void fso_gsm_state_based_at_parser_class_init (FsoGsmStateBasedAtParserClass * klass) {
	fso_gsm_state_based_at_parser_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoGsmStateBasedAtParserPrivate));
	FSO_FRAMEWORK_BASE_PARSER_CLASS (klass)->feed = fso_gsm_state_based_at_parser_real_feed;
	G_OBJECT_CLASS (klass)->finalize = fso_gsm_state_based_at_parser_finalize;
}


static void fso_gsm_state_based_at_parser_instance_init (FsoGsmStateBasedAtParser * self) {
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar** _tmp10_ = NULL;
	gchar* _tmp11_;
	gchar* _tmp12_;
	gchar* _tmp13_;
	gchar** _tmp14_ = NULL;
	gchar* _tmp15_;
	gchar* _tmp16_;
	gchar** _tmp17_ = NULL;
	self->priv = FSO_GSM_STATE_BASED_AT_PARSER_GET_PRIVATE (self);
	self->priv->state = FSO_GSM_STATE_BASED_AT_PARSER_STATE_INVALID;
	_tmp0_ = g_strdup ("OK");
	_tmp1_ = g_strdup ("ERROR");
	_tmp2_ = g_strdup ("+CME ERROR");
	_tmp3_ = g_strdup ("+CMS ERROR");
	_tmp4_ = g_strdup ("+EXT ERROR");
	_tmp5_ = g_strdup ("BUSY");
	_tmp6_ = g_strdup ("CONNECT");
	_tmp7_ = g_strdup ("NO ANSWER");
	_tmp8_ = g_strdup ("NO CARRIER");
	_tmp9_ = g_strdup ("NO DIALTONE");
	_tmp10_ = g_new0 (gchar*, 10 + 1);
	_tmp10_[0] = _tmp0_;
	_tmp10_[1] = _tmp1_;
	_tmp10_[2] = _tmp2_;
	_tmp10_[3] = _tmp3_;
	_tmp10_[4] = _tmp4_;
	_tmp10_[5] = _tmp5_;
	_tmp10_[6] = _tmp6_;
	_tmp10_[7] = _tmp7_;
	_tmp10_[8] = _tmp8_;
	_tmp10_[9] = _tmp9_;
	self->priv->final_responses = _tmp10_;
	self->priv->final_responses_length1 = 10;
	self->priv->_final_responses_size_ = self->priv->final_responses_length1;
	_tmp11_ = g_strdup ("+CBM: ");
	_tmp12_ = g_strdup ("+CDS: ");
	_tmp13_ = g_strdup ("+CMT: ");
	_tmp14_ = g_new0 (gchar*, 3 + 1);
	_tmp14_[0] = _tmp11_;
	_tmp14_[1] = _tmp12_;
	_tmp14_[2] = _tmp13_;
	self->priv->unsolicited_pdu = _tmp14_;
	self->priv->unsolicited_pdu_length1 = 3;
	self->priv->_unsolicited_pdu_size_ = self->priv->unsolicited_pdu_length1;
	_tmp15_ = g_strdup ("+CMGL: ");
	_tmp16_ = g_strdup ("+CMGR: ");
	_tmp17_ = g_new0 (gchar*, 2 + 1);
	_tmp17_[0] = _tmp15_;
	_tmp17_[1] = _tmp16_;
	self->priv->solicited_pdu = _tmp17_;
	self->priv->solicited_pdu_length1 = 2;
	self->priv->_solicited_pdu_size_ = self->priv->solicited_pdu_length1;
}


static void fso_gsm_state_based_at_parser_finalize (GObject* obj) {
	FsoGsmStateBasedAtParser * self;
	self = FSO_GSM_STATE_BASED_AT_PARSER (obj);
	self->priv->curline = (g_free (self->priv->curline), NULL);
	self->priv->solicited = (_vala_array_free (self->priv->solicited, self->priv->solicited_length1, (GDestroyNotify) g_free), NULL);
	self->priv->unsolicited = (_vala_array_free (self->priv->unsolicited, self->priv->unsolicited_length1, (GDestroyNotify) g_free), NULL);
	self->priv->final_responses = (_vala_array_free (self->priv->final_responses, self->priv->final_responses_length1, (GDestroyNotify) g_free), NULL);
	self->priv->unsolicited_pdu = (_vala_array_free (self->priv->unsolicited_pdu, self->priv->unsolicited_pdu_length1, (GDestroyNotify) g_free), NULL);
	self->priv->solicited_pdu = (_vala_array_free (self->priv->solicited_pdu, self->priv->solicited_pdu_length1, (GDestroyNotify) g_free), NULL);
	G_OBJECT_CLASS (fso_gsm_state_based_at_parser_parent_class)->finalize (obj);
}


GType fso_gsm_state_based_at_parser_get_type (void) {
	static volatile gsize fso_gsm_state_based_at_parser_type_id__volatile = 0;
	if (g_once_init_enter (&fso_gsm_state_based_at_parser_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoGsmStateBasedAtParserClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_gsm_state_based_at_parser_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoGsmStateBasedAtParser), 0, (GInstanceInitFunc) fso_gsm_state_based_at_parser_instance_init, NULL };
		GType fso_gsm_state_based_at_parser_type_id;
		fso_gsm_state_based_at_parser_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_BASE_PARSER, "FsoGsmStateBasedAtParser", &g_define_type_info, 0);
		g_once_init_leave (&fso_gsm_state_based_at_parser_type_id__volatile, fso_gsm_state_based_at_parser_type_id);
	}
	return fso_gsm_state_based_at_parser_type_id__volatile;
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




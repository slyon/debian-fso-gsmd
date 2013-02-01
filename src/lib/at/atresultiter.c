/* atresultiter.c generated by valac 0.16.1, the Vala compiler
 * generated from atresultiter.vala, do not modify */

/*
 * Copyright (C) 2012 Simon Busch <morphis@gravedo.de>
 *
 * This is a Vala adoption of the GAtResultIter class implementation
 * from the ofono project.
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
#include <gobject/gvaluecollector.h>


#define FSO_GSM_TYPE_AT_RESULT_ITER (fso_gsm_at_result_iter_get_type ())
#define FSO_GSM_AT_RESULT_ITER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_AT_RESULT_ITER, FsoGsmAtResultIter))
#define FSO_GSM_AT_RESULT_ITER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_AT_RESULT_ITER, FsoGsmAtResultIterClass))
#define FSO_GSM_IS_AT_RESULT_ITER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_AT_RESULT_ITER))
#define FSO_GSM_IS_AT_RESULT_ITER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_AT_RESULT_ITER))
#define FSO_GSM_AT_RESULT_ITER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_AT_RESULT_ITER, FsoGsmAtResultIterClass))

typedef struct _FsoGsmAtResultIter FsoGsmAtResultIter;
typedef struct _FsoGsmAtResultIterClass FsoGsmAtResultIterClass;
typedef struct _FsoGsmAtResultIterPrivate FsoGsmAtResultIterPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _FsoGsmParamSpecAtResultIter FsoGsmParamSpecAtResultIter;

struct _FsoGsmAtResultIter {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FsoGsmAtResultIterPrivate * priv;
};

struct _FsoGsmAtResultIterClass {
	GTypeClass parent_class;
	void (*finalize) (FsoGsmAtResultIter *self);
};

struct _FsoGsmAtResultIterPrivate {
	gint _line_pos;
	gint _line_num;
	gchar** _lines;
	gint _lines_length1;
	gint __lines_size_;
	gchar* _line;
};

struct _FsoGsmParamSpecAtResultIter {
	GParamSpec parent_instance;
};


static gpointer fso_gsm_at_result_iter_parent_class = NULL;

#define FSO_GSM_AT_RESULT_LINE_LENGTH_MAX 2048
gpointer fso_gsm_at_result_iter_ref (gpointer instance);
void fso_gsm_at_result_iter_unref (gpointer instance);
GParamSpec* fso_gsm_param_spec_at_result_iter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fso_gsm_value_set_at_result_iter (GValue* value, gpointer v_object);
void fso_gsm_value_take_at_result_iter (GValue* value, gpointer v_object);
gpointer fso_gsm_value_get_at_result_iter (const GValue* value);
GType fso_gsm_at_result_iter_get_type (void) G_GNUC_CONST;
#define FSO_GSM_AT_RESULT_ITER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_GSM_TYPE_AT_RESULT_ITER, FsoGsmAtResultIterPrivate))
enum  {
	FSO_GSM_AT_RESULT_ITER_DUMMY_PROPERTY
};
static gint fso_gsm_at_result_iter_skip_to_next_field (FsoGsmAtResultIter* self, const gchar* line, gint pos);
static gint fso_gsm_at_result_iter_skip_until (FsoGsmAtResultIter* self, const gchar* line, gint start, gchar delim);
FsoGsmAtResultIter* fso_gsm_at_result_iter_new (gchar** lines, int lines_length1);
FsoGsmAtResultIter* fso_gsm_at_result_iter_construct (GType object_type, gchar** lines, int lines_length1);
static gchar** _vala_array_dup10 (gchar** self, int length);
void fso_gsm_at_result_iter_reset (FsoGsmAtResultIter* self);
gboolean fso_gsm_at_result_iter_next (FsoGsmAtResultIter* self, const gchar* prefix);
gboolean fso_gsm_at_result_iter_next_number (FsoGsmAtResultIter* self, gint* number);
gboolean fso_gsm_at_result_iter_next_string (FsoGsmAtResultIter* self, gchar** str);
gboolean fso_gsm_at_result_iter_next_unquoted_string (FsoGsmAtResultIter* self, gchar** str);
gboolean fso_gsm_at_result_iter_skip_next (FsoGsmAtResultIter* self);
gboolean fso_gsm_at_result_iter_open_list (FsoGsmAtResultIter* self);
gboolean fso_gsm_at_result_iter_close_list (FsoGsmAtResultIter* self);
static void fso_gsm_at_result_iter_finalize (FsoGsmAtResultIter* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_;
	gchar _tmp1_;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


static gint fso_gsm_at_result_iter_skip_to_next_field (FsoGsmAtResultIter* self, const gchar* line, gint pos) {
	gint result = 0;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_;
	const gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	gboolean _tmp8_;
	gint _tmp20_;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (line != NULL, 0);
	_tmp1_ = pos;
	_tmp2_ = line;
	_tmp3_ = strlen (_tmp2_);
	_tmp4_ = _tmp3_;
	if (_tmp1_ < _tmp4_) {
		const gchar* _tmp5_;
		gint _tmp6_;
		gchar _tmp7_ = '\0';
		_tmp5_ = line;
		_tmp6_ = pos;
		_tmp7_ = string_get (_tmp5_, (glong) _tmp6_);
		_tmp0_ = _tmp7_ == ',';
	} else {
		_tmp0_ = FALSE;
	}
	_tmp8_ = _tmp0_;
	if (_tmp8_) {
		gint _tmp9_;
		_tmp9_ = pos;
		pos = _tmp9_ + 1;
	}
	while (TRUE) {
		gboolean _tmp10_ = FALSE;
		gint _tmp11_;
		const gchar* _tmp12_;
		gint _tmp13_;
		gint _tmp14_;
		gboolean _tmp18_;
		gint _tmp19_;
		_tmp11_ = pos;
		_tmp12_ = line;
		_tmp13_ = strlen (_tmp12_);
		_tmp14_ = _tmp13_;
		if (_tmp11_ < _tmp14_) {
			const gchar* _tmp15_;
			gint _tmp16_;
			gchar _tmp17_ = '\0';
			_tmp15_ = line;
			_tmp16_ = pos;
			_tmp17_ = string_get (_tmp15_, (glong) _tmp16_);
			_tmp10_ = _tmp17_ == ' ';
		} else {
			_tmp10_ = FALSE;
		}
		_tmp18_ = _tmp10_;
		if (!_tmp18_) {
			break;
		}
		_tmp19_ = pos;
		pos = _tmp19_ + 1;
	}
	_tmp20_ = pos;
	result = _tmp20_;
	return result;
}


static gint fso_gsm_at_result_iter_skip_until (FsoGsmAtResultIter* self, const gchar* line, gint start, gchar delim) {
	gint result = 0;
	const gchar* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint len;
	gint _tmp3_;
	gint i;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (line != NULL, 0);
	_tmp0_ = line;
	_tmp1_ = strlen (_tmp0_);
	_tmp2_ = _tmp1_;
	len = _tmp2_;
	_tmp3_ = start;
	i = _tmp3_;
	while (TRUE) {
		gint _tmp4_;
		gint _tmp5_;
		const gchar* _tmp6_;
		gint _tmp7_;
		gchar _tmp8_ = '\0';
		gchar _tmp9_;
		const gchar* _tmp10_;
		gint _tmp11_;
		gchar _tmp12_ = '\0';
		const gchar* _tmp25_;
		gint _tmp26_;
		gchar _tmp27_ = '\0';
		const gchar* _tmp29_;
		gint _tmp30_;
		gint _tmp31_ = 0;
		gint _tmp32_;
		gint _tmp33_;
		_tmp4_ = i;
		_tmp5_ = len;
		if (!(_tmp4_ < _tmp5_)) {
			break;
		}
		_tmp6_ = line;
		_tmp7_ = i;
		_tmp8_ = string_get (_tmp6_, (glong) _tmp7_);
		_tmp9_ = delim;
		if (_tmp8_ == _tmp9_) {
			result = i;
			return result;
		}
		_tmp10_ = line;
		_tmp11_ = i;
		_tmp12_ = string_get (_tmp10_, (glong) _tmp11_);
		if (_tmp12_ == '\"') {
			gint _tmp13_;
			gint _tmp22_;
			gint _tmp23_;
			_tmp13_ = i;
			i = _tmp13_ + 1;
			while (TRUE) {
				gboolean _tmp14_ = FALSE;
				gint _tmp15_;
				gint _tmp16_;
				gboolean _tmp20_;
				gint _tmp21_;
				_tmp15_ = i;
				_tmp16_ = len;
				if (_tmp15_ < _tmp16_) {
					const gchar* _tmp17_;
					gint _tmp18_;
					gchar _tmp19_ = '\0';
					_tmp17_ = line;
					_tmp18_ = i;
					_tmp19_ = string_get (_tmp17_, (glong) _tmp18_);
					_tmp14_ = _tmp19_ != '\"';
				} else {
					_tmp14_ = FALSE;
				}
				_tmp20_ = _tmp14_;
				if (!_tmp20_) {
					break;
				}
				_tmp21_ = i;
				i = _tmp21_ + 1;
			}
			_tmp22_ = i;
			_tmp23_ = len;
			if (_tmp22_ < _tmp23_) {
				gint _tmp24_;
				_tmp24_ = i;
				i = _tmp24_ + 1;
			}
			continue;
		}
		_tmp25_ = line;
		_tmp26_ = i;
		_tmp27_ = string_get (_tmp25_, (glong) _tmp26_);
		if (_tmp27_ != '(') {
			gint _tmp28_;
			_tmp28_ = i;
			i = _tmp28_ + 1;
			continue;
		}
		_tmp29_ = line;
		_tmp30_ = i;
		_tmp31_ = fso_gsm_at_result_iter_skip_until (self, _tmp29_, _tmp30_ + 1, ')');
		i = _tmp31_;
		_tmp32_ = i;
		_tmp33_ = len;
		if (_tmp32_ < _tmp33_) {
			gint _tmp34_;
			_tmp34_ = i;
			i = _tmp34_ + 1;
		}
	}
	result = i;
	return result;
}


static gchar** _vala_array_dup10 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


FsoGsmAtResultIter* fso_gsm_at_result_iter_construct (GType object_type, gchar** lines, int lines_length1) {
	FsoGsmAtResultIter* self = NULL;
	gchar** _tmp0_;
	gint _tmp0__length1;
	gchar** _tmp1_;
	gint _tmp1__length1;
	self = (FsoGsmAtResultIter*) g_type_create_instance (object_type);
	_tmp0_ = lines;
	_tmp0__length1 = lines_length1;
	_tmp1_ = (_tmp0_ != NULL) ? _vala_array_dup10 (_tmp0_, _tmp0__length1) : ((gpointer) _tmp0_);
	_tmp1__length1 = _tmp0__length1;
	self->priv->_lines = (_vala_array_free (self->priv->_lines, self->priv->_lines_length1, (GDestroyNotify) g_free), NULL);
	self->priv->_lines = _tmp1_;
	self->priv->_lines_length1 = _tmp1__length1;
	self->priv->__lines_size_ = self->priv->_lines_length1;
	fso_gsm_at_result_iter_reset (self);
	return self;
}


FsoGsmAtResultIter* fso_gsm_at_result_iter_new (gchar** lines, int lines_length1) {
	return fso_gsm_at_result_iter_construct (FSO_GSM_TYPE_AT_RESULT_ITER, lines, lines_length1);
}


void fso_gsm_at_result_iter_reset (FsoGsmAtResultIter* self) {
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_line_pos = 0;
	self->priv->_line_num = 0;
	_tmp0_ = g_strdup ("");
	_g_free0 (self->priv->_line);
	self->priv->_line = _tmp0_;
}


gboolean fso_gsm_at_result_iter_next (FsoGsmAtResultIter* self, const gchar* prefix) {
	gboolean result = FALSE;
	gchar* _tmp0_;
	gchar* line;
	gboolean _result_;
	gint _tmp33_;
	gchar** _tmp34_;
	gint _tmp34__length1;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (prefix != NULL, FALSE);
	_tmp0_ = g_strdup ("");
	line = _tmp0_;
	_result_ = FALSE;
	{
		gboolean _tmp1_;
		_tmp1_ = TRUE;
		while (TRUE) {
			gboolean _tmp2_;
			gint _tmp4_;
			gchar** _tmp5_;
			gint _tmp5__length1;
			gchar** _tmp6_;
			gint _tmp6__length1;
			gint _tmp7_;
			const gchar* _tmp8_;
			gchar* _tmp9_;
			const gchar* _tmp10_;
			gint _tmp11_;
			gint _tmp12_;
			const gchar* _tmp14_;
			gint _tmp15_;
			gint _tmp16_;
			const gchar* _tmp17_;
			const gchar* _tmp18_;
			gboolean _tmp19_ = FALSE;
			_tmp2_ = _tmp1_;
			if (!_tmp2_) {
				gint _tmp3_;
				_tmp3_ = self->priv->_line_num;
				self->priv->_line_num = _tmp3_ + 1;
			}
			_tmp1_ = FALSE;
			_tmp4_ = self->priv->_line_num;
			_tmp5_ = self->priv->_lines;
			_tmp5__length1 = self->priv->_lines_length1;
			if (!(_tmp4_ < _tmp5__length1)) {
				break;
			}
			_tmp6_ = self->priv->_lines;
			_tmp6__length1 = self->priv->_lines_length1;
			_tmp7_ = self->priv->_line_num;
			_tmp8_ = _tmp6_[_tmp7_];
			_tmp9_ = g_strdup (_tmp8_);
			_g_free0 (line);
			line = _tmp9_;
			_tmp10_ = line;
			_tmp11_ = strlen (_tmp10_);
			_tmp12_ = _tmp11_;
			if (_tmp12_ > FSO_GSM_AT_RESULT_LINE_LENGTH_MAX) {
				gint _tmp13_;
				_tmp13_ = self->priv->_line_num;
				self->priv->_line_num = _tmp13_ + 1;
				continue;
			}
			_tmp14_ = prefix;
			_tmp15_ = strlen (_tmp14_);
			_tmp16_ = _tmp15_;
			if (_tmp16_ == 0) {
				self->priv->_line_pos = 0;
				break;
			}
			_tmp17_ = line;
			_tmp18_ = prefix;
			_tmp19_ = g_str_has_prefix (_tmp17_, _tmp18_);
			if (_tmp19_) {
				const gchar* _tmp20_;
				gint _tmp21_;
				gint _tmp22_;
				_tmp20_ = prefix;
				_tmp21_ = strlen (_tmp20_);
				_tmp22_ = _tmp21_;
				self->priv->_line_pos = _tmp22_;
				while (TRUE) {
					gboolean _tmp23_ = FALSE;
					gint _tmp24_;
					const gchar* _tmp25_;
					gint _tmp26_;
					gint _tmp27_;
					gboolean _tmp31_;
					gint _tmp32_;
					_tmp24_ = self->priv->_line_pos;
					_tmp25_ = line;
					_tmp26_ = strlen (_tmp25_);
					_tmp27_ = _tmp26_;
					if (_tmp24_ < _tmp27_) {
						const gchar* _tmp28_;
						gint _tmp29_;
						gchar _tmp30_ = '\0';
						_tmp28_ = line;
						_tmp29_ = self->priv->_line_pos;
						_tmp30_ = string_get (_tmp28_, (glong) _tmp29_);
						_tmp23_ = _tmp30_ == ' ';
					} else {
						_tmp23_ = FALSE;
					}
					_tmp31_ = _tmp23_;
					if (!_tmp31_) {
						break;
					}
					_tmp32_ = self->priv->_line_pos;
					self->priv->_line_pos = _tmp32_ + 1;
				}
				break;
			}
		}
	}
	_tmp33_ = self->priv->_line_num;
	_tmp34_ = self->priv->_lines;
	_tmp34__length1 = self->priv->_lines_length1;
	if (_tmp33_ < _tmp34__length1) {
		const gchar* _tmp35_;
		gchar* _tmp36_ = NULL;
		gint _tmp37_;
		gchar** _tmp38_;
		gint _tmp38__length1;
		_tmp35_ = line;
		_tmp36_ = g_strdup (_tmp35_);
		_g_free0 (self->priv->_line);
		self->priv->_line = _tmp36_;
		_result_ = TRUE;
		_tmp37_ = self->priv->_line_num;
		_tmp38_ = self->priv->_lines;
		_tmp38__length1 = self->priv->_lines_length1;
		if (_tmp37_ == (_tmp38__length1 - 1)) {
			gchar** _tmp39_;
			gint _tmp39__length1;
			_tmp39_ = self->priv->_lines;
			_tmp39__length1 = self->priv->_lines_length1;
			self->priv->_line_num = _tmp39__length1;
		} else {
			gint _tmp40_;
			_tmp40_ = self->priv->_line_num;
			self->priv->_line_num = _tmp40_ + 1;
		}
	} else {
		gchar* _tmp41_;
		_tmp41_ = g_strdup ("");
		_g_free0 (self->priv->_line);
		self->priv->_line = _tmp41_;
		self->priv->_line_pos = 0;
	}
	result = _result_;
	_g_free0 (line);
	return result;
}


gboolean fso_gsm_at_result_iter_next_number (FsoGsmAtResultIter* self, gint* number) {
	gint _vala_number = 0;
	gboolean result = FALSE;
	gint _tmp0_;
	gint end;
	gint value;
	gint _tmp14_;
	gint _tmp15_;
	const gchar* _tmp16_;
	gint _tmp17_;
	gint _tmp18_ = 0;
	gint _tmp19_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_line_pos;
	end = _tmp0_;
	value = 0;
	while (TRUE) {
		gboolean _tmp1_ = FALSE;
		const gchar* _tmp2_;
		gint _tmp3_;
		gchar _tmp4_ = '\0';
		gboolean _tmp8_;
		gint _tmp9_;
		const gchar* _tmp10_;
		gint _tmp11_;
		gchar _tmp12_ = '\0';
		gint _tmp13_;
		_tmp2_ = self->priv->_line;
		_tmp3_ = end;
		_tmp4_ = string_get (_tmp2_, (glong) _tmp3_);
		if (_tmp4_ >= '0') {
			const gchar* _tmp5_;
			gint _tmp6_;
			gchar _tmp7_ = '\0';
			_tmp5_ = self->priv->_line;
			_tmp6_ = end;
			_tmp7_ = string_get (_tmp5_, (glong) _tmp6_);
			_tmp1_ = _tmp7_ <= '9';
		} else {
			_tmp1_ = FALSE;
		}
		_tmp8_ = _tmp1_;
		if (!_tmp8_) {
			break;
		}
		_tmp9_ = value;
		_tmp10_ = self->priv->_line;
		_tmp11_ = end;
		_tmp12_ = string_get (_tmp10_, (glong) _tmp11_);
		value = (_tmp9_ * 10) + ((gint) (_tmp12_ - '0'));
		_tmp13_ = end;
		end = _tmp13_ + 1;
	}
	_tmp14_ = self->priv->_line_pos;
	_tmp15_ = end;
	if (_tmp14_ == _tmp15_) {
		result = FALSE;
		if (number) {
			*number = _vala_number;
		}
		return result;
	}
	_tmp16_ = self->priv->_line;
	_tmp17_ = end;
	_tmp18_ = fso_gsm_at_result_iter_skip_to_next_field (self, _tmp16_, _tmp17_);
	self->priv->_line_pos = _tmp18_;
	_tmp19_ = value;
	_vala_number = _tmp19_;
	result = TRUE;
	if (number) {
		*number = _vala_number;
	}
	return result;
}


static glong string_strnlen (gchar* str, glong maxlen) {
	glong result = 0L;
	gchar* _tmp0_;
	glong _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* end;
	gchar* _tmp3_;
	_tmp0_ = str;
	_tmp1_ = maxlen;
	_tmp2_ = memchr (_tmp0_, 0, (gsize) _tmp1_);
	end = _tmp2_;
	_tmp3_ = end;
	if (_tmp3_ == NULL) {
		glong _tmp4_;
		_tmp4_ = maxlen;
		result = _tmp4_;
		return result;
	} else {
		gchar* _tmp5_;
		gchar* _tmp6_;
		_tmp5_ = end;
		_tmp6_ = str;
		result = (glong) (_tmp5_ - _tmp6_);
		return result;
	}
}


static gchar* string_substring (const gchar* self, glong offset, glong len) {
	gchar* result = NULL;
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	glong _tmp1_;
	gboolean _tmp3_;
	glong _tmp9_;
	glong _tmp15_;
	glong _tmp18_;
	glong _tmp19_;
	glong _tmp20_;
	glong _tmp21_;
	glong _tmp22_;
	gchar* _tmp23_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = offset;
	if (_tmp1_ >= ((glong) 0)) {
		glong _tmp2_;
		_tmp2_ = len;
		_tmp0_ = _tmp2_ >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		glong _tmp4_;
		glong _tmp5_;
		glong _tmp6_ = 0L;
		_tmp4_ = offset;
		_tmp5_ = len;
		_tmp6_ = string_strnlen ((gchar*) self, _tmp4_ + _tmp5_);
		string_length = _tmp6_;
	} else {
		gint _tmp7_;
		gint _tmp8_;
		_tmp7_ = strlen (self);
		_tmp8_ = _tmp7_;
		string_length = (glong) _tmp8_;
	}
	_tmp9_ = offset;
	if (_tmp9_ < ((glong) 0)) {
		glong _tmp10_;
		glong _tmp11_;
		glong _tmp12_;
		_tmp10_ = string_length;
		_tmp11_ = offset;
		offset = _tmp10_ + _tmp11_;
		_tmp12_ = offset;
		g_return_val_if_fail (_tmp12_ >= ((glong) 0), NULL);
	} else {
		glong _tmp13_;
		glong _tmp14_;
		_tmp13_ = offset;
		_tmp14_ = string_length;
		g_return_val_if_fail (_tmp13_ <= _tmp14_, NULL);
	}
	_tmp15_ = len;
	if (_tmp15_ < ((glong) 0)) {
		glong _tmp16_;
		glong _tmp17_;
		_tmp16_ = string_length;
		_tmp17_ = offset;
		len = _tmp16_ - _tmp17_;
	}
	_tmp18_ = offset;
	_tmp19_ = len;
	_tmp20_ = string_length;
	g_return_val_if_fail ((_tmp18_ + _tmp19_) <= _tmp20_, NULL);
	_tmp21_ = offset;
	_tmp22_ = len;
	_tmp23_ = g_strndup (((gchar*) self) + _tmp21_, (gsize) _tmp22_);
	result = _tmp23_;
	return result;
}


gboolean fso_gsm_at_result_iter_next_string (FsoGsmAtResultIter* self, gchar** str) {
	gchar* _vala_str = NULL;
	gboolean result = FALSE;
	gint end = 0;
	gint pos = 0;
	gint _tmp0_;
	const gchar* _tmp1_;
	gint _tmp2_;
	gchar _tmp3_ = '\0';
	const gchar* _tmp29_;
	gint _tmp30_;
	gint _tmp31_ = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_line_pos;
	pos = _tmp0_;
	_tmp1_ = self->priv->_line;
	_tmp2_ = pos;
	_tmp3_ = string_get (_tmp1_, (glong) _tmp2_);
	if (_tmp3_ == ',') {
		gint _tmp4_;
		gchar* _tmp5_;
		_tmp4_ = pos;
		end = _tmp4_;
		_tmp5_ = g_strdup ("");
		_g_free0 (_vala_str);
		_vala_str = _tmp5_;
	} else {
		const gchar* _tmp6_;
		gint _tmp7_;
		gchar _tmp8_ = '\0';
		gint _tmp9_;
		const gchar* _tmp20_;
		gint _tmp21_;
		gchar _tmp22_ = '\0';
		gint _tmp23_;
		const gchar* _tmp24_;
		gint _tmp25_;
		gint _tmp26_;
		gint _tmp27_;
		gchar* _tmp28_ = NULL;
		_tmp6_ = self->priv->_line;
		_tmp7_ = pos;
		pos = _tmp7_ + 1;
		_tmp8_ = string_get (_tmp6_, (glong) _tmp7_);
		if (_tmp8_ != '"') {
			result = FALSE;
			if (str) {
				*str = _vala_str;
			} else {
				_g_free0 (_vala_str);
			}
			return result;
		}
		_tmp9_ = pos;
		end = _tmp9_;
		while (TRUE) {
			gboolean _tmp10_ = FALSE;
			gint _tmp11_;
			const gchar* _tmp12_;
			gint _tmp13_;
			gint _tmp14_;
			gboolean _tmp18_;
			gint _tmp19_;
			_tmp11_ = end;
			_tmp12_ = self->priv->_line;
			_tmp13_ = strlen (_tmp12_);
			_tmp14_ = _tmp13_;
			if (_tmp11_ < _tmp14_) {
				const gchar* _tmp15_;
				gint _tmp16_;
				gchar _tmp17_ = '\0';
				_tmp15_ = self->priv->_line;
				_tmp16_ = end;
				_tmp17_ = string_get (_tmp15_, (glong) _tmp16_);
				_tmp10_ = _tmp17_ != '"';
			} else {
				_tmp10_ = FALSE;
			}
			_tmp18_ = _tmp10_;
			if (!_tmp18_) {
				break;
			}
			_tmp19_ = end;
			end = _tmp19_ + 1;
		}
		_tmp20_ = self->priv->_line;
		_tmp21_ = end;
		_tmp22_ = string_get (_tmp20_, (glong) _tmp21_);
		if (_tmp22_ != '"') {
			result = FALSE;
			if (str) {
				*str = _vala_str;
			} else {
				_g_free0 (_vala_str);
			}
			return result;
		}
		_tmp23_ = end;
		end = _tmp23_ + 1;
		_tmp24_ = self->priv->_line;
		_tmp25_ = self->priv->_line_pos;
		_tmp26_ = end;
		_tmp27_ = self->priv->_line_pos;
		_tmp28_ = string_substring (_tmp24_, (glong) (_tmp25_ + 1), (glong) ((_tmp26_ - _tmp27_) - 2));
		_g_free0 (_vala_str);
		_vala_str = _tmp28_;
	}
	_tmp29_ = self->priv->_line;
	_tmp30_ = end;
	_tmp31_ = fso_gsm_at_result_iter_skip_to_next_field (self, _tmp29_, _tmp30_);
	self->priv->_line_pos = _tmp31_;
	result = TRUE;
	if (str) {
		*str = _vala_str;
	} else {
		_g_free0 (_vala_str);
	}
	return result;
}


gboolean fso_gsm_at_result_iter_next_unquoted_string (FsoGsmAtResultIter* self, gchar** str) {
	gchar* _vala_str = NULL;
	gboolean result = FALSE;
	gint end = 0;
	gint pos = 0;
	gint _tmp0_;
	const gchar* _tmp1_;
	gint _tmp2_;
	gchar _tmp3_ = '\0';
	const gchar* _tmp35_;
	gint _tmp36_;
	gint _tmp37_ = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_line_pos;
	pos = _tmp0_;
	_tmp1_ = self->priv->_line;
	_tmp2_ = pos;
	_tmp3_ = string_get (_tmp1_, (glong) _tmp2_);
	if (_tmp3_ == ',') {
		gint _tmp4_;
		gchar* _tmp5_;
		_tmp4_ = pos;
		end = _tmp4_;
		_tmp5_ = g_strdup ("");
		_g_free0 (_vala_str);
		_vala_str = _tmp5_;
	} else {
		gboolean _tmp6_ = FALSE;
		const gchar* _tmp7_;
		gint _tmp8_;
		gchar _tmp9_ = '\0';
		gboolean _tmp13_;
		gint _tmp14_;
		const gchar* _tmp30_;
		gint _tmp31_;
		gint _tmp32_;
		gint _tmp33_;
		gchar* _tmp34_ = NULL;
		_tmp7_ = self->priv->_line;
		_tmp8_ = pos;
		_tmp9_ = string_get (_tmp7_, (glong) _tmp8_);
		if (_tmp9_ == '"') {
			_tmp6_ = TRUE;
		} else {
			const gchar* _tmp10_;
			gint _tmp11_;
			gchar _tmp12_ = '\0';
			_tmp10_ = self->priv->_line;
			_tmp11_ = pos;
			_tmp12_ = string_get (_tmp10_, (glong) _tmp11_);
			_tmp6_ = _tmp12_ == ')';
		}
		_tmp13_ = _tmp6_;
		if (_tmp13_) {
			result = FALSE;
			if (str) {
				*str = _vala_str;
			} else {
				_g_free0 (_vala_str);
			}
			return result;
		}
		_tmp14_ = pos;
		end = _tmp14_;
		while (TRUE) {
			gboolean _tmp15_ = FALSE;
			gboolean _tmp16_ = FALSE;
			gint _tmp17_;
			const gchar* _tmp18_;
			gint _tmp19_;
			gint _tmp20_;
			gboolean _tmp24_;
			gboolean _tmp28_;
			gint _tmp29_;
			_tmp17_ = end;
			_tmp18_ = self->priv->_line;
			_tmp19_ = strlen (_tmp18_);
			_tmp20_ = _tmp19_;
			if (_tmp17_ < _tmp20_) {
				const gchar* _tmp21_;
				gint _tmp22_;
				gchar _tmp23_ = '\0';
				_tmp21_ = self->priv->_line;
				_tmp22_ = end;
				_tmp23_ = string_get (_tmp21_, (glong) _tmp22_);
				_tmp16_ = _tmp23_ != ',';
			} else {
				_tmp16_ = FALSE;
			}
			_tmp24_ = _tmp16_;
			if (_tmp24_) {
				const gchar* _tmp25_;
				gint _tmp26_;
				gchar _tmp27_ = '\0';
				_tmp25_ = self->priv->_line;
				_tmp26_ = end;
				_tmp27_ = string_get (_tmp25_, (glong) _tmp26_);
				_tmp15_ = _tmp27_ != ')';
			} else {
				_tmp15_ = FALSE;
			}
			_tmp28_ = _tmp15_;
			if (!_tmp28_) {
				break;
			}
			_tmp29_ = end;
			end = _tmp29_ + 1;
		}
		_tmp30_ = self->priv->_line;
		_tmp31_ = self->priv->_line_pos;
		_tmp32_ = end;
		_tmp33_ = self->priv->_line_pos;
		_tmp34_ = string_substring (_tmp30_, (glong) _tmp31_, (glong) (_tmp32_ - _tmp33_));
		_g_free0 (_vala_str);
		_vala_str = _tmp34_;
	}
	_tmp35_ = self->priv->_line;
	_tmp36_ = end;
	_tmp37_ = fso_gsm_at_result_iter_skip_to_next_field (self, _tmp35_, _tmp36_);
	self->priv->_line_pos = _tmp37_;
	result = TRUE;
	if (str) {
		*str = _vala_str;
	} else {
		_g_free0 (_vala_str);
	}
	return result;
}


gboolean fso_gsm_at_result_iter_skip_next (FsoGsmAtResultIter* self) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gint _tmp1_;
	gint _tmp2_ = 0;
	gint skipped_to;
	gboolean _tmp3_ = FALSE;
	gint _tmp4_;
	gint _tmp5_;
	gboolean _tmp9_;
	const gchar* _tmp10_;
	gint _tmp11_;
	gint _tmp12_ = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_line;
	_tmp1_ = self->priv->_line_pos;
	_tmp2_ = fso_gsm_at_result_iter_skip_until (self, _tmp0_, _tmp1_, ',');
	skipped_to = _tmp2_;
	_tmp4_ = skipped_to;
	_tmp5_ = self->priv->_line_pos;
	if (_tmp4_ == _tmp5_) {
		const gchar* _tmp6_;
		gint _tmp7_;
		gchar _tmp8_ = '\0';
		_tmp6_ = self->priv->_line;
		_tmp7_ = skipped_to;
		_tmp8_ = string_get (_tmp6_, (glong) _tmp7_);
		_tmp3_ = _tmp8_ != ',';
	} else {
		_tmp3_ = FALSE;
	}
	_tmp9_ = _tmp3_;
	if (_tmp9_) {
		result = FALSE;
		return result;
	}
	_tmp10_ = self->priv->_line;
	_tmp11_ = skipped_to;
	_tmp12_ = fso_gsm_at_result_iter_skip_to_next_field (self, _tmp10_, _tmp11_);
	self->priv->_line_pos = _tmp12_;
	result = TRUE;
	return result;
}


gboolean fso_gsm_at_result_iter_open_list (FsoGsmAtResultIter* self) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint len;
	gint _tmp3_;
	gint _tmp4_;
	const gchar* _tmp5_;
	gint _tmp6_;
	gchar _tmp7_ = '\0';
	gint _tmp8_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_line;
	_tmp1_ = strlen (_tmp0_);
	_tmp2_ = _tmp1_;
	len = _tmp2_;
	_tmp3_ = self->priv->_line_pos;
	_tmp4_ = len;
	if (_tmp3_ >= _tmp4_) {
		result = FALSE;
		return result;
	}
	_tmp5_ = self->priv->_line;
	_tmp6_ = self->priv->_line_pos;
	_tmp7_ = string_get (_tmp5_, (glong) _tmp6_);
	if (_tmp7_ != '(') {
		result = FALSE;
		return result;
	}
	_tmp8_ = self->priv->_line_pos;
	self->priv->_line_pos = _tmp8_ + 1;
	while (TRUE) {
		gboolean _tmp9_ = FALSE;
		gint _tmp10_;
		gint _tmp11_;
		gboolean _tmp15_;
		gint _tmp16_;
		_tmp10_ = self->priv->_line_pos;
		_tmp11_ = len;
		if (_tmp10_ < _tmp11_) {
			const gchar* _tmp12_;
			gint _tmp13_;
			gchar _tmp14_ = '\0';
			_tmp12_ = self->priv->_line;
			_tmp13_ = self->priv->_line_pos;
			_tmp14_ = string_get (_tmp12_, (glong) _tmp13_);
			_tmp9_ = _tmp14_ == ' ';
		} else {
			_tmp9_ = FALSE;
		}
		_tmp15_ = _tmp9_;
		if (!_tmp15_) {
			break;
		}
		_tmp16_ = self->priv->_line_pos;
		self->priv->_line_pos = _tmp16_ + 1;
	}
	result = TRUE;
	return result;
}


gboolean fso_gsm_at_result_iter_close_list (FsoGsmAtResultIter* self) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint len;
	gint _tmp3_;
	gint _tmp4_;
	const gchar* _tmp5_;
	gint _tmp6_;
	gchar _tmp7_ = '\0';
	gint _tmp8_;
	const gchar* _tmp9_;
	gint _tmp10_;
	gint _tmp11_ = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_line;
	_tmp1_ = strlen (_tmp0_);
	_tmp2_ = _tmp1_;
	len = _tmp2_;
	_tmp3_ = self->priv->_line_pos;
	_tmp4_ = len;
	if (_tmp3_ >= _tmp4_) {
		result = FALSE;
		return result;
	}
	_tmp5_ = self->priv->_line;
	_tmp6_ = self->priv->_line_pos;
	_tmp7_ = string_get (_tmp5_, (glong) _tmp6_);
	if (_tmp7_ != ')') {
		result = FALSE;
		return result;
	}
	_tmp8_ = self->priv->_line_pos;
	self->priv->_line_pos = _tmp8_ + 1;
	_tmp9_ = self->priv->_line;
	_tmp10_ = self->priv->_line_pos;
	_tmp11_ = fso_gsm_at_result_iter_skip_to_next_field (self, _tmp9_, _tmp10_);
	self->priv->_line_pos = _tmp11_;
	result = TRUE;
	return result;
}


static void fso_gsm_value_at_result_iter_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void fso_gsm_value_at_result_iter_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		fso_gsm_at_result_iter_unref (value->data[0].v_pointer);
	}
}


static void fso_gsm_value_at_result_iter_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = fso_gsm_at_result_iter_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer fso_gsm_value_at_result_iter_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* fso_gsm_value_at_result_iter_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		FsoGsmAtResultIter* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = fso_gsm_at_result_iter_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* fso_gsm_value_at_result_iter_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	FsoGsmAtResultIter** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = fso_gsm_at_result_iter_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* fso_gsm_param_spec_at_result_iter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	FsoGsmParamSpecAtResultIter* spec;
	g_return_val_if_fail (g_type_is_a (object_type, FSO_GSM_TYPE_AT_RESULT_ITER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer fso_gsm_value_get_at_result_iter (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_GSM_TYPE_AT_RESULT_ITER), NULL);
	return value->data[0].v_pointer;
}


void fso_gsm_value_set_at_result_iter (GValue* value, gpointer v_object) {
	FsoGsmAtResultIter* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_GSM_TYPE_AT_RESULT_ITER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_GSM_TYPE_AT_RESULT_ITER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		fso_gsm_at_result_iter_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_gsm_at_result_iter_unref (old);
	}
}


void fso_gsm_value_take_at_result_iter (GValue* value, gpointer v_object) {
	FsoGsmAtResultIter* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_GSM_TYPE_AT_RESULT_ITER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_GSM_TYPE_AT_RESULT_ITER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_gsm_at_result_iter_unref (old);
	}
}


static void fso_gsm_at_result_iter_class_init (FsoGsmAtResultIterClass * klass) {
	fso_gsm_at_result_iter_parent_class = g_type_class_peek_parent (klass);
	FSO_GSM_AT_RESULT_ITER_CLASS (klass)->finalize = fso_gsm_at_result_iter_finalize;
	g_type_class_add_private (klass, sizeof (FsoGsmAtResultIterPrivate));
}


static void fso_gsm_at_result_iter_instance_init (FsoGsmAtResultIter * self) {
	self->priv = FSO_GSM_AT_RESULT_ITER_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void fso_gsm_at_result_iter_finalize (FsoGsmAtResultIter* obj) {
	FsoGsmAtResultIter * self;
	self = FSO_GSM_AT_RESULT_ITER (obj);
	self->priv->_lines = (_vala_array_free (self->priv->_lines, self->priv->_lines_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (self->priv->_line);
}


GType fso_gsm_at_result_iter_get_type (void) {
	static volatile gsize fso_gsm_at_result_iter_type_id__volatile = 0;
	if (g_once_init_enter (&fso_gsm_at_result_iter_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { fso_gsm_value_at_result_iter_init, fso_gsm_value_at_result_iter_free_value, fso_gsm_value_at_result_iter_copy_value, fso_gsm_value_at_result_iter_peek_pointer, "p", fso_gsm_value_at_result_iter_collect_value, "p", fso_gsm_value_at_result_iter_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (FsoGsmAtResultIterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_gsm_at_result_iter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoGsmAtResultIter), 0, (GInstanceInitFunc) fso_gsm_at_result_iter_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType fso_gsm_at_result_iter_type_id;
		fso_gsm_at_result_iter_type_id = g_type_register_fundamental (g_type_fundamental_next (), "FsoGsmAtResultIter", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&fso_gsm_at_result_iter_type_id__volatile, fso_gsm_at_result_iter_type_id);
	}
	return fso_gsm_at_result_iter_type_id__volatile;
}


gpointer fso_gsm_at_result_iter_ref (gpointer instance) {
	FsoGsmAtResultIter* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void fso_gsm_at_result_iter_unref (gpointer instance) {
	FsoGsmAtResultIter* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		FSO_GSM_AT_RESULT_ITER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
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




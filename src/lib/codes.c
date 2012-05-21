/* codes.c generated by valac 0.14.2, the Vala compiler
 * generated from codes.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))



gchar* codec_hexToString (const gchar* hex, guint lowest, guint highest, gchar* subst);


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


gchar* codec_hexToString (const gchar* hex, guint lowest, guint highest, gchar* subst) {
	gchar* result = NULL;
	GString* _tmp0_;
	GString* str;
	GString* _tmp27_;
	const gchar* _tmp28_;
	gchar* _tmp29_;
	g_return_val_if_fail (hex != NULL, NULL);
	_tmp0_ = g_string_new ("");
	str = _tmp0_;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp1_;
			_tmp1_ = TRUE;
			while (TRUE) {
				gboolean _tmp2_;
				gint _tmp4_;
				const gchar* _tmp5_;
				gint _tmp6_;
				gint _tmp7_;
				const gchar* _tmp8_;
				gint _tmp9_;
				gchar _tmp10_ = '\0';
				const gchar* _tmp11_;
				gint _tmp12_;
				gchar _tmp13_ = '\0';
				gchar* _tmp14_ = NULL;
				gchar* hexbyte;
				gint hexvalue = 0;
				const gchar* _tmp15_;
				gboolean _tmp16_ = FALSE;
				gint _tmp17_;
				guint _tmp18_;
				gboolean _tmp21_;
				_tmp2_ = _tmp1_;
				if (!_tmp2_) {
					gint _tmp3_;
					_tmp3_ = i;
					i = _tmp3_ + 1;
				}
				_tmp1_ = FALSE;
				_tmp4_ = i;
				_tmp5_ = hex;
				_tmp6_ = strlen (_tmp5_);
				_tmp7_ = _tmp6_;
				if (!(_tmp4_ < (_tmp7_ / 2))) {
					break;
				}
				_tmp8_ = hex;
				_tmp9_ = i;
				_tmp10_ = string_get (_tmp8_, (glong) ((_tmp9_ * 2) + 0));
				_tmp11_ = hex;
				_tmp12_ = i;
				_tmp13_ = string_get (_tmp11_, (glong) ((_tmp12_ * 2) + 1));
				_tmp14_ = g_strdup_printf ("%c%c", (gint) _tmp10_, (gint) _tmp13_);
				hexbyte = _tmp14_;
				_tmp15_ = hexbyte;
				sscanf (_tmp15_, "%02X", &hexvalue);
				_tmp17_ = hexvalue;
				_tmp18_ = lowest;
				if (((guint) _tmp17_) >= _tmp18_) {
					gint _tmp19_;
					guint _tmp20_;
					_tmp19_ = hexvalue;
					_tmp20_ = highest;
					_tmp16_ = ((guint) _tmp19_) <= _tmp20_;
				} else {
					_tmp16_ = FALSE;
				}
				_tmp21_ = _tmp16_;
				if (_tmp21_) {
					GString* _tmp22_;
					gint _tmp23_;
					_tmp22_ = str;
					_tmp23_ = hexvalue;
					g_string_append_c (_tmp22_, (gchar) _tmp23_);
				} else {
					gchar* _tmp24_;
					_tmp24_ = subst;
					if (_tmp24_ != NULL) {
						GString* _tmp25_;
						gchar* _tmp26_;
						_tmp25_ = str;
						_tmp26_ = subst;
						g_string_append_c (_tmp25_, *_tmp26_);
					}
				}
				_g_free0 (hexbyte);
			}
		}
	}
	_tmp27_ = str;
	_tmp28_ = _tmp27_->str;
	_tmp29_ = g_strdup (_tmp28_);
	result = _tmp29_;
	_g_string_free0 (str);
	return result;
}



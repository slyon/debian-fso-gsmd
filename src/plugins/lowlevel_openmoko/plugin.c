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
#include <fsobasics.h>
#include <fsogsm.h>
#include <stdlib.h>
#include <string.h>
#include <fsotransport.h>
#include <fsoframework.h>


#define LOW_LEVEL_TYPE_OPENMOKO (low_level_openmoko_get_type ())
#define LOW_LEVEL_OPENMOKO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LOW_LEVEL_TYPE_OPENMOKO, LowLevelOpenmoko))
#define LOW_LEVEL_OPENMOKO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LOW_LEVEL_TYPE_OPENMOKO, LowLevelOpenmokoClass))
#define LOW_LEVEL_IS_OPENMOKO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LOW_LEVEL_TYPE_OPENMOKO))
#define LOW_LEVEL_IS_OPENMOKO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LOW_LEVEL_TYPE_OPENMOKO))
#define LOW_LEVEL_OPENMOKO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LOW_LEVEL_TYPE_OPENMOKO, LowLevelOpenmokoClass))

typedef struct _LowLevelOpenmoko LowLevelOpenmoko;
typedef struct _LowLevelOpenmokoClass LowLevelOpenmokoClass;
typedef struct _LowLevelOpenmokoPrivate LowLevelOpenmokoPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _LowLevelOpenmoko {
	FsoFrameworkAbstractObject parent_instance;
	LowLevelOpenmokoPrivate * priv;
};

struct _LowLevelOpenmokoClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _LowLevelOpenmokoPrivate {
	gchar* powerNode;
	gchar* fcNode;
	FsoGsmAbstractModem* modem;
};


static gpointer low_level_openmoko_parent_class = NULL;
static FsoGsmLowLevelIface* low_level_openmoko_fso_gsm_low_level_parent_iface = NULL;
static GType low_level_openmoko_type_id = 0;

GType low_level_openmoko_get_type (void) G_GNUC_CONST;
GType low_level_openmoko_register_type (GTypeModule * module);
#define LOW_LEVEL_OPENMOKO_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), LOW_LEVEL_TYPE_OPENMOKO, LowLevelOpenmokoPrivate))
enum  {
	LOW_LEVEL_OPENMOKO_DUMMY_PROPERTY
};
#define LOW_LEVEL_OPENMOKO_MODULE_NAME "fsogsm.lowlevel_openmoko"
#define LOW_LEVEL_OPENMOKO_POWERUP_RETRIES ((guint) 5)
static gchar* low_level_openmoko_real_repr (FsoFrameworkAbstractObject* base);
static gboolean low_level_openmoko_real_poweron (FsoGsmLowLevel* base);
static gboolean low_level_openmoko_real_poweroff (FsoGsmLowLevel* base);
static gboolean low_level_openmoko_real_suspend (FsoGsmLowLevel* base);
static gboolean low_level_openmoko_real_resume (FsoGsmLowLevel* base);
LowLevelOpenmoko* low_level_openmoko_new (void);
LowLevelOpenmoko* low_level_openmoko_construct (GType object_type);
static GObject * low_level_openmoko_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void low_level_openmoko_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static gchar* low_level_openmoko_real_repr (FsoFrameworkAbstractObject* base) {
	LowLevelOpenmoko * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (LowLevelOpenmoko*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static gboolean low_level_openmoko_real_poweron (FsoGsmLowLevel* base) {
	LowLevelOpenmoko * self;
	gboolean result = FALSE;
	const gchar* _tmp0_;
	const gchar* _tmp2_;
	FsoGsmAbstractModem* _tmp3_;
	FsoFrameworkTransportSpec* _tmp4_;
	FsoFrameworkTransportSpec* _tmp5_;
	FsoFrameworkTransport* _tmp6_ = NULL;
	FsoFrameworkTransport* transport;
	FsoFrameworkTransport* _tmp7_;
	FsoFrameworkTransport* _tmp8_;
	gboolean _tmp9_ = FALSE;
	gchar* _tmp10_ = NULL;
	gchar* buf;
	gint buf_length1;
	gint _buf_size_;
	FsoFrameworkTransport* _tmp11_;
	gchar* _tmp12_;
	gint _tmp12__length1;
	gint _tmp13_ = 0;
	gint bread;
	FsoFrameworkTransport* _tmp14_;
	gchar* _tmp15_;
	gint _tmp15__length1;
	gint _tmp16_ = 0;
	guint i;
	FsoFrameworkTransport* _tmp84_;
	self = (LowLevelOpenmoko*) base;
	_tmp0_ = self->priv->powerNode;
	if (g_strcmp0 (_tmp0_, "unknown") == 0) {
		FsoFrameworkLogger* _tmp1_;
		_tmp1_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_error (_tmp1_, "power_node not defined. Can't poweron.");
		result = FALSE;
		return result;
	}
	fso_gsm_low_level_poweroff ((FsoGsmLowLevel*) self);
	g_usleep ((gulong) (1000 * 1000));
	_tmp2_ = self->priv->powerNode;
	fso_framework_file_handling_write ("1\n", _tmp2_, FALSE);
	g_usleep ((gulong) (1000 * 1000));
	_tmp3_ = self->priv->modem;
	_tmp4_ = fso_gsm_abstract_modem_get_modem_transport_spec (_tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = fso_framework_transport_spec_create (_tmp5_);
	transport = _tmp6_;
	_tmp7_ = transport;
	fso_framework_transport_open (_tmp7_);
	_tmp8_ = transport;
	_tmp9_ = fso_framework_transport_isOpen (_tmp8_);
	g_assert (_tmp9_);
	_tmp10_ = g_new0 (gchar, 512);
	buf = _tmp10_;
	buf_length1 = 512;
	_buf_size_ = buf_length1;
	_tmp11_ = transport;
	_tmp12_ = buf;
	_tmp12__length1 = buf_length1;
	_tmp13_ = fso_framework_transport_writeAndRead (_tmp11_, "AT\r\n", 4, _tmp12_, 512, 0);
	bread = _tmp13_;
	_tmp14_ = transport;
	_tmp15_ = buf;
	_tmp15__length1 = buf_length1;
	_tmp16_ = fso_framework_transport_writeAndRead (_tmp14_, "AT\r\n", 4, _tmp15_, 512, 0);
	bread = _tmp16_;
	i = (guint) 0;
	while (TRUE) {
		guint _tmp17_;
		FsoFrameworkTransport* _tmp18_;
		FsoFrameworkTransport* _tmp19_;
		guint _tmp20_;
		gchar* _tmp21_ = NULL;
		gchar* _tmp22_;
		gchar* _tmp23_ = NULL;
		gchar* _tmp24_;
		FsoFrameworkTransport* _tmp25_;
		gchar* _tmp26_;
		gint _tmp26__length1;
		gint _tmp27_ = 0;
		gchar* _tmp28_;
		gint _tmp28__length1;
		gint _tmp29_;
		gchar _tmp30_;
		gchar* _tmp31_;
		gint _tmp31__length1;
		gchar* _tmp32_ = NULL;
		gchar* displayString;
		gboolean _tmp33_ = FALSE;
		gboolean _tmp34_ = FALSE;
		gboolean _tmp35_ = FALSE;
		gboolean _tmp36_ = FALSE;
		gint _tmp37_;
		gboolean _tmp41_;
		gboolean _tmp45_;
		gboolean _tmp49_;
		gboolean _tmp53_;
		_tmp17_ = i;
		i = _tmp17_ + 1;
		if (!(_tmp17_ < LOW_LEVEL_OPENMOKO_POWERUP_RETRIES)) {
			break;
		}
		_tmp18_ = transport;
		fso_framework_transport_drain (_tmp18_);
		_tmp19_ = transport;
		fso_framework_transport_flush (_tmp19_);
		_tmp20_ = i;
		_tmp21_ = g_strdup_printf ("%u", _tmp20_);
		_tmp22_ = _tmp21_;
		_tmp23_ = g_strconcat (" --- while loop ENTER; i = ", _tmp22_, NULL);
		_tmp24_ = _tmp23_;
		g_debug ("plugin.vala:81: %s", _tmp24_);
		_g_free0 (_tmp24_);
		_g_free0 (_tmp22_);
		_tmp25_ = transport;
		_tmp26_ = buf;
		_tmp26__length1 = buf_length1;
		_tmp27_ = fso_framework_transport_writeAndRead (_tmp25_, "ATE0Q0V1\r\n", 10, _tmp26_, 512, 5000);
		bread = _tmp27_;
		_tmp28_ = buf;
		_tmp28__length1 = buf_length1;
		_tmp29_ = bread;
		_tmp28_[_tmp29_] = '\0';
		_tmp30_ = _tmp28_[_tmp29_];
		_tmp31_ = buf;
		_tmp31__length1 = buf_length1;
		_tmp32_ = g_strescape ((const gchar*) _tmp31_, "");
		displayString = _tmp32_;
		_tmp37_ = bread;
		if (_tmp37_ > 3) {
			gchar* _tmp38_;
			gint _tmp38__length1;
			gint _tmp39_;
			gchar _tmp40_;
			_tmp38_ = buf;
			_tmp38__length1 = buf_length1;
			_tmp39_ = bread;
			_tmp40_ = _tmp38_[_tmp39_ - 1];
			_tmp36_ = _tmp40_ == '\n';
		} else {
			_tmp36_ = FALSE;
		}
		_tmp41_ = _tmp36_;
		if (_tmp41_) {
			gchar* _tmp42_;
			gint _tmp42__length1;
			gint _tmp43_;
			gchar _tmp44_;
			_tmp42_ = buf;
			_tmp42__length1 = buf_length1;
			_tmp43_ = bread;
			_tmp44_ = _tmp42_[_tmp43_ - 2];
			_tmp35_ = _tmp44_ == '\r';
		} else {
			_tmp35_ = FALSE;
		}
		_tmp45_ = _tmp35_;
		if (_tmp45_) {
			gchar* _tmp46_;
			gint _tmp46__length1;
			gint _tmp47_;
			gchar _tmp48_;
			_tmp46_ = buf;
			_tmp46__length1 = buf_length1;
			_tmp47_ = bread;
			_tmp48_ = _tmp46_[_tmp47_ - 3];
			_tmp34_ = _tmp48_ == 'K';
		} else {
			_tmp34_ = FALSE;
		}
		_tmp49_ = _tmp34_;
		if (_tmp49_) {
			gchar* _tmp50_;
			gint _tmp50__length1;
			gint _tmp51_;
			gchar _tmp52_;
			_tmp50_ = buf;
			_tmp50__length1 = buf_length1;
			_tmp51_ = bread;
			_tmp52_ = _tmp50_[_tmp51_ - 4];
			_tmp33_ = _tmp52_ == 'O';
		} else {
			_tmp33_ = FALSE;
		}
		_tmp53_ = _tmp33_;
		if (_tmp53_) {
			FsoFrameworkTransport* _tmp54_;
			gchar* _tmp55_;
			gint _tmp55__length1;
			gint _tmp56_ = 0;
			gchar* _tmp57_;
			gint _tmp57__length1;
			gint _tmp58_;
			gchar _tmp59_;
			gchar* _tmp60_;
			gint _tmp60__length1;
			gchar* _tmp61_ = NULL;
			gboolean _tmp62_ = FALSE;
			gboolean _tmp63_ = FALSE;
			gboolean _tmp64_ = FALSE;
			gboolean _tmp65_ = FALSE;
			gint _tmp66_;
			gboolean _tmp70_;
			gboolean _tmp74_;
			gboolean _tmp78_;
			gboolean _tmp82_;
			_tmp54_ = transport;
			_tmp55_ = buf;
			_tmp55__length1 = buf_length1;
			_tmp56_ = fso_framework_transport_writeAndRead (_tmp54_, "AT%SLEEP=2\r\n", 12, _tmp55_, 512, 5000);
			bread = _tmp56_;
			_tmp57_ = buf;
			_tmp57__length1 = buf_length1;
			_tmp58_ = bread;
			_tmp57_[_tmp58_] = '\0';
			_tmp59_ = _tmp57_[_tmp58_];
			_tmp60_ = buf;
			_tmp60__length1 = buf_length1;
			_tmp61_ = g_strescape ((const gchar*) _tmp60_, "");
			_g_free0 (displayString);
			displayString = _tmp61_;
			_tmp66_ = bread;
			if (_tmp66_ > 3) {
				gchar* _tmp67_;
				gint _tmp67__length1;
				gint _tmp68_;
				gchar _tmp69_;
				_tmp67_ = buf;
				_tmp67__length1 = buf_length1;
				_tmp68_ = bread;
				_tmp69_ = _tmp67_[_tmp68_ - 1];
				_tmp65_ = _tmp69_ == '\n';
			} else {
				_tmp65_ = FALSE;
			}
			_tmp70_ = _tmp65_;
			if (_tmp70_) {
				gchar* _tmp71_;
				gint _tmp71__length1;
				gint _tmp72_;
				gchar _tmp73_;
				_tmp71_ = buf;
				_tmp71__length1 = buf_length1;
				_tmp72_ = bread;
				_tmp73_ = _tmp71_[_tmp72_ - 2];
				_tmp64_ = _tmp73_ == '\r';
			} else {
				_tmp64_ = FALSE;
			}
			_tmp74_ = _tmp64_;
			if (_tmp74_) {
				gchar* _tmp75_;
				gint _tmp75__length1;
				gint _tmp76_;
				gchar _tmp77_;
				_tmp75_ = buf;
				_tmp75__length1 = buf_length1;
				_tmp76_ = bread;
				_tmp77_ = _tmp75_[_tmp76_ - 3];
				_tmp63_ = _tmp77_ == 'K';
			} else {
				_tmp63_ = FALSE;
			}
			_tmp78_ = _tmp63_;
			if (_tmp78_) {
				gchar* _tmp79_;
				gint _tmp79__length1;
				gint _tmp80_;
				gchar _tmp81_;
				_tmp79_ = buf;
				_tmp79__length1 = buf_length1;
				_tmp80_ = bread;
				_tmp81_ = _tmp79_[_tmp80_ - 4];
				_tmp62_ = _tmp81_ == 'O';
			} else {
				_tmp62_ = FALSE;
			}
			_tmp82_ = _tmp62_;
			if (_tmp82_) {
				FsoFrameworkTransport* _tmp83_;
				_tmp83_ = transport;
				fso_framework_transport_close (_tmp83_);
				result = TRUE;
				_g_free0 (displayString);
				buf = (g_free (buf), NULL);
				_g_object_unref0 (transport);
				return result;
			}
		}
		_g_free0 (displayString);
	}
	_tmp84_ = transport;
	fso_framework_transport_close (_tmp84_);
	result = FALSE;
	buf = (g_free (buf), NULL);
	_g_object_unref0 (transport);
	return result;
}


static gboolean low_level_openmoko_real_poweroff (FsoGsmLowLevel* base) {
	LowLevelOpenmoko * self;
	gboolean result = FALSE;
	const gchar* _tmp0_;
	self = (LowLevelOpenmoko*) base;
	_tmp0_ = self->priv->powerNode;
	fso_framework_file_handling_write ("0\n", _tmp0_, FALSE);
	result = TRUE;
	return result;
}


static gboolean low_level_openmoko_real_suspend (FsoGsmLowLevel* base) {
	LowLevelOpenmoko * self;
	gboolean result = FALSE;
	const gchar* _tmp0_;
	const gchar* _tmp2_;
	self = (LowLevelOpenmoko*) base;
	_tmp0_ = self->priv->fcNode;
	if (g_strcmp0 (_tmp0_, "unknown") == 0) {
		FsoFrameworkLogger* _tmp1_;
		_tmp1_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_error (_tmp1_, "fc_node not defined. Can't prepare for suspend.");
		result = FALSE;
		return result;
	}
	_tmp2_ = self->priv->fcNode;
	fso_framework_file_handling_write ("1", _tmp2_, FALSE);
	result = TRUE;
	return result;
}


static gboolean low_level_openmoko_real_resume (FsoGsmLowLevel* base) {
	LowLevelOpenmoko * self;
	gboolean result = FALSE;
	const gchar* _tmp0_;
	const gchar* _tmp2_;
	self = (LowLevelOpenmoko*) base;
	_tmp0_ = self->priv->fcNode;
	if (g_strcmp0 (_tmp0_, "unknown") == 0) {
		FsoFrameworkLogger* _tmp1_;
		_tmp1_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_error (_tmp1_, "fc_node not defined. Can't recover from suspend.");
		result = FALSE;
		return result;
	}
	_tmp2_ = self->priv->fcNode;
	fso_framework_file_handling_write ("0", _tmp2_, FALSE);
	result = TRUE;
	return result;
}


LowLevelOpenmoko* low_level_openmoko_construct (GType object_type) {
	LowLevelOpenmoko * self = NULL;
	self = (LowLevelOpenmoko*) fso_framework_abstract_object_construct (object_type);
	return self;
}


LowLevelOpenmoko* low_level_openmoko_new (void) {
	return low_level_openmoko_construct (LOW_LEVEL_TYPE_OPENMOKO);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static GObject * low_level_openmoko_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	LowLevelOpenmoko * self;
	FsoFrameworkSmartKeyFile* _tmp0_;
	gchar* _tmp1_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp2_;
	gchar* _tmp3_ = NULL;
	FsoGsmModem* _tmp4_;
	FsoGsmAbstractModem* _tmp5_;
	FsoFrameworkLogger* _tmp6_;
	parent_class = G_OBJECT_CLASS (low_level_openmoko_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = LOW_LEVEL_OPENMOKO (obj);
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->config;
	_tmp1_ = fso_framework_smart_key_file_stringValue (_tmp0_, LOW_LEVEL_OPENMOKO_MODULE_NAME, "power_node", "unknown");
	_g_free0 (self->priv->powerNode);
	self->priv->powerNode = _tmp1_;
	_tmp2_ = ((FsoFrameworkAbstractObject*) self)->config;
	_tmp3_ = fso_framework_smart_key_file_stringValue (_tmp2_, LOW_LEVEL_OPENMOKO_MODULE_NAME, "fc_node", "unknown");
	_g_free0 (self->priv->fcNode);
	self->priv->fcNode = _tmp3_;
	_tmp4_ = fso_gsm_theModem;
	_tmp5_ = _g_object_ref0 (FSO_GSM_IS_ABSTRACT_MODEM (_tmp4_) ? ((FsoGsmAbstractModem*) _tmp4_) : NULL);
	_g_object_unref0 (self->priv->modem);
	self->priv->modem = _tmp5_;
	_tmp6_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp6_, "Registering openmoko low level poweron/poweroff handling");
	return obj;
}


static void low_level_openmoko_class_init (LowLevelOpenmokoClass * klass) {
	low_level_openmoko_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (LowLevelOpenmokoPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = low_level_openmoko_real_repr;
	G_OBJECT_CLASS (klass)->constructor = low_level_openmoko_constructor;
	G_OBJECT_CLASS (klass)->finalize = low_level_openmoko_finalize;
}


static void low_level_openmoko_fso_gsm_low_level_interface_init (FsoGsmLowLevelIface * iface) {
	low_level_openmoko_fso_gsm_low_level_parent_iface = g_type_interface_peek_parent (iface);
	iface->poweron = (gboolean (*)(FsoGsmLowLevel*)) low_level_openmoko_real_poweron;
	iface->poweroff = (gboolean (*)(FsoGsmLowLevel*)) low_level_openmoko_real_poweroff;
	iface->suspend = (gboolean (*)(FsoGsmLowLevel*)) low_level_openmoko_real_suspend;
	iface->resume = (gboolean (*)(FsoGsmLowLevel*)) low_level_openmoko_real_resume;
}


static void low_level_openmoko_instance_init (LowLevelOpenmoko * self) {
	self->priv = LOW_LEVEL_OPENMOKO_GET_PRIVATE (self);
}


static void low_level_openmoko_finalize (GObject* obj) {
	LowLevelOpenmoko * self;
	self = LOW_LEVEL_OPENMOKO (obj);
	_g_free0 (self->priv->powerNode);
	_g_free0 (self->priv->fcNode);
	_g_object_unref0 (self->priv->modem);
	G_OBJECT_CLASS (low_level_openmoko_parent_class)->finalize (obj);
}


GType low_level_openmoko_get_type (void) {
	return low_level_openmoko_type_id;
}


GType low_level_openmoko_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (LowLevelOpenmokoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) low_level_openmoko_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LowLevelOpenmoko), 0, (GInstanceInitFunc) low_level_openmoko_instance_init, NULL };
	static const GInterfaceInfo fso_gsm_low_level_info = { (GInterfaceInitFunc) low_level_openmoko_fso_gsm_low_level_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	low_level_openmoko_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "LowLevelOpenmoko", &g_define_type_info, 0);
	g_type_module_add_interface (module, low_level_openmoko_type_id, FSO_GSM_TYPE_LOW_LEVEL, &fso_gsm_low_level_info);
	return low_level_openmoko_type_id;
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
	fso_framework_logger_debug (_tmp0_, "lowlevel_openmoko fso_factory_function");
	_tmp1_ = g_strdup (LOW_LEVEL_OPENMOKO_MODULE_NAME);
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	low_level_openmoko_register_type (module);
}




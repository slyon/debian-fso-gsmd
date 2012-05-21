/* plugin.c generated by valac 0.14.2, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2009-2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *                         Simon Busch <morphis@gravedo.de>
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
#include <unistd.h>
#include <fsoframework.h>


#define LOW_LEVEL_TYPE_PALM_PRE (low_level_palm_pre_get_type ())
#define LOW_LEVEL_PALM_PRE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LOW_LEVEL_TYPE_PALM_PRE, LowLevelPalmPre))
#define LOW_LEVEL_PALM_PRE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LOW_LEVEL_TYPE_PALM_PRE, LowLevelPalmPreClass))
#define LOW_LEVEL_IS_PALM_PRE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LOW_LEVEL_TYPE_PALM_PRE))
#define LOW_LEVEL_IS_PALM_PRE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LOW_LEVEL_TYPE_PALM_PRE))
#define LOW_LEVEL_PALM_PRE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LOW_LEVEL_TYPE_PALM_PRE, LowLevelPalmPreClass))

typedef struct _LowLevelPalmPre LowLevelPalmPre;
typedef struct _LowLevelPalmPreClass LowLevelPalmPreClass;
typedef struct _LowLevelPalmPrePrivate LowLevelPalmPrePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _LowLevelPalmPre {
	FsoFrameworkAbstractObject parent_instance;
	LowLevelPalmPrePrivate * priv;
};

struct _LowLevelPalmPreClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _LowLevelPalmPrePrivate {
	FsoGsmAbstractModem* modem;
	gchar* powernode;
	gchar* bootnode;
	gchar* wakeupnode;
	gboolean powered_on;
};


static gpointer low_level_palm_pre_parent_class = NULL;
static FsoGsmLowLevelIface* low_level_palm_pre_fso_gsm_low_level_parent_iface = NULL;
static GType low_level_palm_pre_type_id = 0;

GType low_level_palm_pre_get_type (void) G_GNUC_CONST;
GType low_level_palm_pre_register_type (GTypeModule * module);
#define LOW_LEVEL_PALM_PRE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), LOW_LEVEL_TYPE_PALM_PRE, LowLevelPalmPrePrivate))
enum  {
	LOW_LEVEL_PALM_PRE_DUMMY_PROPERTY
};
#define LOW_LEVEL_PALM_PRE_MODULE_NAME "fsogsm.lowlevel_palmpre"
#define LOW_LEVEL_PALM_PRE_DEFAULT_POWER_NODE "/sys/user_hw/pins/modem/power_on/level"
#define LOW_LEVEL_PALM_PRE_DEFAULT_BOOT_NODE "/sys/user_hw/pins/modem/boot_mode/level"
#define LOW_LEVEL_PALM_PRE_DEFAULT_WAKEUP_NODE "/sys/user_hw/pins/modem/wakeup_modem/level"
static gchar* low_level_palm_pre_real_repr (FsoFrameworkAbstractObject* base);
static gboolean low_level_palm_pre_real_poweron (FsoGsmLowLevel* base);
static gboolean low_level_palm_pre_real_poweroff (FsoGsmLowLevel* base);
static gboolean low_level_palm_pre_real_suspend (FsoGsmLowLevel* base);
static gboolean low_level_palm_pre_real_resume (FsoGsmLowLevel* base);
LowLevelPalmPre* low_level_palm_pre_new (void);
LowLevelPalmPre* low_level_palm_pre_construct (GType object_type);
static GObject * low_level_palm_pre_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void low_level_palm_pre_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static gchar* low_level_palm_pre_real_repr (FsoFrameworkAbstractObject* base) {
	LowLevelPalmPre * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (LowLevelPalmPre*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static gboolean low_level_palm_pre_real_poweron (FsoGsmLowLevel* base) {
	LowLevelPalmPre * self;
	gboolean result = FALSE;
	gboolean _tmp0_;
	self = (LowLevelPalmPre*) base;
	g_debug ("plugin.vala:58: lowlevel_palmpre_poweron()");
	_tmp0_ = self->priv->powered_on;
	if (_tmp0_) {
		const gchar* _tmp1_;
		const gchar* _tmp2_;
		const gchar* _tmp3_;
		const gchar* _tmp4_;
		const gchar* _tmp5_;
		_tmp1_ = self->priv->bootnode;
		fso_framework_file_handling_write ("0", _tmp1_, FALSE);
		_tmp2_ = self->priv->wakeupnode;
		fso_framework_file_handling_write ("0", _tmp2_, FALSE);
		_tmp3_ = self->priv->powernode;
		fso_framework_file_handling_write ("0", _tmp3_, FALSE);
		sleep ((guint) 2);
		_tmp4_ = self->priv->powernode;
		fso_framework_file_handling_write ("1", _tmp4_, FALSE);
		_tmp5_ = self->priv->wakeupnode;
		fso_framework_file_handling_write ("1", _tmp5_, FALSE);
	} else {
		const gchar* _tmp6_;
		_tmp6_ = self->priv->powernode;
		fso_framework_file_handling_write ("1", _tmp6_, FALSE);
	}
	self->priv->powered_on = TRUE;
	result = TRUE;
	return result;
}


static gboolean low_level_palm_pre_real_poweroff (FsoGsmLowLevel* base) {
	LowLevelPalmPre * self;
	gboolean result = FALSE;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	self = (LowLevelPalmPre*) base;
	g_debug ("plugin.vala:85: lowlevel_palmpre_poweroff()");
	_tmp0_ = self->priv->bootnode;
	fso_framework_file_handling_write ("0", _tmp0_, FALSE);
	_tmp1_ = self->priv->powernode;
	fso_framework_file_handling_write ("0", _tmp1_, FALSE);
	self->priv->powered_on = FALSE;
	result = TRUE;
	return result;
}


static gboolean low_level_palm_pre_real_suspend (FsoGsmLowLevel* base) {
	LowLevelPalmPre * self;
	gboolean result = FALSE;
	self = (LowLevelPalmPre*) base;
	g_debug ("plugin.vala:97: lowlevel_palmpre_suspend()");
	result = TRUE;
	return result;
}


static gboolean low_level_palm_pre_real_resume (FsoGsmLowLevel* base) {
	LowLevelPalmPre * self;
	gboolean result = FALSE;
	self = (LowLevelPalmPre*) base;
	g_debug ("plugin.vala:103: lowlevel_palmpre_resume()");
	result = TRUE;
	return result;
}


LowLevelPalmPre* low_level_palm_pre_construct (GType object_type) {
	LowLevelPalmPre * self = NULL;
	self = (LowLevelPalmPre*) fso_framework_abstract_object_construct (object_type);
	return self;
}


LowLevelPalmPre* low_level_palm_pre_new (void) {
	return low_level_palm_pre_construct (LOW_LEVEL_TYPE_PALM_PRE);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static GObject * low_level_palm_pre_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	LowLevelPalmPre * self;
	FsoGsmModem* _tmp0_;
	FsoGsmAbstractModem* _tmp1_;
	FsoFrameworkSmartKeyFile* _tmp2_;
	gchar* _tmp3_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp4_;
	gchar* _tmp5_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp6_;
	gchar* _tmp7_ = NULL;
	FsoFrameworkLogger* _tmp8_;
	parent_class = G_OBJECT_CLASS (low_level_palm_pre_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = LOW_LEVEL_PALM_PRE (obj);
	_tmp0_ = fso_gsm_theModem;
	_tmp1_ = _g_object_ref0 (FSO_GSM_IS_ABSTRACT_MODEM (_tmp0_) ? ((FsoGsmAbstractModem*) _tmp0_) : NULL);
	_g_object_unref0 (self->priv->modem);
	self->priv->modem = _tmp1_;
	_tmp2_ = ((FsoFrameworkAbstractObject*) self)->config;
	_tmp3_ = fso_framework_smart_key_file_stringValue (_tmp2_, LOW_LEVEL_PALM_PRE_MODULE_NAME, "power_node", LOW_LEVEL_PALM_PRE_DEFAULT_POWER_NODE);
	_g_free0 (self->priv->powernode);
	self->priv->powernode = _tmp3_;
	_tmp4_ = ((FsoFrameworkAbstractObject*) self)->config;
	_tmp5_ = fso_framework_smart_key_file_stringValue (_tmp4_, LOW_LEVEL_PALM_PRE_MODULE_NAME, "boot_node", LOW_LEVEL_PALM_PRE_DEFAULT_BOOT_NODE);
	_g_free0 (self->priv->bootnode);
	self->priv->bootnode = _tmp5_;
	_tmp6_ = ((FsoFrameworkAbstractObject*) self)->config;
	_tmp7_ = fso_framework_smart_key_file_stringValue (_tmp6_, LOW_LEVEL_PALM_PRE_MODULE_NAME, "wakeup_node", LOW_LEVEL_PALM_PRE_DEFAULT_WAKEUP_NODE);
	_g_free0 (self->priv->wakeupnode);
	self->priv->wakeupnode = _tmp7_;
	self->priv->powered_on = FALSE;
	_tmp8_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp8_, "Registering Palm Pre low level poweron/poweroff handling");
	return obj;
}


static void low_level_palm_pre_class_init (LowLevelPalmPreClass * klass) {
	low_level_palm_pre_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (LowLevelPalmPrePrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = low_level_palm_pre_real_repr;
	G_OBJECT_CLASS (klass)->constructor = low_level_palm_pre_constructor;
	G_OBJECT_CLASS (klass)->finalize = low_level_palm_pre_finalize;
}


static void low_level_palm_pre_fso_gsm_low_level_interface_init (FsoGsmLowLevelIface * iface) {
	low_level_palm_pre_fso_gsm_low_level_parent_iface = g_type_interface_peek_parent (iface);
	iface->poweron = (gboolean (*)(FsoGsmLowLevel*)) low_level_palm_pre_real_poweron;
	iface->poweroff = (gboolean (*)(FsoGsmLowLevel*)) low_level_palm_pre_real_poweroff;
	iface->suspend = (gboolean (*)(FsoGsmLowLevel*)) low_level_palm_pre_real_suspend;
	iface->resume = (gboolean (*)(FsoGsmLowLevel*)) low_level_palm_pre_real_resume;
}


static void low_level_palm_pre_instance_init (LowLevelPalmPre * self) {
	self->priv = LOW_LEVEL_PALM_PRE_GET_PRIVATE (self);
}


static void low_level_palm_pre_finalize (GObject* obj) {
	LowLevelPalmPre * self;
	self = LOW_LEVEL_PALM_PRE (obj);
	_g_object_unref0 (self->priv->modem);
	_g_free0 (self->priv->powernode);
	_g_free0 (self->priv->bootnode);
	_g_free0 (self->priv->wakeupnode);
	G_OBJECT_CLASS (low_level_palm_pre_parent_class)->finalize (obj);
}


GType low_level_palm_pre_get_type (void) {
	return low_level_palm_pre_type_id;
}


GType low_level_palm_pre_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (LowLevelPalmPreClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) low_level_palm_pre_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LowLevelPalmPre), 0, (GInstanceInitFunc) low_level_palm_pre_instance_init, NULL };
	static const GInterfaceInfo fso_gsm_low_level_info = { (GInterfaceInitFunc) low_level_palm_pre_fso_gsm_low_level_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	low_level_palm_pre_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "LowLevelPalmPre", &g_define_type_info, 0);
	g_type_module_add_interface (module, low_level_palm_pre_type_id, FSO_GSM_TYPE_LOW_LEVEL, &fso_gsm_low_level_info);
	return low_level_palm_pre_type_id;
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
	fso_framework_logger_debug (_tmp0_, "lowlevel_palmpre fso_factory_function");
	_tmp1_ = g_strdup (LOW_LEVEL_PALM_PRE_MODULE_NAME);
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	low_level_palm_pre_register_type (module);
}




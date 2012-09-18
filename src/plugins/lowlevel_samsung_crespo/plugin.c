/* plugin.c generated by valac 0.16.0, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Simon Busch <morphis@gravedo.de>
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
#include <radio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fsoframework.h>


#define LOW_LEVEL_TYPE_SAMSUNG_CRESPO (low_level_samsung_crespo_get_type ())
#define LOW_LEVEL_SAMSUNG_CRESPO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LOW_LEVEL_TYPE_SAMSUNG_CRESPO, LowLevelSamsungCrespo))
#define LOW_LEVEL_SAMSUNG_CRESPO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LOW_LEVEL_TYPE_SAMSUNG_CRESPO, LowLevelSamsungCrespoClass))
#define LOW_LEVEL_IS_SAMSUNG_CRESPO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LOW_LEVEL_TYPE_SAMSUNG_CRESPO))
#define LOW_LEVEL_IS_SAMSUNG_CRESPO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LOW_LEVEL_TYPE_SAMSUNG_CRESPO))
#define LOW_LEVEL_SAMSUNG_CRESPO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LOW_LEVEL_TYPE_SAMSUNG_CRESPO, LowLevelSamsungCrespoClass))

typedef struct _LowLevelSamsungCrespo LowLevelSamsungCrespo;
typedef struct _LowLevelSamsungCrespoClass LowLevelSamsungCrespoClass;
typedef struct _LowLevelSamsungCrespoPrivate LowLevelSamsungCrespoPrivate;
#define _ipc_client_free0(var) ((var == NULL) ? NULL : (var = (ipc_client_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _LowLevelSamsungCrespo {
	FsoFrameworkAbstractObject parent_instance;
	LowLevelSamsungCrespoPrivate * priv;
};

struct _LowLevelSamsungCrespoClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _LowLevelSamsungCrespoPrivate {
	struct ipc_client* client;
	gboolean powered;
	gchar* power_mode_node;
};


static gpointer low_level_samsung_crespo_parent_class = NULL;
static FsoGsmLowLevelIface* low_level_samsung_crespo_fso_gsm_low_level_parent_iface = NULL;
static GType low_level_samsung_crespo_type_id = 0;

GType low_level_samsung_crespo_get_type (void) G_GNUC_CONST;
GType low_level_samsung_crespo_register_type (GTypeModule * module);
#define LOW_LEVEL_SAMSUNG_CRESPO_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), LOW_LEVEL_TYPE_SAMSUNG_CRESPO, LowLevelSamsungCrespoPrivate))
enum  {
	LOW_LEVEL_SAMSUNG_CRESPO_DUMMY_PROPERTY
};
#define LOW_LEVEL_SAMSUNG_CRESPO_MODULE_NAME "fsogsm.lowlevel_samsung_crespo"
static gchar* low_level_samsung_crespo_real_repr (FsoFrameworkAbstractObject* base);
static gboolean low_level_samsung_crespo_real_poweron (FsoGsmLowLevel* base);
static gboolean low_level_samsung_crespo_real_poweroff (FsoGsmLowLevel* base);
static gboolean low_level_samsung_crespo_real_suspend (FsoGsmLowLevel* base);
static gboolean low_level_samsung_crespo_real_resume (FsoGsmLowLevel* base);
LowLevelSamsungCrespo* low_level_samsung_crespo_new (void);
LowLevelSamsungCrespo* low_level_samsung_crespo_construct (GType object_type);
static GObject * low_level_samsung_crespo_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void _low_level_samsung_crespo___lambda2_ (LowLevelSamsungCrespo* self, const gchar* message);
static void __low_level_samsung_crespo___lambda2__samsung_ipc_log_handler_cb (const gchar* message, gpointer self);
static void low_level_samsung_crespo_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


static gchar* low_level_samsung_crespo_real_repr (FsoFrameworkAbstractObject* base) {
	LowLevelSamsungCrespo * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (LowLevelSamsungCrespo*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static gboolean low_level_samsung_crespo_real_poweron (FsoGsmLowLevel* base) {
	LowLevelSamsungCrespo * self;
	gboolean result = FALSE;
	FsoFrameworkLogger* _tmp0_;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	struct ipc_client* _tmp3_;
	gint _tmp4_ = 0;
	const gchar* _tmp6_;
	self = (LowLevelSamsungCrespo*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = fso_framework_logger_debug (_tmp0_, "lowlevel_samsung_crespo_poweron()");
	g_assert (_tmp1_);
	_tmp2_ = self->priv->powered;
	if (_tmp2_) {
		result = FALSE;
		return result;
	}
	_tmp3_ = self->priv->client;
	_tmp4_ = ipc_client_bootstrap_modem (_tmp3_);
	if (_tmp4_ != 0) {
		FsoFrameworkLogger* _tmp5_;
		_tmp5_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_error (_tmp5_, "Modem bootstraping went wrong; cannot power the modem!");
		result = FALSE;
		return result;
	}
	_tmp6_ = self->priv->power_mode_node;
	fso_framework_file_handling_write ("1", _tmp6_, FALSE);
	sleep ((guint) 1);
	result = TRUE;
	return result;
}


static gboolean low_level_samsung_crespo_real_poweroff (FsoGsmLowLevel* base) {
	LowLevelSamsungCrespo * self;
	gboolean result = FALSE;
	FsoFrameworkLogger* _tmp0_;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	const gchar* _tmp3_;
	self = (LowLevelSamsungCrespo*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = fso_framework_logger_debug (_tmp0_, "lowlevel_samsung_crespo_poweroff()");
	g_assert (_tmp1_);
	_tmp2_ = self->priv->powered;
	if (!_tmp2_) {
		result = FALSE;
		return result;
	}
	_tmp3_ = self->priv->power_mode_node;
	fso_framework_file_handling_write ("0", _tmp3_, FALSE);
	result = TRUE;
	return result;
}


static gboolean low_level_samsung_crespo_real_suspend (FsoGsmLowLevel* base) {
	LowLevelSamsungCrespo * self;
	gboolean result = FALSE;
	FsoFrameworkLogger* _tmp0_;
	gboolean _tmp1_ = FALSE;
	self = (LowLevelSamsungCrespo*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = fso_framework_logger_debug (_tmp0_, "lowlevel_samsung_crespo_suspend()");
	g_assert (_tmp1_);
	result = TRUE;
	return result;
}


static gboolean low_level_samsung_crespo_real_resume (FsoGsmLowLevel* base) {
	LowLevelSamsungCrespo * self;
	gboolean result = FALSE;
	FsoFrameworkLogger* _tmp0_;
	gboolean _tmp1_ = FALSE;
	self = (LowLevelSamsungCrespo*) base;
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = fso_framework_logger_debug (_tmp0_, "lowlevel_samsung_crespo_resume()");
	g_assert (_tmp1_);
	result = TRUE;
	return result;
}


LowLevelSamsungCrespo* low_level_samsung_crespo_construct (GType object_type) {
	LowLevelSamsungCrespo * self = NULL;
	self = (LowLevelSamsungCrespo*) fso_framework_abstract_object_construct (object_type);
	return self;
}


LowLevelSamsungCrespo* low_level_samsung_crespo_new (void) {
	return low_level_samsung_crespo_construct (LOW_LEVEL_TYPE_SAMSUNG_CRESPO);
}


static void _low_level_samsung_crespo___lambda2_ (LowLevelSamsungCrespo* self, const gchar* message) {
	FsoFrameworkLogger* _tmp0_;
	const gchar* _tmp1_;
	g_return_if_fail (message != NULL);
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = message;
	fso_framework_logger_debug (_tmp0_, _tmp1_);
}


static void __low_level_samsung_crespo___lambda2__samsung_ipc_log_handler_cb (const gchar* message, gpointer self) {
	_low_level_samsung_crespo___lambda2_ (self, message);
}


static GObject * low_level_samsung_crespo_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	LowLevelSamsungCrespo * self;
	struct ipc_client* _tmp0_;
	struct ipc_client* _tmp1_;
	FsoFrameworkSmartKeyFile* _tmp2_;
	gchar* _tmp3_ = NULL;
	FsoFrameworkLogger* _tmp4_;
	parent_class = G_OBJECT_CLASS (low_level_samsung_crespo_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = LOW_LEVEL_SAMSUNG_CRESPO (obj);
	_tmp0_ = ipc_client_new (IPC_CLIENT_TYPE_FMT);
	_ipc_client_free0 (self->priv->client);
	self->priv->client = _tmp0_;
	_tmp1_ = self->priv->client;
	ipc_client_set_log_handler (_tmp1_, __low_level_samsung_crespo___lambda2__samsung_ipc_log_handler_cb, self);
	_tmp2_ = ((FsoFrameworkAbstractObject*) self)->config;
	_tmp3_ = fso_framework_smart_key_file_stringValue (_tmp2_, LOW_LEVEL_SAMSUNG_CRESPO_MODULE_NAME, "power_mode_node", "/sys/devices/platform/modemctl/power_mode");
	_g_free0 (self->priv->power_mode_node);
	self->priv->power_mode_node = _tmp3_;
	_tmp4_ = ((FsoFrameworkAbstractObject*) self)->logger;
	fso_framework_logger_info (_tmp4_, "Registering Samsung Crespo low level poweron/poweroff handling");
	return obj;
}


static void low_level_samsung_crespo_class_init (LowLevelSamsungCrespoClass * klass) {
	low_level_samsung_crespo_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (LowLevelSamsungCrespoPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = low_level_samsung_crespo_real_repr;
	G_OBJECT_CLASS (klass)->constructor = low_level_samsung_crespo_constructor;
	G_OBJECT_CLASS (klass)->finalize = low_level_samsung_crespo_finalize;
}


static void low_level_samsung_crespo_fso_gsm_low_level_interface_init (FsoGsmLowLevelIface * iface) {
	low_level_samsung_crespo_fso_gsm_low_level_parent_iface = g_type_interface_peek_parent (iface);
	iface->poweron = (gboolean (*)(FsoGsmLowLevel*)) low_level_samsung_crespo_real_poweron;
	iface->poweroff = (gboolean (*)(FsoGsmLowLevel*)) low_level_samsung_crespo_real_poweroff;
	iface->suspend = (gboolean (*)(FsoGsmLowLevel*)) low_level_samsung_crespo_real_suspend;
	iface->resume = (gboolean (*)(FsoGsmLowLevel*)) low_level_samsung_crespo_real_resume;
}


static void low_level_samsung_crespo_instance_init (LowLevelSamsungCrespo * self) {
	self->priv = LOW_LEVEL_SAMSUNG_CRESPO_GET_PRIVATE (self);
	self->priv->powered = FALSE;
}


static void low_level_samsung_crespo_finalize (GObject* obj) {
	LowLevelSamsungCrespo * self;
	self = LOW_LEVEL_SAMSUNG_CRESPO (obj);
	_ipc_client_free0 (self->priv->client);
	_g_free0 (self->priv->power_mode_node);
	G_OBJECT_CLASS (low_level_samsung_crespo_parent_class)->finalize (obj);
}


GType low_level_samsung_crespo_get_type (void) {
	return low_level_samsung_crespo_type_id;
}


GType low_level_samsung_crespo_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (LowLevelSamsungCrespoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) low_level_samsung_crespo_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LowLevelSamsungCrespo), 0, (GInstanceInitFunc) low_level_samsung_crespo_instance_init, NULL };
	static const GInterfaceInfo fso_gsm_low_level_info = { (GInterfaceInitFunc) low_level_samsung_crespo_fso_gsm_low_level_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	low_level_samsung_crespo_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "LowLevelSamsungCrespo", &g_define_type_info, 0);
	g_type_module_add_interface (module, low_level_samsung_crespo_type_id, FSO_GSM_TYPE_LOW_LEVEL, &fso_gsm_low_level_info);
	return low_level_samsung_crespo_type_id;
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
	fso_framework_logger_debug (_tmp0_, "lowlevel_samsung_crespo fso_factory_function");
	_tmp1_ = g_strdup (LOW_LEVEL_SAMSUNG_CRESPO_MODULE_NAME);
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	low_level_samsung_crespo_register_type (module);
}




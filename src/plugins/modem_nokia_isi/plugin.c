/* plugin.c generated by valac 0.14.2, the Vala compiler
 * generated from plugin.vala, do not modify */

/*
 * Copyright (C) 2009-2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 * Copyright (C) 2010 Denis 'GNUtoo' Carikli <GNUtoo@no-log.org>
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
#include <fsogsm.h>
#include <gisicomm.h>
#include <fsotransport.h>
#include <fsobasics.h>
#include <unistd.h>
#include <gee.h>
#include <mtc.h>
#include <libgisi.h>
#include <clients.h>
#include <modem.h>
#include <fsoframework.h>


#define NOKIA_ISI_TYPE_MODEM (nokia_isi_modem_get_type ())
#define NOKIA_ISI_MODEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOKIA_ISI_TYPE_MODEM, NokiaIsiModem))
#define NOKIA_ISI_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOKIA_ISI_TYPE_MODEM, NokiaIsiModemClass))
#define NOKIA_ISI_IS_MODEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOKIA_ISI_TYPE_MODEM))
#define NOKIA_ISI_IS_MODEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOKIA_ISI_TYPE_MODEM))
#define NOKIA_ISI_MODEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOKIA_ISI_TYPE_MODEM, NokiaIsiModemClass))

typedef struct _NokiaIsiModem NokiaIsiModem;
typedef struct _NokiaIsiModemClass NokiaIsiModemClass;
typedef struct _NokiaIsiModemPrivate NokiaIsiModemPrivate;

#define NOKIA_ISI_MODEM_TYPE_RAPU_TYPE (nokia_isi_modem_rapu_type_get_type ())
#define _g_free0(var) (var = (g_free (var), NULL))

#define FSO_GSM_TYPE_ISI_CALL_HANDLER (fso_gsm_isi_call_handler_get_type ())
#define FSO_GSM_ISI_CALL_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_ISI_CALL_HANDLER, FsoGsmIsiCallHandler))
#define FSO_GSM_ISI_CALL_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_GSM_TYPE_ISI_CALL_HANDLER, FsoGsmIsiCallHandlerClass))
#define FSO_GSM_IS_ISI_CALL_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_ISI_CALL_HANDLER))
#define FSO_GSM_IS_ISI_CALL_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_GSM_TYPE_ISI_CALL_HANDLER))
#define FSO_GSM_ISI_CALL_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_GSM_TYPE_ISI_CALL_HANDLER, FsoGsmIsiCallHandlerClass))

typedef struct _FsoGsmIsiCallHandler FsoGsmIsiCallHandler;
typedef struct _FsoGsmIsiCallHandlerClass FsoGsmIsiCallHandlerClass;

#define TYPE_ISI_TRANSPORT (isi_transport_get_type ())
#define ISI_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ISI_TRANSPORT, IsiTransport))
#define ISI_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ISI_TRANSPORT, IsiTransportClass))
#define IS_ISI_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ISI_TRANSPORT))
#define IS_ISI_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ISI_TRANSPORT))
#define ISI_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ISI_TRANSPORT, IsiTransportClass))

typedef struct _IsiTransport IsiTransport;
typedef struct _IsiTransportClass IsiTransportClass;

#define TYPE_ISI_CHANNEL (isi_channel_get_type ())
#define ISI_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ISI_CHANNEL, IsiChannel))
#define ISI_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ISI_CHANNEL, IsiChannelClass))
#define IS_ISI_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ISI_CHANNEL))
#define IS_ISI_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ISI_CHANNEL))
#define ISI_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ISI_CHANNEL, IsiChannelClass))

typedef struct _IsiChannel IsiChannel;
typedef struct _IsiChannelClass IsiChannelClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _gisi_comm_modem_access_unref0(var) ((var == NULL) ? NULL : (var = (gisi_comm_modem_access_unref (var), NULL)))

struct _NokiaIsiModem {
	FsoGsmAbstractModem parent_instance;
	NokiaIsiModemPrivate * priv;
};

struct _NokiaIsiModemClass {
	FsoGsmAbstractModemClass parent_class;
};

typedef enum  {
	NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_1,
	NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_2
} NokiaIsiModemRapuType;

struct _NokiaIsiModemPrivate {
	NokiaIsiModemRapuType rapu_type;
	gboolean have_gpio_switch;
	gboolean have_gpio[5];
	gboolean startup_sequence;
	gboolean handle_modem_power;
};


extern NokiaIsiModem* nokia_isi_modem;
NokiaIsiModem* nokia_isi_modem = NULL;
extern GIsiCommModemAccess* nokia_isi_isimodem;
GIsiCommModemAccess* nokia_isi_isimodem = NULL;
static gpointer nokia_isi_modem_parent_class = NULL;
static GType nokia_isi_modem_type_id = 0;

#define NOKIA_ISI_MODULE_NAME "fsogsm.modem_nokia_isi"
GType nokia_isi_modem_get_type (void) G_GNUC_CONST;
GType nokia_isi_modem_register_type (GTypeModule * module);
GType nokia_isi_modem_rapu_type_get_type (void) G_GNUC_CONST;
#define NOKIA_ISI_MODEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), NOKIA_ISI_TYPE_MODEM, NokiaIsiModemPrivate))
enum  {
	NOKIA_ISI_MODEM_DUMMY_PROPERTY
};
#define NOKIA_ISI_MODEM_ISI_CHANNEL_NAME "main"
#define NOKIA_ISI_MODEM_GPIO_SWITCH "/sys/devices/platform/gpio-switch"
#define NOKIA_ISI_MODEM_DEV_CMT "/dev/cmt"
#define NOKIA_ISI_MODEM_GPIO_DIR "/sys/class/gpio"
#define NOKIA_ISI_MODEM_cmt_en 0
#define NOKIA_ISI_MODEM_cmt_rst_rq 1
#define NOKIA_ISI_MODEM_cmt_rst 2
#define NOKIA_ISI_MODEM_cmt_bsi 3
#define NOKIA_ISI_MODEM_cmt_apeslpx 4
static gchar* nokia_isi_modem_real_repr (FsoFrameworkAbstractObject* base);
static gboolean nokia_isi_modem_real_powerOn (FsoGsmAbstractModem* base);
void _nokia_isi_modem_power_off (NokiaIsiModem* self);
static void nokia_isi_modem_gpio_write (NokiaIsiModem* self, gint line, gboolean value);
const gchar* nokia_isi_modem_rapu_type_to_string (NokiaIsiModemRapuType self);
static void nokia_isi_modem_real_powerOff (FsoGsmAbstractModem* base);
static FsoGsmUnsolicitedResponseHandler* nokia_isi_modem_real_createUnsolicitedHandler (FsoGsmAbstractModem* base);
static FsoGsmCallHandler* nokia_isi_modem_real_createCallHandler (FsoGsmAbstractModem* base);
FsoGsmIsiCallHandler* fso_gsm_isi_call_handler_new (void);
FsoGsmIsiCallHandler* fso_gsm_isi_call_handler_construct (GType object_type);
GType fso_gsm_isi_call_handler_get_type (void) G_GNUC_CONST;
GType fso_gsm_isi_call_handler_register_type (GTypeModule * module);
static FsoGsmSmsHandler* nokia_isi_modem_real_createSmsHandler (FsoGsmAbstractModem* base);
static FsoGsmPhonebookHandler* nokia_isi_modem_real_createPhonebookHandler (FsoGsmAbstractModem* base);
static void nokia_isi_modem_real_createChannels (FsoGsmAbstractModem* base);
IsiTransport* isi_transport_new (const gchar* iface);
IsiTransport* isi_transport_construct (GType object_type, const gchar* iface);
GType isi_transport_get_type (void) G_GNUC_CONST;
GType isi_transport_register_type (GTypeModule * module);
IsiChannel* isi_channel_new (const gchar* name, IsiTransport* transport);
IsiChannel* isi_channel_construct (GType object_type, const gchar* name, IsiTransport* transport);
GType isi_channel_get_type (void) G_GNUC_CONST;
GType isi_channel_register_type (GTypeModule * module);
static FsoGsmChannel* nokia_isi_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query);
static void nokia_isi_modem_real_registerCustomMediators (FsoGsmAbstractModem* base, GeeHashMap* mediators);
void nokia_isi_registerMediators (GeeHashMap* mediators);
static void nokia_isi_modem_onNetlinkChanged (NokiaIsiModem* self, gboolean online);
static gchar* nokia_isi_modem_gpio_idx2string (NokiaIsiModem* self, gint idx);
static gchar* nokia_isi_modem_filename_for_gpio_line (NokiaIsiModem* self, gint line);
static gchar* nokia_isi_modem_value_to_gpio_string (NokiaIsiModem* self, gboolean value);
static gboolean nokia_isi_modem_gpio_line_probe (NokiaIsiModem* self, gint line);
static gboolean nokia_isi_modem_gpio_probe_links (NokiaIsiModem* self);
static void nokia_isi_modem_gpio_probe (NokiaIsiModem* self);
gchar* nokia_isi_modem_deviceFunctionalityModemStateToString (NokiaIsiModem* self, guint8 state);
guint8 nokia_isi_modem_deviceFunctionalityStringToModemState (NokiaIsiModem* self, const gchar* level);
NokiaIsiModem* nokia_isi_modem_new (void);
NokiaIsiModem* nokia_isi_modem_construct (GType object_type);
static GObject * nokia_isi_modem_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void _nokia_isi_modem_onNetlinkChanged_gisi_comm_modem_access_netlink_changed (GIsiCommModemAccess* _sender, gboolean online, gpointer self);
static void nokia_isi_modem_finalize (GObject* obj);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


GType nokia_isi_modem_rapu_type_get_type (void) {
	static volatile gsize nokia_isi_modem_rapu_type_type_id__volatile = 0;
	if (g_once_init_enter (&nokia_isi_modem_rapu_type_type_id__volatile)) {
		static const GEnumValue values[] = {{NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_1, "NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_1", "type-1"}, {NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_2, "NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_2", "type-2"}, {0, NULL, NULL}};
		GType nokia_isi_modem_rapu_type_type_id;
		nokia_isi_modem_rapu_type_type_id = g_enum_register_static ("NokiaIsiModemRapuType", values);
		g_once_init_leave (&nokia_isi_modem_rapu_type_type_id__volatile, nokia_isi_modem_rapu_type_type_id);
	}
	return nokia_isi_modem_rapu_type_type_id__volatile;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gchar* nokia_isi_modem_real_repr (FsoFrameworkAbstractObject* base) {
	NokiaIsiModem * self;
	gchar* result = NULL;
	FsoFrameworkTransportSpec* _tmp0_;
	FsoFrameworkTransportSpec* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_ = NULL;
	FsoFrameworkTransportSpec* _tmp4_;
	FsoFrameworkTransportSpec* _tmp5_;
	const gchar* _tmp6_;
	const gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	self = (NokiaIsiModem*) base;
	_tmp0_ = fso_gsm_abstract_modem_get_modem_transport_spec ((FsoGsmAbstractModem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = _tmp1_->type;
	_tmp3_ = string_to_string (_tmp2_);
	_tmp4_ = fso_gsm_abstract_modem_get_modem_transport_spec ((FsoGsmAbstractModem*) self);
	_tmp5_ = _tmp4_;
	_tmp6_ = _tmp5_->name;
	_tmp7_ = string_to_string (_tmp6_);
	_tmp8_ = g_strconcat ("<", _tmp3_, ":", _tmp7_, ">", NULL);
	result = _tmp8_;
	return result;
}


static gboolean nokia_isi_modem_real_powerOn (FsoGsmAbstractModem* base) {
	NokiaIsiModem * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	FsoFrameworkLogger* _tmp1_;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_;
	NokiaIsiModemRapuType _tmp4_;
	self = (NokiaIsiModem*) base;
	_tmp0_ = FSO_GSM_ABSTRACT_MODEM_CLASS (nokia_isi_modem_parent_class)->powerOn (FSO_GSM_ABSTRACT_MODEM (self));
	if (!_tmp0_) {
		result = FALSE;
		return result;
	}
	_tmp1_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp2_ = fso_framework_logger_debug (_tmp1_, "modem_nokia_isi: powerOn");
	g_assert (_tmp2_);
	_tmp3_ = self->priv->handle_modem_power;
	if (!_tmp3_) {
		result = TRUE;
		return result;
	}
	_nokia_isi_modem_power_off (self);
	self->priv->startup_sequence = TRUE;
	nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_apeslpx, FALSE);
	nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_rst_rq, FALSE);
	_tmp4_ = self->priv->rapu_type;
	switch (_tmp4_) {
		case NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_2:
		{
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_en, FALSE);
			usleep ((guint) 20000);
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_en, TRUE);
			break;
		}
		case NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_1:
		{
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_en, FALSE);
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_bsi, FALSE);
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_rst, FALSE);
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_en, TRUE);
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_rst, TRUE);
			break;
		}
		default:
		{
			FsoFrameworkLogger* _tmp5_;
			NokiaIsiModemRapuType _tmp6_;
			GEnumValue* _tmp7_;
			gchar* _tmp8_ = NULL;
			gchar* _tmp9_;
			_tmp5_ = ((FsoFrameworkAbstractObject*) self)->logger;
			_tmp6_ = self->priv->rapu_type;
			_tmp7_ = g_enum_get_value (g_type_class_ref (NOKIA_ISI_MODEM_TYPE_RAPU_TYPE), _tmp6_);
			_tmp8_ = g_strconcat ("unknown rapu type ", (_tmp7_ != NULL) ? _tmp7_->value_name : NULL, NULL);
			_tmp9_ = _tmp8_;
			fso_framework_logger_warning (_tmp5_, _tmp9_);
			_g_free0 (_tmp9_);
			result = FALSE;
			return result;
		}
	}
	nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_rst_rq, TRUE);
	result = TRUE;
	return result;
}


static void nokia_isi_modem_real_powerOff (FsoGsmAbstractModem* base) {
	NokiaIsiModem * self;
	FsoFrameworkLogger* _tmp0_;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	self = (NokiaIsiModem*) base;
	FSO_GSM_ABSTRACT_MODEM_CLASS (nokia_isi_modem_parent_class)->powerOff (FSO_GSM_ABSTRACT_MODEM (self));
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = fso_framework_logger_debug (_tmp0_, "modem_nokia_isi: powerOff");
	g_assert (_tmp1_);
	_tmp2_ = self->priv->handle_modem_power;
	if (!_tmp2_) {
		return;
	}
	_nokia_isi_modem_power_off (self);
}


void _nokia_isi_modem_power_off (NokiaIsiModem* self) {
	NokiaIsiModemRapuType _tmp0_;
	g_return_if_fail (self != NULL);
	nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_apeslpx, FALSE);
	nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_rst_rq, FALSE);
	_tmp0_ = self->priv->rapu_type;
	switch (_tmp0_) {
		case NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_2:
		{
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_en, FALSE);
			break;
		}
		case NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_1:
		{
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_en, FALSE);
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_rst, FALSE);
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_rst, TRUE);
			break;
		}
		default:
		break;
	}
}


static FsoGsmUnsolicitedResponseHandler* nokia_isi_modem_real_createUnsolicitedHandler (FsoGsmAbstractModem* base) {
	NokiaIsiModem * self;
	FsoGsmUnsolicitedResponseHandler* result = NULL;
	self = (NokiaIsiModem*) base;
	result = NULL;
	return result;
}


static FsoGsmCallHandler* nokia_isi_modem_real_createCallHandler (FsoGsmAbstractModem* base) {
	NokiaIsiModem * self;
	FsoGsmCallHandler* result = NULL;
	FsoGsmIsiCallHandler* _tmp0_;
	self = (NokiaIsiModem*) base;
	_tmp0_ = fso_gsm_isi_call_handler_new ();
	result = (FsoGsmCallHandler*) _tmp0_;
	return result;
}


static FsoGsmSmsHandler* nokia_isi_modem_real_createSmsHandler (FsoGsmAbstractModem* base) {
	NokiaIsiModem * self;
	FsoGsmSmsHandler* result = NULL;
	self = (NokiaIsiModem*) base;
	result = NULL;
	return result;
}


static FsoGsmPhonebookHandler* nokia_isi_modem_real_createPhonebookHandler (FsoGsmAbstractModem* base) {
	NokiaIsiModem * self;
	FsoGsmPhonebookHandler* result = NULL;
	self = (NokiaIsiModem*) base;
	result = NULL;
	return result;
}


static void nokia_isi_modem_real_createChannels (FsoGsmAbstractModem* base) {
	NokiaIsiModem * self;
	FsoFrameworkTransportSpec* _tmp0_;
	FsoFrameworkTransportSpec* _tmp1_;
	const gchar* _tmp2_;
	IsiTransport* _tmp3_;
	IsiTransport* _tmp4_;
	IsiChannel* _tmp5_;
	IsiChannel* _tmp6_;
	self = (NokiaIsiModem*) base;
	_tmp0_ = fso_gsm_abstract_modem_get_modem_transport_spec ((FsoGsmAbstractModem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = _tmp1_->name;
	_tmp3_ = isi_transport_new (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = isi_channel_new (NOKIA_ISI_MODEM_ISI_CHANNEL_NAME, _tmp4_);
	_tmp6_ = _tmp5_;
	_g_object_unref0 (_tmp6_);
	_g_object_unref0 (_tmp4_);
}


static FsoGsmChannel* nokia_isi_modem_real_channelForCommand (FsoGsmAbstractModem* base, FsoGsmAtCommand* command, const gchar* query) {
	NokiaIsiModem * self;
	FsoGsmChannel* result = NULL;
	self = (NokiaIsiModem*) base;
	g_return_val_if_fail (command != NULL, NULL);
	g_return_val_if_fail (query != NULL, NULL);
	result = NULL;
	return result;
}


static void nokia_isi_modem_real_registerCustomMediators (FsoGsmAbstractModem* base, GeeHashMap* mediators) {
	NokiaIsiModem * self;
	GeeHashMap* _tmp0_;
	GeeHashMap* _tmp1_;
	self = (NokiaIsiModem*) base;
	g_return_if_fail (mediators != NULL);
	_tmp0_ = mediators;
	gee_abstract_map_clear ((GeeAbstractMap*) _tmp0_);
	_tmp1_ = mediators;
	nokia_isi_registerMediators (_tmp1_);
}


static void nokia_isi_modem_onNetlinkChanged (NokiaIsiModem* self, gboolean online) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_;
	gboolean _tmp4_;
	gboolean _tmp6_;
	g_return_if_fail (self != NULL);
	_tmp2_ = self->priv->handle_modem_power;
	if (_tmp2_) {
		gboolean _tmp3_;
		_tmp3_ = online;
		_tmp1_ = _tmp3_;
	} else {
		_tmp1_ = FALSE;
	}
	_tmp4_ = _tmp1_;
	if (_tmp4_) {
		gboolean _tmp5_;
		_tmp5_ = self->priv->startup_sequence;
		_tmp0_ = _tmp5_;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp6_ = _tmp0_;
	if (_tmp6_) {
		NokiaIsiModemRapuType _tmp7_;
		nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_rst_rq, FALSE);
		_tmp7_ = self->priv->rapu_type;
		if (_tmp7_ == NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_1) {
			nokia_isi_modem_gpio_write (self, NOKIA_ISI_MODEM_cmt_en, FALSE);
		}
		self->priv->startup_sequence = FALSE;
	}
}


static gchar* nokia_isi_modem_gpio_idx2string (NokiaIsiModem* self, gint idx) {
	gchar* result = NULL;
	gint _tmp0_;
	gchar* _tmp6_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = idx;
	switch (_tmp0_) {
		case NOKIA_ISI_MODEM_cmt_en:
		{
			gchar* _tmp1_;
			_tmp1_ = g_strdup ("cmt_en");
			result = _tmp1_;
			return result;
		}
		case NOKIA_ISI_MODEM_cmt_rst_rq:
		{
			gchar* _tmp2_;
			_tmp2_ = g_strdup ("cmt_rst_rq");
			result = _tmp2_;
			return result;
		}
		case NOKIA_ISI_MODEM_cmt_rst:
		{
			gchar* _tmp3_;
			_tmp3_ = g_strdup ("cmt_rst");
			result = _tmp3_;
			return result;
		}
		case NOKIA_ISI_MODEM_cmt_bsi:
		{
			gchar* _tmp4_;
			_tmp4_ = g_strdup ("cmt_bsi");
			result = _tmp4_;
			return result;
		}
		case NOKIA_ISI_MODEM_cmt_apeslpx:
		{
			gchar* _tmp5_;
			_tmp5_ = g_strdup ("cmt_apeslpx");
			result = _tmp5_;
			return result;
		}
		default:
		break;
	}
	_tmp6_ = g_strdup ("");
	result = _tmp6_;
	return result;
}


static gchar* nokia_isi_modem_filename_for_gpio_line (NokiaIsiModem* self, gint line) {
	gchar* result = NULL;
	gboolean _tmp0_;
	const gchar* _tmp8_ = NULL;
	gint _tmp9_;
	gchar* _tmp10_ = NULL;
	gchar* _tmp11_;
	const gchar* _tmp12_ = NULL;
	gchar* _tmp13_ = NULL;
	gchar* _tmp14_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->have_gpio_switch;
	if (_tmp0_) {
		const gchar* _tmp1_ = NULL;
		gint _tmp2_;
		gchar* _tmp3_ = NULL;
		gchar* _tmp4_;
		const gchar* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		gchar* _tmp7_;
		_tmp1_ = string_to_string (NOKIA_ISI_MODEM_GPIO_SWITCH);
		_tmp2_ = line;
		_tmp3_ = nokia_isi_modem_gpio_idx2string (self, _tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = string_to_string (_tmp4_);
		_tmp6_ = g_strconcat (_tmp1_, "/", _tmp5_, "/state", NULL);
		_tmp7_ = _tmp6_;
		_g_free0 (_tmp4_);
		result = _tmp7_;
		return result;
	}
	_tmp8_ = string_to_string (NOKIA_ISI_MODEM_DEV_CMT);
	_tmp9_ = line;
	_tmp10_ = nokia_isi_modem_gpio_idx2string (self, _tmp9_);
	_tmp11_ = _tmp10_;
	_tmp12_ = string_to_string (_tmp11_);
	_tmp13_ = g_strconcat (_tmp8_, "/", _tmp12_, "/value", NULL);
	_tmp14_ = _tmp13_;
	_g_free0 (_tmp11_);
	result = _tmp14_;
	return result;
}


static gchar* nokia_isi_modem_value_to_gpio_string (NokiaIsiModem* self, gboolean value) {
	gchar* result = NULL;
	gboolean _tmp0_;
	const gchar* _tmp5_ = NULL;
	gboolean _tmp6_;
	const gchar* _tmp7_;
	gchar* _tmp8_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->have_gpio_switch;
	if (_tmp0_) {
		const gchar* _tmp1_ = NULL;
		gboolean _tmp2_;
		const gchar* _tmp3_;
		gchar* _tmp4_;
		_tmp2_ = value;
		if (_tmp2_) {
			_tmp1_ = "active";
		} else {
			_tmp1_ = "inactive";
		}
		_tmp3_ = _tmp1_;
		_tmp4_ = g_strdup (_tmp3_);
		result = _tmp4_;
		return result;
	}
	_tmp6_ = value;
	if (_tmp6_) {
		_tmp5_ = "1";
	} else {
		_tmp5_ = "0";
	}
	_tmp7_ = _tmp5_;
	_tmp8_ = g_strdup (_tmp7_);
	result = _tmp8_;
	return result;
}


static void nokia_isi_modem_gpio_write (NokiaIsiModem* self, gint line, gboolean value) {
	gint _tmp0_;
	gboolean _tmp1_;
	FsoFrameworkLogger* _tmp10_;
	gboolean _tmp11_;
	gchar* _tmp12_ = NULL;
	gchar* _tmp13_;
	const gchar* _tmp14_ = NULL;
	gint _tmp15_;
	gchar* _tmp16_ = NULL;
	gchar* _tmp17_;
	const gchar* _tmp18_ = NULL;
	gchar* _tmp19_ = NULL;
	gchar* _tmp20_;
	gboolean _tmp21_ = FALSE;
	gboolean _tmp22_;
	gchar* _tmp23_ = NULL;
	gchar* _tmp24_;
	gint _tmp25_;
	gchar* _tmp26_ = NULL;
	gchar* _tmp27_;
	g_return_if_fail (self != NULL);
	_tmp0_ = line;
	_tmp1_ = self->priv->have_gpio[_tmp0_];
	if (!_tmp1_) {
		FsoFrameworkLogger* _tmp2_;
		gint _tmp3_;
		gchar* _tmp4_ = NULL;
		gchar* _tmp5_;
		const gchar* _tmp6_ = NULL;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		gboolean _tmp9_ = FALSE;
		_tmp2_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp3_ = line;
		_tmp4_ = nokia_isi_modem_gpio_idx2string (self, _tmp3_);
		_tmp5_ = _tmp4_;
		_tmp6_ = string_to_string (_tmp5_);
		_tmp7_ = g_strconcat ("gpio_write: we don't have gpio ", _tmp6_, " - ignoring", NULL);
		_tmp8_ = _tmp7_;
		_tmp9_ = fso_framework_logger_debug (_tmp2_, _tmp8_);
		g_assert (_tmp9_);
		_g_free0 (_tmp8_);
		_g_free0 (_tmp5_);
		return;
	}
	_tmp10_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp11_ = value;
	_tmp12_ = nokia_isi_modem_value_to_gpio_string (self, _tmp11_);
	_tmp13_ = _tmp12_;
	_tmp14_ = string_to_string (_tmp13_);
	_tmp15_ = line;
	_tmp16_ = nokia_isi_modem_filename_for_gpio_line (self, _tmp15_);
	_tmp17_ = _tmp16_;
	_tmp18_ = string_to_string (_tmp17_);
	_tmp19_ = g_strconcat ("gpio_write: writing ", _tmp14_, " to ", _tmp18_, NULL);
	_tmp20_ = _tmp19_;
	_tmp21_ = fso_framework_logger_debug (_tmp10_, _tmp20_);
	g_assert (_tmp21_);
	_g_free0 (_tmp20_);
	_g_free0 (_tmp17_);
	_g_free0 (_tmp13_);
	_tmp22_ = value;
	_tmp23_ = nokia_isi_modem_value_to_gpio_string (self, _tmp22_);
	_tmp24_ = _tmp23_;
	_tmp25_ = line;
	_tmp26_ = nokia_isi_modem_filename_for_gpio_line (self, _tmp25_);
	_tmp27_ = _tmp26_;
	fso_framework_file_handling_write (_tmp24_, _tmp27_, FALSE);
	_g_free0 (_tmp27_);
	_g_free0 (_tmp24_);
}


static gboolean nokia_isi_modem_gpio_line_probe (NokiaIsiModem* self, gint line) {
	gboolean result = FALSE;
	FsoFrameworkLogger* _tmp0_;
	gint _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_;
	gboolean _tmp7_ = FALSE;
	gint _tmp8_;
	gchar* _tmp9_ = NULL;
	gchar* _tmp10_;
	gboolean _tmp11_ = FALSE;
	gboolean _tmp12_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp1_ = line;
	_tmp2_ = nokia_isi_modem_filename_for_gpio_line (self, _tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = string_to_string (_tmp3_);
	_tmp5_ = g_strconcat ("probing for ", _tmp4_, NULL);
	_tmp6_ = _tmp5_;
	_tmp7_ = fso_framework_logger_debug (_tmp0_, _tmp6_);
	g_assert (_tmp7_);
	_g_free0 (_tmp6_);
	_g_free0 (_tmp3_);
	_tmp8_ = line;
	_tmp9_ = nokia_isi_modem_filename_for_gpio_line (self, _tmp8_);
	_tmp10_ = _tmp9_;
	_tmp11_ = fso_framework_file_handling_isPresent (_tmp10_);
	_tmp12_ = _tmp11_;
	_g_free0 (_tmp10_);
	result = _tmp12_;
	return result;
}


static gboolean nokia_isi_modem_gpio_probe_links (NokiaIsiModem* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = fso_framework_file_handling_isPresent (NOKIA_ISI_MODEM_DEV_CMT);
	result = _tmp0_;
	return result;
}


static gchar* bool_to_string (gboolean self) {
	gchar* result = NULL;
	if (self) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup ("true");
		result = _tmp0_;
		return result;
	} else {
		gchar* _tmp1_;
		_tmp1_ = g_strdup ("false");
		result = _tmp1_;
		return result;
	}
}


static void nokia_isi_modem_gpio_probe (NokiaIsiModem* self) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_;
	gboolean _tmp31_;
	gboolean _tmp33_;
	FsoFrameworkLogger* _tmp34_;
	NokiaIsiModemRapuType _tmp35_;
	GEnumValue* _tmp36_;
	gchar* _tmp37_ = NULL;
	gchar* _tmp38_;
	gboolean _tmp39_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = fso_framework_file_handling_isPresent (NOKIA_ISI_MODEM_GPIO_SWITCH);
	self->priv->have_gpio_switch = _tmp0_;
	_tmp1_ = self->priv->have_gpio_switch;
	if (_tmp1_) {
		FsoFrameworkLogger* _tmp2_;
		const gchar* _tmp3_ = NULL;
		gchar* _tmp4_ = NULL;
		gchar* _tmp5_;
		_tmp2_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp3_ = string_to_string (NOKIA_ISI_MODEM_GPIO_SWITCH);
		_tmp4_ = g_strconcat ("Using ", _tmp3_, " switch", NULL);
		_tmp5_ = _tmp4_;
		fso_framework_logger_info (_tmp2_, _tmp5_);
		_g_free0 (_tmp5_);
	} else {
		gboolean _tmp6_ = FALSE;
		FsoFrameworkLogger* _tmp7_;
		const gchar* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_;
		_tmp6_ = nokia_isi_modem_gpio_probe_links (self);
		if (!_tmp6_) {
			return;
		}
		_tmp7_ = ((FsoFrameworkAbstractObject*) self)->logger;
		_tmp8_ = string_to_string (NOKIA_ISI_MODEM_DEV_CMT);
		_tmp9_ = g_strconcat ("Using ", _tmp8_, NULL);
		_tmp10_ = _tmp9_;
		fso_framework_logger_info (_tmp7_, _tmp10_);
		_g_free0 (_tmp10_);
	}
	{
		gint f;
		f = 0;
		{
			gboolean _tmp11_;
			_tmp11_ = TRUE;
			while (TRUE) {
				gboolean _tmp12_;
				gint _tmp14_;
				gint _tmp15_;
				gint _tmp16_;
				gboolean _tmp17_ = FALSE;
				gboolean _tmp18_;
				FsoFrameworkLogger* _tmp19_;
				gint _tmp20_;
				gchar* _tmp21_ = NULL;
				gchar* _tmp22_;
				const gchar* _tmp23_ = NULL;
				gint _tmp24_;
				gboolean _tmp25_;
				gchar* _tmp26_ = NULL;
				gchar* _tmp27_;
				gchar* _tmp28_ = NULL;
				gchar* _tmp29_;
				gboolean _tmp30_ = FALSE;
				_tmp12_ = _tmp11_;
				if (!_tmp12_) {
					gint _tmp13_;
					_tmp13_ = f;
					f = _tmp13_ + 1;
				}
				_tmp11_ = FALSE;
				_tmp14_ = f;
				if (!(_tmp14_ < 5)) {
					break;
				}
				_tmp15_ = f;
				_tmp16_ = f;
				_tmp17_ = nokia_isi_modem_gpio_line_probe (self, _tmp16_);
				self->priv->have_gpio[_tmp15_] = _tmp17_;
				_tmp18_ = self->priv->have_gpio[_tmp15_];
				_tmp19_ = ((FsoFrameworkAbstractObject*) self)->logger;
				_tmp20_ = f;
				_tmp21_ = nokia_isi_modem_gpio_idx2string (self, _tmp20_);
				_tmp22_ = _tmp21_;
				_tmp23_ = string_to_string (_tmp22_);
				_tmp24_ = f;
				_tmp25_ = self->priv->have_gpio[_tmp24_];
				_tmp26_ = bool_to_string (_tmp25_);
				_tmp27_ = _tmp26_;
				_tmp28_ = g_strconcat ("   --> ", _tmp23_, ": ", _tmp27_, NULL);
				_tmp29_ = _tmp28_;
				_tmp30_ = fso_framework_logger_debug (_tmp19_, _tmp29_);
				g_assert (_tmp30_);
				_g_free0 (_tmp29_);
				_g_free0 (_tmp27_);
				_g_free0 (_tmp22_);
			}
		}
	}
	_tmp31_ = self->priv->have_gpio[NOKIA_ISI_MODEM_cmt_en];
	if (!_tmp31_) {
		FsoFrameworkLogger* _tmp32_;
		_tmp32_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_warning (_tmp32_, "Modem control GPIO lines are not available");
		return;
	}
	_tmp33_ = self->priv->have_gpio[NOKIA_ISI_MODEM_cmt_bsi];
	if (_tmp33_) {
		self->priv->rapu_type = NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_1;
	} else {
		self->priv->rapu_type = NOKIA_ISI_MODEM_RAPU_TYPE_TYPE_2;
	}
	_tmp34_ = ((FsoFrameworkAbstractObject*) self)->logger;
	_tmp35_ = self->priv->rapu_type;
	_tmp36_ = g_enum_get_value (g_type_class_ref (NOKIA_ISI_MODEM_TYPE_RAPU_TYPE), _tmp35_);
	_tmp37_ = g_strconcat ("gpio_probe: rapu is ", (_tmp36_ != NULL) ? _tmp36_->value_name : NULL, NULL);
	_tmp38_ = _tmp37_;
	_tmp39_ = fso_framework_logger_debug (_tmp34_, _tmp38_);
	g_assert (_tmp39_);
	_g_free0 (_tmp38_);
}


gchar* nokia_isi_modem_deviceFunctionalityModemStateToString (NokiaIsiModem* self, guint8 state) {
	gchar* result = NULL;
	guint8 _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = state;
	switch (_tmp0_) {
		case MTC_NORMAL:
		{
			gchar* _tmp1_;
			_tmp1_ = g_strdup ("full");
			result = _tmp1_;
			return result;
		}
		case MTC_RF_INACTIVE:
		{
			gchar* _tmp2_;
			_tmp2_ = g_strdup ("airplane");
			result = _tmp2_;
			return result;
		}
		case MTC_POWER_OFF:
		{
			gchar* _tmp3_;
			_tmp3_ = g_strdup ("minimal");
			result = _tmp3_;
			return result;
		}
		default:
		{
			gchar* _tmp4_;
			_tmp4_ = g_strdup ("unknown");
			result = _tmp4_;
			return result;
		}
	}
}


guint8 nokia_isi_modem_deviceFunctionalityStringToModemState (NokiaIsiModem* self, const gchar* level) {
	guint8 result = 0;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	GQuark _tmp3_ = 0U;
	static GQuark _tmp2_label0 = 0;
	static GQuark _tmp2_label1 = 0;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (level != NULL, 0);
	_tmp0_ = level;
	_tmp1_ = _tmp0_;
	_tmp3_ = (NULL == _tmp1_) ? 0 : g_quark_from_string (_tmp1_);
	if (_tmp3_ == ((0 != _tmp2_label0) ? _tmp2_label0 : (_tmp2_label0 = g_quark_from_static_string ("full")))) {
		switch (0) {
			default:
			{
				result = MTC_NORMAL;
				return result;
			}
		}
	} else if (_tmp3_ == ((0 != _tmp2_label1) ? _tmp2_label1 : (_tmp2_label1 = g_quark_from_static_string ("airplane")))) {
		switch (0) {
			default:
			{
				result = MTC_RF_INACTIVE;
				return result;
			}
		}
	} else {
		switch (0) {
			default:
			{
				result = MTC_POWER_OFF;
				return result;
			}
		}
	}
}


NokiaIsiModem* nokia_isi_modem_construct (GType object_type) {
	NokiaIsiModem * self = NULL;
	self = (NokiaIsiModem*) fso_gsm_abstract_modem_construct (object_type);
	return self;
}


NokiaIsiModem* nokia_isi_modem_new (void) {
	return nokia_isi_modem_construct (NOKIA_ISI_TYPE_MODEM);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _nokia_isi_modem_onNetlinkChanged_gisi_comm_modem_access_netlink_changed (GIsiCommModemAccess* _sender, gboolean online, gpointer self) {
	nokia_isi_modem_onNetlinkChanged (self, online);
}


static GObject * nokia_isi_modem_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	NokiaIsiModem * self;
	FsoFrameworkTransportSpec* _tmp0_;
	FsoFrameworkTransportSpec* _tmp1_;
	const gchar* _tmp2_;
	FsoFrameworkSmartKeyFile* _tmp4_;
	gboolean _tmp5_ = FALSE;
	NokiaIsiModem* _tmp6_;
	FsoFrameworkTransportSpec* _tmp7_;
	FsoFrameworkTransportSpec* _tmp8_;
	const gchar* _tmp9_;
	GIsiCommModemAccess* _tmp10_;
	GIsiCommModemAccess* _tmp11_;
	GIsiModem* _tmp12_;
	GIsiCommModemAccess* _tmp13_;
	parent_class = G_OBJECT_CLASS (nokia_isi_modem_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = NOKIA_ISI_MODEM (obj);
	_tmp0_ = fso_gsm_abstract_modem_get_modem_transport_spec ((FsoGsmAbstractModem*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = _tmp1_->type;
	if (g_strcmp0 (_tmp2_, "phonet") != 0) {
		FsoFrameworkLogger* _tmp3_;
		_tmp3_ = ((FsoFrameworkAbstractObject*) self)->logger;
		fso_framework_logger_critical (_tmp3_, "ISI: This modem plugin only supports the PHONET transport");
		return obj;
	}
	_tmp4_ = ((FsoFrameworkAbstractObject*) self)->config;
	_tmp5_ = fso_framework_smart_key_file_boolValue (_tmp4_, NOKIA_ISI_MODULE_NAME, "handle_modem_power", TRUE);
	self->priv->handle_modem_power = _tmp5_;
	_tmp6_ = _g_object_ref0 (self);
	_g_object_unref0 (nokia_isi_modem);
	nokia_isi_modem = _tmp6_;
	_tmp7_ = fso_gsm_abstract_modem_get_modem_transport_spec ((FsoGsmAbstractModem*) self);
	_tmp8_ = _tmp7_;
	_tmp9_ = _tmp8_->name;
	_tmp10_ = gisi_comm_modem_access_new (_tmp9_);
	_gisi_comm_modem_access_unref0 (nokia_isi_isimodem);
	nokia_isi_isimodem = _tmp10_;
	_tmp11_ = nokia_isi_isimodem;
	_tmp12_ = _tmp11_->m;
	g_isi_modem_set_flags (_tmp12_, GISI_MODEM_FLAG_USE_LEGACY_SUBSCRIBE);
	_tmp13_ = nokia_isi_isimodem;
	g_signal_connect_object (_tmp13_, "netlink-changed", (GCallback) _nokia_isi_modem_onNetlinkChanged_gisi_comm_modem_access_netlink_changed, self, 0);
	nokia_isi_modem_gpio_probe (self);
	return obj;
}


static void nokia_isi_modem_class_init (NokiaIsiModemClass * klass) {
	nokia_isi_modem_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (NokiaIsiModemPrivate));
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = nokia_isi_modem_real_repr;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->powerOn = nokia_isi_modem_real_powerOn;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->powerOff = nokia_isi_modem_real_powerOff;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createUnsolicitedHandler = nokia_isi_modem_real_createUnsolicitedHandler;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createCallHandler = nokia_isi_modem_real_createCallHandler;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createSmsHandler = nokia_isi_modem_real_createSmsHandler;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createPhonebookHandler = nokia_isi_modem_real_createPhonebookHandler;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->createChannels = nokia_isi_modem_real_createChannels;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->channelForCommand = nokia_isi_modem_real_channelForCommand;
	FSO_GSM_ABSTRACT_MODEM_CLASS (klass)->registerCustomMediators = nokia_isi_modem_real_registerCustomMediators;
	G_OBJECT_CLASS (klass)->constructor = nokia_isi_modem_constructor;
	G_OBJECT_CLASS (klass)->finalize = nokia_isi_modem_finalize;
}


static void nokia_isi_modem_instance_init (NokiaIsiModem * self) {
	self->priv = NOKIA_ISI_MODEM_GET_PRIVATE (self);
	self->priv->startup_sequence = FALSE;
	self->priv->handle_modem_power = TRUE;
}


static void nokia_isi_modem_finalize (GObject* obj) {
	NokiaIsiModem * self;
	self = NOKIA_ISI_MODEM (obj);
	G_OBJECT_CLASS (nokia_isi_modem_parent_class)->finalize (obj);
}


/**
 * @class NokiaIsi.Modem
 *
 * This modem plugin supports the Nokia ISI chipset used on Nokia N900
 *
 * The modem uses a binary protocol implemented in libgisi / libgisicomm
 **/
GType nokia_isi_modem_get_type (void) {
	return nokia_isi_modem_type_id;
}


GType nokia_isi_modem_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (NokiaIsiModemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) nokia_isi_modem_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NokiaIsiModem), 0, (GInstanceInitFunc) nokia_isi_modem_instance_init, NULL };
	nokia_isi_modem_type_id = g_type_module_register_type (module, FSO_GSM_TYPE_ABSTRACT_MODEM, "NokiaIsiModem", &g_define_type_info, 0);
	return nokia_isi_modem_type_id;
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
	fso_framework_logger_debug (_tmp0_, "nokia_isi fso_factory_function");
	_tmp1_ = g_strdup ("fsogsm.modem_nokia_isi");
	result = _tmp1_;
	return result;
}


void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	fso_gsm_isi_call_handler_register_type (module);
	nokia_isi_modem_register_type (module);
	nokia_isi_isi_unsolicited_handler_register_type (module);
	nokia_isi_isi_call_activate_register_type (module);
	nokia_isi_isi_call_hold_active_register_type (module);
	nokia_isi_isi_call_initiate_register_type (module);
	nokia_isi_isi_call_release_register_type (module);
	nokia_isi_isi_call_release_all_register_type (module);
	nokia_isi_isi_call_list_calls_register_type (module);
	nokia_isi_isi_call_send_dtmf_register_type (module);
	nokia_isi_isi_debug_command_register_type (module);
	nokia_isi_isi_device_get_information_register_type (module);
	nokia_isi_isi_device_set_functionality_register_type (module);
	nokia_isi_isi_network_get_status_register_type (module);
	nokia_isi_isi_network_list_providers_register_type (module);
	nokia_isi_isi_network_get_signal_strength_register_type (module);
	nokia_isi_isi_network_register_register_type (module);
	nokia_isi_isi_network_register_with_provider_register_type (module);
	nokia_isi_isi_pdp_set_credentials_register_type (module);
	nokia_isi_isi_sim_get_auth_status_register_type (module);
	nokia_isi_isi_sim_get_information_register_type (module);
	nokia_isi_isi_sim_send_auth_code_register_type (module);
	nokia_isi_isi_sim_get_auth_code_required_register_type (module);
	nokia_isi_isi_sim_change_auth_code_register_type (module);
	nokia_isi_isi_sms_send_text_message_register_type (module);
	isi_transport_register_type (module);
	isi_channel_register_type (module);
}




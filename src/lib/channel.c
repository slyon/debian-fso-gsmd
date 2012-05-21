/* channel.c generated by valac 0.14.2, the Vala compiler
 * generated from channel.vala, do not modify */

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
#include <fsotransport.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define FSO_GSM_TYPE_CHANNEL (fso_gsm_channel_get_type ())
#define FSO_GSM_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_CHANNEL, FsoGsmChannel))
#define FSO_GSM_IS_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_CHANNEL))
#define FSO_GSM_CHANNEL_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_GSM_TYPE_CHANNEL, FsoGsmChannelIface))

typedef struct _FsoGsmChannel FsoGsmChannel;
typedef struct _FsoGsmChannelIface FsoGsmChannelIface;

struct _FsoGsmChannelIface {
	GTypeInterface parent_iface;
	void (*injectResponse) (FsoGsmChannel* self, const gchar* response);
	void (*suspend) (FsoGsmChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	gboolean (*suspend_finish) (FsoGsmChannel* self, GAsyncResult* _res_);
	void (*resume) (FsoGsmChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	gboolean (*resume_finish) (FsoGsmChannel* self, GAsyncResult* _res_);
};



GType fso_gsm_channel_get_type (void) G_GNUC_CONST;
void fso_gsm_channel_injectResponse (FsoGsmChannel* self, const gchar* response);
void fso_gsm_channel_suspend (FsoGsmChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
gboolean fso_gsm_channel_suspend_finish (FsoGsmChannel* self, GAsyncResult* _res_);
void fso_gsm_channel_resume (FsoGsmChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
gboolean fso_gsm_channel_resume_finish (FsoGsmChannel* self, GAsyncResult* _res_);
gboolean fso_gsm_channel_isActive (FsoGsmChannel* self);


void fso_gsm_channel_injectResponse (FsoGsmChannel* self, const gchar* response) {
	g_return_if_fail (self != NULL);
	FSO_GSM_CHANNEL_GET_INTERFACE (self)->injectResponse (self, response);
}


void fso_gsm_channel_suspend (FsoGsmChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FSO_GSM_CHANNEL_GET_INTERFACE (self)->suspend (self, _callback_, _user_data_);
}


gboolean fso_gsm_channel_suspend_finish (FsoGsmChannel* self, GAsyncResult* _res_) {
	return FSO_GSM_CHANNEL_GET_INTERFACE (self)->suspend_finish (self, _res_);
}


void fso_gsm_channel_resume (FsoGsmChannel* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FSO_GSM_CHANNEL_GET_INTERFACE (self)->resume (self, _callback_, _user_data_);
}


gboolean fso_gsm_channel_resume_finish (FsoGsmChannel* self, GAsyncResult* _res_) {
	return FSO_GSM_CHANNEL_GET_INTERFACE (self)->resume_finish (self, _res_);
}


/**
     * Check if the channel is currently active.
     **/
gboolean fso_gsm_channel_isActive (FsoGsmChannel* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	FsoFrameworkTransport* _tmp1_;
	FsoFrameworkTransport* _tmp2_;
	_tmp1_ = fso_framework_command_queue_get_transport ((FsoFrameworkCommandQueue*) self);
	_tmp2_ = _tmp1_;
	if (_tmp2_ == NULL) {
		_tmp0_ = FALSE;
	} else {
		FsoFrameworkTransport* _tmp3_;
		FsoFrameworkTransport* _tmp4_;
		gboolean _tmp5_ = FALSE;
		_tmp3_ = fso_framework_command_queue_get_transport ((FsoFrameworkCommandQueue*) self);
		_tmp4_ = _tmp3_;
		_tmp5_ = fso_framework_transport_isOpen (_tmp4_);
		_tmp0_ = _tmp5_;
	}
	result = _tmp0_;
	return result;
}


static void fso_gsm_channel_base_init (FsoGsmChannelIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		g_signal_new ("hangup", FSO_GSM_TYPE_CHANNEL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	}
}


GType fso_gsm_channel_get_type (void) {
	static volatile gsize fso_gsm_channel_type_id__volatile = 0;
	if (g_once_init_enter (&fso_gsm_channel_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoGsmChannelIface), (GBaseInitFunc) fso_gsm_channel_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType fso_gsm_channel_type_id;
		fso_gsm_channel_type_id = g_type_register_static (G_TYPE_INTERFACE, "FsoGsmChannel", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (fso_gsm_channel_type_id, FSO_FRAMEWORK_TYPE_COMMAND_QUEUE);
		g_once_init_leave (&fso_gsm_channel_type_id__volatile, fso_gsm_channel_type_id);
	}
	return fso_gsm_channel_type_id__volatile;
}



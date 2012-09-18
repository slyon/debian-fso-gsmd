/* serviceprovider.c generated by valac 0.16.0, the Vala compiler
 * generated from serviceprovider.vala, do not modify */

/*
 * Copyright (C) 2012 Simon Busch <morphis@gravedo.de>
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


#define FSO_GSM_TYPE_ISERVICE_PROVIDER (fso_gsm_iservice_provider_get_type ())
#define FSO_GSM_ISERVICE_PROVIDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_GSM_TYPE_ISERVICE_PROVIDER, FsoGsmIServiceProvider))
#define FSO_GSM_IS_ISERVICE_PROVIDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_GSM_TYPE_ISERVICE_PROVIDER))
#define FSO_GSM_ISERVICE_PROVIDER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_GSM_TYPE_ISERVICE_PROVIDER, FsoGsmIServiceProviderIface))

typedef struct _FsoGsmIServiceProvider FsoGsmIServiceProvider;
typedef struct _FsoGsmIServiceProviderIface FsoGsmIServiceProviderIface;

struct _FsoGsmIServiceProviderIface {
	GTypeInterface parent_iface;
	gpointer (*retrieveService) (FsoGsmIServiceProvider* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func);
};



GType fso_gsm_iservice_provider_get_type (void) G_GNUC_CONST;
gpointer fso_gsm_iservice_provider_retrieveService (FsoGsmIServiceProvider* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func);


gpointer fso_gsm_iservice_provider_retrieveService (FsoGsmIServiceProvider* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_GSM_ISERVICE_PROVIDER_GET_INTERFACE (self)->retrieveService (self, t_type, t_dup_func, t_destroy_func);
}


static void fso_gsm_iservice_provider_base_init (FsoGsmIServiceProviderIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType fso_gsm_iservice_provider_get_type (void) {
	static volatile gsize fso_gsm_iservice_provider_type_id__volatile = 0;
	if (g_once_init_enter (&fso_gsm_iservice_provider_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoGsmIServiceProviderIface), (GBaseInitFunc) fso_gsm_iservice_provider_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType fso_gsm_iservice_provider_type_id;
		fso_gsm_iservice_provider_type_id = g_type_register_static (G_TYPE_INTERFACE, "FsoGsmIServiceProvider", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (fso_gsm_iservice_provider_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&fso_gsm_iservice_provider_type_id__volatile, fso_gsm_iservice_provider_type_id);
	}
	return fso_gsm_iservice_provider_type_id__volatile;
}




/* soundhandler.c generated by valac 0.14.2, the Vala compiler
 * generated from soundhandler.vala, do not modify */

/*
 * Copyright (C) 2011 Simon Busch <morphis@gravedo.de>
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
#include <gio/gio.h>
#include <freesmartphone.h>
#include <fsogsm.h>
#include <fsotransport.h>
#include <radio.h>
#include <stdlib.h>
#include <string.h>


#define SAMSUNG_TYPE_SOUND_HANDLER (samsung_sound_handler_get_type ())
#define SAMSUNG_SOUND_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_SOUND_HANDLER, SamsungSoundHandler))
#define SAMSUNG_SOUND_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_SOUND_HANDLER, SamsungSoundHandlerClass))
#define SAMSUNG_IS_SOUND_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_SOUND_HANDLER))
#define SAMSUNG_IS_SOUND_HANDLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_SOUND_HANDLER))
#define SAMSUNG_SOUND_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_SOUND_HANDLER, SamsungSoundHandlerClass))

typedef struct _SamsungSoundHandler SamsungSoundHandler;
typedef struct _SamsungSoundHandlerClass SamsungSoundHandlerClass;
typedef struct _SamsungSoundHandlerPrivate SamsungSoundHandlerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SAMSUNG_TYPE_IPC_CHANNEL (samsung_ipc_channel_get_type ())
#define SAMSUNG_IPC_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannel))
#define SAMSUNG_IPC_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannelClass))
#define SAMSUNG_IS_IPC_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SAMSUNG_TYPE_IPC_CHANNEL))
#define SAMSUNG_IS_IPC_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SAMSUNG_TYPE_IPC_CHANNEL))
#define SAMSUNG_IPC_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SAMSUNG_TYPE_IPC_CHANNEL, SamsungIpcChannelClass))

typedef struct _SamsungIpcChannel SamsungIpcChannel;
typedef struct _SamsungIpcChannelClass SamsungIpcChannelClass;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _SamsungSoundHandlerMuteMicrophoneData SamsungSoundHandlerMuteMicrophoneData;
typedef struct _SamsungSoundHandlerSetSpeakerVolumeData SamsungSoundHandlerSetSpeakerVolumeData;
typedef struct _SamsungSoundHandlerSetAudioPathData SamsungSoundHandlerSetAudioPathData;
typedef struct _SamsungSoundHandlerExecuteClockControlData SamsungSoundHandlerExecuteClockControlData;

struct _SamsungSoundHandler {
	FsoFrameworkAbstractObject parent_instance;
	SamsungSoundHandlerPrivate * priv;
};

struct _SamsungSoundHandlerClass {
	FsoFrameworkAbstractObjectClass parent_class;
};

struct _SamsungSoundHandlerMuteMicrophoneData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSoundHandler* self;
	gboolean mute;
	FsoGsmModem* _tmp0_;
	FsoGsmChannel* _tmp1_;
	SamsungIpcChannel* channel;
	struct ipc_message_info* response;
	gint _tmp2_;
	gboolean _tmp3_;
	SamsungIpcChannel* _tmp4_;
	gint _tmp5_;
	guint8* _tmp6_;
	guint8* _tmp7_;
	gint _tmp7__length1;
	struct ipc_message_info* _tmp8_;
	struct ipc_message_info* _tmp9_;
	guint8* _tmp10_;
	gint _tmp10__length1;
	struct ipc_gen_phone_res* gr;
	struct ipc_gen_phone_res* _tmp11_;
	guint16 _tmp12_;
	const gchar* _tmp13_;
	gboolean _tmp14_;
	const gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	GError* _tmp18_;
	GError* _tmp19_;
	GError * _inner_error_;
};

struct _SamsungSoundHandlerSetSpeakerVolumeData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSoundHandler* self;
	gint8 type;
	guint8 volume;
	FsoGsmModem* _tmp0_;
	FsoGsmChannel* _tmp1_;
	SamsungIpcChannel* channel;
	struct ipc_message_info* response;
	struct ipc_snd_spkr_volume_ctrl cmd;
	gint8 _tmp2_;
	guint8 _tmp3_;
	SamsungIpcChannel* _tmp4_;
	struct ipc_snd_spkr_volume_ctrl _tmp5_;
	guint8* _tmp6_;
	gint _tmp6__length1;
	guint8* _tmp7_;
	gint _tmp7__length1;
	struct ipc_message_info* _tmp8_;
	struct ipc_message_info* _tmp9_;
	guint8* _tmp10_;
	gint _tmp10__length1;
	struct ipc_gen_phone_res* gr;
	struct ipc_gen_phone_res* _tmp11_;
	guint16 _tmp12_;
	GError* _tmp13_;
	GError * _inner_error_;
};

struct _SamsungSoundHandlerSetAudioPathData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSoundHandler* self;
	gint8 path;
	FsoGsmModem* _tmp0_;
	FsoGsmChannel* _tmp1_;
	SamsungIpcChannel* channel;
	struct ipc_message_info* response;
	SamsungIpcChannel* _tmp2_;
	gint8 _tmp3_;
	guint8* _tmp4_;
	guint8* _tmp5_;
	gint _tmp5__length1;
	struct ipc_message_info* _tmp6_;
	struct ipc_message_info* _tmp7_;
	guint8* _tmp8_;
	gint _tmp8__length1;
	struct ipc_gen_phone_res* gr;
	struct ipc_gen_phone_res* _tmp9_;
	guint16 _tmp10_;
	GError* _tmp11_;
	GError * _inner_error_;
};

struct _SamsungSoundHandlerExecuteClockControlData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SamsungSoundHandler* self;
	FsoGsmModem* _tmp0_;
	FsoGsmChannel* _tmp1_;
	SamsungIpcChannel* channel;
	struct ipc_message_info* response;
	SamsungIpcChannel* _tmp2_;
	guint8* _tmp3_;
	guint8* _tmp4_;
	gint _tmp4__length1;
	struct ipc_message_info* _tmp5_;
	struct ipc_message_info* _tmp6_;
	guint8* _tmp7_;
	gint _tmp7__length1;
	struct ipc_gen_phone_res* gr;
	struct ipc_gen_phone_res* _tmp8_;
	guint16 _tmp9_;
	GError* _tmp10_;
	GError * _inner_error_;
};


static gpointer samsung_sound_handler_parent_class = NULL;
static GType samsung_sound_handler_type_id = 0;

GType samsung_sound_handler_get_type (void) G_GNUC_CONST;
GType samsung_sound_handler_register_type (GTypeModule * module);
enum  {
	SAMSUNG_SOUND_HANDLER_DUMMY_PROPERTY
};
static void samsung_sound_handler_mute_microphone_data_free (gpointer _data);
void samsung_sound_handler_mute_microphone (SamsungSoundHandler* self, gboolean mute, GAsyncReadyCallback _callback_, gpointer _user_data_);
void samsung_sound_handler_mute_microphone_finish (SamsungSoundHandler* self, GAsyncResult* _res_, GError** error);
static gboolean samsung_sound_handler_mute_microphone_co (SamsungSoundHandlerMuteMicrophoneData* _data_);
GType samsung_ipc_channel_get_type (void) G_GNUC_CONST;
GType samsung_ipc_channel_register_type (GTypeModule * module);
void samsung_ipc_channel_enqueue_async (SamsungIpcChannel* self, int type, unsigned short command, guint8* data, int data_length1, gint retry, gint timeout, GAsyncReadyCallback _callback_, gpointer _user_data_);
struct ipc_message_info* samsung_ipc_channel_enqueue_finish (SamsungIpcChannel* self, GAsyncResult* _res_);
static void samsung_sound_handler_mute_microphone_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void samsung_sound_handler_set_speaker_volume_data_free (gpointer _data);
void samsung_sound_handler_set_speaker_volume (SamsungSoundHandler* self, gint8 type, guint8 volume, GAsyncReadyCallback _callback_, gpointer _user_data_);
void samsung_sound_handler_set_speaker_volume_finish (SamsungSoundHandler* self, GAsyncResult* _res_, GError** error);
static gboolean samsung_sound_handler_set_speaker_volume_co (SamsungSoundHandlerSetSpeakerVolumeData* _data_);
static void samsung_sound_handler_set_speaker_volume_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void samsung_sound_handler_set_audio_path_data_free (gpointer _data);
void samsung_sound_handler_set_audio_path (SamsungSoundHandler* self, gint8 path, GAsyncReadyCallback _callback_, gpointer _user_data_);
void samsung_sound_handler_set_audio_path_finish (SamsungSoundHandler* self, GAsyncResult* _res_, GError** error);
static gboolean samsung_sound_handler_set_audio_path_co (SamsungSoundHandlerSetAudioPathData* _data_);
static void samsung_sound_handler_set_audio_path_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void samsung_sound_handler_execute_clock_control_data_free (gpointer _data);
void samsung_sound_handler_execute_clock_control (SamsungSoundHandler* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void samsung_sound_handler_execute_clock_control_finish (SamsungSoundHandler* self, GAsyncResult* _res_, GError** error);
static gboolean samsung_sound_handler_execute_clock_control_co (SamsungSoundHandlerExecuteClockControlData* _data_);
static void samsung_sound_handler_execute_clock_control_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gchar* samsung_sound_handler_real_repr (FsoFrameworkAbstractObject* base);
SamsungSoundHandler* samsung_sound_handler_new (void);
SamsungSoundHandler* samsung_sound_handler_construct (GType object_type);


static void samsung_sound_handler_mute_microphone_data_free (gpointer _data) {
	SamsungSoundHandlerMuteMicrophoneData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungSoundHandlerMuteMicrophoneData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void samsung_sound_handler_mute_microphone (SamsungSoundHandler* self, gboolean mute, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSoundHandlerMuteMicrophoneData* _data_;
	SamsungSoundHandler* _tmp0_;
	gboolean _tmp1_;
	_data_ = g_slice_new0 (SamsungSoundHandlerMuteMicrophoneData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sound_handler_mute_microphone);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sound_handler_mute_microphone_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = mute;
	_data_->mute = _tmp1_;
	samsung_sound_handler_mute_microphone_co (_data_);
}


void samsung_sound_handler_mute_microphone_finish (SamsungSoundHandler* self, GAsyncResult* _res_, GError** error) {
	SamsungSoundHandlerMuteMicrophoneData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void samsung_sound_handler_mute_microphone_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	SamsungSoundHandlerMuteMicrophoneData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_sound_handler_mute_microphone_co (_data_);
}


static gboolean samsung_sound_handler_mute_microphone_co (SamsungSoundHandlerMuteMicrophoneData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_theModem;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = fso_gsm_modem_channel (_data_->_tmp0_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp1_) ? ((SamsungIpcChannel*) _data_->_tmp1_) : NULL;
	_data_->response = NULL;
	_data_->_tmp3_ = _data_->mute;
	if (_data_->_tmp3_) {
		_data_->_tmp2_ = 0x1;
	} else {
		_data_->_tmp2_ = 0x0;
	}
	_data_->_tmp4_ = _data_->channel;
	_data_->_tmp5_ = _data_->_tmp2_;
	_data_->_tmp6_ = NULL;
	_data_->_tmp6_ = g_new0 (guint8, 1);
	_data_->_tmp6_[0] = (guint8) _data_->_tmp5_;
	_data_->_tmp7_ = _data_->_tmp6_;
	_data_->_tmp7__length1 = 1;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->_tmp4_, IPC_TYPE_SET, IPC_SND_MIC_MUTE_CTRL, _data_->_tmp7_, 1, 0, 5, samsung_sound_handler_mute_microphone_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp8_ = NULL;
	_data_->_tmp8_ = samsung_ipc_channel_enqueue_finish (_data_->_tmp4_, _data_->_res_);
	_data_->response = _data_->_tmp8_;
	_data_->_tmp7_ = (g_free (_data_->_tmp7_), NULL);
	_data_->_tmp9_ = _data_->response;
	_data_->_tmp10_ = (*_data_->_tmp9_).data;
	_data_->_tmp10__length1 = (*_data_->_tmp9_).length;
	_data_->gr = (struct ipc_gen_phone_res*) _data_->_tmp10_;
	_data_->_tmp11_ = _data_->gr;
	_data_->_tmp12_ = (*_data_->_tmp11_).code;
	if (((gint) _data_->_tmp12_) != 0x8000) {
		_data_->_tmp14_ = _data_->mute;
		if (_data_->_tmp14_) {
			_data_->_tmp13_ = "mute";
		} else {
			_data_->_tmp13_ = "unmute";
		}
		_data_->_tmp15_ = _data_->_tmp13_;
		_data_->_tmp16_ = NULL;
		_data_->_tmp16_ = g_strdup_printf ("We can't %s the microphone together with the modem!", _data_->_tmp15_);
		_data_->_tmp17_ = _data_->_tmp16_;
		_data_->_tmp18_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, _data_->_tmp17_);
		_data_->_tmp19_ = _data_->_tmp18_;
		_g_free0 (_data_->_tmp17_);
		_data_->_inner_error_ = _data_->_tmp19_;
		if (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->channel);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->channel);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void samsung_sound_handler_set_speaker_volume_data_free (gpointer _data) {
	SamsungSoundHandlerSetSpeakerVolumeData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungSoundHandlerSetSpeakerVolumeData, _data_);
}


void samsung_sound_handler_set_speaker_volume (SamsungSoundHandler* self, gint8 type, guint8 volume, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSoundHandlerSetSpeakerVolumeData* _data_;
	SamsungSoundHandler* _tmp0_;
	gint8 _tmp1_;
	guint8 _tmp2_;
	_data_ = g_slice_new0 (SamsungSoundHandlerSetSpeakerVolumeData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sound_handler_set_speaker_volume);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sound_handler_set_speaker_volume_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = type;
	_data_->type = _tmp1_;
	_tmp2_ = volume;
	_data_->volume = _tmp2_;
	samsung_sound_handler_set_speaker_volume_co (_data_);
}


void samsung_sound_handler_set_speaker_volume_finish (SamsungSoundHandler* self, GAsyncResult* _res_, GError** error) {
	SamsungSoundHandlerSetSpeakerVolumeData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static guint8* samsung_ipc_sound_speaker_volume_control_message_get_data (struct ipc_snd_spkr_volume_ctrl* self, int* result_length1) {
	guint8* result;
	guint8* res;
	gint res_length1;
	gint _res_size_;
	gint _tmp0_;
	guint8* _tmp1_;
	gint _tmp1__length1;
	guint8* _tmp2_;
	gint _tmp2__length1;
	g_return_val_if_fail (self != NULL, NULL);
	res = (guint8*) (&(*self));
	res_length1 = -1;
	_res_size_ = res_length1;
	res_length1 = (gint) sizeof (struct ipc_snd_spkr_volume_ctrl);
	_tmp0_ = res_length1;
	_tmp1_ = res;
	_tmp1__length1 = res_length1;
	_tmp2_ = _tmp1_;
	_tmp2__length1 = _tmp1__length1;
	if (result_length1) {
		*result_length1 = _tmp2__length1;
	}
	result = _tmp2_;
	return result;
}


static void samsung_sound_handler_set_speaker_volume_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	SamsungSoundHandlerSetSpeakerVolumeData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_sound_handler_set_speaker_volume_co (_data_);
}


static gboolean samsung_sound_handler_set_speaker_volume_co (SamsungSoundHandlerSetSpeakerVolumeData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_theModem;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = fso_gsm_modem_channel (_data_->_tmp0_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp1_) ? ((SamsungIpcChannel*) _data_->_tmp1_) : NULL;
	_data_->response = NULL;
	memset (&_data_->cmd, 0, sizeof (struct ipc_snd_spkr_volume_ctrl));
	_data_->_tmp2_ = _data_->type;
	_data_->cmd.type = _data_->_tmp2_;
	_data_->_tmp3_ = _data_->volume;
	_data_->cmd.volume = _data_->_tmp3_;
	_data_->_tmp4_ = _data_->channel;
	_data_->_tmp5_ = _data_->cmd;
	_data_->_tmp6_ = samsung_ipc_sound_speaker_volume_control_message_get_data (&_data_->_tmp5_, &_data_->_tmp6__length1);
	_data_->_tmp7_ = _data_->_tmp6_;
	_data_->_tmp7__length1 = _data_->_tmp6__length1;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->_tmp4_, IPC_TYPE_SET, IPC_SND_SPKR_VOLUME_CTRL, _data_->_tmp7_, _data_->_tmp7__length1, 0, 5, samsung_sound_handler_set_speaker_volume_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp8_ = NULL;
	_data_->_tmp8_ = samsung_ipc_channel_enqueue_finish (_data_->_tmp4_, _data_->_res_);
	_data_->response = _data_->_tmp8_;
	_data_->_tmp9_ = _data_->response;
	_data_->_tmp10_ = (*_data_->_tmp9_).data;
	_data_->_tmp10__length1 = (*_data_->_tmp9_).length;
	_data_->gr = (struct ipc_gen_phone_res*) _data_->_tmp10_;
	_data_->_tmp11_ = _data_->gr;
	_data_->_tmp12_ = (*_data_->_tmp11_).code;
	if (((gint) _data_->_tmp12_) != 0x8000) {
		_data_->_tmp13_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "Can't set speaker volume together with the modem!");
		_data_->_inner_error_ = _data_->_tmp13_;
		if (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->channel);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->channel);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void samsung_sound_handler_set_audio_path_data_free (gpointer _data) {
	SamsungSoundHandlerSetAudioPathData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungSoundHandlerSetAudioPathData, _data_);
}


void samsung_sound_handler_set_audio_path (SamsungSoundHandler* self, gint8 path, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSoundHandlerSetAudioPathData* _data_;
	SamsungSoundHandler* _tmp0_;
	gint8 _tmp1_;
	_data_ = g_slice_new0 (SamsungSoundHandlerSetAudioPathData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sound_handler_set_audio_path);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sound_handler_set_audio_path_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	_tmp1_ = path;
	_data_->path = _tmp1_;
	samsung_sound_handler_set_audio_path_co (_data_);
}


void samsung_sound_handler_set_audio_path_finish (SamsungSoundHandler* self, GAsyncResult* _res_, GError** error) {
	SamsungSoundHandlerSetAudioPathData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void samsung_sound_handler_set_audio_path_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	SamsungSoundHandlerSetAudioPathData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_sound_handler_set_audio_path_co (_data_);
}


static gboolean samsung_sound_handler_set_audio_path_co (SamsungSoundHandlerSetAudioPathData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_theModem;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = fso_gsm_modem_channel (_data_->_tmp0_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp1_) ? ((SamsungIpcChannel*) _data_->_tmp1_) : NULL;
	_data_->response = NULL;
	_data_->_tmp2_ = _data_->channel;
	_data_->_tmp3_ = _data_->path;
	_data_->_tmp4_ = NULL;
	_data_->_tmp4_ = g_new0 (guint8, 1);
	_data_->_tmp4_[0] = (guint8) _data_->_tmp3_;
	_data_->_tmp5_ = _data_->_tmp4_;
	_data_->_tmp5__length1 = 1;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->_tmp2_, IPC_TYPE_SET, IPC_SND_AUDIO_PATH_CTRL, _data_->_tmp5_, 1, 0, 5, samsung_sound_handler_set_audio_path_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp6_ = NULL;
	_data_->_tmp6_ = samsung_ipc_channel_enqueue_finish (_data_->_tmp2_, _data_->_res_);
	_data_->response = _data_->_tmp6_;
	_data_->_tmp5_ = (g_free (_data_->_tmp5_), NULL);
	_data_->_tmp7_ = _data_->response;
	_data_->_tmp8_ = (*_data_->_tmp7_).data;
	_data_->_tmp8__length1 = (*_data_->_tmp7_).length;
	_data_->gr = (struct ipc_gen_phone_res*) _data_->_tmp8_;
	_data_->_tmp9_ = _data_->gr;
	_data_->_tmp10_ = (*_data_->_tmp9_).code;
	if (((gint) _data_->_tmp10_) != 0x8000) {
		_data_->_tmp11_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "Can't set correct audio path together with the modem!");
		_data_->_inner_error_ = _data_->_tmp11_;
		if (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->channel);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->channel);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void samsung_sound_handler_execute_clock_control_data_free (gpointer _data) {
	SamsungSoundHandlerExecuteClockControlData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (SamsungSoundHandlerExecuteClockControlData, _data_);
}


void samsung_sound_handler_execute_clock_control (SamsungSoundHandler* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SamsungSoundHandlerExecuteClockControlData* _data_;
	SamsungSoundHandler* _tmp0_;
	_data_ = g_slice_new0 (SamsungSoundHandlerExecuteClockControlData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, samsung_sound_handler_execute_clock_control);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, samsung_sound_handler_execute_clock_control_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	samsung_sound_handler_execute_clock_control_co (_data_);
}


void samsung_sound_handler_execute_clock_control_finish (SamsungSoundHandler* self, GAsyncResult* _res_, GError** error) {
	SamsungSoundHandlerExecuteClockControlData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void samsung_sound_handler_execute_clock_control_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	SamsungSoundHandlerExecuteClockControlData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	samsung_sound_handler_execute_clock_control_co (_data_);
}


static gboolean samsung_sound_handler_execute_clock_control_co (SamsungSoundHandlerExecuteClockControlData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = fso_gsm_theModem;
	_data_->_tmp1_ = NULL;
	_data_->_tmp1_ = fso_gsm_modem_channel (_data_->_tmp0_, "main");
	_data_->channel = SAMSUNG_IS_IPC_CHANNEL (_data_->_tmp1_) ? ((SamsungIpcChannel*) _data_->_tmp1_) : NULL;
	_data_->response = NULL;
	_data_->_tmp2_ = _data_->channel;
	_data_->_tmp3_ = NULL;
	_data_->_tmp3_ = g_new0 (guint8, 1);
	_data_->_tmp3_[0] = (guint8) 0x1;
	_data_->_tmp4_ = _data_->_tmp3_;
	_data_->_tmp4__length1 = 1;
	_data_->_state_ = 1;
	samsung_ipc_channel_enqueue_async (_data_->_tmp2_, IPC_TYPE_EXEC, IPC_SND_CLOCK_CTRL, _data_->_tmp4_, 1, 0, 5, samsung_sound_handler_execute_clock_control_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp5_ = NULL;
	_data_->_tmp5_ = samsung_ipc_channel_enqueue_finish (_data_->_tmp2_, _data_->_res_);
	_data_->response = _data_->_tmp5_;
	_data_->_tmp4_ = (g_free (_data_->_tmp4_), NULL);
	_data_->_tmp6_ = _data_->response;
	_data_->_tmp7_ = (*_data_->_tmp6_).data;
	_data_->_tmp7__length1 = (*_data_->_tmp6_).length;
	_data_->gr = (struct ipc_gen_phone_res*) _data_->_tmp7_;
	_data_->_tmp8_ = _data_->gr;
	_data_->_tmp9_ = (*_data_->_tmp8_).code;
	if (((gint) _data_->_tmp9_) != 0x8000) {
		_data_->_tmp10_ = g_error_new_literal (FREE_SMARTPHONE_ERROR, FREE_SMARTPHONE_ERROR_INTERNAL_ERROR, "Can't excute sound control on baseband side!");
		_data_->_inner_error_ = _data_->_tmp10_;
		if (_data_->_inner_error_->domain == FREE_SMARTPHONE_ERROR) {
			g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
			g_error_free (_data_->_inner_error_);
			_g_object_unref0 (_data_->channel);
			if (_data_->_state_ == 0) {
				g_simple_async_result_complete_in_idle (_data_->_async_result);
			} else {
				g_simple_async_result_complete (_data_->_async_result);
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		} else {
			_g_object_unref0 (_data_->channel);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	}
	_g_object_unref0 (_data_->channel);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static gchar* samsung_sound_handler_real_repr (FsoFrameworkAbstractObject* base) {
	SamsungSoundHandler * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (SamsungSoundHandler*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


SamsungSoundHandler* samsung_sound_handler_construct (GType object_type) {
	SamsungSoundHandler * self = NULL;
	self = (SamsungSoundHandler*) fso_framework_abstract_object_construct (object_type);
	return self;
}


SamsungSoundHandler* samsung_sound_handler_new (void) {
	return samsung_sound_handler_construct (SAMSUNG_TYPE_SOUND_HANDLER);
}


static void samsung_sound_handler_class_init (SamsungSoundHandlerClass * klass) {
	samsung_sound_handler_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = samsung_sound_handler_real_repr;
}


static void samsung_sound_handler_instance_init (SamsungSoundHandler * self) {
}


GType samsung_sound_handler_get_type (void) {
	return samsung_sound_handler_type_id;
}


GType samsung_sound_handler_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SamsungSoundHandlerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) samsung_sound_handler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SamsungSoundHandler), 0, (GInstanceInitFunc) samsung_sound_handler_instance_init, NULL };
	samsung_sound_handler_type_id = g_type_module_register_type (module, FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, "SamsungSoundHandler", &g_define_type_info, 0);
	return samsung_sound_handler_type_id;
}



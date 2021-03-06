/*
 * lingot, a musical instrument tuner.
 *
 * Copyright (C) 2004-2013  Ibán Cereijo Graña.
 * Copyright (C) 2004-2008  Jairo Chapela Martínez.

 *
 * This file is part of lingot.
 *
 * lingot is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * lingot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with lingot; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LINGOT_AUDIO_OSS_H__
#define __LINGOT_AUDIO_OSS_H__

#include "lingot-audio.h"

LingotAudioHandler* lingot_audio_oss_new(char* device, int sample_rate);
void lingot_audio_oss_destroy(LingotAudioHandler*);
int lingot_audio_oss_read(LingotAudioHandler*);
LingotAudioSystemProperties* lingot_audio_oss_get_audio_system_properties(
		audio_system_t);

#endif

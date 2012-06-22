/*
Copyright (C) 2012  noname120

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#define USE_GIF_SIZES

#define GIF_FRAME_MAX (120 * 64 * 4)
#define SCRXSIZE 96
#define SCRYSIZE 64

#define GIF_IDLE 0
#define GIF_START 1
#define GIF_FRAME 2
#define GIF_END 3

#ifdef WINVER
#include "gui.h"
#else
#include "coretypes.h"
#endif

extern int gif_write_state;
extern int gif_file_size;
extern TCHAR gif_file_name[256];
extern BOOL gif_autosave;
extern BOOL gif_use_increasing;
extern WORD gif_base_delay;
extern int gif_xs;
extern int gif_indiv_xs;
extern int gif_ys;
extern BYTE gif_frame[GIF_FRAME_MAX];
extern int gif_time;
extern int gif_newframe;
extern int gif_colors;
extern int gif_base_delay_start;
extern int gif_file_num;
extern u_int gif_size;
extern BOOL gif_bw;

void gif_writer(int shades);

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

#ifndef SOUND_H
#define SOUND_H

#include "core.h"

#define	SampleRate		(48000)
#define Channels		(2)
#define SampleSize		(1)
#define PreferedSamples	(4096)
#define BufferBanks		(4)


#define BankTime		(((float)PreferedSamples)/((float)SampleRate))
#define SampleLength	((1.0f)/((float)SampleRate))
#define SampleSizeBits	(SampleSize<<3)
#define BankSize		(PreferedSamples*Channels*SampleSize)

#define BufferSamples	(SampleRate)
#define BufferSize		(BufferSamples*Channels*SampleSize)


typedef struct SAMPLE SAMPLE_t;

#pragma pack(1)
struct SAMPLE {
	unsigned char left;
	unsigned char right;
};

#pragma pack()


typedef struct {
	int init;
	int enabled;
	volatile int endsnd;
	HWAVEOUT hWaveOut;
	WAVEFORMATEX wfx;

	WAVEHDR waveheader[BufferBanks];
	SAMPLE_t playbuf[BufferBanks][PreferedSamples];


	SAMPLE_t buffer[BufferSamples];

	int CurPnt;
	int PlayPnt;
	
	double PlayTime;
	double LastSample;
	
	int LeftOn;
	double LastFlipLeft;
	double HighLengLeft;
	
	int RightOn;
	double LastFlipRight;
	double HighLengRight;
	
	double volume;
	timerc *timer_c;

} AUDIO_t;


int soundinit(void *);
int playsound(AUDIO_t *);
int pausesound(AUDIO_t *);
void togglesound(AUDIO_t *);
int FlippedLeft(CPU_t *, int );
int FlippedRight(CPU_t *, int );
int nextsample(CPU_t *);
void KillSound(AUDIO_t *);

#endif

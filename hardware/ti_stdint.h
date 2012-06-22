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

#ifndef STDINT_H
#define STDINT_H

#include "coretypes.h"

typedef struct STDINT {
	unsigned char intactive;
	double lastchk1;
	double timermax1;
	double lastchk2;
	double timermax2;
	double freq[4];
	int mem;
	int xy;	
	BOOL on_backup;
	BOOL on_latch;
} STDINT_t;




#endif

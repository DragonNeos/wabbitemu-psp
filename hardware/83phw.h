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

#ifndef TI83PHW_H
#define TI83PHW_H
#include "core.h"
#include "ti_stdint.h"

#ifndef LINK_READ
#define LINK_READ
#define LinkRead (((cpu->pio.link->host & 0x03) | (cpu->pio.link->client[0] & 0x03)) ^ 3)
#endif
#define NumElm(array) (sizeof (array) / sizeof ((array)[0]))

int device_init_83p(CPU_t*);
int memory_init_83p(memc *);

void flashwrite83p(CPU_t *, unsigned short , unsigned char );

#endif 

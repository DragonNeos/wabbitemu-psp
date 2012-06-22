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

#ifndef TI83HW_H
#define TI83HW_H
#include "core.h"
#include "ti_stdint.h"

#define PAGE_SIZE 16384


#define NumElm(array) (sizeof (array) / sizeof ((array)[0]))



STDINT_t* INT83_init(CPU_t*);
int device_init_83(CPU_t*,int);
int memory_init_83(memc *);

void port0_83(CPU_t *, device_t *);
void port2_83(CPU_t *, device_t *);
void port3_83(CPU_t *, device_t *);
void port4_83(CPU_t *, device_t *);
void port6_83(CPU_t *, device_t *);
void port7_83(CPU_t *, device_t *);
void port14_83(CPU_t *, device_t *);


#endif 

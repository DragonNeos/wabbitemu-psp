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

#ifndef TI81HW_H
#define TI81HW_H
#include "core.h"
#include "ti_stdint.h"


#define NumElm(array) (sizeof (array) / sizeof ((array)[0]))


static void port10(CPU_t *cpu, device_t *dev);
int device_init_81(CPU_t*);
int memory_init_81(memc *);

#endif 

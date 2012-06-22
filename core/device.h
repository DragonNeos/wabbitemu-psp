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

#ifndef DEVICE_H
#define DEVICE_H
#include "core.h"

#define DEV_INDEX(zdev) (zdev - cpu->pio.devices)

int device_output(CPU_t *, unsigned char);
int device_input(CPU_t *, unsigned char);
int device_control(CPU_t *cpu, unsigned char dev);
void Append_interrupt_device(CPU_t *, int, int);
void Modify_interrupt_device(CPU_t *, int, int);
void ClearDevices(CPU_t*);
#endif

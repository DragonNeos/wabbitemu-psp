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

#include "device.h"

#ifdef DEBUG
void console_output(CPU_t *cpu, device_t *dev) {
	if (cpu->output) {
		printf("output byte: %d\n",cpu->bus);
		cpu->output = FALSE;
	}
}
#endif

void ClearDevices(CPU_t* cpu) {
	int i;
	for (i = 0; i < 256; i++) {
		cpu->pio.devices[i].active = FALSE;
		cpu->pio.interrupt[i] = -1;
		cpu->pio.skip_factor[i] = 1;
		cpu->pio.skip_count[i] = 0;
	}
}

int device_output(CPU_t *cpu, unsigned char dev) {
	if (cpu->pio.devices[dev].active) {
		cpu->output = TRUE;
		cpu->pio.devices[dev].code(cpu, &(cpu->pio.devices[dev]));
		if (cpu->output) {
			/* Device is not responding */
			cpu->output = FALSE;
			return 1;
		}
	}/* else if (dev == 0xFF) {
//		if (isprint(cpu->bus) || cpu->bus=='\r' || cpu->bus=='\n' ) {
			fputc(cpu->bus,stdout);
//		}
	}*/
	return 0;
}

int device_input(CPU_t *cpu, unsigned char dev) {
	if (cpu->pio.devices[dev].active) {
		cpu->input = TRUE;
		cpu->pio.devices[dev].code(cpu, &(cpu->pio.devices[dev]));
		if (cpu->input) {
			/* Device is not responding */
			cpu->input = FALSE;
			cpu->bus = 0xFF;
			return 1;
		}
	} else  {
		cpu->bus = 0xFF;
	//	printf("in port %02X not active\n",dev);
		return 1;
	}
	return 0;
}

void Append_interrupt_device(CPU_t *cpu, int port, int skip) {
	int i;
	for(i=0;i<256;i++) {
		if (cpu->pio.interrupt[i] == -1) {
			cpu->pio.interrupt[i] = port;
			if ( skip > 0 ) cpu->pio.skip_factor[i] = skip;
			else cpu->pio.skip_factor[i] = 0;
			break;
		}
	}
}

void Modify_interrupt_device(CPU_t *cpu, int port, int skip) {
	int i;
	for(i=0;i<256;i++) {
		if (cpu->pio.interrupt[i] == port) {
			if ( skip > 0 ) cpu->pio.skip_factor[i] = skip;
			else cpu->pio.skip_factor[i] = 0;
			break;
		} else if (cpu->pio.interrupt[i] == -1) break;
	}
}

int device_control(CPU_t *cpu, unsigned char dev) {
	if (cpu->pio.devices[dev].active) {
		cpu->pio.devices[dev].code(cpu, &(cpu->pio.devices[dev]));
	}
	return 0;
}


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

#ifndef _LABEL_H_TYPES
#define _LABEL_H_TYPES
#include "coretypes.h"

typedef struct {
    TCHAR *name;
    BOOL IsRAM;
    uint8_t page;
    uint16_t addr;
} label_struct;

#endif

#ifndef _LABEL_H_PROTOTYPES

#include "calc.h"

#ifdef _HAS_CALC_H
#define _LABEL_H_PROTOTYPES
TCHAR* FindAddressLabel(LPCALC lpCalc, waddr_t waddr);
//void ImportBcalls(char* fn);
TCHAR* FindBcall(int address);
void FindFlags(int flag, int bit, TCHAR **flagstring, TCHAR **bitstring);

void VoidLabels(LPCALC lpCalc);
label_struct *lookup_label(LPCALC lpCalc, TCHAR *label);
int labels_app_load(LPCALC lpCalc, LPCTSTR lpszFileName);
#endif

#endif


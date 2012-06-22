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

#ifndef PRINT_H
#define PRINT_H

#include "disassemble.h"
#include "calc.h"
#include "dbcommon.h"

void MyDrawText(LPCALC, HDC, RECT *, Z80_info_t *, ViewType, const TCHAR *, ...);
TCHAR* mysprintf(LPCALC, Z80_info_t *, ViewType, const TCHAR *, ...);

#define DBCOLOR_BASE (RGB(4, 72, 117))
//#define DBCOLOR_HILIGHT (RGB(112, 169, 168))
#define DBCOLOR_HILIGHT (RGB(108, 173, 101))
#define DBCOLOR_CONDITION (RGB(40, 160, 180))

#endif

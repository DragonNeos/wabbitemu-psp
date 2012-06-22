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

#ifndef EXPORTVAR_H
#define EXPORTVAR_H

#include "link.h"

typedef struct {
	FILE* stream;
	unsigned int pnt;
	unsigned int size;
	unsigned char *data;
	unsigned char *name;
	BOOL read;
	BOOL write;
	BOOL bin;
	int eof;
} MFILE;

MFILE *ExportVar(LPCALC, TCHAR *, symbol83P_t *);
MFILE *ExportApp(LPCALC, TCHAR *, apphdr_t *);
MFILE *ExportRom(TCHAR *lpszFile, LPCALC lpCalc);
MFILE * ExportOS(TCHAR *lpszFile, unsigned char *buffer, int size);
MFILE *mopen(const TCHAR *filename, const TCHAR *mode);
int mclose(MFILE *);
int meof(MFILE *);
int mgetc(MFILE *);
int mputc(int, MFILE *);
int msize(MFILE *);

#endif

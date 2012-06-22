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

#ifndef FILEUTILITIES_H
#define FILEUTILITIES_H

int BrowseFile(TCHAR *lpstrFile, const TCHAR *lpstrFilter, const TCHAR *lpstrTitle, const TCHAR *lpstrDefExt, unsigned int flags = 0);
int SaveFile(TCHAR *lpstrFile, const TCHAR *lpstrFilter, const TCHAR *lpstrTitle, const TCHAR *lpstrDefExt, unsigned int flags = 0, unsigned int filterIndex = 0);
BOOL ValidPath(TCHAR *lpstrFile);

#endif	//FILEUTILITIES_H

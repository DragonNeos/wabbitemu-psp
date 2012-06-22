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

#ifndef EXPANDPANE_H
#define EXPANDPANE_H

LRESULT CALLBACK ExpandPaneProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
HWND CreateExpandPane(HWND hwndParent, TCHAR *name, HWND contents);
//int GetExpandedPanesHeight(void);

typedef struct {
	int total;
	BOOL state[32];
} ep_state;

#define g_szExpandPane	_T("wabexppane")

void GetExpandPaneState(ep_state *);
void SetExpandPaneState(const ep_state *);
void ArrangeExpandPanes(void);
int GetExpandPanesHeight(void);
void DrawExpandPanes(void);

#define WM_SHIFT (WM_USER) //wParam = position to move to

#endif /*EXPANDPANE_H_*/

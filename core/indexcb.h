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

#include "core.h"
#include "alu.h"
#include "control.h"

void bit_ind(CPU_t*, char);
void res_ind(CPU_t*, char);
void set_ind(CPU_t*, char);

void rr_ind(CPU_t*, char);
void rrc_ind(CPU_t*, char);
void rl_ind(CPU_t*, char);
void rlc_ind(CPU_t*, char);

void srl_ind(CPU_t*, char);
void sll_ind(CPU_t*, char);

void sra_ind(CPU_t*, char);
void sla_ind(CPU_t*, char);

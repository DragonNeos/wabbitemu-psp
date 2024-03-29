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

static void CPU_CB_opcode_run(CPU_t*);
static void CPU_ED_opcode_run(CPU_t*);

/* This will all compress quite well, through UPX */

// Opcode table
static opcodep opcode[256] = {
	&nop,				//0
	&ld_bc_num16,
	&ld_bc_a,
	&inc_reg16,
	&inc_reg8,
	&dec_reg8,
	&ld_r_num8,
	&rlca,
	
	&ex_af_afp,
	&add_hl_reg16,
	&ld_a_bc,
	&dec_reg16,
	&inc_reg8,
	&dec_reg8,
	&ld_r_num8,
	&rrca,
	
	&djnz,				//10
	&ld_de_num16,
	&ld_de_a,
	&inc_reg16,
	&inc_reg8,
	&dec_reg8,
	&ld_r_num8,
	&rla,
	
	&jr,
	&add_hl_reg16,
	&ld_a_de,
	&dec_reg16,
	&inc_reg8,
	&dec_reg8,
	&ld_r_num8,
	&rra,
	
	&jr_condition,		//20
	&ld_hl_num16,
	&ld_mem16_hlf,
	&inc_reg16,
	&inc_reg8,
	&dec_reg8,
	&ld_r_num8,
	&daa,
	
	&jr_condition,
	&add_hl_reg16,
	&ld_hlf_mem16,
	&dec_reg16,
	&inc_reg8,
	&dec_reg8,
	&ld_r_num8,
	&cpl,
	
	&jr_condition,		//30
	&ld_sp_num16,
	&ld_mem16_a,
	&inc_reg16,
	&inc_reg8,
	&dec_reg8,
	&ld_r_num8,
	&scf,
	
	&jr_condition,
	&add_hl_reg16,
	&ld_a_mem16,
	&dec_reg16,
	&inc_reg8,
	&dec_reg8,
	&ld_r_num8,
	&ccf,
	
	&ld_r_r,		//40
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	
	&ld_r_r,		//50
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	
	&ld_r_r,		//60
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	
	&ld_r_r,		//70
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&halt,
	&ld_r_r,
	
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	&ld_r_r,
	
	&add_a_reg8,	//80
	&add_a_reg8,
	&add_a_reg8,
	&add_a_reg8,
	&add_a_reg8,
	&add_a_reg8,
	&add_a_reg8,
	&add_a_reg8,
	
	&adc_a_reg8,
	&adc_a_reg8,
	&adc_a_reg8,
	&adc_a_reg8,
	&adc_a_reg8,
	&adc_a_reg8,
	&adc_a_reg8,
	&adc_a_reg8,
	
	&sub_a_reg8,		//90
	&sub_a_reg8,
	&sub_a_reg8,
	&sub_a_reg8,
	&sub_a_reg8,
	&sub_a_reg8,
	&sub_a_reg8,
	&sub_a_reg8,
	
	&sbc_a_reg8,
	&sbc_a_reg8,
	&sbc_a_reg8,
	&sbc_a_reg8,
	&sbc_a_reg8,
	&sbc_a_reg8,
	&sbc_a_reg8,
	&sbc_a_reg8,
	
	&and_reg8,		//a0
	&and_reg8,
	&and_reg8,
	&and_reg8,
	&and_reg8,
	&and_reg8,
	&and_reg8,
	&and_reg8,
	
	&xor_reg8,
	&xor_reg8,
	&xor_reg8,
	&xor_reg8,
	&xor_reg8,
	&xor_reg8,
	&xor_reg8,
	&xor_reg8,
	
	&or_reg8,		//b0
	&or_reg8,
	&or_reg8,
	&or_reg8,
	&or_reg8,
	&or_reg8,
	&or_reg8,
	&or_reg8,
	
	&cp_reg8,
	&cp_reg8,
	&cp_reg8,
	&cp_reg8,
	&cp_reg8,
	&cp_reg8,
	&cp_reg8,
	&cp_reg8,

	&ret_condition,		//c0
	&pop_reg16,
	&jp_condition,
	&jp,
	&call_condition,
	&push_reg16,
	&add_a_num8,
	&rst,
	
	&ret_condition,
	&ret,
	&jp_condition,
	&CPU_CB_opcode_run,
	&call_condition,
	&call,
	&adc_a_num8,
	&rst,
	
	&ret_condition,		//d0
	&pop_reg16,
	&jp_condition,
	&out,
	&call_condition,
	&push_reg16,
	&sub_a_num8,
	&rst,
	
	&ret_condition,
	&exx,
	&jp_condition,
	&in,
	&call_condition,
	&ednop,				//DD prefix
	&sbc_a_num8,
	&rst,
	
	&ret_condition,		//e0
	&pop_reg16,
	&jp_condition,
	&ex_sp_hl,
	&call_condition,
	&push_reg16,
	&and_num8,
	&rst,
	
	&ret_condition,
	&jp_hl,
	&jp_condition,
	&ex_de_hl,
	&call_condition,
	&CPU_ED_opcode_run,
	&xor_num8,
	&rst,
	
	&ret_condition,		//f0
	&pop_reg16,
	&jp_condition,
	&di,
	&call_condition,
	&push_reg16,
	&or_num8,
	&rst,
	
	&ret_condition,
	&ld_sp_hl,
	&jp_condition,
	&ei,
	&call_condition,
	&ednop,				//FD prefix
	&cp_num8,
	&rst
};
	



//CB opcodes
static opcodep CBtab[256] = {
	&rlc_reg,			//00
	&rlc_reg,
	&rlc_reg,
	&rlc_reg,
	&rlc_reg,
	&rlc_reg,
	&rlc_reg,
	&rlc_reg,

	&rrc_reg,
	&rrc_reg,
	&rrc_reg,
	&rrc_reg,
	&rrc_reg,
	&rrc_reg,
	&rrc_reg,
	&rrc_reg,

	&rl_reg,			//10
	&rl_reg,
	&rl_reg,
	&rl_reg,
	&rl_reg,
	&rl_reg,
	&rl_reg,
	&rl_reg,
	
	&rr_reg,
	&rr_reg,
	&rr_reg,
	&rr_reg,
	&rr_reg,
	&rr_reg,
	&rr_reg,
	&rr_reg,
	
	&sla_reg,		//20
	&sla_reg,
	&sla_reg,
	&sla_reg,
	&sla_reg,
	&sla_reg,
	&sla_reg,
	&sla_reg,
	
	&sra_reg,
	&sra_reg,
	&sra_reg,
	&sra_reg,
	&sra_reg,
	&sra_reg,
	&sra_reg,
	&sra_reg,
	
	&sll_reg,		//30
	&sll_reg,
	&sll_reg,
	&sll_reg,
	&sll_reg,
	&sll_reg,
	&sll_reg,
	&sll_reg,
	
	&srl_reg,
	&srl_reg,
	&srl_reg,
	&srl_reg,
	&srl_reg,
	&srl_reg,
	&srl_reg,
	&srl_reg,
	
	&bit,			//40
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,

	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,

	&bit,			//50
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,

	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,

	&bit,			//60
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,

	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,

	&bit,			//70
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,

	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,
	&bit,

	&res,			//80
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,

	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,

	&res,			//90
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,

	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,

	&res,			//a0
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,

	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,

	&res,			//b0
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,

	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,
	&res,

	&set,			//c0
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,

	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,

	&set,			//d0
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,

	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,

	&set,			//e0
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,

	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,

	&set,			//f0
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,

	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set,
	&set
};




// index register cb opcodes
static index_opcodep ICB_opcode[256] = {
	&rlc_ind,			//00
	&rlc_ind,
	&rlc_ind,
	&rlc_ind,
	&rlc_ind,
	&rlc_ind,
	&rlc_ind,
	&rlc_ind,

	&rrc_ind,
	&rrc_ind,
	&rrc_ind,
	&rrc_ind,
	&rrc_ind,
	&rrc_ind,
	&rrc_ind,
	&rrc_ind,

	&rl_ind,			//10
	&rl_ind,
	&rl_ind,
	&rl_ind,
	&rl_ind,
	&rl_ind,
	&rl_ind,
	&rl_ind,
	
	&rr_ind,
	&rr_ind,
	&rr_ind,
	&rr_ind,
	&rr_ind,
	&rr_ind,
	&rr_ind,
	&rr_ind,
	
	&sla_ind,		//20
	&sla_ind,
	&sla_ind,
	&sla_ind,
	&sla_ind,
	&sla_ind,
	&sla_ind,
	&sla_ind,
	
	&sra_ind,
	&sra_ind,
	&sra_ind,
	&sra_ind,
	&sra_ind,
	&sra_ind,
	&sra_ind,
	&sra_ind,
	
	&sll_ind,		//30
	&sll_ind,
	&sll_ind,
	&sll_ind,
	&sll_ind,
	&sll_ind,
	&sll_ind,
	&sll_ind,
	
	&srl_ind,
	&srl_ind,
	&srl_ind,
	&srl_ind,
	&srl_ind,
	&srl_ind,
	&srl_ind,
	&srl_ind,
	
	&bit_ind,			//40
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,

	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,

	&bit_ind,			//50
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,

	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,

	&bit_ind,			//60
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,

	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,

	&bit_ind,			//70
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,

	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,
	&bit_ind,

	&res_ind,			//80
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,

	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,

	&res_ind,			//90
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,

	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,

	&res_ind,			//a0
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,

	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,

	&res_ind,			//b0
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,

	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,
	&res_ind,

	&set_ind,			//c0
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,

	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,

	&set_ind,			//d0
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,

	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,

	&set_ind,			//e0
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,

	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,

	&set_ind,			//f0
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,

	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind,
	&set_ind
};




//ED opcodes
/*  According Sean McLaughlin's 28day's 
	the majority of ED prefixed opcodes 
	are nops...
	*/
static opcodep EDtab[256] = {
	&ednop,				//00
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,

	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,				//10
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,				//20
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,

	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,				//30
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&in_reg_c,			//40
	&out_reg,
	&sbc_hl_reg16,
	&ld_mem16_reg16,
	&neg,
	&retn,
	&IM0,
	&ld_i_a,

	&in_reg_c,
	&out_reg,
	&adc_hl_reg16,
	&ld_reg16_mem16,
	&neg,
	&reti,
	&IM0,
	&ld_r_a,
	
	&in_reg_c,			//50
	&out_reg,
	&sbc_hl_reg16,
	&ld_mem16_reg16,
	&neg,
	&retn,
	&IM1,
	&ld_a_i,

	&in_reg_c,
	&out_reg,
	&adc_hl_reg16,
	&ld_reg16_mem16,
	&neg,
	&reti,
	&IM2,
	&ld_a_r,
	
	&in_reg_c,			//60
	&out_reg,
	&sbc_hl_reg16,
	&ld_mem16_reg16,
	&neg,
	&retn,
	&IM0,
	&rrd,

	&in_reg_c,
	&out_reg,
	&adc_hl_reg16,
	&ld_reg16_mem16,
	&neg,
	&reti,
	&IM0,
	&rld,
	
	&in_reg_c,			//70
	&out_reg,
	&sbc_hl_reg16,
	&ld_mem16_reg16,
	&neg,
	&retn,
	&IM1,
	&ednop,

	&in_reg_c,
	&out_reg,
	&adc_hl_reg16,
	&ld_reg16_mem16,
	&neg,
	&reti,
	&IM2,
	&ednop,
	
	&ednop,				//80
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,

	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,				//90
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
		

	&ldi,				//a0
	&cpi,
	&ini,
	&outi,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ldd,
	&cpd,
	&ind,
	&outd,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ldir,				//b0
	&cpir,
	&inir,
	&otir,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&lddr,
	&cpdr,
	&indr,
	&otdr,
	&ednop,
	&ednop,
	&ednop,
	&ednop,

	&ednop,				//c0
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,

	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,				//d0
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,				//e0
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,

	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,				//f0
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop,
	&ednop
};


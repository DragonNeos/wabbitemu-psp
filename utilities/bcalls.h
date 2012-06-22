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


typedef struct {
	TCHAR name[32];
	int address;
} bcall_t;


bcall_t bcalls[] = {
 { _T("_JErrorNo") , 0x4000 }, 
 { _T("_FontHook") , 0x4003 }, 
 { _T("_LocalizeHook") , 0x4006 }, 
 { _T("_LdHLInd") , 0x4009 }, 
 { _T("_LdHLInd") , 0x4009 }, 
 { _T("_CpHLDE") , 0x400C }, 
 { _T("_DivHLBy10") , 0x400F }, 
 { _T("_DivHLByA") , 0x4012 }, 
 { _T("_KbdScan") , 0x4015 }, 
 { _T("_GetCSC") , 0x4018 }, 
 { _T("_coorMon") , 0x401B }, 
 { _T("_Mon") , 0x401E }, 
 { _T("_MonForceKey") , 0x4021 }, 
 { _T("_JForceCmdNoChar") , 0x4027 }, 
 { _T("_JForceCmd") , 0x402A },
 { _T("_NewContext0") , 0x4033 }, 
 { _T("_PutAway") , 0x4039 }, 
 { _T("_callMain") , 0x4045 }, 
 { _T("_AppInit") , 0x404B }, 
 { _T("_LCD_BUSY") , 0x4051 }, 
 { _T("_Min") , 0x4054 }, 
 { _T("_Max") , 0x4057 }, 
 { _T("_AbsO1PAbsO2") , 0x405A }, 
 { _T("_Intgr") , 0x405D }, 
 { _T("_Trunc") , 0x4060 }, 
 { _T("_InvSub") , 0x4063 }, 
 { _T("_Times2") , 0x4066 }, 
 { _T("_Plus1") , 0x4069 }, 
 { _T("_Minus1") , 0x406C }, 
 { _T("_FPSub") , 0x406F }, 
 { _T("_FPAdd") , 0x4072 }, 
 { _T("_DToR") , 0x4075 }, 
 { _T("_RToD") , 0x4078 }, 
 { _T("_Cube") , 0x407B }, 
 { _T("_TimesPt5") , 0x407E }, 
 { _T("_FPSquare") , 0x4081 }, 
 { _T("_FPMult") , 0x4084 }, 
 { _T("_LJRND") , 0x4087 }, 
 { _T("_InvOP1SC") , 0x408A }, 
 { _T("_InvOP1S") , 0x408D }, 
 { _T("_InvOP2S") , 0x4090 }, 
 { _T("_Frac") , 0x4093 }, 
 { _T("_FPRecip") , 0x4096 }, 
 { _T("_FPDiv") , 0x4099 }, 
 { _T("_SqRoot") , 0x409C }, 
 { _T("_RndGuard") , 0x409F }, 
 { _T("_RnFx") , 0x40A2 }, 
 { _T("_Int") , 0x40A5 }, 
 { _T("_Round") , 0x40A8 }, 
 { _T("_LnX") , 0x40AB }, 
 { _T("_LogX") , 0x40AE }, 
 { _T("_LJNORND") , 0x40B1 }, 
 { _T("_EToX") , 0x40B4 }, 
 { _T("_TenX") , 0x40B7 }, 
 { _T("_SinCosRad") , 0x40BA }, 
 { _T("_Sin") , 0x40BD }, 
 { _T("_Cos") , 0x40C0 }, 
 { _T("_Tan") , 0x40C3 }, 
 { _T("_SinHCosH") , 0x40C6 }, 
 { _T("_TanH") , 0x40C9 }, 
 { _T("_CosH") , 0x40CC }, 
 { _T("_SinH") , 0x40CF }, 
 { _T("_ACosRad") , 0x40D2 }, 
 { _T("_ATanRad") , 0x40D5 }, 
 { _T("_ATan2Rad") , 0x40D8 }, 
 { _T("_ASinRad") , 0x40DB }, 
 { _T("_ACos") , 0x40DE }, 
 { _T("_ATan") , 0x40E1 }, 
 { _T("_ASin") , 0x40E4 }, 
 { _T("_ATan2") , 0x40E7 }, 
 { _T("_ATanH") , 0x40EA }, 
 { _T("_ASinH") , 0x40ED }, 
 { _T("_ACosH") , 0x40F0 }, 
 { _T("_PToR") , 0x40F3 }, 
 { _T("_RToP") , 0x40F6 }, 
 { _T("_HLTimes9") , 0x40F9 }, 
 { _T("_CkOP1Cplx") , 0x40FC }, 
 { _T("_CkOP1Real") , 0x40FF }, 
 { _T("_Angle") , 0x4102 }, 
 { _T("_COP1Set0") , 0x4105 }, 
 { _T("_CpOP4OP3") , 0x4108 }, 
 { _T("_Mov9OP2Cp") , 0x410B }, 
 { _T("_AbsO1O2Cp") , 0x410E }, 
 { _T("_CpOP1OP2") , 0x4111 }, 
 { _T("_OP3ToOP4") , 0x4114 }, 
 { _T("_OP1ToOP4") , 0x4117 }, 
 { _T("_OP2ToOP4") , 0x411A }, 
 { _T("_OP4ToOP2") , 0x411D }, 
 { _T("_OP3ToOP2") , 0x4120 }, 
 { _T("_OP1ToOP3") , 0x4123 }, 
 { _T("_OP5ToOP2") , 0x4126 }, 
 { _T("_OP5ToOP6") , 0x4129 }, 
 { _T("_OP5ToOP4") , 0x412C }, 
 { _T("_OP1ToOP2") , 0x412F }, 
 { _T("_OP6ToOP2") , 0x4132 }, 
 { _T("_OP6ToOP1") , 0x4135 }, 
 { _T("_OP4ToOP1") , 0x4138 }, 
 { _T("_OP5ToOP1") , 0x413B }, 
 { _T("_OP3ToOP1") , 0x413E }, 
 { _T("_OP6ToOP5") , 0x4141 }, 
 { _T("_OP4ToOP5") , 0x4144 }, 
 { _T("_OP3ToOP5") , 0x4147 }, 
 { _T("_OP2ToOP5") , 0x414A }, 
 { _T("_OP2ToOP6") , 0x414D }, 
 { _T("_OP1ToOP6") , 0x4150 }, 
 { _T("_OP1ToOP5") , 0x4153 }, 
 { _T("_OP2ToOP1") , 0x4156 }, 
 { _T("_Mov11B") , 0x4159 }, 
 { _T("_Mov10B") , 0x415C }, 
 { _T("_Mov9B") , 0x415F }, 
 { _T("_Mov8B") , 0x4165 }, 
 { _T("_Mov7B") , 0x4168 }, 
 { _T("_OP2ToOP3") , 0x416E }, 
 { _T("_OP4ToOP3") , 0x4171 }, 
 { _T("_OP5ToOP3") , 0x4174 }, 
 { _T("_OP4ToOP6") , 0x4177 }, 
 { _T("_Mov9ToOP1") , 0x417A }, 
 { _T("_Mov9OP1OP2") , 0x417D }, 
 { _T("_Mov9ToOP2") , 0x4180 }, 
 { _T("_MovFrOP1") , 0x4183 }, 
 { _T("_OP4Set1") , 0x4186 }, 
 { _T("_OP3Set1") , 0x4189 }, 
 { _T("_OP2Set8") , 0x418C }, 
 { _T("_OP1toOP2") , 0x418E }, 
 { _T("_OP2Set5") , 0x418F }, 
 { _T("_OP2SetA") , 0x4192 }, 
 { _T("_OP2Set4") , 0x4195 }, 
 { _T("_OP2Set3") , 0x4198 }, 
 { _T("_OP1Set1") , 0x419B }, 
 { _T("_OP1Set4") , 0x419E }, 
 { _T("_OP1Set3") , 0x41A1 }, 
 { _T("_OP3Set2") , 0x41A4 }, 
 { _T("_OP1Set2") , 0x41A7 }, 
 { _T("_OP2Set2") , 0x41AA }, 
 { _T("_OP2Set1") , 0x41AD }, 
 { _T("_Zero16D") , 0x41B0 }, 
 { _T("_OP5Set0") , 0x41B3 }, 
 { _T("_OP4Set0") , 0x41B6 }, 
 { _T("_OP3Set0") , 0x41B9 }, 
 { _T("_OP2Set0") , 0x41BC }, 
 { _T("_OP1Set0") , 0x41BF }, 
 { _T("_SetNum0") , 0x41C2 }, 
 { _T("_ZeroOP1") , 0x41C5 }, 
 { _T("_ZeroOP2") , 0x41C8 }, 
 { _T("_ZeroOP3") , 0x41CB }, 
 { _T("_ZeroOP") , 0x41CE }, 
 { _T("_ClrLp") , 0x41D1 }, 
 { _T("_ShRAcc") , 0x41D4 }, 
 { _T("_ShLAcc") , 0x41D7 }, 
 { _T("_OP2ExOP6") , 0x4207 }, 
 { _T("_OP5ExOP6") , 0x420A }, 
 { _T("_OP1ExOP5") , 0x420D }, 
 { _T("_OP1ExOP6") , 0x4210 }, 
 { _T("_OP2ExOP4") , 0x4213 }, 
 { _T("_OP2ExOP5") , 0x4216 }, 
 { _T("_OP1ExOP3") , 0x4219 }, 
 { _T("_OP1ExOP4") , 0x421C }, 
 { _T("_OP1ExOP2") , 0x421F }, 
 { _T("_ExLp") , 0x4222 }, 
 { _T("_CkOP1C0") , 0x4225 }, 
 { _T("_CkOP1FP0") , 0x4228 }, 
 { _T("_CkOP2FP0") , 0x422B }, 
 { _T("_PosNo0Int") , 0x422E }, 
 { _T("_CkPosInt") , 0x4231 }, 
 { _T("_CkInt") , 0x4234 }, 
 { _T("_CkOdd") , 0x4237 }, 
 { _T("_GETCONOP1") , 0x423D }, 
 { _T("_GETCONOP2") , 0x4240 }, 
 { _T("_ExpToHex") , 0x424F }, 
 { _T("_OP1ExpToDec") , 0x4252 }, 
 { _T("_CkOP2Pos") , 0x4255 }, 
 { _T("_CkOP1Pos") , 0x4258 }, 
 { _T("_ClrOP2S") , 0x425B }, 
 { _T("_ClrOP1S") , 0x425E }, 
 { _T("_FDiv100") , 0x4261 }, 
 { _T("_FDiv10") , 0x4264 }, 
 { _T("_DecO1Exp") , 0x4267 }, 
 { _T("_IncO1Exp") , 0x426A }, 
 { _T("_CkValidNum") , 0x4270 }, 
 { _T("_HTimesL") , 0x4276 }, 
 { _T("_EOP1NotReal") , 0x4279 }, 
 { _T("_ThetaName") , 0x427C }, 
 { _T("_RName") , 0x427F }, 
 { _T("_RegEqName") , 0x4282 }, 
 { _T("_nName") , 0x4285 }, 
 { _T("_XName") , 0x4288 }, 
 { _T("_YName") , 0x428B }, 
 { _T("_TName") , 0x428E }, 
 { _T("_RealName") , 0x4291 }, 
 { _T("_MarkTempDirty") , 0x4297 }, 
 { _T("_IsA2ByteTok") , 0x42A3 }, 
 { _T("_Equ_or_NewEqu") , 0x42C4 }, 
 { _T("_ErrD_OP1NotPos") , 0x42C7 }, 
 { _T("_ErrD_OP1Not_R") , 0x42CA }, 
 { _T("_ErrD_OP1NotPosInt") , 0x42CD }, 
 { _T("_ErrD_OP1_LE_0") , 0x42D0 }, 
 { _T("_ErrD_OP1_0") , 0x42D3 }, 
 { _T("_Rcl_StatVar") , 0x42DC }, 
 { _T("_CkOP2Real") , 0x42DF }, 
 { _T("_MemChk") , 0x42E5 }, 
 { _T("_ChkFindSym") , 0x42F1 }, 
 { _T("_FindSym") , 0x42F4 }, 
 { _T("_InsertMem") , 0x42F7 }, 
 { _T("_InsertMemNoUpdateVAT") , 0x42FA }, 
 { _T("_EnoughMem") , 0x42FD }, 
 { _T("_CreateCplx") , 0x430C }, 
 { _T("_CreateReal") , 0x430F }, 
 { _T("_CreateTempRList") , 0x4312 }, 
 { _T("_CreateRList") , 0x4315 }, 
 { _T("_CreateTempCList") , 0x4318 }, 
 { _T("_CreateCList") , 0x431B }, 
 { _T("_CreateTempRMat") , 0x431E }, 
 { _T("_CreateRMat") , 0x4321 }, 
 { _T("_CreateTempString") , 0x4324 }, 
 { _T("_CreateStrng") , 0x4327 }, 
 { _T("_Create0Equ") , 0x432A }, 
 { _T("_CreateTempEqu") , 0x432D }, 
 { _T("_CreateEqu") , 0x4330 }, 
 { _T("_CreatePict") , 0x4333 }, 
 { _T("_CreateGDB") , 0x4336 }, 
 { _T("_CreateProg") , 0x4339 }, 
 { _T("_AdjMath") , 0x4345 }, 
 { _T("_DelVar") , 0x4351 }, 
 { _T("_DelMem") , 0x4357 }, 
 { _T("_DelVar3DC") , 0x4360 }, 
 { _T("_IsFixedName") , 0x4363 }, 
 { _T("_DelVarEntry") , 0x4366 }, 
 { _T("_DataSizeA") , 0x4369 }, 
 { _T("_DataSize") , 0x436C }, 
 { _T("_PopMCplxO1") , 0x436F }, 
 { _T("_PopOP5") , 0x4378 }, 
 { _T("_PopOP3") , 0x437B }, 
 { _T("_PopOP1") , 0x437E }, 
 { _T("_PopRealO6") , 0x4381 }, 
 { _T("_PopRealO5") , 0x4384 }, 
 { _T("_PopRealO4") , 0x4387 }, 
 { _T("_PopRealO3") , 0x438A }, 
 { _T("_PopRealO2") , 0x438D }, 
 { _T("_PopRealO1") , 0x4390 }, 
 { _T("_PopReal") , 0x4393 }, 
 { _T("_DeallocFPS") , 0x439F }, 
 { _T("_DeallocFPS1") , 0x43A2 }, 
 { _T("_AllocFPS") , 0x43A5 }, 
 { _T("_AllocFPS1") , 0x43A8 }, 
 { _T("_PushRealO6") , 0x43AB }, 
 { _T("_PushRealO5") , 0x43AE }, 
 { _T("_PushRealO4") , 0x43B1 }, 
 { _T("_PushRealO3") , 0x43B4 }, 
 { _T("_PushRealO2") , 0x43B7 }, 
 { _T("_PushRealO1") , 0x43BA }, 
 { _T("_PushReal") , 0x43BD }, 
 { _T("_PushOP5") , 0x43C0 }, 
 { _T("_PushOP3") , 0x43C3 }, 
 { _T("_PushMCplxO3") , 0x43C6 }, 
 { _T("_PushOP1") , 0x43C9 }, 
 { _T("_PushMCplxO1") , 0x43CF }, 
 { _T("_Exch9") , 0x43D5 }, 
 { _T("_CpyTo1FPS11") , 0x43D8 }, 
 { _T("_CpyTo2FPS5") , 0x43DB }, 
 { _T("_CpyTo1FPS5") , 0x43DE }, 
 { _T("_CpyTo2FPS6") , 0x43E1 }, 
 { _T("_CpyTo1FPS6") , 0x43E4 }, 
 { _T("_CpyTo2FPS7") , 0x43E7 }, 
 { _T("_CpyTo1FPS7") , 0x43EA }, 
 { _T("_CpyTo1FPS8") , 0x43ED }, 
 { _T("_CpyTo2FPS8") , 0x43F0 }, 
 { _T("_CpyTo1FPS10") , 0x43F3 }, 
 { _T("_CpyTo1FPS9") , 0x43F6 }, 
 { _T("_CpyTo2FPS4") , 0x43F9 }, 
 { _T("_CpyTo6FPS3") , 0x43FC }, 
 { _T("_CpyTo6FPS2") , 0x43FF }, 
 { _T("_CpyTo2FPS3") , 0x4402 }, 
 { _T("_CpyTo1FPS3") , 0x4408 }, 
 { _T("_CpyTo1FPS4") , 0x440E }, 
 { _T("_CpyTo3FPS2") , 0x4411 }, 
 { _T("_CpyTo5FPST") , 0x4414 }, 
 { _T("_CpyTo6FPST") , 0x4417 }, 
 { _T("_CpyTo4FPST") , 0x441A }, 
 { _T("_CpyTo3FPST") , 0x441D }, 
 { _T("_CpyTo2FPST") , 0x4420 }, 
 { _T("_CpyTo1FPST") , 0x4423 }, 
 { _T("_CpyStack") , 0x4429 }, 
 { _T("_CpyTo3FPS1") , 0x442C }, 
 { _T("_CpyTo2FPS1") , 0x442F }, 
 { _T("_CpyTo1FPS1") , 0x4432 }, 
 { _T("_CpyTo2FPS2") , 0x4438 }, 
 { _T("_CpyTo1FPS2") , 0x443B }, 
 { _T("_CpyO3ToFPST") , 0x4441 }, 
 { _T("_CpyO2ToFPST") , 0x4444 }, 
 { _T("_CpyO6ToFPST") , 0x4447 }, 
 { _T("_CpyO1ToFPST") , 0x444A }, 
 { _T("_CpyToFPST") , 0x444D }, 
 { _T("_CpyToStack") , 0x4450 }, 
 { _T("_CpyO3ToFPS1") , 0x4453 }, 
 { _T("_CpyO5ToFPS1") , 0x4456 }, 
 { _T("_CpyO2ToFPS1") , 0x4459 }, 
 { _T("_CpyO1ToFPS1") , 0x445C }, 
 { _T("_CpyToFPS1") , 0x445F }, 
 { _T("_CpyO2ToFPS2") , 0x4462 }, 
 { _T("_CpyO3ToFPS2") , 0x4465 }, 
 { _T("_CpyO6ToFPS2") , 0x4468 }, 
 { _T("_CpyO1ToFPS2") , 0x446B }, 
 { _T("_CpyToFPS2") , 0x446E }, 
 { _T("_CpyO5ToFPS3") , 0x4471 }, 
 { _T("_CpyO2ToFPS3") , 0x4474 }, 
 { _T("_CpyO1ToFPS3") , 0x4477 }, 
 { _T("_CpyToFPS3") , 0x447A }, 
 { _T("_CpyO1ToFPS6") , 0x447D }, 
 { _T("_CpyO1ToFPS7") , 0x4480 }, 
 { _T("_CpyO1ToFPS5") , 0x4483 }, 
 { _T("_CpyO2ToFPS4") , 0x4486 }, 
 { _T("_CpyO1ToFPS4") , 0x4489 }, 
 { _T("_ErrNotEnoughMem") , 0x448C }, 
 { _T("_HLMinus9") , 0x4492 }, 
 { _T("_ErrOverflow") , 0x4495 }, 
 { _T("_ErrDivBy0") , 0x4498 }, 
 { _T("_ErrSingularMat") , 0x449B }, 
 { _T("_ErrDomain") , 0x449E }, 
 { _T("_ErrIncrement") , 0x44A1 }, 
 { _T("_ErrNon_Real") , 0x44A4 }, 
 { _T("_ErrSyntax") , 0x44A7 }, 
 { _T("_ErrDataType") , 0x44AA }, 
 { _T("_ErrArgument") , 0x44AD }, 
 { _T("_ErrDimMismatch") , 0x44B0 }, 
 { _T("_ErrDimension") , 0x44B3 }, 
 { _T("_ErrUndefined") , 0x44B6 }, 
 { _T("_ErrMemory") , 0x44B9 }, 
 { _T("_ErrInvalid") , 0x44BC }, 
 { _T("_ErrBreak") , 0x44BF }, 
 { _T("_ErrStat") , 0x44C2 }, 
 { _T("_ErrSignChange") , 0x44C5 }, 
 { _T("_ErrIterations") , 0x44C8 }, 
 { _T("_ErrBadGuess") , 0x44CB }, 
 { _T("_ErrTolTooSmall") , 0x44CE }, 
 { _T("_ErrStatPlot") , 0x44D1 }, 
 { _T("_ErrLinkXmit") , 0x44D4 }, 
 { _T("_JError") , 0x44D7 }, 
 { _T("_StrCopy") , 0x44E3 }, 
 { _T("_StrCat") , 0x44E6 }, 
 { _T("_OffPageJump") , 0x44F2 }, 
 { _T("_PutMap") , 0x4501 }, 
 { _T("_PutC") , 0x4504 }, 
 { _T("_DispHL") , 0x4507 }, 
 { _T("_PutS") , 0x450A }, 
 { _T("_PutPSB") , 0x450D }, 
 { _T("_PutPS") , 0x4510 }, 
 { _T("_WPutSEOL") , 0x4522 }, 
 { _T("_NewLine") , 0x452E }, 
 { _T("_ClrLCDFull") , 0x4540 }, 
 { _T("_ClrLCD") , 0x4543 }, 
 { _T("_ClrScrnFull") , 0x4546 }, 
 { _T("_ClrScrn") , 0x4549 }, 
 { _T("_ClrTxtShd") , 0x454C }, 
 { _T("_ClrWindow") , 0x454F }, 
 { _T("_EraseEOL") , 0x4552 }, 
 { _T("_EraseEOW") , 0x4555 }, 
 { _T("_HomeUp") , 0x4558 }, 
 { _T("_VPutMap") , 0x455E }, 
 { _T("_VPutS") , 0x4561 }, 
 { _T("_VPutSN") , 0x4564 }, 
 { _T("_RunIndicOn") , 0x456D }, 
 { _T("_RunIndicOff") , 0x4570 }, 
 { _T("_GetTokLen") , 0x4591 }, 
 { _T("_Get_Tok_Strng") , 0x4594 }, 
 { _T("_DispEOL") , 0x45A6 }, 
 { _T("_DispDone") , 0x45B5 }, 
 { _T("_CursorOff") , 0x45BE }, 
 { _T("_CursorOn") , 0x45C4 }, 
 { _T("_KeyToString") , 0x45CA }, 
 { _T("_PullDownChk") , 0x45CD }, 
 { _T("_PrevContext") , 0x4600 }, 
 { _T("_CompareContext") , 0x4603 }, 
 { _T("_AdrMRow") , 0x4606 }, 
 { _T("_AdrMEle") , 0x4609 }, 
 { _T("_GetMToOP1") , 0x4615 }, 
 { _T("_PutToMat") , 0x461E }, 
 { _T("_AdrLEle") , 0x462D }, 
 { _T("_GetLToOP1") , 0x4636 }, 
 { _T("_PutToL") , 0x4645 }, 
 { _T("_ToFrac") , 0x4657 }, 
 { _T("_BinOPExec") , 0x4663 }, 
 { _T("_UnOPExec") , 0x4672 }, 
 { _T("_ThreeExec") , 0x4675 }, 
 { _T("_FourExec") , 0x467B }, 
 { _T("_FiveExec") , 0x467E }, 
 { _T("_CloseEditBufNoR") , 0x476E }, 
 { _T("_ReleaseBuffer") , 0x4771 }, 
 { _T("_Load_SFont") , 0x4783 }, 
 { _T("_SFont_Len") , 0x4786 }, 
 { _T("_SetXXOP1") , 0x478C }, 
 { _T("_SetXXOP2") , 0x478F }, 
 { _T("_SetXXXXOP2") , 0x4792 }, 
 { _T("_UCLineS") , 0x4795 }, 
 { _T("_CLine") , 0x4798 }, 
 { _T("_CLineS") , 0x479B }, 
 { _T("_XRootY") , 0x479E }, 
 { _T("_YToX") , 0x47A1 }, 
 { _T("_ZmStats") , 0x47A4 }, 
 { _T("_StoGDB2") , 0x47CE }, 
 { _T("_RclGDB2") , 0x47D1 }, 
 { _T("_CircCmd") , 0x47D4 }, 
 { _T("_GrphCirc") , 0x47D7 }, 
 { _T("_Mov18B") , 0x47DA }, 
 { _T("_DarkLine") , 0x47DD }, 
 { _T("_ILine") , 0x47E0 }, 
 { _T("_IPoint") , 0x47E3 }, 
 { _T("_DarkPnt") , 0x47F2 }, 
 { _T("_CPointS") , 0x47F5 }, 
 { _T("_VtoWHLDE") , 0x47FB }, 
 { _T("_Xitof") , 0x47FE }, 
 { _T("_YftoI") , 0x4801 }, 
 { _T("_XftoI") , 0x4804 }, 
 { _T("_SetFuncM") , 0x4840 }, 
 { _T("_SetSeqM") , 0x4843 }, 
 { _T("_SetPolM") , 0x4846 }, 
 { _T("_SetParM") , 0x4849 }, 
 { _T("_ZmInt") , 0x484C }, 
 { _T("_ZmDecml") , 0x484F }, 
 { _T("_ZmPrev") , 0x4852 }, 
 { _T("_ZmUsr") , 0x4855 }, 
 { _T("_ZmFit") , 0x485B }, 
 { _T("_ZmSquare") , 0x485E }, 
 { _T("_ZmTrig") , 0x4861 }, 
 { _T("_ZooDefault") , 0x4867 }, 
 { _T("_GrBufCpy") , 0x486A }, 
 { _T("_RestoreDisp") , 0x4870 }, 
 { _T("_AllEq") , 0x4876 }, 
 { _T("_Regraph") , 0x488E }, 
 { _T("_PutXY") , 0x489D }, 
 { _T("_PDspGrph") , 0x48A3 }, 
 { _T("_HorizCmd") , 0x48A6 }, 
 { _T("_VertCmd") , 0x48A9 }, 
 { _T("_LineCmd") , 0x48AC }, 
 { _T("_UnLineCmd") , 0x48AF }, 
 { _T("_PointCmd") , 0x48B2 }, 
 { _T("_PixelTest") , 0x48B5 }, 
 { _T("_TanLnF") , 0x48BB }, 
 { _T("_DrawCmd") , 0x48C1 }, 
 { _T("_InvCmd") , 0x48C7 }, 
 { _T("_CloseEditBuf") , 0x48D3 }, 
 { _T("_PutSM") , 0x48D9 }, 
 { _T("_IsEditEmpty") , 0x492D }, 
 { _T("_DispEOW") , 0x4957 }, 
 { _T("_DispHead") , 0x495A }, 
 { _T("_DispTail") , 0x495D }, 
 { _T("_PutTokString") , 0x4960 }, 
 { _T("_CloseEditEqu") , 0x496C }, 
 { _T("_GetKey") , 0x4972 }, 
 { _T("_FormDisp") , 0x497E }, 
 { _T("_FormEReal") , 0x4990 }, 
 { _T("_FormDCplx") , 0x4996 }, 
 { _T("_FormReal") , 0x4999 }, 
 { _T("_OP1toEdit") , 0x49A5 }, 
 { _T("_GetEndVar") , 0x49D2 }, 
 { _T("_DispForward") , 0x49D5 }, 
 { _T("_DispErrorScreen") , 0x49DE }, 
 { _T("_CheckSplitFlag") , 0x49F0 }, 
 { _T("_SetNorm_Vals") , 0x49FC }, 
 { _T("_SetYOffset") , 0x49FF }, 
 { _T("_ConvKeyToTok") , 0x4A02 }, 
 { _T("_TokToKey") , 0x4A0B }, 
 { _T("_SendSkipExitPacket") , 0x4A0E }, 
 { _T("_GetVarCmd") , 0x4A11 }, 
 { _T("_SendVarCmd") , 0x4A14 }, 
 { _T("_SendScreenshot") , 0x4A17 }, 
 { _T("_keyscnlnk") , 0x4A1A }, 
 { _T("_DeselectAllVars") , 0x4A1D }, 
 { _T("_DelRes") , 0x4A20 }, 
 { _T("_ConvLcToLr") , 0x4A23 }, 
 { _T("_RedimMat") , 0x4A26 }, 
 { _T("_IncLstSize") , 0x4A29 }, 
 { _T("_InsertList") , 0x4A2C }, 
 { _T("_DelListEl") , 0x4A2F }, 
 { _T("_EditProg") , 0x4A32 }, 
 { _T("_CloseProg") , 0x4A35 }, 
 { _T("_ClrGraphRef") , 0x4A38 }, 
 { _T("_FixTempCnt") , 0x4A3B }, 
 { _T("_FindAlphaUp") , 0x4A44 }, 
 { _T("_FindAlphaDn") , 0x4A47 }, 
 { _T("_CmpSyms") , 0x4A4A }, 
 { _T("_CleanAll") , 0x4A50 }, 
 { _T("_MoveToNextSym") , 0x4A53 }, 
 { _T("_ConvLrToLc") , 0x4A56 }, 
 { _T("_ZIfRclHandler") , 0x4A65 }, 
 { _T("_ZIfRclkApp") , 0x4A68 }, 
 { _T("_RclKey") , 0x4A6B }, 
 { _T("_RclRegEq") , 0x4A71 }, 
 { _T("_CatalogChk") , 0x4A7D }, 
 { _T("_ErrNonReal") , 0x4A8C }, 
 { _T("_DisplayEquSmall") , 0x4A8F }, 
 { _T("_ParseInp") , 0x4A9B }, 
 { _T("_OP2Set60") , 0x4AB0 }, 
 { _T("_StoSysTok") , 0x4ABC }, 
 { _T("_StoAns") , 0x4ABF }, 
 { _T("_StoTheta") , 0x4AC2 }, 
 { _T("_StoR") , 0x4AC5 }, 
 { _T("_StoY") , 0x4AC8 }, 
 { _T("_StoN") , 0x4ACB }, 
 { _T("_StoT") , 0x4ACE }, 
 { _T("_StoX") , 0x4AD1 }, 
 { _T("_StoOther") , 0x4AD4 }, 
 { _T("_RclAns") , 0x4AD7 }, 
 { _T("_RclY") , 0x4ADA }, 
 { _T("_RclN") , 0x4ADD }, 
 { _T("_RclX") , 0x4AE0 }, 
 { _T("_RclVarSym") , 0x4AE3 }, 
 { _T("_RclSysTok") , 0x4AE6 }, 
 { _T("_StMatEl") , 0x4AE9 }, 
 { _T("_ConvOP1") , 0x4AEF }, 
 { _T("_Find_Parse_Formula") , 0x4AF2 }, 
 { _T("_CreatePair") , 0x4B0D }, 
 { _T("_ConvDim") , 0x4B43 }, 
 { _T("_ConvDim00") , 0x4B46 }, 
 { _T("_AnsName") , 0x4B52 }, 
 { _T("_IncFetch") , 0x4B73 }, 
 { _T("_Random") , 0x4B79 }, 
 { _T("_StoRand") , 0x4B7C }, 
 { _T("_RandInit") , 0x4B7F }, 
 { _T("_ResetStacks") , 0x4B82 }, 
 { _T("_Factorial") , 0x4B85 }, 
 { _T("_OneVar") , 0x4BA3 }, 
 { _T("_OutputExpr") , 0x4BB2 }, 
 { _T("_CentCursor") , 0x4BB5 }, 
 { _T("_GrBufClr") , 0x4BD0 }, 
 { _T("_DispAxes") , 0x4BE5 }, 
 { _T("_DispOP1A") , 0x4BF7 }, 
 { _T("_SetTblGraphDraw") , 0x4C00 }, 
 { _T("_MemClear") , 0x4C30 }, 
 { _T("_MemSet") , 0x4C33 }, 
 { _T("_ReloadAppEntryVecs") , 0x4C36 }, 
 { _T("_PointOn") , 0x4C39 }, 
 { _T("_ExecuteNewPrgm") , 0x4C3C }, 
 { _T("_StrLength") , 0x4C3F }, 
 { _T("_VPutMapRec") , 0x4C42 }, 
 { _T("_GetCurrentPageSub") , 0x4C45 }, 
 { _T("_FindAppUp") , 0x4C48 }, 
 { _T("_FindAppDn") , 0x4C4B }, 
 { _T("_FindApp") , 0x4C4E }, 
 { _T("_ExecuteApp") , 0x4C51 }, 
 { _T("_MonReset") , 0x4C54 }, 
 { _T("_IBounds") , 0x4C60 }, 
 { _T("_IOffset") , 0x4C63 }, 
 { _T("_DrawCirc2") , 0x4C66 }, 
 { _T("_CanAlphIns") , 0x4C69 }, 
 { _T("_GetBaseVer") , 0x4C6F }, 
 { _T("_AppGetCbl") , 0x4C75 }, 
 { _T("_AppGetCalc") , 0x4C78 }, 
 { _T("_SaveDisp") , 0x4C7B }, 
 { _T("_DisableApd") , 0x4C84 }, 
 { _T("_EnableApd") , 0x4C87 }, 
 { _T("_ApdSetup") , 0x4C93 }, 
 { _T("_Get_NumKey") , 0x4C96 }, 
 { _T("_HandleLinkActivity") , 0x4C9C }, 
 { _T("_LoadPattern") , 0x4CB1 }, 
 { _T("_SStringLength") , 0x4CB4 }, 
 { _T("_DoNothing") , 0x4CBD }, 
 { _T("_ClearRow") , 0x4CED }, 
 { _T("_ErrCustom1") , 0x4D41 }, 
 { _T("_AppStartMouse") , 0x4D47 }, 
 { _T("_AppEraseMouse") , 0x4D53 }, 
 { _T("_ClearRect") , 0x4D5C }, 
 { _T("_InvertRect") , 0x4D5F }, 
 { _T("_FillRect") , 0x4D62 }, 
 { _T("_AppUpdateMouse") , 0x4D65 }, 
 { _T("_DrawRectBorder") , 0x4D7D }, 
 { _T("_EraseRectBorder") , 0x4D86 }, 
 { _T("_FillRectPattern") , 0x4D89 }, 
 { _T("_DrawRectBorderClear") , 0x4D8C }, 
 { _T("_VerticalLine") , 0x4D95 }, 
 { _T("_IBoundsFull") , 0x4D98 }, 
 { _T("_DisplayImage") , 0x4D9B }, 
 { _T("_CPoint") , 0x4DC8 }, 
 { _T("_DeleteApp") , 0x4DCB }, 
 { _T("_HorizontalLine") , 0x4E67 }, 
 { _T("_CreateAppVar") , 0x4E6A }, 
 { _T("_CreateProtProg") , 0x4E6D }, 
 { _T("_CreateVar") , 0x4E70 }, 
 { _T("_AsmComp") , 0x4E73 }, 
 { _T("_GetAsmSize") , 0x4E76 }, 
 { _T("_SquishPrgm") , 0x4E79 }, 
 { _T("_ExecutePrgm") , 0x4E7C }, 
 { _T("_ChkFindSymAsm") , 0x4E7F }, 
 { _T("_ParsePrgmName") , 0x4E82 }, 
 { _T("_CSub") , 0x4E85 }, 
 { _T("_CAdd") , 0x4E88 }, 
 { _T("_CSquare") , 0x4E8B }, 
 { _T("_CMult") , 0x4E8E }, 
 { _T("_CRecip") , 0x4E91 }, 
 { _T("_CDiv") , 0x4E94 }, 
 { _T("_CAbs") , 0x4E97 }, 
 { _T("_CSqRoot") , 0x4E9D }, 
 { _T("_CLN") , 0x4EA0 }, 
 { _T("_CLog") , 0x4EA3 }, 
 { _T("_CTenX") , 0x4EA6 }, 
 { _T("_CEtoX") , 0x4EA9 }, 
 { _T("_CXrootY") , 0x4EAC }, 
 { _T("_CYtoX") , 0x4EB2 }, 
 { _T("_Conj") , 0x4EB5 }, 
 { _T("_CMltByReal") , 0x4EB8 }, 
 { _T("_CDivByReal") , 0x4EBB }, 
 { _T("_CTrunc") , 0x4EBE }, 
 { _T("_CFrac") , 0x4EC1 }, 
 { _T("_CIntgr") , 0x4EC4 }, 
 { _T("_SendHeaderPacket") , 0x4EC7 }, 
 { _T("_CancelTransmission") , 0x4ECA }, 
 { _T("_SendScreenContents") , 0x4ECD }, 
 { _T("_SendRAMVarData") , 0x4ED0 }, 
 { _T("_SendDataByte") , 0x4ED3 }, 
 { _T("_SendPacket") , 0x4ED6 }, 
 { _T("_ReceiveAck") , 0x4ED9 }, 
 { _T("_Send4BytePacket") , 0x4EDC }, 
 { _T("_Send4Bytes") , 0x4EE2 }, 
 { _T("_SendAByte") , 0x4EE5 }, 
 { _T("_SendCByte") , 0x4EE8 }, 
 { _T("_GetSmallPacket") , 0x4EEB }, 
 { _T("_GetDataPacket") , 0x4EEE }, 
 { _T("_SendAck") , 0x4EF1 }, 
 { _T("_Get4Bytes") , 0x4EF4 }, 
 { _T("_Get3Bytes") , 0x4EF7 }, 
 { _T("_Rec1stByte") , 0x4EFA }, 
 { _T("_Rec1stByteNC") , 0x4EFD }, 
 { _T("_RecAByteIO") , 0x4F03 }, 
 { _T("_ReceiveVar") , 0x4F06 }, 
 { _T("_ReceiveVarData") , 0x4F0C }, 
 { _T("_SrchVLstUp") , 0x4F0F }, 
 { _T("_SrchVLstDn") , 0x4F12 }, 
 { _T("_SendVariable") , 0x4F15 }, 
 { _T("_Get4BytesCursor") , 0x4F18 }, 
 { _T("_Get4BytesNC") , 0x4F1B }, 
 { _T("_SendDirectoryContents") , 0x4F21 }, 
 { _T("_SendReadyPacket") , 0x4F24 }, 
 { _T("_SendApplication") , 0x4F30 }, 
 { _T("_SendOSHeader") , 0x4F33 }, 
 { _T("_SendOSPage") , 0x4F36 }, 
 { _T("_SendOS") , 0x4F39 }, 
 { _T("_FlashWriteDisable") , 0x4F3C }, 
 { _T("_SendCmd") , 0x4F3F }, 
 { _T("_Disp") , 0x4F45 }, 
 { _T("_SendGetKeyPress") , 0x4F48 }, 
 { _T("_ContinueGetByte") , 0x4F4B }, 
 { _T("_CheckLinkLines") , 0x4F4E }, 
 { _T("_GetHookByte") , 0x4F51 }, 
 { _T("_GetBytePaged") , 0x4F54 }, 
 { _T("_EnableCursorHook") , 0x4F60 }, 
 { _T("_EnableLibraryHook") , 0x4F63 }, 
 { _T("_EnableRawKeyHook") , 0x4F66 }, 
 { _T("_ResetHookBytes") , 0x4F72 }, 
 { _T("_AdjustAllHooks") , 0x4F75 }, 
 { _T("_EnableGetCSCHook") , 0x4F7B }, 
 { _T("_EnableLinkActivityHook") , 0x4F84 }, 
 { _T("_EnableCatalog2Hook") , 0x4F8D }, 
 { _T("_EnableLocalizeHook") , 0x4F93 }, 
 { _T("_EnableTokenHook") , 0x4F99 }, 
 { _T("_Bit_VertSplit") , 0x4FA8 }, 
 { _T("_EnableHomescreenHook") , 0x4FAB }, 
 { _T("_EnableWindowHook") , 0x4FB1 }, 
 { _T("_EnableGraphHook") , 0x4FB7 }, 
 { _T("_DelVarArc") , 0x4FC6 }, 
 { _T("_DelVarNoArc") , 0x4FC9 }, 
 { _T("_SetAllPlots") , 0x4FCC }, 
 { _T("_EnableYEquHook") , 0x4FCF }, 
 { _T("_Arc_Unarc") , 0x4FD8 }, 
 { _T("_ArchiveVar") , 0x4FDB }, 
 { _T("_UnarchiveVar") , 0x4FDE }, 
 { _T("_EnableFontHook") , 0x4FE4 }, 
 { _T("_EnableRegraphHook") , 0x4FEA }, 
 { _T("_RunGraphingHook") , 0x4FF0 }, 
 { _T("_EnableTraceHook") , 0x4FF3 }, 
 { _T("_RunTracerHook") , 0x4FF9 }, 
 { _T("_JForceGraphNoKey") , 0x5002 }, 
 { _T("_JForceGraphKey") , 0x5005 }, 
 { _T("_PowerOff") , 0x5008 }, 
 { _T("_GetKeyRetOff") , 0x500B }, 
 { _T("_FindGroupSym") , 0x500E }, 
 { _T("_FillBasePageTable") , 0x5011 }, 
 { _T("_ArcChk") , 0x5014 }, 
 { _T("_FlashToRam") , 0x5017 }, 
 { _T("_LoadDEIndPaged") , 0x501A }, 
 { _T("_LoadCIndPaged") , 0x501D }, 
 { _T("_SetupPagedPtr") , 0x5020 }, 
 { _T("_PagedGet") , 0x5023 }, 
 { _T("_EnableParserHook") , 0x5026 }, 
 { _T("_EnableAppChangeHook") , 0x502C }, 
 { _T("_EnableGraphicsHook") , 0x5032 }, 
 { _T("_ILineNoHook") , 0x503B }, 
 { _T("_EnableCatalog1Hook") , 0x5044 }, 
 { _T("_EnableHelpHook") , 0x504A }, 
 { _T("_RunCatalog1Hook") , 0x505C }, 
 { _T("_DispMenuTitle") , 0x5065 }, 
 { _T("_EnablecxRedispHook") , 0x506B }, 
 { _T("_BufCpy") , 0x5071 }, 
 { _T("_BufClr") , 0x5074 }, 
 { _T("_EnableMenuHook") , 0x5083 }, 
 { _T("_GetBCOffsetIX") , 0x5089 }, 
 { _T("_ForceFullScreen") , 0x508F }, 
 { _T("_GetVariableData") , 0x5092 }, 
 { _T("_FindSwapSector") , 0x5095 }, 
 { _T("_CopyFlashPage") , 0x5098 }, 
 { _T("_FindAppNumPages") , 0x509B }, 
 { _T("_HLMinus5") , 0x509E }, 
 { _T("_SendArcPacket") , 0x50A1 }, 
 { _T("_ForceGraphKeypress") , 0x50A4 }, 
 { _T("_FormBase") , 0x50AA }, 
 { _T("_IsFragmented") , 0x50B0 }, 
 { _T("_Chk_Batt_Low") , 0x50B3 }, 
 { _T("_GetAppBasePage") , 0x50BC }, 
 { _T("_SetExSpeed") , 0x50BF }, 
 { _T("_GroupAllVars") , 0x50C5 }, 
 { _T("_EnableSilentLinkHook") , 0x50CE }, 
 { _T("_ResSilentLink") , 0x50D1 }, 
 { _T("_GetSysInfo") , 0x50DD }, 
 { _T("_NZIf83Plus") , 0x50E0 }, 
 { _T("_LinkStatus") , 0x50E3 }, 
 { _T("_KeyboardGetKey") , 0x50E9 }, 
 { _T("_RunAppLib") , 0x50EC }, 
 { _T("_GetVarCmdUSB") , 0x50FB }, 
 { _T("_GetVarVersion") , 0x510A }, 
 { _T("_InvertTextInsMode") , 0x5122 }, 
 { _T("_DispHeader") , 0x512E }, 
 { _T("_JForceGroup") , 0x5131 }, 
 { _T("_getDate") , 0x514F }, 
 { _T("_getDtFmt") , 0x5155 }, 
 { _T("_getTime") , 0x515B }, 
 { _T("_getTmFmt") , 0x5161 }, 
 { _T("_SetZeroOne") , 0x5167 }, 
 { _T("_IsOneTwoThree") , 0x516D }, 
 { _T("_IsOP112or24") , 0x5173 }, 
 { _T("_chkTimer0") , 0x5176 }, 
 { _T("_ClrWindowAndFlags") , 0x517F }, 
 { _T("_SetMachineID") , 0x5182 }, 
 { _T("_ResetLists") , 0x5185 }, 
 { _T("_ExecLib") , 0x5191 }, 
 { _T("_OpenLib") , 0x519D }, 
 { _T("_WaitEnterKey") , 0x51A0 }, 
 { _T("_IsOP1ResID") , 0x51B8 }, 
 { _T("_DispAboutScreen") , 0x51C7 }, 
 { _T("_ChkHelpHookVer") , 0x51CA }, 
 { _T("_Disp32") , 0x51CD }, 
 { _T("_DrawTableEditor") , 0x51DC }, 
 { _T("_MatrixName") , 0x51F1 }, 
 { _T("_Chk_Batt_Level") , 0x5221 }, 
 { _T("_GoToLastRow") , 0x5233 }, 
 { _T("_RectBorder") , 0x5236 }, 
 { _T("_LoadA5") , 0x5242 }, 
 { _T("_NamedListToOP1") , 0x5248 }, 
 { _T("_SetVertGraphActive") , 0x5284 }, 
 { _T("_ClearVertGraphActive") , 0x5287 }, 
 { _T("_EnableUSBActivityHook") , 0x528A }, 
 { _T("_GraphLine") , 0x529C }, 
 { _T("_ZifTableEditor") , 0x52B1 }, 
 { _T("_DeleteInvalidApps") , 0x52ED }, 
 { _T("_DeleteApp_Link") , 0x52F0 }, 
 { _T("_SetAppRestrictions") , 0x52F6 }, 
 { _T("_RemoveAppRestrictions") , 0x52F9 }, 
 { _T("_SetupHome") , 0x5302 }, 
 { _T("_PolarEquToOP1") , 0x5314 }, 
 { _T("_ClearGraphStyles") , 0x5329 }, 
 { _T("_MD5Final") , 0x8018 }, 
 { _T("_RSAValidate") , 0x801B }, 
 { _T("_BigNumCompare") , 0x801E }, 
 { _T("_WriteAByte") , 0x8021 }, 
 { _T("_EraseFlash") , 0x8024 }, 
 { _T("_FindFirstCertificateField") , 0x8027 }, 
 { _T("_ZeroToCertificate") , 0x802A }, 
 { _T("_GetCertificateEnd") , 0x802D }, 
 { _T("_FindGroupedField") , 0x8030 }, 
 { _T("_Mult8By8") , 0x8042 }, 
 { _T("_Mult16By8") , 0x8045 }, 
 { _T("_Div16By8") , 0x8048 }, 
 { _T("_Divide16By16") , 0x804B }, 
 { _T("_LoadAIndPaged") , 0x8051 }, 
 { _T("_FlashToRAM2") , 0x8054 }, 
 { _T("_GetCertificateStart") , 0x8057 }, 
 { _T("_GetFieldSize") , 0x805A }, 
 { _T("_FindSubField") , 0x805D }, 
 { _T("_EraseCertificateSector") , 0x8060 }, 
 { _T("_CheckHeaderKey") , 0x8063 }, 
 { _T("_Load_LFontV2") , 0x806C }, 
 { _T("_Load_LFontV") , 0x806F }, 
 { _T("_ReceiveOS") , 0x8072 }, 
 { _T("_FindOSHeaderSubField") , 0x8075 }, 
 { _T("_FindNextCertificateField") , 0x8078 }, 
 { _T("_GetByteOrBoot") , 0x807B }, 
 { _T("_GetCalcSerial") , 0x807E }, 
 { _T("_EraseFlashPage") , 0x8084 }, 
 { _T("_WriteFlashUnsafe") , 0x8087 }, 
 { _T("_DispBootVer") , 0x808A }, 
 { _T("_MD5Init") , 0x808D }, 
 { _T("_MD5Update") , 0x8090 }, 
 { _T("_MarkOSInvalid") , 0x8093 }, 
 { _T("_MarkOSValid") , 0x8099 }, 
 { _T("_CheckOSValidated") , 0x809C }, 
 { _T("_SetupAppPubKey") , 0x809F }, 
 { _T("_SigModR") , 0x80A2 }, 
 { _T("_TransformHash") , 0x80A5 }, 
 { _T("_IsAppFreeware") , 0x80A8 }, 
 { _T("_FindAppHeaderSubField") , 0x80AB }, 
 { _T("_Div32By16") , 0x80B1 }, 
 { _T("_GetBootVer") , 0x80B7 }, 
 { _T("_GetHWVer") , 0x80BA }, 
 { _T("_XorA") , 0x80BD }, 
 { _T("_bignumpowermod17") , 0x80C0 }, 
 { _T("_ProdNrPart1") , 0x80C3 }, 
 { _T("_WriteAByteSafe") , 0x80C6 }, 
 { _T("_WriteFlash") , 0x80C9 }, 
 { _T("_SetupDateStampPubKey") , 0x80CC }, 
 { _T("_SetFlashLowerBound") , 0x80CF }, 
 { _T("_LowBatteryBoot") , 0x80D2 }, 
 { _T("_DisplayBootMessage") , 0x80E7 }, 
 { _T("_NewLineWrap") , 0x80EA }, 
 { _T("_DispOSPercentage") , 0x80F9 }, 
 { _T("_ResetCalc") , 0x80FC }, 
 { _T("_SetupOSPubKey") , 0x80FF },
 { _T("") , -1 }
};

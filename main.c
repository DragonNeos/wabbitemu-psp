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

#include <pspkernel.h>
#include <pspiofilemgr.h>

#include <oslib/oslib.h>
#include "calc.h"
#include "keys.h"
#include "main.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Definitions:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PALETTE_SIZE 256
#define MAX_SHADES 255
#define LCD_HIGH 255

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Modules infos:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PSP_MODULE_INFO("Wabbitemu for PSP", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(12*1024);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Init OSLib:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int initOSLib(){
    oslInit(0);
    oslInitGfx(OSL_PF_8888, 1);
	//oslSetDithering(1);
    oslInitAudio();
    oslSetQuitOnLoadFailure(1);
    oslSetKeyAutorepeatInit(40);
    oslSetKeyAutorepeatInterval(10);
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(){

CreatePalette();
//---------------


// FILE * pFile;
// char buffer[] = { 'x' , 'y' , 'z' };
// pFile = fopen ( "myfile.txt" , "wb" );
// fwrite (buffer , 1 , sizeof(buffer) , pFile );
// fclose (pFile);


    int skip = 0;

    initOSLib();

	//oslWarning("OSlib init");
	
    // oslIntraFontInit(INTRAFONT_CACHE_MED);


    //Load font:
    // OSL_FONT *pgfFont = oslLoadFontFile("flash0:/font/ltn0.pgf");
    // oslIntraFontSetStyle(pgfFont, 1.0, RGBA(255,255,255,255), RGBA(0,0,0,0), INTRAFONT_ALIGN_LEFT);
    // oslSetFont(pgfFont);
	//OSL_IMAGE *test1;
	//test1 = oslLoadImageFile("test1.png", OSL_IN_RAM, OSL_PF_8BIT);
	// if (!test1)
		// oslDebug("Impossible to load one or more files. Check if all the files are copied in the game folder.");
	struct CALCBUNDLE MyCalc;
	MyCalc = CreateCalc(1, "z.rom");
	// Timer *timer = CreateTimer(TPF, TimerFunc, (LPVOID) lpCalc);
	 //timer.Start();
	 int i;
	 for(i=0;i<20;i++){
			TimerFunc(MyCalc);
			int skip = oslSyncFrame();
	}
	gprof_cleanup();
	sceKernelExitGame();
}
unsigned char redColors[MAX_SHADES+1];
unsigned char greenColors[MAX_SHADES+1];
unsigned char blueColors[MAX_SHADES+1];
void CreatePalette() {
for (int i = 0; i <= MAX_SHADES; i++) {
	redColors[i] = (0x9E*(256-(LCD_HIGH/MAX_SHADES)*i))/255;
	greenColors[i] = (0xAB*(256-(LCD_HIGH/MAX_SHADES)*i))/255;
	blueColors[i] = (0x88*(256-(LCD_HIGH/MAX_SHADES)*i))/255;
}
}

struct CALCBUNDLE CreateCalc(BOOL StartCalculator, LPCTSTR RomName) {
int i=0;
struct CALCBUNDLE MyCalc; //create a structure containing the LPCALC structure, the image buffer etc...
MyCalc.lpCalc = calc_slot_new();
BOOL rom_result = rom_load(MyCalc.lpCalc, RomName);	//load a rom according to the RomName specified by the caller
MyCalc.currentscreen = oslCreateImage(96, 64, OSL_IN_RAM, OSL_PF_8888);	//create an image to hold the current screen
//MyCalc.currentscreen->sizeX=96;
 if (StartCalculator) {
	MyCalc.lpCalc->running=TRUE;	//alot faster: turn on the calculator
	//calc_turn_on(lpCalc);			//slower: do the same
 }

 return MyCalc;
} 


void TimerFunc(struct CALCBUNDLE MyCalc) {
 calc_run_all();
 UpdateDisplay(MyCalc);
 KeysHandler(&MyCalc);
}

void UpdateDisplay(struct CALCBUNDLE MyCalc) {
LCD_t *lcd = MyCalc.lpCalc->cpu.pio.lcd;
lcd->active=TRUE;
//lpCalc->active=TRUE;
//lpCalc->running=TRUE;
//oslWarning("%d", (int)lpCalc->active);
//oslWarning("%d", (int)lpCalc->running);
//oslWarning("%d", (int)lcd->active);
 if (lcd->active == FALSE) {
unsigned char rgb_data[128*64*4] = {0};
int i, j, h;
for (int i = j = 0; i < 128*64; i++) {
rgb_data[j++] = redColors[0];
rgb_data[j++] = greenColors[0];
rgb_data[j++] = blueColors[0];
rgb_data[j++] = 0xFF;
}
memcpy(MyCalc.currentscreen->data, rgb_data, 96 * 64 * 4);
	oslStartDrawing();
	oslDrawImage(MyCalc.currentscreen);
	oslEndDrawing();
 } else {
  u_char *screen = LCD_image(MyCalc.lpCalc->cpu.pio.lcd);
unsigned char rgb_data[128*64*4];
int i, j, h;
for (int i = j = h = 0; i < 128*64; i++, h++) {

rgb_data[j++] = redColors[screen[i]];
rgb_data[j++] = greenColors[screen[i]];
rgb_data[j++] = blueColors[screen[i]];
rgb_data[j++] = 0xFF;
}
memcpy(MyCalc.currentscreen->data, rgb_data, 128 * 64 * 4);

  /*for (i=0;i<=128*64;i++) {
wabbit_32_bit_buffer[i] = screen[i];
  }*/
  //memcpy(currentscreen->data, &wabbit_32_bit_buffer, 128 * 64 * 4);
	//memcpy(currentscreen->data, screen, 128 * 64);
//oslWarning("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, ",MyCalc.currentscreen->sizeX, MyCalc.currentscreen->sizeY, MyCalc.currentscreen->sysSizeX, MyCalc.currentscreen->sysSizeY, MyCalc.currentscreen->realSizeX, MyCalc.currentscreen->realSizeY, MyCalc.currentscreen->data, MyCalc.currentscreen->flags, MyCalc.currentscreen->totalSize, MyCalc.currentscreen->location, MyCalc.currentscreen->pixelFormat, MyCalc.currentscreen->frameSizeX, MyCalc.currentscreen->frameSizeY, MyCalc.currentscreen->x, MyCalc.currentscreen->y, MyCalc.currentscreen->stretchX, MyCalc.currentscreen->stretchY, MyCalc.currentscreen->offsetX0, MyCalc.currentscreen->offsetY0, MyCalc.currentscreen->offsetX1, MyCalc.currentscreen->offsetY1, MyCalc.currentscreen->centerX, MyCalc.currentscreen->centerY, MyCalc.currentscreen->angle);

	// currentscreen->sizeY=62;
	// currentscreen->realSizeX=94;
	// currentscreen->realSizeY=62;
	oslStartDrawing();
	//OSL_IMAGE *test1;
	//test1 = oslLoadImageFile("test1.png", OSL_IN_RAM, OSL_PF_8BIT);
	//oslDrawImage(test1);
	//oslClearScreen(0xFFFFFF);
	//oslWarning("Hey guys");
	oslUncacheImage(MyCalc.currentscreen);
	//oslWarning("Hey guys 1");
	oslDrawImage(MyCalc.currentscreen);
	//oslWarning("Hey guys 2");
	//draw this to the screen
	oslEndDrawing();
	
  //Draw8BitArray(screen);
 }
}
void KeysHandler(struct CALCBUNDLE *MyCalc) {
//CPU_t *cpu = MyCalc->lpCalc->cpu;
oslReadKeys();
if (osl_pad.held.up) {
	keypad_press(&MyCalc->lpCalc->cpu, 0,3);
}
else {
keypad_release(&MyCalc->lpCalc->cpu, 0,3);
}
if (osl_pad.held.down) {
keypad_press(&MyCalc->lpCalc->cpu, 0,0);
}
else {
keypad_release(&MyCalc->lpCalc->cpu, 0,0);
}
if (osl_pad.held.start) {
	keypad_press(&MyCalc->lpCalc->cpu, 6,5);
}
else {
keypad_release(&MyCalc->lpCalc->cpu, 6,5);
}
}
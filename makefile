TARGET = WabbitemuPSP
OBJS = main.o utilities\sendfile.o utilities\savestate.o utilities\var.o utilities\label.o utilities\gif.o utilities\gifhandle.o interface\calc.o interface\state.o hardware\83psehw.o hardware\83phw.o hardware\83hw.o hardware\86hw.o hardware\lcd.o hardware\link.o hardware\81hw.o hardware\keys.o core\core.o core\device.o core\indexcb.o core\alu.o core\control.o

#To build for custom firmware:
BUILD_PRX = 1
PSP_FW_VERSION=371

#Include folders core/interface/hardwars/utilities to avoid to use relative paths for .h files || We use a special convention of C: gnu99 || we use D_LINUX to have some necessary stuff defined (like uint32...) || -fpack-struct is designed to force the compiler to align structures in memory
CFLAGS = -I. -I./core -I./interface -I./hardware -I./utilities -I./menu -O0 -pg -g -G0 -std=gnu99 -D_LINUX -DVERBOSE -fpack-struct -fsigned-char -funroll-loops -fsigned-char -ffast-math -fno-signed-zeros


CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
LIBDIR =

MYLIBS=
STDLIBS= -lpspprof -losl -lpng -lz \
         -lpsphprm -lpspsdk -lpspctrl -lpspumd -lpsprtc -lpsppower -lpspgu -lpspgum  -lpspaudiolib -lpspaudio -lpsphttp -lpspssl -lpspwlan \
         -lpspnet_adhocmatching -lpspnet_adhoc -lpspnet_adhocctl -lm -ljpeg
	
LIBS=$(STDLIBS) $(MYLIBS)

LDFLAGS =
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Wabbitemu for PSP
#PSP_EBOOT_ICON = ICON0.PNG
PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

clean:
	rm *.o
	rm /core/*.o
	rm /hardware/*.o
	rm /utilities/*.o
	rm /interface/*.o
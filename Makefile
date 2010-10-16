# imgbrowser
CC          = g++
CCFLAGS     = -c -Wall -O2 -Funrollloop -ggdb -D REENTRANT $(shell wx-config --cxxflags adv,html,xml,core,base)
#-I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -DHAVE_OPENGL -DSOUND
LDFLAGS     = -lm -O2  $(shell wx-config --libs )
#-lGL -lGLU  -lSDL -lSDL_image
CCFLAGS    += -MD -MP -MT $(*F).o -MF dep/$(@F).d
MY_NAME     = pdfbeamer
LIBS        = 
MYOBJECTS   = main.o mainwindow.o panel.o



all: $(MYOBJECTS) $(MYHEADER) Makefile 
	$(CC) $(MYOBJECTS) $(LIBS) $(LDFLAGS)  -o $(MY_NAME)

.cpp.o: $< $(MYHEADER) Makefile
	 $(CC) $(INCLUDES) $(CCFLAGS) $<

clean:
	rm -rf $(MYOBJECTS) $(MY_NAME)
install:
	install $(MY_NAME) ~/bin/

-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

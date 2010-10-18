#      Copyright 2010 Benjamin Reh <ich@benjaminreh.de>
#      
#      This program is free software; you can redistribute it and/or modify
#      it under the terms of the GNU General Public License as published by
#      the Free Software Foundation; either version 2 of the License, or
#      (at your option) any later version.
#     
#     This program is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
#    
#     You should have received a copy of the GNU General Public License
#     along with this program; if not, write to the Free Software
#     Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#     MA 02110-1301, USA.
 
CC          = g++
CCFLAGS     = -c -Wall -O2 -Funrollloop -ggdb -D REENTRANT $(shell wx-config --cxxflags adv,html,xml,core,base) $(shell pkg-config --cflags poppler-splash)
LDFLAGS     = -lm -O2  
CCFLAGS    += -MD -MP -MT $(*F).o -MF dep/$(@F).d
MY_NAME     = pdfbeamer
LIBS        = $(shell wx-config --libs ) $(shell pkg-config --libs poppler-splash)
MYOBJECTS   = main.o mainwindow.o panel.o pdf_panel.o pdf.o beamer.o



all: $(MYOBJECTS) $(MYHEADER) Makefile 
	$(CC) $(MYOBJECTS) $(LIBS) $(LDFLAGS)  -o $(MY_NAME)

.cpp.o: $< $(MYHEADER) Makefile
	 $(CC) $(INCLUDES) $(CCFLAGS) $<

clean:
	rm -rf $(MYOBJECTS) $(MY_NAME)
install:
	install $(MY_NAME) ~/bin/

-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

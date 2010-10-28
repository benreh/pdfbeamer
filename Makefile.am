##Process this file with automake to create Makefile.in
bin_PROGRAMS = pdfbeamer
pdfbeamer_SOURCES = beamer.cpp  main.cpp  mainwindow.cpp  panel.cpp  pdf.cpp  pdfpage.cpp  pdf_panel.cpp

LIBS=$(DEPS_LIBS)

INCLUDES = $(DEPS_CFLAGS)
CXXFLAGS = $(DEPS_CFLAGS)

pdfbeamer_CXXFLAGS = $(DEPS_CFLAGS)
pdfbeamer_LDADD = $(DEPS_LIBS)

AUTOMAKE_OPTIONS = foreign


//      Copyright 2010 Benjamin Reh <ich@benjaminreh.de>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.

#ifndef PDF_H
#define PDF_H
#include <GlobalParams.h>
#include <Object.h>
#include <splash/SplashBitmap.h>
#include <SplashOutputDev.h>
#include <PDFDoc.h>
#include <wx/wx.h>
#include <list>

#include "pdfpage.h"

class PDF {
public:
	PDF();
	~PDF();

	bool load(const char * filename);
	bool isLoaded();
	int n_pages();
	void render(wxBitmap ** bitmap, int w, int h, int page, double stretch=1.0);
	void render_page(PDFPage & cachepage);
	int limitpage(int page_in);
	void clean_cache();
	std::list<PDFPage *> cache;
	
private:
	PDFDoc * doc;
	SplashOutputDev * output_dev;
};


#endif

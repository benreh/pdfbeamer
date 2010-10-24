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
#include "pdf.h"

#include <iostream>


#define MIN(A,B) A>B ? B : A

PDF::PDF() {
	doc=NULL;
	output_dev=NULL;
	//Poppler needs this or seqfaults 
	globalParams = new GlobalParams();
    globalParams->setErrQuiet(gFalse);
}

PDF::~PDF() {
	//~ if (doc)
		//~ delete doc;
	delete globalParams;
}
int PDF::limitpage(int page) {
	if (n_pages()<page)
		page=n_pages();
	if (page<1)
		page=1;
	return page;

}


bool PDF::load(const char * filename) {
	GooString *file_name_str = new GooString(filename);
	doc = new PDFDoc(file_name_str, NULL, NULL, NULL);
	delete file_name_str;
	if (!output_dev) {	
		SplashColor bg_color = {0xff,0xff,0xff};
		output_dev = new SplashOutputDev(splashModeRGB8, 3, gFalse, bg_color);
	}

	if (output_dev)
		output_dev->startDoc(doc->getXRef());
	cache.clear();
	
	return true;
}
bool PDF::isLoaded() {
	if (doc)
		return true;
	else
		return false;
}

int PDF::n_pages() {
	if (!isLoaded())
		return -1;
	return doc->getNumPages();

}
void PDF::render(wxBitmap ** bitmap, int w, int h, int page, double stretch) {
	PDFPage * cachepage;
	bool found=false;
	for (std::list<PDFPage *>::iterator it=cache.begin();it != cache.end() && found==false; it++){
		if ((*it)->w==w &&
			(*it)->h==h &&
			(*it)->page==page &&
			(*it)->stretch==stretch) {
				cachepage=(*it);
				found=true;
			}
	}
	if (!found){
		cachepage= new PDFPage();
		cachepage->w=w;
		cachepage->h=h;
		cachepage->page=page;
		cachepage->stretch=stretch;
		render_page(*cachepage);	
		cache.push_back(cachepage);
		//~ std::cerr << "not found " <<cache.size() << std::endl;
	} else {
		//~ std::cerr << "found" << std::endl;
	}
	*bitmap=&(cachepage->bitmap);
}
void PDF::render_page(PDFPage & cachepage) {
	cachepage.page=limitpage(cachepage.page);

	// 72.0 is the magical number falling from the sky
	//  ...not really, it is some kind of resolution
	//     no idea, where to obtain it from
	double dpi_w = 72.0*cachepage.w/doc->getPageMediaWidth(cachepage.page); 
	double dpi_h = 72.0*cachepage.h/doc->getPageMediaHeight(cachepage.page); 
	double dpi = MIN(dpi_w,dpi_h);
	
	doc->displayPage(output_dev, cachepage.page, dpi*cachepage.stretch, dpi, 0, gFalse, gFalse, gFalse);
	SplashBitmap *bmp = output_dev->getBitmap();
	if (!bmp)
        std::cerr << "error in SplashBitmap" << std::endl;


	cachepage.bitmap = wxBitmap(wxImage(bmp->getWidth(), bmp->getHeight(),(unsigned char * ) bmp->getDataPtr(),true ));
}

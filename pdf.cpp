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
	if (n_pages()-1<page)
		page=n_pages()-1;
	if (page<1)
		page=1;
	return page;

}


bool PDF::load(const char * filename) {
	GooString *file_name_str = new GooString(filename);
	doc = new PDFDoc(file_name_str, NULL, NULL, NULL);
	//~ std::cerr << filename << " " << n_pages() << std::endl;
	delete file_name_str;
	if (!output_dev) {	
		SplashColor bg_color = {0xff,0xff,0xff};
		output_dev = new SplashOutputDev(splashModeRGB8, 3, gFalse, bg_color);
	}

	if (output_dev)
		output_dev->startDoc(doc->getXRef());
    else
		std::cerr << "error:outputdev "  << std::endl;

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
void PDF::render(wxBitmap & bitmap, int w, int h, int page) {
	page=limitpage(page);

	double dpi_w = 72*w/doc->getPageMediaWidth(page); 
	double dpi_h = 72*h/doc->getPageMediaHeight(page); 
	double dpi = MIN(dpi_w,dpi_h);
	
	doc->displayPage(output_dev, page, dpi, dpi, 0, gFalse, gFalse, gFalse);
	SplashBitmap *bmp = output_dev->getBitmap();
	if (!bmp)
        std::cerr << "error in SplashBitmap" << std::endl;


	bitmap = wxBitmap(wxImage(bmp->getWidth(), bmp->getHeight(),(unsigned char * ) bmp->getDataPtr(),true ));
}

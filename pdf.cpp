#include "pdf.h"

#include <iostream>

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
		SplashColor bg_color = {1,0,1};
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
	const double dpi = 30; //get_pdf_doc_dpi(width_inch(page_nr), height_inch(page_nr), width, height);


	doc->displayPage(output_dev, limitpage(page), dpi, dpi, 0, gFalse, gFalse, gFalse);
	SplashBitmap *bmp = output_dev->getBitmap();
	if (!bmp)
        std::cerr << "error in SplashBitmap" << std::endl;

	std::cerr << "bmp" << bmp->getWidth() << "x" << bmp->getHeight() << " row-size:" << bmp->getRowSize()<< std::endl;
	//~ std::cerr << "w " << w << " h" << h << std::endl;

	//~ int s=bmp->getHeight() * bmp->getRowSize();
	//~ unsigned char * temp = new unsigned char[s];

	//~ std::cerr <<"before memcpy" << std::endl;
	//~ memcpy(temp, bmp->getDataPtr(), s);
	//~ std::cerr <<"after memcpy" << std::endl;
	bitmap = wxBitmap(wxImage(bmp->getWidth(), bmp->getHeight(),(unsigned char * ) bmp->getDataPtr(),true ));
	//~ bitmap = wxBitmap(wxImage(bmp->getWidth(), bmp->getHeight(),temp));
	
	//~ delete temp;
}

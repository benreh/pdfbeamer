#include "pdf.h"

#include <iostream>

PDF::PDF() {
	doc=NULL;
}

PDF::~PDF() {
	//~ if (doc)
		//~ delete doc;
}



bool PDF::load(const char * filename) {
	GooString *file_name_str = new GooString(filename);
	doc = new PDFDoc(file_name_str, NULL, NULL, NULL);
	std::cerr << filename << " " << n_pages() << std::endl;
	delete file_name_str;

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

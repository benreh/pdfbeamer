#ifndef PDF_H
#define PDF_H
#include <SplashOutputDev.h>
#include <PDFDoc.h>

class PDF {
public:
	PDF();
	~PDF();

	bool load(const char * filename);
	PDFDoc * doc;
	SplashOutputDev * output_dev;

	bool isLoaded();
	int n_pages();
};


#endif

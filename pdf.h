#ifndef PDF_H
#define PDF_H
#include <GlobalParams.h>
#include <Object.h>
#include <splash/SplashBitmap.h>
#include <SplashOutputDev.h>
#include <PDFDoc.h>
#include <wx/wx.h>

class PDF {
public:
	PDF();
	~PDF();

	bool load(const char * filename);
	bool isLoaded();
	int n_pages();
	void render(wxBitmap & bitmap, int w, int h, int page);
	int limitpage(int page_in);
	
private:
	PDFDoc * doc;
	SplashOutputDev * output_dev;
};


#endif

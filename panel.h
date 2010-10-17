#ifndef PANEL_H
#define PANEL_H
#include <wx/wx.h>
#include <wx/panel.h>
#include "pdf_panel.h"


class LeftPanel : public wxPanel {
public:
    LeftPanel(wxPanel *parent, PDF * pdf);
	PDFPanel * pdfpanel;
	void OnUpdate(wxCommandEvent& event);
	void update();
};

class RightPanel : public wxPanel {
public:
    RightPanel(wxPanel *parent, PDF * newpdf);
	PDFPanel * pdfpanel;
	PDF * pdf;
	wxSlider *slider;
	wxButton * showb;
	void OnUpdate(wxCommandEvent& event);
	void OnScroll(wxScrollEvent& event);
	void OnShowB(wxCommandEvent & WXUNUSED(event));
	void update();

};
const int ID_SLIDER = 100;
#endif

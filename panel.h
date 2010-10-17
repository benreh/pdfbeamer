#ifndef PANEL_H
#define PANEL_H
#include <wx/wx.h>
#include <wx/panel.h>
#include "pdf_panel.h"
#include <wx/tglbtn.h>

class LeftPanel : public wxPanel {
public:
    LeftPanel(wxPanel *parent, PDF * pdf);
	PDFPanel * pdfpanel;
	void OnUpdate(wxCommandEvent& event);
	void update();
	wxButton * nextb;
	wxButton * prevb;
	wxToggleButton * blackb;
	void OnNextB(wxCommandEvent & WXUNUSED(event));
	void OnPrevB(wxCommandEvent & WXUNUSED(event));
	void OnBlackB(wxCommandEvent & WXUNUSED(event));
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
const int ID_SHOW = 101;
const int ID_PREV = 102;
const int ID_NEXT = 103;
const int ID_BLACK = 104;
#endif

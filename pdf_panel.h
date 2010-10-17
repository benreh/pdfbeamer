#ifndef PDF_PANEL_H
#define PDF_PANEL_H
#include <wx/wx.h>
#include <wx/panel.h>
#include "pdf.h"

class PDFPanel : public wxPanel {
public:
    PDFPanel(wxPanel *parent, PDF * newpdf, bool presentationmode=false);



	void OnUpdate(wxCommandEvent& event);
	void OnPaint(wxPaintEvent& event);
	void OnResize(wxSizeEvent &e);
	void update();
	int page;
	bool pm;

private:
	PDF * pdf;
	wxStaticText *m_text;
	wxBitmap slide;
	DECLARE_EVENT_TABLE()
	
};
#endif

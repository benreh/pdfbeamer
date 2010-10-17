#ifndef BEAMER_H
#define BEAMER_H

#include <wx/wx.h>
#include "pdf_panel.h"

class Beamer : public wxFrame
{
public:
	Beamer(wxFrame* parent, PDF * pdf);


	void OnUpdate(wxCommandEvent& event);
	void OnHereB(wxCommandEvent & WXUNUSED(event));
	void update();
	void maximize();

	wxBoxSizer *vbox;
	wxButton *hereb;
	wxStaticText *m_text;
	PDFPanel * pdfpanel;
	bool fs;
	
};
#endif

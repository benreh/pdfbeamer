#include <wx/stattext.h>
#include "pdf_panel.h"

PDFPanel::PDFPanel(wxPanel * parent, PDF * newpdf, bool presentationmode)
       : wxPanel(parent,-1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_NONE) {
    m_parent = parent;
    pm=presentationmode;
 	m_text = new wxStaticText(this, -1, wxT(""), wxPoint(0, 0));
	page=1;
	black=false;
 	pdf=newpdf;
 	if (pm) {
		SetBackgroundColour(wxColour(0,0,0));
	}
 	update();
}

void PDFPanel::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}

void PDFPanel::update() {
	if (!pdf->isLoaded()) {
		m_text->SetLabel(wxT(""));
		//~ m_text->SetLabel(wxT("No file!"));
		return;
	}
	else if (!pm) {
		
		m_text->SetLabel(wxString::Format(wxT("Page %i of %i"), page, pdf->n_pages()));
	}
	int iw, ih; 
    GetClientSize(&iw,&ih);
    pdf->render(slide, iw, ih, page);


    Refresh();
	
}
void PDFPanel::OnResize(wxSizeEvent &e) {
	update();
}

void PDFPanel::OnPaint(wxPaintEvent& event) {
	wxPaintDC dc(this);
	if (black)
		return;
	int iw, ih;

	// center view
	GetClientSize(&iw, &ih);
	iw = (iw - slide.GetWidth())/2;
	ih = (ih - slide.GetHeight())/2;
	if (slide.Ok()) {
		dc.DrawBitmap(slide, iw, ih, true);
	} 

}

BEGIN_EVENT_TABLE(PDFPanel, wxPanel)
	EVT_PAINT(PDFPanel::OnPaint)
	EVT_SIZE(PDFPanel::OnResize)
END_EVENT_TABLE()

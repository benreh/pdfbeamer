#include <wx/stattext.h>
#include "pdf_panel.h"

PDFPanel::PDFPanel(wxPanel * parent, PDF * newpdf)
       : wxPanel(parent,-1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
    m_parent = parent;
 	m_text = new wxStaticText(this, -1, wxT(""), wxPoint(40, 60));
	page=1;
 	pdf=newpdf;
 	update();
}

void PDFPanel::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}

void PDFPanel::update() {
	if (!pdf->isLoaded()) {
		m_text->SetLabel(wxT("No file!"));
		return;
	}
	m_text->SetLabel(wxString::Format(wxT("Page %i of %i"), page, pdf->n_pages()));
	int iw, ih; 
    GetClientSize(&iw,&ih);
    pdf->render(slide, iw, ih, page);
	//~ slide=wxBitmap();


    Refresh();
	
}
void PDFPanel::OnResize(wxSizeEvent &e) {
	//~ std::cerr << "resize" << std::endl;
	update();
}

void PDFPanel::OnPaint(wxPaintEvent& event) {
	wxPaintDC dc(this);

	int iw, ih;

	// center view
	GetClientSize(&iw, &ih);
	iw = (iw - slide.GetWidth())/2;
	ih = (ih - slide.GetHeight())/2;
	//~ std::cerr << iw << " " << ih << std::endl;
	if (slide.Ok()) {
		std::cerr << "draw bitmap ok" << std::endl;
		//~ dc.DrawBitmap(slide, 0, 0, false);
		dc.DrawBitmap(slide, iw, ih, true);
	} else {
		//~ std::cerr << "bitmap Nok" << std::endl;
	}

}

BEGIN_EVENT_TABLE(PDFPanel, wxPanel)
	EVT_PAINT(PDFPanel::OnPaint)
	EVT_SIZE(PDFPanel::OnResize)
END_EVENT_TABLE()

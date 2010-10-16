#include <wx/stattext.h>
#include "pdf_panel.h"

PDFPanel::PDFPanel(wxPanel * parent, PDF * newpdf)
       : wxPanel(parent,-1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
    m_parent = parent;
 	m_text = new wxStaticText(this, -1, wxT(""), wxPoint(40, 60));
	page=0;
 	pdf=newpdf;
 	update();
}

void PDFPanel::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}

void PDFPanel::update() {
	if (!pdf->isLoaded()) {
		m_text->SetLabel(wxT("No file loaded!"));
		return;
	}
	m_text->SetLabel(wxString::Format(wxT("Page %i of %i"), page, pdf->n_pages()));
	
}

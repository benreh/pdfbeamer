//~ #include <wx/stattext.h>
#include <wx/wx.h>
#include <wx/panel.h>
#include "panel.h"

LeftPanel::LeftPanel(wxPanel * parent, PDF * pdf)
       : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
    m_parent = parent;
	
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	pdfpanel = new PDFPanel(this, pdf);

	hbox->Add(pdfpanel, 1, wxEXPAND | wxALL, 5);

	SetSizer(hbox);

	this->Centre();
}
void LeftPanel::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}

void LeftPanel::update(){
	pdfpanel->update();
	pdfpanel->update();
}


RightPanel::RightPanel(wxPanel * parent, PDF * pdf)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition, 
         wxSize(270, 150), wxBORDER_SUNKEN) {
}
void RightPanel::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}
void RightPanel::update() {

}

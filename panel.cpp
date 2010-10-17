//~ #include <wx/stattext.h>
#include <wx/wx.h>
#include <wx/panel.h>
#include "mainwindow.h"
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
}


RightPanel::RightPanel(wxPanel * parent, PDF * newpdf)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition, 
         wxSize(270, 150), wxBORDER_SUNKEN) {

	m_parent=parent;

	pdf=newpdf;
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

	pdfpanel = new PDFPanel(this, pdf);

	vbox->Add(pdfpanel, 10, wxEXPAND | wxALL, 5);
	slider = new wxSlider(this, ID_SLIDER, 1, 1, 1);
	vbox->Add(slider, 1, wxEXPAND | wxALL, 0);

	showb = new wxButton(this, wxID_ANY, wxT("<< show"), wxPoint(20, 20));
	vbox->Add(showb,1,wxEXPAND | wxALL,0);
	vbox->SetSizeHints(this);
	SetSizer(vbox);
	Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(RightPanel::OnScroll));
	Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RightPanel::OnShowB));
}
void RightPanel::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}
void RightPanel::update() {
	slider->SetRange(1,pdf->n_pages());
	pdfpanel->update();
}
void RightPanel::OnScroll(wxScrollEvent& event){
	pdfpanel->page=slider->GetValue();
	pdfpanel->update();
	
}
void RightPanel::OnShowB(wxCommandEvent & WXUNUSED(event)) {
	Mainwindow * mw = (Mainwindow *) m_parent->GetParent();
	mw->show(pdfpanel->page);
}

#include "beamer.h"


Beamer::Beamer(wxFrame* parent, PDF * pdf)
 : wxFrame(NULL, wxID_ANY, wxT("Beamer"), wxDefaultPosition, wxSize(200, 100)) {
	 //~ SetBackgroundColour(wxColour(0,0,0));
	m_parent = new wxPanel(parent, wxID_ANY);

	pdfpanel= new PDFPanel((wxPanel*)this, pdf);

	fs=false;

	vbox = new wxBoxSizer(wxVERTICAL);
	hereb = new wxButton(this, wxID_ANY, wxT("here"), wxPoint(20, 20));

	//~ hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);
	m_text = new wxStaticText(this, -1, wxT("Drag me to your audience and press"), wxPoint(0, 0),wxSize(200, 100));

	
	vbox->Add(m_text, 2, wxEXPAND | wxALL, 0);
	vbox->Add(hereb, 1, wxEXPAND | wxALL, 0);
	vbox->Add(pdfpanel, 3, wxEXPAND | wxALL, 0);

	Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Beamer::OnHereB));

	vbox->SetSizeHints(this);
	SetSizer(vbox);
	this->Centre();
}

void Beamer::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}
void Beamer::update() {
	pdfpanel->update();
}
void Beamer::OnHereB(wxCommandEvent & WXUNUSED(event)) {
	maximize();
}
void Beamer::maximize() {
	fs=true;
	hereb->Hide();
	m_text->Hide();
	SetBackgroundColour(wxColour(0,0,0));
	ShowFullScreen(true);
}

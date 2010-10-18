//      Copyright 2010 Benjamin Reh <ich@benjaminreh.de>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.

#include "mainwindow.h"
#include "beamer.h"


Beamer::Beamer(wxFrame* parent, PDF * pdf, wxFrame* myinoff_parent)
 : wxFrame(NULL, wxID_ANY, wxT("Beamer"), wxDefaultPosition, wxSize(200, 100)) {
	m_parent = new wxPanel(parent, wxID_ANY);

	inoff_parent=myinoff_parent;

	pdfpanel= new PDFPanel((wxPanel*)this, pdf, true);

	fs=false;

	vbox = new wxBoxSizer(wxVERTICAL);
	hereb = new wxButton(this, wxID_ANY, wxT("here"), wxPoint(20, 20));

	m_text = new wxStaticText(this, -1, wxT("Drag me to your audience and press"), wxPoint(0, 0),wxSize(200, 100));

	
	vbox->Add(m_text, 2, wxEXPAND | wxALL, 0);
	vbox->Add(hereb, 1, wxEXPAND | wxALL, 0);
	vbox->Add(pdfpanel, 3, wxEXPAND | wxALL, 0);

	Connect(wxEVT_CLOSE_WINDOW,  wxCommandEventHandler(Beamer::OnQuit));
	Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Beamer::OnHereB));

	vbox->SetSizeHints(this);
	SetSizer(vbox);
	this->Centre();
}

void Beamer::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}
void Beamer::OnQuit(wxCommandEvent& event) {
	Mainwindow * mw = (Mainwindow *) inoff_parent;
	delete mw->beamer;
	mw->beamer=NULL;
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

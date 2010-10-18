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

#include <wx/wx.h>
#include <wx/panel.h>
#include "mainwindow.h"
#include "panel.h"

LeftPanel::LeftPanel(wxPanel * parent, PDF * pdf)
       : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
    m_parent = parent;
	
	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

	pdfpanel = new PDFPanel(this, pdf);

	vbox->Add(pdfpanel, 10, wxEXPAND | wxALL, 0);

	prevb = new wxButton(this, ID_PREV, wxT("<< prev"));
	nextb = new wxButton(this, ID_NEXT, wxT("next >>"));
	blackb = new wxToggleButton(this, ID_BLACK, wxT("black"));
	
	hbox1->Add(prevb, 1, wxEXPAND | wxALL, 5);
	hbox1->Add(nextb, 1, wxEXPAND | wxALL, 5);
	
	hbox2->Add(blackb, 1, wxEXPAND | wxALL, 5);

	vbox->Add(hbox1, 1, wxEXPAND | wxALL, 0);
	vbox->Add(hbox2, 1, wxEXPAND | wxALL, 0);
	SetSizer(vbox);

	Connect(ID_PREV, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnPrevB));
	Connect(ID_NEXT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnNextB));
	Connect(ID_BLACK, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnBlackB));

	this->Centre();
}
void LeftPanel::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}

void LeftPanel::update(){
	pdfpanel->update();
}

void LeftPanel::OnBlackB(wxCommandEvent & WXUNUSED(event)) {
	Mainwindow * mw = (Mainwindow *) m_parent->GetParent();
	mw->beamer->pdfpanel->black=blackb->GetValue();
	mw->beamer->pdfpanel->update();
}
void LeftPanel::OnNextB(wxCommandEvent & WXUNUSED(event)) {
	Mainwindow * mw = (Mainwindow *) m_parent->GetParent();
	mw->show(pdfpanel->page+1);
}
void LeftPanel::OnPrevB(wxCommandEvent & WXUNUSED(event)){
	Mainwindow * mw = (Mainwindow *) m_parent->GetParent();
	mw->show(pdfpanel->page-1);
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

	showb = new wxButton(this, ID_SHOW, wxT("<< show"), wxPoint(20, 20));
	vbox->Add(showb,1,wxEXPAND | wxALL,0);
	vbox->SetSizeHints(this);
	SetSizer(vbox);
	Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(RightPanel::OnScroll));
	Connect(ID_SHOW, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RightPanel::OnShowB));
	showb->SetFocus();
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

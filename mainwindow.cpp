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
#include <wx/progdlg.h>

Mainwindow::Mainwindow(const wxString& title)
 : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 400)) {
	
	m_parent = new wxPanel(this, wxID_ANY);

	beamer = new Beamer(NULL, &pdf, this);
	
	beamer->Show();

	menubar = new wxMenuBar;
	file = new wxMenu;
	file->Append(wxID_OPEN, wxT("&Open"));
	file->AppendSeparator();
	file->Append(wxID_EXIT, wxT("&Quit"));

	cache = new wxMenu;
	cache->Append(ID_cleanup, wxT("&Clean"));
	cache->Append(ID_prerender, wxT("&Pre-Render"));
	
	presenter = new wxMenu;
	presenter->Append(ID_restart, wxT("&Restart"));
	presenter->AppendSeparator();

	scale = new wxMenu;
	scale->Append(ID_pre1_1, wxT("reset 1:1"));
	scale->AppendSeparator();
	scale->Append(ID_pre16_9, wxT("16:9"));
	scale->Append(ID_pre9_16, wxT("9:16"));
	scale->Append(ID_pre4_3, wxT("4:3"));
	scale->Append(ID_pre3_4, wxT("3:4"));

	presenter->AppendSubMenu(scale, wxT("&Scale"));
	
	menubar->Append(file, wxT("&File"));
	menubar->Append(presenter, wxT("&Presenter"));
	menubar->Append(cache, wxT("&Cache"));
	SetMenuBar(menubar);


	Connect(wxEVT_CLOSE_WINDOW,  wxCommandEventHandler(Mainwindow::OnQuit));
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnQuit));
	Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnOpen));
	Connect(ID_restart, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnRestart));
	Connect(ID_pre1_1, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnPresenterScale1_1));
	Connect(ID_pre4_3, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnPresenterScale4_3));
	Connect(ID_pre3_4, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnPresenterScale3_4));
	Connect(ID_pre16_9, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnPresenterScale16_9));
	Connect(ID_pre9_16, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnPresenterScale9_16));
	Connect(ID_prerender, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnPrerender));
	Connect(ID_cleanup, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnCleanup));

	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	m_lp = new LeftPanel(m_parent, &pdf);
	m_rp = new RightPanel(m_parent,&pdf);

	hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
	hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(hbox);

	this->Centre();
}

void Mainwindow::OnPresenterScale1_1(wxCommandEvent& event) {
	beamer->pdfpanel->stretch=1.0;
	beamer->update();
}
void Mainwindow::OnPresenterScale4_3(wxCommandEvent& event) {
	beamer->pdfpanel->stretch*=4.0/3.0;
	beamer->update();
}
void Mainwindow::OnPresenterScale3_4(wxCommandEvent& event) {
	beamer->pdfpanel->stretch*=3.0/4.0;
	beamer->update();
}
void Mainwindow::OnPresenterScale16_9(wxCommandEvent& event) {
	beamer->pdfpanel->stretch*=16.0/9.0;
	beamer->update();
}
void Mainwindow::OnPresenterScale9_16(wxCommandEvent& event) {
	beamer->pdfpanel->stretch*=9.0/16.0;
	beamer->update();
}

void Mainwindow::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	wxPuts(wxT("Quit"));
	if (beamer)
		beamer->Close();
 	Destroy();
}

void Mainwindow::OnOpen(wxCommandEvent& WXUNUSED(event)) {
	wxFileDialog * openFileDialog = new wxFileDialog(this, wxT("Select presentation"), wxT(""), wxT(""), wxT("PDF files |*.pdf;*.PDF"));
	
	if (openFileDialog->ShowModal() == wxID_OK){
		wxString filename = openFileDialog->GetPath();
		wxPuts(filename);
		pdf.load(filename.mb_str());
 	}
 	show(1);
	update();
	
}
void Mainwindow::OnCleanup(wxCommandEvent& WXUNUSED(event)) {
	pdf.clean_cache();
	update();
}
void Mainwindow::OnPrerender(wxCommandEvent& WXUNUSED(event)) {
	wxProgressDialog * pd;
	int flags = wxPD_APP_MODAL | wxPD_AUTO_HIDE | wxPD_CAN_SKIP | wxPD_ELAPSED_TIME | wxPD_REMAINING_TIME | wxPD_SMOOTH;
	pd = new wxProgressDialog(wxT("Rendering"),wxT("Prerendering slides..."), (pdf.n_pages()-1)*3, this,flags);
	pd->Show();
	bool skip=false;
	for (int i = 1; i < pdf.n_pages() && !skip; i++) {
		m_lp->pdfpanel->prerender(i);
		pd->Update(i*3+0,wxT(""), &skip);
		m_rp->pdfpanel->prerender(i);
		pd->Update(i*3+1,wxT(""), &skip);
		beamer->pdfpanel->prerender(i);
		pd->Update(i*3+2,wxT(""), &skip);
	}
	delete pd;
	
}
void Mainwindow::OnRestart(wxCommandEvent& WXUNUSED(event)) {
	if (beamer) {
		beamer->Close();
	}
	beamer = new Beamer(NULL, &pdf, this);
	beamer->Show();
	update();
	
}
void Mainwindow::OnUpdate(wxCommandEvent& event) {

	event.Skip();
}
void Mainwindow::update() {
	m_lp->update();
	m_rp->update();
	if (beamer)
		beamer->update();
}
void Mainwindow::show(int page) {
	page=pdf.limitpage(page);
	int nextpage = pdf.limitpage(page+1);
	m_lp->pdfpanel->page=page;
	if (beamer)
		beamer->pdfpanel->page=page;

	m_rp->slider->SetValue(nextpage);
	m_rp->pdfpanel->page=nextpage;
	
	update();
}

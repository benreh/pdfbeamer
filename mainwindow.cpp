#include "mainwindow.h"


Mainwindow::Mainwindow(const wxString& title)
 : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 400)) {
	
	m_parent = new wxPanel(this, wxID_ANY);

	beamer = new Beamer(NULL, &pdf);
	
	beamer->Show();

	menubar = new wxMenuBar;
	file = new wxMenu;
	file->Append(wxID_OPEN, wxT("&Open"));
	file->AppendSeparator();
	file->Append(wxID_EXIT, wxT("&Quit"));
	
	menubar->Append(file, wxT("&File"));
	SetMenuBar(menubar);

	//~ Connect(wxEVT_CLOSE_WINDOW,  wxCommandEventHandler(Mainwindow::OnQuit));
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnQuit));
	Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnOpen));

	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	m_lp = new LeftPanel(m_parent, &pdf);
	m_rp = new RightPanel(m_parent,&pdf);

	hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
	hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(hbox);

	this->Centre();
}

void Mainwindow::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	wxPuts(wxT("Quit"));
	if (beamer)
		delete beamer;
 	Close(true);
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

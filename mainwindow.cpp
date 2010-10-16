#include "mainwindow.h"


Mainwindow::Mainwindow(const wxString& title)
 : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180)) {
	m_parent = new wxPanel(this, wxID_ANY);

	menubar = new wxMenuBar;
	file = new wxMenu;
	file->Append(wxID_EXIT, wxT("&Quit"));
	menubar->Append(file, wxT("&File"));
	SetMenuBar(menubar);

	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Mainwindow::OnQuit));


	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	m_lp = new LeftPanel(m_parent);
	m_rp = new RightPanel(m_parent);

	hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
	hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(hbox);

	this->Centre();

}

void Mainwindow::OnQuit(wxCommandEvent& WXUNUSED(event)) {
  Close(true);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <wx/wx.h>
#include "pdf.h"
#include "panel.h"
#include "beamer.h"

class Mainwindow : public wxFrame
{
public:
	Mainwindow(const wxString& title);

	LeftPanel *m_lp;
	RightPanel *m_rp;
	wxPanel *m_parent;

	void OnQuit(wxCommandEvent& WXUNUSED(event));
	void OnOpen(wxCommandEvent& WXUNUSED(event));

	void show(int page);

 	wxMenuBar *menubar;
	wxMenu *file;

	Beamer * beamer;

	void OnUpdate(wxCommandEvent& event);
	void update();

	PDF pdf;

};

#endif

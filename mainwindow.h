#include <wx/wx.h>
#include "pdf.h"
#include "panel.h"

class Mainwindow : public wxFrame
{
public:
	Mainwindow(const wxString& title);

	LeftPanel *m_lp;
	RightPanel *m_rp;
	wxPanel *m_parent;

	void OnQuit(wxCommandEvent& WXUNUSED(event));
	void OnOpen(wxCommandEvent& WXUNUSED(event));

 	wxMenuBar *menubar;
	wxMenu *file;

	void OnUpdate(wxCommandEvent& event);
	void update();

	PDF pdf;

};

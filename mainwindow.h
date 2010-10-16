#include <wx/wx.h>
#include "panel.h"

class Mainwindow : public wxFrame
{
public:
    Mainwindow(const wxString& title);

	LeftPanel *m_lp;
    RightPanel *m_rp;
    wxPanel *m_parent;

};

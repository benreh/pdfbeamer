#include <wx/wx.h>
#include <wx/panel.h>
#include "pdf_panel.h"


class LeftPanel : public wxPanel {
public:
    LeftPanel(wxPanel *parent, PDF * pdf);
	PDFPanel * pdfpanel; 
	void OnUpdate(wxCommandEvent& event);
	void update();
};

class RightPanel : public wxPanel {
public:
    RightPanel(wxPanel *parent, PDF * pdf);
    PDFPanel * pdfpanel; 
	void OnUpdate(wxCommandEvent& event);
	void update();

};

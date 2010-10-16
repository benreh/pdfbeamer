#include <wx/wx.h>
#include <wx/panel.h>
#include "pdf.h"

class PDFPanel : public wxPanel {
public:
    PDFPanel(wxPanel *parent, PDF * newpdf);


	PDF * pdf;
	wxStaticText *m_text;
	int page;

	void OnUpdate(wxCommandEvent& event);
	void update();
};

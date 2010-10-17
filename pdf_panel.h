#include <wx/wx.h>
#include <wx/panel.h>
#include "pdf.h"

class PDFPanel : public wxPanel {
public:
    PDFPanel(wxPanel *parent, PDF * newpdf);



	void OnUpdate(wxCommandEvent& event);
	void OnPaint(wxPaintEvent& event);
	void OnResize(wxSizeEvent &e);
	void update();

private:
	PDF * pdf;
	wxStaticText *m_text;
	int page;
	wxBitmap slide;
	DECLARE_EVENT_TABLE()
	
};

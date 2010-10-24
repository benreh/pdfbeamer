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

#ifndef PDF_PANEL_H
#define PDF_PANEL_H
#include <wx/wx.h>
#include <wx/panel.h>
#include "pdf.h"

class PDFPanel : public wxPanel {
public:
    PDFPanel(wxPanel *parent, PDF * newpdf, bool presentationmode=false);

	void OnUpdate(wxCommandEvent& event);
	void OnPaint(wxPaintEvent& event);
	void OnResize(wxSizeEvent &e);
	void update();
	int page;
	bool pm;
	bool black;
	double stretch;

private:
	PDF * pdf;
	wxStaticText *m_text;
	wxBitmap * slide;
	DECLARE_EVENT_TABLE()
	
};
#endif

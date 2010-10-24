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

#ifndef BEAMER_H
#define BEAMER_H

#include <wx/wx.h>
#include "pdf_panel.h"

class Beamer : public wxFrame
{
public:
	Beamer(wxFrame* parent, PDF * pdf, int mdis, wxFrame* myinoff_parent);

	wxFrame* inoff_parent;
	void OnQuit(wxCommandEvent& event);
	void OnUpdate(wxCommandEvent& event);
	void OnHereB(wxCommandEvent & WXUNUSED(event));
	void update();
	void maximize();

	int dis;
	wxBoxSizer *vbox;
	wxButton *hereb;
	wxStaticText *m_text;
	PDFPanel * pdfpanel;
	bool fs;
	
};
#endif

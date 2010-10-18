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

#ifndef PANEL_H
#define PANEL_H
#include <wx/wx.h>
#include <wx/panel.h>
#include "pdf_panel.h"
#include <wx/tglbtn.h>

class LeftPanel : public wxPanel {
public:
    LeftPanel(wxPanel *parent, PDF * pdf);
	PDFPanel * pdfpanel;
	void OnUpdate(wxCommandEvent& event);
	void update();
	wxButton * nextb;
	wxButton * prevb;
	wxToggleButton * blackb;
	void OnNextB(wxCommandEvent & WXUNUSED(event));
	void OnPrevB(wxCommandEvent & WXUNUSED(event));
	void OnBlackB(wxCommandEvent & WXUNUSED(event));
};

class RightPanel : public wxPanel {
public:
    RightPanel(wxPanel *parent, PDF * newpdf);
	PDFPanel * pdfpanel;
	PDF * pdf;
	wxSlider *slider;
	wxButton * showb;
	void OnUpdate(wxCommandEvent& event);
	void OnScroll(wxScrollEvent& event);
	void OnShowB(wxCommandEvent & WXUNUSED(event));
	void update();

};
const int ID_SLIDER = 100;
const int ID_SHOW = 101;
const int ID_PREV = 102;
const int ID_NEXT = 103;
const int ID_BLACK = 104;
#endif

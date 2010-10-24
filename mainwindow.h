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
	void OnPresenterScale1_1(wxCommandEvent& event);
	void OnPresenterScale4_3(wxCommandEvent& event);
	void OnPresenterScale3_4(wxCommandEvent& event);
	void OnPresenterScale16_9(wxCommandEvent& event);
	void OnPresenterScale9_16(wxCommandEvent& event);
	void OnRestart(wxCommandEvent& WXUNUSED(event));
	void OnCleanup(wxCommandEvent& WXUNUSED(event));
	void OnPrerender(wxCommandEvent& WXUNUSED(event));

	void show(int page);

 	wxMenuBar *menubar;
	wxMenu *file;
	wxMenu *presenter;
	wxMenu *scale;
	wxMenu *cache;

	Beamer * beamer;

	void OnUpdate(wxCommandEvent& event);
	void update();

	PDF pdf;

};
const int ID_restart=201;
const int ID_pre1_1=202;
const int ID_pre4_3=203;
const int ID_pre3_4=204;
const int ID_pre16_9=205;
const int ID_pre9_16=206;
const int ID_cleanup=207;
const int ID_prerender=208;

#endif

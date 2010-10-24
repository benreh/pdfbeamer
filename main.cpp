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

#include "main.h"
#include "mainwindow.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit(){
	if (!wxApp::OnInit())
        return false;
    Mainwindow *mw = new Mainwindow(wxT("pdfbeamer"));
    mw->Show(true);
    if (filename!=wxT("")) {
    	mw->pdf.load(filename.mb_str());
    	if (prerender){
			wxCommandEvent event;
			mw->OnPrerender(event);
		} 
		mw->update();
	}
    SetTopWindow(mw);

    return true;
}
void MyApp::OnInitCmdLine(wxCmdLineParser& parser) {
    parser.SetDesc (g_cmdLineDesc);
    // must refuse '/' as parameter starter or cannot use "/path" style paths
    parser.SetSwitchChars (wxT("-"));
}
 
bool MyApp::OnCmdLineParsed(wxCmdLineParser& parser) {
 
    // to get at your unnamed parameters use
    //~ wxArrayString files;
    //~ for (unsigned i = 0; i < parser.GetParamCount(); i++) {
            //~ files.Add(parser.GetParam(i));
    //~ }
 	filename= parser.GetParam(0);
 	prerender=parser.Found( wxT("p") );
    return true;
}

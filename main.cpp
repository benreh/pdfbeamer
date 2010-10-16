#include "main.h"
#include "mainwindow.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Mainwindow *mw = new Mainwindow(wxT("pdfbeamer"));
    mw->Show(true);

    return true;
}

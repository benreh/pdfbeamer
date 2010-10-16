#include <wx/wx.h>
#include <wx/panel.h>

class LeftPanel : public wxPanel {
public:
    LeftPanel(wxPanel *parent);


};

class RightPanel : public wxPanel {
public:
    RightPanel(wxPanel *parent);


};

const int ID_PLUS = 101;
const int ID_MINUS = 102;

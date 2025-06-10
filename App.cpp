#include "ui/mainFrame.h"
#include "App.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    auto *mainFrame = new MainFrame("RPG-Companion");

    mainFrame->SetClientSize(1440, 1024);
    mainFrame->Center();
    mainFrame->Show(true);
    return true;
}


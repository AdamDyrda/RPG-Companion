#include "ui/mainFrame.h"
#include "App.h"
#include <wx/wx.h>

#include "inc/StorageManager.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    StorageManager *sm =new StorageManager("Players");
    players = sm->LoadPlayers();
    auto *mainFrame = new MainFrame("RPG-Companion",players);
    mainFrame->SetClientSize(1440, 1024);
    mainFrame->Center();
    mainFrame->Show(true);
    return true;
}


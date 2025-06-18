#include "ui/mainFrame.h"
#include "App.h"
#include <wx/wx.h>

#include "inc/StorageManager.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    auto *sm =new StorageManager("Players");
    players = sm->LoadPlayers();
    auto *mainFrame = new MainFrame("RPG-Companion",players);
    mainFrame->Center();
    mainFrame->Show(true);
    return true;
}


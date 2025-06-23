#include "ui/mainFrame.h"
#include "App.h"
#include "inc/StorageManager.h"

#include <wx/wx.h>
#include <filesystem>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    std::string const filePath = std::filesystem::current_path().string()+"./Players.json";
    auto* const sm =new StorageManager(filePath);
    players = sm->LoadPlayers();
    auto *mainFrame = new MainFrame("RPG-Companion",players);
    mainFrame->Center();
    mainFrame->Show(true);
    return true;
}

int App::OnExit() {
    std::string const filePath = std::filesystem::current_path().string()+"./Players.json";
    auto * const sm = new StorageManager(filePath);
    nlohmann::json j;
    sm->SavePlayersToFile(j, *players);
    delete sm;
    wxApp::OnExit();
    return 0;
}


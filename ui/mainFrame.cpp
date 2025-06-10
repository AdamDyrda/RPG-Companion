#include "mainFrame.h"
#include <wx/wx.h>
#include <wx/filename.h>
#include <string>
#include <wx/tokenzr.h>

#include "../inc/NameGenerator.h"
#include "../inc/Player.h"

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    CreateControls();
    SetupSizers();
    BindEventHandlers();
}

bool MainFrame::LoadCustomFont() {
    wxString fontPath =wxFileName::GetCwd() + wxFileName::GetPathSeparator() +  "../data/AlmendraSC.ttf";
    if (!wxFont::AddPrivateFont(fontPath))
    {
        wxLogError("Failed to load custom font from %s", fontPath);
        return false;
    }
    return true;
}



void MainFrame::CreateControls() {
  if (!LoadCustomFont()) {
        wxLogStatus("Failed to load custom font, using default font.");
    }
    auto const HeadlineFont = wxFont(wxFontInfo(wxSize(0,64)).Bold().FaceName("Almendra SC"));
    auto const MainFont = wxFont(wxFontInfo(wxSize(0,24)).FaceName("Almendra SC"));
    auto const BACKGROUND_COLOR = wxColour(143, 185, 150);
    auto const BUTTON_COLOR = wxColour(236,210,187);
    auto const TEXT_COLOR = wxColour(17, 29, 19);

    wxMenu* mainMenu = new wxMenu();
    mainMenu->Append(wxID_EXIT, "&Exit\tCtrl-Q", "Exit the application");
    wxMenu* tools = new wxMenu();
    tools->Append(ID_NameGenerator, "Names Generator", "A tool for generating random names");
    menuBar = new wxMenuBar();
    menuBar->Append(mainMenu, "&File");
    menuBar->Append(tools, "&Tools");
    SetMenuBar(menuBar);
    wxAcceleratorEntry entries[1];
    entries[0].Set(wxACCEL_CTRL, (int)'Q', wxID_EXIT);
    wxAcceleratorTable accel(1, entries);
    SetAcceleratorTable(accel);

    //PLAYER PANEL
    playersPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
    playersPanel->SetFont(MainFont);
    playersPanel->SetBackgroundColour(BACKGROUND_COLOR);
    playersPanel->SetForegroundColour(TEXT_COLOR);
    //controls
    playersHeadlineText = new wxStaticText(playersPanel, wxID_ANY, "Players");
    playersHeadlineText->SetFont(HeadlineFont);

    playersListBox = new wxListBox(playersPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    playersListBox->SetBackgroundColour(BUTTON_COLOR);

    inspectPlayerButton = new wxButton(playersPanel, wxID_ANY, "Inspect Player", wxDefaultPosition, wxDefaultSize);
    inspectPlayerButton->SetBackgroundColour(BUTTON_COLOR);
    addPlayerButton = new wxButton(playersPanel, wxID_ANY, "Add Player",wxDefaultPosition,wxDefaultSize);
    addPlayerButton->SetBackgroundColour(BUTTON_COLOR);

   //DICEROLLER PANEL
    diceRollerPanel = new wxPanel(this);
    diceRollerPanel->SetFont(MainFont);
    diceRollerPanel->SetBackgroundColour(BACKGROUND_COLOR);
    diceRollerPanel->SetForegroundColour(TEXT_COLOR);

    //controls
    diceRollerHeadlineText = new wxStaticText(diceRollerPanel, wxID_ANY, "Dice Roller");
    diceRollerHeadlineText->SetFont(HeadlineFont);

    //ADD PLAYER DIALOG
    addPlayerDialog = new wxDialog(this, wxID_ANY, "Add Player");
    addPlayerDialog->SetBackgroundColour(BACKGROUND_COLOR);
    addPlayerDialog->SetForegroundColour(TEXT_COLOR);
    addPlayerDialog->SetFont(MainFont);
    auto* addPlayerDialogSizer = new wxBoxSizer(wxVERTICAL);
    auto* nameLabel = new wxStaticText(addPlayerDialog, wxID_ANY, "Name:");
    nameTextCtrl = new wxTextCtrl(addPlayerDialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    auto* button = new wxButton(addPlayerDialog, wxID_OK, "Add Player");
    auto* ocupationLabel = new wxStaticText(addPlayerDialog, wxID_ANY, "Occupation:");
    occupationTextCtrl = new wxTextCtrl(addPlayerDialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
     auto* birthplaceLabel = new wxStaticText(addPlayerDialog, wxID_ANY, "Birthplace:");
    birthplaceTextCtrl = new wxTextCtrl(addPlayerDialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    auto* residenceLabel = new wxStaticText(addPlayerDialog, wxID_ANY, "Residence:");
    residenceTextCtrl = new wxTextCtrl(addPlayerDialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    auto* pronounLabel = new wxStaticText(addPlayerDialog, wxID_ANY, "Pronoun:");
    pronounTextCtrl = new wxTextCtrl(addPlayerDialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    auto* ageLabel = new wxStaticText(addPlayerDialog, wxID_ANY, "Age:");
    ageTextCtrl = new wxTextCtrl(addPlayerDialog, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);

  button->SetBackgroundColour(BUTTON_COLOR);
    addPlayerDialogSizer->Add(nameLabel, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    addPlayerDialogSizer->Add(nameTextCtrl, 0, wxLEFT|wxRIGHT | wxEXPAND, 10);
    addPlayerDialogSizer->Add(ocupationLabel, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    addPlayerDialogSizer->Add(occupationTextCtrl, 0, wxLEFT|wxRIGHT | wxEXPAND, 10);
    addPlayerDialogSizer->Add(birthplaceLabel, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    addPlayerDialogSizer->Add(birthplaceTextCtrl, 0, wxLEFT|wxRIGHT | wxEXPAND, 10);
    addPlayerDialogSizer->Add(residenceLabel, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    addPlayerDialogSizer->Add(residenceTextCtrl, 0, wxLEFT|wxRIGHT | wxEXPAND, 10);
    addPlayerDialogSizer->Add(pronounLabel, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    addPlayerDialogSizer->Add(pronounTextCtrl, 0, wxLEFT|wxRIGHT | wxEXPAND, 10);
    addPlayerDialogSizer->Add(ageLabel, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    addPlayerDialogSizer->Add(ageTextCtrl, 0, wxLEFT|wxRIGHT | wxEXPAND, 10);
    addPlayerDialogSizer->AddSpacer(30);
    addPlayerDialogSizer->Add(button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 50);
    addPlayerDialog->SetSizer(addPlayerDialogSizer);
    addPlayerDialogSizer->SetSizeHints(addPlayerDialog);
    addPlayerDialog->Center();

    //GENERATE PLAYER NAMES DIALOG
    generatePlayerNamesDialog = new wxDialog(this, wxID_ANY, "Generate Player Names");
    generatePlayerNamesDialog->SetBackgroundColour(BACKGROUND_COLOR);
    generatePlayerNamesDialog->SetForegroundColour(TEXT_COLOR);
    generatePlayerNamesDialog->SetFont(MainFont);
    auto* generatePlayerNamesDialogSizer = new wxBoxSizer(wxVERTICAL);
    auto* namesGeneratorHeadlineText = new wxStaticText(generatePlayerNamesDialog, wxID_ANY, "Generate Player Names");
    nameList = new wxListBox(generatePlayerNamesDialog, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    nameList->SetBackgroundColour(BUTTON_COLOR);
    nameList->SetMinSize(wxSize(wxDefaultCoord, 200));
    nameList->SetFont(MainFont);
    wxString const genderChoices[] = {"female","male"};
    radioButtons = new wxRadioBox(generatePlayerNamesDialog, wxID_ANY, "Select Gender", wxDefaultPosition,
                                wxSize(wxDefaultSize), 2, genderChoices);
    generateNamesButton = new wxButton(generatePlayerNamesDialog, wxID_ANY, "Generate Names");
    doneButton = new wxButton(generatePlayerNamesDialog, wxID_ANY, "Done");
    namesGeneratorHeadlineText->SetFont(HeadlineFont);
    generateNamesButton->SetBackgroundColour(BUTTON_COLOR);
    doneButton->SetBackgroundColour(BUTTON_COLOR);

    generatePlayerNamesDialogSizer->Add(namesGeneratorHeadlineText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    generatePlayerNamesDialogSizer->Add(nameList, wxSizerFlags().Proportion(1).Expand().Border(wxALL, 10));
    generatePlayerNamesDialogSizer->Add(radioButtons, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10);
    generatePlayerNamesDialogSizer->Add(generateNamesButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    generatePlayerNamesDialogSizer->Add(doneButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    generatePlayerNamesDialog->SetSizer(generatePlayerNamesDialogSizer);
    generatePlayerNamesDialogSizer->SetSizeHints(generatePlayerNamesDialog);
    generatePlayerNamesDialog->Center();




}

void MainFrame::BindEventHandlers() {
    //TODO: Create and bind event handlers for buttons and other controls

    //menu events
    this->menuBar->Bind(wxEVT_MENU, [this](wxCommandEvent& event) {
        if (event.GetId() == wxID_EXIT) {
            this->Close(true);
            event.Skip();
        }
        if (event.GetId() == ID_NameGenerator) {

            auto ng = NameGenerator();

            generatePlayerNamesDialog->Show(true);
    }
});
    //PlayerPanel events
    this->addPlayerButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnAddPlayerButtonClicked(event);});

    //AddPlayerDialog events
    this->addPlayerDialog->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnDialogAddPlayerButtonClicked(event);}, wxID_OK);
    this->addPlayerDialog->Bind(wxEVT_CLOSE_WINDOW, [this](wxCloseEvent& event) {OnDialogClose(event);});

    //InspectPlayerButton events
    this->inspectPlayerButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnInspectPlayerButtonClicked(event);});
    //generatePlayerNamesDialog events
    this->generateNamesButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnGenerateNamesButtonClicked(event);});
    this->doneButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
        nameList->Clear();
        generatePlayerNamesDialog->Close();
        event.Skip();
    });
}

void MainFrame::PullDataFromFile() {
//TODO: Implement data loading from file
}


void MainFrame::SetupSizers() {

    auto* playersPanelSizer = new wxBoxSizer(wxVERTICAL);
    playersPanelSizer->Add(playersHeadlineText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    playersPanelSizer->AddStretchSpacer(0.5);
    playersPanelSizer->Add(playersListBox, wxSizerFlags().Proportion(7).Expand().Border(wxALL, 10));
    playersPanelSizer->AddStretchSpacer(2);
    playersPanelSizer->Add(inspectPlayerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    playersPanelSizer->Add(addPlayerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    playersPanelSizer->AddSpacer(10);
    playersPanel->SetSizer(playersPanelSizer);

    auto* diceRollerPanelSizer = new wxBoxSizer(wxVERTICAL);
    diceRollerPanelSizer->Add(diceRollerHeadlineText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    diceRollerPanel->SetSizer(diceRollerPanelSizer);


    SetBackgroundColour(wxColour(115, 149, 111));
    auto* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(playersPanel, 2, wxEXPAND | wxALL, 50);
    mainSizer->Add(diceRollerPanel, 3, wxEXPAND | wxALL, 50);
    SetSizer(mainSizer);
    SetSizeHints(mainSizer->GetMinSize().GetWidth(), mainSizer->GetMinSize().GetHeight());
    Layout();
}


void MainFrame::OnQuit(wxCloseEvent &event) {
    //twoje rzeczy
    event.Skip();
}

void MainFrame::OnDialogClose(wxCloseEvent &event) {
    addPlayerDialog->Hide();
    nameTextCtrl->SetValue("");
    occupationTextCtrl->SetValue("");
    birthplaceTextCtrl->SetValue("");
    residenceTextCtrl->SetValue("");
    pronounTextCtrl->SetValue("");
    ageTextCtrl->SetValue("");
    event.Skip();
}

void MainFrame::OnAddPlayerButtonClicked(wxCommandEvent &event) {
    addPlayerDialog->Show(true);
    addPlayerDialog->Center();
    event.Skip();
}

void MainFrame::OnDialogAddPlayerButtonClicked(wxCommandEvent &event) {
    AddPlayer();
    addPlayerDialog->Hide();
}


void MainFrame::OnInspectPlayerButtonClicked(wxCommandEvent &event) {
//TODO: Implement player inspection logic

}

void MainFrame::OnGenerateNamesButtonClicked(wxCommandEvent &event) {
    NameGenerator ng;
    nameList->Clear();
    wxString output;
    if (radioButtons->GetSelection() == 0) {
        output=ng.generateFemaleName(5);
    }
    if (radioButtons->GetSelection() == 1) {
        output=ng.generateMaleName(5);
    }
    for (const auto& name : wxStringTokenize(output, "\n")) {
        if (!name.IsEmpty()) {
            nameList->Append(name);
        }
    }



}


void MainFrame::AddPlayer() {
Player* player = new Player(
    nameTextCtrl->GetValue().ToStdString(),
    occupationTextCtrl->GetValue().ToStdString(),
    birthplaceTextCtrl->GetValue().ToStdString(),
    residenceTextCtrl->GetValue().ToStdString(),
    pronounTextCtrl->GetValue().ToStdString(),
    std::stoi(ageTextCtrl->GetValue().ToStdString()));


    playersListBox->Append(player->GetName());
    nameTextCtrl->SetValue("");
    occupationTextCtrl->SetValue("");
    birthplaceTextCtrl->SetValue("");
    residenceTextCtrl->SetValue("");
    pronounTextCtrl->SetValue("");
    ageTextCtrl->SetValue("");
};
void MainFrame::InspectPlayer() {

}

#include "mainFrame.h"
#include <wx/wx.h>
#include <wx/filename.h>
#include <string>
#include <wx/tokenzr.h>

#include "../inc/dice.h"
#include "../inc/NameGenerator.h"
#include "../inc/Player.h"

MainFrame::MainFrame(const wxString &title, std::vector<Player*>* players ) : wxFrame(nullptr, wxID_ANY, title) {
    this->players = players;
    CreateControls();
    SetupSizers();
    BindEventHandlers();
    //
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

    //MENU CONTROLS
    wxMenu* mainMenu = new wxMenu();
    mainMenu->Append(ID_About, "About","Get to know the application");
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

    D4rectangle = new wxStaticBox(diceRollerPanel, wxID_ANY, "D4",wxDefaultPosition,wxSize(200,200));
    auto* D4sizer = new wxBoxSizer(wxVERTICAL);
    D4result = new wxStaticText(D4rectangle, wxID_ANY, "",wxDefaultPosition,wxSize(130,wxDefaultCoord));
    D4result->SetFont(HeadlineFont);
    D4RollButton = new wxButton(D4rectangle, wxID_ANY, "Roll");
    D4RollButton->SetBackgroundColour(BUTTON_COLOR);

    D4sizer->AddSpacer(15);
    D4sizer->Add(D4result, 0, wxALIGN_CENTER_HORIZONTAL |wxALL,20);
    D4sizer->AddStretchSpacer(1);
    D4sizer->Add(D4RollButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D4rectangle->SetSizer(D4sizer);


    D6rectangle = new wxStaticBox(diceRollerPanel, wxID_ANY, "D6",wxDefaultPosition,wxSize(200,200));
    auto* D6sizer = new wxBoxSizer(wxVERTICAL);
    D6result = new wxStaticText(D6rectangle, wxID_ANY, "",wxDefaultPosition,wxSize(130,wxDefaultCoord));
    D6result->SetFont(HeadlineFont);
    D6RollButton = new wxButton(D6rectangle, wxID_ANY, "Roll");
    D6RollButton->SetBackgroundColour(BUTTON_COLOR);

    D6sizer->AddSpacer(15);
    D6sizer->Add(D6result, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D6sizer->AddStretchSpacer(1);
    D6sizer->Add(D6RollButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D6rectangle->SetSizer(D6sizer);

    D10rectangle = new wxStaticBox(diceRollerPanel, wxID_ANY, "D10",wxDefaultPosition,wxSize(200,200));
    auto* D10sizer = new wxBoxSizer(wxVERTICAL);
    D10result = new wxStaticText(D10rectangle, wxID_ANY, "",wxDefaultPosition,wxSize(130,wxDefaultCoord));
    D10result->SetFont(HeadlineFont);
    D10RollButton = new wxButton(D10rectangle, wxID_ANY, "Roll");
    D10RollButton->SetBackgroundColour(BUTTON_COLOR);

    D10sizer->AddSpacer(15);
    D10sizer->Add(D10result, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D10sizer->AddStretchSpacer(1);
    D10sizer->Add(D10RollButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D10rectangle->SetSizer(D10sizer);

    D12rectangle = new wxStaticBox(diceRollerPanel, wxID_ANY, "D12",wxDefaultPosition,wxSize(200,200));
    auto* D12sizer = new wxBoxSizer(wxVERTICAL);
  D12result = new
          wxStaticText(D12rectangle, wxID_ANY, "", wxDefaultPosition, wxSize(130, wxDefaultCoord));
  D12result->SetFont(HeadlineFont);
    D12RollButton = new wxButton(D12rectangle, wxID_ANY, "Roll");
    D12RollButton->SetBackgroundColour(BUTTON_COLOR);

    D12sizer->AddSpacer(15);
    D12sizer->Add(D12result, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D12sizer->AddStretchSpacer(1);
    D12sizer->Add(D12RollButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D12rectangle->SetSizer(D12sizer);

    D20rectangle = new wxStaticBox(diceRollerPanel, wxID_ANY, "D20",wxDefaultPosition,wxSize(200,200));
    auto* D20sizer = new wxBoxSizer(wxVERTICAL);
  D20result = new wxStaticText(D20rectangle, wxID_ANY, "", wxDefaultPosition, wxSize(130, wxDefaultCoord));
  D20result->SetFont(HeadlineFont);
    D20RollButton = new wxButton(D20rectangle, wxID_ANY, "Roll");
    D20RollButton->SetBackgroundColour(BUTTON_COLOR);

    D20sizer->AddSpacer(15);
    D20sizer->Add(D20result, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D20sizer->AddStretchSpacer(1);
    D20sizer->Add(D20RollButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D20rectangle->SetSizer(D20sizer);

    D100rectangle = new wxStaticBox(diceRollerPanel, wxID_ANY, "D100",wxDefaultPosition,wxSize(200,200));
    auto* D100sizer = new wxBoxSizer(wxVERTICAL);
    D100result = new wxStaticText(D100rectangle, wxID_ANY, "", wxDefaultPosition,wxSize(130, wxDefaultCoord));
    D100result->SetFont(HeadlineFont);
    D100RollButton = new wxButton(D100rectangle, wxID_ANY, "Roll");
    D100RollButton->SetBackgroundColour(BUTTON_COLOR);


    D100sizer->AddSpacer(15);
    D100sizer->Add(D100result, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D100sizer->AddStretchSpacer(1);
    D100sizer->Add(D100RollButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 20);
    D100rectangle->SetSizer(D100sizer);



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
    generatePlayerNamesDialog->Center();
    generatePlayerNamesDialog->SetSizer(generatePlayerNamesDialogSizer);
    generatePlayerNamesDialogSizer->SetSizeHints(generatePlayerNamesDialog);




}

void MainFrame::BindEventHandlers() {


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
        if(event.GetId()==ID_About) {
            wxLogMessage(wxID_ANY,"This app was created by Adam :P");

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
    //DICE ROLLER EVENTS
    this->D4RollButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnD4ButtonClicked(event);});
    this->D6RollButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnD6ButtonClicked(event);});
    this->D10RollButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnD10ButtonClicked(event);});
    this->D12RollButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnD12ButtonClicked(event);});
    this->D20RollButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnD20ButtonClicked(event);});
    this->D100RollButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnD100ButtonClicked(event);});
}

void MainFrame::PullDataFromFile() {
//TODO: Implement data loading from file
}


void MainFrame::SetupSizers() {
    //players part
    auto* playersPanelSizer = new wxBoxSizer(wxVERTICAL);
    playersPanelSizer->Add(playersHeadlineText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    playersPanelSizer->AddStretchSpacer(0.5);
    playersPanelSizer->Add(playersListBox, wxSizerFlags().Proportion(7).Expand().Border(wxALL, 10));
    playersPanelSizer->AddStretchSpacer(2);
    playersPanelSizer->Add(inspectPlayerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    playersPanelSizer->Add(addPlayerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    playersPanelSizer->AddSpacer(10);
    playersPanel->SetSizer(playersPanelSizer);
    //dice roller part
    auto* diceRollerPanelSizer = new wxBoxSizer(wxVERTICAL);
    diceRollerPanelSizer->Add(diceRollerHeadlineText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    auto* D4D6sizer = new wxBoxSizer(wxHORIZONTAL);
    D4D6sizer->Add(D4rectangle, 0,  wxALL, 10);
    D4D6sizer->Add(D6rectangle, 0,  wxALL, 10);
    auto* D10D12sizer = new wxBoxSizer(wxHORIZONTAL);
    diceRollerPanelSizer->Add(D4D6sizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    D10D12sizer->Add(D10rectangle, 0,  wxALL, 10);
    D10D12sizer->Add(D12rectangle, 0, wxALL, 10);
    diceRollerPanelSizer->Add(D10D12sizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    auto D20D100sizer = new wxBoxSizer(wxHORIZONTAL);
    D20D100sizer->Add(D20rectangle,0,  wxALL, 10);
    D20D100sizer->Add(D100rectangle, 0 | wxALL, 10);
    diceRollerPanelSizer->AddSpacer(20);
    diceRollerPanelSizer->Add(D20D100sizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    diceRollerPanelSizer->AddStretchSpacer(1);

    diceRollerPanel->SetSizer(diceRollerPanelSizer);


    //main sizer part
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

void MainFrame::OnD4ButtonClicked(wxCommandEvent &event) {
    D4result->SetLabel(dice::rollD4((1)));
    event.Skip();
}

void MainFrame::OnD6ButtonClicked(wxCommandEvent &event) {
    D6result->SetLabel(dice::rollD6((1)));
    event.Skip();
}

void MainFrame::OnD10ButtonClicked(wxCommandEvent &event) {
    D10result->SetLabel(dice::rollD10((1)));
    event.Skip();
}

void MainFrame::OnD12ButtonClicked(wxCommandEvent &event) {
    D12result->SetLabel(dice::rollD12((1)));
    event.Skip();
}

void MainFrame::OnD20ButtonClicked(wxCommandEvent &event) {
    D20result->SetLabel(dice::rollD20((1)));
    event.Skip();
}

void MainFrame::OnD100ButtonClicked(wxCommandEvent &event) {
    D100result->SetLabel(dice::rollD100((1)));
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
if (playersListBox->GetSelection()!=wxNOT_FOUND) {
    int selection = playersListBox->GetSelection();
    p

}

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

    bool fieldsChecked = nameTextCtrl->GetValue().ToStdString().empty() | occupationTextCtrl->GetValue().ToStdString()=="" |
    birthplaceTextCtrl->GetValue().ToStdString() == "" | residenceTextCtrl->GetValue().ToStdString() == "" |
    pronounTextCtrl->GetValue().ToStdString() == "" | !ageTextCtrl->GetValue().IsNumber();
    if (fieldsChecked) {
        wxLogError("Some of the fields are missing or age is not a number",wxOK);
    }else {
        Player* player = new Player(
            nameTextCtrl->GetValue().ToStdString(),
            occupationTextCtrl->GetValue().ToStdString(),
            birthplaceTextCtrl->GetValue().ToStdString(),
            residenceTextCtrl->GetValue().ToStdString(),
            pronounTextCtrl->GetValue().ToStdString(),
            std::stoi(ageTextCtrl->GetValue().ToStdString()));
        players->push_back(player);

        playersListBox->Append(player->GetName());
        nameTextCtrl->SetValue("");
        occupationTextCtrl->SetValue("");
        birthplaceTextCtrl->SetValue("");
        residenceTextCtrl->SetValue("");
        pronounTextCtrl->SetValue("");
        ageTextCtrl->SetValue("");
    }
    };
void MainFrame::InspectPlayer() {

}

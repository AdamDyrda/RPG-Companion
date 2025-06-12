//
// Created by adame on 6/10/2025.
//

#include "playerFrame.h"

PlayerFrame::PlayerFrame(wxString windowTitle, Player *player, wxFont mainFont):wxFrame(nullptr,wxID_ANY,windowTitle) {
  //  CreateControls();
//    BindEventHandlers();
    //SetupSizers();
    this->mainFont= mainFont;
    this->player = player;
}


void PlayerFrame::CreateControls() {
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    auto* mainWindow = new wxScrolledWindow(this, wxID_ANY);
    auto* nameLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Name:"));
    nameCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* occupationLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Occupation:"));
    occupationCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* birthplaceLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Birthplace:"));
    birthplaceCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* residenceLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Residence:"));
    residenceCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* pronounLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Pronoun:"));
    pronounCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* ageLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Age:"));
    ageCtrl = new wxTextCtrl(mainWindow, wxID_ANY);

    auto* strengthLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Strength:"));
    strengthCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* concentrationLabel = new wxStaticText(mainWindow, wxID_ANY,wxT("concentration"));
    concentrationCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* dexterityLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("dexterity:"));
    dexterityCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* inteligenceLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("inteligence:"));
    inteligenceCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* sizeLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("size:"));
    sizeCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* powerLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("power:"));
    powerCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* appearanceLabel = new wxStaticText(mainWindow,wxID_ANY, wxT("appearance:"));
    appearanceCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* educationLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("education:"));
    educationCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* hitPointsLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("hitpoints:"));
    hitPointsCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* magicPointsLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("magicpoints:"));
    magicPointsCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* luckPointsLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("luckpoints:"));
    luckPointsCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* luckLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("luck:"));
    luckCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* sanityLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("sanity:"));
    sanityCtrl = new wxTextCtrl(mainWindow, wxID_ANY);


    auto* accountingLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("accounting:"));
    accountingCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* anthropologyLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("anthropology:"));
    anthropologyCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* appraiseLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("appraise:"));
    appearanceCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* archaeologyLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("archaeology:"));
    archaeologyCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* artLabel= new wxStaticText(mainWindow, wxID_ANY, wxT("art:"));
    artCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* charmLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("charm:"));
    charmCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* climbLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("climb:"));
    climbCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* creditRatingLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("credit:"));
    creditRatingCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* chtulhuMythosLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("chtulhu:"));
    chtulhuMythosCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* disguiseLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("disguise:"));
    disguiseCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* dodgeLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("dodge:"));
    dodgeCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* driveAutoLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("drive:"));
    driveAutoCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* electricalRepairLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("electrical:"));
    electricalRepairCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* fastTalkLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("fasttalk:"));
    fastTalkCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* fightingLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("fighting:"));
    fightingCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* firearmsHandgunLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("firearm(Handgun):"));
    firearmsHandgunCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* firearmsRifleLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("firearms:"));
    firearmsRifleCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* firstAidLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("firstAid:"));
    firstAidCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* historyLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("history:"));
    historyCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* intimidateLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("intime:"));
    intimidateCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* jumpLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("jump:"));
    jumpCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* languageOtherLabel = new wxStaticText(mainWindow, wxID_ANY,wxT("Language(Other):"));
    languageOtherCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* languageOwnLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Language(Other):"));
    languageOwnCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* lawLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("Law:"));
    lawCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* libraryUseLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("libraryLabel:"));
    libraryUseCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* listenLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("listen:"));
    listenCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* locksmithLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("locksmith:"));
    locksmithCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* mechanicalRepairLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("mechanical repair:"));
    mechanicalRepairCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* medicineLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("medicine:"));
    medicineCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* naturalWorldLabel = new wxStaticText(mainWindow, wxID_ANY,wxT("naturalWorld:"));
    naturalWorldCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* navigatelabel = new wxStaticText(mainWindow, wxID_ANY, wxT("navigatelabel:"));
    navigateCtrl= new wxTextCtrl(mainWindow, wxID_ANY);
    auto* ocultLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("ocult:"));
    occultCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* persuadeLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("persuade:"));
    persuadeCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* pilotLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("pilot:"));
    pilotCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* psychoanalysisLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("psychoanalysis:"));
    psychoanalysisCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* psychologyLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("psychology:"));
    psychologyCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* rideLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("ride:"));
    rideCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* sicenceLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("sicence:"));
    scienceCtrl= new wxTextCtrl(mainWindow, wxID_ANY);
    auto* sleightOfHandLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("sleightOfHand:"));
    sleightOfHandCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* spotHiddenLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("spotHidden:"));
    spotHiddenCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* stealthLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("stealth:"));
    stealthCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* survivalLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("survival:"));
    survivalCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* swimLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("swim:"));
    swimCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* throwingLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("throwing:"));
    throwingCtrl = new wxTextCtrl(mainWindow, wxID_ANY);
    auto* trackLabel = new wxStaticText(mainWindow, wxID_ANY, wxT("track:"));
    trackCtrl = new wxTextCtrl(mainWindow, wxID_ANY);








}

void PlayerFrame::LoadPlayerData() {
nameCtrl->SetValue(wxT(&player.));
}

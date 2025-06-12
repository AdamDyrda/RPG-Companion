//
// Created by adame on 6/10/2025.
//

#ifndef PLAYERFRAME_H
#define PLAYERFRAME_H

#include <wx/wx.h>
#include "../inc/player.h"



class PlayerFrame : public wxFrame{
public:

    PlayerFrame(wxString windowTitle,Player* player,wxFont mainFont);
    private:
    Player* player;
    wxFont mainFont;
    void CreateControls();
    void LoadPlayerData();
    void BindEventHandlers();
    void SetupSizers();




    wxTextCtrl* nameCtrl;
    wxTextCtrl* occupationCtrl;
    wxTextCtrl* birthplaceCtrl;
    wxTextCtrl* residenceCtrl;
    wxTextCtrl* pronounCtrl;
    wxTextCtrl* ageCtrl;

    wxTextCtrl* strengthCtrl;
    wxTextCtrl* concentrationCtrl;
    wxTextCtrl* dexterityCtrl;
    wxTextCtrl* inteligenceCtrl;
    wxTextCtrl* sizeCtrl;
    wxTextCtrl* powerCtrl;
    wxTextCtrl* appearanceCtrl;
    wxTextCtrl* educationCtrl;
    wxTextCtrl* hitPointsCtrl;
    wxTextCtrl* magicPointsCtrl;
    wxTextCtrl* luckPointsCtrl;
    wxTextCtrl* luckCtrl;
    wxTextCtrl* sanityCtrl;

    wxTextCtrl* accountingCtrl;
    wxTextCtrl* anthropologyCtrl;
    wxTextCtrl* appraiseCtrl;
    wxTextCtrl* archaeologyCtrl;
    wxTextCtrl* artCtrl;
    wxTextCtrl* charmCtrl;
    wxTextCtrl* climbCtrl;
    wxTextCtrl* creditRatingCtrl;
    wxTextCtrl* chtulhuMythosCtrl;
    wxTextCtrl* disguiseCtrl;
    wxTextCtrl* dodgeCtrl;
    wxTextCtrl* driveAutoCtrl;
    wxTextCtrl* electricalRepairCtrl;
    wxTextCtrl* fastTalkCtrl;
    wxTextCtrl* fightingCtrl;
    wxTextCtrl* firearmsHandgunCtrl;
    wxTextCtrl* firearmsRifleCtrl;
    wxTextCtrl* firstAidCtrl;
    wxTextCtrl* historyCtrl;
    wxTextCtrl* intimidateCtrl;
    wxTextCtrl* jumpCtrl;
    wxTextCtrl* languageOtherCtrl;
    wxTextCtrl* languageOwnCtrl;
    wxTextCtrl* lawCtrl;
    wxTextCtrl* libraryUseCtrl;
    wxTextCtrl* listenCtrl;
    wxTextCtrl* locksmithCtrl;
    wxTextCtrl* mechanicalRepairCtrl;
    wxTextCtrl* medicineCtrl;
    wxTextCtrl* naturalWorldCtrl;
    wxTextCtrl* navigateCtrl;
    wxTextCtrl* occultCtrl;
    wxTextCtrl* persuadeCtrl;
    wxTextCtrl* pilotCtrl;
    wxTextCtrl* psychoanalysisCtrl;
    wxTextCtrl* psychologyCtrl;
    wxTextCtrl* rideCtrl;
    wxTextCtrl* scienceCtrl;
    wxTextCtrl* sleightOfHandCtrl;
    wxTextCtrl* spotHiddenCtrl;
    wxTextCtrl* stealthCtrl;
    wxTextCtrl* survivalCtrl;
    wxTextCtrl* swimCtrl;
    wxTextCtrl* throwingCtrl;
    wxTextCtrl* trackCtrl;


};



#endif //PLAYERFRAME_H

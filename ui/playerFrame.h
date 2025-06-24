/**
 *@file playerFrame.h
 *@brief header file for the PlayerFrame class, which provides a GUI for displaying and editing player information.
 **/

#ifndef PLAYERFRAME_H
#define PLAYERFRAME_H

#include <wx/wx.h>
#include "../inc/player.h"


/**
 * @class PlayerFrame
 * @brief An interactive frame for displaying and editing player information.
 */
class PlayerFrame final : public wxFrame{
public:
    /**
     * @brief Constructor for the PlayerFrame class.
    * @param windowTitle The title of the window.
    * @param player A pointer to the Player object containing player data.
    * @param mainFont reference of an wxFont object that defines the main font used for the controls.
    * @param headlineFont reference of an wxFont object that defines the font used for headlines in the frame.
     */
    PlayerFrame(const wxString &windowTitle,Player* player,const wxFont &mainFont, const wxFont &headlineFont);
    private:
    Player* player;
    wxFont mainFont;
        wxFont headlineFont;

    /**
     * @brief initializes the frame controls
     */
    void CreateControls();
    /**
     * @brief Loads player data into the controls.
     */
    void LoadPlayerData();
    /**
     * @brief Updates the player object with data from the controls.
     */
    void UpdatePlayer();

    /**
     *@brief Event handler for the delete player button click event.
     *@param event The wxCommandEvent object containing event data.
     */
     void OnClose(wxCloseEvent &event);

    /**
     * @brief Binds event handlers to the controls.
     */
    void BindEventHandlers();
    /**
     * @brief Sets up the sizers for layout management.
     */
    void SetupSizers();

    wxScrolledWindow* mainWindow;

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
        wxButton* deletePlayerButton;
        wxBoxSizer* nameSizer;
    wxBoxSizer* occupationSizer;
        wxBoxSizer* birthplaceSizer;
    wxBoxSizer* residenceSizer;
        wxBoxSizer* pronounSizer;
        wxBoxSizer* ageSizer;
        wxBoxSizer* strengthSizer;
    wxBoxSizer* concentrationSizer;
        wxBoxSizer* dexteritySizer;
    wxBoxSizer* inteligenceSizer;
        wxBoxSizer* sizeSizer;
    wxBoxSizer* powerSizer;
        wxBoxSizer* appearanceSizer;
    wxBoxSizer* educationSizer;
        wxBoxSizer* hitPointsSizer;
    wxBoxSizer* magicPointsSizer;
        wxBoxSizer* luckPointsSizer;
    wxBoxSizer* luckSizer;
        wxBoxSizer* sanitySizer;
    wxBoxSizer* accountingSizer;
        wxBoxSizer* anthropologySizer;
    wxBoxSizer* appraiseSizer;
        wxBoxSizer* archaeologySizer;
    wxBoxSizer* artSizer;
        wxBoxSizer* charmSizer;
        wxBoxSizer* climbSizer;
        wxBoxSizer* creditRatingSizer;
        wxBoxSizer* chtulhuMythosSizer;
    wxBoxSizer* disguiseSizer;
        wxBoxSizer* dodgeSizer;
    wxBoxSizer* driveAutoSizer;
        wxBoxSizer* electricalRepairSizer;
        wxBoxSizer* fastTalkSizer;
    wxBoxSizer* fightingSizer;
        wxBoxSizer* firearmsHandgunSizer;
    wxBoxSizer* firearmsRifleSizer;
        wxBoxSizer* firstAidSizer;
    wxBoxSizer* historySizer;
        wxBoxSizer* intimidateSizer;
    wxBoxSizer* jumpSizer;
        wxBoxSizer* languageOtherSizer;
    wxBoxSizer* languageOwnSizer;
        wxBoxSizer* lawSizer;
    wxBoxSizer* libraryUseSizer;
        wxBoxSizer* listenSizer;
    wxBoxSizer* locksmithSizer;
        wxBoxSizer* mechanicalRepairSizer;
    wxBoxSizer* medicineSizer;
        wxBoxSizer* naturalWorldSizer;
        wxBoxSizer* occultSizer;
        wxBoxSizer* persuadeSizer;
    wxBoxSizer* pilotSizer;
        wxBoxSizer* psychoanalysisSizer;
    wxBoxSizer* psychologySizer;
        wxBoxSizer* rideSizer;
    wxBoxSizer* scienceSizer;
        wxBoxSizer* sleightOfHandSizer;
    wxBoxSizer* spotHiddenSizer;
        wxBoxSizer* stealthSizer;
    wxBoxSizer* survivalSizer;
        wxBoxSizer* swimSizer;
    wxBoxSizer* throwingSizer;
        wxBoxSizer* trackSizer;
        wxBoxSizer* navigateSizer;

        wxBoxSizer* mainSizer;




};



#endif //PLAYERFRAME_H

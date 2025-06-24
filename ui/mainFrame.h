/**
 *@file mainFrame.h
 *@brief header file for the MainFrame class, which provides the main GUI for the RPG Companion application.
 **/
#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <wx/wx.h>
#include <wx/grid.h>
#include "../inc/Player.h"
#include "playerFrame.h"

/** * @class MainFrame
 * @brief The main frame of the RPG Companion application, providing a GUI for managing players and rolling dice.
 */
class MainFrame final : public wxFrame {
    public:
    /**
         * @brief Constructor for the MainFrame class.
         * @param title The title of the main window.
         * @param players A pointer to a vector of Player objects that will be managed by this frame.
         */
    MainFrame (const wxString& title,std::vector<Player*>*);
    ~MainFrame()=default;
    private:

        enum {
            ID_NameGenerator = wxID_HIGHEST + 1,
            ID_About
        };

        std::vector<Player*>* players;

    /**
         * @brief Initializes the main frame controls.
         */
        void CreateControls();
    /**
         * @brief Binds event handlers to the controls.
         */
        void BindEventHandlers();
    /**
         * @brief Loads player data from a file and populates the players list box.
         */
        void loadPlayers();
    /**
     * @brief Sets sizers for layout management.
     */
        void SetupSizers();

    /**
     * @brief Loads a custom font for the application.
     * @return  Returns true if the custom font was loaded successfully, false otherwise.
     */
    bool LoadCustomFont();


    /**
     * @brief event handler for the Add Player button click event.
     * @param event wxWindow event triggered when the "Add Player" button is clicked.
     */
    void OnAddPlayerButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the Add player dialog triggers on add button click event.
     * @param event wxWidnow event triggered when the "Delete Player" button is clicked.
     */
    void OnDialogAddPlayerButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the Delete Player button click event.
     * @param event wxWindow event triggered when the "Delete Player" button is clicked.
     */
    void OnDeletePlayerButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the Inspect Player button click event.
     * @param event wxWindow event triggered when the "Inspect Player" button is clicked.
     */
    void OnInspectPlayerButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the Generate Player Names dialog triggers on generate names button click event.
     * @param event wxWindow event triggered when the "Generate Names" button is clicked.
     */
    void OnGenerateNamesButtonClicked(wxCommandEvent & event);

    /**
     * @brief event handler triggered when the main window is closed.
     * @param event wxCloseEvent triggered when the main window is closed.
     */
    void OnQuit(wxCloseEvent &event);

    /**
     * @brief event handler triggered when the add player dialog is closed.
     * @param event wxCloseEvent triggered when the dialog is closed.
     */
    void OnDialogClose(wxCloseEvent &event);

    /**
     * @brief event handler for the D4 button click event, calls a roll function.
     * @param event wxCommandEvent triggered when the D4 button is clicked.
     */
    void OnD4ButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the D6 button click event, calls a roll function .
     * @param event wxCommandEvent triggered when the D6 button is clicked.
     */
    void OnD6ButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the D10 button click event, calls a roll function.
     * @param event wxCommandEvent triggered when the D10 button is clicked.
     */
    void OnD10ButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the D12 button click event, calls a roll function.
     * @param event wxCommandEvent triggered when the D12 button is clicked.
     */
    void OnD12ButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the D20 button click event, calls a roll function.
     * @param event wxCommandEvent triggered when the D20 button is clicked.
     */
    void OnD20ButtonClicked(wxCommandEvent &event);

    /**
     * @brief event handler for the D100 button click event, calls a roll function.
     * @param event wxCommandEvent triggered when the D100 button is clicked.
     */
    void OnD100ButtonClicked(wxCommandEvent &event);

    /**
     * @brief Adds a new player to the players list and updates the UI.
     */
    void AddPlayer();

    /**
     * @brief Inspects the selected player and opens a new frame to display their details.
     */
    void InspectPlayer();

    /**
     * @brief Deletes the selected player from the players list and updates the UI.
     */
    void DeletePlayer();



    wxMenuBar* menuBar;
        wxFont mainFont;
        wxFont headlineFont;
        wxPanel* playersPanel;
        wxPanel* diceRollerPanel;
        wxListBox* playersListBox;
        wxStaticText* playersHeadlineText;
        wxStaticText* diceRollerHeadlineText;
        wxButton* addPlayerButton;
        wxButton* deletePlayerButton;
        wxButton* inspectPlayerButton;
        wxDialog* addPlayerDialog;
        wxDialog* generatePlayerNamesDialog;
        wxTextCtrl* nameTextCtrl;
        wxTextCtrl* occupationTextCtrl;
        wxTextCtrl* birthplaceTextCtrl;
        wxTextCtrl* residenceTextCtrl;
        wxTextCtrl* pronounTextCtrl;
        wxTextCtrl* ageTextCtrl;
        wxButton *generateNamesButton;
        wxButton *doneButton;
        wxRadioBox *radioButtons;
        wxListBox *nameList;
        wxStaticBox* D4rectangle;
        wxStaticBox* D6rectangle;
        wxStaticBox* D10rectangle;
        wxStaticBox* D12rectangle;
        wxStaticBox* D20rectangle;
        wxStaticBox* D100rectangle;
        wxStaticText* D4result;
        wxStaticText* D6result;
        wxStaticText* D10result;
        wxStaticText* D12result;
        wxStaticText* D20result;
        wxStaticText* D100result;
        wxButton* D4RollButton;
        wxButton* D6RollButton;
        wxButton* D10RollButton;
        wxButton* D12RollButton;
        wxButton* D20RollButton;
        wxButton* D100RollButton;





};


#endif // MAINFRAME_H

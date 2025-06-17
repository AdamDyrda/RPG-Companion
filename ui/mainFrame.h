#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <wx/wx.h>
#include <wx/grid.h>
#include "../inc/Player.h"
#include "playerFrame.h"


class MainFrame : public wxFrame {
    public:
    MainFrame (const wxString& title,std::vector<Player*>*);

    private:
        enum {
            ID_NameGenerator = wxID_HIGHEST + 1,
            ID_About
        };

        std::vector<Player*>* players;

        void CreateControls();
        void BindEventHandlers();
        void loadPlayers();
        void SetupSizers();
        bool LoadCustomFont();

        void OnAddPlayerButtonClicked(wxCommandEvent &event);
        void OnDialogAddPlayerButtonClicked(wxCommandEvent &event);
        void OnInspectPlayerButtonClicked(wxCommandEvent &event);
        void OnGenerateNamesButtonClicked(wxCommandEvent & event);
        void OnQuit(wxCloseEvent &event);
        void OnDialogClose(wxCloseEvent &event);
        void OnD4ButtonClicked(wxCommandEvent &event);
        void OnD6ButtonClicked(wxCommandEvent &event);
        void OnD10ButtonClicked(wxCommandEvent &event);
        void OnD12ButtonClicked(wxCommandEvent &event);
        void OnD20ButtonClicked(wxCommandEvent &event);
        void OnD100ButtonClicked(wxCommandEvent &event);

        void AddPlayer();
        void InspectPlayer();



    wxMenuBar* menuBar;
        wxFont mainFont;
        wxFont headlineFont;
        wxPanel* playersPanel;
        wxPanel* diceRollerPanel;
        wxListBox* playersListBox;
        wxStaticText* playersHeadlineText;
        wxStaticText* diceRollerHeadlineText;
        wxButton* addPlayerButton;
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

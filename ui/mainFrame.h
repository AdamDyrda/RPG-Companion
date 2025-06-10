#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <queue>
#include <wx/wx.h>
#include <wx/grid.h>


class MainFrame : public wxFrame {
    public:
    MainFrame (const wxString& title);

    private:
        enum {
            ID_NameGenerator = wxID_HIGHEST + 1,
        };

        void CreateControls();
        void BindEventHandlers();
        void PullDataFromFile();
        void SetupSizers();
        bool LoadCustomFont();

        void OnAddPlayerButtonClicked(wxCommandEvent &event);
        void OnDialogAddPlayerButtonClicked(wxCommandEvent &event);
        void OnInspectPlayerButtonClicked(wxCommandEvent &event);
        void OnGenerateNamesButtonClicked(wxCommandEvent & event);
        void OnQuit(wxCloseEvent &event);
        void OnDialogClose(wxCloseEvent &event);

        void AddPlayer();
        void InspectPlayer();



    wxMenuBar* menuBar;
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




};


#endif // MAINFRAME_H

/**
 *@file App.h
 *@brief App class header file, responsible for initializing the application and managing player data storage.
 **/

#ifndef APP_H
#define APP_H

#include <wx/wx.h>

/**
 * @class App
 * @brief a wxWidgets application class that initializes the application and manages player data.
 *
 * This class is responsible for setting up the application, loading player data, and managing the lifecycle of the application.
 */
class App : public wxApp {
    public:
    /** @brief function intilializes the application.
     */
        bool OnInit() override;
    /** @brief function cleans up the application and calls data save before exit.
     */
        int OnExit() override;
private:
    std::vector<Player*>* players;
};
#endif //APP_H

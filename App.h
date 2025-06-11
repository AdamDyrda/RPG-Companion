//
// Created by adame on 5/26/2025.
//

#ifndef APP_H
#define APP_H

#include <wx/wx.h>

class App : public wxApp {
    public:
        bool OnInit();
private:
    std::vector<Player*>* players;
};
#endif //APP_H

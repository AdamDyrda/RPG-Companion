

#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <vector>

#include "Player.h"

class StorageManager {
    public:
        StorageManager(std::string filePath);
        ~StorageManager();
        void SaveDataToFile();
        std::vector<Player*>* LoadPlayers();
    private:
        std::vector<Player*> players;
        std::string filePath;


};



#endif //STORAGEMANAGER_H

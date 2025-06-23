

#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <vector>
#include <nlohmann/json.hpp>
#include "Player.h"

class StorageManager {
    public:
        StorageManager(std::string filePath);
        ~StorageManager()=default;
        void SavePlayersToFile(nlohmann::json& j, const std::vector<Player*>& players) const;
        std::vector<Player*>* LoadPlayers() const;
    private:

        std::vector<Player*> players;
        std::string filePath;


};



#endif //STORAGEMANAGER_H

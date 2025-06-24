/**
 *@file StorageManager.h
 *@brief header file for the StorageManager class, which is responsible for saving and loading player data to and from a JSON file.
 **/

#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <vector>
#include <nlohmann/json.hpp>
#include "Player.h"

/** * @class StorageManager
 * @brief Class responsible for saving and loading player data to and from a JSON file.
 *
 * The StorageManager class provides methods to save a vector of Player objects to a JSON file
 * and load them back into a vector of Player pointers.
 */
class StorageManager {
    public:
        /**
         * @brief Constructor for the StorageManager class.
         * @param filePath The path to the JSON file where player data will be saved and loaded.
         */
        StorageManager(std::string filePath);

        /**
         * @brief Destructor for the StorageManager class.
         */
        ~StorageManager()=default;
    /**
         * @brief Saves the player data to a JSON file.
         * @param players A vector of Player pointers to be saved.
         */
        void SavePlayersToFile(nlohmann::json& j, const std::vector<Player*>& players) const;
    /**
         * @brief Loads player data from a JSON file.
         * @return A vector of Player pointers loaded from the file.
         */
        std::vector<Player*>* LoadPlayers() const;
    private:

        std::vector<Player*> players;
        std::string filePath;


};



#endif //STORAGEMANAGER_H

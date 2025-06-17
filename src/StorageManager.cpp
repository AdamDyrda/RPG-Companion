
#include "../inc/StorageManager.h"

#include <format>

StorageManager::StorageManager(std::string filePath) {
this->filePath = std::move(filePath);
}

std::vector<Player *>* StorageManager::LoadPlayers() {
    std::vector<Player *>* players = new std::vector<Player *>();
    return players;
}


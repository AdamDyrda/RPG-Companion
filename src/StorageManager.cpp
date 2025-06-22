
#include "../inc/StorageManager.h"

#include <fstream>

StorageManager::StorageManager(std::string filePath) {
this->filePath = std::move(filePath);
}

void StorageManager::SavePlayersToFile(nlohmann::json& j,const std::vector<Player *>& players) {
    j["players"] = nlohmann::json::array();
    for (const auto& player : players) {
        nlohmann::json playerJson;
        playerJson["name"] = player->GetName();
        playerJson["occupation"] = player->GetOccupation();
        playerJson["birthplace"] = player->GetBirthplace();
        playerJson["residence"] = player->GetResistance();
        playerJson["pronoun"] = player->GetPronoun();
        playerJson["age"] = player->GetAge();
        playerJson["strength"] = player->GetStrength();
        playerJson["concentration"] = player->GetConcentration();
        playerJson["dexterity"] = player->GetDexterity();
        playerJson["intelligence"] = player->GetIntelligence();
        playerJson["size"] = player->GetSize();
        playerJson["power"] = player->GetPower();
        playerJson["appearance"] = player->GetAppearance();
        playerJson["education"] = player->GetEducation();
        playerJson["hitPoints"] = player->GetHitPoints();
        playerJson["magicPoints"] = player->GetMagicPoints();
        playerJson["luckPoints"] = player->GetLuckPoints();
        playerJson["luck"] = player->GetLuck();
        playerJson["sanity"] = player->GetSanity();
        playerJson["accounting"] = player->GetAccounting();
        playerJson["anthropology"] = player->GetAnthropology();
        playerJson["apprise"] = player->GetApprise();
        playerJson["archaeology"] = player->GetArchaeology();
        playerJson["art"] = player->GetArt();
        playerJson["charm"] = player->GetCharm();
        playerJson["climb"] = player->GetClimb();
        playerJson["creditRating"] = player->GetCreditRating();
        playerJson["cthulhuMythos"] = player->GetCtulhuMythos();
        playerJson["disguise"] = player->GetDisguise();
        playerJson["dodge"] = player->GetDodge();
        playerJson["driveAuto"] = player->GetDriveAuto();
        playerJson["electricalRepair"] = player->GetElectricalRepair();
        playerJson["fastTalk"] = player->GetFastTalk();
        playerJson["fighting"] = player->GetFighting();
        playerJson["firearmsHandgun"] = player->GetFirearmsHandgun();
        playerJson["firearmsRifle"] = player->GetFirearmsRifle();
        playerJson["firstAid"] = player->GetFirstAid();
        playerJson["history"] = player->GetHistory();
        playerJson["intimidate"] = player->GetIntimidate();
        playerJson["jump"] = player->GetJump();
        playerJson["languageOther"] = player->GetLanguageOther();
        playerJson["languageOwn"] = player->GetLanguageOwn();
        playerJson["law"] = player->GetLaw();
        playerJson["libraryUse"] = player->GetLibraryUse();
        playerJson["listen"] = player->GetListen();
        playerJson["locksmith"] = player->GetLocksmith();
        playerJson["mechanicalRepair"] = player->GetMechanicalRepair();
        playerJson["medicine"] = player->GetMedicine();
        playerJson["naturalWorld"] = player->GetNaturalWorld();
        playerJson["occult"] = player->GetOccult();
        playerJson["navigate"] = player->GetNavigate();
        playerJson["persuade"] = player->GetPersuade();
        playerJson["pilot"] = player->GetPilot();
        playerJson["psychoanalysis"] = player->GetPsychoanalysis();
        playerJson["psychology"] = player->GetPsychology();
        playerJson["ride"] = player->GetRide();
        playerJson["science"] = player->GetScience();
        playerJson["sleightOfHand"] = player->GetSleightOfHand();
        playerJson["spotHidden"] = player->GetSpotHidden();
        playerJson["stealth"] = player->GetStealth();
        playerJson["survival"] = player->GetSurvival();
        playerJson["swim"] = player->GetSwim();
        playerJson["throwing"] = player->GetThrowing();
        playerJson["track"] = player->GetTrack();
        j["players"].push_back(playerJson);
        delete player;
        std::cout<<"player deleted"<<std::endl;
    }
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
    } else {
        throw std::runtime_error("Could not open file for writing: " + filePath);
    }

}

std::vector<Player *>* StorageManager::LoadPlayers() {
    auto* players = new std::vector<Player *>();
    nlohmann::json j;
    std::ifstream
    file(filePath);
    if (file.is_open()) {
        file >> j;
        file.close();
    } else {
        std::cout << "Could not open file for reading: " << filePath << std::endl;
        return players;
    }
    if (j.contains("players")) {
        for (const auto& playerJson : j["players"]) {
            auto* player = new Player(
                playerJson["name"].get<std::string>(),
                playerJson["occupation"].get<std::string>(),
                playerJson["birthplace"].get<std::string>(),
                playerJson["residence"].get<std::string>(),
                playerJson["pronoun"].get<std::string>(),
                playerJson["age"].get<int>()
            );
            try {
            player->SetStrength(std::to_string(playerJson["strength"].get<int>()));
            }catch (const std::exception& e) {
                std::cerr << "Error setting strength: " << e.what() << std::endl;
            }

            player->SetConcentration(std::to_string(playerJson["concentration"].get<int>()));
            player->SetDexterity(std::to_string(playerJson["dexterity"].get<int>()));
            player->SetIntelligence(std::to_string(playerJson["intelligence"].get<int>()));
            player->SetSize(std::to_string(playerJson["size"].get<int>()));
            player->SetPower(std::to_string(playerJson["power"].get<int>()));
            player->SetAppearance(std::to_string(playerJson["appearance"].get<int>()));
            player->SetEducation(std::to_string(playerJson["education"].get<int>()));
            player->SetHitPoints(std::to_string(playerJson["hitPoints"].get<int>()));
            player->SetMagicPoints(std::to_string(playerJson["magicPoints"].get<int>()));
            player->SetLuckPoints(std::to_string(playerJson["luckPoints"].get<int>()));
            player->SetLuck(std::to_string(playerJson["luck"].get<int>()));
            player->SetSanity(std::to_string(playerJson["sanity"].get<int>()));
            player->SetAccounting(std::to_string(playerJson["accounting"].get<int>()));
            player->SetAnthropology(std::to_string(playerJson["anthropology"].get<int>()));
            player->SetApprise(std::to_string(playerJson["apprise"].get<int>()));
            player->SetArcheology(std::to_string(playerJson["archaeology"].get<int>()));
            player->SetArt(std::to_string(playerJson["art"].get<int>()));
            player->SetCharm(std::to_string(playerJson["charm"].get<int>()));
            player->SetClimb(std::to_string(playerJson["climb"].get<int>()));
            player->SetCreditRating(std::to_string(playerJson["creditRating"].get<int>()));
            player->SetCThulhuMythos(std::to_string(playerJson["cthulhuMythos"].get<int>()));
            player->SetDisguise(std::to_string(playerJson["disguise"].get<int>()));
            player->SetDodge(std::to_string(playerJson["dodge"].get<int>()));
            player->SetDriveAuto(std::to_string(playerJson["driveAuto"].get<int>()));
            player->SetElectricalRepair(std::to_string(playerJson["electricalRepair"].get<int>()));
            player->SetFastTalk(std::to_string(playerJson["fastTalk"].get<int>()));
            player->SetFighting(std::to_string(playerJson["fighting"].get<int>()));
            player->SetFirearmsHandgun(std::to_string(playerJson["firearmsHandgun"].get<int>()));
            player->SetFirearmsRifle(std::to_string(playerJson["firearmsRifle"].get<int>()));
            player->SetFirstAid(std::to_string(playerJson["firstAid"].get<int>()));
            player->SetHistory(std::to_string(playerJson["history"].get<int>()));
            player->SetIntimidate(std::to_string(playerJson["intimidate"].get<int>()));
            player->SetJump(std::to_string(playerJson["jump"].get<int>()));
            player->SetLanguageOther(std::to_string(playerJson["languageOther"].get<int>()));
            player->SetLanguageOwn(std::to_string(playerJson["languageOwn"].get<int>()));
            player->SetLaw(std::to_string(playerJson["law"].get<int>()));
            player->SetLibraryUse(std::to_string(playerJson["libraryUse"].get<int>()));
            player->SetListen(std::to_string(playerJson["listen"].get<int>()));
            player->SetLocksmith(std::to_string(playerJson["locksmith"].get<int>()));
            player->SetMechanicalRepair(std::to_string(playerJson["mechanicalRepair"].get<int>()));
            player->SetMedicine(std::to_string(playerJson["medicine"].get<int>()));
            player->SetNaturalWorld(std::to_string(playerJson["naturalWorld"].get<int>()));
            player->SetOccult(std::to_string(playerJson["occult"].get<int>()));
            player->SetNavigate(std::to_string(playerJson["navigate"].get<int>()));
            player->SetPersuade(std::to_string(playerJson["persuade"].get<int>()));
            player->SetPilot(std::to_string(playerJson["pilot"].get<int>()));
            player->SetPsychoanalysis(std::to_string(playerJson["psychoanalysis"].get<int>()));
            player->SetPsychology(std::to_string(playerJson["psychology"].get<int>()));
            player->SetRide(std::to_string(playerJson["ride"].get<int>()));
            player->SetScience(std::to_string(playerJson["science"].get<int>()));
            player->SetSleightOfHand(std::to_string(playerJson["sleightOfHand"].get<int>()));
            player->SetSpotHidden(std::to_string(playerJson["spotHidden"].get<int>()));
            player->SetStealth(std::to_string(playerJson["stealth"].get<int>()));
            player->SetSurvival(std::to_string(playerJson["survival"].get<int>()));
            player->SetSwim(std::to_string(playerJson["swim"].get<int>()));
            player->SetThrowing(std::to_string(playerJson["throwing"].get<int>()));
            player->SetTrack(std::to_string(playerJson["track"].get<int>()));
            players->push_back(player);
        }
    }
            return players;
}



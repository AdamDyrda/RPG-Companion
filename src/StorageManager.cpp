
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
            player->SetStrength(playerJson["strength"].get<std::string>());
            player->SetConcentration(playerJson["concentration"].get<std::string>());
            player->SetDexterity(playerJson["dexterity"].get<std::string>());
            player->SetIntelligence(playerJson["std::stringelligence"].get<std::string>());
            player->SetSize(playerJson["size"].get<std::string>());
            player->SetPower(playerJson["power"].get<std::string>());
            player->SetAppearance(playerJson["appearance"].get<std::string>());
            player->SetEducation(playerJson["education"].get<std::string>());
            player->SetHitPoints(playerJson["hitPostd::strings"].get<std::string>());
            player->SetMagicPoints(playerJson["magicPostd::strings"].get<std::string>());
            player->SetLuckPoints(playerJson["luckPostd::strings"].get<std::string>());
            player->SetLuck(playerJson["luck"].get<std::string>());
            player->SetSanity(playerJson["sanity"].get<std::string>());
            player->SetAccounting(playerJson["accounting"].get<std::string>());
            player->SetAnthropology(playerJson["anthropology"].get<std::string>());
            player->SetApprise(playerJson["apprise"].get<std::string>());
            player->SetArcheology(playerJson["archaeology"].get<std::string>());
            player->SetArt(playerJson["art"].get<std::string>());
            player->SetCharm(playerJson["charm"].get<std::string>());
            player->SetClimb(playerJson["climb"].get<std::string>());
            player->SetCreditRating(playerJson["creditRating"].get<std::string>());
            player->SetCThulhuMythos(playerJson["cthulhuMythos"].get<std::string>());
            player->SetDisguise(playerJson["disguise"].get<std::string>());
            player->SetDodge(playerJson["dodge"].get<std::string>());
            player->SetDriveAuto(playerJson["driveAuto"].get<std::string>());
            player->SetElectricalRepair(playerJson["electricalRepair"].get<std::string>());
            player->SetFastTalk(playerJson["fastTalk"].get<std::string>());
            player->SetFighting(playerJson["fighting"].get<std::string>());
            player->SetFirearmsHandgun(playerJson["firearmsHandgun"].get<std::string>());
            player->SetFirearmsRifle(playerJson["firearmsRifle"].get<std::string>());
            player->SetFirstAid(playerJson["firstAid"].get<std::string>());
            player->SetHistory(playerJson["history"].get<std::string>());
            player->SetIntimidate(playerJson["std::stringimidate"].get<std::string>());
            player->SetJump(playerJson["jump"].get<std::string>());
            player->SetLanguageOther(playerJson["languageOther"].get<std::string>());
            player->SetLanguageOwn(playerJson["languageOwn"].get<std::string>());
            player->SetLaw(playerJson["law"].get<std::string>());
            player->SetLibraryUse(playerJson["libraryUse"].get<std::string>());
            player->SetListen(playerJson["listen"].get<std::string>());
            player->SetLocksmith(playerJson["locksmith"].get<std::string>());
            player->SetMechanicalRepair(playerJson["mechanicalRepair"].get<std::string>());
            player->SetMedicine(playerJson["medicine"].get<std::string>());
            player->SetNaturalWorld(playerJson["naturalWorld"].get<std::string>());
            player->SetOccult(playerJson["occult"].get<std::string>());
            player->SetNavigate(playerJson["navigate"].get<std::string>());
            player->SetPersuade(playerJson["persuade"].get<std::string>());
            player->SetPilot(playerJson["pilot"].get<std::string>());
            player->SetPsychoanalysis(playerJson["psychoanalysis"].get<std::string>());
            player->SetPsychology(playerJson["psychology"].get<std::string>());
            player->SetRide(playerJson["ride"].get<std::string>());
            player->SetScience(playerJson["science"].get<std::string>());
            player->SetSleightOfHand(playerJson["sleightOfHand"].get<std::string>());
            player->SetSpotHidden(playerJson["spotHidden"].get<std::string>());
            player->SetStealth(playerJson["stealth"].get<std::string>());
            player->SetSurvival(playerJson["survival"].get<std::string>());
            player->SetSwim(playerJson["swim"].get<std::string>());
            player->SetThrowing(playerJson["throwing"].get<std::string>());
            player->SetTrack(playerJson["track"].get<std::string>());
            players->push_back(player);
            return players;
        }
    }
}



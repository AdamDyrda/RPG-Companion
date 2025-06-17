//
// Created by adame on 3/16/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <wx/string.h>


#include "../inc/Weapon.h"


struct Stats{
  int strength;
  int concentration;
  int dexterity;
  int intelligence;
  int size;
  int power;
  int appearance;
  int education;
  int HitPoints;
  int MagicPoints;
  int LuckPoints;
  int Luck;
  int Sanity;
};

struct Skills{
  int accounting;
  int anthropology;
  int appraise;
  int archaeology;
  int art;
  int charm;
  int climb;
  int creditRating;
  int cthulhuMythos;
  int disguise;
  int dodge;
  int driveAuto;
  int electricalRepair;
  int fastTalk;
  int fighting;
  int firearmsHandgun;
  int firearmsRifle;
  int firstAid;
  int history;
  int intimidate;
  int jump;
  int languageOther;
  int languageOwn;
  int law;
  int libraryUse;
  int listen;
  int locksmith;
  int mechanicalRepair;
  int medicine;
  int naturalWorld;
  int navigate;
  int occult;
  int persuade;
  int pilot;
  int psychology;
  int psychoanalysis;
  int ride;
  int science;
  int sleightOfHand;
  int spotHidden;
  int stealth;
  int survival;
  int swim;
  int throwing;
  int track;

};


class Player {
private:
std::string name;
std::string occupation;
std::string birthplace;
std::string residence;
std::string pronoun;
int age;
Stats stats;
Skills skills;
std::vector<Weapon>weapons;


public:
  Player(std::string name, std::string occupation, std::string birthplace, std::string residence, std::string pronoun, int age) {
    this->name = std::move(name);
    this->occupation = std::move(occupation);
    this->birthplace = std::move(birthplace);
    this->residence = std::move(residence);
    this->pronoun = std::move(pronoun);
    this->age = age;
    this->stats = Stats();
    this->skills = Skills();

    stats.strength = 0;
    stats.concentration = 0;
    stats.dexterity = 0;
    stats.intelligence = 0;
    stats.size = 0;
    stats.power = 0;
    stats.appearance = 0;
    stats.education = 0;
    stats.HitPoints = 0;
    stats.MagicPoints = 0;
    stats.LuckPoints = 0;
    stats.Luck = 0;
    stats.Sanity = 0;

    skills.accounting = 5;
    skills.anthropology = 1;
    skills.appraise = 5;
    skills.archaeology = 1;
    skills.art = 5;
    skills.charm = 15;
    skills.climb = 20;
    skills.creditRating = 0;
    skills.cthulhuMythos = 0;
    skills.disguise = 5;
    skills.dodge = stats.dexterity/2;
    skills.driveAuto = 20;
    skills.electricalRepair = 10;
    skills.fastTalk = 5;
    skills.fighting = 25;
    skills.firearmsHandgun = 20;
    skills.firearmsRifle = 25;
    skills.firstAid = 30;
    skills.history = 5;
    skills.intimidate = 15;
    skills.jump = 20;
    skills.languageOther = 1;
    skills.languageOwn = stats.education;
    skills.law = 5;
    skills.libraryUse = 20;
    skills.listen = 20;
    skills.locksmith = 1;
    skills.mechanicalRepair = 10;
    skills.medicine = 1;
    skills.naturalWorld = 10;
    skills.navigate = 10;
    skills.occult = 5;
    skills.persuade = 10;
    skills.pilot = 1;
    skills.psychoanalysis = 1;
    skills.psychology = 10;
    skills.ride = 5;
    skills.science = 1;
    skills.sleightOfHand = 10;
    skills.spotHidden = 25;
    skills.stealth = 20;
    skills.survival = 10;
    skills.swim = 20;
    skills.throwing = 20;
    skills.track = 10;
    std::cout<<"Player created"<<std::endl;
  }
  ~Player(){
    std::cout<<"Player destroyed"<<std::endl;
  }
    std::string GetName() const {
    return name;
  }
  std::string GetName();
  std::string GetOccupation() const;
  std::string GetBirthplace() const;
  std::string GetResistance() const;
  std::string GetPronoun() const;
  int GetAge() const;

  int GetStrength() const;
  int GetConcentration() const;
  int GetDexterity() const;
  int GetIntelligence() const;
  int GetSize() const;
  int GetPower() const;
  int GetAppearance() const;
  int GetEducation() const;
  int GetHitPoints() const;
  int GetMagicPoints() const;
  int GetLuckPoints() const;
  int GetLuck() const;
  int GetSanity() const;

  int GetAccounting() const;
  int GetAnthropology() const;
  int GetApprise() const;
  int GetArchaeology() const;
  int GetArt() const;
  int GetCharm() const;
  int GetClimb() const;
  int GetCreditRating() const;
  int GetCtulhuMythos() const;
  int GetDisguise() const;
  int GetDodge() const;
  int GetDriveAuto() const;
  int GetElectricalRepair() const;
  int GetFastTalk() const;
  int GetFighting() const;
  int GetFirearmsHandgun() const;
  int GetFirearmsRifle() const;
  int GetFirstAid() const;
  int GetHistory() const;
  int GetIntimidate() const;
  int GetJump() const;
  int GetLanguageOther()const;
  int GetLanguageOwn()const;
  int GetLaw() const;
  int GetLibraryUse() const;
  int GetListen() const;
  int GetLocksmith() const;
  int GetMechanicalRepair() const;
  int GetMedicine() const;
  int GetNaturalWorld() const;
  int GetOccult() const;
  int GetPersuade() const;
  int GetPilot() const;
  int GetPsychoanalysis() const;
  int GetPsychology() const;
  int GetRide() const;
  int GetScience() const;
  int GetSleightOfHand() const;
  int GetSpotHidden() const;
  int GetStealth() const;
  int GetSurvival() const;
  int GetSwim() const;
  int GetThrowing() const;
  int GetTrack() const;
  int GetNavigate() const;

  void SetName(const wxString&);
  void SetOccupation(const wxString&);
  void SetBirthplace(const wxString&);
  void SetResidence(const wxString&);
  void SetPronoun(const wxString&);
  void SetAge(const wxString&);
  void SetStrength(const wxString&);
  void SetConcentration(const wxString&);
  void SetDexterity(const wxString&);
  void SetIntelligence(const wxString&);
  void SetSize(const wxString&);
  void SetPower(const wxString&);
  void SetAppearance(const wxString&);
  void SetEducation(const wxString&);
  void SetHitPoints(const wxString&);
  void SetMagicPoints(const wxString&);
  void SetLuckPoints(const wxString&);
  void SetLuck(const wxString&);
  void SetSanity(const wxString&);
  void SetAccounting(const wxString&);
  void SetAnthropology(const wxString&);
  void SetApprise(const wxString&);
  void SetArcheology(const wxString&);
  void SetArt(const wxString&);
  void SetClimb(const wxString&);
  void SetCreditRating(const wxString&);
  void SetCThulhuMythos(const wxString&);
  void SetDisguise(const wxString&);
  void SetDodge(const wxString&);
  void SetDriveAuto(const wxString&);
  void SetElectricalRepair(const wxString&);
  void SetFastTalk(const wxString&);
  void SetFighting(const wxString&);
  void SetFirearmsHandgun(const wxString&);
  void SetFirearmsRifle(const wxString&);
  void SetFirstAid(const wxString&);
  void SetHistory(const wxString&);
  void SetIntimidate(const wxString&);
  void SetJump(const wxString&);
  void SetLanguageOther(const wxString&);
  void SetLanguageOwn(const wxString&);
  void SetLaw(const wxString&);
  void SetLibraryUse(const wxString&);
  void SetListen(const wxString&);
  void SetLocksmith(const wxString&);
  void SetMechanicalRepair(const wxString&);
  void SetMedicine(const wxString&);
  void SetNaturalWorld(const wxString&);
  void SetOccult(const wxString&);
  void SetPersuade(const wxString&);
  void SetPilot(const wxString&);
  void SetPsychoanalysis(const wxString&);
  void SetPsychology(const wxString&);
  void SetRide(const wxString&);
  void SetScience(const wxString&);
  void SetSleightOfHand(const wxString&);
  void SetSpotHidden(const wxString&);
  void SetStealth(const wxString&);
  void SetSurvival(const wxString&);
  void SetSwim(const wxString&);
  void SetThrowing(const wxString&);
  void SetTrack(const wxString&);
    void SetCharm(const wxString&);
    void SetNavigate(const wxString&);
};



#endif //PLAYER_H

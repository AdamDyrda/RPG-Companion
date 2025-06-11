//
// Created by adame on 3/16/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>


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
};



#endif //PLAYER_H

//
// Created by adame on 3/16/2025.
//

#ifndef WEAPON_H
#define WEAPON_H

#include <string>


class Weapon {
  private:
std::string name;
std::string skill;
std::string dmg;
int numberOfAttacks;
std::string range;
int ammo;
int malfunction;
public:
  Weapon(std::string name, std::string skill, std::string dmg, int numberOfAttacks, std::string range, int ammo, int malfunction) {
    this->name = std::move(name);
    this->skill = std::move(skill);
    this->dmg = std::move(dmg);
    this->numberOfAttacks = numberOfAttacks;
    this->range = std::move(range);
    this->ammo = ammo;
    this->malfunction = malfunction;
  }
};



#endif //WEAPON_H

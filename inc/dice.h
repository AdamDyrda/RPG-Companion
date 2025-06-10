//
// Created by adame on 3/27/2025.
//

#ifndef DICE_H
#define DICE_H

#include <string>
#include <ctime>

namespace dice{
  std::string rollD4(int numOfRolls);
  std::string rollD6(int numOfRolls);
  std::string rollD10(int numOfRolls);
  std::string rollD12(int numOfRolls);
  std::string rollD20(int numOfRolls);
  std::string rollD100(int numOfRolls);

};

#endif //DICE_H

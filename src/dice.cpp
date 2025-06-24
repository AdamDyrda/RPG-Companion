/**
 *@file dice.cpp
 *@brief implementation of the dice rolling functions.
**/
#include "../inc/dice.h"

namespace dice{
std::string rollD4(int numOfRolls){
  srand(time(nullptr));
  std::string result = "";
  for(int i = 0; i < numOfRolls; i++){
    result += std::to_string(rand() % 4 + 1) + " ";
  }
  return result;
  }

std::string rollD6(int numOfRolls){
  std::string result = "";
  srand(time(0));
  for(int i = 0; i < numOfRolls; i++){
    result += std::to_string(rand() % 6 + 1) + " ";
  }
  return result;
}

std::string rollD10(int numOfRolls){
  srand(time(0));
  std::string result = "";
  for(int i = 0; i < numOfRolls; i++){
    result += std::to_string(rand() % 10 + 1) + " ";
  }
  return result;
  }

std::string rollD12(int numOfRolls){
  srand(time(0));
  std::string result = "";
  for(int i = 0; i < numOfRolls; i++){
    result += std::to_string(rand() % 12 + 1) + " ";
  }
  return result;
  }

std::string rollD20(int numOfRolls){
  srand(time(0));
  std::string result = "";
  for(int i = 0; i < numOfRolls; i++){
    result += std::to_string(rand() % 20 + 1) + " ";
  }
  return result;
  }

std::string rollD100(int numOfRolls){
  srand(time(0));
  std::string result = "";
  for(int i = 0; i < numOfRolls; i++){
    result += std::to_string(rand() % 100 + 1) + " ";
  }
  return result;
  }
};
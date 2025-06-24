/**
 *@file dice.h
 *@brief header file for the dice rolling functions.
 **/

#ifndef DICE_H
#define DICE_H

#include <string>
#include <ctime>

/**
 * @namespace dice
 * @brief namespace containing functions for rolling different types of dice.
 */
namespace dice{
    /**
     * @brief Rolls a die of the specified type and number of rolls.
     * @param numOfRolls The number of times to roll the die.
     * @return A string containing the results of the rolls.
     */
  std::string rollD4(int numOfRolls);
    /**
     * @brief Rolls a six-sided die.
     * @param numOfRolls The number of times to roll the die.
     * @return A string containing the results of the rolls.
     */
  std::string rollD6(int numOfRolls);
    /**
     * @brief Rolls a ten-sided die.
     * @param numOfRolls The number of times to roll the die.
     * @return A string containing the results of the rolls.
     */
  std::string rollD10(int numOfRolls);

  /**
   * @brief Rolls a twelve-sided die.
   * @param numOfRolls The number of times to roll the die.
   * @return A string containing the results of the rolls.
   */
  std::string rollD12(int numOfRolls);
    /**
     * @brief Rolls a twenty-sided die.
     * @param numOfRolls The number of times to roll the die.
     * @return A string containing the results of the rolls.
     */
  std::string rollD20(int numOfRolls);

  /**
   * @brief Rolls a hundred-sided die.
   * @param numOfRolls The number of times to roll the die.
   * @return A string containing the results of the rolls.
   */
  std::string rollD100(int numOfRolls);

};

#endif //DICE_H

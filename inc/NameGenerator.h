/**
 *@file NameGenerator.h
 *@brief header file for the NameGenerator class, which generates names for players.
 */
#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <iostream>
#include <fstream>
#include <ctime>
/** * @class NameGenerator
 * @brief Class responsible for generating names for players.
 */
class  NameGenerator {
public:
    /** @brief Constructor for the NameGenerator class.
     * Initializes the random number generator with the current time.
     */
    NameGenerator();

    /**
     * @brief NameGenerator destructor.
     */
    ~NameGenerator();
    /**
     * @brief Generates a string of random male names.
     * @param numOfNames The number of names to generate.
     * @return A string containing the generated names.
     */
    std::string generateMaleName(int numOfNames);

    /**
     * @brief Generates a string of random female names.
     * @param numOfNames The number of names to generate.
     * @return A string containing the generated names,
     */
    std::string generateFemaleName(int numOfNames);
};

#endif //NAMEGENERATOR_H

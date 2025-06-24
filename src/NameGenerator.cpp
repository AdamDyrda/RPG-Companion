/**
 *@file NameGenerator.cpp
 *@brief implementation of the NameGenerator class, which generates names for players.
 */

#include "../inc/NameGenerator.h"

#include <vector>

NameGenerator::NameGenerator() {
    std::cout<<"NameGenerator constructor called"<<std::endl;
}
NameGenerator::~NameGenerator() {
    std::cout<<"NameGenerator destructor called"<<std::endl;
}
std::string NameGenerator::generateFemaleName(int numOfNames) {
    std::vector<std::string> femaleNames;
    std::ifstream reader("../data/femaleNames.txt");
    if (!reader.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return "Error";
    }
    std::string name;
    while (std::getline(reader, name)) {
        femaleNames.push_back(name);
    }
    reader.close();
    std::string result;
    for (int i=0;i<numOfNames;i++){
        srand(time(NULL));
        int randomPos = rand()%100;
        result += femaleNames[randomPos] + '\n';
        femaleNames.erase(femaleNames.begin()+randomPos);
    }
    std::cout<<result<<std::endl;
    return result;
}

std::string NameGenerator::generateMaleName(int numOfNames) {
    std::vector<std::string> maleNames;
    std::ifstream reader("../data/maleNames.txt");
    if (!reader.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return "Error";
    }
    std::string name;
    while (std::getline(reader, name)) {
        maleNames.push_back(name);
    }
    reader.close();
    std::string result;
    for (int i=0;i<numOfNames;i++){
        srand(time(NULL));
        int randomPos = rand()%100;
        result += maleNames[randomPos] + '\n';
        maleNames.erase(maleNames.begin()+randomPos);
    }
    std::cout<<result<<std::endl;
    return result;
}



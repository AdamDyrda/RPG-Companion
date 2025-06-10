
#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <iostream>
#include <fstream>
class  NameGenerator {
public:
    NameGenerator();
    ~NameGenerator();
    std::string generateMaleName(int numOfNames);
        std::string generateFemaleName(int numOfNames);
};

#endif //NAMEGENERATOR_H

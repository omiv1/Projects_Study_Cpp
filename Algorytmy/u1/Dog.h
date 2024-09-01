//
// Created by lukas on 02.12.2023.
//

#ifndef U1_DOG_H
#define U1_DOG_H
#include <iostream>
#include "Animal.h"
using namespace std;

class Dog : public Animal{
private:
    string breed;
    int levelOfGuideSkills;
    int levelOfTrackerSkills;

public:
    Dog();

    Dog(int limbNr, string name, bool protectedAnimal, string breed, int levelOfGuideSkills, int levelOfTrackerSkills);

    Dog(int limbNr, string name, bool protectedAnimal);

    void setSkillLevel(int type, int value);

    int getSkillLever(int type);

    void giveVoice();

    void info();
};



#endif //U1_DOG_H

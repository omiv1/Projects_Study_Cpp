//
// Created by lukas on 02.12.2023.
//

#ifndef U1_ANIMAL_H
#define U1_ANIMAL_H
#include <iostream>

using namespace std;

class Animal {
private:
    int limbNR;
    string name;
    bool protectedAnimal;

public:
    Animal();

    Animal(int limbNr, string name, bool protectedAnimal = true);

    int getLimbNr();

    void setLimbNr(int limbNr);

    string getName();

    void setName(string name);

    bool getProtectedAnimal();

    void setProtectedAnimal(bool protectedAnimal);

    void giveVoice();

    void info();
};


#endif //U1_ANIMAL_H

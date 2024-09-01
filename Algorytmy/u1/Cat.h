//
// Created by lukas on 02.12.2023.
//

#ifndef U1_CAT_H
#define U1_CAT_H
#include <iostream>
#include "Animal.h"

using namespace std;

class Cat : public Animal{
private:
    int levelOfMouseHunting;
    int mice[5] = {0};

public:
    Cat();

    Cat(int limbNr, string name, bool protectedAnimal);

    Cat(int limbNr, string name, bool protectedAnimal, int levelOfMouseHunting);

    void initMice(int tab[], int size);

    void initCat(int levelOfMouseHunting, int tab[]);

    Cat(int limbNr, string name, bool protectedAnimal, int levelOfMouseHunting, int tab[]);

    int getLevelOfMouseHunting();

    void setLevelOfMouseHunting(int value);

    int getMice(int index);

    void giveVoice();

    void info();
};


#endif //U1_CAT_H

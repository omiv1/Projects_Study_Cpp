//
// Created by lukas on 02.12.2023.
//

#include "Cat.h"
Cat::Cat() {}

Cat::Cat(int limbNr, string name, bool protectedAnimal) : Animal(limbNr, name, protectedAnimal) {
}

Cat::Cat(int limbNr, string name, bool protectedAnimal, int levelOfMouseHunting) : Animal(limbNr,name,protectedAnimal){
    this -> levelOfMouseHunting = levelOfMouseHunting;
}

Cat::Cat(int limbNr, std::string name, bool protectedAnimal, int levelOfMouseHunting, int tab[]) : Animal(limbNr,name,protectedAnimal){
    this -> levelOfMouseHunting = levelOfMouseHunting;
    initMice(tab, 5);
}

void Cat::initMice(int tab[], int size) {
    for(int i = 0; i < size; i++)
    {
        mice[i] = tab[i];
    }
}

void Cat::initCat(int levelOfMouseHunting, int tab[]) {
    this -> levelOfMouseHunting = levelOfMouseHunting;
    initMice(tab, 5);
}

void Cat::setLevelOfMouseHunting(int value) {
    levelOfMouseHunting = value;
}

int Cat::getLevelOfMouseHunting() {
    return levelOfMouseHunting;
}

int Cat::getMice(int index) {
    return mice[index];
}

void Cat::giveVoice() {
    cout<<"Miau miau"<<endl;
}

void Cat::info() {
    Animal::info();
    cout<<"Umiejetnosci: "<<levelOfMouseHunting<<endl;
    for(int i = 0; i<5;i++)
    {
        cout<<"Year "<<i<<" - "<<mice[i]<<", ";
    }
    cout<<endl;

}

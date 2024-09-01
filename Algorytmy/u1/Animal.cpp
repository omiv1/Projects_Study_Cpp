//
// Created by lukas on 02.12.2023.
//

#include "Animal.h"

Animal::Animal() {}

Animal::Animal(int limbNr, string name, bool protectedAnimal){
    this -> limbNR = limbNr;
    this -> name = name;
    this -> protectedAnimal = protectedAnimal;
}

int Animal::getLimbNr() {
    return limbNR;
}

void Animal::setLimbNr(int limbNr) {
    limbNR = limbNr;
}

string Animal::getName() {
    return name;
}

void Animal::setName(string name) {
    Animal::name = name;
}

bool Animal::getProtectedAnimal() {
    return protectedAnimal;
}

void Animal::setProtectedAnimal(bool protectedAnimal) {
    Animal::protectedAnimal = protectedAnimal;
}

void Animal::giveVoice() {
    cout<<"Chrum, miau, hau, piiiii"<<endl;
}

void Animal::info() {
    cout<<"Nazwa: "<<name<<", Liczba Konczyn: "<<getLimbNr()<<", Czy jest pod ochrona: "<<getProtectedAnimal()<<endl;
}




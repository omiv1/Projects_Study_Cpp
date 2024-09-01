//
// Created by lukas on 02.12.2023.
//

#include "Dog.h"

Dog::Dog() {}

Dog::Dog(int limbNr, string name, bool protectedAnimal, string breed, int levelOfGuideSkills, int levelOfTrackerSkills) : Animal(limbNr, name, protectedAnimal){
    this -> breed = breed;
    this -> levelOfGuideSkills = levelOfGuideSkills;
    this -> levelOfTrackerSkills = levelOfTrackerSkills;
}

Dog::Dog(int limbNr, string name, bool protectedAnimal) : Animal(limbNr, name, protectedAnimal){
}

void Dog::setSkillLevel(int type, int value) {
    if(type == 0){
        levelOfGuideSkills = value;
    } else if (type == 1){
        levelOfTrackerSkills = value;
    } else{
        cout<<"Brak odpowiedniego typu"<<endl;
    }
}

int Dog::getSkillLever(int type) {
    if(type == 0){
        return levelOfGuideSkills;
    } else if (type == 1){
        return levelOfTrackerSkills;
    } else{
        return 0;
    }
}

void Dog::giveVoice() {
    cout<<"Hau, hau"<<endl;
}

void Dog::info() {
    Animal::info();
    cout<<"Rasa: "<<breed<<", przewodnik: "<<levelOfTrackerSkills<<", tropiciel: "<<levelOfTrackerSkills<<endl;
}

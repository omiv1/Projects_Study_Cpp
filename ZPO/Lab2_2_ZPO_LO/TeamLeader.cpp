//
// Created by lukas on 16.10.2023.
//

#include "TeamLeader.h"

TeamLeader::TeamLeader(string suname1, int age1, int experience1,double solary1):Employee(suname1,age1,experience1, solary1){
}

int TeamLeader::calculateSalary(int value) {
    return value*(1+getSalary()+getExperience());
}
void TeamLeader::show() {
    cout<<"Jestem TeamLeader z "<<getExperience()<<" letnim doswiadczeniem"<<endl;
}
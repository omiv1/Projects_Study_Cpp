//
// Created by lukas on 16.10.2023.
//

#include "Developer.h"

Developer::Developer(string suname1, int age1, int experience1,double solary1):Employee(suname1,age1,experience1, solary1){
}
int Developer::calculateSalary(int value) {
    return value+(0.2*(value*(getSalary()+getExperience())));
}

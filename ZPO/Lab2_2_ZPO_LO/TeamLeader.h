//
// Created by lukas on 16.10.2023.
//

#ifndef LAB2_2_ZPO_LO_TEAMLEADER_H
#define LAB2_2_ZPO_LO_TEAMLEADER_H
#include "Employee.h"

class TeamLeader : public Employee{
public:
    TeamLeader();
    TeamLeader(string suname1, int age1, int experience1, double solary1);
    virtual int calculateSalary(int value) override;
    virtual void show();
};


#endif //LAB2_2_ZPO_LO_TEAMLEADER_H

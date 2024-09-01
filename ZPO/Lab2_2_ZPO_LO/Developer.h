//
// Created by lukas on 16.10.2023.
//

#ifndef LAB2_2_ZPO_LO_DEVELOPER_H
#define LAB2_2_ZPO_LO_DEVELOPER_H
#include "Employee.h"

class Developer: public Employee {
public:
    Developer();
    Developer(string suname1, int age1, int experience1, double solary1);
    virtual int calculateSalary(int value) override;
};


#endif //LAB2_2_ZPO_LO_DEVELOPER_H

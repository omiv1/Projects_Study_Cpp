//
// Created by lukas on 16.10.2023.
//

#ifndef LAB2_2_ZPO_LO_EMPLOYEE_H
#define LAB2_2_ZPO_LO_EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee {
private:
    string surname;
    int age;
    int experience;
    double salary;
public:
    Employee();
    Employee(string surname1,int age1,int experience1,double solary1);
    virtual ~Employee();
    virtual void show();
    virtual int calculateSalary(int value)=0;
    int ageEmployment();
    const string &getSurname() const;
    void setSurname(const string &surname);
    int getAge() const;
    void setAge(int age);
    int getExperience() const;
    void setExperience(int experience);
    double getSalary() const;
    void setSalary(double salary);
};
#endif //LAB2_2_ZPO_LO_EMPLOYEE_H

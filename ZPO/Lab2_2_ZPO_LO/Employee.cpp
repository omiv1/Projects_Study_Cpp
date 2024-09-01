//
// Created by lukas on 16.10.2023.
//
#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee() {}
Employee::Employee(string surname1, int age1, int experience1, double solary1) {
    surname=surname1;
    age=age1;
    experience=experience1;
    salary=solary1;
}
Employee::~Employee() {}

void Employee::show() {
    cout<<"Nazwisko: "<<getSurname()<<" Wiek: "<<getAge()<<" Doswiadczenie: "<<getExperience()<<" Pensja: "<<getSalary()<<endl;
}
int Employee::ageEmployment() {
    return getAge()-getExperience();
}
const string &Employee::getSurname() const {
    return surname;
}
void Employee::setSurname(const string &surname) {
    Employee::surname = surname;
}
int Employee::getAge() const {
    return age;
}
void Employee::setAge(int age) {
    Employee::age = age;
}
int Employee::getExperience() const {
    return experience;
}
void Employee::setExperience(int experience) {
    Employee::experience = experience;
}
double Employee::getSalary() const {
    return salary;
}
void Employee::setSalary(double salary) {
    Employee::salary = salary;
}

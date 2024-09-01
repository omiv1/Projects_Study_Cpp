//
// Created by lukas on 05.11.2023.
//

#ifndef LAB4_3_LO_CITIZEN_H
#define LAB4_3_LO_CITIZEN_H

#include <iostream>

using namespace std;
class Citizen {
private:
    string name;
    string surname;
    int age;
    char sex;
    string postal_code;
public:
    Citizen() {}

    Citizen(const string &name, const string &surname, int age, char sex, const string &postal_code)
            : name(name), surname(surname), age(age), sex(sex), postal_code(postal_code) {}
    void show() {
        cout << "Name: " << name << ", Surname: " << surname << ", Age: " << age << ", Sex: " << sex << ", Postal Code: " << postal_code << std::endl;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Citizen::name = name;
    }

    const string &getSurname() const {
        return surname;
    }

    void setSurname(const string &surname) {
        Citizen::surname = surname;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Citizen::age = age;
    }

    char getSex() const {
        return sex;
    }

    void setSex(char sex) {
        Citizen::sex = sex;
    }

    const string &getPostalCode() const {
        return postal_code;
    }

    void setPostalCode(const string &postalCode) {
        postal_code = postalCode;
    }
};


#endif //LAB4_3_LO_CITIZEN_H

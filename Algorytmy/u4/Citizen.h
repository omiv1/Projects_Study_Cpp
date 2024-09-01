//
// Created by lukas on 04.12.2023.
//

#ifndef U4_CITIZEN_H
#define U4_CITIZEN_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Citizen {
private:
    string name;
    string surename;
    int age;
    char sex;
    string postal_code;

public:
    Citizen()
    {

    }
    Citizen(string name, string surename, int age, char sex, string postal_code)
    {
        this -> name = name;
        this -> surename = surename;
        this -> age = age;
        this -> sex = sex;
        this -> postal_code = postal_code;
    }
    void show()
    {
        cout<<name<<" "<<surename<<" "<<age<<" "<<sex<<" "<<postal_code<<endl;
    }
    string getSurename()
    {
        return surename;
    }
    int getAge()
    {
        return age;
    }
    char getSex()
    {
        return sex;
    }
    string getCode()
    {
        return postal_code;
    }

};


#endif //U4_CITIZEN_H

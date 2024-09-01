//
// Created by lukas on 04.12.2023.
//

#ifndef KOLOKWIUM1_ZPO_LO_STUDENT_H
#define KOLOKWIUM1_ZPO_LO_STUDENT_H
#include <iostream>
#include <map>

using namespace std;

template<typename T>
class Student {
private:
    string name;
    string surename;
    long id;
    map<string,T> oceny;

public:
    Student();
    Student(string name, string surename, long id)
    {
        this -> name = name;
        this -> surename = surename;
        this -> id = id;
    }
    Student(string name, string surename, long id, map<string,T> oceny)
    {
        this -> name = name;
        this -> surename = surename;
        this -> id = id;
        this -> oceny = oceny;
    }
    void add(string przedmiot, T ocena)
    {
        oceny[przedmiot] = ocena;
    }
    void setName(string value)
    {
        name = value;
    }
    string getName()
    {
        return name;
    }
    void setSurename(string value)
    {
        surename = value;
    }
    string getSurename()
    {
        return surename;
    }
    void setId(long value)
    {
        id = value;
    }
    long getId()
    {
        return id;
    }
    void show_all_grades()
    {
        for(pair<string,T> para : oceny)
        {
            cout<<para.first<<" ocena: "<<para.second<<endl;
        }
    }
    int getSize()
    {
        return oceny.size();
    }
    map<string,T> getOceny()
    {
        return oceny;
    }
};
template<>
void Student<string>::show_all_grades()
{
    for(pair<string,string> para : oceny)
    {
        cout<<para.first<<" ocena w skali opisowej: "<<para.second<<endl;
    }
}

#endif //KOLOKWIUM1_ZPO_LO_STUDENT_H

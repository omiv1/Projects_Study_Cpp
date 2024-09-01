//
// Created by lukas on 04.12.2023.
//

#ifndef KOLOKWIUM1_ZPO_LO_SUBJECT_H
#define KOLOKWIUM1_ZPO_LO_SUBJECT_H
#include <iostream>

using namespace std;

class Subject {
private:
    long id;
    string subject_name;
    string teacher;
    int ects;
    int amount_of_lessons;

public:
    Subject();
    Subject(long id, string subject_name, string teacher, int ects, int amount_of_lessons);
    long getId();
    void setId(long value);
    string getSubject_name();
    void setSubject_name(string value);
    string getTeacher();
    void setTeacher(string value);
    int getEcts();
    void setEcts(int value);
    int getAmount_of_lessons();
    void setAmount_of_lessons(int value);
    bool operator<(const Subject& other) const;

};


#endif //KOLOKWIUM1_ZPO_LO_SUBJECT_H

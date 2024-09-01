//
// Created by lukas on 04.12.2023.
//

#include "Subject.h"
Subject::Subject(){

}
Subject::Subject(long id, string subject_name, string teacher, int ects, int amount_of_lessons){
    this -> id = id;
    this -> subject_name = subject_name;
    this -> teacher = teacher;
    this -> ects = ects;
    this -> amount_of_lessons = amount_of_lessons;
}
long Subject::getId() {
    return id;
}
void Subject::setId(long value) {
    id = value;
}
string Subject::getSubject_name() {
    return subject_name;
}
void Subject::setSubject_name(string value) {
    subject_name = value;
}
string Subject::getTeacher() {
    return teacher;
}
void Subject::setTeacher(string value) {
    teacher = value;
}
int Subject::getEcts() {
    return ects;
}
void Subject::setEcts(int value) {
    ects = value;
}
void Subject::setAmount_of_lessons(int value) {
    amount_of_lessons = value;
}
int Subject::getAmount_of_lessons() {
    return amount_of_lessons;
}
bool Subject::operator<(const Subject& other) const {
    return this->id < other.id;
}
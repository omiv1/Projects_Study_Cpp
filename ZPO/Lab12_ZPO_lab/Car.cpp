//
// Created by lukas on 08.01.2024.
//

#include <iostream>
#include "car.h"

using namespace std;

Car::Car(string model, int year, double engineCapacity): model(model), year(year), engineCapacity(engineCapacity) {}

string Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

double Car::getEngineCapacity() const {
    return engineCapacity;
}

void Car::setModel(string newModel) {
    model = newModel;
}

void Car::setYear(int newYear) {
    year = newYear;
}

void Car::setEngineCapacity(double newEngineCapacity) {
    engineCapacity = newEngineCapacity;
}

void Car::display() const {
    cout << "Model: " << model << ", Rok: " << year << ", Pojemnosc: " << engineCapacity << "L" << endl;
}
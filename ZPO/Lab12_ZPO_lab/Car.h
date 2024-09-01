//
// Created by lukas on 08.01.2024.
//

#ifndef LAB12_ZPO_LAB_CAR_H
#define LAB12_ZPO_LAB_CAR_H

#include <string>

using namespace std;

class Car {
private:
    string model;
    int year;
    double engineCapacity;

public:

    Car(string model, int year, double engineCapacity);

    string getModel() const;
    int getYear() const;
    double getEngineCapacity() const;

    void setModel(string newModel);
    void setYear(int newYear);
    void setEngineCapacity(double newEngineCapacity);

    void display() const;
};
#endif //LAB12_ZPO_LAB_CAR_H

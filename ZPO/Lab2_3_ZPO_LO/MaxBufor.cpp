//
// Created by lukas on 22.10.2023.
//
#include <iostream>
#include "MaxBufor.h"
#include "Bufor.h"

MaxBufor::MaxBufor():Bufor(){};
MaxBufor::MaxBufor(int Size):Bufor(Size){};

double MaxBufor::calculate() {
    if (getIndex() == 0) {
        return 0.0;
    }
    int max = getTab(0);
    for (int i = 1; i < getIndex(); i++) {
        if (getTab(i) > max) {
            max = getTab(i);
        }
    }
    return max;
}
void MaxBufor::add(int value) {
    if(getIndex() >= getSize())
    {
        cout<<"Brak miejsca w tablicy!!!"<<endl;
    } else
    {
        Bufor::add(value);
    }
}
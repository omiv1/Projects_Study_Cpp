//
// Created by lukas on 22.10.2023.
//

#include "MeanBufor.h"
#include "Bufor.h"

MeanBufor::MeanBufor():Bufor(){};
MeanBufor::MeanBufor(int Size):Bufor(Size){};

double MeanBufor::calculate() {
    if(getIndex() == 0)
    {
        return 0.0;
    } else {
        double sum = 0;
        for (int i = 0; i < getIndex(); i++) {
            sum = sum + getTab(i);
        }
        sum = sum / getIndex();
        return sum;
    }
}

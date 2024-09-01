//
// Created by lukas on 03.12.2023.
//

#include "MeanBufor.h"
MeanBufor::MeanBufor() : Bufor(){

}
MeanBufor::MeanBufor(int size) : Bufor(size){

}

double MeanBufor::calculate() {
    double suma = 0;
    for(int i=0;i<getIndex();i++)
    {
        suma = suma + getTab(i);
    }
    return suma/getIndex();
}
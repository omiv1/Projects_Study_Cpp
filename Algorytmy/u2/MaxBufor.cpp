//
// Created by lukas on 03.12.2023.
//

#include "MaxBufor.h"

MaxBufor::MaxBufor() : Bufor(){

}
MaxBufor::MaxBufor(int size) : Bufor(size){

}

double MaxBufor::calculate() {
    //cout<<getf();
    int* m = max_element(getf(),getf() + getIndex());
    return *m;
}

void MaxBufor::sortt() {
    sort(getf(),getf() + getIndex(),greater<int>());
}

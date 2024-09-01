//
// Created by lukas on 03.12.2023.
//

#ifndef U2_MAXBUFOR_H
#define U2_MAXBUFOR_H
#include "Bufor.h"
#include "iostream"
#include "algorithm"

using namespace std;

class MaxBufor : public Bufor{
public:
    MaxBufor();
    MaxBufor(int size);
    double calculate() override;
    void sortt();
};


#endif //U2_MAXBUFOR_H

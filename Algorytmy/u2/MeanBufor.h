//
// Created by lukas on 03.12.2023.
//

#ifndef U2_MEANBUFOR_H
#define U2_MEANBUFOR_H
#include <iostream>
#include "Bufor.h"

using namespace std;

class MeanBufor : public Bufor{
public:
    MeanBufor();
    MeanBufor(int size);
    double calculate() override;
};


#endif //U2_MEANBUFOR_H

//
// Created by lukas on 22.10.2023.
//

#ifndef LAB2_3_ZPO_LO_MAXBUFOR_H
#define LAB2_3_ZPO_LO_MAXBUFOR_H
#include "Bufor.h"

class MaxBufor: public Bufor {
public:
    MaxBufor();
    MaxBufor(int Size);

    double calculate() override;
    void add(int value) override;
};


#endif //LAB2_3_ZPO_LO_MAXBUFOR_H

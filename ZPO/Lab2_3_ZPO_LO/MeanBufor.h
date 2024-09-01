//
// Created by lukas on 22.10.2023.
//

#ifndef LAB2_3_ZPO_LO_MEANBUFOR_H
#define LAB2_3_ZPO_LO_MEANBUFOR_H
#include "Bufor.h"

class MeanBufor: public Bufor {
public:
    MeanBufor();
    MeanBufor(int Size);

    double calculate() override;
};


#endif //LAB2_3_ZPO_LO_MEANBUFOR_H

//
// Created by lukas on 16.10.2023.
//

#ifndef LAB2_ZPO_LO_CIRCLE_H
#define LAB2_ZPO_LO_CIRCLE_H

#include "Figure.h"

class Circle : public Figure
{
private:
    float r;

public:
    Circle(float r1);
    ~Circle();
    virtual void calculateArea() override;
    virtual void calculateCircuit() override;
};

#endif //LAB2_ZPO_LO_CIRCLE_H

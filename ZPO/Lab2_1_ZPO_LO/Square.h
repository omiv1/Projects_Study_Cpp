//
// Created by lukas on 16.10.2023.
//

#ifndef LAB2_ZPO_LO_SQUARE_H
#define LAB2_ZPO_LO_SQUARE_H

#include "Figure.h"

class Square : public Figure
{
private:
    float a;

public:
    Square(float a1);
    ~Square();
    virtual void calculateArea() override;
    virtual void show() override;
    virtual void calculateCircuit() override;
};

#endif //LAB2_ZPO_LO_SQUARE_H

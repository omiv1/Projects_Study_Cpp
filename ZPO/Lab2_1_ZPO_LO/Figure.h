//
// Created by lukas on 16.10.2023.
//

#ifndef LAB2_ZPO_LO_FIGURE_H
#define LAB2_ZPO_LO_FIGURE_H

class Figure
{
private:
    float area;
    float circuit;

public:
    Figure();
    virtual ~Figure();
    float getArea();
    void setArea(float area1);
    float getCircuit();
    void setCircuit(float circuit1);
    virtual void calculateArea() = 0;
    virtual void show();
    virtual void calculateCircuit() = 0;
};

#endif //LAB2_ZPO_LO_FIGURE_H

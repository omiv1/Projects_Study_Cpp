//
// Created by lukas on 16.10.2023.
//

#include <iostream>
#include "Figure.h"
using namespace std;

Figure::Figure()
{
    cout << "Konstruktor klasy bazowej Figure" << endl;
}

Figure::~Figure()
{
    cout << "Wirtualny destruktor klasy bazowej Figure" << endl;
}

float Figure::getArea()
{
    return area;
}

void Figure::setArea(float area1)
{
    area = area1;
}
float Figure::getCircuit() {
    return circuit;
}

void Figure::setCircuit(float circuit1) {
    area = circuit1;
}
void Figure::show()
{
    cout << "Pole: " << area << endl;
}
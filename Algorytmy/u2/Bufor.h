//
// Created by lukas on 03.12.2023.
//

#ifndef U2_BUFOR_H
#define U2_BUFOR_H
#include <iostream>

using namespace std;

class Bufor {
private:
    int *tab;
    int size;
    int index;

public:
    Bufor();
    Bufor(int size);
    virtual ~Bufor();
    virtual void add(int value);
    virtual double calculate() = 0;
    int getSize();
    int getIndex();
    int getTab(int i);
    int getFirst();
    void setFirts(int value);
    void setTab(int pos, int value);
    void show();
    int* getf();

};


#endif //U2_BUFOR_H

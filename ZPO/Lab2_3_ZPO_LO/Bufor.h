//
// Created by lukas on 22.10.2023.
//

#ifndef LAB2_3_ZPO_LO_BUFOR_H
#define LAB2_3_ZPO_LO_BUFOR_H

using namespace std;

class Bufor {
private:
    int* tab;
    int size;
    int index;
public:
    Bufor();
    Bufor(int size1);
    virtual ~Bufor();
    virtual void add(int value);
    virtual double calculate()=0;
    int getIndex();
    int getSize();
    int getTab(int i);
    int getFirst();
    void setFirst(int value);
    void setTab(int pos,int value);
    void show();
};


#endif //LAB2_3_ZPO_LO_BUFOR_H

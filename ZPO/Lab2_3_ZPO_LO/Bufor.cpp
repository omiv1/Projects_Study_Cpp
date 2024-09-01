//
// Created by lukas on 22.10.2023.
//
#include <iostream>
#include "Bufor.h"

using namespace std;

Bufor::Bufor() {
    size = 10;
    tab = new int[size];
    index = 0;
}
Bufor::Bufor(int size1) {
    size = size1;
    tab = new int[size];
    index = 0;
}
Bufor::~Bufor() {
    delete[] tab;
}
void Bufor::add(int value) {
    tab[index] = value;
    index++;
}
int Bufor::getIndex() {
    return index;
}
int Bufor::getSize() {
    return size;
}
int Bufor::getFirst() {
    return tab[0];
}
int Bufor::getTab(int i) {
    return tab[i];
}
void Bufor::setFirst(int value) {
    tab[0] = value;
}
void Bufor::setTab(int pos, int value) {
    tab[pos] = value;
}
void Bufor::show() {
    cout<<"Rozmiar: "<<getSize()<<" Index: "<< " Elementy:";
    for(int i = 0 ; i < getIndex(); i++)
    {
        cout<<" "<<getTab(i);
    }
    cout<<endl;
}

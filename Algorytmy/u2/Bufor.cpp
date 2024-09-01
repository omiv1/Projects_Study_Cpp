//
// Created by lukas on 03.12.2023.
//

#include "Bufor.h"

Bufor::Bufor() {
    size = 10;
    tab = new int[10];
    index = 0;
}
Bufor::Bufor(int size){
    this -> size = size;
    tab = new int[size];
    index = 0;
}
Bufor::~Bufor() {

}
void Bufor::add(int value){
    tab[index] = value;
    index++;
}
int Bufor::getIndex(){
    return index;
}
int Bufor::getTab(int i){
    return tab[i];
}
int Bufor::getSize()
{
    return size;
}
int Bufor::getFirst(){
    return index;
}
void Bufor::setFirts(int value){
    index = value;
}
void Bufor::setTab(int pos, int value){
    tab[pos] = value;
}
void Bufor::show(){
    for(int i=0;i<index;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

int* Bufor::getf() {
    //cout<<tab;
    return tab;
}
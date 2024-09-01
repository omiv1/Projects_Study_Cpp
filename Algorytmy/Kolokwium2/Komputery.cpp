//
// Created by lukas on 15.01.2024.
//

#include "Komputery.h"

Komputery::Komputery() {

}
Komputery::Komputery(int numer_komputera, char seria, int pojemnosc_dysku) {
    this->numer_komputera = numer_komputera;
    this->seria =seria;
    this->pojemnosc_dysku = pojemnosc_dysku;
}
Komputery::~Komputery() {

}

int Komputery::getNumerKomputera() const {
    return numer_komputera;
}

void Komputery::setNumerKomputera(int numerKomputera) {
    numer_komputera = numerKomputera;
}

char Komputery::getSeria() const {
    return seria;
}

void Komputery::setSeria(char seria) {
    Komputery::seria = seria;
}

int Komputery::getPojemnoscDysku() const {
    return pojemnosc_dysku;
}

void Komputery::setPojemnoscDysku(int pojemnoscDysku) {
    pojemnosc_dysku = pojemnoscDysku;
}

void Komputery::show() {
    cout<<numer_komputera<<" "<<seria<<" "<<pojemnosc_dysku<<endl;
}

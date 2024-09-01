//
// Created by lukas on 15.01.2024.
//

#include "Awaria.h"

Awaria::Awaria() {

}
Awaria::Awaria(int numer_zgloszenia, int numer_komputera, std::string czas_awarii, int priorytet) {
    this->numer_zgloszenia = numer_zgloszenia;
    this->numer_komputera = numer_komputera;
    this-> czas_awarii = czas_awarii;
    this-> priorytet;
}
Awaria::~Awaria() {

}

int Awaria::getNumerZgloszenia() const {
    return numer_zgloszenia;
}

void Awaria::setNumerZgloszenia(int numerZgloszenia) {
    numer_zgloszenia = numerZgloszenia;
}

int Awaria::getNumerKomputera() const {
    return numer_komputera;
}

void Awaria::setNumerKomputera(int numerKomputera) {
    numer_komputera = numerKomputera;
}

const string &Awaria::getCzasAwarii() const {
    return czas_awarii;
}

void Awaria::setCzasAwarii(const string &czasAwarii) {
    czas_awarii = czasAwarii;
}

int Awaria::getPriorytet() const {
    return priorytet;
}

void Awaria::setPriorytet(int priorytet) {
    Awaria::priorytet = priorytet;
}

void Awaria::show() {
    cout<<numer_zgloszenia<<" "<<numer_komputera<<" "<<czas_awarii<<" "<<priorytet<<endl;
}

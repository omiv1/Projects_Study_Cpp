//
// Created by lukas on 15.01.2024.
//

#ifndef KOLOKWIUM2_KOMPUTERY_H
#define KOLOKWIUM2_KOMPUTERY_H

#include <iostream>

using namespace std;

class Komputery {
private:
    int numer_komputera;
    char seria;
    int pojemnosc_dysku;

public:
    Komputery();
    Komputery(int numer_komputera, char seria, int pojemnosc_dysku);
    ~Komputery();

    int getNumerKomputera() const;

    void setNumerKomputera(int numerKomputera);

    char getSeria() const;

    void setSeria(char seria);

    int getPojemnoscDysku() const;

    void setPojemnoscDysku(int pojemnoscDysku);

    void show();

};


#endif //KOLOKWIUM2_KOMPUTERY_H

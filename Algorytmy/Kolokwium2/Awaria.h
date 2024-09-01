//
// Created by lukas on 15.01.2024.
//

#ifndef KOLOKWIUM2_AWARIA_H
#define KOLOKWIUM2_AWARIA_H
#include <iostream>

using namespace std;

class Awaria {
private:
    int numer_zgloszenia;
    int numer_komputera;
    string czas_awarii;
    int priorytet;

public:
    Awaria();
    Awaria(int numer_zgloszenia,int numer_komputera, string czas_awarii, int priorytet);
    ~Awaria();

    int getNumerZgloszenia() const;

    void setNumerZgloszenia(int numerZgloszenia);

    int getNumerKomputera() const;

    void setNumerKomputera(int numerKomputera);

    const string &getCzasAwarii() const;

    void setCzasAwarii(const string &czasAwarii);

    int getPriorytet() const;

    void setPriorytet(int priorytet);

    void show();

};


#endif //KOLOKWIUM2_AWARIA_H

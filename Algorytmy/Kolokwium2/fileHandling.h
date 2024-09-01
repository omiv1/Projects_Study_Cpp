//
// Created by lukas on 15.01.2024.
//

#ifndef KOLOKWIUM2_FILEHANDLING_H
#define KOLOKWIUM2_FILEHANDLING_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Awaria.h"
#include "Komputery.h"

using namespace std;

class fileHandling {
private:
    //string sciezka_do_awarie = "C:\\Users\\lukas\\CLionProjects\\Kolokwium2\\awarie.csv";
    //string sciezka_do_komputery = "C:\\Users\\lukas\\CLionProjects\\Kolokwium2\\komputery.csv";
public:
    static vector<Awaria> read_awarie()
    {
        vector<Awaria> awarie;
        ifstream plik_awarie;
        plik_awarie.open("C:\\Users\\lukas\\CLionProjects\\Kolokwium2\\awarie.csv");
        if(plik_awarie.is_open())
        {
            string linia, nz, nk,ca,p;
            getline(plik_awarie,linia);
            //cout<<"otwarto awarie.csv"<<endl;
            while(getline(plik_awarie,linia))
            {
                awarie.push_back(Awaria());
                stringstream ss(linia);
                getline(ss,nz,';');
                getline(ss,nk,';');
                getline(ss,ca,';');
                getline(ss,p,';');

                awarie.back().setNumerZgloszenia(stoi(nz));
                awarie.back().setNumerKomputera(stoi(nk));
                awarie.back().setCzasAwarii(ca);
                awarie.back().setPriorytet(stoi(p));
            }
        } else
        {
            cout<<"blad awarie.csv"<<endl;
            throw "Nie udalo sie otworzyc pliku awaria.";
        }
        return awarie;
    }
    static vector<Komputery> read_komputery()
    {
        vector<Komputery> komputery;
        ifstream plik_komputery;
        plik_komputery.open("C:\\Users\\lukas\\CLionProjects\\Kolokwium2\\komputery.csv");
        if(plik_komputery.is_open())
        {
            string linia, nk,s,pd;
            getline(plik_komputery,linia);
            //cout<<"otwarto awarie.csv"<<endl;
            while(getline(plik_komputery,linia))
            {
                komputery.push_back(Komputery());
                stringstream ss(linia);
                getline(ss,nk,';');
                getline(ss,s,';');
                getline(ss,pd,';');

                komputery.back().setNumerKomputera(stoi(nk));
                komputery.back().setSeria(s[0]);
                komputery.back().setPojemnoscDysku(stoi(pd));

            }
        } else
        {
            cout<<"blad komputery.csv"<<endl;
            throw "Nie udalo sie otworzyc pliku komputery.";
        }
        return komputery;
    }
};


#endif //KOLOKWIUM2_FILEHANDLING_H

//
// Created by lukas on 14.01.2024.
//

#ifndef KOLOS2_NAUKA1_STUDENT_H
#define KOLOS2_NAUKA1_STUDENT_H
#include <iostream>
#include <iomanip>
#include <regex>

using namespace std;

class Student {
private:
    string imie;
    string nazwisko;
    char plec;
    int ocena;
    string email;
public:
    Student(string imie, string nazwisko, char plec, int ocena, string email)
    {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->plec = plec;
        this->ocena = ocena;
        this->email = email;
    }
    Student()
    {
        //cout<<"Konstruktor"<<endl;
    }
    ~Student()
    {
        //cout<<"Destruktor"<<endl;
    }

    string getImie()
    {
        return imie;
    }
    string getNazwisko()
    {
        return nazwisko;
    }
    char getPlec()
    {
        return plec;
    }
    int getOcena()
    {
        return ocena;
    }
    string getEmail()
    {
        return email;
    }
    void setImie(string imie)
    {
        this->imie = imie;
    }
    void setNazwisko(string nazwisko)
    {
        this->nazwisko = nazwisko;
    }
    void setPlec(char plec)
    {
        this->plec = plec;
    }
    void setOcena(int ocena)
    {
        this->ocena = ocena;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void wypisz() const {
        const int szerokoscKolumny = 20;

        std::cout << std::left
                  << std::setw(15) << imie
                  << std::setw(15) << nazwisko
                  << std::setw(5) << plec
                  << std::setw(5) << ocena
                  << std::setw(5) << email
                  << std::endl;
    }
    void dodaj()
    {
        cout<<"Podaj imie: ";
        int test = 0;
        string x;
        while(test == 0)
        {

            cin>>x;
            if(regex_match(x,regex("[A-Z][a-z]+")))
            {
                imie = x;
                test = 1;
            }
            else
            {
                cout<<"Podaj poprawne imie: ";
            }
        }
        cout<<"Podaj nazwisko: ";
        test = 0;
        while(test == 0)
        {

            cin>>x;
            if(regex_match(x,regex("[A-Z][a-z]+")))
            {
                nazwisko = x;
                test = 1;
            }
            else
            {
                cout<<"Podaj poprawne nazwisko: ";
            }
        }
        cout<<"Podaj plec: ";
        test = 0;
        while(test == 0)
        {

            cin>>x;
            if(regex_match(x,regex("[KM]")))
            {
                plec = x[0];
                test = 1;
            }
            else
            {
                cout<<"Podaj poprawna plec: ";
            }
        }
        cout<<"Podaj ocene: ";
        test = 0;
        while(test == 0)
        {

            cin>>x;
            if(regex_match(x,regex("[1-5]")))
            {
                ocena = stoi(x);
                test = 1;
            }
            else
            {
                cout<<"Podaj poprawna ocene: ";
            }
        }
        cout<<"Podaj email: ";
        test = 0;
        while(test == 0)
        {

            cin>>x;
            if(regex_match(x,regex("[a-z]+@[a-z]+.[a-z]+")))
            {
                email = x;
                test = 1;
            }
            else
            {
                cout<<"Podaj poprawny email: ";
            }
        }

    }


};


#endif //KOLOS2_NAUKA1_STUDENT_H

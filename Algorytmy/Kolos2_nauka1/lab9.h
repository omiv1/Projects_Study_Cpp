#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Student.h"

using namespace std;

void lab9_zadanie1()
{
    cout << "test" << endl;
    ifstream plik;
    plik.open("C:\\Users\\lukas\\CLionProjects\\Kolos2_nauka1\\kod.txt");

    if (!plik.is_open())
    {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }

    string linia;
    char znak;
    while (plik.get(znak))
    {
        if(znak == '/')
        {
            if(plik.peek() == '/')
            {
                plik.ignore('\n');
                //cout<<endl;
            }
        }
        else
        {
            cout << znak;
        }
    }

    plik.close();
}
int wczytaj()
{
    int liczba;
    cout<< "Podaj liczbe: ";
    if (cin>>liczba)
    {
        cout<<"calkowika"<<endl;
    }
    else
    {
        cout<<"inna"<<endl;
    }
    return liczba;
}
void lab9_zadanie2()
{
    int liczba = 0;
    int test = 1;
    int oczko = 0;
    while(test == 1)
    {
        liczba = wczytaj();
        cout<<liczba<<endl;
    }
}
void pokaz_nazw(vector <Student> s, string nazwisko)
{
    for(Student x : s)
    {
        if(x.getNazwisko() == nazwisko)
        {
            x.wypisz();
        }
    }
}
string naglowek()
{
    string naglowek = "Imie;Nazwisko;Plec;Ocena;Email";
    return naglowek;
}
void stworz_plik(vector <Student> s, char p)
{
    ofstream plik;
    plik.open("C:\\Users\\lukas\\CLionProjects\\Kolos2_nauka1\\plik_" + string(1,p) + ".csv");
    plik<<naglowek()<<endl;
    for(Student x : s)
    {
        if(x.getPlec() == p)
        {
            plik<<x.getImie()<<";"<<x.getNazwisko()<<";"<<x.getPlec()<<";"<<x.getOcena()<<";"<<x.getEmail()<<endl;
        }
    }
    plik.close();
}
void dopisz_do_pliku(vector <Student> s, char p)
{
    ofstream plik;
    plik.open("C:\\Users\\lukas\\CLionProjects\\Kolos2_nauka1\\plik_" + string(1,p) + ".csv", ios::app);
    for(Student x : s)
    {
        if(x.getPlec() == p)
        {
            plik<<x.getImie()<<";"<<x.getNazwisko()<<";"<<x.getPlec()<<";"<<x.getOcena()<<";"<<x.getEmail()<<endl;
        }
    }
    plik.close();
}
void pierwsze_x_osob(vector <Student> s, int x)
{
    int i = 0;
    while(i < x && i < s.size())
    {
        s[i].wypisz();
        i++;
    }
}
void lab9_zadanie3()
{

    ifstream plik;
    plik.open("C:\\Users\\lukas\\CLionProjects\\Kolos2_nauka1\\dane.csv");
    string linia;
    vector<Student> s;
    int i = 0;
    string imie, nazwisko, email,plec,ocena;
    getline(plik,linia);
    while(getline(plik,linia))
    {
        //cout<<linia<<endl;
        s.push_back(Student());
        stringstream ss(linia);
        getline(ss,imie,';');
        getline(ss,nazwisko,';');
        getline(ss,plec,';');
        getline(ss,ocena,';');
        getline(ss,email,';');
        //cout<<ost<<endl;
        s.back().setImie(imie);
        s.back().setNazwisko(nazwisko);
        s.back().setPlec(plec[0]);
        s.back().setOcena(stoi(ocena));
        s.back().setEmail(email);
    }
    for(Student x : s)
    {
        x.wypisz();
    }
    s.push_back(Student());
    s.back().dodaj();
    s.back().wypisz();
    cout<<endl;
    pokaz_nazw(s,"Kowalski");
    pokaz_nazw(s,"Nowak");
    stworz_plik(s,'M');
    cout<<endl;
    pierwsze_x_osob(s,3);
    cout<<endl;
    sort(s.begin(),s.end(), [](Student a, Student b){return a.getOcena() < b.getOcena();});
    pierwsze_x_osob(s,100);
    dopisz_do_pliku(s,'K');
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Ksiazka
{
private:
    static int licznik;
    int id;
    string imie;
    string nazwisko;
    string plec;
    int nr_tel;
    string email;
public:
    Ksiazka();
    Ksiazka(string imie,string nazwisko,string plec,int nr_tel,string email)
    {
        id=licznik;
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->plec=plec;
        this->nr_tel=nr_tel;
        this->email=email;
        licznik++;
    }
    ~Ksiazka()
    {

    }
    void show()
    {
        cout<<id<<"\t"<<imie<<"     \t"<<nazwisko<<"    \t"<<plec<<"    \t"<<nr_tel<<"  \t"<<email<<endl;
        cout<<endl;
    }
    void add(string imie,string nazwisko,string plec,int nr_tel,string email)
    {
        id=licznik;
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->plec=plec;
        this->nr_tel=nr_tel;
        this->email=email;
        licznik++;
    }
    int get_licznik()
    {
        return licznik;
    }
    friend void kobiety(Ksiazka **k);
    friend void ile_email(Ksiazka **k);
    friend void domeny(Ksiazka **k);
};
void kobiety(Ksiazka **k)
{
    ofstream out("kobiety.txt");
    int pom=k[0]->get_licznik();
    int j=0;
    for (int i=0;i<pom;i++)
    {
        if (k[i]->plec == "K")
        {
            out<<j<<"\t"<<k[i]->imie<<"     \t"<<k[i]->nazwisko<<"    \t"<<k[i]->plec<<"    \t"<<k[i]->nr_tel<<"  \t"<<k[i]->email<<endl;
            out<<endl;
            j++;
        }
    }
}

void ile_email(Ksiazka **k)
{
    int pom=k[0]->get_licznik();
    int j=0;
    for (int i=0;i<pom;i++)
    {
        if (k[i]->email == "" )
        {
            cout<<j<<"\t"<<k[i]->imie<<"     \t"<<k[i]->nazwisko<<"    \t"<<k[i]->plec<<"    \t"<<k[i]->nr_tel<<"  \t"<<k[i]->email<<endl;
            cout<<endl;
        }
    }
    cout<<j;
}

void domeny(Ksiazka **k)
{
    int pom=k[0]->get_licznik();
    string domena;
    int id_malpa;
    int id_kropka;

    for (int i=0;i<pom;i++)
    {
        if (k[i]->email != "" )
        {
            id_malpa=k[i]->email.find("@");
            id_kropka=k[i]->email.find(".");
            domena=k[i]->email.substr(id_malpa+1,id_kropka-id_malpa-1);
            cout<<k[i]->email<<" "<<id_malpa<<" "<<domena<<endl;
        }
    }
}

int Ksiazka::licznik=0;
int main()
{
    ifstream in("dane.csv");
    //ofstream kout("kobiety.csv");
    string kosz,id_st,imie,nazwisko,plec,nr_tel_st,email;
    int i=0,id,nr_tel;
    //char plec;
    Ksiazka **k;
    k=new Ksiazka*[100];


    getline(in,kosz);

    while(!in.eof())
    {
        getline(in,kosz,';');
        getline(in,imie,';');
        getline(in,nazwisko,';');
        getline(in,plec,';');
        getline(in,nr_tel_st,';');
        getline(in,email);

        //id=stoi(id_st);
        nr_tel = stoi(nr_tel_st);
        k[i]=new Ksiazka(imie,nazwisko,plec,nr_tel,email);
        i++;
    }
    for(int j=0;j<i;j++)
    {
        k[j]->show();
    }
    kobiety(k);
    cout<<endl<<endl;
    //ile_email(k);
    domeny(k);


}

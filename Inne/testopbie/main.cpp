#include <iostream>

using namespace std;

class A
{
private:
    int liczbaA;
public:
    A()
    {

    }
    A(int liczbaA)
    {
        this->liczbaA=liczbaA;
        this->liczbaB=liczbaA;
    }
    A(A &a)
    {
        liczbaA=a.liczbaA;
        liczbaB=a.liczbaB;
    }
    int liczbaB;
    void show()
    {
        cout<<liczbaA<<" "<<liczbaB<<endl;
    }
    friend class B;
    friend void funkcja(A a);
    A operator=(A a)
    {
        liczbaA=a.liczbaA;
        liczbaB=a.liczbaB;
    }
    static int licznik;
    A& operator=(const A& a)
    {
        this->liczbaA=a.liczbaA;
    }
};
class B
{
private:
    int liczbaaa;
public:
    B(int licz)
    {
        liczbaaa=licz;
        liczbabb=licz;
    }
    int liczbabb;
    void showa()
    {
        cout<<liczbaaa<<" "<<liczbabb<<" "<<endl;
    }
};
void funkcja(A a)
{
    a.show();
    cout<<a.liczbaA<<endl;
}
void funkcja2(A a)
{
    a.show();
    //cout<<a.liczbaA<<endl;
}

class Dodawanie
{
private:
    static int licznik;  //zmienna statyczna
public:
    Dodawanie()
    {
        cout<<"Konstruktor"<<endl;
    }
    Dodawanie(int licz)
    {
        licznik=licz;
    }
    ~Dodawanie()
    {
        cout<<"Destruktor"<<endl;
    }
    static void dodajLiczbe(int liczba) //metoda statyczna nie ma dostepu do niestatycznych metod i pol
    {
        licznik=licznik+liczba;
    }
    static void show()  //metoda statyczna
    {
        cout<<"Licznik to "<<licznik<<endl;
    }

};

int Dodawanie::licznik=0; //inicjalizacja zmiennej statycznej odbywa sie po za klasa

int main()
{
    A a1;
    A a2(15);
    a2.show();
    funkcja(a2);
    funkcja2(a2);
    B b1(14);
    b1.showa();
    //a2.A(14);
    cout<<endl;
    A a5(1);
    A a6=a5;
    A a7=(a2);
    cout<<endl;
    A *a10= new A(10);
    a10->show();
}

#include <iostream>

using namespace std;

class Dodawanie
{
private:
    static int licznik;
public:
    Dodawanie()
    {

    }
    Dodawanie(int liczba)
    {
        licznik=liczba;
    }
    ~Dodawanie()
    {

    }
    static void dodaj(int liczba)
    {
        licznik = licznik+liczba;
    }
    static void show()
    {
        cout<<licznik<<endl;
    }
};
int Dodawanie::licznik = 0;
int main()
{
    Dodawanie::dodaj(6);
    Dodawanie::show();
    Dodawanie d;
    d.dodaj(4);
    d.show();

    Dodawanie dd(120);
    dd.show();
    dd.dodaj(5);
    dd.show();
    Dodawanie::show();
    return 0;
}

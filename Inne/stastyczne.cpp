#include <iostream>

using namespace std;
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
int main() //zmienna statyczna jest przywiazana do klasy a nie do obiektu
{
    Dodawanie::dodajLiczbe(4);  //metode statyczna mozna wywolac bez obiektu, nazwa metody poprzedzona nazwa klasy oraz ::
    Dodawanie::show();
    Dodawanie d;  //tworzenie obiektu klasy Dodawanie
    d.dodajLiczbe(55);  //wywolanie metody dodajacej do obecnego stanu 55
    d.show();       //wywolanie metody show wyswietlajacej stan licznika


    Dodawanie dd(10); //mozna stworzyc obiekt z wartoscia poczatkowa licznika przekazana do konstruktora
    dd.show();
    dd.dodajLiczbe(100);
    Dodawanie::show(); //wywolanie metody bez obiektu, stan licznika 110

    return 0;
}

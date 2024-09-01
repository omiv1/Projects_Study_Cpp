/*#include <iostream>
using namespace std;
class Parent
{
public:
    // Atrybuty, metody, wirtualny destruktor
    virtual void show()
    {
        cout << "Metoda wirtualna Parent" << endl;
    }
};

class Child : public Parent
{
public:
    // Atrybuty, metody
    void show() override
    {
        cout << "Metoda wirtualna Child" << endl;
    }
};

int main()
{
    // Typ statyczny Parent, typ dynamiczny Child
    Parent* p = new Child();
    // Metoda show z klasy Child
    p->show();

    // Typ statyczny Child, typ dynamiczny Child
    Child* c = new Child();
    // Metoda show z klasy Child
    c->show();
}*/

#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
using namespace std;

int main()
{
    Figure* f1 = new Square(4);
    Figure* f2 = new Circle(2);

    f1->calculateArea();
    f1->show();

    f2->calculateArea();
    f2->show();

    delete f1;  // Zwolnij pamięć obiektu Square
    delete f2;  // Zwolnij pamięć obiektu Circle

    Figure *f3;
    Square s1(4);
    f3=&s1;
    f3->calculateArea();
    f3->show();

    cout<<endl;
    Figure* tab[3];
    tab[0] = new Square(4);
    tab[1] = new Square(2);
    tab[2] = new Circle(5);

    for (int i = 0; i < 3; i++)
    {
        tab[i]->calculateArea();
        tab[i]->show(); // Dodane wywolanie show()
        delete tab[i];
    }
    return 0;
}



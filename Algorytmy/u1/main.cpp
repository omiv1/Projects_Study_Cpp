#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Animal.h"

using namespace std;

void howManyProtectedAnimals(Animal* tab, int size)
{
    int sum = 0;
    for (int i=0; i<size; i++)
    {
        if (tab[i].getProtectedAnimal() == 1){
            sum += 1;
            //cout<<"a";
        }
        //cout<<"a";
        //tab[i].info();
    }
    cout<<"Suma: "<<sum<<endl;
}
void xhowManyProtectedAnimals(Animal** tab, int size)
{
    int sum = 0;
    for (int i=0; i<size; i++)
    {
        if (tab[i] -> getProtectedAnimal() == 1){
            sum += 1;
            //cout<<"a";
        }
        //cout<<"a";
        //tab[i].info();
    }
    cout<<"Suma: "<<sum<<endl;
}

void howManyCats(Cat* tab,int size)
{
    int pom;
    for(int i=0;i<size;i++)
    {
        pom=0;
        for(int j = 0;j<5;j++)
        {
            pom = pom + tab[j].getMice(j);
        }
        tab[i].info();
        cout<<"Suma myszy: "<<pom<<endl;
    }
}
int main() {

    Cat c1(4,"mruczek", false);
    int tab[5] = {1,2,3,4,5};
    c1.initCat(5,tab);
    c1.info();
    c1.giveVoice();

    Animal a1(4,"nazwa");
    a1.info();
    a1.giveVoice();

    Dog d1(4,"burek", false,"kundel",4,2);
    d1.info();
    d1.giveVoice();

    Animal* a;
    a = new Animal[10];
    for(int i=0;i<10;i++)
    {
        a[i] = *new Animal(i,"nazwa",(i+1)%2);

        a[i].info();
    }
    a[5].giveVoice();
    howManyProtectedAnimals(a,10);

    Cat c[10];
    //Cat** c;
    //c = new Cat[10];
    for(int i=0;i<10;i++)
    {
        c[i] = Cat(4,"kot"+i,0);
        int tab[5] = {1+i,2,3+i,4,11-i};
        c[i].initCat(i,tab);
    }
    howManyCats(c,10);

    Dog* d;
    d = new Dog[10];
    for(int i=0;i<10;i++)
    {
        d[i] = Dog();
    }

    Animal* tab_a[10];
    for(int i=0;i<5;i++)
    {
        tab_a[i] = new Dog(4,"pies",i%2,"rasa",4,5);
    }
    for(int i=5;i<10;i++)
    {
        tab_a[i] = new Cat(4,"kot",i%2);
    }

    cout<<"test"<<endl;
    xhowManyProtectedAnimals(tab_a,10);
    tab_a[3]->info();

    return 0;
}

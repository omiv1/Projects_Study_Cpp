#include <iostream>
#include <memory>
#include <vector>
#include "main2.cpp"
#include "zadanie3.h"
#include "BufferArr.h"
#include "BufferFile.h"

using namespace std;

void funUniqueDeleter(int* ptr) {
    cout << "Custom deleter called for array element: " << *ptr << endl;
    delete[] ptr;
}

unique_ptr<int[]> funUniqueArray(int size) {
    return unique_ptr<int[]>(new int[size]);
}

void funcUniqueModify(unique_ptr<int>& uptr) {
    *uptr = 112;
}

void zadanie2()
{
    shared_ptr < Person > sptr1( new Person("Ola",32) );
    shared_ptr < Person > sptr2( new Person("Ula",52) );
    sptr1->info();
    cout<<"Licznik sptr1: "<<sptr1.use_count()<<endl;
    cout<<"Licznik sptr2: "<<sptr2.use_count()<<endl;
    vector<shared_ptr<Person>> firstInOffice;
    firstInOffice.push_back(sptr1);
    firstInOffice.push_back(sptr2);
    firstInOffice.push_back(sptr2);
    firstInOffice.push_back(sptr1);
    firstInOffice.push_back(sptr2);
    cout<<"Po dodaniu do kontenera"<<endl;
    cout<<"Licznik sptr1: "<<sptr1.use_count()<<endl;
    cout<<"Licznik sptr2: "<<sptr2.use_count()<<endl;
    for (shared_ptr<Person> ptr : firstInOffice)
        ptr->info();
    cout << endl;
    firstInOffice.resize(3);
    cout<<"Po resize"<<endl;
    cout<<"Licznik sptr1: "<<sptr1.use_count()<<endl;
    cout<<"Licznik sptr2: "<<sptr2.use_count()<<endl;
    shared_ptr <Person> sptr3(new
                                      Person("Magda",22),funDeleter);
    sptr3->info();
}
void zadanie3()
{
    shared_ptr <Elem> el1 (new Elem);
    shared_ptr <Elem> el2 (new Elem);
    el1->next = el2;
    el2->prev = el1;

    shared_ptr<Elem> tempEl(el2->prev);
    cout <<"Adres: " <<tempEl<< endl;
}
void zadanie4()
{
    vector<Buffer*> buffers;

    buffers.push_back(new BufferArr(5));
    buffers.push_back(new BufferArr(3));
    buffers.push_back(new BufferFile("test1.txt"));
    buffers.push_back(new BufferArr(2));
    buffers.push_back(new BufferFile("test2.txt"));
    buffers.push_back(new BufferFile("test3.txt"));

    for (auto buffer : buffers) {
        buffer->add(1);
        buffer->add(2);
        buffer->add(3);
        buffer->write();
        delete buffer;
    }

}
void zadanie1()
{
    unique_ptr<int> uptr1(new int);
    *uptr1 = 12;
    cout << "Wartosc uptr1: " << *uptr1 << endl;
    cout << "Adres uptr1: " << uptr1.get() << endl;

    unique_ptr<int> uptr2;
    cout << "Przed move" << endl;
    cout << "Adres uptr1: " << uptr1.get() << endl;
    cout << "Adres uptr2: " << uptr2.get() << endl;

    uptr2 = move(uptr1);
    cout << "Po move: " << endl;
    cout << "Adres uptr1: " << uptr1.get() << endl; // This will be nullptr after the move
    cout << "Adres uptr2: " << uptr2.get() << endl;

    funcUniqueModify(uptr2);
    cout << "Wartosc uptr2: " << *uptr2 << endl;

    cout << "Przed reset: Adres uptr2: " << uptr2.get() << endl;
    uptr2.reset();
    cout << "Po reset: Adres uptr2: " << uptr2.get() << endl;

    unique_ptr<int[]> tab1(new int[4]);
    cout << "Elementy tablicy tab1:" << endl;
    for (int i = 0; i < 4; i++) {
        tab1[i] = i + 7;
        cout << tab1[i] << endl;
    }

    unique_ptr<int[]> tab3 = funUniqueArray(5);
    cout << "Elementy tablicy tab3:" << endl;
    for (int i = 0; i < 5; i++)
        cout << tab3[i] << endl;

    unique_ptr<int[], void (*)(int*)> tab2(new int[10], funUniqueDeleter);
    vector<unique_ptr<int>> vec;
    unique_ptr<int> i1(new int);
    *i1 = 3;
    vec.push_back(move(i1));
    cout << "Element w wektorze: " << *vec[0] << endl;



}
int main() {
    //zadanie2();
    //zadanie3();
    zadanie4();

    return 0;
}

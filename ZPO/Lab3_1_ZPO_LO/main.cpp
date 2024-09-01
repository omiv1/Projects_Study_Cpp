#include <iostream>
#include "Adding.h"
#include "Student.h"

using namespace std;

template <typename T>
void mySwap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
template <typename T>
void showAll(T* tab[], int n)
{
    for(int i=0;i<n;i++)
    tab[i]->show();
}


int main()
{
//    int a=6;
//    int b=8;
//    cout<<"przed: "<<a<<" "<<b<<endl;
//    mySwap<int>(a,b);
//    cout<<"po: "<<a<<" "<<b<<endl;
//    char a1='a';
//    char b1='b';
//    cout<<"przed: "<<a1<<" "<<b1<<endl;
//    mySwap<char>(a1,b1);
//    cout<<"po: "<<a1<<" "<<b1<<endl;
//    return 0;

//    Adding<int> a1(5);
//    a1.add(6);
//    a1.show();
//    Adding<string> a2("Pro");
//    a2.add("gramowanie");
//    a2.show();
//
//    return 0;

//    Student<float> s(5, "Ala");
//    s.showMark();
//    s.show();
//
//    Student<int> s1(5, "Ala");
//    s1.showMark();
//    s1.show();
//
//    Student<string> s2(5, "Ala");
//    s2.showMark();
//    s2.show();

    Adding<int>* arrAdd[4];
    for(int i=0;i<3;i++)
    {
        arrAdd[i]=new Adding<int>(i);
    }
    showAll(arrAdd,3);
    Student<string>* arrStu[2];
    for(int i=0;i<3;i++){
        arrStu[i]=new Student<string>(i+2,"Ala");
    }
    showAll(arrStu,3);
    for(int i=0; i<3; i++) delete arrAdd[i];
    for(int i=0; i<2; i++) delete arrStu[i];


    return 0;
}

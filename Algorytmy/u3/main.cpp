#include <iostream>
#include <algorithm>
#include "Array.h"

using namespace std;

template<typename T>
void funkcja1(T& a)
{
    a = a + a;
}

template<typename T>
T funkcja2(T a)
{
    return a + a;
}

template<typename T>
void z2(T tab[],int size)
{
    cout<<*min_element(tab, tab + size)<<endl;
}
template<>
void z2<string>(string tab[],int size)
{
    cout<<*min_element(tab, tab + size,[](string a,string b) {return a.length() < b.length();})<<endl;
}
int main() {

    int size = 6;
    int tab[6] = {1,3,6,0,8,5};
    z2<int>(tab,size);

    double tab1[6] = {1.0,3.0,6.0,0.5,8.0,5.0};
    z2(tab1,size);

    string tab2[4] = {"aaa","acaa","bbbb","cx"};
    z2<string>(tab2,4);


//    string a1 = "test";
//    cout<<a1<<endl;
//    funkcja1<string>(a1);
//    cout<<a1<<endl;
//
//    int a2 = 2;
//    cout<<a2<<endl;
//    funkcja1<int>(a2);
//    cout<<a2<<endl;
//
//    string b1 = "test";
//    cout<<b1<<endl;
//    cout<<funkcja2<string>(b1)<<endl;
//
//    int b2 = 2;
//    cout<<b2<<endl;
//    cout<<funkcja2<int>(b2)<<endl;

    srand(time(NULL));
    cout<<endl;
    Array<int> a(5);
    int x;
    for(int i = 0;i<a.getSize();i++)
    {
        x = rand()%10;
        a.add(x);
    }
    a.show();
    cout<<*a.max_a()<<endl;
    a.sort_a();
    a.show();

    Array<string> t(5);
    t.add("napis");
    t.add("aaa");
    t.add("bbbb");
    t.add("abcdefg");
    t.add("rtx");
    t.show();
    cout<<*t.max_a()<<endl;
    t.sort_a();
    t.show();

    return 0;
}

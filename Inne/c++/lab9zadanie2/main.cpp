#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex c1(5,2);
    Complex c2(3,-9);
    c1.show();
    c2.show();
    //cout<<c1+c2;
    Complex c3=c1+c2;
    c3.show();
    Complex c4=c1*c2;
    c4.show();
    Complex c5;
    //cin>>c5;
    //c5.show();
    if (c2>c1) cout<<"tak"<<endl;
    else cout<<"nie"<<endl;
    Complex **c;
    c=new Complex*[10];
    for(int i=0;i<10;i++)
    {
        c[i]=new Complex(i,i);
    }
    c[1]->show();
    modul(c,10);
    c1.show();
    ++c1;
    c1.show();
    c1++;
    c1.show();
}

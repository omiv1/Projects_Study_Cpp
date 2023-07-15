#include <iostream>
#include "Complex.h"
#include <cmath>

using namespace std;

Complex::Complex()
{

}
Complex::Complex(double re=0, double im=0)
{
    this->re=re;
    this->im=im;
}
void Complex::show()
{
    cout<<re<<" + ("<<im<<"i)"<<endl;
}
Complex Complex::operator+(Complex c)
{
    Complex p(re+c.re,im+c.im);
    return p;
}
Complex Complex::operator*(Complex c)
{
    Complex p((re*c.re)-(im*c.im),(re*c.im)+im*c.re);
    return p;
}
bool Complex::operator>(Complex c)
{
    if (im>c.im) return true;
    else return false;
}
istream & operator>>(istream &key, Complex &c)
{
    key>>c.re>>c.im;
    return key;
}
void modul(Complex **c,int n)
{
    double pom;
    double maks=0;
    for (int i=0;i<n;i++)
    {
        pom=sqrt(((c[i]->re*c[i]->re)+(c[i]->im*c[i]->im)));
        if (maks<pom) maks=pom;
    }
    cout<<maks<<endl;
}
Complex Complex::operator++()
{
    re++;
    return *this;
}
Complex Complex::operator++(int)
{
    Complex c(re,im);
    re++;
    return c;
}

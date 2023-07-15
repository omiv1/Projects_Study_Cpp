#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <iostream>

using namespace std;

class Complex
{
private:
    double re;
    double im;
public:
    Complex();
    Complex(double re,double im);
    void show();
    Complex operator+(Complex c);
    Complex operator*(Complex c);
    Complex operator++();
    Complex operator++(int);
    bool operator>(Complex c);
    friend istream & operator>>(istream & key, Complex &c);
    friend void modul(Complex **c,int n);

};

#endif // COMPLEX_H_INCLUDED

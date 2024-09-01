#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout<<"wybierz calke 1, 2, 3, 4"<<endl;
    cout<<"/int_{-1}^{1} /frac{x^2}{/sqrt(1-x^2)}dx    n = 3   gauss_chebyshev"<<endl;
    cout<<"/int_{-1}^{1} /frac{dx}{/sqrt(1+x^2)}       n = 4   gauss_legendre"<<endl;
    cout<<"/int_{0}{/infty} /e^{-2x}/frac{sinx}{x}dx   n = 3   gauss_laguerre"<<endl;
    cout<<"/int_{-/infty}^{/infty} e^{-x^2}coxdx       n = 4   gauss_hermite"<<endl;
    int w;
    cin>>w;
    if (w == 1)
    {
        double x;
        double h;
        double suma=0;
        for(int i=0;i<=3;i++)
        {
            x=(M_PI*((2*i)+1))/(2*(3+1));
            h=M_PI/(3+1);
            cout<<"x = "<<x<<"  h = "<<h<<endl;
            suma = suma + (h*pow(cos(x),2));
        }
        cout<<"wynik: "<<suma<<endl;
    }
    if (w == 2)
    {
        double x[5];
        x[0] = -0.906180;
        x[1] = -0.538469;
        x[2] = 0.0;
        x[3] = 0.538469;
        x[4] = 0.906180;
        double h[5];
        h[0] = 0.236927;
        h[1] = 0.478629;
        h[2] = 0.568889;
        h[3] = 0.478629;
        h[4] = 0.236927;
        double suma=0;
        for(int i=0;i<=4;i++)
        {
            suma = suma + (h[i]*(1.0/ sqrt(1.0+ pow(x[i],2))));
        }
        cout<<"wynik: "<<suma<<endl;
    }
    if (w == 3)
    {
        double x[4];
        x[0] = 0.322548;
        x[1] = 1.745761;
        x[2] = 4.536620;
        x[3] = 9.395071;
        double h[4];
        h[0] = 0.603154;
        h[1] = 0.357419;
        h[2] = 0.038888;
        h[3] = 0.000539;
        double suma=0;
        for(int i=0;i<=3;i++)
        {
            suma = suma + (h[i]*(pow(M_E,-1*x[i])*sin(x[i])/x[i]));
        }
        cout<<"wynik: "<<suma<<endl;

    }
    if (w == 4)
    {
        double x[5];
        x[0] = -2.020183;
        x[1] = -0.958572;
        x[2] = 0;
        x[3] = 0.958572;
        x[4] = 2.020183;
        double h[5];
        h[0] = 0.019953;
        h[1] = 0.393619;
        h[2] = 0.945309;
        h[3] = 0.393619;
        h[4] = 0.019953;
        double suma=0;
        for(int i=0;i<=4;i++)
        {
            suma = suma + (h[i]*cos(x[i]));
        }
        cout<<"wynik: "<<suma<<endl;
    }


}

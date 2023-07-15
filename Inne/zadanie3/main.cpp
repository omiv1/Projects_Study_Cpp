#include <iostream>
#include <cmath>

using namespace std;

int singnal (double a)
{
    if(a>0){
        return 1;
    }
    else if(a<0){
        return -1;
    }
    else{
        return 0;
    }
}

double t(double a, double b){
    return -singnal(a)*b;
}

double dziwneA(double* vektor, int a){
    double var = 0;
    for (int i=0; i<a; i++){
        var += pow(vektor[i],2);
    }
    return sqrt(var);
}


int main() {
    int a;
    double * vektor = new double[a];
    cout << "Podaj rozmiar wektora: ";
    cin >> a;
    for (int i=0; i<a; i++)
    {
        cout << "podaj: " << i+1 << " element wektora: ";
        cin >> vektor[i];
    }
    cout << "Wynik:" << std::endl;
    cout << t(vektor[0], dziwneA(vektor, a)) << std::endl;
    for (int i = 0; i < a -1; ++i)
    {
        std::cout << 0 << std::endl;
    }
    return 0;
}
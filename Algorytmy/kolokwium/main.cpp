#include <iostream>
#include <cmath>
using namespace std;

int main() {
     int wezly;
     cout<<"podaj liczbe wezlow: "<<endl;
     cin>>wezly;
     //wezly--;
     double x[wezly + 1];
     double h[wezly + 1];
     if(wezly == 2)
     {

         x[0] = -0.577350;
         x[1] = 0.577350;

         h[0] = 1;
         h[1] = 1;
     }
     if(wezly == 3)
     {

         x[0] = -0.774597;
         x[1] = 0;
         x[2] = 0.774597;

         h[0] = 5.0/9.0;
         h[1] = 8.0/9.0;
         h[2] = 5.0/9.0;
     }
     if(wezly == 4)
     {

         x[0] = -0.861136;
         x[1] = -0.339981;
         x[2] = 0.339981;
         x[3] = 0.861136;

         h[0] = 0.347855;
         h[1] = 0.652145;
         h[2] = 0.652145;
         h[3] = 0.347855;
     }
     if(wezly == 5)
     {

         x[0] = -0.906180;
         x[1] = -0.538469;
         x[2] = 0;
         x[3] = 0.538469;
         x[4] = 0.906180;

         h[0] = 0.236927;
         h[1] = 0.478629;
         h[2] = 0.568889;
         h[3] = 0.478629;
         h[4] = 0.236927;
     }
     double suma=0;
     for(int i=0;i<wezly;i++)
     {
         suma = suma + (h[i]*((x[i]-1.0)/sqrt(1.0 - pow(x[i],2))));
         //cout<<i<<" : wyrazenie = "<<(h[i]*((x[i]-1.0)/ sqrt(1.0 - pow(x[i],2))))<<" : h = "<<h[i]<<" : x = "<<x[i]<<endl;
         //suma = suma + (h[i]*(1.0/ sqrt(1.0+ pow(x[i],2))));
     }
     cout<<"wynik: "<<suma<<endl;

}

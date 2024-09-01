#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    //wczytanie
    cout<<"ile wezlow?"<<endl;
    int rozmiar = 4;
    //int punkt;// = 2;
    //cin>>rozmiar;
    cout<<"podaj punkt:"<<endl;
    //cin>>punkt;
    double x[rozmiar+1] = {1,3,4,6,8};
    double y[rozmiar+1] = {-4,-8,-10,-14,-18};
    /*for(int i=0;i<=rozmiar;i++)
    {
        cout<<"podaj x"<<i<<" :"<<endl;
        cin>>x[i];
        z[i]=x[i];
        cout<<"podaj y"<<i<<" :"<<endl;
        cin>>y[i];
    }*/
    double suma_x = 0;
    double suma_y = 0;
    double suma_xk = 0;
    double suma_xy = 0;
    double a,b,w,wa,wb;
    for(int i=0;i<=rozmiar;i++)
    {
        suma_x = suma_x + x[i];
        suma_y = suma_y + y[i];
        suma_xk = suma_xk + pow(x[i],2);
        suma_xy = suma_xy + (x[i]*y[i]);
    }
    w=((rozmiar+1)*suma_xk)-(suma_x*suma_x);
    wa=(suma_y*suma_xk)-(suma_x*suma_xy);
    wb=((rozmiar+1)*suma_xy)-(suma_y*suma_x);
    a=wa/w;
    b=wb/w;
    cout<<suma_x<<" "<<suma_y<<" "<<suma_xk<<" "<<suma_xy<<endl;
    cout<<w<<" "<<wa<<" "<<wb<<" "<<endl<<"a0 = "<<a<<endl<<"a1 = "<<b<<endl;
}

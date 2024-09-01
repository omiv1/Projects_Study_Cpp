#include <iostream>

using namespace std;
int main()
{
    //wczytanie
    cout<<"ile wezlow?"<<endl;
    int rozmiar;// = 3;
    int punkt;// = 2;
    cin>>rozmiar;
    cout<<"podaj punkt:"<<endl;
    cin>>punkt;
    double x[rozmiar];// = {0,1,3};
    double y[rozmiar];// = {1,3,2};
    double z[rozmiar];
    for(int i=0;i<rozmiar;i++)
    {
        cout<<"podaj x"<<i<<" :"<<endl;
        cin>>x[i];
        z[i]=x[i];
        cout<<"podaj y"<<i<<" :"<<endl;
        cin>>y[i];
    }
    //sprawdzenie
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            if(z[i]>z[i+1]) swap(z[i],z[i+1]);
        }
    }
    int pom=0;
    for(int i=0;i<rozmiar;i++)
    {
        if(z[i]==z[i+1])
        {
            cout<<"bledne dane"<<endl;
            pom=1;
            break;
        }
    }
    //program
    if(pom==0) {
        double tab[rozmiar][rozmiar];
        for (int i = 0; i < rozmiar; i++)
        {
            tab[i][0] = y[i];
        }
        for (int j = 1; j < rozmiar; j++)
        {
            for (int i = 0; i < rozmiar - j; i++)
            {
                tab[i][j] = (((punkt - x[i]) * tab[i + 1][j - 1]) - ((punkt - x[i + j]) * tab[i][j - 1])) / (x[i + j] - x[i]);
            }
        }
        //wynik
        for (int i = 0; i < rozmiar; i++)
        {
            cout<<x[i]<<" ";
            for (int j = 0; j < rozmiar -i; j++)
            {
                cout << tab[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"wartosc przyblizona w punkcie ("<<punkt<<") wynosi: "<<tab[0][rozmiar-1];
    }
    return 0;
}

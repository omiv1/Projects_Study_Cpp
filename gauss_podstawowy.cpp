#include <iostream>
using namespace std;
int main() {
    //wymagane zmienne i tablice
    int n;
    cout<<"podaj liczbe rownan:";
    cin>>n;
    //int n = 4;
    double macierz[n+1][n+1];
    //double macierz[n + 1][n + 1] = {{1, 2,  3,  4, 5},{1, 2,  -1,  2, 0},{1, 0,  -2,  4, 4},{0, -3, 1.5, 7, 0},{0, -1, 1,   6, -1}};
    //double macierz[n + 1][n + 1] = {{1, 2,  3,  4},{-1,2,1,-1},{1,-3,-2,-1},{3,-1,-1,4}};
    //double macierz[n + 1][n + 1] = {{1, 2,  3,  4, 5},{3,1,-1,1,0},{1,5,-3,0,7},{1,3,0,-1,1},{0,3,2,1,2}};

    //wczytanie danych
    for (int j = 0; j <= n; j++)
    {
        macierz[0][j] = j+1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<endl<<"w rownaniu "<<i<<endl;
        for (int j = 0; j <= n; j++)
        {
            cout<<"podaj "<<char(j+97)<<":";
            cin>>macierz[i][j];
        }
    }
    cout<<endl;
    cout<<endl;
    //wyswietlenie wczytenej macierzy
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    //cout<<endl;
    //przeksztalcenie macierzy do macierzy trojkatnej
    double pom;
    for(int i=0;i<n;i++)
    {
        if(macierz[i+1][i] != 0)
        {
            for(int j=i+2;j<n+1;j++)
            {
                if(macierz[j][i] != 0)
                {
                    pom = macierz[j][i] / macierz[i + 1][i];
                    //cout << macierz[j][i] << "/" << macierz[i + 1][i] << " = " << pom << endl;
                    for (int k = i; k < n + 1; k++) {
                        macierz[j][k] = macierz[j][k] - (pom * macierz[i + 1][k]);
                    }
                }
            }
        }
        else
        {
            cout<<"0 na przekatnej!!!"<<endl;
            break;
        }
    }
    cout<<endl;
    pom=0;
    //wyswietlenie macierzy trujkatnej
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    //obliczbenie wartosci zmiennych z macierzy
    for(int i=0;i<n;i++)
    {
        //cout<<"mnozenie = "<<pom <<"*" <<macierz[n-i][n-i]<< " = " <<pom*macierz[n-i][n-i]<<endl;
        for(int j=i;j<n;j++)
        {
            macierz[n-j][n] = macierz[n-j][n] - (pom * macierz[n-j][n-i]);
        }

        pom = macierz[n-i][n] / macierz[n-i][n-1-i];
        //cout<<"pom = "<<macierz[n-i][n]<<" / "<<macierz[n-i][n-1-i]<<" = "<<pom<<endl;
        macierz[n-i][n] = macierz[n-i][n] / macierz[n-i][n-1-i];

    }
    //cout<<endl;
    //wyswietlenie macierzy wynikow
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    //wyswietlenie wynikow
    for(int i=1;i<n+1;i++)
    {
        cout<<char(macierz[0][i-1]+96)<<" = "<<macierz[i][n]<<endl;
        //cout<<macierz[0][i-1]<<" = "<<macierz[i][n]<<endl;
    }
}
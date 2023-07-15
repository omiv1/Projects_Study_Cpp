#include <iostream>
using namespace std;

int main()
{
    //int n = 3;
    //double macierz[n + 1][n + 1] = {{1, 2,  3,  4},{1,2,3,0},{4,5,6,0},{7,8,9,0}};
    //double macierz[n + 1][n + 1] = {{1, 2,  3,  4, 5},{1, 2,  -1,  2, 0},{1, 0,  -2,  4, 4},{0, -3, 1.5, 7, 0},{0, -1, 1,   6, -1}};
    //double macierz[n + 1][n + 1] = {{1, 2,  3,  4},{-1,2,1,-1},{1,-3,-2,-1},{3,-1,-1,4}};
    //double macierz[n + 1][n + 1] = {{1, 2,  3,  4, 5},{3,1,-1,1,0},{1,5,-3,0,7},{1,3,0,-1,1},{0,3,2,1,2}};
    //niezbedne zmienne
    int n;
    cout<<"podaj liczbe rownan:";
    cin>>n;
    double macierz[n+1][n+1];

    //wczytenie danych
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
    //wyswietlenie wczytanych danych
    cout<<endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    int x=0,y=0;
    double pom;
    double naj=0;
    for(int i=0;i<n;i++)
    {
        for(int a=i+1;a<n+1;a++)
        {
            for(int b=i;b<n;b++)
            {
                if(abs(macierz[a][b]) > abs(naj))
                {
                    naj = macierz[a][b];
                    x = a;
                    y = b;
                }
            }
        }
        //cout<<"naj = "<<naj<<" x = "<<x<<" y = "<<y<<" i = "<<i<<endl;
        naj=0;
        if(x!=i+1)
        {
            for(int a=0;a<n+1;a++)
            {
                swap(macierz[i+1][a],macierz[x][a]);
            }
        }
        if(y!=i)
        {
            for(int a=0;a<n+1;a++)
            {
                swap(macierz[a][i],macierz[a][y]);
            }
        }
        for(int j=i+2;j<n+1;j++)
        {
            if(macierz[j][i] != 0)
            {
                pom = macierz[j][i] / macierz[i + 1][i];
                //cout<<"wiesz: "<<j<<"  komurka: "<<macierz[j][i]<<endl;
                //cout <<"pom = " <<macierz[j][i] << " / " << macierz[i + 1][i] << " = " << pom << endl;
                for (int k = i; k < n + 1; k++) {
                    macierz[j][k] = macierz[j][k] - (pom * macierz[i + 1][k]);
                }
            }
        }

    }
    //cout<<endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    if(macierz[n][n]==0)
    {
        cout<<"To jest macierz osobliwa"<<endl;
    }
    else
    {
        pom = 0;
        for (int i = 0; i < n; i++) {
            //cout<<"mnozenie = "<<pom <<"*" <<macierz[n-i][n-i]<< " = " <<pom*macierz[n-i][n-i]<<endl;
            for (int j = i; j < n; j++) {
                macierz[n - j][n] = macierz[n - j][n] - (pom * macierz[n - j][n - i]);
            }
            pom = macierz[n - i][n] / macierz[n - i][n - 1 - i];
            //cout<<"pom = "<<macierz[n-i][n]<<" / "<<macierz[n-i][n-1-i]<<" = "<<pom<<endl;
            macierz[n - i][n] = macierz[n - i][n] / macierz[n - i][n - 1 - i];
        }
        //wyswietlenie wynikow
        for (int i = 1; i < n + 1; i++) {
            cout << char(macierz[0][i - 1] + 96) << " = " << macierz[i][n] << endl;
            //cout<<macierz[0][i-1]<<" = "<<macierz[i][n]<<endl;
        }
    }
}
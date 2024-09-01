#include <iostream>

using namespace std;
int main()
{
    int rozmiar = 5;
    double wezly[rozmiar] = {1,1,2,2,2};
    double wartosci[rozmiar] = {2,3,6,7,8};
    double tabela[rozmiar+1][rozmiar+1];
    for(int i=0;i<=rozmiar;i++)
    {
        for(int j=0;j<=rozmiar;j++)
        {
            tabela[i][j]=0;
        }
    }
    int pom=0;
    int ilcznik=1;
    for(int i=0;i<rozmiar;i++)
    {
        tabela[i][0] = wezly[i];
        for(int j=1;j<=ilcznik;j++)
        {
            tabela[i][j] = wartosci[j+pom-1];
        }
        if(wezly[i] == wezly[i+1]) ilcznik = ilcznik + 1;
        else
        {
            pom = pom +ilcznik;
            ilcznik=1;
        }
    }
    pom=0;
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=2;j<i+2;j++)
        {
            if(tabela[i][j]==0)
            {
                pom = i;
                while ( tabela[pom][0] == tabela[i][0])
                {
                    pom--;
                }
                tabela[i][j] = (tabela[i][j-1] - tabela[i-1][j-1])/(wezly[i]-wezly[pom]);
            }
        }
    }
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            cout<<tabela[i][j]<<" ";
        }
        cout<<endl;
    }

}
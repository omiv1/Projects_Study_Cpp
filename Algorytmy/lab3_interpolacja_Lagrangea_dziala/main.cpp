#include <iostream>
//wielomian interpolacji degradacji

using namespace std;
int main()
{
    int rozmiar=3,punkt;
    cout<<"podaj rozmiar: "<<endl;
    //cin>>rozmiar;
    cout<<"podaj punkt: "<<endl;
    cin>>punkt;
    int tablica[rozmiar+1][rozmiar+1];
    //podanie danych
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<=rozmiar;j++)
        {
            tablica[i][j]=1;
        }
    }
    tablica[0][0]=0;
    tablica[1][0]=1;
    tablica[2][0]=3;
    tablica[0][1]=1;
    tablica[1][1]=3;
    tablica[2][1]=2;
    /*for(int i=0;i<rozmiar;i++)
    {
        cout<<"podaj x["<<i<<"]: ";
        cin>>tablica[i][0];
        cout<<"podaj y["<<i<<"]: ";
        cin>>tablica[i][1];
    }*/
    cout<<endl;
    //sprawdzenie kolejnosci
    int pom=tablica[0][0];
    for(int i=0;i<rozmiar;i++)
    {
        if(pom>tablica[i][0])
        {
            cout<<"zla kolejnosc"<<endl;
            break;
        }
    }
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            cout<<tablica[i][j]<<" ";
        }
        cout<<endl;
    }

    double iloczyn[rozmiar];
    for(int i=0;i<rozmiar;i++)
    {
        iloczyn[i]=1;
    }
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            if(j!=i)
            {
                iloczyn[i] = iloczyn[i] * ((1.0*punkt - 1.0*tablica[j][0])/(1.0*tablica[i][0]-1.0*tablica[j][0]));
            }
        }
    }
    for(int i=0;i<rozmiar;i++)
    {
        cout<<iloczyn[i]<<endl;
    }
    double suma=0;
    for(int i=0;i<rozmiar;i++)
    {
        suma = suma + tablica[i][1]*iloczyn[i];
    }
    cout<<suma<<endl;

}

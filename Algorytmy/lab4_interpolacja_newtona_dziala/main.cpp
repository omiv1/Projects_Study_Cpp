#include <iostream>

using namespace std;
int main()
{
    int rozmiar = 4;
    int x[rozmiar] = {-1,0,1,2};
    int y[rozmiar] = {2,1,2,7};
    double w[rozmiar+1][rozmiar+1];

    for (int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar+1;j++)
        {
            w[i][j]=0;
        }
    }
    for (int i=0;i<rozmiar;i++)
    {
        w[i][0]=x[i];
        w[i][1]=y[i];
    }
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar+1;j++)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=2;j<i+2;j++)
        {
            w[i][j] = (w[i][j-1] - w[i-1][j-1]) / (w[i][0] - w[i+1-j][0]);
        }
    }
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<i+2;j++)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"podaj punkt: "<<endl;
    double punkt;
    cin>>punkt;
    double suma=0;
    double iloczyn=1;
    for(int i=1;i<rozmiar+1;i++)
    {
        for(int j=0;j<i-1;j++)
        {
            iloczyn = iloczyn * (punkt - w[j][0]);
        }
        suma = suma + (w[i-1][i] * iloczyn);
        cout<<w[i-1][i]<<" : "<<iloczyn<<endl;

        iloczyn=1;
    }
    cout<<endl<<suma<<endl;
}
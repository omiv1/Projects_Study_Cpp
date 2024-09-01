#include <iostream>

using namespace std;
int main()
{
    int rozmiar = 3,punkt = 2;
    int x[rozmiar] = {0,1,3};
    int y[rozmiar] = {1,3,2};
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
    cout<<endl;
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar+1;j++)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
   // cout<<endl;
   //int pom=0;
    for(int j=2;j<=rozmiar;j++)
    {
        for(int i=0;i<rozmiar-1-j+2;i++)
        {
            //w[i][j] = pom;
            //pom++;
            w[i][j] = ((w[i+1][j-1]*(punkt - w[i][0]))-((punkt - w[i+j-1][0])*w[i][j-1])) / (w[j-1+i][0] - w[i][0]);
            cout<<w[i+1][j-1]<<" * (" <<punkt<<" - "<<w[i][0]<<") - ("<<punkt<<" - "<<w[i+j-1][0]<<") * "<<w[i][j-1]<<" / "<<w[j-1+i][0] - w[i][0]<<endl;
            //cout<<w[i][j]<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar+1-i;j++)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }

}
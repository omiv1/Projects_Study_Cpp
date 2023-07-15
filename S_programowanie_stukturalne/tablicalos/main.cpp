#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n=5;
    int tab [n][n];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            tab[i][j]=rand();
        }
    }
    int m=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(tab[i][j]>m)
            {
                m=tab[i][j];
                //cout<<m<<endl;
            }
        }
    }
        cout<<m<<endl;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }

}

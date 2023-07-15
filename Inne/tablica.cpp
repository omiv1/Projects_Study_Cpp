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
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}

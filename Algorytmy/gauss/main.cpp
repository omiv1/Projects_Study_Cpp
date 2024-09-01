#include <iostream>

using namespace std;
int main() {
    int n=4;

    double macierz[n+1][n+1] = {{1,2,3,4,5},{1,2,-1,2,0},{1,0,-2,4,4},{0,-3,1.5,7,0},{0,-1,1,6,-1}};
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<macierz[i][j]<<" ";
        }
        cout<<endl;
    }
    int k=0;
    double pom[n+1];
    for(int i=1;i<n;i++)
    {
        k=0;
        while (macierz[k][i-1]!=0)
        {
            pom[k] = macierz[i+1][i-1] / macierz[i][i-1];
            k++;
        }
        for(int j=i-1;j<=n;j++)
        {
            for(int )
            if(pom!=0) macierz[i+1][j] = macierz[i+1][j] - (pom*macierz[i][j]);
        }

        for(int j=0;j<=n;j++)
        {
            for(int k=i-1;k<n;k++)
            {

            }
        }
    }
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<macierz[i][j]<<" ";
        }
        cout<<endl;
    }
}

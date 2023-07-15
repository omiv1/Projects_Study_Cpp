#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void wypisz(int lis[],int n)
{
    for (int i=0;i<n;i++)
    {
        lis[i]=6;
        cout<<lis[i]<<endl;
    }
}
int main()
{
    srand(time(NULL));
    int low=10,high=300;
	int a;
	cin>>a;
	cout<<endl;
	int *tab = new int[a];
	for (int i=0;i<a;i++)
        tab[i]=low+rand()%(high-low+1);
    for (int i=0;i<a;i++)
        for(int j=0;j<a-i-1;j++)
            if (tab[j]>tab[j+1]) swap(tab[j],tab[j+1]);

    for (int i=0;i<a;i++)
    {
        cout<<tab[i]<<endl;
    }
    cout<<endl;
    wypisz(tab,a);
    cout<<endl;
    for (int i=0;i<a;i++)
    {
        cout<<tab[i]<<endl;
    }
	return 0;
}

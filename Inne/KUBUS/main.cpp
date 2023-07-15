#include <iostream>

using namespace std;

int  funkca(int tab[],int n)
{
    int licznik=0;
    int poczatek=0,koniec=0;
    for(int j=0;j<n;j++)
    {
        if (tab[j] <= tab[j + 1])
        {
            koniec += 1;
        }
        else
        {
            if (koniec - poczatek >= 1)
            {
                for (int g = 0; g < koniec - poczatek; g++)
                {
                    for (int k = poczatek; k <= koniec; k++)
                    {
                        if (k - poczatek - g >= 1)
                        {
                            for (int h = poczatek + g; h <= k; h++)
                            {
                                cout << tab[h] << " ";
                            }
                            licznik = licznik + 1;
                            cout << endl;
                        }
                    }
                    cout << endl;
                }
                cout << endl;
            }
            koniec++;
            poczatek = koniec;
        }
    }
    return licznik;
}

int main() {

        int n = 15;
       // cin>>n;
       int tab[15] = {0,1,3,5,7,3,7,4,1,5,7,8,9,10,1};
       cout<<funkca(tab,n);

}

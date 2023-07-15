#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t czas;
    clock_t poczatek,koniec,czas_wyk;
    int n=10000000000,i,x=1;
    float czas_wykonania_1,czas_wykonania_2;
    time(&czas);
    printf("Czas: %s\n",ctime(&czas));
    poczatek=clock();
    for(i=0;i<n;i++)
    {
        x=x*4;
        x=x/4;
    }
    koniec=clock();
    czas_wyk=koniec-poczatek;
    czas_wykonania_1 = ((float)czas_wyk)/CLOCKS_PER_SEC;
    poczatek=clock();
    for(i=0;i<n;i++)
    {
        x=x<<2;
        x=x>>2;
    }
    koniec=clock();
    czas_wyk=koniec-poczatek;
    czas_wykonania_2 = ((float)czas_wyk)/CLOCKS_PER_SEC;
    printf("Czas operacji na liczbach: %f\n",czas_wykonania_1);
    printf("Czas operacji na bitach: %f",czas_wykonania_2);


}

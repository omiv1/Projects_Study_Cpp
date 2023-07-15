#include <stdio.h>
#include <stdlib.h>

void czytaj(float *tablica,int m,int n)
{
    int i;
    for (i=0;i<n*m;i++)
    {
        scanf("%f",tablica+i);
    }
}
void drukuj(float *tablica,int m,int n)
{
    int i;
    for (i=0;i<n*m;i++)
    {
        printf("%.2f ",*(tablica+i));
        if ((i+1)%n==0) printf("\n");
    }
}


int main()
{
    float *tab;
    int n,m;
    scanf("%d",&m);
    scanf("%d",&n);
    tab=(float *) calloc(m*n,sizeof(float));
    czytaj(tab,m,n);
    drukuj(tab,m,n);
}

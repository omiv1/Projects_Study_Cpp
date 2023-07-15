#include <stdio.h>
#include <stdlib.h>

struct produkt
{
    char nazwa[20];
    float cena;
    char firma[20];
};
struct produkt zapis(struct produkt pro[],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        scanf("%s",pro[i].nazwa);
        scanf("%f",&pro[i].cena);
        scanf("%s",pro[i].firma);
    }
    return *pro;
}
void wypisz(struct produkt pro[],int m,float p)
{
    int i=0;
    for(i=0;i<m;i++)
    {
        printf("Produkt: %s, ",pro[i].nazwa);
        printf("Cena: %.2f PLN, ",pro[i].cena);
        printf("Firma: %s, ",pro[i].firma);
        printf("Prowizja: %.2f PLN\n",pro[i].cena*p*0.01);
    }
}
int main()
{
    struct produkt item[100];
    int n;
    float prowizja;
    scanf("%d",&n);
    scanf("%f",&prowizja);
    zapis(item,n);
    wypisz(item,n,prowizja);

}

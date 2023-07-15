#include <stdio.h>
#include <stdlib.h>

struct produkt
{
    char nazwa[20];
    float cena;
    char firma[20];
};
struct produkt wpisz(struct produkt pro[],int m)
{
    int j;
    for (j=0;j<m;j++)
    {
        scanf("%s",pro[j].nazwa);
        scanf("%f",&pro[j].cena);
        scanf("%s",pro[j].firma);
    }
    return *pro;
}
void wypisz(struct produkt pro)
{
    printf("Produkt: %s, ",pro.nazwa);
    printf("Cena: %.2f PLN, ",pro.cena);
    printf("Firmy: %s, ",pro.firma);
}
float prowizja(struct produkt pro,float x)
{
    x=pro.cena*x*0.01;
    return x;
}
void zapis(struct produkt pro[],int m)
{
    FILE *plik_wb;
    plik_wb = fopen("wynik","wb");
    fwrite(pro,sizeof(pro[1]),m,plik_wb);
    fclose(plik_wb);
}
int main()
{
    int n,i;
    float procent;
    scanf("%d",&n);
    scanf("%f",&procent);
    struct produkt item[100];
    wpisz(item,n);
    for (i=0;i<n;i++)
    {
    wypisz(item[i]);
    printf("Prowizja: %.2f PLN\n",prowizja(item[i],procent));
    }
    zapis(item,n);

}

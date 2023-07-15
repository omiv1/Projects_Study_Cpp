#include <stdio.h>
#include <stdlib.h>

struct produkt
{
    char nazwa[20];
    float cena;
    char firma[20];
};
struct produkt wpisz(struct produkt pro)
{
    scanf("%s",pro.nazwa);
    scanf("%f",&pro.cena);
    scanf("%s",pro.firma);
    return pro;
}
void wypisz(struct produkt pro)
{
    printf("%s ",pro.nazwa);
    printf("%.2f ",pro.cena);
    printf("%s ",pro.firma);
}
float prowizja(struct produkt pro,float x)
{
    x=pro.cena*x*0.01;
    return x;
}
int main()
{
    struct produkt item;
    float procent=15;
    item = wpisz(item);
    wypisz(item);
    printf("%f",prowizja(item,procent));

}

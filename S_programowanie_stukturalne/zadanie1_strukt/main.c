#include <stdio.h>
#include <stdlib.h>

struct produkt
{
    char nazwa[20];
    float cena;
    char firma[20];
};
int main()
{
    struct produkt item[100];
    int i,n;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%s",item[i].nazwa);
        scanf("%f",&item[i].cena);
        scanf("%s",item[i].firma);
    }
    for(i=0;i<n;i++)
    {
        printf("%s ",item[i].nazwa);
        printf("%.2f ",item[i].cena);
        printf("%s\n",item[i].firma);
    }

}

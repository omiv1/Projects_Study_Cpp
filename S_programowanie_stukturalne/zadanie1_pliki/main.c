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
   FILE *plik_w;
   plik_w = fopen("wyniki.txt","w");

   FILE *plik_wb;
   plik_wb = fopen("wyniki_b.txt","wb");

   struct produkt item[3];
   int i,n=2;
   char pom[20];

   for(i=0;i<n;i++)
   {
       scanf("%s",item[i].nazwa);
       scanf("%f",&item[i].cena);
       scanf("%s",item[i].firma);
       sprintf(pom,"%.2f",item[i].cena);

       fputs(item[i].nazwa,plik_w);
       fputs(" ",plik_w);
       fputs(pom,plik_w);
       fputs(" ",plik_w);
       fputs(item[i].firma,plik_w);
       fputs("\n",plik_w);

       fputs(item[i].nazwa,plik_wb);
       fputs(" ",plik_wb);
       fputs(pom,plik_wb);
       fputs(" ",plik_wb);
       fputs(item[i].firma,plik_wb);
       fputs("\n",plik_wb);
   }
   fclose(plik_w);

   FILE *plik_r;
   plik_r = fopen("wyniki.txt","r");
   char p_nazwa[20],p_firma[20];
   float p_cena;
   printf("\ndane z pliku tekstowego:\n");
   for(i=0;i<n;i++)
   {
       fscanf(plik_r,"%s %f %s",p_nazwa,&p_cena,p_firma);
       printf("%s %.2f %s\n",p_nazwa,p_cena,p_firma);

   }
   fclose(plik_r);

   FILE *plik_rb;
   plik_rb = fopen("wyniki.txt","rb");
   char p_nazwa_b[20],p_firma_b[20];
   float p_cena_b;
   printf("\ndane z pliku binarnego:\n");
   for(i=0;i<n;i++)
   {
       fscanf(plik_rb,"%s %f %s",p_nazwa_b,&p_cena_b,p_firma_b);
       printf("%s %.2f %s\n",p_nazwa_b,p_cena_b,p_firma_b);

   }
   fclose(plik_rb);

}

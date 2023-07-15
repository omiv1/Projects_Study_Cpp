#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cmath>

using namespace std;

void sort_bombel(int* &tab,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(tab[j]>tab[j+1])
            {
                swap(tab[j],tab[j+1]);
            }
        }
    }
}
void sort_wybor(int* &tab,int n)
{
    int pom,i=n-1,j;
    while(i>0)
    {
        pom=0;
        j=1;
        while(j<=i)
        {
            if(tab[j]>tab[pom])
            {
                pom=j;
            }
            j++;
        }
        swap(tab[i],tab[pom]);
        i--;
    }
}
void sort_wstaw(int* &tab,int n)
{
    int pom,i,j;
    i=n-2;
    while(i>=0)
    {
        j=i;
        pom=tab[j];
        while(pom>tab[j+1] && j<n-1)
        {
            tab[j]=tab[j+1];
            j++;
        }
        tab[j]=pom;
        i--;
    }
}
void sort_szybki(int* &tab,int lewy,int prawy)
{
    int srodek,piwot,granica,i;
    srodek = int((lewy+prawy)/2);
    piwot = tab[srodek];
    tab[srodek] = tab[prawy];
    granica = lewy;
    i = lewy;
    while (i<prawy)
    {
        if(tab[i]<piwot)
        {
            swap(tab[granica],tab[i]);
            granica++;
        }
        i++;
    }
    tab[prawy]=tab[granica];
    tab[granica]=piwot;
    if(lewy<granica-1) sort_szybki(tab,lewy,granica-1);
    if(granica+1<prawy) sort_szybki(tab,granica+1,prawy);
}
int flaga_polska(int* &tab,int n,int granica)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while (tab[i]<=granica and i<j) i++;
        while (tab[j]>=granica and i<j) j--;
        if(i<j)
        {
            swap(tab[i],tab[j]);
            i++;
            j--;
        }
    }
    if(tab[i]<=granica) return i+1;
    else return i;
}
void flaga_franc(int* &tab,int n,int granica1,int granica2,int &p1,int &p2)
{
    int i=-1;
    int j=0;
    int k=n;
    while(j<k)
    {
        if(tab[j]<=granica1)
        {
            i++;
            swap(tab[i],tab[j]);
            j++;
        }
        else
        {
            if(tab[j]>granica2)
            {
                k--;
                swap(tab[k],tab[j]);
            }
            else j++;
        }
    }
    p1=i;
    p2=k;
}
void sort_szybki2(int* &tab,int lewy,int prawy)
{
    int i=lewy;
    int j=prawy;
    int srodek=int((lewy+prawy)/2);
    int pivot=tab[srodek];
    while(i<=j)
    {
        while(tab[i]<pivot) i++;
        while(tab[j]>pivot) j--;
        if(i<=j)
        {
            swap(tab[i],tab[j]);
            i++;
            j--;
        }
    }
    if(lewy<j) sort_szybki2(tab,lewy,j);
    if(prawy>i) sort_szybki2(tab,i,prawy);
}
void wzorzec_naiwy(string tekst,int n, string wzor, int m)
{
    int j,pom,k;
    for(int i=0;i<n-m+1;i++)
    {
        j=0;
        pom=0;
        k=0;
        while(k==0)
        {
            if (tekst[i+j]==wzor[j]) pom++;
            if (tekst[i+j]!=wzor[j]) k=1;
            if (pom==m)
            {
                cout<<i<<" ";
                k=1;
            }
            j++;
        }

    }
}
void tablica_KMP(string wzor,int m,int p[])
{
    p[0]=0;
    p[1]=0;
    int t=0;
    int i=1;
    while(i<m)
    {
        while(t>0 and wzor[t] != wzor[i])
        {
            t = p[t];
        }
        if(wzor[t] == wzor[i])
        {
            t++;
        }
        p[i+1]=t;
        i++;
    }
}
void wzorzez_KMP(string tekst,int n,string wzor,int m,int p[])
{
    int i=0;
    int j=0;
    while (i<n-m+1)
    {
        while(wzor[j] == tekst[j+i] and j<m) j++;
        if(j==m) cout<<i<<" ";
        i=i+max(1,j-p[j]);
        j=p[j];
    }
}
void tablica_Przesuniec(string wzor,int* &p,int n,char pocz, char kon)
{
    int n_pocz=(int)pocz;
    int n_kon=(int)kon;
    int i=0;
    while(i<=n_kon-n_pocz)
    {
        p[i]=-1;
        i++;
    }
    i=0;
    while(i<n)
    {
        p[wzor[i]-n_pocz]=i;
        i++;
    }

}
void bm(string wzor,string tekst,int n,int m,int* &p,char pocz)
{
    int n_pocz=(int)pocz;
    int i=0,j;
    while(i<=m-n)
    {
        j=n-1;
        while(j>-1 && wzor[j]==tekst[i+j])
        {
            j--;
        }
        if(j==-1)
        {
            cout<<i<<" ";
            i++;
        }
        else i=i+max(1,j-p[tekst[i+j]-n_pocz]);
    }
}
int make_hash(char s,char off,int exp, int p)
{
    int has;
    has = has + ((int)s- (int)off)*pow(p,exp);
    return has;
}
int update_hash(int has,char s_prev,char s_next,char off,int exp,int p)
{
    int u_has;
    u_has = has-((int)s_prev-(int)off)*pow(p,exp);
    u_has = u_has*p;
    u_has = u_has+((int)s_next-(int)off);
    return u_has;
}
void kr(string wzor,string text,int lenP,int lenT,int p,char off)
{
    int hashP=0;
    int hashT=0;
    int i,j;
    i=0;
    while(i<lenP)
    {
        hashP = hashP+make_hash(wzor[i],off,p,lenP-i-1);
        hashT = hashT+make_hash(text[i],off,p,lenP-i-1);
        i++;
    }
    i=lenP;
    j=0;
    while(i<=lenT)
    {
        if(hashP==hashT)
        {

        }
        if(i<lenT)
        {
            hashT=update_hash(hashT,text[j],text[i],off,p,lenP-1);
        }
        i++;
        j++;
    }
}
int wyszukiwanieLiniowe(int x[],int n,int wartosc)
{
    int i;
    i=0;
    while (i<n)
    {
        if (x[i]==wartosc)
        {
            return i;
        }
        i++;
    }
    return -1;
}
int wyszukiwanieBisekcyjne(int x[],int n,int wartosc)
{
    int lewy=0;
    int prawy=n-1;
    int srodek;
    while (lewy<=prawy)
    {
        srodek=(int)(lewy+prawy)/2;
        if(x[srodek]==wartosc)
        {
            return srodek;
        }
        else
        {
            if(wartosc<x[srodek])
            {
                prawy=srodek-1;
            }
            else
            {
                lewy=srodek+1;
            }
        }
    }
    return -1;
}


int main()
{
    srand(time(NULL));
    int n=10;
    int* tab;
    tab = new int[n];
    int* prz;
    prz=new int[40];
    for (int i=0;i<n;i++)
    {
        tab[i]=rand()%100;
    }
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    //sort_bombel(tab,n);
    //sort_wybor(tab,n);
    //sort_wstaw(tab,n);
    //sort_szybki(tab,0,n-1);
    //int granica = flaga_polska(tab,n,50); cout<<granica<<endl;
    //int p1,p2; flaga_franc(tab,n,25,75,p1,p2); cout<<p1<<" "<<p2<<endl;
    //sort_szybki2(tab,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    string tekst = "abacabacabacababacababacabab";
    string wzor = "abacabab";
    cout<<tekst.length()<<" "<<wzor.length()<<endl;
    int p[wzor.length()+1]={0};
    tablica_KMP(wzor,wzor.length(),p);
    for(int i=0;i<wzor.length()+1;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<wzor.length()+1;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl<<"  ";
    for(int i=0;i<wzor.length();i++)
    {
        cout<<wzor[i]<<" ";
    }

    cout<<endl<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<char(97+i)<<" ";
    }
    cout<<endl;
    tablica_Przesuniec("baac",prz,4,'a','e');
    for(int i=0;i<5;i++)
    {
        cout<<prz[i]<<" ";
    }
    cout<<endl;
    bm("baac","babaacbdbaacec",4,14,prz,'a');


    cout<<endl;
    tablica_Przesuniec(wzor,prz,wzor.length(),'a','c');
    bm(wzor,tekst,wzor.length(),tekst.length(),prz,'a');
    cout<<endl;
    //cout<<endl<<(int)'b';
    wzorzez_KMP(tekst,tekst.length(),wzor,wzor.length(),p);
    cout<<endl;
    wzorzec_naiwy(tekst,tekst.length(),wzor,wzor.length());

    cout<<endl<<endl;
    kr("aabb","abaabbacdfaabbfdbbaacd",4,22,5,'a');
    cout<<endl<<endl;

    int tablica[10]={1,1,2,5,2,3,6,2,1,5};
   // tablica = new int[10];
    cout<<wyszukiwanieBisekcyjne(tablica,10,2);
    cout<<endl;
    cout<<wyszukiwanieLiniowe(tablica,10,2);

    /*int** tab;
    tab = new int*[n];
    for (int i=0;i<n;i++)
    {
        tab[i] = new int[n];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            tab[i][j]=rand()%100;
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        delete tab[i];
    }
    delete []tab;*/

}

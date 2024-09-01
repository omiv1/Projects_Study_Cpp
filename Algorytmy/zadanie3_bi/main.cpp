#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

void zadanie11(int n)
{
    if(n==3){
        ofstream hasla113("hasla113.txt");
        for(int i=97;i<=122;i++)
        {
            for(int j=97;j<=122;j++)
            {
                for(int k=97;k<=122;k++)
                {
                    hasla113<<char(i)<<char(j)<<char(k)<<endl;
                }
            }
        }}
    if(n==4){
        ofstream hasla114("hasla114.txt");
        for(int i=97;i<=122;i++)
        {
            for(int j=97;j<=122;j++)
            {
                for(int k=97;k<=122;k++)
                {
                    for(int h=97;h<=122;h++)
                    {
                        hasla114<<char(i)<<char(j)<<char(k)<<char(h)<<endl;
                    }
                }
            }
        }}
    if(n==5){
        ofstream hasla115("hasla115.txt");
        for(int i=97;i<=122;i++)
        {
            for(int j=97;j<=122;j++)
            {
                for(int k=97;k<=122;k++)
                {
                    for(int h=97;h<=122;h++)
                    {
                        for(int g=97;g<=122;g++)
                        {
                            hasla115<<char(i)<<char(j)<<char(k)<<char(h)<<char(g)<<endl;
                        }
                    }
                }
            }
        }}
    if(n==6){
        ofstream hasla116("hasla116.txt");
        for(int i=97;i<=122;i++)
        {
            for(int j=97;j<=122;j++)
            {
                for(int k=97;k<=122;k++)
                {
                    for(int h=97;h<=122;h++)
                    {
                        for(int g=97;g<=122;g++)
                        {
                            for(int f=97;f<=122;f++)
                            {
                                hasla116<<char(i)<<char(j)<<char(k)<<char(h)<<char(g)<<char(f)<<endl;
                            }
                        }
                    }
                }
            }
        }}
}
int hex2dec(string hex)
{
    int result = 0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            result += (hex[i]-48)*pow(16,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            result += (hex[i]-55)*pow(16,hex.length( )-i-1);
        } else if (hex[i]>=97 && hex[i]<=102) {
            result += (hex[i]-87)*pow(16,hex.length()-i-1);
        }
    }
    return result;
}
string dec2Hexa(int n)
{
    string ans = "";

    while (n != 0) {
        int rem = 0;
        char ch;
        rem = n % 16;
        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
        ans += ch;
        n = n / 16;
    }
    int i = 0, j = ans.size() - 1;
    while(i <= j)
    {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}
void zadanie3(string b1,string b2)
{
    int x=-1,y,bi1 = hex2dec(b1),bi2 = hex2dec(b2),i=0;
    while(x==-1)
    {
        srand(i);
        y=rand()%256;
        if(y == bi2) x=i;
        i++;
    }
    cout<<x;
    /*
    srand(time(NULL));
    for(int i=0;i<8;i++)
    {
        cout<<rand()%256<<" ";
    }
    cout<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<dec2Hexa(rand()%256)<<" ";
    }*/
}
int kontrolna(string p)
{
    int suma=0,x;
    for(int i=0;i<p.size();i++)
    {
        x = char(p.at(i))-48;
        if(x==0) x = x * 1;
        if(x==0) x = x * 1;
        if(x==0) x = x * 1;
        if(x==0) x = x * 1;
        if(x==0) x = x * 1;
        if(x==0) x = x * 1;
        if(x==0) x = x * 1;
        if(x==0) x = x * 1;
        if(x==0) x = x * 1;


        suma = suma + x;
    }
    return suma;
}
void zadanie2()
{
    ofstream pesele("pesele.txt");
    int p=0;

}
int main()
{
    //zadanie11(6);
    /*zadanie3("51","9A");
    srand(114);
    cout<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<dec2Hexa(rand()%256)<<" ";
    }*/
    cout<<kontrolna("12345678")<<endl;

}

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string toBinary(int n,int m)
{
    if(n==64) return "nnnnnnnn";
    else
    {
        string r;
        while (n != 0) {
            r = (n % 2 == 0 ? "0" : "1") + r;
            n /= 2;
        }
        if (r.size() < 8 and m == 1)
            for (int i = r.size(); i < 8; i++) {
                r = '0' + r;
            }
        if (r.size() < 6 and m == 0)
            for (int i = r.size(); i < 6; i++) {
                r = '0' + r;
            }
        return r;
    }
}
char toBase(int n)
{
    if(n==64)
    {
        return '=';
    }
    if(n>=0 and n<=25)
    {
        return char(n+65);
    }
    if(n>=26 and n<=51)
    {
        return char(n+97-26);
    }
    if(n>=52 and n<=61)
    {
        return char(n+48-52);
    }
    if(n==62) return '+';
    if(n==63) return '/';
}
int toAsci(char znak)
{
    if('=' == znak) return 64;
    if('+' == znak) return 62;
    if('/' == znak) return 63;
    if(znak>='a' and znak<='z') return char(znak)-71;
    if(znak>='A' and znak<='Z') return char(znak)-65;
    if(znak>='0' and znak<='9') return char(znak)+4;
}
int convert(string n)
{
    int x=0;
    if(n == "nnnnnn") return 64;
    else
    {
        for (int i = 0; i < n.size(); i++) {
            x = x + ((n.at(i) - 48) * pow(2, n.size() - i - 1));
        }
        return x;
    }
}
string kodowanie(string tekst)
{
    string ciag = "",nowy = "",kod = "";
    char znak;
    int x;
    //cout<<tekst<<endl;
    for(int i=0;i<tekst.size();i++)
    {
        ciag = ciag + toBinary(char(tekst.at(i)),1);
    }
    if(ciag.size()%24 != 0)
    {
        while(ciag.size()%6 != 0)
            ciag = ciag + '0';
        while(ciag.size()%24 != 0)
            ciag = ciag + 'n';
    }
    //cout<<ciag<<endl;
    for(int i=0;i<ciag.size();i = i+6)
    {
        nowy = ciag.substr(i,6);
        //cout<<nowy<<" "<<endl;
        x = convert(nowy);
        //cout<<x<<" "<<toBase(x)<<endl;
        kod = kod + toBase(x);
    }
    return kod;
}
string dekodowanie(string tekst)
{
    string ciag = "",nowy = "", kod = "";
    int x;
    for(int i=0;i<tekst.size();i++)
    {
        //cout<<tekst.at(i)<<" "<<toAsci(tekst.at(i))<<endl;
        ciag = ciag + toBinary(toAsci(tekst.at(i)),0);
    }
    //cout<<ciag<<endl;
    for(int i=0;i<ciag.size();i = i+8)
    {
        nowy = ciag.substr(i,8);
        //cout<<nowy<<" "<<endl;
        x = convert(nowy);
        if(nowy.at(nowy.size()-1)!='n')
        {
            //cout << x << " " << char(x) << endl;
            kod = kod + char(x);
        }
    }
    return kod;
}
int main()
{
    string tekst,kod;
    cin>>tekst;
    kod = kodowanie(tekst);
    cout<<kod<<endl;
    tekst = dekodowanie(kod);
    cout<<tekst;

}

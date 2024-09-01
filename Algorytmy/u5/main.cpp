#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include "Dictionary.h"

using namespace std;

pair<int,int> zadanie1(vector<int> v)
{
    set<int> s;
    for(int i=0;i<v.size();i++)
    {
        s.insert(v.at(i));
    }
    cout<<endl;
    for_each(v.begin(),v.end(),[](int a){cout<<a<<" ";});
    cout<<endl;
    for_each(s.begin(),s.end(),[](int a){cout<<a<<" ";});
    cout<<endl;
    sort(v.begin(), v.end());
    for_each(v.begin(),v.end(),[](int a){cout<<a<<" ";});
    cout<<endl;
    int i = 0;
    int suma = 0;
    int p;
    for(int s1 : s)
    {
        suma = suma + s1;
        if(v.at(i) == s1)
        {

        }
        else
        {
            p = s1;
        }
    }
    pair<int, int> wynik(suma, p);
    return wynik;
}
pair<int,int> zadanie11(vector<int> vec)
{
    int suma = 0;
    int dup;
    set<int> s;
    for(int v : vec)
    {
        if(s.insert(v).second)
        {
            suma = suma + v;
        } else
        {
            dup = v;
        }
    }
    pair<int,int> wynik(suma,dup);
    return wynik;
}

template<typename T>
void zadanie2(set<T> s1,set<T> s2)
{
    for(T s: s1)
    {
        if(s2.find(s) == s2.end())
        {
            cout<<s<<" ";
        }

    }
    cout<<endl;
    for(T s: s2)
    {
        if(s1.find(s) == s1.end())
        {
            cout<<s<<" ";
        }

    }
    cout<<endl;
}

string zadanie3(string s1,string s2)
{
    map<char, int> licznik;
    for(char z: s1)
    {
        licznik[z] ++;
    }
    for(char z: s2)
    {
        licznik[z] --;
    }
    for(pair<char,int> p : licznik) {
        if(p.second != 0) cout<<p.first<<endl;
    }

}

int main() {
//    vector<int> vec = {1,8,4,3,4,5,6};
//
//    pair<int,int> zad1;
//    zad1 = zadanie1(vec);
//    cout<<zad1.first<<" "<<zad1.second<<endl;
//
//    zad1 = zadanie11(vec);
//    cout<<zad1.first<<" "<<zad1.second<<endl;
//
//    set<int> s1 = {1,2,3,4};
//    set<int> s2 = {2,3,5};
//    zadanie2(s1,s2);
//
//    set<double> s11 = {1.5,2.5,3.5,4.5};
//    set<double> s22 = {2.5,3.5,5.5};
//    zadanie2(s11,s22);
//
//    string t1 = "abcdefgh";
//    string t2 = "fedabcg";
//    zadanie3(t1,t2);

    Dictionary d;
    d.add("jablko","apple");
    d.add("wisnia","cherry");
    d.add("banan","banana");
    d.add("winogron","grape");
    d.show();
    d.get("banan");
    d.remove("x");
    d.remove("banan");
    d.show();
    cout<<endl;
    d.a_z();



    return 0;
}

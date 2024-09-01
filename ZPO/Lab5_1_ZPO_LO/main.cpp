#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;
void show( set <int> s)
{
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout<<endl;
}

void showMap( map<string, int> m)
{
    cout<<endl<<"m: "<<endl;
    map<string, int>::iterator it;
    for(it=m.begin(); it!=m.end(); ++it)
    {
        cout << it->first <<" "<<it->second<<endl;
    }
    cout<<endl;
}

map<string, int>::iterator searchByValue(map<string, int>& m, int val)
{
    map<string, int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if (it->second == val) break;
    }

    return it;
}

int main()
{
//    set <int> s;
//    s.insert(2);
//    s.insert(1);
//    s.insert(3);
//    s.insert(7);
//    s.insert(3);
//    show(s);
//    s.erase(s.begin(), s.find(2));
//    show(s);
//    cout<<s.count(2)<<endl;
//    s.erase(2);
//    cout<<s.count(2)<<endl;

//    set <int> s1={1,2,3,7};
//    set<int>s2={-2,4,1,7,6};
//    cout<<"s1: ";
//    show(s1);
//    cout<<"s2: ";
//    show(s2);
//    set<int>sUnion,sIntersec,sDiffer;
//    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int>>(sUnion,sUnion.begin()));
//    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int>>(sIntersec,sIntersec.begin()));
//    set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int>>(sDiffer,sDiffer.begin()));
//    cout<<"sUnion: ";
//    show(sUnion);
//    cout<<"sIntersec: ";
//    show(sIntersec);
//    cout<<"sDiffer: ";
//    show(sDiffer);

//    set<int> s3={3,8};
//    pair <set<int>::iterator, bool > res;
//    res=s3.insert(6);
//    cout<<"Dodany element: "<<*(res.first)<<endl;
//    cout<<"Czy element dodany? "<<res.second<<endl;
//    show(s3);

    map<string,int> m;
    m.insert(pair<string,int>("Kowalski",4500));
    m.insert(make_pair("Nowak",2000));
    m["Adamek"]=3000;
    showMap(m);
    int salary=m.find("Kowalski")->second;
    cout<<"Zarobki Kowalskiego: "<<salary<<endl;
    m.erase("Adamek");
    showMap(m);
    cout<< "Czy jest Kowalski? "<<m.count("Kowalski")<<endl;

    map<string, int>::iterator it = searchByValue(m, 2000);
    if(it != m.end())
        cout<<"Element znaleziony: "<<it->first<<" "<<
        it->second<<endl;
    else
    cout<<"Brak elementu"<<endl;


    return 0;
}
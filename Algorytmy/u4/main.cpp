#include <iostream>
#include <vector>
#include <algorithm>
#include "City.h"
#include "Citizen.h"


using namespace std;

void show(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

void zadanie2()
{
    srand(time(NULL));
    int n = 15;
    int x;
    vector<int> vec1;
    vector<int> vec2;
    vector<int> vec3;
    for(int i = 0;i<n;i++)
    {
        x = (rand()%200)-100;
        if(x > 0)
        {
            vec1.push_back(x);
        } else
        {
            vec2.push_back(x);
        }

    }
    //merge(vec1.begin(), vec1.end(),vec1.begin(),vec2.end(),vec3.begin());
    vec1.insert(vec1.end(),vec2.begin(),vec2.end());
    for(int i : vec1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main() {
    zadanie2();
    City c("miasto");
    Citizen m1("imie","nazwisko",43,'k',"21-560");
    Citizen m2("imie2","nazwisko2",30,'m',"21-561");
    Citizen m3("imie2","nazwisko2",30,'m',"21-561");
    Citizen m4("imie2","nazwisko2",30,'m',"21-561");
    c.addCitizen(m1);
    c.addCitizen(m2);
    c.addCitizen(m3);
    c.addCitizen(m4);
    c.show();
    cout<<c.city_citizens()<<endl;
    cout<<c.woman()<<endl;
    cout<<c.postal_codes()<<endl;


//    vector<int> vec;
//    srand(time(NULL));
//
//    for(int i=0;i<10;i++)
//    {
//        vec.push_back(rand()%100000);
//    }
//    show(vec);
//    sort(vec.begin(), vec.end());
//    show(vec);
//
//    sort(vec.begin(),vec.end(),[](int a,int b)
//    {
//        int s1 = 0;
//        int s2 = 0;
//        int t1 = a;
//        int t2 = b;
//        while (t1 >0)
//        {
//            s1 = s1 + t1%10;
//            t1 = t1/10;
//        }
//        while (t2 > 0)
//        {
//            s2 = s2 + t2%10;
//            t2 = t2/10;
//        }
//        return s1 < s2;
//    });
//    show(vec);
//
//    sort(vec.begin(),vec.end(),[](int a,int b)
//    {
//        int s1 = 0;
//        int s2 = 0;
//        int t1 = a;
//        int t2 = b;
//        while (t1 >0)
//        {
//            s1 = s1 + 1;
//            t1 = t1/10;
//        }
//        while (t2 > 0)
//        {
//            s2 = s2 + 1;
//            t2 = t2/10;
//        }
//        return s1 > s2;
//    });
//    cout<<"show:"<<endl;
//    show(vec);
//    cout<<"for_each:"<<endl;
//    for_each(vec.begin(),vec.end(),[](int a) {cout<<a<<" ";});
//    cout<<endl;
//    cout<<"for:"<<endl;
//    for(int v : vec)
//    {
//        cout<<v<<" ";
//    }
//    cout<<endl;

    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
int main() {

    string la;
    int pa,pb,intla=0;
    int da;
    cout<<"Podaj liczbe:";
    cin>>la;
    cout<<"Podaj podstawe liczby:";
    cin>>pa;
    cout<<"Podaj podstawe na jaka ma byc zamieniona liczba:";
    cin>>pb;
    cout<<"Podales liczbe "<<la<<" o podstawie "<<pa<<endl;
    da = la.length();
    int *ta;
    ta = new int(da);
    for(int i=0;i<da;i++)
    {
        if ( la[i] < 58 ) ta[i] = la[i] - 48;
        if ( la[i] < 91 and la[i] > 58 ) ta[i] = la[i] - 55;
        if ( la[i] > 91 ) ta[i] = la[i] - 87;
    }
    for(int i=0;i<da;i++)
    {
        //cout<<ta[i]<<" ";
    }
    //cout<<endl;
    for(int i=0;i<da;i++)
    {
        intla = intla + (ta[i] * pow(pa,da-i-1));
        //cout<<intla<<" ";
    }
    //cout<<endl<<intla<<endl;
    delete ta;
    int i=0;
    int pom;
    vector<int> lb;
    while(intla > 0)
    {
        lb.push_back( intla % pb );
        pom = intla - (intla % pb);
        intla = pom / pb;
        //cout<<intla<<" ";
    }
    //cout<<endl;
    int db;
    db = lb.size();
    cout<<"Liczba po konwersji: ";
    for (int i=0;i<db;i++)
    {
        if ( lb[db-i-1] > 10 )
        {
            cout<<char(lb[db-i-1]+55);
        }
        else cout<<lb[db-i-1];
    }

    return 0;
}

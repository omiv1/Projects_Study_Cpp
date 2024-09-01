#include <iostream>
#include <vector>

#include "Awaria.h"
#include "Komputery.h"
#include "fileHandling.h"
#include <algorithm>
#include <regex>


using namespace std;

void zadanie3(vector<Awaria> a, vector<Komputery> k)
{
    int suma = 0;
    for (Komputery element : k)
    {
        auto it = find_if(a.begin(), a.end(), [element](Awaria awaria) {return awaria.getNumerKomputera() == element.getNumerKomputera();});
        if (it == a.end())
        {
            //element.show();
            suma ++;
        }
    }
    cout<<"Liczba komputrow: "<<suma<<endl;
}

void zadanie4(vector<Awaria> a, vector<Komputery> k)
{
    for ( Komputery element : k) {
        bool test = all_of(a.begin(), a.end(), [element](Awaria awaria) {
            regex pattern("^\\d{2}\\.\\d{2}\\.\\d{4}\\.\\d{2}:\\d{2}$");
            return regex_match(awaria.getCzasAwarii(), pattern);
        });

        if (!test) {
            element.show();
        }
    }
}

int main() {

    try {
        vector<Awaria> awarie = fileHandling::read_awarie();
        vector<Komputery> komputery = fileHandling::read_komputery();
        //    for(Awaria a : awarie)
//    {
//        a.show();
//    }
//    for(Komputery k : komputery)
//    {
//        k.show();
//    }
        zadanie3(awarie,komputery);
        zadanie4(awarie,komputery);
    }catch(string e)
    {
        cout<<"Zlapany wyjatek int "<<e<<endl;
    }




    return 0;
}

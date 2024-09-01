#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "Dictionary.h"

using namespace std;

pair<int, int> zadanie1(vector<int> vec)
{
    sort(vec.begin(),vec.end());
    int x,y = vec.at(0);
    int sum = 0;
    for(int v : vec)
    {
        //cout<<v<<", ";
        sum = sum + v;
        if(y == v)
        {
            x = v;
        }
        else
        {
            y = v;
        }
    }
    //cout<<endl<<x<<" "<<sum<<endl;
    sum = sum - x;
    return pair<int,int>(x,sum);
}

template <typename T>
void zadanie2(set<T> set1, set<T> set2) {
    cout << "Element w pierwszym zbierze ale nie w drugim: ";
    for(T element : set1) {
        if(set2.find(element) == set2.end()) {
            cout << element << " ";
        }
    }

    cout << "\nElement w drugim zbierze ale nie w pierszym: ";
    for(T element : set2){
        if(set1.find(element) == set1.end()) {
            cout<<element << " ";
        }
    }

    cout<<endl;
}
char zadanie3(string pierwszy, string drugi) {
    map<char, int> liczniki;

    for (char znak : drugi) {
        liczniki[znak]++;
    }

    for (auto znak : pierwszy) {
        liczniki[znak]--;
    }

    for (auto para : liczniki) {
        if (para.second > 0) {
            return para.first;
        }
    }

    return '\0';
}
int main() {
    vector<int> vec = {5,10,8,2,7,6,9,4,7,1};
    cout<<"Powtarzajacy sie element: "<<zadanie1(vec).first<<endl<<"Suma liczba unikalnych: "<<zadanie1(vec).second<<endl<<endl;

    set<int> set1 = {1, 2, 3, 4, 5};
    set<int> set2 = {3, 4, 5, 6, 7};

    set<char> set3 = {'a','b','c','d'};
    set<char> set4 = {'c','d','e','f'};

    zadanie2(set1, set2);
    zadanie2(set3,set4);
    cout<<endl;

    string map1 = "abc";
    string map2 = "bcaz";

    char znak = zadanie3(map1, map2);
    cout<<"Dodany znak: "<<znak<<endl<<endl;

    Dictionary dictionary;

    dictionary.addWord("apple", "jablko");
    dictionary.addWord("banana", "banan");
    dictionary.addWord("apple", "jablko"); // Powtórne dodanie tego samego słowa
    dictionary.addWord("orange", "pomarancza");

    dictionary.showDictionary();

    dictionary.removeWord("banana");
    dictionary.removeWord("grape"); // Próba usunięcia nieistniejącego słowa

    dictionary.showDictionary();

    dictionary.showTranslation("apple");
    dictionary.showTranslation("grape"); // Próba wyświetlenia tłumaczenia nieistniejącego słowa

    dictionary.addWord("grape", "winogrono");

    dictionary.showSortedDictionary();

    return 0;
}

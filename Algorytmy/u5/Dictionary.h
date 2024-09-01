//
// Created by lukas on 03.12.2023.
//

#ifndef U5_DICTIONARY_H
#define U5_DICTIONARY_H
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Dictionary {
private:
    map<string,string> words;
public:
    Dictionary()
    {

    }
    void add(string slowo, string tlumaczenie)
    {
        if(words.find(slowo) == words.end())
        {
            words[slowo] = tlumaczenie;
        } else
        {
            cout<<"slowo juz istnieje"<<endl;
        }
    }
    void remove(string slowo)
    {
        if(words.find(slowo) == words.end())
        {
            cout<<"brak slowa"<<endl;
        } else
        {
            words.erase(slowo);
        }
    }
    void show()
    {
        for(pair<string,string> p : words)
        {
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
    void get(string slowo)
    {
        cout<<slowo<<" "<<words[slowo]<<endl;
    }
    void a_z()
    {
        vector<pair<string,string>> vec;
        for(pair<string,string> p : words)
        {
            vec.push_back(p);
        }
        sort(vec.begin(), vec.end(),[](auto a, auto b){return a.second < b.second;});
        for(auto v : vec)
        {
            cout<<v.first<<" "<<v.second<<endl;
        }
    }

};


#endif //U5_DICTIONARY_H

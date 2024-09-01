//
// Created by lukas on 04.12.2023.
//

#ifndef U4_CITY_H
#define U4_CITY_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Citizen.h"
#include <map>

using namespace std;
class City {
private:
    vector<Citizen> citizens;
    string city_name;
    map<string,int> kody;
public:
    City(string city_name)
    {
        this -> city_name = city_name;
    }
    void addCitizen(Citizen c)
    {
        citizens.push_back(c);
    }
    void deleteCitizen(string sm, int a)
    {
        remove_if(citizens.begin(),citizens.end(),[&sm, &a](Citizen c){
            return c.getSurename() == sm && c.getAge() == a;
        });
    }
    void show()
    {
        cout<<city_name<<endl;
    }
    int city_citizens()
    {
        int count = 0;
        for(Citizen c : citizens)
        {
            count++;
        }
        return count;
    }
    int woman()
    {
        int count = 0;
        for(Citizen c : citizens)
        {
            if(c.getSex() == 'k') count++;
        }
        return count;
    }
    int postal_codes()
    {
        for(Citizen c : citizens)
        {
            kody[c.getCode()] ++;
        }
        for(auto k : kody)
        {
            cout<<k.first<<" "<<k.second<<endl;
        }
        return kody.size();
    }


};


#endif //U4_CITY_H

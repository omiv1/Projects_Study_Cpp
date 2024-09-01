//
// Created by lukas on 05.11.2023.
//

#ifndef LAB4_3_LO_CITY_H
#define LAB4_3_LO_CITY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "Citizen.h"

using namespace std;
class City {
private:
    vector<Citizen> citizens;
    string city_name;

public:
    City(const string &name) : city_name(name) {}

    void addCitizen(const Citizen &citizen) {
        citizens.push_back(citizen);
    }

    void deleteCitizen(const string &surname, int age) {
        citizens.erase(remove_if(citizens.begin(), citizens.end(), [&surname, age](const Citizen &c) {
            return c.getPostalCode() == surname && c.getAge() == age;
        }), citizens.end());
    }

    void show_citizens() {
        cout << "Citizens of " << city_name << ":" << std::endl;
        for (Citizen &citizen : citizens) {
            citizen.show();
        }
    }

    void show_city() {
        cout << "City Name: " << city_name << endl;
    }

    int women() {
        int count = 0;
        for (Citizen &citizen : citizens) {
            if (citizen.getSex() == 'F') {
                count++;
            }
        }
        return count;
    }

    int city_citizens() {
        return citizens.size();
    }

    int adults() {
        int count = 0;
        for (Citizen &citizen : citizens) {
            if (citizen.getAge() >= 18) {
                count++;
            }
        }
        return count;
    }

    map<string, int> postal_codes() {
        map<string, int> postal_code_count;
        for (const Citizen &citizen : citizens) {
            postal_code_count[citizen.getPostalCode()]++;
        }
        return postal_code_count;
    }
};


#endif //LAB4_3_LO_CITY_H

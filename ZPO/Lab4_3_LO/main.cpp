#include <iostream>
#include <algorithm>
#include <vector>
#include "Citizen.h"
#include "City.h"

using namespace std;

void showCities(vector<City> &cities) {
    for (City &city : cities) {
        city.show_city();
    }
}

void the_most(vector<City> &cities, int mode) {
    if (mode == 1) {
        City most_unique_postal_codes_city = cities[0];
        for (City &city : cities) {
            if (city.postal_codes().size() > most_unique_postal_codes_city.postal_codes().size()) {
                most_unique_postal_codes_city = city;
            }
        }
        most_unique_postal_codes_city.show_city();
    } else if (mode == 2) {
        City least_citizens_city = cities[0];
        for ( City &city : cities) {
            if (city.city_citizens() < least_citizens_city.city_citizens()) {
                least_citizens_city = city;
            }
        }
        least_citizens_city.show_city();
    }
}

void statistic(vector<City> &cities) {
    for (City &city : cities) {
        int total_citizens = city.city_citizens();
        int total_women = city.women();
        int total_men = total_citizens - total_women;
        int total_adults = city.adults();
        int total_minors = total_citizens - total_adults;

        city.show_city();
        //cout << "City Name: " << city.show_city() << endl;
        cout << "Total Citizens: " << total_citizens << endl;
        cout << "Total Women: " << total_women << endl;
        cout << "Total Men: " << total_men << endl;
        cout << "Total Adults: " << total_adults << endl;
        cout << "Total Minors: " << total_minors << endl;
    }
}

void sort_cities(vector<City> &cities) {
    sort(cities.begin(), cities.end(), [](City &a, City &b) {
        return a.city_citizens() < b.city_citizens();
    });
}

int main() {
   vector<City> cities;

    City city1("City1");
    city1.addCitizen(Citizen("John", "Doe", 25, 'M', "12345"));
    city1.addCitizen(Citizen("Alice", "Smith", 32, 'F', "54321"));
    city1.addCitizen(Citizen("Bob", "Johnson", 18, 'M', "12345"));

    City city2("City2");
    city2.addCitizen(Citizen("Emily", "Brown", 29, 'F', "67890"));
    city2.addCitizen(Citizen("David", "Lee", 42, 'M', "12345"));

    cities.push_back(city1);
    cities.push_back(city2);

    showCities(cities);
    the_most(cities, 1);
    the_most(cities, 2);
    statistic(cities);
    sort_cities(cities);

    return 0;
}
/*
 *  Megacity.cpp
 *
 *  Created on: 06 oct 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/424/B?locale=en
 *      Description Solution:
 *      The idea is: store input in a vector of Cities (City is a struct composed of coordinates, distance from Tomsk city, and population). Sort the vector based on the growing distance. Then, sum Tomsk each city population. When sum the total population is greater than 999999, print the distance of current city, else print -1.
 */

#include <iostream>
#include <set>
#include <cstdlib>
#include <math.h>

using namespace std;

struct City{
    int x;
    int y;
    int population;
    double distance;

    City(){}

    City(int init_x, int init_y, int init_population, double init_distance){
        x = init_x;
        y = init_y;
        population = init_population;
        distance = init_distance;
    }

};

struct classcomp {
    bool operator()(const City &c1, const City &c2){
        return c1.distance < c2.distance;
    }
}comparator;


int main() {
    //INPUT DATA
    cout << "\nInsert number cities: ";
    int n;
    cin >> n;

    cout << "\nInsert Tomsk population: ";
    int population;
    cin >> population;

    std::vector<City> cities(n);

    //INITIALIZE
    for(int i = 1; i < n; i++) {
        int x;
        int y;
        int pop;

        cin >> x >> y >> pop;

        double distance = sqrt((x*x)+(y*y));
        cities.emplace_back(x, y, pop, distance);
    }


    std::sort(cities.begin(), cities.end(), comparator);

	for (auto city : cities){
        population += city.population;
        if(population > 999999){
            cout << city.distance << endl;
            return 0;
        }
    }

    cout << -1 << endl;

}

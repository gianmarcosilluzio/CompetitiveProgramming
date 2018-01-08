/*
 *  Megacity.cpp
 *
 *      Created on: 06 oct 2017
 *      Updated on: 08 jun 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/424/B?locale=en
 *      Description Solution:
 *      The idea is: store input in a vector of Cities (City is a pair of double (distance from Tomsk city), and uint64_t population). Sort the vector based on the growing distance. Then, sum Tomsk each city population. When sum the total population is greater than 999999, print the distance of current city, else print -1.
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct classcomp {
    bool operator()(const pair<double, uint64_t> & a, const pair<double, uint64_t> & b){
        return a.first < b.first;
    }
}comparator;

int main(){

    int n;
    cin >> n;
    int population;
    cin >> population;

    vector<pair<double, uint64_t>> cities;
    cities.reserve(n);

    for(int i = 0; i < n; i++) {
        int x, y, pop;
        cin >> x  >> y >> pop;
        double distance = sqrt(x*x + y*y);
        cities.emplace_back(distance, pop);
    }

    sort(cities.begin(), cities.end(), comparator);

    for(auto &city : cities) {
        population += city.second;
        if(population > 999999) {
            cout.precision(8);
            cout << city.first << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}

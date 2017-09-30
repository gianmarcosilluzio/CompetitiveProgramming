/*
 *  FindingTeamMember.cpp
 *
 *  Updated on: 30 sept 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/579/B?locale=en
 *      Description Solution:
 *      The idea is store input in a set in order to have a list of element sorted.
 *      Then, store the best pairings in a vector checking each element if the position of vector is already busy.
 *      If player1 o player2 have already been stored, the element will be discarded.
 */

#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

struct Team{
    int p1;
    int p2;
    int strength;

    Team(){}

    Team(int init_p1, int init_p2, int init_strength){
        p1 = init_p1;
        p2 = init_p2;
        strength = init_strength;
    }

};

struct classcomp {
    bool operator()(const Team* t1, const Team* t2) const{
        return t1->strength >= t2->strength;
    }
};


int main() {
    //INPUT DATA
    int n = 3;
    int array[] = {487060,3831,161856,845957,794650,976977,83847,50566,691206,498447,698377,156232,59015,382455,626960};

    std::set<Team*, classcomp> teams;
    std::set<Team*,classcomp>::iterator itt;
    vector<int> results(n*2);

    //INITIALIZE
    int k = 0;
    for(int i = 1; i < 2*n; ++i) {
        for(int j = 0; j < i; ++j) {
            int strength = array[k++];
            teams.insert(new Team(i, j, strength));
        }
    }

	for (itt=teams.begin(); itt != teams.end(); itt++){
        if(results[(*itt)->p1] == 0 && results[(*itt)->p2] == 0) {
            results[(*itt)->p2] = (*itt)->p1+1;
            results[(*itt)->p1] = (*itt)->p2+1;
        }
    }

    for(int result: results){
        printf("%d ",result);
    }

}

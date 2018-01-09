/*
 *  FiringEmployees.cpp
 *
 *  	Created on: 12 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/firing-employees/0/?ref=self
 *      Description Solution:
 *      The idea is find level of each number (bosses number of each employee), find the prime number of the sum of level and value.

 Time complexity consists of find level and find prime numbers --> O(3N)
 Space complexity --> O(3N)
 */

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

//this function is inspired from Rossano's solution, in my first solution I checked each number if it was a prime number
std::vector<bool> generate_primes(size_t n) {
    std::vector<bool> primes(n, true);
    for(uint64_t i = 2; i <= (uint64_t)sqrt(n); ++i) {
        if (primes[i]) {
            uint64_t sqr = i*i;
            for(uint64_t j = sqr; j < n; j+=i){
                primes[j] = false;
            }
        }
    }

    return primes;
}

std::vector<int> findNumBosses(vector<int> empl, int n){
    std::stack<int> s;
    std::vector<int> bosses(n + 1, 0);
    std::vector<std::vector<int>> positions(n + 1, std::vector<int>());
    for (int i = 0; i < n; ++i) {
        positions[empl[i]].push_back(i + 1);
    }

    s.push(positions[0].front());
    for (int i = 0; i < n; ++i) {
        auto list = positions[s.top()];
        s.pop();
        for (auto pos: list) {
            bosses[pos] = 1 + bosses[empl[pos - 1]];
            s.push(pos);
        }
    }

    return bosses;
}

int findFiredEmployees(vector<int> empl){

    size_t n = empl.size();
    int firedEmpl = 0;
    std::vector<int> bosses = findNumBosses(empl, n);
    auto primes = generate_primes(2*(n + 1));

    for (int i = 1; i <= n; i++) {
        if (bosses[i] && primes[bosses[i] + i]) {
            firedEmpl++;
        }
    }

    return firedEmpl;

}

int main(){
    int num_test_cases = 1;
    cin >> num_test_cases;

    std::vector<int> empl;
    for (int i = 0; i < num_test_cases; ++i) {
        int n = 0;
        cin >> n;
        empl.reserve(n);
        for (int j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            empl.push_back(x);
        }

        cout << findFiredEmployees(empl) << endl;
        empl.clear();
    }

    return 0;
}

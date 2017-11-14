/*
 *  IlyaQueries.cpp
 *
 *  Created on: 14 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/313/B
 *      Description Solution:
 *      The idea is save the sums of adjacent characters of string in a vector. The result of a query is the sum of r (rigth index) less the sum of l (left index) given in input.
 Time complexity consists of looks each character of string --> O(N), where N is a length of string
 Space complexity (space of string) --> O(N)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    string s;
    int l, r, m;

    cin >> s;
    cin >> m;

    int n = s.size();
    vector<uint32_t> sums(n+1, 0);

    for(int i = 1; i < n; i++) {
        if(s[i-1] == s[i]){
            sums[i] = sums[i-1] + 1;
        }else{
            sums[i] = sums[i-1];
        }
    }
    sums[n] = sums[n-1];

    for(int i = 0; i < m; i++) {
        cin >> l >> r;
        cout << sums[r-1]-sums[l-1] << endl;
    }

    return 0;
}

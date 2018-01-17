/*
 *  PashmakProblem.cpp
 *
 *  	Created on: 17 dic 2017
 *      Updated on: 16 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/459/D?locale=en
 *      Description Solution:
 *      The idea is remap values of input sequence, replacing value with rank in ascending order. Save the frequency of occurences in a vector, creating a fenwick tree to compute frequency, scanning sequence from rigth to left storing an vector of count of each value processed. Next, we scanning sequence from left to right, adding -1 in position of suff_counter of element scanned, incrementing counter, and adding to result the sum of counter in position of element scanned. Then print result.

 Time complexity --> Wrost case: O(NlogN)
 Space complexity --> O(n)
*/

#include <iostream>
#include <algorithm>
#include <vector>

#include "fenwick_tree.hpp"

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; i++){
        cin >> sequence[i];
    }
    return sequence;
}

template<typename T>
void remap(vector<T>& a) {
  vector<T> tmp(a.size());

  copy(a.begin(), a.end(), tmp.begin());
  sort(tmp.begin(), tmp.end());

  size_t siz = distance(tmp.begin(), unique(tmp.begin(), tmp.end()));
  tmp.resize(siz);

  for(auto &x : a){
    x = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), x));
  }
}

int main() {
    int n;
    cin >> n;

    auto a = get_input_sequence<int>(n);
    remap<int>(a);

    vector<int> counter(n);
    vector<int> suff_counter(n);

    fenwick_tree<int> f(n);

    for(int i = n-1; i >= 0; i--) {
        counter[a[i]]++;
        suff_counter[i] = counter[a[i]];
        f.add(counter[a[i]], 1);
    }

    fill(counter.begin(), counter.end(), 0);

    uint64_t result = 0;
    for(int i = 0; i < n; i++) {
        f.add(suff_counter[i], -1);
        counter[a[i]]++;
        result += f.sum(counter[a[i]]-1);
    }

    cout << result << endl;
    return 0;
}

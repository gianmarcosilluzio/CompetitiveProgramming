/*
 *  TwoHeap.cpp
 *
 *      Created on: 06 nov 2017
 *      Updated on: 08 jan 2018
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/353/B
 *      Description Solution:
 *      Create structure vector of pair where are contained all input numbers (reversed if the second digit is smaller than first; e.g. 53 will become 35) with own position.
 *      Sort the vector of pair by first value (number). Add to results vector the real numbers input with position (1 or 2) given from vector of pair created before. Count distinct value of 2 heap.
 *      Print the number of all combination (heap1.size * heap2.size) and the position heap of results.
 Time complexity consists of 2 loop and one sort vector --> O(2N) + O(NlogN)
 Space complexity --> O(2N)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    size_t n;
    cin >> n;
    n = 2*n;

    vector<pair<int,size_t>> inputs(n);
    vector<int> heaps(n);
    int distinctSize[3];
    distinctSize[1] = 0; distinctSize[2] = 0;

    for(int i = 0; i < n; i++) {
        cin >> inputs[i].first;
        inputs[i].second = i;
    }

    sort(inputs.begin(), inputs.end());

    bool first_occurence = true;

    for(int i = 1; i < n; ++i) {
        if(inputs[i].first == inputs[i-1].first) {
            if(first_occurence) {
                heaps[inputs[i-1].second] = 1;
                heaps[inputs[i].second] = 2;
                distinctSize[1]++; distinctSize[2]++;
                first_occurence = false;
            }
            continue;
        }
        if(first_occurence) {
            heaps[inputs[i-1].second] = (distinctSize[1] > distinctSize[2])+1;
            distinctSize[heaps[inputs[i-1].second]]++;
        }
        first_occurence = true;
    }

    if(first_occurence && inputs[n-1] != inputs[n-2]) {
        heaps[inputs[n-1].second] = (distinctSize[1] > distinctSize[2])+1;
        distinctSize[heaps[inputs[n-1].second]]++;
    }

    cout << distinctSize[1] * distinctSize[2] << endl;

    for(auto x: heaps) {
        if(x == 0) {
            x = (distinctSize[1] > distinctSize[2])+1;
            distinctSize[x]++;
        }
        cout << x << " ";
    }

    return 0;
}

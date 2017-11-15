/*
 *  LittleGirl.cpp
 *
 *  Created on: 15 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/status
 *      Description Solution:
 *      The idea is save frequencies, adding 1 to counts vector in position 'l' and removing '1' to counts vector in position 'r'. Calculate prefix sum of count vector up to element is equal to frequency of element. Then sort elements e counts vectors. The result is the sum of elements moltiplicate own frequency.
 Time complexity consits of calculate frequency of elements in based of num of queries--> O(n+q)
 Space complexity (space of elements and counts frequency vector) --> O(q+n)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, q;
    int64_t result = 0;
    cin >> n >> q;
    vector<int32_t> elements(n);
    vector<int32_t> qCounts(n+1);

    for (size_t i = 0; i < n; i++) {
        int64_t elem;
        cin >> elem;
        elements[i] = elem;
    }

    int l, r;
    for (size_t i = 0; i < q; i++) {
        cin >> l >> r;
        qCounts[l-1] += 1;
        qCounts[r] -= 1;
    }

    for(size_t i = 1; i < n; i++){
        qCounts[i] += qCounts[i-1];
    }

    sort(elements.begin(), elements.end());
    sort(qCounts.begin(), qCounts.end()-1);

    for (size_t i = 0; i < n; i++) {
        result += static_cast<int64_t>(elements[i])*static_cast<int64_t>(qCounts[i]);// static_cast is inspired by Rossano's solution
    }

    cout << result;
    return 0;
}

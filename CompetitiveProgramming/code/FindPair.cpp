/*
 *  FindPair.cpp
 *
 *  Created on: 07 oct 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/160/C?locale=en
 *      Description Solution:
 *      Sort input elements. Then, find the k-th pair. First element of pair is the position in array elements (sorted) of number given by division of k/n (rounding for excess) less one (because array starts from 0 position).
 *      Second element of pair is the position in array elements ((k-1)-minVal*n)/cnt, where minVal is the smaller value than first element, and cnt is the count of first element of array.
 Time complexity consists of one loop and sort array --> O(N) + O(NlogN)
 Space complexity --> O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    uint64_t n, k, minVal;
    std::cin >> n;
    std::cin >> k;

    std::vector<int> elements(n);
    for(int i = 0; i < n; i++){
        std::cin >> elements[i];
    }
    std::sort(elements.begin(), elements.end());

    int x = elements[(k-1)/n];

    for(minVal = 0; minVal < n; minVal++){
        if(elements[minVal] == x) break;
    }

    uint64_t cnt = count(elements.begin(), elements.end(), x);
    int y = elements[((k-1)-minVal*n)/cnt];

    std::cout << x << " " << y;
}

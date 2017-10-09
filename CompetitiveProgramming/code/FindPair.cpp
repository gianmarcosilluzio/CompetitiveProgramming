/*
 *  FindPair.cpp
 *
 *  Created on: 07 oct 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/160/C?locale=en
 *      Description Solution:
 *      The idea is: sort input elements. Then, find the k-th pair. First element of pair is the position in array elements (sorted) of number given by division of k/n (rounding for excess) less one (because array starts from 0 position). Second element of pair is the position in array elements of number given by subtraction of n (number of elements) moltiplicated the position of first element of pair (calculate before) less 1 from k.
 Time complexity consists of sort array --> O(NlogN)
 Space complexity --> O(N)
 */

#include <iostream>
#include <vector>
#include <math.h>

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    std::vector<int> elements(n);
    for(int i = 0; i < n; i++){
        cin >> elements[i];
    }
    std::sort(elements.begin(), elements.end());
    int x = ceil(k/(double)n);
    int y = elements[k-(n*(x-1))-1];
    std::cout << elements[x-1] << " " << y;
}

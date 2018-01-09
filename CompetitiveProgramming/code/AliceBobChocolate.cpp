/*
 *  AliceBobChocolate.cpp
 *
 *  	Created on: 14 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/6/C?locale=en
 *      Description Solution:
 *      The idea is save the total sum of all element in input, and store each element in a vector. Then through vector, saving sum of element analyzed, and remove value of element analyzed from total sum. If sum of element analyzed is minor than totalSum, then break the through of vector and check the element in common (if sum is minor than sum of element analyzed less element provious than element in common, I decrease one element for the left index).
 Time complexity consits of calculate total sum--> Wrost case: O(N)[calculate of total sum] + O(N)[analysis of all elements], Better case: O(n)[calculate of total sum] + O(1)[analysis just one element]
 Space complexity (space of vector) --> O(N)
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int totSum, prefixSum = 0;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        vec[i] = elem;
    }

    totSum = accumulate(vec.begin(), vec.end(), 0);//this function is inspired by Rossano's Solution

    int i = 0;
    while(i < n and prefixSum < totSum){
        prefixSum += vec[i];
        totSum -= vec[i];
        i++;
    }

    if(i != 0 and totSum < prefixSum - vec[i-1]){
        i--;
    }

    cout << i << " " << n-i;

    return 0;
}

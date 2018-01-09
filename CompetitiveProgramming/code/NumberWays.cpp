/*
 *  NumberWays.cpp
 *
 *  	Created on: 15 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/466/C?locale=en
 *      Description Solution:
 *      The idea return 0 if the sum of element of array is not divisible for 3. Else, we store in array, in each pos the sum of suffix of element of sequence (element of array) that are equal to total sum/3. Then calculate the sum of the prefixes of element of array, and add the prefix to result when prefix is equal tototal sum/3.
 The idea is inspired by Rossano's solution https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/code/NumberWays.cpp
 Time complexity --> Wrost case: O(4N), Best case: O(1) when vector is not divisible for 3.
 Space complexity (vector of element and vector of prefixes) --> O(2N)
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){

    int n;
    int64_t result = 0;
    cin >> n;

    vector<int64_t> vec(n);

    for (size_t i = 0; i < n; i++) {
        int64_t elem;
        cin >> elem;
        vec[i] = elem;
    }

    int64_t totSum = 0;
    for(auto elem : vec){
        totSum += elem;
    }

    if(totSum%3 != 0){
        result = 0;
    }else{
        totSum /= 3;
        int64_t L = 0;
        vector<int64_t> c(n, 0);
        for(int i = n-1; i >= 0; i--) {
            L += vec[i];
            if(L == totSum){
                c[i] = 1;
            }
        }

        for(int i = n-2; i >= 0; i--){
            c[i] += c[i+1];
        }

        L = 0;
        for(int i = 0; i < n-2; i++) {
            L += vec[i];
            if(L == totSum){
                result += c[i+2];
            }
        }
    }

    cout << result;

    return 0;
}

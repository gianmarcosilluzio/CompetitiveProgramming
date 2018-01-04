/*
 * Towers.cpp
 *
 *      Created on: 26 set 2017
 *      Updated on: 03 jan 2018
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/37/A?locale=en
 *      Description Solution:
 *      The idea is sort the array elements, keep track maximum value level, and increment towers counter when current element is different from the next item.
 *      Time complexity  --> O(nlog(N)) of sort and O(n) of loop
 *      Space complexity --> O(n) for loop and O(n) auxiliary space for sort.
 *
 */

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> getTowers(int n, vector<int> vec){

    int tot = 0, currentLength = 0, currentHeight = 0, max = 1;
    for(int i = 0; i < n; i++) {
        if(vec[i] == currentLength) {
            currentHeight += 1;
            if(currentHeight > max){
                max = currentHeight;
            }
        } else {
            currentLength = vec[i];
            currentHeight = 1;
            tot++;
        }
    }
    return {max, tot};
}

int main(){
    int n = 0;
    cin >> n;
    vector<int> inputs;
    inputs.reserve(n);
    for(int i = 0; i < n; i++){
        int elem = 0;
        cin >> elem;
        inputs.push_back(elem);
    }
    sort(inputs.begin(), inputs.end());
    vector<int> results = getTowers(n, inputs);
    cout << results[0] << " " << results[1];
    return 0;
}

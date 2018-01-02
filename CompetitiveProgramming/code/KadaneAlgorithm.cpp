/*
 * KadaneAlgorithm.cpp
 *
 *  	Created on: 26 set 2017
 *  	Updated on: 02 jan 2018
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
 *      Description Solution: Analyze all positive contiguous segments, store the maximum sum contiguous segment, and find the maximum among all elements of segment. 'max' variable must be initialized with the min value of INT (because the negative value of int elements of array can be at most -2147483648, or with first array element).
 *      	The value 'max' is updated only if the 'sum' (sum of each element) is greater than 'max' value. If all numbers of array are negative the solution is the negative number greater.
 *		Time complexity --> O(n) because there is only one loop (inside core algorithm)
 *		Space complexity --> O(n)
 */

#include<iostream>
#include<vector>

using namespace std;

int getMaxSubArrayGeneric(int N, vector<int> const& inputs){

    int max = inputs.front();
    int sum = 0;

    for (int i = 0; i < N; i++){
    	sum = sum + inputs[i];
        if (sum > max){
        	max = sum;
        }
        if (sum < 0){
        	sum = 0;
        }
    }
    return max;
}

int main(){
    int num_tests = 0;
    cin >> num_tests;
    vector<int> inputs;

    for(int i = 0; i < num_tests; i++){
    	int n = 0;
    	cin >> n;
    	inputs.reserve(n);
    	for(int j = 0; j < n; j++){
    		int elem = 0;
    		cin >> elem;
    		inputs.push_back(elem);
    	}
    	int max = getMaxSubArrayGeneric(n, inputs);
    	inputs.clear();
    	cout << max << endl;
    }

    return 0;
}


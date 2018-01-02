/*
 * SlidingWindowMaxima.cpp
 *      Updated on: 26 set 2017
 *      Updated on: 02 jan 2018
 *      Author: Gianmarco Silluzio
 *		Problem: http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
 *		Description Problem: My solution is inspired by https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/notes/lecture2.pdf
 *		Time complexity: O(n)
 *		Space complexity: O(n)
*/

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

void getNextLargestNumbers(vector<int> const& array, int k){
    vector<int> results;
    deque<int> Q;
    int N = array.size();
    results.reserve(N - k + 1);
    for(int i = 0; i < N; i++){
        while(!Q.empty() && Q.front() <= i-k){
            Q.pop_front();
        }
        while(!Q.empty() && array[i] > array[Q.back()]){
            Q.pop_back();
        }

        Q.push_back(i);

        if(i >= k-1){
            results.push_back(array[Q.front()]);
        }

    }

    for(auto el = results.begin(); el != results.end(); el++){
    	cout << *el << " ";
    }

    cout << endl;
}

int main() {
	int num_tests = 0;
	cin >> num_tests;
	vector<int> inputs;

	for(int i = 0; i < num_tests; i++){
	  	int n = 0;
	  	int k = 0;
	   	cin >> n >> k;
	   	inputs.reserve(n);
	   	for(int j = 0; j < n; j++){
	   		int elem = 0;
	   		cin >> elem;
	   		inputs.push_back(elem);
	   	}
	   	getNextLargestNumbers(inputs, k);
	   	inputs.clear();
	}

	return 0;
}





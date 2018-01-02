/*
 * MissingNumberInArray.cpp
 *
 *  	Created on: 26 set 2017
 *  	Updated on: 02 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/missing-number-in-array/0
 *      Description Solution: The idea is get the sum of numbers inside array. Then subtract from the total each number. Then the total will be number missing
 *		Time complexity --> O(N)
 *		Space complexity --> O(N)
 */

#include<iostream>

using namespace std;

int main(){
	int num_tests = 0;
	cin >> num_tests;

	for(int i = 0; i < num_tests; i++){
		int n = 0;
		cin >> n;
		int sum = 0;
		int total  = n*(n+1)/2;
		for(int j = 0; j < n-1; j++){
			int elem = 0;
			cin >> elem;
			total -= elem;
		}
		cout << total << endl;
	}
    return 0;
}



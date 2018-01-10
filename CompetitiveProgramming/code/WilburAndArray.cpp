/*
 *  WilburArray.cpp
 *
 *  	Created on: 13 dic 2017
 *      Updated on: 10 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/596/B?locale=en
 *      Description Solution:
 *      The idea is get each input digit and increment result with the absolute value of input less b. b is the previous value of input digit
 Time complexity --> Wrost case: O(N) - get input char
 Space complexity --> O(1)
*/

#include<iostream>

using namespace std;

int main(){
    long long result, a, b;
    int n = 0;
    cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a;
		result = result + abs(a-b);
		b = a;
	}
	cout << result;
}

/*
 *  Woodcutters.cpp
 *
 *  	Created on: 15 dic 2017
 *      Updated on: 11 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/contest/545/problem/C?locale=en
 *      Description Solution:
 *      The idea is store x(coordinate of tree) and h(heigth of tree) in 2 distinct array. Analyzing each tree we increment result if the diffrence of coordinate of element anlyzed and coordinate of previous element is greater than heigth of element analyzed, or if the difference of coordinate of next element and coordinate element analyzed is greater than heigth of element analyzed (in this case to the coordinate of element analyzed is added the corrispondent heigth)
 Time complexity --> Wrost case: O(N)
 Space complexity --> O(n)
*/

#include<iostream>

using namespace std;

#define MAX 100001

int main(){
    int x[MAX], h[MAX];
    int n = 0, result = 2;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> x[i] >> h[i];
	}

	for(int i = 1; i < n-1; i++){
		if(x[i] - x[i-1] > h[i]){
		    result++;
		}
		else if(x[i+1] - x[i] > h[i]){
		    result++;
		    x[i] += h[i];
		}
	}
	cout << (n == 1 ? 1 : result);
}

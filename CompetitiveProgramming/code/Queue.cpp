/*
 *  Queue.cpp
 *
 *  	Created on: 15 dic 2017
 *      Updated on: 11 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/141/C?locale=en
 *      Description Solution:
 *      The idea is sort person by h (number of person more higher in front of person) in order ascendent. If the difference of index and h is minor than 0, the answer is -1 because there isn't acceptable order of the people in the queue. for each h of element analyzed we compare with other h of element in front of it, and if. If there is element more higher in front of it we increment result of element.

 Time complexity --> Wrost case: O(NlogN)
 Space complexity --> O(n)
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n = 0;
	cin >> n;

	pair<int, string> persons[n];
	int results[n];

	for (int i = 0; i < n; i++){
		cin >> persons[i].second >> persons[i].first;
	}

	sort(persons, persons + n);

	for (int i = 0; i < n; i++){
		int l = i - persons[i].first;
		if (l < 0) {
		    cout << -1; return 0;
		}
		results[i] = l;
		for (int j = 0; j < i; j++){
		    if (results[j] >= results[i]){
		        results[j]++;
		    }
		}
	}
	for (int i = 0; i < n; i++){
		cout << persons[i].second << " " << 1+results[i] << endl;
	}

}

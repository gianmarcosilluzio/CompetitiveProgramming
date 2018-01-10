/*
 *  NMeetingRoom.cpp
 *
 *  	Created on: 13 dic 2017
 *      Updated on: 10 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
 *      Description Solution:
 *      The result is all meetings which start before and have length (finish - start) minor possible. The meeting overlap in vertically are not solution. The idea save input in array of node struct. Sort array in order ascendent by finish time. Save the first node of array in array result. Go through odered array and compare each element with last elemnte saved in array result. If start of element analyzed is greater than finish of last element saved in array result, the element is added in array result.
 Time complexity consits of sort array and one loop to save result--> Wrost case: O(N log N)
 Space complexity (space of vector) --> O(N)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int first, last, index;
};

bool compare(struct node a, struct node b){
    return a.last < b.last;
}

int main() {
	int test_cases = 0;
	cin >> test_cases;
	for(int t = 0; t < test_cases; t++){

	    vector<int> results;


	    int n = 0;
	    cin >> n;
	    struct node A[n];

	    for(int i = 0; i < n; i++){
	        cin >> A[i].first;
	    }
	    for(int i = 0; i < n; i++){
	        cin >> A[i].last;
	        A[i].index = i+1;
	    }

	    sort(A, A+n, compare);

	    int i = 0;
	    results.push_back(A[0].index);
	    for(int j = 1; j < n; j++){
	        if(A[j].first >= A[i].last){
	            results.push_back(A[j].index);
	            i = j;
	        }
	    }

	    for(int i = 0; i < results.size(); i++){
	        cout << results[i] << " ";
	    }

	    cout<<endl;
	}
	return 0;
}

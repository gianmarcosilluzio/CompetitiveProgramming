/*
 * LeadersInAnArray.cpp
 *
 *      Created on: 26 set 2017
 *      Updated on: 02 jan 2018
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
 *      Description Solution: The idea behind the algorithm is scan array from the rigth. Save the highest number scanned and compare each number of array with the highest scanned.
 *			The highest is updated only when the number scanned is greater than last highest, and in this case the number scanned will be printed.
 *		Time complexity --> O(n) because there is only one loop
 *		Space complexity --> O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

void getAllLeadersFromRight(int n, vector<int> const& inputs){
    vector<int> results;
    results.reserve(n);
    int highest = inputs.back();
    results.push_back(highest);

    for(auto el = inputs.rbegin() + 1; el != inputs.rend(); el++){
        if(*el > highest){
            highest = *el;
            results.push_back(highest);
        }
    }

    for(auto el = results.rbegin(); el != results.rend(); el++){
        cout << *el << " ";
    }

    cout << endl;

}

int main() {
	int num_tests = 0;
	vector<int> inputs;
	cin >> num_tests;

	for(int i = 0; i < num_tests; i++){

	    int n = 0;
	    cin >> n;
	    inputs.reserve(n);

	    for(int j = 0; j < n; j++){
	        int elem = 0;
	        cin >> elem;
	        inputs.push_back(elem);
	    }

	    getAllLeadersFromRight(n, inputs);
        inputs.clear();
	}

    return 0;
}

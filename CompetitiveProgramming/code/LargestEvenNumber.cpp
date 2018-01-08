/*
 *  LargestEvenNumber.cpp
 *
 *      Created on: 09 nov 2017
 *      Updated on: 08 jan 2018
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/largest-even-number/0
 *      Description Solution:
 *      The idea is convert input in digit array of number. Order array with counting sort. If the first element of array is even, return result converting array in string (through array in decreasing order). Else, find minimum even value of array, delete it from array and concat to the result (result is obtained converting array in string through array in decreasing order)
 Time complexity consists of sort array, so the time complexity of counting sort + converting array to string result --> O(n+k) + O(n) where n is the number of elements in input array and k is the range of input.
Wrost case --> O(n+k) + O(2n);
 Space complexity --> O(2N)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> countSort(vector<int> arr);
vector<int> stringToArray(string str);
string maxEven(vector<int> arr);

int main(){

    int numTest = 0;
    cin >> numTest;

    string str;
    for (int i = 0; i < numTest; ++i) {
        cin >> str;
        str = maxEven(stringToArray(str));
        cout << str << endl;
        str.clear();
    }

    return 0;
}

vector<int> countSort(vector<int> arr){

    vector<int> count(10, 0);
    vector<int> results(arr.size(), 0);

    for (auto i : arr) {
        count[i]++;
    }

    for (int i = 0; i < count.size(); i++) {
        count[i] += count[i-1];
    }

    for (int i = 0; i < arr.size(); i++) {
        results[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    return results;
}

vector<int> stringToArray(string str){
    vector<int> arr(str.length());

    for(int i=0;i<str.length();i++){
        arr[i] = str[i] - '0';
    }

    return arr;
}

string maxEven(vector<int> arr){
    arr = countSort(arr);
    string result;
    pair<int, int> minEven = make_pair(-1, -1);

    if(arr[0]%2 != 0){
        for (int i = arr.size()-1; i >= 0; i--) {
            if(arr[i]%2 == 0){
                minEven.first = arr[i];
                minEven.second = i;
            }
        }
    }

    if(minEven.first != -1){
        arr[minEven.second] = -1;
    }
    for (int i = arr.size()-1; i >= 0; i--) {
        if(arr[i] != -1){
            result += to_string(arr[i]);
        }
    }
    if(minEven.first != -1){
        result += to_string(minEven.first);
    }

    return result;
}

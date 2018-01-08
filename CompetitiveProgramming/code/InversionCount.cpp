/*
 *  InversionCount.cpp
 *      First release was named CountInversion.cpp
 *      Created on: 07 nov 2017
 *      Updated on: 08 jan 2018
 *      Author: Gianmarco Silluzio
 *      Problem: http://www.spoj.com/problems/INVCNT/
 *      Description Solution:
 *      The idea is count all inversions of number during merge step of mergeSort algorithm. The final result is given by the sum of left and rigth count of inversion. The count of inversions is in merge step, in particular when the number of left side is greater than rigth side (the inversions are the middle - position of left number because left and right sides are sorted).
 Time complexity consists of sort array, so the time complexity of merge sort --> O(NlogN)
 Space complexity --> O(N)
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i)
        cin >> sequence[i];
    return sequence;
}

uint64_t merge(vector<uint64_t>& arr, int l, int m, int r){
    int i = l, j = m+1, k = 0;
    uint64_t inv = 0;

    vector<uint64_t> arr2((r-l)+1);//inspired by Rossano's solution, in my solution I created 2 arrays R and L for copy the content of arr

    while (i <= m && j <= r){
        if (arr[i] < arr[j]){
            arr2[k] = arr[i++];
        }
        else{
            arr2[k] = arr[j++];
            inv += m-i+1;
        }
        k++;
    }


    while (i <= m){
        arr2[k++] = arr[i++];
    }

    while (j <= r){
        arr2[k++] = arr[j++];
    }

    copy(arr2.begin(), arr2.end(), arr.begin()+l);//inspired by Rossano's solution

    return inv;
}

uint64_t mergeSort(vector<uint64_t>& arr, int l, int r){
    if (l >= r){
        return 0;
    }

    int m = (l+r)/2;
    uint64_t invL = mergeSort(arr, l, m);
    uint64_t invR = mergeSort(arr, m+1, r);
    return invL + invR + merge(arr, l, m, r);
}


int main(){
    string blank;//"get input" inspired by Rossano's solution
    int tests_case;
    cin >> tests_case;
    getline(cin, blank);

    for(int i = 0; i < tests_case; ++i) {
        int n;
        cin >> n;
        auto A = get_input_sequence<uint64_t>(n);
        getline(cin, blank);
        uint64_t inv = mergeSort(A, 0, n-1);

        cout << inv << endl;
    }

    return 0;
}

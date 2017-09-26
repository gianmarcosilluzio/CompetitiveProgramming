/*
 * SlidingWindowMaxima.cpp
 *
 *  Updated on: 26 set 2017
 *      Author: Gianmarco Silluzio
		Problem: http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
		Description Problem: I find the max number in first subarray, and put value in variable max and add it in results array. Then I compare the max value of first array with each next array elements. If array element analyzed is greater than max value, I update max value. For each element I add max to array result.
		Time complexity: O(n)
		Auxiliary Space: O(k)
*/

#include <iostream>
#include <array>

using namespace std;

std::vector<int> getNextLargestNumbers(std::vector<int> array, int k);
void printArrayElements(std::vector<int> array);

int main() {
    int k = 5;
    std::vector<int> array = {3, 7, 4, 5, 8, 12, 7, 6, 17};
    std::vector<int> results = getNextLargestNumbers(array, k);
    printArrayElements(results);
}

std::vector<int> getNextLargestNumbers(std::vector<int> array, int k){
    std::vector<int> results;
    int N = array.size();
    results.reserve(N - k + 1);
    int max = array[0];
    for(int i = 0; i < k; i++){
        if(array[i] > max){
            max = array [i];
        }
    }
    results.push_back(max);
    for(int i = k; i < N; i++){
        if(array[i] > max){
            max = array [i];
        }
        results.push_back(max);
    }
    return results;
}

void printArrayElements(std::vector<int> array){
    for(int i = 0; i < array.size(); i++){
        printf("%d ", array[i]);
    }
}

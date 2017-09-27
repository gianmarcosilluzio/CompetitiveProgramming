/*
 * SlidingWindowMaxima.cpp
 *
 *  Updated on: 26 set 2017
 *      Author: Gianmarco Silluzio
		Problem: http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
		Description Problem: My solution is inspired by https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/notes/lecture2.pdf
		Time complexity: O(n)
		Auxiliary Space: O(k)
*/

#include <iostream>
#include <array>
#include <deque>

using namespace std;

std::vector<int> getNextLargestNumbers(std::vector<int> array, int k);
void printArrayElements(std::vector<int> array);

int main() {
    int k = 2;
    std::vector<int> array = {5, 3, 2, 4, 6 };
    std::vector<int> results = getNextLargestNumbers(array, k);
    printArrayElements(results);
}

std::vector<int> getNextLargestNumbers(std::vector<int> array, int k){
    std::vector<int> results;
    std::deque<int> Q;
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

    return results;
}

void printArrayElements(std::vector<int> array){
    for(int i = 0; i < array.size(); i++){
        printf("%d ", array[i]);
    }
}

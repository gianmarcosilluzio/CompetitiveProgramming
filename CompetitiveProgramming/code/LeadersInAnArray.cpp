/*
 * LeadersInAnArray.cpp
 *
 *  Created on: 26 set 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
 *      Description Solution:
Solution has Time complexity O(n) because there is only one loop.
The idea behind the algorithm is scan array from the rigth. Save the highest number scanned and compare each number of array with the highest scanned.
The highest is updated only when the number scanned is greater than last highest, and in this case the number scanned will be printed.

 */

#include <iostream>
#include <array>


std::vector<int> getAllLeadersFromRight(int N, int array[]){
    std:vector<int> results;
    int highest = array[N-1];

    for(int i = N-2; i > -1; i--){
        if(array[i] > highest){
            highest = array[i];
            results.push_back(highest);
        }
    }
    return results;
}

void printArrayElements(std::vector<int> array){
    for(int i = 0; i < array.size(); i++){
        printf("%d ", array[i]);
    }
}

int main() {
    int array[] = {53, 4, 6, 7, 2, 0, -40};
    int N = sizeof(array)/sizeof(array[0]);
    std:vector<int> results = getAllLeadersFromRight(N, array);
    printArrayElements(results);
    return 0;
}

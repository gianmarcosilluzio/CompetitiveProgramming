/*
 * KadaneAlgorithm.cpp
 *
 *  Updated on: 26 set 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
 *      Description Solution:
 *      Analyze all positive contiguous segments, store the maximum sum contiguous segment, and find the maximum among all. 'max' variable must be initialized with the min value of INT (because the negative value of int elements of array can be at most -2147483648, or with first array element).
 *      The value 'max' is updated only if the 'sum' (sum of each element) is greater than 'max' value. If all numbers of array are negative the solution is the negative number greater.
 *
 */

#include<iostream>

using namespace std;

int getMaxSubArrayGeneric(int N, int array[]){
    int max = array[0];
    int sum = 0;

    for (int i = 0; i < N; i++){
    	sum = sum + array[i];
        if (sum > max){
        	max = sum;
        }
        if (sum < 0){
        	sum = 0;
        }
    }
    return max;
}

int main(){
    int array[] = {-6, -2, -5, -2, -6, -9};
    int N = sizeof(array)/sizeof(array[0]);
    int max = getMaxSubArrayGeneric(N, array);
    printf("%d", max);
    return 0;
}


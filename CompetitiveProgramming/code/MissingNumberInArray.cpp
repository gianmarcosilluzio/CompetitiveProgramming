/*
 * MissingNumberInArray.cpp
 *
 *  Created on: 26 set 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/missing-number-in-array/0
 *      Description Solution:
 *      The idea is get the sum of numbers inside array. Then subtract from the total each number.
 *      Then the total will be number missing
 */

#include<iostream>

using namespace std;

int getMissingNumber (int N, int array[]){
    int i, total;
    total  = N*(N+1)/2;
    for ( i = 0; i< N; i++)
       total -= array[i];
    return total;
}

int main(){
    int array[] = {1,2,4,5,6};
    int N = sizeof(array)/sizeof(array[0]);
    int missingNumber = getMissingNumber(N, array);
    printf("%d", missingNumber);
    return 1;
}



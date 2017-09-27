/*
 * Towers.cpp
 *
 *  Created on: 26 set 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/37/A?locale=en
 *      Description Solution:
 *      The idea is sort the array elements, keep track maximum value level, and increment towers counter when current element is different from the next item.
 *      Time complexity is given from O(nlog(N)) of sort and O(n) of loop. Space complexity is O(n) for loop and O(n) auxiliary space for sort.
 *
 */

#include<iostream>
#include <algorithm>

using namespace std;

std::vector<int> getTowers(int N, int array[]){
    int max = 1;
    int tot = 0;
    int count = 1;

    for (int i = 0; i < N; i++){
        if (array[i] != array[i+1]){
        	tot++;
        	if(max < count){
        		max = count;
        		count = 1;
        	}
        }
        else{
        	count++;
        }
    }
    return {max, tot};
}

int main(){
    int array[] = {6, 5, 6, 7, 6, 7, 7, 7, 3, 5, 1, 2};
    int N = sizeof(array)/sizeof(array[0]);
    sort(array, array + N);
    std::vector<int> results = getTowers(N, array);
    printf("Level max: %d - Tot levels: %d", results[0], results[1]);
    return 0;
}


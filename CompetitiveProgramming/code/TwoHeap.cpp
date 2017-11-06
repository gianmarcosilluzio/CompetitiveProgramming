/*
 *  TwoHeap.cpp
 *
 *  Created on: 06 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/353/B
 *      Description Solution:
 *      Create structure vector of pair where are contained all input numbers (reversed if the second digit is smaller than first; e.g. 53 will become 35) with own position.
 *      Sort the vector of pair by first value (number). Add to results vector the real numbers input with position (1 or 2) given from vector of pair created before. Count distinct value of 2 heap.
 *      Print the number of all combination (heap1.size * heap2.size) and the position heap of results.
 Time complexity consists of 2 loop and one sort vector --> O(2N) + O(NlogN)
 Space complexity --> O(2N)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int invertNumber(int number);

bool compare (std::pair<int, int> i,std::pair<int, int> j) {
    return (i.first<j.first);
}

int main(){
    
    size_t n;
    cin >> n;
    n = 2*n;
    
    std::vector<int> input(n);
    for(size_t i = 0; i < n; ++i){
        cin >> input[i];
    }
    
    std::vector<std::pair<int, int>> results(n);
    std::vector<std::pair<int, int>> pairs;
    int distinctSize1 = 1;
    int distinctSize2 = 1;
    
    for (int i = 0; i < input.size(); i++) {
        std::pair<int, int> pair; 
        int number = input[i];
        int invertedNumber = invertNumber(number);
        if(invertedNumber<number){
            pair.first = invertedNumber;
        }else{
            pair.first = number;
        }
        pair.second = i;
        pairs.push_back(pair);
    }
    
    std::sort (pairs.begin(), pairs.end(), compare);
    
    int k = 1;
    for (int i = 0; i < pairs.size(); i++) {
        results[pairs[i].second].first = input[pairs[i].second];
        results[pairs[i].second].second = k;
        if(k==2){
            k--;
            if(i > 1 && results[pairs[i].second].first != results[pairs[i-2].second].first){
                distinctSize1++;
            }
        }else{
            k++;
            if(i > 1 && results[pairs[i].second].first != results[pairs[i-2].second].first){
                
                distinctSize2++;
            }
        }
    }
    
    //print outcome
    std::cout << distinctSize1*distinctSize2 << "\n";
    for (auto i : results) {
        std::cout << i.second << " ";
    }
    
    return 0;
}

int invertNumber(int number){
    int inverted = 0;
    int remainder;

    while(number != 0)    {
        remainder = number%10;
        inverted = inverted*10 + remainder;
        number /= 10;
    }
    
    return inverted;
}

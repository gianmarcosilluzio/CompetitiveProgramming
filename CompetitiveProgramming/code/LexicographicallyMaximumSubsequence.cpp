/*
 *  LexicographicallyMaximumSubsequence.cpp
 *
 *  	Created on: 14 dic 2017
 *      Updated on: 11 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/603/A?locale=en
 *      Description Solution:
 *      The idea is start from the end of string s to beginning of s (anlyzing each character), save char analyzed result if ascii code of character is greater than max character (first time 0), and update max character with element analyzed.
 Time complexity --> Wrost case: O(N)
 Space complexity --> O(1)
*/

#include<iostream>
#include<string.h>

using namespace std;

int main(){
    char max;
    string s, result;
    cin >> s;

    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] >= max){
            max = s[i];
            result = s[i] + result;
        }
    }
    cout << result;
}

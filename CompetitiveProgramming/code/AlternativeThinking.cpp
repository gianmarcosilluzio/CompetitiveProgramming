/*
 *  AlterativeThinking.cpp
 *
 *  	Created on: 14 dic 2017
 *      Updated on: 11 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/603/A?locale=en
 *      Description Solution:
 *      The idea is start from the beginning of string s to length of s, incrementing result if there is alternate digit (of character analyzed and previous character). The solution is the min value between result (longest alternative path) + 2 (flip operation) and n (string length).
 Time complexity --> Wrost case: O(N)
 Space complexity --> O(1)
*/

#include<iostream>

using namespace std;

int main(){
    int n, tot = 1;
    string s;
    cin >> n >> s;

    for(int i = 1; i < n; i++){
        if(s[i-1] != s[i]){
            tot ++;
        }
    }

    cout << min(tot+2, n);
}

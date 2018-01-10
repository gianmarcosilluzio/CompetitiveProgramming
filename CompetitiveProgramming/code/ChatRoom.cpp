/*
 *  ChatRoom.cpp
 *
 *  	Created on: 13 dic 2017
 *      Updated on: 10 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/58/A?locale=en
 *      Description Solution:
 *      The idea is get each input char and compare with hello[i]. i is incremented if there is a match. Then check if i = 5 and print YES, else NO.
 Time complexity --> Wrost case: O(N) - get input char
 Space complexity --> O(1)
*/

#include<iostream>

using namespace std;

int main(){
    char c;
    int i = 0;

	while(cin >> c && i!=5){
		if(c == "hello"[i]){
		    i++;
		}
	}

    cout << ((i==5) ? "YES" : "NO");
}

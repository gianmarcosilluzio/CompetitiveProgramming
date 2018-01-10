/*
 *  MagicNumbers.cpp
 *
 *  	Created on: 13 dic 2017
 *      Updated on: 10 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/320/A?locale=en
 *      Description Solution:
 *      The idea is compare the modulo of input number of 1, 2, 3 digits with respective 1, 14 and 144. Loop start analyzing end of number, and continuing analyzing number/10 (removing one digit from number).
 Time complexity --> Wrost case: O(N)
 Space complexity --> O(1)
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = n; i > 0; i = i/10){
        if(!(i%10 == 1 || i%100 == 14 || i%1000 == 144)){
            cout<<"NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

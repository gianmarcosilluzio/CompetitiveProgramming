/*
 *  UpdateArray.cpp
 *
 *  	Created on: 16 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://www.spoj.com/submit/UPDATEIT/
 *      Description Solution:
 *      The idea is use the fenwick tree for update the elemnts, adding value to elements left (of query) postion on tree and subtracting the value to elements rigth (of query) postion +1. The value of element is the sum from 0 element position of tree to the position of element.
 Time complexity --> O(logN)
 Space complexity --> O(N)
*/
#include <iostream>
#include "fenwick_tree.hpp"

using namespace std;

int main(){
    size_t n_tests;
    cin >> n_tests;

    for(size_t i = 0; i < n_tests; i++) {
        size_t n, u, q;
        cin >> n;
        cin >> u;
        fenwick_tree<int> f_tree(n+1);
        vector<int> F(n+1);

        int l, r, val;
        for(size_t j = 0; j < u; j++) {
            cin >> l >> r >> val;
            f_tree.add(l, val);
            f_tree.add(r+1, val*-1);
        }

        cin >> q;

        for(size_t j = 0; j < q; j++) {
            cin >> l;
            cout << f_tree.sum(l) << endl;
        }
    }

    return 0;
}


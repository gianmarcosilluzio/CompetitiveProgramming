/*
 *  PreorderTraversal.cpp
 *
 *  Created on: 13 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0
 *      Description Solution:
 *      The idea is find next greater element and after finding next greater (using a stack), if we find a smaller element, then return false.
 Time complexity consists of looks each array element --> O(N)
 Space complexity (space of array) + space of stack --> O(N)
 */

#include<iostream>
#include<climits>
#include<stack>
#include<vector>

using namespace std;

bool isBSTPreorder(vector<int> vec){
    stack<int> s;
    int root = INT_MIN;

    for (int i = 0; i < vec.size(); i++){

        if (vec[i] < root){
            return false;
        }

        while (!s.empty() && vec[i] > s.top()){
            root = s.top();
            s.pop();
        }

        s.push(vec[i]);
    }
    return true;
}

int main() {
    std::vector<int> vec;
    int test = 0;
    cin >> test;

    for (int i = 0; i < test; ++i) {
        int n = 0;
        cin >> n;

        vec.reserve(n);

        for (int j = 0; j < n; j++) {
            int elem = 0;
            std::cin >> elem;
            vec.push_back(elem);
        }

        cout << isBSTPreorder(vec) << endl;

        vec.clear();
    }

    return 0;
}

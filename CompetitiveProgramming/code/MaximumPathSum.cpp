/*
 *  MaximumPathSum.cpp
 *
 *      Created on: 13 nov 2017
 *      Updated on: 09 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/maximum-path-sum/1
 *      Description Solution:
 *      The idea is to keep trace of four paths (Node only, Max path through Left Child + Node, Max path through Right Child + Node, Max path through Left Child + Node + Max path through Right Child) and pick up the max one in the end.
 This Solution is inspired by http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
 Time complexity consists of looks each node of BST --> O(N)
 Space complexity (space of BST) --> O(N)
 */
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
#include<bits/stdc++.h>
using namespace std;
*/

int findMax(Node* root, int &maxVal){

    if (root == NULL){
        return 0;
    }

    int l = findMax(root->left,maxVal);
    int r = findMax(root->right,maxVal);
    int maxSingle = max(max(l, r) + root->data, root->data);
    int maxTop = max(maxSingle, l + r + root->data);
    maxVal = max(maxVal, maxTop);

    return maxSingle;
}

int maxPathSum(Node *root){
    int max = INT_MIN;
    findMax(root, max);
    return max;
}

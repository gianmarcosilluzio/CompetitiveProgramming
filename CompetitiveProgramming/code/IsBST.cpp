/*
 *  IsBST.cpp
 *
 *  Created on: 12 nov 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/check-for-bst/1
 *      Description Solution:
 *      The idea is return false if data of node left and right of each node is greater and less than of own root node.
        The idea is inspired from: http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
 Time complexity consists of looks each node only once --> O(N)
 Space complexity --> O(1)
 */

/*#include <cstdlib>
#include <iostream>
using namespace std;

//struct of node
struct Node{
    struct Node* left, *right;
    int data;
};
*/

bool isBST(Node* root, Node* l, Node* r){

    if (root == NULL){
        return true;
    }

    if (l != NULL and l->data > root->data){
        return false;
    }

    if (r != NULL and r->data < root->data){
        return false;
    }

    return isBST(root->left, l, root) and isBST(root->right, root, r);
}




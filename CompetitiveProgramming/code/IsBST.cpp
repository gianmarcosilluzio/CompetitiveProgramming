/*
 *  IsBST.cpp
 *
 *      Created on: 12 nov 2017
 *      Updated on: 09 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/check-for-bst/1
 *      Description Solution:
 *      The idea is return false if data of node left and right of each node is greater and less than of own root node.
        The idea is inspired from: http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
 Time complexity consists of looks each node only once --> O(N)
 Space complexity --> O(1)
 */

#include <climits>

bool checkNodes(Node* root, int min, int max) {
    if (!root){
        return true;
    }
    if (root->data < min or root->data > max){
        return false;
    }
    return checkNodes(root->left, min, root->data - 1) and checkNodes(root->right, root->data + 1, max);
}

bool isBST(Node* root) {
    return checkNodes(root, INT_MIN, INT_MAX);
}

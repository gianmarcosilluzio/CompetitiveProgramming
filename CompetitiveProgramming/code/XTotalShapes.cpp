/*
 *  XTotalShapes.cpp
 *
 *  Created on: 27 dic 2017
 *      Author: Gianmarco Silluzio
 *      Problem: https://practice.geeksforgeeks.org/problems/x-total-shapes/0
 *      Description Solution:
 *      The idea is use a simple graph traversal approach. Check each field of matrix (if equal to X) and if it is not visited. Mark the visited field with DFS. Update and return the result.
 Time complexity --> O(V^2), each position (vertex V) in the matrix is visited once.
 Space complexity --> O(V)
*/

#include <bits/stdc++.h>

using namespace std;

bool matrix[50][50];

void dfs(int i,int j){
    matrix[i][j] = true;

    if(!matrix[i][j-1]){
        dfs(i,j-1);
    }
    if(!matrix[i][j+1]){
        dfs(i,j+1);
    }
    if(!matrix[i-1][j]){
        dfs(i-1,j);
    }
    if(!matrix[i+1][j]){
        dfs(i+1,j);
    }
}

int main(){
    int num_test, m, n;

    cin >> num_test;
    for(int t = 0; t < num_test; t++){
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            string str;
            cin >> str;

            for(int j = 0; j < str.size(); j++){
                if(str[j] == 'X'){
                    matrix[i][j+1] = false;
                }else{
                    matrix[i][j+1] = true;
                }
            }
        }

        for(int i = 0; i <= n; i++){
            matrix[i][0] = true;
            matrix[i][m+1] = true;
        }

        for(int i = 0;i <= m; i++){
            matrix[0][i] = true;
            matrix[n+1][i] = true;
        }

        int result = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!matrix[i][j]){
                    dfs(i,j);
                    result++;
                }
            }
        }
        cout << result << endl;
    }

	return 0;
}

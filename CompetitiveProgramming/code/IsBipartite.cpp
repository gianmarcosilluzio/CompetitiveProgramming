/*
 *  IsBipartite.cpp
 *
 *  Created on: 27 dic 2017
 *      Author: Gianmarco Silluzio
 *      Problem: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
 *      Description Solution:
 *      The idea is use a simple graph traversal approach. Check each field of matrix if are connected. Each field is marked with DFS.
 Time complexity --> O(V^2), each position (vertex V) in the matrix is visited once.
 Space complexity --> O(V)
*/
#include <bits/stdc++.h>

using namespace std;

bool dfs(int G[][MAX],int V,int j,int i,vector<int> nodes){
    if(j == i){
       return false;
    }
    if(j == -1){
        nodes[i] = 1;
    }
    bool temp = true;
    for(int v = 0; v < V; v++){
        if(G[i][v] && nodes[v] == -1){
            nodes[v] = 1-nodes[i];
            temp = temp && dfs(G,V,i,v,nodes);
        }
        else if(G[i][v] && nodes[v] == nodes[i]){
            return false;
        }
    }
    return temp;
}


bool isBipartite(int G[][MAX], int V){
    vector<int> nodes(V, -1);
    for(int i = 0; i < V; i++){
        if(nodes[i] == -1){
            if(dfs(G,V,-1,i,nodes) == false){
               return false;
            }
        }
    }
    return true;
}



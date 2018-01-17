/*
 *    FoxAndNames.cpp
 *
 *  	Created on: 17 dic 2017
 *      Updated on: 14 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/459/D?locale=en
 *      Optimized solution inspired from https://bruceoutdoors.wordpress.com/2015/10/26/510c-fox-and-names-codeforces-tutorial/
 *      Description Solution:
 *      The idea is tracing the DFS using a vector of booleans, where the indices of the vector correspond to the graph nodes. Then validate that the digraph has no cycles (DAG: Directed Acyclic Graph), the topological order is as simple as finding the reverse post order of the DAG. Then use DFS twice on the digraph. First pass to check for cycles, and second pass to get the topological order. Detecting whether a sequence of words is “Impossible” is as simple as detecting whether there are any cycles in a directed graph, tracing the nodes of every recursive call a node traverses in a DFS. If within a recursive call of a node it traverses itself, there is a cycle.

 Time complexity --> Wrost case: O(V + E)
 Space complexity --> O(n)
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
const int ALPHABET = 26;
vector<int> g[30], results;
string s[MAX];
bool visited[30];
bool used[30];

void dfs(int x){
    visited[x] = true;
	used[x] = true;
	for(int i = 0; i < g[x].size(); i++){
		if(used[g[x][i]]){
			cout << "Impossible";
			exit(0);
		}
		else if(!visited[g[x][i]]){
			dfs(g[x][i]);
		}
	}
	used[x] = false;
	results.push_back(x);
}

void func(int id){
	for(int i = 0; i < s[id].size() && i < s[id+1].size(); i++){
		if(s[id][i] != s[id+1][i]){
			g[s[id+1][i]-'a'].push_back(s[id][i]-'a');
			return;
		}
	}

	if(s[id].size() > s[id+1].size()){
		cout << "Impossible";
		exit(0);
	}
}
int main(){
    int n;
	cin >> n;

	for(int i = 1;i <= n; i++){
		cin >> s[i];
	}

	for(int i = 1; i < n; i++){
		func(i);
	}

	for(int i = 0; i < ALPHABET; i++){
		if(!visited[i]){
		    dfs(i);
		}
	}

	for(int i = 0; i < ALPHABET; i++){
	    char c = results[i]+'a';
		cout << c;
	}
	return 0;
}

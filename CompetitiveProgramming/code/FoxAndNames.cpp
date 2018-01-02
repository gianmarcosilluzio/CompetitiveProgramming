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

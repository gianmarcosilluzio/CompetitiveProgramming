#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MAX_N = 3e5 + 500;
const int inf = 2e10;
const int MOD = 1e9 + 7;

vector <int> g[MAX_N], gr[MAX_N], top, comp;
int visited_1[MAX_N], visited_2[MAX_N], a[MAX_N];

void dfs1(int v){
	visited_1[v] = 1;
	for (int i = 0; i < g[v].size(); i++){
		if (!visited_1[g[v][i]]){
			dfs1(g[v][i]);
		}
	}
	top.push_back(v);
}

void dfs2(int v){
	visited_2[v] = 1;
	comp.push_back(v);
	for (int i = 0; i < gr[v].size(); i++){
		if (!visited_2[gr[v][i]]){
			dfs2(gr[v][i]);
		}
	}
}

main(){
	int n = 0, m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		if (!visited_1[i]){
			dfs1(i);
		}
	}

	int cost = 0, ways = 1;
	for (int i = top.size() - 1; i >= 0; i--){
		if (!visited_2[top[i]]){
			int c = inf;
			dfs2(top[i]);
			int w = 0;
			for (int j = 0; j < comp.size(); j++){
				c = min(c, a[comp[j]]);
			}
			for (int j = 0; j < comp.size(); j++){
				if (c == a[comp[j]]) w++;
			}
			comp.clear();

			ways *= w;
			ways %= MOD;
			cost += c;

		}
	}
	cout << cost << " " << ways;
}

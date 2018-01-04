#include <iostream>
#include<vector>

using namespace std;

vector <int> a[200];
bool visited[200];

void dfs(int i){
	visited[i] = true;
	for (int j = 0; j < a[i].size(); j++){
		if (!visited[a[i][j]]){
		    dfs(a[i][j]);
		}
	}
}
int main(){
	int n = 0, m = 0, result = 0, tr = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int num_lang_empl;
		cin >> num_lang_empl;
		if (num_lang_empl > 0){
		    tr = 1;
		}
		for (int j = 0; j < num_lang_empl; j++){
		    int lang = 0;
			cin >> lang;
			a[i].push_back(n+lang);
			a[n+lang].push_back(i);
		}
	}
	for (int i = 0; i < n; i++){
		if (!visited[i]) {
			result++;
			dfs(i);
		}
	}
	result -= tr;
	cout << result;
	return 0;
}

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    pair<int, string> a[3010];
    int tot[3010];
    int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].second >> a[i].first;
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++){
		int l = i - a[i].first;
		if (l < 0) {
		    cout << -1; return 0;
		}
		tot[i] = l;
		for (int j = 0; j < i; j++){
		    if (tot[j] >= tot[i]) tot[j]++;
		}
	}
	for (int i = 0; i < n; i++){
		cout << a[i].second << " " << 3000 + tot[i] << endl;
	}

}

/*
 *  NestedSegments.cpp
 *
 *  	Created on: 15 dic 2017
 *      Updated on: 14 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://codeforces.com/problemset/problem/652/D?locale=en
 *      Description Solution:
 *      The idea is sort queries in decreasing order by left part. Create a BIT and stores the right part of query for each segment. For each query store answer in array anwers given from BIT (passing rigth of query and n. n start from end, so from number of queries), and update sum of BIT. The result is contained in answrs array.

 Time complexity --> Wrost case: O(NlogN)
 Space complexity --> O(n)
*/

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX = 1103+2e5;

int ans[MAX];
int tree[MAX];

struct Q{
	int id;
	int l,r;
} queries[MAX];

bool cmp_l(Q x, Q y) {
	return x.l < y.l;
}

bool cmp_r(Q x, Q y) {
	return x.r < y.r;
}

int low_bit(int x) {
	return x&(-x);
}

void update(int x,int value,int n) {
	while(x <= n) {
		tree[x] += value;
		x += low_bit(x);
	}
}

int get_sum(int x,int n) {
	int ans = 0;
	while(x > 0) {
		ans += tree[x];
		x -= low_bit(x);
	}
	return ans;
}

int main() {



	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].id = i;
	}

	sort(queries+1, queries+1+n, cmp_r);

	for(int i = 1; i <= n; i++){
		queries[i].r = i;
	}

	sort(queries+1, queries+1+n, cmp_l);

	for(int i = n; i >= 1; i--){
		ans[queries[i].id] = get_sum(queries[i].r,n);
		update(queries[i].r,1,n);
	}

	for(int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}

	return 0;
}

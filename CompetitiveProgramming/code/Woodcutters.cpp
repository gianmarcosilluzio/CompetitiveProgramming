#include<iostream>

using namespace std;

#define MAX 100001

int main(){
    int n = 0, s = 2;
	cin >> n;
	int a[MAX], b[MAX];
	for(int i = 0;i< n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 1; i < n-1; i++){
		if(a[i]-a[i-1] > b[i]){
		    s++;
		}
		else if(a[i+1]-a[i] > b[i]){
		    s++;
		    a[i]+=b[i];
		}
	}
	cout << (n == 1 ? 1 : s);
}

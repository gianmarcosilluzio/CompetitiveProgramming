#include<iostream>

using namespace std;

int main(){
    long long result, a, b;
    int n = 0;
    cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a;
		result = result + abs(a-b);
		b = a;
	}
	cout << result;
}

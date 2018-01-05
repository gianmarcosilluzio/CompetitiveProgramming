#include<iostream>

using namespace std;

int main(){
    int n, tot = 1;
    string s;
    cin >> n >> s;

    for(int i = 1; i < n; i++){
        tot += (s[i-1] != s[i]);
    }

    cout << min(tot+2, n);
}

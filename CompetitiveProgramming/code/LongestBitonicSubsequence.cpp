#include<iostream>

using namespace std;

int main(){

    int tests_case;
    cin >> tests_case;

    for(int t = 0; t < tests_case; t++) {
        int n = 0;
        cin >> n;
        int arr[n], incr[n], decr[n];

        for (int i = 0; i < n; ++i) {
            incr[i] = decr[i] = 1;
            cin >> arr[i];
        }

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (arr[i] > arr[j] and incr[i] < (incr[j] + 1)){
                    incr[i] = incr[j] + 1;
                }
            }
        }

        for (int i = (n - 2); i >= 0; i--){
            for (int j = n - 1; j > i; j--){
                if (arr[j] < arr[i] and decr[i] < (decr[j] + 1)){
                    decr[i] = decr[j] + 1;
                }
            }
        }

        int max = incr[0] + decr[0] - 1;

        for (int i = 1; i < n; ++i){
            if (max < (incr[i] + decr[i] - 1)){
                max = incr[i] + decr[i] - 1;
            }
        }

        cout << max << endl;
    }
}

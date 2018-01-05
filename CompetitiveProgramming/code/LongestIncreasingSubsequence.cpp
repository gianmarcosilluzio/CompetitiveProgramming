#include <iostream>
#include <vector>

using namespace std;

int main(){
	int tests_case = 0;
	cin >> tests_case;
	vector<int> inputs;
	vector<int> arr;

	for(int t = 0; t < tests_case; t++){
	    int n = 0, maxResult = 0;
	    cin >> n;

	    inputs.reserve(n);
	    arr.reserve(n);

	    for(int i = 0; i < n; i++){
	        cin >> inputs[i];
	        int max = 1;
	        for(int j = 0 ; i > 0 && j < i ; j++){
	            if(inputs[i] > inputs[j] ){
	                if (max < (arr[j]+1)){
	                    max = arr[j]+1;
	                }
	            }
	        }

	        arr[i] = max;
	        if(maxResult < max){
	            maxResult = max;
	        }
	    }

	    inputs.clear();
	    arr.clear();
	    cout << maxResult << endl;
	}
	return 0;
}

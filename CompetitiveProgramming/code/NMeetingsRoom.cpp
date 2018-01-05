#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int first, last, index;
};

bool compare(struct node a, struct node b){
    return a.last < b.last;
}

int main() {
	int test_cases = 0;
	cin >> test_cases;
	for(int t = 0; t < test_cases; t++){

	    vector<int> results;


	    int n = 0;
	    cin >> n;
	    struct node A[n];

	    for(int i = 0; i < n; i++){
	        cin >> A[i].first;
	    }
	    for(int i = 0; i < n; i++){
	        cin >> A[i].last;
	        A[i].index = i+1;
	    }

	    sort(A, A+n, compare);

	    int i = 0;
	    results.push_back(A[0].index);
	    for(int j = 1; j < n; j++){
	        if(A[j].first >= A[i].last){
	            results.push_back(A[j].index);
	            i = j;
	        }
	    }

	    for(int i = 0; i < results.size(); i++){
	        cout << results[i] << " ";
	    }

	    cout<<endl;
	}
	return 0;
}

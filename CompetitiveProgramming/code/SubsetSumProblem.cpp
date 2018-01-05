#include <iostream>
#include <vector>

using namespace std;

bool isSub(vector<int> const& vec, int n, int sum){

    if(sum % 2){
        return false;
    }

    bool dp[sum/2 + 1][n+1];

    for(int i = 0;i <= n; i++){
        dp[0][i]=true;
    }

    for(int i = 1; i <= sum/2; i++){
        dp[i][0]=false;
    }

    for(int i = 1; i <= sum/2; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j-1];
            if(vec[j-1] <= i){
                dp[i][j] = dp[i-vec[j-1]][j-1] || dp[i][j];
            }
        }
    }
    return dp[sum/2][n];
}

int main(){

	int tests_case;
	vector<int> vec;
	cin >> tests_case;
	for(int t = 0; t < tests_case; t++){
	    int n = 0, sum = 0;
	    cin >> n;
	    vec.reserve(n);
	    for(int i = 0; i < n; i++){
	        cin >> vec[i];
	        sum += vec[i];
	    }
	    isSub(vec, n, sum) ? cout << "YES" << endl : cout << "NO" << endl;
	    vec.clear();
	}
	return 0;
}

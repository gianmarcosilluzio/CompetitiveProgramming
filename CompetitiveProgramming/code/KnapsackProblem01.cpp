#include <iostream>
#include <vector>

using namespace std;

int main(){
    int tests_case = 0;
    cin >> tests_case;

    for(int t = 0; t < tests_case; t++){
        int n = 0, w = 0;
        cin >> n >> w;

        vector<int> val(n);
        vector<int> wt(n);
        for(int i = 0; i < n; i++){
            cin >> val[i];
        }
        for(int i = 0; i < n; i++){
            cin >> wt[i];
        }

        vector<vector<int>> res(n+1,vector<int>(w+1,0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= w; j++){
                res[i][j] = res[i-1][j];
                if(wt[i-1] <= j){
                    res[i][j] = max(res[i][j], val[i-1]+res[i-1][j-wt[i-1]]);
                }
            }
        }
        cout << res[n][w] << endl;
    }
	return 0;
}

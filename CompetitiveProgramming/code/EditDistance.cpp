#include <iostream>
#include<algorithm>

using namespace std;

int main() {
	int tests_case = 0;
	cin >> tests_case;

	for(int t = 0; t < tests_case; t++){
	    int p = 0, q = 0;
	    cin >> p >> q;

	    int res[p+1][q+1];

	    string str_1, str_2;
	    cin >> str_1 >> str_2;

	    for(int i = 0;i <= p; i++){
	        for(int j = 0; j <= q; j++){
	            if(i == 0){
	                res[i][j] = j;
	            }
	            else if(j == 0){
	                res[i][j] = i;
	            }
	            else if(str_1[i-1] == str_2[j-1]){
	                res[i][j] = res[i-1][j-1];
	            }
	            else{
	                res[i][j] = 1 + min(res[i-1][j-1], min(res[i][j-1], res[i-1][j]));
	            }
	        }
	    }
	    cout << res[p][q] << endl;
	}
	return 0;
}

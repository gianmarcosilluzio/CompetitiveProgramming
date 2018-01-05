#include <iostream>
#include <string>

using namespace std;

int main(){

	int tests_case;
	cin >> tests_case;

	for(int t = 0; t < tests_case; t++){
	    int n_1 = 0, n_2 = 0;
	    string str_1, str_2;

	    cin >> n_1 >> n_2;
	    cin >> str_1 >> str_2;

	    int lcs[n_1+1][n_2+1];

	    for(int i = 0; i <= n_1; i++){
	        for(int j = 0;j <= n_2; j++){
	            if(i == 0 || j == 0){
	                lcs[i][j]=0;
	            }
	            else if(str_1[i-1] == str_2[j-1]){
	                lcs[i][j]=lcs[i-1][j-1]+1;
	            }
	            else{
	             lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
	            }
	       }
	   }

	   cout << lcs[n_1][n_2] << endl;

	}
	return 0;
}


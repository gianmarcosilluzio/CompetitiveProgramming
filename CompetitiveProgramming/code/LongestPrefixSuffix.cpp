#include <iostream>
#include <vector>

using namespace std;

int getLps(const string& s) {
    const int s_len = s.length();

    vector<int> lps(s_len);
    lps[0] = 0;

    int len = 0, i = 1;
    while (i < s_len) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len == 0) {
                lps[i] = 0;
                i++;
            } else {
                len = lps[len-1];
            }
        }
    }

    return lps[s_len-1];
}

int main() {
	int tests_case;
	cin >> tests_case;

	for(int t = 0; t < tests_case; t++){
	    string s;
	    cin >> s;
	    cout << getLps(s) << endl;
	}
	return 0;
}

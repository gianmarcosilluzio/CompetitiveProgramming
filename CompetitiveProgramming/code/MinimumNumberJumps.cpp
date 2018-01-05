#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tests_case;
	cin >> tests_case;

	vector<int> inputs;

	for (int t = 0; t < tests_case; t++) {
		int n;
		cin >> n;
        inputs.reserve(n);
        vector<int> arr(n, 1e6);
        arr[0] = 0;

		for (int i = 0; i < n; i++){
			cin >> inputs[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n && j <= i + inputs[i]; j++)
				arr[j] = min(arr[j], arr[i] + 1);
		}

		cout << (arr.back() == 1e6 ? -1 : arr.back()) << endl;
		inputs.clear();
	}

	return 0;
}

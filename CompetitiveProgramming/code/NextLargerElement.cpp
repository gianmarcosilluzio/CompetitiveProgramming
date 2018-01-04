/*
 * NextLargerElement.cpp
 *
 *      Created on: 02 oct 2017
 *      Updated on: 03 jan 2017
 *      Author: Gianmarco Silluzio
 *		Problem: http://practice.geeksforgeeks.org/problems/next-larger-element/0
 *		Description Problem: Push the first element to stack. Pick rest of the elements one by one, assign -1 value, and follow following steps in loop: Mark the current element as next; If stack is not empty, then pop an element from stack and compare it with next; If next is greater than the popped element, then next is the next greater element for the popped element; Keep popping from the stack while the popped element is smaller than next; next becomes the next greater element for all such popped elements; If next is smaller than the popped element, then push the popped element back. Solution insiperd by https://www.geeksforgeeks.org/next-greater-element/ and by https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/code/NextLargerElements.cpp
 *		Time complexity: O(n)
 *		Auxiliary Space: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct int_type {

    int_type(int v)
        : val(v)
    {}

    void operator>>(int_type x) {
        cin >> x.val;
    }

    friend ostream& operator<<(ostream& out, int_type x) {
        out << x.val;
        return out;
    }

    static int_type invalid() {
        return int_type(-1);
    }

    int val;
};

template<typename T, typename GreaterFunc>
vector<T> get_next_larger_elements(vector<T> const& vec, GreaterFunc g) {

    vector<T> results;
    results.reserve(vec.size());
    stack<T> s;

    for (auto i = vec.rbegin(); i != vec.rend(); i++) {
        auto next = T::invalid();
        while (!s.empty()) {
            auto tos = s.top();
            if (g(tos, *i)) {
                next = tos;
                break;
            }
            s.pop();
        }
        results.push_back(next);
        s.push(*i);
    }

    return results;
}

int main() {

    int num_tests = 0;
    cin >> num_tests;
    vector<int_type> inputs;
    for (int i = 0; i < num_tests; i++) {
        int n = 0;
        cin >> n;
        inputs.reserve(n);
        for (int j = 0; j < n; j++) {
            int elem = 0;
            cin >> elem;
            inputs.push_back(elem);
        }
        auto res = get_next_larger_elements(inputs, [](int_type x, int_type y) { return x.val > y.val; });

        for (auto i = res.rbegin(); i != res.rend(); i++) {
            cout << *i << " ";
        }
        cout << endl;
        inputs.clear();
    }

    return 0;
}

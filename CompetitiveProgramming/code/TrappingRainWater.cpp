/*
 * TrappingRainWater.cpp
 *
 *      Created on: 26 set 2017
 *      Updated on: 02 jan 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/trapping-rain-water/0
 *      Description Solution: Pre-compute highest bar on left and right of every bar in O(n) time, with two variables to store the maximum till that point. Since water trapped at any element = min(m_left, m_right) – vec[i] we will calculate water trapped on smaller element out of vec[l] and vec[h] first and move the pointers till lo doesn’t cross hi. Efficient space solution inspired by https://www.geeksforgeeks.org/trapping-rain-water/.
 *      Time complexity --> O(N)
 *      Space complexity --> O(N), just input elements array
 */
#include <iostream>
#include <vector>

using namespace std;

int get_water(vector<int> const& vec){
    int n = vec.size();
    int result = 0;

    // maximum element on left and right
    int l_max = 0, r_max = 0;

    // indices to traverse the array
    int l = 0, h = n-1;

    while(l <= h){
        if(vec[l] < vec[h]){
            if(vec[l] > l_max){
                // update max in left
                l_max = vec[l];
            }else{
                // water on curr element = max - curr
                result += l_max - vec[l];
                l++;
            }
        }else{
            if(vec[h] > r_max){
                // update right maximum
                r_max = vec[h];
            }else{
                result += r_max - vec[h];
                h--;
            }
        }
    }

    return result;
}

int main() {

    int num_tests = 0;
    cin >> num_tests;

    vector<int> inputs;
    for (int i = 0; i < num_tests; ++i) {
        int n = 0;
        cin >> n;
        inputs.reserve(n);
        for (int j = 0; j < n; ++j) {
            int x = 0;
            cin >> x;
            inputs.push_back(x);
        }

        int water = get_water(inputs);
        cout << water << endl;
        inputs.clear();
    }

    return 0;
}

/*
 * TrappingRainWater.cpp
 *
 *  Created on: 26 set 2017
 *      Author: Gianmarco Silluzio
 *      Problem: http://practice.geeksforgeeks.org/problems/trapping-rain-water/0
 *      Description Solution: Time complexity O(n), Space complexity O(n) + O(n) for addiotinal vector
 *      The idea is find maximum height from the left and store it on leftMax array, find maximum height from the right and store it on rightMax array.
 *      For each element of array update variable water and then add minimum between maxLeft and maxRigth less height of element.
 */

#include <iostream>
#include <array>

using namespace std;

int getWaterTrapped(std::vector<int> array);

int main() {
    std::vector<int> array = {3, 2, 5, 1, 0, 2, 1, 5, 0};
    int water = getWaterTrapped(array);
    printf("%d", water);
}

int getWaterTrapped(std::vector<int> array){
    int water = 0;
    int size = array.size();
    std::vector<int> leftMax(size);
    std::vector<int> rightMax(size);
    leftMax[0] = array[0];
    for (int i = 1; i < size; i++) {
        leftMax[i] = max(array[i], leftMax[i - 1]);
    }
    rightMax[size - 1] = array[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        rightMax[i] = max(array[i], rightMax[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        water += min(leftMax[i], rightMax[i]) - array[i];
    }
    return water;
}

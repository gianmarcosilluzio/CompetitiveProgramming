/*
 * NextLargerElement.cpp
 *
 *  Created on: 02 oct 2017
 *      Author: Gianmarco Silluzio
		Problem: http://practice.geeksforgeeks.org/problems/next-larger-element/0
		Description Problem: The idea is use a deque for store the element postion of the largest element of analyzed element. If the element analyzed is minor than element in front of queue, the element analyzed will be inserted in the queue. If the element analyzed is greater than elements in the queue, will be stored the element of the queue in the array result (in the position of analyzed element). Then will be stored value -1 in the array results (in the position of analyzed element) for all remaining in the queue.
		Time complexity: O(2n)
		Auxiliary Space: O(k)
*/

#include <iostream>
#include <array>
#include <deque>

using namespace std;

std::vector<int> getNextLargestNumbers(std::vector<int> array, int N);
void printArrayElements(std::vector<int> array);

int main() {
    int N = 0;
    std::vector<int> array;
    cout << "Insert Size: ";
    std::cin >> N;
    array.reserve(N);
    for (int i = 0; i < N; i++) {
        int num = 0;
        cout << "\nInsert Element: ";
        std::cin >> num;
        array.push_back(num);
    }
    std::vector<int> results = getNextLargestNumbers(array, N);
    printArrayElements(results);
}

std::vector<int> getNextLargestNumbers(std::vector<int> array, int N){
    std::vector<int> results;
    std::deque<int> Q;
    Q.push_back(0);
    for(int i = 1; i < N; i++){
        while(!Q.empty() && array[i] > array[Q.back()]){
            results.push_back(array[i]);
            Q.pop_back();
        }
        if(Q.empty() || array[i] < array[Q.front()]){
            Q.push_back(i);
        }
    }

    for(auto i : Q){
        results.insert(results.begin()+i, -1);
    }
    return results;
}

void printArrayElements(std::vector<int> array){
    printf("\nResults: ");
    for(int i = 0; i < array.size(); i++){
        printf("%d ", array[i]);
    }
}

//============================================================================
// Name        : CompetitiveProgramming.cpp
// Author      : Gianmarco Silluzio
// Version     :
// Copyright   : gianmarcosilluzio
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int getTrappingWater(int N, int array[]);

int main() {
	int array[] = {3, 0, 3, 1, 4, 0, 2, 2, 1};
	int N = sizeof(array)/sizeof(array[0]);
	int water = getTrappingWater(N, array);
	printf("%d, Water: ", water);
	return 0;
}

int getTrappingWater(int N, int array[]){
	int totalSum = 0;
	int sum = 0;
	int current = 0;
	int max = array[0];
	int analyzed = 0;
	int empty = 0;

	for(int i = 0; i < N; i++){
		current = array[i];

		if(i != 0 && current >= max){
			current = max;
			max = array[i];
			printf("FINAL] i: %d - Current: %d - Max: %d - Analyzed: %d - sum: %d\n",i, current, max, analyzed, sum);

			sum = (analyzed * current - empty);
			analyzed = 0;
			totalSum += sum;
			sum = 0;
			empty = 0;
			printf("MAX] i: %d - Current: %d - Max: %d - Analyzed: %d - TotalSum: %d\n",i, current, max, analyzed, totalSum);

		}

		if(analyzed > 0 && current>0){
			sum += (analyzed * current - empty);
			printf("SOMMA] i: %d - Current: %d - Max: %d - Analyzed: %d - Sum: %d\n",i, current, max, analyzed, sum);

		}

		if(array[i] < max){
			analyzed++;
			empty += current;
		}
		printf("i: %d - Current: %d - Max: %d - Analyzed: %d - Sum: %d\n",i, current, max, analyzed, sum);

		if(i == N-1){
			totalSum += sum;
		}


	}

	return totalSum;
}

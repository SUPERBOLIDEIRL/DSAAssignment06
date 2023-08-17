#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "BubbleSort.h"
#include "HeapSort.h"

//Adam Wajda - DSA - Assignment 6

#define N 20000

int main()
{
	srand(time(NULL)); //seed the generator

	int arrayBubble[N]; //initiate arrays and random number variable
	int arrayHeap[N];
	int rng;

	for (int i = 0; i < N; i++) //put same random numbers into both arrays
	{
		rng = (rand() % 20000) + 1;
		arrayBubble[i] = rng;
		arrayHeap[i] = rng;
	}

	clock_t BubbleStartTime = clock();
	bubbleSort(&arrayBubble, N);
	clock_t BubbleEndTime = clock();
	double BubbbleSortTime = (double)(BubbleEndTime - BubbleStartTime) / CLOCKS_PER_SEC; //calculate time it takes to perform  bubble sort
	
	clock_t HeapStartTime = clock();
	heapSort(arrayHeap, N);
	clock_t HeapEndTime = clock();
	double HeapSortTime = (double)(HeapEndTime - HeapStartTime) / CLOCKS_PER_SEC; //check time it takes to perform heap sort

	printf("Bubble sort time: %lf\n", BubbbleSortTime);
	printf("Heap sort time: %lf\n", HeapSortTime);
	
	return 0;
}
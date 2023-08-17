#include <stdio.h>
#include "HeapSort.h"

//Adam Wajda -  DSA - Assignment 6

void swap(int* x, int* y) //function to swap positions of 2 elements
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//heapify function to push the largest element to the top
void heapify(int HeapArray[], int N, int i) //takes i
{
    int largest = i; //set root as largest value
    int left = 2 * i + 1; //index of left root
    int right = 2 * i + 2; //index of right root

    if (left < N && HeapArray[left] > HeapArray[largest]) //if left child is larger than root
        largest = left; //then change index of largest to that of left child

    if (right < N && HeapArray[right] > HeapArray[largest]) //if right child is larger that current largest
        largest = right; //then change index of largest to that of right child

    if (largest != i) //if root is not the largest element
    {
        swap(&HeapArray[i], &HeapArray[largest]); //swap the root with largest element
        heapify(HeapArray, N, largest); //recursively heapify to make sure that parent is the largest
    }
}


void heapSort(int HeapArray[], int N) //heap sorting function
{
    int i;
    for (i = N / 2 - 1; i >= 0; i--) //loop to use heapify to form a max heap
        heapify(HeapArray, N, i); //call heapify to push max elment to first index spot
    for (i = N - 1; i >= 0; i--)  //loop with heapify to sort the max heap
    {
        swap(&HeapArray[0], &HeapArray[i]);//push the root, which is the largest after heapify, element to the last index
        heapify(HeapArray, i, 0); //heapify to get the next largest elment to the first index spot
    }
}
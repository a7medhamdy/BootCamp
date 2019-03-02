/*********************************************************************************
 *
 *  problem_three.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/

/****************************[Problem Description]*********************************
 *
 * Given a sorted array with duplicates find the last occurance of a given number
 * and if not existing report it.
 *
 * Sample Input: Arr= [ 2, 5, 5, 5, 6, 6, 7 ]
 * 				 Target = 5
 * Sample Output: Last occurance of 5 is at index 3
 *
 * Sample Input: Arr= [1, 1, 2, 2, 2, 4, 6]
 * 				 Target = 5
 *
 * Sample Output: There is no 5 in the array
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_three.h"

/*********************************************************************************
 *
 * Function: findLastOccurrence
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: target, The elment to be searched for the last occurance for
 * @return: int, the index of the last occurance of the element
 *
 * Description: Function to find the index of the last occurance of a number
 * in a sorted array. The function should return -1 if the elment is not found in
 * the array.
 *
 *
 ********************************************************************************/
int findLastOccurrence(int arr[], int arr_size, int target)
{
	int i=0;
	int index =-1;
	for (i=0; i<arr_size;i++)
	{
		if (arr[i]==target)
		{
			index=i;
		}
	}
	return index;

}



/* findLastOccurrence_test function */
int main(void)
{
	int A[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
	int n = sizeof(A)/sizeof(A[0]);

	int target = 5;

	int index = findLastOccurrence(A, n, target);

	if (index != -1)
		printf("First occurrence of element %d is found at index %d\n", target, index);
	else
		printf("Element not found in the array");
	return 0;

}

/*********************************************************************************
 *
 *  problem_six.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/

/****************************[Problem Description]*********************************
 *
 * Given an array with non negative integers find the Peak (largest) element
 *
 * Sample Input: arr = [8, 9, 10, 2, 5, 6]
 * Sample Output: The Peak is 10
 *
 * Sample Input: arr = [ 1 ,2 ,5, 7, 17]
 * Sample Output: The peak is 17
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_six.h"
/*********************************************************************************
 *
 * Function: findPeakElement
 *
 * @param: arr[], Array that the function should find the largest number in.
 * @param: low, the index of the first element in array
 * @param: high, the index of the last elment in the array
 * @return: int, the index of peak element
 *
 * Description: function to get the largest number in the array.
 *
 *
 ********************************************************************************/
int findPeakElement(int arr[], int low, int high, int n){
	int i = 0;
	int temp = 0;
	for (i = 0;i<n-1;i++)
	{
		if(arr[i+1]<arr[i]){
			temp = arr[i];
			arr[i+1] = arr[i];
			arr[i]=temp;
			findPeakElement(arr,low,i,i+1);
		}
	}

	return high;
}

/* findPeakElement_test function */
void main(void)
{
	int A[] = { 8, 9, 10, 2, 11, 6 };
	int n = sizeof(A) / sizeof(A[0]);

	int index = findPeakElement(A, 0, n - 1, n);
	printf("The peak element is %d\n", A[index]);


	int A2[] = { 1, 2, 3, 17 ,5, 10};
	int n2 = sizeof(A2) / sizeof(A2[0]);

	int index2 = findPeakElement(A2, 0, n2 - 1, n2);
	printf("The peak element is %d\n", A2[index2]);

}

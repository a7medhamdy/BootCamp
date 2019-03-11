/*********************************************************************************
 *
 *  problem_seven.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/

/****************************[Problem Description]*********************************
 *
 * Find the number of 1's in a binary array that is sorted
 * Sample Input: arr = [0,0,1,1,1,1]
 * Sample Output: Number of 1s is 4
 *
 ********************************************************************************/

#include <stdio.h>
#include "problem_seven.h"
/*********************************************************************************
 *
 * Function: countOnes
 *
 * @param: arr[], Array that the function is to count the ones in.
 * @param: arr_size, size of the array
 * @return: int, the number of ones in the array
 *
 * Description: function to get the largest number in the array.
 *
 *
 ********************************************************************************/
int countOnes(int arr[], int arr_size){
	int i = 0;
	int count = 0;
	for (i=arr_size-1;i>=0;i--)
	{
		if (arr[i]==0)
		{
			return count;
		}
		else
		{
			count++;
		}
	}
}


/* countOnes_test function */
void main(void)
{
	int arr[] = { 0, 0, 0, 0,0,1,1,1,1,1,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Total number of 1's present are %d", countOnes(arr, n));

}

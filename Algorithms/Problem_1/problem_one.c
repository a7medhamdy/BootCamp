/*********************************************************************************
 *
 *  problem_one.c

 *  Author: Ahmed Hamdy Mahmoud
 *  		Mohamed Mostafa Abdel karim
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_one.h"

/****************************[Problem Description]*********************************
 *
 * Given an array that is circularly rotated and sorted in an ascending order and
 * the rotation is clock wise, find the number of rotations in the array.
 *
 * Sample Input:  arr = [8, 9, 10, 2, 5, 6]
 * Sample Output: The Array is rotated 3 times
 *
 * Sample Input:  arr = [2, 5, 6, 8, 9, 10]
 * Sample Output: The array is rotated 0 times
 *
 ********************************************************************************/

/*********************************************************************************
 *
 * Function: findRotationCount
 * @param: arr[], Array that the function should find the number of rotations in.
 * @param: arr_size, Size of the array
 * Description: Function to find the number of times the array is rotated
 *
 ********************************************************************************/
int findRotationCount(int arr[], int arr_size) {
	/* Your code goes here  */
	int temp = 0;
	int i=0,j=0;
	for (i = 0 ;i<arr_size;i++)
	{
		if (arr[arr_size-1]<arr[0])
		{
			temp = arr[arr_size-1];
			for (j = arr_size-1;j>=1;j--)
			{
				arr[j]=arr[j-1];
			}
			arr[0]=temp;
		}
		else
		{
			break;
		}
	}
	for (j=0;j<arr_size-1;j++)
	{
		if (!(arr[j]<arr[j+1])){
			printf("The given array is not circulary sorted\n");
		}
		else{
		}
	}
	return i;
}


/*********************************************************************************
 *
 * findRotationCount_Test function to test your code
 *
 ********************************************************************************/
int main(void)
{
	int arr[] = { 9, 8, 10, 2, 5, 6 };

	int n = sizeof(arr) / sizeof(arr[0]);

	int count = findRotationCount(arr, n);
	printf("The array is rotated %d times\n", count);
}

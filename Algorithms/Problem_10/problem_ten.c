/**********************************************************************************************************************
 *
 *  problem_ten.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 *********************************************************************************************************************/
/****************************[Problem Description]********************************************************************
 *
 * You are given two arrays A and B consisting of integers, sorted in non-decreasing order.
 * Check whether it is possible to choose k numbers in array A and choose m numbers in array B so that any
 * number chosen in the first array is strictly less than any number chosen in the second array
 * Print "YES" (without the quotes), if you can choose k numbers in array A and m numbers in array B so that any number chosen in array A was strictly less
 * than any number chosen in array B. Otherwise, print "NO" (without the quotes).
 *
 * Sample Input: arr1 = [1, 2 ,3]  and arr2 = [3, 4 ,5]
 * 				 K = 1 and M = 2
 *
 * Sample Output: Yes.
 *                This is because if we take one number of arr1 which would be '1' and take two of arr2 which would
 *                be '3' and '4' then '1' is strictly less than 3 and 4
 *
 * Sample Input: arr1 = [1,2,3] and arr2 = [3, 4, 5]
 * 				 K = 3 and M = 3
 * Sample Output: NO.
 * 				  Although '1' and '2' are strictly less than all elements in arr2 the number '3' is not as
 * 				  3 is not less than 3 so there exists an element that is not strictly less than elemnets in arr2
 *
 **********************************************************************************************************************/
#include <stdio.h>
#include "problem_ten.h"
#define ARR_SIZE 3

void elemntsInOneLessThanSecond(int arr1[], int size_arr1, int arr2[], int size_arr2, int k, int n){
	int i = 0,j = 0;
	int flag = 0;
	for (i = 0;i<k;i++)
	{
		for (j = 0;j<n;j++)
		{
			if (arr1[i]<arr2[j])
			{
				continue;
			}
			else
			{
				printf("NO");
				flag = 1;
			}
		}

	}
	if (flag==0)
	{
		printf("Yes");
	}

}


int main(void){
	int arr1[ARR_SIZE] = {1,2,3}, arr2[ARR_SIZE] = {3,4,5};
	elemntsInOneLessThanSecond(arr1, ARR_SIZE, arr2, ARR_SIZE,2, 3);
	return 0;
}

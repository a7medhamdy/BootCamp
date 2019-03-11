/*********************************************************************************
 *
 *  problem_four.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/

/****************************[Problem Description]*********************************
 *
 * Count occurances of a number in a sorted array
 * Sample Input: arr= [2,2, 4, 5, 5, 5, 5, 6, 6]
 * 				 target = 5
 * Sample Output: The number 5 occured 4 times in the array
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_four.h"

/*********************************************************************************
 *
 * Function: BinarySearchOccurances
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: target, The elment to be searched for the last occurance for
 * @param: searchFirst, Indicates whether you are using this function to get the
 * first occurance of the target or last (1 for first and 0 for last)
 * @return: int, the index of the last occurance of the element
 *
 * Description: function to get the number of occurances of a target element in a
 * given sorted array.
 *
 *
 ********************************************************************************/
int BinarySearchOccurances(int arr[], int arr_size, int target, int searchFirst){
	int i = 0;
	static int call=0;
	int index = 0;
	if (searchFirst==1)
	{
		for(i = 0;i<arr_size;i++)
		{
			if (arr[i]==target)
			{
				call=1;
				return i;

			}
			else
			{

			}
		}
		return -1;
	}
	else if(searchFirst==0)
	{

		if (call==1)
		{
			for(i = 0;i<arr_size;i++)
					{
						if (arr[i]==target)
						{
							index= i;
						}
						else
						{

						}
					}
					return index;
		}
		else
		{
			printf("you must get the first occurence\n");
		}

	}
	else
	{
		printf("You must enter 1 or 0\n");

	}

}

/* Count occurrences of a number in a sorted array with duplicates*/
void main(void)
{
	int A[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
	int target = 5;

	int n = sizeof(A)/sizeof(A[0]);
	int first = BinarySearchOccurances(A, n, target,1);  // 1 for first occurrence
	int last = BinarySearchOccurances(A, n, target, 0);   // 0 for last occurrence

	int count = last - first + 1;

	if (first != -1)
		printf("Element %d occurs %d times.", target, count);
	else
		printf("Element not found in the array.");
}


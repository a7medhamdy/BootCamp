/*********************************************************************************
 *
 *  Binary_Search.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/



/****************************[Problem Description]*********************************
 *
 * Binary search is one of the best searching algorithms. Binary search algorithm
 * works as follows:
 * Assume having a sorted array arr = [1, 2, 3, 4, 5, 6, 7] and you want to search
 * for the number "2" the algorithm starts by comparing your target number "2" to
 * the middle number in the array which is "4" if this is the desired number then
 * return the index of it, if not, is 2 greater than 4 ? no then is it less than 4?
 * Yes, then start looking in the sub array starting from the first element in the
 * array to the elment right before the middle element "4", i.e (1..arr[mid-1]).
 * Get the middle element in this sub-array and compare it to 2, is 2 equal to 2?
 * Yes then return the index of it.
 * As we can see Binary search found this number in 2 iterations only.
 *
 *Notice:: if you try searching for the element "6" you will reach it in only two
 *		   iterations
 ********************************************************************************/
#include <stdio.h>
#include "Binary_Search.h"
#include "Bubble_Sort.h"



int Linear_search_algo(int arr[], int arr_size, int target){
	int i = 0;
	for (i = 0; i<arr_size; i++)
	{
		if (target==arr[i])
		{
			return i;
		}
		else
		{
			continue;
		}
	}
	return -1;
}
int Binary_search_algo(int arr[], int arr_size, int target){
	/* Your code goes here */
	Bubble_sort_algo(arr,arr_size);
	int start = 0;
	int end = arr_size-1;
	int mid = (end-start)/2;
	while (arr[mid]!=target)
	{
		if (arr[mid]>target)
		{
			end = mid-1;
			mid = (end-start)/2;
		}
		else
		{
			start = mid+1;
			mid = ((end-start)/2)+start;
		}
		if (mid == 0 || mid == arr_size-1)
		{
			break;
		}


	}
	if (arr[mid]==target)
	{
		return mid;
	}
	else
	{
		return -1;
	}


}




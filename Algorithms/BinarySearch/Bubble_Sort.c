/*********************************************************************************
 *
 *  Bubble_Sort.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/
#include "Bubble_Sort.h"
/********************************************************************************
 *
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Example:
First Pass:
( '5' '1' 4 2 8 ) –> ( '1' '5' 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 '5' '4' 2 8 ) –>  ( 1 '4' '5' 2 8 ), Swap since 5 > 4
( 1 4 '5' '2' 8 ) –>  ( 1 4 '2' '5' 8 ), Swap since 5 > 2
( 1 4 2 '5' '8' ) –> ( 1 4 2 '5' '8' ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( '1' '4' 2 5 8 ) –> ( '1' '4' 2 5 8 ), No swapping
( 1 '4' '2' 5 8 ) –> ( 1 '2' '4' 5 8 ), Swap since 4 > 2
( 1 2 '4' '5' 8 ) –> ( 1 2 '4' '5' 8 ), No swapping
( 1 2 4 '5' '8' ) –>  ( 1 2 4 '5' '8' ), No swapping
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs
one whole pass without any swap to know it is sorted.

Third Pass:
( '1' '2' 4 5 8 ) –> ( '1' '2' 4 5 8 ), No swapping
( 1 '2' '4' 5 8 ) –> ( 1 '2' '4' 5 8 ), No swapping
( 1 2 '4' '5' 8 ) –> ( 1 2 '4' '5' 8 ), No swapping
( 1 2 4 '5' '8' ) –> ( 1 2 4 '5' '8' ), No swapping
 *******************************************************************************/
void Bubble_sort_algo(int arr[], int size){
	int i =0,j=0;
	int temp = 0;
	for(j =0; j <size;j++)
	{
		for(i = 0; i<size-1; i++)
		{
			if (arr[i+1]<arr[i])
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;

			}
		}
			/* Your code goes here*/
	}
	/* Your code goes here*/
}

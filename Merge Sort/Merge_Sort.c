/*********************************************************************************
 *
 *  Merge_Sort.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/



/****************************[Problem Description]*********************************
 *
 * As per explained algorithm, complete the below code to implement a fully
 * functional merge sort code
 *
 ********************************************************************************/
#include <stdio.h>


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int left, int middle, int right)
{
    /* Variables to hold the values of the sizes of the two sub-arrays */
	int i,j,k;
	int n1 = middle - left + 1;
	 int n2 =  right - middle;

    /* create temp sub-arrays of sizes that you got when you divided the large array */
	 int l[n1];
	 int r[n2];

    /* Copy data to temp arrays L[] and R[] */
	for(i=0;i< n1;i++){
		l[i]=arr[i+left];
	}

	for(i=0;i<n2 ;i++){
		r[i]=arr[i+1+middle];

	}

	i=0,j=0,k=left;
    /* Merge the temp arrays back into arr[l..r]*/

    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }


    /* Copy the remaining elements of L[], if there
       are any */
	  while (i < n1)
	    {
	        arr[k] = l[i];
	        i++;
	        k++;
	    }


    /* Copy the remaining elements of R[], if there
       are any */
	while(j<n2){
		arr[k]=r[j];
		j++;
		k++;
	}

}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main(void)
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size-1 );

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

/*
 * main.c
 *
 *  Created on: Feb 11, 2019
 *      Author: AVE-LAP-039
 */

# include <stdio.h>
#include <stdlib.h>
#include "Bubble_Sort.h"
#include "Binary_Search.h"

#define ARR_SIZE 12

int main(void){
	int index = 0;
	int arr[ARR_SIZE] = {1, 55, 10, 23, 6, 12, 44, 2, 0, 15, 43, 7};
	index = Linear_search_algo(arr, ARR_SIZE, 44);
	if(index == -1 ){
		printf("Target not found in the array\n");
	}

	else{
		printf("Target is found in the array at index %d\n", index);
	}
	index = Binary_search_algo(arr,ARR_SIZE, 33);
	if(index == -1 ){
		printf("Target not found in the array\n");
	}
	else{
		printf("Target is found in the array at index %d\n", index);
	}
	return 0;
}

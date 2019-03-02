/*
 * Selection.c
 *
 *  Created on: Feb 12, 2019
 *      Author: AVE-LAP-005
 */

/* Team Names */

/* Ahmed Abdlrehem
 * Ahmed Hamdy
 */

#include "stdio.h"
void Selection_Sort(int arr[],int arr_size){

	int i,j;
	int temp=0;
	for(i=0;i<arr_size-1;i++){
		for(j=i+1;j<arr_size;j++){
			if(arr[i]>arr[j]){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;

			}

		}

	}

}
 void main(void){

	 int arr[]={5,6,3,2,1};
	Selection_Sort(arr,5);
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
 }

/*
 * Implementation.c
 *
 *  Created on: Feb 11, 2019
 *      Author: AVE-LAP-039
 */

int Sort_RotationCount(int arr[], int arr_size) {
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

int Binary_search_algo(int arr[], int arr_size, int target){

	int rotation_count = Sort_RotationCount(arr,arr_size);
	unsigned short i = 0;
	unsigned short first = 0;
	unsigned short last  = arr_size-1U;
	unsigned short mid   = ((last-first)+!((last-first)%2))/2U;

	while((first <= last)){

		if(arr[mid] == target){
			if(mid < arr_size-(arr_size-rotation_count)){
				return arr_size+(mid-rotation_count);
			}
			else
			{
				return mid-rotation_count;
			}
		}
		else if(target > arr[mid]){
			first=mid+1;
			mid = (((last-first)+!((last-first)%2))/2U)+first;
		}
		else{
			last=mid-1;
			mid = (((last-first)+!((last-first)%2))/2U)+first;
		}
	}

	return -1;

}


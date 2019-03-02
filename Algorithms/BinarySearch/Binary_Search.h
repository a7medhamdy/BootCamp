/*********************************************************************************
 *
 *  Binary_Search.h
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/
#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

/*********************************************************************************
 *
 * @param:: arr[], the array to search in
 * @param:: arr_size, the size of the array
 * @param:: target, the element to be searched for
 * @return:: Index of the number in the array.
 *
 * Note: If the number is not found in the array the function should return -1
 *
 ********************************************************************************/
extern int Binary_search_algo(int arr[], int arr_size, int target);
extern int Linear_search_algo(int arr[], int arr_size, int target);

#endif

/*********************************************************************************
 *
 *  problem_three.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/

#ifndef PROBLEM_THREE_H_
#define PROBLEM_THREE_H_

/*********************************************************************************
 *
 * Function: findLastOccurrence
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: target, The elment to be searched for the last occurance for
 * @return: int, the index of the last occurance of the element
 *
 * Description: Function to find the index of the last occurance of a number
 * in a sorted array. The function should return -1 if the elment is not found in
 * the array.
 *
 *
 ********************************************************************************/
extern int findLastOccurrence(int arr[], int arr_size, int target);

#endif /* PROBLEM_THREE_H_ */

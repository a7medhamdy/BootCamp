/*********************************************************************************
 *
 *  problem_two.h
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/

#ifndef PROBLEM_TWO_H_
#define PROBLEM_TWO_H_

/*********************************************************************************
 *
 * Function: circularArraySearch
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: element_to_be_found, The elment to be searcher for
 * @return: int, the index of the element to be found
 *
 * Description: Function to find the number of times the array is rotated, if the
 * element was not found it should return -1
 *
 ********************************************************************************/
extern int circularArraySearch(int arr[], int arr_size, int element_to_be_found);

#endif /* PROBLEM_TWO_H_ */

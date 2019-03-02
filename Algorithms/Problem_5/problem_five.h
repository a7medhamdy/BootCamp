/*********************************************************************************
 *
 *  problem_five.h
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/


#ifndef PROBLEM_FIVE_H_
#define PROBLEM_FIVE_H_

/*********************************************************************************
 *
 * Function: smallestMissing
 *
 * @param: arr[], Array that the function should find the missing number in.
 * @param: low, the index of the first element in array
 * @param: high, the index of the last elment in the array
 * @return: int, the missing element
 *
 * Description: function to get the number of occurances of a target element in a
 * given sorted array.
 *
 *
 ********************************************************************************/
extern int smallestMissing(int arr[], int low, int high);

#endif /* PROBLEM_FIVE_H_ */

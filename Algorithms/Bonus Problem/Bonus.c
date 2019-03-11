/*********************************************************************************
 *
 *  Bonus.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * Write a function that takes an integer non-negative number(N)
 * and uses it to print the following pattern:
 * Sample Input: N = 3
 * Sample Output:
 * 					3 3 3 3 3
 * 					3 2 2 2 3
 * 					3 2 1 2 3
 * 					3 2 2 2 3
 * 					3 3 3 3 3
 * Sample Input: N = 2
 * Sample Output:
 * 					2 2 2
 * 					2 1 2
 * 					2 2 2
 *
 ********************************************************************************/
#include <stdio.h>
#include "Bonus.h"
void printPattern(unsigned int N)
{
    unsigned int i,j;
    unsigned int length = 2*N-1;
    unsigned int arr1[length][length];
    unsigned int arr2[length][length];
    unsigned int start = 0;
    unsigned int end = length-1;
	
    for (i = 0; i<length; i++)
    {
        for (j=0; j<length; j++)
        {
            arr1[i][j]=N;
            arr2[i][j]=1;
        }
    }

    while ((start != (N-1)) && end != (end != (N-1)))
    {
        for (i = 1 ; i<length-1; i++)
        {
            for (j=1 ; j<length-1; j++)
            {
                if(!(i<=start || j<=start || i>=end || j>=end) )
                {
                    arr1[i][j]=arr1[i][j]-arr2[i][j];
                }
            }
        }
        start++;
        end--;
    }

    for (i = 0; i<length; i++)
    {
        for (j=0; j<length; j++)
        {
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    printPattern(5);
}

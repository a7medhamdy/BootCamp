/*********************************************************************************
 *
 *  problem_ten.h
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/
/****************************[Problem Description]****************************************************
 *
 * Given a number "N" find four integer numbers a, b, c and d such that b, c and d are prime numbers,
 * and a & N are odd knowing that a^3 + b^3 + c^3 + d^3 = N and a <= b <= c <= d
 *
 * Sample Input: N = 161
 * Sample Output: Numbers are 1, 2, 3 and 5
 *
 * @return: Array containing a, b, c and d respectively that satisfy the equation
 *
 * Note: 1 <= N <= 10^18
 *
 *******************************************************************************************************/
#include <stdio.h>
#include <math.h>
#include "problem_nine.h"


int getprimes(int n,int *p_primes)
{
	int k = 0,i=0,index=0;
	for(k=2;k<=n;k++)
	{

		i=2;
		while(k%i!=0)
		{
			i++;
		}

		if(i==k)
		{
			*(p_primes+index)=i;
			index++;
		}
	}
	return index;
}

void findPrimeNumbers(int n){
	int i=0,j=0;
	int max = pow(n,(float)1/3);
	int arr[max];
	/* getting the prime numbers below the given number*/
	getprimes(max,arr);

	/* To get odd summation as a result of adding 4 numbers,
	 * We must have 3 odd number and 1 even number,
	 * so b = 2 and where a <=b so a = 1,
	 * the equation will be  N = 9 + c^3 + d^3
	 */
    int a = 1;
    int b =2;
    int c,d;
    for (i=1;i<max;i++)
    {
        c=arr[i];

        for(j=i;j<max;j++)
        {
            d=arr[j];
            int x = 9 + c*c*c + d*d*d;

            if ((int)x == n)
            {
                    printf("a = %d\n",a);
                    printf("b = %d\n",b);
                    printf("c = %d\n",c);
                    printf("d = %d\n",d);
            }
        }

    }

}



int main(void){

	findPrimeNumbers(161);


	return 0;
}

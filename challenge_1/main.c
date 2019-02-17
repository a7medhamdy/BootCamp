/*
 * main.c
 *
 *  Created on: Feb 5, 2019
 *      Author: AVE-LAP-039
 */


/*
 * AUTHOR: Ahmed Nofal, Avelabs Embedded R&D software team
 */
#include <stdio.h>

void Detect_Endianness(void){
	short int x = 0x1234;
		char y= (char)x;
		char *p = y;
		printf("%x",*p);
	if((*p) == 0x34)
	{
		printf("Big endian\n");
	}
	else{
		printf("Little endian\n");
	}
}

int main(void){
	Detect_Endianness();
}

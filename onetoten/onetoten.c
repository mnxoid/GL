/** 
 * @file	onetoten.c
 * @brief	C source of the app that displays the sum of first 10 integers
 *
 * 

 * Copyright 2014 by mnxoid,
 * 
 * This software is the confidential and proprietary information
 * of mnxoid ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with mnxoid.
 */
#include <stdio.h>
const int N=10;
int main()
{
	int i,s=0;
	for (i=0;i<N;i++) s+=i;
	printf("The sum of %i first integers is: %i\n",N,s);
	char nothing=getchar();
	return 0;
}
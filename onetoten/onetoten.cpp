/** 
 * @file	onetoten.cpp
 * @brief	C++ source of the app that displays the sum of first 10 integers
 *
 * 

 * Copyright 2014 by mnxoid,
 * 
 * This software is the confidential and proprietary information
 * of mnxoid ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with mnxoid.
 **/
#include <iostream>
#include <stdio.h>
using namespace std;
const int N=10;/*variable in case we need to change the sum limit in the future*/
int main()
{
	int s=0;
	for (int i=0;i<N;i++) s+=i;
	cout << "The sum of " << N << " first integers is: " << s <<endl;
	char nothing=getchar();
	return 0;
}
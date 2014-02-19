/** 
 * @file	hidingtest.cpp
 * @brief	C++ source of the app that tests hiding ability
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
int main()
{
	int i=7;
	 {
	 	int i=9;
	 	i++;
	 }
	i--;
	cout << i << "Hoorah! Hiding works in gcc4.7!" << endl;
	char nothing=getchar();
	return 0;
}
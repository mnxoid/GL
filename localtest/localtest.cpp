/** 
 * @file	localtest.cpp
 * @brief	C++ source of the app that ...
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
//------------------Includes------------------------------------
#include <stdio.h>
#include <iostream>
//------------------Namespaces----------------------------------
using namespace std;
//------------------Definitions---------------------------------
int a=6;
namespace
	 {
	 	int a=7;
	 }
namespace A
	 {
	 	int a=8;
	 }
//------------------Structures,classes,unions-------------------
//------------------Utility functions---------------------------
//------------------Main function-------------------------------
int main()
{
	//put da code here
	cout << "global a=6 only" << endl;
	
	cout << "Now a equals: " << a << endl;
	
	cout << "A::a equals " << A::a << endl;
	cout << "Using A" << endl;
	cout << "a equals " << a << endl;
	char nothing=getchar();
	return 0;
}
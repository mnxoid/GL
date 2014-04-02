/** 
 * @file	coins_3.cpp
 * @brief	C++ source of the app that flips coins and determines
 *			the sequence in which they should be placed so that
 *			after K flips of every 5th coin there were I coins
 *			placed heads up.
 *			Parameters:
 *				N - coin quantity
 *				M - tails up
 *				K - number of flips
 *				I - heads up after flipping
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
#include "util.h"
//------------------Namespaces----------------------------------
using namespace std;
//------------------Disclaimer----------------------------------
/**
 * @brief       This function displays license agreement
 **/
void Disclaimer (  ) 
 {
 	printf ( "This is an app that flips coins and determines\n" ) ; 
 	printf ( "the sequence in which they should be placed so that\n" ) ;
 	printf ( "after K flips of every 5th coin there were I coins\n" ) ;
 	printf ( "placed heads up.\nParameters:\n\tN - coin quantity\n\tM - tails up\n\tK - number of flips\n\tI - heads up after flipping\n\n" ) ;
	printf ( "Copyright 2014 by mnxoid, \n\n" ) ; 
	printf ( "This software is the confidential and proprietary information\n" ) ; 
	printf ( "of mnxoid  (\"Confidential Information\") .  You\n" ) ; 
	printf ( "shall not disclose such Confidential Information and shall use\n" ) ; 
	printf ( "it only in accordance with the terms of the license agreement\n" ) ; 
	printf ( "you entered into with mnxoid.\n\n" ) ; 
	printf ( "By pressing [ENTER] you confirm that you are NOT A GEODESIST\n" ) ; 
	CleanInput (  ) ; //here CleanInput is used as a safe getchar (  ) 
 }
//------------------Main function-------------------------------
int main()
{
	Disclaimer();
	//put da code here
	CleanInput();
	return 0;
}
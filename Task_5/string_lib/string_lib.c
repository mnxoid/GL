/** 
 * @file	string_lib.c
 * @brief	C source of the app that uses functions from mystring.h
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
#include "mystring.h"
#include "util.h"
//------------------Disclaimer----------------------------------
/**
 * @brief       This function displays license agreement
 **/
void Disclaimer (  ) 
 {
 	printf ( "This is an app that ...\n\n" ) ; 
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
	printf("strcasecmp usage:\n");
	printf("abcd vs abcd -> %i\n",strcasecmp("abcd","abcd"));
	printf("ABCD vs abcd -> %i\n",strcasecmp("ABCD","abcd"));
	printf("abcd vs abcde -> %i\n",strcasecmp("abcd","abcde"));
	printf("abcde vs abcd -> %i\n\n",strcasecmp("abcde","abcd"));

	printf("strcmp usage:\n");
	printf("abcd vs abcd -> %i\n",strcmp("abcd","abcd"));
	printf("ABCD vs abcd -> %i\n",strcmp("ABCD","abcd"));
	printf("abcd vs abcde -> %i\n",strcmp("abcd","abcde"));
	printf("abcde vs abcd -> %i\n\n",strcmp("abcde","abcd"));

	printf("strncmp usage:\n");
	printf("abcd vs abcd -> %i\n",strncmp("abcd","abcd",3));
	printf("ABCD vs abcd -> %i\n",strncmp("ABCD","abcd",3));
	printf("abcd vs abcde -> %i\n",strncmp("abcd","abcde",3));
	printf("abcde vs abcd -> %i\n\n",strncmp("abcde","abcd",3));

	printf("strncasecmp usage:\n");
	printf("abcd vs abcd (3) -> %i\n",strncasecmp("abcd","abcd",3));
	printf("ABCD vs abcd (3) -> %i\n",strncasecmp("ABCD","abcd",3));
	printf("abcd vs abcde (3) -> %i\n",strncasecmp("abcd","abcde",3));
	printf("abcde vs abcd (3) -> %i\n\n",strncasecmp("abcde","abcd",3));

	CleanInput();
	return 0;
}
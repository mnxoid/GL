/** 
 * @file	replace_2.cpp
 * @brief	C++ source of the app that replaces numbers in a sequence
 *			 with the closest bigger ones or zero if not possible.
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
#include <stdlib.h>
#include "util.h"
struct elem
 {
	int value;
	unsigned int index;
	elem* prev;
 };
//------------------Disclaimer----------------------------------
/**
 * @brief       This function displays license agreement
 **/
void Disclaimer ( void ) //puts is faster
 {
 	printf ( "This is an app that that replaces numbers in a sequence\n with the closest bigger ones or zero if not possible.\n\n" ) ; 
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
	unsigned int size;
	printf("Input the number of elements: ");
	if( InputUInt( &size, USELIM, 0, MAXUI ) == ERROR )
	 {
	 	printf("Error!\n");
	 	return 0;
	 }
	int *arr = (int*)calloc( size, sizeof(int) );//alloc check
	unsigned int i;
	for ( i = 0; i < size; ++i )
	 {
	 	printf("Array[%i]=", i+1);
	 	if( InputInt(arr+i, NOLIM, 0, 0) == ERROR )
		 {
		 	printf("Error!\n");
		 	return 0;
		 }
	 }
	printf("Here's the inputted array: \n");
	for( i = 0; i < size; ++i )   
	 {
	 	printf( "%i  ", *(arr+i) );
	 }
	//elem stack;
	//stack.value=0;
	//stack.index=0;
	//stack.prev=NULL;
	elem *current = NULL;
	elem *previous;
	int j;
	for( i = 0; i < size ; ++i)
	 {
	 	if(current == NULL)
	 	 {
	 	 	previous = current;
	 	 	current = (elem*)calloc( 1, sizeof(elem) );//check
	 	 	current->value = *(arr+i);//make function
	 	 	current->index = i;
	 	 	current->prev = previous;
	 	 } else if ( *(arr+i) > current->value ) {
	 	 	while ( (current != NULL) && ( *(arr+i) > current->value ) )
	 	 	 {
	 	 	 	*( arr + current->index ) = *(arr+i);
	 	 	 	elem *temp=current;
	 	 	 	current = current->prev;//free
	 	 	 	free(temp);
	 	 	 }
	 	 	previous = current;
	 	 	current = (elem*)calloc( 1, sizeof(elem) );//check
	 	 	current->value = *(arr+i);
	 	 	current->index = i;
	 	 	current->prev = previous;
	 	 } else {
	 	 	previous = current;
	 	 	current = (elem*)calloc( 1, sizeof(elem) );//check
	 	 	current->value = *(arr+i);
	 	 	current->index = i;
	 	 	current->prev = previous;
	 	 }
	 	//printf("\nHere's the modified array: \n");
		//for(j=0;j<size;j++)
		 //{
		 	//printf("%i  ",*(arr+j));
		 //}
	 }
	while ( current != NULL )
	 {
	 	*( arr + current->index ) = 0;
	 	elem *temp=current;
	 	current=current->prev;
	 	free(temp);
	 }
	printf("\nHere's the modified array: \n");
	for( i=0; i < size ; ++i )
	 {
	 	printf( "%i  ", *(arr+i) );
	 }
	
	CleanInput();//free
	return 0;
}
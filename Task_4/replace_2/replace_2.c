/** 
 * @file	replace_2.c
 * @brief	C source of the app that ...
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
typedef struct A
 {
	int value;
	unsigned int index;
	elem* prev;
 } elem;
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
	unsigned int size;
	printf("Input the number of elements: ");
	if(InputUInt(&size,NOLIM,0,0)==ERROR)
	 {
	 	printf("Error!\n");
	 	return 0;
	 }
	int *arr=calloc(size, sizeof(int));
	unsigned int i;
	for (i=0;i<size;i++)
	 {
	 	printf("Array[%i]=",i+1);
	 	if(InputInt(arr+i,NOLIM,0,0)==ERROR)
		 {
		 	printf("Error!\n");
		 	return 0;
		 }
	 }
	elem stack;
	stack.value=0;
	stack.index=0;
	stack.prev=NULL;
	elem *current=&stack;
	elem *previous;
	for(i=0;i<size;i++)
	 {
	 	if(current->prev==NULL)
	 	 {
	 	 	previous=current;
	 	 	current=calloc(1,sizeof(elem));
	 	 	current->value=*(arr+i);
	 	 	current->index=i;
	 	 	current->prev=previous;
	 	 } else if (*(arr+i)>current->value) {
	 	 	while (*(arr+i)>current->value)
	 	 	 {
	 	 	 	*(arr+current->index)=*(arr+i);
	 	 	 	current=current->prev;
	 	 	 }
	 	 	previous=current;
	 	 	current=calloc(1,sizeof(elem));
	 	 	current->value=*(arr+i);
	 	 	current->index=i;
	 	 	current->prev=previous;
	 	 } else {
	 	 	previous=current;
	 	 	current=calloc(1,sizeof(elem));
	 	 	current->value=*(arr+i);
	 	 	current->index=i;
	 	 	current->prev=previous;
	 	 }
	 }
	while (current->prev!=NULL)
	 {
	 	*(arr+current->index)=0;
	 }
	printf("Here's the modified array: \n");
	for(i=0;i<size;i++)
	 {
	 	printf("%i  ",*(arr+i));
	 }
	CleanInput();
	return 0;
}
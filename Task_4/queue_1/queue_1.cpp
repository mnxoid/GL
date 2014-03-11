/** 
 * @file	queue_1.c
 * @brief	C source of the app that simulates a queue
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
//------------------Definitions---------------------------------
#define ERROR 1
#define SUCCESS 0
#define USELIM 1
#define NOLIM 0
#define MAXUI 294967290
//------------------Structures,classes,unions-------------------
struct item
 {
	unsigned int number;
	item *next,*prev;
 };
//------------------Utility functions---------------------------
/**
 * @brief       This function flushes stdin
 **/
void CleanInput (  ) 
 {
 	while ( ! ( getchar (  ) =='\n' )  )  continue; 
 }
/**
 * @brief       This function displays license agreement
 **/
void Disclaimer (  ) 
 {
 	printf ( "This is an app that simulates a queue.\n\n" ) ; 
	printf ( "Copyright 2014 by mnxoid, \n\n" ) ; 
	printf ( "This software is the confidential and proprietary information\n" ) ; 
	printf ( "of mnxoid  (\"Confidential Information\") .  You\n" ) ; 
	printf ( "shall not disclose such Confidential Information and shall use\n" ) ; 
	printf ( "it only in accordance with the terms of the license agreement\n" ) ; 
	printf ( "you entered into with mnxoid.\n\n" ) ; 
	printf ( "By pressing [ENTER] you confirm that you are NOT A GEODESIST\n" ) ; 
	CleanInput (  ) ; //here CleanInput is used as a safe getchar (  ) 
 }
/**
 * @brief       This function inputs an integer
 * @param	[in/out]		*i - pointer to the integer
 * @param   [in]			use - limit usage flag ( USELIM/NOLIM ) 
 *							min - lower bound
 *							max - upper bound
 * @return	unsigned char		SUCCESS - success
 *								ERROR - error ( null pointer ) 
 **/
unsigned char InputUInt ( unsigned int *i, unsigned char use, unsigned int min, unsigned int max ) 
 {
 	if  ( i==NULL )  return ERROR; 
 	unsigned int in;
 	int retc; 
 	if  ( use==USELIM ) 
 	 {
 	 	retc=scanf ( "%u", &in ) ; 
	 	CleanInput (  ) ; 
	 	if  (  ! (  (  retc > 0  )  &&  (  in > min  )  &&  (  in < max  )  )   ) 
	 	 {
	 	 	do
	 	 	 {
	 	 		printf ( "Sorry,  try again: " ) ; 
	 	 		retc=scanf ( "%u", &in ) ; 
	 	 		CleanInput (  ) ; 
	 	 	 } while  (  ! (  (  retc > 0  )  &&  (  in > min  )  &&  (  in < max  )  )   ) ; 
	 	 }
 	 } else {
 	 	retc=scanf ( "%u", &in ) ; 
	 	CleanInput (  ) ; 
	 	if  (  ! (  retc > 0  )   ) 
	 	 {
	 	 	do
	 	 	 {
	 	 		printf ( "Sorry,  try again: " ) ; 
	 	 		retc=scanf ( "%u", &in ) ; 
	 	 		CleanInput (  ) ; 
	 	 	 } while  (  ! (  retc > 0  )   ) ; 
	 	 }
 	 }
 	*i=in; 
 	return SUCCESS;
 }
/**
 * @brief       This function creates a queue 
 * @param		[in]			*first - pointer to the first element
 * @param						n - number of elements
 * @return		unsigned char 	SUCCESS - success
 * 								ERROR - error
 **/
unsigned char QueueGen(item **first,unsigned int n)
 {
 	if (n<1)
 	 {
 	 	printf("Error! Cannot allocate 0 items!\n");
 	 	return ERROR;
 	 }
 	unsigned int i;
 	item *curr,*prev;
 	*first = (item*)calloc(1, sizeof( item ));
 	if (*first==NULL)
 	 {
 	 	printf("Error! Not enough memory!\n");
 	 	return ERROR;
 	 }
 	(*first)->number=1;
 	(*first)->prev=NULL;
 	prev=(*first);
 	for (i=2; i<n+1; ++i)
 	 {
		curr = (item*)calloc(1, sizeof( item ));
	 	if (curr==NULL)
	 	 {
	 	 	printf("Error! Not enough memory!\n");
	 	 	return ERROR;
	 	 }
	 	curr->number=i;
	 	prev->next=curr;
	 	curr->prev=prev;
	 	prev=curr;
 	 }
 	curr->next=NULL;
 	return SUCCESS;
 }
/**
 * @brief       This function outputs a queue 
 * @param		[in]			*first - pointer to the first element
 * @return		unsigned char 	SUCCESS - success
 * 								ERROR - error
 **/
unsigned char QueueOut(item *first)
 {
 	if (first==NULL)
 	 {
 	 	printf("Error! Nothing to output!\n");
 	 	return ERROR;
 	 }
 	item *curr;
 	curr=first;
 	printf("The queue is : ");
 	do
 	 {
 	 	printf("%u ",curr->number);
 	 	curr=curr->next;
 	 } while (curr != NULL);
 	return SUCCESS;
 }
/**
 * @brief       This function sends an element to the end of the queue
 * @param		[in]			*elem - pointer to the first element
 * @return		unsigned char 	SUCCESS - success
 * 								ERROR - error
 **/
unsigned char ToEnd(item **elem)
 {
 	if ( (*elem) == NULL )
 	 {
 	 	printf("Error! Null pinter exception!\n");
 	 	return ERROR;
 	 }
 	if ( (*elem)->next == NULL )
 	 {
 	 	return SUCCESS;
 	 }
 	item *end;
 	end = (*elem);
 	while( end->next != NULL) end = end -> next;
 	(*elem)->prev->next = (*elem)->next;
 	(*elem)->next->prev = (*elem)->prev;
 	end->next = (*elem);
 	(*elem)->prev = end;
 	(*elem)->next = NULL;
 }
//------------------Main function-------------------------------
int main()
{
	Disclaimer();
	unsigned int M,N,K,L,i;
	printf("Input the quantity of people in the queue: ");
	if (InputUInt(&N,USELIM,0,MAXUI) == ERROR)
	 {
	 	printf("Error! Null pointer exception!\n");
	 	return 0;
	 }
	printf("Input the step: ");
	if (InputUInt(&M,USELIM,0,N) == ERROR)
	 {
	 	printf("Error! Null pointer exception!\n");
	 	return 0;
	 }
	printf("Input the starting number: ");
	if (InputUInt(&K,USELIM,0,N) == ERROR)
	 {
	 	printf("Error! Null pointer exception!\n");
	 	return 0;
	 }
	printf("Input the number of iterations: ");
	if (InputUInt(&L,USELIM,0,MAXUI) == ERROR)
	 {
	 	printf("Error! Null pointer exception!\n");
	 	return 0;
	 }
	item *queue,*curr,*temp;
	if ( QueueGen( &queue, N ) == ERROR )
	 {
	 	return 0;
	 }
	unsigned int j;
	QueueOut(queue);
	printf("\n");
	curr=queue;
	for(i=0; i<L; ++i)
	 {
	 	//curr=queue;
	 	for(j=0; j<M-1; ++j)
	 	 {
	 	 	if ( curr->next != NULL )
	 	 	 {
	 	 	 	curr=curr->next;
	 	 	 }
	 	 }
	 	temp=curr->prev;
	 	ToEnd(&curr);
	 	curr=temp->next;
	 	QueueOut(queue);
	 	printf("\n");
	 }
	CleanInput();
	return 0;
}
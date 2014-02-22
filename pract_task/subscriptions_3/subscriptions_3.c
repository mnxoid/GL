/** 
 * @file	subscriptions_3.c
 * @brief	C source of the app that works with subscription data
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
//------------------Definitions---------------------------------
#define MAXNAME 10
#define ENTRIES 10
#define MAXINDEX 2147483647
#define MAXSUBSCR 2147483647
//------------------Structures,classes,unions-------------------
typedef struct
 {
 	char name[MAXNAME];
 	int subs,index;
 }entry;
//------------------Utility functions---------------------------
/**
 * @brief       This function inputs an entry for the database,
 *				according to the "entry" structure
 * @param	[in,out]		pointer to the entry  
 * @return	int				0  - success
 *							-1 - error
 **/
int EntryIn(entry *e)
 {
 	printf("Entry input:\n");

 	printf("\tName: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->name))) return -1;

 	printf("\tIndex: ");
 	while (getchar() != '\n') continue;
 	if((!(scanf("%i",&e->index)))||(e->index<0)) return -1;

 	printf("\tSubscribers: ");
 	while (getchar() != '\n') continue;
 	if((!(scanf("%i",&e->subs)))||(e->subs<0)) return -1;

 	return 0;
 }
/**
 * @brief       This function outputs an entry from the database,
 *				according to the "entry" structure
 * @param	[in]			the entry(in our case - db[i])  
 * @return	int				0  - success
 *							-1 - error
 **/
void EntryOut(entry e)
 {
 	//printf("Entry output:\n");
 	printf("\t\t%s\t\t%i\t\t%i\n",e.name,e.index,e.subs);
 }
//------------------Main function-------------------------------
int main()
{
	entry db[ENTRIES];
	int k=0;
	printf("Welcome, this app stores the information about subscriptions\n");
	printf("What would you like to do?\n\tA - add entry\n\tV - view entries\n\tD - delete last entry\n\tX - exit\n$ ");
	char input;
	while(1)
	 {
	 	scanf("%c",&input);
		if (input=='A')
		 {
		 	if(EntryIn(&db[k]))
		 	 {
		 	 	printf("Error! Invalid input. Geodesist detected!\n");
		 		break;
		 	 }
		 	//while (getchar() != '\n') continue;
		 	k++;
		 } else if (input=='V') {
		 	if (k>0)
		 	 {
		 	 	int i,l;
		 	 	//sorting start
		 	 	int undone=1;
				while (undone)
				 {
				 	undone=0;
				 	for (i=0;i<k-1;i++){
				 		if (db[i].index>db[i+1].index)
				 		 {
				 		 	entry temp=db[i];
				 		 	db[i]=db[i+1];
				 		 	db[i+1]=temp;
				 		 	undone=1;
				 		 }
				 	}
				 }
		 	 	//sorting end
			 	printf("Database output:\n\t\tName\t\tIndex\t\tSubscribers\n\n");
			 	for (i=0;i<k;i++)
			 	 {
			 	 	EntryOut(db[i]);
			 	 }
			 	//most popular
			 	undone=1;
			 	while (undone)
				 {
				 	undone=0;
				 	for (i=0;i<k-1;i++){
				 		if (db[i].subs<db[i+1].subs)
				 		 {
				 		 	entry temp=db[i];
				 		 	db[i]=db[i+1];
				 		 	db[i+1]=temp;
				 		 	undone=1;
				 		 }
				 	}
				 }
				printf("Most popular:\n");
				if (k>1)
				 {
				 	EntryOut(db[0]);
				 	EntryOut(db[1]);
				 } else {
				 	EntryOut(db[0]);
				 }
			 } else {
			 	printf("Database is empty\n");
			 }
		 } else if (input=='D') {
		 	printf("Entry deleted\n");
		 	if (k>0)
		 	 {
		 		k--;
		 	 }
		 } else if (input=='\n') {
		 	printf("$ ");
		 } else if (input=='X') {
		 	printf("Goodbye!\n");
		 	break;
		 } else {
		 	printf("Error! Invalid input. Geodesist detected!\n");
		 	break;
		 }
		while (getchar() != '\n') continue;
		printf("$ ");
	 }
	char nothing=getchar();
	return 0;
}
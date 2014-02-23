/** 
 * @file	auto_4.c
 * @brief	C source of the app that works with automobile data
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
#define MAXBRAND 20
#define ENTRIES 10
#define MAXNUMBER 10
#define MAXNAME 10
#define MAXSURNAME 10
#define MAXPROBLEMS 40
//------------------Structures,classes,unions-------------------
typedef struct
 {
 	char brand[MAXBRAND],name[MAXNAME],surname[MAXSURNAME],problems[MAXPROBLEMS],number[MAXNUMBER];
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

 	printf("\tNumber: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->number))) return -1;

 	printf("\tBrand: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->brand))) return -1;

 	printf("\tYour name: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->name))) return -1;

 	printf("\tYour surname: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->surname))) return -1;

 	printf("\tProblems: ");
 	while (getchar() != '\n') continue;
 	if(!(fgets(e->problems,MAXPROBLEMS,stdin))) return -1;

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
 	printf("\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",e.number,e.brand,e.name,e.surname,e.problems);
 }
//------------------Main function-------------------------------
int main()
{
	entry db[ENTRIES];
	int k=0;
	printf("Welcome, this app stores the information about automobiles\n");
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
				 	for (i=0;i<k-1;i++)
				 	 {
				 		if (strcmp (db[i].surname,db[i+1].surname)>0)
				 		 {
				 		 	entry temp=db[i];
				 		 	db[i]=db[i+1];
				 		 	db[i+1]=temp;
				 		 	undone=1;
				 		 }
				 	 }
				 }
		 	 	//sorting end
			 	printf("Database output:\n\t\tNumber\t\tBrand\t\tName\t\tSurname\t\tProblems\n\n");
			 	for (i=0;i<k;i++)
			 	 {
			 	 	EntryOut(db[i]);
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
		if(input!='A') while (getchar() != '\n') continue;
		printf("$ ");
	 }
	while (getchar() != '\n') continue;
	char nothing=getchar();
	return 0;
}
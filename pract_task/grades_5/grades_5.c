/** 
 * @file	grades_5.c
 * @brief	C source of the app that works students' grades
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
#define MAXGRADE 100
#define ENTRIES 10
#define MAXNAME 10
#define MAXSURNAME 10
#define SUBJN 6
//------------------Structures,classes,unions-------------------
char subjects[SUBJN][15] = {"Math.Analysis","Algebra","Programming","Geometry","Physics","English"};
typedef struct
 {
 	char name[MAXNAME],surname[MAXSURNAME];
 	int grades[SUBJN];
 	double average;
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

 	printf("\tYour name: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->name))) return -1;

 	printf("\tYour surname: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->surname))) return -1;

 	printf("\tGrades: \n");
 	int i;
 	e->average=0;
 	for(i=0;i<SUBJN;i++)
 	 {
 	 	printf("\t\t%s:",subjects[i]);
 	 	while (getchar() != '\n') continue;
 	 	if((!(scanf("%i",&e->grades[i])))||(e->grades[i]<0)||(e->grades[i]>MAXGRADE)) return -1;
 	 	e->average+=e->grades[i];
 	 }
 	e->average/=SUBJN;
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
 	printf("\t\t%s\t\t%s",e.name,e.surname);
 	int i;
 	printf("\t\t%s: ",subjects[0]);
 	printf("%i\n",e.grades[0]);
 	for(i=1;i<SUBJN;i++)
 	 {
 	 	printf("\t\t\t\t\t\t%s: ",subjects[i]);
 	 	printf("%i\n",e.grades[i]);
 	 }
 	printf("\n");
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
				 		if (db[i].average<db[i+1].average)
				 		 {
				 		 	entry temp=db[i];
				 		 	db[i]=db[i+1];
				 		 	db[i+1]=temp;
				 		 	undone=1;
				 		 }
				 	 }
				 }
		 	 	//sorting end
			 	printf("Database output:\n\t\tName\t\tSurname\t\tGrades\n\n");
			 	l=0;
			 	for (i=0;i<k;i++)
			 	 {
			 	 	if (db[i].average>70) l++;
			 	 	EntryOut(db[i]);
			 	 }
			 	double dob=100*(double)(l)/k;
			 	printf("There are %1.2f%% good students.\n",dob );
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
	while (getchar() != '\n') continue;
	char nothing=getchar();
	return 0;
}
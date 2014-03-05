/** 
 * @file	medic_6.c
 * @brief	C source of the app that works with school medical
 *			examination data
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
#define MAXSURNAME 10
#define ENTRIES 10
#define MAXWEIGHT 200
#define MAXHEIGHT 200
#define DATE_LEN 11 //11.11.2011
//------------------Structures,classes,unions-------------------
typedef struct
 {
 	char name[MAXNAME],surname[MAXSURNAME],birthday[DATE_LEN];
 	int height,weight;
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
 	e->name[MAXNAME]='\0';

 	printf("\tSurname: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->surname))) return -1;
 	e->surname[MAXSURNAME]='\0';

 	printf("\tBirth date: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->birthday))) return -1;
 	e->birthday[DATE_LEN]='\0';

 	printf("\tHeight: ");
 	while (getchar() != '\n') continue;
 	if((!(scanf("%i",&e->height)))||(e->height<0)||(e->height>MAXHEIGHT)) return -1;

 	printf("\tWeight: ");
 	while (getchar() != '\n') continue;
 	if((!(scanf("%i",&e->weight)))||(e->weight<0)||(e->weight>MAXWEIGHT)) return -1;

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
 	printf("\t\t%s\t\t%s\t\t%s\t\t%i\t\t%i\n",e.name,e.surname,e.birthday,e.height,e.weight);
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
			 	printf("Database output:\n\t\tName\t\tSurname\t\tBirth Date\tHeight\tWeight\n\n");
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
		while (getchar() != '\n') continue;
		printf("$ ");
	 }
	while (getchar() != '\n') continue;
	char nothing=getchar();
	return 0;
}
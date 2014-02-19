/** 
 * @file	sport_2.c
 * @brief	C source of the app that gets data about sportsmen
 *			from stdin and outputs them grouped by sport type
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
#define MAXSURNAME 10
#define MAXNAME 10
#define ENTRIES 10
#define MAXSP 10
//------------------Structures,classes,unions-------------------
typedef struct
 {
 	char surname[MAXSURNAME],name[MAXNAME],sport[MAXSP];
 	int age;
 }entry;
//------------------Utility functions---------------------------
int EntryIn(entry *e)
 {
 	printf("Entry input:\n");
 	printf("\tName: ");
 	if(!(scanf("%s",e->name))) return -1;
 	printf("\tSurname: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->surname))) return -1;
 	printf("\tAge: ");
 	while (getchar() != '\n') continue;
 	if((!(scanf("%i",&e->age)))||(e->age>199)) return -1;
 	printf("\tSport(lowercase only):");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->sport))) return -1;
 	while (getchar() != '\n') continue;
 	return 0;
 }
void EntryOut(entry e)
 {
 	//printf("Entry output:\n");
 	printf("\t%s\t%s\t%i\t%s\n",e.name,e.surname,e.age,e.sport);
 }
//------------------Main function-------------------------------
int main()
{
	entry db[ENTRIES];
	int k=0;
	printf("Welcome, this app stores the information about sportsmen\n");
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
			 	printf("Database output:\n\tName\tSurname\tAge\tSport\n\n");
			 	int i,l;
			 	int minbask=200;
			 	for (i=0;i<k;i++)
			 	 {
			 	 	if ((db[i].sport=="basketball") && (db[i].age<minbask))
			 	 	 {
			 	 	 	minbask = db[i].age;
			 	 	 	l=i;
			 	 	 }
			 	 	EntryOut(db[i]);
			 	 	if (minbask!=200)
			 	 	 {
			 	 		printf("Youngest basketballer is:\n");
			 	 		EntryOut(db[l]);	
			 	 	 }
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
	 }
	char nothing=getchar();
	return 0;
}
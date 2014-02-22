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
#define MAXSP 15
//------------------Structures,classes,unions-------------------
typedef struct
 {
 	char surname[MAXSURNAME],name[MAXNAME],sport[MAXSP];
 	int age,deg;
 }entry;
//------------------Utility functions---------------------------
/**
 * @brief       This function inputs an entry for the database,
 *				according to the "entry" structure
 * @param	[in,out]		pointer to the entry  
 * @return	int				
 **/
int EntryIn(entry *e)
 {
 	printf("Entry input:\n");
 	printf("\tName: ");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->name))) return -1;
 	while (getchar() != '\n') continue;
 	printf("\tSurname: ");
 	if(!(scanf("%s",e->surname))) return -1;
 	printf("\tAge: ");
 	while (getchar() != '\n') continue;
 	if((!(scanf("%i",&e->age)))||(e->age>199)||(e->age<0)) return -1;
 	printf("\tSport(lowercase only):");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%s",e->sport))) return -1;
 	printf("\tDegree:");
 	while (getchar() != '\n') continue;
 	if(!(scanf("%i",&e->deg))) return -1;
 	return 0;
 }
void EntryOut(entry e)
 {
 	//printf("Entry output:\n");
 	printf("\t\t%s\t\t%s\t\t%i\t\t%s\t\t%i\n",e.name,e.surname,e.age,e.sport,e.deg);
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
		 	 	// TODO:	sort start
		 	 	//find unique sports:
		 	 	int found,j,ku=0;
		 	 	int i,l;
		 	 	char *unique[ENTRIES];
		 	 	for(i=0;i<k;i++)
		 	 	 {
		 	 	 	found=0;
				 	for(j=0;j<ku;j++)
				 		if(!strncmp(db[i].sport,unique[j],MAXSP)) found=1;
				 	if (!found)
				 	 {
				 	 	unique[ku]=db[i].sport;
				 	 	ku++;
				 	 }
		 	 	 }
		 	 	int pos=0;
		 	 	for(j=0;j<ku;j++)
		 	 	 {
		 	 	 	for(i=pos;i<k;i++)
		 	 	 	 {
		 	 	 	 	if ((!strncmp(db[i].sport,unique[j],MAXSP)) && (i>pos))
		 	 	 	 	 {
		 	 	 	 	 	entry temp=db[i];
		 	 	 	 	 	db[i]=db[pos];
		 	 	 	 	 	db[pos]=temp;
		 	 	 	 	 	pos++;
		 	 	 	 	 }
		 	 	 	 }
		 	 	 }
		 	 	// TODO:	sort end
			 	printf("Database output:\n\t\tName\t\tSurname\t\tAge\t\tSport\t\tDegree\n\n");
			 	int minbask=200;
			 	char bas[] = "basketball";
			 	for (i=0;i<k;i++)
			 	 {
			 	 	//printf("before if\n");
			 	 	//if (db[i].sport==bas) printf("basketballer\n");
			 	 	//if (!strncmp(db[i].sport,bas,10)) printf("basketballer\n");
			 	 	//if (db[i].age<minbask) printf("young\n");
			 	 	if ((!strncmp(db[i].sport,bas,10)) && (db[i].age<minbask))
			 	 	 {
			 	 	 	minbask = db[i].age;
			 	 	 	l=i;
			 	 	 }
			 	 	//printf("after if\n");
			 	 	EntryOut(db[i]);
			 	 }
		 	 	if (minbask!=200)
		 	 	 {
		 	 		printf("Youngest basketballer(s) are:\n");
		 	 		for(i=0;i<k;i++)
		 	 		 {
		 	 		 	if ((!strncmp(db[i].sport,bas,10)) && (db[i].age==db[l].age)) EntryOut(db[i]);
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
		while (getchar() != '\n') continue;
		printf("$ ");
	 }
	char nothing=getchar();
	return 0;
}
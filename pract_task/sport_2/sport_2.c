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
//#define EOF 27
#define MAXLINE 1000
//------------------Structures,classes,unions-------------------
typedef enum spt
 {
 	BASEBALL,
 	GOLF,
 	SOCCER,
 	BASKETBALL,
 	OTHER
 }sport;
typedef struct ent
 {
 	char surname[MAXSURNAME],name[MAXNAME];
 	int age;
 	sport sport_type;
 }entry;
//------------------Utility functions---------------------------
/*int getline(char s[],int lim)
 {
	int c,i;
	for(i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
	 s[i]=c;
	 s[i]='\0';
	 i++;
	return(i);
 }*/
void EntryIn(entry *e)
 {
 	//add code here
 	printf("Entry input:\n");
 }
void EntryOut(entry e)
 {
 	//add code here
 	printf("Entry output:\n");
 }
//------------------Main function-------------------------------
int main()
{
	entry db[ENTRIES];
	int k=0;
	printf("Welcome, this app stores the information about sportsmen\n");
	printf("What would you like to do?\n\tA - add entry\n\tV - view entries\n\tD - delete last entry\n$ ");
	char input;
	while(1)
	 {
	 	scanf("%c",&input);
		if (input=='A')
		 {
		 	EntryIn(&db[k]);
		 	k++;
		 } else if (input=='V') {
		 	int i;
		 	for (i=0;i<k;i++)
		 	 {
		 	 	EntryOut(db[i]);
		 	 }
		 } else if (input=='D') {
		 	k--;
		 } else if (input=='\n') {
		 	printf("$ ");
		 } else {
		 	printf("Error! Invalid input. Geodesist detected!\n");
		 	break;
		 }
	 }
	char nothing=getchar();
	return 0;
}
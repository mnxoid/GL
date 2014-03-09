/** 
 * @file	hex_2.c
 * @brief	C source of the app that parses a string with hex numbers
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
#include <string.h>
//------------------Definitions---------------------------------
#define MAXLINE 100
#define SUCCESS 0
#define ERROR 1
#define MAXTOK 8
//------------------Structures,classes,unions-------------------
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
 	printf ( "This is an app that parses strings with hex numbers.\n\n" ) ; 
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
 * @brief       This function gets user input ( char ) 
 * @param		[in]			*possible - pointer to char array of possible
 *											input values
 * @param		[in/out]		*pc - pointer to char that we input
 * @return		unsigned char 	SUCCESS - success
 * 								ERROR - error
 **/
unsigned char InputChar ( const char *possible, char *pc ) 
 {
 	if  ( possible==NULL ) 
 	 {
 	 	return ERROR; 
 	 } else {
	 	char a; 
	 	scanf ( "%c", &a ) ; 
	 	CleanInput (  ) ; 
	 	char needle[2]; 
	 	needle[0]=a; 
	 	needle[1]='\0'; 
	 	if  ( strstr ( possible, needle ) ==NULL ) 
	 	 {
	 	 	do
	 	 	 {
	 	 		printf ( "Sorry,  try again: " ) ; 
	 	 		scanf ( "%c", &a ) ; 
	 	 		CleanInput (  ) ; 
	 	 		needle[0]=a; 
	 	 	 } while  ( strstr ( possible, needle ) ==NULL ) ; 
	 	 	*pc=a; 
	 	 	return SUCCESS; 
	 	 } else {
	 	 	*pc=a; 
	 	 	//printf ( "%c\n", a ) ; 
	 	 	//printf ( "%s\n", pc ) ; 
	 	 	return SUCCESS; 
	 	 }
	 }
 }
/**
 * @brief       This function gets user input ( string ) and converts it to uppercase
 * @param		[in]			len - length of the string
 *					
 * @return		char* 			pointer to the string, NULL if error
 **/
char* GetString(unsigned int len)
 {
 	if (len == 0)
 	 {
 		printf("Cannot input an empty string!\n");
 		return NULL;
 	 }
 	char *a = calloc( len, sizeof( char ) );
 	if (a==NULL)
 	 {
 	 	printf("Not enough memory!\n");
 	 	return NULL;
 	 }
 	fgets( a, len, stdin);
 	const char* end = "\n";
 	if ( !( strstr(a, end) ) )
 	 {
 	 	CleanInput();
 	 	printf("You entered too much.\nThe cropped string is :\n\t");
 	 	printf("%s\n", a);
 	 	printf("Do you want to input the string again?\n");
		printf("Enter \"Y\" if you want to enter again, enter \"N\" to use the cropped string: ");
 	 	char input;
 	 	if( InputChar("YN",&input) == ERROR )
 	 	 {
 	 	 	printf("Null pointer exception!\n");
 	 	 	return NULL;
 	 	 }
 	 	if ( input == 'Y')
 	 	 {
 	 	 	do
 	 	 	 {
 	 	 	 	printf("Try entering the string again:");
 	 	 	 	fgets( a, len, stdin );
 	 	 	 } while ( !( strstr(a, end) ) );
 	 	 }
 	 }
 	int i;
 	for(i=0;i<len;++i)
 	 {
 	 	*(a+i)=toupper(*(a+i));
 	 }
 	return a;
 }
/**
 * @brief       This function checks whether user input is a set of hex numbers
 * @param		[in]			*str - pointer to the string
 *								len - length of the string
 *					
 * @return		unsigned char 	ERROR - false
 *								SUCCESS - true
 **/
unsigned char CheckHex(char *str, unsigned int len)
 {
 	int i;
 	for (i=0;i<len;++i)
 	 {
 	 	if ( !( ( ( *(str + i) >= '0' ) && ( *(str + i) <= '9' ) ) || ( ( *(str + i) >= 'A' ) && ( *(str + i) <= 'F' ) ) || (*(str + i)==' ') || (*(str + i)=='\n') || (*(str + i)=='\0') ) )
 	 	 {
 	 	 	return ERROR;
 	 	 }
 	 }
 	return SUCCESS;
 }
/**
 * @brief       This function returns next token converted from hex to dec and
 *				modifies the pointer so that it points to the next token
 * @param		[in]			**str - pointer to the string
 *					
 * @return		unsigned int 	token value
 **/
unsigned char HexTok(char **str,unsigned int *num)
 {
 	*num=0;
 	while (**str==' ')
 	 {
 	 	*(str)+=1;//ignore preceeding spaces
 	 }
 	if ((**str=='\0')||(**str=='\n'))
 	 {
 	 	return ERROR;//no more tokens
 	 }
 	int i=0;
 	while (!((*(*str+i)==' ')||(*(*str+i)=='\0')||(*(*str+i)=='\n')))//find the end
 	 {
 	 	++i;
 	 }
 	int n=i,st=1;
 	if (n>8)
 	 {
 	 	printf("\tToo big number");
 	 	*str+=n;
 	 	return ERROR;
 	 }
 	for(;i>0;--i)
 	 {
 	 	if ((*(*str + i-1) >= '0' )&&(*(*str + i-1) <= '9' ))
 	 	 {
 	 	 	*num+=(*(*str+i-1)-'0')*st;
 	 	 } else {
 	 	 	*num+=(*(*str+i-1)-'A'+10)*st;
 	 	 }
 	 	st*=16;
 	 }
 	*str+=n;
 	return SUCCESS;
 }
//------------------Main function-------------------------------
int main()
{
	Disclaimer();
	printf("Now you should input a string with hexadecimal numbers separated by spaces(do not use the 0x prefix):\n");
	char *str;
	str=GetString(MAXLINE);
	if (str==NULL)
	 {
	 	printf("Error while GetString(%u)",MAXLINE);
	 	return 0;
	 }
	printf("You inputted:%s\n",str);
	while (CheckHex(str,MAXLINE)==ERROR)
	 {
	 	printf("I found some invalid characters...Make sure you are not a GEODESIST and try again:\n");
	 	str=GetString(MAXLINE);
		if (str==NULL)
		 {
	 		printf("Error while GetString(%u)",MAXLINE);
	 		return 0;
		 }
		printf("You inputted:%s\n",str);
	 }
	printf("Here are the numbers:\n");
	unsigned int tok;
	unsigned char res=SUCCESS;
	while (1)
	 {
	 	res=HexTok(&str,&tok);
	 	if (res==SUCCESS)
	 	 {
	 	 	printf("\t%u",tok);
	 	 } else {
	 	 	printf("\n");
	 	 	break;
	 	 }
	 }
	CleanInput();
	return 0;
}
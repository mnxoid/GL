/** 
 * @file	swap_1.c
 * @brief	C source of the app that contains a function for 
 *			swapping integers between arrays
 *
 * 
 * Copyright 2014 by mnxoid, 
 * 
 * This software is the confidential and proprietary information
 * of mnxoid  ( "Confidential Information" ) .  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with mnxoid.
 **/
//------------------Includes------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------Definitions---------------------------------
#define USELIM 1
#define NOLIM 0
#define ERROR 1
#define SUCCESS 0
//------------------Structures, classes, unions-------------------
//------------------Utility functions---------------------------
/**
 * @brief       This function swaps integers between arrays
 * @param	[in]		*a - pointer to the first array
 *						*b - pointer to the second array
 *						pos - integer index for swapping  
 * @return	unsigned char			SUCCESS - success
 *									ERROR - error ( null pointer ) 
 **/
unsigned char Swap ( int *a, int *b,  unsigned int pos ) 
 {
 	if  (  ( a==NULL ) || ( b==NULL )  ) 
 	 {
	 	return ERROR; 
	 } else {
	 	int temp=* ( a + pos ) ; 
	 	* ( a + pos )  = * ( b + pos ) ; 
	 	* ( b + pos )  = temp; 
	 	return SUCCESS; 
	 } 
 }
/**
 * @brief       This function swaps rows
 * @param	[in]		*a - pointer to the first row
 *						*b - pointer to the second row
 *						 
 * @return	unsigned char			SUCCESS - success
 *									ERROR - error ( null pointer ) 
 **/
unsigned char PSwap ( int **a, int **b,  unsigned int pos ) 
 {
 	if  (  ( a==NULL ) || ( b==NULL )  ) 
 	 {
	 	return ERROR; 
	 } else {
	 	int *temp;
	 	temp=*((int**)a); 
	 	*a=*b;
	 	*b=temp;
	 	return SUCCESS; 
	 } 
 }
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
 	printf ( "This is an app that swaps integers in an array.\n\n" ) ; 
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
 * @brief       This function inputs an integer
 * @param	[in/out]		*i - pointer to the integer
 * @param   [in]			use - limit usage flag ( USELIM/NOLIM ) 
 *							min - lower bound
 *							upper bound
 * @return	unsigned char		0 - success
 *								1 - error ( null pointer ) 
 **/
unsigned char InputInt ( int *i, unsigned char use, int min, int max ) 
 {
 	if  ( i==NULL )  return ERROR; 
 	int retc, in; 
 	if  ( use==USELIM ) 
 	 {
 	 	retc=scanf ( "%i", &in ) ; 
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
 	 	retc=scanf ( "%i", &in ) ; 
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
 * @brief       This function outputs an array
 * @param	[in]		*a - pointer to the array
 *						name - name of the array 
 *						size - size of the array 
 * @return	unsigned char			SUCCESS - success
 *									ERROR - error ( null pointer ) 
 **/
unsigned char OutArr ( int *a,  const char *name,  unsigned int size ) 
 {
 	if  ( a==NULL )  return ERROR; 
 	int i; 
 	printf ( "%s={", name ) ; 
 	for  ( i=0; i < size-1; ++i ) 
 	 {
 	 	printf ( "%i, ", * ( a+i )  ) ; 
 	 }
 	printf ( "%i}\n", * ( a+size-1 )  ) ; 
 	return SUCCESS; 
 }
/**
 * @brief       This function inputs two arrays
 * @param	[in]		input - Input mode(M-manual,H-hardcoded)
 *						size - size of the array 
 *						array1 - pointer to first array
 *						array2 - pinter to second array
 * @return	unsigned char			SUCCESS - success
 *									ERROR - error ( null pointer ) 
 **/
unsigned char ArrayInput(char input,unsigned int *size,int **array1,int **array2)
  {
  	int retc;
  	unsigned int i;
  	if  (  input == 'M'  ) 
	 { 
	 	//----------------------Size input--------------------------------
	 	printf ( "Input the size of the arrays  ( it has to be an integer ) : " ) ; 
	 	retc=scanf ( "%i", size ) ; 
	 	CleanInput (  ) ; 
	 	if  (  ! (  (  retc > 0  )  &&  (  *size > 0  )  )   ) 
	 	 {
	 	 	do
	 	 	 {
	 	 		printf ( "Sorry,  try again: " ) ; 
	 	 		retc=scanf ( "%u", size ) ; 
	 	 		CleanInput (  ) ; 
	 	 	 } while  (  ! (  (  retc > 0  )  &&  (  *size > 0  )  )   ) ; 
	 	 }
	 	//----------------------Memory allocation-------------------------
	 	*array1=calloc ( *size, sizeof ( int )  ) ; 
	 	*array2=calloc ( *size, sizeof ( int )  ) ; 
	 	if  (  ( *array1==NULL )  ||  ( *array2==NULL )  )  {printf ( "Not enough memory!\n" ) ; return ERROR; }
	 	//----------------------Array input-------------------------------
	 	for  ( i=0; i < *size; ++i ) 
	 	 {
	 	 	printf ( "\nA[%i]=", i+1 ) ; 
	 	 	if  ( InputInt (  ( *array1+i ) ,  NOLIM,  0,  0 ) ==ERROR )  {printf ( "Null pointer exception!\n" ) ; return ERROR; }
	 	 }
	 	for  ( i=0; i < *size; ++i ) 
	 	 {
	 	 	printf ( "\nB[%i]=", i+1 ) ; 
	 	 	if  ( InputInt (  ( *array2+i ) ,  NOLIM,  0,  0 ) ==ERROR )  {printf ( "Null pointer exception!\n" ) ; return ERROR; }
	 	 }
	 } else {
	 	*size=5; 
	 	*array1=calloc ( *size, sizeof ( int )  ) ; 
	 	*array2=calloc ( *size, sizeof ( int )  ) ; 
	 	if  (  ( *array1==NULL )  ||  ( *array2==NULL )  )  {printf ( "Not enough memory!\n" ) ; return ERROR; }
	 	for  ( i=0; i < *size; ++i )  * ( *array1+i ) =i; 
	 	for  ( i=0; i < *size; ++i )  * ( *array2+i ) =3-i; //chosen by fair dice roll,  guaranteed to be random
	 }
  }
//------------------Main function-------------------------------
int main (  ) 
{
	Disclaimer (  ) ; 

	printf ( "\n\nWould you like to input the array manually or use the hardcoded one?\n" ) ; 
	printf ( "Input \"M\" to input manually or \"H\" for the hardcoded version: " ) ; 
	char input; 
	if  ( InputChar ( "MH", &input ) ==ERROR ) 
	 {
	 	printf ( "Null pointer exception!\n" ) ; 
	 	getchar (  ) ; 
	 	return 0; 
	 }
	int *array1, *array2, retc;
	unsigned int size,i,j; 
	size=0; 
	retc=0; 
	//--------------------Array Input-----------------
	if( ArrayInput( input, &size, &array1, &array2 ) == ERROR ) return 0;
	//--------------------Array Output----------------
	if ( OutArr ( array1, "A", size ) ==ERROR ) 
	 {
		printf ( "Null pointer exception!\n" ) ; return 0; 
	 }
	if ( OutArr ( array2, "B", size ) ==ERROR )  
	 {
		printf ( "Null pointer exception!\n" ) ;
		return 0;
	 }
	//--------------------Swap------------------------
	printf ( "Which element would you like to swap? " ) ; 
	if  ( InputInt ( &i, USELIM,  0,  size+1 ) ==ERROR )  
	 {
		printf ( "Null pointer exception!\n" ) ;
		return 0;
	 }
	if  ( Swap ( array1, array2, i-1 ) ==ERROR )  
	 {
		printf ( "Null pointer exception!\n" ) ;
		return 0;
	 }
	//--------------------Array Output----------------
	if ( OutArr ( array1, "A", size ) ==ERROR )  
	 {
		printf ( "Null pointer exception!\n" ) ;
		return 0;
	 }
	if ( OutArr ( array2, "B", size ) ==ERROR )  
	 {
		printf ( "Null pointer exception!\n" ) ;
		return 0;
	 }
	//--------------------Memory Deallocation---------
	free ( array1 ) ; 
	free ( array2 ) ; 
	//--------------------Matrix Reversing-------------------------------------------------------------
	printf ( "Press [ENTER] to continue..." ) ; 
	CleanInput (  ) ; 
	printf ( "\n\n\n\n\n\n\nNow we are going to reverse rows of a matrix.\n" ) ; 
	//----------------------------Allocation------------------------
	printf ( "Enter matrix size:" ) ; 
	if  ( InputInt ( &size, USELIM, 0, 1000 ) ==ERROR )  
	 {
		printf ( "Null pointer exception!\n" ) ;
		return 0;
	 }
	int **matrix; 
	matrix =  ( int** )  calloc ( size, sizeof ( int* )  ) ; 
	if  ( matrix==NULL )  
	 {
		printf ( "Not enough memory!\n" ) ;
		return 0;
	 }
	for  ( i=0; i < size; ++i ) 
	 {
	 	* ( matrix+i )  =  ( int* )  calloc ( size, sizeof ( int )  ) ; 
	 	if  ( * ( matrix+i ) ==NULL )  
		 {
			printf ( "Not enough memory!\n" ) ;
			return 0;
		 }
	 }
	//----------------------------Input-----------------------------
	for ( i=0; i < size; ++i ) 
		for ( j=0; j < size; ++j ) 
		 {
			printf ( "M[%i][%i]=", i+1, j+1 ) ; 
			InputInt ( &matrix[i][j],  NOLIM, 0, 0 ) ; 
		 }
	//----------------------------Output----------------------------
	printf("Before:\n");
	for ( i=0; i < size; ++i ) 
	 {
		for ( j=0; j < size; ++j ) 
			printf ( "%i ", matrix[i][j] ) ; 
		printf ( "\n" ) ; 
	 }
	//----------------------------Reversing-------------------------
	for ( i=0; i < size/2; ++i ) 
	 {
	 	for  ( j=0; j < size; ++j ) 
	 	 {
	 	 	if  ( PSwap ( &matrix[i], &matrix[size-i-1], j ) ==ERROR )  
			 {
				printf ( "Null pointer exception!\n" ) ;
				return 0;
			 }
	 	 }
	 }
	//----------------------------Output----------------------------
	printf("After:\n");
	for ( i=0; i < size; ++i ) 
	 {
		for ( j=0; j < size; ++j ) 
			printf ( "%i ", matrix[i][j] ) ; 
		printf ( "\n" ) ; 
	 }
	//----------------------------Memory Deallocation---------------
	for  ( i=0; i < size; ++i ) 
	 {
	 	free ( * ( matrix+i )  ) ; 
	 }
	free ( matrix ) ; 
	//----------------------------End-------------------------------
	printf ( "Press [ENTER] to exit..." ) ; 
	CleanInput (  ) ; //here used as safe getchar (  ) 
	return 0; 
}
/** 
 * @file	util.c
 * @brief	A source file with utility functions
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#define USELIM 1
#define NOLIM 0
#define SUCCESS 0
#define ERROR 1
#define MAXGRADE 100
#define ENTRIES 10
#define MAXNAME 10
#define MAXSURNAME 10
#define SUBJN 6
#define BUFFERSIZE 256
//------------------C/C++ content-------------------------------
char subjects[SUBJN][15] = {"Math.Analysis","Algebra","Programming","Geometry","Physics","English"};
struct entry
 {
 	char name[MAXNAME],surname[MAXSURNAME];
 	int grades[SUBJN];
 	double average;
 };
/**
 * @brief       This function flushes stdin
 **/
void CleanInput (  ) 
 {
 	while ( ! ( getchar (  ) =='\n' )  )  continue; 
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
 * @brief       This function gets user input ( string ) 
 * @param		[in/out]		*a - char pointer for string input
 *								
 * @param		[in]			size - max string size
 * @return		unsigned char 	SUCCESS - success
 * 								ERROR - error
 **/
unsigned int StrIn(char** a,unsigned int size)
 {
 	*a = (char*)calloc(size,sizeof(char));
 	if  ( *a == NULL )  return ERROR;
 	unsigned int i=0;
 	char in; 
 	while (i < size-1)
 	 {
 	 	in=getchar();
 	 	if (in=='\n') break;
 	 	*(*a+i)=in;
 	 	i++;
 	 }
 	*(*a+i)='\0';
 	*(*a+size)='\0';
 	return SUCCESS;
 }
/**
 * @brief       This function displays an error and exits
 * @param		[in]			msg - error message
 **/
void Error(const char *msg)
 {
    perror(msg);
    CleanInput();
    exit(0);
 }
/**
 * @brief       This function waits N seconds
 * @param		[in]			N - number of seconds to wait
 **/
void Wait(unsigned int N)
 {
	int k;
	for ( k = 1; k < 1000; k++)
	 {
		usleep(N);
	 }
 }
/**
 * @brief       This function inputs an entry for the database,
 *				according to the "entry" structure
 * @param	[in,out]		pointer to the entry  
 * @return	int				0  - success
 *							-1 - error
 **/
int EntryIn(entry *e,int *n, int *newsockfd,int *sockfd, 
	socklen_t *clilen, sockaddr_in *cli_addr ,sockaddr_in *serv_addr, char **buffer)
 {
 	char *s = ( char* )calloc( 1, BUFFERSIZE );
 	if (s==NULL || n==NULL || newsockfd==NULL || sockfd==NULL || clilen==NULL || cli_addr==NULL || serv_addr==NULL || buffer==NULL)
 	 {
 	 	Error("Null pointer in EntryIn");
 	 }
 	sprintf( s, "Entry input:\n" );
 	*n = write( *newsockfd, s, BUFFERSIZE - 1 );
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }
	//close(*newsockfd);

 	sprintf( s, "\tYour name: " );
 	*n = write( *newsockfd, s, BUFFERSIZE - 1 );
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }
	sprintf( s, "\0" );
 	*n = write( *newsockfd, s, BUFFERSIZE - 1 );
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }
	//close(*newsockfd);

	 	listen( *sockfd, 5 );
		*clilen = sizeof( *cli_addr );
		*newsockfd = accept( *sockfd, (sockaddr *) cli_addr, clilen);
		if (*newsockfd < 0)
		 { 
			Error("Error on accept");
		 }
		bzero( (char (*)[BUFFERSIZE]) buffer, BUFFERSIZE );
		*n = read( *newsockfd, (char (*)[BUFFERSIZE])buffer, BUFFERSIZE - 1);
		if (*n < 0) Error("Error reading from socket");

 	if( !( sscanf( ( char* )( char (*)[BUFFERSIZE] )buffer, "%s",e->name ) ) )
 	 { 
 	 	return -1;
 	 }
 	e->name[MAXNAME]='\0';

 	sprintf( s , "\tYour surname: ");
 	*n = write( *newsockfd, s, BUFFERSIZE - 1 );
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }
	sprintf( s, "\0" );
 	*n = write( *newsockfd, s, BUFFERSIZE - 1 );
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }

	 	listen( *sockfd, 5 );
		*clilen = sizeof( *cli_addr );
		*newsockfd = accept( *sockfd, (sockaddr *) cli_addr, clilen );
		if ( *newsockfd < 0 )
		 { 
			Error("Error on accept");
		 }
		bzero( (char (*)[BUFFERSIZE])buffer, BUFFERSIZE );
		*n = read( *newsockfd, (char (*)[BUFFERSIZE])buffer, BUFFERSIZE - 1);
		if (*n < 0) Error("Error reading from socket");

 	if ( !( sscanf( (char*)(char (*)[BUFFERSIZE])buffer, "%s", e->surname ) ) ) return -1;
 	e->surname[MAXSURNAME]='\0';

 	sprintf( s, "\tGrades: \n" );
 	*n = write( *newsockfd, s, BUFFERSIZE - 1 );
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }
	

 	int i;
 	e->average=0;
 	for( i=0; i < SUBJN; i++ )
 	 {
 	 	sprintf( s, "\t\t%s:", subjects[i] );
 	 	*n = write( *newsockfd, s, BUFFERSIZE - 1 );
		if (*n < 0) 
		 {
		 	Error("Error writing to socket");
		 }
		sprintf( s, "\0" );
	 	*n = write( *newsockfd, s, BUFFERSIZE - 1 );
		if (*n < 0) 
		 {
		 	Error("Error writing to socket");
		 }
 	 	
	 		listen( *sockfd, 5 );
			*clilen = sizeof( *cli_addr );
			*newsockfd = accept( *sockfd, (sockaddr *) cli_addr, clilen );
			if ( *newsockfd < 0 )
			 { 
				Error("Error on accept");
			 }
			bzero( (char (*)[BUFFERSIZE])buffer, BUFFERSIZE);
			*n = read( *newsockfd, (char (*)[BUFFERSIZE])buffer, BUFFERSIZE - 1 );
			if (*n < 0) Error("Error reading from socket");

 	 	if ( ( !( sscanf( (char*)(char (*)[BUFFERSIZE])buffer, "%i", &e->grades[i] ) ) )  || 
 	 							 ( e->grades[i] < 0 )  ||  
 	 							 ( e->grades[i]>MAXGRADE))
 	 	 {
 	 		return -1;
 	 	 }
 	 	e->average += e->grades[i];
 	 }
 	e->average /= SUBJN;
 	return 0;
 }
/**
 * @brief       This function outputs an entry from the database,
 *				according to the "entry" structure
 * @param	[in]			the entry(in our case - db[i])  
 * @return	int				0  - success
 *							-1 - error
 **/
void EntryOut( entry e, int *n, int *newsockfd )
 {
 	char *s=(char*)calloc(1,BUFFERSIZE);
 	if (s==NULL || n==NULL || newsockfd==NULL)
 	 {
 	 	Error("Null pointer in EntryOut");
 	 }
	//close(*newsockfd);
 	//printf("Entry output:\n");
 	sprintf(s,"\t\t%s\t\t%s\n",e.name,e.surname);
 	*n = write(*newsockfd,s,BUFFERSIZE-1);
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }
	//close(*newsockfd);
 	int i;
 	/*sprintf(s,"\t\t\t%s: ",subjects[0]);
 	*n = write(*newsockfd,s,BUFFERSIZE-1);
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }
	//close(*newsockfd);
 	sprintf(s,"%i\n",e.grades[0]);
 	*n = write(*newsockfd,s,BUFFERSIZE-1);
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }*/
	//close(*newsockfd);
 	for(i=0;i<SUBJN;i++)
 	 {
 	 	sprintf(s,"\t\t\t\t\t\t\t%s: ",subjects[i]);
 	 	*n = write(*newsockfd,s,BUFFERSIZE-1);
		if (*n < 0) 
		 {
		 	Error("Error writing to socket");
		 }
		//close(*newsockfd);
 	 	sprintf(s,"%i\n",e.grades[i]);
 	 	*n = write(*newsockfd,s,BUFFERSIZE-1);
		if (*n < 0) 
		 {
		 	Error("Error writing to socket");
		 }
		//close(*newsockfd);
 	 }
 	sprintf(s,"\n");
 	*n = write(*newsockfd,s,BUFFERSIZE-1);
	if (*n < 0) 
	 {
	 	Error("Error writing to socket");
	 }
	
	//close(*newsockfd);
 }
//------------------C++ only content----------------------------
#ifdef __CPLUSPLUS
#endif
//------------------End of file---------------------------------
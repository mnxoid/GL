/** 
 * @file	util.h
 * @brief	A header file with utility function prototypes, definitions
 * 			structures, namespaces and constants
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
#ifndef _netbase_HEADER_
#define _netbase_HEADER_
//------------------Includes------------------------------------
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
//------------------Definitions---------------------------------
#define MAXGRADE 100
#define ENTRIES 10
#define MAXNAME 10
#define MAXSURNAME 10
#define SUBJN 6
#define BUFFERSIZE 256
//------------------Structures,unions---------------------------
extern char subjects[SUBJN][15];
struct entry
 {
 	char name[MAXNAME],surname[MAXSURNAME];
 	int grades[SUBJN];
 	double average;
 };
//------------------Utility functions---------------------------
/**
 * @brief       This function flushes stdin
 **/
extern void CleanInput ( );
/**
 * @brief       This function gets user input ( char ) 
 * @param		[in]			*possible - pointer to char array of possible
 *											input values
 * @param		[in/out]		*pc - pointer to char that we input
 * @return		unsigned char 	SUCCESS - success
 * 								ERROR - error
 **/
extern unsigned char InputChar ( const char *possible, char *pc );
/**
 * @brief       This function inputs an integer
 * @param	[in/out]		*i - pointer to the integer
 * @param   [in]			use - limit usage flag ( USELIM/NOLIM ) 
 *							min - lower bound
 *							upper bound
 * @return	unsigned char		0 - success
 *								1 - error ( null pointer ) 
 **/
extern unsigned char InputInt ( int *i, unsigned char use, int min, int max );
/**
 * @brief       This function gets user input ( string ) 
 * @param		[in/out]		*a - char pointer for string input
 *								
 * @param		[in]			size - max string size
 * @return		unsigned char 	SUCCESS - success
 * 								ERROR - error
 **/
extern unsigned int StrIn(char* a,unsigned int size);
/**
 * @brief       This function displays an error and exits
 * @param		[in]			msg - error message
 **/
extern void Error(const char *msg);
/**
 * @brief       This function waits N seconds
 * @param		[in]			N - number of seconds to wait
 **/
extern void Wait(unsigned int N);
/**
 * @brief       This function inputs an entry for the database,
 *				according to the "entry" structure
 * @param	[in,out]		pointer to the entry  
 * @return	int				0  - success
 *							-1 - error
 **/
extern int EntryIn(entry *e,int *n, int *newsockfd,int *sockfd, 
	socklen_t *clilen, sockaddr_in *cli_addr ,sockaddr_in *serv_addr, char **buffer);
/**
 * @brief       This function outputs an entry from the database,
 *				according to the "entry" structure
 * @param	[in]			the entry(in our case - db[i])  
 * @return	int				0  - success
 *							-1 - error
 **/
extern void EntryOut(entry e,int *n, int *newsockfd);
//------------------C++ only------------------------------------
#ifdef __CPLUSPLUS
//------------------Namespaces----------------------------------
//------------------Classes-------------------------------------
#endif
#endif
//------------------End of file---------------------------------
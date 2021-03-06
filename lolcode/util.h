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
#ifndef _lolcode_HEADER_
#define _lolcode_HEADER_
//------------------Definitions---------------------------------
//------------------Structures,unions---------------------------
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
//------------------C++ only------------------------------------
#ifdef __CPLUSPLUS
//------------------Namespaces----------------------------------
//------------------Classes-------------------------------------
#endif
#endif
//------------------End of file---------------------------------
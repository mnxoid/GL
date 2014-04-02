/** 
 * @file	mystring.h
 * @brief	A header file with string.h function prototypes
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
 #ifndef _mystring_HEADER_
 #define _mystring_HEADER_
//------------------Definitions---------------------------------
//------------------Structures,unions---------------------------
//------------------Utility functions---------------------------

extern int strcasecmp(const char *s1, const char *s2);

extern int strncasecmp(const char *s1, const char *s2, size_t n);

extern char *index(const char *s, int c);

extern char *rindex(const char *s, int c);

//--------------------------------------------------------------

extern char *stpcpy(char *dest, const char *src);

extern char *strcat(char *dest, const char *src);

extern char *strchr(const char *s, int c);

extern int strcmp(const char *s1, const char *s2);

extern int strcoll(const char *s1, const char *s2);

extern char *strcpy(char *dest, const char *src);

extern size_t strcspn(const char *s, const char *reject);

extern char *strdup(const char *s);

extern char *strfry(char *string);

extern size_t strlen(const char *s);

extern char *strncat(char *dest, const char *src, size_t n);

extern int strncmp(const char *s1, const char *s2, size_t n);

extern char *strncpy(char *dest, const char *src, size_t n);

extern char *strpbrk(const char *s, const char *accept);

extern char *strrchr(const char *s, int c);

extern char *strsep(char **stringp, const char *delim);

extern size_t strspn(const char *s, const char *accept);

extern char *strstr(const char *haystack, const char *needle);

extern char *strtok(char *s, const char *delim);

extern size_t strxfrm(char *dest, const char *src, size_t n);
//------------------C++ only------------------------------------
#ifdef __CPLUSPLUS
//------------------Namespaces----------------------------------
//------------------Classes-------------------------------------
#endif
#endif
//------------------End of file---------------------------------
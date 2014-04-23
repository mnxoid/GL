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
//we need input/output (gets/puts) 
//with portion buffer input into allocated memory
//------------------C/C++ content-------------------------------
char mytolower(const char a)
 {
	char res;
	res=a;
	if (a>64 && a<91)
	 {
	 	return res+32;
	 } else if (a>191 && a<224) {
	 	return res+32;
	 } else {
	 	return res;
	 }
 }


size_t strlen(const char *s)
 {
 	size_t res=0;
 	if (s==NULL)
 	 {
 	 	return -1;
 	 }
 	while(*(s+res)!='\0')
 	 {
 	 	res++;
 	 }
 	return res;
 }

int strcasecmp(const char *s1, const char *s2)
 {
	unsigned int i;
	int res;
	res=0;
	for (i=0;(*(s1+i)!='\0') && (*(s2+i)!='\0');i++)
	 {
	 	res=mytolower(*(s1+i))-mytolower(*(s2+i));
	 	if (res) break;
	 }
	if (res==0 && *(s1+i)!='\0')
	 {
		return 1;
	 } else if (res==0 && *(s2+i)!='\0') {
	 	return -1;
	 }
	return res; 
 }

int strncasecmp(const char *s1, const char *s2, size_t n)
 {
	unsigned int i;
	int res;
	res=0;
	for (i=0;(*(s1+i)!='\0') && (*(s2+i)!='\0') && i<n+1;i++)
	 {
	 	res=mytolower(*(s1+i))-mytolower(*(s2+i));
	 	if (res) break;
	 }
	return res; 
 }

char *index(const char *s, int c)
 {
 	 size_t res=0;
 	while(*(s+res)!=c)
 	 {
 	 	res++;
 	 }
 	 char* ret=(char*)s;
 	return ret+res;
 }

char *rindex(const char *s, int c)
 {
 	 size_t res=(size_t)strlen(s)-1;
 	while(*(s+res)!=c)
 	 {
 	 	res--;
 	 }
 	 char* ret=(char*)s;
 	return ret+res;
 }

//--------------------------------------------------------------

char *stpcpy(char *dest, const char *src)
 {
 	size_t dc=strlen(dest);
 	size_t sc=strlen(src)+1;
 	if (dc<sc) return NULL;
 	for (dc=0;dc<sc;dc++)
 		*(dest+dc)=*(src+dc);
 }

char *strcat(char *dest, const char *src)
 {
 	size_t dc=strlen(dest);
 	size_t sc=strlen(src)+1;
 	if (dc<sc) return NULL;
 	for (;dc<sc;dc++)
 		*(dest+dc)=*(src+dc);
 }

char *strchr(const char *s, int c)
 {
 	 size_t res=0;
 	while(*(s+res)!=c)
 	 {
 	 	res++;
 	 }
 	 char* ret=(char*)s;
 	return ret+res;
 }

int strcmp(const char *s1, const char *s2)
 {
	unsigned int i;
	int res;
	res=0;
	for (i=0;(*(s1+i)!='\0') && (*(s2+i)!='\0');i++)
	 {
	 	res=*(s1+i)-*(s2+i);
	 	if (res) break;
	 }
	if (res==0 && *(s1+i)!='\0')
	 {
		return 1;
	 } else if (res==0 && *(s2+i)!='\0') {
	 	return -1;
	 }
	return res; 	
 }

int strcoll(const char *s1, const char *s2)
 {
 	unsigned int i;
	int res;
	res=0;
	for (i=0;(*(s1+i)!='\0') && (*(s2+i)!='\0');i++)
	 {
	 	res=*(s1+i)-*(s2+i);
	 	if (res) break;
	 }
	if (res==0 && *(s1+i)!='\0')
	 {
		return 1;
	 } else if (res==0 && *(s2+i)!='\0') {
	 	return -1;
	 }
	return res; 
 }

char *strcpy(char *dest, const char *src)
 {
 	size_t dc=strlen(dest);
 	size_t sc=strlen(src)+1;
 	if (dc<sc) return NULL;
 	memcpy(dest,src,sc-1);
 }

size_t strcspn(const char *s, const char *reject);

char *strdup(const char *s);

char *strfry(char *string);


char *strncat(char **dest, const char *src, size_t n)
 {
 	size_t dc=strlen(dest);
 	size_t sc=strlen(src)+1;
 	if (dc<sc)
 	 {
 	 	char* temp = *dest;
 	 	*dest = (char*)calloc(1,dc+sc);
 	 	if(*dest==NULL) return NULL;
 	 	memcpy(dest,temp,dc);
 	 	free(temp);
 	 }
 	memcpy(dest+dc-1,src,n);
 }

int strncmp(const char *s1, const char *s2, size_t n)
 {
	unsigned int i;
	int res;
	res=0;
	for (i=0;(*(s1+i)!='\0') && (*(s2+i)!='\0') && i<n+1;i++)
	 {
	 	res=*(s1+i)-*(s2+i);
	 	if (res) break;
	 }
	return res; 
 }

char *strncpy(char *dest, const char *src, size_t n)
 {
 	size_t dc=strlen(dest);
 	size_t sc=strlen(src)+1;
 	sc=n;
 	if (dc<sc) return NULL;
 	for (dc=0;dc<sc;dc++)
 		*(dest+dc)=*(src+dc);
 }

char *strpbrk(const char *s, const char *accept);

char *strrchr(const char *s, int c)
 {
 	 size_t res=strlen(s)-1;
 	while(*(s+res)!=c)
 	 {
 	 	res--;
 	 }
 	 char* ret=(char*)s;
 	return ret+res;
 }

char *strsep(char **stringp, const char *delim);

size_t strspn(const char *s, const char *accept);

char *strstr(const char *haystack, const char *needle);

char *strtok(char *s, const char *delim);

size_t strxfrm(char *dest, const char *src, size_t n)
 {
 	size_t srclen, copysize;
	srclen = strlen(src);
	if (n != 0) {
		if (srclen < n)
		 {
		 	copysize = srclen;
		 } else {
		 	copysize = n - 1;
		 }
		memcpy(dst, src, copysize);
		*(dst+copysize) = 0;
	}
	return (srclen);
 }

//------------------C++ only content----------------------------
#ifdef __CPLUSPLUS
#endif
//------------------End of file---------------------------------
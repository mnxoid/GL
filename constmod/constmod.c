/** 
 * @file	constmod.cpp
 * @brief	C source of the app that modifies a constant
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
volatile const int c=6;
//------------------Structures,classes,unions-------------------
//------------------Utility functions---------------------------
//------------------Main function-------------------------------
int main()
{
	__asm__ volatile
	 (
		"pushl %eax\n"
		"xorl %eax, %eax\n"
		"popl %eax"
	 );
	volatile const int a=5;
	int b;
	printf("What to assign to the const a? ");
	scanf("%i",&b);
	int *p;
	p=&a;
	__asm__ volatile
	 (
		"nop\n"
		"nop\n"
		"movl   0x1c(%esp),%eax\n"		//mov eax,addr a
		"movl   0x18(%esp),%ebx\n"		//mov ebx,b
		"movl   %ebx,(%eax)\n"			//mov [eax],ebx
		"nop\n"
		"nop\n"
	 );
	//from now on, const a is changed
	printf("a=%i\ninput=%i\n",a,b);
	p=&c;
	printf("What to assign to the const a? ");
	scanf("%i",&b);
	__asm__ volatile
	 (
		"nop\n"
		"nop\n"
		"movl   0x1c(%esp),%eax\n"		//mov eax,addr a
		"movl   0x18(%esp),%ebx\n"		//mov ebx,b
		"movl   %ebx,(%eax)\n"			//mov [eax],ebx
		"nop\n"
		"nop\n"
	 );
	printf("c=%i\ninput=%i\n",c,b);
	char nothing=getchar();
	return 0;
}
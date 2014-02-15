/** 
 * @file	binop.c
 * @brief	C source of the app that performs basic bitwise operations
 *			and numeral system conversions 
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
void BinOut(int n)
 {
 	int k=0;
	while (k<8*sizeof(int))
	 {
		if (n & (1 << 8*sizeof(int)-1))
			printf("1");
		else
			printf("0");
		n <<= 1;
		k++;
	 }
 }
void AllOut(int n)
 {
 	printf("\t\t%i\t",n);
 	BinOut(n);
 	printf("\t0x%-9x\t0%o\n",n,n);
 }
int main()
{
	int a,b;
	printf("Input two numbers:\nA=");
	scanf("%i",&a);
	printf("B=");
	scanf("%i",&b);
	printf("\t\tDec\tBin\t\t\t\t\tHex\t\tOct\n");
	printf("A:\n");
	AllOut(a);
	printf("B:\n");
	AllOut(b);
	printf("NOT A:\n");
	AllOut(~a);
	printf("NOT B:\n");
	AllOut(~b);
	printf("AND A,B:\n");
	AllOut(a&b);
	printf("OR A,B:\n");
	AllOut(a|b);
	printf("XOR A,B:\n");
	AllOut(a^b);
	int s;
	printf("Enter shift value:\nS=");
	scanf("%i",&s);
	printf("SAL A,%i:\n",s);
	AllOut(a<<s);
	printf("SAL B,%i:\n",s);
	AllOut(b<<s);
	printf("SAR A,%i:\n",s);
	AllOut(a>>s);
	printf("SAR A,%i:\n",s);
	AllOut(b>>s);
	char nothing=getchar();
	return 0;
}
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
typedef unsigned long int ui;
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
void UiOut(ui n)
 {
 	printf("\t\t%10lu\t",n);
 	int k=0;
	while (k<8*sizeof(ui))
	 {
		if (n & (1 << 8*sizeof(ui)-1))
			printf("1");
		else
			printf("0");
		n <<= 1;
		k++;
	 }
	printf("\n");
 }
void AllOut(int n)
 {
 	printf("\t\t%i\t",n);
 	BinOut(n);
 	printf("\t0x%-9x\t0%o\n",n,n);
 }
ui Swap16(ui a)
 {
 	ui mask = (~0) << 16;
 	//UiOut(mask);
 	ui p1=a&(~mask);
 	//UiOut(p1);
 	ui p2=a&(mask);
 	//UiOut(p2);
 	p1 = p1 << 16;
 	//UiOut(p1);
 	p2 = p2 >> 16;
 	//UiOut(p2);
 	p2 = p2&(~mask);
 	//UiOut(p2);
 	//UiOut(p2|p1);
 	return(p2|p1);
 }
ui CompareBits(ui a,int i,int j)
 {
 	//UiOut(a>>i);
 	//UiOut((a>>i)&1);
 	//UiOut(a>>j);
 	//UiOut((a>>j)&1);
 	return(((a>>i)&1)&((a>>j)&1));
 }
ui RCR(ui a,int n)
 {
 	ui mask = (~0) << n;
 	UiOut(mask);
 	ui p1 = a&mask;
 	UiOut(p1);
 	ui p2 = a&(~mask);
 	UiOut(p2);
 	p1 = p1 >> n;
 	UiOut(p1);
 	p2 = p2 << (32-n);
 	UiOut(p2);
 	return(p1|p2);
 }
int CountZeroBits(ui a)
 {
 	ui b=~a;
 	int s=0;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	s+=b&1;
 	b = b >>1;
 	return s;
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

	printf("Tasks:\n\n");

	ui u=0;

	printf("Task 31:\n");
	printf("Enter A for swapping its 16bit parts:\nA=");
	scanf("%lu",&u);
	UiOut(u);
	UiOut(Swap16(u));

	printf("Task 30:\n");
	printf("Enter A for comparing its bits :\nA=");
	scanf("%lu",&u);
	UiOut(u);
	printf("Enter which bit to compare:\n1:");
	scanf("%i",&a);
	printf("Enter which bit to compare:\n2:");
	scanf("%i",&b);
	UiOut(CompareBits(u,a,b));

	printf("Task 29:\n");
	printf("Enter A for RCR(A,N) :\nA=");
	scanf("%lu",&u);
	printf("Enter N for RCR(A,N) :\nA=");
	scanf("%i",&a);
	UiOut(u);
	UiOut(RCR(u,a));

	printf("Task 28:\n");
	printf("Enter A for counting its zero bits :\nA=");
	scanf("%lu",&u);
	UiOut(u);
	AllOut(CountZeroBits(u));
	while (getchar() != '\n') continue;
	char nothing=getchar();
	return 0;
}
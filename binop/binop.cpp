/** 
 * @file	binop.cpp
 * @brief	C++ source of the app that performs basic bitwise operations
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
#include <iostream>
#include <stdio.h>
using namespace std;
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
 	cout << "\t\t" << n << "\t";
 	BinOut(n);
 	printf("\t0x%-9x\t0%o\n",n,n);
 }
int main()
{
	int a,b;
	cout << "Input two numbers:\nA=";
	cin >> a;
	cout << "B=";
	cin >> b;
	cout << "\t\tDec\tBin\t\t\t\t\tHex\t\tOct\n";
	cout << "A:" << endl;
	AllOut(a);
	cout << "B:" << endl;
	AllOut(b);
	cout << "NOT A:" << endl;
	AllOut(~a);
	cout << "NOT B:" << endl;
	AllOut(~b);
	cout << "AND A,B:" << endl;
	AllOut(a&b);
	cout << "OR A,B:" << endl;
	AllOut(a|b);
	cout << "XOR A,B:" << endl;
	AllOut(a^b);
	int s;
	cout << "Enter shift value:\nS=";
	cin >> s;
	cout << "SAL A," << s << ":" << endl;
	AllOut(a<<s);
	cout << "SAL B," << s << ":" << endl;
	AllOut(b<<s);
	cout << "SAR A," << s << ":" << endl;
	AllOut(a>>s);
	cout << "SAR B," << s << ":" << endl;
	AllOut(b>>s);
	char nothing=getchar();
	return 0;
}
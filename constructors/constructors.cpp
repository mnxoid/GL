/** 
 * @file	constructors.cpp
 * @brief	C++ source of the app that ...
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
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <iostream>
#include "util.h"
//------------------Namespaces----------------------------------
using namespace std;
//------------------Classes-------------------------------------
class A
 {
	public:
		char *p;
		A( unsigned i)        	// конструктор з параметрами
		 {
			p = (i) ? new (nothrow) char[i + 1] : nullptr;
			if (p)
			 {
			 	memset(p, '*', i*sizeof(char) );
			 }
			p[i] = 0;
			cout << "ctor A::(unsigned) \n\t p (addr:" << hex << (int)p <<") = " << p << "\n" ;
		 }
		A( A & a)	// конструктор копіювання
		 {
			unsigned sz = malloc_usable_size(a.p);
			p = ( sz > 0 ) ? new (nothrow) char[sz] : nullptr;
			if (p)
			 { 
			 	memcpy(p, a.p, sz);
			 }
			cout << "ctor A::(A&) \n\t p (addr:" << hex << 
			(int)p <<") = " << p << "\n" ;
		 }
		A( A && a)	// конструктор переміщення
		 {
			p = a.p;
			a.p = nullptr;
			cout << "ctor A::(A&&) \n\t p (addr:" << hex << (int)p <<") = " << p << "\n" ;
		 }
 };
//------------------Utility functions---------------------------
A f(A a)
 {
	cout << "f is executing... ";
	unsigned sz = malloc_usable_size(a.p); 
	if (a.p)
	 {
	 	memset(a.p, '+', sz ); 
	 }
	a.p [sz - 1] = 0;
	cout << " OK\n";
	return a;
 }
//------------------Disclaimer----------------------------------
/**
 * @brief       This function displays license agreement
 **/
void Disclaimer (  ) 
 {
 	printf ( "This is an app that ....\n\n" ) ; 
	printf ( "Copyright 2014 by mnxoid, \n\n" ) ; 
	printf ( "This software is the confidential and proprietary information\n" ) ; 
	printf ( "of mnxoid  (\"Confidential Information\") .  You\n" ) ; 
	printf ( "shall not disclose such Confidential Information and shall use\n" ) ; 
	printf ( "it only in accordance with the terms of the license agreement\n" ) ; 
	printf ( "you entered into with mnxoid.\n\n" ) ; 
	printf ( "By pressing [ENTER] you confirm that you are NOT A GEODESIST\n" ) ; 
	CleanInput (  ) ; //here CleanInput is used as a safe getchar (  ) 
 }
//------------------Main function-------------------------------
int main()
{
	Disclaimer();
	A a(10);
	A a3 = f(a);
	cout << "f is executed \n\t a3.p (addr:" << hex << (int)a3.p <<") = " << a3.p << "\n" ;
	cout << "f is not executed \n\t a.p (addr:" << hex << (int)a.p <<") = " << a.p << "\n" ;
	CleanInput();
	return 0;
}
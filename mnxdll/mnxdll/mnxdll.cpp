// mnxdll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "myheader.h"
int sum(int a, int b)
{
	cout << "Hoorah! You have called my function!" << endl;
	return a+b;
}


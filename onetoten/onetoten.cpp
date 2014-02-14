#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int s=0;
	for (int i=0;i<10;i++) s+=i;
	cout << "The sum of 10 first integers is: " << s <<endl;
	char nothing=getchar();
	return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;
const int N=10;
int main()
{
	int s=0;
	for (int i=0;i<N;i++) s+=i;
	cout << "The sum of " << N << " first integers is: " << s <<endl;
	char nothing=getchar();
	return 0;
}
#include <stdio.h>
const int N=10;
int main()
{
	int i,s=0;
	for (i=0;i<N;i++) s+=i;
	printf("The sum of %i first integers is: %i\n",N,s);
	char nothing=getchar();
	return 0;
}
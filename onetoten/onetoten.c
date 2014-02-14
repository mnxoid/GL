#include <stdio.h>
int main()
{
	int i,s=0;
	for (i=0;i<10;i++) s+=i;
	printf("The sum of 10 first integers is: %i\n",s);
	char nothing=getchar();
	return 0;
}
/** 
 * @file	bagtokut_1.c
 * @brief	C source of the app that gets a set of vertices
 *			from stdin, outputs them sorted by distance from
 *			(0,0,0) and determines whether there are 3 vertices
 *			with the same z coordinate.
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
#include <stdio.h>
#include <math.h>
/*
double sqrt1(double a,double eps)
 {
 	double res,resprev;
 	res = a/2;resprev=res+2*eps;
 	int undone=1;
 	int k=2;
 	while (undone)
 	 {
 	 	undone=0;
 	 	if ((resprev - res)>0)
 	 	 {
 	 		if ((resprev - res) > eps) undone = 1;
 	 	 }
 	 	else if ((res - resprev) > eps) undone = 1;
 	 	if (res*res>a) {resprev = res;res -= a/k;}
 	 	else if (res*res<a) {resprev = res;res+=a/k;}
 	 	else return res;
 	 	k=k*2;
 	 }
 	return res;
 }*/
#define N 20
typedef struct vert
 {
 	double x,y,z;
 	double d;
 } vertex;
int main()
{
	int n,i;
	printf("Input number of vertices (it has to be an integer):");
	int err = scanf("%i",&n);
	//printf("%i\n",err);
	if ((err==0)||(n<0)) {printf("Error! Bad input. Geodesist detected!\n");return 0;}
	vertex vertices[N];
	printf("input coords:\n"); 
	for (i=0; i<n;i++)
	 {
		err=scanf("%lf %lf %lf",&vertices[i].x,&vertices[i].y,&vertices[i].z);
		//printf("%i\n",err);
		if (err==0) {printf("Error! Bad input. Geodesist detected!\n");return 0;}
		vertices[i].d=sqrt(vertices[i].x*vertices[i].x+vertices[i].y*vertices[i].y+vertices[i].z*vertices[i].z);
	 }
	int undone=1;
	while (undone)
	 {
	 	undone=0;
	 	for (i=0;i<n-1;i++){
	 		if (vertices[i].d<vertices[i+1].d)
	 		 {
	 		 	vertex temp=vertices[i];
	 		 	vertices[i]=vertices[i+1];
	 		 	vertices[i+1]=temp;
	 		 	undone=1;
	 		 }
	 	}
	 }
	printf("You inputted:\n");
	double unique[N];
	int k=0, found;
	for(i=0;i<n;i++)
	 {
	 	int j;
	 	printf("%lf\t%lf\t%lf\td=%lf\n",vertices[i].x,vertices[i].y,vertices[i].z,vertices[i].d);
	 	found=0;
	 	for(j=0;j<k;j++)
	 		if(vertices[i].z==unique[j]) found=1;
	 	if (!found)
	 	 {
	 	 	unique[k]=vertices[i].z;
	 	 	k++;
	 	 }
	 }
	found=0;
	for (i=0;i<k;i++)
	 {
		int a=0,j;
		for (j=0;j<n;j++)
			if (unique[i]==vertices[j].z) a++;
		if (a==3) 
		 {
		 	found=1;
		 	break;
		 }
	 }
	if (found) printf("There are three vertices with the same z coord!\n");
	else printf("There are less than three vertices with the same z coord!\n");
	char nothing=getchar();
	return 0;
}
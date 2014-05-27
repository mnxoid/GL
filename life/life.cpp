/** 
 * @file	life.cpp
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
#include <iostream>
#include <GL/glut.h>
#include <pthread.h>
#include "util.h"
//------------------Definitions---------------------------------
#define SIZE 95
//------------------Namespaces----------------------------------
using namespace std;
//------------------Classes-------------------------------------
class cell
 {
 	private:
 		unsigned char alive;
	public:
		cell(unsigned char a)
		 {
		 	if (a)
		 	 {
		 		alive=1;
		 	 } else {
		 	 	alive=0;
		 	 }
		 }
		cell():cell(0){}
		unsigned char getState()
		 {
		 	return alive;
		 }
		void setState(unsigned char a)
		 {
		 	if (a)
		 	 {
		 		alive=1;
		 	 } else {
		 	 	alive=0;
		 	 }
		 }
 } field[SIZE][SIZE];
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
//------------------Utility functions---------------------------
void Display()
 {
 	glClear(GL_COLOR_BUFFER_BIT);
 	glPointSize(5);
 	glBegin(GL_POINTS);
 	glColor3f(0.0, 0.0, 0.0);
 	int i,j;
 	for (i=0;i<SIZE;++i)
 	 {
 	 	for(j=0;j<SIZE;++j)
 	 	 {
 	 	 	if (field[i][j].getState())
 	 	 	 {
 	 	 		glVertex2f(0.005*i+0.015, 0.005*j+0.015);
 	 	 	 }
 	 	 }
 	 }
 	glEnd();
 	glFlush();
 }
void Init_GL(int argc, char **argv)
 {
 	glutInit(&argc,argv);
 	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 	glutInitWindowSize(480, 480);
 	glutInitWindowPosition(200, 200);
 	glutCreateWindow("A game of life");
 	glClearColor(1.0, 1.0, 1.0, 1.0);
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(0.0, 0.5, 0.0, 0.5, -1.0, 1.0);
 	glutDisplayFunc(Display);
 }
void * thread_fun(void * param)
 {
 	while(0==0)
 	 {
 	 	int i,j;
 	 	for(i=0;i<SIZE;++i)
 	 	 {
 	 	 	for(j=0;j<SIZE;++j)
 	 	 	 {
 	 	 	 	field[i][j].setState((i+j)%2);
 	 	 	 }
 	 	 }
 	 }
 }
//------------------Main function-------------------------------
int main(int argc, char **argv)
{
	Disclaimer();
	Init_GL(argc,argv);
	pthread_t thread_id;
	int param;
	pthread_create(&thread_id, NULL, thread_fun, &param); 
	glutMainLoop();
	CleanInput();
	return 0;
}
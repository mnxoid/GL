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
#include <memory.h>
#include <iostream>
#include <GL/glut.h>
#include <pthread.h>
#include <time.h>
#include "util.h"
//------------------Definitions---------------------------------
#define SIZE 40
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
 } field[SIZE][SIZE],newfield[SIZE][SIZE];
int flag;
pthread_t thread_id;
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
void fieldInit()
 {
 	
 	int i,j;
 	for(i=1;i<SIZE-1;++i)
 	 {
 	 	for(j=1; j<SIZE-1; ++j)
 	 	 {
 	 	 	field[i][j].setState( (rand()>RAND_MAX/2) ? 1 : 0);
 	 	 }
 	 }
 	
 }
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
void keyb(unsigned char key, int x, int y)//keyboard callback
 {
 	
 	if(key=='s') flag=1;
 	else if(key=='e') flag=0;
 	else if(key=='x')fieldInit();
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
 	glutKeyboardFunc(keyb);
 }
void * thread_fun(void * param)
 {
 	while(0==0)
 	 {
 	 	if (!flag) {
 	 	int i,j;
 	 	for(i=1;i<SIZE-1;++i)
 	 	 {
 	 	 	for(j=1;j<SIZE-1;++j)
 	 	 	 {
 	 	 	 	int neighbours=0;
	 	 	 	int i1=i-1,j1=j-1;
	 	 	 	for (;i1<i+2;++i1)
	 	 	 	 {
	 	 	 	 	for (;j1<j+2;++j1)
	 	 	 	 	 {
	 	 	 	 	 	neighbours+=field[i1][j1].getState();
	 	 	 	 	 }
	 	 	 	 }
	 	 	 	neighbours-=field[i][j].getState();
 	 	 	 	if (field[i][j].getState()==0)
 	 	 	 	 {
 	 	 	 	 	if (neighbours > 0)
 	 	 	 	 	 {
 	 	 	 	 	 	newfield[i][j].setState(1);
 	 	 	 	 	 }
 	 	 	 	 } else if (field[i][j].getState()==1) {
 	 	 	 	 	if ((neighbours<3)||(neighbours>7))
 	 	 	 	 	 {
 	 	 	 	 	 //	newfield[i][j].setState(0);
 	 	 	 	 	 }
 	 	 	 	 }
 	 	 	 	
 	 	 	 }
 	 	 }
 	 	for(i=1;i<SIZE-1;++i)
 	 	 {
 	 	 	for(j=1;j<SIZE-1;++j)
 	 	 	 {
 	 	 	 	field[i][j].setState(newfield[i][j].getState());
 	 	 	 }
 	 	 }
 	 	//memcpy(field,newfield,SIZE*SIZE*sizeof(cell));
 	 	flag=1;
 	 	printf("One cycle passed!\n");
 	 }
 	 glutPostRedisplay();
 	 }

 }
//------------------Main function-------------------------------
int main(int argc, char **argv)
{
	flag=0;
	srand(time(NULL));
	Disclaimer();
	Init_GL(argc,argv);
	int param;
	fieldInit();
	pthread_create(&thread_id, NULL, thread_fun, &param); 
	glutMainLoop();
	CleanInput();
	return 0;
}
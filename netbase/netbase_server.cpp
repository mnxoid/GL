/** 
 * @file	netbase_server.cpp
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
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include "util.h"
//------------------Definitions---------------------------------
#define MAXGRADE 100
#define ENTRIES 10
#define MAXNAME 10
#define MAXSURNAME 10
#define SUBJN 6
//------------------Structures,classes,unions-------------------
//------------------Namespaces----------------------------------
using namespace std;
//------------------Disclaimer----------------------------------
/**
 * @brief	   This function displays license agreement
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
int main(int argc, char *argv[])
{
	Disclaimer();
	int sockfd, newsockfd, portno;
	char buffer[BUFFERSIZE];
	socklen_t clilen;
	sockaddr_in serv_addr, cli_addr;
	int n;
	//-----------------Too few arguments-------------------
	if (argc < 2) 
	 {
		printf("#----------USAGE-------------#\n");
		printf("I                            I\n");
		printf("I  server [port]             I\n");
		printf("I                            I\n");
		printf("#----------------------------#\n");
		CleanInput();		 
		exit(1);
	 }
	//-----------------Arguments are ok--------------------
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	 {
		Error("Error opening socket");
	 }
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	 {
		Error("Error on binding");
	 }
	//-----------------Database initialization-------------
	entry db[ENTRIES];
	int k=0;
	//-----------------Main cycle--------------------------
	while (1==1)
	 {
		listen(sockfd,5);
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
		 { 
			Error("Error on accept");
		 }
		bzero(buffer,BUFFERSIZE);
		n = read(newsockfd,buffer,BUFFERSIZE-1);
		if (n < 0) Error("Error reading from socket");
		//-------------Here we have the message----------------
		if (strncmp(buffer,"X",1)==0)
		 {
		 	printf("Goodbye!\n");
		 	n = write(newsockfd,"Goodbye\n",BUFFERSIZE-1);
			if (n < 0) 
			 {
				Error("Error writing to socket");
			 }
			close(newsockfd);
			return 0;
		 } else if (strncmp(buffer,"A",1)==0) {
		 	if(EntryIn(&db[k],&n, &newsockfd, &sockfd, &clilen, &cli_addr , &serv_addr, (char**)&buffer))
		 	 {
		 	 	n = write(newsockfd,"Goodbye!\nError! Invalid input. Geodesist detected!\n",BUFFERSIZE-1);
				if (n < 0) 
				 {
					Error("Error! Invalid input. Geodesist detected!\n");
				 }
				
				close(newsockfd);
		 		break;
		 	 }
			n = write(newsockfd,"\0",1);
			if (n < 0) 
			 {
			 	Error("Error writing to socket");
			 }
		 	//while (getchar() != '\n') continue;
			close(newsockfd);
		 	k++;
		 } else if (strncmp(buffer,"V",1)==0) {
		 	if (k>0)
		 	 {
		 	 	int i,l;
		 	 	//sorting start
		 	 	int undone=1;
				while (undone)
				 {
				 	undone=0;
				 	for (i=0;i<k-1;i++)
				 	 {
				 		if (db[i].average<db[i+1].average)
				 		 {
				 		 	entry temp=db[i];
				 		 	db[i]=db[i+1];
				 		 	db[i+1]=temp;
				 		 	undone=1;
				 		 }
				 	 }
				 }
		 	 	//sorting end
				n = write(newsockfd,"Database output:\n\t\tName\t\tSurname\t\tGrades\n\n",BUFFERSIZE-1);
				if (n < 0) 
				 {
				 	Error("Error writing to socket");
				 }
				
			 	//printf("Database output:\n\t\tName\t\tSurname\t\tGrades\n\n");
			 	l=0;
			 	for (i=0;i<k;i++)
			 	 {
			 	 	if (db[i].average>70) l++;
			 	 	EntryOut(db[i],&n,&newsockfd);
			 	 }
			 	double dob=100*(double)(l)/k;
			 	char* tempstr=(char*)calloc(1,BUFFERSIZE);
			 	sprintf(tempstr,"There are %1.2f%% good students.\n",dob );
			 	n = write(newsockfd,tempstr,BUFFERSIZE-1);
				if (n < 0) 
				 {
				 	Error("Error writing to socket");
				 }
				n = write(newsockfd,"\0",BUFFERSIZE-1);
				if (n < 0) 
				 {
				 	Error("Error writing to socket");
				 }
				
			 } else {
			 	n = write(newsockfd,"Database is empty\n",BUFFERSIZE-1);
				if (n < 0) 
				 {
				 	Error("Error writing to socket");
				 }
				//close(newsockfd);
			 }
			n = write(newsockfd,"\0",1);
			if (n < 0) 
			 {
			 	Error("Error writing to socket");
			 }
			close(newsockfd);
		 } else if (strncmp(buffer,"D",1)==0) {//done
		 	if (k>0)
		 	 {
		 		k--;
		 	 }
		 	n = write(newsockfd,"Entry deleted\n",BUFFERSIZE-1);
			if (n < 0) 
			 {
			 	Error("Error writing to socket");
			 }
			n = write(newsockfd,"\0",BUFFERSIZE-1);
			if (n < 0) 
			 {
			 	Error("Error writing to socket");
			 }
			close(newsockfd);
		 } else if (strncmp(buffer,"\n",1)==0) {//done
		 	n = write(newsockfd,"$ ",BUFFERSIZE-1);
			if (n < 0) 
			 {
			 	Error("Error writing to socket");
			 }
			n = write(newsockfd,"\0",BUFFERSIZE-1);
			if (n < 0) 
			 {
			 	Error("Error writing to socket");
			 }
			close(newsockfd);
		 } else {
		 	n = write(newsockfd,"Goodbye!\nError! Invalid input. Geodesist detected!\n",BUFFERSIZE-1);
			if (n < 0) 
			 {
				Error("Error! Invalid input. Geodesist detected!\n");
			 }
			
			close(newsockfd);
	 		return 0;
		 }
		printf("Here is the message: >%s<",buffer);
		continue;
		//-------------Here we reply---------------------------
		n = write(newsockfd,"I got your message\n",BUFFERSIZE-1);
		if (n < 0) 
		 {
		 	Error("Error writing to socket");
		 }
		close(newsockfd);//here
	 }
	//-----------------End---------------------------------
	close(sockfd);
	CleanInput();
	return 0;
}
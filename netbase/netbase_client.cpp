/** 
 * @file	filename.cpp
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
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "util.h"
//------------------Namespaces----------------------------------
using namespace std;
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
int main(int argc, char *argv[])
{
	Disclaimer();
	int sockfd, portno, n;
	sockaddr_in serv_addr;
	hostent *server;
	char buffer[256];
	//---------Too few arguments-------------------------
	if (argc < 3) 
	 {
		fprintf(stderr,"usage %s hostname port\n", argv[0]);
		getchar();
		exit(0);
	 }
	//---------Arguments are ok--------------------------
	portno = atoi(argv[2]);
	//---------------------------------------------------
	printf("Welcome, this app stores the information about students\n");
	printf("What would you like to do?\n\tA - add entry\n\tV - view entries\n\tD - delete last entry\n\tX - exit\n");
	//---------Main cycle--------------------------------
	while (1==1) 
	 {
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0)
		 {
			Error("Error opening socket");
		 }
		server = gethostbyname(argv[1]);
		if (server == NULL) 
		 {
			fprintf(stderr,"Error, no such host\n");
			CleanInput();
			exit(0);
		 }
		bzero((char *) &serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
		serv_addr.sin_port = htons(portno);
		if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
		 { 
			Error("Error connecting");
		 }
		//--------------------------------------------------------------
		fprintf(stderr,"\n$ ");
		bzero(buffer,256);
		fgets(buffer,255,stdin);
		n = write(sockfd,buffer,strlen(buffer));
		if (n < 0)
		 { 
			Error("Error writing to socket");
		 }
		//----------------------------------------------------------------
		bzero(buffer,256);
		do
		 {		
			
			n = read(sockfd,buffer,255);
			if (n < 0)
			 {
				Error("Error reading from socket");
			 }
			printf("%s\n",buffer);
			if (strncmp(buffer,"Goodbye",7)==0)
			 {
			 	close(sockfd);
			 	return 0;
			 }
		 }
		while (buffer[0]!='\0');
		close(sockfd);
	 }
	CleanInput();
	return 0;
}
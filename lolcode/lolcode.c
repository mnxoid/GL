/** 
 * @file	lolcode.c
 * @brief	C source of the app that messes up your mind
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
#include "util.h"
#define something 1
#define MagicNumber1 25672
#define MagicNumber2 25967 
#define MagicNumber3 27756 
#define MagicNumber4 11375 
#define MagicNumber5 16199
//------------------Disclaimer----------------------------------
/**
 * @brief       This function displays license agreement
 **/
void Disclaimer (  ) 
 {
 	printf ( "This is an app that messes up your mind\n\n" ) ; 
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
int main()
{
	Disclaimer();
	int count=457;
	int lol1=1537;
	int lol=0;
	int lol3=1555;
	int lol5=15670;
	begin:
	goto sub_i;
	int lol2;
	sub_a:
	if (lol3>2*MagicNumber5)
	 {
	 	goto sub_b;
	 } else if (lol3>lol) {
	 	goto begin;
	 } else {
	 	goto end;
	 }
	sub_b:
	for (;lol5< MagicNumber3 - ( MagicNumber1 - MagicNumber2 ) ;lol1++)
	 {
	 	if (lol>3000)
 	 	 {
 	 	 	lol2-=7;
 	 	 }
	 }
	printf("%c%c%c",(char)lol1,(char)(lol3+5),(char)lol5 );
	end:
	CleanInput();
	return 0;
	sub_c:
	for (;lol5< MagicNumber5 - ( MagicNumber4 - MagicNumber1 ) ;lol5++)
	 {
	 	if (lol<78)
 	 	 {
 	 	 	lol1-=7;
 	 	 }
	 }
	printf("%c\x77%cr%c\x64!",(char)lol5,(char)(lol2+3),(char)lol2 );
	goto sub_a;
	sub_e:
	printf("%c",(char)lol3);
	lol3>>8;
	printf("%c",(char)lol3-67);
	if (lol<300000) 
	 {
	 	goto sub_e;
	 } else if (lol2>30000) {
	 	goto sub_f;
	 } else {
	 	goto sub_c;
	 }
	goto end;
	
	sub_d:
	
	while(lol<MagicNumber3)
	 {
	 	
	 	for(lol2=0;lol2<MagicNumber3;lol2+=2)
	 	 {
	 	 	if (lol<78)
	 	 	 {
	 	 	 	lol1-=7;
	 	 	 }
	 	 }
	 	count+=30;
	 	lol++;
	 	printf("%c",(char)lol2);
	 	if (count>500) break;
	 	lol2>>8;
	 }
	goto sub_g;
	sub_g:
	for (;lol3<MagicNumber4;lol3+=5)
	 {
	 	if( 5*lol>50 ) 
	 	 {
	 	 	lol++;
	 	 } else {
	 	 	lol*=2000-lol1;
	 	 }
	 }
	printf("%c",(char)lol3);
	lol3>>8;
	printf("%c",(char)lol3-67);
	if (lol<300000) 
	 {
	 	goto sub_e;
	 } else if (lol2>30000) {
	 	goto sub_f;
	 } else {
	 	goto sub_c;
	 }
	sub_f:
	for (;lol2<MagicNumber1;lol2+=5)
	 {
	 	if( 7*lol1<500 ) 
	 	 {
	 	 	lol3++;
	 	 } else {
	 	 	lol1*=2-lol2;
	 	 }
	 }
	printf("%c",(char)lol3);
	lol3>>8;
	printf("%c",(char)lol3-67);
	if (something) 
	 {
	 	goto sub_a;
	 } else if (something) {
	 	goto sub_c;
	 } else {
	 	goto sub_g;
	 }
	sub_h:
	
	for (;lol1<MagicNumber2;lol1+=15)
	 {
	 	if( 2*lol1<50 ) 
	 	 {
	 	 	lol3++;
	 	 } else {
	 	 	lol*=2000-lol1;
	 	 }
	 }
	lol1-=15;
	printf("%c",(char)lol1);
	goto sub_d;
	sub_i:
	
	for (;lol<MagicNumber1;lol+=4)
	 {
	 	lol2+=300;
	 }
	if (printf("%c",(char)lol))
	 {
	 	goto sub_h;
	 } else {
	 	goto sub_f;
	 }
	CleanInput();
	return 0;
}
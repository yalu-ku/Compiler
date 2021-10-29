/*
	2018270679 À±¾Æ·Î
	[1] ¿¹Á¦ 3.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 100
#define FINALSTATE 2


int Table[3][2] = {
	{1, 0}, 
	{2, 0}, 
	{2, 2}
};


/*
		0	1
	p	1	0
	q	2	0
	r	2	2

	Fianl state = 2
*/


void main()
{
	char input[LENGTH];
	int state = 0;
	scanf("%s", input);
	int len = strlen(input);

	for (int i = 0; i < len; i++) {
		state = Table[state][input[i] - '0'];
	}
	if (state == FINALSTATE)
		printf("input recognized!\n");
	else
		printf("input not recognized..\n");


}
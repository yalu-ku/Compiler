/*
	2018270679 윤아로
	[2] 연습문제 3.7(5)
*/

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define LENGTH 100
//#define FINALSTATE {1,3}
//
//int Table[5][2] = {
//	{1,0}, 
//	{3,2}, 
//	{4,-1}, 
//	{3,4}, 
//	{3,0}
//};


/*
	0: A = [q0]
	1: B = [q1, q2]
	2: C = [q1]
	3: D = [q0, q1, q2]
	4: E = [q0, q1]

	Fianl state: 1, 3
*/

//aaaab


//void main()
//{
//	int finalstate[] = FINALSTATE;
//	char input[LENGTH];
//	int state = 0;
//	scanf("%s", input);
//	int len = strlen(input);
//	int recognize = 0;
//
//	for (int i = 0; i < len; i++) {
//		state = Table[state][input[i] - 'a'];
//		if (state == -1) {
//			printf("inaccessible\n"); //공집합을 만남
//			return;
//		}
//	}
//	for (int i = 0; i < sizeof(finalstate) / sizeof(int); i++) {
//		if (state == finalstate[i])
//			recognize = 1;
//
//	}
//	if (recognize)
//		printf("input recognized!\n"); //Reject
//	else
//		printf("input not recognized..\n"); //Accept
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int state = 5;
int symbol = 2;


int state_table[5][2] = {
   {1,0},
   {3,2},
   {4,-1},
   {3,4},
   {3,0}

};

/*
   0: A=[q0]
   1: B=[q1,q2]
   2: C=[q1]
   3: D=[q0,q1,q2]
   4: E=[q0,q1] 라고 가정
*/
#define max 100
int main() {
    char str[max];
    int current_state = 0;
    int final_state = 0;
    int i = 0;
    scanf("%s", str);
    int len = strlen(str);
    while(i != len){
        current_state = state_table[current_state][str[i++] - 'a'];
        printf("%d\n",current_state);
    }
    if (current_state == 1 || current_state == 3)//현재 상태가 final상태일 때. 현재 이 식에서 final은 r, r=2
    {
        printf("Accept");
    }
    else printf("Reject");

}
#include <stdio.h>

char ch;
int flag = 0;
int cnt[20];
int i = 0;

void error() {
    if (!flag) {
        puts("error!!");
        flag = 1;
    }
}


void pop_() {
    if (ch == 'a' || 'b' || 'c') {
        ch = getchar();
    }
    else
        error();
}



//1. S->aS
//2. S->bA
void expand_S() {
    void expand_A();
    if (ch == 'a') {
        pop_();
        expand_S();
        cnt[i++] = 1;
    }
    else if (ch == 'b') {
        pop_();
        expand_A();
        cnt[i++] = 2;
    }
    else
        error();
}


//3. A -> d
//4. A -> ccA
void expand_A() {
    if (ch == 'd') {
        pop_();
        cnt[i++] = 3;
    }
    else if (ch == 'c') {
        pop_();
        pop_();
        expand_A();
        cnt[i++] = 4;
    }
    else
        error();
}


int main() {
    printf("Enter a sentence:");
    ch = getchar();
    expand_S();
    if (!flag && ch == '$') puts("Accept!!");
    else error();
    if (flag != 1) {
        printf("LeftParser:");
        for (int i = 30; i >= 0; i--) {
            if (cnt[i] != 0)
                printf("%d", cnt[i]);
        }
    }

    return 0;

}


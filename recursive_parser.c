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


void pop_a() {
    if (ch == 'a') {
        ch = getchar();
    }
    else error();
}

void pop_b() {
    if (ch == 'b') {
        ch = getchar();
    }
    else error();
}
void pop_c() {
    if (ch == 'c') {
        ch = getchar();
    }
    else error();
}
void pop_d() {
    if (ch == 'd') {
        ch = getchar();
    }
    else error();
}


//1. S->aS
//2. S->bA
void expand_S() {
    void expand_A();
    if (ch == 'a') {
        pop_a();
        expand_S();
        cnt[i++] = 1;
    }
    else if (ch == 'b') {
        pop_b();
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
        pop_d();
        cnt[i++] = 3;
    }
    else if (ch == 'c') {
        pop_c();
        pop_c();
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


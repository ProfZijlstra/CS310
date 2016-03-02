#include <stdio.h>

int areall(void * any, int (*test)(void* any, int idx), 
        int (*term)(void* any, int idx)) {
    int len = 0;
    while (!term(any, len)) {
        if (test(any, len)) {
            len++;
        } else {
            return 0;
        }
    }
    return 1;
}

int isany(void *any, int (*test)(void* any, int idx),
        int (*term)(void* any, int idx)) {
    int len = 0;
    while (!term(any, len)) {
        if (test(any, len)) {
            return 1;
        } else {
            len++;
        }
    }
    return 0;
}

int even(int *a, int i) {
    return a[i] % 2 == 0;
}

int odd(int *a, int i) {
    return a[i] % 2 == 1;
}

int lowerc(char *a, int i) {
    return islower(a[i]);
}

int str_term(char* a, int i) {
    return a[i] == '\0';
}
int pos_int_term(int* a, int i) {
    return a[i] == -1;
}

typedef int (* FN) (void* any, int index);
int main() {
    if (areall("abcd", (FN)lowerc, (FN)str_term)) {
        puts("all lower case");
    }

    if (isany("ABcD", (FN)lowerc, (FN)str_term)) {
        puts("one is lower case");
    }
}

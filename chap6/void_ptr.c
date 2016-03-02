//typedef int (* TERM_FN) (void* any, int index);

int arblen(void *any, int (*term)(void* any, int index)) {
    int len = 0;
    while (!term(any, len)) {
        len++;
    }
    return len;
}

int str_term(char* a, int i) {
    return a[i] == '\0';
}

int pos_int_term(int* a, int i) {
    return a[i] == -1;
}

#include <stdio.h>
int main() {
    char a[] = "Hello world!";
    int b[] = {5, 8, 4, 6, 3, 9, -1};
    int len = arblen(a, (int (*)(void*,int))str_term);
    printf("Length of string is: %d\n", len);
    len = arblen(b, (int (*)(void*,int))pos_int_term);
    printf("Length of positive integer array is: %d", len);
}

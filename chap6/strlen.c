#include <stdio.h>

int mystrlen(const char s[]) {
    const char *p = s;
    while (*p != '\0') {
        p++;
    }
    return p - s;
}

int strlen2(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}


int main() {
    printf("%d\n", mystrlen("abc"));
    printf("%d\n", strlen2("abc"));
}



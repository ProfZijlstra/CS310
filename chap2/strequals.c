#include <stdio.h>

int strequals(char x[], char y[]) {
    if ( x == y ) { // same memory locations
        return 1;
    }
    for (int i = 0; x[i] == y[i]; i++) {
        if (x[i] == '\0') {
            return 1; // yes equal
        }
    }
    return 0; // not equal
}

int main() {
    if ("abc" == "abc") {
        printf("same location\n");
    } else {
        printf("not same location\n");
    }

    char t[4];
    t[0] = 'a';
    t[1] = 'b';
    t[2] = 'c';
    t[3] = '\0';
    if (strequals("abc", t) ){
        printf("equal string a\n");
    } else {
        printf("not same string a\n");
    }

    if (strequals("abcd", "abce") ){
        printf("equal string b\n");
    } else {
        printf("not same string b\n");
    }
}

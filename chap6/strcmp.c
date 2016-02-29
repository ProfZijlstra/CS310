#include <stdio.h>

int strcmp(const char s1[], const char s2[]) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') {
            return 0; // same
        }
        i++;
    }
    return s1[i] - s2[i]; 
}

int strcmp2(const char* s1, const char* s2) {
    while (*s1 == *s2) {
        if (*s1 == '\0') {
            return 0; // same
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main() {
    printf("%d\n", strcmp("abc", "abd"));
    printf("%d\n", strcmp2("abc", "abd"));

}

#include <stdio.h>

const char* strchr(const char* s, char c) {
    while (*s != c) {
        s++;
    }
    return s;
}


const char* strchrrec(const char* s, char c) {
    if (*s == c) {
        return s;
    }
    return strchrrec(s+1, c);
}

int main() {
    char *s = "Hello world!";
    char w = 'w';
    const char *f1 = strchr(s, w);
    const char *f2 = strchrrec(s, w);

    printf("%c found at %ld in %s\n", *f1, f1 - s, s);
    printf("%c found at %ld in %s\n", *f2, f2 - s, s);
}

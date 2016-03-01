#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* dstrcpy(const char* s) {
    int l = strlen(s);
    char* cp = malloc(l * sizeof(char));
    for (int i = 0; i < l; i++) {
        cp[i] = s[i];
    }
    return cp;
}

int main() {
    char *test = "This is a test of things!";
    char buf[26];
    // regular copy
    strncpy(buf, test, 26);
    char *dynamic = dstrcpy(test);
    puts(buf);
    puts(dynamic);
}

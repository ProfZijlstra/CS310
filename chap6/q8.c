#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* reverse(const char* s) {
    int len = strlen(s);
    char* r = (char*) malloc((len+1) * sizeof(char));
    register int i = len - 1;
    while (i >= 0) {
        r[(len- 1) -i] = s[i];
        i--;
    }
    r[len]  = '\0';
    return r;
}

int main() {
    char a[] = "Hello world!";
    char *b = reverse(a);
    puts(b);
    free(b); // cause we're good ppl
}

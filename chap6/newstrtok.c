#include <stdio.h>

static int isin(const char *s, int c) {
    for (int i=0; s[i] != '\0'; i++) {
        if (c == s[i]) {
            return 1;
        }
    }
    return 0;
}

char * newstrtok(char *s, const char* delim, char **next){
    // if we're at the end
    if (s[0] == '\0') {
        return NULL;
    }

    // make sure to skip preceding delims
    while (isin(delim, *s)) {
        s++;
    }

    char *ret = s;
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (isin(delim, s[i])) {
            break;
        }
    }
    // if we found a delim
    if (s[i] != '\0') {
        // move through consecutive delims
        do {
            i++;
            s[i-1] = '\0';
        } while (isin(delim, s[i]) && s[i] != '\0');
    }

    *next = &s[i];
    return ret;
}

int main() {
    char s[100];
    fgets(s, 99, stdin);
    char *delim = " \t\n\r\f";

    char *curr = s;
    char *next = s;
    char *tok  = s;
    while (tok != NULL) {
        tok = newstrtok(curr, delim, &next);
        if (tok != NULL) {
            printf("%s\n", tok);
            curr = next;
        }
    }
}

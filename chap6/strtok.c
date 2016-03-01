#include <stdio.h>

static int isin(const char *s, int c) {
    for (int i=0; s[i] != '\0'; i++) {
        if (c == s[i]) {
            return 1;
        }
    }
    return 0;
}

char *strtok(char *str, const char *delim) {
    static char* s;
    if (str != NULL) {
        s = str;
        // make sure to skip preceding delims
        while (isin(delim, *s)) {
            s++;
        }
    } else if (*s == '\0') {
        // if we're at the end of s
        return NULL;
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

    // make sure ret wasn't inside a delim
    // do we still need this???
    while (*ret == '\0') {
        ret++;
    }

    s = &s[i];
    return ret;
}


int main() {
    // strings declared with quotes are constant, chars cannot be changed
    const char *text = "  This \t is some text \n\f with \r tests  ";

    char buf[50];
    for (int i = 0; text[i] != '\0'; i++) {
        buf[i] = text[i];
    }

    s = strtok(buf, " \r\n\f\t");
    if (s != NULL) {
        puts(s);
        while ( (s = strtok(NULL, " \r\n\f\t")) != NULL) {
            puts(s);
        }
    }
}

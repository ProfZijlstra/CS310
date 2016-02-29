#include <stdio.h>

char *simple_strtok(char *str, const char *delim) {
    static char* s;
    if (str != NULL) {
        s = str;
    } else if (*s == '\0') {
        // when there is nothing left 
        return NULL;
    }
    char *start = s;
    while (*s != *delim && *s != '\0') {
        s++;
    }
    *s = '\0';
    s++;
    return start;
}

char *strtok(char *str, const char *delim) {
    static char* s;
    if (str != NULL) {
        s = str;
    } else if (*s == '\0') {
        // if we're at the end of s
        return NULL;
    }

    char *ret = s;
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        // check if this char is any of the delims
        for (int j = 0; delim[j] != '\0'; j++) {
            if (s[i] == delim[i]) {
                goto found;
            }
        }
    }
    goto end;
found:
    // remove all consecutive delims
    for (; s[i] != '\0'; i++) {
        int j;
        for (j = 0; delim[j] != '\0'; j++) {
            // break if we find delim
            if (s[i] == delim[j]) {
                break;
            }
        }
        // if s[i] is not a delim
        if (delim[j] == '\0') {
            i--; // make sure i points to last delim
            break;
        }
    }
    // if we're at a delim, and not the end
    if (s[i] != '\0') {
        s[i] = '\0';
        i++; // go to after delim
    } 
end:
    s = &s[i];
    return ret;
}


int main() {
    // strings declared with quotes are constant, chars cannot be changed
    char *text = "This is some text";
    char other[18];
    for (int i = 0; i< 18; i++) {
        other[i] = text[i];
    }
    
    puts(simple_strtok(other, " "));
    puts(simple_strtok(NULL, " "));
    puts(simple_strtok(NULL, " "));
    puts(simple_strtok(NULL, " "));
    puts(simple_strtok(NULL, " ")); // prints '\0'
    puts(strtok(other, " "));
    puts(strtok(NULL, " "));
    puts(strtok(NULL, " "));
    puts(strtok(NULL, " "));
    puts(strtok(NULL, " ")); // prints '\0'
}

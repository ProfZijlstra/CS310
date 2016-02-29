#include <stdio.h>

extern char** environ;

/* Where s1 is the key we're looking for
 * and s2 is an environment string we're looking through 
 * returns char* of value on success
 * or NULL on failure
 */
static const char* match(const char* s1, const char* s2) {
    register int i = 0;
    // find where they no longer match
    while (s1[i] == s2[i]) {
        i++;
    }
    // if at end of s1, and s2 is delim
    if (s1[i] == '\0' && s2[i] == '=') {
        return &s2[i+1]; // ptr to first char of val
    }
    return NULL;
}

/* Uses match() to search for key in environ
 * returns char* of value on success
 * or NULL on failure
 */
const char* getenv(const char* key) {
    const char* val = NULL;
    for (int i = 0; environ[i] != '\0'; i++) {
        if ( (val = match(key, environ[i])) != NULL) {
            return val;
        }
    }
    return NULL;
}

/* Test getenv by trying to get HOME and TERM */
int main() {
    printf("%s\n", getenv("HOME"));
    printf("%s\n", getenv("TERM"));
}


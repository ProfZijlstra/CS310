#include <stdio.h>
#include <string.h>

extern char** environ;

/* Uses match() to search for key in environ
 * returns char* of value on success
 * or NULL on failure
 */
const char* getenv(const char* key) {
    const char* val = NULL;
    for (int i = 0; environ[i] != '\0'; i++) {
        // get an environ string
        char *s = environ[i];
        // find where equals is
        char *eq = strchr(s, '=');
        // find distance to the equals
        int distance = eq - s;

        // found the right one if they're same for that distance
        if (strncmp(key, s, distance) == 0) {
            return eq + 1;
        }
    }
    return NULL;
}

/* Test getenv by trying to get HOME and TERM */
int main() {
    printf("%s\n", getenv("HOME"));
    printf("%s\n", getenv("TERM"));
}


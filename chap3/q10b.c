#include <stdio.h>
#include <stdlib.h>

// reads from standard in, and counts spaces, tabs, what not
int main() {
    char c;
    unsigned int s = 0;
    unsigned int t = 0;
    unsigned int n = 0;
    unsigned int f = 0;
    while ( (c = getchar()) != EOF) { 
        switch (c) {
            case ' ':
                s++;
                break;
            case '\t':
                t++;
                break;
            case '\n':
                n++;
                break;
            case '\f':
                f++;
                break;
        }
    }
    printf("Spaces found: %u\n", s);
    printf("Newlines found: %u\n", n);
    printf("Tabs found: %u\n", t);
    printf("Formfeed found: %u\n", f);
}

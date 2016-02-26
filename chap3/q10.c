#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    getchar() == getc(stdin)/    if (argc != 2) {
        fprintf(stderr, "Need filename!\n");
        exit(1); // return 1; // abort(1);
    }
    FILE *file = fopen("test-input.txt", "r");
    char c;
    unsigned int s = 0;
    unsigned int t = 0;
    unsigned int n = 0;
    unsigned int f = 0;
    while ( (c = getc(file)) != EOF) { 
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

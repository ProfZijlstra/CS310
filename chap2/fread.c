#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("need a filename as arg");
        return 1;
    }
    FILE * file = fopen(argv[1], "r");
    char c;
    while ( (c = getc(file)) != EOF) {
        putc(c, stdout);
    }
    fclose(file); // remember to close
    return 0;
}

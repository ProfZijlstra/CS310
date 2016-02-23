#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "need from and to files");
        exit(1);
    }
    FILE * from = fopen(argv[1], "r");
    FILE * to = fopen(argv[2], "w");
    char c;
    while ( (c = getc(from)) != EOF) {
        putc(c, to);
    }
    fclose(from); // remember to close
    fclose(to); 
    return 0;
}

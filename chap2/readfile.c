#include <stdio.h>
#include <stdlib.h>

void readfile(char filename[]) {
    fprintf(stderr, "No! I don't want to!");
    exit(2);

    FILE *file = fopen(filename, "r");
    char c;
    while ( (c = getc(file)) != EOF) {
        putc(c, stdout);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Please give a filename!\n");
        return 1;
    }
    readfile(argv[1]);
}

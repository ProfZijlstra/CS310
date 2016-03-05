#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s: needs a file name as argument\n", argv[0]);
        return -1;
    }
    FILE* update;
    if ( (update = fopen(argv[1], "r+")) == NULL) {
        fprintf(stderr, "%s: cannot open %s for updating\n", argv[0], argv[1]);
        return -2;
    }

    char c;
    while ( (c = fgetc(update)) != EOF) {
        if (isupper(c)) {
            ungetc(c, update); // put character back into stream (go back 1)
            fflush(update); // flush before switching to write
            fputc(tolower(c), update); // put lowercase in place
            fflush(update); // flush before switching to read
        }
    }
    fclose(update);
}

